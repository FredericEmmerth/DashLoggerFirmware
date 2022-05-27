#include "command.h"

void COMMAND_Generate(signals_signal* signal_list, uint32_t signal_list_len,
        uint32_t* current_display_signal, SHORTPROTOCOL_Instance* shortProt){
    
    uint32_t display_signal_count;
    
    signals_signal* current_signal;
    
    /* get the count of display signals and if there is one, the current display signal*/
    current_signal = signals_find_display_signal(signal_list, signal_list_len,
            &display_signal_count, *current_display_signal);
    
    if(SHORTPROTOCOL_Available(shortProt)==SHORTPROTOCOL_AVAILABLE){
        
        SHORTPROTOCOL_Send(shortProt, current_signal->value_string.data,
                current_signal->value_string.length);
    
        *current_display_signal++;

        if(*current_display_signal >= display_signal_count){
            *current_display_signal = 0;
        }
    
    }
}