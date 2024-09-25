#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // for using transform 
#include <cctype> // for using toupper
using namespace std;

// function initializers
string Encrypt(string message, string key);
string Decrypt(string message, string key);

int otp(string mode, string message_input) {
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
        cout << "Enter a key: "<< endl;
        //input gotten from terminal
        getline(cin, key);
        // make all character in the key uppercase
        transform(key.begin(), key.end(), key.begin(), ::toupper);

        if(key.length() != message_input.length()) {
            check2 = false;
            cout << "Key must be equal in length to message" << endl;
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
                    cout << "You can only use alphabetical letters and spaces."<< endl;
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
        cout << "-----OTP Cipher-----" << endl;
        cout << "Original Message: " + message_input << endl;
        cout << "Key: " + key << endl;
        string cypherText = Encrypt(message_input, key);
        cout << "Encrypted Message: " + cypherText << endl;
        ofstream Encrypt("Encrypt.txt");
        Encrypt << cypherText;
        Encrypt.close();
    }
    else if (mode == "DECRYPT") {
        cout << "-----OTP Cipher-----" << endl;
        cout << "Original Message: " + message_input << endl;
        cout << "Key: " + key << endl;
        string plainText = Decrypt(message_input, key);
        cout << "Encrypted Message: " + plainText << endl;
        ofstream Decrypt("Decrypt.txt");
        Decrypt << plainText;
        Decrypt.close();
    }

    return 0;
}

string Encrypt(string message, string key)
{
    string encrypt;
    // open file 'Encrypt.txt'
    ofstream Encrypt("Encrypt.txt");
    // encrypt each letter of the message individually
    for (int i = 0; i < message.length(); i++)
    {
        // if the character is a space, 59 (ascii value) is added to make the space sit after 'Z' for encryption
        if(isspace(message[i]))
        {
            message[i] += 59;
        }
        if(isspace(key[i]))
        {
            key[i] += 59;
        }
        // 'A' is subtracted from the message and charcater key reducing each letter to a number sitting between 0 and 26
        // key[i] is added to message[i] and modded by 27 to create the new number
        // 'A' is added to change the ascii value once again to creat the encrypted character
        char newChar = (((message[i] - 'A') + (key[i] - 'A')) % 27) + 'A';
        // '[' is the character after 'Z', subtracting 29 makes it a space
        if (newChar == '['){
            newChar -= 59;
        }
        // encrypted character is added to the file 'Encrypt.txt'
        encrypt += newChar;
    }
    
    // return encrypted method
    return encrypt;
}

string Decrypt(string message, string key)
{
    string decrypt;
    for (int i = 0; i < message.length(); i++)
    {
        // if the character is a space, 59 (ascii value) is added to make the space sit after 'Z' for decryption
        if(isspace(message[i]))
        {
            message[i] += 59;
        }
        if(isspace(key[i]))
        {
            key[i] += 59;
        }
        // 'A' is subtracted from the message and charcater key reducing each letter to a number sitting between 0 and 26
        // key[i] is subtracted from message[i] and then 27 is added to the total. This prevents negative numbers
        // The result is then modded by 27 to create the new number
        // 'A' is added to change the ascii value once again to create the decrypted character
        char newChar = ((((message[i] - 'A') - (key[i] - 'A')) +27)% 27) + 'A';
        // '[' is the character after 'Z', subtracting 29 makes it a space
        if (newChar == '['){
            newChar -= 59;
        }
        // decrypted character is added to the file 'Encrypt.txt'
        decrypt +=  newChar;
    }
    // return decrypted message
    return decrypt;
}