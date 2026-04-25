#ifndef HUFFMAN_H
#define HUFFMAN_H

typedef struct Node {
    unsigned char character;
    int frequency;
    struct Node *left, *right;
} Node;

#endif
