#include<iostream>

using namespace std;


//structura
//pointeri
//vectori
//transmiterea unui vector prin parametru
//citirea unui vector

struct Tara {
	char* denumire;
	int nrLocuitori;
	string capitala;
	bool areIesireLaMare;
};

void afisareTara(Tara tara) {

}

void afisarePointerLaTara(Tara* pt) {
	cout << "Nume:" << pt->denumire << endl;
	cout << "Numar locuitori:" << pt->nrLocuitori << endl;
	cout << "Capitala:" << pt->capitala << endl;
	cout << "Are iesire la mare:" << (pt->areIesireLaMare ? "DA" : "NU") << endl;//pt->areIesireLaMare
	//if (pt->areIesireLaMare) {
	//	cout << "DA" << endl;
	//}
	//else {
	//	cout << "NU" << endl;
	//}
	//op ternar are 3 operanti binar are 2 unar; asa arata  ?:  am scris cu op ternar ca sa nu mai avem multe linii de cod
}

Tara* citirePointerLaTara() {
	Tara* p = new Tara(); //new aloca pe heap p ocupa 4 sau 8 octeti, iar p este pe stiva
	cout << "Capitala:";
	cin >> p->capitala;
	cout << "Denumire:";
	char buffer[100];//buffer ul e alocare statica pe stiva
	cin >> buffer;//p->capitala;  nu merge sa scriem asa ca e de tip pointer 
	p->denumire = new char[strlen(buffer) + 1];
	strcpy_s(p->denumire, strlen(buffer) + 1, buffer);
	cout << "Numar locuitori:";
	cin >> p->nrLocuitori;

	cout << "Are iesire la mare?(0-NU;1-DA)";
	cin >> p->areIesireLaMare;
	return p;

}


int main() {

	Tara tara;
	tara.areIesireLaMare = false;

	Tara* pTara;
	pTara = new Tara();
	pTara->areIesireLaMare = true;
	pTara->capitala = "Bucuresti";
	pTara->denumire = new char[strlen("Romania") + 1];//+1 pt backslash 0 shallow copy cand atribuim adresele si nu informatii
	strcpy_s(pTara->denumire, strlen("Romania") + 1, "Romania");//eroare strcpy nu e sigura- la sirul de caractere ROMANIA am alocat exact cat are strcpy nu tine cont de spatiu scrie in continuare rezulta folosim strcpy_s care mai are un parametru si practic ii zicem sa se opreasca dupa primele 7 caracrtere
	pTara->nrLocuitori = 200;

	afisarePointerLaTara(pTara);
	delete[]pTara->denumire;
	delete pTara;

	//Tara* p2Tara = citirePointerLaTara();
	//afisarePointerLaTara(p2Tara);

	//Tara vector[10]; nu se face asa pt ca nu introducem 10 ntari si ramane memorie nefolosita
	Tara* vector;
	vector = new Tara[2];
	delete[]vector;

	int nrPointeri = 2;
	//vector de pointeri
	Tara** pointeri;
	pointeri = new Tara * [nrPointeri];//daca nu faceam asa am fi pus 2 in loc de nrPointeri
	for (int i = 0; i < nrPointeri; i++) {
		pointeri[i] = citirePointerLaTara();
	}
	//procesare
	for (int i = 0; i < nrPointeri; i++) {
		afisarePointerLaTara(pointeri[i]);
	}
	//procesare
	for (int i = 0; i < nrPointeri; i++) {
		delete[]pointeri[i]->denumire;
		delete pointeri[i];

	}
	delete[]pointeri;
	//stergem tot ce am alocat dinamic-- memory leak zona de mem alocata care nu a fost dezalocata si nu mai putem ajunge la ea (nu mai avem referinta adresa acelei zone)
}