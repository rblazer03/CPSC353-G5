#include <iostream>
#include <string>
#include "CeasarCipher.cpp"

using namespace std;

// Checking for letters and handling them correctly if they are lowercase is handled all in main through reprompts
// This checks to make sure the actual cipher functions are working properly.


// Testing for valid Encryption
void test_ceasar_encryption() {
    string valid_encryption = "Encryption Passed";
    cout<< "Encryption Test: ";

    if(caesar_encrypt("JOHNSON IS PEDANTIC", 'J') != "CHAGLHGTBLTIYXUGMBW") {
        cout<< caesar_encrypt("JOHNSON IS PEDANTIC", 'J')<< endl;
        valid_encryption = "Encryption Failed";
    }
    
    cout<< valid_encryption <<endl;
}

// Testing for valid Decryption
void test_ceasar_decryption() {
    string valid_decryption = "Decryption Passed";
    cout<< "Decryption Test: ";

    if(caesar_decrypt("CHAGLHGTBLTIYXUGMBW", 'J') != "JOHNSON IS PEDANTIC") {
        valid_decryption = "Decryption Failed";
    }
    
    cout<< valid_decryption <<endl;
}

int main(void) {
    cout<< "Unit Testing For Ceasar Cipher:" << endl;
    test_ceasar_encryption();
    test_ceasar_decryption();
    return 0;
}