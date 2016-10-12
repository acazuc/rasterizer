/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 10:53:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/12 16:32:32 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"
#include <stdio.h>

t_env	*g_env = NULL;

static void		draw_elements(t_env *env)
{
	int		coords[4 * 2];
	int		vertex[4 * 2];

	ft_memset(coords, 0, sizeof(coords));
	coords[2] = 1;
	coords[4] = 1;
	coords[5] = 1;
	coords[7] = 1;
	ft_memset(vertex, 0, sizeof(vertex));
	vertex[2] = env->render.width;
	vertex[4] = env->render.width;
	vertex[5] = env->render.height;
	vertex[7] = env->render.height;
	glBindTexture(GL_TEXTURE_2D, env->render.texture);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glVertexPointer(2, GL_INT, 0, vertex);
	glTexCoordPointer(2, GL_INT, 0, coords);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void test()
{
	t_mat4 t;
	t_mat4 rx;
	t_mat4 ry;
	t_mat4 rz;
	t_mat4 p;
	t_mat4 s;
	t_vec4 v;
	double ranges[2] = {0.1, 1000};

	mat4_init_translation(&t, 20, 20, 0);
	ft_putendl("translation:");
	mat4_dump(&t);
	mat4_init_rotation_x(&rx, M_PI / 4);
	ft_putendl("roation x:");
	mat4_dump(&rx);
	mat4_init_rotation_y(&ry, M_PI / 2);
	ft_putendl("rotation y:");
	mat4_dump(&ry);
	mat4_init_rotation_z(&rz, M_PI * 2);
	ft_putendl("rotation z");
	mat4_dump(&rz);
	mat4_init_projection(&p, 60, 640/480., ranges);
	ft_putendl("projection: ");
	mat4_dump(&p);
	mat4_init_scale(&s, 10, 10, 10);
	ft_putendl("scale: ");
	mat4_dump(&s);
	t = mat4_mult(&t, &rx);
	t = mat4_mult(&t, &ry);
	t = mat4_mult(&t, &s);
	ft_putendl("final:");
	mat4_dump(&t);
	ft_memset(&v, 0, sizeof(v));
	v.x = 1;
	v.y = 1;
	v.w = 1;
	mat4_transform_vec4(&t, &v);
	printf("x: %f, y: %f, z: %f, w: %f\n", v.x, v.y, v.z, v.w);
}

int				main()
{
	t_mat4	proj;
	t_env	env;
	double ranges[2] = {0.1, 1000};

	//test();
	mat4_init_projection(&proj, 60, 1280./720, ranges);
	g_env = &env;
	ft_memset(&env, 0, sizeof(env));
	if (!glfwInit())
		ERROR("Can't init glfw");
	camera_set_position(&env.camera, 0, 0, 2);
	camera_set_rotation(&env.camera, 0, ft_toradians(0), 0);
	camera_set_projection(&env.camera, &proj);
	window_create(&env);
	double i = 0;
	while (!glfwWindowShouldClose(env.window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		long start = epoch_millis();
		draw_elements(&env);
		glfwSwapBuffers(env.window);
		camera_set_rotation(&env.camera, 0, ft_toradians(i), 0);
		render_resize(&env.render, env.render.width, env.render.height);
		i++;
		printf("%ld\n", epoch_millis() - start);
		glfwPollEvents();
	}
	glfwTerminate();
	return (EXIT_SUCCESS);
}
