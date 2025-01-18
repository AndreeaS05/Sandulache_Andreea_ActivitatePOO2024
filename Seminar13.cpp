#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<numeric>
#include<algorithm>
using namespace std;

class Librarie {
protected:
	string nume;
public:
	Librarie() {
		this->nume = "Mihai Eminescu";
	}
	Librarie(string nume) {
		this->nume = nume;
	}
	virtual string getDenumire() {//tabela de pointeri la fct virtuale si o sa avem un pointer care retine adresa acestei metode supradefinire in clasa libonline 
		return nume;
	}
};
class LibrarieOnline :public Librarie {
	string site;

public:
	LibrarieOnline() :Librarie("Librarie Online") {
		this->site = "www.site.ro";

	}
	LibrarieOnline(string nume, string site) :Librarie(nume) {//apelam constructorul din clasa de baza
		this->site = site;
	}
	string getDenumire() {
		return nume + "-" + site;//
	}
};

int main() {

	LibrarieOnline lo("Libris", "libris.ro");

	cout << lo.getDenumire() << endl;

	Librarie* lib = new  LibrarieOnline("Humanitas", "humanitas.ro");

	cout << lib->getDenumire() << endl;

	//stl librarie de clasa template ce contine algoritmi containere si iteratori
	vector<float>v;
	v.push_back(1.2);
	v.push_back(4.5);
	v.push_back(3.7);
	v.push_back(5.9);
	float s = 0;
	for (int i = 0; i < v.size(); i++) {

		s += v[i];
	}

	float suma = accumulate(v.begin(), v.end(), 0);

	if (v.size() > 0) {
		cout << "Media este:" << s / v.size() << endl;
	}
	else
		cout << "Media nu poate fi calculata." << endl;
	for (int i = 0; i < v.size(); i++) {

		cout << v[i] << endl;
	}

	//st<Librarie>* l;//pointer la o lista de librarii
	list<Librarie*>lista;
	lista.push_front(new Librarie());
	lista.push_front(new Librarie("Carturesti"));
	lista.push_front(new LibrarieOnline("Bookzone", "bookzone.ro"));
	lista.push_front(new LibrarieOnline());
	list<Librarie*>::iterator it = lista.begin();
	while (it != lista.end()) {
		cout << (*it)->getDenumire() << endl;
		it++;
	}

	map<int, Librarie>librarii;
	librarii.insert(pair<int, Librarie>(1, Librarie()));
	librarii.insert(pair<int, Librarie>(27, Librarie("Carturesti")));
	librarii.insert(pair<int, Librarie>(3, Librarie("Libris")));
	librarii.insert(pair<int, Librarie>(17, Librarie("Humanitas")));
	librarii.insert(pair<int, Librarie>(3, Librarie("Mihail Sadoveanu")));//cheile ca si val din set sunt unice si sortate

	cout << librarii[27].getDenumire() << endl;
	map<int, Librarie>::iterator iterator = librarii.begin();
	cout << "Afisare map:" << endl;
	while (iterator != librarii.end()) {
		cout << iterator->first << " - ";
		cout << iterator->second.getDenumire();
		iterator++;

	}




	return 0;

}
