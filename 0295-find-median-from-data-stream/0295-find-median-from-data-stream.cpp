class MedianFinder {
public:
    vector<int> vec;

    MedianFinder() {}
    
    void addNum(int num) {
        int i = 0;
        for(i=0; i<vec.size() && vec[i]<num; i++);
        vec.insert(vec.begin() + i, num);
    }
    
    double findMedian() {
        int size = vec.size();
        if(size == 1)
            return double(vec[0]);
        if(size % 2 == 1)
            return double(vec[size / 2]);

        return ((double)vec[size / 2] + (double)vec[size / 2 - 1]) / 2;
    }
};

/**
1 2 3 4 5 6 
6 / 2 -> 3
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */