//
//  Locuinta.hpp
//  poo3
//
//  Created by Alex Barbu on 23/04/2021.
//  Copyright © 2021 Alex Barbu. All rights reserved.
//

#ifndef Locuinta_hpp
#define Locuinta_hpp
#include <iostream>
#include <string>
#include "MyException.hpp"
using namespace std;

class Locuinta
{
protected:
    string numeClient;
    double suprafata;
    double discount;
    double pretMetru;
    int index;
    
    Locuinta(int, double, double, string = "" ,double = 0);
    Locuinta(const Locuinta& other);
    
    Locuinta& operator=(Locuinta&);
    
    virtual const string what() const=0;
    
    friend istream& operator>>(istream& in, Locuinta& ob);
    friend ostream& operator<<(ostream& out, const Locuinta& ob);
public:
    virtual double calcChirie() const=0;
    void setIndex(int index) {this->index=index;}
    virtual ostream& afiseaza(ostream&) const;
    void brief() const
    {
        cout << this->numeClient << "(" << this->suprafata << ")\n";
    }
    virtual ~Locuinta() {}
};

#endif /* Locuinta_hpp */
