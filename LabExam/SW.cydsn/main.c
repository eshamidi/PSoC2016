/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

CY_ISR(TimerISR){
    LED_PIN_Write(!LED_PIN_Read());
    UART_1_UartPutString("Hi");
    Timer_1_ReadStatusRegister();
    Timer_1_Stop();      

    
}




CY_ISR(SW_Int){
    LED_PIN_Write(!LED_PIN_Read());
    UART_1_UartPutString("press");
    Timer_1_Start();
    SW_ClearInterrupt();
    
    }

int main()
{

    CyGlobalIntDisable;
    isr_2_StartEx(TimerISR);
    isr_1_StartEx(SW_Int);
    UART_1_Start();
    CyGlobalIntEnable;
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
