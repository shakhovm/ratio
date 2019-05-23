//
// Created by user on 22.05.2019.
//

#ifndef DRIB_RATIO_H
#define DRIB_RATIO_H

#endif //DRIB_RATIO_H
#include <iostream>
#include <sstream>

class Ratio {

    int reduce();
public:
    int numenator;
    int denominator;
    Ratio operator*=(const Ratio& ratio);
    Ratio operator*=(int integer);
    Ratio operator+=(const Ratio& ratio);
    Ratio operator+=(int integer);
    Ratio& operator++();
    Ratio operator++(int);
    Ratio operator-=(const Ratio& ratio);
    Ratio operator-=(int integer);
    Ratio& operator--();
    Ratio operator--(int);
    Ratio operator/=(const Ratio& ratio);
    Ratio operator/=(int integer);
    inline bool operator<(const Ratio& ratio);
    inline bool operator>(const Ratio& ratio);
    inline bool operator<=(const Ratio& ratio);
    inline bool operator>=(const Ratio& ratio);
    inline bool operator==(const Ratio& ratio);
    inline bool operator!=(const Ratio& ratio);
    void reverse();
    float to_ten();
    Ratio(int num, int den);
};

int Ratio::reduce()
{
    if(numenator < 0 && denominator < 0) {
        numenator = abs(numenator);
        denominator = abs(denominator);
    } else if(numenator > 0 && denominator < 0)
    {
        numenator = -numenator;
        denominator = abs(denominator);
    }
    for(int i = abs(denominator); i >= 1; i--)
    {
        if(abs(numenator) % i == 0 && abs(denominator) % i == 0)
        {
            numenator /= i;
            denominator /= i;
            break;
        }
    }
    return 0;
}

void Ratio::reverse()
{
    if(numenator == 0)
    {
        return;
    }
    int new_den = abs(numenator);
    int new_num;
    if(numenator < 0)
        new_num = -denominator;
    else {new_num = denominator;}
    numenator = new_num;
    denominator = new_den;
}

inline Ratio negative(Ratio ratio)
{
    ratio.numenator = -ratio.numenator;
    return ratio;
}

Ratio Ratio::operator*=(const Ratio &ratio)
{
    numenator *= ratio.numenator ;
    denominator *= ratio.denominator ;
    reduce();
    return *this;
}

Ratio Ratio::operator*=(int integer)
{
    numenator*= integer;
    reduce();
    return *this;
}
inline Ratio operator*(Ratio ratio1, const Ratio& ratio2)
{
    return ratio1 *= ratio2;
}
inline Ratio operator*(Ratio ratio, int integer)
{
    return ratio *= integer;
}
inline Ratio operator*(int integer, Ratio ratio)
{
    return ratio *= integer;
}
Ratio Ratio::operator+=(const Ratio &ratio)
{
    numenator = numenator*ratio.denominator + ratio.numenator*denominator;
    denominator *= ratio.denominator;
    reduce();
    return *this;
}
inline Ratio operator+(Ratio ratio1, const Ratio& ratio2)
{
    return ratio1 += ratio2;
}
Ratio Ratio::operator+=(int integer)
{
    numenator += integer*denominator;
    reduce();
    return *this;
}

inline Ratio operator+(Ratio ratio, int integer)
{
    return ratio += integer;
}
inline Ratio operator+(int integer, Ratio ratio)
{
    return ratio += integer;
}


Ratio& Ratio::operator++()
{
    *this += 1;
    return *this;
}
Ratio Ratio::operator++(int)
{
    *this += 1;
    return *this;
}

Ratio Ratio::operator-=(const Ratio& ratio)
{
    numenator = numenator*ratio.denominator - ratio.numenator*denominator;
    denominator *= ratio.denominator;
    reduce();
    return *this;
}

Ratio Ratio::operator-=(int integer)
{
    numenator -= integer*denominator;
    reduce();
    return *this;
}

inline Ratio operator-(Ratio ratio1, const Ratio& ratio2)
{
    return ratio1 -= ratio2;
}

inline Ratio operator-(Ratio ratio, int integer)
{
    return ratio -= integer;
}

inline Ratio operator-(int integer, Ratio ratio)
{
    return negative(ratio -= integer);
}

Ratio& Ratio::operator--()
{
    *this -= 1;
    return *this;
}

Ratio Ratio::operator--(int)
{
    *this -= 1;
    return *this;
}

Ratio Ratio::operator/=(const Ratio& ratio)
{
    numenator *= ratio.denominator;
    denominator *= ratio.numenator;
    reduce();
    return *this;
}

Ratio Ratio::operator/=(int integer)
{
    denominator *= integer;
    reduce();
    return *this;
}

inline Ratio operator/(Ratio ratio1, const Ratio &ratio2)
{
    return ratio1 /= ratio2;
}

inline Ratio operator/(Ratio ratio, int integer)
{
    return ratio /= integer;
}

Ratio operator/(int integer, Ratio ratio)
{
    ratio.reverse();
    return integer*ratio;
}

inline bool Ratio::operator<(const Ratio& ratio)
{
    return numenator * ratio.numenator < ratio.numenator*denominator;
}

inline bool Ratio::operator>(const Ratio& ratio)
{
    return numenator * ratio.numenator > ratio.numenator*denominator;
}

inline bool Ratio::operator==(const Ratio& ratio)
{
    return numenator == ratio.numenator && denominator == ratio.denominator;
}

inline bool Ratio::operator!=(const Ratio& ratio)
{
    return numenator != ratio.numenator || denominator != ratio.denominator;
}

inline bool Ratio::operator<=(const Ratio& ratio)
{
    return *this < ratio ||*this == ratio;
}

inline bool Ratio::operator>=(const Ratio& ratio)
{
    return *this > ratio || *this == ratio;
}



float Ratio::to_ten()
{
    float x = static_cast<float>(numenator) / static_cast<float>(denominator);
    return x;
}

Ratio::Ratio(int num, int den):
        numenator(num), denominator(den)
{
    reduce();
}

std::ostream& operator<<(std::ostream& os, const Ratio& ratio) {
    std::stringstream ss ;
    ss << ratio.numenator;
    if(ratio.denominator != 1)
        ss << '/' << ratio.denominator;
    os << ss.str ();
    return os;
}
