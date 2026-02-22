#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>&arr, int left, int right) {
    if (left >= right) return;

    int mid = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < mid) i++;
        while (arr[j] > mid) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr[i] = x;
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

}