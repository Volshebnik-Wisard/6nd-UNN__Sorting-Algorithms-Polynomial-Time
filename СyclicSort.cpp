#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl;
}

void cyclicSort(int arr[], int n) {
	int i = 0;
	while (i < n) // Проходим по всем элементам массива
	{
		// Поскольку массив использует индексацию с 1 (элементы от 1 до n),
		// правильная позиция каждого элемента равна (элемент - 1)
		// Например: 1 должен быть на позиции 0, 2 на позиции 1 и т.д.
		int correct = arr[i] - 1;
		// Если текущий элемент не находится на своей правильной позиции
		if (arr[i] != arr[correct]) {

			// Меняем местами текущий элемент с элементом на его правильной позиции
			swap(arr[i], arr[correct]);
		}
		else {
			// Если элемент уже находится на своей правильной позиции,
			// переходим к следующему элементу
			i++;
		}
	}
}

int main() {

	int arr[] = { 3, 2, 4, 5, 1, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Unsorted array: "; printArray(arr, n);
	cyclicSort(arr, n);
	cout << "\nCyclic sort:    "; printArray(arr, n);
	return 0;
}