class DoublyLinkedList {
public:
    int val;
    int key;
    DoublyLinkedList* next;
    DoublyLinkedList* prev;

    DoublyLinkedList() {
        this->val = -1;
        this->key = -1;
        this->next = nullptr;
        this->prev = nullptr;
    }

    DoublyLinkedList(int val, int key) {
        this->val = val;
        this->key = key;
        this->next = nullptr;
        this->prev = nullptr;
    }

    DoublyLinkedList(int val, int key, DoublyLinkedList* next,
                     DoublyLinkedList* prev) {
        this->val = val;
        this->key = key;
        this->next = next;
        this->prev = prev;
    }
};

class LRUCache {
public:
    int capacity;
    int size;
    unordered_map<int, DoublyLinkedList*> m;
    DoublyLinkedList* head;
    DoublyLinkedList* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            // print();
            return -1;
        }

        DoublyLinkedList* node = m[key];

        if (node == tail) {
            // print();
            return node->val;
        }
        if (node == head) {
            if(head == tail)    
                head = tail = nullptr;
            else
                head = head->next;
        }
        
        if (node->next)
            node->next->prev = node->prev;
        if (node->prev)
            node->prev->next = node->next;
        node->prev = nullptr;
        node->next = nullptr;

        if (tail == nullptr)
            head = tail = node;
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        // print();
        return node->val;
    }

    void put(int key, int value) {
        size++;
        DoublyLinkedList* newNode = new DoublyLinkedList(value, key);

        if (m.find(key) != m.end()) {
            DoublyLinkedList* existingNode = m[key];
            if (existingNode->next)
                existingNode->next->prev = existingNode->prev;
            if (existingNode->prev)
                existingNode->prev->next = existingNode->next;
            
            if (existingNode == head) 
                head = head->next;

            if(existingNode == tail)
                tail = tail->prev;

            existingNode->prev = nullptr;
            existingNode->next = nullptr;
            delete existingNode;
            size--;
        }

        if (tail == nullptr)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        m[key] = newNode;

        if (size > capacity) {
            DoublyLinkedList* dummy = head;
            head = head->next;

            if (head)
                head->prev = nullptr;
            else
                tail = nullptr;

            dummy->next = nullptr;
            m.erase(dummy->key);
            delete dummy;
            size--;
        }

        // print();
    }

    void print() {
        DoublyLinkedList *temp = head;

        while(temp != nullptr) {
            cout <<"(" << temp->key << "," << temp->val << ") ";
            temp = temp->next;
        }

        cout << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */