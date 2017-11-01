// Author: Mateusz Mitura
// Date: 25.10.2017
// WIT

#include "stdafx.h" // <= musi byæ na samym szczycie, inaczej s¹ b³êdy kompilacji
#include <iostream>
#include <cmath>

using namespace std;

class Frac {

	int num, denum;

	/*Funkcja sprawdzajaca czy przypadkiem ¿adna z liczb nie jest ujemna a nastêpnie
	  znalezienie najwiekszego wspólnego dzielnika liczb, aby wprowadzony u³amek
	  sprowadziæ do formy "skróconej" - algorytm Euklidesa*/
	static int NWD(int a, int b) {
		if (a<0) a = -a;
		if (b<0) b = -b;
		while (a != b) {
			if (a>b) a = a - b;
			if (a<b) b = b - a;
		}
		return a;
	}

public:

	Frac(int n) {
		this->num = n;
		denum = 1;
	}

	Frac() {
		num = 0;
		denum = 1;
	}

	Frac(int n, int d) {
		if (d == 0) throw 1;
		if (n == 0) {
			num = 0;
			denum = 1;
			return;
		}
		if (d<0) {
			n = -n;
			d = -d;
		}
		int nwd = NWD(n, d);

		this->num = n / nwd;
		this->denum = d / nwd;
	}
	void show() {
		cout << num << "/" << denum << endl;
	}
	
	Frac& add(const Frac& f) {
		int temp_num = this->num*f.denum + this->denum*f.num;
		int temp_denum = this->denum*f.denum;

		int temp_nwd = NWD(temp_num, temp_denum);

		this->num = temp_num / temp_nwd;
		this->denum = temp_denum / temp_nwd;
		return *this;
	}
	static Frac add(const Frac& f1, const Frac& f2) {
		int temp_num = f1.num*f2.denum + f1.denum*f2.num;
		int temp_denum = f1.denum*f2.denum;

		int temp_nwd = NWD(temp_num, temp_denum);
		temp_num /= temp_nwd;
		temp_denum /= temp_nwd;

		return Frac(temp_num, temp_denum);
	}

};

int main() {
	// 2 * ( (2 + 4/10)*5 - 4 ) / (24/15) = 10
	//Frac f1 = Frac(2).mul(Frac::sub(Frac(5).mul(
	//Frac::add(Frac(2), Frac(4, 10));
	//Frac(4))).div(Frac(24,15));
	
	//// 7 - 1/3 + (2/6 * 1114) / 111
	//Frac f2 = Frac(7).sub(Frac(1,3)).add(
	//Frac::div(Frac(2,6).mul(Frac(1114)),Frac(111)));
	//f1.show(); std::cout << " ";
	//f2.show(); std::cout << std::endl;
	
	Frac f1(3, 5);
	Frac f2(4, 6);
	f1.show();
	f1.add(Frac(3, 10)).show();

	getchar();
	return 0;
}
