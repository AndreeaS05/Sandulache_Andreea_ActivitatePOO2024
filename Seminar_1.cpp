#include<iostream>
using namespace std;

struct CoordonateGPS {
	int latitudine;
	int longitudine;
	float altitudine;
	string locatie;
};

void afisareCoordonateGPS(CoordonateGPS l) {
	cout << "Latitudine: " << l.latitudine << endl;
	cout << "Longitutidine: " << l.longitudine << endl;
	cout << "Altitudine: " << l.altitudine << endl;
	cout << "Locatie: " << l.locatie << endl;
}
/*fiecare fct are o stiva de memorie in mom in care ii dam l2 din memorie se pune in stiva lui l2
apoi e copiat si bagat in stiva lui modifica dupa ce se terima functia se sterge memoria
ca rezolvare lucram prin adrese la atp se lucreaza prin pointeri-tip de date care retine o adresa*/


void modificaAltitudine(CoordonateGPS* l, float nouaAltitudine) {
	l->altitudine = nouaAltitudine;/*-> este dereferentiere + accesare*/
}

void modificaAltitudineRef(CoordonateGPS& l, float nouaAltitudine) {
	l.altitudine = nouaAltitudine;
}

CoordonateGPS initializareCoordonate(int latitudine, int longitudine, float altitudine, string locatie) {
	CoordonateGPS l;
	l.latitudine = latitudine;
	l.longitudine = longitudine;
	l.altitudine = altitudine;
	l.locatie = locatie;
	return l;
}

int main() {
	CoordonateGPS l;
	l.latitudine = 46;
	l.longitudine = 22;
	l.altitudine = 1010;
	l.locatie = "Predeal";

	afisareCoordonateGPS(l);

	CoordonateGPS l2;
	cout << "Introduceti latitudinea:";
	cin >> l2.latitudine;
	cout << "Introduceti longitudinea:";
	cin >> l2.longitudine;
	cout << "Introduceti altitudinea:";
	cin >> l2.altitudine;
	cout << "Introduceti locatia:";
	cin >> l2.locatie;

	afisareCoordonateGPS(l2);
	modificaAltitudine(&l2, 2000);
	modificaAltitudineRef(l2, 3000);
	afisareCoordonateGPS(l2);

	int a = 20;
	int* pa = &a;
	int* p = new int(50);
	/*new returneaza o adresa la fel ca malloc in c*/

	return 0;
}

/*  "a"-sir de caractere la final \0 care reprezinta finalul -2octeti 'a' -un singur caracter 1byte octet
functie: tip returnat, nume,(parametrii[params]intre paranteze drepte pt ca pot fi mai multi sau pot lipsi),corpul functiei{}
*/