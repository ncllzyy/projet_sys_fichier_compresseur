#include "fs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour créer un nouveau répertoire
Directory* create_directory(char* name, Directory* parent) {
    Directory* new_dir = (Directory*)malloc(sizeof(Directory));
    if (!new_dir) return NULL;

    strcpy(new_dir->name, name);
    new_dir->sub_dirs = NULL;
    new_dir->files = NULL;
    new_dir->parent = parent;
    new_dir->next = NULL;

    return new_dir;
}

// Fonction pour afficher ce qu'il y a dans le dossier
void list_content(Directory* current) {
    printf("\n--- Contenu de : %s ---\n", current->name);
    
    Directory* d = current->sub_dirs;
    while (d) {
        printf("[DIR]  %s\n", d->name);
        d = d->next;
    }

    File* f = current->files;
    while (f) {
        printf("[FILE] %s (%d octets)\n", f->name, f->size);
        f = f->next;
    }
}
// Fonction pour créer un fichier dans le répertoire actuel
void create_file(Directory* current, char* name, char* content) {
    File* new_file = (File*)malloc(sizeof(File));
    if (!new_file) return;

    strcpy(new_file->name, name);
    new_file->content = strdup(content); // Duplique la chaîne de texte
    new_file->size = strlen(content);
    
    // Ajout en tête de la liste chaînée du répertoire
    new_file->next = current->files;
    current->files = new_file;
    
    printf("Fichier '%s' cree avec succes.\n", name);
}
