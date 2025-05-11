// main.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "include/Trie.hpp"

using namespace std;

// Function to load words from the file into the Trie
void loadWordsFromFile(Trie& trie, const string& filename) {
    ifstream file(filename);
    string word;
    while (getline(file, word)) {
        trie.insert(word);  // Insert word into the Trie
    }
    file.close();
}

int main() {
    Trie trie;

    // Load words from 'words.txt' into the Trie
    loadWordsFromFile(trie, "data/words.txt");

    cout << "Enter a prefix to get suggestions: ";
    string prefix = "";
    char ch;

    while(cin >> ch) {
        prefix += ch;
        // Get all words that start with the prefix
        vector<string> suggestions = trie.getWordsWithPrefix(prefix);

        if (suggestions.empty()) {
            cout << "No suggestions found for prefix: " << prefix << endl;
        } else {
            cout << "Suggestions for prefix '" << prefix << "':" << endl;
            for (const string& word : suggestions) {
                cout << word << ", ";
            } 
        }
        cout << "\n";
    }

    return 0;
}
