//-----Include required headers here-----
#include <iostream>
#include <string>
#include <stdlib.h>

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
		toGray.append(to_string(xor_curr_prev));
		}
	}

	return toGray;
}

/* Question : Function to convert a gray code string to 
   binary string as explained in the problem description. */
string graytoBinary(string gray) {
	// Write your code below this line.
	string toBinary;
	for(string::iterator it = gray.begin(); it !=gray.end(); ++it){
		if(it == gray.begin()){
			toBinary.push_back(*it);
		} 
		else {
			char curr_char = *it;
			int curr_char_int = atoi(&curr_char);
			if (curr_char_int == 0){
				char prevChar = *(it - 1 );
				toBinary.push_back(prevChar);
			} else {
				char prevChar = *(it - 1);
				string invert_prevChar = to_string(not(atoi(&prevChar)));
				toBinary.append(invert_prevChar);
			}
		}

	}
	return toBinary;
}

int main(int argc, char** argv){
	string tBin = "0011";
	string tGray = "01101";

	cout << "BinaryToGray " << tBin << ' ' << binarytoGray(tBin) << '\n';
	cout << "GraytoBinary " << tGray << ' ' << graytoBinary(tGray) << '\n';
	return 0;
}
