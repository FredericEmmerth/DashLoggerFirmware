/**
 * @file command.c
 * @brief This File implements the Prototypes for \ref COMMAND
 * 
 * @author Frederic Emmerth
 * 
 * \ingroup COMMAND
 * \addtogroup COMMAND
 * \{
 * 
 */



#include "command.h"

void COMMAND_Generate(signals_signal* signal_list, uint32_t signal_list_len,
        uint32_t* current_display_signal, SHORTPROTOCOL_Instance* shortProt){
    
    uint32_t display_signal_count;
    
    signals_signal* current_signal;
    
    /* get the count of display signals and if there is one, the current display signal*/
    current_signal = signals_find_display_signal(signal_list, signal_list_len,
            &display_signal_count, *current_display_signal);
    
    /* Only add a new Command to be sent if the last one was sent */
    if(SHORTPROTOCOL_Available(shortProt)==SHORTPROTOCOL_AVAILABLE){
        
        /* Set the Command to be next transmitted by the Shortprotocol */
        SHORTPROTOCOL_Send(shortProt, current_signal->value_string.data,
                current_signal->value_string.length);
    
        *current_display_signal = *current_display_signal + 1;

        if(*current_display_signal >= display_signal_count){
            *current_display_signal = 0;
        }
    
    }
}


/**
 * \}
 */