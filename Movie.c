/*
Date Fall 2023
Author:Orlando Companioni
email:companor@sheridancollege.ca
*/
#include "Movie.h"
#include <stdio.h>
#include <string.h>


int loadMovie( struct Movie* mptr, FILE* fptr ) {//it has a pointer to the struct Movie and a pointer to the file
   return (fscanf( fptr, "%[^\t]\t%d\t%[^\t]\t%d\t%[^\t]\t%f", mptr->title, &mptr->year ,mptr->rating,&mptr->duration,mptr->genre,&mptr->consumerRating) == 6);
   //This return statement is a conditional expression that returns true if the fscanf() function returns 6, and 0 otherwise.
}
