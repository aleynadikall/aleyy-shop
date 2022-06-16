#include <iostream>  //cin,cout,endl
#include <locale.h>  //setlocale
#include <iomanip>   //setw()
#include <string>    //string
#include <fstream>   //dosya i�lemleri i�in gerekli k�t�phane

using namespace std;

//Anasayfa giris ekran�nda ekrana bast�r�l�cak olan ifadeleri bar�nd�ran fonksiyon.
void giris() {

	cout << "Aleyna Evcil Hayvan �r�nleri -> HO�GELD�N�Z..." << endl;
	cout << "--------------------------------------------------" << endl;
}

//Ekrana s�rekli olarak bast�r�l�cak ifadeler sadelik ve anla��labilirlik a��s�ndan fonksiyon i�ine konulmu�tur.
void anaMenuSecim() {

	cout << "--------------------------------------------------" << endl;
	cout << setw(25) << "Ana Men�" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "|      [1]- A marka Kedi-Kopek Mamas�      :100 TL|" << endl;
	cout << "|      [2]- B marka Kedi-K�pek K�nyesi      :50 TL|" << endl;
	cout << "|      [3]- C marka Kedi-K�pek Kumu        :150 TL|" << endl;
	cout << "|      [4]- D marka Kedi-K�pek Tuvaleti    :300 TL|" << endl;
	cout << "|      [5]- E marka Kedi-K�pek Oyuncaklar�  :75 TL|" << endl;
	cout << "--------------------------------------------------" << endl;

}

//Proje boyunca kullan�lacak olan ifadelerin istenilen �ekilde txt dosyas�na yazd�r�lmas� i�in olu�turulmu� fonksiyon.
//Bu fonksiyon ald��� parametrelere i�lemler yaparak istenilen formatta txt ��kt�s� olu�turmam�z� sa�lar.
void dosyayaYazdir(string kullaniciAdi, float toplamBorc, float aylikOdemeTutari, int taksitSayisi, string aylar[12]) {

	/*int ve float de�i�kenlerin stringe d�n��t�r�lmesi i�lemi
	 Kaynak�a:https://www.javatpoint.com/cpp-int-to-string
	*/
	string toplamBorcString = to_string(toplamBorc);
	string aylikOdemeString = to_string(aylikOdemeTutari);

	string cizgi = "--------------------------------------------------";
	string odemeCizelgesi;

	/*Proje dizininde dosya olu�turma i�lemi dosyalar�n olu�turulmas� ve i�ine istenilen bilgilerin yaz�lmas�
	sa�lanm��t�r.
	Kaynak�a:https://www.w3schools.com/cpp/cpp_files.asp
	*/

	ofstream BenimDosyam("Fatura.txt");

	for (int i = 0; i < taksitSayisi; i++) {
		odemeCizelgesi = odemeCizelgesi + aylar[i] + ": " + aylikOdemeString + "\n";
	}

	//txt dosyas�n�n i�ine yaz�lacak olan ifade istenilen formatta bir string i�ine atanm��t�r.
	string faturaMetin = "M��teri Ad�\n" + kullaniciAdi + "\n" + "\n" + "Toplam Bor� Tutar: " + toplamBorcString + "\n" + "Odeme Cizelgesi:" + "\n" + cizgi + "\n" + odemeCizelgesi;

	//stringin txt dosyas� i�ine yaz�lma i�lemi.
	BenimDosyam << faturaMetin;
	//dosya i�lemlerinin kapat�lmas� gerekti�i ve yapmam�z gereken i�lemler bitti�i i�in kapat�lm��t�r.
	BenimDosyam.close();


}

