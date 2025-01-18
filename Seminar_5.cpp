#include<iostream>

using namespace std;

class Masina {
private:
	int nrRoti;
	string* producatori;
	string marca;
	float pret;
	static int TVA;
	const int anFabricatie;
public:
	Masina() :anFabricatie(2024), nrRoti(4) {
		this->marca = "Dacia";
		this->pret = 5000;
		this->producatori = NULL;
	}
	Masina(int _nrRoti, string marca, float pret, int an) :anFabricatie(an) {
		this->nrRoti = _nrRoti;
		this->marca = marca;
		this->pret = pret;
		this->producatori = new string[this->nrRoti];
		for (int i = 0; i < this->nrRoti; i++) {
			this->producatori[i] = "Michelin";
		}
	}
	Masina(const Masina& m) :anFabricatie(m.anFabricatie) {
		this->nrRoti = m.nrRoti;
		this->marca = m.marca;
		this->pret = m.pret;
		this->producatori = new string[m.nrRoti];
		for (int i = 0; i < m.nrRoti; i++) {
			this->producatori[i] = m.producatori[i];
		}
	}

	Masina operator=(const Masina& m) {//referinta constanta ca sa evitam apelul constr de copiere daca cand punem const ma asigur ca modificam ob care trebuie
		if (&m != this) {//verificare de autoasignare
			this->nrRoti = m.nrRoti;
			this->marca = m.marca;
			this->pret = m.pret;
			if (this->producatori != NULL) {
				delete[]this->producatori;//intai dezalocam trebuie pus inainte de alocare
				this->producatori = new string[m.nrRoti];
				for (int i = 0; i < m.nrRoti; i++) {
					this->producatori[i] = m.producatori[i];
				}
			}

		}//obicetul de la adresa lui this obiectul pe care noi l-am modificat de la adresa lui this

		return*this;

	}//daca punem in main m4=m4 daca stergem prod din this ii stergem si din m si atunci trebuie verificare de autoasignare

	Masina operator+(const Masina& m) const {//ultimul const e ca sa facem pointerul this sa fie constant
		Masina temp = *this;
		temp.pret = this->pret + m.pret;
		return temp;
	}

	Masina operator+=(const Masina& m) { //aici this ul se modifica adica m4 care se duce in this se modifica
		this->pret = this->pret + m.pret;
		return *this;
	}

	Masina operator+(float valoare) const {
		Masina temp = *this;
		temp.pret = this->pret + valoare;
		return temp;
	}

	~Masina() {
		if (this->producatori != NULL) {
			delete[]this->producatori;
		}
	}

	string getMarca() {
		return this->marca;
	}
	void setMarca(string marca) {
		if (marca.length() > 2) {
			this->marca = marca;
		}
	}
	float getPret() {
		return this->pret;
	}
	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
	}
	string* getProducatori() {
		return this->producatori;
	}

	string getProducator(int index) {
		if (index >= 0 && index < this->nrRoti) {
			return this->producatori[index];
		}
		else {
			return "NU a fost gasit.";
		}
	}
	void setNrRoti(int nrRoti, string* producatori) {
		if (nrRoti > 0) {
			this->nrRoti = nrRoti;
			if (this->producatori != NULL) {
				delete[]this->producatori;
			}
			this->producatori = new string[nrRoti];
			for (int i = 0; i < nrRoti; i++) {
				this->producatori[i] = producatori[i];
			}
		}
	}

	void afisare() {
		cout << "Marca:" << this->marca << endl;
		cout << "Nr roti:" << this->nrRoti << ": ";
		if (this->producatori != NULL) {
			for (int i = 0; i < this->nrRoti; i++) {
				cout << this->producatori[i] << ", ";
			}
		}
		cout << endl;
		cout << "Pret:" << this->pret << endl;
		cout << "TVA:" << this->TVA << endl;
		cout << "An fabricatie:" << this->anFabricatie << endl;
	}

	float calculeazaPretTotal() {
		return this->pret + (this->pret * (Masina::TVA / 100.0f));
	}

	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Masina::TVA = noulTVA;
		}
	}

	static float calculeazaPretTotalVector(int nrMasini, Masina* vector) {
		float pretTotal = 0;
		for (int i = 0; i < nrMasini; i++) {
			pretTotal += vector[i].calculeazaPretTotal();
		}
		return pretTotal;
	}

	friend Masina operator+(float valoare, const Masina& m);
};

int Masina::TVA = 19;

Masina operator+(float valoare, const Masina& m) {
	Masina masina = m;
	masina.pret = valoare + m.pret;
	return masina;
}

int main() {
	Masina m;


	Masina m2(4, "BMW", 45000, 2021);


	m2.setNrRoti(6, new string[6]{ "Michelin","Continental","Bridgestone", "Pirelli", "Hankoover", "POO" });


	Masina m3(m2);
	Masina m4 = m2;

	m4 = m2;
	m4.operator=(m2);

	m4 = m4;
	m4 = m2 + m3;//se apeleaza m4.operator=(m2.operator+(m3))metoda apelata prin obiectul m2 care are rolul this ului
	m2 + m2;//m2.operatro+(m3)
	//polimorfism prin nr si sau tipul parametrilor
	m4 += m2;//m4.operator+=(m2)

	m4 = m2 + 5000.0f; //tipul celui de al doilea param e float are tipul schimbat  se asigura polimorfismul de aceea putem face supraincarcarea
	//m2.operator+(5000.0f)
	m4 = 5000.0f + m2;//facemj in afara clasei pt ca 5000.0f nu este de tipul clasei
	//operator+(5000.0f,m2)

}