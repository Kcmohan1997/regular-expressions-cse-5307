// Sivakumar, Namrata

// 2019-03-07

#include <ctype.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getToken( FILE *fp );
int status1, status2, status3;
int fp, str, intt;
regex_t re1, re2, re3;

const char* fppattern = "^[0-9]+[)]{1}[(]{1}[0-9]+$";
const char* intpattern = "^[#]{1}[r-wR-W0-9]+$";
const char* strpattern = "^[|]{1}[A-Z0-9]*[+]{1}$";


void processToken( char *token )
{
  fp = regcomp(&re1, fppattern, REG_EXTENDED);
  str = regcomp(&re2, strpattern, REG_EXTENDED);
  intt = regcomp(&re3, intpattern, REG_EXTENDED);

  int flag = 0;
      if (fp == 0 ) {
          status1 = regexec(&re1, token, 0, NULL, 0);
          if (status1 == 0 && flag == 0){
            printf(">%s< matches FP.\n", token);
            flag = 1;
          }
      }
    if (str == 0){
      status3 = regexec(&re2, token, 0, NULL, 0);
        if (status3 == 0 && flag == 0){
          printf(">%s< matches STR.\n", token);
          flag = 1;
        }    
    }
     if (intt==0){
      status2 = regexec(&re3, token, 0, NULL, 0);
        if (status2 == 0 && flag == 0){
          printf(">%s< matches INT.\n", token);
          flag = 1;
        }
    }
    if(flag == 0){
        printf(">%s< does not match.\n", token);
    }
    regfree(&re1);
    regfree(&re2);
    regfree(&re3);
}

int main( int argc, char *argv[] )
{
  if ( argc > 1 ) {
    printf( "processing tokens from %s ...\n", argv[1] );

    FILE *fp = fopen( argv[1], "r" );
    char *token = NULL;

    if ( fp != NULL ) {
      while ( token = getToken( fp ) ) {
        processToken( token );
        free( token );
      }

      fclose( fp );
    } else {
      printf( "unable to open %s?\n", argv[1] );
    }
  } else {
    printf( "No input file specified.\n" );
  }
}

#define MAX_TOKEN_SIZE (1024)

char *getToken( FILE *fp )
{
  char token[ MAX_TOKEN_SIZE+1 ];
  int  i  = 0;

  while ( i < MAX_TOKEN_SIZE ) {
    int ch = fgetc( fp );

    if ( ch == EOF ) { break; }

    if ( isspace( ch ) ) {
      if ( i == 0 ) { continue; }
      break;
    }

    token[ i++ ] = ch;
  }

  if ( i == 0 ) { return NULL; }

  token[ i ] = '\0';

  return strdup( token );
}
