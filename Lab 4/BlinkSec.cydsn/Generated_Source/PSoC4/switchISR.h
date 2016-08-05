/*******************************************************************************
* File Name: switchISR.h
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
#if !defined(CY_ISR_switchISR_H)
#define CY_ISR_switchISR_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void switchISR_Start(void);
void switchISR_StartEx(cyisraddress address);
void switchISR_Stop(void);

CY_ISR_PROTO(switchISR_Interrupt);

void switchISR_SetVector(cyisraddress address);
cyisraddress switchISR_GetVector(void);

void switchISR_SetPriority(uint8 priority);
uint8 switchISR_GetPriority(void);

void switchISR_Enable(void);
uint8 switchISR_GetState(void);
void switchISR_Disable(void);

void switchISR_SetPending(void);
void switchISR_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the switchISR ISR. */
#define switchISR_INTC_VECTOR            ((reg32 *) switchISR__INTC_VECT)

/* Address of the switchISR ISR priority. */
#define switchISR_INTC_PRIOR             ((reg32 *) switchISR__INTC_PRIOR_REG)

/* Priority of the switchISR interrupt. */
#define switchISR_INTC_PRIOR_NUMBER      switchISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable switchISR interrupt. */
#define switchISR_INTC_SET_EN            ((reg32 *) switchISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the switchISR interrupt. */
#define switchISR_INTC_CLR_EN            ((reg32 *) switchISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the switchISR interrupt state to pending. */
#define switchISR_INTC_SET_PD            ((reg32 *) switchISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the switchISR interrupt. */
#define switchISR_INTC_CLR_PD            ((reg32 *) switchISR__INTC_CLR_PD_REG)



#endif /* CY_ISR_switchISR_H */


/* [] END OF FILE */
