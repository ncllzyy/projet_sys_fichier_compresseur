# Projet Système de Fichiers et Compresseur Huffman

Ce projet en langage C simule un système de gestion de fichiers et propose un outil de compression basé sur l'algorithme de Huffman.

## Fonctionnalités

### 📁 Système de Fichiers
- **Navigation** : Déplacement dans l'arborescence via `cd`.
- **Gestion** : Création de répertoires (`mkdir`) et de fichiers (`touch`).
- **Consultation** : Listage du contenu (`ls`) et lecture de fichiers (`cat`).
- **Nettoyage** : Suppression de fichiers (`rm`).

### 📦 Compresseur Huffman
- **Analyse** : Calcul de la fréquence d'apparition des caractères.
- **Arbre** : Construction d'un arbre binaire de Huffman optimal.
- **Encodage** : Génération des codes binaires (0 et 1) pour chaque caractère.

## Compilation et Lancement
1. Compilez le projet avec le Makefile :
   ```bash
   make
