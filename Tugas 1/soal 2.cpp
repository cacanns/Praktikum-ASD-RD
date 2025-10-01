#include <iostream>
using namespace std;

void nilai(int *x, int y, int *z) { 
    // loop dari 1 sampai y
    for (int i = 1; i <= y; i++) { 
        *x += (i * i);  // tambahkan hasil kuadrat ke x
        *z *= (2 * i - 1); // kalikan bilangan ganjil ke z
    }
}

int main() {
    int a = 0, b, c = 1; // a dan c sebagai nilai awal
    cout << "Masukkan batas: ";
    cin >> b; // baca input y dari user
    nilai(&a, b, &c); // panggil prosedur untuk hitung x dan z
    cout << "Hasil x = " << a << ", Hasil z = " << c; // tampilkan hasil
    return 0;
}
