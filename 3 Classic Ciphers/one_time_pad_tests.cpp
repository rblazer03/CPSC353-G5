#include <iostream>
#include <string>
#include "one_time_pad.cpp"
using namespace std;

void test_otp_encrypt(void);
void test_otp_decrypt(void);

string valid = "PASS";
string invalid = "FAIL";

int test_main(void)
{
    test_otp_encrypt();
    test_otp_decrypt();

    return 0;
}

void test_otp_encrypt()
{   
    string encrypted = Encrypt("Hello World", "TestEncrypt");
    if (encrypted == " ICDSMYEO W")
    {
        cout << "One Time Pad Encrypt: " << valid << endl;
    }
    else
    {
        cout << "One Time Pad Encrypt: " << invalid << endl;
    }

    return;
}

void test_otp_decrypt()
{   
    string decrypted = Decrypt("Hello World", " ICDRDYEO W");
    if ( decrypted == "TestDecrypt")
    {
        cout << "One Time Pad Decrypt: " << valid << endl;
    }
    else
    {
        cout << "One Time Pad Decrypt: " << invalid << endl;
    }

    return;
}