#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <algorithm>

using namespace std;
// Convert a string to uppercase and handle spaces

// Function to encrypt text using the Caesar Cipher
string caesar_encrypt(string plaintext, string shift) {
    string ciphertext;
    char key_shift = shift[0];
    //goes through entire message
    for (int i = 0; i < plaintext.length(); i++) {
        char plain_letter = plaintext[i];
        char shifted_index;
        if(plain_letter == ' ')  {
            shifted_index = ((26 + (key_shift - 'A')) % 27) + 'A';
        } else {
            shifted_index = ((plain_letter - 'A') + (key_shift - 'A')) % 27 + 'A';
        }

        // special case
        if(shifted_index == '[') {
            shifted_index = ' ';
        }
        ciphertext += shifted_index;
    }
    return ciphertext;
}

// Function to decrypt text using the Caesar Cipher, same logic as encrypt but reversed
string caesar_decrypt(string ciphertext, string shift) {
    string plaintext;
    char key_shift = shift[0];

    // goes through entire cipher text
    for (int i = 0; i < ciphertext.length(); i++) {
        char cipher_letter = ciphertext[i];
        char shifted_index;
        if(cipher_letter == ' ')  {
            shifted_index = (26 - (key_shift - 'A') % 27) + 'A';
        } else {
            shifted_index = ((cipher_letter - 'A') - (key_shift - 'A') + 27) % 27 + 'A';
        }

        // special case
        if(shifted_index == '[') {
            shifted_index = ' ';
        }
        plaintext += shifted_index;
    }
    return plaintext;
}

void ceasar(string mode, string message_input) {
    // reading and writing to files
    fstream fin;
    fstream fout;
    
    // initalizer for the user inputed message and key
    string key;

    // controls continuation of error checking for loop
    // check is set to false initially to enter the for loop
    bool check2 = false;
    while (check2 == false)
    {
        // check is changed to true so the while loop can exit if all characters in the message are valid
        check2 = true;
        // user is prompted to for the key they want to use for encryting/decrypting
        printf("Enter a key: ");
        //input gotten from terminal
        getline(cin, key);
        // make all character in the key uppercase
        transform(key.begin(), key.end(), key.begin(), ::toupper);

        if(key.length()!= 1) {
            check2 = false;
            cout<< "Key must be a single letter" << endl;
        }
        
        // chech each character to ensure it is a letter or a space
        if(check2 == true) {
            for (int i = 0; i < key.length(); i++)
            {
                // if the character is not a letter or space
                if (!isalpha(key[i]))
                {
                    // check2 is changed to false continuing the while loop and re-prompting the user
                    check2 = false;
                    // error message is given
                    printf("You can only use alphabetical letters.\n");
                    // break from for loop
                    break;
                }
            }
        }
    }
    // the user entered key is written into file 'Key.txt'
    ofstream Key("Key.txt");
    Key << key;
    Key.close();

    // encrypt of decrypt the message based on user choice
    // output messages and keys to files
    if (mode == "ENCRYPT") {
        cout << "-----Ceasar Cipher-----" << endl;
        cout << "Original Message: " + message_input << endl;
        cout << "Key: " + key << endl;
        string cypherText = caesar_encrypt(message_input, key);
        cout << "Encrypted Message: " + cypherText << endl;
        ofstream Encrypt("Encrypt.txt");
        Encrypt << cypherText;
        Encrypt.close();
    }
    else if (mode == "DECRYPT") {
        cout << "-----Ceasar Cipher-----" << endl;
        cout << "Original Message: " + message_input << endl;
        cout << "Key: " + key << endl;
        string plainText = caesar_decrypt(message_input, key);
        cout << "Decrypted Message: " + plainText << endl;
        ofstream Decrypt("Decrypt.txt");
        Decrypt << plainText;
        Decrypt.close();
    }
}