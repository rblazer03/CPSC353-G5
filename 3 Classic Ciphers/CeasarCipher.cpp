#include <iostream>
#include <string>
#include <cctype>

// Convert a string to uppercase and handle spaces
std::string to_uppercase(const std::string &text) {
    std::string result;
    for (char c : text) {
        result += std::toupper(c);
    }
    return result;
}

// Map characters to their position
int char_to_index(char c) {
    if (c == ' ') return 26; // I'd give this return statement its own line
    return c - 'A';
}

// Function to map positions back to characters
char index_to_char(int index) {
    if (index == 26) return ' '; // I'd give this return statement its own line
    return 'A' + index;     
}

// Function to encrypt text using the Caesar Cipher
std::string caesar_encrypt(const std::string &plaintext, int shift) {
    std::string ciphertext;
    for (char c : plaintext) {
        // Convert character to index
        int index = char_to_index(c);             
        // Shift index and wrap around using modulo 27     
        int shifted_index = (index + shift) % 27;      
        // Convert back to character
        ciphertext += index_to_char(shifted_index);     
    }
    return ciphertext;
}

// Function to decrypt text using the Caesar Cipher, same logic as encrypt but reversed
std::string caesar_decrypt(const std::string &ciphertext, int shift) {
    std::string plaintext;
    for (char c : ciphertext) {
        int index = char_to_index(c);  
        int shifted_index = (index - shift + 27) % 27; 
        plaintext += index_to_char(shifted_index);      
    }
    return plaintext;
}

/*

int main(int argc, char *argv[]) {
    std::string mode, input;
    int shift;

    // Check command-line arguments
    if (argc < 4) {
        std::cout << "Usage: " << argv[0] << " <mode> <text> <shift>\n";
        std::cout << "Mode: encrypt or decrypt\n";
        return 1;
    }

    // Read mode, input text, and shift value
    mode = argv[1];
    input = to_uppercase(argv[2]);
    shift = std::stoi(argv[3]);

    // Ensure shift is within valid range
    if (shift < 0 || shift > 26) {
        std::cout << "Shift must be between 0 and 26 (A-Z + _)" << std::endl;
    }

    // Execute based on selected mode
    if (mode == "encrypt") {
        std::string ciphertext = caesar_encrypt(input, shift);
        std::cout << "Key: " << shift << "\nCiphertext: " << ciphertext << "\n";
    } else if (mode == "decrypt") {
        std::string plaintext = caesar_decrypt(input, shift);
        std::cout << "Key: " << shift << "\nPlaintext: " << plaintext << "\n";
    } else {
        std::cout << "Invalid mode, use encrypt or decrypt" << std::endl;
    }

    return 0;
}
*/