#include <iostream>
using namespace std;

// Bubble Sort Ascending
void bubbleSortAsc(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Quick Sort Descending
void quickSortDesc(string arr[], int awal, int akhir) {
    int low = awal, high = akhir;
    string pivot = arr[(awal + akhir) / 2];

    do {
        while (arr[low] > pivot)
            low++;
        while (arr[high] < pivot)
            high--;

        if (low <= high) {
            string temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    } while (low <= high);

    if (awal < high)
        quickSortDesc(arr, awal, high);
    if (low < akhir)
        quickSortDesc(arr, low, akhir);
}

int main() {
    int n;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    cin.ignore();

    string nama[n];        // tanpa MAX
    string namaDesc[n];    // array kedua untuk quick sort

    for (int i = 0; i < n; i++) {
        cout << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
        getline(cin, nama[i]);
        namaDesc[i] = nama[i]; // salin data
    }

    // Bubble Sort Ascending
    bubbleSortAsc(nama, n);

    cout << "\nHasil Bubble Sort (Ascending):\n";
    for (int i = 0; i < n; i++) {
        cout << nama[i] << endl;
    }

    // Quick Sort Descending
    quickSortDesc(namaDesc, 0, n - 1);

    cout << "\nHasil Quick Sort (Descending):\n";
    for (int i = 0; i < n; i++) {
        cout << namaDesc[i] << endl;
    }

    return 0;
}
