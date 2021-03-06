#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar_trm.inc

/* PWM_0_cy_m0s8_tcpwm_1 */
PWM_0_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT3_CC
PWM_0_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT3_CC_BUFF
PWM_0_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT3_COUNTER
PWM_0_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT3_CTRL
PWM_0_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT3_INTR
PWM_0_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT3_INTR_MASK
PWM_0_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT3_INTR_MASKED
PWM_0_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT3_INTR_SET
PWM_0_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT3_PERIOD
PWM_0_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT3_PERIOD_BUFF
PWM_0_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT3_STATUS
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x08
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 3
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x800
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 11
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x8000000
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 27
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x80000
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 19
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x08
PWM_0_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 3
PWM_0_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
PWM_0_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x08
PWM_0_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 3
PWM_0_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 3
PWM_0_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT3_TR_CTRL0
PWM_0_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT3_TR_CTRL1
PWM_0_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT3_TR_CTRL2

/* PWM_0_Int */
PWM_0_Int__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
PWM_0_Int__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
PWM_0_Int__INTC_MASK EQU 0x80000
PWM_0_Int__INTC_NUMBER EQU 19
PWM_0_Int__INTC_PRIOR_MASK EQU 0xC0000000
PWM_0_Int__INTC_PRIOR_NUM EQU 3
PWM_0_Int__INTC_PRIOR_REG EQU CYREG_CM0_IPR4
PWM_0_Int__INTC_SET_EN_REG EQU CYREG_CM0_ISER
PWM_0_Int__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

/* PWM_0_Out */
PWM_0_Out__0__DM__MASK EQU 0x1C0
PWM_0_Out__0__DM__SHIFT EQU 6
PWM_0_Out__0__DR EQU CYREG_PRT1_DR
PWM_0_Out__0__HSIOM EQU CYREG_HSIOM_PORT_SEL1
PWM_0_Out__0__HSIOM_MASK EQU 0x00000F00
PWM_0_Out__0__HSIOM_SHIFT EQU 8
PWM_0_Out__0__INTCFG EQU CYREG_PRT1_INTCFG
PWM_0_Out__0__INTSTAT EQU CYREG_PRT1_INTSTAT
PWM_0_Out__0__MASK EQU 0x04
PWM_0_Out__0__OUT_SEL EQU CYREG_UDB_PA1_CFG10
PWM_0_Out__0__OUT_SEL_SHIFT EQU 4
PWM_0_Out__0__OUT_SEL_VAL EQU -1
PWM_0_Out__0__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
PWM_0_Out__0__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
PWM_0_Out__0__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
PWM_0_Out__0__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
PWM_0_Out__0__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
PWM_0_Out__0__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
PWM_0_Out__0__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
PWM_0_Out__0__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
PWM_0_Out__0__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
PWM_0_Out__0__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
PWM_0_Out__0__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
PWM_0_Out__0__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
PWM_0_Out__0__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
PWM_0_Out__0__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
PWM_0_Out__0__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
PWM_0_Out__0__PC EQU CYREG_PRT1_PC
PWM_0_Out__0__PC2 EQU CYREG_PRT1_PC2
PWM_0_Out__0__PORT EQU 1
PWM_0_Out__0__PS EQU CYREG_PRT1_PS
PWM_0_Out__0__SHIFT EQU 2
PWM_0_Out__DR EQU CYREG_PRT1_DR
PWM_0_Out__INTCFG EQU CYREG_PRT1_INTCFG
PWM_0_Out__INTSTAT EQU CYREG_PRT1_INTSTAT
PWM_0_Out__MASK EQU 0x04
PWM_0_Out__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
PWM_0_Out__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
PWM_0_Out__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
PWM_0_Out__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
PWM_0_Out__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
PWM_0_Out__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
PWM_0_Out__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
PWM_0_Out__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
PWM_0_Out__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
PWM_0_Out__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
PWM_0_Out__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
PWM_0_Out__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
PWM_0_Out__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
PWM_0_Out__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
PWM_0_Out__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
PWM_0_Out__PC EQU CYREG_PRT1_PC
PWM_0_Out__PC2 EQU CYREG_PRT1_PC2
PWM_0_Out__PORT EQU 1
PWM_0_Out__PS EQU CYREG_PRT1_PS
PWM_0_Out__SHIFT EQU 2

