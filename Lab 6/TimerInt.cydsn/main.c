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


int press = 0; 
int tc_1, tc_2;
int time; 

void PrintInt(int b){
    char buf[10];
    sprintf(buf, "%d", b); 
    UART_1_UartPutString(buf);

}



CY_ISR(SW_Int){

    CyDelay(90);
    if(SW_Read() == 0){
        tc_2 = tc_1;
        tc_1 = Timer_1_ReadCounter(); 
        press++;
        SW_ClearInterrupt();
        }
      
    
    
    }


int main()
{
    CyGlobalIntEnable;      /* Enable global interrupts */
    isr_sw_StartEx(SW_Int);
    UART_1_Start();
    Timer_1_Start(); 
    
    
    for(;;)
    {
        if(press == 2){
            
            
            time = abs(tc_2 - tc_1)/10;
            
            UART_1_UartPutString("\n \r Time Between Presses: ");
            PrintInt(time);
            UART_1_UartPutString(" ms  ");
            press = 0; 
        }

        /* Place your application code here */
    }
}

