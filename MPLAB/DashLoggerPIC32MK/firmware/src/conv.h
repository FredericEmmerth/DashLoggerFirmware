/**
 * @file conv.h
 * @brief This File defines the Prototypes for \ref CONV
 * 
 * @author Frederic Emmerth
 * 
 * \ingroup CONV
 * 
 */

/**
 * \defgroup CONV CONV
 * In this Module the Callback Functions for the Signals from the 
 * \ref SIGNALS Module are defined. 
 * 
 * There are Callback Functions for CAN Message Interpretation, for Internal
 * Message Processing and Display Command Generation.
 * 
 * \addtogroup CONV
 * \{
 */

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
    
/* CAN Signals*/
float CONV_MinBatVoltage(uint8_t* data);
float CONV_MaxBatTemp(uint8_t* data);
float CONV_LapTime(uint8_t* data);
float CONV_BestLapTime(uint8_t* data);
uint32_t CONV_FSG_AMI_state(uint8_t* data);
float CONV_MaxMotTemp(uint8_t* data);
float CONV_MaxInvTemp(uint8_t* data);
float CONV_InverterTemp_FL(uint8_t* data);
float CONV_InverterTemp_FR(uint8_t* data);
float CONV_InverterTemp_RL(uint8_t* data);
float CONV_InverterTemp_RR(uint8_t* data);
float CONV_MotorTemp_RR(uint8_t* data);
float CONV_MotorTemp_RL(uint8_t* data);
float CONV_MotorTemp_FL(uint8_t* data);
float CONV_MotorTemp_FR(uint8_t* data);

/* Internal Signals */
float CONV_MaxMotorTemp(signals_signal* signal_list, uint32_t signal_list_len);
float CONV_LastLapTime(signals_signal* signal_list, uint32_t signal_list_len);
float CONV_MaxInverterTemp(signals_signal* signal_list,
        uint32_t signal_list_len);

/* Display Signals */
void CONV_DISP_Motor_Temp(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring);
void CONV_DISP_MinVoltage(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring);
void CONV_DISP_LapDelta(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring);
void CONV_DISP_LapTime(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring);
void CONV_DISP_LastLapTime(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring);
void CONV_DISP_InverterTemp(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring);
void CONV_DISP_MaxBatTemp(signals_signal* signal_list, uint32_t signal_list_len,
        SIGNALS_string* outstring);
void CONV_DISP_FSG_AMI_State(signals_signal* signal_list,
        uint32_t signal_list_len, SIGNALS_string* outstring);

/* Useful Arithmetic Functions (No Signal Callback Functions)*/
uint32_t CONV_find_string_length(uint8_t* str, uint32_t strlen);
float CONV_max(float* vals, uint32_t valcount);
float CONV_min(float* vals, uint32_t valcount);

#ifdef	__cplusplus
}
#endif

#endif	/* CONV_H */

/**
 * \}
 */

