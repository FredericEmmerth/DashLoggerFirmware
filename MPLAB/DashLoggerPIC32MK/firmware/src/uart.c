#include "uart.h"

SHORTPROTOCOL_status UART_ReadAvailable( void ){
    if(UART3_ReceiverIsReady()){
        return SHORTPROTOCOL_AVAILABLE;
    }else{
        return SHORTPROTOCOL_NOT_AVAILABLE;
    }
}

uint8_t UART_ReadByte( void ){
    return UART3_ReadByte();
}

SHORTPROTOCOL_status UART_WriteAvailable( void ){
    if(UART3_TransmitterIsReady()){
        return SHORTPROTOCOL_AVAILABLE;
    }else{
        return SHORTPROTOCOL_NOT_AVAILABLE;
    }
}

void UART_WriteByte(uint8_t byte){
    UART3_WriteByte(byte);
}

