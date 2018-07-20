//============================================================================
// Name        : intToEng.cpp
// Author      : Mina Tadros
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

string integerToString(int);
string unitsString(int);
string tensString(int);
string hundredsString(int);
string sign = "positive";

int main() {

	int inputValue;
	bool clear = false;

	do{
	inputValue = 0;
	cout << "Please input an Integer value between -2 billion to 2 billion: ";
	cin >> inputValue;
	cout <<endl;

	if (cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "!!! It is not a number" << endl;
		clear = false;
	}else if(inputValue <= 2147483647 || inputValue <= -2147483647){
		clear = true;
	}else{
		cout << "!!! It is not a number within range" << endl;
		clear = false;
	}
	} while(clear == false);

	if(inputValue <= -1){
	sign = "negative";
	inputValue *= -1;
	}

	if(sign == "negative"){
		cout << "negative" + integerToString(inputValue);
	}else{
		cout << integerToString(inputValue);
	}


}

string integerToString(int x){

	int length = to_string(x).length();
	int remainder = length % 3;

	if(remainder == 1){

		if(length == 1){

			if(x == 0){
				return "zero";
			}else{
				return unitsString(x);
			}

		}else if(length == 4){

			return unitsString((x/1000)%10) + " thousand" + hundredsString(x%1000);

		}else if(length == 7){

			return unitsString((x/1000000)%10) + " million" + hundredsString((x/1000)%1000) + " thousand" + hundredsString(x%1000);

		}else{
			return unitsString((x/1000000000)%10) + " billion" + hundredsString((x/1000000)%1000) + " million" + hundredsString((x/1000)%1000) + " thousand" + hundredsString(x%1000);
		}
	}else if(remainder == 2){

		if(length == 2){
			return tensString(x);
		}else if(length == 5){
			return tensString((x/1000)%100) + " thousand" + hundredsString(x%1000);
		}else{
			return tensString((x/1000000)%100) + " million" + hundredsString((x/1000)%1000) + " thousand" + hundredsString(x%1000);
		}

	}else{
			if(length == 3){
				return hundredsString(x);
			}else if(length == 6){
				return hundredsString((x/1000)%1000) + " thousand" + hundredsString(x%1000);
			}else{
				return hundredsString((x/1000000)%1000) + " million" + hundredsString((x/1000)%1000) + " thousand" + hundredsString(x%1000);
			}

	}

}

string unitsString (int x){

	switch(x){
	case 1:
		return " one";
	case 2:
		return " two";
	case 3:
		return " three";
	case 4:
		return " four";
	case 5:
		return " five";
	case 6:
		return " six";
	case 7:
		return " seven";
	case 8:
		return " eight";
	case 9:
		return " nine";
	default:
		return "";
	}
}

string tensString (int x){


	if( x >= 20){

		switch((x/10)%10){
		case 2:
			return " twenty" + unitsString(x%10);
		case 3:
			return " thirty" + unitsString(x%10);
		case 4:
			return " forty" + unitsString(x%10);
		case 5:
			return " fifty" + unitsString(x%10);
		case 6:
			return " sixty" + unitsString(x%10);
		case 7:
			return " seventy" + unitsString(x%10);
		case 8:
			return " eighty" + unitsString(x%10);
		case 9:
			return " ninety" + unitsString(x%10);
		default:
			return "" + unitsString(x%10);
		}

	}else{

		switch(x){
			case 10:
				return " ten";
			case 11:
				return " eleven";
			case 12:
				return " twelve";
			case 13:
				return " thirteen";
			case 14:
				return " fourteen";
			case 15:
				return " fifteen";
			case 16:
				return " sixteen";
			case 17:
				return " seventeen";
			case 18:
				return " eighteen";
			case 19:
				return " nineteen";
			default:
				return "";

		}

	}

}

string hundredsString(int x){

	switch((x/100)%10){
		case 1:
			return " one hundred" + tensString(x%100);
		case 2:
			return " two hundred" + tensString(x%100);
		case 3:
			return " three hundred" + tensString(x%100);
		case 4:
			return " four hundred" + tensString(x%100);
		case 5:
			return " five hundred" + tensString(x%100);
		case 6:
			return " six hundred" + tensString(x%100);
		case 7:
			return " seven hundred" + tensString(x%100);
		case 8:
			return " eight hundred" + tensString(x%100);
		case 9:
			return " nine hundred" + tensString(x%100);
		default:
			return "" + tensString(x%100);

	}

}







