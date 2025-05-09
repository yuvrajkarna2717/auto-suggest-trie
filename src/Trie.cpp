// src/Trie.cpp

#include "../include/Trie.hpp"
#include <iostream>

TrieNode::TrieNode() {
    isEndOfWord = false;
    for (int i = 0; i < 26; ++i)
        children[i] = nullptr;
}

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const std::string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (!node->children[index])
            node->children[index] = new TrieNode();
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

void Trie::dfs(TrieNode* node, std::string prefix, std::vector<std::string>& results) {
    if (!node) return;

    if (node->isEndOfWord)
        results.push_back(prefix);

    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            char nextChar = 'a' + i;
            dfs(node->children[i], prefix + nextChar, results);
        }
    }
}

std::vector<std::string> Trie::getWordsWithPrefix(const std::string& prefix) {
    TrieNode* node = root;
    for (char ch : prefix) {
        int index = ch - 'a';
        if (!node->children[index])
            return {}; 
        node = node->children[index];
    }

    std::vector<std::string> results;
    dfs(node, prefix, results);
    return results;
}
