#include "client.h"
#include <iostream>
using namespace std;
Client::Client(string n, int v,int i1) : nume(n), varsta(v) ,id(i1){}

void Client::imprumutaCarte(const Carte& carte) {
    if (!cartiImprumutate.empty()) {
        cout << "Clientul " << nume << " are deja o carte imprumutata si nu poate imprumuta alta carte." << endl;
        return;
    }
    cartiImprumutate.push_back(carte);
    cout << "Clientul " << nume << " a imprumutat cartea: " << carte.getTitlu() << endl;
}

void Client::returneazaCarti() {
    cartiImprumutate.clear();
}

bool Client::hasCartiImprumutate() const {
    return !cartiImprumutate.empty();
}

void Client::afisare() const {
    cout << "Client: " << nume << ", Varsta: " << varsta <<" "<< "ID_Client:" << id<<endl;
    cout << "Carti imprumutate: " << endl;
    if (cartiImprumutate.empty()) {
        cout << "Nicio carte imprumutata." << endl;
    }
    else {
        for (const auto& carte : cartiImprumutate) {
            carte.afisare();
        }
    }
}

string Client::getNume() const {
    return nume;
}
