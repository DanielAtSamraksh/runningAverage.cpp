#include "runningAverage.h"
#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[] ) {
  RunningAverage avg(3); 
  for ( int i = 0; i < argc; i++ ) {
    double x = atof(argv[i]);
    printf ( "adding %lf: running average is now %lf\n", x, avg(x) );
  }
};
