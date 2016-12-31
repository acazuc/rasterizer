/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_dump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 12:15:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 12:27:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

static void	print_value(double val, int x)
{
	if (val < 0)
		ft_putchar('-');
	else
		ft_putchar(' ');
	ft_putnbr(abs((int)val % 100) / 10);
	ft_putnbr(abs((int)val % 10));
	ft_putchar('.');
	ft_putnbr(abs((int)(val * 100) % 100));
	if ((int)(val * 100) % 100 < 10)
		ft_putchar(' ');
	if (x != 3)
		ft_putchar(' ');
}

void		mat4_dump(t_mat4 *mat)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			print_value(mat->value[y + x * 4], x);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
