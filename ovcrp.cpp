//Author: Geoff Lord 
//Date:01\07\2020

#include "ovcrp.h"


// Returns Double Ohms = (Power Source in Volts - Forward Volt) / AMPs (I) i.e. R = ( 9 - 3.2 ) / 0.024 = 241.66 ohms
double Covcrp::GetOhms(double SourceVolt, double ForwardVolt, double Amps)
{
	return (SourceVolt - ForwardVolt) / Amps;
}

// Need to right somrthing a little more clever here like showing option variables to select or
// display desired AMPs on the fly based on resistance? - i like this last idea.
// Returns Double: Current = Volt / Resistance
double Covcrp::GetCurrent(double Volt, double Resistance) 
{
	return Volt / Resistance;
}


// Returns Double: Power(Wattage) = Volt(V) * Current( I )
double Covcrp::GetPWattage(double Volt, double Current)
{
	return Volt * Current;
}


// Returns Double: Volt(V) = Current(I) * Resistance
double Covcrp::GetVolt(double Current, double Resistance)
{
	return Current * Resistance;
}


// Returns Double: Resistance = Volts / Current(I)
double Covcrp::GetResistance(double Volt, double Current)
{
	return Volt / Current;
}


int Covcrp::ShowResistorColour()
{
	//Calculate the Resistor codes here

	const char* arrColour[] = {
		"Gold", //Only a multiplyer
		"Silver", //Only a multiplyer
		"Black",
		"Brown",
		"Red",
		"Orange",
		"Yellow",
		"Green",
		"Blue",
		"Violet",
		"Grey",
		"White"
	};

	int arrColour1st[] = { 0,0,0,1,2,3,4,5,6,7,8,9 };
	int arrColour2nd[] = { 0,0,0,1,2,3,4,5,6,7,8,9 };
	int arrColour3rd[] = { 0,0,0,1,2,3,4,5,6,7,8,9 };

	int arrMultiplyer[] = {
		0.10,	//Gold - IS NOT AN INTEGER !!! needs to be a double or float or...
		0.01,	//Silver - IS NOT AN INTEGER !!!
		1,
		10,
		100,
		1000,
		10000,
		100000,
		1000000,
		10000000,
		100000000,
		1000000000};

	const char* arrTolerance[] = {
		"+/- 5%",  //Gold tollerance
		"+/- 10%", //Silver tollerance
		"---",
		"+/- 1%",
		"+/- 2%",
		"---",
		"---",
		"+/- 0.5%",
		"+/- 0.25%",
		"+/- 0.1%",
		"+/- 0.05%",
		"---"
	};

	cout << "\n\n\t\t\t\t\t\t" << "Resistor Colour Chart.\n\n\n";
	int clr1 = 0;
	int ln1 = 0;
	int ln2 = 0;
	int ln3 = 0;
	int ln4 = 0;
	int ln5 = 0;

	//the following won't display all the array details towards the end of the loops - may cause other errors
	for (ln1; ln1 <= 11; ln1++, ln2++, ln3++, ln4++, ln5++, clr1++)
	{
		//The following scope (commented out) is a test to see how to change the text colour.
		/*
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			int txtcolour = 111;

			txtcolour++;
			SetConsoleTextAttribute(hConsole, txtcolour);
			cout << arrColour[clr1] << "\t";
			SetConsoleTextAttribute(hConsole, 15);
		}*/
	
		cout << "\t\t" << arrColour[clr1] << "\t";
		cout << arrColour1st[ln1] << "\t";
		cout << arrColour2nd[ln2] << "\t";
		cout << arrColour3rd[ln3] << "\t";
		if (ln4 >= 9 && ln4 <= 11 )
		{
			cout << arrMultiplyer[ln4] << "\t\t";
		}
		else
		{
			cout << arrMultiplyer[ln4] << "\t\t\t";
		}
		cout << arrTolerance[ln5];

		cout << "\n";
	}
	
	return 0;
}
