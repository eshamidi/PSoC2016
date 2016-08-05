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
#include <stdbool.h>

uint16 PWMCompare = 0;
bool updown = false;


void PrintInt(int b){
    char buf[10];
    sprintf(buf, "%d", b); 
    UART_1_UartPutString(buf);

}

CY_ISR(TimerISR){
            
       if(updown == false)
         {
            PWMCompare+=1; 
        }
       if(updown == true){
        PWMCompare-= 1; 
    }
    
    if(PWMCompare >= 1000){
        updown = true;
    }
    if(PWMCompare <= 0){
        updown = false;
    }
    
        PWM_1_WriteCompare(PWMCompare);
        CyDelay(1);
        
    PrintInt(PWMCompare);    
    UART_1_UartPutString(" \n \r");
    Timer_1_ReadStatusRegister();
        
    
}




int main()
{
    PWM_1_Start();
    Timer_1_Start();
    UART_1_Start();
    CyGlobalIntDisable;
    isr_1_StartEx(TimerISR);
    
    CyGlobalIntEnable;
    
    
    for(;;)
    {

    }
/* [] END OF FILE */
}