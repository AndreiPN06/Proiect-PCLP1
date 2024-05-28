#include "carte.h"
#include <iostream>
using namespace std;

Carte::Carte(string t, string a, int an) : titlu(t), autor(a), anPublicatie(an) {}

void Carte::afisare() const {
    cout << "Carte: " << titlu << ", Autor: " << autor << ", An: " << anPublicatie << endl;
}
int Carte::getAnPublicatie() const {
    return anPublicatie;
}
string Carte::getTitlu() const {
    return titlu;
}
