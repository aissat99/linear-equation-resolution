# linear-equation-resolution

## Description
Un programme en ligne de commande qui résoud un système d'équations linéaires, utilisant la méthode d'élimination de Gauss.
Le système contient N équations avec N inconnus.

## Guide d'utilisation
Ce guide explique la compilation et l'éxecution du programme sur un système Linux.

### Compilation des codes sources
En utilisant l'outil de compilation `g++`, la commande suivante permet de compiler les codes sources:
```
g++ -c main.cpp functions.cpp
```
Ensuite, pour créer l'éxecutable, utilisez la commande suivante:
```
g++ -o solver *.o
```
***Note***: Le nom donné au programme ici est *solver*, vous pouvez le modifier selon vos besoins.

### Execution du programme
Une fois l'éxecutable `solver` créé, la commande suivante permet de lancer le programme sur la ligne de commande:
```
./solver
```
***Note***: Pour pouvoir fonctionner, le programme récupère les données du système d'équation dans un fichier texte nommé `data.txt`. Assurez-vous que ce fichier soit présent dans le même dossier que les codes sources.

