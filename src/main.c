#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fs.h"
#include "huffman.h"

int main() {
    // Initialisation : on crée la racine du système
    Directory* root = create_directory("root", NULL);
    Directory* currentDir = root;
    int choix;

    do {
        printf("\n========================================\n");
        printf("  DOSSIER ACTUEL : %s\n", currentDir->name);
        printf("========================================\n");
        printf("1. Lister le contenu (ls)\n");
        printf("2. Creer un repertoire (mkdir)\n");
        printf("3. Creer un fichier (touch)\n");
        printf("4. Naviguer (cd)\n");
        printf("5. Lire un fichier (cat)\n");
        printf("6. Supprimer un fichier (rm)\n");
        printf("7. PASSER A LA COMPRESSION (Huffman)\n");
        printf("8. Quitter\n");
        printf("Choix : ");
        
        if (scanf("%d", &choix) != 1) break;

        switch(choix) {
            case 1:
                list_content(currentDir);
                break;
            case 2: {
                char name[100];
                printf("Nom du nouveau répertoire : ");
                scanf("%s", name);
                Directory* new_sub = create_directory(name, currentDir);
                new_sub->next = currentDir->sub_dirs;
                currentDir->sub_dirs = new_sub;
                printf("Répertoire créé.\n");
                break;
            }
            case 3: {
                char name[100], content[255];
                printf("Nom du fichier : ");
                scanf("%s", name);
                printf("Contenu : ");
                scanf(" %[^\n]s", content);
                create_file(currentDir, name, content);
                break;
            }
            case 4: {
                char name[100];
                printf("Nom du dossier (ou ..) : ");
                scanf("%s", name);
                currentDir = change_directory(currentDir, name);
                break;
            }
            case 5: {
                char name[100];
                printf("Nom du fichier à lire : ");
                scanf("%s", name);
                read_file(currentDir, name);
                break;
            }
            case 6: {
                char name[100];
                printf("Nom du fichier à supprimer : ");
                scanf("%s", name);
                delete_file(currentDir, name);
                break;
            }
            case 7: {
                int freqs[256] = {0}; // Tableau pour l'ASCII
                char nomF[100];
                printf("Nom du fichier à analyser pour la compression : ");
                scanf("%s", nomF);
                
                analyser_frequences(nomF, freqs);
                Node* racine = construire_arbre(freqs);
                printf("Arbre de Huffman construit avec succes.\n");
                printf("Frequences analysees (aperçu) :\n");
                for(int i = 0; i < 256; i++) {
                    if(freqs[i] > 0) {
                        printf("'%c' : %d fois\n", i, freqs[i]);
                    }
                }
                break;
            }
            case 8:
                printf("Fermeture du programme.\n");
                break;
            default:
                printf("Option invalide.\n");
        }
    } while (choix != 8);

    return 0;
}
