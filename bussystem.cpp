#include <iostream>
#include <string>

using namespace std;

// ====================
// Person
// ====================
class Person {
protected:
    string name;
    string geburtsdatum;

public:
    Person(string n, string geb)
        : name(n), geburtsdatum(geb) {}

    void anzeigen() {
        cout << "Name: " << name << endl;
        cout << "Geburtsdatum: " << geburtsdatum << endl;
    }
};

// ====================
// Fahrer
// ====================
class Fahrer : public Person {
private:
    string fuehrerscheinNr;

public:
    Fahrer(string n, string geb, string fsNr)
        : Person(n, geb), fuehrerscheinNr(fsNr) {}

    void fahrerInfo() {
        anzeigen();
        cout << "Fuehrerschein-Nr: " << fuehrerscheinNr << endl;
    }
};

// ====================
// Fahrzeug
// ====================
class Fahrzeug {
protected:
    string kennzeichen;
    string fahrgestellNr;

public:
    Fahrzeug(string kz, string fnr)
        : kennzeichen(kz), fahrgestellNr(fnr) {}

    void fahren() {
        cout << "Fahrzeug faehrt." << endl;
    }

    void bremsen() {
        cout << "Fahrzeug bremst." << endl;
    }
};

// ====================
// Bus
// ====================
class Bus : public Fahrzeug {
private:
    int busNr;
    string start;
    string ziel;
    int fahrgaeste;

    // Assoziation zu Fahrer
    Fahrer* fahrer;

public:
    Bus(
        string kz,
        string fnr,
        int nr,
        string s,
        string z,
        Fahrer* f
    )
        : Fahrzeug(kz, fnr),
          busNr(nr),
          start(s),
          ziel(z),
          fahrgaeste(0),
          fahrer(f) {}

    void halten() {
        cout << "Bus haelt an der Haltestelle." << endl;
    }

    void einsteigen(int anzahl) {
        fahrgaeste += anzahl;
        cout << anzahl << " Fahrgaeste eingestiegen." << endl;
    }

    void aussteigen(int anzahl) {
        fahrgaeste -= anzahl;

        if (fahrgaeste < 0) {
            fahrgaeste = 0;
        }

        cout << anzahl << " Fahrgaeste ausgestiegen." << endl;
    }

    void busInfo() {
        cout << endl;
        cout << "===== BUS INFO =====" << endl;
        cout << "Busnummer: " << busNr << endl;
        cout << "Kennzeichen: " << kennzeichen << endl;
        cout << "Fahrgestellnummer: " << fahrgestellNr << endl;
        cout << "Start: " << start << endl;
        cout << "Ziel: " << ziel << endl;
        cout << "Fahrgaeste: " << fahrgaeste << endl;

        cout << endl;
        cout << "===== FAHRER =====" << endl;
        fahrer->fahrerInfo();
    }
};

// ====================
// Main
// ====================
int main() {

    Fahrer fahrer1(
        "Max Mustermann",
        "01.01.1980",
        "FS-12345"
    );

    Bus bus1(
        "M-AB-123",
        "FG-999999",
        42,
        "Muenchen Hbf",
        "Flughafen",
        &fahrer1
    );

    bus1.fahren();

    bus1.halten();
    bus1.einsteigen(5);

    bus1.fahren();

    bus1.halten();
    bus1.aussteigen(2);

    bus1.bremsen();

    bus1.busInfo();

    return 0;
}
