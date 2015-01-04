#include "runningAverage.h"
#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[] ) {
  unsigned n = 3;
  RunningAverage avg(3); 
  RunningRatio rat1(3), rat2(3); 
  for ( int i = 0; i < argc; i++ ) {
    double x = atof(argv[i]);
    printf ( "\nadding %lf: avg=%lf, rat1=%lf, rat2=%lf\n", x, avg(x), rat1(x, 1), rat2 (x, 2) );
    vector<double> &avgs = avg.avgs();
    vector<double> &rats1 = rat1.avgs();
    vector<double> &rats2 = rat2.avgs();
    unsigned n = avgs.size();
    for ( int i = 0; i < n; i++ ) {
      printf ( "  %d: avg %lf, rat1 %lf, rat2 %lf\n", i, avgs[ i ], rats1 [ i ], rats2 [ i ] );
    }
  }
};
