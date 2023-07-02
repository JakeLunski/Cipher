// Jake Lunski
// CPSC 1071-002
// Binary Beasts
// 4/3/2023

#include "CipherAdvanced.h"
#include <fstream>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <unordered_set>

using namespace std;

// Constructor for CipherAdvanced
CipherAdvanced::CipherAdvanced() {
    loadDictionary(); // Load the dictionary when the object is created
}

// Function to load the dictionary file
void CipherAdvanced::loadDictionary() {
    ifstream file("/usr/share/dict/words");

    if (!file) {
        file.open("/usr/dict/words");
    }

    // If the file is open, read words and insert them into the dictionary
    if (file) {
        string word;
        while (file >> word) {
            string lowerWord = toLowerCase(word);
            if (isNonSpecial(lowerWord)) {
                dictionary.insert(lowerWord);
            }
        }
    } else {
        cout << "Failed to open the dictionary file." << endl;
    }

    file.close();
}

// Function to check if a word is in the dictionary
bool CipherAdvanced::isInDictionary(const string& word) {
    
    // Convert the word to lowercase
    string lowercaseWord = toLowerCase(word);
    return dictionary.find(lowercaseWord) != dictionary.end();
}

// Function to check if a word contains only alphabetic characters
// (Gaddis, 17.5)
bool CipherAdvanced::isNonSpecial(const string& word) {
    for (const char &c : word) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

// Recursive function to generate keys and test possible words
void CipherAdvanced::makeKeys(int keySize, int depth, int keys[5], const string& encodedWord, Cipher& cipherInstance, unordered_set<string>& possibleWords) {
    if (depth == keySize) {
        cipherInstance.setCipher(keySize, keys);
        string decoded = cipherInstance.decodeMessage(encodedWord);
        if (isInDictionary(decoded)) {
            cout << decoded << endl; // Print the decoded word if it's in the dictionary
            dictionary.erase(decoded);  // Remove the decoded word from the dictionary
            possibleWords.insert(decoded);

        }
        return;
    }

    for (int i = 1; i <= 26; ++i) {
        keys[depth] = i;
        makeKeys(keySize, depth + 1, keys, encodedWord, cipherInstance, possibleWords);
    }
}


// Function to find possible words from a scrambled word
vector<string> CipherAdvanced::unknownScramble(const string& word) {
    int unknownWordLength = 0;
    for (char c : word) {
        if (isalpha(c)) {
            ++unknownWordLength;
        }
    }
    // load the dictionary
    loadDictionary();

    unordered_set<string> possibleWordsSet;     // create a set for the possible words
    Cipher cipherInstance;      // create a cipher object

    for (int keySize = 1; keySize <= 5; ++keySize) {
        int keys[5] = {0};
        makeKeys(keySize, 0, keys, word, cipherInstance, possibleWordsSet);
    }

    // sort the words alphabetically
    vector<string> possibleWords(possibleWordsSet.begin(), possibleWordsSet.end());
    sort(possibleWords.begin(), possibleWords.end());

    return possibleWords;
}

// Function to convert a string to lowercase
string CipherAdvanced::toLowerCase(const string& word) {
    string lowerWord = word;
    for (size_t i = 0; i < lowerWord.size(); ++i) {
        lowerWord[i] = tolower(lowerWord[i]);
    }
    return lowerWord;
}











