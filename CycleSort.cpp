#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)  cout << arr[i] << " ";
}

void cycleSort(int arr[], int n)
{
	int writes = 0; // Счетчик количества операций записи в память

	// Проходим по всем элементам массива, кроме последнего
	for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
		int item = arr[cycle_start]; // Запоминаем текущий элемент как начальную точку цикла

		// Находим правильную позицию для элемента item
		int pos = cycle_start;
		for (int i = cycle_start + 1; i < n; i++)
			if (arr[i] < item) // Считаем количество элементов меньше item справа от текущей позиции
				pos++;

		// Если элемент уже находится на правильной позиции, переходим к следующему
		if (pos == cycle_start)	continue;
		while (item == arr[pos]) pos += 1; // Пропускаем все дубликаты элементов

		// Помещаем элемент на правильную позицию, если это необходимо
		if (pos != cycle_start) {
			swap(item, arr[pos]);
			writes++; // Увеличиваем счетчик операций записи
		}

		// Обрабатываем оставшуюся часть цикла
		while (pos != cycle_start) {
			pos = cycle_start;  // Начинаем новый цикл с текущей позиции

			// Снова находим правильную позицию для элемента item
			for (int i = cycle_start + 1; i < n; i++)
				if (arr[i] < item) pos += 1;
			while (item == arr[pos]) pos += 1; // Пропускаем все дубликаты элементов

			// Помещаем элемент на правильную позицию, если он еще не на месте
			if (item != arr[pos]) {
				swap(item, arr[pos]);
				writes++;
			}
		}
	}
	// Количество операций записи для анализа эффективности
	cout << "Writes: " << writes << endl;
}

int main()
{
	int arr[] = { 6, 21, 10, -9, 19, 4, -11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Unsorted array: "; printArray(arr, n);  cout << "\n";
	cycleSort(arr, n);
	cout << "Cycle sort:    "; printArray(arr, n);  cout << "\n";

	return 0;
}