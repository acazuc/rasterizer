#ifndef LIBFTG_H
# define LIBFTG_H

# include <stdint.h>
# include "libft.h"
# include "mat4.h"

# define FTG_INVALID_ENUM	0x00000001
# define FTG_MODELVIEW		0x00000002
# define FTG_PROJECTION		0x00000004

typedef uint32_t		t_ftg_enum;
typedef struct s_ftg_ctx	t_ftg_ctx;

void		ftg_matrix_mode(t_ftg_enum mode);
t_ftg_enum	ftg_get_error(void);

struct					s_ftg_ctx
{
	double				*z_index;
	float				*colors;
	GLuint				texture;
	int32_t				width;
	int32_t				height;
	t_mat4				matrix_view;
	t_mat4				matrix_model;
	t_ftg_enum			matrix_mode;
};

#endif
