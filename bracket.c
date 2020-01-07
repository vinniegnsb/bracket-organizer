#include "bracket.h"

int main() {
  FILE *pFile = NULL;
  int lines;
  char fileInput[50];
  player plyr;

  printf("Enter the name of the text file: ");
  // File name entry loop
  while (pFile == NULL) {
    fgets(fileInput, 50, stdin);
    fileInput[strlen(fileInput) - 1] = '\0';
    pFile = fopen(fileInput, "rw");
    if (pFile == NULL)
      printf("Does not exist, please give a new entry: ");
  }

  printf("\nFile contents:\n");
  lines = lineCounter(pFile);
  infoExtractorAndPopulator(lines, pFile);

  listPlayers(lines, head);

  fclose(pFile);

  return 0;
}

// Did not change after LL integration
int lineCounter(FILE *file) {
  char c;
  int lineCount = 0;
  while (c != EOF) {
    c = fgetc(file);
    if (c == '\n')
      lineCount++;
  }
  // Resetting pointer to beginning of file
  rewind(file);
  return lineCount;
}

// Takes formatted input from file and populates LL
void infoExtractorAndPopulator(int length, FILE *file) {
  char dataEntry[50];
  int skillEntry;
  char nameEntry[50];
  // Loop through and check the lines
  for (int i = 0; i < length; i++) {
    fgets(dataEntry, 50, file);
    sscanf(dataEntry, "%[^,], %d", nameEntry, &skillEntry);

    temp = makeNewNode(skillEntry, nameEntry); // Takes formatted data from above and creates a new node
    insertNode(&head, temp); // Links up node to head
  }
}

// List data from LL
void listPlayers(int length, node *start) {
  node *temp = start;
  /* for (int i = 0; i < length; i++) { */ while (temp != NULL) {
    printf("Player Name: %s\n", temp->data.name);
    printf("Player Skill: %d\n\n", temp->data.skill);
    temp = temp->next;
  }
}

node *makeNewNode(int skill, char name[50]) {
  node *newNode = malloc(sizeof(node));
  newNode->data.skill = skill;
  strcpy(newNode->data.name, name);// newNode->data.name = name;
  newNode->next = NULL;
  return newNode;
}

node *insertNode(node **head, node *newNode) {
  newNode->next = *head;
  *head = newNode;
  return newNode;
}
