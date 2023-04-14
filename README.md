# CPYRR Compiler-Virtual Machine

## Créateurs

- **Noms :** AKIL, AMIROUCHE, BAYAZID
- **Prénoms :** Mourtaza, Azedine, Hany
- **Projet :** compilateur et machine virtuelle pour le langage CPYRR
- **Dernière modification :** 14/04/23

## Programmes

### Liste des programmes

- **cpyrr-cvm**

### Descriptif des programmes

- **cpyrr-cvm :**
  - Le programme compile et exécute un programme écrit en langage CPYRR

## Commandes du Makefile

Pour compiler le programme **cpyrr-cvm**, il faut taper la commande `make` depuis le dossier racine.

- `make clean` : permet de supprimer tous les fichiers objets, tous les fichiers associés aux parties *Lex* et *YACC* et tous les exécutables
- `make clean_output` : permet de supprimer tous les fichiers de sortie générés par défaut : *default\**, *log*
- `make build` : permet de compiler le programme **cpyrr-cvm**
- `make rebuild` : permet de recompiler le programme **cpyrr-cvm**

## Exécution des programmes

Les exécutables, après leur compilation, sont situés dans le dossier *./bin/*

## Programme *cpyrr-cvm*

Depuis le dossier racine, l'appel se fera ainsi :

    ./bin/cpyrr-cvm <option> [ <nom_fichier_cpyrr> [ <nom_fichier_sortie> ] ]

- `<option>` :

  - ` -c ` : compile le programme donné
  - ` -h ` : affiche la notice d'utilisation du programme

- `<nom_fichier_cpyrr>` : code source en langage CPYRR, accessible en lecture.

- `<nom_fichier_sortie>` :

  - nom du fichier de sortie qui contiendra le texte intermédiare
  - [optionnel] : si non indiqué, un fichier par défaut sera généré
