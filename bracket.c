#include <stdio.h>
#include <string.h>

// I really want to implement linked lists so that I can dynamically
// size my player list without having to declare a finite size
typedef struct Player {
  // For now list sizes can only be up to 10
  int skill[10];
  char name[10][50];
} player;

int LineCounter();
player InfoExtractor();
void ListPlayers();

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
    pFile = fopen(fileInput, "r");
    if (pFile == NULL)
      printf("Does not exist, please give a new entry: ");
  }

  printf("\nFile contents:\n");
  lines = LineCounter(pFile);
  plyr = InfoExtractor(lines, plyr, pFile);
  ListPlayers(lines, plyr);

  fclose(pFile);

  return 0;
}

int LineCounter(FILE *file) {
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

player InfoExtractor(int length, player p, FILE *file) {
  char dataEntry[50];
  // Loop through and check the lines
  for (int i = 0; i < length; i++) {
    fgets(dataEntry, 50, file);
    sscanf(dataEntry, "%[^,], %d", p.name[i], &p.skill[i]);
  }
  return p;
}

void ListPlayers(int length, player p) {
  for (int i = 0; i < length; i++) {
    printf("Player Name: %s\n", p.name[i]);
    printf("Player Skill: %d\n\n", p.skill[i]);
  }
}
