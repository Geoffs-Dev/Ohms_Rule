//Author: Geoff Lord 
//Date:01\07\2020

#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
using namespace std;

class Covcrp
{
public:
	//Voltage source.
	double m_voltage;
	//Post voltage (The tail end voltage after it has passed through the components').
	double m_forwardVoltage;
	//The flow of electricity (AMPs).
	double m_current;
	//The restriction of current(I) measured in Ohms.
	double m_resistance;
	//Power.
	double m_wattage;
	//Ohms not limited to resistors - may require additional member variables to avoid confusion.
	double m_ohms;

	// The resistance = (Power Source volts - Forward Volt) / AMPs i.e. R = ( 9 - 3.2 ) / 0.024 = 241.66 ohms
	double GetOhms(double SourceVolt, double ForwardVolt, double Amps);
	// Returns Double: Current = Volt / Resistance
	double GetCurrent(double Volt, double Resistance);
	// Returns Double: Power(Wattage) = Volt(V) X Current(I) [AMPs]
	double GetPWattage(double Volt, double Current);
	// Returns double: Volt(V) = Current(I) X Resistance
	double GetVolt(double Current, double Resistance);
	// Returns double: Resistance = Volts / Current(I) [AMPs]
	double GetResistance(double Volt, double Current);

	// More complex calculation a variable passed to CalcResistance must be first set to GetOhms(double Sv, double Fv, double Amps)
	int ShowResistorColour();
};

