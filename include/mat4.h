/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:17:03 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 19:17:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_H
# define MAT4_H

# include "vec4.h"

typedef struct s_mat4	t_mat4;

void			mat4_clear(t_mat4 *mat);
void			mat4_init_scale(t_mat4 *mat, double x, double y, double z);
void			mat4_init_identity(t_mat4 *mat);
void			mat4_init_projection(t_mat4 *mat, double sfov, double ratio
		, double ranges[2]);
void			mat4_init_translation(t_mat4 *mat, double x, double y
		, double z);
void			mat4_init_rotation_x(t_mat4 *mat, double angle);
void			mat4_init_rotation_y(t_mat4 *mat, double angle);
void			mat4_init_rotation_z(t_mat4 *mat, double angle);
void			mat4_dump(t_mat4 *mat);
void			mat4_mult(t_mat4 *dst, t_mat4 *m1, t_mat4 *m2);
void			mat4_transform_vec4(t_mat4 *mat, t_vec4 *vec);
void			mat4_reverse(t_mat4 *mat);

struct			s_mat4
{
	double		value[16];
};

#endif
