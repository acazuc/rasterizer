#ifndef LIBFTG_H
# define LIBFTG_H

# include <stdint.h>
# include <limits.h>
# include "../libft/include/libft.h"
# include "mat4.h"

# define FTG_NO_ERROR		0x00000000
# define FTG_INVALID_ENUM	0x00000001
# define FTG_INVALID_VALUE	0x00000002

# define FTG_BYTE		0x00000001
# define FTG_UNSIGNED_BYTE	0x00000002
# define FTG_SHORT		0x00000003
# define FTG_UNSIGNED_SHORT	0x00000004
# define FTG_INT		0x00000005
# define FTG_ENUM		FTG_INT
# define FTG_UNSIGNED_INT	0x00000006
# define FTG_LONG		0x00000007
# define FTG_UNSIGNED_LONG	0x00000008
# define FTG_FLOAT		0x00000009
# define FTG_CLAMPF		0x0000000a
# define FTG_DOUBLE		0x0000000b
# define FTG_CLAMPD		0x0000000c
# define FTG_BOOLEAN		0x0000000d

/*
** t_ftg_enum
*/
# define FTG_MATRIX_MODE		0x00000001
# define FTG_MODELVIEW			0x00000002
# define FTG_MODELVIEW_MATRIX		0x00000002
# define FTG_PROJECTION			0x00000003
# define FTG_PROJECTION_MATRIX		0x00000003
# define FTG_NEVER			0x00000004
# define FTG_LESS			0x00000005
# define FTG_EQUAL			0x00000006
# define FTG_LEQUAL			0x00000007
# define FTG_GREATER			0x00000008
# define FTG_NOTEQUAL			0x00000009
# define FTG_GEQUAL			0x0000000a
# define FTG_ALWAYS			0x0000000b
# define FTG_DEPTH_RANGE		0x0000000c
# define FTG_DEPTH_FUNC			0x0000000d
# define FTG_DEPTH_TEST			0x0000000e
# define FTG_DEPTH_WRITEMASK		0x0000000f
# define FTG_ZERO			0x00000010
# define FTG_ONE			0x00000011
# define FTG_SRC_COLOR			0x00000012
# define FTG_ONE_MINUS_SRC_COLOR	0x00000013
# define FTG_DST_COLOR			0x00000014
# define FTG_ONE_MINUS_DST_COLOR	0x00000015
# define FTG_SRC_ALPHA			0x00000016
# define FTG_ONE_MINUS_SRC_ALPHA	0x00000017
# define FTG_DST_ALPHA			0x00000018
# define FTG_ONE_MINUS_DST_ALPHA	0x00000019
# define FTG_CONSTANT_COLOR		0x0000001a
# define FTG_ONE_MINUS_CONSTANT_COLOR	0x0000001b
# define FTG_CONSTANT_ALPHA		0x0000001c
# define FTG_ONE_MINUS_CONSTANT_ALPHA	0x0000001d
# define FTG_SRC_ALPHA_SATURATE		0x0000001e
# define FTG_BLEND_SRC_RGB		0x0000001f
# define FTG_BLEND_SRC_ALPHA		0x00000020
# define FTG_BLEND_DST_RGB		0x00000021
# define FTG_BLEND_DST_ALPHA		0x00000022
# define FTG_FUNC_ADD			0x00000023
# define FTG_FUNC_SUBSTRACT		0x00000024
# define FTG_FUNC_REVERSE_SUBSTRACT	0x00000025
# define FTG_MIN			0x00000026
# define FTG_MAX			0x00000027
# define FTG_BLEND_COLOR		0x00000028
# define FTG_BLEND_EQUATION_RGB		0x00000029
# define FTG_BLEND_EQUATION_ALPHA	0x00000030
# define FTG_BLEND			0x00000031
# define FTG_EXP			0x00000032
# define FTG_EXP2			0x00000033
# define FTG_LINEAR			0x00000034
# define FTG_FOG			0x00000035
# define FTG_FOG_MODE			0x00000036
# define FTG_FOG_DENSITY		0x00000037
# define FTG_FOG_START			0x00000038
# define FTG_FOG_END			0x00000039
# define FTG_FOG_INDEX			0x0000003a
# define FTG_FOG_COLOR			0x0000003b

