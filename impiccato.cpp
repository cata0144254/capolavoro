#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {

    int vite = 10;
    bool vinto = false;
    const int l = 6;

    // chiediamo la parola da indovinare:
    cout << "inserisci la parola da indovinare" << endl;

    // Leggiamo la parola da indovnare:
    char parola[l];
    cin.getline(parola, l+1);
    cout << parola << endl;

    // soluzione parziale inizialmente vuota
    char soluzioneParziale[l];
    for (int i = 0; i < l; i++) {
        soluzioneParziale[i] = '_';
    }

    char lettera;

    // turno
    do {
        // chiedi la lettera
        cout << "inserisci una lettera" << endl;

        // leggi la lettera
        cin >> lettera;

        // aggiorna la soluzione parziale
        for (int i = 0; i < l; i++) {
            if (parola[i] == lettera) {
               soluzioneParziale[i] = lettera; //
            }
        }

        // mostra la soluzione parziale
        cout << "Soluzione Parziale:" << endl;
        for (int i = 0; i < sizeof(soluzioneParziale); i++) {
            cout << soluzioneParziale[i];
        }
        cout << endl;

        // capire se abbiamo indovinato
        bool indovinato = true;
        for (int i = 0; i < l; i++) {
            if (parola[i] == soluzioneParziale[i]) {
                // niente
            }
            else {
                indovinato = false;
            }
        }

        // aggiorna le vite
        vite--;

        // aggiornare se abbiamo vinto
        if (indovinato == true) {
            vinto = true;
        }
    }
    while (!vinto && vite > 0);
    if (vinto) {
        cout << "HAI VINTO!" << endl;
    }
    if (vite == 0) {
       cout << "hai finito le vite" << endl;
    }
    cout << "vite rimanenti: " << vite << endl;
    cout << "La soluzione era:" << endl;
    cout << parola << endl;

    return 0;
}
