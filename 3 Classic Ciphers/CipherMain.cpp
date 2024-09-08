#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <algorithm>
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
    bool cond = true;
    while(cond == true) {
        cout << "What Cipher do you want to do?" << endl;
        cout << "1. Caesar Cipher" << endl;
        cout << "2. Vigenère_Cipher" << endl;
        cout << "3. One Time Pad" << endl;
        cout << "4. Exit program" << endl;
        getline(cin, cipher);


        if(cipher == "1") {
            while(mode != "ENCRYPT" || mode != "DECRYPT") {
                cout << "Choose a mode: Encrypt or Decrypt" << endl;
                getline(cin, mode);
                transform(mode.begin(), mode.end(), mode.begin(), ::toupper);
                if(mode == "ENCRYPT" || mode == "DECRYPT") {
                    cout << "What is your key?" << endl;
                    getline(cin, key1);
                    if (!is_valid_message(key1)) {
                        cout << "Invalid key. The key must be an uppercase letter (A-Z) or a space." << endl;
                    }
                    key = string_to_index(key1);
                    cout << "What is your message?" << endl;
                    getline(cin, input);
                    input = to_uppercase(input);
                    if (!is_valid_message(input)) {
                        cout << "Invalid message. Only letters (A-Z) and spaces are allowed." << endl;
                    }
                    if(mode == "ENCRYPT"){
                        string ciphertext = caesar_encrypt(input, key);
                        cout << "Key: " << key1 << "\nCiphertext: " << ciphertext << "\n";
                    }
                    else if(mode == "DECRYPT"){
                        string plaintext = caesar_decrypt(input, key);
                        cout << "Key: " << key1 << "\nPlaintext: " << plaintext << "\n";
                    }
                }
                else{
                cout << "Invalid mode, use ENCRYPT or DECRYPT" << std::endl;
                }
            }
        }
        if (cipher == "2") {
            while(mode != "ENCRYPT" || mode != "DECRYPT") {
                cout << "Choose a mode: Encrypt or Decrypt" << endl;
                getline(cin, mode);
                transform(mode.begin(), mode.end(), mode.begin(), ::toupper);
                if(mode == "ENCRYPT" || mode == "DECRYPT") {
                    cout << "What is your key?" << endl;
                    getline(cin, key1);
                    if (!is_valid_message(key1)) {
                        cout << "Invalid key. The key must be an uppercase letter (A-Z) or a space." << endl;
                    }
                    key = string_to_index(key1);
                    cout << "What is your message?" << endl;
                    getline(cin, input);
                    input = to_uppercase(input);
                    if (!is_valid_message(input)) {
                        cout << "Invalid message. Only letters (A-Z) and spaces are allowed." << endl;
                    }
                    if(mode == "ENCRYPT"){
                        string ciphertext = vig_encryption(input, multiKey);
                        cout << "Key: " << multiKey << "\nCiphertext: " << ciphertext << "\n";
                    }
                    else if(mode == "DECRYPT"){
                        string plaintext = vig_decryption(input, multiKey);
                        cout << "Key: " << multiKey << "\nPlaintext: " << plaintext << "\n"; 
                    }
                }
                else{
                    cout << "Invalid mode, use ENCRYPT or DECRYPT" << std::endl;
                }
            }

        }

        /*
        if (cipher == 3) {
        
            while (mode != "ENCRYPT" || mode != "DECRYPT" || mode != "TEST") {
                cout << "Choose a mode: Encrypt, Decrypt, or Test?" << endl;
                getline(cin, mode);
                transform(mode.begin(), mode.end(), mode.begin(), ::toupper);
                if(mode == "ENCRYPT" || mode == "DECRYPT" || mode == "TEST")
                    input = checkMessage();
                    otp_main(mode, input);
                else
                {
                    cout << "Invalid mode: Enter Encrypt, Decrypt, or Test" << std::endl;
                }
            }

        }
        */
        if(cipher == "4") {
            cout << "Goodbye!" << endl;
            cond = false;
        }

        else {
            cout << "Invalid input, enter the number for what cipher you want to do" << endl;
        }
    }
    /*
    if (cipher == "1") {
        while(mode != "ENCRYPT" || mode != "DECRYPT") {
            cout << "Choose a mode: Encrypt or Decrypt" << endl;
            getline(cin, mode);
            transform(mode.begin(), mode.end(), mode.begin(), ::toupper);
            if(mode == "ENCRYPT" || mode == "DECRYPT") {
                cout << "What is your key?" << endl;
                getline(cin, key1);
                if (!is_valid_message(key1)) {
                    cout << "Invalid key. The key must be an uppercase letter (A-Z) or a space." << endl;
                }
                key = string_to_index(key1);
                cout << "What is your message?" << endl;
                getline(cin, input);
                input = to_uppercase(input);
                if (!is_valid_message(input)) {
                    cout << "Invalid message. Only letters (A-Z) and spaces are allowed." << endl;
                }
                if(mode == "ENCRYPT"){
                    string ciphertext = caesar_encrypt(input, key);
                    cout << "Key: " << key1 << "\nCiphertext: " << ciphertext << "\n";
                }
                else if(mode == "DECRYPT"){
                    string plaintext = caesar_decrypt(input, key);
                    cout << "Key: " << key1 << "\nPlaintext: " << plaintext << "\n";
                }
            }
            else{
                cout << "Invalid mode, use ENCRYPT or DECRYPT" << std::endl;
            }
        }
        
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
    */
    /*
    if (cipher == 3) {
    
        while (mode != "ENCRYPT" || mode != "DECRYPT" || mode != "TEST") {
            cout << "Choose a mode: Encrypt, Decrypt, or Test?" << endl;
            getline(cin, mode);
            transform(mode.begin(), mode.end(), mode.begin(), ::toupper);
            if(mode == "ENCRYPT" || mode == "DECRYPT" || mode == "TEST")
                input = checkMessage();
                otp_main(mode, input);
            else
            {
                cout << "Invalid mode: Enter Encrypt, Decrypt, or Test" << std::endl;
            }
        }

    }
    */
    return 0;
}