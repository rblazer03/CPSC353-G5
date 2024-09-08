#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <algorithm> // for using transform 
#include <cctype> // for using toupper
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

bool is_valid_key(char key) {
    return (isupper(key) || key == ' ');
}


int main(int argc, char *argv[]) {
    string mode, input, multiKey;
    char key1;
    int key;
    int cipher;

    cout << "What Cipher do you want to do?" << endl;
    cout << "1. Caesar Cipher" << endl;
    cout << "2. Vigenère_Cipher" << endl;
    cout << "3. One Time Pad" << endl;
    cin >> cipher;

    if (cipher == 1) {
        cout << "Do you want to encrypt or decrypt?" << endl;
        cin >> mode;
        if (mode == "encrypt") {
            cout << "What is your key?" << endl;
            cin >> key1;
            if (!is_valid_key(key1)) {
                cout << "Invalid key. The key must be an uppercase letter (A-Z) or a space." << endl;
                return 1;
            }
            key = char_to_index(key1);
            cout << "What is your message?" << endl;
            cin >> input;
            input = to_uppercase(input);
            if (!is_valid_message(input)) {
                cout << "Invalid message. Only uppercase letters (A-Z) and spaces are allowed." << endl;
                return 1;
            }
            string ciphertext = caesar_encrypt(input, key);
            cout << "Key: " << key1 << "\nCiphertext: " << ciphertext << "\n";
        }else if (mode == "decrypt") {
            cout << "What is your key" << endl;
            cin >> key1;
            if (!is_valid_key(key1)) {
                cout << "Invalid key. The key must be an uppercase letter (A-Z) or a space." << endl;
                return 1;
            }
            key = char_to_index(key1);
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
    
    if (cipher == 2) {
        cout << "Do you want to encrypt or decrypt?" << endl;
        cin >> mode;
        if (mode == "encrypt") {
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
                return 1;
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

string checkMessage(){
    fstream fin;
    string message;
    // controls continuation of error checking for loop
    // check is set to false initially to enter the for loop
    bool check = false;
    while (check == false)
    {
        // check is changed to true so the while loop can exit if all characters in the message are valid
        check = true;
        // user prompted for the message they wish to encrypt/decrypt
        printf("Enter a message: ");
        // input gotten from terminal
        getline(cin, message);
        // make all character in the message uppercase
        transform(message.begin(), message.end(), message.begin(), ::toupper);

        // chech each character to ensure it is a letter or a space
        for (int i = 0; i < message.length(); i++)
        {
            // if the character is not a letter or space
            if (!isalpha(message[i]) && !isspace(message[i]))
            {
                // check is changed to false continuing the while loop and re-prompting the user
                check = false;
                // error message is given
                printf("You can only use alphabetical letters and spaces.\n");
                // break from for loop
                break;
            }
        }
    }
    // the user entered message is written into file 'Message.txt'
    ofstream Message("Message.txt");
    Message << message;
    Message.close();
}