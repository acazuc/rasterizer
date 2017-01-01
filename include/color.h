#ifndef COLOR_H
# define COLOR_H

typedef struct s_color	t_color;

t_color			color_add(t_color *c1, t_color *c2);
t_color			color_sub(t_color *c1, t_color *c2);
t_color			color_mult(t_color *color, double factor);

struct			s_color
{
	double		red;
	double		green;
	double		blue;
	double		alpha;
};

#endif
