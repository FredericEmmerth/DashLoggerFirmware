/* 
 * File:   command.h
 * Author: Frederic
 *
 * Created on 23. Mai 2022, 17:22
 */

#ifndef COMMAND_H
#define	COMMAND_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "definitions.h"
#include "signals.h"
#include "shortprotocol.h"
    
typedef struct {
    uint32_t currentCommand;
    uint32_t commandCount;
    void(*CommandCallback)(uint32_t commandNum);
}COMMAND_Instance;

void COMMAND_Generate(signals_signal* signal_list, uint32_t signal_list_len, 
        SHORTPROTOCOL_Instance* inst);


#ifdef	__cplusplus
}
#endif

#endif	/* COMMAND_H */

