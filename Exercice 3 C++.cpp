
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Classe mere : Employe
class Employe {
protected:
    string matricule;
    string nom;
    string prenom;
    double salaireBase;

public:
    // Constructeur
    Employe(string m, string n, string p, double s) {
        matricule = m;
        nom = n;
        prenom = p;
        salaireBase = s;
    }

    // Destructeur virtuel
    virtual ~Employe() {}

    // Methode virtuelle pure
    virtual double calculerSalaire() = 0;

    // Methode pour afficher les informations
    virtual void afficherInformations() {
        cout << "Matricule : " << matricule << endl;
        cout << "Nom : " << nom << endl;
        cout << "Prenom : " << prenom << endl;
        cout << "Salaire de base : " << salaireBase << endl;
    }
};

// Classe Enseignant
class Enseignant : public Employe {
private:
    double indemnite;

public:
    Enseignant(string m, string n, string p,
               double s, double i)
        : Employe(m, n, p, s) {
        indemnite = i;
    }

    double calculerSalaire() override {
        return salaireBase + indemnite;
    }

    void afficherInformations() override {
        cout << "\n--- ENSEIGNANT ---" << endl;
        Employe::afficherInformations();
        cout << "Indemnite : " << indemnite << endl;
        cout << "Salaire total : " << calculerSalaire() << endl;
    }
};

// Classe Agent Administratif
class AgentAdministratif : public Employe {
private:
    double prime;

public:
    AgentAdministratif(string m, string n, string p,
                       double s, double pr)
        : Employe(m, n, p, s) {
        prime = pr;
    }

    double calculerSalaire() override {
        return salaireBase + prime;
    }

    void afficherInformations() override {
        cout << "\n--- AGENT ADMINISTRATIF ---" << endl;
        Employe::afficherInformations();
        cout << "Prime : " << prime << endl;
        cout << "Salaire total : " << calculerSalaire() << endl;
    }
};

// Classe Technicien
class Technicien : public Employe {
private:
    double prime;

public:
    Technicien(string m, string n, string p,
               double s, double pr)
        : Employe(m, n, p, s) {
        prime = pr;
    }

    double calculerSalaire() override {
        return salaireBase + prime;
    }

    void afficherInformations() override {
        cout << "\n--- TECHNICIEN ---" << endl;
        Employe::afficherInformations();
        cout << "Prime : " << prime << endl;
        cout << "Salaire total : " << calculerSalaire() << endl;
    }
};

// Fonction principale
int main() {

    // Creation des employes
    Enseignant e1("ENS001", "Koffi", "Jean", 150000, 50000);

    AgentAdministratif a1("ADM001", "Saliou", "Paul", 120000, 20000);

    Technicien t1("TEC001", "Amina", "Marie", 100000, 30000);

    // Creation d'une collection d'employes
    vector<Employe*> listeEmployes;

    listeEmployes.push_back(&e1);
    listeEmployes.push_back(&a1);
    listeEmployes.push_back(&t1);

    // Affichage des informations
    cout << "GESTION DU PERSONNEL UNIVERSITAIRE" << endl;

    for (int i = 0; i < listeEmployes.size(); i++) {
        listeEmployes[i]->afficherInformations();
    }

    return 0;
}

