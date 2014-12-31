/// running average

struct RunningAverage {
  double *nums;
  unsigned size; // maximum size of the running average
  unsigned currentIndex; // always points where a new value will go
  bool isFull; // true if at least size values have been submitted
  RunningAverage ( unsigned size ) : size(size), currentIndex(0),
    isFull(false), nums( new double[size] ){};
  double operator() ( double x ) {
    // add x to nums and increment the current index
    this->nums [ this->currentIndex ] = x;
    this->currentIndex = (this->currentIndex + 1 ) % this->size;
    if ( this->currentIndex == 0 ) isFull = true;
    
    double sum = 0;
    unsigned i = 0;
    unsigned n = this->isFull? this->size: this->currentIndex;
    while ( i < n ) sum += this->nums[i++];
    return sum / n;
  };
  double latest() {
    return this->nums[ this->currentIndex ];
  };
};
  
