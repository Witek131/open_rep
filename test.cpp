#include <iostream>
using namespace std;

class child
{
    private:
        string f_name;
        string s_name;
        int age;
    public:
        child()
        {
            f_name="John";
            s_name="Smith";
            age=20;
        }
        
        child(string a,string b, int c)
        {
            f_name = a;
            s_name = b;
            age = c;
        }

        void print()
        {
            cout<<f_name<<endl<<s_name<<endl<<age<<endl;
        }

        void input(string a,string b, int c)
        {
            f_name = a;
            s_name = b;
            age = c;
        }
};

int main()
{
    child *A, *B;
    A.print();
    B.print();
    A.input("A","B",10);
    A.print();
    return 0;
}