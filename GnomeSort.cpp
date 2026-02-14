#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)  cout << arr[i] << " ";
}


void gnomeSort(int arr[], int n)
{
	int index = 0; // Начинаем с первого элемента
	// Продолжаем, пока не дойдем до конца массива
	while (index < n) {
		// Если находимся в начале массива, переходим к следующему элементу
		if (index == 0)
			index++;
		// Если текущий элемент больше или равен предыдущему, идем вперед
		if (arr[index] >= arr[index - 1])
			index++;
		else {
			// Если текущий элемент меньше предыдущего, меняем их местами
			swap(arr[index], arr[index - 1]);
			// Возвращаемся на шаг назад для проверки предыдущих элементов
			index--;
		}
	}
	return;
}

int main()
{
	int arr[] = { 6, 21, 10, -9, 19, 4, -11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Unsorted array: "; printArray(arr, n);  cout << "\n\n";
	gnomeSort(arr, n);
	cout << "Gnome sort:     "; printArray(arr, n);  cout << "\n";
	return (0);
}



