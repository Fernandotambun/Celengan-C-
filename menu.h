#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Kamus

void menu();
void lihatTabungan(tabungans, size);
void tambahTabungan(tabungans, size);
void editTabungan(tabungans, size);
void hapusTabungan(tabungans, size);
void saveFiles(tabungans, size);

void tampilMenu() {
  cout << "Selamat datang di aplikasi celenganku versi c++\n";
  cout << "Pilih menu yang ingin kamu lakukan:\n";
  cout << "1. Tambah tabungan baru\n";
  cout << "2. Lihat daftar tabungan\n";
  cout << "3. Edit tabungan\n";
  cout << "4. Hapus tabungan\n";
  cout << "5. Keluar\n";

  menu();
}

void menu()
{
    do{
        tampilMenu();

        char pilihan;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch(pilihan)
        {
            case '1':
            {
                // ke menu 1
                // cout << "Menu 1";
                system("cls");
                tambahTabungan(tabungans, size);
            }
            break;
            case '2':
            {
                // ke menu 2
                // cout << "Menu 2";
                system("cls");
                lihatTabungan(tabungans, size);
            }
            break;
            case '3':
            {
                // ke menu 3
                // cout << "Menu 3";
                system("cls");
                editTabungan(tabungans, size);
            }
            break;
            case '4':
            {
                // ke menu 3
                // cout << "Menu 3";
                system("cls");
                hapusTabungan(tabungans, size);
            }
            break;
            case '5':
            {
                // ke menu 3
                // cout << "Menu 3";
                system("cls");
                // jika pilihan 5, memanggil fungsi saveFiles untuk menyimpan data tabungan ke file
                saveFiles(tabungans, size);
                // menampilkan pesan terima kasih dan keluar dari loop
                cout << "Terima kasih telah menggunakan aplikasi celenganku versi c++\n";
            }
            break;
            default:
                // jika pilihan tidak valid, menampilkan pesan error
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    }(pilihan != 5);
}
