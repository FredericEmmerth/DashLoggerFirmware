
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "definitions.h"
#include "delay.h"
#include "cancomm.h"
#include "signals.h"
#include "conv.h"
#include "shortprotocol.h"
#include "uart.h"
#include "command.h"

/* Define List of CAN Interfaces */
cancomm_interface interface_list [] = {
    {.number=1,
            .receiveFifo=2, .transmitFifo=1,
            .MessageTransmit=CAN1_MessageTransmit,
            .MessageReceive=CAN1_MessageReceive
    },
    {.number=2,
            .receiveFifo=2, .transmitFifo=1,
            .MessageTransmit=CAN2_MessageTransmit,
            .MessageReceive=CAN2_MessageReceive
    },
    {.number=3,
            .receiveFifo=2, .transmitFifo=1,
            .MessageTransmit=CAN3_MessageTransmit,
            .MessageReceive=CAN3_MessageReceive
    },
    {.number=4,
            .receiveFifo=2, .transmitFifo=1,
            .MessageTransmit=CAN4_MessageTransmit,
            .MessageReceive=CAN4_MessageReceive
    }
};
uint32_t interface_list_len = sizeof(interface_list)
                                        / sizeof(cancomm_interface);

/* Define all Messages to be interpreted */
cancomm_message message_list [] = {
    {.friendly_name="BCU_Extrem_Voltages",
            .id=0xA2,  .interface_number=1, .length=8
    },
    {.friendly_name="BCU_Extrem_Temperatures",
            .id=0xA3,  .interface_number=1, .length=8
    },
    {.friendly_name="VCU_LapInfo",
            .id=0x711, .interface_number=1, .length=8
    },
    {.friendly_name="FSG_System_status",
            .id=0x502, .interface_number=1, .length=8
    },
    {.friendly_name="BCU_SCstatus",
            .id=0xA4,  .interface_number=1, .length=2
    },
    {.friendly_name="VCU_Motor_Temps",
            .id=0x239, .interface_number=1, .length=8
    },
    {.friendly_name="VCU_Inverter_Temp",
            .id=0x23A, .interface_number=1, .length=8
    }
};
uint32_t message_list_len = sizeof(message_list) / sizeof(cancomm_message);

