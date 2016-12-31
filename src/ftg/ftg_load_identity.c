#include "libftg.h"

t_ftg_ctx	*ctx;

void	ftg_load_identity(void)
{
	t_mat4	identity;

	mat4_init_identity(&identity);
	ftg_load_matrixd(identity.value);
}
