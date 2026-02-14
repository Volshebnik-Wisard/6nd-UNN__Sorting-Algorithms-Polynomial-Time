#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)  cout << arr[i] << " ";
}

int getNextGap(int gap) // Функция для вычисления следующего промежутка (gap)
{
	gap = (gap * 10) / 13; // Уменьшаем промежуток с коэффициентом сжатия 1.3
	if (gap < 1) return 1; // Промежуток будет не меньше 1
	return gap;
}

void combSort(int a[], int n)
{
	int gap = n; // Инициализируем начальный промежуток равным размеру массива
	bool swapped = true; // Флаг, были ли обмены элементов на предыдущей итерации
	// Продолжаем цикл, пока промежуток не станет равным 1 И не будет обменов
	while (gap != 1 || swapped == true)
	{
		gap = getNextGap(gap); // Вычисляем следующий промежуток
		swapped = false; // Сбрасываем флаг обменов
		// Сравниваем элементы на расстоянии gap друг от друга
		for (int i = 0; i < n - gap; i++)
		{
			// Если элементы находятся в неправильном порядке, меняем их местами
			if (a[i] > a[i + gap])
			{
				swap(a[i], a[i + gap]);
				swapped = true; // Устанавливаем флаг, что был произведен обмен
			}
		}
	}
}

int main()
{
	int arr[] = { 8, 4, 1, 56, 3, -44, 23, -6, 28, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Unsorted array: "; printArray(arr, n);  cout << "\n\n";
	combSort(arr, n);
	cout << "Comb sort:      "; printArray(arr, n);  cout << "\n";
	return 0;
}