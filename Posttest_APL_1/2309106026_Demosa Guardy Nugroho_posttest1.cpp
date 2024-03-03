#include <iostream>
//#include <cctype>
using namespace std;

bool login() {
    string username, password;
    int coba = 0;
    int max_coba = 3;
    string correctuser = "DEMOSA GUARDY NUGROHO";
    string correctpass = "2309106026";

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

double konversi_rupiah(){
    char ulang = 'y';
    double rupiah;
    double rp_to_usd = 0;
    double rp_to_eur = 0;
    double rp_to_jpy = 0;
    while(ulang == 'y' || ulang == 'Y'){
        cout<<"masukkan jumlah rupiah yang ingin di konversi : ";
        cin>>rupiah;
        
        rp_to_usd = rupiah * 0.000064;
        cout<< "nilai rupiah dalam dollar adalah : "<<rp_to_usd<<endl;
        rp_to_eur = rupiah * 0.000059;
        cout<< "nilai rupiah dalam euro adalah : "<<rp_to_eur<<endl;
        rp_to_jpy = rupiah * 0.0096;
        cout<<"nilai rupiah dalam yen adalah : "<<rp_to_jpy<<endl;

        cout<< "apakah anda masih ingin meng-konversi nilai rupiah (y/t) : ";
        cin>>ulang;
    }
    return 0;
}
double konversi_dollar(){
    char ulang = 'y';
    double dollar;
    double usd_to_rp = 0;
    double usd_to_eur = 0;
    double usd_to_jpy = 0;
    while(ulang == 'y'||ulang == 'Y'){
        cout<<"masukkan jumlah dollar yang ingin di konversi : ";
        cin>>dollar;

        usd_to_rp = dollar * 15701.95;
        cout<< "nilai dollar dalam rupiah adalah : "<<usd_to_rp<<endl;
        usd_to_eur = dollar * 0.92;
        cout<< "nilai dollar dalam euro adalah : "<<usd_to_eur<<endl;
        usd_to_jpy = dollar * 150.09;
        cout<< "nilai dollar dalam yen adalah : "<<usd_to_jpy<<endl;

        cout<< "apakah anda masih ingin meng-konversi nilai dollar (y/t) : ";
        cin>>ulang;
    }
    return 0;
}

double konversi_euro(){
    char ulang = 'y';
    double euro;
    double eur_to_rp = 0;
    double eur_to_usd = 0;
    double eur_to_jpy = 0;
    while(ulang == 'y'||ulang == 'Y'){
        cout<<"masukkan jumlah euro yang ingin di konversi : ";
        cin>>euro;

        eur_to_rp = euro * 17043.68;
        cout<< "nilai euro dalam rupiah adalah : "<<eur_to_rp<<endl;
        eur_to_usd = euro * 1.09;
        cout<< "nilai euro dalam dollar adalah : "<<eur_to_usd<<endl;
        eur_to_jpy = euro * 162.93;
        cout<< "nilai euro dalam yen adalah : "<<eur_to_jpy<<endl;

        cout<< "apakah anda masih ingin meng-konversi nilai euro (y/t) : ";
        cin>>ulang;
    }
    return 0;
}

double konversi_yen(){
    char ulang = 'y';
    double yen;
    double yen_to_rp = 0;
    double yen_to_eur = 0;
    double yen_to_dollar = 0;
    while(ulang == 'y'||ulang == 'Y'){
        cout<<"masukkan jumlah yen yang ingin di konversi : ";
        cin>>yen;

        yen_to_rp = yen * 104.61;
        cout<< "nilai yen dalam rupiah adalah : "<<yen_to_rp<<endl;
        yen_to_eur = yen * 0.0061;
        cout<< "nilai yen dalam euro adalah : "<<yen_to_eur<<endl;
        yen_to_dollar = yen * 0.0067;
        cout<< "nilai yen dalam dollar adalah : "<<yen_to_dollar<<endl;

        cout<< "apakah anda masih ingin meng-konversi nilai rupiah (y/t) : ";
        cin>>ulang;
    }
    return 0;
}
int main(){
    
    if(login()){
        char pilih;
        while(pilih != '5'){
            cout<<"MENU"<<endl;
            cout<<"1. Konversi Rupiah ke (Dollar, Euro, Yen)"<<endl;
            cout<<"2. Konversi Dollar ke (Rupiah, Euro, Yen)"<<endl;
            cout<<"3. Konversi Euro ke (Rupiah, Dollar, Yen)"<<endl;
            cout<<"4. Konversi Yen ke (Rupiah, Dollar, Euro)"<<endl;
            cout<<"5. keluar"<<endl;
    
            cout<<"masukkan nomor menu yang ingin anda pilih : ";
            cin>>pilih;

            if(pilih == '1'){
                konversi_rupiah();
            }
            else if(pilih == '2'){
                konversi_dollar();
            }
            else if(pilih == '3'){
                konversi_euro();
            }
            else if(pilih == '4'){
                konversi_yen();
            }
        
        }
        cout<<"sampai jumpa lagi <3"<<endl;
        return 0;
    
    }
}