/**
  ******************************************************************************
  * @file    array_example.c
  * @author  AW		adrian.wojcik@put.poznan.pl
  * @version 3.0
  * @date    09-May-2022
  * @brief   Arrays in C
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>

/* Defines -------------------------------------------------------------------*/
#define array_size(x) sizeof( x ) / sizeof( x[0] )

/* Global variables ----------------------------------------------------------*/
uint8_t x[10];

/* Main function -------------------------------------------------------------*/

/**
  * @brief  The application entry point.
  * @retval 0 
  */
int main(void)
{
  uint8_t y[10] = { 0 };
  
  printf("uint8_t sizeof(): %llu\n", sizeof(x[0])); // %I64u instead of %llu for Microsoft Visual Studio
  printf("Array 'x' sizeof(): %llu\n", sizeof(x));
  printf("Array 'x' number of elements: %llu\n", array_size(x));
  
  for(int i = 0; i < 10; i++)
    printf("%d\n", y[i]);
  
  return 0;
}