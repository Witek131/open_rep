#include "human.h"

Human::Human() // конструктор по умаолчанию
{
    cout << "I've been born! Deafault" << endl;
    setter("");
}

Human::Human(string name)
{
    cout << "I've been born!" << endl;
    this->name = name;
}

void Human::say_hello()
{
    cout << "HELLO!" << endl;
    cout << "My name is " << this->getter() << endl;
}

string Human::getter()
{
    return this->name;
}

void Human::setter(string new_name)
{
    name = new_name;
}