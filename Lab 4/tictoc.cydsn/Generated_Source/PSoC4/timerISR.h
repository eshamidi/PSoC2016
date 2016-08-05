/*******************************************************************************
* File Name: timerISR.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_timerISR_H)
#define CY_ISR_timerISR_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void timerISR_Start(void);
void timerISR_StartEx(cyisraddress address);
void timerISR_Stop(void);

CY_ISR_PROTO(timerISR_Interrupt);

void timerISR_SetVector(cyisraddress address);
cyisraddress timerISR_GetVector(void);

void timerISR_SetPriority(uint8 priority);
uint8 timerISR_GetPriority(void);

void timerISR_Enable(void);
uint8 timerISR_GetState(void);
void timerISR_Disable(void);

void timerISR_SetPending(void);
void timerISR_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the timerISR ISR. */
#define timerISR_INTC_VECTOR            ((reg32 *) timerISR__INTC_VECT)

/* Address of the timerISR ISR priority. */
#define timerISR_INTC_PRIOR             ((reg32 *) timerISR__INTC_PRIOR_REG)

/* Priority of the timerISR interrupt. */
#define timerISR_INTC_PRIOR_NUMBER      timerISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable timerISR interrupt. */
#define timerISR_INTC_SET_EN            ((reg32 *) timerISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the timerISR interrupt. */
#define timerISR_INTC_CLR_EN            ((reg32 *) timerISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the timerISR interrupt state to pending. */
#define timerISR_INTC_SET_PD            ((reg32 *) timerISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the timerISR interrupt. */
#define timerISR_INTC_CLR_PD            ((reg32 *) timerISR__INTC_CLR_PD_REG)



#endif /* CY_ISR_timerISR_H */


/* [] END OF FILE */
