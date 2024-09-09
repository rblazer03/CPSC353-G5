#include <iostream>
#include <string>
#include "CeasarCipher.cpp"
#include "Vigenère_Cipher.cpp"
#include "one_time_pad.cpp"
using namespace std;

// Checking for letters and handling them correctly if they are lowercase is handled all in main through reprompts
// This checks to make sure the actual cipher functions are working properly.

// Testing for valid  Ceasar Encryption
void test_ceasar_encryption() {
    string valid_encryption = "Encryption Passed";
    cout<< "Encryption Test: ";

    if(caesar_encrypt("JOHNSON IS PEDANTIC", 'J') != "CHAGLHGTBLTIYXUGMBW") {
        valid_encryption = "Encryption Failed";
    }
    
    cout<< valid_encryption <<endl;
}

// Testing for valid Ceasaar Decryption
void test_ceasar_decryption() {
    string valid_decryption = "Decryption Passed";
    cout<< "Decryption Test: ";

    if(caesar_decrypt("CHAGLHGTBLTIYXUGMBW", 'J') != "JOHNSON IS PEDANTIC") {
        cout << caesar_decrypt("CHAGLHGTBLTIYXUGMBW", 'J') << endl;
        valid_decryption = "Decryption Failed";
    }
    
    cout<< valid_decryption <<endl;
}


// Testing for valid Vigenere Encryption
void test_vigenere_encryption() {
    string valid_encryption = "Encryption Passed";
    cout<< "Encryption Test: ";

    if(vig_encryption("JOHNSON IS PEDANTIC", "JORDAN") != "SBYQSAWNZV BNRRQTVL") {
        valid_encryption = "Encryption Failed";
    }
    
    cout<< valid_encryption <<endl;
}

// Testing for valid Vigenere Decryption
void test_vigenere_decryption() {
    string valid_decryption = "Decryption Passed";
    cout<< "Decryption Test: ";

    if(vig_decryption("SBYQSAWNZV BNRRQTVL", "JORDAN") != "JOHNSON IS PEDANTIC") {
        valid_decryption = "Decryption Failed";
    }
    
    cout<< valid_decryption <<endl;
}

// Testing for valid otp Encryption
void test_otp_encrypt() {   
    string valid = "Encryption Passed";
    cout<< "Encryption Test: ";

    string encrypted = Encrypt("HELLO WORLD", "TESTENCRYPT");
    if (encrypted != " ICDSMYEO W") {
        valid = "Encryption Failed";
    }
    
    cout << valid << endl;
}

// Testing for valid otp Decryption
void test_otp_decrypt() {   
    string valid = "Decryption Passed";
    cout << "Decryption Test: ";

    string decrypted = Decrypt("HELLO WORLD", " ICDRDYEO W");
    if ( decrypted != "TestDecrypt") {
        valid = "Decryptiong Failed";
    }

    cout << valid << endl;
}



int main(void) {
    cout<< "Unit Testing For Ceasar Cipher:" << endl;
    test_ceasar_encryption();
    test_ceasar_decryption();

    cout<< "Unit Testing For Vignere Cipher:" << endl;
    test_vigenere_encryption();
    test_vigenere_decryption();

    cout<< "Unit Testing For OTP Cipher:" << endl;
    test_otp_encrypt();
    test_otp_decrypt();
    return 0;
}