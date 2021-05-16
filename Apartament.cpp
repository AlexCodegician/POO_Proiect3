//
//  Apartament.cpp
//  poo3
//
//  Created by Alex Barbu on 23/04/2021.
//  Copyright © 2021 Alex Barbu. All rights reserved.
//

#include "Apartament.hpp"
using namespace std;

Apartament::Apartament (double suprafata,double pretMetru, int etaj, string numeClient, double discount, int index):  Locuinta(index, suprafata, pretMetru, numeClient, discount), etaj(etaj) {}

Apartament::Apartament (const Apartament &other):Locuinta(other)
{
    this->etaj=other.etaj;
}

Apartament& Apartament::operator=(Apartament& other)
{
    this->Locuinta::operator=(other);
    this->etaj = other.etaj;

    return (*this);
}

double Apartament::calcChirie() const
{
    return (this->pretMetru * this->suprafata) * (1-this->discount/100);
}

ostream& Apartament::afiseaza(ostream& out) const
{
    this->Locuinta::afiseaza(out);
    out << "Etaj: " << this->etaj << '\n';
    return out;
}

istream& operator>>(istream& in, Apartament& ob)
{
    in >> (Locuinta&)ob;
    cout << "Etaj: ";
    in >> ob.etaj;
    return in;
}
