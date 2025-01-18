#include<iostream>

using namespace std;

class Magazin {
private:
	string oras;
	int nrAngajati;//
	float* salarii;
	float suprafata;//
	const int anDeschidere;
	static int impozitM2;

public:
	Magazin() :anDeschidere(2024), nrAngajati(0) {
		this->oras = "Bucuresti";
		this->suprafata = 50;
		this->salarii = NULL;
	}

	Magazin(string oras, int nrAngajati, float suprafata, int an) :anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 2000 + i;
		}
	}

	Magazin(const Magazin& m) :anDeschidere(m.anDeschidere) {
		this->oras = m.oras;
		this->nrAngajati = m.nrAngajati;

		this->salarii = new float[m.nrAngajati];
		for (int i = 0; i < m.nrAngajati; i++) {
			this->salarii[i] = m.salarii[i];
		}
		this->suprafata = m.suprafata;
	}

	~Magazin() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}

	Magazin operator=(const Magazin& m) {
		if (&m != this) { //verificare de autoasignare
			this->oras = m.oras;
			this->nrAngajati = m.nrAngajati;
			if (this->salarii) {
				delete[]this->salarii;
			}
			this->salarii = new float[m.nrAngajati];
			for (int i = 0; i < m.nrAngajati; i++) {
				this->salarii[i] = m.salarii[i];
			}
			this->suprafata = m.suprafata;
		}
		return *this;
	}


	int getNrAngajati() {
		return this->nrAngajati;
	}
	void setNrAngajati(int nrAngajati, float* salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[nrAngajati];
			for (int i = 0; i < nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}
	float getSuprafata() {
		return this->suprafata;
	}
	void setSuprafata(float suprafataNoua) {
		if (suprafata > 0) {
			this->suprafata = suprafata;
		}
	}
	float* getSalarii() {
		return this->salarii;
	}
	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	operator float() {
		float s = 0;
		for (int i = 0; i < this->nrAngajati; i++) {
			s += this->salarii[i];
		}
		return s;
	}

	Magazin operator+(Magazin m2)const {
		Magazin temp = *this;
		temp.nrAngajati = this->nrAngajati + m2.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->salarii[i];
		}
		for (int i = 0; i < m2.nrAngajati; i++) {
			aux[i + this->nrAngajati] = m2.salarii[i];
		}
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = aux;
		return temp;
	}

	Magazin& operator+=(Magazin m) {
		*this = *this + m;
		return *this;
	}

	Magazin operator+(float salariu)const {
		Magazin temp = *this;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++) {
			temp.salarii[i] = this->salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}

	//friend Magazin operator+(float salariu, Magazin m) {
	//	Magazin temp = m;
	//	if (temp.salarii != NULL) {
	//		delete[]temp.salarii;
	//	}
	//	temp.salarii = new float[temp.nrAngajati + 1];
	//	for (int i = 0; i < m.nrAngajati; i++) {
	//		temp.salarii[i] = m.salarii[i];
	//	}
	//	temp.salarii[temp.nrAngajati] = salariu;
	//	temp.nrAngajati++;
	//	return temp;
	//}

	friend Magazin operator+(float salariu, Magazin m);



	void afisare() {
		cout << "Oras:" << this->oras << endl;
		cout << "Numar angajati:" << this->nrAngajati << endl;
		cout << "Suprafata:" << this->suprafata << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Impozit pe m2:" << Magazin::impozitM2 << endl;
	}

	float calculeazaSuprafataMedie() {
		if (this->nrAngajati != 0) {
			return this->suprafata / this->nrAngajati;
		}
		else {
			return 0;
		}
	}

	static void modificaImpozit(int impozit) {
		if (impozit > 0) {
			Magazin::impozitM2 = impozit;
		}
	}

	static float calculeazaSuprafataTotala(Magazin* vector, int nrMagazine) {
		float suma = 0;
		for (int i = 0; i < nrMagazine; i++) {
			suma += vector[i].suprafata;
		}
		return suma;
	}

	bool operator>(Magazin m)
	{
		return this->suprafata > m.suprafata && this->nrAngajati > m.nrAngajati;
	}

	bool operator==(Magazin m)
	{
		return this->suprafata == m.suprafata && this->nrAngajati == m.nrAngajati;
	}

	explicit operator int() {
		return this->nrAngajati;
	}

	float& operator[](int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
		else {
			throw "indexul este in afara limitelor";
		}
	}

	friend ostream& operator<<(ostream& out, const Magazin& m) {
		out << "Oras:" << m.oras << endl;
		out << "Numar angajati:" << m.nrAngajati << endl;
		if (m.nrAngajati > 0) {
			for (int i = 0; i < m.nrAngajati; i++) {
				out << m.salarii[i] << " ";
			}
		}
		out << endl;
		out << "Suprafata:" << m.suprafata << endl;
		out << "An deschidere:" << m.anDeschidere << endl;
		out << "Impozit pe m2:" << Magazin::impozitM2 << endl;

		return out;
	}

	friend istream& operator>>(istream& input, Magazin& m);
};
int Magazin::impozitM2 = 2;


