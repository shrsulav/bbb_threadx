/*
 * dmtimerCounter.h
 *
 *  Created on: Nov 11, 2022
 *      Author: sulavs
 */

#ifndef DMTIMERCOUNTER_H_
#define DMTIMERCOUNTER_H_

/******************************************************************************
**                      INTERNAL MACRO DEFINITIONS
*******************************************************************************/
#define TIMER_INITIAL_COUNT             (0xFF000000u)
#define TIMER_RLD_COUNT                 (0xFF000000u)

/******************************************************************************
**                      INTERNAL FUNCTION PROTOTYPES
*******************************************************************************/
static void DMTimerAintcConfigure(void);
static void DMTimerSetUp(void);
static void DMTimerIsr(void);
void timerInit(void);


#endif /* DMTIMERCOUNTER_H_ */
