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
// Fonction pour construire l'arbre de Huffman
Node* construire_arbre(int* tableFrequences) {
    Node* nodes[256];
    int count = 0;

    // 1. Créer un nœud pour chaque caractère existant
    for (int i = 0; i < 256; i++) {
        if (tableFrequences[i] > 0) {
            nodes[count++] = create_node((unsigned char)i, tableFrequences[i]);
        }
    }

    // 2. Assembler l'arbre
    while (count > 1) {
        // Trier pour avoir les deux plus petits au début (méthode simple)
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (nodes[i]->frequency > nodes[j]->frequency) {
                    Node* temp = nodes[i];
                    nodes[i] = nodes[j];
                    nodes[j] = temp;
                }
            }
        }

        // Créer un parent pour les deux plus petits
        Node* left = nodes[0];
        Node* right = nodes[1];
        Node* parent = create_node('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        // Remplacer les deux nœuds par le parent
        nodes[0] = parent;
        for (int i = 1; i < count - 1; i++) {
            nodes[i] = nodes[i + 1];
        }
        count--;
    }
    return nodes[0]; // La racine de l'arbre
}
// Fonction récursive pour générer les codes (0 et 1)
void generer_codes(Node* racine, char* codeActuel, int niveau) {
    if (!racine) return;

    // Si c'est une feuille (un caractère)
    if (!racine->left && !racine->right) {
        codeActuel[niveau] = '\0';
        printf("Code pour '%c' : %s\n", racine->character, codeActuel);
        return;
    }

    // On ajoute '0' pour la gauche
    if (racine->left) {
        codeActuel[niveau] = '0';
        generer_codes(racine->left, codeActuel, niveau + 1);
    }

    // On ajoute '1' pour la droite
    if (racine->right) {
        codeActuel[niveau] = '1';
        generer_codes(racine->right, codeActuel, niveau + 1);
    }
}
