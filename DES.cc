#include <bits/stdc++.h> 
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std; 

// Structure indiquant pour chaque chiffré faux s'il est utile à la sbox ou pas
typedef struct LISTE{
    int useful; //Indice indiquant si le chiffré faux apporte de l'information sur la clé, 1 si oui, 0 si non
}LISTE;


//Permute les bits d'un message suivant la table donnée en entrée 
string permutation(string m, int* table, int n){ 
	string res = ""; 
	int i = 0;
	for (i = 0; i < n; i++) { 
		res += m[table[i]-1]; 
	} 
	return res; 
} 

//Applique  initial_permutation à un message
string initial_permutation(string m){
	// Initial Permutation table 
    int table_ip[64] = { 58, 50, 42, 34, 26, 18, 10, 2, 
                         60, 52, 44, 36, 28, 20, 12, 4, 
                         62, 54, 46, 38, 30, 22, 14, 6, 
                         64, 56, 48, 40, 32, 24, 16, 8, 
                         57, 49, 41, 33, 25, 17, 9, 1, 
                         59, 51, 43, 35, 27, 19, 11, 3, 
                         61, 53, 45, 37, 29, 21, 13, 5, 
                         63, 55, 47, 39, 31, 23, 15, 7 };

    return permutation(m,table_ip,64);
}

//Applique  initial_permutation inverse à un message
string initial_permutation_1(string m){
	// Inversal Initial Permutation table 
	int table_ip_1[64] = { 40, 8, 48, 16, 56, 24, 64, 32,
						   39, 7, 47, 15, 55, 23, 63, 31,
						   38, 6, 46, 14, 54, 22, 62, 30,
						   37, 5, 45, 13, 53, 21, 61, 29,
						   36, 4, 44, 12, 52, 20, 60, 28,
						   35, 3, 43, 11, 51, 19, 59, 27,
						   34, 2, 42, 10, 50, 18, 58, 26,
						   33, 1, 41, 9, 49, 17, 57, 25 };

	return permutation(m,table_ip_1,64);
}

// E(m), fonction d'expansion de m de 32 à 48 bits
string expansion_32_to_48(string m){
	int E_table[48] = { 32, 1, 2, 3, 4, 5, 4, 5, 
                      6, 7, 8, 9, 8, 9, 10, 11, 
                      12, 13, 12, 13, 14, 15, 16, 17, 
                      16, 17, 18, 19, 20, 21, 20, 21, 
                      22, 23, 24, 25, 24, 25, 26, 27, 
                      28, 29, 28, 29, 30, 31, 32, 1 }; 

    return permutation(m,E_table,48);
}

// Applique  P_permutation à un message
string P_permutation(string m){
	int P_table[32] = { 16, 7, 20, 21,
						29, 12, 28, 17,
						1, 15, 23, 26,
						5, 18, 31, 10,
					    2, 8, 24, 14, 
						32, 27, 3, 9,
						19, 13, 30, 6, 
						22, 11, 4, 25 };

	return permutation(m,P_table,32);	
}

// Applique  P1_permutation à un message
string P_1_permutation(string m){
	int P_1_table[32] = { 9, 17, 23, 31, //1
						13, 28, 2, 18, //5
						24, 16, 30, 6, //9
						26, 20, 10, 1, //13
						8, 14, 25, 3,  //17
						4, 29, 11, 19, //21
						32, 12, 22, 7, //25
						5, 27, 15, 21 }; //29
	return permutation(m,P_1_table,32);
}

// Applique  PC1_permutation à un message
string PC1_permutation(string m){
	 int PC1[56] ={		57,49,41,33,25,17,9,
    					1,58,50,42,34,26,18,
					    10,2,59,51,43,35,27,
					    19,11,3,60,52,44,36,
					    63,55,47,39,31,23,15,
					    7,62,54,46,38,30,22,
					    14,6,61,53,45,37,29,
					    21,13,5,28,20,12,4
    };
	return permutation(m,PC1,56);
}

