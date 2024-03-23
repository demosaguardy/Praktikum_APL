#include <iostream>
#include <string>
using namespace std;

struct SUV {
    string merk;
    struct data{
        string model;
        int tahun;
    };
    struct data dt;
};

bool login() {
    string username, password;
    int coba = 0;
    int max_coba = 3;
    string correctuser = "DEMOSA GUARDY NUGROHO";
    string correctpass = "026";

    while (coba < max_coba) {
        cout << "masukkan nama anda : ";
        getline(cin, username);

        for (char &c : username) {
            c = toupper(c);
        }
        cout << "masukkan NIM anda : ";
        getline(cin, password);

        if (username == correctuser && password == correctpass) {
            cout << "login berhasil" << endl;
            return true;
        } else {
            cout << "nama atau NIM anda salah. silahkan coba lagi" << endl;
            coba++;
        }
    }
    cout << "anda telah mencoba login sebanyak " << max_coba << " kali. anda tidak akan bisa login untuk beberapa saat" << endl;
    return false;
}

void menu() {
    cout << "MENU" << endl;
    cout << "1. Tambah Data Mobil " << endl;
    cout << "2. Lihat Data Mobil" << endl;
    cout << "3. Ubah Data Mobil" << endl;
    cout << "4. Hapus Data Mobil" << endl;
    cout << "5. keluar" << endl;
}

bool lihatdata(SUV suv[], int n) {
    if (n == 0) {
        cout << "data tidak tersedia. mohon tambahkan data" << endl;
        return false;
    } else {
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ". " << suv[i].merk <<endl;
            cout<<"model : "<<suv[i].dt.model<<endl;
            cout<<"tahun : "<<suv[i].dt.tahun<<endl;
            cout<<"============================================\n";
        }
        return true;
    }
}

void hapusdata(SUV suv[], int& n) {
    int nomor;

    if (lihatdata(suv, n)) {
        cout << "masukkan nomor suv yang ingin di hapus : ";
        cin >> nomor;
        cin.ignore();

        if (nomor < 1 || nomor > n) {
            cout << "Nomor SUV tidak valid." << endl;
            return;
        }

        for (int i = nomor - 1; i < n; ++i) {
           suv[i].merk = suv[i + 1 ].merk;
           suv[i].dt.model = suv[i + 1 ].dt.model;
           suv[i].dt.tahun = suv[i + 1 ].dt.tahun;
        }
        cout << "data berhasil di hapus" << endl;
        n--;
    } else {
        cout << "input tidak valid" << endl;
    }
}

void tambahdata(SUV suv[], int& n) {
    string tambah,model;
    cout << "masukkan merk mobil suv : ";
    getline(cin, tambah);
    for (char &c : tambah) {
        c = toupper(c);
    }
    suv[n].merk = tambah;
    cout<<"masukkan model suv : ";
    getline(cin, model);
    for (char &c : model) {
        c = toupper(c);
    }
    suv[n].dt.model = model;
    cout<<"masukkan tahun keluar mobil : ";
    cin>>suv[n].dt.tahun;
    n++;
    cout << "data berhasil ditambahkan\n";
}

void ubahdata(SUV suv[], int& n) {
    int nomor;
    string tambah, model;
    if (lihatdata(suv, n)) {
        cout << "masukkan nomor suv yang ingin di ubah : ";
        cin >> nomor;
        cin.ignore();

        if (nomor < 1 || nomor > n) {
            cout << "Nomor SUV tidak valid." << endl;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (i == nomor - 1) {
                cout << "masukkan merk baru : ";
                getline(cin, tambah);
                for (char &c : tambah) {
                    c = toupper(c);
                }
                suv[i].merk = tambah;
                cout << "masukkan model baru : ";
                getline(cin, model);
                for (char &c : model) {
                    c = toupper(c);
                }
                suv[i].dt.model = model;
                cout << "masukkan tahun rilis mobil : ";
                cin >> suv[i].dt.tahun;
                cout << "data berhasil diubah" << endl;
                return;
            }
        }
    } else {
        cout << "Tidak ada data SUV untuk diubah." << endl;
    }
}


void pilihmenu(SUV suv[], int& n) {
    char pilih;
    menu();
    cout << "Masukkan nomor menu yang ingin anda pilih : ";
    cin >> pilih;
    cin.ignore();

    switch (pilih) {
    case '1':
        tambahdata(suv, n);
        break;
    case '2':
        lihatdata(suv, n);
        break;
    case '3':
        ubahdata(suv, n);
        break;
    case '4':
        hapusdata(suv, n);
        break;
    case '5':
        cout << "Keluar dari program." << endl;
        return;
    default:
        cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
    }

    pilihmenu(suv, n);
}

int main() {
    if (login()) {
        int n = 4;
        SUV suv[100] = {{"HYUNDAI", "PALISADE", 2020}, {"TOYOTA", "RUSH", 2019}, {"MITSHUBISHI", "PAJERO SPORT", 2018}, {"CHERY", "OMODA 5", 2023}};

        pilihmenu(suv, n);
    }
    return 0;
}
