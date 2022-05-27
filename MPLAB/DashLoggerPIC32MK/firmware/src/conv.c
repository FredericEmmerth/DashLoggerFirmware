#include "conv.h"

float CONV_MinVoltage(uint8_t* data){
    uint16_t temp;
    temp = (data[7] << 8) | data[6];
    return (float)0.0001 * temp;  
}

float CONV_MaxTemp(uint8_t* data){
    return 1.0;
}

float CONV_LapTime(uint8_t* data){
    
    return 1.0;    
}

float CONV_BestLapTime(uint8_t* data){
    uint32_t temp = (data[4]<<12)|(data[3]<<4)|((data[2]&0xF0)>>4);
    return temp * 0.001;    
}

uint32_t CONV_FSG_AMI_state(uint8_t* data){
    return 1;
}

float CONV_MotorTemp_RR(uint8_t* data){    
    int16_t temp;
    temp = (data[6] | (data[7]  << 8));
    return (float)temp * 0.1; 
}

float CONV_MotorTemp_RL(uint8_t* data){
    int16_t temp;
    temp = (data[4] | (data[5] << 8));
    return (float)temp * 0.1;
}

float CONV_MotorTemp_FL(uint8_t* data){
    int16_t temp;
    temp = (data[0] | (data[1] << 8));
    return (float)temp * 0.1;
}

float CONV_MotorTemp_FR(uint8_t* data){
    int16_t temp;
    temp = (data[2] | (data[3] << 8));
    return (float)temp * 0.1;
}

float CONV_MaxInvTemp(uint8_t* data){
    return 1.0;
}

float CONV_min(float* vals, uint32_t valcount){
    float minimum;
    for(uint32_t i=0; i<valcount; i++){
        if(vals[i] < minimum){
            minimum = vals[i];
        }
    }
    return minimum;
}

float CONV_max(float* vals, uint32_t valcount){
    float maximum;
    for(uint32_t i=0; i<valcount; i++){
        if(vals[i] > maximum){
            maximum = vals[i];
        }
    }
    return maximum;
}

float CONV_MaxMotorTemp(signals_signal* signal_list, uint32_t signal_list_len){
    
    signals_signal* rr_temp = signals_find_signal(signal_list, signal_list_len,
            (void*)CONV_MotorTemp_RR);
    
    signals_signal* rl_temp = signals_find_signal(signal_list, signal_list_len,
            (void*)CONV_MotorTemp_FL);
    
    signals_signal* fr_temp = signals_find_signal(signal_list, signal_list_len,
            (void*)CONV_MotorTemp_FR);
    
    signals_signal* fl_temp = signals_find_signal(signal_list, signal_list_len,
            (void*)CONV_MotorTemp_RL);
    
    float temperatureValues[4] = 
    {
        rr_temp->value_float,
        rl_temp->value_float,
        fr_temp->value_float,
        fl_temp->value_float
    };
    
    return CONV_max(temperatureValues, 4);
}

void CONV_DISP_MinVoltage(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring){
    float minvoltage = signals_find_signal(signal_list,
        signal_list_len,(void(*)(void))CONV_MinVoltage)->value_float;
    
    sprintf((char*)outstring->data,"#SSC %d,\"%4.3fV\";\n",9,minvoltage);
    
    outstring->length = CONV_find_string_length(outstring->data,
                                SIGNALS_STRING_MAXIMUM_LENGTH);
}

void CONV_DISP_Motor_Temp(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring){
    
    float maxtemp = signals_find_signal(signal_list,
        signal_list_len,(void(*)(void))CONV_MaxMotorTemp)->value_float;
    sprintf((char*)outstring->data,"#SSC %d,\"%4.1f°C\";\n",11,maxtemp);
    
    outstring->length = CONV_find_string_length(outstring->data,
                                SIGNALS_STRING_MAXIMUM_LENGTH);
    
}

uint32_t CONV_find_string_length(uint8_t* str, uint32_t strlen){
    
    uint32_t i=0;
    for(; i<strlen; i++){
        if(str[i] == 0x00){
            break;
        }
    }
    return i;
}
