#pragma once

#include<iostream>
using namespace std;

class Ogrenci {

private:
	string isim;
	int numara;
	int sinavNot;

public:
	Ogrenci(string _isim, int _numara);
	void setSinavNot(int _sinavNot);
	int getSinavNot();

	void bilgileriGoster();
	void notSorgula();
	int getNumara();
};