/**
  ******************************************************************************
  * @file    L04_example_01.c
  * @author  AW           Adrian.Wojcik@put.poznan.pl
  * @version 2.0
  * @date    14-Mar-2022
  * @brief   Instruction #04 bit manipulation playground
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>

/* Main function -------------------------------------------------------------*/

/**
  * @brief  The application entry point.
  * @retval 0 
  */
int main()
{
   uint32_t arg1 = 0x55555555;
   uint32_t arg2 = 0xAAAAAAAA;
   
   puts("                      HEX        | DEC");
   puts("----------------------------------------------");
   printf("ARG #1             :  0x%08x | %010u \n", arg1, arg1);
   printf("ARG #2             :  0x%08x | %010u \n", arg2, arg2);
   printf("(ARG #1) %c (ARG #2):  0x%08x | %010u \n", '&', arg1 & arg2, arg1 & arg2);
}
