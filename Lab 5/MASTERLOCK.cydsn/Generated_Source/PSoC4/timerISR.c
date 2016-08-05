/*******************************************************************************
* File Name: timerISR.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <timerISR.h>

#if !defined(timerISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START timerISR_intc` */

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: timerISR_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it. This function disables the interrupt, 
*  sets the default interrupt vector, sets the priority from the value in the
*  Design Wide Resources Interrupt Editor, then enables the interrupt to the 
*  interrupt controller.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void timerISR_Start(void)
{
    /* For all we know the interrupt is active. */
    timerISR_Disable();

    /* Set the ISR to point to the timerISR Interrupt. */
    timerISR_SetVector(&timerISR_Interrupt);

    /* Set the priority. */
    timerISR_SetPriority((uint8)timerISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    timerISR_Enable();
}


/*******************************************************************************
* Function Name: timerISR_StartEx
********************************************************************************
*
* Summary:
*  Sets up the interrupt and enables it. This function disables the interrupt,
*  sets the interrupt vector based on the address passed in, sets the priority 
*  from the value in the Design Wide Resources Interrupt Editor, then enables 
*  the interrupt to the interrupt controller.
*  
*  When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*  used to provide consistent definition across compilers:
*  
*  Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*   Function prototype example:
*   CY_ISR_PROTO(MyISR);
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void timerISR_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    timerISR_Disable();

    /* Set the ISR to point to the timerISR Interrupt. */
    timerISR_SetVector(address);

    /* Set the priority. */
    timerISR_SetPriority((uint8)timerISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    timerISR_Enable();
}


/*******************************************************************************
* Function Name: timerISR_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void timerISR_Stop(void)
{
    /* Disable this interrupt. */
    timerISR_Disable();

    /* Set the ISR to point to the passive one. */
    timerISR_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: timerISR_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for timerISR.
*
*   Add custom code between the START and END comments to keep the next version
*   of this file from over-writing your code.
*
*   Note You may use either the default ISR by using this API, or you may define
*   your own separate ISR through ISR_StartEx().
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(timerISR_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START timerISR_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: timerISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling timerISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use timerISR_StartEx instead.
* 
*   When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*   used to provide consistent definition across compilers:
*
*   Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*
*   Function prototype example:
*     CY_ISR_PROTO(MyISR);
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void timerISR_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + timerISR__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: timerISR_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress timerISR_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + timerISR__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: timerISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling timerISR_Start or timerISR_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after timerISR_Start or timerISR_StartEx has been called. 
*   To set the initial priority for the component, use the Design-Wide Resources
*   Interrupt Editor.
*
*   Note This API has no effect on Non-maskable interrupt NMI).
*
* Parameters:
*   priority: Priority of the interrupt, 0 being the highest priority
*             PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*             PSoC 4: Priority is from 0 to 3.
*
* Return:
*   None
*
*******************************************************************************/
void timerISR_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((timerISR__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *timerISR_INTC_PRIOR = (*timerISR_INTC_PRIOR & (uint32)(~timerISR__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: timerISR_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt, 0 being the highest priority
*    PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*    PSoC 4: Priority is from 0 to 3.
*
*******************************************************************************/
uint8 timerISR_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((timerISR__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*timerISR_INTC_PRIOR & timerISR__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: timerISR_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt to the interrupt controller. Do not call this function
*   unless ISR_Start() has been called or the functionality of the ISR_Start() 
*   function, which sets the vector and the priority, has been called.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void timerISR_Enable(void)
{
    /* Enable the general interrupt. */
    *timerISR_INTC_SET_EN = timerISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: timerISR_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 timerISR_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*timerISR_INTC_SET_EN & (uint32)timerISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: timerISR_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt in the interrupt controller.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void timerISR_Disable(void)
{
    /* Disable the general interrupt. */
    *timerISR_INTC_CLR_EN = timerISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: timerISR_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
* Side Effects:
*   If interrupts are enabled and the interrupt is set up properly, the ISR is
*   entered (depending on the priority of this interrupt and other pending 
*   interrupts).
*
*******************************************************************************/
void timerISR_SetPending(void)
{
    *timerISR_INTC_SET_PD = timerISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: timerISR_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt in the interrupt controller.
*
*   Note Some interrupt sources are clear-on-read and require the block 
*   interrupt/status register to be read/cleared with the appropriate block API 
*   (GPIO, UART, and so on). Otherwise the ISR will continue to remain in 
*   pending state even though the interrupt itself is cleared using this API.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void timerISR_ClearPending(void)
{
    *timerISR_INTC_CLR_PD = timerISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
