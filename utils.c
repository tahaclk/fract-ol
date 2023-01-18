/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:02:48 by tcelik            #+#    #+#             */
/*   Updated: 2022/12/24 19:03:44 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	swap_int(int *i, int *j)
{
	int	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

int	closee(int keycode, t_vars *vars)
{
	exit(EXIT_SUCCESS);
	return (0);
}

void	swtch_draw(t_vars *vars)
{
	if (vars->swtch == 0)
		draw(vars);
	else
		draw2(vars);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	set_fract(char **str, t_vars *vars)
{
	if (!ft_strcmp(str[1], "Julia"))
	{
		vars->selected_r = vars->julia_r[0];
		vars->selected_i = vars->julia_i[0];
		vars->swtch = 0;
		draw(vars);
	}
	else if (!ft_strcmp(str[1], "Mandelbrot"))
	{
		vars->swtch = 1;
		draw2(vars);
	}
}
