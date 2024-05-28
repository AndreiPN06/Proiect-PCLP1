#include <iostream>
#include <vector>
#include "carte.h"
#include "client.h"
using namespace std;

void afisare(const Biblioteca& obj) {
    obj.afisare();
}

int main() {
    
    Carte carte1("Poveste lui Harap Alb", "Ion Creanga", 1873);
    Carte carte2("Moara cu noroc", "Ioan Slavici", 1881);
    Carte carte3("Ion", "Liviu Rebreanu", 1920);
    Carte carte4("Baltagul", "Mihail Sadoveanu", 1930);
    Carte carte5("Ultima noapte de dragoste intaia noapte de razboi", "Camil Petrescu", 1930);
    Carte carte6("Enigma Otiliei", "George Calinescu", 1938);
    Carte carte7("Morometii", "Marin Preda", 1955);

    
    Client client1("Ion Popescu", 30,1);
    Client client2("Maria Ionescu", 25,2);
    Client client3("Andrei Georgescu", 35,3);
    Client client4("Maxim Marius", 22, 4);
    Client client5("Munteanu Diana", 20, 5);

    vector<Client> clienti = { client1, client2, client3, client4,client5 };
    int an1;
    int an2;
    int optiune;
    int clientSelectat;
    bool imprumuta = false;

    cout << "Selectati clientul care doreste sa imprumute o carte:" << endl;
    for (size_t i = 0; i < clienti.size(); ++i) {
        afisare(clienti[i]);
    }

    cin >> clientSelectat;

    if (clientSelectat < 1 || clientSelectat > clienti.size()) {
        cout << "Optiune invalida!" << endl;
        return 1;
    }

    Client& client = clienti[clientSelectat - 1];

    cout << "Doriti ca clientul sa imprumute o carte? (1 - Da, 0 - Nu): ";
    cin >> optiune;
    imprumuta = (optiune == 1);

    if (imprumuta) {
        if (client.hasCartiImprumutate()) {
            cout << "Clientul are deja o carte imprumutata si nu poate imprumuta alta carte." << endl;
        }
        else {
            
            vector<Carte> carti = { carte1, carte2, carte3, carte4, carte5, carte6, carte7 };
            int anStart, anFinal;
            cout << "Introduceti anul de inceput al perioadei: ";
            cin >> anStart;
            cout << "Introduceti anul de sfarsit al perioadei: ";
            cin >> anFinal;

            cout << "Cartile publicate intre anii " << anStart << " si " << anFinal << " sunt:" << endl;
            for (const auto& carte : carti) {
                int anCarte = carte.getAnPublicatie();
                if (anCarte >= anStart && anCarte <= anFinal) {
                    carte.afisare();
                }
                
            }

            
            
            

            int carteSelectata;
            cin >> carteSelectata;

            switch (carteSelectata) {
            case 1:
                client.imprumutaCarte(carte1);
                break;
            case 2:
                client.imprumutaCarte(carte2);
                break;
            case 3:
                client.imprumutaCarte(carte3);
                break;
            case 4:
                client.imprumutaCarte(carte4);
                    break;
            case 5:
                client.imprumutaCarte(carte5);
                    break;
            default:
                cout<< "Optiune invalida!" << endl;
                break;
            }
        }
    }

  
    cout << "\nInformatii carti:" << endl;
    afisare(carte1);
    afisare(carte2);
    afisare(carte3);
    afisare(carte4);
    afisare(carte5);

    cout << "\nInformatii clienti:" << endl;
    for (const auto& client : clienti) {
        afisare(client);
    }

    return 0;
}
