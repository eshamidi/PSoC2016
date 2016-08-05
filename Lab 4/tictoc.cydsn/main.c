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
#include <time.h>





#define MATRIX_SIZE 5
float tc;
float elapsedTime;
float elapsed1, elapsed2, lead, trail;



void PrintInt(int b){
    char buf[10];
    sprintf(buf, "%d", b); 
    UART_1_UartPutString(buf);

}

void matrixMult(float A[MATRIX_SIZE][MATRIX_SIZE], \
float B[MATRIX_SIZE][MATRIX_SIZE], \
float C[MATRIX_SIZE][MATRIX_SIZE])
{
int8 i, j, k;
float temp;
for(i = 0; i < MATRIX_SIZE; i++){
for(j = 0; j < MATRIX_SIZE; j++){
temp = 0.0;
for(k = 0; k < MATRIX_SIZE; k++){
temp += A[i][k] * B[k][j];
}
C[i][j] = temp;
}
}
}

void populateMatrix(float M[MATRIX_SIZE][MATRIX_SIZE])
{
int8 i, j;
for(i = 0; i < MATRIX_SIZE; i++){
for(j = 0; j < MATRIX_SIZE; j++){
M[i][j] = (float)rand()/(float)2147483647;
}
}
}





CY_ISR(UART_Int) /* ISR to handle UART interrupts. */
{
/* Your ISR code. */
/* Clear the interrupt. */
UART_1_ClearRxInterruptSource(UART_1_GetRxInterruptSource());
}



CY_ISR(timerISR) /* ISR to handle tc interrupts from timer. */
{
tc = tc + 1;
/* Your ISR code. */
/* Reset the interrupt. */
Timer_1_ReadStatusRegister();
}


void tic(void)
{
lead =  ( 24000 - Timer_1_ReadCounter() )/24000000; 
elapsed1 = tc;     
    
/* Your code. */
}


void toc(void)
{
trail =  (Timer_1_ReadCounter())/24000000;
elapsed2 = tc;
/* Your code. */
}



int main()
{
CyGlobalIntDisable; /* Disable global interrupts. */
    
UART_Int_StartEx(UART_Int);
timerISR_StartEx(timerISR);

CyGlobalIntEnable;

UART_1_Start(); /* Start the UART. */
Timer_1_Start(); /* Start timer. */
srand(rand()); /* Initialize random number generator. */
float A[MATRIX_SIZE][MATRIX_SIZE];
float B[MATRIX_SIZE][MATRIX_SIZE];
float C[MATRIX_SIZE][MATRIX_SIZE];

for(;;){
    populateMatrix(A); /* Populate matrices with random numbers. */
    populateMatrix(B);
    tic(); /* Time the multiplication operation. */
    matrixMult(A, B, C);
    toc();
    /* Display elapsed time on the terminal. */
    CyDelay(1000);
    elapsedTime = elapsed2 - elapsed1 + lead + trail; 
    UART_1_UartPutString("It took ");
    PrintInt(elapsedTime); 
    UART_1_UartPutString(" ms ");
    UART_1_UartPutString("\n \r");
    
    
    
    

}
}
