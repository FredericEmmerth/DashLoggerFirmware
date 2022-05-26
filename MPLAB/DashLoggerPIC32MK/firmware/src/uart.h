/* 
 * File:   uart.h
 * Author: Frederic
 *
 * Created on 23. Mai 2022, 17:10
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "shortprotocol.h"
    
SHORTPROTOCOL_status UART_ReadAvailable( void );
uint8_t UART_ReadByte( void );
SHORTPROTOCOL_status UART_WriteAvailable( void );
void UART_WriteByte(uint8_t byte);

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

