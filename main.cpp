#include <iostream>
using namespace std;

#include <fstream>

// include file .h
#include "menu.h"
#include "tabungan.h"

// string
#include <string.h>

int main()
{


    // memanggil fungsi createFiles untuk membuat file text jika belum ada
    createFile();

    // memanggil fungsi openFiles untuk membuka file dan menyimpan data tabungan dalam array
    openFiles(tabungans, size);
    tampilMenu();
    return 0;
}

