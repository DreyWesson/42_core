#include <stdio.h>

int rgb1(int r, int g, int b) {
  int c = r;
  c = (c << 8) | g;
  c = (c << 8) | b;
  printf("%d\n", c);
  return c;
}


int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
  	printf("%d\n", color);
    return (color);
}

int main(void)
{
	rgb1(12,34,56);
	rgb_to_int(12,34,56);
	return (0);
}