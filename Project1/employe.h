#include <iostream>
#include <vector>
#include <string>


using namespace std;


class Employe {
    string matricule;
    string name;
    string prenom;
    string email;
    string motdepass;
    string dateembauche;
    string typeContrat;
    vector<int> conges;
    vector<string> listformation;
    vector<int> listconges;
    vector<string> datedebut;

public:
    Employe(string matricule, string name, string prenom, string email,
        string motdepass, string dateEmbauche ,string typeContrat, vector<int> conges, vector<string> listformation);
    void connect(string userMatricule, string userPassword) const;
    bool authentifier(const std::string& inputMatricule, const std::string& inputMotdepass) const;
    void Conges();
    void consulterFormations();
    void ajouterConge(int duree, const string& debut) {
        listconges.push_back(duree);
        datedebut.push_back(debut);
    }

    void consulterProfil();
    void modifierProfil();
   
    void sInscrireFormation();
    void menu();
};

