#include <iostream>
#include "mystring.h"																	//includes mystring.h that holds the class my_string implemented on my_string.cpp used in main.cpp and 
#include <fstream>																		//allows us to use ifstream object for opening input.dat
using namespace std;

int main() 
{
	hw4::my_string S1,S2,S3,S4,STotal;													//object of class my_string called S1,S2,S3,S4, Stotal will have al the strings in on big string
	string target;																		//will be the target being 
	int width;																			//variable will hold the width input from the user
	cout << "Hello Please enter the width desired to format this paragraph" << endl;	//greets the user and asks for input on the width variable
	cin >> width;																		//user will input a int value for width 

	ifstream inputFile;																	//stream object named inputFile
	inputFile.open("input.txt");														//inputFile will open input.dat 

	if (inputFile.fail())
	{
		cout << "Error Opening input.dat Terminating Program!!" << endl;				//if statement that will terminate the program if input.dat was able to open
		exit(1);																		//will terminate the program
	}
	
	hw4::getline(inputFile,S1);															//will read in data from input.dat through stream file and will place it in *sequence 
	hw4::getline(inputFile,S2);															//eaach instance S1,S2,S3,S4 will have a line from the input file
	hw4::getline(inputFile,S3);
	hw4::getline(inputFile,S4);
	


	STotal += S1;																		/////////////////////////////////////////////////////////////////////////
	STotal += S2;																		// All strings will	will be added together  						   //
	STotal += S3;																		// This will combine all strings S1-S4 into one bi string called STotal//
	STotal += S4;																		/////////////////////////////////////////////////////////////////////////

	//will seperate each line into the users desired width, using the variable width
	STotal.insert(width);																//STotal.insert will insert hyphens after X amount of chars in the dynamic array if theres 
	STotal.formatData(width);															//this Function is called to format data to the users width it will search for hyphens and will add endline characters
	cout << STotal.length() << endl;
																						
																						////////////////////////////////////////////////////////////////////////////////////
   //will be used for Error checking while testing 
	fstream outputFile;																	//outputFile will recieve input from STotal class
	outputFile.open("output.txt");														//opens file were writing to output.dat
	outputFile << STotal;																//will put STotal Sequence in outputFile
	outputFile.close();																	//closes outputFile that has output.dat

   ////////////////////////////////////////////////////////////////////////////////////
	
	
	inputFile.close();																	//will close the inputFile that holds stream object input.dat
	
	////////////////////////////////////////////////////////////////////////////////////
	//WILL DESTRUCT ALL DYNAMIC MEMORY!!!											 //
	S1.~my_string();																 //
	S2.~my_string();																 //
	S3.~my_string();																 //
	S4.~my_string();																 //
	STotal.~my_string();															 //
	cout << "All Dynamic memory was destroyed" << endl;								 //
	////////////////////////////////////////////////////////////////////////////////////
	return 0;
}