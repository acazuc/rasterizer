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
void		ftg_load_identity(void);
void		ftg_mult_transpose_matrixd(const t_ftg_double *m);
void		ftg_mult_transpose_matrixf(const t_ftg_float *m);
void		ftg_load_transpose_matrixd(const t_ftg_double *m);
void		ftg_load_transpose_matrixf(const t_ftg_float *m);
void		ftg_perspective(t_ftg_double fovy, t_ftg_double aspect, t_ftg_double z_near, t_ftg_double z_far);
void		ftg_translated(t_ftg_double x, t_ftg_double y, t_ftg_double z);
void		ftg_translatef(t_ftg_float x, t_ftg_float y, t_ftg_float z);
void		ftg_rotated(t_ftg_double angle, t_ftg_double x, t_ftg_double y, t_ftg_double z);
void		ftg_rotatef(t_ftg_float angle, t_ftg_float x, t_ftg_float y, t_ftg_float z);
void		ftg_scaled(t_ftg_double x, t_ftg_double y, t_ftg_double z);
void		ftg_scalef(t_ftg_float x, t_ftg_float y, t_ftg_float z);
t_ftg_byte	ftg_minb(t_ftg_byte b1, t_ftg_byte b2);
t_ftg_ubyte	ftg_minub(t_ftg_ubyte b1, t_ftg_ubyte b2);
t_ftg_short	ftg_mins(t_ftg_short s1, t_ftg_short s2);
t_ftg_ushort	ftg_minus(t_ftg_ushort s1, t_ftg_ushort s2);
t_ftg_int	ftg_mini(t_ftg_int i1, t_ftg_int i2);
t_ftg_uint	ftg_minui(t_ftg_uint i1, t_ftg_uint i2);
t_ftg_long	ftg_minl(t_ftg_long l1, t_ftg_long l2);
t_ftg_ulong	ftg_minul(t_ftg_ulong l1, t_ftg_ulong l2);
t_ftg_float	ftg_minf(t_ftg_float f1, t_ftg_float f2);
t_ftg_double	ftg_mind(t_ftg_double f1, t_ftg_double f2);
t_ftg_byte	ftg_maxb(t_ftg_byte b1, t_ftg_byte b2);
t_ftg_ubyte	ftg_maxub(t_ftg_ubyte b1, t_ftg_ubyte b2);
t_ftg_short	ftg_maxs(t_ftg_short s1, t_ftg_short s2);
t_ftg_ushort	ftg_maxus(t_ftg_ushort s1, t_ftg_ushort s2);
t_ftg_int	ftg_maxi(t_ftg_int i1, t_ftg_int i2);
t_ftg_uint	ftg_maxui(t_ftg_uint i1, t_ftg_uint i2);
t_ftg_long	ftg_maxl(t_ftg_long l1, t_ftg_long l2);
t_ftg_ulong	ftg_maxul(t_ftg_ulong l1, t_ftg_ulong l2);
t_ftg_float	ftg_maxf(t_ftg_float f1, t_ftg_float f2);
t_ftg_double	ftg_maxd(t_ftg_double f1, t_ftg_double f2);

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
