#include "libftg.h"

t_ftg_ctx	*ctx;

void	rast_pixel_set(int x, int y, t_color *color)
{
	float	*red;
	float	*green;
	float	*blue;
	float	*alpha;
	int	pos;

	if (y < 0 || y >= ctx->height || x < 0 || x >= ctx->width)
		return ;
	pos = (y * ctx->width + x) * 4;
	red = &ctx->color_buffer[pos + 0];
	green = &ctx->color_buffer[pos + 1];
	blue = &ctx->color_buffer[pos + 2];
	alpha = &ctx->color_buffer[pos + 3];
	if (color->alpha == 1)
	{
		*red = ftg_maxf(0, ftg_minf(1, color->red));
		*green = ftg_maxf(0, ftg_minf(1, color->green));
		*blue = ftg_maxf(0, ftg_minf(1, color->blue));
		*alpha = 1;
	}
	else
	{
		*red = ftg_maxf(0, ftg_minf(1, color->red * color->alpha + *red * (1 - color->alpha)));
		*green = ftg_maxf(0, ftg_minf(1, color->green * color->alpha + *green * (1 - color->alpha)));
		*blue = ftg_maxf(0, ftg_minf(1, color->blue * color->alpha + *blue * (1 - color->alpha)));
		*alpha = ftg_maxf(0, ftg_minf(1, *alpha + color->alpha * (1 - *alpha)));
	}
}
