class Trie {
public:
    struct Node {
        bool isEnd;
        Node* children[26];
        Node() {
            isEnd = false;
            for(int i=0;i<26;i++) {
                children[i] = nullptr;
            }
        }
    };
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* curr = root;
        for(auto ch : word) {
            if(!curr->children[ch-'a']) {
                curr->children[ch-'a'] = new Node();
            }
            curr = curr->children[ch-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(auto ch : word) {
            if(!curr->children[ch-'a']) {
                return false;
            }
            curr = curr->children[ch-'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(auto ch : prefix) {
            if(!curr->children[ch-'a']) {
                return false;
            }
            curr = curr->children[ch-'a'];
        }
        return true;
    }
};