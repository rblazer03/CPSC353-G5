#include <iostream>
#include <string>
#include <one_time_pad.cpp>
using namespace std;

string valid = "PASS";
string invalid = "FAIL";

void test_otp_encrypt()
{   

    if (Encrypt("Hello World", "TestEncrypt") == " ICDSMYEO W")
    {
        cout << valid;
    }
    else{
        cout << invalid;
    }
}

void test_otp_decrypt()
{   

    if (Decrypt("Hello World", "TestDecrypt") == " ICDSMYEO W")
    {
        cout << valid;
    }
    else{
        cout << invalid;
    }
}