// Applique  PC2_permutation à un message
string PC2_permutation(string m){
	 int PC2[48] ={		14,17,11,24,1,5,
					    3,28,15,6,21,10,
					    23,19,12,4,26,8,
					    16,7,27,20,13,2,
					    41,52,31,37,47,55,
					    30,40,51,45,33,48,
					    44,49,39,56,34,53,
					    46,42,50,36,29,32
    };
	return permutation(m,PC2,48);
}

// Applique  PC1_permutation inverse à un message
string PC1_1_permutation(string m){
	    int PC1_1[64]={ 8, 16, 24, 56, 52, 44,
					    36, 0,  7,  15, 23, 55,
					    51, 43, 35, 0,  6,  14,
					    22, 54, 50, 42, 34, 0,
					    5,  13, 21, 53, 49, 41,
					    33, 0,  4,  12, 20, 28,
					    48, 40, 32, 0,  3,  11,
					    19, 27, 47, 39, 31, 0,
					    2,  10, 18, 26, 46, 38,
					    30, 0,  1,  9,  17, 25,
					    45, 37, 29, 0
	};
	return permutation(m,PC1_1,64); 
}

// Applique  PC2_permutation inverse à un message
string PC2_1_permutation(string m){
		 int PC2_1[56]={5,  24, 7,  16, 6,  10,
					    20, 18, 0,  12, 3,  15,
					    23, 1,  9,  19, 2,  0,
					    14, 22, 11, 0,  13, 4,
					    0,  17, 21, 8,  47, 31,
					    27, 48, 35, 41, 0,  46,
					    28, 0,  39, 32, 25, 44,
					    0,  37, 34, 43, 29, 36,
					    38, 45, 33, 26, 42, 0,
					    30,  40
	};
	return permutation(m,PC2_1,56); 
}


//Convertit un message hexadécimal en binaire
string hex_to_bin(string s){ 
	unordered_map<char, string> c; 
	c['0'] = "0000"; 
	c['1'] = "0001"; 
	c['2'] = "0010"; 
	c['3'] = "0011"; 
	c['4'] = "0100"; 
	c['5'] = "0101"; 
	c['6'] = "0110"; 
	c['7'] = "0111"; 
	c['8'] = "1000"; 
	c['9'] = "1001"; 
	c['A'] = "1010"; 
	c['B'] = "1011"; 
	c['C'] = "1100"; 
	c['D'] = "1101"; 
	c['E'] = "1110"; 
	c['F'] = "1111"; 
	string res_bin = ""; 
	for (int i = 0; i < s.size(); i++) { 
		res_bin += c[s[i]]; 
	} 
	return res_bin; 
} 
//Convertit un hexadécimal de 2 bits en un binaire de 6 bits
string hex_to_bin_26(string s){ 
	string s1,s2,res;
	switch (s[0]) {
        case '0':
            s1 = "00";
            break;
        case '1':
            s1 = "01";
            break;
        case '2':
            s1 = "10";
            break;
        case '3':
           s1 = "11";
            break;
        default:
           s1 = "woooo";
  		}

	switch (s[1]) {
        case '0':
            s2 = "0000";
            break;
        case '1':
            s2 = "0001";
            break;
        case '2':
            s2 = "0010";
            break;
        case '3':
           s2 = "0011";
            break;
        case '4':
           s2 = "0100";
            break;
        case '5':
            s2 = "0101";
            break;
        case '6':
            s2 = "0110";
            break;
        case '7':
            s2 = "0111";
            break;
        case '8':
            s2 = "1000";
            break;
      	case '9':
            s2 = "1001";
            break;
        case 'A':
      		s2 = "1010";
            break;
        case 'B':
       		s2 = "1011";
            break;
        case 'C':
        	s2 = "1100";
            break;
        case 'D':
       		s2 = "1101";
            break;
        case 'E':
    		s2 = "1110";
            break;
        case 'F':
  			s2 = "1111";
            break;
        default:
            s2 = "grrrr";
  		}
  	res = s1+s2;
	return res;
} 

