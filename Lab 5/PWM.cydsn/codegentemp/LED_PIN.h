/*******************************************************************************
* File Name: LED_PIN.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LED_PIN_H) /* Pins LED_PIN_H */
#define CY_PINS_LED_PIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LED_PIN_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED_PIN_Write(uint8 value) ;
void    LED_PIN_SetDriveMode(uint8 mode) ;
uint8   LED_PIN_ReadDataReg(void) ;
uint8   LED_PIN_Read(void) ;
uint8   LED_PIN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED_PIN_DRIVE_MODE_BITS        (3)
#define LED_PIN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LED_PIN_DRIVE_MODE_BITS))

#define LED_PIN_DM_ALG_HIZ         (0x00u)
#define LED_PIN_DM_DIG_HIZ         (0x01u)
#define LED_PIN_DM_RES_UP          (0x02u)
#define LED_PIN_DM_RES_DWN         (0x03u)
#define LED_PIN_DM_OD_LO           (0x04u)
#define LED_PIN_DM_OD_HI           (0x05u)
#define LED_PIN_DM_STRONG          (0x06u)
#define LED_PIN_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define LED_PIN_MASK               LED_PIN__MASK
#define LED_PIN_SHIFT              LED_PIN__SHIFT
#define LED_PIN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED_PIN_PS                     (* (reg32 *) LED_PIN__PS)
/* Port Configuration */
#define LED_PIN_PC                     (* (reg32 *) LED_PIN__PC)
/* Data Register */
#define LED_PIN_DR                     (* (reg32 *) LED_PIN__DR)
/* Input Buffer Disable Override */
#define LED_PIN_INP_DIS                (* (reg32 *) LED_PIN__PC2)


#if defined(LED_PIN__INTSTAT)  /* Interrupt Registers */

    #define LED_PIN_INTSTAT                (* (reg32 *) LED_PIN__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define LED_PIN_DRIVE_MODE_SHIFT       (0x00u)
#define LED_PIN_DRIVE_MODE_MASK        (0x07u << LED_PIN_DRIVE_MODE_SHIFT)


#endif /* End Pins LED_PIN_H */


/* [] END OF FILE */
