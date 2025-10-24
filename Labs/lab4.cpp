#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	const int c = 4 + 3;
	int massive[c];
	cout << "Введите " << c << " элементов массива:" << endl;
	for (int l = 0; l < c; ++l)
	{
		cout << l + 1 << " элемент:";
		cin >> massive[l];
	}

	//1

	int povtr = 0;
	for (int l = 0; l < c; ++l)
	{
		if (massive[l] % 5 == 0)
		{
			povtr += 1;
		}

	}
	if (povtr == c)
	{
		for (int l = 0; l < c - 1; ++l)
		{
			for (int i = l + 1; i < c; ++i)
			{
				if (massive[l] > massive[i])
				{
					swap(massive[l], massive[i]);
				}
			}
		}
	}
	for (int l = 0; l < c; ++l)
	{
		cout << massive[l] << " ";
	}
	cout << endl;

	//2

	const int str = 3;
	const int stl = 4;
	int mtr[str][stl];
	cout << "Введите элементы матрицы " << str << "x" << stl << ":" << endl;
	for (int i = 0; i < str; ++i)
	{
		for (int j = 0; j < stl; ++j)
		{
			cout << "Введите элемент " << i + 1 << "," << j + 1 << ":";
			cin >> mtr[i][j];
		}
	}
	cout << "Введенная матрица:" << endl;
	for (int i = 0; i < str; ++i)
	{
		for (int j = 0; j < stl; ++j)
		{
			cout << mtr[i][j] << "  ";
		}
		cout << endl;
	}

	int k = 0;
	int max = -1;

	for (int j = 0; j < stl; ++j)
	{
		int b = 0;
		for (int i = 0; i < str; ++i)
		{
			if (mtr[i][j] < 0)
			{
				b += 1;
			}
		}
		if (b > k)
		{
			max = j;
			k = b;
		}
	}

	if (max >= 0)
	{
		for (int i = 0; i < str; ++i)
		{
			mtr[i][max] = -1;
		}
	}
	else
	{
		cout << "Нет отрицательных чисел" << endl;
	}

	cout << "Итоговая матрица:" << endl;
	for (int i = 0; i < str; ++i)
	{
		for (int j = 0; j < stl; ++j)
		{
			cout << mtr[i][j] << "  ";
		}
		cout << endl;
	}


	return 0;
}