/* PWM_1_cy_m0s8_tcpwm_1 */
PWM_1_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT1_CC
PWM_1_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT1_CC_BUFF
PWM_1_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT1_COUNTER
PWM_1_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT1_CTRL
PWM_1_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT1_INTR
PWM_1_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT1_INTR_MASK
PWM_1_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT1_INTR_MASKED
PWM_1_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT1_INTR_SET
PWM_1_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT1_PERIOD
PWM_1_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT1_PERIOD_BUFF
PWM_1_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT1_STATUS
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x02
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 1
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x200
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 9
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x2000000
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 25
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x20000
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 17
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x02
PWM_1_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 1
PWM_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
PWM_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x02
PWM_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 1
PWM_1_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 1
PWM_1_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT1_TR_CTRL0
PWM_1_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT1_TR_CTRL1
PWM_1_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT1_TR_CTRL2

/* PWM_1_Out */
PWM_1_Out__0__DM__MASK EQU 0x1C0000
PWM_1_Out__0__DM__SHIFT EQU 18
PWM_1_Out__0__DR EQU CYREG_PRT2_DR
PWM_1_Out__0__HSIOM EQU CYREG_HSIOM_PORT_SEL2
PWM_1_Out__0__HSIOM_MASK EQU 0x0F000000
PWM_1_Out__0__HSIOM_SHIFT EQU 24
PWM_1_Out__0__INTCFG EQU CYREG_PRT2_INTCFG
PWM_1_Out__0__INTSTAT EQU CYREG_PRT2_INTSTAT
PWM_1_Out__0__MASK EQU 0x40
PWM_1_Out__0__OUT_SEL EQU CYREG_UDB_PA2_CFG10
PWM_1_Out__0__OUT_SEL_SHIFT EQU 12
PWM_1_Out__0__OUT_SEL_VAL EQU -1
PWM_1_Out__0__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
PWM_1_Out__0__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
PWM_1_Out__0__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
PWM_1_Out__0__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
PWM_1_Out__0__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
PWM_1_Out__0__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
PWM_1_Out__0__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
PWM_1_Out__0__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
PWM_1_Out__0__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
PWM_1_Out__0__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
PWM_1_Out__0__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
PWM_1_Out__0__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
PWM_1_Out__0__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
PWM_1_Out__0__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
PWM_1_Out__0__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
PWM_1_Out__0__PC EQU CYREG_PRT2_PC
PWM_1_Out__0__PC2 EQU CYREG_PRT2_PC2
PWM_1_Out__0__PORT EQU 2
PWM_1_Out__0__PS EQU CYREG_PRT2_PS
PWM_1_Out__0__SHIFT EQU 6
PWM_1_Out__DR EQU CYREG_PRT2_DR
PWM_1_Out__INTCFG EQU CYREG_PRT2_INTCFG
PWM_1_Out__INTSTAT EQU CYREG_PRT2_INTSTAT
PWM_1_Out__MASK EQU 0x40
PWM_1_Out__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
PWM_1_Out__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
PWM_1_Out__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
PWM_1_Out__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
PWM_1_Out__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
PWM_1_Out__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
PWM_1_Out__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
PWM_1_Out__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
PWM_1_Out__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
PWM_1_Out__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
PWM_1_Out__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
PWM_1_Out__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
PWM_1_Out__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
PWM_1_Out__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
PWM_1_Out__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
PWM_1_Out__PC EQU CYREG_PRT2_PC
PWM_1_Out__PC2 EQU CYREG_PRT2_PC2
PWM_1_Out__PORT EQU 2
PWM_1_Out__PS EQU CYREG_PRT2_PS
PWM_1_Out__SHIFT EQU 6

