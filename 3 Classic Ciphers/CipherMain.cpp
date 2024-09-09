#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <algorithm> // for using transform 
#include <cctype> // for using toupper
#include "CeasarCipher.cpp"
#include "Vigenère_Cipher.cpp"
#include "one_time_pad.cpp"

using namespace std;

// makes sure the message is legal input
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

    return message;
}


int main(int argc, char *argv[]) {
    string cipher, mode, input, multiKey;
    string key1;
    int key;
    bool cipher_cond = true;
    // gets number for respective program
    while(cipher_cond == true) {
        cipher_cond = false;
        cout << "What Cipher do you want to do?" << endl;
        cout << "1. Caesar Cipher" << endl;
        cout << "2. Vigenere_Cipher" << endl;
        cout << "3. One Time Pad" << endl;
        cout << "4. Exit program" << endl;
        getline(cin, cipher);

        if(cipher != "1" && cipher!= "2" && cipher!= "3" && cipher!= "4") {
            cipher_cond = true;
            cout << "Invalid input. Please enter a number 1-4." <<endl;
        }
    }

    // exits program
    if(cipher == "4") {
        cout << "Goodbye!" << endl;
        return 0;
    }

    // gets input for either decryption or encryption
    bool mode_cond = true;
    while(mode_cond == true) {
        mode_cond = false;
        cout << "Choose a mode: ENCRYPT or DECRYPT" << endl;
        getline(cin, mode);
        transform(mode.begin(), mode.end(), mode.begin(), ::toupper);
        if(mode != "ENCRYPT" && mode != "DECRYPT") {
            cout << "Please type either ENCRYPT or DECRYPT" <<endl;
            cout<< mode << endl;
            mode_cond = true;
        }
    }
    
    // gets message for encrypting or decrypting
    cout << "What is your message?" << endl;
    input = checkMessage();
        
    // runs correct cipher
    if(cipher == "1") {
        ceasar(mode, input);
    }

    if (cipher == "2") {
        vigenere(mode, input);
    }

    if (cipher == "3") {
        otp(mode, input);      
    }
    
    return 0;
}