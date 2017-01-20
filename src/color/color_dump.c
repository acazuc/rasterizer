#include "color.h"

void	color_dump(t_color *color)
{
	printf("red: %f, green: %f, blue: %f, alpha: %f\n", color->red, color->green, color->blue, color->alpha);
}
