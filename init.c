/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:58:11 by tcelik            #+#    #+#             */
/*   Updated: 2022/12/24 18:58:26 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_juliari(t_vars *vars)
{
	vars->julia_r[0] = 0.285;
	vars->julia_i[0] = 0.01;
	vars->julia_r[1] = -0.7269;
	vars->julia_i[1] = 0.1889;
	vars->julia_r[2] = -0.70176;
	vars->julia_i[2] = -0.3842;
	vars->julia_r[3] = -0.8;
	vars->julia_i[3] = 0.156;
	vars->julia_r[4] = -0.512511498387847167;
	vars->julia_i[4] = 0.521295573094847167;
	vars->julia_r[5] = -0.156844471694257101941;
	vars->julia_i[5] = -0.649707745759247905171;
	vars->julia_r[6] = -0.500934515513869749377;
	vars->julia_i[6] = -0.52287731735700945607;
	vars->julia_r[7] = -1.125;
	vars->julia_i[7] = 0.21650635094611;
	vars->julia_r[8] = -0.220858;
	vars->julia_i[8] = -0.650752;
}

void	init_img(t_vars *f)
{
	int		bpp;
	int		sizeline;
	int		endian;

	f->img.image = mlx_new_image(f->img.mlx, WIDTH, HEIGHT);
	f->img.data = mlx_get_data_addr(f->img.image, &bpp, &sizeline, &endian);
	f->img.bpp = bpp;
	f->img.sizeline = sizeline;
	f->img.endian = endian;
}

void	init_vars(t_vars *vars)
{
	vars->x_val = 0;
	vars->y_val = 0;
	vars->x = 0;
	vars->y = 0;
	vars->vertical_swift = 0;
	vars->horizontal_swift = 0;
	vars->zoom = 300.0;
	vars->color = 0;
	vars->iteras = 90;
	vars->img.mlx = mlx_init();
	vars->img.win = mlx_new_window(vars->img.mlx, WIDTH, HEIGHT, "Fract-ol");
	init_img(vars);
	init_juliari(vars);
}
