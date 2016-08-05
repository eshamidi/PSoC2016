/*******************************************************************************
* File Name: CompP_1.h  
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

#if !defined(CY_PINS_CompP_1_H) /* Pins CompP_1_H */
#define CY_PINS_CompP_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CompP_1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    CompP_1_Write(uint8 value) ;
void    CompP_1_SetDriveMode(uint8 mode) ;
uint8   CompP_1_ReadDataReg(void) ;
uint8   CompP_1_Read(void) ;
uint8   CompP_1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CompP_1_DRIVE_MODE_BITS        (3)
#define CompP_1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - CompP_1_DRIVE_MODE_BITS))

#define CompP_1_DM_ALG_HIZ         (0x00u)
#define CompP_1_DM_DIG_HIZ         (0x01u)
#define CompP_1_DM_RES_UP          (0x02u)
#define CompP_1_DM_RES_DWN         (0x03u)
#define CompP_1_DM_OD_LO           (0x04u)
#define CompP_1_DM_OD_HI           (0x05u)
#define CompP_1_DM_STRONG          (0x06u)
#define CompP_1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define CompP_1_MASK               CompP_1__MASK
#define CompP_1_SHIFT              CompP_1__SHIFT
#define CompP_1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CompP_1_PS                     (* (reg32 *) CompP_1__PS)
/* Port Configuration */
#define CompP_1_PC                     (* (reg32 *) CompP_1__PC)
/* Data Register */
#define CompP_1_DR                     (* (reg32 *) CompP_1__DR)
/* Input Buffer Disable Override */
#define CompP_1_INP_DIS                (* (reg32 *) CompP_1__PC2)


#if defined(CompP_1__INTSTAT)  /* Interrupt Registers */

    #define CompP_1_INTSTAT                (* (reg32 *) CompP_1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define CompP_1_DRIVE_MODE_SHIFT       (0x00u)
#define CompP_1_DRIVE_MODE_MASK        (0x07u << CompP_1_DRIVE_MODE_SHIFT)


#endif /* End Pins CompP_1_H */


/* [] END OF FILE */
