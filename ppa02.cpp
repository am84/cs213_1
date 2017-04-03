//-----Include required headers here-----
#include <iostream>
#include <cmath>

using namespace std;

//-----End of headers-----

//-----Don't change/delete structs-----
struct rational {
	int numerator;
	int denominator;
};
//-----Structs end here


int exact(int numerator, int denominator){
	
	cout << numerator << "," << denominator << endl;
	int remainder = numerator%denominator;
	if (remainder == 0){
		return denominator;
	}else {
		return exact(denominator, remainder);	
	}
}


/*Question: Reduce the number 'inputrational' to its lowest form and store it in 'outputrational'
  struct rational *inputrational  : Actual rational number to be reduced
  struct rational *outputrational : Variable to store the rational number in its lowest form */
void reduce(struct rational *inputrational, struct rational *outputrational) {
	//Write your solution code below this line
	
	int num = inputrational->numerator;
	int den = inputrational->denominator;

	int divisor = exact(num, den);

	outputrational->numerator = num / divisor;
	outputrational->denominator = den / divisor;

}

/* Question: Check whether both the rational numbers obtained in the lowest form are equal or not. 
   Retrun true or false accordingly
 */
bool isEqual(struct rational num1, struct rational num2) {
	//Write your solution code below this line


}

int main(int argc, char** argv){
	
	int a, b;
	cout << "Enter data:" << endl;
	cin >> a >> b;
	cout << a << b << endl;
	rational test, output;
	
	test.numerator = a;
	test.denominator = b;

	reduce(&test, &output);
	cout << output.numerator << "," << output.denominator << endl;
	return 0;
}
