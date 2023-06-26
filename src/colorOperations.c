#include "minirt.h"

unsigned int    makeIntFromRGB(t_color color)
{
    int r;
    int g;
    int b;

    r = (double)(color.r * 255);
    g = (double)(color.g * 255);
    b = (double)(color.b * 255);
    return (r << 16 | g << 8 | b);
}

t_color	makeRGBfromInt(unsigned int color)
{
	t_color		rgb;

	rgb.r = ((color >> 16) & 0xFF) / 255.0;
	rgb.g = ((color >> 8) & 0xFF) / 255.0;
	rgb.b = ((color) & 0xFF) / 255.0;
	return (rgb);
}