/* PWM_2_cy_m0s8_tcpwm_1 */
PWM_2_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT2_CC
PWM_2_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT2_CC_BUFF
PWM_2_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT2_COUNTER
PWM_2_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT2_CTRL
PWM_2_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT2_INTR
PWM_2_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT2_INTR_MASK
PWM_2_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT2_INTR_MASKED
PWM_2_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT2_INTR_SET
PWM_2_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT2_PERIOD
PWM_2_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT2_PERIOD_BUFF
PWM_2_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT2_STATUS
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x04
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 2
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x400
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 10
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x4000000
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 26
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x40000
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 18
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x04
PWM_2_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 2
PWM_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
PWM_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x04
PWM_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 2
PWM_2_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 2
PWM_2_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT2_TR_CTRL0
PWM_2_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT2_TR_CTRL1
PWM_2_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT2_TR_CTRL2

/* PWM_2_Out */
PWM_2_Out__0__DM__MASK EQU 0x07
PWM_2_Out__0__DM__SHIFT EQU 0
PWM_2_Out__0__DR EQU CYREG_PRT1_DR
PWM_2_Out__0__HSIOM EQU CYREG_HSIOM_PORT_SEL1
PWM_2_Out__0__HSIOM_MASK EQU 0x0000000F
PWM_2_Out__0__HSIOM_SHIFT EQU 0
PWM_2_Out__0__INTCFG EQU CYREG_PRT1_INTCFG
PWM_2_Out__0__INTSTAT EQU CYREG_PRT1_INTSTAT
PWM_2_Out__0__MASK EQU 0x01
PWM_2_Out__0__OUT_SEL EQU CYREG_UDB_PA1_CFG10
PWM_2_Out__0__OUT_SEL_SHIFT EQU 0
PWM_2_Out__0__OUT_SEL_VAL EQU -1
PWM_2_Out__0__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
PWM_2_Out__0__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
PWM_2_Out__0__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
PWM_2_Out__0__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
PWM_2_Out__0__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
PWM_2_Out__0__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
PWM_2_Out__0__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
PWM_2_Out__0__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
PWM_2_Out__0__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
PWM_2_Out__0__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
PWM_2_Out__0__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
PWM_2_Out__0__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
PWM_2_Out__0__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
PWM_2_Out__0__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
PWM_2_Out__0__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
PWM_2_Out__0__PC EQU CYREG_PRT1_PC
PWM_2_Out__0__PC2 EQU CYREG_PRT1_PC2
PWM_2_Out__0__PORT EQU 1
PWM_2_Out__0__PS EQU CYREG_PRT1_PS
PWM_2_Out__0__SHIFT EQU 0
PWM_2_Out__DR EQU CYREG_PRT1_DR
PWM_2_Out__INTCFG EQU CYREG_PRT1_INTCFG
PWM_2_Out__INTSTAT EQU CYREG_PRT1_INTSTAT
PWM_2_Out__MASK EQU 0x01
PWM_2_Out__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
PWM_2_Out__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
PWM_2_Out__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
PWM_2_Out__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
PWM_2_Out__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
PWM_2_Out__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
PWM_2_Out__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
PWM_2_Out__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
PWM_2_Out__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
PWM_2_Out__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
PWM_2_Out__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
PWM_2_Out__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
PWM_2_Out__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
PWM_2_Out__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
PWM_2_Out__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
PWM_2_Out__PC EQU CYREG_PRT1_PC
PWM_2_Out__PC2 EQU CYREG_PRT1_PC2
PWM_2_Out__PORT EQU 1
PWM_2_Out__PS EQU CYREG_PRT1_PS
PWM_2_Out__SHIFT EQU 0

/* Timer_cy_m0s8_tcpwm_1 */
Timer_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT0_CC
Timer_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT0_CC_BUFF
Timer_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT0_COUNTER
Timer_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT0_CTRL
Timer_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT0_INTR
Timer_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT0_INTR_MASK
Timer_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT0_INTR_MASKED
Timer_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT0_INTR_SET
Timer_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT0_PERIOD
Timer_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT0_PERIOD_BUFF
Timer_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT0_STATUS
Timer_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x01
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 0
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x100
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 8
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x1000000
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 24
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x10000
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 16
Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x01
Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 0
Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x01
Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 0
Timer_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 0
Timer_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT0_TR_CTRL0
Timer_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT0_TR_CTRL1
Timer_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT0_TR_CTRL2

