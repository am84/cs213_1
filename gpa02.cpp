//-----Include required headers here-----
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

//-----End of headers-----


//-----Add new functions here(if any)-----

int xor_two_chars(const char* a, const char* b){
	int a_int = atoi(a);
	int b_int = atoi(b);

	int xor_a_b = a_int ^ b_int;
	return xor_a_b;
}



//-----New functions end here-----

/* Question : Function to convert a given binary string to 
   gray code string as explained in the problem description. */
string binarytoGray(string binary) {
	// Write your code below this line.
	string toGray;
	for (string::iterator it = binary.begin() ; it != binary.end(); ++it){
		if (it == binary.begin()){
			toGray.push_back(*it);
		}else {
		char prevChar = *(it - 1);
		char currChar = *it;
		int xor_curr_prev = xor_two_chars(&currChar,&prevChar);
		stringstream ss;
		ss << xor_curr_prev;
		toGray.append(ss.str());
		}
	}

	return toGray;
}

/* Question : Function to convert a gray code string to 
   binary string as explained in the problem description. */
string graytoBinary(string gray) {
	// Write your code below this line.
	string toBinary;
	string::iterator toBinary_end;
	for(string::iterator it = gray.begin(); it !=gray.end(); ++it){
		char last_char;
		if(it == gray.begin()){
			toBinary.push_back(*it);
			last_char = *it;
		} 
		else {
			char curr_gray_char = *it;
			int curr_char_int = atoi(&curr_gray_char);
			if (curr_char_int == 0){
				toBinary.push_back(last_char);
			} else {
				int last_char_int = atoi(&last_char);
				if (last_char_int == 0){
					toBinary.append("1");
				}else {
					toBinary.append("0");
				}
			}
			cout << curr_gray_char << "," << toBinary << endl;
		}
		last_char = *(toBinary.end() - 1);

	}
	return toBinary;
}

int main(int argc, char** argv){
	//string tBin = "0011";
	//string tGray = "01101";

	//cout << "BinaryToGray " << tBin << ' ' << binarytoGray(tBin) << '\n';
	//cout << "GraytoBinary " << tGray << ' ' << graytoBinary(tGray) << '\n';
	
	string inputString;
	cout << "Enter string: ";
	cin >> inputString;
	cout << binarytoGray(inputString) << endl;
	cout << graytoBinary(inputString) << endl;
	


	return 0;
}
