/* 
 * File:   shortprotocol.h
 * Author: Frederic
 *
 * Created on 11. Mai 2022, 23:54
 */

#ifndef SHORTPROTOCOL_H
#define	SHORTPROTOCOL_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>
    
#define SHORTPROTOCOL_SEND_BUFFER_SIZE 100

void SHORTPROTOCOL_Send(uint8_t* chars, uint32_t length);

#ifdef	__cplusplus
}
#endif

#endif	/* SHORTPROTOCOL_H */

