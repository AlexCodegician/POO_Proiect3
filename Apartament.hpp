//
//  Apartament.hpp
//  poo3
//
//  Created by Alex Barbu on 23/04/2021.
//  Copyright © 2021 Alex Barbu. All rights reserved.
//

#ifndef Apartament_hpp
#define Apartament_hpp
#include "Locuinta.hpp"
#include <iostream>
using namespace std;

class Apartament : public Locuinta
{
    int etaj;
public:
    Apartament (double=0, double=0, int=0, string = "", double = 0, int = -1);
    Apartament (const Apartament& other);
    ~Apartament() {}
    
    Apartament& operator=(Apartament&);
    
    double calcChirie() const;
    const string what() const { return "apartament"; }
    
    ostream& afiseaza(ostream&) const;
    
    friend istream& operator>>(istream& in, Apartament& ob);
};
#endif /* Apartament_hpp */
