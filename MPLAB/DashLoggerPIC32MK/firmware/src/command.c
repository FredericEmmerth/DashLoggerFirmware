#include "command.h"

void COMMAND_Generate(signals_signal* signal_list, uint32_t signal_list_len,
        COMMAND_Command* command_list, uint32_t command_list_len,
        uint32_t* current_command, SHORTPROTOCOL_Instance* shortProt){
    
    uint8_t buffer[SHORTPROTOCOL_MAXIMUM_COMMAND_LENGTH];
    

    
    if(SHORTPROTOCOL_Available(shortProt)==SHORTPROTOCOL_AVAILABLE){
        
        sprintf((char*)buffer,"#SSC %d,\"%s\";\n",
                command_list[*current_command].object_id,
                signals_find_signal(signal_list,signal_list_len,
                command_list[*current_command].Signal)->value_string.data);
        
        
        SHORTPROTOCOL_Send(shortProt, buffer,
                CONV_find_string_length(buffer, SHORTPROTOCOL_MAXIMUM_COMMAND_LENGTH));
    }
    
    

SHORTPROTOCOL_status SHORTPROTOCOL_Send(SHORTPROTOCOL_Instance* inst,
        uint8_t* data, uint32_t length);
}