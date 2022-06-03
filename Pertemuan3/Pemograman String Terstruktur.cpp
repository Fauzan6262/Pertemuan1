#include <iostream>

using namespace std;
 
struct mahasiswa{
    string nama;
    string umur;
    string jeniskelamin;
    string jurusan;
    float NIM;
};
 
int main(){
 
    mahasiswa mhs;
 
    mhs.nama="Mochammad Fauzan Satriawan";
    mhs.jeniskelamin ="Laki laki";
    mhs.umur= " 21";
    mhs.jurusan="Teknik Informatika";
    mhs.NIM=121758;
    
    cout<<"DATA MAHASISWA UIN"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Nama    		 : "<<mhs.nama<<endl;
    cout<<"Jenis Kelamin 		 : "<<mhs.jeniskelamin<<endl;
    cout<<"umur         		 :"<<mhs.umur<<endl;
    cout<<"Jurusan 		 : "<<mhs.jurusan<<endl;
    cout<<"NIM     		 : "<<mhs.NIM<<endl;
      
    return 0;
}
