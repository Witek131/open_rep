#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void division(int num_1, int num_2)
{
	if (num_2) // num_2 != 0
		cout << "DIV -> " << num_1 / num_2 << endl;
	else
		cout << "Division by zero!" << endl;
}

int converte_km_to_m(int kilometr)
{
	return (kilometr * 1000);
}

float converte_m_to_km(int metr)
{
	return (metr / 1000.);
}

// w - width
// h - height
void print_map(int h, int w, char border)
{
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (i == 1 || i == h)
				cout << border;
			else if (j == 1 || j == w) 
				cout << border;
			else if (j == w / 2 && i == h / 2)
				cout << '%';
			else
				cout << ' ';
		}
		cout << endl;
	}
}

char *ceasar_cipher_code(char *str, int shift)
{
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] =  'a' + (str[i] - 'a' + shift) % 26;
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] =  'A' + (str[i] - 'A' + shift) % 26;
	}
	return str;
}

void print_matrix(int **double_ptr, int m, int n)
{
	for (int row = 0; row < m; ++row)
	{
		for (int col = 0; col < n; ++col)
			cout << double_ptr[row][col] << '\t';
		cout << endl;
	}
	cout << endl;
}

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

void delete_matrix(int **double_ptr, int m, int n)
{
	for (int row = 0; row < m; ++row)
		delete [] double_ptr[row];
	delete [] double_ptr;
}

int **sum_matrix(int **first_m, int **second_m, int m, int n)
{
	int **res = NULL;
	
	res = init_matrix(m, n);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			res[i][j] = first_m[i][j] + second_m[i][j];
	}
	return (res);
}

int main()
{
	int w = 5, h = 5;
	int **matrix_1 = NULL;
	int **matrix_2 = NULL;
	int **matrix_sum = NULL;

	srand(time(NULL)); // srand - seed rand

	matrix_1 = init_matrix(h, w);
	matrix_2 = init_matrix(h, w);
	print_matrix(matrix_1, h, w);
	print_matrix(matrix_2, h, w);

	matrix_sum = sum_matrix(matrix_1, matrix_2, h, w);
	print_matrix(matrix_sum, w, h);

	delete_matrix(matrix_1, h, w);
	delete_matrix(matrix_2, h, w);
	delete_matrix(matrix_sum, h, w);

	return (0);
}
