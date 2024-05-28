#ifndef CLIENT_H
#define CLIENT_H

#include "biblioteca.h"
#include "carte.h"
#include <string>
#include <vector>
using namespace std;

class Client : public Biblioteca {
private:
    string nume;
    int varsta;
    int id;
    vector<Carte> cartiImprumutate;
public:
    Client(string n, int v, int i1);

    void imprumutaCarte(const Carte& carte);
    void returneazaCarti();
    bool hasCartiImprumutate() const; 
    void afisare() const override;

    string getNume() const;
};

#endif 
