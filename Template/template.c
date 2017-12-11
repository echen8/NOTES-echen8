/*
=====================================================================

                           TEMPLATE MAKER!
                      #iUseCamelCaseBecauseICan

=====================================================================
*/

/*
============================== DEV LOG ==============================

CREDITS:
- Eric Chen


KNOWN BUGS:
- Creates files with ? around the filename.
- makefile a tad bit wonky.
- Empty space on top of .c file.


FUTURE IMPLEMENTATIONS:
- Automatic Header Generator given Name, Period, Work No.

============================== *** *** ==============================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


// TESTED - WORKING!
void make( char * dPath, char * cName, char * exeName ) {
  
  char completePath[513];
  strcpy( completePath, dPath );
  strcat( completePath, "makefile" );
  
  size_t fd = open( completePath, O_CREAT | O_TRUNC | O_WRONLY, 0666 );
  
  char buffer[2048] = "all: ";
  strcat( buffer, cName );
  strcat( buffer, "\n\tgcc -o " );
  strcat( buffer, exeName );
  strcat( buffer, " " );
  strcat( buffer, cName );
  strcat( buffer, "\nrun: all\n\t./" );
  strcat( buffer, exeName );
  strcat( buffer, "\nclean:\n\trm *~" );

  write( fd, buffer, sizeof( buffer ) );
  
  close( fd );
  
}

// TESTED - WORKING!
void makeC( char * dPath, char * cName ) {

// void makeC( char * student, int period, int workNo, char * dPath, char * cName ) {

  char completePath[513];
  strcpy( completePath, dPath );
  strcat( completePath, cName );
  
  size_t fd = open( completePath, O_CREAT | O_TRUNC | O_WRONLY, 0666 );

  char messyBuffer[2048] = "\n";
  
  /*
  char messyBuffer[2048] = "// ";
  strcat( messyBuffer, student );
  strcat( messyBuffer, "\n// Period " );
  strcat( messyBuffer, (char *)period );
  strcat( messyBuffer, "\n// WORK " );
  strcat( messyBuffer, (char *)workNo );
  */
  
  strcat( messyBuffer, "\n\n#include <stdio.h>\n" );
  strcat( messyBuffer, "#include <stdlib.h>\n" );
  strcat( messyBuffer, "#include <unistd.h.h>\n" );
  strcat( messyBuffer, "#include <sys/stat.h>\n" );
  strcat( messyBuffer, "#include <string.h>\n" );
  strcat( messyBuffer, "#include <fcntl.h>\n" );
  strcat( messyBuffer, "\nint main() {\n\n  // Start coding here.\n\n  return 0;\n}\n" );

  // Removes all unfilled spaces in messyBuffer
  int length = strlen( messyBuffer );
  char buffer[ length ];
  strncpy( buffer, messyBuffer, length );
  
  write( fd, buffer, sizeof( buffer ) );
  
  close( fd );
  
}



int main( int argc, char * argv[] ) {

  int version = 1;

  printf( "========================================\n" );
  printf( " Starting Eric's Template Maker v%d.0...\n", version );
  printf( "========================================\n" );

  /*
  // Get the Name, pd#, HW#
  char name[256];
  int pd = (unsigned int *)calloc( 1, sizeof( unsigned int ) );
  int hw = (unsigned int *)calloc( 1, sizeof( unsigned int ) );
  
  printf( "\nHello! What is your name?\n" );
  printf( "NAME: " );
  fgets( name, sizeof( name ), stdin );
  sleep( 1 );
  
  // THIS PART GIVES SEG FAULT \/

  printf( "\nGreat! %s, what Systems Period are you in? Please only provide the period number.\n", name );
  printf( "PD#: " );
  fgets( pd, sizeof( pd ), stdin );
  sleep( 1 );
  
  printf( "\nAwesome! What Work# is this for?\n" );
  printf( "WORK#: " );
  fgets( hw, sizeof( hw ), stdin );
  sleep( 1 );

  char dataYN[1];
  printf( "\n\nHere's what I got from you.\n\tNAME: %s\n\tPeriod#%d\n\tWork#%d\n\nIs this info correct?\n", name, pd, hw );
  printf( "Respond with (y/n) ONLY: " );
  fgets( dataYN, sizeof( dataYN ), stdin );
  sleep( 1 );

  if ( dataYN == "n" ) {
    printf( "\nOops! The program will now exit for you to be able to resubmit your information!\n" );
    printf( "Exiting in 3 seconds...\n" );
    sleep( 3 );
    exit( 0 );
  }
  else if ( dataYN != "y" ) {
    printf( "\nHmm... I don't recognize your input! The program will now exit for you to resubmit your information\n" );
    printf( "Exiting in 3 seconds...\n" );
    sleep( 3 );
    exit( 0 );
  }
  
  */

  // Ask for the exact directory path from current file.
  char d[256];
  printf( "Enter the directory path from this directory to the working directory.\n" );
  printf( "  Note:         The directory must already be created.\n" );
  printf( "  Example Path: 'dir1/dir2/dir3/'\n" );
  printf( "PATH: " );
  fgets( d, sizeof( d ), stdin );
  printf( "\n\nPath Saved.\n\n\n" );
  sleep( 1 );

  // Ask for the desired .c file name. (ie. "main.c")
  char c[256];
  printf( "Enter the desired .c file name.\n" );
  printf( "  Example Name: 'main.c'\n" );
  printf( "C FILE NAME: " );
  fgets( c, sizeof( c ), stdin );
  printf( "\n\nC File Name Saved.\n\n\n" );
  sleep( 1 );
  
  // Ask for the desired executable name.
  char exe[256];
  printf( "Enter the desired executable (AKA compiled) file name.\n" );
  printf( "EXECUTABLE NAME: " );
  fgets( exe, sizeof( exe ), stdin );
  printf( "\n\nExecutable Name Saved.\n\n\n" );
  sleep( 1 );

  printf( "Now creating files in specified directory...\n\n" );

  // Create makefile
  make( d, c, exe );
  printf( "Successfully created makefile!\n\n" );

  // Create .c file
  makeC( d, c );
  // makeC( name, pd, hw, d, c );
  printf( "Successfully created %s!\n\n", c );

  printf( "Done!  Thanks for using Eric's Template Maker v%d.0!\n\n", version );
  
  return 0;
}
