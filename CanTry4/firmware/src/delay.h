/* 
 * File:   delay.h
 * Author: Frederic
 *
 * Created on 11. Mai 2022, 17:54
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

