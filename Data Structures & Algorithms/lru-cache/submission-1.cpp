class LRUCache {
public:
   class Node{
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k , int v){
            key = k;
            val = v;
            prev = next = NULL;
        }
   };

   Node* head = new Node(-1, -1);
   Node* tail = new Node(-1, -1);
   unordered_map<int, Node*>mpp;
   int limit;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        int ans = mpp[key]->val;
        Node* ansNode = mpp[key];
        mpp.erase(key);
        deleteNode(ansNode);
        addNode(ansNode);
        mpp[key] = ansNode;
        return ans;
    }
    
    void put(int key, int value) {
        // if key already exists
        if(mpp.find(key) != mpp.end()){
            Node* oldNode = mpp[key];
            deleteNode(oldNode);
            mpp.erase(key);
        }

        // capacity reached
        if(mpp.size() == limit){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        } 

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mpp[key] = newNode;
    }

    void addNode(Node* node){
        // insert at head -> next
        Node* temp = head->next;

        head-> next = node;
        temp->prev = node;

        node->next = temp;
        node->prev = head;
    }

    void deleteNode(Node* node){
        Node* oldPrev = node->prev;
        Node* oldNext = node-> next;

        oldPrev -> next = oldNext;
        oldNext -> prev = oldPrev;
    }
};
