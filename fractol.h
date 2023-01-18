/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:53:29 by tcelik            #+#    #+#             */
/*   Updated: 2022/12/25 14:55:41 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlxlib/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define WIDTH				1280
# define HEIGHT				720
//# include <unistd.h>

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_image
{
	void	*mlx;
	void	*win;
	int		*image;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
}	t_image;

typedef struct s_vars
{
	t_image	img;
	double	x;
	double	y;
	double	x_val;
	double	y_val;
	double	vertical_swift;
	double	horizontal_swift;
	double	zoom;
	double	julia_r[9];
	double	julia_i[9];
	double	selected_r;
	double	selected_i;
	int		color;
	int		swtch;
	int		c1;
	int		c2;
	int		c3;
	int		iteras;
}				t_vars;

int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
void	c_calc(t_vars *vars, int *x, int *y);
int		create_trgb(int t, int r, int g, int b);
int		closee(int keycode, t_vars *vars);
void	black_screen(t_vars *vars);
void	draw(t_vars *vars);
void	draw2(t_vars *vars);
int		f1(int i, t_vars *vars);
int		f2(int i, t_vars *vars);
int		move(int keycode, t_vars *vars);
int		key(int keycode, t_vars *vars);
void	color_chng(t_vars *vars, int i);
void	swap_int(int *i, int *j);
void	colorful_fract(t_vars *vars);
void	swtch_draw(t_vars *vars);
void	set_fract(char **str, t_vars *vars);
void	draw(t_vars *vars);
void	draw2(t_vars *vars);
void	init__i(t_vars *vars);
int		ft_strcmp(char *s1, char *s2);
int		zoom(int keycode, int x, int y, t_vars *vars);
void	put_pixel_in_img(t_vars *f, int x, int y, int color);
void	init_img(t_vars *f);
void	init_vars(t_vars *vars);
int		func(t_vars *vars);

#endif
