#include <stdio.h>
#include <stdlib.h>
#include "fs.h"
#include "huffman.h"

int main() {
    // Initialisation du système de fichiers avec un répertoire racine "/"
    Directory* root = create_directory("root", NULL);
    Directory* currentDir = root;
    int choix;

    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Lister le contenu (ls)\n");
        printf("2. Creer un répertoire (mkdir)\n");
        printf("3. Compresser un fichier (Huffman)\n");
        printf("4. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                list_content(currentDir);
                break;
            case 2: {
                char name[100];
                printf("Nom du nouveau répertoire : ");
                scanf("%s", name);
                Directory* new_sub = create_directory(name, currentDir);
                // On l'ajoute à la liste des sous-répertoires
                new_sub->next = currentDir->sub_dirs;
                currentDir->sub_dirs = new_sub;
                printf("Répertoire '%s' créé.\n", name);
                break;
            }
            case 3:
                printf("Fonction Huffman bientôt disponible...\n");
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide.\n");
        }
    } while (choix != 4);

    return 0;
}
