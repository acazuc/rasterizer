#include "libftg.h"

t_ftg_byte	ftg_maxb(t_ftg_byte b1, t_ftg_byte b2)
{
	return (b1 > b2 ? b1 : b2);
}

t_ftg_ubyte	ftg_maxub(t_ftg_ubyte b1, t_ftg_ubyte b2)
{
	return (b1 > b2 ? b1 : b2);
}

t_ftg_short	ftg_maxs(t_ftg_short s1, t_ftg_short s2)
{
	return (s1 > s2 ? s1 : s2);
}

t_ftg_ushort	ftg_maxus(t_ftg_ushort s1, t_ftg_ushort s2)
{
	return (s1 > s2 ? s1 : s2);
}

t_ftg_float	ftg_maxf(t_ftg_float f1, t_ftg_float f2)
{
	return (f1 > f2 ? f1 : f2);
}
