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
	// �teleme operat�r�m� a��r� y�kledim, b�ylece cout her nesnemi hemen yazd�rabilecek.
	Dugum* dugumGetir(int sira);

private:
	
	Dugum* ilk;
};

#endif