

#ifndef CONV_H
#define	CONV_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "definitions.h"
#include "signals.h"
#include "stdio.h"
    
/* User-Defined Callback Functions to Convert the RAW CAN Data to Values */
/* Numbers are Hardcoded here, to make it more Readable */
    
float CONV_MinVoltage(uint8_t* data);
float CONV_MaxTemp(uint8_t* data);
float CONV_LapTime(uint8_t* data);
float CONV_BestLapTime(uint8_t* data);
uint32_t CONV_FSG_AMI_state(uint8_t* data);
float CONV_MaxMotTemp(uint8_t* data);
float CONV_MaxInvTemp(uint8_t* data);
float CONV_MotorTemp_RR(uint8_t* data);
float CONV_MotorTemp_RL(uint8_t* data);
float CONV_MotorTemp_FL(uint8_t* data);
float CONV_MotorTemp_FR(uint8_t* data);
float CONV_MaxMotorTemp(signals_signal* signal_list, uint32_t signal_list_len);
void CONV_DISP_Motor_Temp(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring);
void CONV_DISP_MinVoltage(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring);
uint32_t CONV_find_string_length(uint8_t* str, uint32_t strlen);

float CONV_max(float* vals, uint32_t valcount);
float CONV_min(float* vals, uint32_t valcount);

#ifdef	__cplusplus
}
#endif

#endif	/* CONV_H */

