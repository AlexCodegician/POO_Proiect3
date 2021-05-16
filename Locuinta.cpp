//
//  Locuinta.cpp
//  poo3
//
//  Created by Alex Barbu on 23/04/2021.
//  Copyright © 2021 Alex Barbu. All rights reserved.
//

#include "Locuinta.hpp"
using namespace std;

Locuinta::Locuinta (int index, double suprafata, double pretMetru, string numeClient, double discount) : index(index), numeClient(numeClient), suprafata(suprafata), discount(discount), pretMetru(pretMetru)
{
    if (discount < 0 || discount > 10) throw(MyException("Discount-ul trebuie sa fie intre 0-10%."));
}

Locuinta::Locuinta (const Locuinta& other)
{
    this->numeClient=other.numeClient;
    this->suprafata=other.suprafata;
    this->discount=other.discount;
    this->pretMetru=other.pretMetru;
    this->index=other.index;
}

Locuinta& Locuinta::operator=(Locuinta& other)
{
    this->numeClient=other.numeClient;
    this->suprafata=other.suprafata;
    this->discount=other.discount;
    this->pretMetru=other.pretMetru;
    this->index=other.index;
    
    return (*this);
}

ostream& Locuinta::afiseaza(ostream& out) const
{
    out << "Tip: " << this->what() << '\n';
    out << "Index: " << this->index << '\n';
    out << "Suprafata utila: " << this->suprafata << "m^2\n";
    out << "Chirie: " << this->pretMetru << "m^2\n";
    out << "Client: " << this->numeClient << '\n';
    out << "Discount: " << this->discount << '\n';
    return out;
}

istream& operator>> (istream&in, Locuinta& ob)
{
    cout << "Nume client: ";
    cin.get();
    getline(in,ob.numeClient);
    cout << "Suprafata: ";
    in >> ob.suprafata;
    cout << "Discount(0-10%): ";
    in >> ob.discount;
    if (ob.discount<0 || ob.discount>10)
        throw(MyException("Discount-ul trebuie sa fie intre 0-10%."));
    cout << "Pret pe m^2: ";
    in >> ob.pretMetru;
    return in;
}

ostream& operator<< (ostream& out, const Locuinta& ob)
{
    return ob.afiseaza(out);
}
