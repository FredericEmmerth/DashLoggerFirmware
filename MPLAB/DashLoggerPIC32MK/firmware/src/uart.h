/**
 * @file uart.h
 * @brief This File defines the Prototypes for \ref UART
 * 
 * @author Frederic Emmerth
 * 
 * \ingroup UART
 * 
 */

/**
 * \defgroup UART UART
 * This Module defines the Interface Functions used by \ref SHORTPROTOCOL.
 * 
 * \addtogroup UART
 * \{
 */


#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "shortprotocol.h"
    
/**
 * Returns wether or not a Byte can be read from UART
 * @return SHORTPROTOCOL_AVAILABLE if a Byte can be read from UART and 
 * SHORTPROTOCOL_NOT_AVAILABLE if no Byte can be read from UART
 */
SHORTPROTOCOL_status UART_ReadAvailable( void );

/**
 * Reads one Byte from UART
 * @return The Byte read from UART
 */
uint8_t UART_ReadByte( void );

/**
 * Returns wether or not a Byte can be written to UART
 * @return SHORTPROTOCOL_AVAILABLE if a Byte can be written to UART and 
 * SHORTPROTOCOL_NOT_AVAILABLE if no Byte can be written to UART
 */
SHORTPROTOCOL_status UART_WriteAvailable( void );

/**
 * Writes one Byte to UART
 */
void UART_WriteByte(uint8_t byte);

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

/**
 * \}
 */

