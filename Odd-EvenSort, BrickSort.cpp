#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

void oddEvenSort(int arr[], int n)
{
	bool isSorted = false; // Изначально массив считается неотсортированным
	while (!isSorted) // пока массив не будет отсортирован
	{
		isSorted = true; // Предполагаем, что массив отсортирован

		// Bubble sort для нечётных индексов
		for (int i = 1; i <= n - 2; i = i + 2)
		{
			if (arr[i] > arr[i + 1])
			{
				// Если элементы в неправильном порядке, меняем их местами
				swap(arr[i], arr[i + 1]);
				isSorted = false; // Перестановка -> массив еще не отсортирован
			}
		}

		// Bubble sort для чётных индексов
		for (int i = 0; i <= n - 2; i = i + 2)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}
	}
	return;
}

int main()
{
	int arr[] = { 61, -42, 12, -9, 19, 23, -11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Unsorted array:             "; printArray(arr, n);  cout << "\n\n";
	oddEvenSort(arr, n);
	cout << "Odd-Even Sort / Brick Sort: "; printArray(arr, n);  cout << "\n";
	return (0);
}