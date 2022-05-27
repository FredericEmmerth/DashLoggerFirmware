/**
 * @file cancomm.c
 * @brief This File Implements the Prototypes for \ref CANCOMM
 * 
 * @author Frederic Emmerth
 * 
 * \ingroup CANCOMM
 * 
 * \addtogroup CANCOMM
 * \{
 * 
 */






#include "cancomm.h"


void CANCOMM_ReadMessages(cancomm_message* message_list,
        uint32_t message_list_len,
        cancomm_interface* interface_list,
        uint8_t interface_list_len){
    
    /* Local Variables where the Frame Data can be temporarily saved */
    uint8_t message_recieved = 0;
    uint32_t temp_id;
    uint8_t temp_length;
    uint8_t temp_data[CANCOMM_MAXIMUM_DATA_LENGTH];
    CANFD_MSG_RX_ATTRIBUTE temp_msgAttr;
    uint32_t temp_timestamp;
    
    /* Loop over every Interface and get the recieved Messages from the FIFOs*/
    for(uint8_t current_interface = 0;
            current_interface < interface_list_len;
            current_interface ++)
        {
        
        /* Endless Loop, broken internally when there is no data in the fifo */    
        while(1){

            /* Try to get a Message from FIFO */
            message_recieved = interface_list[current_interface].MessageReceive(
                    &temp_id,
                    &temp_length,
                    temp_data,
                    &temp_timestamp,
                    interface_list[current_interface].receiveFifo,
                    &temp_msgAttr);

            /* If there was a Message in the FIFO interpret it */
            if(message_recieved){
                /* See if the Message is in cancomm_message_list */
                for(uint32_t i=0; i<message_list_len; i++){
                    /* If ID and Interface match, copy the data into the message_list*/
                    if((message_list[i].id == temp_id)&&
                            (message_list[i].interface_number == 
                            interface_list[current_interface].number))
                    {
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
    
}

/**
 * \}
 */