#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

enum class TipMaterie { Obligatorie, Facultativa, Optionala };

class Materie {
protected:
    string nume;
    TipMaterie tip;
    int credite;

public:
    Materie(string nume, TipMaterie tip, int credite)
        : nume(nume), tip(tip), credite(credite) {}

    virtual ~Materie() = default;

    string getNume() const { return nume; }
    TipMaterie getTip() const { return tip; }
    int getCredite() const { return credite; }

    virtual void afisare() const = 0;
};

class Matematica : public Materie {
public:
    Matematica() : Materie("Matematica", TipMaterie::Obligatorie, 6) {}
    void afisare() const override {
        cout << "Matematica (obligatorie, 6 credite)" << endl;
    }
};

class Optional1 : public Materie {
public:
    Optional1() : Materie("Engleza", TipMaterie::Optionala, 3) {}
    void afisare() const override {
        cout << "Engleza (optional, 3 credite)" << endl;
    }
};

// Structura nota + materie
//struct NotaMaterie {
//    Materie* materie;
//    float nota;
//};

class Student {
private:
    string nume;
    int nrMatricol;
    string programInvatare;
    map<Materie*, float> noteMaterii;

public:
    Student(string nume, int nrMatricol, string programInvatare)
        : nume(nume), nrMatricol(nrMatricol), programInvatare(programInvatare) {}

    void adaugaNota(Materie* materie, float nota) {
        noteMaterii[materie] = nota;
    }

    float calculeazaMedie() const {
        float suma = 0;
        for (auto& [nume, nota] : noteMaterii) {
            suma += nota;
        }
        return noteMaterii.empty() ? 0 : suma / noteMaterii.size();
    }

    void afisareNote() const {
        cout << "Student: " << nume << " (" << programInvatare << ")" << endl;
        for (auto& [nume, nota] : noteMaterii) {
            cout << "  " << nume->getNume() << ": " << nota << endl;
        }
    }

    string getNume() const { return nume; }
    string getProgram() const { return programInvatare; }
};

class Catalog {
protected:
    vector<Student*> studenti;

public:
    virtual ~Catalog() {
        for (auto s : studenti) delete s;
    }

    void adaugaStudent(Student* s) {
        studenti.push_back(s);
    }

    virtual void afisare() const = 0;

    void ranking() const {
        vector<Student*> copie = studenti;
        sort(copie.begin(), copie.end(), [](Student* a, Student* b) {
            return a->calculeazaMedie() > b->calculeazaMedie();
        });
        int i=1;
        cout <<endl<< "Ranking:"<<endl;
        for (auto s : copie) {
            cout <<i++<<". " << s->getNume() << " - " << s->calculeazaMedie() << endl;
        }
    }
};

class CatalogRO : public Catalog {
public:
    void afisare() const override {
        cout << "Catalog RO:\n";
        for (auto s : studenti) {
            if (s->getProgram() == "RO") s->afisareNote();
        }
    }
};

class CatalogEN : public Catalog {
public:
    void afisare() const override {
        cout << "Catalog EN:\n";
        for (auto s : studenti) {
            if (s->getProgram() == "EN") s->afisareNote();
        }
    }
};


// -------------------------------
int main() {
    Materie* m1 = new Matematica();
    Materie* m2 = new Optional1();

    CatalogRO catalog;

    Student* s1 = new Student("Ana", 101, "RO");
    s1->adaugaNota(m1, 9);
    s1->adaugaNota(m2, 7);

    catalog.adaugaStudent(s1);

    Student* s2 = new Student("Ion", 102, "RO");
    s2->adaugaNota(m1, 8);
    s2->adaugaNota(m2, 6);

    catalog.adaugaStudent(s2);

    catalog.afisare();
    catalog.ranking();

    // Eliberare materii
    delete m1;
    delete m2;

    return 0;
}
