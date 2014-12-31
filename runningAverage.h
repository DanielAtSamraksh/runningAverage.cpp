/// running average
#include <vector>
using std::vector;

struct RunningAverage {
  /* double *nums; */
  /* double *_avgs; */
  vector<double> nums;
  vector<double> _avgs;
  unsigned size; // maximum size of the running average
  unsigned currentIndex; // always points where a new value will go

  RunningAverage ( unsigned size ) : size(size), currentIndex(0) {};

  double operator() ( double x ) {
    if ( nums.size() < size ) {nums.push_back(x); currentIndex++;}
    else { nums[currentIndex] = x; currentIndex = (currentIndex+1)%size; }
    double sum = 0;
    unsigned i = 0;
    while ( i < nums.size() ) sum += this->nums[i++];
    return sum / nums.size();
  };

  vector<double> &avgs() {
    unsigned n = this->nums.size();
    this->_avgs.resize(n);
    double sum = 0;
    for ( unsigned i = 0; i < n; i++ ) {
      double num = this->nums [ ( currentIndex + n - 1 - i ) % n ];
      sum += num;
      this->_avgs [ i ] = i > 0? sum / (1+i): sum;
    }
    return _avgs;
  };
  
  double latest() {
    return this->nums[ this->currentIndex ];
  };
};
  
