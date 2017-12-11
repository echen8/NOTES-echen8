#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

#define KEY 1234

int main() {

  int n = 10;

  int sd = shmget( KEY, sizeof( int ), 0600 | IPC_CREAT );

  int f = fork();
  
  if ( f ) {
    int status;
    wait( &status );
    int * m = shmat( sd, 0, 0 );
    printf( "P| m = [%d]\n", *m );
  }

  if ( !f ) {
    // n *= 2;
    int * m = shmat( sd, 0, 0 );
    *m = 113;
    printf( "C| m = [%d]\n", *m );
  }
  
  return 0;
}
