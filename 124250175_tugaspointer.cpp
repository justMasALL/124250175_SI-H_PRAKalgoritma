#include <iostream>
using namespace std;

int main() 
{
    static int angka[] = {12, 45, 7, 23, 90}; 
    int n = 5;  
    
    // Pointer yang menunjuk ke alamat awal array 
    int *ptr = angka; 
    
    // Variabel penampung hasil
    int max = *ptr;      
    int min = *ptr;      
    int sum = 0;         
    float rataRata;
    
    // Mencetak semua elemen 
    cout << "Isi Array: ";
    for (int i = 0; i < n; i++) 
    {
        // Mengakses nilai tanpa mengubah alamat asli ptr 
        cout << *(ptr + i) << " "; 
    }
    cout << endl;
    
    // Loop untuk perhitungan Max, Min, dan Sum
    for (int i = 0; i < n; i++) 
    {
        // Mengambil nilai menggunakan pointer 
        int nilaiSekarang = *(ptr + i);
        
        // Mencari nilai maximum dan minimum 
        if (nilaiSekarang > max) 
        {
            max = nilaiSekarang;
        }
        if (nilaiSekarang < min) 
        {
            min = nilaiSekarang;
        }
        // Menghitung jumlah 
        sum += nilaiSekarang;
    }
    // Menghitung rata-rata
    rataRata = (float)sum / n;

    // Output hasil akhir
    cout << "\n--- Hasil Perhitungan ---" << endl;
    cout << "Nilai Maximum : " << max << endl;
    cout << "Nilai Minimum : " << min << endl;
    cout << "Total Jumlah  : " << sum << endl;
    cout << "Rata-rata     : " << rataRata << endl;

    return 0;
}
