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

int ms_acc; 
int seconds = 0;
int minutes = 0;
int hours = 0;
char buf[10];
int rxData; 
bool reset = true; 
int max_value; 

void PrintInt(int b){
    char buf[10];
    sprintf(buf, "%d", b); 
    UART_1_UartPutString(buf);

}


int read2Dig(int limit) // read in 2 digits, convert to int. must be less than 24 H, 60 min, 60 s. 
{
int rxData;
char digit[2];
int dig = 0;
int clk = 0; 
    
for(;;){ //read in 2 ascii characters to an array of length 2. 
    rxData = UART_1_UartGetChar();
    if(rxData){
        UART_1_UartPutChar(rxData);
        digit[dig] = rxData;
        dig++;
        if(dig >= 2){
            break;
        }
        /* Echo character. */
        /* On a carriage return, null terminate the string
        and break out of the loop. */
        }
    

}
//converts from ascii to int
digit[0] = digit[0] - 48; 
digit[1] = digit[1] - 48; 

clk = digit[0]*10 + digit[1];

if(clk >= limit){
    UART_1_UartPutString("\n \r Error - you have input a value outside the bounds. Try again:");
    clk = read2Dig(limit);
}

return clk; 
}

void InitClk(){

UART_1_UartPutString("\n \r Enter in hour value:");
hours = read2Dig(24);//hours
UART_1_UartPutString("\n \r Enter in minute value:");
minutes = read2Dig(60);//minutes
UART_1_UartPutString("\n \r Enter in seconds value:");
seconds = read2Dig(60);//minutes    
reset = true;     
    
}


CY_ISR(UART_Int) /* ISR to handle UART interrupts. */
{

rxData = UART_1_UartGetChar(); /* Get character from buffer. */
UART_1_UartPutChar(rxData); /* Echo back to terminal. */
if(rxData == 99){
    reset = false; 
    InitClk();
       
}


/* Process the user input as appropriate. */
/* Clear the interrrupt. */

UART_1_ClearRxInterruptSource(UART_1_GetRxInterruptSource());
}




CY_ISR(timerISR) /* ISR to handle the tc interrupt. */
{
ms_acc++;
    
if(ms_acc == 5){
    seconds++;
    ms_acc = 0;
}

if(seconds == 60){
    minutes++;
    seconds = 0;
}

if(minutes == 60){
    hours++;

}
if(hours == 24){
    hours = 0;

}
    
/* Code to handle tc interrupt. */
/* Reset the interrupt. */
Timer_1_ReadStatusRegister();
}


int main(){

CyGlobalIntDisable;
    
UART_Int_StartEx(UART_Int);
timerISR_StartEx(timerISR);


CyGlobalIntEnable;
ms_acc = 0; 

UART_1_Start(); /* Start the UART. */
UART_1_UartPutString("Established connection to terminal. \n \r");


/* Code to initialize wall clock here. */
InitClk();

Timer_1_Start(); /* Start the timer. */


for(;;)
{

if(reset == true){
sprintf(buf, "%02d : %02d : %02d", hours, minutes, seconds);
UART_1_UartPutString("\n \r");
UART_1_UartPutString(buf);
}
CyDelay(1000);

}
}
