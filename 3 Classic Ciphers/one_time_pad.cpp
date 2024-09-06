#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // for using transform 
#include <cctype> // for using toupper 
using namespace std;

int main(void)
{
    // reading and writing to files
    fstream fin;
    fstream fout;
    
    // initalizer for the user inputed message and key
    string message;
    string key;

    // controls continuation of error checking for loop
    bool check = false;

    // check is set to false initially to enter the for loop
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

    // // user is prompted to for the key they want to use for encryting/decrypting
    // printf("Enter a key: ");
    //     //input gotten from terminal
    //     getline(cin, key);
    //     // make all character in the message uppercase
    //     transform(key.begin(), key.end(), key.begin(), ::toupper);
    // while (key.length() != message.length())
    // {
        
    //     printf("Key must be equal to message length.\n");
    //     printf("Enter a key: ");
    //     getline(cin, key);
    //     transform(key.begin(), key.end(), key.begin(), ::toupper);
    // }
    // controls continuation of error checking for loop
    bool check2 = false;

    // check is set to false initially to enter the for loop
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

        // while loop to re-prompt user if key is not the same length as the message
        while (key.length() != message.length())
        {
            // error message given
            printf("Key must be equal to message length.\n");
            // user re-prompted
            printf("Enter a key: ");
            getline(cin, key);
            transform(key.begin(), key.end(), key.begin(), ::toupper);
        }
        
        // chech each character to ensure it is a letter or a space
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
    // the user entered key is written into file 'Key.txt'
    ofstream Key("Key.txt");
    Key << key;
    Key.close();

    // users original message and chosen key is printed in the terminal
    printf("Original Message: %s\n", message.c_str());
    printf("Key: %s\n", key.c_str());
    
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
        Encrypt << newChar;
    }
    Encrypt.close();

    // initilaizer for encrypted text
    string encrypted;
    // 'Encrypt.txt' is opened
    ifstream Encrypted("Encrypt.txt");
    // the first line of the file is read and the saved to string encrypted
    getline(Encrypted, encrypted);
    // the encrypted message is printed to the terminal
    printf("Encrypted Message: %s\n", encrypted.c_str());
    Encrypted.close();

    ofstream Decrypt("Decrypt.txt");
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
        Decrypt << newChar;
    }
    Decrypt.close();

    // initilaizer for decrypted text
    string decrypted;
    // 'Decrypt.txt' is opened
    ifstream Decrypted("Decrypt.txt");
    // the first line of the file is read and the saved to string decrypted
    getline(Decrypted, decrypted);
    // the decrypted message is printed to the terminal
    printf("Decrypted Message: %s\n", decrypted.c_str());
    Decrypted.close();

    return 0;
}