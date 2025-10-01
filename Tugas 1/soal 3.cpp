#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan ukuran array: ";
    cin >> n;

    int *arr = new int[n]; // alokasi array dinamis sesuai ukuran n

    // proses input elemen array
    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i); // menyimpan elemen menggunakan pointer
    }

    // menampilkan array sebelum dibalik
    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    // membalik urutan elemen array dengan pointer
    int *awal = arr; // mereferensikan elemen pertama
    int *akhir = arr + n - 1; // mereferensikan elemen terakhir

    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;

        awal++;   // geser pointer ke arah depan
        akhir--;  // geser pointer ke arah belakang
    }

    // menampilkan array setelah dibalik
    cout << "Array sesudah dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    delete[] arr; // membebaskan memori yang telah dialokasikan
    return 0;
}
