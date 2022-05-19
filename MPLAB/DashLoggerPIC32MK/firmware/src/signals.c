#include "signals.h"

void SIGNALS_Interpret(signals_signal* signal_list, uint32_t signal_list_len,
        cancomm_message* message_list, uint32_t message_list_len){
    
    uint8_t databuff[CANCOMM_MAXIMUM_DATA_LENGTH];
    for(uint32_t i=0; i<signal_list_len; i++){
        if(signals_find_data(signal_list[i].id, signal_list[i].interface_number,
                message_list, message_list_len, databuff) == SIGNALS_FOUND)
        {
            switch(signal_list[i].signal_type){
                case SIGNALS_FLOAT_SIGNAL:
                    signal_list[i].value_float = 
                            signal_list[i].convert_float(databuff);
                    break;
                    
                case SIGNALS_UINT32_T_SIGNAL:
                    signal_list[i].value_uint32_t =
                            signal_list[i].convert_uint32_t(databuff);
                    break;
                    
                default:
                    break;
            }
        }    
    }
    
}

signals_result signals_find_data(uint32_t id, uint8_t interface,
        cancomm_message* message_list, uint32_t message_list_len,
        uint8_t* data){
    
    signals_result result = SIGNALS_NOT_FOUND;
    for(uint32_t i=0; i<message_list_len; i++){
        if(message_list[i].id == id && message_list[i].interface_number == interface){
            result = SIGNALS_FOUND;
            for(uint8_t j=0; j<CANCOMM_MAXIMUM_DATA_LENGTH; j++){
                data[j] = message_list[i].data[j];
            }
        }
    }
    
    return result;
}
