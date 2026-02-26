#include <iostream>
#include <iomanip>

using namespace std;

struct Buku 
{
    string judul;
    int harga;
};

int main() 
{
    // Data disediakan dari awal
    Buku toko[6] = {
        {"Algoritma C++", 10000},
        {"Struktur Data", 20000},
        {"Basis Data", 38000},
        {"Pemrograman Web", 48000},
        {"Jaringan Komputer", 50000}
    };
    
    int n = 5;
    int cari, pilihanUtama, pilihanSekuensial;
    char ulang; // Variabel untuk kontrol perulangan

    do {
        // Menampilkan Tabel Buku
        cout << "\n========================================" << endl;
        cout << "           DAFTAR BUKU TOKO             " << endl;
        cout << "========================================" << endl;
        cout << left << setw(5) << "ID" << setw(20) << "Judul Buku" << "Harga" << endl;
        cout << "----------------------------------------" << endl;
        for(int i = 0; i < n; i++) {
            cout << left << setw(5) << i 
                 << setw(20) << toko[i].judul 
                 << "Rp " << toko[i].harga << endl;
        }
        cout << "========================================" << endl;

        // Menu Utama
        cout << "\nMENU PENCARIAN:" << endl;
        cout << "1. Pencarian Sekuensial (Linear)" << endl;
        cout << "2. Pencarian Binary (Bagi Dua)" << endl;
        cout << "Pilih metode (1/2): "; cin >> pilihanUtama;

        if (pilihanUtama == 1) {
            // --- SUB-MENU SEKUENSIAL ---
            cout << "\nVARIAN SEKUENSIAL:" << endl;
            cout << "1. Tanpa Sentinel" << endl;
            cout << "2. Dengan Sentinel" << endl;
            cout << "Pilih varian (1/2): "; cin >> pilihanSekuensial;
            
            cout << "Masukkan harga yang dicari: "; cin >> cari;
            cout << "----------------------------------------" << endl;

            int i = 0;
            if (pilihanSekuensial == 1) {
                // RUMUS Tanpa Sentinel: while (i < n && !found)
                bool ketemu = false;
                while (i < n && !ketemu) {
                    if (toko[i].harga == cari) ketemu = true;
                    else i++;
                }
                if (ketemu) cout << "[NON-SENTINEL] Ditemukan: " << toko[i].judul << " (Indeks " << i << ")" << endl;
                else cout << "Data tidak ditemukan." << endl;

            } else if (pilihanSekuensial == 2) {
                // RUMUS Dengan Sentinel: x[n] = cari; while (x[i] != cari)
                toko[n].harga = cari; // Memasang sentinel di akhir array
                while (toko[i].harga != cari) i++;
                
                if (i < n) cout << "[SENTINEL] Ditemukan: " << toko[i].judul << " (Indeks " << i << ")" << endl;
                else cout << "Data tidak ditemukan (Berhenti di Sentinel)." << endl;
            }

        } else if (pilihanUtama == 2) {
            // --- BINARY SEARCH ---
            // Syarat: Data sudah terurut (Data toko di atas sudah urut berdasarkan harga)
            cout << "Masukkan harga yang dicari: "; cin >> cari;
            cout << "----------------------------------------" << endl;

            int awal = 0, akhir = n - 1, tengah;
            bool ketemu = false;

            // RUMUS: tengah = (awal + akhir) / 2
            while (awal <= akhir && !ketemu) {
                tengah = (awal + akhir) / 2;
                if (toko[tengah].harga == cari) ketemu = true;
                else if (toko[tengah].harga < cari) awal = tengah + 1;
                else akhir = tengah - 1;
            }

            if (ketemu) cout << "[BINARY] Ditemukan: " << toko[tengah].judul << " (Indeks " << tengah << ")" << endl;
            else cout << "Data tidak ditemukan." << endl;

        } else {
            cout << "Pilihan tidak tersedia!" << endl;
        }

        // Bagian Pengulangan Program
        cout << "\n----------------------------------------" << endl;
        cout << "Ingin mencari lagi? (y/n): "; cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "Program selesai. Terima kasih!" << endl;
    return 0;
}
