/*
Workshop 3 :
File Movie.h
Version 1.0
Date Fall 2023
Author:Orlando Companioni
student number:991 437 087 
email:companor@sheridancollege.ca
*/
#pragma once
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <stdio.h>

struct Movie {// this is a struct for all the movies in the file
   char title[61];
   int year;
   char rating[3];
   int duration;
   char genre[60];
   float consumerRating;
};
int loadMovie( struct Movie* mptr, FILE* fptr );
#endif // !SDDS_MOVIE_H
