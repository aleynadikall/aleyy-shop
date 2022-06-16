#include <iostream>  //cin,cout,endl
#include <locale.h>  //setlocale
#include <iomanip>   //setw()
#include <string>    //string
#include <fstream>   //dosya iþlemleri için gerekli kütüphane

using namespace std;

//Anasayfa giris ekranýnda ekrana bastýrýlýcak olan ifadeleri barýndýran fonksiyon.
void giris() {

	cout << "Aleyna Evcil Hayvan Ürünleri -> HOÞGELDÝNÝZ..." << endl;
	cout << "--------------------------------------------------" << endl;
}

//Ekrana sürekli olarak bastýrýlýcak ifadeler sadelik ve anlaþýlabilirlik açýsýndan fonksiyon içine konulmuþtur.
void anaMenuSecim() {

	cout << "--------------------------------------------------" << endl;
	cout << setw(25) << "Ana Menü" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "|      [1]- A marka Kedi-Kopek Mamasý      :100 TL|" << endl;
	cout << "|      [2]- B marka Kedi-Köpek Künyesi      :50 TL|" << endl;
	cout << "|      [3]- C marka Kedi-Köpek Kumu        :150 TL|" << endl;
	cout << "|      [4]- D marka Kedi-Köpek Tuvaleti    :300 TL|" << endl;
	cout << "|      [5]- E marka Kedi-Köpek Oyuncaklarý  :75 TL|" << endl;
	cout << "--------------------------------------------------" << endl;

}

//Proje boyunca kullanýlacak olan ifadelerin istenilen þekilde txt dosyasýna yazdýrýlmasý için oluþturulmuþ fonksiyon.
//Bu fonksiyon aldýðý parametrelere iþlemler yaparak istenilen formatta txt çýktýsý oluþturmamýzý saðlar.
void dosyayaYazdir(string kullaniciAdi, float toplamBorc, float aylikOdemeTutari, int taksitSayisi, string aylar[12]) {

	/*int ve float deðiþkenlerin stringe dönüþtürülmesi iþlemi
	 Kaynakça:https://www.javatpoint.com/cpp-int-to-string
	*/
	string toplamBorcString = to_string(toplamBorc);
	string aylikOdemeString = to_string(aylikOdemeTutari);

	string cizgi = "--------------------------------------------------";
	string odemeCizelgesi;

	/*Proje dizininde dosya oluþturma iþlemi dosyalarýn oluþturulmasý ve içine istenilen bilgilerin yazýlmasý
	saðlanmýþtýr.
	Kaynakça:https://www.w3schools.com/cpp/cpp_files.asp
	*/

	ofstream BenimDosyam("Fatura.txt");

	for (int i = 0; i < taksitSayisi; i++) {
		odemeCizelgesi = odemeCizelgesi + aylar[i] + ": " + aylikOdemeString + "\n";
	}

	//txt dosyasýnýn içine yazýlacak olan ifade istenilen formatta bir string içine atanmýþtýr.
	string faturaMetin = "Müþteri Adý\n" + kullaniciAdi + "\n" + "\n" + "Toplam Borç Tutar: " + toplamBorcString + "\n" + "Odeme Cizelgesi:" + "\n" + cizgi + "\n" + odemeCizelgesi;

	//stringin txt dosyasý içine yazýlma iþlemi.
	BenimDosyam << faturaMetin;
	//dosya iþlemlerinin kapatýlmasý gerektiði ve yapmamýz gereken iþlemler bittiði için kapatýlmýþtýr.
	BenimDosyam.close();


}

