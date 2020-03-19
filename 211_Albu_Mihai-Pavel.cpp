#include <iostream>
#include <math.h>
using namespace std;

#include "complex.h"

class Matrice_Complexa {

private:
	friend class complex;
	complex matrix[100][100];
	int n;
	int m;

public:
	Matrice_Complexa ();
	Matrice_Complexa (Matrice_Complexa&);
	Matrice_Complexa (complex, int, int);
	friend istream& operator>>(istream &in, Matrice_Complexa& m);
	friend ostream& operator<<(ostream& out, Matrice_Complexa& mat);
	friend Matrice_Complexa& operator+(Matrice_Complexa &fst, Matrice_Complexa& snd);
	friend Matrice_Complexa& operator*(Matrice_Complexa &fst, Matrice_Complexa& snd);
	int get_n() {return n;};
	int get_m() {return m;};
	~Matrice_Complexa();

};

Matrice_Complexa::Matrice_Complexa(){
}

Matrice_Complexa::Matrice_Complexa(complex x, int n, int m)
{
	this->n = n;
	this->m = m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			this->matrix[i][j] = x;
}

Matrice_Complexa::Matrice_Complexa(Matrice_Complexa &mat)
{
	this->n = mat.n;
	this->m = mat.m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			this->matrix[i][j] = mat.matrix[i][j];
}

Matrice_Complexa::~Matrice_Complexa(){
	this->n = 0;
	this->m = 0;
}

istream& operator>>(istream& in, Matrice_Complexa& mat){
    cout << "* N (numar de linii): ";
    in >> mat.n;
    cout << "* M (numar de coloane): ";
    in >> mat.m;
	for(int i = 0; i < mat.n; i++)
		for(int j = 0; j < mat.m; j++)
		{
    		cout << "* a[" << i << "][" << j << "] = \n";
			in >> mat.matrix[i][j];
		}
    return in;
}

ostream& operator<<(ostream& out, Matrice_Complexa& mat){
	int i, j;
    cout << "\nMatricea are " << mat.n << " linii si " << mat.m << " coloane.\n";
    cout << "\n\t\t";
    for(i = 0; i < mat.m; i++)
    	cout << "Coloana " << (i + 1) << "\t";
    cout << "\n";
    for(i = 0; i < mat.n; i++)
    {	
    	cout << "Linia " << (i + 1) << "\t\t";
    	for(j = 0; j < mat.m; j++)
    		cout << mat.matrix[i][j] << "\t\t";
    	cout << "\n";
    }
    return out;
}

inline Matrice_Complexa& operator+(Matrice_Complexa &fst, Matrice_Complexa& snd){
    Matrice_Complexa *sum = new Matrice_Complexa;
    sum->n = fst.n;
    sum->m = fst.m;
    for(int i = 0; i < sum->n; i++)
    	for(int j = 0; j < sum->m; j++)
    		sum->matrix[i][j] = fst.matrix[i][j] + snd.matrix[i][j];
    return *sum;
}

inline Matrice_Complexa& operator*(Matrice_Complexa &fst, Matrice_Complexa& snd){
    Matrice_Complexa *prod = new Matrice_Complexa;
    prod->n = fst.n;
    prod->m = snd.m;
    for(int i = 0; i < prod->n; i++)
    	for(int j = 0; j < prod->m; j++)
    	{
    		complex tmp;
    		tmp.set_real(0);
    		tmp.set_imaginar(0);
    		for(int k = 0; k < fst.m; k++)
    			tmp = tmp + fst.matrix[i][k] * snd.matrix[k][j];
    		prod->matrix[i][j] = tmp;
    	}
    return *prod;
}

int main ()
{
	int action = 1;
	while(action)
	{
		cout << "\n-----------------------------------------------\n";
		cout << "Introduceti actiunea: \n";
		cout << "1) Calculul SUMEI a 2 matrice\n";
		cout << "2) Calculul PRODUSULUI a 2 matrice\n";
		cout << "3) Constructia unei matrice cu un element anume\n";
		cout << "0) Iesire din program";
		cout << "\n-----------------------------------------------\n";
		cin >> action;
		switch (action){
			case 1:{
				Matrice_Complexa A, B, R;
				cout << "\n-----------------------------\n";
				cout << "Introduceti prima matrice: \n\n";
				cin >> A;
				cout << "\n-----------------------------\n";
				cout << "Introduceti a doua matrice: \n\n";
				cin >> B;
				if (A.get_n() != B.get_n() || A.get_m() != B.get_m())
				{
					cout << "\n-----------------------------\n";
					cout << "Nu se poate efectua adunarea\n";
					cout << "Conditie: sa corespunda nr. de linii / coloane\n";
					cout << "\n====================\n";
					cout << "1) Inapoi la meniu\n";
					cout << "2) Iesire";
					cout << "\n====================\n";
					cin >> action;
					if (action == 2)
						return 0;
					break;
				}
				R = A + B;
				cout << "Suma este:\n" << R << "\n";
				cout << "\n====================\n";
				cout << "1) Inapoi la meniu\n";
				cout << "2) Iesire";
				cout << "\n====================\n";
				cin >> action;
				if (action == 2)
					return 0;
				break;
			}
			case 2:{
				Matrice_Complexa A, B, R;
				cout << "\n-----------------------------\n";
				cout << "Introduceti prima matrice: \n\n";
				cin >> A;
				cout << "\n-----------------------------\n";
				cout << "Introduceti a doua matrice: \n\n";
				cin >> B;
				if (A.get_m() != B.get_n())
				{
					cout << "\n-----------------------------\n";
					cout << "Nu se poate efectua adunarea\n";
					cout << "Conditie: nr. de coloane ale primei matrice = nr. de linii ale celei de-a doua\n";
					cout << "\n====================\n";
					cout << "1) Inapoi la meniu\n";
					cout << "2) Iesire";
					cout << "\n====================\n";
					cin >> action;
					if (action == 2)
						return 0;
					break;
				}
				R = A * B;
				cout << "\n-------------------\n";
				cout << "Produsul este:\n" << R << "\n";
				cout << "\n-------------------\n";
				cout << "\n====================\n";
				cout << "1) Inapoi la meniu\n";
				cout << "2) Iesire";
				cout << "\n====================\n";
				cin >> action;
				if (action == 2)
					return 0;
				break;
			}
			case 3:{
				complex x;
				int lins, cols;
				cout << "Introduceti elementul complex:\n"; cin >> x;
				cout << "Introduceti numarul de linii: "; cin >> lins;
				cout << "Introduceti numarul de coloane: "; cin >> cols;
				Matrice_Complexa matr(x, lins, cols);
				cout << matr;
				cout << "\n====================\n";
				cout << "1) Inapoi la meniu\n";
				cout << "2) Iesire";
				cout << "\n====================\n";
				cin >> action;
				if (action == 2)
					return 0;
				break;
			}
		}
	}
	return 0;
}