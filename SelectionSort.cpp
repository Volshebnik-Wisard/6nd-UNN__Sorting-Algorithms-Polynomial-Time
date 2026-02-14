#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& arr) {
	for (int num : arr) cout << " " << num;
}

void selectionSort(vector<int>& arr) {
	int n = arr.size();
	// Проходим по всем элементам массива, кроме последнего
	for (int i = 0; i < n - 1; ++i) {
		int min_idx = i; // Предполагаем, что текущий элемент является минимальным

		// Проходим по неотсортированной части массива для поиска реального минимума
		for (int j = i + 1; j < n; ++j) {

			// Если находим элемент меньше текущего минимума
			if (arr[j] < arr[min_idx]) {
				min_idx = j; // Обновляем индекс минимального элемента
			}
		}
		// Перемещаем найденный минимальный элемент на его правильную позицию
		swap(arr[i], arr[min_idx]);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	vector<int> arr = { 56, 8, 12, 22, 11, 43, 3, 23, 51, 18 };
	cout << "Unsorted array: "; printVector(arr);
	selectionSort(arr);
	cout << "\n\nSelection sort: "; printVector(arr); cout << "\n";
	return 0;
}


