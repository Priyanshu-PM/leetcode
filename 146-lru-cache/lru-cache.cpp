class LRUCache {
public:
    struct Node {

        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };
    
    int cap = 0;

    struct Node* head = new Node(-1, -1);
    struct Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mpp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode)
    {
        struct Node* temp = head->next;
        newNode->next = temp;
        temp->prev = newNode;

        newNode->prev = head;
        head->next = newNode;
    }

    void deleteNode(Node* delNode) {
        struct Node* n1 = delNode->prev;
        struct Node* n2 = delNode->next;

        n1->next = n2;
        n2->prev = n1;
    }

    int get(int key) {
        
        if(mpp.find(key) != mpp.end()) {

            struct Node* res = mpp[key];
            int ans = res->val;

            mpp.erase(key);
            deleteNode(res);
            addNode(res);

            mpp[key] = res;
            return ans;
        }

        return -1;
    }
    
    void put(int key, int value) {
        
        if(mpp.find(key) != mpp.end()) {

            struct Node* current = mpp[key];
            mpp.erase(key);
            deleteNode(current);
        }

        if(mpp.size() == cap) {
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */