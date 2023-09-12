// Write a program to apply the round function to a given 32-bit data and subkey, and display the intermediate 
#include<iostream>
#include<string>
#include<bitset>
#include<cmath>

using namespace std;

string convertDecimalToBinary(int decimal)
{
	string binary;
    while (decimal != 0) 
    {
        if (decimal % 2 == 0) {
            binary = "0" + binary;
        } 
        else 
        {
            binary = "1" + binary;
        }
        decimal = decimal / 2;
    }
	while(binary.length() < 4){
		binary = "0" + binary;
	}
    return binary;
}
int convertBinaryToDecimal(string binary)
{
    int decimal = 0;
	int counter = 0;
	int size = binary.length();
	for(int i = size-1; i >= 0; i--)
	{
    	if(binary[i] == '1'){
        	decimal += pow(2, counter);
    	}
    counter++;
	}
	return decimal;
}

string Xor(string a, string b){ 
	string result = ""; 
	int size = b.size();
	for(int i = 0; i < size; i++){ 
		if(a[i] != b[i]){ 
			result += "1"; 
		}
		else{ 
			result += "0"; 
		} 
	} 
	return result; 
}

void round_function(string Right_Plain_text, const string Round_key) {
    int expansion_table[48] = { 
	    32,1,2,3,4,5,4,5, 
	    6,7,8,9,8,9,10,11, 
	    12,13,12,13,14,15,16,17, 
	    16,17,18,19,20,21,20,21, 
	    22,23,24,25,24,25,26,27, 
	    28,29,28,29,30,31,32,1 
	    };

    int substition_boxes[8][4][16]=  
	{{ 
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7, 
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8, 
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0, 
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13 
    }, 
    { 
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10, 
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5, 
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15, 
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9 
    }, 
    { 
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8, 
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1, 
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7, 
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12 
    }, 
    { 
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15, 
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9, 
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4, 
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14 
    }, 
    { 
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9, 
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6, 
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14, 
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3 
    }, 
    { 
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11, 
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8, 
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6, 
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13 
    }, 
    { 
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1, 
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6, 
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2, 
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12 
    }, 
    { 
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7, 
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2, 
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8, 
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11 
    }};

    // The permutation table
	int permutation_tab[32] = { 
	16,7,20,21,29,12,28,17, 
	1,15,23,26,5,18,31,10, 
	2,8,24,14,32,27,3,9,
	19,13,30,6,22,11,4,25 
	};
    // Apply the expansion permutation.The right half of the plain text is expanded
    string right_expanded="";
    for(int i = 0; i < 48; i++) { 
        right_expanded += Right_Plain_text[expansion_table[i]];    
    }

    // XOR with the round key.
    string xored = Xor(Round_key, right_expanded);  
	string res = "";

    // Apply the S-boxes.
    string S_box_outputs(32, '\0');
    for (int i = 0; i < 8; i++) {
    string row1= xored.substr(i*6,1) + xored.substr(i*6 + 5,1);
      		int row = convertBinaryToDecimal(row1);
      		string col1 = xored.substr(i*6 + 1,1) + xored.substr(i*6 + 2,1) + xored.substr(i*6 + 3,1) + xored.substr(i*6 + 4,1);;
			int col = convertBinaryToDecimal(col1);
			int val = substition_boxes[i][row][col];
			res += convertDecimalToBinary(val); 
    }

  // Apply the P-box permutation.
    string perm2 ="";
    for(int i = 0; i < 32; i++){ 
		perm2 += res[permutation_tab[i]-1]; 
	}
    cout << perm2 <<endl;
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
    string key, Plain_Text, key_bin, binary_plaintext, ciphertext;
    cout << "Enter the Plain text to encrypt" << endl;
    cin >> Plain_Text;
    binary_plaintext = TextToBinaryString(Plain_Text).substr(0, 64);
    string left_half = binary_plaintext.substr(0, 32);
    string right_half = binary_plaintext.substr(32, 32);
    for (int i = 0; i < 16; i++) 
    {
        // Get the round key.
        string round_key = "";
        for (int j = 0; j < 48; j++) 
        {
            round_key += binary_plaintext[48 * i + j];
        }
        // Apply the round function.
        round_function(right_half, round_key);
        // Swap the left and right halves.
        string temp = left_half;
        left_half = right_half;
        right_half = temp;
    }
    ciphertext = left_half + right_half;
    cout << ciphertext << endl;
}