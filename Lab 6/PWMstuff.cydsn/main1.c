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

int inc = 1; 
bool updown = false;
uint16 PWMCompare = 0; 




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
    if(PWMCompare <= 100){
        updown = false;
    }
   
           
    UART_1_UartPutString(" \n \r");
    Timer_1_ReadStatusRegister();
        
    
}


void PrintInt(int b){
    char buf[10];
    sprintf(buf, "%d", b); 
    UART_1_UartPutString(buf);

}

int main()
{
isr_1_StartEx(TimerISR);
    CyGlobalIntEnable; /* Enable global interrupts. */

PWM_1_Start(); 
UART_1_Start();
Timer_1_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
// PWM Triangle wave - part 1
    for(;;)
    {
        

        PrintInt(PWMCompare);
        PWM_1_WriteCompare(PWMCompare);
        CyDelay(1);
        
        /* Place your application code here. */
    }

    
    
    
    
    
}