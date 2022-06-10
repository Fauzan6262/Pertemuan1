#include <iostream>  
using namespace std;  

int jumlahbarang(int hargasatuanbarang , int jumlahsatuanbarang , int diskon) {
  int jumlahbarang = hargasatuanbarang * jumlahsatuanbarang;
  diskon = jumlahbarang*diskon/100;
  jumlahbarang = jumlahbarang - diskon;
  
  cout << "-Quiz Pemograman perhitungan satuan barang-"<<endl;
  cout << "================================"<<endl;
  cout <<"Harga satuan barang Rp. "<< hargasatuanbarang<<endl;
  cout <<"Jumlah barang dibeli :"<< jumlahsatuanbarang <<endl;
  cout <<"Diskon Rp."<< diskon<<endl;
  cout << "================================"<<endl;
  cout <<"Total harga Rp." << jumlahbarang<<endl;
  }

int main() {  
	
	jumlahbarang(50000, 5, 15);

  return 0;
}  

