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

int IsPalindrome(char *str, int len){
    
char str1[len];
char str_rev[len];
int i = 0;
char buf[10];
int status = 0; 

    //kill spaces - if not space, set equal, if space, increment root string
UART_1_UartPutString("\n \r  ");
while(*str != 0){
    if(*str != 32){
        str1[i] = *str;
    sprintf(buf, "%c", str1[i]);
    UART_1_UartPutString(buf);
        str++;
        i++;
  
    }
    else{
        str++;
    }
    
}

i = 0; 
//reverse jawn 
UART_1_UartPutString("\n \r  ");
for(i = 0; i < len; i++){
    str_rev[i] = str1[len-1-i];
    sprintf(buf, "%c", str_rev[i]);
    UART_1_UartPutString(buf);
}

for(i = 0; i < len; i++){
    if(str_rev[i] != str1[i]){
    UART_1_UartPutString("\n \r not a palindrome "); 
    status = 1;
    break; 
    }
}

if(status == 0){
    UART_1_UartPutString("\n \r yup, this is a palindrome. cool "); 
}
return status; 




}

int StrinLen(char *str){ //returns number of characters minus spaces 
    int length =0; 
    
    while(*str != 0){
        if(*str != 32){
            length++; 
            str++;
        }
        else{
            str++;
        }
    }
    
    return length;
    
    
    
    
}



void readString(char *buffer)
{
uint32 rxData;
char *ptr = buffer;
    
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

void PrintInt(int b){
    char buf[10];
    sprintf(buf, "%d", b); 
    UART_1_UartPutString(buf);

}



int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_1_Start(); /* Start the UART component. */
    char str1[20];
    int status;
        

    
    while(str1)
{
    UART_1_UartPutString("\n \r Enter a string for palindrome check: ");    
    readString(str1);
    int len = StrinLen(str1);
    status = IsPalindrome(str1, len);
    //PrintInt(status); 
    }
}

/* [] END OF FILE */
