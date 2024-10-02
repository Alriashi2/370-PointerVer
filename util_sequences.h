#ifndef UTIL_SEQUNCES_H
#define UTIL_SEQUNCES_H

#endif // UTIL_SEQUNCES_H

int interpolate(int n, float x[], float y[]);

float linspace(float x[], int n, float min, float max);

int delete(int n, int x[], int y[], int k);

int insert(int n, int x[], int y[], int k, int p);

int uniform_sample(float x[], float min, float max, float step);

void cos_samples (int n, float x[], float y[], float amp, float freq, float phase);

void cos_samples (int n, float x[], float y[], float amp, float freq, float phase);

void damped_cos_samples (int n, float x[], float y[], float alpha, float w);


