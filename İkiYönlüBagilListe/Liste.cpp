#include "Liste.hpp"
#include <iomanip>
using namespace std;
Liste::Liste() {
	ilk = 0;
}
Liste::~Liste() {
	Dugum* gec = ilk;
	while (gec != 0) {
		Dugum* silinecek = gec;
		gec = gec->sonraki;

		delete silinecek;
	}

}
int Liste::ilkGetir() {
	if (ilk != 0) {
		return ilk->veri;
	}
	else {
		throw out_of_range("Liste::ilkGetir(): Liste Bos Hatasi");
	}
}
void Liste::ekle(int veri) {
	Dugum* yeniDugum = new Dugum(veri);
	if (ilk == 0) {
		ilk = yeniDugum;
	}
	else {
		Dugum* gec = ilk;

		while (gec->sonraki != 0) {
			gec = gec->sonraki;

		}

		gec->sonraki = yeniDugum;
		yeniDugum->onceki = gec;
	}
	

}
void Liste::onuneekle(int sira, int veri) {
	Dugum* aktifDugum = dugumGetir(sira);

	if (aktifDugum) {
		Dugum* aktifOnceki = aktifDugum->onceki;

		Dugum* yeniDugum = new Dugum(veri);

		aktifDugum->onceki = yeniDugum;
		yeniDugum->sonraki = aktifDugum;
		yeniDugum->onceki = aktifOnceki;

		if (aktifOnceki) {
			aktifOnceki->sonraki = yeniDugum;
		}
		else {
			ilk = yeniDugum;
		}
	}
}


ostream& operator<<(ostream& os, Liste& liste) {
	os << setw(15) << "dugum adresi" << setw(15) << "veri" << setw(15) << "onceki" << setw(15) << "sonraki" << endl;

	Dugum* gec = liste.ilk;
	while (gec != 0) {
		os << setw(15) << gec << setw(15) << gec->veri << setw(15) << gec->onceki << setw(15) << gec->sonraki << endl;

		gec = gec->sonraki;
	}
	os << "--------------------------------------" << endl;
	return os;
}
void Liste::cikar() {
	if (ilk == 0) {
		return;
	}
	if(ilk->sonraki ==0) {
		delete ilk;
		ilk = 0;

	}
	else {
		Dugum* gec = ilk;

		while (gec->sonraki->sonraki != 0) {
			gec = gec->sonraki;

			delete gec->sonraki;
		}
		gec->sonraki = 0;
	}
}
void Liste::cikar(int sira) {
	Dugum* silinecek = dugumGetir(sira);

	if (silinecek) {
		Dugum* silinecek_onceki = silinecek->onceki;
		Dugum* silinecek_sonraki = silinecek->sonraki;

		if (silinecek_sonraki) {
			silinecek_sonraki->onceki= silinecek_onceki;
		}
		if (silinecek_onceki) {
			silinecek_onceki->sonraki = silinecek_sonraki;
		}
		else {
			ilk = silinecek_sonraki;
		}
		delete silinecek;
	}

}
Dugum* Liste::dugumGetir(int sira) {
	Dugum* gec = ilk;

	int sayac = 0;
	while (sira >= 0 && gec != 0) {
		if (sayac == sira) {
			return gec;
		}
		gec = gec->sonraki;
		sayac++;
	}
	return 0;
}