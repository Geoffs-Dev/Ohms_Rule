// Ohms Rule.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Author: Geoff Lord 
//Date:01\07\2020

//#include <iostream>
#include "ovcrp.h"

int main()
{
    Covcrp elecCalc; //using two objects for the same purpose... ??? Change this!!!
    int ch_exit = 0;
    int key_choices = 0;
    int f_loop = 0;

    const char* ch_array_menu[] = {
        "Q - Exit",
        "O - Ohms",
        "V - Voltage",
        "C - Current",
        "R - Resistance",
        "P - Power",
        "S - Show resistor chart"
    };
    //add a do while loop for exit

    cout << "\n\n\t\t\t\t  Welcome to 'Honey Combe' created by @Geoff Lord\n\n\n\n\n";

    for (f_loop; f_loop <=6; f_loop++)
    {
        cout << "\t\t" << ch_array_menu[f_loop] << "\t\t";
        if (f_loop == 2 || f_loop == 5)
        {
            cout << "\n\n\n";
        }
        
    }
    cout << "\n\n\t\tPlease enter your choice:";
    
    do
    {
        
        key_choices = _getch();
        //cout << "\n\n";
        switch (toupper(key_choices))
        {
        case 'Q': //Quit
            cout << "\n\nThank you for using 'Honey Combe!' \nPlease come back soon.\n\n";
            exit(0);
            break;

        case 'O':
            cout << "\nPlease enter the source voltage:";
            cin >> elecCalc.m_voltage;
            cout << "\nPlease enter the forward voltage:";
            cin >> elecCalc.m_forwardVoltage;
            cout << "\nPlease enter the current(AMPs):";
            cin >> elecCalc.m_current;
            
            cout << "\n(Calculation " << elecCalc.m_voltage << " - " << elecCalc.m_forwardVoltage << ")"
                    << " / " << elecCalc.m_current << "\n\t\t\t\t: "
                    << elecCalc.GetOhms (elecCalc.m_voltage, elecCalc.m_forwardVoltage, elecCalc.m_current) << " Ohms";

            cout << "\n\n\t\tPlease enter your choice:";
            break;
        
        case 'V':
            cout << "\n\t\tVoltage(V):";
            cout << "\n\n\t\tPlease enter your choice:";
            break;

        case 'C': //Need to be more clever to work out what i really need respectively........
            //Voltage / resistance
            cout << "\n\t\tCurrent(I) (AMPs):";
            cout << "\n\t\tHow many Volts?:";
            cin >> elecCalc.m_voltage;
            cout << "\n\t\tHow many Ohms (Resistence)?:";
            cin >> elecCalc.m_resistance;
            cout << "\t\t\tAMPs = :" << elecCalc.GetCurrent(elecCalc.m_voltage, elecCalc.m_resistance) << "\n\n";
            cout << "Please enter your choice:";
            break;

        case 'R':
            cout << "\n\t\tResistence(Ohms)";
            cout << "\n\n\t\tPlease enter your choice:";
            break;

        case 'P':
            cout << "\n\t\tPower (WATTS): \'Volts x Current\'";
            cout << "\n\n\t\tHow many Volts?:";
            cin >> elecCalc.m_voltage;
            cout << "\n\t\t\tCurrent (AMPs)?:";
            cin >> elecCalc.m_current;
            cout << "\n WATTS = ";
            cout << elecCalc.GetPWattage(elecCalc.m_voltage,elecCalc.m_current) << "\n";
            cout << "\t\t\tPlease enter your choice:";
            break;

        case 'S':
            elecCalc.ShowResistorColour();
            break;
        }

        
       
    } while (ch_exit != 'Q');
 
}
