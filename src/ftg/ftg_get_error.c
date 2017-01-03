/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_get_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:10:41 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 19:12:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*ctx;

t_ftg_enum	ftg_get_error(void)
{
	t_ftg_enum	error;

	error = ctx->errno;
	ctx->errno = FTG_NO_ERROR;
	return (error);
}