int main()
{
	//Ödeme çizelgesi sýrasýnda taksitlerin hangi aylara ait olduðunu ekrana bastýrmak için oluþturulmuþ string dizisi.
	string aylar[12] = { "Ocak", "Subat", "Mart","Nisan","Mayýs","Haziran","Temmuz","Aðustos","Eylül","Ekim","Kasým","Aralýk" };

	string kullaniciAdi;

	//fiyat ve gerekli deðiþken atamalarý yapýlmýþtýr.
	//fiyatlar,toplamborç ve aylik ödeme tutarý kayan noktalý sayý olduðundan float tipindedir.
	float aMarka = 100, bMarka = 50, cMarka = 150, dMarka = 300, eMarka = 75, aylikOdemeTutari = 0, toplamBorc = 0;
	int adet = 0, taksitSayisi = 0, secim;
	char devamMi, kdvEklensinMi, taksitlendirmeSecenek;

	//türkçe karakterlerin kullanýlmasý için eklenmiþtir.
	setlocale(LC_ALL, "Turkish");

	//giris fonksiyonu çaðýrýlmýþtýr.
	giris();


	cout << "Lütfen Adýnýzý Giriniz:" << endl;
	//Müþteri ismi boþluklu olabileceði için getline yardýmýyla deðiþkene atanmýþtýr.
	getline(cin, kullaniciAdi);

	cout << endl << "Sayýn " << kullaniciAdi << " Aþaðýdaki menüden alýþ-veriþ yapabilirsiniz" << endl;


	while (true) {
		//anaMenuSecim fonksiyonu çaðýrýlmýþtýr.
		anaMenuSecim();
		cout << "Seçiminiz:";
		cin >> secim;

		//Kontrol yapýlarý sayesinde kullanýcýnýn seçtiði iþleme göre toplam borç belirlenmiþtir.
		if (secim == 1) {
			cout << "Adet Sayýsý Giriniz:";
			cin >> adet;
			toplamBorc = toplamBorc + (adet * aMarka);
			adet = 0;
		}
		else if (secim == 2) {
			cout << "Adet Sayýsý Giriniz:";
			cin >> adet;
			toplamBorc = toplamBorc + (adet * bMarka);
			adet = 0;
		}
		else if (secim == 3) {
			cout << "Adet Sayýsý Giriniz:";
			cin >> adet;
			toplamBorc = toplamBorc + (adet * cMarka);
			adet = 0;
		}
		else if (secim == 4) {
			cout << "Adet Sayýsý Giriniz:";
			cin >> adet;
			toplamBorc = toplamBorc + (adet * dMarka);
			adet = 0;
		}
		else if (secim == 5) {
			cout << "Adet Sayýsý Giriniz:";
			cin >> adet;
			toplamBorc = toplamBorc + (adet * eMarka);
			adet = 0;
		}
		else {
			cout << "Hatalý Secim Yaptýnýz Lutfen 1-5 aralýðýnda sayýlar giriniz..." << endl;
		}
		cout << "Þu anki toplam borcunuz: " << toplamBorc << endl;

		cout << "Alýþveriþe devam etmek istiyor musunuz? (E/H):";
		//Daha önceden kullanýlan getline getchar gibi ifadelerin programda hata vermemesi için görmezden gelinmesi saðlanmýþtýr.
		cin.ignore();
		devamMi = getchar();

		//Kullanýcý devam etmek istemezse programdan çýkmadan önce yapýlmasý gereken iþlemler yapýlýr.
		if (devamMi == 'H' || devamMi == 'h') {
			cout << "%18 KDV Eklensin Mi? (E/H):";
			cin.ignore();
			kdvEklensinMi = getchar();

			//Kullanýcý e veya E seçerse kdv miktarý toplam borca eklenir.
			if (kdvEklensinMi == 'E' || kdvEklensinMi == 'e') {
				float kdvBorc = (toplamBorc * 18) / 100;
				toplamBorc = toplamBorc + kdvBorc;
			}

			cout << "Toplam Borcunuz=" << toplamBorc << endl;
			cout << "Taksitlendirmek istiyor musunuz? (E/H):";
			cin.ignore();
			taksitlendirmeSecenek = getchar();
			cout << endl;

			//taksitlendirme seçeneði için oluþturulmuþ karar yapýsý.
			if (taksitlendirmeSecenek == 'E' || taksitlendirmeSecenek == 'e') {
				cout << "Taksit sayýsýný giriniz (MAX:12 taksit):";
				cin >> taksitSayisi;
				aylikOdemeTutari = toplamBorc / taksitSayisi;
				cout << "Aylýk Odeme Tutarýnýz: " << aylikOdemeTutari << endl;
			}
			else if (taksitlendirmeSecenek == 'H' || taksitlendirmeSecenek == 'h') {

				//tek seferde ödeme yapýlacaðý için taksit sayýsýna 1 dedik ve toplam borcumuz direkt aylýk ödeme tutarýna eþit oldu.
				taksitSayisi = 1;
				aylikOdemeTutari = toplamBorc;
				cout << "Odeme Tutarýnýz: " << aylikOdemeTutari << endl;
			}

			cout << "Ödeme Çizelgeniz" << endl;
			cout << "--------------------------------------------------" << endl;

			//ödeme çizelgesindeki ay ve ödenecek tutar için oluþturulmuþ for döngüsü.
			for (int i = 0; i < taksitSayisi; i++) {
				cout << aylar[i] << ": " << aylikOdemeTutari << endl;
			}

			//dosyayayazdir fonksiyonun çaðýrýlma iþlemi.
			dosyayaYazdir(kullaniciAdi, toplamBorc, aylikOdemeTutari, taksitSayisi, aylar);

			//while döngüsünü durdurmak için yerleþtirilen break ifadesi.
			break;
		}

	}

	system("PAUSE");
	return 0;
}