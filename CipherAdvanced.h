// Jake Lunski
// CPSC 1071-002
// Binary Beasts
// 4/3/2023

#ifndef CIPHER_ADVANCED_H
#define CIPHER_ADVANCED_H

// Headers
#include <string>
#include <vector>
#include <unordered_set>
#include "Cipher.h"

using namespace std;

class CipherAdvanced : public Cipher {
public:
    CipherAdvanced();

    bool isInDictionary(const string& word);                // isInDictionary function takes in a string reference and returns a boolean whether the word is found in the dictionary or not.
    vector<string> unknownScramble(const string& word);     // unknownScramble function takes a string reference and returns a vector of strings that could be the possible unscrambled word.

private:
    void loadDictionary();                                  // function that loads a dictionary of words into an unordered_set
    string toLowerCase(const string& word);                 // this function converts a string to lower case.
    bool isNonSpecial(const string& word);                  // function that checks whether a string contains only alphabetic characters.
    void makeKeys(int keySize, int depth, int keys[5], const string& encodedWord, Cipher& cipherInstance, unordered_set<string>& possibleWords);       //function that generates the key for a given word.

    unordered_set<string> dictionary;                  // stores the loaded dictionary of words.
};

#endif 





















