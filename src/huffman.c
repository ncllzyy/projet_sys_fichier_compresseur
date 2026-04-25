#include "huffman.h"
#include <stdlib.h>

// Crée un nouveau nœud pour l'arbre
Node* create_node(unsigned char c, int freq) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = c;
    newNode->frequency = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Compte combien de fois chaque caractère apparaît dans le fichier
void analyser_frequences(char* nomFichier, int* tableFrequences) {
    FILE* f = fopen(nomFichier, "r");
    if (!f) {
        printf("Erreur : Impossible d'ouvrir le fichier pour analyse.\n");
        return;
    }

    int c;
    while ((c = fgetc(f)) != EOF) {
        tableFrequences[(unsigned char)c]++;
    }

    fclose(f);
}
