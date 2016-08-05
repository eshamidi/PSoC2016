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

int compareStrings(char *str1, char *str2)
{
    char *strpt1 = str1; 
    char *strpt2 = str2; 
    int Match = 0; 
    int countlen_1 =0; 
    int countlen_2 =0; 
    
    for(;;){
        if(*strpt1 != *strpt2){
            UART_1_UartPutString("\n \r Your strings do not match. ");
            break; //break loop
        }
        strpt1++;
        strpt2++;
        if( *strpt1 == 0 & *strpt2 ==0){
            UART_1_UartPutString("\n \r Your strings match. ");
            Match = 1; 
            break;
        }
    }
    
        return Match; 
}

    

int searchForChar(char *str, char *ch){
    char *strpt1 = str; 
    int pos = 0; 
    int FindMatch = -1; 
    
    for(;;){
        if(*strpt1 == *ch){
            UART_1_UartPutString("\n \r Your string first has the specified character at position = ");
            pos  = strpt1 - str;
            PrintInt(pos);
            FindMatch = 1; 
            break; 
        }
        strpt1++;
        if(*strpt1 == 0){
            UART_1_UartPutString("\n \r Your string doesn't have that character. ");
            break;
        }
        
    }
    
       

     return FindMatch; 
}


int searchSubString(char *str, char *subStr)
{
    char *strpt1 = str; 
    char *strpt2 = subStr; 
    int Matchpt = 0; 
    int isSSet = -1; 
    
while(*strpt1 != 0){
    if(*strpt1 == *strpt2){
        Matchpt = strpt1 - str;
        //UART_1_UartPutString("\n \r String 2 may be a subset of String 1.... ");
        Matchpt = strpt1 - str; //save match start point
        while(*strpt2 != 0){
            if(*strpt1 != *strpt2){
                UART_1_UartPutString("\n \r String 2 is not a full subset of String 1. ");
                Matchpt = 0;
                break;
            }
            strpt1++;
            strpt2++;
            if(*strpt2 ==0 | *strpt1 == 0){
                break;
            }
        }
                
      
            }
    strpt1++;
    
}
if(Matchpt != 0)
{
    UART_1_UartPutString("\n \r String 2 is a subset of String 1, starting at position ");
    PrintInt(Matchpt); 
}
else
{
   UART_1_UartPutString("\n \r String 2 is not a subset of String 1 "); 
  }
    return Matchpt; 

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

void readInt(int *choice){
    int rxData;
    int *ptr1 = choice; 
    
for(;;){
    rxData = UART_1_UartGetChar();
    if(rxData){
        UART_1_UartPutChar(rxData); /* Echo character. */
        /* On a carriage return, null terminate the string
        and break out of the loop. */
        if(rxData == 13){
        *ptr1 = 0;
        break;
        }
*ptr1 = rxData - 48;
ptr1++;
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
int MAX_BUFFER_SIZE = 20; 
int choice;
int8 status;
char ch[2];
char str1[MAX_BUFFER_SIZE], str2[MAX_BUFFER_SIZE], buffer[MAX_BUFFER_SIZE];


while(choice){
UART_1_UartPutString("\n \r Function to execute (1 for string \ compare, 2 of character search, 3 for sub-string \2 search, or -1 to exit): ");
readInt(&choice); //take in address of choice variable, set it to what user enters


if(choice == -3) break;
switch(choice){

case 1:
/* Read in the strings and store them in str1
and str2. */
UART_1_UartPutString("\n \r Enter first string.");    
readString(str1);
UART_1_UartPutString("\n \r Enter second string.");
readString(str2);
status = compareStrings(str1, str2);
break;

case 2:
/* Read in the string, store it in str1; the
character in ch. */
UART_1_UartPutString("\n \r Enter first string.");    
readString(str1);
UART_1_UartPutString("\n \r Enter second string.");
readString(ch);
status = searchForChar(str1, ch);
UART_1_UartPutString("\n \r Status is: ");
PrintInt(status);
break;

case 3:
/* Read in the string, store it in str1; the
substring in str2. */
UART_1_UartPutString("\n \r Enter first string.");    
readString(str1);
UART_1_UartPutString("\n \r Enter second string.");
readString(str2);
status = searchSubString(str1, str2);
UART_1_UartPutString("\n \r Status is: ");
PrintInt(status);
break;
default:
UART_1_UartPutString("\n \r Erroneous entry. Try again.");
};
}
UART_1_UartPutString("\n \r All done. Idling the CPU.");
for(;;)
{
/* Let the microprocessor run. */
}
}
