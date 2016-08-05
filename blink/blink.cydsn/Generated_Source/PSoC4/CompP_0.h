/*******************************************************************************
* File Name: CompP_0.h  
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

#if !defined(CY_PINS_CompP_0_H) /* Pins CompP_0_H */
#define CY_PINS_CompP_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CompP_0_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    CompP_0_Write(uint8 value) ;
void    CompP_0_SetDriveMode(uint8 mode) ;
uint8   CompP_0_ReadDataReg(void) ;
uint8   CompP_0_Read(void) ;
uint8   CompP_0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CompP_0_DRIVE_MODE_BITS        (3)
#define CompP_0_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - CompP_0_DRIVE_MODE_BITS))

#define CompP_0_DM_ALG_HIZ         (0x00u)
#define CompP_0_DM_DIG_HIZ         (0x01u)
#define CompP_0_DM_RES_UP          (0x02u)
#define CompP_0_DM_RES_DWN         (0x03u)
#define CompP_0_DM_OD_LO           (0x04u)
#define CompP_0_DM_OD_HI           (0x05u)
#define CompP_0_DM_STRONG          (0x06u)
#define CompP_0_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define CompP_0_MASK               CompP_0__MASK
#define CompP_0_SHIFT              CompP_0__SHIFT
#define CompP_0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CompP_0_PS                     (* (reg32 *) CompP_0__PS)
/* Port Configuration */
#define CompP_0_PC                     (* (reg32 *) CompP_0__PC)
/* Data Register */
#define CompP_0_DR                     (* (reg32 *) CompP_0__DR)
/* Input Buffer Disable Override */
#define CompP_0_INP_DIS                (* (reg32 *) CompP_0__PC2)


#if defined(CompP_0__INTSTAT)  /* Interrupt Registers */

    #define CompP_0_INTSTAT                (* (reg32 *) CompP_0__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define CompP_0_DRIVE_MODE_SHIFT       (0x00u)
#define CompP_0_DRIVE_MODE_MASK        (0x07u << CompP_0_DRIVE_MODE_SHIFT)


#endif /* End Pins CompP_0_H */


/* [] END OF FILE */