/* Define all Signals to be interpreted */
signals_signal signal_list [] = {
    {.friendly_name="Min_Voltage",
            .type = SIGNALS_CAN_MESSAGE,
            .id=0xA2,
            .interface_number=1,
            .data_type=SIGNALS_FLOAT_SIGNAL,
            .can_convert_float=CONV_MinVoltage
    },
    {.friendly_name="MaxBatTemp",
            .type = SIGNALS_CAN_MESSAGE,
            .id=0xA3,
            .interface_number=1,
            .data_type=SIGNALS_FLOAT_SIGNAL,
            .can_convert_float=CONV_MaxTemp
    },
    {.friendly_name="LapTime",
            .type = SIGNALS_CAN_MESSAGE,
            .id=0x711,
            .interface_number=1,
            .data_type=SIGNALS_FLOAT_SIGNAL,
            .can_convert_float=CONV_LapTime
    },
    {.friendly_name="BestLapTime",
            .type=SIGNALS_CAN_MESSAGE,
            .id=0x711,
            .interface_number=1,
            .data_type=SIGNALS_FLOAT_SIGNAL,
            .can_convert_float=CONV_BestLapTime
    },
    {.friendly_name="FSG_AMI_state",
            .type = SIGNALS_CAN_MESSAGE,
            .id=0x502,
            .interface_number=1,
            .data_type=SIGNALS_UINT32_T_SIGNAL,
            .can_convert_uint32_t=CONV_FSG_AMI_state
    },
    {.friendly_name="MotorTemp_RR",
            .type = SIGNALS_CAN_MESSAGE,
            .id=0x239,
            .interface_number=1,
            .data_type=SIGNALS_FLOAT_SIGNAL,
            .can_convert_float=CONV_MotorTemp_RR
    },
    {.friendly_name="MotorTemp_FL",
            .type = SIGNALS_CAN_MESSAGE,
            .id=0x239,
            .interface_number=1,
            .data_type=SIGNALS_FLOAT_SIGNAL,
            .can_convert_float=CONV_MotorTemp_FL
    },
    {.friendly_name="MotorTemp_FR",
            .type = SIGNALS_CAN_MESSAGE,
            .id=0x239,
            .interface_number=1,
            .data_type=SIGNALS_FLOAT_SIGNAL,
            .can_convert_float=CONV_MotorTemp_FR
    },
    {.friendly_name="MotorTemp_RL",
            .type = SIGNALS_CAN_MESSAGE,
            .id=0x239,
            .interface_number=1,
            .data_type=SIGNALS_FLOAT_SIGNAL,
            .can_convert_float=CONV_MotorTemp_RL
    },
    {.friendly_name="MaxInvTemp",
            .type = SIGNALS_CAN_MESSAGE,
            .id=0x23A,
            .interface_number=1,
            .data_type=SIGNALS_FLOAT_SIGNAL,
            .can_convert_float=CONV_MaxInvTemp
    },
    {.friendly_name="MaxMotorTemp",
            .type = SIGNALS_INTERNAL_SIGNAL,
            .data_type=SIGNALS_FLOAT_SIGNAL,
            .internal_convert_float=CONV_MaxMotorTemp
    },
    {.friendly_name="DISP_Motor_Temp",
            .type=SIGNALS_DISPLAY_SIGNAL,
            .data_type=SIGNALS_STRING_SIGNAL,
            .internal_convert_string=CONV_DISP_Motor_Temp
    },
    {.friendly_name="DISP_MinVoltage",
            .type=SIGNALS_DISPLAY_SIGNAL,
            .data_type=SIGNALS_STRING_SIGNAL,
            .internal_convert_string=CONV_DISP_MinVoltage
    }
            
};
uint32_t signal_list_len = sizeof(signal_list) / sizeof(signals_signal);

uint32_t current_command_signal = 0;

/* Define a Protocol Instance for Shortprotocol Communication with Display */
SHORTPROTOCOL_Instance shortProt = {
    .readAvailable = UART_ReadAvailable,
    .readByte = UART_ReadByte,
    .writeAvailable = UART_WriteAvailable,
    .writeByte = UART_WriteByte,
    .maximumPackageLength = 5
};

uint8_t sendData[] = "#MRN <P:macro/screen/Default.emc>\n";
uint32_t sendData_length = sizeof(sendData) / sizeof(uint8_t) - 1;

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    SHORTPROTOCOL_Initialize(&shortProt);
    
    DELAY_Microseconds(5000);
    
    //SHORTPROTOCOL_Send(&shortProt, sendData, sendData_length);
    
    /* Main Loop */
    /* The Maximum Loop Time has to be smaller than 2ms, to catch all Messages*/
    /* 15k Frames/s MAX and FIFO Length 32 -> 1/15E3 * 32 = 2ms */
    while(1){
        
        /* Read All Messages in the CAN FIFOs */
        CANCOMM_ReadMessages(message_list, message_list_len,
                interface_list, interface_list_len);
        
        /* Interpret the RAW CAN Message Data */
        SIGNALS_Interpret(signal_list, signal_list_len,
                message_list, message_list_len);
        
        /* Generate the Commands to be sent to the Display */
        COMMAND_Generate(signal_list, signal_list_len, 
                &current_command_signal, &shortProt);
        
        /* Send Messages to Display */
        SHORTPROTOCOL_Update(&shortProt);
        
        /* Wait for constant Loop time */
        DELAY_Microseconds(200);
        
        /* (Window WDG Reset)*/
        
        
    }

    /* Execution should not come here during normal operation */
}


