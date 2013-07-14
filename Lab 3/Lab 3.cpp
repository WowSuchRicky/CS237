//
//  Lab 3
//  Test Project - Xcode
//
//  Created by Ricky Mutschlechner on 1/30/13.
//  Authors: Ricky Mutschlechner, Erin McNeil
//

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

bool magicSquareCheck(int);
bool duplicateCheck(string);

int main(void) {

	int start = 276000000; //This is the starting number - we could start from 123456789 but it would take days to find the actual value.

	int counter = 0; // start a counter for square checks.

	while(!magicSquareCheck(start)){
		start++;
		cout << start << endl;
		counter++;
	}

    //This stringstream business I learned from cplusplus.com's tutorial on stringstreams, because atoi() and itoa() would not work.
	stringstream sa;
	sa << start;
	string square = sa.str();


    //I am printing it this way in lieu of using a 2D array for simplicity's sake. 
    cout << "The 3x3 Magic Square Is: " << endl;
	cout << "|" << square[0] << square[1] << square[2]<< "|" << endl;
	cout << "|" << square[3] << square[4] << square[5]<< "|" << endl;
	cout << "|" << square[6] << square[7] << square[8]<< "|" << endl;
	cout << "Tested " << counter << " squares to see if they are magic or not!" << endl;
	system("PAUSE"); //For some compilers/runtimes, without this, the console just goes away upon completion.
}


//This function checks the current square (inputted as 123456789 format for a 3x3 square) to see if it is "magic"

bool magicSquareCheck(int squareToInt){
	stringstream ss;
	ss << squareToInt;
	string squareToString = ss.str(); //converting the square value (ie. 123456789) to a String for index manipulation purposes

	for(int i = 0; i < 9; i++){
		if (squareToString[i]=='0')  //Make sure that there is no 0 in the square, as that is not allowed.
			return false;
	}


    if(duplicateCheck(squareToString)) //Checks to see if there are any duplicate numbers within the square
        return false;

	int x[9]; //This is for checking to see if the square/number is actually "magic".

	for(int i=0; i<9; i++){
		x[i] = squareToString[i]; //assigns the temp array x to the current square being checked.
	}

        //159 is our magic sum (15) but in ASCII, due to converting the number to a string / char *
    	if (x[0] + x[1] + x[2] == 159)
    		if (x[3] + x[4] + x[5] == 159)
    			if(x[6] + x[7] + x[8] == 159)
    				if(x[0] + x[3] + x[6] == 159)
    					if(x[1] + x[4] + x[7] == 159)
    						if(x[2] + x[5] + x[8] == 159)
    							if(x[0] + x[4] + x[8] == 159)
    								if(x[6] + x[4] + x[2] == 159)
                                        return true;

	return false;
}


bool duplicateCheck(string squareToString){
    for(int i = 0; i < 8; i++){
		for(int a = i+1; a < 9; a++){
			if (squareToString[i] == squareToString[a]){
				return true;
			}
		}
	}
    return false;
}

