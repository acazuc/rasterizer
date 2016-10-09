/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_init_identity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 11:33:17 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 11:36:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	mat4_init_identity(t_mat4 *mat)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		ft_memset(mat->value[i], 0, sizeof(*mat->value[i]));
		i++;
	}
	mat->value[0][0] = 1;
	mat->value[1][1] = 1;
	mat->value[2][2] = 1;
	mat->value[3][3] = 1;
}
