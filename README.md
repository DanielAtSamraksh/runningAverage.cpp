runningAverage.cpp
==================

Simple class that computes a running average.

example
-------

    cat - > test.cpp <<< EOF
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
    EOF
    
    > g++ test.cpp -o testa
    ./testa 1 2 3 4 5 6 7
    adding 0.000000: running average is now 0.000000
    adding 1.000000: running average is now 0.500000
    adding 2.000000: running average is now 1.000000
    adding 3.000000: running average is now 2.000000
    adding 4.000000: running average is now 3.000000
    adding 5.000000: running average is now 4.000000
    adding 6.000000: running average is now 5.000000
    adding 7.000000: running average is now 6.000000


    

