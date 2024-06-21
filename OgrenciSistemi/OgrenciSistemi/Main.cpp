#include<iostream>
#include<list>
#include"Ogrenci.h"
using namespace std;

list<Ogrenci>* ogrenciList = new list<Ogrenci>;
int numara;
string isim,ad,soyad;


void ogrenciSilme(list<Ogrenci>* lst) {
	cout << "hangi ogrenciyi silmek istersiniz;" << endl << "Numarasini giriniz:";
	cin >> numara;
	list<Ogrenci>::iterator it;
	for (it = lst->begin(); it != lst->end(); it++) {
		if (it->getNumara() == numara)
			break;
	}
	lst->erase(it);
}

void notEkleme(list<Ogrenci> *lst) {
	int sinavNot;
	Ogrenci mOgrenci(isim, numara);
	cout <<"Ogrencinin numarasini giriniz:" << endl;
	cin >> numara;
	cout << "Eklenilecek notu giriniz:";
	cin >> sinavNot;
	list<Ogrenci>::iterator it;
	for (it = ogrenciList->begin();it!= ogrenciList->end(); it++) {
		if (mOgrenci.getNumara() == numara)
			break;
	}
	it->setSinavNot(sinavNot);
	cout << numara << " numaralý ogrencinin sinav notu : " << sinavNot<<endl;
}

void notSorgulama(list<Ogrenci> *lst) {				
	cout << "Ogrencinin numarasini giriniz:";
	cin >> numara;
	Ogrenci nOgrenci(isim, numara);
	list<Ogrenci>::iterator it;
	for (it = lst->begin(); it != ogrenciList->end(); it++) {
		if (it->getNumara() == numara)
			break;
	}
	if (it == lst->end())
		cout << "Ogrenci bulunamadi" << endl;
	else
		cout << numara << " numaralý ogrencinin sinav notu : " << endl;
		it->notSorgula();
} 

void printList(list<Ogrenci> *lst) {
	list<Ogrenci>::iterator ltr;
	int i = 0;
	cout << "     Numara  Isim              Not" << endl;
	for (ltr = lst->begin(); ltr != lst->end(); ltr++) {
		i++;
		cout << i << ")   ";
		ltr->bilgileriGoster();
	}
	cout << endl << endl;
}

void ogrenciEkleme(list<Ogrenci> *lst) {
	cout << "Ogrencinin ismini giriniz:"<<endl;
	cin >> ad >> soyad;
	isim = ad + " " + soyad;
	cout << "Ogrencinin numarasini giriniz:"<<endl;
	cin >> numara;
	Ogrenci yeniOgrenci(isim, numara);
	lst->push_back(yeniOgrenci);
	printList(lst);
}

void menu() {
	int  islem;
	string cevap;
	cout << "Ne yapmak istersiniz ?" << endl;
	cout << "1)Ogrenci ekleme:\n"<< "2)ogrenci silme:\n"<<"3)Not sorgulama:\n"<<"4)Not ekleme:\n"<<"5)Liste goruntule: \n";
	cout << endl << "Cikis yapmak icin 0 yaziniz" << endl;
	cin >> islem;
	if (islem != 0) {
			if (islem == 1) {
				ogrenciEkleme(ogrenciList);
				cout << endl << endl;
				cout << "Menuye donmek ister misiniz ?" << endl;
				cin >> cevap;
				if (cevap == "evet")
					menu();
			}
			else if (islem == 2) {
				ogrenciSilme(ogrenciList);
				cout << "Menuye donmek ister misiniz ?" << endl;
				cin >> cevap;
				if (cevap == "evet")
					menu();
			}
			else if (islem == 3) {
				notSorgulama(ogrenciList);
				cout << "Menuye donmek ister misiniz ?" << endl;
				cin >> cevap;
				if (cevap == "evet")
					menu();
			}
			else if (islem == 4) {
				notEkleme(ogrenciList);
				cout << "Menuye donmek ister misiniz ?" << endl;
				cin >> cevap;
				if (cevap == "evet")
					menu();
			}
			else if (islem == 5) {
				printList(ogrenciList);
				cout << "Menuye donmek ister misiniz ?" << endl;
				cin >> cevap;
				if (cevap == "evet")
					menu();
			}
			else
				cout << "hatali sayi girdiniz";
		}
	else
		cout << "Iyi gunler...";
}

int main() {
	menu();
}