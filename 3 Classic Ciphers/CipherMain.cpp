#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "CeasarCipher.cpp"
#include "Vigenère_Cipher.cpp"

using namespace std;

bool is_valid_message(const string &text) {
    for (char c : text) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
        if (isalpha(c) && !isupper(c)) {
            return false;
        }
    }
    return true;
}



int main(int argc, char *argv[]) {
    string mode, input, multiKey;
    string key1;
    int key;
    string cipher;

    cout << "What Cipher do you want to do?" << endl;
    cout << "1. Caesar Cipher" << endl;
    cout << "2. Vigenère_Cipher" << endl;
    cout << "3. One Time Pad" << endl;
    getline(cin, cipher);
    //cin >> cipher;
    //getline(cin, cipher);

    if (cipher == "1") {
        cout << "Do you want to encrypt or decrypt?" << endl;
        //cin >>mode;
        getline(cin, mode);
        if (mode == "encrypt") {
            cout << "What is your key?" << endl;
            //cin >> key1;
            getline(cin, key1);
            if (!is_valid_message(key1)) {
                cout << "Invalid key. The key must be an uppercase letter (A-Z) or a space." << endl;
                return 1;
            }
            key = string_to_index(key1);
            cout << "What is your message?" << endl;
            //cin >> input;
            getline(cin, input);
            input = to_uppercase(input);
            if (!is_valid_message(input)) {
                cout << "Invalid message. Only letters (A-Z) and spaces are allowed." << endl;
                return 1;
            }
            string ciphertext = caesar_encrypt(input, key);
            cout << "Key: " << key1 << "\nCiphertext: " << ciphertext << "\n";
        }else if (mode == "decrypt") {
            cout << "What is your key" << endl;
            cin >> key1;
            if (!is_valid_message(key1)) {
                cout << "Invalid key. The key must be an uppercase letter (A-Z) or a space." << endl;
                return 1;
            }
            key = string_to_index(key1);
            cout << "what is your message" << endl;
            cin >> input;
            if (!is_valid_message(input)) {
                cout << "Invalid message. Only uppercase letters (A-Z) and spaces are allowed." << endl;
                return 1;
            }
            string plaintext = caesar_decrypt(input, key);
            cout << "Key: " << key1 << "\nPlaintext: " << plaintext << "\n";
        }else {
            cout << "Invalid mode, use encrypt or decrypt" << std::endl;
        }
    }
    
    if (cipher == "2") {
        cout << "Do you want to encrypt or decrypt?" << endl;
        getline(cin, mode);
        if (mode == "encrypt") {
            cout << "What is your key?" << endl;
            getline(cin, multiKey);
            multiKey = to_uppercase(multiKey);
            if (!is_valid_message(input)) {
                cout << "Invalid key. Only uppercase letters (A-Z) and spaces are allowed." << endl;
                return 1;
            }
            cout << "What is your message?" << endl;
            //cin >> input;
            getline(cin, input);
            input = to_uppercase(input);
            if (!is_valid_message(input)) {
                cout << "Invalid message. Only uppercase letters (A-Z) and spaces are allowed." << endl;
                return 1;
            }
            string ciphertext = vig_encryption(input, multiKey);
            cout << "Key: " << multiKey << "\nCiphertext: " << ciphertext << "\n";
        }
        else if (mode == "decrypt") {
            cout << "What is your key?" << endl;
            cin >> multiKey;
            multiKey = to_uppercase(multiKey);
            if (!is_valid_message(input)) {
                cout << "Invalid key. Only uppercase letters (A-Z) and spaces are allowed." << endl;
                return 1;
            }
            cout << "What is your message?" << endl;
            cin >> input;
            input = to_uppercase(input);
            if (!is_valid_message(input)) {
                cout << "Invalid message. Only uppercase letters (A-Z) and spaces are allowed." << endl;
            }
            string plaintext = vig_decryption(input, multiKey);
            cout << "Key: " << multiKey << "\nPlaintext: " << plaintext << "\n";           
        }
        else {
            cout << "Invalid mode, use encrypt or decrypt" << std::endl;
        }
    }
    /*
    if (cipher == 3) {
        cout << "Do you want to encrypt or decrypt?" << endl;
        cin >> mode;
        if (mode == "encrypt") {
            cout << "What is your key?" << endl;
            cin >> multiKey;
            multiKey = to_uppercase(multiKey);
            cout << "What is your message?" << endl;
            cin >> input;
            input = to_uppercase(input);
            //string ciphertext = vig_encryption(input, multiKey);
            cout << "Key: " << multiKey << "\nCiphertext: " << ciphertext << "\n";
        }
        else if (mode == "decrypt") {
            cout << "What is your key?" << endl;
            cin >> multiKey;
            multiKey = to_uppercase(multiKey);
            if (!is_valid_message(input)) {
                cout << "Invalid key. Only uppercase letters (A-Z) and spaces are allowed." << endl;
                return 1;
            }
            cout << "What is your message?" << endl;
            cin >> input;
            input = to_uppercase(input);
            if (!is_valid_message(input)) {
                cout << "Invalid message. Only uppercase letters (A-Z) and spaces are allowed." << endl;
                return 1;
            }
            //string plaintext = vig_decryption(input, multiKey);
            cout << "Key: " << multiKey << "\nPlaintext: " << plaintext << "\n";          
        }
        else {
            cout << "Invalid mode, use encrypt or decrypt" << std::endl;
        }

    }
    */
    
    return 0;
}