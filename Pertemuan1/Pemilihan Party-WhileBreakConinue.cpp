#include <iostream>
using namespace std;

struct player
{
    int id;
    string name;
    string sSpecial;
    string sUmum;
};

int main()
{
    player skill[] = {
        {1, "Shielder", "Pertahanan Absolute", "Serangan mendapatkan efek kejut"},
        {2, "Saber", "Serangan Meningkat ketika terpojok", "Serangan dapat merusak pertahanan"},
        {3, "Lancer", "Kecepatan Kilat", "Serangan membuat efek ilusi"},
        {4, "Mage", "Tembakan Matahari", "Tidak diketahui"}};

cariKelasKarakter:
    int idPekerjaanYangDiPilih;
    int idPekerjaanYangDIlewati;
    
	cout << "Daftar Party Petualang Maksimal 3\n";
	cout <<	"1,Shielder, Pertahanan Absolute, Serangan mendapatkan efek kejut\n";
	cout << "=================================================================================================\n";
    cout <<	"2, Saber, Serangan Meningkat ketika terpojok, Serangan dapat merusak pertahanan\n";
    cout << "=================================================================================================\n";
    cout << "3, Lancer, Kecepatan Kilat, Serangan membuat efek ilusi\n";
    cout << "=================================================================================================\n";
    cout << "4, Mage, Tembakan Matahari, Tidak diketahui\n";
    cout << "=================================================================================================\n";
			 
    cout << "Masukkan Nomor Kelas Karakter yang ingin dipilih untuk menjadi pemimpin :";
    cin >> idPekerjaanYangDiPilih;

    cout << "Masukkan Nomor Kelas Karakter yang ingin dikeluarkan :";
    cin >> idPekerjaanYangDIlewati;

    for (int i = 0; i < 4; i++)
    {
        if (i + 1 == idPekerjaanYangDIlewati)
        {
            continue;
        }
        else
        {
            cout << "Kelas Karakter ID " << skill[i].id << " Adalah " << skill[i].name << " Dengan Skill Special " << skill[i].sSpecial << " dan Skill Umum " << skill[i].sUmum << "'\n";
            while (i + 1 == idPekerjaanYangDiPilih)
            {
                cout << "[Sang Pemimpin]\n";
                break;
            }
        }
    }
    string answer;
    do
    {
    	cout << "=================================================================================================\n";
        cout << "Apakah Anda ingin mengulangi kembali? (ya/tidak)\n";
        cin >> answer;
        if (answer == "tidak" || answer == "Tidak")
        {
            break;
        }
        goto cariKelasKarakter;
    } while (answer == "ya" || answer == "Ya");

    return 0;
}
