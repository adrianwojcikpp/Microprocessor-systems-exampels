/**
  ******************************************************************************
  * @file    print_mem.c
  * @author  AW           Adrian.Wojcik@put.poznan.pl
  * @version 2.0
  * @date    14-Mar-2022
  * @brief   Printing memory content
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include "print_mem.h"
  
/* BEGIN RAW MEMORY -------------------------------------------- */
/**
 * @brief Printing content of 32-bit memory location
 *        as unsigned integer in decimal, hexadecimal and binary.
 * @param mem : Input memory address
 */
void print_mem(mem_t* mem)
{
  printf("Memory content [dec]: %10u \n", *mem);
  printf("Memory content [hex]: 0x%08X \n", *mem);
  printf("Memory content [bin]: 0b");
  for(int i = 8*sizeof(mem_t) - 1; i >= 0; i--)
  {
    printf("%c", ((1 << i) & *mem) ? '1' : '0');
  }
}
/* END RAW MEMORY ---------------------------------------------- */

/* BEGIN INTEGER ----------------------------------------------- */
/**
 * @brief Printing integer variable or literal 
 *        as a numeric value and memory content.
 * @param number_text : Input integer number as text
 * @param number : Input integer number as 'int32_t'
 */
void print_int32(const char* number_text, int32_t number)
{
  printf("Integer variable / literal: %s \n", number_text);
  printf("Value [dec]: %d \n", number);
  print_mem( (mem_t*)&number ); /* Casting 'number' address to  
                                   'mem_t' pointer             */
}
/* END INTEGER ------------------------------------------------- */

/* BEGIN FIXED-POINT ------------------------------------------- */
/**
 * @brief Printing fixed-point variable or literal 
 *        from <-1.0, 1.0) range as a numeric value and memory content.
 * @param number_text : Input fixed-point fractional number as text
 * @param number : Input fixed-point fractional number as 'q31_t'
 */
void print_q31(const char* number_text, q31_t number)
{
  printf("Fixed-point variable / literal: %s \n", number_text);
  printf("Value [dec]: %0.15f \n", Q31_TO_DOUBLE(number));
  print_mem( (mem_t*)&number ); /* Casting 'number' address to  
                                   'mem_t' pointer             */
}
/* END FIXED-POINT --------------------------------------------- */

/* BEGIN FLOATING-POINT -----------------------------------------*/
/**
 * @brief Printing single-precision floating point variable or literal 
 *        as a numeric value and memory content.
 * @param number_text : Input floating-point fractional number as text
 * @param number : Input floating-point fractional number as 'float'
 */
void print_float(const char* number_text, float number)
{
  printf("Floating-point variable / literal: %s \n", number_text);
  printf("Value [dec]: %0.15f \n", number);
  print_mem( (mem_t*)&number ); /* Casting 'number' address to  
                                   'mem_t' pointer             */
}
/* END FLOATING-POINT -------------------------------------------*/