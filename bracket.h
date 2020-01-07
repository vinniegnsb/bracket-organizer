#ifndef bracket_h
#define bracket_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Player {
  int skill;
  char name[50];
} player;

// FIXME - make this Doubly Linked so List can be traversed in original order easily
typedef struct Node {
  player data;
  struct Node *next;
} node;

node *head = NULL;
node *temp;

//void printList();
node *makeNewNode();
node *insertNode();
void listPlayers();
int lineCounter();
void infoExtractorAndPopulator();

#endif
