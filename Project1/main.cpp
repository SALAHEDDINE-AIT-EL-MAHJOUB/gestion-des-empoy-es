#include <iostream>
#include <vector>
#include <string>
#include "employe.h"

void menu() {
    
    std::cout << " 1) les Conges" << std::endl;
    std::cout << " 2) consulter les Formations" << std::endl;
    std::cout << " 3) consulter mon Profil" << std::endl;
    std::cout << " 4) modifier mon Profil" << std::endl;
  
    std::cout << " 5) s'InscrireFormation" << std::endl;
    std::cout << " 0) Quiter" << std::endl;
}
int main() {
    std::vector<Employe> employees;

    // Ajout des employés
    vector<int> congee1={1,2};
    std::vector<string> listformation = { "c++" };
    vector<int> conge2 ;
    employees.push_back(Employe("12345", "mhj", "salah", "salah", "123", "2024-01-01","cdi", congee1, listformation));/*Le contrat à durée indéterminée(CDI)*/
    employees.push_back(Employe("54321", "eaz", "ismail", "ismail", "123", "2023-12-01","cdi" ,conge2, listformation));

    std::string inputMatricule;
    std::cout << "Enter your matricule: ";
    std::cin >> inputMatricule;

    std::string inputPassword;
    std::cout << "Enter your password: ";
    std::cin >> inputPassword;
    int choix;
    bool found = false;
    for ( Employe& emp : employees) {
        if (emp.authentifier(inputMatricule, inputPassword)) {
            found = true;
            emp.connect(inputMatricule, inputPassword);
            
            
            do {
                menu();
            do {
                std::cout << "donnez votre choix: ";
                std::cin >> choix;
            } while (choix < 0 || choix > 5);
            
                switch (choix)
                {
                case 1:emp.Conges(); break;
                case 3:emp.consulterProfil(); break;
                case 2:emp.consulterFormations(); break;
                case 4:emp.modifierProfil(); break;
                case 5:emp.sInscrireFormation(); break;
                
                

                }system("cls");
            }while (choix != 0);
            

        }
    }

    if (!found) {
        std::cout << "Employee not found." << std::endl;
    }






    return 0;
}



