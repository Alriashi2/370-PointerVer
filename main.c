#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#include "util_matrices.h"
#include "util_sequences.h"
#include "my_utils.h"

//API
int *alloc_rand_array(int n, int min, int max);


//Funcations
void inc(int a)//line A
{
    a = a+1;   //Line B
}              //Line C


void inc2(int *a) //Line AA
{
    *a = *a + 1;  // Line BB
}                 //Line CC

int *alloc_rand_array(int n, int min, int max)
{
    int *x;
    x = (int*) malloc(n*sizeof (int));
    for(int i = 0; i<n; i++)
    {
        x[i] = min + rand()%(max-min+1);
    }

    return x;
}
int main()
{

    srand(time(NULL));
    /*---------------10-07-2024--------------------------------------
    int x[10];
    int n;

    //Address              Contents              Variable
    //A000 0000              -2342(g)                n


    int *ptr;

    //Address                Contents              Variable
    //A000 0000              -2342   (g)                n
    //B000 0000            FF00 8674 (g)               ptr  iTunes Problems

    //*ptr =9854;  Error crashes



    n = 50;
    ptr =&n;   //initalizing ptr to n

    //Address                Contents              Variable
    //A000 0000                 50                  n, *ptr
    //B000 0000              A000 0000                ptr

    //ptr =A000 0000 error because you can't hard-code adresses



    ptr = (int *) malloc(sizeof(int));

    //Address                Contents              Variable
    //A000 0000                 50                     n
    //B000 0000              C000 0000                ptr
    //C000 0000              84954 (g)                *ptr

    -----------------------------------------------------*/


    int n;
    int *ptr;     //iTunes problem

    //1. Set to existing address
    ptr = &n;

    //Address            Contents                 Variable
    //A000 0000           -784(g)                  n, *ptr
    //B000 0000         A000 0000                   ptr


    //2. Use Malloc
    ptr = (int*) malloc(sizeof(int));   //Saves 4 bits in ptr


    //Address            Contents                 Variable
    //A000 0000           -784(g)                    n
    //B000 0000         C000 0000                   ptr
    //C000 0000           5432 (g)                  *ptr
    //C000 0004          NExt Avaiable


    //Saving space for three integers
    int *nptr;
    nptr = (int *) malloc(3*sizeof(int));

    //Address             Contents                 Variable
    //A000 0000           -784(g)                   n
    //B000 0000         C000 0000                   ptr
    //B000 0004         C000 0004                   nptr
    //C000 0000           5432 (g)                 *ptr
    //C000 0004            735 (g)                 *(nptr + 0)  nptr[0]
    //C000 0008            390 (g)                 *(nptr + 1)  nptr[1]
    //C000 000C            930(g)                  *(nptr + 2)  nptr[2]


    //Pointer arithmetic: nptr+1 advances in memory
    //to the next
    //nptr + 1: C000 0004 + 1 = C000 0008

    //Pass by refrence = pass array
    //int sumArray(int n, int x[]);
    //int sumArray(int n, int *x);

    int x[4] = (10, 20, 30 ,40);
    //Address             Contents                 Variable
    //A000 0000           -784(g)                   n
    //B000 0000         C000 0000                   ptr
    //B000 0004         C000 0004                   nptr
    //C000 0000           5432 (g)                 *ptr
    //C000 0004            735 (g)                 *(nptr + 0)  nptr[0]
    //C000 0008            390 (g)                 *(nptr + 1)  nptr[1]
    //C000 000C            930(g)                  *(nptr + 2)  nptr[2]
    //D000 0000             10                      x[0]
    //D000 0004             20                      x[1]
    //D000 0008             30                      x[2]
    //D000 000C             40                      x[3]

    //&x[0] = D000 0000
    //*x = D000 0000

    //x[3] = *(x+3)

    /*chat *cptr;
     * int *nptr;
     * float *fptr;
     * double *dptr;
     *
     * Questoins:
     * sizeof(cptr) = 4 bytes
     * sizeof(nptr) = 4 bytes
     * sizeof(fptr) = 4 bytes
     * sizeof(dptr) = 4 bytes
     *
     * Questions:
     * sizeof(*cptr) = 1 bytes
     * sizeof(*nptr) = 4 bytes
     * sizeof(*fptr) = 4 bytes
     * sizeof(*dptr) = 8 bytes
     */


    //P is not initalized probably.
    int *p = NULL;            //not pointing to iTune
    //Address             Contents                 Variable
    //A000 0000           -784(g)                   n
    //B000 0000         C000 0000                   ptr
    //B000 0004         C000 0004                   nptr
    //B000 0008         0000 0000                   p    //not pointing to iTune
    //C000 0000           5432 (g)                 *ptr
    //C000 0004            735 (g)                 *(nptr + 0)  nptr[0]
    //C000 0008            390 (g)                 *(nptr + 1)  nptr[1]
    //C000 000C            930(g)                  *(nptr + 2)  nptr[2]
    //D000 0000             10                      x[0]
    //D000 0004             20                      x[1]
    //D000 0008             30                      x[2]
    //D000 000C             40                      x[3]


    //inc with pass by value
    int q = 50;
    inc(q);
    //Address           Contents          Variable
    /*After line A*/
    //A000 0000            50               q
    //E000 0000            50               a

    /*After line B*/
    //A000 0000            50               q
    //E000 0000            51               a

    /*After line C*/
    //A000 0000            50               q


    inc2(&q);
    //Address           Contents          Variable
    /*After line AA*/
    //A000 0000            50               q, *a
    //E000 0000         A000 0000           a

    /*After line BB*/
    //A000 0000            51               q, *a
    //E000 0000         A000 0000           a
    //it to the valuable at location a (*a) and adds a 1

    /*After line CC*/
    //A000 0000            51               q




    int *r;

    /*inc2(r);*/
    //Address           Contents        Variable
    //B000 000C        FF92  3894          r    //pointer veriable


    r = (int *) malloc(sizeof(int));
    inc2(r); //working since we alreay have space saved for a variable for r.
    //Address           Contents        Variable
    //B000 0000        C000 0000          r    //pointer veriable
    //C000 0010        932 (g)           *r    //this value will be incriminted by 1.


    int grades[20];
    rand_array(20,grades,70,100);
    print_array(20, grades, "grades");

    //do memory table
    int *scores;

    scores = alloc_rand_array(20, 70, 100);



    return 0;
}
