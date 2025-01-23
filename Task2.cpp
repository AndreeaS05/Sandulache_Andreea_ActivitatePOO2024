#include<iostream>
using namespace std;

class Tablou {
public:
	string titlu;
	string artist;
	int nrTablouri;
	float* pret;
	string locatieExpozitie;
	static int TVA;
	const string tehnica;


	Tablou() :tehnica("Ulei") {
		this->titlu = "Necunoscut";
		this->artist = "Anonim";
		int nrTablouri = 0;
		this->pret = NULL;
		this->locatieExpozitie = "Necunoscuta";


	}

	Tablou(string titlu, string artist, int nrTablouri, float* pret, string locatieExpozitie, string tehnicaFolosita) :tehnica(tehnicaFolosita) {
		this->titlu = titlu;
		this->artist = artist;
		this->nrTablouri = nrTablouri;
		this->pret = new float[this->nrTablouri];
		for (int i = 0;i < this->nrTablouri;i++) {
			this->pret[i] = pret[i];
		}
		this->locatieExpozitie = locatieExpozitie;
	}

	Tablou(const Tablou& t) :tehnica(t.tehnica) {
		this->titlu = t.titlu;
		this->artist = t.artist;
		this->nrTablouri = t.nrTablouri;
		this->pret = new float[this->nrTablouri];
		for (int i = 0;i < this->nrTablouri; i++) {
			this->pret[i] = t.pret[i];

		}
		this->locatieExpozitie = t.locatieExpozitie;

	}
	~Tablou() {
		if (this->pret) {
			delete[]this->pret;
		}
		cout << "S-a apelat destructorul." << endl;
	}

	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Tablou::TVA = noulTVA;
		}
	}

	void afisare() {
		cout << "Titlul tabloului este:" << this->titlu << endl;
		cout << "Artistul este:" << this->artist << endl;
		cout << "Numarul de tablouri este:" << this->nrTablouri << endl;

		if (this->pret != NULL) {
			cout << "Preturile tablourilor sunt: ";
			for (int i = 0; i < this->nrTablouri; i++) {
				cout << this->pret[i] << " ";
			}
			cout << endl;
		}
		cout << "Locatia expozitiei este: " << this->locatieExpozitie << endl;
		cout << "Valoarea TVA este: " << this->TVA << endl;
		cout << "Tehnica de realizare a tabloului este: " << this->tehnica << endl << endl;
	}

};

int Tablou::TVA = 19;

class Artist {
public:
	char* nume;
	string prenume;
	int varsta;
	static int nrArtisti;
	const string nationalitate;

	Artist() :nationalitate("necunoscuta") {
		this->nume = NULL;
		this->prenume = "Anonim";
		this->varsta = 0;
		nrArtisti++;

	}

	Artist(const char* nume, string prenume, int varsta, string nationalitatea) :nationalitate(nationalitatea) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->prenume = prenume;
		this->varsta = varsta;
		nrArtisti++;

	}

	Artist(const Artist& a) :nationalitate(a.nationalitate) {
		if (a.nume != NULL) {
			this->nume = new char[strlen(a.nume) + 1];
			strcpy_s(this->nume, strlen(a.nume) + 1, a.nume);
		}
		else {
			this->nume = NULL;
		}
		this->prenume = a.prenume;
		this->varsta = a.varsta;
		nrArtisti++;
	}

	~Artist() {
		if (this->nume) {
			delete[]this->nume;
		}
		cout << "S-a apelat destructorul" << endl;
	}

	static int getNrArtisti() {
		return nrArtisti;
	}

	void afisare() {
		if (this->nume != NULL) {
			cout << "Numele este: " << this->nume << endl;
		}
		else {
			cout << "Numele nu este cunoscut." << endl;
		}

		cout << "Prenumele este: " << this->prenume << endl;
		cout << "Varsta este: " << this->varsta << endl;
		cout << "Numarul de artisti este: " << this->nrArtisti << endl;
		cout << "Nationalitatea este: " << this->nationalitate << endl << endl;

	}


};
int Artist::nrArtisti = 0;

class Sculptura {
public:
	string material;
	int nrSculpturi;
	int* anCreare;
	static int TVA;
	const string stil;

	Sculptura() :stil("clasic") {
		this->material = "neconoscut";
		this->nrSculpturi = 0;
		this->anCreare = NULL;

	}

	Sculptura(string material, int nrSculpturi, int* anCreare, string stil) :stil(stil) {
		this->material = material;
		this->nrSculpturi = nrSculpturi;
		this->anCreare = new int[this->nrSculpturi];
		for (int i = 0;i < nrSculpturi;i++) {
			this->anCreare[i] = anCreare[i];

		}
	}

	Sculptura(const Sculptura& s) :stil(s.stil) {
		this->material = s.material;
		this->nrSculpturi = s.nrSculpturi;
		this->anCreare = new int[this->nrSculpturi];
		for (int i = 0;i < s.nrSculpturi;i++) {
			this->anCreare[i] = s.anCreare[i];

		}
	}

	~Sculptura() {
		if (this->anCreare) {
			delete[]this->anCreare;
		}
		cout << "S-a apelat destructorul." << endl;
	}

	void afisare() {
		cout << "Maerialul este:" << this->material << endl;
		cout << "Numarul de sculpturi este:" << this->nrSculpturi << endl;
		if (this->anCreare != NULL) {
			cout << "Este creata in anul: ";
			for (int i = 0; i < this->nrSculpturi; i++) {
				cout << this->anCreare[i] << " ";
			}
			cout << endl;
		}
		cout << "Valoarea TVA este: " << this->TVA << endl;
		cout << "Stilul sculpturii este: " << this->stil << endl << endl;


	}

	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Sculptura::TVA = noulTVA;
		}
	}
};
int Sculptura::TVA = 19;





int main() {

	Tablou t;
	t.afisare();

	float* preturi = new float[3] {4.0, 6.0, 7.0};
	Tablou t1("Noapte instelata", "Vincent van Gogh", 3, preturi, "Muzeul de Arta Moderna", "Ulei");
	t1.afisare();

	Tablou t2(t1);
	t2.afisare();

	delete[] preturi;

	cout << "TVA initial este: " << Tablou::TVA << endl;
	Tablou::modificaTVA(24);
	cout << "TVA modificat este: " << Tablou::TVA << endl << endl;


	cout << "Numarul de artisti este: " << Artist::getNrArtisti() << endl;
	Artist a;
	a.afisare();

	Artist a1("Buonarroti", "Michelangelo", 25, "italian");
	a1.afisare();

	Artist a2(a1);
	a2.afisare();
	cout << "Numarul de artisti dupa crearea tuturor este: " << Artist::getNrArtisti() << endl << endl;

	Sculptura s;
	s.afisare();

	int* ani = new int[3] {1500, 1501, 1503};
	Sculptura s1("Marmura", 3, ani, "Renastere");
	s1.afisare();

	Sculptura s2(s1);
	s2.afisare();

	delete[] ani;

	cout << "TVA initial este: " << Sculptura::TVA << endl;
	Sculptura::modificaTVA(25);
	cout << "TVA modificat este: " << Sculptura::TVA << endl << endl;

	return 0;
}