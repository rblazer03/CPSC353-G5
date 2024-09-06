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