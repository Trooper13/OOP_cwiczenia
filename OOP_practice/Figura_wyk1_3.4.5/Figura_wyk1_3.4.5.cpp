// Figura_wyk1_3.4.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//using namespace std;

class Figura 
{
private:
	int dlugosc, szerokosc, powierzchnia;

public:
	Figura();
	//{
	//	dlugosc = 0;
	//	szerokosc = 0;
	//	powierzchnia = dlugosc*szerokosc;
	//}

	Figura(int d, int s);
	
	//Definiowanie konstruktora za pomocą listy inicjatorów
	//Inaczej: { d=dlugosc, s=szerokosc, p=powierzchnia }
	Figura::Figura(int d, int s, int p) : dlugosc(d), szerokosc(s), powierzchnia(p) {};

	int pobierzDl() { return dlugosc; }
	int pobierzSzer() { return szerokosc; }
	int pobierzPole() { return powierzchnia; }
	void ustawDl(int dl);
	void ustawSzer(int szer);
};

Figura::Figura()
{
	dlugosc = 0;
	szerokosc = 0;
	powierzchnia = dlugosc*szerokosc;
}

//Summary: w poniższym konstruktorze opędzone jest stworzenie jednocześnie			kontruktora domyślnego (jak powyżej, z zerami) i konstruktora z dwoma parametrami (int, int)

//Figura::Figura(int d=0, int s=0)
//{
//	dlugosc = d;
//	szerokosc = s;
//	powierzchnia = d*s;
//}

// można jescze w taki sposób
//Figura::Figura(int d = 0, int s = 0) : dlugosc(d), szerokosc(s), powierzchnia(dlugosc*szerokosc) {}

Figura::Figura(int d, int s)
{
	dlugosc = d;
	szerokosc = s;
	powierzchnia = d*s;
}


void Figura::ustawDl(int d)
{
	dlugosc = d;
	powierzchnia = dlugosc*szerokosc;
}

void Figura::ustawSzer(int s)
{
	szerokosc = s;
	powierzchnia = dlugosc*szerokosc;
}

int main()
{
	using std::cin; using std::cout; using std::endl;

	int x, y;
	cout << "Podaj dlugosc: ";
	cin >> x;
	cout << "Podaj szerokosc: ";
	cin >> y;
	Figura a(x, y); // utwórz prostokąt a
	Figura b;
	cout << "Dlugosc=" << a.pobierzDl() << " Szerokosc=" << a.pobierzSzer()
		<< " Pole=" << a.pobierzPole() << endl;
	cout << "Podaj nowa dlugosc: ";
	cin >> x;
	a.ustawDl(x);
	cout << "Dlugosc=" << a.pobierzDl() << " Szerokosc=" << a.pobierzSzer()
		<< " Pole=" << a.pobierzPole() << endl;
	cout << "Podaj nowa szerokosc: ";
	cin >> y;
	a.ustawSzer(y);
	cout << "Dlugosc=" << a.pobierzDl() << " Szerokosc=" << a.pobierzSzer()
		<< " Pole=" << a.pobierzPole() << endl;
	
	cout << "Dlugosc=" << b.pobierzDl() << " Szerokosc=" << b.pobierzSzer()
		<< " Pole=" << b.pobierzPole() << endl;

	Figura *c = new Figura(); // obiekt bez nazwy, dostęp za pomocą wskaźnika
	Figura *d = new Figura(10, 10); // obiekt bez nazwy, dostęp za pomocą wskaźnika
	

	getchar();
	getchar();
	return 0;
}

