#include"Ogrenci.h"

Ogrenci::Ogrenci(string _isim,int _numara){
	int _sinavNot=0;
	isim = _isim;
	numara = _numara;
	sinavNot = _sinavNot;
}

void Ogrenci::setSinavNot(int _sinavNot) {
	Ogrenci::sinavNot = _sinavNot;
}
int Ogrenci::getSinavNot() {
	return Ogrenci::sinavNot;
}


void Ogrenci::bilgileriGoster() {
	cout << numara << "     " << isim << "     " << sinavNot << endl;
}
void Ogrenci::notSorgula() {
	cout<<sinavNot<<endl;
}
int Ogrenci::getNumara() {
	return numara;
}