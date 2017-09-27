class MovingAverage {
private:
    int size;
    queue<double> nums;
    double mean;
public:
    /** Initialize your data structure here. */
    MovingAverage(int _size) {
        size = _size;
        mean = 0;
    }
    
    double next(int val) {
        int nums_size = nums.size();
        if (nums_size < size){
            mean = (mean*nums_size + val)/ (nums_size + 1);
        } else {
            mean = mean + (val - nums.front()) / size;
            nums.pop();
        }
        nums.push(val);
        return mean;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */