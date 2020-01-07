//////////////////////////////////////////////////////////////////////////////////
/// \file mac_sender.c
/// \brief MAC sender thread
/// \author Pascal Sartoretti (pascal dot sartoretti at hevs dot ch)
/// \version 1.0 - original
/// \date  2018-02
//////////////////////////////////////////////////////////////////////////////////
#include "stm32f7xx_hal.h"

#include <stdio.h>
#include <string.h>
#include "main.h"
#include "ext_led.h"

osMessageQueueId_t	queue_mem_macS_id; 

//////////////////////////////////////////////////////////////////////////////////
// THREAD MAC RECEIVER
//////////////////////////////////////////////////////////////////////////////////
void MacSender(void *argument)
{
		struct queueMsg_t queueMsg;							// queue message
		osStatus_t retCode;
		uint8_t * token; 
		uint8_t * msgPtr; 
		uint8_t * copyPtr; 
		uint8_t * sendPtr;
	
		char errorMsg[] = "MAC ERROR"; 
		queue_mem_macS_id = osMessageQueueNew(4,sizeof(struct queueMsg_t),NULL); 
		for(;;){			
			//----------------------------------------------------------------------------
			// QUEUE READ										
			//----------------------------------------------------------------------------
			retCode = osMessageQueueGet(queue_macS_id,&queueMsg,NULL,osWaitForever); 	
			CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);

			msgPtr = queueMsg.anyPtr;
			
			switch(queueMsg.type){				
				case TOKEN:							
					//update station list
					msgPtr[gTokenInterface.myAddress+1] = (1 << TIME_SAPI) | (gTokenInterface.connected << CHAT_SAPI);				
					memcpy(gTokenInterface.station_list,&msgPtr[1],15);
					
					//save token 
					token = osMemoryPoolAlloc(memPool,osWaitForever); 
					memcpy(token,msgPtr,16); 
					
					//free the memory used for the token message
					retCode = osMemoryPoolFree(memPool,msgPtr);
					CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
					
					//transmit to lcd
					queueMsg.type = TOKEN_LIST; 
					retCode = osMessageQueuePut(queue_lcd_id,&queueMsg,osPriorityNormal,osWaitForever);
					CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);	

					//-----------------------------------------------------------------------
					// is a messag to send ?
					//-----------------------------------------------------------------------
					if(osMessageQueueGet(queue_mem_macS_id,&queueMsg,NULL,0)==osOK)
					{						
						msgPtr = queueMsg.anyPtr;
						
						/*get a new dynamic mermory pool*/
						sendPtr = osMemoryPoolAlloc(memPool,osWaitForever);	
						
						/*create a data frame*/
						sendPtr[0] = (gTokenInterface.myAddress<<3)  + queueMsg.sapi; 
						sendPtr[1] = (queueMsg.addr<<3) + queueMsg.sapi; 
						sendPtr[2] = strlen((char*)msgPtr); 									// lenght of message 
						memcpy(&sendPtr[3],msgPtr,strlen((char*)msgPtr)); 	// data

						//calculate checksum and add in dynamic memory
						sendPtr[3+sendPtr[2]] = (calculateCRC(sendPtr)<<2)&0xFC; 						
						
						//free the memory used for the token message
						retCode = osMemoryPoolFree(memPool,msgPtr);
						CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
						//keep in memory the message send
						copyPtr = osMemoryPoolAlloc(memPool,osWaitForever); 
						memcpy(copyPtr,sendPtr,sendPtr[2]+4); 	// data
						
						queueMsg.anyPtr = sendPtr; 
						queueMsg.type = TO_PHY;
						
						//transmit msg to physical layer
						retCode = osMessageQueuePut(queue_phyS_id,&queueMsg,osPriorityNormal,osWaitForever);
						CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);	
					}
					else
					{
							//give the token
							queueMsg.anyPtr = token; 
							queueMsg.type = TO_PHY;
						
							//transmit msg to physical layer
							retCode = osMessageQueuePut(queue_phyS_id,&queueMsg,osPriorityNormal,osWaitForever);
							CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);	
					}

					break;
				case DATABACK:
					if ((msgPtr[1]>>3) == BROADCAST_ADDRESS)
					{											
							retCode = osMemoryPoolFree(memPool,copyPtr);
							CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
						
							//give the token
							queueMsg.anyPtr = token; 
							queueMsg.type = TO_PHY;
						
							//transmit msg to physical layer
							retCode = osMessageQueuePut(queue_phyS_id,&queueMsg,osPriorityNormal,osWaitForever);
							CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
					}
					else
					{
						switch(msgPtr[3+msgPtr[2]]&0x03){//check read and ack
							case 0:
							case 1: //send mac error							
												
								retCode = osMemoryPoolFree(memPool,copyPtr);
								CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
							
								sendPtr = osMemoryPoolAlloc(memPool,osWaitForever); 
								memcpy(sendPtr,errorMsg,strlen(errorMsg)); 
								
								queueMsg.anyPtr = sendPtr; 
								queueMsg.type = MAC_ERROR;
								
								//transmit msg to lcd
								retCode = osMessageQueuePut(queue_lcd_id,&queueMsg,osPriorityNormal,osWaitForever);
								CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);	
							
								//give the token
								queueMsg.anyPtr = token; 
								queueMsg.type = TO_PHY;
							
								//transmit msg to physical layer
								retCode = osMessageQueuePut(queue_phyS_id,&queueMsg,osPriorityNormal,osWaitForever);
								CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
							break; 
							case 2: //message ack -> resend message								
								//keep in memory the message send
								sendPtr = osMemoryPoolAlloc(memPool,osWaitForever); 
								memcpy(sendPtr,copyPtr,copyPtr[2]+4); 	// data
								
								queueMsg.anyPtr = sendPtr; 
								queueMsg.type = TO_PHY;
								
								//transmit msg to physical layer
								retCode = osMessageQueuePut(queue_phyS_id,&queueMsg,osPriorityNormal,osWaitForever);
								CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);	
							break; 
							case 3: //message Ok -> realese the token
								//free message copy													
								retCode = osMemoryPoolFree(memPool,copyPtr);
								CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
								
								//give the token
								queueMsg.anyPtr = token; 
								queueMsg.type = TO_PHY;
							
								//transmit msg to physical layer
								retCode = osMessageQueuePut(queue_phyS_id,&queueMsg,osPriorityNormal,osWaitForever);
								CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
							break; 		
						}
					}	
					//free message copy					
					retCode = osMemoryPoolFree(memPool,msgPtr);
					CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
					break; 
				case DATA_IND:
						//transmit msg to memory queue
						retCode = osMessageQueuePut(queue_mem_macS_id,&queueMsg,osPriorityNormal,osWaitForever);
						CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);	
					break; 
				case START: 
					gTokenInterface.connected = 1;
					break;
				case STOP:
					gTokenInterface.connected = 0;
					break; 
				case NEW_TOKEN:
						/*get a new dynamic mermory pool*/
						sendPtr = osMemoryPoolAlloc(memPool,osWaitForever);	
						sendPtr[0] = TOKEN_TAG; 						
						//initialise station list to 0
						for(int i=0;i<15;i++){
							sendPtr[i+1] = 0; 
							gTokenInterface.station_list[i] = 0; 
						}
						
						//put our station sapi status in station and in the token
						gTokenInterface.station_list[gTokenInterface.myAddress] = (1 << TIME_SAPI) | (gTokenInterface.connected << CHAT_SAPI); 
						sendPtr[1+gTokenInterface.myAddress] =  (1 << TIME_SAPI) | (gTokenInterface.connected << CHAT_SAPI); 
						
						//give the token
						queueMsg.anyPtr = sendPtr; 
						queueMsg.type = TO_PHY;				
						
						//transmit msg to physical layer						
						retCode = osMessageQueuePut(queue_phyS_id,&queueMsg,osPriorityNormal,osWaitForever);
						CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
					break; 
				default:
					break;				
			}							
		}	
}


