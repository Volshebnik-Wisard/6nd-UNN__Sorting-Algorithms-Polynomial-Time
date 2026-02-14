#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& arr) {
	for (int num : arr) cout << " " << num;
}

void insertionsort(vector<int>& arr, int n) {
	// Начинаем с индекса 1, так как первый элемент считается отсортированным
	for (int i = 1; i < n; ++i) {
		int key = arr[i]; // Текущий элемент, который нужно вставить в отсортированную часть
		int j = i - 1; // Индекс последнего элемента в отсортированной части

		// Сдвигаем элементы большие чем key на одну позицию вправо
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j]; // Сдвигаем элемент вправо
			j = j - 1; // Переходим к следующему элементу слева
		}
		arr[j + 1] = key; // Вставляем key на правильную позицию в отсортированной части
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	vector<int> arr = { 24, 1, 13, 5, 36, 4, 18, 9, 22 };
	int n = arr.size();
	cout << "Unsorted array: "; printVector(arr);
	insertionsort(arr, n);
	cout << "\n\nInsertion Sort: "; printVector(arr);
	return 0;
}



