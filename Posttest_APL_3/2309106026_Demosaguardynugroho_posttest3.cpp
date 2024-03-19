#include <iostream>
using namespace std;

bool login() {
    string username, password;
    int coba = 0;
    int max_coba = 3;
    string correctuser = "DEMOSA GUARDY NUGROHO";
    string correctpass = "026";

    while(coba < max_coba) {
        cout << "masukkan nama anda : ";
        getline(cin, username);

        for (char &c : username){
            c = toupper(c);
        }
        cout << "masukkan NIM anda : ";
        getline(cin, password);

        if(username == correctuser && password == correctpass){
            cout << "login berhasil" <<endl;
            return true;
        }else {
            cout << "nama atau NIM anda salah. silahkan coba lagi" << endl;
            coba++;
        }
    }
    cout << "anda telah mencoba login sebanyak " <<max_coba<< " kali. anda tidak akan bisa login untuk beberapa saat" <<endl;
    return false;
}

void menu(){
    cout<<"MENU"<<endl;
    cout<<"1. Tambah Data Mobil "<<endl;
    cout<<"2. Lihat Data Mobil"<<endl;
    cout<<"3. Ubah Data Mobil"<<endl;
    cout<<"4. Hapus Data Mobil"<<endl;
    cout<<"5. keluar"<<endl;
}

bool lihatdata(string suv[], int n){
    if(n==0){
        cout<<"data tidak tersedia. mohon tambahkan data"<<endl;
        return false;
            }
    else{
        for(int i=0; i<n; i++){
        cout<<i+1<<". "<<suv[i]<<endl;
            }
        return true;
        }
}   
void hapusdata(string suv[], int& n){
    int nomor;

    if(lihatdata(suv,n)){;
                
        cout<<"masukkan nomor suv yang ingin di hapus : ";
        cin>>nomor;
        cin.ignore();
        for(int i=nomor-1; i<n; ++i){
            suv[i]=suv[i+1];
            }
        cout<<"data berhasil di hapus"<<endl;
        n--; 
        }
        else{
            cout<<"input tidak valid"<<endl;
        }
    
}

void tambahdata(string suv[], int& n){
    string tambah;
    cout<<"masukkan merk mobil suv : ";
    getline(cin, tambah);
    for (char &c : tambah){
        c = toupper(c);
    }
    suv[n++]=tambah;
    cout<<"data berhasil ditambahkan\n";
    
}

void ubahdata(string suv[], int& n){
    int nomor;
    string tambah;
    if(lihatdata(suv,n)){;
        cout<<"masukkan nomor suv yang ingin di ubah : ";
        cin>>nomor;
        cin.ignore();

        for(int i=0; i<n; i++){
            if(i == nomor-1){
                cout<<"masukkan suv baru : ";
                getline(cin, tambah);
                for (char &c : tambah){
                    c = toupper(c);
                }
                suv[i]=tambah;
                cout<<"data berhasil diubah"<<endl;
            }
        }
    }
}
void pilihmenu(string suv[], int& n) {
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
int main(){
    if(login()){
       int n=4;
       string suv[100] ={"HYUNDAI PALISADE", "TOYOTA RUSH", "MITSHUBISHI PAJERO SPORT", "CHERY OMODA 5"};
    
        pilihmenu(suv, n);
    }
    return 0;
}
