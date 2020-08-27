#include <iostream>
using namespace std;

class Birthday 
{
    private:
        int day;
        int month;
        int year;
    public:
        Birthday(int m, int d, int y)
        : month(m), day(d), year(y)
        { }
        void printDate()
        {
            cout<<month<<"/"<<day <<"/"<<year<<endl;
        }
};

class Person 
{
    private:
        string name;
        Birthday bd;
    public:
        Person(string n, int m, int d, int y)
        : name(n), bd(m, d, y)
        { }
        void printInfo()
        {
            cout << name << endl;
            bd.printDate();
        }
        friend void Person_sport(Person input_person);
};

void Person_sport(Person input_person)
{
    input_person.name = "SPORT";
    input_person.printInfo();
}

int main() 
{
    Person first("David", 2, 21, 1985);
    Person second("David", 2, 21, 1985);

    p.printInfo();
}