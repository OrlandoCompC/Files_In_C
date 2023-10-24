/*
Date Fall 2023
Author:Orlando Companioni
email:companor@sheridancollege.ca
*/
#include <stdio.h>
#include <string.h>
#include "Movie.h"
#include "utils.h"


void printInWidth(const char str[], int width){
   //print the string one by one up to the width
   int counter=0;
   int spaceCount=0,count=0;
   if(width!=5){
      for (int i = 0; i < width; i++){ //it will run for the whole width
         if (counter<strlen(str)){ //it will onlt run if the counter is less than the length of the string
         if (str[counter]=='\n'){
               counter++;
         }
         putchar(str[counter]);
         counter++;
         }
         else{
         putchar(' ');
         }
      }
   }
   if(width==5){//this is to be able to print right aligned
      for (int i = 0; i < width; i++){
        if (spaceCount< width-strlen(str))
        {
            putchar(' ');//it will print
            spaceCount+=1;
        }
        else if(spaceCount>=width-strlen(str))
         {
        putchar(str[count]);
        count++;
        }
   }
   }
}//end of printInWidth

void list(const struct Movie* mptr, int row){
   printf("| %3d | ",row);
   printInWidth(mptr->title, 20);
   printf(" | %4d |",mptr->year);
   printInWidth(mptr->rating, 5);
   printf(" |%2d:%02d | ",mptr->duration/60,mptr->duration%60);
   printInWidth(mptr->genre, 25);
   printf(" | %4.1f |\n",mptr->consumerRating); //it has the f because its a float
}//end of list

void display(const struct Movie* m){
   int len=strlen(m->title);//This will skip the first newline character that the file comes with
   printf("Title: ");
    for(int i =0;i<len;i++){
      if(m->title[i]!='\n'){
         putchar(m->title[i]);
      }
    }
    printf("\nYear: %d\n",m->year);
    printf("Rating: %s\n",m->rating);
    printf("Duration: %d:%d\n",m->duration/60,m->duration%60);
    printf("Genre: %s\n",m->genre);
    printf("Consumer Rating: %0.1f\n",m->consumerRating);
}//end of display

const char* getMovieTitle(const struct Movie* mptr){
   return mptr->title;          //return the title of the movie
}