#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Matrix
{
    private:
        int **mtx;
        int w;
        int h;
        int **init_matrix(int m, int n)
        {
            int **double_ptr = NULL;

            double_ptr = new int* [m];
            for (int row = 0; row < m; ++row)
            {
                double_ptr[row] = new int [n];
                for (int col = 0; col < n; ++col)
                    double_ptr[row][col] = rand() % 100; // random
            }
            return double_ptr;
        }
    public:
        Matrix()
        {
            mtx = NULL;
            w = 0;
            h = 0;
        }
       
        Matrix(int h, int w)
        {
            this->w = w;
            this->h = h;
            this->mtx = this->init_matrix(h, w);
        }

        void print()
        {
            for (int row = 0; row < this->h; ++row)
            {
                for (int col = 0; col < this->w; ++col)
                    cout << this->mtx[row][col] << '\t';
                cout << endl;
            }
            cout << endl;
        }

        Matrix *operator+(Matrix second)
        {
            if (this->h == second.h && this->w == second.w)
            {
                Matrix *res = new Matrix(this->h, this->w);
                for (int i = 0; i < this->h; ++i)
                {
                    for (int j = 0; j < this->w; ++j)
                        res->mtx[i][j] = this->mtx[i][j] + second.mtx[i][j];
                }
                return (res);
            }
            else
                return (NULL);
        }

        ~Matrix()
        {
            for (int row = 0; row < this->h; ++row)
                delete [] mtx[row];
            delete [] mtx;
        }
};


int main()
{
    Matrix *first = new Matrix(3, 3);
    Matrix *second = new Matrix(3, 3);
    first->print();
    second->print();

    (*first + *second)->print();
	return (0);
}