#ifndef HEADERS
#define HEADERS

#include <vector>
#include <cstdio>
#include <fstream>
#include <sstream>

// Fonctions de résolution
void eliminationDeGauss(std::vector<std::vector<int>>& A, std::vector<int>& b);
std::vector<float> resoudreSystemeTriangSup(const std::vector<std::vector<int>>& A, std::vector<int>& b);

// Opérations intermédiaires
void permuter(std::vector<std::vector<int>>& A, std::vector<int>& b, int i, int j);
int trouverPivotNonNul(const std::vector<std::vector<int>>& A, int i);

// Récupération de données
void recupererDonneesDuSysteme(std::vector<std::vector<int>>& A, std::vector<int>& b, std::string filename);

// Affichage
void afficherSysteme(const std::vector<std::vector<int>>& A, const std::vector<int>& b);
void afficherSolution(const std::vector<float>& x);

#endif