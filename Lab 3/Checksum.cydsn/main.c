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

void CheckSum(int *ch){
    
    int acc = 0;
    int *strpt1 = ch;
    int dblvar = 0;
    int c_sum[20];
    int adv = 0;  
    
    
    while(*strpt1 != 0){ 
    
        // odd digit case - modulus 
    if(((strpt1-ch) % 2) == 1){
        
        dblvar = (*strpt1-48) *2; //multiply by 2 
        if(dblvar >= 10){ //if greater than 10, subtract 10 add 1 
        dblvar = dblvar - 10 + 1;
        //PrintInt(dblvar);
        UART_1_UartPutString(" ");
        }
        acc+= dblvar; //accumulator variable adds result
                   
        }
        
    else{
        acc+= *strpt1 - 48;
        //PrintInt(*strpt1 - 48);
        UART_1_UartPutString(" ");
        
    }
    strpt1++;     
        
    }
    
    
    if(acc % 10 == 0){
    UART_1_UartPutString("\n \r The number is valid. ");    
    }
    else{
     UART_1_UartPutString("\n \r The number is not valid. ");    
    }
    
    
}

void PrintInt(int b){
    char buf[10];
    sprintf(buf, "%d", b); 
    UART_1_UartPutString(buf);

}


void readString(int *buffer)
{
uint32 rxData;
int *ptr = buffer;
    
for(;;){
    rxData = UART_1_UartGetChar();
    if(rxData){
        UART_1_UartPutChar(rxData); /* Echo character. */
        /* On a carriage return, null terminate the string
        and break out of the loop. */
        if(rxData == 13){
        *ptr = 0;
        break;
        }
*ptr = rxData;
ptr++;
}
}
}


int main()
{
    CyGlobalIntEnable;      /* Enable global interrupts */
    UART_1_Start(); /* Start the UART component. */
    int choice[20];
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    while(choice){
        
    UART_1_UartPutString("\n \r Enter the number you'd like to check with the formula: ");
    readString(choice); //take in address of choice variable, set it to what user enters
    CheckSum(choice); 
    
    }
    for(;;)
    {
        /* Place your application code here */
    }
}

