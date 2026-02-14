#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& arr) {
	for (int num : arr) cout << " " << num;
}

vector<int> countsort(vector<int>& arr) {
	int n = arr.size();
	int maxval = 0; // Находим максимальный элемент в массиве
	for (int i = 0; i < n; i++) { maxval = max(maxval, arr[i]); }

	// 1.Создаем и инициализируем массив для подсчета (частоты)
	vector<int> count(maxval + 1, 0);

	// 2.Подсчитываем частоту каждого элемента
	for (int i = 0; i < n; i++) { count[arr[i]]++; }

	// 3.Вычисляем префиксные суммы (кумулятивные суммы)
	for (int i = 1; i <= maxval; i++) {
		// Теперь count[i] содержит позицию последнего
		// элемента i в отсортированном массиве
		count[i] += count[i - 1];
	}

	// 4.Строим отсортированный массив
	vector<int> ans(n);
	for (int i = n - 1; i >= 0; i--) {
		// Размещаем элемент на правильной позиции в отсортированном массиве
		ans[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--; // Уменьшаем счетчик для этого элемента
	}
	return ans;
}

int main() {
	setlocale(LC_ALL, "Russian");
	vector<int> arr = { 2,5,3,0,2,3,0,3 };
	cout << "Unsorted array: "; printVector(arr);
	vector<int> sorted = countsort(arr);
	cout << "\n\nCounting sort:  "; printVector(sorted); cout << "\n";
	return 0;
}




