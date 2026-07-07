class FreqStack {
public:
    // Because an element reaches frequencies 1, 2, 3, ... over time. 
    // We record the moment it reaches each frequency. When its frequency 
    // decreases after a pop(), we simply move to the lower-frequency stack 
    // where its earlier record already exists.
    unordered_map<int, int> freq;          // value -> frequency
    unordered_map<int, stack<int>> group;  // frequency -> stack of values
    int maxFreq;

    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        
        int f = freq[val];
        if(f > maxFreq){
            maxFreq = f;
        }

        group[f].push(val);
    }
    
    int pop() {
        int val = group[maxFreq].top();
        group[maxFreq].pop();

        freq[val]--;
        if (group[maxFreq].empty())
            maxFreq--;

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */