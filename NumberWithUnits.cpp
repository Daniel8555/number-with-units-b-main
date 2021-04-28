#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <map>
#include "NumberWithUnits.hpp"

using namespace std;

namespace ariel
{
    void NumberWithUnits::read_units(ifstream &units_file)
    {
        char eq=0;
        double value = 0;
        double num=0;
        string from,to;
        while (units_file >> num >> from >> eq >> value >> to)
        {
            mp[from][to] = value;
            mp[to][from] = num / value;
            for (auto const &i : mp[to])
            {
                 string fir=i.first;
                 double sec=i.second;
                if (i.first != from)
                {
                    mp[from][fir] = mp[from][to] * sec;
                    mp[fir][from] = (double)(num/(mp[from][to] * sec));
                }
            }
                for (auto const &i : mp[from])
            {
                string fir=i.first;
                double sec=i.second;
                 if (i.first != to)
                {
                    mp[to][fir] =  mp[to][from] * sec;
                    mp[fir][to] = (double)(num/(mp[to][from]*sec));
                }

             }
        }
    }

    static double convert(const string &a, const string &b, double c)
    {
        if(a==b){return c;}
         if (a != b&& mp[a][b]!=0){return c * mp[a][b];}
            throw invalid_argument("isn't exist");        
 
    }
    NumberWithUnits::NumberWithUnits(double num, const string &t)
    {
            if(mp.count(t)==0){ throw invalid_argument("isn't exist");}
              NumberWithUnits::num=num;
               NumberWithUnits::t=t;
    }

    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &num1) const
    {
        double converted = convert(num1.t, this->t, num1.num);
        return NumberWithUnits(this->num + converted, this->t);
    }

    NumberWithUnits NumberWithUnits::operator-() const
    {
        return NumberWithUnits(-this->num, this->t);
    }
    NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &a) const
    {
        return NumberWithUnits((this->num - (convert(a.t, this->t, a.num))), this->t);
    }
    NumberWithUnits NumberWithUnits::operator+() const
    {
        return NumberWithUnits{this->num, this->t};

    }
    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &other)
    {
        this->num += convert(other.t, this->t, other.num);
        return *this;
    }

    NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &other)
    {
        this->num -= convert(other.t, this->t, other.num);
        return *this;
    }
    NumberWithUnits &NumberWithUnits::operator*=(const NumberWithUnits &other)
    {
        this->num *= convert(other.t, this->t, other.num);
        return *this;
    }
    bool operator<(const NumberWithUnits &num, const NumberWithUnits &num1)
    {
        return (num.num < convert(num1.t, num.t, num1.num));
    }
    bool operator>(const NumberWithUnits &num, const NumberWithUnits &num1)
    {

        return (num.num > convert(num1.t, num.t, num1.num));
    }

    bool operator!=(const NumberWithUnits &num, const NumberWithUnits &num1)
    {
        return (num.num != convert(num1.t, num.t, num1.num));
    }
    bool operator<=(const NumberWithUnits &num, const NumberWithUnits &num1)
    {
        return (num.num <= convert(num1.t, num.t, num1.num));
    }
    bool operator>=(const NumberWithUnits &num, const NumberWithUnits &num1)
    {
        return ((double)(num.num - convert(num1.t, num.t, num1.num))>=0);
    }

    bool operator==(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        const double epsilon=0.0001;
        return ((std::abs(a.num - convert(b.t, a.t, b.num)))<=epsilon);
    }
    ostream &operator<<(ostream &out, const NumberWithUnits &n)
    {
        out << n.getn() << "[" << n.gett() << "]";
        return out;
    }


    istream &operator>>(istream &in, NumberWithUnits &n)
    {
        string str;
        in>>n.num;
        getline(in, str, ']'); 
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        str.erase(remove(str.begin(), str.end(), '['), str.end());
        str.erase(remove(str.begin(), str.end(), ']'), str.end());
        n.t=str;
        if (mp.find(str) == mp.end())
        {
            throw invalid_argument("isn't exist");
        }
        return in;

    }

}