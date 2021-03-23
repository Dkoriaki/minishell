#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tri_iteratif(char *tableau[], int taille)
 {
   char *temp; 
   int i, j;

   for (i = 0; i < taille; i++) 
    for (j = 0; j < taille; j++)
      if (strcmp(tableau[i], tableau[j]) < 0)
        {
          temp = tableau[i];
          tableau[i] = tableau[j];
          tableau[j] = temp;
        }
  }

int main(void)
 {
   char *valeurs[] = {"AAA", "CCC", "BBB", "EEE", "DDD"};
   int i;

   tri_iteratif(valeurs, 5);
   for (i = 0; i < 5; i++)
     printf("%s ", valeurs[i]);
	return (0);
 }
