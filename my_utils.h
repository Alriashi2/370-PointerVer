#ifndef MY_UTIL_H
#define MY_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#endif // MY_UTIL_H


//API
void rand_array(int n, int x[], int min, int max);
void rand_array_float(int n, float x[], float min, float max);
void print_array(int n, int x[], char label[]);
void print_array_float(int n, float x[], char label[]);
int get_sum(int n, int x[]);
float get_ave(int n, int x[]);
int get_count(int n, int x[], int min, int max);
int get_max(int n, int x[]);
int get_values_in_range(int n, int in[], int out[], int min, int max);


//sequence

int delete(int n, int x[], int y[], int k);
int insert(int n, int x[], int y[], int k, int p);


