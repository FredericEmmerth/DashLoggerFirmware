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

#define CANCOMM_MAXIMUM_DATA_LENGTH     8
#define CANCOMM_MAXIMUM_NAME_LENGTH     30

typedef struct{
    uint8_t number;
    uint8_t receiveFifo;
    uint8_t transmitFifo;
    bool (*MessageTransmit)(uint32_t id,
            uint8_t length, uint8_t* data,
            uint8_t fifoQueueNum, CANFD_MODE mode,
            CANFD_MSG_TX_ATTRIBUTE msgAttr);
    bool (*MessageReceive)(uint32_t *id,
            uint8_t *length, uint8_t *data,
            uint32_t *timestamp, uint8_t fifoNum,
            CANFD_MSG_RX_ATTRIBUTE *msgAttr);
}cancomm_interface;
    
typedef struct{
    uint32_t id;
    uint8_t interface_number;
    uint8_t length;
    uint8_t data [CANCOMM_MAXIMUM_DATA_LENGTH];
    uint32_t timestamp;
    uint8_t friendly_name [CANCOMM_MAXIMUM_NAME_LENGTH];
}cancomm_message;

void CANCOMM_ReadMessages(cancomm_message* message_list,
        uint32_t message_list_len,
        cancomm_interface* interface_list,
        uint8_t interface_list_len);

#ifdef	__cplusplus
}
#endif

#endif	/* CANCOMM_H */

