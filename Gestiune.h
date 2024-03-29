//
//  Gestiune.h
//  poo3
//
//  Created by Alex Barbu on 23/04/2021.
//  Copyright © 2021 Alex Barbu. All rights reserved.
//

#ifndef Gestiune_h
#define Gestiune_h
#include "Apartament.hpp"
#include "Casa.hpp"
using namespace std;

template <typename T>
class Gestiune
{
    static int index;
    vector <T*> evidenta;
public:
    Gestiune& operator+=(T& ob);
    ~Gestiune();
};

template <typename T>
int Gestiune<T>::index=0;

template <typename T>
Gestiune<T>& Gestiune<T>::operator+=(T& ob)
{
    Gestiune<T>::index++;
    T* tmp=new T(ob);
    tmp->setIndex(index);
    this->evidenta.push_back(tmp);
    return (*this);
}

template <typename T>
Gestiune<T>::~Gestiune()
{
    for (unsigned int i=0;i<this->evidenta.size();i++)
    {
        delete this->evidenta[i];
    }
}

template <>
class Gestiune<Casa>
{
    static int index;
    vector <Casa*> evidenta;
    int nrCase=0;
public:
    Gestiune& operator+=(Casa& ob);
    double totalChirie();
    ~Gestiune();
};
int Gestiune<Casa>::index=0;

Gestiune<Casa>& Gestiune<Casa>::operator+=(Casa& ob)
{
    Gestiune<Casa>::index++;
    this->nrCase++;
    Casa* tmp=new Casa(ob);
    tmp->setIndex(index);
    this->evidenta.push_back(tmp);
    return (*this);
}

double Gestiune<Casa>::totalChirie()
{
    double total=0;
    for (int i=0;i<this->nrCase;++i)
    {
        total+=this->evidenta[i]->calcChirie();
    }
    return total;
}

Gestiune<Casa>::~Gestiune()
{
    for (unsigned int i = 0; i < this->evidenta.size(); ++i)
    {
        delete this->evidenta[i];
    }
}

#endif /* Gestiune_h */
