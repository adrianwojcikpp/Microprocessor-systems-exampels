/**
  ******************************************************************************
  * @file    struct_example.c
  * @author  AW		adrian.wojcik@put.poznan.pl
  * @version 3.0
  * @date    09-May-2022
  * @brief   Unions in C
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>

/* Typedef -------------------------------------------------------------------*/
typedef union {
  int8_t number;
  char   character;
} int8_to_char;

/* Main function -------------------------------------------------------------*/

/**
  * @brief  The application entry point.
  * @retval 0 
  */
int main(void)
{
  int8_to_char x = { .character = 'a' };
  int8_to_char y = { .number = 0x62 };
  
  printf("x var: %d | %c\n", x.number, x.character);
  printf("y var: %d | %c\n", y.number, y.character);
  
  return 0;
}