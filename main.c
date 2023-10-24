/*
Date Fall 2023
Author:Orlando Companioni
Description The program reads a file and it orginizes it in a struct array and then it searches for a movie based on the title
email:companor@sheridancollege.ca
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Movie.h"
#include "utils.h"


void searchMovies(struct Movie* m, int size);

int main(void) {
   struct Movie m[100];
   int num = 0;
   char yes;
   FILE* file = fopen("movies.dat", "r");             //the file is opened for reading here
   while(num < 100 && loadMovie(&m[num], file)) {
      list(&m[num], num+1);
      num++;
   }
   fclose(file);                                       //the file is closed here
   do {
      searchMovies(m, num);
      printf("Another Search? (y)es/(n)o: ");
      yes = getchar();
      while(getchar() != '\n');
   } while(yes == 'y' || yes == 'Y');

   return 0;
} //end of main

void searchMovies(struct Movie* m, int size) {
   char title[51];
   int i;
   int found;
   printf("Searching for a movie based on title...\n");
   printf("Title: ");
   scanf("%[^\n]", title);
   for(found = 0,i = 0; i < size; i++) {
      if(strstr(getMovieTitle(&m[i]), title)) {
         printf("%d ============================\n", ++found);
         display(&m[i]);
      }
   }
   while(getchar() != '\n');
}//end of searchMovies
