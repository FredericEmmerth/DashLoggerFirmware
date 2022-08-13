/**
 * @file conv.c
 * @brief This File implements the Prototypes for \ref CONV
 * 
 * @author Frederic Emmerth
 * 
 * \ingroup CONV
 * \addtogroup CONV
 * \{
 * 
 */


#include "conv.h"

/*############################################################################*/
/*############################# CAN Signals ##################################*/
/*############################################################################*/

float CONV_MinBatVoltage(uint8_t* data){
    uint16_t temp;
    temp = (data[7] << 8) | data[6];
    return (float)0.0001 * temp;  
}

float CONV_MaxBatTemp(uint8_t* data){
    int16_t temp = (data[5] << 8) | data[4];
    return temp * 0.01;
}

float CONV_LapTime(uint8_t* data){
    uint32_t temp = ((data[2]&0x0F)<<16)|(data[1]<<8)|data[0];
    return temp * 0.001;    
}

float CONV_BestLapTime(uint8_t* data){
    uint32_t temp = (data[4]<<12)|(data[3]<<4)|((data[2]&0xF0)>>4);
    return temp * 0.001;    
}

uint32_t CONV_FSG_AMI_state(uint8_t* data){
    uint8_t state = (data[0] & 0xE0)>>5;
    return state;
}

float CONV_InverterTemp_FL(uint8_t* data){    
    int16_t temp;
    temp = (data[1]<<8) | data[0];
    return (float)temp * 0.1; 
}

float CONV_InverterTemp_FR(uint8_t* data){    
    int16_t temp;
    temp = (data[3]<<8) | data[2];
    return (float)temp * 0.1; 
}

float CONV_InverterTemp_RL(uint8_t* data){    
    int16_t temp;
    temp = (data[5]<<8) | data[4];
    return (float)temp * 0.1; 
}

