class WordDictionary {
    struct Node{
        Node* links[26] = {};
        bool flag = false;

        bool containsKey(char ch){
            return links[ch - 'a'] != NULL;
        }

        void put(char ch, Node* node){
            links[ch - 'a'] = node;
        }

        Node* get(char ch){
            return links[ch - 'a'];
        }

        void setEnd(){
            flag = true;
        }

        bool isEnd(){
            return flag;
        }
    };
    Node* root;
    bool dfs(string& word, int idx, Node* node){
        if(idx == word.size()) return node-> isEnd();

        char ch = word[idx];
        if(ch != '.'){
            if(!node->containsKey(ch)) return false;
            return dfs(word, idx+1, node->get(ch));
        }

        // if ch == '.'
        for(int i = 0; i < 26; i++){
            if(node-> links[i] && dfs(word, idx+1, node-> links[i])) return true;
        }

        return false;
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;

        for(char ch : word){
            if(!node-> containsKey(ch)){
                node-> put(ch, new Node);
            }
            node = node -> get(ch);
        }
        node-> setEnd();
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
