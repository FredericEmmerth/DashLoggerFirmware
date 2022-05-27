#include "signals.h"

void SIGNALS_Interpret(signals_signal* signal_list, uint32_t signal_list_len,
    cancomm_message* message_list, uint32_t message_list_len){
    
    uint8_t databuff[CANCOMM_MAXIMUM_DATA_LENGTH];
    for(uint32_t i=0; i<signal_list_len; i++){
        if(signal_list[i].type == SIGNALS_CAN_MESSAGE){
            if(signals_find_data(signal_list[i].id, signal_list[i].interface_number,
                    message_list, message_list_len, databuff) == SIGNALS_FOUND)
            {
                switch(signal_list[i].data_type){
                    case SIGNALS_FLOAT_SIGNAL:
                        signal_list[i].value_float = 
                                signal_list[i].can_convert_float(databuff);
                        break;

                    case SIGNALS_UINT32_T_SIGNAL:
                        signal_list[i].value_uint32_t =
                                signal_list[i].can_convert_uint32_t(databuff);
                        break;
                    
                    case SIGNALS_STRING_SIGNAL:
                        signal_list[i].can_convert_string(databuff, 
                                &(signal_list[i].value_string));
                        break;

                    default:
                        break;
                }
            }
        }else if(signal_list[i].type == SIGNALS_INTERNAL_SIGNAL){
            switch(signal_list[i].data_type){
                    case SIGNALS_FLOAT_SIGNAL:
                        signal_list[i].value_float = 
                                signal_list[i].internal_convert_float(
                                        signal_list,signal_list_len);
                        break;

                    case SIGNALS_UINT32_T_SIGNAL:
                        signal_list[i].value_uint32_t =
                                signal_list[i].internal_convert_uint32_t(
                                        signal_list, signal_list_len);
                        break;
                        
                    case SIGNALS_STRING_SIGNAL:
                        signal_list[i].internal_convert_string(signal_list,
                                signal_list_len, &(signal_list[i].value_string));
                        break;

                    default:
                        break;
            }
        }else if(signal_list[i].type == SIGNALS_DISPLAY_SIGNAL){
            switch(signal_list[i].data_type){

                    case SIGNALS_STRING_SIGNAL:
                        signal_list[i].internal_convert_string(signal_list,
                                signal_list_len, &(signal_list[i].value_string));
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
            break;
        }
    }
    
    return result;
}

signals_result signals_compare_names(uint8_t* first, uint32_t firstlen,
        uint8_t* second, uint32_t secondlen){
    
    uint32_t searchlen;
    
    /* Set searchlen to the shorter length */
    if(firstlen > secondlen){
        searchlen = secondlen;
    }else if (secondlen > firstlen){
        searchlen = firstlen;
    }else{
        /* The Strings have equal length */
        searchlen = firstlen;
    }
    
    signals_result res = SIGNALS_MATCH;
    
    for(uint32_t i=0; i<searchlen; i++){
        if(first[i] != second[i]){
            res = SIGNALS_NO_MATCH;
            break;
        }
    }
    
    return res;
}

signals_signal* signals_find_signal( signals_signal* signal_list,
        uint32_t signal_list_len, void(*Callback)(void)){
    
    for(uint32_t i=0; i<signal_list_len; i++){
        if(Callback == (void(*)(void))signal_list[i].can_convert_float        ||
           Callback == (void(*)(void))signal_list[i].can_convert_uint32_t     ||
           Callback == (void(*)(void))signal_list[i].internal_convert_float   ||
           Callback == (void(*)(void))signal_list[i].internal_convert_uint32_t||
           Callback == (void(*)(void))signal_list[i].internal_convert_string  ||
           Callback == (void(*)(void))signal_list[i].can_convert_string        )
        { 
            return &(signal_list[i]);
        }
    }
    
    return NULL;
}

/* this function returns the total count of display signals in the list, and */
/* if there is at least one display signal, the nth display signal by needle*/

signals_signal* signals_find_display_signal(signals_signal* signal_list,
        uint32_t signal_list_len, uint32_t* dispSignalCount, uint32_t needle){
    
    uint32_t counter = 0;
    signals_signal* foundNeedle = NULL;
    for(uint32_t i=0; i<signal_list_len; i++){
        if(signal_list[i].type == SIGNALS_DISPLAY_SIGNAL){
            if(needle == counter){
                foundNeedle = &(signal_list[i]);
            }
            counter++;
        }
    }
    
    *dispSignalCount = counter;
    return foundNeedle;
}
