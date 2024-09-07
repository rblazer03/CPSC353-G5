#include <iostream>
#include <string>
#include <cctype>
#include "CeasarCipher.cpp"

using namespace std;


int main(int argc, char *argv[]) {
    string mode, input;
    char key1;
    int key;
    int cipher;

    cout << "What Cipher do you want to do?" << endl;
    cout << "1. Caesar Cipher" << endl;
    cout << "2. Vegnere Cipher" << endl;
    cout << "3. One Time Pad" << endl;
    cin >> cipher;

    //mode = argv[1];
    //input = to_uppercase(argv[2]);
    //key = stoi(argv[3]);
    if (cipher == 1) {
        cout << "Do you want to encrypt or decrypt?" << endl;
        cin >> mode;
        if (mode == "encrypt") {
            cout << "What is your key?" << endl;
            cin >> key1;
            key = char_to_index(key1);
            cout << "What is your message?" << endl;
            cin >> input;
           // getline(input);
            //to_uppercase(input);
            string ciphertext = caesar_encrypt(input, key);
            cout << "Key: " << key1 << "\nCiphertext: " << ciphertext << "\n";
        }else if (mode == "decrypt") {
            cout << "What is your key" << endl;
            cin >> key1;
            key = char_to_index(key1);
            cout << "what is your message" << endl;
            cin >> input;
            string plaintext = caesar_decrypt(input, key);
            cout << "Key: " << key1 << "\nPlaintext: " << plaintext << "\n";
        }else {
            cout << "Invalid mode, use encrypt or decrypt" << std::endl;
        }
    }
    /*
    if (cipher == 2) {

    }
    if (cipher == 3) {

    }
    */
    return 0;
}