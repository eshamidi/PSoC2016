/*******************************************************************************
* File Name: cyPm.h
* Version 5.10
*
*  Description:
*   Provides the function definitions for the power management API.
*
*  Note:
*   Documentation of the API's in this file is located in the
*   System Reference Guide provided with PSoC Creator.
*
********************************************************************************
* Copyright 2011-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_BOOT_CYPM_H)
#define CY_BOOT_CYPM_H

#include "cytypes.h"


/***************************************
*        Function Prototypes
***************************************/
void CySysPmSleep(void);
void CySysPmDeepSleep(void);

#if(CY_IP_SRSSV2)
    void CySysPmHibernate(void);
    void CySysPmFreezeIo(void);
    void CySysPmUnfreezeIo(void);
    uint32 CySysPmGetResetReason(void);
    void CySysPmStop(void);
    void CySysPmSetWakeupPolarity(uint32 polarity);
#else
    void CySysPmSetWakeupHoldoff(uint32 hfclkFrequencyMhz);
#endif /* (CY_IP_SRSSV2) */


/***************************************
*       Macro definition
***************************************/

/*******************************************************************************
* The ARM compilers have the __wfi() intrinsic that inserts a WFI instruction
* into the instruction stream generated by the compiler. The GCC compiler has to
* execute assembly language instruction.
*******************************************************************************/
#if defined(__ARMCC_VERSION)    /* Instristic for Keil compilers */
    #define CY_PM_WFI       __wfi()
#else   /* ASM for GCC & IAR */
    #define CY_PM_WFI       __asm volatile ("WFI \n")
#endif /* __ARMCC_VERSION */

#if(CY_IP_SRSSV2)

    /* CySysPmSetWakeupPolarity() */
    #define CY_PM_STOP_WAKEUP_ACTIVE_LOW        ((uint32)(0x0u))
    #define CY_PM_STOP_WAKEUP_ACTIVE_HIGH       ((uint32)(0x1u))
    #define CY_PM_STOP_WAKEUP_POLARITY          (CY_PM_STOP_WAKEUP_ACTIVE_LOW)

    /* CySysPmGetResetReason() */
    #define CY_PM_RESET_REASON_UNKN             (0u)
    #define CY_PM_RESET_REASON_XRES             (1u)
    #define CY_PM_RESET_REASON_WAKEUP_HIB       (2u)
    #define CY_PM_RESET_REASON_WAKEUP_STOP      (3u)

#endif /* (CY_IP_SRSSV2) */


/***************************************
*              Registers
***************************************/

/* Power Mode Control */
#define CY_PM_PWR_CONTROL_REG               (*(reg32 *) CYREG_PWR_CONTROL)
#define CY_PM_PWR_CONTROL_PTR               ( (reg32 *) CYREG_PWR_CONTROL)

/* CM0 System Control Register */
#define CY_PM_CM0_SCR_REG                   (*(reg32 *) CYREG_CM0_SCR)
#define CY_PM_CM0_SCR_PTR                   ( (reg32 *) CYREG_CM0_SCR)

/* Power System Key & Delay Register */
#define CY_PM_PWR_KEY_DELAY_REG             (*(reg32 *) CYREG_PWR_KEY_DELAY)
#define CY_PM_PWR_KEY_DELAY_PTR             ( (reg32 *) CYREG_PWR_KEY_DELAY)


#if(CY_IP_SRSSV2)
    /* Hibernate wakeup value for PWR_KEY_DELAY */
    #define CY_SFLASH_HIB_KEY_DELAY_REG     (*(reg16 *) CYREG_SFLASH_HIB_KEY_DELAY)
    #define CY_SFLASH_HIB_KEY_DELAY_PTR     ( (reg16 *) CYREG_SFLASH_HIB_KEY_DELAY)
#endif  /* (CY_IP_SRSSV2) */

