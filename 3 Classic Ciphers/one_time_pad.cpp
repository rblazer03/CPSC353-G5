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

    printf("Enter a message: ");
    getline(cin, message);
    transform(message.begin(), message.end(), message.begin(), ::toupper);
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

    // printf("Message: %s\n", message.c_str());
    // printf("Key: %s\n", key.c_str());
    
    ofstream Encrypt("Encrypt.txt");
    for (int i = 0; i < message.length(); i++)
    {
        char newChar = (((message[i] - 'A') + (key[i] - 'A')) % 26) + 'A';
        printf("NewChar: %c\n", newChar);
        Encrypt << newChar ;
    }
    Encrypt.close();

    return 0;
}