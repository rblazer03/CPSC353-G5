// Jordan Wakefield
// CPSC 353
#include <iostream>
#include <string>

using namespace std;


// encryption useing inputting key 
string vig_encryption(string plainText, string key){
    string cypherText;
    // goes through entire message encrypting it
    for(int i=0;i<plainText.length();i++){
        char x = plainText[i];
        char y = key[(i % key.length())];
        char z;
        
        if(x==' '){
            z = ((26+(y-'A')) % 27) + 'A';
        } else {
            z = ((x-'A')+(y-'A')) % 27 + 'A';
        }

        if(z == '[') {
            z = ' ';
        }
        
        cypherText+=z;
    }
    return cypherText;
}

// decryption using inputed key
string vig_decryption(string cypherText, string key){
    string plainText;
    // goes through message and encrypts it
    for(int i=0;i<cypherText.length();i++){
        char x = cypherText[i];
        char y = key[(i % key.length())];
        char z;

        if(x==' '){
            z = ((26-(y-'A')) % 27) + 'A';
        } else {
            z = (((x-'A')-(y-'A')+27) % 27) + 'A';
        }

        if(z == '[') {
            z = ' ';
        }
        
        plainText+=z;
    }
    return plainText;
}

void vigenere(string mode, string message_input) {
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

        if(key.length() < 1 || key.length() >= message_input.length()) {
            check2 = false;
            cout<< "Key must be greater less than legnth of message" << endl;
        }
        
        // chech each character to ensure it is a letter or a space
        if(check2 == true) {
            for (int i = 0; i < key.length(); i++)
            {
                // if the character is not a letter or space
                if (!isalpha(key[i]) && !isspace(key[i]))
                {
                    // check2 is changed to false continuing the while loop and re-prompting the user
                    check2 = false;
                    // error message is given
                    printf("You can only use alphabetical letters and spaces.\n");
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
    if (mode == "ENCRYPT") {
        cout << "-----Vig Cipher-----" << endl;
        cout << "Original Message: " + message_input << endl;
        cout << "Key: " + key << endl;
        string cypherText = vig_encryption(message_input, key);
        cout << "Encrypted Message: " + cypherText << endl;
        ofstream Encrypt("Encrypt.txt");
        Encrypt << cypherText;
        Encrypt.close();
    }
    else if (mode == "DECRYPT") {
        cout << "-----Vig Cipher-----" << endl;
        cout << "Original Message: " + message_input << endl;
        cout << "Key: " + key << endl;
        string plainText = vig_decryption(message_input, key);
        cout << "Encrypted Message: " + plainText << endl;
        ofstream Decrypt("Decrypt.txt");
        Decrypt << plainText;
        Decrypt.close();
    }
}
