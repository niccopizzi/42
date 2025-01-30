/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:07:25 by npizzi            #+#    #+#             */
/*   Updated: 2024/10/31 16:12:42 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	image_put_pixel(t_img_data *image, int x, int y, int color)
{
	int		offset;
	char	*pixel_address;

	offset = (y * image->line_len + x * (image->bits_per_pixel / 8));
	pixel_address = (image->image_address) + offset;
	*(unsigned int *)pixel_address = color;
}

void	shift_color(int *palette, double brightness)
{
	int	i;

	i = 0;
	while (i < 30)
	{
		palette[i] = palette[i] * brightness;
		i++;
	}
}

void	close_all(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image->image);
	mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}

void	print_error_and_exit(t_data *data, char *str)
{
	if (data != NULL)
	{
		if (data->image->image != NULL)
			mlx_destroy_image(data->mlx_ptr, data->image->image);
		if (data->window_ptr != NULL)
			mlx_destroy_window(data->mlx_ptr, data->window_ptr);
		if (data->mlx_ptr != NULL)
			mlx_destroy_display(data->mlx_ptr);
		ft_printf(MODE_BOLD ANSI_COLOR_RED "%s" ANSI_MODE_RESET, str);
		exit(EXIT_FAILURE);
	}
	ft_printf("%s", str);
	ft_printf("These are the fractals you can choose:\n");
	ft_printf("-> " MODE_BOLD ANSI_COLOR_BLUE "Mandelbrot\n" ANSI_MODE_RESET);
	ft_printf("-> " MODE_BOLD ANSI_COLOR_GREEN "Julia\n" ANSI_MODE_RESET);
	ft_printf("-> " MODE_BOLD ANSI_COLOR_RED "Burning Ship\n" ANSI_MODE_RESET);
	exit(EXIT_FAILURE);
}
