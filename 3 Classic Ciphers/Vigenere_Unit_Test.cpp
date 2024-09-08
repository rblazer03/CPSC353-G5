#include <iostream>
#include <string>
#include "Vigenère_Cipher.cpp"

using namespace std;

// Checking for letters and handling them correctly if they are lowercase is handled all in main through reprompts
// This checks to make sure the actual cipher functions are working properly.


// Testing for valid Encryption
void test_vigenere_encryption() {
    string valid_encryption = "Encryption Passed";
    cout<< "Encryption Test: ";

    if(vig_encryption("JOHNSON IS PEDANTIC", "JORDAN") != "SBYQSAWNZV BNRRQTVL") {
        valid_encryption = "Encryption Failed";
    }
    
    cout<< valid_encryption <<endl;
}

// Testing for valid Decryption
void test_vigenere_decryption() {
    string valid_decryption = "Decryption Passed";
    cout<< "Decryption Test: ";

    if(vig_encryption("SBYQSAWNZV BNRRQTVL", "JORDAN") != "JOHNSON IS PEDANTIC") {
        valid_decryption = "Decryption Failed";
    }
    
    cout<< valid_decryption <<endl;
}

int main(void) {
    cout<< "Unit Testing For Vignere Cypher:" << endl;
    test_vigenere_encryption();
    test_vigenere_decryption();
    return 0;
}