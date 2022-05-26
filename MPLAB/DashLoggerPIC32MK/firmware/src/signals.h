/* 
 * File:   signals.h
 * Author: Frederic
 *
 * Created on 14. Mai 2022, 16:56
 */

#ifndef SIGNALS_H
#define	SIGNALS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "definitions.h"
#include "cancomm.h"
    
#define SIGNALS_MAXIMUM_NAME_LENGTH     30
#define SIGNALS_STRING_MAXIMUM_LENGTH   50
    
typedef enum{
    SIGNALS_FOUND = 0,
    SIGNALS_NOT_FOUND,
    SIGNALS_MATCH,
    SIGNALS_NO_MATCH
}signals_result;

typedef enum{
    SIGNALS_FLOAT_SIGNAL = 0,
    SIGNALS_UINT32_T_SIGNAL,
    SIGNALS_STRING_SIGNAL
}signals_signal_type;

typedef enum{
    SIGNALS_CAN_MESSAGE = 0,
    SIGNALS_INTERNAL_SIGNAL
}signals_signal_origin;

typedef struct{
    uint32_t length;
    uint8_t data[SIGNALS_STRING_MAXIMUM_LENGTH];
}SIGNALS_string;

typedef struct signals_signal_struct signals_signal;
     
struct signals_signal_struct{
    uint32_t id;
    uint8_t interface_number;
    signals_signal_type signal_type;
    
    float(*can_convert_float)(uint8_t* data);
    float(*internal_convert_float)(signals_signal* signal_list,
            uint32_t signal_list_len);
    float value_float;
    
    uint32_t(*can_convert_uint32_t)(uint8_t* data);
    uint32_t(*internal_convert_uint32_t)(signals_signal* signal_list,
            uint32_t signal_list_len);
    uint32_t value_uint32_t;
    
    void (*can_convert_string)(uint8_t* data, SIGNALS_string* string);
    void (*internal_convert_string)(signals_signal* signal_list,
            uint32_t signal_list_len, SIGNALS_string* string);
    SIGNALS_string value_string;
    
    uint8_t friendly_name[SIGNALS_MAXIMUM_NAME_LENGTH];
    uint32_t timestamp;
    signals_signal_origin origin;
};

void SIGNALS_Interpret(signals_signal* signal_list, uint32_t signal_list_len,
        cancomm_message* message_list, uint32_t message_list_len);

signals_result signals_find_data(uint32_t id, uint8_t interface,
        cancomm_message* message_list, uint32_t message_list_len,
        uint8_t* data);

signals_signal* signals_find_signal( signals_signal* signal_list,
        uint32_t signal_list_len, void(*Callback)(void));

signals_result signals_compare_names(uint8_t* first, uint32_t firstlen,
        uint8_t* second, uint32_t secondlen);

#ifdef	__cplusplus
}
#endif

#endif	/* SIGNALS_H */

