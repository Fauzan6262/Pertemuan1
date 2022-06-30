//Mochammad Fauzan Satriiawan
//UAS Praktikum Algoritma Dan Pemograman
#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

// Arrow key
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC 27

// Fungsi set warna
void setcolor(unsigned short color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}

// Fungsi menjalankan player 
void playerMovement(int key);

// Fungsi coloring and symbolic
void displayMap();

// Fungsi Set warna
void setcolor(unsigned short color);

const int panjangPeta = 505;
const int lebarPeta = 20;
int playerX = 7;
int playerY = 7;
int arrowKey = ' ';


// Map peta UBER
int peta[lebarPeta][panjangPeta] = {
		{9, 9, 9, 9, 9, 9, 8, 8, 8, 7, 7, 7, 8, 8, 8, 8, 7, 7, 2, 7, 9, 9, 9, 9, 9, 9},
		{9, 9, 9, 9, 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7, 5, 7, 9, 9, 9, 9, 9, 9},
		{9, 9, 9, 1, 1, 1, 1, 1, 1, 2, 2, 1, 2, 2, 1, 1, 1, 7, 1, 7, 9, 9, 9, 9, 9, 9},
		{9, 9, 9, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 7, 1, 7, 9, 9, 9, 9, 9, 9},
		{9, 9, 9, 10, 10, 10, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9},
		{9, 9, 10, 10, 10, 10, 10, 10, 1, 1, 1, 1, 1, 1, 1, 7, 9, 1, 1, 1, 9, 9, 9, 9, 9, 9},
		{9, 9, 9, 11, 11, 11, 11, 1, 1, 1, 1, 1, 1, 1, 7, 2, 9, 1, 1, 1, 9, 9, 9, 9, 9, 9},
		{9, 9, 9, 11, 10, 10, 11, 1, 1, 1, 1, 1, 1, 1, 7, 1, 9, 1, 1, 1, 9, 9, 9, 9, 9, 9},
		{9, 9, 9, 11, 11, 11, 11, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 8, 1, 1, 7, 9, 9, 9, 9, 9},
		{9, 9, 1, 8, 1, 4, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 8, 1 , 9, 9, 9, 9, 9, 9},
		{9, 9, 1, 8, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 8, 1, 1, 9, 9, 9, 9, 9, 9},
		{9, 9, 1, 1, 1, 1, 1, 1, 1, 9, 9, 1, 1, 1, 8, 8, 8, 1, 1, 1, 7, 7, 7, 9, 9, 9},
		{9, 9, 1, 1, 9, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 7, 9, 9, 9, 9},
		{9, 9, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1, 2, 2, 1, 9, 9, 7, 9, 9, 9},
		{9, 9, 9, 1, 1, 1, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 9, 9, 9, 9, 9, 9}, 
		{9, 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, 10, 10, 9, 9, 9, 9, 9, 9, 9},
		{9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 10, 10, 10, 10, 10, 10, 9, 9, 9, 9, 9, 9},
		{9, 7, 2, 2, 7, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 11, 11, 11, 11, 8, 9, 9, 9, 9, 9, 9},
		{9, 7, 2, 2, 7, 1, 1, 1, 1, 9, 2, 1, 1, 1, 1, 11, 10, 10, 11, 8, 9, 9, 9, 9, 9, 9},
		{9, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 1, 1, 1, 11, 11, 11, 11, 8, 9, 9, 9, 9, 9, 9},
};

// Structure Player
struct Hero
{
	string name;
	int hp;
	int atk;
	int def;

	void baseAtkPlayer(int *Pokemon_hp, int *Pokemon_def)
	{
		*Pokemon_hp = *Pokemon_hp - (atk - *Pokemon_def);
	}
};

// Structure Pokemon monster
struct Pokemon
{
	string name;
	int hp;
	int atk;
	int def;

	void baseAtkPokemon(int *player_hp, int *player_def)
	{
		*player_hp = *player_hp - (atk - *player_def);
	}
};

//Fungsi Menjalankan Player
void playerMovement(int key)
{
  	if (key == KEY_UP
  	&& peta[playerY - 1][playerX] < 7)
	{
	  playerY -= 1;
	  playerY < 0 ? playerY =
	    0 : playerY;
	}
      else if (key == KEY_DOWN
		&& peta[playerY + 1][playerX] < 7)
	{
	  playerY += 1;
	  playerY > 19 ? playerY =
	    19 : playerY;
	}
      else if (key == KEY_LEFT
	       && peta[playerY][playerX - 1] < 7)
	{
	  playerX -= 1;
	  playerX < 0 ? playerX =
	    0 : playerX;
	}
      else if (key == KEY_RIGHT
	       && peta[playerY][playerX + 1] < 7)
	{
	  playerX += 1;
	  playerX > 19 ? playerX =
	    19 : playerX;
	}
	  else if (key == ESC)
    {  
    	system("cls");
    	char	 choice;
    	cout << "\tApa anda yakin ingin keluar?" << endl;
    	cout << "\Terima Kasih sudah mau bermain :)" << endl;
    	cout << "1. Ya \n2. tidak\n";
    	choice = getch();

    	if (choice == '1') {
			exit(0);
		} else if (choice == '2') {
			system("cls");
		}
    };     
}