/* Timer_Int */
Timer_Int__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
Timer_Int__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
Timer_Int__INTC_MASK EQU 0x10000
Timer_Int__INTC_NUMBER EQU 16
Timer_Int__INTC_PRIOR_MASK EQU 0xC0
Timer_Int__INTC_PRIOR_NUM EQU 3
Timer_Int__INTC_PRIOR_REG EQU CYREG_CM0_IPR4
Timer_Int__INTC_SET_EN_REG EQU CYREG_CM0_ISER
Timer_Int__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

/* Timer_Pin */
Timer_Pin__0__DM__MASK EQU 0x07
Timer_Pin__0__DM__SHIFT EQU 0
Timer_Pin__0__DR EQU CYREG_PRT0_DR
Timer_Pin__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
Timer_Pin__0__HSIOM_MASK EQU 0x0000000F
Timer_Pin__0__HSIOM_SHIFT EQU 0
Timer_Pin__0__INTCFG EQU CYREG_PRT0_INTCFG
Timer_Pin__0__INTSTAT EQU CYREG_PRT0_INTSTAT
Timer_Pin__0__MASK EQU 0x01
Timer_Pin__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Timer_Pin__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Timer_Pin__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Timer_Pin__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Timer_Pin__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Timer_Pin__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Timer_Pin__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Timer_Pin__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Timer_Pin__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Timer_Pin__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Timer_Pin__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Timer_Pin__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Timer_Pin__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Timer_Pin__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Timer_Pin__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Timer_Pin__0__PC EQU CYREG_PRT0_PC
Timer_Pin__0__PC2 EQU CYREG_PRT0_PC2
Timer_Pin__0__PORT EQU 0
Timer_Pin__0__PS EQU CYREG_PRT0_PS
Timer_Pin__0__SHIFT EQU 0
Timer_Pin__DR EQU CYREG_PRT0_DR
Timer_Pin__INTCFG EQU CYREG_PRT0_INTCFG
Timer_Pin__INTSTAT EQU CYREG_PRT0_INTSTAT
Timer_Pin__MASK EQU 0x01
Timer_Pin__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Timer_Pin__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Timer_Pin__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Timer_Pin__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Timer_Pin__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Timer_Pin__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Timer_Pin__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Timer_Pin__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Timer_Pin__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Timer_Pin__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Timer_Pin__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Timer_Pin__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Timer_Pin__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Timer_Pin__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Timer_Pin__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Timer_Pin__PC EQU CYREG_PRT0_PC
Timer_Pin__PC2 EQU CYREG_PRT0_PC2
Timer_Pin__PORT EQU 0
Timer_Pin__PS EQU CYREG_PRT0_PS
Timer_Pin__SHIFT EQU 0

/* Pin_Red */
Pin_Red__0__DM__MASK EQU 0x1C0
Pin_Red__0__DM__SHIFT EQU 6
Pin_Red__0__DR EQU CYREG_PRT0_DR
Pin_Red__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
Pin_Red__0__HSIOM_MASK EQU 0x00000F00
Pin_Red__0__HSIOM_SHIFT EQU 8
Pin_Red__0__INTCFG EQU CYREG_PRT0_INTCFG
Pin_Red__0__INTSTAT EQU CYREG_PRT0_INTSTAT
Pin_Red__0__MASK EQU 0x04
Pin_Red__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Pin_Red__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Pin_Red__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Pin_Red__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Pin_Red__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Pin_Red__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Pin_Red__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Pin_Red__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Pin_Red__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Pin_Red__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Pin_Red__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Pin_Red__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Pin_Red__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Pin_Red__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Pin_Red__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Pin_Red__0__PC EQU CYREG_PRT0_PC
Pin_Red__0__PC2 EQU CYREG_PRT0_PC2
Pin_Red__0__PORT EQU 0
Pin_Red__0__PS EQU CYREG_PRT0_PS
Pin_Red__0__SHIFT EQU 2
Pin_Red__DR EQU CYREG_PRT0_DR
Pin_Red__INTCFG EQU CYREG_PRT0_INTCFG
Pin_Red__INTSTAT EQU CYREG_PRT0_INTSTAT
Pin_Red__MASK EQU 0x04
Pin_Red__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Pin_Red__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Pin_Red__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Pin_Red__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Pin_Red__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Pin_Red__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Pin_Red__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Pin_Red__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Pin_Red__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Pin_Red__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Pin_Red__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Pin_Red__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Pin_Red__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Pin_Red__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Pin_Red__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Pin_Red__PC EQU CYREG_PRT0_PC
Pin_Red__PC2 EQU CYREG_PRT0_PC2
Pin_Red__PORT EQU 0
Pin_Red__PS EQU CYREG_PRT0_PS
Pin_Red__SHIFT EQU 2