//Convertit un binaire en hexadecimal 
string bin_to_hex(string s){ 
	unordered_map<string, string> c; 
	c["0000"] = "0"; 
	c["0001"] = "1"; 
	c["0010"] = "2"; 
	c["0011"] = "3"; 
	c["0100"] = "4"; 
	c["0101"] = "5"; 
	c["0110"] = "6"; 
	c["0111"] = "7"; 
	c["1000"] = "8"; 
	c["1001"] = "9"; 
	c["1010"] = "A"; 
	c["1011"] = "B"; 
	c["1100"] = "C"; 
	c["1101"] = "D"; 
	c["1110"] = "E"; 
	c["1111"] = "F"; 
	string res_hex = ""; 
	for (int i = 0; i < s.length(); i += 4) { 
		string tmp = ""; 
		tmp += s[i]; 
		tmp += s[i + 1]; 
		tmp += s[i + 2]; 
		tmp += s[i + 3]; 
		res_hex += c[tmp]; 
	} 
	return res_hex; 
} 

//XOR entre 2 binaires, retourne un binaire
string XOR_bin_input(string a, string b) { 
	string x = ""; 
	for (int i = 0; i < a.size(); i++) { 
		if (a[i] == b[i]) { 
			x += "0"; 
		} 
		else { 
			x += "1"; 
		} 
	} 
	return x; 
}

// Transforme un décimal en binaire
string dec_to_bin(int n){
    string res;
    while(n != 0){
        res += ( n%2 == 0 ? "0" : "1");
        n /= 2;
    }
    return res;
}

// Transforme un hexadécimal de 2 bits en binaire de 6 bits
string bin_to_hex_26(string a){
	string s = a.substr(0,2);
  	unordered_map<string, string> c; 
	c["00"] = "0"; 
	c["01"] = "1"; 
	c["10"] = "2"; 
	c["11"] = "3";
	string res = ""; 
		string tmp = ""; 
		tmp += s[0]; 
		tmp += s[1]; 
		res = c[tmp]; 
  	string e = a.substr(2,4);
  	e = bin_to_hex(e);
    res = res + e;
  	return res;

}

// Calcule le résultat après passage dans l'une des 8 SBOXes
int S_BOX_result(int SBOX, int row, int column){
	//SBox Table 
    int S_BOX[8][4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7, 
                          0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8, 
                          4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0, 
                          15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 }, 
                        { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10, 
                          3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5, 
                          0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15, 
                          13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 }, 
  
                        { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8, 
                          13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1, 
                          13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7, 
                          1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 }, 
                        { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15, 
                          13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9, 
                          10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4, 
                          3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 }, 
                        { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9, 
                          14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6, 
                          4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14, 
                          11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 }, 
                        { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11, 
                          10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8, 
                          9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6, 
                          4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 }, 
                        { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1, 
                          13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6, 
                          1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2, 
                          6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 }, 
                        { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7, 
                          1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2, 
                          7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8, 
                          2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };
	return S_BOX[SBOX-1][row][column];
}

// Shift d'un bit vers la gauche d'un message 
string left_shift(string m){
	string a = "";
	for(int i = 1; i < 28; i++) {
            a += m[i];
    }
    a += m[0];
    return a;
}

