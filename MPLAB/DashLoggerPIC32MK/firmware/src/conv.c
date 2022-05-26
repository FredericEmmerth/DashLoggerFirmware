#include "conv.h"

float CONV_MinVoltage(uint8_t* data){
    return 1.0;
}

float CONV_MaxTemp(uint8_t* data){
    return 1.0;    
}

float CONV_LapTime(uint8_t* data){
    return 1.0;    
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

float CONV_MaxMotorTemp(signals_signal* signal_list, uint32_t signal_list_len){
    return 1.0;
}
