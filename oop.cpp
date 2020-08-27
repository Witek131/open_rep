#include <iostream>
using namespace std;

class Human
{
    private:
        string name;
    public:
        Human() // конструктор по умаолчанию
        {
            cout << "I've been born! Deafault" << endl;
            setter("");
        }

        Human(string name)
        {
            cout << "I've been born!" << endl;
            this->name = name;
        }

        void say_hello()
        {
            cout << "HELLO!" << endl;
            cout << "My name is " << this->getter() << endl;
        }

        string getter()
        {
            return this->name;
        }

        void setter(string new_name)
        {
            name = new_name;
        }
};

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
