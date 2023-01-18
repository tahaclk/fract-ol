/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:50:58 by tcelik            #+#    #+#             */
/*   Updated: 2022/12/24 16:52:58 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_in_img(t_vars *f, int x, int y, int color)
{
	char	*dst;

	dst = f->img.data + (y * f->img.sizeline + x * (f->img.bpp / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	f1(int i, t_vars *vars)
{
	if (i * (255.0 / vars->iteras) < 122)
		return (i * (255.0 / vars->iteras));
	else
		return (255 - i * (255.0 / vars->iteras));
}

int	f2(int i, t_vars *vars)
{
	if (i * (255.0 / vars->iteras) < 122)
		return (0);
	else
		return (i * (255.0 / vars->iteras) - 122);
}

void	color_chng(t_vars *vars, int i)
{
	vars->c1 = f1(i, vars);
	vars->c2 = f2(i, vars);
	vars->c3 = 0;
	if (vars->color == 0)
		return ;
	else if (vars->color == 1)
		swap_int(&(vars->c1), &(vars->c3));
	else if (vars->color == 2)
		swap_int(&(vars->c2), &(vars->c3));
	else if (vars->color == 3)
	{
		swap_int(&(vars->c2), &(vars->c3));
		swap_int(&(vars->c1), &(vars->c2));
	}
	else if (vars->color == 4)
	{
		swap_int(&(vars->c1), &(vars->c2));
		swap_int(&(vars->c2), &(vars->c3));
	}
	else if (vars->color == 5)
		swap_int(&(vars->c1), &(vars->c2));
}
