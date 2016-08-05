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
#include <time.h>

char combo[5] = {'1', '2', '3', '4', '5'};
int currentState = -1;
bool disable_entry = false;
int tc = 0; 



CY_ISR(timerISR) /* ISR to handle tc interrupts from timer. */
{

if(currentState == -2){
    
RED_LED_Write(!RED_LED_Read());
    
}

tc++; //timer triggers every 100 ms, 10 = 1 s


/* Your ISR code. */
/* Reset the interrupt. */
Timer_1_ReadStatusRegister();
}






char getButton(){
    char rxData;
    rxData = UART_1_UartGetChar();
    
    UART_1_UartPutChar(rxData);
    
    return rxData; 
    
    

}
void PrintInt(int b){
    char buf[10];
    sprintf(buf, "%d", b); 
    UART_1_UartPutString(buf);

}
void Printchar(char b){
    char buf[10];
    sprintf(buf, "%c", b); 
    UART_1_UartPutString(buf);

}

void InitCode(){
    currentState = -2;
    int i = 0;
    char verify;
    char combo1[sizeof(combo)], combo2[sizeof(combo)];
    bool isEqual = true;
    
    UART_1_UartPutString("\n \r Enter code:"); //initial entry of new code
    while(i < 5){
        verify = getButton();
        if(verify > '0'){
        combo1[i] = verify;
        i++;
        }
        
    }
    
    UART_1_UartPutString("\n \r Enter code again to confirm:"); //second confirmation entry
    i = 0; 
    while(i < 5){
        verify = getButton();
        if(verify > '0'){
            combo2[i] = verify;
            i++;
        }
        
    }
    
    i = 0; 
    while(i < 5){
        if(combo1[i] != combo2[i]){
            isEqual = false;  
        }
        i++;
    }
    
    i = 0; 
    if( isEqual == true){

        while(i<5){
            combo[i] =  combo1[i];
            i++;
        }
    }
    else{
            UART_1_UartPutString("\n \r Codes do not match. Exiting and keeping old code...");
        
    }
    
UART_1_UartPutString("\n \r Code has been reset to ");
    i = 0; 
    while(i<5){
Printchar(combo[i]);
        i++;
    }
    
    UART_1_UartPutString(" Don't forget to lock it again!");
currentState = -1; 
RED_LED_Write(1); 
    
        
        
        
        
}
    







int getCombination(){
    
    
 /* Our start state. */
char input;



while(1){
    /* Get button pushed by user via UART. */

    input = getButton();
 
    if(input == combo[0]){
        if(currentState == 0 ){
            tc = 0; //timer set to 0   
            currentState = 1; 
          
        }
        else{
        return 0; 
        }
       }
    
    if(input == combo[1]){
        if(currentState == 1){
            currentState = 2;
        }
        else{
        return 0;
        }
    }
        
    if(input == combo[2]){
        if(currentState == 2){
            currentState = 3; 
        }
        else{
        return 0; 
        }
    }
        
    if(input == combo[3]){
        if(currentState == 3){
            currentState = 4; 
        }
        else{
        return 0; 
        }
    }    

    if(input == combo[4]){
        if(currentState == 4){
            return 1;  
            currentState = -1; 
        }
        else{
        return 0; 
        }
    }
    
    if(tc > 50 & currentState > 0 ){
        UART_1_UartPutString("\n \r Out of time!");
        tc = 0; 
        return 0;
    }

}
}


    
    
    
int main()
{
    
CyGlobalIntDisable; /* Disable global interrupts. */    
timerISR_StartEx(timerISR);
    

CyGlobalIntEnable; /* Enable global interrupts. */
Timer_1_Start(); 

int failed = 0; 
int returnval = 0;     
UART_1_Start();    
UART_1_UartPutString("\n \r Combination Lock Program");
UART_1_UartPutString("\n \r Stock Combination is ");
   int  i = 0; 
    while(i<5){
Printchar(combo[i]);
        i++;
    }

RED_LED_Write(1);


char locked = '0'; 
UART_1_UartPutString("\n \r Initial status: Unlocked. Press 1 to lock, or 2 to reset the code:");


for(;;){


    
locked = getButton();
if(failed >3){
    break;
}


switch (locked){ //state if locked
    case '1':
    currentState = 0;
    RED_LED_Write(100); //turns on LED 
    UART_1_UartPutString("\n \r Locked. Enter in the code:");
    for(;;){
        returnval = getCombination();
        if(returnval == 1){
            locked = '0'; 
            RED_LED_Write(1); //turn off LED 
            currentState = -1; //reset lock state to unlocked, or -1 
            UART_1_UartPutString("\n \r Unlocked! Press 1 to lock again, or 2 to reset the code:");
            failed = 0; //failed attempts back to 0
            break;
        }
        else{
            failed++; //increment fail state 
            if(failed > 3){
            UART_1_UartPutString("\n \r You have failed 3 attempts. System is locked.");
            break;
            }
        else{    
        UART_1_UartPutString("\n \r Incorrect. Try again. Fail attempt ");

        PrintInt(failed);
        UART_1_UartPutString("\n \r");
            }
        currentState = 0; //reset lock state to beginning 

        }
    }
    break;

    
    case '2':
    UART_1_UartPutString("\n \r Code Reset. Enter in your new code:");
    InitCode();
    break;
    
    
    default:
    
    break;
    
    
    
}
}


    







    
    
    
    
    
    
}
  
    



/* [] END OF FILE */
