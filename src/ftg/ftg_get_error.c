/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_get_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:10:41 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:34:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

t_ftg_enum	ftg_get_error(void)
{
	t_ftg_enum	error;

	error = g_ctx->errno;
	g_ctx->errno = FTG_NO_ERROR;
	return (error);
}
