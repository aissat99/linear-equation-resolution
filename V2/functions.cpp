#include "./headers.hpp"

// Triangularisation d'un système d'équations linéaires par la méthode de Gauss
void eliminationDeGauss(std::vector<std::vector<int>>& A, std::vector<int>& b)
{
    int dim = (int)A.size();    // la matrice est carré puisqu'on a affaire à un système de N équations à N inconnus

    for(int i = 0; i < dim; i++)
    {
        // choix du pivot
        int pivot = A[i][i];
        if(pivot == 0)  // si la valeur du pivot est 0, on recherche une autre ligne avec une valeur non nulle parmi les lignes en dessous du pivot, puis on permute la ligne en cours par celle-ci
        {
            int lignePivot = trouverPivotNonNul(A, i);
            permuter(A, b, i, lignePivot);
            pivot = A[i][i];
        }

        // Elimination des coefficients en dessous du pivot
        for(int k = i+1; k < dim; k++)
        {
            int anchor = A[k][i];   // stocker la première valeur de la ligne

            // Elimination des coefficients en dessous du pivot par une combinaison linéaire avec la ligne du pivot
            for(int j = i; j < dim; j++)
            {
                A[k][j] = pivot*A[k][j] - anchor*A[i][j];
            }
            b[k] = pivot*b[k] - anchor*b[i];
        }
    }
}

// Recherche de la solution par transposition. le vecteur b va contenir la solution finale
std::vector<float> resoudreSystemeTriangSup(const std::vector<std::vector<int>>& A, std::vector<int>& b)
{
    std::vector<float> x;
    int dim = (int)A.size();

    // remplir les valeurs de la solution x par les valeurs de b
    for(int i = 0; i < dim; i++)
    {
        x.push_back((float)b[i]);
    }

    // la ligne à seule coefficient non nul commence par la dernière ligne, vu qu'on a une matrice triangulaire supérieure
    for(int i = dim-1; i >= 0; i--)
    {
        for(int j = dim-1; j > i; j--)  // on s'arrête à la colonne à côté de la diagonale (déjà calculée dans les boucles précédentes)
        {
            x[i] = x[i] - A[i][j]*x[j];
        }
        x[i] = x[i] / (float)A[i][i];
    }
    return x;
}

// Permutation de deux équations du système
void permuter(std::vector<std::vector<int>>& A, std::vector<int>& b, int i, int j)
{
    int nbColonnes = (int)A[i].size();

    // Pour A
    for(int k = 0; k < nbColonnes; k++)
    {
        int a_i = A[i][k];
        A[i][k] = A[j][k];
        A[j][k] = a_i;
    }

    // Pour b
    int b_i = b[i];
    b[i] = b[j];
    b[j] = b_i;
}

// Fonction qui permet de trouver un pivot non nul pour la ligne i
int trouverPivotNonNul(const std::vector<std::vector<int>>& A, int i)
{
    int index = 0;
    int nbLignes = (int)A.size();
    for(int j = i+1; j < nbLignes; j++)
    {
        if(A[j][i] != 0)
        {
            index = j;
            break;
        }
    }
    return index;
}

// Récupération des données du système depuis un fichier
// Chaque ligne du fichier correspond à une équation du système, avec la dernière valeur comme valeur du second membre
void recupererDonneesDuSysteme(std::vector<std::vector<int>>& A, std::vector<int>& b, std::string filename)
{
    std::ifstream file(filename);
    std::string line;

    // Récupération de la première ligne qui de sera pas traitée
    std::getline(file, line);
    
    // Récupération des données depuis me fichier
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<int> numbers;
        int num;

        // Récupération des données dans le flux via ss
        while (ss >> num) {
            numbers.push_back(num);
        }

        // Remplisage de la matrice A et du vecteur b
        if (!numbers.empty()) {
            b.push_back(numbers.back());
            numbers.pop_back();
            A.push_back(numbers);
        }
    }
}

// Affichage d'un système d'équations
void afficherSysteme(const std::vector<std::vector<int>>& A, const std::vector<int>& b)
{
    int dim = (int)A.size();
    for(int i = 0; i < dim; i++)
    {
        // Pour la matrice A
        for(int j = 0; j < dim; j++)
        {
            if(j == dim-1)
            {
                printf("%2d x_%d = ", A[i][j], j+1);
            }
            else
            {
                printf("%2d x_%d + ", A[i][j], j+1);
            }
        }

        // POur le second membre b
        printf("%2d\n", b[i]);
    }
    printf("\n");
}

// Affichage de la solution finale de la forme: x_1 = s_1; x_2 = s_2; ...
void afficherSolution(const std::vector<float>& x)
{
    int dim = (int)x.size();

    for(int i = 0; i < dim; i++)
    {
        if(i == dim-1)
        {
            printf("x_%d = %.2f\n", i+1, x[i]);
        }
        else
        {
            printf("x_%d = %.2f; ", i+1, x[i]);
        }
    }
}