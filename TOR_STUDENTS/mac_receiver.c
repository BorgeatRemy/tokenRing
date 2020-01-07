//////////////////////////////////////////////////////////////////////////////////
/// \file mac_receiver.c
/// \brief MAC receiver thread
/// \author Pascal Sartoretti (sap at hevs dot ch)
/// \version 1.0 - original
/// \date  2018-02
//////////////////////////////////////////////////////////////////////////////////
#include "stm32f7xx_hal.h"

#include <stdio.h>
#include <string.h>
#include "main.h"


uint8_t calculateCRC(uint8_t* data){
		uint32_t checksum = 0; 
		for(int i = 0; i < data[2]+3; i++)
		{
			checksum+=data[i]; 		
		}
		return checksum&0x3F; 
}

//////////////////////////////////////////////////////////////////////////////////
// THREAD MAC RECEIVER
//////////////////////////////////////////////////////////////////////////////////
void MacReceiver(void *argument)
{
	struct queueMsg_t queueMsg;							// queue message
	osStatus_t retCode;											// return error code
	uint8_t checksumCalculate; 
	uint8_t * msg;
	uint8_t * toPhy;
	uint8_t * data;
	uint8_t * msgPtr; 
	for (;;)																// loop until doomsday
	{
		//----------------------------------------------------------------------------
		// QUEUE READ										
		//----------------------------------------------------------------------------
		retCode = osMessageQueueGet(queue_macR_id,&queueMsg,NULL,osWaitForever); 	
    CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);		
		
		msgPtr = queueMsg.anyPtr; 
		
		if(msgPtr[0] == TOKEN_TAG){
			//save user data in a new memory pool
			msg = osMemoryPoolAlloc(memPool,osWaitForever);	
			memcpy(msg,msgPtr,16);
			
			//send message to mac sender
			queueMsg.anyPtr = msg; 
			queueMsg.type = TOKEN;
			retCode = osMessageQueuePut(queue_macS_id,&queueMsg,osPriorityNormal,osWaitForever);
			CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
		}
		//-------------- Test if we recept our message ----------------------------------------------									
		else if((msgPtr[0]>>3) == gTokenInterface.myAddress)
		{
				//save user data in a new memory pool
				msg = osMemoryPoolAlloc(memPool,osWaitForever);	
				memcpy(msg,msgPtr,msgPtr[2]+4);
				
				if((msgPtr[1]>>3) == gTokenInterface.myAddress || msgPtr[1]>>3 == BROADCAST_ADDRESS) 
				{
						//verify checksum 
						checksumCalculate = calculateCRC(msgPtr);
						if(checksumCalculate == msgPtr[3+msgPtr[2]]>>2){//checksum calcul == checksum receive				
							//send ack + read (1,1)
							msg[3+msgPtr[2]] |= 0x03;

							data = osMemoryPoolAlloc(memPool,osWaitForever);
							memcpy(data,&msgPtr[3],msgPtr[2]);
							data[msgPtr[2]] = 0; 
							
							//send dataIndication
							switch(msgPtr[1]&0x7)
								{
									case CHAT_SAPI:
										//send data to chat receiver
										queueMsg.anyPtr = data; 
										queueMsg.type = DATA_IND; 
										retCode = osMessageQueuePut(queue_chatR_id,&queueMsg,osPriorityNormal,osWaitForever);
										CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
										break; 
									case TIME_SAPI: 
										//send data to time receiver
										queueMsg.anyPtr = data; 
										queueMsg.type = DATA_IND; 
										retCode = osMessageQueuePut(queue_timeR_id,&queueMsg,osPriorityNormal,osWaitForever);
										CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
										break; 	
								}	
						}		
						else{		
							//send nack and received (1,0)
							msg[3+msgPtr[2]] |= 0x02;					
						}				
				}	
				//si on reçoit un msg de nous
				queueMsg.anyPtr = msg; 
				queueMsg.type = DATABACK;
				retCode = osMessageQueuePut(queue_macS_id,&queueMsg,osPriorityNormal,osWaitForever);
				CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
		}
		//-------------- if we send a message or a broadcast -----------------------------------------
		else if((msgPtr[1]>>3) == gTokenInterface.myAddress || msgPtr[1]>>3 == BROADCAST_ADDRESS){		  
			//save user data in a new memory pool
			msg = osMemoryPoolAlloc(memPool,osWaitForever);	
			memcpy(msg,&msgPtr[3],msgPtr[2]);
			
			// the message is for us --> answer with read and ack/nack
			if((msgPtr[1]>>3) == gTokenInterface.myAddress)
			{
					toPhy = osMemoryPoolAlloc(memPool,osWaitForever);	
					memcpy(toPhy,msgPtr,msgPtr[2]+4);
					//verify checksum 
					checksumCalculate = calculateCRC(msgPtr);
					if(checksumCalculate == msgPtr[3+msgPtr[2]]>>2){//checksum calcul == checksum receive				
						//send ack + read (1,1)
						toPhy[3+toPhy[2]] |= 0x03; 
						queueMsg.anyPtr = toPhy; 
						queueMsg.type = TO_PHY;
						retCode = osMessageQueuePut(queue_phyS_id,&queueMsg,osPriorityNormal,osWaitForever);
						CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);

					}		
					else{		
						//send nack and received (1,0)
						toPhy[3+msgPtr[2]] |= 0x02;
						toPhy[3+msgPtr[2]] &= 0xFE; 
						queueMsg.anyPtr = toPhy; 
						queueMsg.type = TO_PHY;
						retCode = osMessageQueuePut(queue_phyS_id,&queueMsg,osPriorityNormal,osWaitForever);
						CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
					}				
			}	
			//send data to time or chat if the checksum is correct broadcast or myAddress
			if(checksumCalculate == msgPtr[3+msgPtr[2]]>>2){										
				//check which application must reiceved the message
				switch(msgPtr[1]&0x7)
				{
					case CHAT_SAPI:
						//send data to chat receiver
						queueMsg.anyPtr = msg; 
						queueMsg.type = DATA_IND; 
						retCode = osMessageQueuePut(queue_chatR_id,&queueMsg,osPriorityNormal,osWaitForever);
						CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
						break; 
					case TIME_SAPI: 
						//send data to time receiver
						queueMsg.anyPtr = msg; 
						queueMsg.type = DATA_IND; 
						retCode = osMessageQueuePut(queue_timeR_id,&queueMsg,osPriorityNormal,osWaitForever);
						CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
						break; 	
				}
			}		
			else
			{
				retCode = osMemoryPoolFree(memPool,msg);
				CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);				
			}
		}	

		retCode = osMemoryPoolFree(memPool,msgPtr);
		CheckRetCode(retCode,__LINE__,__FILE__,CONTINUE);
	}	
}



