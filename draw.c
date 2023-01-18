/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:54:02 by tcelik            #+#    #+#             */
/*   Updated: 2022/12/24 18:51:45 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	func(t_vars *vars)
{
	int		i;
	double	temp;

	i = 0;
	while (i < vars->iteras && vars->x_val * vars->x_val + vars->y_val
		* vars->y_val < 4)
	{
		temp = vars->x_val;
		vars->x_val = vars->x_val * vars->x_val - vars->y_val * vars->y_val
			+ vars->selected_r;
		vars->y_val = 2 * temp * vars->y_val + vars->selected_i;
		i++;
	}
	return (i);
}

void	c_calc(t_vars *vars, int *x, int *y)
{
	vars->selected_r = ((*x - WIDTH / 2.0) / vars->zoom) + vars->vertical_swift;
	vars->selected_i = ((*y - HEIGHT / 2.0) / vars->zoom)
		+ vars->horizontal_swift;
	vars->y_val = 0;
	vars->x_val = 0;
}

void	draw2(t_vars *vars)
{
	int	x;
	int	y;
	int	i;

	x = -1;
	y = -1;
	i = 0;
	black_screen(vars);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c_calc(vars, &x, &y);
			i = func(vars);
			color_chng(vars, i);
			if ((vars->x_val * vars->x_val + vars->y_val * vars->y_val) < 4)
				put_pixel_in_img(vars, x, y, create_trgb(0, 0, 0, 0));
			else
				put_pixel_in_img(vars, x, y, create_trgb(0, vars->c1, vars->c2,
						vars->c3));
		}
	}
	mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.image,
		0, 0);
}

void	draw(t_vars *f)
{
	int	x;
	int	y;
	int	i;

	x = -1;
	y = -1;
	i = 0;
	black_screen(f);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			f->x_val = ((x - WIDTH / 2.0) / f->zoom) + f->vertical_swift;
			f->y_val = ((y - HEIGHT / 2.0) / f->zoom) + f->horizontal_swift;
			i = func(f);
			color_chng(f, i);
			if ((f->x_val * f->x_val + f->y_val * f->y_val) < 4)
				put_pixel_in_img(f, x, y, create_trgb(0, 0, 0, 0));
			else
				put_pixel_in_img(f, x, y, create_trgb(0, f->c1, f->c2, f->c3));
		}
	}
	mlx_put_image_to_window(f->img.mlx, f->img.win, f->img.image, 0, 0);
}

void	black_screen(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			put_pixel_in_img(vars, i, j, 0X000000);
	}
}
