#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>

// Structure d'un nœud de l'arbre
typedef struct Node {
    unsigned char character;
    int frequency;
    struct Node *left, *right;
} Node;

// Prototypes
void analyser_frequences(char* nomFichier, int* tableFrequences);
Node* create_node(unsigned char c, int freq);
analyser_frequences(nomF, freqs);
                Node* racine = construire_arbre(freqs);
                printf("Arbre de Huffman construit avec succes.\n");
#endif
