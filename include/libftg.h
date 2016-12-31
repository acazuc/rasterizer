#ifndef LIBFTG_H
# define LIBFTG_H

# include <stdint.h>
# include "../libft/include/libft.h"
# include "mat4.h"

# define FTG_NO_ERROR		0x00000000
# define FTG_INVALID_ENUM	0x00000001

# define FTG_BYTE		0x00000001
# define FTG_UNSIGNED_BYTE	0x00000002
# define FTG_SHORT		0x00000004
# define FTG_UNSIGNED_SHORT	0x00000008
# define FTG_INT		0x0000000f
# define FTG_UNSIGNED_INT	0x00000010
# define FTG_LONG		0x00000011
# define FTG_UNSIGNED_LONG	0x00000012
# define FTG_FLOAT		0x00000014
# define FTG_DOUBLE		0x00000018
# define FTG_BOOLEAN		0x0000001f

# define FTG_MATRIX_MODE	0x00000001
# define FTG_MODELVIEW		0x00000002
# define FTG_MODELVIEW_MATRIX	0x00000002
# define FTG_PROJECTION		0x00000004
# define FTG_PROJECTION_MATRIX	0x00000004

# define FTG_FALSE		0x00000000
# define FTG_TRUE		0x00000001

typedef uint32_t		t_ftg_enum;
typedef double			t_ftg_double;
typedef float			t_ftg_float;
typedef uint8_t			t_ftg_boolean;
typedef int64_t			t_ftg_long;
typedef uint64_t		t_ftg_ulong;
typedef int32_t			t_ftg_int;
typedef uint32_t		t_ftg_uint;
typedef int16_t			t_ftg_short;
typedef uint16_t		t_ftg_ushort;
typedef int8_t			t_ftg_byte;
typedef uint8_t			t_ftg_ubyte;
typedef struct s_ftg_ctx	t_ftg_ctx;

void		ftg_matrix_mode(t_ftg_enum mode);
t_ftg_enum	ftg_get_error(void);
void		ftg_load_matrixd(const t_ftg_double *m);
void		ftg_load_matrixf(const t_ftg_float *m);
t_ftg_boolean	ftg_get(t_ftg_enum pname, void **data, t_ftg_enum *format, t_ftg_uint *length);
void		ftg_get_booleanv(t_ftg_enum pname, t_ftg_boolean *params);
void		ftg_get_doublev(t_ftg_enum pname, t_ftg_double *params);
void		ftg_get_floatv(t_ftg_enum pname, t_ftg_float *params);
void		ftg_get_integerv(t_ftg_enum pname, t_ftg_int *params);
void		ftg_mult_matrixd(const t_ftg_double *m);
void		ftg_mult_matrixf(const t_ftg_float *m);

struct					s_ftg_ctx
{
	double				*z_index;
	float				*colors;
	int32_t				width;
	int32_t				height;
	t_mat4				matrix_projection;
	t_mat4				matrix_modelview;
	t_ftg_enum			matrix_mode;
	t_ftg_enum			errno;
};

#endif
