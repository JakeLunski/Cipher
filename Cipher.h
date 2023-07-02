// Jake Lunski
// CPSC 1071-002
// Binary Beasts
// 4/3/2023
#ifndef CIPHER_H
#define CIPHER_H

// Headers
#include <string>
#include "Queue.h"

using namespace std;

class Cipher {
public:
    Cipher();
    void setCipher(int, int[]);     // set the encryption key for the cipher
    int* getCipher() ;              // returns a pointer to the encryption key array
    string encodeMessage(string);   // takes a string and returns the encoded version of the string
    string decodeMessage(string);   // takes a string and returns the decoded version of the string

private:
    Queue repeatingKey;     // Queue for storing the repeating key
    static const int defaultKeySize = 4;    // sets default key size to 4
    int keySize;    // stores the key size
    int* originalKey;   // stores the original encryption key 
    int defaultKey[defaultKeySize] = {1, 2, 3, 4};  // Default key
    string processMessage(string, bool);        //  takes a string and a boolean indicating whether the function should encode or decode the string
};

#endif
