//
//  MyException.cpp
//  poo3
//
//  Created by Alex Barbu on 23/04/2021.
//  Copyright © 2021 Alex Barbu. All rights reserved.
//

#include "MyException.hpp"
using namespace std;

MyException::MyException(const char* what_arg):what_arg(what_arg){}

const char* MyException::what() const noexcept {
    return this->what_arg;
}
