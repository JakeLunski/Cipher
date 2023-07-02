// Jake Lunski
// CPSC 1071-002
// Binary Beasts
// 4/3/2023

// I mainly used this to test my CipherAdvanced because I already had my Cipher and Queue class working.

#include "CipherAdvanced.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    CipherAdvanced cipherAdvanced;
    

    vector<string> inputs = {
        "yqujuz", "wdvladgu", "iorupav", "tgdywmtv", 
        "nxtiku-ojqwwk", "dsk", "vtosonj", "dc", "xhakfzv",
        "cqqho", "yenjakz", "bianhtb", "mjuiau", "mvcp", "vkxkyejx", "cynizdyn?"
    };

    for (const auto& input : inputs) {
        cout << "Decoding input: " << input << endl;

        vector<string> possibleWords = cipherAdvanced.unknownScramble(input);

        // Check if there are any possibilities
        if (possibleWords.empty()) {
            cout << "NO POSSIBILITIES EXIST" << endl;
        } else {
            cout << "POSSIBLE WORDS:" << endl;
            for (const auto& possibleWord : possibleWords) {
                cout << possibleWord << endl;
            }
        }
    }

    return 0;
}
