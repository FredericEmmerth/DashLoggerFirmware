/**
 * @file delay.h
 * @brief This File defines the Prototypes for \ref DELAY
 * 
 * @author Frederic Emmerth
 * 
 * \ingroup DELAY
 * 
 */

/**
 * \defgroup DELAY DELAY
 * 
 * This Module defines two Functions useful for generating a Delay of
 * Microseconds or Milliseconds.
 * 
 * @todo Use NOPs for Delay
 * @bug \ref DELAY_Milliseconds is not working, the Delay Time is very off
 * 
 * \addtogroup DELAY
 * \{
 */

#ifndef DELAY_H
#define	DELAY_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>

#define CLOCK_FREQUENCY_CORE 120000000
#define MICROSECONDS_IN_SECOND 1000000
#define MILLISECONDS_IN_SECOND 1000
#define TWO_STEPS_DELAY_ADJ 2

void DELAY_Milliseconds(uint32_t delay);
void DELAY_Microseconds(uint32_t delay);


#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */

/**
 * \}
 */
