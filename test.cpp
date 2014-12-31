#include "runningAverage.h"
#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[] ) {
  unsigned n = 3;
  RunningAverage avg(3); 
  for ( int i = 0; i < argc; i++ ) {
    double x = atof(argv[i]);
    printf ( "\nadding %lf: running average is now %lf\n", x, avg(x) );
    double *avgs = avg.avgs();
    unsigned n = avg.isFull? avg.size: avg.currentIndex;
    for ( int i = 0; i < n; i++ ) {
      printf ( "  %d: %lf\n", i, avgs[ i ] );
    }
  }
};
