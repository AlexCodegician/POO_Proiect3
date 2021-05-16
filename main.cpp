//
//  main.cpp
//  poo3
//
//  Created by Alex Barbu on 23/04/2021.
//  Copyright © 2021 Alex Barbu. All rights reserved.
//

#include <iostream>
#include <set>
#include <utility>
#include "Gestiune.h"
using namespace std;
int main()
{
    set<pair<Locuinta*, string>> evidentaTotala;
    Gestiune<Apartament> evidentaApartamente;
    Gestiune<Casa> evidentaCase;
    int op;
    do 
    {
        cout << "GESTIUNE LOCUINTE:\n";
        cout << "1. Adauga apartament\n";
        cout << "2. Adauga casa\n";
        cout << "3. Afiseaza toate locuintele\n";
        cout << "4. Afiseaza apartament\n";
        cout << "5. Afiseaza casa\n";
        cout << "6. Calculeaza chiria\n";
        cout << "7. Calculeaza chiria totala case\n";
        cout << "0. Exit\n";
        
        cin >> op;
        cout << "\n";
        if (op==1)
        {
            cout << "1. Adauga apartament\n";
            Apartament* ap=new Apartament();
            try
            {
                cin >> (*ap);
            }
            catch (exception& e)
            {
                cout << e.what();
            }
            evidentaApartamente+=(*ap);
            evidentaTotala.insert(make_pair(ap,ap->what()));
        }
        else if (op == 2)
        {
            cout << "2. Adauga casa\n";
            Casa* c = new Casa();
            try
            {
                cin >> (*c);
            }
            catch (exception& e)
            {
                cout << e.what();
            }
            evidentaCase+=(*c);
            evidentaTotala.insert(make_pair(c,c->what()));
        }
        else if (op==3)
        {
            cout << "3. Afiseaza toate locuintele\n";
            for (auto it=evidentaTotala.begin();it!=evidentaTotala.end();++it)
            {
                cout << (*it->first) << "\n\n";
            }
        }
        else if (op == 4)
        {
            cout << "4. Afiseaza apartament - Alegeti apartamentul:\n";
            int k = 0;
            for (auto it = evidentaTotala.begin(); it != evidentaTotala.end(); ++it)
            {
                if (it->second == "apartament")
                {
                    cout << k++ << ": ";
                    it->first->brief();
                }
            }
            int op_ap;
            cin >> op_ap;
            k = 0;
            for (auto it = evidentaTotala.begin(); it != evidentaTotala.end(); ++it)
            {
                if (it->second == "apartament")
                {
                    if (op_ap == k)
                    {
                        cout << (*it->first);
                    }
                    k++;
                }
            }
        }
        else if (op == 5)
        {
            cout << "5. Afiseaza casa - Alegeti casa:\n";
            int k = 0;
            for (auto it = evidentaTotala.begin(); it != evidentaTotala.end(); ++it)
            {
                if (it->second == "casa")
                {
                    cout << k++ << ": ";
                    it->first->brief();
                }
            }
            int op_ap;
            cin >> op_ap;
            k = 0;
            for (auto it = evidentaTotala.begin(); it != evidentaTotala.end(); ++it)
            {
                if (it->second == "casa")
                {
                    if (op_ap == k)
                    {
                        cout << (*it->first);
                    }
                    k++;
                }
            }
        }
        else if (op == 6)
        {
            cout << "6. Calculeaza chiria - Alegeti locuinta:\n";
            int k = 0;
            for (auto it = evidentaTotala.begin(); it != evidentaTotala.end(); ++it)
            {
                cout << k++ << ": ";
                it->first->brief();
            }
            int op_ap;
            cin >> op_ap;
            k = 0;
            for (auto it = evidentaTotala.begin(); it != evidentaTotala.end(); ++it)
            {
                if (op_ap == k)
                {
                    cout << (it->first->calcChirie());
                }
                k++;
            }
        }
        else if (op == 7)
        {
            cout << "7. Calculeaza chiria totala case\n";
            cout << evidentaCase.totalChirie();
        }
        cout << "\n";
    }while(op);
    return 0;
}
