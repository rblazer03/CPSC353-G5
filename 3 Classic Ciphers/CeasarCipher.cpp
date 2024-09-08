#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

// Convert a string to uppercase and handle spaces

std::string to_uppercase(const std::string &text) {
    std::string result;
    for (char c : text) {
        if (c == ' ') {
            result += ' ';  // Preserve spaces
        } else {
            result += std::toupper(c);
        }
    }
    return result;
}

// Map a single-character string to its corresponding index
int string_to_index(const std::string &s) {
    if (s == " ") return 26; // Map space to 26
    return s[0] - 'A';
}

// Convert an index back to a string (character)
std::string index_to_string(int index) {
    if (index == 26) return " "; // Map 26 back to space
    return std::string(1, 'A' + index);
}

// Function to encrypt text using the Caesar Cipher
std::string caesar_encrypt(const std::string &plaintext, int shift) {
    std::string ciphertext;
    for (size_t i = 0; i < plaintext.length(); i++) {
        std::string current_char(1, plaintext[i]);  // Convert character to string
        int index = string_to_index(current_char);
        int shifted_index = (index + shift) % 27;
        ciphertext += index_to_string(shifted_index);
    }
    return ciphertext;
}

// Function to decrypt text using the Caesar Cipher, same logic as encrypt but reversed
std::string caesar_decrypt(const std::string &ciphertext, int shift) {
    std::string plaintext;
    for (size_t i = 0; i < ciphertext.length(); i++) {
        std::string current_char(1, ciphertext[i]); // Convert character to string
        int index = string_to_index(current_char);
        int shifted_index = (index - shift + 27) % 27;
        plaintext += index_to_string(shifted_index);
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