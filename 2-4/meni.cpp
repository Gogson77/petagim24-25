#include <iostream>
#include <string>
using namespace std;

int main() {
    string meni[] = {
        "Hamburger",
        "Pita",
        "Sendvic",
        "Hotdog",
        "Pizza",
        "Doner",
        "Koka-kola"
    };

    cout << "Meni restorana:\n";
    for (int i = 0; i < 7; ++i) {
        cout << i + 1 << ". " << meni[i] << endl;
    }

    int izbor;
    cout << "Sta zelite naruciti? Unesite broj narudzbe (1-7): ";
    cin >> izbor;

    if (izbor >= 1 && izbor <= 7) {
        cout << "Narucili ste: " << meni[izbor - 1] << endl;
    } else {
        cout << "Pogresan unos!" << endl;
    }

    return 0;
}