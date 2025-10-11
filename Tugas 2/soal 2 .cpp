#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk menyimpan data siswa
struct Node {
    string nama;  // Nama siswa
    int nilai;    // Nilai siswa
    Node* next;   // Pointer ke node berikutnya
};

Node* head = nullptr;  // Pointer ke node pertama (head) linked list

// Fungsi untuk menyisipkan data siswa secara terurut ascending berdasarkan nilai
void insertSorted(string nama, int nilai) {
    Node* newNode = new Node{nama, nilai, nullptr};  // Membuat node baru

    // Jika linked list kosong atau nilai lebih kecil dari nilai head,
    // maka node baru menjadi head
    if (head == nullptr || nilai < head->nilai) {
        newNode->next = head;
        head = newNode;
    } else {
        // Cari posisi yang tepat untuk menyisipkan node baru
        Node* temp = head;
        while (temp->next != nullptr && temp->next->nilai < nilai) {
            temp = temp->next;
        }
        // Sisipkan node baru setelah node temp
        newNode->next = temp->next;
        temp->next = newNode;
    }

    cout << "Data berhasil disisipkan secara terurut.\n";
}

// Fungsi untuk menampilkan seluruh data siswa dalam linked list
void tampilkanData() {
    if (head == nullptr) {
        cout << "Belum ada data.\n";  // Jika list kosong, tampilkan pesan
        return;
    }

    Node* temp = head;
    int no = 1;
    cout << "\nData Siswa (Terurut Ascending):\n";
    // Traversal linked list untuk menampilkan semua node
    while (temp != nullptr) {
        cout << no << ". " << temp->nama << " - " << temp->nilai << endl;
        temp = temp->next;
        no++;
    }
}

// Fungsi untuk menghapus seluruh node di linked list untuk mencegah memory leak
void hapusSemuaData() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;  // Simpan alamat node berikutnya
        delete current;              // Hapus node sekarang
        current = next;              // Lanjut ke node berikutnya
    }
    head = nullptr;  // Set head menjadi nullptr menandakan list kosong
}

int main() {
    int pilihan;
    string nama;
    int nilai;

    do {
        // Menu interaktif untuk pengguna
        cout << "\n=== Menu Sistem Nilai Terurut ===\n";
        cout << "1. Tambah Data Siswa (Terurut)\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan newline dari buffer input

        switch (pilihan) {
            case 1:
                // Input data siswa baru
                cout << "Masukkan Nama Siswa: ";
                getline(cin, nama);
                cout << "Masukkan Nilai Siswa: ";
                cin >> nilai;
                // Validasi nilai agar dalam rentang 0-100
                if (nilai < 0 || nilai > 100) {
                    cout << "Nilai harus antara 0 dan 100!\n";
                } else {
                    insertSorted(nama, nilai);  // Tambah data secara terurut
                }
                break;
            case 2:
                tampilkanData();  // Tampilkan semua data siswa
                break;
            case 3:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 3);

    hapusSemuaData();  // Bersihkan memori sebelum program selesai

    return 0;
}
