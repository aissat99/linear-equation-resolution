/*Ce programme résoud un système linéaire de N équations à N inconnus en utilisant la méthode d'élimination de Gauss.

Les données des équations sont récupérées depuis un fichier 'data.txt'.
Le programme transforme ensuite le système en un système triangulaire équivalent, avant de le résoudre par transposition.

Par: RAFIDY Julie Tassia*
(*)Pour toute utilisation des codes sources inclus dans ce répértoire, veuillez mentionner le nom de l'autrice indiqué ci-dessus.
*/

#include "./headers.hpp"

int main()
{
    std::vector<std::vector<int>> A;
    std::vector<int> b;
    std::vector<float> solution;
    std::string filename = "./data.txt";

    // Récupération des données
    recupererDonneesDuSysteme(A, b, filename);

    // Affichage du problème
    printf("The system of equations to solve:\n");
    afficherSysteme(A, b);

    // Resolution du systeme
    eliminationDeGauss(A, b);
    printf("\nAn equivalent system to the previous system in a triangular form:\n");
    afficherSysteme(A, b);
    solution = resoudreSystemeTriangSup(A, b);

    // Affichage de la solution finale
    printf("\nThe final solution of the system:\n");
    afficherSolution(solution);

    return 0;
}