#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Proizvod {
    string naziv;
    double cijena;
    int kolicina;
};

int main() {
    Proizvod proizvodi[16] = {
        {"Coca-Cola", 1.50, 10},
        {"Fanta", 1.50, 10},
        {"Sprite", 1.50, 10},
        {"Pepsi", 1.40, 10},
        {"Next sok", 1.20, 10},
        {"Voda", 1.00, 10},
        {"Red Bull", 2.00, 10},
        {"Ice Tea", 1.30, 10},
        {"Chips", 1.80, 10},
        {"Smoki", 1.00, 10},
        {"Cokoladica", 1.20, 10},
        {"Bananica", 0.80, 10},
        {"Keks", 1.10, 10},
        {"Sendvič", 2.50, 10},
        {"Croissant", 1.60, 10},
        {"Gumene bombone", 0.90, 10}
    };

    double novac;
    cout << "Unesite iznos novca: ";
    cin >> novac;
    cout << fixed << setprecision(2);
    cout << "Trenutno ste unijeli: " << novac << " KM\n";

    while (true) {
        cout << "\nIzaberite proizvod:\n";
        for (int i = 0; i < 16; ++i) {
            cout << i+1 << ". " << proizvodi[i].naziv 
                 << " - " << proizvodi[i].cijena << " KM"
                 << " (preostalo: " << proizvodi[i].kolicina << ")\n";
        }
        cout << "0. Kraj kupovine i vrati visak novca\n";
        cout << "Unesite broj proizvoda: ";
        int izbor;
        cin >> izbor;

        if (izbor == 0) {
            cout << "Vas visak novca: " << novac << " KM\n";
            cout << "Hvala na kupovini!\n";
            break;
        }
        if (izbor < 1 || izbor > 16) {
            cout << "Nepostojeci izbor!\n";
            continue;
        }
        Proizvod &p = proizvodi[izbor-1];
        if (p.kolicina == 0) {
            cout << "Proizvod \"" << p.naziv << "\" je rasprodat!\n";
            continue;
        }
        if (novac < p.cijena) {
            cout << "Nemate dovoljno kredita za \"" << p.naziv << "\"!\n";
            continue;
        }
        // Kupovina
        novac -= p.cijena;
        p.kolicina--;
        cout << "Kupili ste: " << p.naziv << ". Preostalo novca: " << novac << " KM\n";
        if (novac < 0.80) { // najmanja cijena proizvoda
            cout << "Nemate dovoljno novca za dalje kupovine.\n";
            cout << "Vas visak novca: " << novac << " KM\n";
            break;
        }
        cout << "Zelite li kupiti jos nesto? (1 - da, 0 - ne): ";
        int jos;
        cin >> jos;
        if (!jos) {
            cout << "Vas visak novca: " << novac << " KM\n";
            cout << "Hvala na kupovini!\n";
            break;
        }
    }
    return 0;
}