float CONV_InverterTemp_RR(uint8_t* data){    
    int16_t temp;
    temp = (data[7]<<8) | data[6];
    return (float)temp * 0.1; 
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

/*############################################################################*/
/*############################# Internal Signals #############################*/
/*############################################################################*/

float CONV_LastLapTime(signals_signal* signal_list, uint32_t signal_list_len){
    
    static float last_reported_value;
    static float last_lap;
    
    float reported_lap_value = signals_find_signal(signal_list, signal_list_len,
            (void(*)(void))CONV_LapTime)->value_float;
    
    if(reported_lap_value != last_reported_value){
        last_lap = last_reported_value;
    }
    
    
    last_reported_value = reported_lap_value;
    
    return last_lap;
}

float CONV_MaxInverterTemp(signals_signal* signal_list,
        uint32_t signal_list_len){
    
    signals_signal* rr_temp = signals_find_signal(signal_list, signal_list_len,
            (void(*)(void))CONV_InverterTemp_RR);
    
    signals_signal* rl_temp = signals_find_signal(signal_list, signal_list_len,
            (void(*)(void))CONV_InverterTemp_FL);
    
    signals_signal* fr_temp = signals_find_signal(signal_list, signal_list_len,
            (void(*)(void))CONV_InverterTemp_FR);
    
    signals_signal* fl_temp = signals_find_signal(signal_list, signal_list_len,
            (void(*)(void))CONV_InverterTemp_RL);
    
    float temperatureValues[4] = 
    {
        rr_temp->value_float,
        rl_temp->value_float,
        fr_temp->value_float,
        fl_temp->value_float
    };
    
    return CONV_max(temperatureValues, 4);
}

float CONV_MaxMotorTemp(signals_signal* signal_list, uint32_t signal_list_len){
    
    signals_signal* rr_temp = signals_find_signal(signal_list, signal_list_len,
            (void(*)(void))CONV_MotorTemp_RR);
    
    signals_signal* rl_temp = signals_find_signal(signal_list, signal_list_len,
            (void(*)(void))CONV_MotorTemp_FL);
    
    signals_signal* fr_temp = signals_find_signal(signal_list, signal_list_len,
            (void(*)(void))CONV_MotorTemp_FR);
    
    signals_signal* fl_temp = signals_find_signal(signal_list, signal_list_len,
            (void(*)(void))CONV_MotorTemp_RL);
    
    float temperatureValues[4] = 
    {
        rr_temp->value_float,
        rl_temp->value_float,
        fr_temp->value_float,
        fl_temp->value_float
    };
    
    return CONV_max(temperatureValues, 4);
}

/*############################################################################*/
/*############################# Display Signals ##############################*/
/*############################################################################*/

void CONV_DISP_MinVoltage(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring){
    float minvoltage = signals_find_signal(signal_list,
        signal_list_len,(void(*)(void))CONV_MinBatVoltage)->value_float;
    
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



void CONV_DISP_InverterTemp(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring){
    
    float invtemp = signals_find_signal(signal_list,
        signal_list_len,(void(*)(void))CONV_MaxInverterTemp)->value_float;
    sprintf((char*)outstring->data,"#SSC %d,\"%4.1f°C\";\n",8,invtemp);
    
    outstring->length = CONV_find_string_length(outstring->data,
                                SIGNALS_STRING_MAXIMUM_LENGTH);
    
}

void CONV_DISP_LapDelta(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring){
    
    float bestlap = signals_find_signal(signal_list, signal_list_len,
            (void(*)(void))CONV_BestLapTime)->value_float;
    
    float thislap = signals_find_signal(signal_list, signal_list_len,
            (void(*)(void))CONV_LapTime)->value_float;
    
    float timedelta = bestlap - thislap;
    
    sprintf((char*)outstring->data,"#SSC %d,\"%4.2fs\";\n",5,timedelta);
    
    outstring->length = CONV_find_string_length(outstring->data,
                                SIGNALS_STRING_MAXIMUM_LENGTH);
    
}

void CONV_DISP_LapTime(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring){
    float thislap = signals_find_signal(signal_list, signal_list_len,
            (void(*)(void))CONV_LapTime)->value_float;
    
    sprintf((char*)outstring->data,"#SSC %d,\"%4.2fs\";\n",2,thislap);
    
    outstring->length = CONV_find_string_length(outstring->data,
                                SIGNALS_STRING_MAXIMUM_LENGTH);
    
}

void CONV_DISP_LastLapTime(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring){
    float lastlap = signals_find_signal(signal_list, signal_list_len,
            (void(*)(void))CONV_LastLapTime)->value_float;
    
    sprintf((char*)outstring->data,"#SSC %d,\"%4.2fs\";\n",4,lastlap);
    
    outstring->length = CONV_find_string_length(outstring->data,
                                SIGNALS_STRING_MAXIMUM_LENGTH);
    
}

void CONV_DISP_MaxBatTemp(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring){
    float maxtemp = signals_find_signal(signal_list, signal_list_len,
            (void(*)(void))CONV_MaxBatTemp)->value_float;
    
    sprintf((char*)outstring->data,"#SSC %d,\"%4.1f°C\";\n",6,maxtemp);
    
    outstring->length = CONV_find_string_length(outstring->data,
                                SIGNALS_STRING_MAXIMUM_LENGTH);
    
}

void CONV_DISP_FSG_AMI_State(signals_signal* signal_list,
        uint32_t signal_list_len, SIGNALS_string* outstring){
    
    uint8_t statenum = signals_find_signal(signal_list, signal_list_len,
            (void(*)(void))CONV_FSG_AMI_state)->value_uint32_t;
    
    if(statenum > 7){
        statenum = 8;
    }
    
    uint8_t statenames [9][15] ={
        "Manual",
        "Acceleration",
        "Skidpad",
        "Trackdrive",
        "Braketest",
        "Inspection",
        "Autocross",
        "Selecting",
        "Unknown"
    };
    
    sprintf((char*)outstring->data,"#SSC %d,\"%s\";\n",12,statenames[statenum]);
    
    outstring->length = CONV_find_string_length(outstring->data,
                                SIGNALS_STRING_MAXIMUM_LENGTH);
    
}

/*############################################################################*/
/*############################# Helpful Functions ############################*/
/*############################################################################*/

uint32_t CONV_find_string_length(uint8_t* str, uint32_t strlen){
    
    uint32_t i=0;
    for(; i<strlen; i++){
        if(str[i] == 0x00){
            break;
        }
    }
    return i;
}

float CONV_min(float* vals, uint32_t valcount){
    float minimum = 10000;
    for(uint32_t i=0; i<valcount; i++){
        if(vals[i] < minimum){
            minimum = vals[i];
        }
    }
    return minimum;
}

float CONV_max(float* vals, uint32_t valcount){
    float maximum = -10000;
    for(uint32_t i=0; i<valcount; i++){
        if(vals[i] > maximum){
            maximum = vals[i];
        }
    }
    return maximum;
}

/**
 * \}
 */
