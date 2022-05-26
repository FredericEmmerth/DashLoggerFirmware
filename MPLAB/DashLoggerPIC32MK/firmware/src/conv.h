/* 
 * File:   conv.h
 * Author: Frederic
 *
 * Created on 14. Mai 2022, 17:12
 */

#ifndef CONV_H
#define	CONV_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "definitions.h"
#include "signals.h"
    
/* User-Defined Callback Functions to Convert the RAW CAN Data to Values */
/* Numbers are Hardcoded here, to make it more Readable */
    
float CONV_MinVoltage(uint8_t* data);
float CONV_MaxTemp(uint8_t* data);
float CONV_LapTime(uint8_t* data);
uint32_t CONV_FSG_AMI_state(uint8_t* data);
float CONV_MaxMotTemp(uint8_t* data);
float CONV_MaxInvTemp(uint8_t* data);
float CONV_MotorTemp_RR(uint8_t* data);
float CONV_MotorTemp_RL(uint8_t* data);
float CONV_MotorTemp_FL(uint8_t* data);
float CONV_MotorTemp_FR(uint8_t* data);
float CONV_MaxMotorTemp(signals_signal* signal_list, uint32_t signal_list_len);

#ifdef	__cplusplus
}
#endif

#endif	/* CONV_H */

