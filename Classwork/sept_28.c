// LENGTH FUNCTION

#include <stdio.h>

int length( char *c ) {

  int i = 0;

  while ( c[i] ) {
    i++;
  }
  
  return i;
  
}

int main() {

  char arr[10] = "hello";
  printf( "Length of \"%s\": %d\n", arr, length( arr ) );
}
