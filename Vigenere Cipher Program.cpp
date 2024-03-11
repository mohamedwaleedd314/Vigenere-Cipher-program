// Program: Welcome to the Vigenere Cipher program
// Author:  mohamed waleed aly mohamed
//         ID :20230363
// Version: 2.0
// Date:    3/5/2024

// alphabet = a  b  c  d  e  f  g  h  i   j   k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
// number   = 0  1  2  3  4  5  6  7  8  9  10  11  12 13 14 15 16 17 18 19 20 21 22 23 24 25

#include <iostream>
#include <string>

using namespace std;

// Function to encrypt a message using the Vigenere Cipher
string encrypt(const string& message, const string& keyword) {
    string encrypted_text;
    int keyword_length = keyword.length();
    string lowercase_keyword = keyword;
    for (char& c : lowercase_keyword) {
        c = tolower(c);
    }


    for (size_t i = 0; i < message.length(); ++i) {
        char char_to_encrypt = message[i];
        if (isalpha(char_to_encrypt)) {
            char base = islower(char_to_encrypt) ? 'a' : 'A';

            int shift = lowercase_keyword[i % keyword_length] - 'a';

            char encrypted_char = (char_to_encrypt - base + shift) % 26 + base;
            encrypted_text += encrypted_char;
        } else {

            encrypted_text += char_to_encrypt;
        }
    }

    return encrypted_text;
}

// Function to decrypt a ciphertext using the Vigenere Cipher
string decrypt(const string& ciphertext, const string& keyword) {
    string decrypted_text;
    int keyword_length = keyword.length();
    string lowercase_keyword = keyword;
    for (char& c : lowercase_keyword) {
        c = tolower(c);
    }


    for (size_t i = 0; i < ciphertext.length(); ++i) {
        char char_to_decrypt = ciphertext[i];
        if (isalpha(char_to_decrypt)) {
            char base = islower(char_to_decrypt) ? 'a' : 'A';

            int shift = lowercase_keyword[i % keyword_length] - 'a';

            char decrypted_char = (char_to_decrypt - base - shift + 26) % 26 + base;
            decrypted_text += decrypted_char;
        } else {

            decrypted_text += char_to_decrypt;
        }
    }

    return decrypted_text;
}

int main() {
    cout << "--------------Welcome to the Vigenere Cipher program-----------\n";     //welcome message
    cout << "This program can encrypt or decrypt a message using the Vigenere Cipher method\n";
    cout << "The input message should be restricted to 80 characters, the keyword to 8 characters \n.";
    cout << "------------------------------------------------------------------\n";
    while (true) {
        cout << "1. Encrypt\n";
        cout << "2. Decrypt\n";
        cout << "3. Quit\n";
        cout << "Enter your choice: ";

        string choice;
        getline(cin, choice);

        if (choice == "1") {
            string message, keyword;
            cout << "Enter your message (up to 80 characters): ";
            getline(cin, message);

            if (message.length() > 80) {
                cout << "Message length exceeds the limit. Please enter a message with up to 80 characters.\n";
                continue;
            }

            cout << "Enter your keyword (up to 8 characters): ";
            getline(cin, keyword);

            if (keyword.length() > 8) {
                cout << "Keyword length exceeds the limit. Please enter a keyword with up to 8 characters.\n";
                continue;
            }

            string encrypted_message = encrypt(message, keyword);
            cout << "Encrypted message: " << encrypted_message << endl;
        } else if (choice == "2") {
            string ciphertext, keyword;
            cout << "Enter your ciphertext: ";
            getline(cin, ciphertext);

            cout << "Enter your keyword (up to 8 characters): ";
            getline(cin, keyword);

            if (keyword.length() > 8) {
                cout << "Keyword length exceeds the limit. Please enter a keyword with up to 8 characters.\n";
                continue;
            }

            string decrypted_message = decrypt(ciphertext, keyword);
            cout << "Decrypted message: " << decrypted_message << endl;
        } else if (choice == "3") {
            cout << "Thanks for using the program. lets See you again \n";
            break;
        } else {
            cout << "Invalid choice. Please choose 1, 2, or 3.\n";
        }
    }

    return 0;
}