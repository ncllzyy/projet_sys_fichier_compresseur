#ifndef FS_H
#define FS_H

#include <stdlib.h>
#include <string.h>

// Structure pour un fichier
typedef struct File {
    char name[100];
    int size;
    char* content;
    struct File* next; // Pour lister plusieurs fichiers dans un dossier
} File;

// Structure pour un répertoire
typedef struct Directory {
    char name[100];
    struct Directory* sub_dirs; // Liste des sous-dossiers
    struct File* files;         // Liste des fichiers
    struct Directory* parent;   // Pour pouvoir faire "cd .."
    struct Directory* next;     // Pour lister les dossiers frères
} Directory;

// Prototypes des fonctions que nous allons créer
Directory* create_directory(char* name, Directory* parent);
void list_content(Directory* current);

Directory* change_directory(Directory* current, char* name);
void create_file(Directory* current, char* name, char* content);
void read_file(Directory* current, char* name);
void delete_file(Directory* current, char* name);

#endif