istream& operator>>(istream& input, Magazin& m) {
	cout << "Oras:";
	input >> m.oras;
	cout << "nr angajati:";
	input >> m.nrAngajati;
	if (m.salarii != NULL) {
		delete[]m.salarii;
	}
	if (m.nrAngajati > 0) {
		m.salarii = new float[m.nrAngajati];
		for (int i = 0; i < m.nrAngajati; i++) {
			cout << " Salariul " << i + 1 << ":";
			input >> m.salarii[i];
		}
	}
	else {
		m.salarii = NULL;
	}
	cout << "Suprafata:";
	input >> m.suprafata;
	return input;
}

Magazin operator+(float salariu, Magazin m) {
	float valoare = m.nrAngajati;
	return m + salariu;
}

Magazin f(Magazin m) {
	Magazin magazin;
	return magazin;
}

class Librarie :public Magazin {
	char* nume;
	int nrCarti;

public:
	Librarie(const char* nume, int nrCarti) :Magazin()
	{

		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);//al treilea parametru este sursa
		this->nrCarti = nrCarti;

	}

	Librarie(const char* nume, int nrCarti, string oras, int nrAngajati, float* salarii, float suprafata, const int anDeschidere) :Magazin(oras, nrAngajati, suprafata, anDeschidere) {
		//atributul salarii nu este in parametrii din Magazin asa ca apelam setter ul
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->nrCarti = nrCarti;
		this->setNrAngajati(nrAngajati, salarii); //mergea si varianta in care faceam cu for din nou
	}

	Librarie() :Magazin() {//trebuie initializate si atributele din cealata clasa apeland constructorul din clasa de baza
		this->nume = NULL;
		this->nrCarti = 0;
	}




	//operatorul cast la int ??

	~Librarie() {
		if (this->nume)
			delete[]this->nume;
	}


	//Librarie(const Librarie& l) este semanatura 
	Librarie(const Librarie& l) :Magazin(l) {

		this->nume = new char[strlen(l.nume) + 1];
		strcpy_s(this->nume, strlen(l.nume) + 1, l.nume);//al treilea parametru este sursa
		this->nrCarti = l.nrCarti;

	}

	operator int() {
		return this->nrCarti;
	}

	float getNrMediuCartiPerAngajat() {
		float rezultat = this->nrCarti / (float)this->getNrAngajati();
		return rezultat;
	}

	//ce e dupa : se numeste lista de initializare a constructorului deci nu e nevoie de :Magazin
	Librarie operator =(const Librarie& l) {
		if (&l != this)  //verificare de autoasignare
		{
			// apelam op = din clasa parinte
			Magazin::operator=(l);
			if (this->nume)
				delete[]this->nume;
			this->nume = new char[strlen(l.nume) + 1];
			strcpy_s(this->nume, strlen(l.nume) + 1, l.nume);//al treilea parametru este sursa
			this->nrCarti = l.nrCarti;
		}
		return *this;
	}

	//op << cu friend in line
	friend ostream& operator<<(ostream& output, const Librarie& l) {
		output << (Magazin)l;
		output << "Nume: " << l.nume << endl;
		output << "Nr. carti: " << l.nrCarti << endl; //pe langa astea trebuie sa le afisam si pe cele din clasa parinte

		return output;

	}


};

int main() {

	Librarie l;   //fara () [t ca e un constructor implicit cel fara parametrii
	Librarie l2("Libris", 100);
	//cream un vector pt salarii inaite de a apela
	float* salarii = new float[3] {2000, 3000, 4000};
	Librarie l3("Daco", 80, "Bucuresti", 3, salarii, 200, 2019);
	Librarie l4(l3);
	Librarie l5 = l3;//aamdoua pt constr de copiere
	Librarie l6;
	l6 = l3;//op egal
	cout << l3;
	cout << l6;//ar trebui sa afiseze acelasi lucru, dar nu face asta pt ca op nu a copiat si elem specifice unui magazin trebuie sa apelam op = din clasa parinte cand il scriem

	int nrCarti = (int)l3;//afiseaza 9000 pt ca avem in clasa parinte op de cast la float asta daca nu puneam int in paranteze si cu int in paranteze afisa 3 pt ca in ala parinte era facut op int pt angajati care sumt 3 cred
	cout << "Numar carti:" << nrCarti << endl;

	cout << "Nr mediu de carti per angajat" << l3.getNrMediuCartiPerAngajat() << endl;

	delete[]salarii;


	return 254;
}

//MOSTENIREA IS A reutilizeaza codul dintr-o clasa; o clasa este de tipul altei clase
//HAS A o clasa are atribute de tipul altei clase are obiecte de tipul altei clase