#include <iostream>
using namespace std;

/* Prosedur untuk menghitung jumlah bilangan ganjil dari 1 sampai y.
   Parameter:
   - x : pointer untuk menyimpan hasil
   - y : batas atas perhitungan */
   
void hitungGanjil(int *x, int y) {
    *x = 0; // mulai dari 0
    for (int i = 1; i <= y; i++) {
        if (i % 2 != 0) {   // cek ganjil
            *x += i;        // tambah ke hasil
        }
    }
}

int main() { 
    int hasil; 
    int y;     
    cout << "Masukkan nilai y: ";
    cin >> y; // input batas atas
    hitungGanjil(&hasil, y); // panggil prosedur
    cout << "Jumlah bilangan ganjil dari 1 sampai " << y 
         << " adalah: " << hasil << endl;
    return 0;
}
