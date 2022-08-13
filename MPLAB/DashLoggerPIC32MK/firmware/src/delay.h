/**
 * @file delay.h
 * @brief This File defines the Prototypes for \ref DELAY
 * 
 * @author Frederic Emmerth
 * 
 * \ingroup DELAY
 * 
 * @bug Millisecond Deley is inaccurate
 * 
 */

/**
 * \defgroup DELAY DELAY
 * This Module implements Functions to sleep/delay for a specified Amount of 
 * Time.
 * \addtogroup DELAY
 * \{
 */

#ifndef DELAY_H
#define	DELAY_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>

/**
 * @brief The Frequency of the Core in Hz.
 */
#define CLOCK_FREQUENCY_CORE 120000000
    
/**
 * @brief Count of Microseconds in a Second
 */
#define MICROSECONDS_IN_SECOND 1000000
    
/**
 * @brief Count of Milliseconds in a Second
 */
#define MILLISECONDS_IN_SECOND 1000
    
/**
 * Adjustment of the Delay Functions
 */
#define TWO_STEPS_DELAY_ADJ 2

/**
 * @brief Delay for an amount of Milliseconds
 * @param delay The Time to Delay in Milliseconds
 */
void DELAY_Milliseconds(uint32_t delay);

/**
 * @brief Delay for an amount of Microseconds
 * @param delay The Time to Delay in Microseconds
 */
void DELAY_Microseconds(uint32_t delay);


#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */

/**
 * \}
 */

