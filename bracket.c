#include <stdio.h>
#include <string.h>

int main() {
  FILE *pFile;
  char fileInput[50], c;
  char playerName[10][50];
  char dataEntry[50];
  int playerSkill[10], lineCount;

  printf("Enter the name of the text file\n");

  fgets(fileInput, 50, stdin);
  fileInput[strlen(fileInput) - 1] = '\0';
  //printf("You entered: %s\n", fileInput);
  pFile = fopen(fileInput, "r");

  printf("\nFile contents:\n");

  lineCount = 0;
  while (c != EOF) {
    c = fgetc(pFile);
    if (c == '\n')
      lineCount++;
  }

  // Resetting pointer to beginning of file
  rewind(pFile);

  printf("lineCount: %d\n", lineCount);
  // Loop through and check the lines
  for (int i = 0; i < lineCount; i++) {
    //strcpy(dataEntry, "");
    /
    fgets(dataEntry, 50, pFile);
    //printf("%s", dataEntry);
    sscanf(dataEntry, "%[^,], %d", playerName[i], &playerSkill[i]);
  }

  for (int i = 0; i < lineCount; i++) {
    printf("Player Name: %s\n", playerName[i]);
    printf("Player Skill: %d\n\n", playerSkill[i]);
  }

  fclose(pFile);
}
