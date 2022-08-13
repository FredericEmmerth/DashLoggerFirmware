/**
 * @file delay.c
 * @brief This File implements the Prototypes for \ref DELAY
 * 
 * @author Frederic Emmerth
 * 
 * \ingroup DELAY
 * 
 * \addtogroup DELAY
 * \{
 * 
 */

#include "delay.h"

void DELAY_Milliseconds(uint32_t delay){
    uint32_t i=0;
    for(;i < delay; i++){
        DELAY_Microseconds(MILLISECONDS_IN_SECOND);
    }
}

void DELAY_Microseconds(uint32_t delay){
    uint32_t cycles;
    cycles = (CLOCK_FREQUENCY_CORE / 
            (MICROSECONDS_IN_SECOND * TWO_STEPS_DELAY_ADJ))
             * delay;
    uint32_t i=0;
    for(; i<cycles; i++){
        
    }
}

/**
 * \}
 */