int main()
{
	//�deme �izelgesi s�ras�nda taksitlerin hangi aylara ait oldu�unu ekrana bast�rmak i�in olu�turulmu� string dizisi.
	string aylar[12] = { "Ocak", "Subat", "Mart","Nisan","May�s","Haziran","Temmuz","A�ustos","Eyl�l","Ekim","Kas�m","Aral�k" };

	string kullaniciAdi;

	//fiyat ve gerekli de�i�ken atamalar� yap�lm��t�r.
	//fiyatlar,toplambor� ve aylik �deme tutar� kayan noktal� say� oldu�undan float tipindedir.
	float aMarka = 100, bMarka = 50, cMarka = 150, dMarka = 300, eMarka = 75, aylikOdemeTutari = 0, toplamBorc = 0;
	int adet = 0, taksitSayisi = 0, secim;
	char devamMi, kdvEklensinMi, taksitlendirmeSecenek;

	//t�rk�e karakterlerin kullan�lmas� i�in eklenmi�tir.
	setlocale(LC_ALL, "Turkish");

	//giris fonksiyonu �a��r�lm��t�r.
	giris();


	cout << "L�tfen Ad�n�z� Giriniz:" << endl;
	//M��teri ismi bo�luklu olabilece�i i�in getline yard�m�yla de�i�kene atanm��t�r.
	getline(cin, kullaniciAdi);

	cout << endl << "Say�n " << kullaniciAdi << " A�a��daki men�den al��-veri� yapabilirsiniz" << endl;


	while (true) {
		//anaMenuSecim fonksiyonu �a��r�lm��t�r.
		anaMenuSecim();
		cout << "Se�iminiz:";
		cin >> secim;

		//Kontrol yap�lar� sayesinde kullan�c�n�n se�ti�i i�leme g�re toplam bor� belirlenmi�tir.
		if (secim == 1) {
			cout << "Adet Say�s� Giriniz:";
			cin >> adet;
			toplamBorc = toplamBorc + (adet * aMarka);
			adet = 0;
		}
		else if (secim == 2) {
			cout << "Adet Say�s� Giriniz:";
			cin >> adet;
			toplamBorc = toplamBorc + (adet * bMarka);
			adet = 0;
		}
		else if (secim == 3) {
			cout << "Adet Say�s� Giriniz:";
			cin >> adet;
			toplamBorc = toplamBorc + (adet * cMarka);
			adet = 0;
		}
		else if (secim == 4) {
			cout << "Adet Say�s� Giriniz:";
			cin >> adet;
			toplamBorc = toplamBorc + (adet * dMarka);
			adet = 0;
		}
		else if (secim == 5) {
			cout << "Adet Say�s� Giriniz:";
			cin >> adet;
			toplamBorc = toplamBorc + (adet * eMarka);
			adet = 0;
		}
		else {
			cout << "Hatal� Secim Yapt�n�z Lutfen 1-5 aral���nda say�lar giriniz..." << endl;
		}
		cout << "�u anki toplam borcunuz: " << toplamBorc << endl;

		cout << "Al��veri�e devam etmek istiyor musunuz? (E/H):";
		//Daha �nceden kullan�lan getline getchar gibi ifadelerin programda hata vermemesi i�in g�rmezden gelinmesi sa�lanm��t�r.
		cin.ignore();
		devamMi = getchar();

		//Kullan�c� devam etmek istemezse programdan ��kmadan �nce yap�lmas� gereken i�lemler yap�l�r.
		if (devamMi == 'H' || devamMi == 'h') {
			cout << "%18 KDV Eklensin Mi? (E/H):";
			cin.ignore();
			kdvEklensinMi = getchar();

			//Kullan�c� e veya E se�erse kdv miktar� toplam borca eklenir.
			if (kdvEklensinMi == 'E' || kdvEklensinMi == 'e') {
				float kdvBorc = (toplamBorc * 18) / 100;
				toplamBorc = toplamBorc + kdvBorc;
			}

			cout << "Toplam Borcunuz=" << toplamBorc << endl;
			cout << "Taksitlendirmek istiyor musunuz? (E/H):";
			cin.ignore();
			taksitlendirmeSecenek = getchar();
			cout << endl;

			//taksitlendirme se�ene�i i�in olu�turulmu� karar yap�s�.
			if (taksitlendirmeSecenek == 'E' || taksitlendirmeSecenek == 'e') {
				cout << "Taksit say�s�n� giriniz (MAX:12 taksit):";
				cin >> taksitSayisi;
				aylikOdemeTutari = toplamBorc / taksitSayisi;
				cout << "Ayl�k Odeme Tutar�n�z: " << aylikOdemeTutari << endl;
			}
			else if (taksitlendirmeSecenek == 'H' || taksitlendirmeSecenek == 'h') {

				//tek seferde �deme yap�laca�� i�in taksit say�s�na 1 dedik ve toplam borcumuz direkt ayl�k �deme tutar�na e�it oldu.
				taksitSayisi = 1;
				aylikOdemeTutari = toplamBorc;
				cout << "Odeme Tutar�n�z: " << aylikOdemeTutari << endl;
			}

			cout << "�deme �izelgeniz" << endl;
			cout << "--------------------------------------------------" << endl;

			//�deme �izelgesindeki ay ve �denecek tutar i�in olu�turulmu� for d�ng�s�.
			for (int i = 0; i < taksitSayisi; i++) {
				cout << aylar[i] << ": " << aylikOdemeTutari << endl;
			}

			//dosyayayazdir fonksiyonun �a��r�lma i�lemi.
			dosyayaYazdir(kullaniciAdi, toplamBorc, aylikOdemeTutari, taksitSayisi, aylar);

			//while d�ng�s�n� durdurmak i�in yerle�tirilen break ifadesi.
			break;
		}

	}

	system("PAUSE");
	return 0;
}