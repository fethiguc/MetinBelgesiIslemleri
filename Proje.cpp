#include <iostream>
#include <fstream>
#include <locale>
#include <string>
using namespace std;
int main()
{
	int i=0;//---------------------------------------------------------------------//d�ng� de�i�keni
	int nt;//-------------------------------------------------------------------//not de�i�keni
	string isim="";//--------------------------------------------------------------//isim de�i�keni
	string tc;//-------------------------------------------------------------------//tc de�i�keni
	string sonuc;//----------------------------------------------------------------//t�m de�i�kenlerin birle�ti�i de�i�ken
	int secim=0;//-----------------------------------------------------------------//secilen i�lemi tutan de�i�ken
	setlocale(LC_ALL,"Turkish");
	do
	{
		cout<<"\n-------------Menu-----------";
		cout<<"\n-1-Kayit Ekle---------------";
		cout<<"\n-2-Kayitlari G�ster--------";
		cout<<"\n-0-Cikis-------------------";
		cout<<"\nSeciminiz :";
		cin>>secim;
		if(secim==1)
		{
			do
			{
				cout<<"�sim giriniz : ";
				cin>>isim;
				for(i=isim.length();i<15;i++)//----------------------------------//isim de�i�keninin uzunlu�u 15 e ula�as�ya kadar d�nen d�ng�.
				{
					isim=isim+" ";//---------------------------------------------//isim de�i�kenine her d�n��te 1 bo�luk ekler.
				}
				if(isim.length()!=15)//------------------------------------------//isim de�i�keninin uzunlu�u 15den b�y�k oldu�unda kullan�c�ya uyar� verir.
				{
					cout<<"L�tfen 15 karakterden fazla isim girmeyiniz.\n";
				}	
			}while(isim.length()!=15);//----------------------------------------//isim de�i�keninin uzunlu�u 15 olmad��� durumda program tekrardan isim ister.
			//-----------//�sim de�i�keninin uzunlu�u 15 veya 15den k�sa ise zaten i�eride 15 olur bu sebeple 15 den b�y�k oldu�u durumlarda bu d�ng� �al���r.
			do
			{
				cout<<"TC giriniz : ";
				cin>>tc;
				if(tc.length()!=11)//-------------------------------------------//tc de�i�keninin uzunlu�u 11 olmad��� durumda kullan�c�ya uyar� verir.
				{
					cout<<"TC kimlik numaras� 11 karakter olmal�d�r.L�tfen tekrar giriniz.\n";
				}
			}while(tc.length()!=11);//-----------------------------------------//tc degiskeni 11 uzunlu�undan farkl� bir uzunlukta ise program tekrardan tc ister.
			do
			{
				cout<<"Not giriniz : ";
				cin>>nt;
				if(nt>100||nt<0)
				{
					cout<<"L�tfen 100 ile 0 aras�nda bir not giriniz";
				}
			}while(nt>100||nt<0);	
			ofstream dosya;
   			dosya.open("C://��renciler/�grenci.txt", ios::app);//----------------------//dosyay� �zerineki verilere zarar vermeden dosyaya veri eklenece�i belirtilir.
		  	//----------------------------------------------------------------//dosyan�n konumunu belirtir.
   		    sonuc=isim+" "+tc+" ";//---------------------------------------//sonuc degiskenine yukar�daki t�m veriler ard arda eklenir.	
   			dosya<<sonuc<<nt<<endl;//---------------------------------------------//dosyaya sonuc verisi yaz�l�r otomatik alt sat�ra ge�ilir.
   			dosya.close();//--------------------------------------------------//dosya kapan�r.
		}
		else if(secim==2)
		{
			ifstream dosya1;
			dosya1.open("C://��renciler/�grenci.txt", ios::in);//----- --//dosyay� okunabilir yapar ve dosya yolunu belirtir.
			string line;//--------------------------------------//satir verisi belirtilir.
   		    while ( getline (dosya1,line) )//-------------------//dosya1 deki sat�r getirilir ve line de�i�kenine kaydedilir.e�er yeni sat�r yoksa d�ng� durur.
   				{
   			    	cout << line << '\n';//---------------------//sat�rdaki veri ekrana yazd�r�l�r. bu d�ng�y� internetten ald�m.
   				}
			dosya1.close();//----------------------------------//dosya kapat�l�r.
		}
		else if(secim==0)
		{
			cout<<"Program kapatiliyor";
		}
		else
		{
			cout<<"L�tfen 0 ile 2 arasinda bir deger giriniz";
		}
		
	}while(secim!=0);//secim degiskeni 0dan farkl� oldugu s�rece d�ng� d�nmeye devam eder.
}
