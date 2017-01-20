#include "libftg.h"

t_ftg_ctx	*g_ctx;

static double	fog_get_alpha(double z)
{
	if (g_ctx->fog_mode == FTG_LINEAR)
		return ((g_ctx->fog_end - z) / (g_ctx->fog_end - g_ctx->fog_start));
	else if (g_ctx->fog_mode == FTG_EXP)
		return (exp(-g_ctx->fog_density * z));
	else if (g_ctx->fog_mode == FTG_EXP2)
		return (exp(pow(-g_ctx->fog_density * z, 2)));
	return (0);
}

static void	do_place(int x, int y)
{
	double	alpha;
	t_color	org;
	t_color	fog;

	alpha = fog_get_alpha(g_ctx->depth_buffer[y * g_ctx->width + x]);
	alpha = ftg_minf(1, ftg_maxf(0, alpha));
	fog.red = g_ctx->fog_color[0];
	fog.green = g_ctx->fog_color[1];
	fog.blue = g_ctx->fog_color[2];
	fog.alpha = g_ctx->fog_color[3];
	org.red = g_ctx->color_buffer[(y * g_ctx->width + x) * 4 + 0];
	org.green = g_ctx->color_buffer[(y * g_ctx->width + x) * 4 + 1];
	org.blue = g_ctx->color_buffer[(y * g_ctx->width + x) * 4 + 2];
	org.alpha = g_ctx->color_buffer[(y * g_ctx->width + x) * 4 + 3];
	color_mul(&fog, &fog, 1 - alpha);
	color_mul(&org, &org, alpha);
	color_add(&org, &org, &fog);
	org.alpha = 1;
	g_ctx->color_buffer[(y * g_ctx->width + x) * 4 + 0] = org.red;
	g_ctx->color_buffer[(y * g_ctx->width + x) * 4 + 1] = org.green;
	g_ctx->color_buffer[(y * g_ctx->width + x) * 4 + 2] = org.blue;
	g_ctx->color_buffer[(y * g_ctx->width + x) * 4 + 3] = org.alpha;
}

void		ftg_fog_place(void)
{
	int	x;
	int	y;

	y = 0;
	while (y < g_ctx->height)
	{
		x = 0;
		while (x < g_ctx->width)
		{
			do_place(x, y);
			++x;
		}
		++y;
	}
}
