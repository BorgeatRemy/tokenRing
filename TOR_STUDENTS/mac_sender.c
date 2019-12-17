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
const osMessageQueueAttr_t queue_mem_macS_id = {
	.name = "memoristation in mac Sender  "  	
};	

uint8_t calculateCRC(uint8_t* data){
		uint32_t checksum = 0; 
		for(int i = 0; i < data[2]+3; i++)
		{
			checksum+=data[i]; 		
		}
		return checksum&0x3F; //get 6 LSB
}
//////////////////////////////////////////////////////////////////////////////////
// THREAD MAC RECEIVER
//////////////////////////////////////////////////////////////////////////////////
void MacSender(void *argument)
{
		struct queueMsg_t queueMsg;							// queue message

		uint8_t * token; 
		uint8_t * msgPtr; 
		uint8_t * copyPtr; 
		uint8_t * sendPtr;
	
		char errorMsg[] = "MAC ERROR"; 
		queue_mem_macS_id = osMessageQueueNew(4,sizeof(struct queueMsg_t),NULL); 
		struct queueMsg_t queueMsg;							// queue message
		for(;;){			
			//----------------------------------------------------------------------------
			// QUEUE READ										
			//----------------------------------------------------------------------------
			retCode = osMessageQueueGet(queue_macS_id,&queueMsg,NULL,osWaitForever); 	
			CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);

			msgPtr = queueMsg.anyPtr;
			
			switch(queueMsg.type){				
				case TOKEN:				
					msgPtr[gTokenInterface.myAddress+1] = (1 << TIME_SAPI) | (gTokenInterface.connected << CHAT_SAPI);				
					memcpy(gTokenInterface.station_list,&msgPtr[1],15);
					//free the memory used for the token message
					retCode = osMemoryPoolFree(memPool,msgPtr);
					CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
					//-----------------------------------------------------------------------
					// is a messag to send ?
					//-----------------------------------------------------------------------
					if(osMessageQueueGet(queue_mem_macS_id,&queueMsg,NULL)==osOk)
					{						
						/*get the pointer to memory pool*/
						msgPtr = queueMsg.anyPtr;
						
						/*get a new dynamic mermory pool*/
						sendPtr = osMemoryPoolAlloc(memPool,osWaitForever);	
						
						/*create a data frame*/
						sendPtr[0] = gTokenInterface.myAddress<<3 +  (1 << TIME_SAPI) | (gTokenInterface.connected << CHAT_SAPI); 
						sendPtr[1] = gTokenInterface.destinationAddress<<3 + queueMsg.sapi; 
						sendPtr[2] = strlen(msgPtr); 									// lenght of message 
						memcpy(&sendPtr[3],msgPtr,strlen(msgPtr)); 	// data

						//calculate checksum and add in dynamic memory
						sendPtr[3+sendPtr[2]] = calculateCRC(sendPtr)<<3&0xFC; 
						
						//free the memory used for the data indication message
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
						//send token 
					}
					break;
				case DATABACK:
					switch(msgPtr[3+msgPtr[2]]&0x03){
						case 0:
						case 1: //send mac error
							sendPtr = osMemoryPoolAlloc(memPool,osWaitForever); 
							memcpy(sendPtr,errorMsg,strlen(errorMsg)); 
							
							queueMsg.anyPtr = sendPtr; 
							queueMsg.type = MAC_ERROR;
							
							//transmit msg to physical layer
							retCode = osMessageQueuePut(queue_lcd_id,&queueMsg,osPriorityNormal,osWaitForever);
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
						
					break; 
				case DATA_IND:
					//put msg in queue 
					break; 
				case START: 
					gTokenInterface.connected = 1;
					break;
				case STOP:
					gTokenInterface.connected = 0;
					break; 
				case NEW_TOKEN:
					break; 
				default:
					break; 
			}			
		}	
}


