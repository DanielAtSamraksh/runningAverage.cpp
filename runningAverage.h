#ifndef RUNNING_AVERAGE_H_
#define RUNNING_AVERAGE_H_

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
  bool dirty_avgs;
  
  RunningAverage ( unsigned size ) : size(size), currentIndex(0), dirty_avgs(true) {};

  double operator() ( double x ) {
    if ( nums.size() < size ) {nums.push_back(x); currentIndex++;}
    else { nums[currentIndex] = x; currentIndex = (currentIndex+1)%size; }
    double sum = 0;
    unsigned i = 0;
    while ( i < nums.size() ) sum += this->nums[i++];
    dirty_avgs = true;
    return sum / nums.size();
  };

  vector<double> &avgs() {
    if ( dirty_avgs ) {
      unsigned n = this->nums.size();
      this->_avgs.resize(n);
      double sum = 0;
      for ( unsigned i = 0; i < n; i++ ) {
	double num = this->nums [ ( currentIndex + n - 1 - i ) % n ];
	sum += num;
	this->_avgs [ i ] = i > 0? sum / (1+i): sum;
      }
      dirty_avgs = false;
    }
    return _avgs;
  };
  
  double latest() {
    return this->nums[ this->currentIndex ];
  };
};

struct RunningRatio {
  /* double *nums; */
  /* double *_avgs; */
  vector<double> nums, dens;
  vector<double> _avgs;
  unsigned size; // maximum size of the running average
  unsigned currentIndex; // always points where a new value will go
  bool dirty_avgs;
  
  RunningRatio ( unsigned size ) : size(size), currentIndex(0), dirty_avgs(true) {};

  double operator() ( double n, double d ) {
    if ( nums.size() < size ) { nums.push_back(n); dens.push_back(d); currentIndex++; }
    else { nums[currentIndex] = n;  dens[currentIndex] = d; currentIndex = (currentIndex+1)%size; }
    double ns = 0, ds = 0;
    unsigned i = 0;
    while ( i < nums.size() ) {
      ns += this->nums[i];
      ds += this->dens[i];
      i++;
    }
    dirty_avgs = true;
    return ns / ds; 
  };

  vector<double> &avgs() {
    if ( dirty_avgs ) {
      unsigned n = this->nums.size();
      this->_avgs.resize(n);
      double ns = 0, ds = 0;
      for ( unsigned i = 0; i < n; i++ ) {
	unsigned j = ( currentIndex + n - 1 - i ) % n;
	ns += this->nums[j];
	ds += this->dens[j];
	this->_avgs [ i ] = ns / ds;
      }
      dirty_avgs = false;
    }
    return _avgs;
  };
  
  double latest() {
    unsigned i = this->currentIndex;
    return this->nums[ i ] / this->dens[ i ];
  };
};

#endif // RUNNING_AVERAGE_H_
