#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
}

void exchangeSort(int num[], int size)
{
	int i, j, temp;
	for (i = 0; i < size - 1; i++) {
		// Внешний цикл: проходим по всем элементам массива, кроме последнего
		for (j = i + 1; j < size; j++) {
			// Внутренний цикл: проходим по всем элементам после текущего
			// Сортировка по возрастанию:
			// Если предыдущий элемент больше следующего, меняем их местами
			//if (num[i] > num[j]) {
			// Сортировка по убыванию:
			if (num[i] < num[j]) {
				// Обмен элементов местами
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
}

int main()
{
	int arr[] = { 61, -42, 12, -9, 19, 23, -11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Unsorted array: "; printArray(arr, n);
	exchangeSort(arr, n);
	cout << "\n\nExchange sort: "; printArray(arr, n);
	return 0;
}