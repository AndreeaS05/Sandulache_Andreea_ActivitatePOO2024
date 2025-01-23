#include<iostream>
using namespace std;

class Tablou {
private:
	string titlu;
	string artist;
	int nrTablouri;
	float* pret;
	string locatieExpozitie;
	static int TVA;
	const string tehnica;

public:
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

	string getTitlu() {
		return this->titlu;
	}
	string getArtist() {
		return this->artist;

	}
	int getNrTablouri() {
		return this->nrTablouri;
	}
	float* getPreturi() {
		return this->pret;
	}
	string getLocatieExpozitie() {
		return this->locatieExpozitie;
	}
	static int getTVA() {
		return Tablou::TVA;
	}

	void setTitlu(string titlu) {
		if (titlu.length() > 1) {
			this->titlu = titlu;
		}
	}

	void setArtist(string artist) {
		if (artist.length() > 3) {
			this->artist = artist;
		}
	}



	void setPreturi(float* pret, int nrTablouri) {
		if (this->pret) {
			delete[] this->pret;
			this->pret = NULL;
		}
		this->nrTablouri = nrTablouri;
		if (nrTablouri > 0 && pret != nullptr) {
			this->pret = new float[nrTablouri];
			for (int i = 0; i < nrTablouri; i++) {
				this->pret[i] = pret[i];
			}
		}
	}

	void setLocatieExpozitie(string locatieExpozitie) {
		this->locatieExpozitie = locatieExpozitie;
	}

	static void modificaTVA(int TVA) {
		if (TVA > 0) {
			Tablou::TVA = TVA;
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

	friend void aplicaReducereTablou(Tablou& t, float procent);
	friend void schimbaLocatieTablou(Tablou& t, const string& nouaLocatie);
};

int Tablou::TVA = 19;

void aplicaReducereTablou(Tablou& t, float procent) {

	if (t.pret != NULL) {
		for (int i = 0; i < t.nrTablouri; i++) {
			t.pret[i] = t.pret[i] - t.pret[i] * procent / 100;
		}
	}
}

void schimbaLocatieTablou(Tablou& t, const string& nouaLocatie) {
	t.locatieExpozitie = nouaLocatie;
}

class Artist {
private:
	char* nume;
	string prenume;
	int varsta;
	static int nrArtisti;
	const string nationalitate;

public:
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
		cout << "S-a apelat destructorul." << endl;
	}

	char* getNume() const {
		return this->nume;
	}

	string getPrenume() {
		return this->prenume;
	}

	int getVarsta() {
		return this->varsta;
	}

	static int getNrArtisti() {
		return Artist::nrArtisti;
	}

	string getNationalitate() {
		return this->nationalitate;
	}

	void setNume(char* nume) {
		if (this->nume) {
			delete[] this->nume;
			this->nume = nullptr;
		}
		if (nume != nullptr) {
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
	}

	void setPrenume(string prenume) {
		this->prenume = prenume;
	}

	void setVarsta(int v) {
		this->varsta = v;
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

	friend void maresteVarsta(Artist& a, int catiAni);
};
int Artist::nrArtisti = 0;

void maresteVarsta(Artist& a, int catiAni) {
	a.varsta += catiAni;
}
	class Sculptura {
	private:
		string material;
		int nrSculpturi;
		int* anCreare;
		static int TVA;
		const string stil;

	public:

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

		string getMaterial() {
			return this->material;
		}

		int getNrSculpturi() {
			return this->nrSculpturi;
		}

		int* getAniCreare() {
			return this->anCreare; // la fel, atenție la pointer
		}

		static int getTVA() {
			return Sculptura::TVA;
		}

		string getStil() {
			return this->stil;
		}


		void setMaterial(string material) {
			this->material = material;
		}




		void setAnCreare(int* anCreare, int nrSculpturi) {
			if (this->anCreare) {
				delete[] this->anCreare;
				this->anCreare = NULL;
			}
			this->nrSculpturi = nrSculpturi;
			if (nrSculpturi > 0 && anCreare != NULL) {
				this->anCreare = new int[nrSculpturi];
				for (int i = 0; i < nrSculpturi; i++) {
					this->anCreare[i] = anCreare[i];
				}
			}
		}

		static void setTVA(int noulTVA) {
			if (noulTVA > 0) {
				Sculptura::TVA = noulTVA;
			}
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
		friend void modificaAniSculptura(Sculptura& s, int* noiAni);
	};
	int Sculptura::TVA = 19;

	void modificaAniSculptura(Sculptura & s, int* noiAni) {
		for (int i = 0; i < s.nrSculpturi; i++) {
			s.anCreare[i] = noiAni[i];
		}
	}





	int main() {

		Tablou t;
		t.afisare();

		float* preturi = new float[3] {400.0, 600.0, 700.0};
		Tablou t1("Noapte instelata", "Vincent van Gogh", 3, preturi, "Muzeul de Arta Moderna", "Ulei");
		t1.afisare();

		Tablou t2(t1);
		t2.afisare();

		delete[] preturi;

		cout << "TVA initial este: " << Tablou::getTVA() << endl;
		Tablou::modificaTVA(24);
		cout << "TVA modificat este: " << Tablou::getTVA() << endl << endl;

		aplicaReducereTablou(t2, 10.0);
		schimbaLocatieTablou(t2, "Muzeul National");
		cout << "Dupa reducere si schimbare locatie: \n";
		t2.afisare();


		t2.setTitlu("Floarea soarelui");
		cout << "Noul titlu: " << t2.getTitlu() << endl << endl;


		cout << "Numarul de artisti este: " << Artist::getNrArtisti() << endl;
		Artist a;
		a.afisare();

		Artist a1("Buonarroti", "Michelangelo", 25, "italian");
		a1.afisare();

		Artist a2(a1);
		a2.afisare();
		cout << "Numarul de artisti dupa crearea tuturor este: " << Artist::getNrArtisti() << endl << endl;
		maresteVarsta(a2, 5);
		cout << "Dupa marirea varstei: " << endl;
		a2.afisare();

		a2.setPrenume("Michel");
		cout << "Prenumele schimbat este:" << a2.getPrenume() << endl << endl;

		Sculptura s;
		s.afisare();

		int* ani = new int[3] {1500, 1501, 1503};
		Sculptura s1("Marmura", 3, ani, "Renastere");
		s1.afisare();

		Sculptura s2(s1);
		s2.afisare();

		int* noiAni = new int[3] { 1600, 1601, 1603 };
		modificaAniSculptura(s2, noiAni);
		cout << "Dupa modificarea anilor: "<<endl;
		s2.afisare();

		delete[] ani;
		delete[] noiAni;

		cout << "TVA initial este: " << Sculptura::getTVA() << endl;
		Sculptura::modificaTVA(25);
		cout << "TVA modificat este: " << Sculptura::getTVA() << endl << endl;

		return 0;
	}