/* Deep Sleep wakeup value for PWR_KEY_DELAY */
#define CY_SFLASH_DPSLP_KEY_DELAY_REG       (*(reg16 *) CYREG_SFLASH_DPSLP_KEY_DELAY)
#define CY_SFLASH_DPSLP_KEY_DELAY_PTR       ( (reg16 *) CYREG_SFLASH_DPSLP_KEY_DELAY)

/* Power Stop Mode Register */
#if(CY_IP_SRSSV2)
    #define CY_PM_PWR_STOP_REG              (*(reg32 *) CYREG_PWR_STOP)
    #define CY_PM_PWR_STOP_PTR              ( (reg32 *) CYREG_PWR_STOP)
#endif /* (CY_IP_SRSSV2) */

#if (CY_PSOC4_4100 || CY_PSOC4_4200)
    /* CPU Subsystem Configuration */
    #define CY_PM_CPUSS_CONFIG_REG             (*(reg32 *) CYREG_CPUSS_CONFIG)
    #define CY_PM_CPUSS_CONFIG_PTR             ( (reg32 *) CYREG_CPUSS_CONFIG)
#endif /* (CY_PSOC4_4100 || CY_PSOC4_4200) */


/***************************************
*       Register Constants
***************************************/

/* CM0 System Control Register Constants */
#define CY_PM_CM0_SCR_SLEEPDEEP             ((uint32)(0x04u))

#if(CY_IP_SRSSV2)
    /* Power Mode Control Constants */
    #define CY_PM_PWR_CONTROL_HIBERNATE         (0x80000000u)

    /* Power Mode Stop Constants */
    #define CY_PM_PWR_STOP_POLARITY_SHIFT       (16u)
    #define CY_PM_PWR_STOP_POLARITY             ((uint32)((uint32)1u << CY_PM_PWR_STOP_POLARITY_SHIFT))
    #define CY_PM_PWR_STOP_FREEZE_SHIFT         (17u)
    #define CY_PM_PWR_STOP_FREEZE               ((uint32)((uint32)1u << CY_PM_PWR_STOP_FREEZE_SHIFT))
    #define CY_PM_PWR_STOP_UNLOCK_SHIFT         (8u)
    #define CY_PM_PWR_STOP_UNLOCK_MASK          ((uint32)((uint32)0xFFu << CY_PM_PWR_STOP_UNLOCK_SHIFT))
    #define CY_PM_PWR_STOP_UNLOCK               ((uint32)((uint32)0x3Au << CY_PM_PWR_STOP_UNLOCK_SHIFT))
    #define CY_PM_PWR_STOP_STOP_SHIFT           (31u)
    #define CY_PM_PWR_STOP_STOP                 ((uint32)((uint32)1u << CY_PM_PWR_STOP_STOP_SHIFT))
    #define CY_PM_PWR_STOP_TOKEN_MASK           ((uint32)(0xFFu))
    #define CY_PM_PWR_STOP_TOKEN_XRES           ((uint32)(0x00u))
    #define CY_PM_PWR_STOP_TOKEN_HIB            ((uint32)(0xF1u))
    #define CY_PM_PWR_STOP_TOKEN_STOP           ((uint32)(0xF2u))
#else
    #define CY_PM_PWR_KEY_DELAY_REG_DEFAULT     ((uint32) 248u)
    #define CY_PM_PWR_KEY_DELAY_FREQ_DEFAULT    (48u)
#endif /* (CY_IP_SRSSV2) */

#if (CY_PSOC4_4100 || CY_PSOC4_4200)
    /* 0 - normal operation, 1 - Flash Accelerator in bypass mode */
    #define CY_PM_CPUSS_CONFIG_FLSH_ACC_BYPASS      ((uint32) 0x02u)
#endif /* (CY_PSOC4_4100 || CY_PSOC4_4200) */

#endif  /* CY_BOOT_CYPM_H */


/* [] END OF FILE */
