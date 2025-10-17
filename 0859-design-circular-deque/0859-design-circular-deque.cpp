class MyCircularDeque {
public:
    int size;
    int k;
    int front;
    int rear;
    vector<int> dq;

    MyCircularDeque(int k) {
        this->k = k;
        size = 0;
        front = -1;
        rear = -1;
        dq.resize(k);
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;

        if (isEmpty())
            front = rear = 0;
        else
            front = (front - 1 + k) % k;
        
        dq[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;

        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % k;
        
        dq[rear] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        
        size--;
        if (isEmpty())
            front = rear = -1;
        else
            front = (front + 1) % k;
        
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;

        size--;
        if (isEmpty())
            front = rear = -1;
        else
            rear = (rear - 1 + k) % k;
        
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return dq[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return dq[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};


/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */