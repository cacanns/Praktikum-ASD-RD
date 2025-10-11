#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk linked list
struct Node {
    string nama;
    int nilai;
    Node* next;
};

// Pointer ke head (awal linked list)
Node* head = nullptr;

// Fungsi untuk menambahkan data siswa di akhir linked list
void tambahData(string nama, int nilai) {
    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->nilai = nilai;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Data berhasil ditambahkan.\n";
}

// Fungsi untuk menampilkan seluruh data siswa
void tampilkanData() {
    if (head == nullptr) {
        cout << "Belum ada data siswa.\n";
        return;
    }

    Node* temp = head;
    int no = 1;
    cout << "Data Siswa:\n";
    while (temp != nullptr) {
        cout << no << ". " << temp->nama << " - " << temp->nilai << endl;
        temp = temp->next;
        no++;
    }
}

// Fungsi untuk menghapus seluruh data dari linked list (untuk cleanup)
void hapusSemuaData() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

int main() {
    int pilihan;
    string nama;
    int nilai;

    do {
        cout << "\n=== Menu Sistem Nilai Siswa ===\n";
        cout << "1. Tambah Data Siswa\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan newline dari buffer

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Siswa: ";
                getline(cin, nama);
                cout << "Masukkan Nilai Siswa: ";
                cin >> nilai;
                if (nilai < 0 || nilai > 100) {
                    cout << "Nilai harus antara 0 dan 100!\n";
                } else {
                    tambahData(nama, nilai);
                }
                break;
            case 2:
                tampilkanData();
                break;
            case 3:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 3);

    // Hapus semua data sebelum keluar
    hapusSemuaData();

    return 0;
}
