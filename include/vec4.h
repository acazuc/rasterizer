#ifndef VEC4_H
# define VEC4_H

# include "color.h"

typedef struct s_vec4	t_vec4;

struct			s_vec4
{
	t_color		color;
	double		x;
	double		y;
	double		z;
	double		w;
};

#endif