/* Clock_1MHz */
Clock_1MHz__DIVIDER_MASK EQU 0x0000FFFF
Clock_1MHz__ENABLE EQU CYREG_CLK_DIVIDER_A00
Clock_1MHz__ENABLE_MASK EQU 0x80000000
Clock_1MHz__MASK EQU 0x80000000
Clock_1MHz__REGISTER EQU CYREG_CLK_DIVIDER_A00

/* Miscellaneous */
CYDEV_BCLK__HFCLK__HZ EQU 24000000
CYDEV_BCLK__HFCLK__KHZ EQU 24000
CYDEV_BCLK__HFCLK__MHZ EQU 24
CYDEV_BCLK__SYSCLK__HZ EQU 24000000
CYDEV_BCLK__SYSCLK__KHZ EQU 24000
CYDEV_BCLK__SYSCLK__MHZ EQU 24
CYDEV_CHIP_DIE_GEN4 EQU 2
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PANTHER EQU 13
CYDEV_CHIP_DIE_PSOC4A EQU 6
CYDEV_CHIP_DIE_PSOC5LP EQU 12
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC4
CYDEV_CHIP_JTAG_ID EQU 0x04C81193
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 6
CYDEV_CHIP_MEMBER_4C EQU 10
CYDEV_CHIP_MEMBER_4D EQU 3
CYDEV_CHIP_MEMBER_4E EQU 5
CYDEV_CHIP_MEMBER_4F EQU 7
CYDEV_CHIP_MEMBER_4G EQU 2
CYDEV_CHIP_MEMBER_4H EQU 4
CYDEV_CHIP_MEMBER_4L EQU 9
CYDEV_CHIP_MEMBER_4M EQU 8
CYDEV_CHIP_MEMBER_5A EQU 12
CYDEV_CHIP_MEMBER_5B EQU 11
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_4A
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_GEN4_ES EQU 17
CYDEV_CHIP_REV_GEN4_ES2 EQU 33
CYDEV_CHIP_REV_GEN4_PRODUCTION EQU 17
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4C_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_4A_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_READ_ACCELERATOR EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_PROTECT_KILL EQU 4
CYDEV_DEBUG_PROTECT_OPEN EQU 1
CYDEV_DEBUG_PROTECT EQU CYDEV_DEBUG_PROTECT_OPEN
CYDEV_DEBUG_PROTECT_PROTECTED EQU 2
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DFT_SELECT_CLK0 EQU 1
CYDEV_DFT_SELECT_CLK1 EQU 2
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_IMO_TRIMMED_BY_WCO EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_STACK_SIZE EQU 0x0400
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 1
CYDEV_VDDA_MV EQU 3300
CYDEV_VDDD_MV EQU 3300
CYDEV_WDT_GENERATE_ISR EQU 1
CYIPBLOCK_M0S8_CTBM_VERSION EQU 0
CYIPBLOCK_m0s8cpuss_VERSION EQU 0
CYIPBLOCK_m0s8csd_VERSION EQU 0
CYIPBLOCK_m0s8gpio2_VERSION EQU 0
CYIPBLOCK_m0s8hsiom4a_VERSION EQU 0
CYIPBLOCK_m0s8lcd_VERSION EQU 0
CYIPBLOCK_m0s8lpcomp_VERSION EQU 0
CYIPBLOCK_m0s8pclk_VERSION EQU 0
CYIPBLOCK_m0s8sar_VERSION EQU 0
CYIPBLOCK_m0s8scb_VERSION EQU 0
CYIPBLOCK_m0s8srssv2_VERSION EQU 1
CYIPBLOCK_m0s8tcpwm_VERSION EQU 0
CYIPBLOCK_m0s8udbif_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 2
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */
