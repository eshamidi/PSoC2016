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
#include <stdio.h>


int press = 0; 
int seconds_new, seconds_old, ms_new, ms_old, time_s, time_ms;


void PrintInt(int b){
    char buf[10];
    sprintf(buf, "%d", b); 
    UART_1_UartPutString(buf);

}





CY_ISR(SW_Int){
 if(SW_Read() == 0){
    CyDelay(90);
    if(SW_Read() == 0){
        UART_1_UartPutString("\n \r press");
        ms_old = ms_new;
        ms_new = Timer_1_ReadCounter();
        
        
        seconds_old = seconds_new;
        seconds_new = Timer_2_ReadCounter();
        

        press++;
        SW_ClearInterrupt();
        }
    }   
    
    
    }


int main()
{
    CyGlobalIntDisable;
    isr_sw_StartEx(SW_Int);

    
    CyGlobalIntEnable;      /* Enable global interrupts */

    UART_1_Start();
    Timer_1_Start();
    Timer_2_Start();
    
    
    for(;;)
    {

      if(press == 2){
            
                        
            time_s = abs(seconds_new - seconds_old)/1000;
            time_ms = (ms_old + 24000 - ms_new);
            
            UART_1_UartPutString("\n \r Time Between Presses: ");
            PrintInt(time_s);
            UART_1_UartPutString(".");
            PrintInt(time_ms);
            UART_1_UartPutString(" s");
            press = 0; 
        }
}
}

