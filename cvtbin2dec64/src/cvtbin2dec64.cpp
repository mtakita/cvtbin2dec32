
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

void putdec64( int64_t n ){

  uint16_t d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10;
  uint16_t d11, d12, d13, d14, d15, d16, d17, d18, d19, q;

  uint8_t n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
  uint8_t n11, n12, n13, n14, n15, n16, n17, n18, n19;

  if( n < 0 ){
    putchar( '-' );
    n = -n;
  }

  n0 = n & 0xF;
  n1 = (n>>4) & 0xF;
  n2 = (n>>8)& 0xF;
  n3 = (n>>12)& 0xF;
  n4 = (n>>16)& 0xF;
  n5 = (n>>20)& 0xF;
  n6 = (n>>24)& 0xF;
  n7 = (n>>28)& 0xF;
  n8 = (n>>32)& 0xF;
  n9 = (n>>36)& 0xF;
  n10 = (n>>40)& 0xF;
  n11 = (n>>44)& 0xF;
  n12 = (n>>48)& 0xF;
  n13 = (n>>52)& 0xF;
  n14 = (n>>56)& 0xF;
  n15 = (n>>60)& 0xF;

  d0 =  ( 6 * (n15 +n14 +n13 +n12 +n11 +n10 +n9 +n8 +n7 +n6 +n5 +n4 +n3 +n2 +n1) + n0 );
  q = d0 / 10;
  d0 = d0 % 10;

  d1 = q + ( 9 * (n13 + n8 + n3 ) + 7* ( n15 + n10 + n5) + 5 * ( n12 + n7 + n2) + 3 * ( n14 + n9 + n4 ) + n11 + n6 + n1 ); //  * 10;
  q = d1 / 10;
  d1 = d1 % 10;
  
  d2 = q + (9 * ( n15 + n14 ) + 7 * ( n10 + n9 ) + n12*6 + 5 * ( n5 + n4 ) + 4 * ( n13 + n11 + n7 ) + 2 * ( n8 + n6 ) + n2*2 ); // * 100;
  q = d2 / 10;
  d2 = d2 % 10;
  
  d3 = q + ( n5*8 + 7 * ( n14 + n10 + n8 + n6 ) + 6 * ( n15 + n9 ) + 5 * ( n7 + n4) + 4 * ( n11 + n3 ) ); // * 1000;
  q = d3 / 10;
  d3 = d3 % 10;

  d4 = q + ( 7 * (n13 + n9 + n6 ) + 6 * (n8 + n4 ) +4 * (n15 + n11 + n5 ) + n7*3 + 2 * (n14 + n10) + n12); // * 10000;
  q = d4 / 10;
  d4 = d4 % 10;

  d5 = q + (9 * (n14 +n8 ) + n15*8 +7 * (n12 + n6 ) + n10*6 + 4 * (n9 +n7 ) + n13*3 ); // * 100000;
  q = d5 / 10;
  d5 = d5 % 10;

  d6 = q + ( n9*9 + n7*8 + 7 * (n14 + n13 ) + 6 * (n15 + n12 +n11 +n6 ) + n8*4 + n10 + n5 ); // * 1000000;
  q = d6 / 10;
  d6 = d6 % 10;
  
  d7 = q + ( n8*9 + n11*8 + n12*7 + n7*6 + n14*3 + n13*2 + n10 + n9 + n6 ); // * 1000000;
  q = d7 / 10;
  d7 = d7 % 10;
  
  d8 = q + ( n12*9 + n9*7 + 6 * (n15 +n13 ) + n10*5 + 2 * (n8 + n7 ) + n11 ); // * 100000000;
  q = d8 / 10;
  d8 = d8 % 10;
  
  d9 = q + ( 9 * (n13 + n10 ) + n9*8 + 4 * (n15 + n14 + n12 + n8 ) + n11*2 ); // * 1000000000;
  q = d9 / 10;
  d9 = d9 % 10;
  
  d10 = q + (9 * (n14 + n13 + n11 + n10 ) + n12*7 + n9*6 ); // * 10000000000;
  q = d10 / 10;
  d10 = d10 % 10;
  
  d11 = q + (5 * (n15 + n14 + n13 + n11 ) + n12*4 ); // *100000000000;
  q = d11 / 10;
  d11 = d11 % 10;
  
  d12 = q + ( 7 * (n14 + n11 ) + n13*3 +  n15 + n12 + n10 ); // * 1000000000000;
  q = d12 / 10;
  d12 = d12 % 10;
  
  d13 = q + ( n15*2 + n14*5 + n12*8 + n11*1 ); // * 10000000000000;
  q = d13 / 10;
  d13 = d13 % 10;
  
  d14 = q + ( n15*9 + n13*5 + n12*2 ); // * 100000000000000;
  q = d14 / 10;
  d14 = d14 % 10;
  
  d15 = q + ( 2 * (n15 + n14 ) + n13*4 ); // * 1000000000000000;
  q = d15 / 10;
  d15 = d15 % 10;
  
  d16 = q + ( n15*5 + n14*7 ); // * 10000000000000000;
  q = d16 / 10;
  d16 = d16 % 10;
  
  d17 = q + ( n15*1 ); // * 100000000000000000;
  q = d17 / 10;
  d17 = d17 % 10;
  
  d18 = q + ( n15*1 ); // * 1000000000000000000;
  q = d18 / 10;
  d18 = d18 % 10;

  d19 = q;
  
  putchar( d19 + '0' );
  putchar( d18 + '0' );
  putchar( d17 + '0' );
  putchar( d16 + '0' );
  putchar( d15 + '0' );
  putchar( d14 + '0' );
  putchar( d13 + '0' );
  putchar( d12 + '0' );
  putchar( d11 + '0' );
  putchar( d10 + '0' );
  putchar( d9 + '0' );
  putchar( d8 + '0' );
  putchar( d7 + '0' );
  putchar( d6 + '0' );
  putchar( d5 + '0' );
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

void test_putdec64(){
  int64_t i = -1;

  putdec64( 16 );

  do{
    i++;
    putdec64( i );

  }while( (i+1) < 256 );

  putdec64( 9223372036854775807 );

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
  //test_cvtb2d();
  test_putdec64();
	exit(0);

	return 0;

}

