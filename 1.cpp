#include <iostream>
#include <string>
using namespace std;

struct Pasien {
    string nama;
    string jenis;
    int umur;
    int tingkatDarurat;
};

int main() {
    int n;
    cout << "Masukkan jumlah pasien: ";
    cin >> n;
    cin.ignore();

    Pasien* daftar = new Pasien[n];

    for (int i = 0; i < n; i++) {
        cout << "\nPasien " << i + 1 << ":\n";
        cout << "Nama hewan: ";
        getline(cin, daftar[i].nama);
        cout << "Jenis hewan: ";
        getline(cin, daftar[i].jenis);
        cout << "Umur: ";
        cin >> daftar[i].umur;
        cout << "Tingkat darurat (1-5): ";
        cin >> daftar[i].tingkatDarurat;
        cin.ignore();
    }

    // Urutkan berdasarkan tingkat darurat tertinggi
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (daftar[j].tingkatDarurat > daftar[i].tingkatDarurat) {
                Pasien temp = daftar[i];
                daftar[i] = daftar[j];
                daftar[j] = temp;
            }
        }
    }

    cout << "\n=== Urutan Penanganan Pasien ===\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << daftar[i].nama
             << " (" << daftar[i].jenis << ", " << daftar[i].umur << " tahun)"
             << " - Darurat " << daftar[i].tingkatDarurat << endl;
    }

    delete[] daftar;
    return 0;
}
