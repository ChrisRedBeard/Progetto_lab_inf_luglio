
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

// Sequenze di escape ANSI per i colori
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

typedef unsigned short int int_pos;

void input_string(const char *prompt, char *dest, int_pos size, int_pos lunghezza);
void input_float(const char *prompt, float *dest, float min);
void input_id(const char *prompt, char *dest, int_pos size, int_pos lunghezza);

#endif