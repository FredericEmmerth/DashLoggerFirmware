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
#include "stdio.h"
#include "conv.h"
    
typedef struct {
    uint32_t object_id;
    void(*Signal)(void);
}COMMAND_Command;

void COMMAND_Generate(signals_signal* signal_list, uint32_t signal_list_len,
        COMMAND_Command* command_list, uint32_t command_list_len,
        uint32_t* current_command, SHORTPROTOCOL_Instance* shortProt);


#ifdef	__cplusplus
}
#endif

#endif	/* COMMAND_H */

