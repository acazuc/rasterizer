/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:17:35 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 19:17:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdio.h>

typedef struct s_color	t_color;

void			color_add(t_color *dst, t_color *c1, t_color *c2);
void			color_sub(t_color *dst, t_color *c1, t_color *c2);
void			color_mul(t_color *dst, t_color *c1, double factor);
void			color_div(t_color *dst, t_color *c1, double factor);
void			color_dump(t_color *color);

struct			s_color
{
	double		red;
	double		green;
	double		blue;
	double		alpha;
};

#endif
