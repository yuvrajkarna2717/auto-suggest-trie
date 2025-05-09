#include <iostream>
#include <cassert>
#include <algorithm>
#include "../include/Trie.hpp"

// Helper function to print a vector of strings (for debugging)
void printVector(const std::vector<std::string>& vec) {
    for (const auto& word : vec) {
        std::cout << word << std::endl;
    }
}

void testTrie() {
    Trie trie;

    // Test 1: Insert and retrieve words with a given prefix
    trie.insert("apple");
    trie.insert("app");
    trie.insert("applause");
    trie.insert("ape");

    std::vector<std::string> result = trie.getWordsWithPrefix("ap");
    assert(result.size() == 4);  // Should return 4 words

    std::sort(result.begin(), result.end());

    std::vector<std::string> expected1 = {"ape", "app", "applause", "apple"};
    std::sort(expected1.begin(), expected1.end());

    assert(result == expected1);

    // Test 2: Search with a prefix that doesn't match any word
    result = trie.getWordsWithPrefix("xyz");
    assert(result.empty());

    // Test 3: Single word insert and exact prefix match
    trie.insert("banana");
    result = trie.getWordsWithPrefix("banana");
    assert(result.size() == 1);
    assert(result[0] == "banana");

    // Test 4: Prefix with no match (should return empty)
    result = trie.getWordsWithPrefix("zz");
    assert(result.empty());

    std::cout << "✅ All tests passed successfully!" << std::endl;
}

int main() {
    testTrie();
    return 0;
}