void displayMap()
{
	int koordinat = peta[playerY][playerX];
	
	cout << "\t\t=========================\n";
	cout << "\t\t=   [LvL.1] HUTAN UBER  =\n";
	cout << "\t\t=========================\n";
	
	for (int i = 0; i < lebarPeta; i++)
	{
	  for (int j = 0; j < panjangPeta; j++)
	    {
	      	if (playerX == j && playerY == i
		  	&& koordinat < 7)
			{
				//Player Bojan
		  		setcolor (13);		
		  		cout << char (2);	
		  		setcolor (7);
			}
	      		else if (peta[i][j] == 1)
			{
				//Rumput pendek
		  		setcolor (14);		
		  		cout << ".";		
		  		setcolor (7);
			}
	      		else if (peta[i][j] == 2)
			{
				//Genangan air
		  		setcolor (9);		
		  		cout << "~";		
		  		setcolor (7);
			}
	      		else if (peta[i][j] == 3)
			{
				//default
		  		setcolor (13);		
		  		cout << "&";		
		  		setcolor (7);
			}
	      		else if (peta[i][j] == 4)
			{
				//UCOK
		  		setcolor (4);		
		  		cout << "UC";		
		  		setcolor (7);
			}
	      		else if (peta[i][j] == 5)
			{
				//UJANG
		  		setcolor (12);		
		  		cout << "UJ";		
		  		setcolor (7);
			}
		  		else if (peta[i][j] == 6)
			{
				//Asep
		  		setcolor (11);		
		  		cout << "AS";		
		 		 setcolor (7);
			}
		  		else if (peta[i][j] == 7)
			{
				//Gunung
		  		setcolor (2);		
		  		cout << "^";		
		 		setcolor (7);
			}	
	      		else if (peta[i][j] == 8)
			{
				//Batu
		  		setcolor (8);		
		  		cout << "o";		
		  		setcolor (7);
			}
	     		else if (peta[i][j] == 9)
			{
				//Semak
		  		setcolor (10);		
		  		cout << "#";		
		  		setcolor (7);
			}
			else if (peta[i][j] == 10)
			{
				//RUMAH
		  		setcolor (6);		
		  		cout << "_";		
		  		setcolor (7);
			}
			else if (peta[i][j] == 11)
			{
				//RUMAH
		  		setcolor (6);		
		  		cout << "|";		
		  		setcolor (7);
			}
	     		else
	     	{
		}
	    }
	  cout << "\n";
	};
}

