#include <iostream>
#include <string>

using namespace std;

struct Mobil {
    string merek;
    string tipe;
    int tahun;
    int harga;
    string status;
};

void tampilanAwal() {
    cout << "=======================================\n"
         << "          LAYANAN SEWA MOBIL           \n"
         << "=======================================\n"
         << "1. Daftar Mobil\n"
         << "2. Data Urut Terendah - Tertinggi\n"
         << "3. Mobil yang Tersedia\n"
         << "4. Pesan Mobil\n"
         << "Pilih menu: ";
}

void tampilkanDaftarMobil(Mobil mobil[], int jumlah) {
    cout << "Daftar Mobil\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Merek: " << mobil[i].merek << endl;
        cout << "Tipe: " << mobil[i].tipe << endl;
        cout << "Tahun: " << mobil[i].tahun << endl;
        cout << "Harga: " << mobil[i].harga << " per hari" << endl;
        cout << "Status: " << mobil[i].status << endl << endl;
    }
}

void urutDataMobil(Mobil mobil[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (mobil[j + 1].harga < mobil[j].harga) {
                swap(mobil[j + 1], mobil[j]);
            }
        }
    }
}

void tampilkanMobilTersedia(Mobil mobil[], int jumlah) {
    cout << "Mobil yang Tersedia\n";
    for (int i = 0; i < jumlah; i++) {
        if (mobil[i].status == "tersedia") {
            cout << "Merek: " << mobil[i].merek << endl;
            cout << "Tipe: " << mobil[i].tipe << endl;
            cout << "Tahun: " << mobil[i].tahun << endl;
            cout << "Harga: " << mobil[i].harga << " per hari" << endl;
            cout << "Status: " << mobil[i].status << endl << endl;
        }
    }
}

int main() {
    int pilihan;
    char ulang;
    const int jumlahMobil = 5;
    Mobil mobil[jumlahMobil] = {
        {"Toyota Avanza", "MPV", 2020, 300000, "tersedia"},
        {"Honda Jazz", "Hatchback", 2019, 350000, "tersedia"},
        {"Mitsubishi Pajero Sport", "SUV", 2021, 500000, "tersedia"},
        {"BMW 320i", "Sedan", 2018, 800000, "tersedia"},
        {"Mercedes-Benz GLC", "SUV", 2022, 1000000, "tersedia"}
    };

    do {
        system("cls");
        tampilanAwal();
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                system("cls");
                tampilkanDaftarMobil(mobil, jumlahMobil);
                break;
            case 2:
                system("cls");
                urutDataMobil(mobil, jumlahMobil);
                tampilkanDaftarMobil(mobil, jumlahMobil);
                break;
            case 3:
                system("cls");
                tampilkanMobilTersedia(mobil, jumlahMobil);
                break;
            case 4: {
                string merek;
                int lamaSewa;
                bool mobilTersedia = false;

                cout << "Masukkan merek mobil yang ingin disewa: ";
                cin.ignore();
                getline(cin, merek);

                cout << "Masukkan lama sewa (dalam hari): ";
                cin >> lamaSewa;
                system("cls");

                for (int i = 0; i < jumlahMobil; i++) {
                    if (mobil[i].merek == merek && mobil[i].status == "tersedia") {
                        mobilTersedia = true;
                        cout << "=======================================\n";
                        cout << "      Pemesanan mobil Anda berhasil!    \n";
                        cout << "=======================================\n";
                        cout << "---------------------------------------\n";
                        cout << "Detail mobil yang sudah dipesan:       \n";
                        cout << "---------------------------------------\n";
                        cout << "Merek: " << mobil[i].merek << endl;
                        cout << "Tipe: " << mobil[i].tipe << endl;
                        cout << "Tahun: " << mobil[i].tahun << endl;
                        cout << "Harga per hari: " << mobil[i].harga << endl;
                        cout << "Lama sewa: " << lamaSewa << " hari" << endl;
                        cout << "Total biaya: " << mobil[i].harga * lamaSewa << endl;
                        break;
                    }
                }

                if (!mobilTersedia) {
                    cout << "Mobil tidak tersedia." << endl;
                }
                break;
            }
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
        cout << "Apakah Anda ingin melanjutkan (y/n)? ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}
