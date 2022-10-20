#include <iostream>
#include "trie.h"

int main(){
    Trie t;
    
    std::string words[] {"hello","he","apple","aple","news"};
    
    for (std::string w: words) {
        t.insert(w);
    }
    
    std::string key{};
    std::cin >> key;
    
    std::cout << std::boolalpha << t.search(key) << "\n";
    
    return 0;
}