int main()
{
	int pil;
	int oke;
	
	setcolor(6);
    cout << "\t=======***======" << endl;
    setcolor(11);
    cout << "\t   Demo Game" << endl;
    setcolor(6);					
    cout << "\t=======***======" << endl; 

    cout << "1. Mulai Permainan\n2. Keluar\nPilihan : ";
    cin >> pil;
    switch (pil) 
    case 1 :
        system("cls");
        cout <<  "===   Welkam tu Game UBER!   ===\n";
        cout << "Insert any key : "; cin >> oke;
    while (true) 
		
	while (true)
	{
		// Gerak Player
		playerMovement(arrowKey);
		
		// Tampilan Peta
		displayMap();
		
		// Input Keyboard dan panduan
		cout << " \n";
		cout << "-----------------------\n";
		setcolor (10);
		cout << "# = Rumput\n";
		setcolor (2);
		cout << "^ = Gunung\n";
		setcolor (6);
		cout << "| dan _ = Bentukan Rumah\n";
		setcolor (8);
		cout << "o = Batu\n";
		setcolor (9);
		cout << "~ = Genangan Air\n";
		setcolor (4);
		cout << "UC = Enemey Ucok\n";
		setcolor (12);
		cout << "UJ = Enemy Ujang\n";
		setcolor (11);
		cout << "AS = Enemy Asep\n";
		setcolor (13);
		cout << ":) = Player\n";
		setcolor (7);
		cout << "-----------------------\n";
		cout << " Tekan ESC untuk keluar  \n";
		
		arrowKey = getch();
		
		//Clear Screen
		system("cls");

		// Hero Object
		Hero player;
		player.name = "Nicholas Bojan";
		player.hp = 520;
		player.atk = 50;
		player.def = 25;

		// find pokemon
		if (peta[playerY][playerX] == 4)
		{
			// Pokemon Object
			Pokemon pokemon1;
			pokemon1.name = "Ucok,";
			pokemon1.hp = 450;
			pokemon1.atk = 50;
			pokemon1.def = 22;

			while (true)
			{
				system("cls");

				char input_battle = ' ';
				cout << "\t ==kau bertemu " << pokemon1.name << "Kapaksa kudu nyerang Bojan!!==" << endl;
				cout << player.name << ": " << player.hp << endl;
				cout << pokemon1.name << ": " << pokemon1.hp << endl;
				cout << "Pencet F untuk menyerang si ucok!" << endl;
				input_battle = getch();
	
				if (input_battle == 'f' || input_battle == 'F')
				{
					player.baseAtkPlayer(&pokemon1.hp, &pokemon1.def);
					pokemon1.baseAtkPokemon(&player.hp, &player.def);
				}

				if (pokemon1.hp <= 0)
				{
					peta[playerY][playerX] = 1;
					setcolor(6);
					cout << "Bojan telah menang melawan " << pokemon1.name << endl;
					setcolor(7);
					
					cout << "[LOADING Mohon tunggu sebentar]" << endl;
					setcolor(7);
					
					Sleep(3000);
					system("cls");
					break;
				}
			}
		}
		if (peta[playerY][playerX] == 5)
		{
			// Pokemon Object
			Pokemon pokemon2;
			pokemon2.name = "Ujang";
			pokemon2.hp = 500;
			pokemon2.atk = 225;
			pokemon2.def = 100;

			while (true)
			{
				system("cls");

				char input_battle = ' ';
				cout << "\t==Kau menggangu " << pokemon2.name << "Kapaksa kudu nyerang Bojan!!==" << endl;
				cout << player.name << ": " << player.hp << endl;
				cout << pokemon2.name << ": " << pokemon2.hp << endl;
				cout << "Pencet F untuk menyerang si Ujang!" << endl;
				input_battle = getch();

				if (input_battle == 'f' || input_battle == 'F')
				{
					player.baseAtkPlayer(&pokemon2.hp, &pokemon2.def);
					pokemon2.baseAtkPokemon(&player.hp, &player.def);
				}

				if (player.hp <= 0)
				{
					peta[playerY][playerX] = 1;
					setcolor(6);
					cout << "Bojan telah kalah melawan " << pokemon2.name << endl;
					setcolor(6);
						
					cout << "[LOADING Mohon tunggu sebentar]" << endl;
					setcolor(7);
					
					Sleep(3000);
					system("cls");
					break;
				}
			}
		}
		if (peta[playerY][playerX] == 6)
		{
			// Pokemon Object
			Pokemon pokemon3;
			pokemon3.name = "Asep";
			pokemon3.hp = 500;
			pokemon3.atk = 40;
			pokemon3.def = 15;

			while (true)
			{
				system("cls");

				char input_battle = ' ';
				cout << "\t==Kau bertemu " << pokemon3.name << ",Asep sedang membentakmu!==" << endl;
				cout << player.name << ": " << player.hp << endl;
				cout << pokemon3.name << ": " << pokemon3.hp << endl;
				cout << "Pencet F untuk membentak balik!" << endl;
				input_battle = getch();

				if (input_battle == 'f' || input_battle == 'F')
				{
					player.baseAtkPlayer(&pokemon3.hp, &pokemon3.def);
					pokemon3.baseAtkPokemon(&player.hp, &player.def);
				}

				if (pokemon3.hp <= 0)
				{
					peta[playerY][playerX] = 1;
					setcolor(6);
					cout << "Bojan menang mental dengan " << pokemon3.name << endl;
					setcolor(7);
					
					cout << "[LOADING Mohon tunggu sebentar]" << endl;
					setcolor(7);
					
					Sleep(3000);
					system("cls");
					break;
				}
			}
		}
		else if (peta[playerY][playerX] == 2)
		{
			int chance;
			srand(time(NULL));
			chance = rand() % 10;

			if (chance < 4)
			{
				while(true)
				{
					system("cls");
					int choice;
					cout << "kamu menemukan monster, Bojan!"<<endl;
	      			cout << "1. Gelutan\n2. Lumpat" << endl;
	      			cout << "Segera pilih opsi anda!";
					choice = getch();
				
	      			if (choice == '1')
					{
	      				//Pokemon Object
						Pokemon pokemon4;
						pokemon4.name = "Ucing Hideung";
						pokemon4.hp = 520;
						pokemon4.atk = 30;
						pokemon4.def = 15;
						
						while(true)
						{	
							system("cls");
							char input_battle = ' ';
							cout << "\t==Kau menemukan" << pokemon4.name << " Kapaksa kudu nyerang Bojan!!==" << endl;
							cout << player.name << ": " << player.hp << endl;
							cout << pokemon4.name << ": " << pokemon4.hp << endl;
							cout << "Pencet F untuk menjinakan!" << endl;
							input_battle = getch();
							
							if (input_battle == 'f' || input_battle == 'F')
							{
								player.baseAtkPlayer(&pokemon4.hp, &pokemon4.def);
								pokemon4.baseAtkPokemon(&player.hp, &player.def);
							}
							if (pokemon4.hp <= 0)
							{
								setcolor(6);
								cout << "Bojan telah menjinakan " << pokemon4.name << endl;
								setcolor(7);
								
								cout << "[LOADING Mohon tunggu sebentar]" << endl;
								setcolor(7);
								
								Sleep(3000);
								system("cls");
								break;
							}
						}
						break;
					}
					else if (choice == '2')
					{
						break;
					}
				
				}
			}
		}
	};
	getch();
	return 0;
}
