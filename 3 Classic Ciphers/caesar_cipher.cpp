#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <algorithm>

using namespace std;
// Convert a string to uppercase and handle spaces

// Function to encrypt text using the Caesar Cipher
string caesar_encrypt(string plain_text, string key) {
    string cypher_text;
    // goes through entire message encrypting it
    for(int i=0;i<plain_text.length();i++){
        char message_char = plain_text[i];
        char key_char = key[(i % key.length())];
        char cyphertext_char;

        //handles spaces
        if(message_char ==' '){
            message_char = '[';
        } 

        // handles spaces
        if(key_char ==' ') {
            key_char = '[';
        }
        // computes cyphertext
        cyphertext_char = ((message_char-'A')+(key_char-'A')) % 27 + 'A';

        // handles spaces
        if(cyphertext_char == '[') {
            cyphertext_char = ' ';
        }

        //appends it to string
        cypher_text+=cyphertext_char;
    }
    return cypher_text;
}

// Function to decrypt text using the Caesar Cipher, same logic as encrypt but reversed
string caesar_decrypt(string ciphertext, string key) {
    string plain_text;
    // goes through message and encrypts it
    for(int i=0;i<ciphertext.length();i++){
        char cyphertext_char = ciphertext[i];
        char key_char = key[(i % key.length())];
        char message_char;

        // handles spaces
        if(cyphertext_char ==' '){
           cyphertext_char = '[';
        }

        // handles spaces
        if(key_char==' ') {
            key_char = '[';
        }

        // computes secret message
        message_char = (((cyphertext_char-'A')-(key_char-'A')+27) % 27) + 'A';

        // handles spaces
        if(message_char == '[') {
            message_char = ' ';
        }

        // appends it to string
        plain_text+=message_char;
    }
    return plain_text;
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
                if (!isalpha(key[i]) && key[i] != ' ')
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