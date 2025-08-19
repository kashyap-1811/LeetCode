class DataStream {
public:
    stack<int> s;
    int value;
    int k;

    DataStream(int value, int k) {
        this->value = value;
        this->k = k;    
    }
    
    bool consec(int num) {
        if(num != value){
            // clear by reassigning
            s = stack<int>();
            return false;
        }

        s.push(num);

        return s.size() < k ? false : true;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */