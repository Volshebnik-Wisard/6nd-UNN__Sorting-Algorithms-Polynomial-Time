#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& arr) {
	for (int num : arr) cout << " " << num;
}

void cocktail_sort(vector<int>& arr) {
	int n = arr.size();
	bool swapped = true;
	int start = 0;   int end = n - 1;
	while (swapped) {
		// Bubble Sort - слева направо
		swapped = false;
		for (int i = start; i < end; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		if (!swapped) break;
		end--;
		// Bubble Sort - справа налево
		swapped = false;
		for (int i = end - 1; i >= start; i--) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		start++;
	}
}

int main() {
	vector<int> arr = { 52, 12, 49, 31, 7, 26 };
	cout << "Unsorted array: "; printVector(arr);
	cocktail_sort(arr);
	cout << "\n\nCocktail sort:  "; printVector(arr);
	cout << "\n";
	return 0;
}





