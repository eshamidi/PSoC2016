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
#include <stdbool.h> 

bool accept_input;
int blink_it; 

void PrintInt(int b){
    char buf[10];
    sprintf(buf, "%d", b); 
    UART_1_UartPutString(buf);

}

CY_ISR(UART_Int) /* ISR associated with the UART. */
{
uint32 rxData;
rxData = UART_1_UartGetChar(); /* Get character from buffer. */
UART_1_UartPutChar(rxData); /* Echo back to terminal. */
if((rxData > 47) & (rxData < 54)){
    blink_it = rxData - 49; 
}
/* Process the user input as appropriate. */
/* Clear the interrrupt. */
UART_1_ClearRxInterruptSource(UART_1_GetRxInterruptSource());
}


CY_ISR(SW_Int) /* ISR associated with the GPIO. */
{
CyDelay(50); /* Debouncing the switch. */
while(!SW_Read()); /* Wait for switch to be released. */
CyDelay(50);

if(accept_input == false){
    UART_1_UartPutString("\n \r Input is enabled");
}
else{
    UART_1_UartPutString("\n \r Input is disabled");
}
accept_input = !(accept_input);

SW_ClearInterrupt(); /* Clear the interrupt. */
}



int main()
{

accept_input = false; 
int blkt = 500;     
    
CyGlobalIntDisable; /* Disable global interrupts. */
UART_Int_StartEx(UART_Int); /* Start the ISR. */



SW_Int_StartEx(SW_Int); /* Start the ISR. */
CyGlobalIntEnable; /* Enable global interrupts */


UART_1_Start(); /* Start the UART. */


for(;;){

if(accept_input == true){

    switch(blink_it){
    case 0:
    blkt = 500; 
    break; 
    
    case 1:
    blkt = 1000; 
    break; 
    
    case 2:
    blkt = 1500; 
    break;
    
    case 3:
    blkt = 2000; 
    
    break; 
    
    case 4:
    blkt = 2500;
    break;
    
}
}


RED_LED_Write(!(RED_LED_Read()));    
CyDelay(blkt); 
    
    
/* Procesing code. */
}
}