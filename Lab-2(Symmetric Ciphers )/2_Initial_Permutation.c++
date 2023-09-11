// Implement the initial permutation of the DES algorithm by applying the initial permutation to a given plaintext block and observe the result.
#include<iostream>
#include<string>
#include<bitset>
using namespace std;

void initial_permutation(string Plain_Text)
{
    //Assuming each character is 1 bit instead of 1 byte
	int initial_perm[64] = {
        58, 50, 42, 34, 26, 18, 10, 2,
        60, 52, 44, 36, 28, 20, 12, 4,
        62, 54, 46, 38, 30, 22, 14, 6,
        64, 56, 48, 40, 32, 24, 16, 8,
        57, 49, 41, 33, 25, 17, 9, 1,
        59, 51, 43, 35, 27, 19, 11, 3,
        61, 53, 45, 37, 29, 21, 13, 5,
        63, 55, 47, 39, 31, 23, 15, 7
        };

    string Encrypt;
	for(int i=0;i<64;i++){
	    Encrypt += Plain_Text[initial_perm[i]];
	}
	cout << Encrypt;
    cout<<"\n";
}

string TextToBinaryString(string words)
{
    string binaryString = "";
    for (char& _char : words) {
        binaryString +=bitset<8>(_char).to_string();
    }
    return binaryString;
}

int main()
{
    string Plain_Text, Plain_Text_bin;
    cout << "Enter the Plain text to encrypt" << endl;
    cin >> Plain_Text;
    cout<<"Text to be Encrypted " << Plain_Text <<endl;
    Plain_Text_bin = TextToBinaryString(Plain_Text).substr(0, 64);
    initial_permutation(Plain_Text_bin);
}