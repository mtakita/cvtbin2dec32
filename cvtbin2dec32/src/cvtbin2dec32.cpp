
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstdint>
#include <math.h>

uint8_t q, r;

void div10( uint8_t i ){

	q = ((i>>1) + i ) >> 1;
	q = ((q>>4) + q ) >> 3;

	r = ((q<<2) + q) << 1;
	r = i - r;

	if( r >= 10 ){
		r = r - 10;
		q = q + 1;
	}

	printf( "%d( %d ) = %d / 10\n", q, r, i );
}

void test_div10(){

	uint8_t i = -1;

	do{
		i++;
		div10( i );
	}while( (i + 1) < 256 );

}

void putdec( int16_t n ){

  uint8_t d4, d3, d2, d1, d0, q;

  if( n < 0 ){
    putchar( '-' );
    n = -n;
  }

  d1 = (n>>4) & 0xF;
  d2 = (n>>8) & 0xF;
  d3 = (n>>12)& 0xF;

  d0 = 6*(d3 + d2 + d1 ) + ( n & 0xF );
  q = (d0 * 0xCD ) >> 11;
  d0 = d0 - 10*q;

  d1 = q + 9*d3 + 5* d2 + d1;
  q = (d1 * 0xCD ) >> 11;
  d1 = d1 - 10*q;

  d2 = q + 2*d2;
  q = (d2 * 0x1A) >> 8;
  d2 = d2 - 10*q;

  d3 = q + 4*d3;
  d4 = (d3 * 0x1A ) >> 8;
  d3 = d3 - 10*d4;

  putchar( d4 + '0' );
  putchar( d3 + '0' );
  putchar( d2 + '0' );
  putchar( d1 + '0' );
  putchar( d0 + '0' );

  putchar( '\n' );

}

void test_putdec(){

	uint8_t i = -1;

	do{
		i++;
		putdec( i );
	}while( (i + 1) < 256 );

}


void cvtb2d( uint32_t n ){

  uint32_t d0, d1, d2, d3, d4, d5, dd5, d6, dd6, d7, dd7, d8, d9, q;

  d0 = n       & 0xF;
  d1 = (n>>4)  & 0xF;
  d2 = (n>>8)  & 0xF;
  d3 = (n>>12) & 0xF;
  d4 = (n>>16) & 0xF;
  d5 = (n>>20) & 0xF;
  d6 = (n>>24) & 0xF;
  d7 = (n>>28) & 0xF;
  

  d0 = 6 * ( d7 + d6 + d5 + d4 + d3 + d2 + d1 ) + d0;
  q = d0 / 10;
  d0 = d0 % 10;

  d1 = q + ( 5*(d7 + d2) + d6 + 7*d5 + 3*d4 + 9*d3 + d1 );
  q = d1 / 10;
  d1 = d1 % 10;

  d2 = q + ( 4*d7 + 2*d6 + 5*(d5+d4) + 2 * d2 );
  q = d2 / 10;
  d2 = d2 % 10;

  d3 = q + ( 5*(d7+d4) + 7*d6 + 8*d5 + 4*d3 );
  q = d3 / 10;
  d3 = d3 % 10;

  d4 = q + ( 3*d7 + 7*d6 + 4*d5 + 6*d4 );
  q = d4 / 10;
  d4 = d4 % 10;

  dd5 = q + ( 4*d7 + 7*d6 );
  q = dd5 / 10;
  dd5 = dd5 % 10;

  dd6 = q + ( 8*d7 + 6*d6 + d5 );
  q = dd6 / 10;
  dd6 = dd6 % 10;

  dd7 = q + ( 6*d7 + d6 );
  q = dd7 / 10;
  dd7 = dd7 % 10;

  d8 = q + 2*d7;
  q = d8 / 10;
  d8 = d8 % 10;

  d9 = q;

  printf( "%d ", n );
  
  putchar( d9 + '0' );
  putchar( d8 + '0' );
  putchar( dd7 + '0' );
  putchar( dd6 + '0' );
  putchar( dd5 + '0' );
  putchar( d4 + '0' );
  putchar( d3 + '0' );
  putchar( d2 + '0' );
  putchar( d1 + '0' );
  putchar( d0 + '0' );

  putchar( '\n' );

}

void test_cvtb2d(){
  for( long i = 0; i < 32474736; i++ ){
    cvtb2d( i );
  }

}

int main( int argc, char* argv[] ){
  //test_div10();
  //test_putdec();
  test_cvtb2d();
  
	exit(0);

	return 0;

}

