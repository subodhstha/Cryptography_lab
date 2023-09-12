// Write a program to implement the DES key generation process to generate subkeys. Also, show the subkeys generated at each round.
#include<iostream>
#include<string>
#include<bitset>
using namespace std;

string round_keys[16];
// circular left shift by one
string C_L_Shift_Once(string key_chunk)
{
    string shifted = "";
    for (int i = 1; i < 28; i++)
    {
        shifted += key_chunk[i];
    }
    shifted += key_chunk[0];
    return shifted;

}

// circular left shift by two
string C_L_Shift_Twice(string key_chunk)
{
    string shifted = "";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < 28; j++)
        {
            shifted += key_chunk[j];
        }
        shifted += key_chunk[0];
        key_chunk = shifted;
        shifted = "";
    }
    return key_chunk;
}

void key_generate(string key)
{
    // initial permutation table to convert the key in 56bits
	int ip[56] = {
	    57,49,41,33,25,17,9, 
	    1,58,50,42,34,26,18, 
	    10,2,59,51,43,35,27, 
	    19,11,3,60,52,44,36,		 
	    63,55,47,39,31,23,15, 
	    7,62,54,46,38,30,22, 
	    14,6,61,53,45,37,29, 
	    21,13,5,28,20,12,4 
	    };
	// compression permutation table to compress the key in 48bits
	int cp[48] = { 
	    14,17,11,24,1,5, 
	    3,28,15,6,21,10, 
	    23,19,12,4,26,8, 
	    16,7,27,20,13,2, 
	    41,52,31,37,47,55, 
	    30,40,51,45,33,48, 
	    44,49,39,56,34,53, 
	    46,42,50,36,29,32 
	    };

    // compressing the Key to 56 bit using compression permutation table
    string perm_key =""; 
	for(int i = 0; i < 56; i++)
    { 
		perm_key+= key[ip[i]-1]; 
	}
    // dividing the the 56 key into two part
    string left = perm_key.substr(0, 28);
    string right = perm_key.substr(28, 56);

    // generating 16 round key
    for (int i = 0; i < 16; i++)
    {
        // one left circular for 1, 2, 9, 16
        if (i == 0 || i == 1|| i == 8 || i == 15)
        {
            left = C_L_Shift_Once(left);
            right = C_L_Shift_Once(right);
        }
        else
        {
            left = C_L_Shift_Twice(left);
            right = C_L_Shift_Twice(right);
        }   
        // key chunks are combined
        string combined_key = left + right;
        string round_key = "";
        for (int i = 0; i < 48; i++)
        {
            round_key += combined_key[cp[i]-1];
        }
        round_keys[i] = round_key;
        cout << "Key "<< i+1 << ":" << round_keys[i] << endl;
    }
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
    string key, Plain_Text, key_bin;
    cout << "Enter the key to encrypt" << endl;
    cin >> key;
    key_bin = TextToBinaryString(key).substr(0, 64);
    key_generate(key_bin);
}