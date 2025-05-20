#include <iostream>
#include <ctime>

using namespace std;
void Pyzir(int arr[], const int size);
void Otbor(int arr[], const int size);
void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	const int SIZE = 20;
	int Arr[SIZE]{};
	int Arr1[SIZE]{};
	for (int i = 0; i < SIZE; i++)
	{
		Arr[i] = rand() % 50;
	}
	for (int i = 0; i < SIZE; i++)
	{
		Arr1[i] = Arr[i];
	}
	cout << "Количество элементов в массиве: " << SIZE << endl;
	cout << "\nИсходный массив: " << endl << "[";
	for (int i = 0; i < SIZE; i++)
	{
		cout << Arr[i];
		if (i + 1 == SIZE)
		{
			cout << "]";
			break;
		}
		else
			cout << ", ";
	}
	cout << endl;

		Pyzir(Arr, SIZE);
		Otbor(Arr1, SIZE);
}

void Pyzir(int arr[], const int size)
{
	int srav = 0;
	int sumzamena = 0;
	for (int k = 1; k < size; k++)
	{
		int zamena = 0;
		for (int i = 0; i < (size - k); i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int h = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = h;
				zamena++;
			}
			srav++;
		}
		if (zamena == 0)
			break;
		sumzamena = sumzamena + zamena;
	}
	cout << "\nОтсортированный массив методом пузырька: " << endl << "[";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
		if (i + 1 == size)
		{
			cout << "]";
			break;
		}
		else
			cout << ", ";
	}
	cout << endl << "Количество сравнений: " << srav << endl;
	cout << "Количество замен: " << sumzamena << endl;
}
void Otbor(int arr[], const int size)
{
	int srav = 0;
	int zamena = 0;
	for (int k = 1; k < size; k++)
	{
		int max = arr[0];
		int maxI = 0;
		for (int i = 0; i < size - k; i++)
		{
			if (max < arr[i + 1])
			{
				max = arr[i + 1];
				maxI = i + 1;
			}
			srav++;
		}
		if (max > arr[size - k])
		{
			int h = arr[size - k];
			arr[size - k] = max;
			arr[maxI] = h;
			zamena++;
		}
	}
	cout << "\nОтсортированный массив методом отбора: " << endl << "[";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
		if (i + 1 == size)
		{
			cout << "]";
			break;
		}
		else
			cout << ", ";
	}
	cout << endl << "Количество сравнений: " << srav << endl;
	cout << "Количество замен: " << zamena << endl;
}
