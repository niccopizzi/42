/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:54:00 by npizzi            #+#    #+#             */
/*   Updated: 2024/10/31 15:49:11 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	exit_hook(t_data *data)
{
	close_all(data);
	exit(EXIT_SUCCESS);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	float	scale_change;

	if (button == 4)
	{
		scale_change = data->fractal.scale * 0.8 - data->fractal.scale;
		data->fractal.scale *= 0.8;
		data->fractal.x_start -= ((double)x / WIDTH) * scale_change;
		data->fractal.y_start -= ((double)y / HEIGHT) * scale_change;
		if (data->fractal.max_iter < MAX_ITER)
			data->fractal.max_iter += 5;
		calculate_fractal(*data, data->fractal);
	}
	if (button == 5)
	{
		scale_change = data->fractal.scale * 1.2 - data->fractal.scale;
		data->fractal.scale *= 1.2;
		data->fractal.x_start -= ((double)x / WIDTH) * scale_change;
		data->fractal.y_start -= ((double)y / HEIGHT) * scale_change;
		if (data->fractal.max_iter > MIN_ITER)
			data->fractal.max_iter -= 5;
		calculate_fractal(*data, data->fractal);
	}
	return (0);
}

void	up_and_down_hook(int key, t_data *data)
{
	if (key == XK_Down)
	{
		if (data->fractal.type == 'J' || data->fractal.type == 'j')
			data->fractal.c -= 0.02 * I;
		else
			data->fractal.y_start += 0.05 * (4.0 * data->fractal.scale);
	}
	if (key == XK_Up)
	{
		if (data->fractal.type == 'J' || data->fractal.type == 'j')
			data->fractal.c += 0.02 * I;
		else
			data->fractal.y_start -= 0.05 * (4.0 * data->fractal.scale);
	}
	calculate_fractal(*data, data->fractal);
}

void	plus_minus_hook(int key, t_data *data)
{
	if (key == XK_plus || key == 65453)
		data->fractal.brightness += 0.2;
	if (key == XK_minus || key == 65451)
		data->fractal.brightness -= 0.2;
	calculate_fractal(*data, data->fractal);
}

int	keys_hook(int key, t_data *data)
{
	if (key == XK_Escape)
		close_all(data);
	if (key == XK_Left)
	{
		if (data->fractal.type == 'J' || data->fractal.type == 'j')
			data->fractal.c -= 0.02;
		else
			data->fractal.x_start -= 0.05 * (4.0 * data->fractal.scale);
		calculate_fractal(*data, data->fractal);
	}
	if (key == XK_Right)
	{
		if (data->fractal.type == 'J' || data->fractal.type == 'j')
			data->fractal.c += 0.02;
		else
			data->fractal.x_start += 0.05 * (4.0 * data->fractal.scale);
		calculate_fractal(*data, data->fractal);
	}
	if (key == XK_Down || key == XK_Up)
		up_and_down_hook(key, data);
	if (key == XK_plus || key == XK_minus || key == 65453 || key == 65451)
		plus_minus_hook(key, data);
	return (0);
}
