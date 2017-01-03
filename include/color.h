#ifndef COLOR_H
# define COLOR_H

typedef struct s_color	t_color;

void			color_add(t_color *dst, t_color *c1, t_color *c2);
void			color_sub(t_color *dst, t_color *c1, t_color *c2);
void			color_mul(t_color *dst, t_color *c1, double factor);
void			color_div(t_color *dst, t_color *c1, double factor);

struct			s_color
{
	double		red;
	double		green;
	double		blue;
	double		alpha;
};

#endif
