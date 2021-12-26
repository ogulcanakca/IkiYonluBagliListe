#include <iostream>
#include <iomanip>
#include "Liste.hpp"
#include <iostream>

int main()
{
	Liste* liste = new Liste();

	liste->ekle(11);

	cout << *liste;

	liste->ekle(22);

	cout << *liste;

	liste->cikar();

	cout << *liste;

	
	liste->cikar();

	cout << "-------------------------------------" << endl;


	try
	{
		cout << liste->ilkGetir() << endl;
	}
	catch (out_of_range& e)
	{
		cout << e.what() << endl;
	}
	cout << "-------------------------------------" << endl;

	liste->ekle(11);

	cout << *liste;

	cout << "-------------------------------------" << endl;

	cout << liste->dugumGetir(0)->veri << endl;

	cout << "-------------------------------------" << endl;

	liste->cikar(0);
	cout << *liste << endl;

	cout << "-------------------------------------" << endl;

	liste->ekle(11);

	cout << *liste;

	liste->ekle(22);

	cout << *liste;

	liste->ekle(44);

	cout << *liste;

	liste->onuneekle(2,33);

	cout << *liste;

	delete liste;
}

