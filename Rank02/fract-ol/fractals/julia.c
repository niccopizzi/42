/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:08:45 by npizzi            #+#    #+#             */
/*   Updated: 2024/11/04 19:43:34 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	julia_set(double complex z, double complex c, int max_iterations)
{
	int	iteration;

	iteration = 0;
	while (cabs(z) <= 2 && iteration < max_iterations)
	{
		z = z * z + c;
		iteration++;
	}
	if (iteration == max_iterations)
		return (0);
	return (iteration);
}

void	calculate_julia(t_data data, t_fractal fractal)
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
			color = julia_colors(fractal.brightness, julia_set(real + imag * I,
						fractal.c, fractal.max_iter) % 30);
			image_put_pixel(data.image, x_axis, y_axis, color);
			x_axis++;
		}
		y_axis++;
	}
}
