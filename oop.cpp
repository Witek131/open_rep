#include "human.h"

int main()
{
    Human Adam = Human("Adam");
    Adam.say_hello();
    cout << Adam.getter() << endl;
    Adam.setter("Kirill");
    cout << Adam.getter() << endl;

    Human *pointer = new Human;
    cout << (*pointer).getter() << endl;
    cout << pointer->getter() << endl;

    return (0);
}
