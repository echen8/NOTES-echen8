#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

	int READ = 0;
	int WRITE = 1;

	int f;
	int fds[2];
	pipe( fds );

	f = fork();

	if ( f == 0 ) {
		close( fds[READ] );
		char s[10] = "bonjour!";
		sleep( 2 );
		write( fds[WRITE], s, sizeof(s) );
	}
	else {
		close( fds[WRITE] );
		char s[10];
		read( fds[READ], s, sizeof(s) );
		printf( "parent received: [%s]\n", s );
	}

	return 0;
}
