// Write a program that asks user for key and plain text and displays the corresponding Vigenere cipher.

#include<iostream>
using namespace std;

string keygen(string plain, string key)
{
    for (int i = 0; i < plain.length(); i++)
    {
        if (plain.length() == i)
        {
            i = 0;
        }
        if (key.length() == plain.length())
        {
            break;
        }
        key = key + key[i];
    }
    return key;
}

string encrypt(string plain, string key)
{
    string c, p;
    p = plain;
    for (int i=0;i<p.length();i++)
    {
        if (isupper(p[i]))
        {
            c = c + char((p[i] + key[i]) % 26 + 65);
        }
        else
        {
            c = c + char((p[i] + key[i]) % 26 + 97);
        }
    }
    return c;
}

string decrypt(string cipher, string key)
{
    string  p, c;
    c = cipher;
    for (int i=0;i<c.length();i++)
    {
        if (isupper(c[i]))
        {
            p = p + char((c[i] - key[i] + 26) % 26 + 65);
        }
        else
        {
            p = p + char((c[i] - key[i] + 26) % 26 + 97);
        }
    }
    return p;
}

int main(){
    string  key, c, p, str,  keys; 
    int choice;
    while (choice != 3)
    {
        cout << "Enter 1 for encryption" <<endl;
        cout << "Enter 2 for decryption" <<endl;
        cout << "Enter 3 to exit " << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter the string to cipher ";
                cin >> str;
                cout << "Enter the key ";
                cin >> key;
                keys = keygen(str, key);
                cout << "The cyphered string is " << encrypt(str, keys) << endl;
                break;
            case 2:
                cout << "Enter the string to decipher: ";
                cin >> str;
                cout << "Enter the key ";
                cin >> key;
                keys = keygen(str, key);
                cout << "The deciphered string is " << decrypt(str, keys) << endl;
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return 0;
}