#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // for using transform 
#include <cctype> // for using toupper 
using namespace std;

int main(void)
{
    fstream fin;
    fstream fout;
    
    string message;
    string key;
    bool check = false;

    while (check == false)
    {
        check = true;
        printf("Enter a message: ");
        getline(cin, message);
        transform(message.begin(), message.end(), message.begin(), ::toupper);
        for (int i = 0; i < message.length(); i++)
        {
            if (!isalpha(message[i]) && !isspace(message[i]))
            {
                check = false;
            }
        }
    }
    ofstream Message("Message.txt");
    Message << message;
    Message.close();

    
    while (key.length() != message.length())
    {
        printf("Enter a key: ");
        getline(cin, key);
        transform(key.begin(), key.end(), key.begin(), ::toupper);
        printf("Key must be equal to message length.\n");
    }
    ofstream Key("Key.txt");
    Key << key;
    Key.close();

    printf("Original Message: %s\n", message.c_str());
    printf("Key: %s\n", key.c_str());
    
    
    ofstream Encrypt("Encrypt.txt");
    for (int i = 0; i < message.length(); i++)
    {
        // if char
        if(isspace(message[i]))
        {
            message[i] += 59;
        }
        if(isspace(key[i]))
        {
            key[i] += 59;
        }
        char newChar = (((message[i] - 'A') + (key[i] - 'A')) % 27) + 'A';
        if (newChar == '['){
            newChar -= 59;
        }
        printf("NewChar: %c\n", newChar);
        Encrypt << newChar ;
    }
    Encrypt.close();


    return 0;
}