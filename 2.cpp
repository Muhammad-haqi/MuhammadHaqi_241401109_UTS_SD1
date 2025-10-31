#include <iostream>
#include <string>
using namespace std;

// Struktur Node
struct node {
    string judul;
    int tahun;
    int rating;
    node *next;
};

node *head = NULL;
node *tail = NULL;

// Tambah di depan
void insertFirst(string j, int t, int r) {
    node *newNode = new node;
    newNode->judul = j;
    newNode->tahun = t;
    newNode->rating = r;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Tambah di belakang
void insertLast(string j, int t, int r) {
    node *newNode = new node;
    newNode->judul = j;
    newNode->tahun = t;
    newNode->rating = r;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Tambah di tengah (setelah judul tertentu)
void insertAfter(string target, string j, int t, int r) {
    if (head == NULL) {
        cout << "List masih kosong, tambah data dulu!\n";
        return;
    }

    node *p = head;
    while (p != NULL && p->judul != target) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Film dengan judul \"" << target << "\" tidak ditemukan.\n";
        return;
    }

    node *newNode = new node;
    newNode->judul = j;
    newNode->tahun = t;
    newNode->rating = r;
    newNode->next = p->next;
    p->next = newNode;

    if (p == tail) {
        tail = newNode;
    }
}

// Hapus film berdasarkan judul
void deleteFilm(string j) {
    if (head == NULL) {
        cout << "Daftar film kosong.\n";
        return;
    }

    node *hapus = head;
    node *prev = NULL;

    // Cari node dengan judul yang sesuai
    while (hapus != NULL && hapus->judul != j) {
        prev = hapus;
        hapus = hapus->next;
    }

    // Jika tidak ditemukan
    if (hapus == NULL) {
        cout << "Film dengan judul \"" << j << "\" tidak ditemukan.\n";
        return;
    }

    // Jika node yang dihapus adalah node pertama
    if (hapus == head) {
        head = head->next;
        if (hapus == tail) tail = NULL;
    } else {
        prev->next = hapus->next;
        if (hapus == tail) tail = prev;
    }

    delete hapus;
    cout << "\nFilm \"" << j << "\" berhasil dihapus.\n";
}

// Cetak daftar film
void printList() {
    node *temp = head;
    if (temp == NULL) {
        cout << "\nDaftar film kosong.\n";
        return;
    }

    cout << "\nDaftar Film Harry:\n";
    int count = 0;
    while (temp != NULL) {
        cout << temp->judul << " (" << temp->tahun << ") - " << temp->rating << endl;
        temp = temp->next;
        count++;
    }
    cout << "\nTotal film tersisa: " << count << endl;
}

// Fungsi Utama (Main)
int main() {
    int n;
    cout << "Masukkan jumlah film awal: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string judul;
        int tahun, rating;

        cout << "\nFilm " << i + 1 << ":\n";
        cout << "Judul: ";
        getline(cin, judul);
        cout << "Tahun: ";
        cin >> tahun;
        cout << "Rating: ";
        cin >> rating;
        cin.ignore();

        insertLast(judul, tahun, rating);
    }

    char hapus;
    cout << "\nApakah ingin menghapus film? (y/n): ";
    cin >> hapus;
    cin.ignore();

    if (hapus == 'y' || hapus == 'Y') {
        string target;
        cout << "Masukkan judul film yang sudah ditonton: ";
        getline(cin, target);
        deleteFilm(target);
    }

    printList();
    return 0;
}
