#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include<stdio.h>
#define size 100
#define ksize 30

void decplainedit(char plain[]);
void plainedit(char plain[]);
void matrixx(char key[],char cmatrix[5][6]);
void makedistinct(char key[]);
void decrypt(char cipher[],char cmatrix[5][6]);
void playfair(char plain[],char cmatrix[5][6]);

#endif // HEADER_H_INCLUDED
