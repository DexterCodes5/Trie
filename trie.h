#include <unordered_map>

// generic tree like structure
class node {

    char data;
    std::unordered_map<char, node*> m;
    bool isTerminal;
public:
    node(char d) :data{d}, isTerminal{false} {} 
    
    friend class Trie;
};

class Trie {
    node *root;
    
public:
    Trie() {
        root = new node('\0');
    }
    
    // Insertion
    void insert(std::string s) {
        node *temp = root;
        
        for (char c: s) {
            if (temp->m.count(c) == 0) {
                node *n = new node(c);
                temp->m[c] = n;
            }
            temp = temp->m[c];
        }
        temp->isTerminal = true;
    }
    
    // Searching
    bool search(std::string w) {
        node *temp = root;
        
        for (char c: w) {
            if (temp->m.count(c) == 0) {
                return false;
            }
            temp = temp->m[c];
        }
        return temp->isTerminal;
    }
};