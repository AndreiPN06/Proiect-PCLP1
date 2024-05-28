#ifndef CARTE_H
#define CARTE_H

#include "biblioteca.h"
#include <string>

using namespace std;

class Carte : public Biblioteca {
private:
    string titlu;
    string autor;
    int anPublicatie;

public:
    Carte(string t, string a, int an);

    void afisare() const override;
    string getTitlu() const;
    int getAnPublicatie() const;
};

#endif 

