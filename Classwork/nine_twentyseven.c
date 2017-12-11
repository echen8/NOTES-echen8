#include <stdio.h>

int main() {

  char *s = "hello";
  char s1[] = "hello";
  printf( "s points to: %p\n", s);
  printf( "s1 points to: %p\n", s1);
  printf( "address of \"hello\": %p\n", &"hello");
  
}
