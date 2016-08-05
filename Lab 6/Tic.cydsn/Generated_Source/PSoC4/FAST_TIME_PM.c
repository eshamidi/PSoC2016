/*******************************************************************************
* File Name: FAST_TIME_PM.c
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

#include "FAST_TIME.h"

static FAST_TIME_backupStruct FAST_TIME_backup;


/*******************************************************************************
* Function Name: FAST_TIME_SaveConfig
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
*  FAST_TIME_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void FAST_TIME_SaveConfig(void) 
{
    #if (!FAST_TIME_UsingFixedFunction)
        FAST_TIME_backup.TimerUdb = FAST_TIME_ReadCounter();
        FAST_TIME_backup.InterruptMaskValue = FAST_TIME_STATUS_MASK;
        #if (FAST_TIME_UsingHWCaptureCounter)
            FAST_TIME_backup.TimerCaptureCounter = FAST_TIME_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!FAST_TIME_UDB_CONTROL_REG_REMOVED)
            FAST_TIME_backup.TimerControlRegister = FAST_TIME_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: FAST_TIME_RestoreConfig
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
*  FAST_TIME_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void FAST_TIME_RestoreConfig(void) 
{   
    #if (!FAST_TIME_UsingFixedFunction)

        FAST_TIME_WriteCounter(FAST_TIME_backup.TimerUdb);
        FAST_TIME_STATUS_MASK =FAST_TIME_backup.InterruptMaskValue;
        #if (FAST_TIME_UsingHWCaptureCounter)
            FAST_TIME_SetCaptureCount(FAST_TIME_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!FAST_TIME_UDB_CONTROL_REG_REMOVED)
            FAST_TIME_WriteControlRegister(FAST_TIME_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: FAST_TIME_Sleep
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
*  FAST_TIME_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void FAST_TIME_Sleep(void) 
{
    #if(!FAST_TIME_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(FAST_TIME_CTRL_ENABLE == (FAST_TIME_CONTROL & FAST_TIME_CTRL_ENABLE))
        {
            /* Timer is enabled */
            FAST_TIME_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            FAST_TIME_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    FAST_TIME_Stop();
    FAST_TIME_SaveConfig();
}


/*******************************************************************************
* Function Name: FAST_TIME_Wakeup
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
*  FAST_TIME_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void FAST_TIME_Wakeup(void) 
{
    FAST_TIME_RestoreConfig();
    #if(!FAST_TIME_UDB_CONTROL_REG_REMOVED)
        if(FAST_TIME_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                FAST_TIME_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
