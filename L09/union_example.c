/**
  ******************************************************************************
  * @file    union_example.c
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

typedef union {
  uint8_t raw[sizeof(float)];
  float  fp;
} uint8_to_float;

typedef union {
  uint8_t raw[sizeof(double)];
  double  fp;
} uint8_to_double;

typedef union {
  uint8_t raw[sizeof(long double)];
  long double  fp;
} uint8_to_longdouble;

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
  
  //uint8_to_float a = { .fp = 1.0f };
  uint8_to_float a = { .raw = {0x00,0x00,0x80,0x3f} };
  
  
  printf("\n\n floating-point | memory content \n"); 
  
  printf("a var: %f | 0x%02x%02x%02x%02x\n", 
				a.fp, a.raw[3], a.raw[2], a.raw[1], a.raw[0]);
  
  //uint8_to_double b = { .fp = 1.0 };
  uint8_to_double b = { .raw = {0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x3f} };
  
  printf("b var: %f | 0x%02x%02x%02x%02x%02x%02x%02x%02x\n", 
			b.fp, 
					b.raw[7], b.raw[6], b.raw[5], b.raw[4],
					b.raw[3], b.raw[2], b.raw[1], b.raw[0]);
  
  //uint8_to_longdouble c = { .fp = 1.0L };
  uint8_to_longdouble c = { .raw = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
									0xff,0x3f,0x00,0x00,0x00,0x00,0x00,0x00} };
  
  printf("c var: %Lf | 0x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\n", 
			c.fp, 
					c.raw[15], c.raw[14], c.raw[13], c.raw[12],
					c.raw[11], c.raw[10], c.raw[ 9], c.raw[ 8],
					c.raw[ 7], c.raw[ 6], c.raw[ 5], c.raw[ 4],
					c.raw[ 3], c.raw[ 2], c.raw[ 1], c.raw[ 0]);
  
  // add garbage to 6 most significant bytes
  c.raw[15] = 0xaa;
  c.raw[14] = 0xbb;
  c.raw[13] = 0xcc;
  c.raw[12] = 0xdd;
  c.raw[11] = 0xee;
  c.raw[10] = 0xff;
  
  printf("c var: %Lf | 0x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\n", 
			c.fp, 
					c.raw[15], c.raw[14], c.raw[13], c.raw[12],
					c.raw[11], c.raw[10], c.raw[ 9], c.raw[ 8],
					c.raw[ 7], c.raw[ 6], c.raw[ 5], c.raw[ 4],
					c.raw[ 3], c.raw[ 2], c.raw[ 1], c.raw[ 0]);
  
  return 0;
}