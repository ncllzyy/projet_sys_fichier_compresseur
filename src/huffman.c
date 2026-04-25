#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>

// Étape 1 : Analyser le fichier pour compter les fréquences
void analyser_frequences(char* nomFichier, int* tableFrequences) {
    FILE* f = fopen(nomFichier, "r");
    if (!f) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    int c;
    while ((c = fgetc(f)) != EOF) {
        tableFrequences[(unsigned char)c]++;
    }

    fclose(f);
}

// Les prochaines étapes seront :
// - Construire l'arbre de Huffman
// - Générer les codes binaires
// - Compresser le fichier
