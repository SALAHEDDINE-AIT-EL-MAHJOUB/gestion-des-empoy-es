#include "employe.h"
#include <iostream>
#include <vector>
#include <string>


Employe::Employe(string matricule, string name, string prenom, string email,
    string motdepass, string dateEmbauche, string typeContrat, vector<int> conges, vector<string> listformation) :
    matricule(matricule), name(name), prenom(prenom), email(email),
    motdepass(motdepass), dateembauche(dateEmbauche), typeContrat(typeContrat), conges(conges), listformation(listformation){}
bool Employe::authentifier(const std::string& inputMatricule, const std::string& inputMotdepass) const {
    return (inputMatricule == matricule && inputMotdepass == motdepass);
}



void Employe::connect(string userMatricule, string userPassword) const {


    if (authentifier(userMatricule, userPassword)) {
        cout << "Authentication successful!" << endl;
    }
    else {
        cout << "Authentication failed. Invalid matricule or password." << endl;
    }
}
void menu_conge() {
   
    cout << "1)consultez les conges";
    cout << "\n2)demmandez un conge\n";
    
}
void Employe::Conges() {
    int choix,b;
    menu_conge();
    cout << "Donnez votre choix : ";
    cin >> choix;
    
    if (choix == 1) {
        // Afficher les congés déjà pris
        if (this->listconges.empty()) {
            cout << "Aucun conge pris pour le moment." << endl;
        }
        else {
            cout << "Liste des conges :" << endl;
            for (int j = 0; j < this->listconges.size(); j++) {
                cout << "Conge " << j + 1 << ":" << endl;
                cout << "  Duree: " << this->listconges[j] << " jours" << endl;
                cout << "  Date debut: " << this->datedebut[j] << endl;
                // Ajoutez l'affichage de la date de fin si nécessaire
            }
        }
    }
    else if (choix == 2) {
        // Ajouter un nouveau congé
        int duree;
        string debut;
        cout << "Donnez la duree du conge(en jours) : ";
        cin >> duree;

        // Vérifier si le total des jours de congé pris est inférieur ou égal à 45
        int totalConges = 0;
        for (int j = 0; j < this->listconges.size(); j++) {
            totalConges += this->listconges[j];
        }

        if (totalConges + duree > 45) {
            cout << "Impossible d'ajouter ce conge. Le total des jours de conge ne doit pas depasser 45 jours." << endl;
            return;
        }

        // Vérifier s'il existe déjà un congé de 15 jours
        bool aCongeLongueDuree = false;
        for (int j = 0; j < this->listconges.size(); j++) {
            if (this->listconges[j] == 15) {
                aCongeLongueDuree = true;
                break;
            }
        }

        if (duree == 15 && aCongeLongueDuree) {
            cout << "Impossible d'ajouter un autre congé de 15 jours. Vous avez déjà pris un conge de longue duree." << endl;
            return;
        }

        if (duree > 4) {
            cout << "Impossible d'ajouter un conge de plus de 4 jours. La duree maximale autorisee est de 4 jours." << endl;
            return;
        }

        cout << "Donnez la date de debut du conge (JJ/MM/AAAA) : ";
        cin >> debut;

        // Ajouter le congé
        this->ajouterConge(duree, debut);
        cout << "Conge ajoute avec succes !" << endl;
    }
    else {
        cout << "Choix invalide." << endl;
    }
   
    cout << "terminner";
    cin >> b;
}

void Employe::consulterProfil() {
    int b;
    system("cls");
    std::cout << "\n\n\t\t Profil de l'employe :" << std::endl;
    std::cout << "\n\t\t\tMatricule: " << matricule << std::endl;
    std::cout << "\t\t\tNom: " << name << std::endl;
    std::cout << "\t\t\tPrenom: " << prenom << std::endl;
    std::cout << "\t\t\tEmail: " << email << std::endl;
    std::cout << "\t\t\tDate d'embauche: " << dateembauche << std::endl;
    std::cout << "\t\t\tType de contrat: " << typeContrat << std::endl;
    cout << "\t\tterminner";
    cin >> b;
}
void Employe::modifierProfil() {
    system("cls");
    int b;
    // Afficher les informations actuelles de l'employe
   cout << "Profil actuel :" << endl;
    cout << "Nom : " << name << endl;
    cout << "Prenom : " << prenom << endl;
   cout << "Email : " << email << endl;
    cout << "Mot de passe : " << motdepass << endl;

    // Demander à l'utilisateur de saisir les nouvelles informations
    std::cout << "Entrez les nouvelles informations de votre profil :" << std::endl;

    std::string nouveauNom, nouveauPrenom, nouvelEmail, nouveauMotDePasse;

    std::cout << "Nouveau nom : ";
    std::cin >> nouveauNom;

    std::cout << "Nouveau prenom : ";
    std::cin >> nouveauPrenom;

    std::cout << "Nouvel email : ";
    std::cin >> nouvelEmail;

    std::cout << "Nouveau mot de passe : ";
    std::cin >> nouveauMotDePasse;
    
    // Mettre à jour les informations du profil avec les nouvelles valeurs
    name = nouveauNom;
    prenom = nouveauPrenom;
    email = nouvelEmail;
    motdepass = nouveauMotDePasse;

    std::cout << "Profil mis a jour avec succes !" << std::endl;
    cout << "terminner";
    cin >> b;
}

void Employe::sInscrireFormation() {
    std::string nouvelleFormation;
    std::cout << "Entrez le nom de la nouvelle formation : ";
    std::cin >> nouvelleFormation;

    // Ajouter la nouvelle formation au vecteur de formations de l'employé
    this->listformation.push_back(nouvelleFormation);

    std::cout << "Formation ajoutée avec succès !" << std::endl;
}



void Employe::consulterFormations() {
    int choix,b;
   
    // Afficher un menu pour permettre à l'employé de choisir une action
    cout << "Menu Formations :" << endl;
    cout << "1. Consulter les formations" << endl;
    cout << "2. Ajouter une formation" << endl;
    cout << "Choix : ";
    cin >> choix;

    if (choix == 1) {
        // Afficher les formations disponibles
        cout << "Liste des formations :" << endl;
        for (int i = 0; i < this->listformation.size(); i++) {
            cout << this->listformation[i] << endl;
        }
    }
    else if (choix == 2) {
        // Demander à l'employé d'ajouter une formation
        string nouvelleFormation;
        cout << "Entrez le nom de la nouvelle formation : ";
        cin >> nouvelleFormation;

        // Ajouter la nouvelle formation au vecteur de formations
        this->listformation.push_back(nouvelleFormation);
        cout << "Formation ajoutée avec succès !" << endl;
    }
    else {
        cout << "Choix invalide." << endl;
    }
   
    cout << "terminner";
    cin >> b;
}

