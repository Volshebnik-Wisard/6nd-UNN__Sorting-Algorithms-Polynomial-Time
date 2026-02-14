#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& arr) {
	for (int num : arr) cout << " " << num;
}

void bubbleSort(vector<int>& arr) {
	int n = arr.size();
	bool swapped; // Флаг для отслеживания обменов

	for (int i = 0; i < n - 1; i++) { // Внешний цикл
		swapped = false; // Сбрасываем флаг обменов перед каждым проходом

		for (int j = 0; j < n - i - 1; j++) { // Внутренний цикл
			if (arr[j] > arr[j + 1]) { // Сравниваем соседние элементы
				swap(arr[j], arr[j + 1]); // Меняем местами, если порядок нарушен
				swapped = true; // Устанавливаем флаг, что был обмен
			}
		}
		// Если ни один из двух элементов не был поменян, то прерываем
		if (!swapped)
			break;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
	cout << "Unsorted array: "; printVector(arr);
	bubbleSort(arr);
	cout << "\n\nBubble sort:    "; printVector(arr); cout << "\n";
}



