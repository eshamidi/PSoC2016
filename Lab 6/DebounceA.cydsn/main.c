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


void PrintInt(int b){
    char buf[10];
    sprintf(buf, "%d", b); 
    UART_1_UartPutString(buf);

}

int main()
{
    int press = 0;
    int tc_1, tc_2; 
    float time = 0; 
    int tc_new, tc_old;
    UART_1_Start();
    Timer_1_Start();
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
for(;;){
    
//PrintInt(SW_Read());

if(SW_Read() == 0){
    CyDelay(90);
    if(SW_Read() == 0){
        tc_1 = Timer_1_ReadCounter(); 
        press++;
    }
}

time = abs(tc_2 - tc_1)/10;
tc_2 = tc_1;

if(press == 2){
    
    UART_1_UartPutString("\n \r Time Between Presses: ");
    PrintInt(time);
    UART_1_UartPutString(" ms  ");
    press = 0; 
}
    
    

    
    }


}

/* [] END OF FILE */
