/*******************************************************************************
* File Name: Input_Pin_0.h  
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

#if !defined(CY_PINS_Input_Pin_0_H) /* Pins Input_Pin_0_H */
#define CY_PINS_Input_Pin_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Input_Pin_0_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Input_Pin_0_Write(uint8 value) ;
void    Input_Pin_0_SetDriveMode(uint8 mode) ;
uint8   Input_Pin_0_ReadDataReg(void) ;
uint8   Input_Pin_0_Read(void) ;
uint8   Input_Pin_0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Input_Pin_0_DRIVE_MODE_BITS        (3)
#define Input_Pin_0_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Input_Pin_0_DRIVE_MODE_BITS))

#define Input_Pin_0_DM_ALG_HIZ         (0x00u)
#define Input_Pin_0_DM_DIG_HIZ         (0x01u)
#define Input_Pin_0_DM_RES_UP          (0x02u)
#define Input_Pin_0_DM_RES_DWN         (0x03u)
#define Input_Pin_0_DM_OD_LO           (0x04u)
#define Input_Pin_0_DM_OD_HI           (0x05u)
#define Input_Pin_0_DM_STRONG          (0x06u)
#define Input_Pin_0_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Input_Pin_0_MASK               Input_Pin_0__MASK
#define Input_Pin_0_SHIFT              Input_Pin_0__SHIFT
#define Input_Pin_0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Input_Pin_0_PS                     (* (reg32 *) Input_Pin_0__PS)
/* Port Configuration */
#define Input_Pin_0_PC                     (* (reg32 *) Input_Pin_0__PC)
/* Data Register */
#define Input_Pin_0_DR                     (* (reg32 *) Input_Pin_0__DR)
/* Input Buffer Disable Override */
#define Input_Pin_0_INP_DIS                (* (reg32 *) Input_Pin_0__PC2)


#if defined(Input_Pin_0__INTSTAT)  /* Interrupt Registers */

    #define Input_Pin_0_INTSTAT                (* (reg32 *) Input_Pin_0__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Input_Pin_0_DRIVE_MODE_SHIFT       (0x00u)
#define Input_Pin_0_DRIVE_MODE_MASK        (0x07u << Input_Pin_0_DRIVE_MODE_SHIFT)


#endif /* End Pins Input_Pin_0_H */


/* [] END OF FILE */
