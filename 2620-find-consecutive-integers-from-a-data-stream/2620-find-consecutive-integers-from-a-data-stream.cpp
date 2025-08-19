class DataStream {
public:
    int count;
    int value;
    int k;

    DataStream(int value, int k) {
        this->value = value;
        this->k = k; 
        this->count = 0;   
    }
    
    bool consec(int num) {
        if(num != value){
            count = 0;
            return false;
        }

        count++;

        return count < k ? false : true;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */