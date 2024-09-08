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

    if (Encrypt("Hello World", "TestEncrypt") == " ICDSMYEO W")
    {
        cout << valid << endl;
    }
    else
    {
        cout << invalid << endl;
    }
}

void test_otp_decrypt()
{   

    if (Decrypt("Hello World", " ICDRDYEO W") == "TestDecrypt")
    {
        cout << valid << endl;
    }
    else
    {
        cout << invalid << endl;
    }
}