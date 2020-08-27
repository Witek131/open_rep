#pragma once

#include <iostream>
using namespace std;

class Human
{
    private:
        string name;
    public:
        Human();
        Human(string name);
        void say_hello();
        string getter();
        void setter(string new_name);
};

