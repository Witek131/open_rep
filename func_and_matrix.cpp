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

int **init_matrix(int **double_ptr, int m, int n)
{
	double_ptr = new int* [m];
	for (int row = 0; row < m; ++row)
	{
		double_ptr[row] = new int [n];
		for (int col = 0; col < n; ++col)
			double_ptr[row][col] = rand(); // random
	}
	return double_ptr;
}

void delete_matrix(int **double_ptr, int m, int n)
{
	for (int row = 0; row < m; ++row)
		delete [] double_ptr[row];
	delete [] double_ptr;
}

int main()
{
	srand(time(NULL)); // srand - seed rand
	int w, h;
	int **matrix = NULL;
	cout << "Please, enter the size of the matrix" << endl;
	cin >> h;
	cin >> w;
	matrix = init_matrix(matrix, h, w);
	print_matrix(matrix, h, w);
	delete_matrix(matrix, h, w);
	return (0);
}
