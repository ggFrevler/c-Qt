#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Helo world
/*
int main()
{
    std::cout << "Hello World!\n";
}
*/



// Massive 
/*
int main() {
    int n; vector <int> p;

    cout << "Kol-vo chisel: "; cin >> n;

    int a;
    for (int i = 0; i < n; i++) {
        cout << "number " << i + 1 << ": "; cin >> a;
        p.push_back(a);
    }

    cout << "Do: ";

    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }

    sort(p.begin(), p.end());
    cout << endl << "Posle: ";

    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    return 0;
}
*/




// bank

class Schet
{
public:
    int number_schet;
    char valuta;
    int kol_vo_deneg;

    void display()
    {
        cout << "nomer scheta: " << number_schet << endl;
        cout << "Valuta: " << valuta << endl;
        cout << "Schet: " << kol_vo_deneg << endl;
        cout << "\n" << endl;

    }
};

class Card : public Schet
{
public:
    int nomer_card;
    string name;
    string sname;
    int draft;

    void display()
    {
        cout << "nomer scheta: " << number_schet << endl;
        cout << "Valuta: " << valuta << endl;
        cout << "Schet: " << kol_vo_deneg << endl;
        cout << "nomer carty: " << nomer_card << endl;
        cout << "Name: " << sname << " " << name << endl;
        cout << "ur draft: " << draft << endl;


    }
};




int main()
{
    Schet som;
    som.number_schet = 46546848;
    som.valuta = { 'S' };
    som.kol_vo_deneg = 1000;
    som.display();

    Schet euro;
    euro.number_schet = 879878464;
    euro.valuta = { 'E' };
    euro.kol_vo_deneg = 10;
    euro.display();


    Card dollar;
    dollar.number_schet = 123456789;
    dollar.valuta = { '$' };
    dollar.kol_vo_deneg = 100;
    dollar.nomer_card = 123425;
    dollar.name = "Tom";
    dollar.sname = "So";
    dollar.draft = 10;
    dollar.display();

    return 0;
}
