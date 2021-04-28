#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <string>
#include <utility>
using namespace std;

namespace ariel
{
 
    static map<string, map<string, double>> mp;
    class NumberWithUnits
    {
    private:
        double num;
        string t;

    public:
        NumberWithUnits()
        {
            ;
        }
         ~NumberWithUnits(){}
        NumberWithUnits(double num, const string &t);

        static void read_units(ifstream &units_file);

        double getn() const
        {
            return num;
        }
        std::string gett() const
        {
            return t;
        }

        NumberWithUnits operator+() const;
        NumberWithUnits operator+(const NumberWithUnits &num1) const;
        friend bool operator==(const NumberWithUnits &a, const NumberWithUnits &b);
        friend std::ostream &operator<<(ostream &out, const NumberWithUnits &n);
        friend std::istream &operator>>(istream &in, NumberWithUnits &n);
        friend bool operator>(const NumberWithUnits &num, const NumberWithUnits &num1);
        NumberWithUnits operator-(const NumberWithUnits &a) const;
        NumberWithUnits operator-() const;
        NumberWithUnits &operator+=(const NumberWithUnits &other);
        NumberWithUnits &operator-=(const NumberWithUnits &other);
        NumberWithUnits &operator*=(const NumberWithUnits &other);
        friend bool operator!=(const NumberWithUnits &num, const NumberWithUnits &num1);
        friend bool operator<(const NumberWithUnits &num, const NumberWithUnits &num1);
        friend bool operator>(const NumberWithUnits &num, const NumberWithUnits &num1);
        friend bool operator<=(const NumberWithUnits &num, const NumberWithUnits &num1);
        friend bool operator>=(const NumberWithUnits &num, const NumberWithUnits &num1);
    

        NumberWithUnits operator++(int x)
        {
            NumberWithUnits temp = *this;
            num++;
            return temp;
        }
             NumberWithUnits &operator++()
        {
            num++;
            return *this;
        }
        NumberWithUnits operator--(int x)
        {
            NumberWithUnits temp = *this;
            num--;
            return temp;
        }
            NumberWithUnits &operator--()
        {

            num--;
            return *this;
        }

        friend const NumberWithUnits operator*(const NumberWithUnits &num, const double &copy)
        {
            return NumberWithUnits(num.num * copy, num.t);
        }
        friend const NumberWithUnits operator*(const double &copy, const NumberWithUnits &num)
        {
            return NumberWithUnits(num.num * copy, num.t);
        }

   
    };
}