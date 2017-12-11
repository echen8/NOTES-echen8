#include <stdio.h>

int fxn( int x ) {
  return x += 3;
}

int main() {
  printf( "x + 3 where x = 4: %d\n", fxn( 4 ) );
}