// Algorithme de cadencement de clés
void key_schedule(string k, string keys[16]){
	int shift[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
	string p = PC1_permutation(k);
	//On split la clé en deux moitiés de 28 bits sur lesquelles on effectue 1 ou 2 shifts suivant le tour
	string left = p.substr(0,28);
	string right = p.substr(28,28); 
	for(int i=0; i<16; i++){
		if(shift[i] == 1){
			left = left_shift(left);
			right = left_shift(right);
		}
		else{
			left = left_shift(left_shift(left));
			right = left_shift(left_shift(right));
		}
		string merge = left + right;
		string round_key = "";
		round_key = PC2_permutation(merge);
		keys[i] = round_key;
	}
}

// Transforme un entier binaire en string décimal
string dec_to_bin_str(int decimal){
	string binary;
	while (decimal != 0) {
		binary = (decimal % 2 == 0 ? "0" : "1") + binary;
		decimal = decimal / 2;
	}
	while (binary.size() < 4) {
		binary = "0" + binary;
	}
	return binary;
}

// Transforme un string binaire en entier décimal
int bin_to_dec_int(string binary){
	int count = 0;
	int decimal = 0;
	int size = binary.size();
	for (int i = size - 1; i >= 0; i--)
	{
		if (binary[i] == '1') {
			decimal += pow(2, count);
		}
		count++;
	}
	return decimal;
}

// Trouve l'élément le plus fréquent, utile pour l'intersection de clés
string mostFrequent(string arr[], int n){
    sort(arr, arr + n);
    int max_count = 1,  curr_count = 1;
    string res = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1])
            curr_count++;
        else {
            if (curr_count > max_count) {
                max_count = curr_count;
                res = arr[i - 1];
            }
            curr_count = 1;
        }
    }
    if (curr_count > max_count)
    {
        max_count = curr_count;
        res = arr[n - 1];
    }
    return res;
}

//Return 1 si c contient un nombre impair de 1, 0 sinon
int is_odd_nb_1(string c){
	int count=0;
	for(int z=0;z<c.size();z++){
		count += bin_to_dec_int(c.substr(z,1));
	}
	int is_odd = (count % 2 == 0 ?  0 : 1);
	return is_odd;
}

// Algorithme de chiffrement du DES 
string DES_Encryption(string plaintext, string key){
	// Round Keys generation 
	string keys[16];
	key_schedule(hex_to_bin(key),keys);
	
	// Initial Permutation
	string m = hex_to_bin(plaintext);
	m = initial_permutation(m);
	
	// Splitting
	string left = m.substr(0, 32);
    string right = m.substr(32, 32);

	for(int i=0; i<16; i++){
		// Expansion E and xor with round key i
		string right_E = expansion_32_to_48(right);
	
		string x = XOR_bin_input(right_E,keys[i]);
		// SBOXES
		string p = "";
		string res = "";
		for (int j = 0; j<8 ; j++){
			string row1 = x.substr(j * 6, 1) + x.substr(j * 6 + 5, 1);
			int row = bin_to_dec_int(row1);
			string col1 = x.substr(j * 6 + 1, 1) + x.substr(j * 6 + 2, 1) + x.substr(j * 6 + 3, 1) + x.substr(j * 6 + 4, 1);;
			int col = bin_to_dec_int(col1);
			int val = S_BOX_result(j+1,row,col);
			res += dec_to_bin_str(val);

		} 
		// Permutation P
		p = P_permutation(res);
		// left xor F(right,ki)
		x = XOR_bin_input(left,p);
		left = x;

		// Swap (twisted ladder)
		if(i<15)
			swap(left,right);
		else;		
	}
	// Merge left right
	string merge = left + right;
	// Inverse initial permutation
	string cipher = initial_permutation_1(merge);
	cipher = bin_to_hex(cipher);

	return cipher;
}

// Met les bons bits de parité (nombre impair de 1) d'un message de 64 bits
string set_parity(string m){
	string K="";
	string tmp="";
	int i=0;
	string m1 = m.substr(0,7); 
	if(is_odd_nb_1(m1) == 0){
			m1 += "1";
		}
		else{
			m1 += "0";
		}
	string m2 = m.substr(8,7);
	if(is_odd_nb_1(m2) == 0){
			m2 += "1";
		}
		else{
			m2 += "0";
		}
	string m3 = m.substr(16,7);;
	if(is_odd_nb_1(m3) == 0){
			m3 += "1";
		}
		else{
			m3 += "0";
		}
	string m4 = m.substr(24,7);;
	if(is_odd_nb_1(m4) == 0){
			m4 += "1";
		}
		else{
			m4 += "0";
		}
	string m5 = m.substr(32,7);;
	if(is_odd_nb_1(m5) == 0){
			m5 += "1";
		}
		else{
			m5 += "0";
		}
	string m6 = m.substr(40,7);;
	if(is_odd_nb_1(m6) == 0){
			m6 += "1";
		}
		else{
			m6 += "0";
		}
	string m7 = m.substr(48,7);;
	if(is_odd_nb_1(m7) == 0){
			m7 += "1";
		}
		else{
			m7 += "0";
		}
	string m8 = m.substr(56,7);;
	if(is_odd_nb_1(m8) == 0){
			m8 += "1";
		}
		else{
			m8 += "0";
		}
	
	K = m1+m2+m3+m4+m5+m6+m7+m8;					
	return K;
}

