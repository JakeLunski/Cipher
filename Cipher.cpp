// Jake Lunski
// CPSC 1071-002
// Binary Beasts
// 4/3/2023

#include "Cipher.h"
#include <cctype>

using namespace std;

// Constructor for Cipher class
Cipher::Cipher() {
    setCipher(defaultKeySize, defaultKey);
}

// // Set the cipher key for the Cipher class
void Cipher::setCipher(int size, int key[]) {
    keySize = size;     // Save the key size
    originalKey = new int[keySize]; // Allocate memory for the originalKey array
    for (int i = 0; i < keySize; i++) {
        originalKey[i] = key[i];      // Copy the input key array to the originalKey array
    }

    // Clear the existing repeatingKey queue
    while (!repeatingKey.isEmpty()) {
        int temp;
        repeatingKey.dequeue(temp);
    }

    // Enqueue the key elements in a repeating manner
    for (int i = 0; i < keySize; i++) {
        repeatingKey.enqueue(key[i]);
    }
}

// Get the cipher key for the Cipher class
int* Cipher::getCipher() {
    int* keyCopy = new int[keySize];
    for (int i = 0; i < keySize; ++i) {
        keyCopy[i] = originalKey[i]; // Copy the elements from the originalKey array to the keyCopy array
    }
    return keyCopy;     // Return the keyCopy array
}

// Encode a message using the current cipher key
string Cipher::encodeMessage(string input) {
    return processMessage(input, true);     // Process the message with the current key and flag set to true
}

// Decode a message using the current cipher key
string Cipher::decodeMessage(string input) {
    return processMessage(input, false);    // Process the message with the current key and flag set to false
}

// Process a message with the current cipher key
string Cipher::processMessage(string input, bool encode) {
    string processed = "";
    int* key = getCipher(); // Save the current state of the repeating key
    int keyIndex = 0;

    for (char ch : input) {             // Iterate over each character in the input string
        if (isalpha(ch)) {              // If the character is a letter
            ch = tolower(ch);           // Convert the character to lowercase
            int shift = key[keyIndex];      // Get the shift value from the key
            if (!encode) {              // If decoding the message
                shift = -shift;         // Negate the shift value
            }
            ch = (ch - 'a' + shift) % 26;    // Apply the shift to the character
            if (ch < 0) {
                ch += 26;
            }
            ch += 'a';

            processed += ch;    // Add the processed character to the output string

            keyIndex = (keyIndex + 1) % keySize;     // Increment the key index, wrapping around to the start if necessary
        }
    }

    delete[] key; // Free the memory allocated for the key

    return processed;   // Return the processed message
}
