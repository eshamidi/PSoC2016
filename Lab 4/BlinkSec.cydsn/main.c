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

int pressamt;
int countingup;

void PrintInt(int b){
    char buf[10];
    sprintf(buf, "%d", b); 
    UART_1_UartPutString(buf);

}


CY_ISR(SW_int)
{
/* Simple debouncing to eliminate any switch glitches. */
CyDelay(50);
while(!SW_Read()); /* Wait for switch to be released. */
CyDelay(50);

switch(countingup){
    case 1:
    pressamt++;
    if(pressamt == 4){
        countingup = 0;
    }
    break;
    
    case 0:
    pressamt--;
    if(pressamt == 0){
        countingup = 1;
    }
    break;
}
PrintInt(pressamt);

SW_ClearInterrupt(); /* Clear the interrupt. */
}



int main()
{
    
int blkt = 1000; 
pressamt = 0;
countingup = 1; 
   
UART_1_Start();

CyGlobalIntDisable; /* Disable global interrupts. */
SW_Int_StartEx(SW_int); /* Start the ISR. */





CyGlobalIntEnable; /* Enable global interrupts */
for(;;){
    
switch(pressamt){
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

RED_LED_Write(!(RED_LED_Read()));    
CyDelay(blkt);    
    /* Idle the processor. */
}
}