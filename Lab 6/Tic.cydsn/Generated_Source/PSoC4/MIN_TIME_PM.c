/*******************************************************************************
* File Name: MIN_TIME_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "MIN_TIME.h"

static MIN_TIME_backupStruct MIN_TIME_backup;


/*******************************************************************************
* Function Name: MIN_TIME_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  MIN_TIME_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void MIN_TIME_SaveConfig(void) 
{
    #if (!MIN_TIME_UsingFixedFunction)
        MIN_TIME_backup.TimerUdb = MIN_TIME_ReadCounter();
        MIN_TIME_backup.InterruptMaskValue = MIN_TIME_STATUS_MASK;
        #if (MIN_TIME_UsingHWCaptureCounter)
            MIN_TIME_backup.TimerCaptureCounter = MIN_TIME_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!MIN_TIME_UDB_CONTROL_REG_REMOVED)
            MIN_TIME_backup.TimerControlRegister = MIN_TIME_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: MIN_TIME_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  MIN_TIME_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void MIN_TIME_RestoreConfig(void) 
{   
    #if (!MIN_TIME_UsingFixedFunction)

        MIN_TIME_WriteCounter(MIN_TIME_backup.TimerUdb);
        MIN_TIME_STATUS_MASK =MIN_TIME_backup.InterruptMaskValue;
        #if (MIN_TIME_UsingHWCaptureCounter)
            MIN_TIME_SetCaptureCount(MIN_TIME_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!MIN_TIME_UDB_CONTROL_REG_REMOVED)
            MIN_TIME_WriteControlRegister(MIN_TIME_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: MIN_TIME_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  MIN_TIME_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void MIN_TIME_Sleep(void) 
{
    #if(!MIN_TIME_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(MIN_TIME_CTRL_ENABLE == (MIN_TIME_CONTROL & MIN_TIME_CTRL_ENABLE))
        {
            /* Timer is enabled */
            MIN_TIME_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            MIN_TIME_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    MIN_TIME_Stop();
    MIN_TIME_SaveConfig();
}


/*******************************************************************************
* Function Name: MIN_TIME_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  MIN_TIME_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void MIN_TIME_Wakeup(void) 
{
    MIN_TIME_RestoreConfig();
    #if(!MIN_TIME_UDB_CONTROL_REG_REMOVED)
        if(MIN_TIME_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                MIN_TIME_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
