#ifndef UTIL_SEQUNCES_C
#define UTIL_SEQUNCES_C

#endif // UTIL_SEQUNCES_C
#include <util_sequences.h>
#include <my_utils.h>

int interpolate(int n, float x[], float y[])
{
    int ny;
    ny = (2*n)-1;

    for(int i =0; i<ny; i++)
    {
        if(i%2 == 0) y[i] = x[i/2];
        if(i%2 == 1) y[i] = (x[(i-1)/2]+x[(i+1)/2])/2;
    }
    return ny;
}
float linspace(float x[], int n, float min, float max)
{
    float step;
    step = (float)(max - min)/(n-1);

    for(int i =0; i<n; i++)
    {
        x[i] = min + i*step;
    }

    return step;
}

int delete(int n, int x[], int y[], int k)
{
    int ny = n+1;
    for (int i = 0; i<ny; i++)
    {
        if( (i > 0)&&(i<k))
        {
            x[i] = y[i];
            // ny++;
        }
        if( (i>k))
        {
            x[i-1] = y[i];
            //ny++ ;
        }
    }


    return ny;
}
int insert(int n, int x[], int y[], int k, int p)
{
    int ny = n+1;
    for (int i = 0; i<ny; i++)
    {
        if( (i<k))
        {
            x[i] = y[i];
            //ny++;
        }
        if (i=k) y[i] = p;
        if(i>k)
        {
            x[i-1] = y[i+1];
            //ny++;
        }
    }
    return ny;
}



int uniform_sample(float x[], float min, float max, float step)
{
    int n;
    n = (max-min)/step + 1;
    for(int i = 0; i<n; i++)
    {
        x[i] = min + i*step;
    }
    return n;
}
