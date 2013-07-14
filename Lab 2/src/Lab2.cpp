//============================================================================
// Name        : Lab2.cpp
// Author      : Ricky Mutschlechner
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
double ftoc(double);
double ctof(double);

int main() {
	double temperaturesInitialCelsius[5] = {39.5, 10.8, 22.6, 18.9, 15.7};
	double temperaturesFahrenheit[5];
	double temperaturesFinalCelsius[5];

	cout << "\nPrinting Temperatures in Celsius: " << endl;
	for(int i = 0; i < 5; i++)
		cout << temperaturesInitialCelsius[i] << " ";

	cout << "\nConverting to Fahrenheit..." << endl;
	for(int i = 0; i < 5; i++)
		temperaturesFahrenheit[i] = ftoc(temperaturesInitialCelsius[i]);

	cout << "\nPrinting Temperatures in Fahrenheit: " << endl;
	for(int i = 0; i < 5; i++)
		cout << temperaturesFahrenheit[i] << " ";

	cout <<"\nConverting back to Celsius..." << endl;
	for(int i = 0; i < 5; i++)
		temperaturesFinalCelsius[i] = ctof(temperaturesFahrenheit[i]);

	cout << "\nPrinting Temperatures in Celsius Again: " << endl;
	for(int i = 0; i < 5; i++)
		cout << temperaturesFinalCelsius[i] << " ";
}

double ftoc(double temperature){
	return (temperature * 1.8) + 32;
}

double ctof(double temperature){
	return (temperature - 32) * (5.0/9.0);
}
