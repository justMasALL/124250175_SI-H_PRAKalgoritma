#include <iostream>
#include <string>

using namespace std;

/**
 * Fungsi untuk menampilkan seluruh data dalam array.
 * @param array: array berisi daftar nama.
 * @param n: jumlah elemen dalam array.
 */
void tampilData(string array[], int n) {
    for (int i = 0; i < n; i++) {
        // Menampilkan nama mahasiswa diikuti spasi
        cout << array[i] << " ";            
    }   
    cout << endl; // Baris baru setelah data ditampilkan
}

/**
 * Algoritma Bubble Sort untuk mengurutkan secara Ascending (A-Z).
 * Membandingkan elemen berurutan dan menukarnya jika posisi salah.
 */
void bubbleSort(string array[], int n) {
    // Perulangan untuk jumlah tahapan pengurutan
    for(int i = 0; i < n - 1; i++) {
        // Perulangan untuk membandingkan data yang berdekatan
        for(int j = 0; j < n - 1 - i; j++) {
            // Jika elemen kiri lebih besar dari kanan, lakukan penukaran (Ascending)
            if (array[j] > array[j + 1]) {
                string temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

/**
 * Algoritma Quick Sort untuk mengurutkan secara Descending (Z-A).
 * Menggunakan pivot untuk membagi array menjadi dua bagian.
 */
void quick_sort(string array[], int awal, int akhir) {
    int low = awal, high = akhir;
    // Menentukan pivot di tengah array
    string pivot = array[(awal + akhir) / 2];

    do {
        // Cari elemen yang lebih besar dari pivot (untuk Descending) di sisi kiri
        while (array[low] > pivot)
            low++;
        // Cari elemen yang lebih kecil dari pivot (untuk Descending) di sisi kanan
        while (array[high] < pivot)
            high--;

        // Jika ditemukan pasangan yang salah posisi, tukar datanya
        if (low <= high) {
            swap(array[low], array[high]);
            low++;
            high--;
        }
    } while (low <= high); // Ulangi hingga pointer low dan high bertemu

    // Rekursif untuk bagian kiri array
    if (awal < high)
        quick_sort(array, awal, high);
    // Rekursif untuk bagian kanan array
    if (low < akhir)
        quick_sort(array, low, akhir);
}

int main() {
    int n;
    
    // Meminta user menginputkan jumlah mahasiswa
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    cin.ignore(); // Membersihkan buffer agar input string tidak terlewati

    string arrayAsli[n]; // Array untuk menyimpan input awal
    string arrayBubble[n]; // Array untuk proses Bubble Sort
    string arrayQuick[n];  // Array untuk proses Quick Sort

    // Meminta user menginputkan nama satu per satu
    cout << "Masukkan " << n << " nama mahasiswa:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nama ke-" << i + 1 << ": ";
        getline(cin, arrayAsli[i]);
        // Salin data ke array kerja
        arrayBubble[i] = arrayAsli[i];
        arrayQuick[i] = arrayAsli[i];
    }

    cout << "\nData Sebelum diurutkan:" << endl;
    tampilData(arrayAsli, n);

    // Proses Pengurutan Ascending dengan Bubble Sort
    bubbleSort(arrayBubble, n);
    cout << "\nData setelah disort (Bubble Sort - Ascending):" << endl;
    tampilData(arrayBubble, n);

    // Proses Pengurutan Descending dengan Quick Sort
    quick_sort(arrayQuick, 0, n - 1);
    cout << "\nData setelah disort (Quick Sort - Descending):" << endl;
    tampilData(arrayQuick, n);

    return 0;
}
