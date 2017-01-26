#include <stdio.h>
#include <stdlib.h>

#define L (1 << 23)
#define B (127)
#define QUAKE_SIGMA (0.0450465)

float magic_number(float);
float inv_sqrt(float ,float);
float sqrt_(float ,float);

int main(int argc, const char *argv[])
{
	float x = atof(argv[1]);
	float magic = magic_number(QUAKE_SIGMA);

	printf("f(x) = %f\n", inv_sqrt(x, magic));
	return 0;
}

inline float magic_number(float sigma)
{
	return 1.5 * L * (B - sigma);
}

float inv_sqrt(float x, float magic_number)
{
	float xhalf = 0.5 * x;
	int i = *(int *)&x; //Convert to integer representation
	i = magic_number - (i >> 1); // Iy ~ K - 1/2 * Ix
	x = *(float *)&i; //Back to float representation

	x = x * (1.5 - (xhalf * x * x)); //Single newton iteration
	return x;
}
