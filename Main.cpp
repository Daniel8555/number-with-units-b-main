#include "NumberWithUnits.hpp"
// #include <stdio.h>
using namespace std;
using namespace ariel;
#include <iostream>
// void update_table(){
//     ofstream myfile;
//     myfile.open ("myTestFile.txt");
//     myfile << "1 km = 1000 m" << endl;
//     myfile << "1 m = 100 cm" << endl;
//     myfile << "1 kg = 1000 g" << endl;
//     myfile << "1 ton = 1000 kg" << endl;
//     myfile << "1 hour = 60 min" << endl;
//     myfile << "1 min = 60 sec" << endl;
//     myfile << "1 day = 24 hour" << endl;
//     myfile << "1 month = 30 day" << endl;
//     myfile << "1 year = 12 month" << endl;   
//     myfile.close(); 
//     ifstream units_file{"myTestFile.txt"};
//     NumberWithUnits::read_units(units_file);
// }
// void update_table(string s){
//     ofstream myfile;
//     myfile.open ("myTestFile.txt");
//     myfile << s << endl;
//     myfile.close(); 
//     ifstream units_file{"myTestFile.txt"};
//     NumberWithUnits::read_units(units_file);
// }
int main()
{
    

    // ariel::NumberWithUnits a{2, "km"}; 
    // cout<< 2 * ariel::NumberWithUnits(-7, "r_hour") + ariel::NumberWithUnits(7, "r_hour");
    // // 2 kilometers
    // cout << a << endl;                 // Prints "2[km]".
    // cout << (-a) << endl;              // Prints "-2[km]"
    // cout << (3 * a) << endl;           // Prints "6[km]"

    // ariel::NumberWithUnits b{300, "m"}; // 300 meters
    // cout << (a + b) << endl;            // Prints "2.3[km]". Note: units are determined by first number (a).
    // cout << (b - a) << endl;            // Prints "-1700[m]". Note: units are determined by first number (b).

    // cout << boolalpha;                                        // print booleans as strings from now on:
    // cout << (a > b) << endl;                                  // Prints "true"
    // cout << (a <= b) << endl;                                 // Prints "false"
    // cout << (a == ariel::NumberWithUnits{2000, "m"}) << endl; // Prints "true"
    // cout << (a != a) << endl;

    // istringstream sample_input{"700 [ kg ]"};
    // sample_input >> a;
    // cout << a << endl;   // Prints "700[kg]"
    // cout << (a += ariel::NumberWithUnits{1, "ton"}) << endl;  // prints "1700[kg]"
    // cout << a << endl;   // Prints "1700[kg]". Note that a has changed.
}
