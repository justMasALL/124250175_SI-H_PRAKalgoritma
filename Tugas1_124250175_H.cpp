#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Product 
{
    char name[60];     
    char category[30]; 
    double price;      
    int stock;         
    float rating;        
};
Product katalog[100]; 
int jumlahProduk = 0;

void saveToFile() 
{
    FILE *pf = fopen("shopease_db.txt", "w");
    if (pf == NULL) return;

    for (int i = 0; i < jumlahProduk; i++) 
    {
        fprintf(pf, "%s|%s|%.0f|%d|%.1f\n", katalog[i].name, 
                katalog[i].category, katalog[i].price, 
                katalog[i].stock, katalog[i].rating);
    }
    fclose(pf);
}

void loadFromFile() 
{
    FILE *pf = fopen("shopease_db.txt", "r");
    if (pf == NULL) return;

    jumlahProduk = 0;

    while (fscanf(pf, " %[^|]|%[^|]|%lf|%d|%f\n", katalog[jumlahProduk].name, 
           katalog[jumlahProduk].category, &katalog[jumlahProduk].price, 
           &katalog[jumlahProduk].stock, &katalog[jumlahProduk].rating) != EOF) 
           {
        jumlahProduk++;
    }
    fclose(pf);
}
void tambahProduk() 
{
    cout << "\n--- Tambah Produk Baru ---\n";
    cout << "Nama Produk    : "; cin.ignore(); cin.getline(katalog[jumlahProduk].name, 60);
    cout << "Kategori       : "; cin.getline(katalog[jumlahProduk].category, 30);
    cout << "Harga (Rp)     : "; cin >> katalog[jumlahProduk].price;
    cout << "Stok           : "; cin >> katalog[jumlahProduk].stock;
    cout << "Rating (0-5)   : "; cin >> katalog[jumlahProduk].rating;
    
    jumlahProduk++;
    saveToFile(); 
    cout << "Produk berhasil ditambahkan!\n"; 
}
void bubbleSortName() 
{
    for (int i = 0; i < jumlahProduk - 1; i++) 
    {
        for (int j = 0; j < jumlahProduk - i - 1; j++) 
        {
            if (strcasecmp(katalog[j].name, katalog[j+1].name) > 0) 
            {
                Product temp = katalog[j];
                katalog[j] = katalog[j+1];
                katalog[j+1] = temp;
            }
        }
    }
}
int partition(int low, int high) 
{
    float pivot = katalog[high].rating;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) 
    {
        if (katalog[j].rating > pivot) 
        { 
            i++;
            Product temp = katalog[i];
            katalog[i] = katalog[j];
            katalog[j] = temp;
        }
    }
    Product temp = katalog[i + 1];
    katalog[i + 1] = katalog[high];
    katalog[high] = temp;
    return (i + 1);
}
void quickSortRating(int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(low, high);
        quickSortRating(low, pi - 1);
        quickSortRating(pi + 1, high);
    }
}
void tampilkanDaftar() 
{
    if (jumlahProduk == 0) 
    {
        cout << "Katalog kosong!\n";
        return;
    }
    cout << "\n" << setfill('=') << setw(85) << "" << endl;
    cout << setfill(' ') << left << setw(25) << "| Nama" << setw(15) << "| Kategori" 
         << setw(15) << "| Harga" << setw(10) << "| Stok" << setw(10) << "| Rating" << " |" << endl;
    cout << setfill('=') << setw(85) << "" << endl;
    for (int i = 0; i < jumlahProduk; i++) {
        cout << setfill(' ') << "| " << setw(23) << katalog[i].name 
             << "| " << setw(13) << katalog[i].category 
             << "| " << setw(13) << (long long)katalog[i].price 
             << "| " << setw(8) << katalog[i].stock 
             << "| " << setw(8) << katalog[i].rating << " |" << endl;
    }
    cout << setfill('=') << setw(85) << "" << endl;
}
void cariProduk() 
{
    bubbleSortName(); 
    char target[60];
    cout << "\nCari Nama Produk: "; cin.ignore(); cin.getline(target, 60);

    int low = 0, high = jumlahProduk - 1, foundIdx = -1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        int res = strcasecmp(katalog[mid].name, target);
        if (res == 0) 
        {
            foundIdx = mid;
            break;
        }
        if (res < 0) low = mid + 1;
        else high = mid - 1;
    }
    if (foundIdx != -1) 
    {
        cout << "\nDetail Produk:\n";
        cout << "Nama     : " << katalog[foundIdx].name << endl;
        cout << "Kategori : " << katalog[foundIdx].category << endl;
        cout << "Harga    : Rp " << (long long)katalog[foundIdx].price << endl;
        cout << "Stok     : " << katalog[foundIdx].stock << endl;
        cout << "Rating   : " << katalog[foundIdx].rating << endl;
    } 
    else 
    {
        cout << "Produk tidak ditemukan!\n"; 
    }
}
int main() 
{
    loadFromFile(); // Load data di awal
    int pilihan;
    do 
    {
        cout << "\n--- ShopEase CLI Management ---\n";
        cout << "1. Tambah Produk Baru\n";
        cout << "2. Tampilkan Daftar Produk\n";
        cout << "3. Cari Produk\n";
        cout << "4. Keluar dan Simpan\n";
        cout << "Pilih Menu: "; cin >> pilihan;

        switch (pilihan) 
        {
            case 1:
                tambahProduk();
                break;
            case 2:
                int mode;
                cout << "Pilih Mode Urut:\n1. Nama (Ascending)\n2. Rating (Descending)\nMode: ";
                cin >> mode;
                if (mode == 1) bubbleSortName();
                else if (mode == 2) quickSortRating(0, jumlahProduk - 1);
                tampilkanDaftar();
                break;
            case 3:
                cariProduk();
                break;
            case 4:
                saveToFile(); 
                cout << "Data disimpan. Sampai jumpa!\n"; 
                break;
            default:
                cout << "Pilihan tidak tersedia.\n";
        }
    }
    while (pilihan != 4);

    return 0;
}
