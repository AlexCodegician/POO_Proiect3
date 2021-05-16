//
//  Casa.hpp
//  poo3
//
//  Created by Alex Barbu on 23/04/2021.
//  Copyright © 2021 Alex Barbu. All rights reserved.
//

#ifndef Casa_hpp
#define Casa_hpp
#include "Locuinta.hpp"
#include <vector>
#include <iostream>
using namespace std;

class Casa: public Locuinta {
    double suprafataCurte;
    double pretMetruCurte;
    int nrEtaje;
    vector<double> suprafataEtaj;
public:
    Casa(double=0, double=0, double=0, double=0, int=0, const double* = NULL, string = "", double = 0, int = -1);
    Casa(const Casa& other);
    ~Casa() {}
    
    Casa& operator=(Casa&);
    
    double calcChirie() const;
    const string what() const { return "casa"; }
    ostream& afiseaza(ostream&) const;

    friend istream& operator>>(istream& in, Casa& ob);
};
#endif /* Casa_hpp */
