#include "libftg.h"

t_ftg_int	ftg_maxi(t_ftg_int i1, t_ftg_int i2)
{
	return (i1 > i2 ? i1 : i2);
}

t_ftg_uint	ftg_maxui(t_ftg_uint i1, t_ftg_uint i2)
{
	return (i1 > i2 ? i1 : i2);
}

t_ftg_long	ftg_maxl(t_ftg_long l1, t_ftg_long l2)
{
	return (l1 > l2 ? l1 : l2);
}

t_ftg_ulong	ftg_maxul(t_ftg_ulong l1, t_ftg_ulong l2)
{
	return (l1 > l2 ? l1 : l2);
}

t_ftg_double	ftg_maxd(t_ftg_double d1, t_ftg_double d2)
{
	return (d1 > d2 ? d1 : d2);
}
