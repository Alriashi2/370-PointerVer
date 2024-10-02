#ifndef MY_UTIL_C
#define MY_UTIL_C
#include <my_utils.h>

#endif // MY_UTIL_C


void rand_array(int n, int x[], int min, int max)
{
    for (int i=0; i<n; i++)
    {
        x[i] = min + rand() % (max - min + 1);
    }
}
void rand_array_float(int n, float x[], float min, float max)
{
    for (int i=0; i<n; i++)
    {
        float p = (float) rand()/RAND_MAX;
        x[i] = min + (max-min)*p;
        //(float)rand()/(float)RAND_MAX * (max - min + 1);
    }
}
void print_array(int n, int x[], char label[])
{
    printf("\n\n %s", label);
    for(int i = 0; i<n; i++)
    {
        printf(" %d", x[i]);
    }
}
void print_array_float(int n, float x[], char label[])
{
    printf("\n\n %s", label);
    for(int i = 0; i<n; i++)
    {
        printf(" %.2f", x[i]);
    }
}
int get_sum(int n, int x[])
{
    int sum;
    sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum=sum+x[i];
    }
    return (sum);
}
float get_ave(int n, int x[])
{
    int sum = 0;
    float ave;

    for(int i =0; i<n; i++)
    {
        sum = sum+x[i];
    }
    ave = (float) sum/n;
    return ave;
}
int get_count(int n, int x[], int min, int max)
{
    int count = 0;
    for (int i =0; i<n; i++)
    {
        if ((x[i]>=min)&&(x[i]<=max))
            count ++;
    }
    return count;
}
int get_max(int n, int x[])
{
    int max = x[0];
    for (int i = 0; i<n; i++)
    {
        if(x[i]>max) max = x[i];
    }

    return max;
}
int get_values_in_range(int n, int in[], int out[], int min, int max)
{
    int values =0;

    for (int i = 0; i<n; i++)
    {
        if ((in[i]>=min)&&(in[i]<=max))
        {
            out[values] = in[i];
            values++;
        }
    }
    return values;
}
