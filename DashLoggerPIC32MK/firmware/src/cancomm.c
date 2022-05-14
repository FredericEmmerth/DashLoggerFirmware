#include "cancomm.h"


static cancomm_message cancomm_message_list [] = {
    {.id=0xA2,  .interface=CANCOMM_CAN_1, .length=8, .friendly_name="BCU_Extrem_Voltages" },
    {.id=0xA3,  .interface=CANCOMM_CAN_1, .length=8, .friendly_name="BCU_Extrem_Temperatures"},
    {.id=0x711, .interface=CANCOMM_CAN_1, .length=8, .friendly_name="VCU_LapInfo"},
    {.id=0x502, .interface=CANCOMM_CAN_1, .length=8, .friendly_name="FSG_System_status"},
    {.id=0xA4,  .interface=CANCOMM_CAN_1, .length=2, .friendly_name="BCU_SCstatus"},
    {.id=0x239, .interface=CANCOMM_CAN_1, .length=8, .friendly_name="VCU_Motor_Temps"},
    {.id=0x23A, .interface=CANCOMM_CAN_1, .length=8, .friendly_name="VCU_Inverter_Temp"}
};

static uint32_t cancomm_message_list_len = sizeof(cancomm_message_list) / sizeof(cancomm_message);

void CANCOMM_ReadMessages( void ){
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
            for(uint32_t i=0; i<cancomm_message_list_len; i++){
                /* If it is, copy the data into the message_list*/
                if(cancomm_message_list[i].id == temp_id){
                    for(uint8_t j=0; j<CANCOMM_MAXIMUM_DATA_LENGTH; j++){
                        cancomm_message_list[i].data[j] = temp_data[j];
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
    
