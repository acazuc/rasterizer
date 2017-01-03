/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:17:29 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 19:17:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC4_H
# define VEC4_H

# include "color.h"

typedef struct s_vec4	t_vec4;

void			vec4_add(t_vec4 *dst, t_vec4 *v1, t_vec4 *v2);
void			vec4_sub(t_vec4 *dst, t_vec4 *v1, t_vec4 *v2);
void			vec4_mul(t_vec4 *dst, t_vec4 *v1, double factor);
void			vec4_div(t_vec4 *dst, t_vec4 *v1, double factor);

struct			s_vec4
{
	t_color		color;
	double		x;
	double		y;
	double		z;
	double		w;
	double		u;
	double		v;
};

#endif
