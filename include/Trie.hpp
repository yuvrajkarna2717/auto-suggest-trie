// include/Trie.hpp

#ifndef TRIE_HPP
#define TRIE_HPP

#include <string>
#include <vector>

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode();
};

class Trie {
private:
    TrieNode* root;

    void dfs(TrieNode* node, std::string prefix, std::vector<std::string>& results);

public:
    Trie();
    void insert(const std::string& word);
    std::vector<std::string> getWordsWithPrefix(const std::string& prefix);
};

#endif // TRIE_HPP
