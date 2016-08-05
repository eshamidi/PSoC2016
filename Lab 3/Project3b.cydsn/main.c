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

void PrintInt(int b){
    char buf[10];
    sprintf(buf, "%d", b); 
    UART_1_UartPutString(buf);

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


int CountWords(char *str1){
    int WordCt = 0; 

//while string is not 0
    while(*str1 != 0){
        //if char is not a space...
        if(*str1 != 32){
            //advance...if space, word
            str1++;
            if(*str1 == 32){
            WordCt++;
            str1++; 
            }
        }
    }
    UART_1_UartPutString("\n \r Your text has ");  
    PrintInt(WordCt); 
    UART_1_UartPutString(" words. "); 
    return WordCt; 
    
    
}


void LongWords(char *str1, int WD_CT){
    int WordLet[WD_CT];
    int pos = 0; 
    int WD_LN = 0;
    
    //store length of words in array as long as word count
    while(*str1 != 0){
        if(*str1 != 32){
            WD_LN++;
        }
        
        if(*str1 == 32){
            WordLet[pos] = WD_LN;
            pos++;
            WD_LN = 0; 
        }
        str1++;
    }
//print number of letters in each word     
  for (pos = 0; pos < WD_CT; pos++)
  {
  PrintInt(WordLet[pos]);
  UART_1_UartPutString("  "); 
  }    

    
    //find max value from array
  int max = WordLet[0];
  int max_loc = 0; 

  for (pos = 1; pos < WD_CT; pos++)
  {
    if (WordLet[pos] > max)
    {
       max  = WordLet[pos];
       max_loc = pos+1;
    }
  }
  int maximum = WordLet[max_loc - 1];
    UART_1_UartPutString("\n \r Your longest word has ");  
    PrintInt(maximum);
    UART_1_UartPutString(" letters. ");  
    
    
    
}


void VowelWords(char *str1, int WD_CT){
 int VowLet[WD_CT];
    int pos = 0; 
    int VW_CT = 0;
    
    //store length of words in array as long as word count
    while(*str1 != 0){
        if((*str1 == 65) | (*str1 == 97) //A, a 
         | (*str1 == 69) | (*str1 == 101) // E, e
         | (*str1 == 73) | (*str1 == 105) // I, i
         | (*str1 == 79) | (*str1 == 111) // O, o
         | (*str1 == 85) | (*str1 == 117)){  //U, u
            VW_CT++;
        }        
        if(*str1 == 32){
            VowLet[pos] = VW_CT;
            pos++;
            VW_CT = 0; 
        }
        str1++;
    }
    
    
  for (pos = 0; pos < WD_CT; pos++)
  {
  PrintInt(VowLet[pos]);
  UART_1_UartPutString("  "); 
  }    

  int max = VowLet[0];
  int max_loc = 0; 

  for (pos = 1; pos < WD_CT; pos++)
  {
    if (VowLet[pos] > max)
    {
       max  = VowLet[pos];
       max_loc = pos+1;
    }
  }
  int maximum = VowLet[max_loc - 1];
    UART_1_UartPutString("\n \r Word ");  
    PrintInt(max_loc);
    UART_1_UartPutString(" has the most vowels. It has ");  
    PrintInt(maximum);
    UART_1_UartPutString(". \n \r ");
    
    
}






int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_1_Start(); /* Start the UART component. */
    int WordCount = 0;
    int MAX_BUFFER_SIZE = 20; 
    char str1[MAX_BUFFER_SIZE];
    
    
    UART_1_UartPutString("\n \r Enter in a line of text.");    
    readString(str1);
    WordCount = CountWords(str1);
    LongWords(str1, WordCount);
    VowelWords(str1, WordCount);
    
}

/* [] END OF FILE */
