
#include <string> // mengikutsertakan library string untuk menggunakan tipe data string
using namespace std; // menggunakan namespace std untuk mempersingkat penulisan kode

//kamus
void createFile(); // fungsi untuk membuat file txt jika belum ada
void openFiles(Tabungan tabungans[], int &size); // fungsi untuk membuka file dan menyimpan data tabungan dalam array
void lihatTabungan(Tabungan tabungans[], int size); // fungsi untuk menampilkan daftar tabungan
void tambahTabungan(Tabungan tabungans[], int &size); // fungsi untuk menambah tabungan baru
void editTabungan(Tabungan tabungans[], int size); // fungsi untuk mengedit tabungan
void hapusTabungan(Tabungan tabungans[], int &size); // fungsi untuk menghapus tabungan
void saveFiles(Tabungan tabungans[], int size); // fungsi untuk menyimpan data tabungan ke file

// konstanta untuk ukuran maksimum array
const int MAX_SIZE = 100;

// class untuk menyimpan data tabungan
class Tabungan {
  public:
    // deklarasi variabel anggota
    string nama; // nama tabungan
    double saldo_awal; // uang yang sudah saldo_awal
    double target; // target tabungan
    double simpanan_bulanan; // jumlah uang yang disimpan setiap bulan
    double waktu; // estimasi waktu yang dibutuhkan untuk mencapai target

    // deklarasi fungsi anggota
    void hitungWaktu(); // fungsi untuk menghitung estimasi waktu tabungan
};

// definisi fungsi hitungWaktu
void Tabungan::hitungWaktu() {
  // menghitung jumlah tabungan setelah simpanan bulanan
  double saldo_terbaru = saldo_awal + simpanan_bulanan;

  // menghitung jumlah bulan yang dibutuhkan
  double bulan = 0;

  // menggunakan loop while untuk mengulang sampai saldo terbaru mencapai target
  while (saldo_terbaru < target) {
    // menambahkan simpanan bulanan ke saldo terbaru
    saldo_terbaru = saldo_terbaru + simpanan_bulanan;
    // menambahkan satu ke bulan
    bulan++;
  }

  // mengisi nilai waktu dengan bulan
  waktu = bulan;
}

// fungsi untuk membuat file txt jika belum ada
void createFile() {
  // mendeklarasikan variabel untuk nama file
  string filename = "tabungan.txt";

  // mendeklarasikan objek ifstream untuk membaca file
  ifstream fin;

  // membuka file dengan nama file
  fin.open(filename);

  // mengecek apakah file sudah ada atau tidak
  if (fin.fail()) {
    // jika tidak ada, menutup file dan membuat file baru dengan ofstream
    fin.close();
    ofstream fout;
    fout.open(filename);
    fout.close();
    // menampilkan pesan sukses
    cout << "File berhasil dibuat.\n";
  } else {
    // jika sudah ada, menutup file dan tidak perlu membuat file baru
    fin.close();
    // menampilkan pesan informasi
    cout << "File sudah ada.\n";
  }
}

// fungsi untuk membuka file dan menyimpan data tabungan dalam array
void openFiles(Tabungan tabungans[], int &size) {
  // mendeklarasikan variabel untuk nama file
  string filename = "tabungan.txt";

  // mendeklarasikan objek ifstream untuk membaca file
  ifstream fin;

  // membuka file dengan nama file
  fin.open(filename);

  // mengecek apakah file berhasil dibuka atau tidak
  if (fin.fail()) {
    // jika gagal, menampilkan pesan error dan keluar dari fungsi
    cout << "File tidak dapat dibuka.\n";
    return;
  }

  // mendeklarasikan variabel untuk menyimpan data dari file
  string nama;
  double saldo_awal, target, simpanan_bulanan, waktu;

  // menggunakan loop while untuk membaca data dari file sampai akhir file
  while (fin >> nama >> saldo_awal >> target >> simpanan_bulanan >> waktu) {
    // membuat objek Tabungan dengan data dari file
    Tabungan tabungan;
    tabungan.nama = nama;
    tabungan.saldo_awal = saldo_awal;
    tabungan.target = target;
    tabungan.simpanan_bulanan = simpanan_bulanan;
    tabungan.waktu = waktu;

    // menambahkan objek Tabungan ke array tabungans pada indeks size
    tabungans[size] = tabungan;

    // menambahkan satu ke size
    size++;
  }

  // menutup file setelah selesai membaca
  fin.close();

  // menampilkan pesan sukses
  cout << "File berhasil dibuka.\n";
}