// Fonction retrouvant la valeur K de la clé initiale à partir de la clé de tour K16
void find_final_k(string plaintext, string k16, string expected_cipher){
	string t[2] = {"0","1"};
	string m = k16;
	// Permutation inverse 2
	string p1 = m.substr(4,1)+m.substr(23,1)+m.substr(6,1)+m.substr(15,1)+m.substr(5,1)+m.substr(9,1)+m.substr(19,1)+m.substr(17,1);
	string p2 = m.substr(11,1)+m.substr(2,1)+m.substr(14,1)+m.substr(22,1)+m.substr(0,1)+m.substr(8,1)+m.substr(18,1)+m.substr(1,1);
	string p3 = m.substr(13,1)+m.substr(21,1)+m.substr(10,1);
	string p4 = m.substr(12,1)+m.substr(3,1);
	string p5 = m.substr(16,1)+m.substr(20,1)+m.substr(7,1)+m.substr(46,1)+m.substr(30,1)+m.substr(26,1)+m.substr(47,1)+m.substr(34,1)+m.substr(40,1);
	string p6 = m.substr(45,1)+m.substr(27,1);
	string p7 = m.substr(38,1)+m.substr(31,1)+m.substr(24,1)+m.substr(43,1);
	string p8 = m.substr(36,1)+m.substr(33,1)+m.substr(42,1)+m.substr(28,1)+m.substr(35,1)+m.substr(37,1)+m.substr(44,1)+m.substr(32,1)+m.substr(25,1)+m.substr(41,1);
	string p9 = m.substr(29,1)+m.substr(39,1);
	// Les 8 bits perdus sont mis à valeur 8
	string PC2_1_K16 = p1+"8"+p2+"8"+p3+"8"+p4+"8"+p5+"8"+p6+"8"+p7+"8"+p8+"8"+p9;
	// Permutation inverse 1
	string q = PC2_1_K16;
	string q1 = q.substr(7,1)+q.substr(15,1)+q.substr(23,1)+q.substr(55,1)+q.substr(51,1)+q.substr(43,1)+q.substr(35,1);
	string q2 = q.substr(6,1)+q.substr(14,1)+q.substr(22,1)+q.substr(54,1)+q.substr(50,1)+q.substr(42,1)+q.substr(34,1);
	string q3 = q.substr(5,1)+q.substr(13,1)+q.substr(21,1)+q.substr(53,1)+q.substr(49,1)+q.substr(41,1)+q.substr(33,1);
	string q4 = q.substr(4,1)+q.substr(12,1)+q.substr(20,1)+q.substr(52,1)+q.substr(48,1)+q.substr(40,1)+q.substr(32,1);
	string q5 = q.substr(3,1)+q.substr(11,1)+q.substr(19,1)+q.substr(27,1)+q.substr(47,1)+q.substr(39,1)+q.substr(31,1);
	string q6 = q.substr(2,1)+q.substr(10,1)+q.substr(18,1)+q.substr(26,1)+q.substr(46,1)+q.substr(38,1)+q.substr(30,1);
	string q7 = q.substr(1,1)+q.substr(9,1)+q.substr(17,1)+q.substr(25,1)+q.substr(45,1)+q.substr(37,1)+q.substr(29,1);
	string q8 = q.substr(0,1)+q.substr(8,1)+q.substr(16,1)+q.substr(24,1)+q.substr(44,1)+q.substr(36,1)+q.substr(28,1);
	string o1 ="7";
	string o2 ="7";
	string o3 ="7";
	string o4 ="7";
	string o5 ="7";
	string o6 ="7";
	string o7 ="7";
	string o8 ="8";
	string PC1_1_PC2_1_K16 = q1+o1+q2+o2+q3+o3+q4+o4+q5+o5+q6+o6+q7+o7+q8+o8;

	// Retrouver les bits perdus après les deux permutations, les bits 7 de parités sont mis à valeur 7 
	// Avec p: portion non splitée, x: bit perdu , o:bit de parité
	// Le message devient: p1+o1+p2+x1+x2+o2+p3+x3+x4+p4+o3+p5+o4+p6+o5+p7+o5+p8+x5+p9+x6+p10+o6+p11+x7+p12+x8+p13+x8
	string actu = PC1_1_PC2_1_K16;
	p1 = actu.substr(0,7); 
	p2 = actu.substr(8,5);
	p3 = actu.substr(16,2); 
	p4 = actu.substr(20,3);
	p5 = actu.substr(24,7);
	p6 = actu.substr(32,7);
	p7 = actu.substr(40,7);
	p8 = actu.substr(48,2);
	p9 = actu.substr(51,2);
	string p10 = actu.substr(54,1);
	string p11 = actu.substr(56,1);
	string p12 = actu.substr(58,1);
	string p13 = actu.substr(60,3);
	
	//Brut force sur les 8 bits manquants (256 possibilités)	
	int val = 0;
	for(int i1=0;i1<2;i1++){
		for(int i2=0;i2<2;i2++){
			for(int i3=0;i3<2;i3++){
				for(int i4=0;i4<2;i4++){
					for(int i5=0;i5<2;i5++){
						for(int i6=0;i6<2;i6++){
							for(int i7=0;i7<2;i7++){
								for(int i8=0;i8<2;i8++){
									val++;
									string x1 = t[i1];
									string x2 = t[i2];
									string x3 = t[i3];
									string x4 = t[i4];
									string x5 = t[i5];
									string x6 = t[i6];
									string x7 = t[i7];
									string x8 = t[i8];
									actu = p1+o1+p2+x1+x2+o2+p3+x3+x4+p4+o3+p5+o4+p6+o5+p7+o5+p8+x5+p9+x6+p10+o6+p11+x7+p12+x8+p13+x8;
									// On modifie la clé avec les bits de parité adéquats
									actu = set_parity(actu);
									string K = bin_to_hex(actu);
									string cipher = DES_Encryption(plaintext,K);
									if(cipher == expected_cipher ){ 
										cout<<"CLÉ TROUVÉE: "<<K<<endl;
									}
								}
							}
						}
					}
				} 
			}
		}
	}  
}


