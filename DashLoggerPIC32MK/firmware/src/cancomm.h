/* 
 * File:   cancomm.h
 * Author: Frederic
 *
 * Created on 14. Mai 2022, 12:56
 */

#ifndef CANCOMM_H
#define	CANCOMM_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "definitions.h"
    
#define CANCOMM_CAN1_FIFO_TRANS     1
#define CANCOMM_CAN1_FIFO_REC       2
    

#define CANCOMM_MAXIMUM_DATA_LENGTH     8
#define CANCOMM_MAXIMUM_NAME_LENGTH     30
    
typedef enum{
    CANCOMM_CAN_1 = 0,
    CANCOMM_CAN_2,
    CANCOMM_CAN_3,
    CANCOMM_CAN_4
}cancomm_interface;
    
typedef struct{
    uint32_t id;
    cancomm_interface interface;
    uint8_t length;
    uint8_t data [CANCOMM_MAXIMUM_DATA_LENGTH];
    uint32_t timestamp;
    uint8_t friendly_name [CANCOMM_MAXIMUM_NAME_LENGTH];
}cancomm_message;

void CANCOMM_ReadMessages(cancomm_message* message_list,
        uint32_t message_list_len);

#ifdef	__cplusplus
}
#endif

#endif	/* CANCOMM_H */

