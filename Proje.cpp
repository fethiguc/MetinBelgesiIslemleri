#include <iostream>
#include <fstream>
#include <locale>
#include <string>
using namespace std;
int main()
{
	int i=0;//---------------------------------------------------------------------//döngü deðiþkeni
	int nt;//-------------------------------------------------------------------//not deðiþkeni
	string isim="";//--------------------------------------------------------------//isim deðiþkeni
	string tc;//-------------------------------------------------------------------//tc deðiþkeni
	string sonuc;//----------------------------------------------------------------//tüm deðiþkenlerin birleþtiði deðiþken
	int secim=0;//-----------------------------------------------------------------//secilen iþlemi tutan deðiþken
	setlocale(LC_ALL,"Turkish");
	do
	{
		cout<<"\n-------------Menu-----------";
		cout<<"\n-1-Kayit Ekle---------------";
		cout<<"\n-2-Kayitlari Göster--------";
		cout<<"\n-0-Cikis-------------------";
		cout<<"\nSeciminiz :";
		cin>>secim;
		if(secim==1)
		{
			do
			{
				cout<<"Ýsim giriniz : ";
				cin>>isim;
				for(i=isim.length();i<15;i++)//----------------------------------//isim deðiþkeninin uzunluðu 15 e ulaþasýya kadar dönen döngü.
				{
					isim=isim+" ";//---------------------------------------------//isim deðiþkenine her dönüþte 1 boþluk ekler.
				}
				if(isim.length()!=15)//------------------------------------------//isim deðiþkeninin uzunluðu 15den büyük olduðunda kullanýcýya uyarý verir.
				{
					cout<<"Lütfen 15 karakterden fazla isim girmeyiniz.\n";
				}	
			}while(isim.length()!=15);//----------------------------------------//isim deðiþkeninin uzunluðu 15 olmadýðý durumda program tekrardan isim ister.
			//-----------//Ýsim deðiþkeninin uzunluðu 15 veya 15den kýsa ise zaten içeride 15 olur bu sebeple 15 den büyük olduðu durumlarda bu döngü çalýþýr.
			do
			{
				cout<<"TC giriniz : ";
				cin>>tc;
				if(tc.length()!=11)//-------------------------------------------//tc deðiþkeninin uzunluðu 11 olmadýðý durumda kullanýcýya uyarý verir.
				{
					cout<<"TC kimlik numarasý 11 karakter olmalýdýr.Lütfen tekrar giriniz.\n";
				}
			}while(tc.length()!=11);//-----------------------------------------//tc degiskeni 11 uzunluðundan farklý bir uzunlukta ise program tekrardan tc ister.
			do
			{
				cout<<"Not giriniz : ";
				cin>>nt;
				if(nt>100||nt<0)
				{
					cout<<"Lütfen 100 ile 0 arasýnda bir not giriniz";
				}
			}while(nt>100||nt<0);	
			ofstream dosya;
   			dosya.open("C://Öðrenciler/Ögrenci.txt", ios::app);//----------------------//dosyayý üzerineki verilere zarar vermeden dosyaya veri ekleneceði belirtilir.
		  	//----------------------------------------------------------------//dosyanýn konumunu belirtir.
   		    sonuc=isim+" "+tc+" ";//---------------------------------------//sonuc degiskenine yukarýdaki tüm veriler ard arda eklenir.	
   			dosya<<sonuc<<nt<<endl;//---------------------------------------------//dosyaya sonuc verisi yazýlýr otomatik alt satýra geçilir.
   			dosya.close();//--------------------------------------------------//dosya kapanýr.
		}
		else if(secim==2)
		{
			ifstream dosya1;
			dosya1.open("C://Öðrenciler/Ögrenci.txt", ios::in);//----- --//dosyayý okunabilir yapar ve dosya yolunu belirtir.
			string line;//--------------------------------------//satir verisi belirtilir.
   		    while ( getline (dosya1,line) )//-------------------//dosya1 deki satýr getirilir ve line deðiþkenine kaydedilir.eðer yeni satýr yoksa döngü durur.
   				{
   			    	cout << line << '\n';//---------------------//satýrdaki veri ekrana yazdýrýlýr. bu döngüyü internetten aldým.
   				}
			dosya1.close();//----------------------------------//dosya kapatýlýr.
		}
		else if(secim==0)
		{
			cout<<"Program kapatiliyor";
		}
		else
		{
			cout<<"Lütfen 0 ile 2 arasinda bir deger giriniz";
		}
		
	}while(secim!=0);//secim degiskeni 0dan farklý oldugu sürece döngü dönmeye devam eder.
}