// fungsi untuk menampilkan menu utama
void tampilMenu() {
  cout << "Selamat datang di aplikasi celenganku versi c++\n";
  cout << "Pilih menu yang ingin kamu lakukan:\n";
  cout << "1. Tambah tabungan baru\n";
  cout << "2. Lihat daftar tabungan\n";
  cout << "3. Edit tabungan\n";
  cout << "4. Hapus tabungan\n";
  cout << "5. Keluar\n";
}

// fungsi untuk menambah tabungan baru
void tambahTabungan(Tabungan tabungans[], int &size) {
  // mengecek apakah array tabungans sudah penuh atau tidak
  if (size == MAX_SIZE) {
    // jika penuh, menampilkan pesan error dan keluar dari fungsi
    cout << "Tidak dapat menambah tabungan lagi karena sudah mencapai batas maksimum.\n";
    return;
  }

  // mendeklarasikan variabel untuk input
  string nama;
  double saldo_awal, target, simpanan_bulanan;

  // meminta input dari user
  cout << "Masukkan nama tabungan: ";
  cin >> nama;

  cout << "Masukkan saldo awal: ";
  cin >> saldo_awal;

  cout << "Masukkan target tabungan: ";
  cin >> target;

  cout << "Masukkan jumlah uang yang disimpan setiap bulan: ";
  cin >> simpanan_bulanan;

  // membuat objek Tabungan dengan data input
  Tabungan tabungan;
  tabungan.nama = nama;
  tabungan.saldo_awal = saldo_awal;
  tabungan.target = target;
  tabungan.simpanan_bulanan = simpanan_bulanan;

  // memanggil fungsi hitungWaktu untuk menghitung estimasi waktu tabungan
  tabungan.hitungWaktu();

  // menambahkan objek Tabungan ke array tabungans pada indeks size
  tabungans[size] = tabungan;

  // menambahkan satu ke size
  size++;

  // menampilkan pesan sukses
  cout << "Tabungan berhasil ditambahkan!\n";
}

