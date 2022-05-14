/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "delay.h"
#include "cancomm.h"
#include "signals.h"
#include "conv.h"

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

cancomm_message message_list [] = {
    {.id=0xA2,  .interface=CANCOMM_CAN_1, .length=8, .friendly_name="BCU_Extrem_Voltages" },
    {.id=0xA3,  .interface=CANCOMM_CAN_1, .length=8, .friendly_name="BCU_Extrem_Temperatures"},
    {.id=0x711, .interface=CANCOMM_CAN_1, .length=8, .friendly_name="VCU_LapInfo"},
    {.id=0x502, .interface=CANCOMM_CAN_1, .length=8, .friendly_name="FSG_System_status"},
    {.id=0xA4,  .interface=CANCOMM_CAN_1, .length=2, .friendly_name="BCU_SCstatus"},
    {.id=0x239, .interface=CANCOMM_CAN_1, .length=8, .friendly_name="VCU_Motor_Temps"},
    {.id=0x23A, .interface=CANCOMM_CAN_1, .length=8, .friendly_name="VCU_Inverter_Temp"}
};

uint32_t message_list_len = sizeof(message_list) / sizeof(cancomm_message);

signals_signal signal_list [] = {
    {.friendly_name="Min_Voltage",
            .id=0xA2,
            .interface=CANCOMM_CAN_1,
            .signal_type=SIGNALS_FLOAT_SIGNAL,
            .convert_float=CONV_MinVoltage
    },
    {.friendly_name="Max_Temp",
            .id=0xA3,
            .interface=CANCOMM_CAN_1,
            .signal_type=SIGNALS_FLOAT_SIGNAL,
            .convert_float=CONV_MaxTemp
    },
    {.friendly_name="LapTime",
            .id=0x711,
            .interface=CANCOMM_CAN_1,
            .signal_type=SIGNALS_FLOAT_SIGNAL,
            .convert_float=CONV_LapTime
    },
    {.friendly_name="FSG_AMI_state",
            .id=0x502,
            .interface=CANCOMM_CAN_1,
            .signal_type=SIGNALS_UINT32_T_SIGNAL,
            .convert_uint32_t=CONV_FSG_AMI_state
    },
    {.friendly_name="MaxMotTemp",
            .id=0x239,
            .interface=CANCOMM_CAN_1,
            .signal_type=SIGNALS_FLOAT_SIGNAL,
            .convert_float=CONV_MaxMotTemp
    },
    {.friendly_name="MaxInvTemp",
            .id=0x23A,
            .interface=CANCOMM_CAN_1,
            .signal_type=SIGNALS_FLOAT_SIGNAL,
            .convert_float=CONV_MaxInvTemp
    }
};

uint32_t signal_list_len = sizeof(signal_list) / sizeof(signals_signal);



int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    /* Main Loop */
    while(1){
    
        /* Read All Messages in the FIFOs */
        CANCOMM_ReadMessages(message_list, message_list_len);
        /* Interpret the RAW Message Data */
        SIGNALS_Interpret(signal_list, signal_list_len);
        /* Generate the Messages to be sent to the Display */
        
        /* Send Messages to Display */
        
        /* Wait for constant Loop time */
        
        /* (Window WDG Reset)*/
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

