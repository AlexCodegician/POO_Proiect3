//
//  MyException.hpp
//  poo3
//
//  Created by Alex Barbu on 23/04/2021.
//  Copyright © 2021 Alex Barbu. All rights reserved.
//

#ifndef MyException_hpp
#define MyException_hpp

#include <iostream>
using namespace std;

class MyException:public exception
{
    const char* what_arg;
public:
    MyException (const char*);
    ~MyException() noexcept {}
    const char* what() const noexcept;
};

#endif /* MyException_hpp */