// fungsi untuk menampilkan daftar tabungan
void lihatTabungan(Tabungan tabungans[], int size) {
  // mengecek apakah array tabungans kosong atau tidak
  if (size == 0) {
    // jika kosong, menampilkan pesan tidak ada tabungan
    cout << "Belum ada tabungan yang ditambahkan.\n";
    return;
  }

  // jika tidak kosong, menampilkan header tabel
  cout << "Daftar tabungan:\n";
  cout << "No\tNama\tSaldo Awal\tTarget\tSimpanan Bulanan\tWaktu\n";

  // menggunakan loop for untuk menampilkan data setiap tabungan dalam array tabungans
  for (int i = 0; i < size; i++) {
    // mendapatkan objek Tabungan dari array tabungans berdasarkan indeks i
    Tabungan tabungan = tabungans[i];

    // menampilkan data objek Tabungan ke layar dengan format tabel
    cout << i + 1 << "\t" << tabungan.nama << "\t" << tabungan.saldo_awal << "\t" << tabungan.target << "\t" << tabungan.simpanan_bulanan << "\t" << tabungan.waktu << "\n";
  }

  // menampilkan menu catat tabungan nominal
    // menampilkan menu catat tabungan nominal
  cout << "Pilih nomor tabungan yang ingin kamu catat nominalnya, atau ketik 0 untuk kembali ke menu utama.\n";
// mendeklarasikan variabel untuk input
  int nomor;
  double nominal;

  // meminta input nomor tabungan dari user
  cout << "Masukkan nomor tabungan: ";
  cin >> nomor;

  // mengecek apakah nomor valid atau tidak
  if (nomor < 0 || nomor > size) {
    // jika tidak valid, menampilkan pesan error dan keluar dari fungsi
    cout << "Nomor tabungan tidak valid. Silakan coba lagi.\n";
    return;
  }

  // mengecek apakah nomor sama dengan 0 atau tidak
  if (nomor == 0) {
    // jika sama dengan 0, menampilkan pesan kembali ke menu utama dan keluar dari fungsi
    cout << "Kembali ke menu utama.\n";
    return;
  }

  // mendapatkan objek Tabungan dari array tabungans berdasarkan nomor
  Tabungan &tabungan = tabungans[nomor - 1];

  // meminta input nominal tabungan dari user
  cout << "Masukkan nominal tabungan: ";
  cin >> nominal;

  // menambahkan nominal ke saldo awal tabungan
  tabungan.saldo_awal += nominal;

  // menghitung ulang estimasi waktu tabungan dengan fungsi hitungWaktu
  tabungan.hitungWaktu();

  // menampilkan pesan sukses
  cout << "Tabungan berhasil dicatat!\n";
}
// fungsi untuk mengedit tabungan
void editTabungan(Tabungan tabungans[], int size) {
  // mengecek apakah array tabungans kosong atau tidak
  if (size == 0) {
    // jika kosong, menampilkan pesan tidak ada tabungan
    cout << "Belum ada tabungan yang ditambahkan.\n";
    return;
  }

  // jika tidak kosong, menampilkan header tabel
  cout << "Daftar tabungan:\n";
  cout << "No\tNama\tSaldo Awal\tTarget\tSimpanan Bulanan\tWaktu\n";

  // menggunakan loop for untuk menampilkan data setiap tabungan dalam array tabungans
  for (int i = 0; i < size; i++) {
    // mendapatkan objek Tabungan dari array tabungans berdasarkan indeks i
    Tabungan tabungan = tabungans[i];

    // menampilkan data objek Tabungan ke layar dengan format tabel
    cout << i + 1 << "\t" << tabungan.nama << "\t" << tabungan.saldo_awal << "\t" << tabungan.target << "\t" << tabungan.simpanan_bulanan << "\t" << tabungan.waktu << "\n";
  }

  // menampilkan menu edit tabungan
  cout << "Pilih nomor tabungan yang ingin kamu edit, atau ketik 0 untuk kembali ke menu utama.\n";

  // mendeklarasikan variabel untuk input
  int nomor;
  string nama;
  double saldo_awal, target, simpanan_bulanan;

  // meminta input nomor tabungan dari user
  cout << "Masukkan nomor tabungan: ";
  cin >> nomor;

  // mengecek apakah nomor valid atau tidak
  if (nomor < 0 || nomor > size) {
    // jika tidak valid, menampilkan pesan error dan keluar dari fungsi
    cout << "Nomor tabungan tidak valid. Silakan coba lagi.\n";
    return;
  }

  // mengecek apakah nomor sama dengan 0 atau tidak
  if (nomor == 0) {
    // jika sama dengan 0, menampilkan pesan kembali ke menu utama dan keluar dari fungsi
    cout << "Kembali ke menu utama.\n";
    return;
  }

  // mendapatkan objek Tabungan dari array tabungans berdasarkan nomor
  Tabungan &tabungan = tabungans[nomor - 1];

  // meminta input data baru dari user
  cout << "Masukkan nama tabungan baru: ";
  cin >> nama;

  cout << "Masukkan saldo awal baru: ";
  cin >> saldo_awal;

  cout << "Masukkan target tabungan baru: ";
    cin >> target;

  cout << "Masukkan jumlah uang yang disimpan setiap bulan baru: ";
  cin >> simpanan_bulanan;

  // mengubah data objek Tabungan dengan data baru
  tabungan.nama = nama;
  tabungan.saldo_awal = saldo_awal;
  tabungan.target = target;
  tabungan.simpanan_bulanan = simpanan_bulanan;

  // menghitung ulang estimasi waktu tabungan dengan fungsi hitungWaktu
  tabungan.hitungWaktu();

  // menampilkan pesan sukses
  cout << "Tabungan berhasil diedit!\n";
}
// fungsi untuk menghapus tabungan
void hapusTabungan(Tabungan tabungans[], int &size) {
  // mengecek apakah array tabungans kosong atau tidak
  if (size == 0) {
    // jika kosong, menampilkan pesan tidak ada tabungan
    cout << "Belum ada tabungan yang ditambahkan.\n";
    return;
  }

  // jika tidak kosong, menampilkan header tabel
  cout << "Daftar tabungan:\n";
  cout << "No\tNama\tSaldo Awal\tTarget\tSimpanan Bulanan\tWaktu\n";

  // menggunakan loop for untuk menampilkan data setiap tabungan dalam array tabungans
  for (int i = 0; i < size; i++) {
    // mendapatkan objek Tabungan dari array tabungans berdasarkan indeks i
    Tabungan tabungan = tabungans[i];

    // menampilkan data objek Tabungan ke layar dengan format tabel
    cout << i + 1 << "\t" << tabungan.nama << "\t" << tabungan.saldo_awal << "\t" << tabungan.target << "\t" << tabungan.simpanan_bulanan << "\t" << tabungan.waktu << "\n";
  }

  // menampilkan menu hapus tabungan
  cout << "Pilih nomor tabungan yang ingin kamu hapus, atau ketik 0 untuk kembali ke menu utama.\n";

  // mendeklarasikan variabel untuk input
  int nomor;

  // meminta input nomor tabungan dari user
  cout << "Masukkan nomor tabungan: ";
  cin >> nomor;

  // mengecek apakah nomor valid atau tidak
  if (nomor < 0 || nomor > size) {
    // jika tidak valid, menampilkan pesan error dan keluar dari fungsi
    cout << "Nomor tabungan tidak valid. Silakan coba lagi.\n";
    return;
  }

  // mengecek apakah nomor sama dengan 0 atau tidak
  if (nomor == 0) {
    // jika sama dengan 0, menampilkan pesan kembali ke menu utama dan keluar dari fungsi
    cout << "Kembali ke menu utama.\n";
    return;
  }

  // menggunakan loop for untuk menggeser data tabungan setelah nomor yang dihapus ke kiri
  for (int i = nomor - 1; i < size - 1; i++) {
    // mengisi data tabungan pada indeks i dengan data tabungan pada indeks i + 1
    tabungans[i] = tabungans[i + 1];
  }
   // mengurangi satu dari size
  size--;

  // menampilkan pesan sukses
  cout << "Tabungan berhasil dihapus!\n";
}
// fungsi untuk menyimpan data tabungan ke file
void saveFiles(Tabungan tabungans[], int size) {
  // mendeklarasikan variabel untuk nama file
  string filename = "tabungan.txt";

  // mendeklarasikan objek ofstream untuk menulis file
  ofstream fout;

  // membuka file dengan nama file
  fout.open(filename);

  // mengecek apakah file berhasil dibuka atau tidak
  if (fout.fail()) {
    // jika gagal, menampilkan pesan error dan keluar dari fungsi
    cout << "File tidak dapat dibuka.\n";
    return;
  }

  // menggunakan loop for untuk menulis data setiap tabungan dalam array tabungans ke file
  for (int i = 0; i < size; i++) {
    // mendapatkan objek Tabungan dari array tabungans berdasarkan indeks i
    Tabungan tabungan = tabungans[i];

    // menulis data objek Tabungan ke file dengan spasi sebagai pemisah
    fout << tabungan.nama << " " << tabungan.saldo_awal << " " << tabungan.target << " " << tabungan.simpanan_bulanan << " " << tabungan.waktu << "\n";
  }

  // menutup file setelah selesai menulis
  fout.close();

  // menampilkan pesan sukses
  cout << "File berhasil disimpan.\n";
}

