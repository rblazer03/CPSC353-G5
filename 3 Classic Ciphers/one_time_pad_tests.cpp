#include <iostream>
#include <string>
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
    string encrypted = Encrypt("HELLO WORLD", "TESTENCRYPT");
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
    string decrypted = Decrypt(" ICDRDYEO W", "HELLO WORLD");
    if ( decrypted == "TESTDECRYPT")
    {
        cout << "One Time Pad Decrypt: " << valid << endl;
    }
    else
    {
        cout << "One Time Pad Decrypt: " << invalid << endl;
    }

    return;
}