// Differential Fault Analysis sur le DES
// Retrouve la clé à partir d'un message clair, du chiffré juste, et de la liste de chiffrés faux
void DFA_attack(string plaintext,string right_cipher,string wrong_ciphers[]){
		
	LISTE all_keys[8][32];
	string k16 ="";
	// Stockage des listes de clés possibles pour l'intersection 
	list<string> ks1;
	list<string> ks2;
	list<string> ks3;
	list<string> ks4;
	list<string> ks5;
	list<string> ks6;
	list<string> ks7;
	list<string> ks8;

	for(int z = 0; z<32; z++){
		//Pour chaque couple chiffré juste,faux find_XOR_S_in_out_put
		string c = hex_to_bin(right_cipher);
		c = initial_permutation(c);
		string R16_c =  c.substr(0, 32);
		string R15_c =  c.substr(32, 32);
		R15_c = expansion_32_to_48(R15_c);

		string c_ = wrong_ciphers[z];
		c_ = hex_to_bin(c_);
		c_ = initial_permutation(c_);
		string R16_c_ =  c_.substr(0, 32);
		string R15_c_ =  c_.substr(32, 32);
		R15_c_ = expansion_32_to_48(R15_c_);

		string XOR_S_i = XOR_bin_input(R15_c,R15_c_);
		string XOR_S_o = XOR_bin_input(R16_c,R16_c_);
		XOR_S_o = P_1_permutation(XOR_S_o);

		// Pour chaque paquet de s_i,s_o (chaque sbox)
		for(int p=0; p<8; p++){
			string p_xor_i = XOR_S_i.substr(p*6,6);
			string p_xor_o = XOR_S_o.substr(p*4,4);
			// si xor nul, ce paquet ne donne pas d'info sur la clé pour cette sbox
			if(p_xor_i == "000000") all_keys[p][z].useful = 0;
			else{
				string diff_si = p_xor_i;
				string t1[4] ={"0","1","2","3"};
				string t2[16] ={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
				string a ="";
				string b ="";
				//Générer tous les couples tel que a xor b = diff_si
				for(int i = 0; i<4;i++){
					for(int j=0; j<16;j++){
						a = t1[i] + t2[j];
						a = hex_to_bin_26(a);
						for(int k = 0; k<4;k++){
							for(int l=0; l<16;l++){
								b = t1[k] + t2[l];
								b = hex_to_bin_26(b);
								if(XOR_bin_input(a,b) == diff_si){
									string row1 = a.substr(0, 1) + a.substr(5, 1);
									int row_a = bin_to_dec_int(row1);
									string col1 = a.substr(1,4);
									int col_a = bin_to_dec_int(col1);
									int val_a = S_BOX_result(p+1,row_a,col_a);
									string out_1 = dec_to_bin_str(val_a);
									string row2 = b.substr(0, 1) + b.substr(5, 1);
									int row_b = bin_to_dec_int(row1);
									string col2 = b.substr(1,4);
									int col_b = bin_to_dec_int(col2);
									int val_b = S_BOX_result(p+1,row_b,col_b);
									string out_2 = dec_to_bin_str(val_b);
									// Si Sbox(a) xor Sbox(b), alors on garde le couple
									if(XOR_bin_input(out_1,out_2) == p_xor_o){
										all_keys[p][i].useful = 1;
										a = XOR_bin_input(R15_c.substr(p*6,6),a);
										a = bin_to_hex_26(a);
										b = XOR_bin_input(R15_c.substr(p*6,6),b);
										b = bin_to_hex_26(b);
										switch (p) {
										        case 0:
										            ks1.push_back(a);
										            ks1.push_back(b);
										            break;
										        case 1:
										            ks2.push_back(a);
										            ks2.push_back(b);
										            break;
										        case 2:
										            ks3.push_back(a);
										            ks3.push_back(b);
										            break;
										        case 3:
										            ks4.push_back(a);
										            ks4.push_back(b);
										            break;
										        case 4:
										            ks5.push_back(a);
										            ks5.push_back(b);
										            break;
										        case 5:
										            ks6.push_back(a);
										            ks6.push_back(b);
										            break;
										        case 6:
										            ks7.push_back(a);
										            ks7.push_back(b);
										            break;
										        case 7:
										            ks8.push_back(a);
										            ks8.push_back(b);
										            break;
										        default:
										      	cout<<"PB"<<endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
    }

    // Faire l'intersection des clés potentielles trouvées 
	// La bonne clé apparaît pour chaque chiffré faux utile, donc plus souvent
    // Pour chaque intersection trouvée, ajouter à k16="";
   	int f=0;
	string high="";
	string k_16_bin =""; 
	//SBOX 1
	string arr1[ks1.size()];
	for(auto i = ks1.begin(); i != ks1.end(); i++){
		arr1[f] = *i;
		f++;
	}
	f=0;
	high = mostFrequent(arr1,ks1.size());
	k16 += high;
	k_16_bin += hex_to_bin_26(high);
	high ="";

	//SBOX 2
	string arr2[ks2.size()];
	for(auto i = ks2.begin(); i != ks2.end(); i++){
		arr2[f] = *i;
		f++;
	}
	f=0;
	high = mostFrequent(arr2,ks2.size());
	k16 += high;
	k_16_bin += hex_to_bin_26(high);
	high ="";

	//SBOX 3
	string arr3[ks3.size()];
	for(auto i = ks3.begin(); i != ks3.end(); i++){
		arr3[f] = *i;
		f++;
	}
	f=0;
	high = mostFrequent(arr3,ks3.size());
	k16 += high;
	k_16_bin += hex_to_bin_26(high);
	high ="";

	//SBOX 4
	string arr4[ks4.size()];
	for(auto i = ks4.begin(); i != ks4.end(); i++){
		arr4[f] = *i;
		f++;
	}
	f=0;
	high = mostFrequent(arr4,ks4.size());
	k16 += high;
	k_16_bin += hex_to_bin_26(high);
	high ="";

	//SBOX 5
	string arr5[ks5.size()];
	for(auto i = ks5.begin(); i != ks5.end(); i++){
		arr5[f] = *i;
		f++;
	}
	f=0;
	high = mostFrequent(arr5,ks5.size());
	k16 += high;
	k_16_bin += hex_to_bin_26(high);
	high ="";

	//SBOX 6
	string arr6[ks6.size()];
	for(auto i = ks6.begin(); i != ks6.end(); i++){
		arr6[f] = *i;
		f++;
	}
	f=0;
	high = mostFrequent(arr6,ks6.size());
	k16 += high;
	k_16_bin += hex_to_bin_26(high);
	high ="";
	

	//SBOX 7
	string arr7[ks7.size()];
	for(auto i = ks7.begin(); i != ks7.end(); i++){
		arr7[f] = *i;
		f++;
	}
	f=0;
	high = mostFrequent(arr7,ks7.size());
	k16 += high;
	k_16_bin += hex_to_bin_26(high);
	high ="";

	//SBOX 8
	string arr8[ks8.size()];
	for(auto i = ks8.begin(); i != ks8.end(); i++){
		arr8[f] = *i;
		f++;
	}
	f=0;
	high = mostFrequent(arr8,ks8.size());
	k16 += high;
	k_16_bin += hex_to_bin_26(high);
	high ="";
	// On retrouve la clé K à partir de K16
	find_final_k(plaintext,k_16_bin,right_cipher);
}


int main(int argc, char const *argv[]){ 
	float temps;
    clock_t time1, time2;
    time1 = clock();
     
	string plaintext = "FB0E6B4F70A84367";
	string right_cipher = "3B5FA69AC60EEF7D";
	string wrong_ciphers[] = {"394EA69EC60FEF79","3B4DA6DEC60EEF7D","3B5FA49EC60FEF7D","3A1FA2D8D60FEF7D","3B0FA69ED40EEF7D","3A1FA69AC60CEF7D","3B1FA29AD60EED7D","3A1FA29B861EEF7F","321FA29BD61AEF7D","3B57A69AC61AEF7D","3B5FAE9BC61EEF7D","7B5FB692860AEF7C","7B5FA69BCE1AEF7C","7B5FA69AC646EF7C","3B5FB69AC60EE77C","3B5FB69AC64EEE34","5B5FA69AC24EEE7D","3B7FA69AC60EFF3D","3B5F869AC20EFF7D","2F5FA6BAC20EEF3D","2F5FA79AE20EEE3D","3F5FE69AC62EEF7D","2F5FA69AC60ECF7D","3F5FA79AC70EAF5D","AF5FE69AC70EEB7D","3BDFA68AC70EEF7D","3B5F269AC60EAB7D","3B5EA60AC60EAF6D","3B5EA68A470EEF69","3B5EA69AC68EEF79","3B5AA69AC60E6F7D","3B5FA6DEC60FEFE9"};
	DFA_attack(plaintext,right_cipher,wrong_ciphers);
	
	time2 = clock();
    temps = (float)(time2-time1)/CLOCKS_PER_SEC;
    cout<<"Temps d'exécution :"<<temps<<"s"<<endl;

	return 0;  
}

