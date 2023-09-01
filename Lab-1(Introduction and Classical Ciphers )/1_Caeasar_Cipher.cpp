// Write a program that takes an integer value K (i.e. shift value between +/- 26) and a plaintext
// message and returns the corresponding Caeasar cipher. The program should also implement a
// decryption routine that reconstructs the original plaintext from the ciphertext.

#include<iostream>
using namespace std;

string encrypt(string plain, int key)
{
    string c, p;
    p = plain;
    for (int i=0;i<p.length();i++)
    {
        if (isupper(p[i]))
        {
            c = c + char((int(p[i]) + key - 65 ) % 26 + 65);
        }
        else
        {
            c = c + char((int(p[i]) + key - 97 ) % 26 + 97);
        }
    }
    return c;
}

string decrypt(string cipher, int key)
{
    string  p, c;
    c = cipher;
    for (int i=0;i<c.length();i++)
    {
        if (isupper(c[i]))
        {
            p = p + char((int(c[i]) - key - 65 ) % 26 + 65);
        }
        else
        {
            p = p + char((int(c[i]) - key - 97 ) % 26 + 97);
        }
    }
    return p;
}

int main(){
    string str, c, p;
    int key, choice;
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
                cout << "The cyphered string is " << encrypt(str, key) << endl;
                break;
            case 2:
                cout << "Enter the string to decipher: ";
                cin >> str;
                cout << "Enter the key ";
                cin >> key;
                cout << "The deciphered string is " << decrypt(str, key) << endl;
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