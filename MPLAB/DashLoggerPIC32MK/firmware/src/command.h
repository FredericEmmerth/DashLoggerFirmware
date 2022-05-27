/**
 * @file command.h
 * @brief This File defines the Prototypes for \ref COMMAND
 * 
 * @author Frederic Emmerth
 * 
 * \ingroup COMMAND
 * 
 */

/**
 * \defgroup COMMAND COMMAND
 * This Module Picks the \ref signals_signal from a signal_list wich are of Type
 * SIGNALS_DISPLAY_SIGNAL and Generates a Comand to change the Text Object on
 * the Display with ID \ref signals_signal.oject_id to
 * \ref signals_signal.string_value.
 * 
 * \addtogroup COMMAND
 * \{
 */

#ifndef COMMAND_H
#define	COMMAND_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "definitions.h"
#include "signals.h"
#include "shortprotocol.h"

/**
 * @brief Adds a Command from \p signal_list if \p shortProt is ready.
 * 
 * \param signal_list A list of \ref signals_signal
 * \param signal_list_len The Length of \p signal_list
 * \param next_command A pointer to an Integer. This represents the next
 *  Command to be Sent. This value should only be changed by this Function.
 * \param shortProt A \ref SHORTPROTOCOL_Instance for sending Packets to the
 *  Display.
 * 
 */
void COMMAND_Generate(signals_signal* signal_list, uint32_t signal_list_len,
        uint32_t* next_command, SHORTPROTOCOL_Instance* shortProt);


#ifdef	__cplusplus
}
#endif

#endif	/* COMMAND_H */

/**
 * \}
 */

