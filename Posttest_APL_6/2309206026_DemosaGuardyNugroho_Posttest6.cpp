#include <iostream>
using namespace std;

struct SUV {
    float id;
    string merk;
    struct data {
        string model;
        int tahun;
    };
    struct data dt;
};

float id = 5;
int n = 4;

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
    cout << "5. Merge Sort Ascending" << endl;
    cout << "6. Bubble Sort Descending"<< endl;
    cout << "7. Insertion Sort Ascending"<< endl;
    cout << "8. Sequential Search Descending"<< endl;
    cout << "9. Binary Search Ascending"<< endl;
    cout << "10. Keluar"<< endl;
}

bool lihatdata(SUV *suv, int n) {
    if (n == 0) {
        cout << "data tidak tersedia. mohon tambahkan data" << endl;
        return false;
    } else {
        for (int i = 0; i < n; i++) {
            cout<<"ID : "<<suv[i].id<<endl;
            cout<<"merk : "<< suv[i].merk<<endl;
            cout<<"model : "<<suv[i].dt.model<<endl;
            cout<<"tahun : "<<suv[i].dt.tahun<<endl;
            cout<<"============================================\n";
        }
        return true;
    }
}

void hapusdata(SUV *suv, int& n) {
    int nomor;

    if (lihatdata(suv, n)) {
        cout << "masukkan id suv yang ingin di hapus : ";
        cin >> nomor;
        cin.ignore();

        if (nomor < 1 || nomor > n) {
            cout << "Nomor SUV tidak valid." << endl;
            return;
        }

        for (int i = nomor - 1; i < n; ++i) {
            suv[i] = suv[i + 1];
        }
        cout << "data berhasil di hapus" << endl;
        n--;
    } else {
        cout << "input tidak valid" << endl;
    }
}

void tambahdata(SUV *suv, int& n) {
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
    suv[n].id = id++;
    n++;
    cout << "data berhasil ditambahkan\n";
}

void ubahdata(SUV *suv, int& n) {
    int nomor;
    string tambah, model;
    if (lihatdata(suv, n)) {
        cout << "masukkan id suv yang ingin di ubah : ";
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

void merge(SUV *suv, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    SUV Left[n1], Right[n2];

    for (int i = 0; i < n1; i++)
        Left[i] = suv[left + i];
    for (int j = 0; j < n2; j++)
        Right[j] = suv[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (Left[i].dt.tahun <= Right[j].dt.tahun) {
            suv[k] = Left[i];
            i++;
        } else {
            suv[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        suv[k] = Left[i];
        i++;
        k++;
    }
    while (j < n2) {
        suv[k] = Right[j];
        j++;
        k++;
    }
}
void mergesort(SUV *suv, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergesort(suv, left, middle);
        mergesort(suv, middle + 1, right);

        merge(suv, left, middle, right);
    }
}
void bubblesort(SUV *suv, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (suv[j].dt.model > suv[j+1].dt.model) {
                SUV temp = suv[j];
                suv[j] = suv[j+1];
                suv[j+1] = temp;
            }
        }
    }
}
void insertionSort(SUV *suv, int n) {
    int i, j;
    SUV key;
    for (i = 1; i < n; i++) {
        key = suv[i];
        j = i - 1;

        while (j >= 0 && suv[j].id > key.id) {
            suv[j + 1] = suv[j];
            j = j - 1;
        }
        suv[j + 1] = key;
    }
}

int sequentialsearch(SUV *suv, int n, string target) {
    for (int i = 0; i < n; ++i) {
        if (suv[i].dt.model == target) {
            return i; 
        }
    }
    return -1; 
}

int binarysearch(SUV *suv, int n, float target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (suv[mid].id == target)
            return mid;
        if (suv[mid].id < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void pilihmenu(SUV *suv, int& n) {
    int pilih;
    int index1, index2;
    string target;
    int target1;
    menu();
    cout << "Masukkan nomor menu yang ingin anda pilih : ";
    cin >> pilih;
    cin.ignore();

    switch (pilih) {
    case 1:
        tambahdata(suv, n);
        break;
    case 2:
        lihatdata(suv, n);
        break;
    case 3:
        ubahdata(suv, n);
        break;
    case 4:
        hapusdata(suv, n);
        break;
    case 5:
        mergesort(suv, 0, n-1);
        cout<<"data berhasil di sorting secara ascending dengan merge sort berdasarkan tahun"<<endl;
        break;
    case 6:
        bubblesort(suv, n);
        cout<<"data berhasil di sorting secara descending dengan bubble sort berdasarkan model"<<endl;
        break;
    case 7:
        insertionSort(suv, n);
        cout<<"data berhasil di sorting secara ascending dengan insertion sort berdasarkan ID"<<endl;
        break;
    case 8:
        cout << "Masukkan model mobil yang ingin Anda cari: ";
        getline(cin, target);
        for (char &c : target) {
            c = toupper(c);
        }
        index1 = sequentialsearch(suv, n, target);
        if (index1 != -1) {
            cout << "Mobil dengan model '" << target << "' ditemukan pada indeks: " << index1 << endl;
            cout << "Merk: " << suv[index1].merk << ", Model: " << suv[index1].dt.model << ", Tahun: " << suv[index1].dt.tahun << endl;
        } else {
            cout << "Mobil dengan model '" << target << "' tidak ditemukan dalam data." << endl;
        }
        break;
    case 9:
        cout << "Masukkan ID mobil yang ingin Anda cari: ";
        cin >> target1;

        index2 = binarysearch(suv, n, target1);
        if (index2 != -1) {
        cout << "Mobil dengan ID " << target1 << " ditemukan pada indeks: " << index2 << endl;
        cout << "Merk: " << suv[index2].merk << ", Model: " << suv[index2].dt.model << ", Tahun: " << suv[index2].dt.tahun << endl;
        } else {
        cout << "Mobil dengan ID " << target << " tidak ditemukan dalam data." << endl;
        }
        break;
    case 10:
        cout << "Keluar dari program." << endl;
        return;
    default:
        cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
    }

    pilihmenu(suv, n);
}

int main() {
    if (login()) {
        SUV suv[100] = {{1, "HYUNDAI", "PALISADE", 2020}, {2, "TOYOTA", "RUSH", 2019}, {3, "MITSHUBISHI", "PAJERO SPORT", 2018}, {4, "CHERY", "OMODA 5", 2023}};

        pilihmenu(&suv[0], n);
    }
    return 0;
}