/*
** t_ftg_bitmask
*/
# define FTG_COLOR_BUFFER_BIT	0x00000001
# define FTG_DEPTH_BUFFER_BIT	0x00000002

/*
** t_ftg_boolean
*/
# define FTG_FALSE		0x00000000
# define FTG_TRUE		0x00000001

typedef uint8_t			t_ftg_bitmask;
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
typedef int32_t			t_ftg_sizei;
typedef float			t_ftg_clampf;
typedef double			t_ftg_clampd;
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
void		ftg_viewport(t_ftg_sizei width, t_ftg_sizei height);
void		ftg_clear(t_ftg_bitmask mask);
void		ftg_depth_mask(t_ftg_boolean flag);
void		ftg_depth_func(t_ftg_enum func);
void		ftg_depth_range(t_ftg_clampd near_val, t_ftg_clampd far_val);
void		ftg_disable(t_ftg_enum cap);
void		ftg_enable(t_ftg_enum cap);
void		ftg_blend_func(t_ftg_enum s_factor, t_ftg_enum d_factor);
void		ftg_blend_func_separate(t_ftg_enum src_rgb, t_ftg_enum dst_rgb, t_ftg_enum src_alpha, t_ftg_enum dst_alpha);
void		ftg_blend_equation(t_ftg_enum mode);
void		ftg_blend_equation_separate(t_ftg_enum mode_rgb, t_ftg_enum mode_alpha);
void		ftg_blend_color(t_ftg_clampf red, t_ftg_clampf green, t_ftg_clampf blue,t_ftg_clampf alpha);
void		ftg_fogf(t_ftg_enum pname, t_ftg_float param);
void		ftg_fogi(t_ftg_enum pname, t_ftg_int param);
void		ftg_fogfv(t_ftg_enum pname, t_ftg_float *param);
void		ftg_fogiv(t_ftg_enum pname, t_ftg_int *param);
void		ftg_fog_start(void *data, t_ftg_enum type);
void		ftg_fog_end(void *data, t_ftg_enum type);
void		ftg_fog_index(void *data, t_ftg_enum type);
void		ftg_fog_density(void *data, t_ftg_enum type);
void		ftg_fog_mode(void *data, t_ftg_enum type);
void		ftg_fog_color(void *data, t_ftg_enum type);
t_ftg_boolean	ftg_is_enabled(t_ftg_enum cap);
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
	t_ftg_double			*depth_buffer;
	t_ftg_float			*color_buffer;
	t_ftg_sizei			width;
	t_ftg_sizei			height;
	t_mat4				matrix_projection;
	t_mat4				matrix_modelview;
	t_ftg_boolean			depth_test;
	t_ftg_boolean			depth_writemask;
	t_ftg_enum			depth_func;
	t_ftg_clampd			depth_range[2];
	t_ftg_boolean			blend;
	t_ftg_enum			blend_src_rgb;
	t_ftg_enum			blend_src_alpha;
	t_ftg_enum			blend_dst_rgb;
	t_ftg_enum			blend_dst_alpha;
	t_ftg_enum			blend_equation_rgb;
	t_ftg_enum			blend_equation_alpha;
	t_ftg_clampf			blend_color[4];
	t_ftg_boolean			fog;
	t_ftg_clampf			fog_color[4];
	t_ftg_clampd			fog_density;
	t_ftg_clampd			fog_index;
	t_ftg_clampd			fog_start;
	t_ftg_clampd			fog_end;
	t_ftg_enum			fog_mode;
	t_ftg_enum			matrix_mode;
	t_ftg_enum			errno;
};

#endif
