/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:08:45 by npizzi            #+#    #+#             */
/*   Updated: 2024/11/04 19:43:29 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	burning_ship_set(double complex c, int max_iterations)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	int		iteration;

	iteration = 0;
	x = 0.0;
	y = 0.0;
	x2 = 0.0;
	y2 = 0.0;
	while ((x2 + y2) <= 4 && iteration < max_iterations)
	{
		y = fabs((x + x) * y + cimag(c));
		x = fabs(x2 - y2 + creal(c));
		x2 = x * x;
		y2 = y * y;
		iteration++;
	}
	if (iteration == max_iterations)
		return (0);
	return (iteration);
}

void	calculate_burning_ship(t_data data, t_fractal fractal)
{
	double	real;
	double	imag;
	int		x_axis;
	int		y_axis;
	int		color;

	y_axis = 0;
	while (y_axis <= HEIGHT)
	{
		x_axis = 0;
		while (x_axis <= WIDTH)
		{
			real = fractal.x_start + (double)x_axis / WIDTH * fractal.scale;
			imag = fractal.y_start + (double)y_axis / HEIGHT * fractal.scale;
			color = burning_ship_colors(fractal.brightness,
					burning_ship_set(real + imag * I, fractal.max_iter) % 30);
			image_put_pixel(data.image, x_axis, y_axis, color);
			x_axis++;
		}
		y_axis++;
	}
}
