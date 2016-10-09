/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 11:08:09 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 11:08:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	error_quit(char *error_message, char *file, int line)
{
	ft_putstr_fd("\033[1;31m", 2);
	ft_putstr_fd(error_message, 2);
	ft_putstr_fd(" (", 2);
	ft_putstr_fd(file, 2);
	ft_putchar_fd(':', 2);
	ft_putnbr_fd(line, 2);
	ft_putchar_fd(')', 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("\033[0;37m", 2);
	exit(EXIT_FAILURE);
}
