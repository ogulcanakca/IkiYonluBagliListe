#ifndef Liste_hpp
#define Liste_hpp
#include "Dugum.hpp"
#include <iostream>
#include<exception>

using namespace std;

class Liste {
public:
	Liste();
	~Liste();
	void ekle(int veri);
	void onuneekle(int sira, int veri);
	void cikar();
	void cikar(int sira);
	int ilkGetir();
	friend ostream& operator<<(ostream& os, Liste& liste); 
	// öteleme operatörümü aþýrý yükledim, böylece cout her nesnemi hemen yazdýrabilecek.
	Dugum* dugumGetir(int sira);

private:
	
	Dugum* ilk;
};

#endif