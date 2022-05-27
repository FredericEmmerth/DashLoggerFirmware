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

void COMMAND_Generate(signals_signal* out_signal_list, uint32_t signal_list_len,
        uint32_t* next_command, SHORTPROTOCOL_Instance* shortProt);


#ifdef	__cplusplus
}
#endif

#endif	/* COMMAND_H */

