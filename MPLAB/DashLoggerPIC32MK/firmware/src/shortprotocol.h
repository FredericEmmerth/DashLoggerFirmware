/* 
 * File:   shortprotocol.h
 * Author: Frederic
 *
 * Created on 19. Mai 2022, 13:37
 */

#ifndef SHORTPROTOCOL_H
#define	SHORTPROTOCOL_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "definitions.h"
    
typedef struct{
    uint8_t(*readByte)(void);
    uint8_t(*readAvailable)(void);
    uint8_t(*writeByte)(uint8_t);
    uint8_t(*writeAvailable)(void);
    
}SHORTPROTOCOL_Instance;
    
void SHORTPROTOCOL_Send(SHORTPROTOCOL_Instance inst, uint8_t* data, uint32_t length);

void SHORTPROTOCOL_Update(SHORTPROTOCOL_Instance inst);


#ifdef	__cplusplus
}
#endif

#endif	/* SHORTPROTOCOL_H */

