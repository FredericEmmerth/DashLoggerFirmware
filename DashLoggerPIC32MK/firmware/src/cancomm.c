#include "cancomm.h"




void CANCOMM_ReadMessages(cancomm_message* message_list, uint32_t message_list_len){
    uint8_t message_recieved = 0;
    uint32_t temp_id;
    uint8_t temp_length;
    uint8_t temp_data[CANCOMM_MAXIMUM_DATA_LENGTH];
    CANFD_MSG_RX_ATTRIBUTE temp_msgAttr;
    uint32_t temp_timestamp;
    
    while(1){
        
        /* Try to get a Message from FIFO */
        message_recieved = CAN1_MessageReceive(
                &temp_id,
                &temp_length,
                temp_data,
                &temp_timestamp,
                CANCOMM_CAN1_FIFO_REC,
                &temp_msgAttr);
        
        /* If there was a Message in the FIFO interpret it */
        if(message_recieved){
            /* See if the Message is in cancomm_message_list */
            for(uint32_t i=0; i<message_list_len; i++){
                /* If it is, copy the data into the message_list*/
                if(message_list[i].id == temp_id){
                    for(uint8_t j=0; j<CANCOMM_MAXIMUM_DATA_LENGTH; j++){
                        message_list[i].data[j] = temp_data[j];
                    }
                    /* Break the Loop after finding the Message */
                    break;
                }
            }
        /* If there was no Message in the FIFO break Loop */
        }else{
            break;
        }
    }
    
}
