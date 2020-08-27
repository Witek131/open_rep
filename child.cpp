#include <iostream>
using namespace std;

class Child
{
    private:
        string  name;
        string  s_name;
        int     age;
    public:
        Child()
        {
            this->input_data();
        }

        Child(string name, string s_name, int age)
        {
            this->name = name;
            this->s_name = s_name;
            this->age = age;
        }

        void input_data()
        {
            cout << "Please, enter the name: ";
            cin >> this->name;
            cout << "Enter s_name: ";
            cin >> this->s_name;
            cout << "Enter age: ";
            cin >> this->age;
        }

        void show_data()
        {
            cout << "My name is " << this->name << 
            ' ' << this->s_name << endl;
            cout << "And I'm " << this->age << " y o!" << endl;
        }
};

int main()
{
    Child Petya = Child("Petya", "Petrov", 15);
    Petya.show_data();

    Child *pointer_child = new Child();
    pointer_child->show_data();

    return 0;
}