/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:05:36 by npizzi            #+#    #+#             */
/*   Updated: 2024/10/31 17:54:43 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot_colors(double brightness, int iteration)
{
	int	*mandelbrot_palette;

	mandelbrot_palette = (int []){0x000000, 0x0033FF, 0x0066FF, 0x0099FF,
		0x00CCFF, 0x00FFFF, 0x19E5FF, 0x33CCFF, 0x4CB2FF, 0x66A5FF, 0x80CCFF,
		0x99E5FF, 0xB2FFFF, 0xCCFFCC, 0xE5FF99, 0xFFFF66, 0xFFCC00, 0xFFB300,
		0xFF9900, 0xFF8000, 0xFF6600, 0xFF4C00, 0xFF3300, 0xFF1900, 0xFF0000,
		0xE50000, 0xCC0000, 0xB30000, 0x990000, 0x800000};
	if (brightness != 1.0)
		return (mandelbrot_palette[iteration] * brightness);
	return (mandelbrot_palette[iteration]);
}

int	julia_colors(double brightness, int iteration)
{
	int	*julia_palette;

	julia_palette = (int []){0x000000, 0x33FF57, 0x5733FF, 0x33FFF5, 0xF5FF33,
		0xFF33F5, 0xF5A623, 0x23A6F5, 0xA6F523, 0x23F5A6, 0xA623F5, 0xF523A6,
		0xE74C3C, 0x3498DB, 0x2ECC71, 0x9B59B6, 0xF1C40F, 0xE67E22, 0x1ABC9C,
		0x34495E, 0x95A5A6, 0xE84393, 0x2C3E50, 0xD4AC0D, 0x48C9B0, 0x5DADE2,
		0xD98880, 0xAF7AC5, 0x45B39D, 0x2980B9};
	if (brightness != 1.0)
		return (julia_palette[iteration] * brightness);
	return (julia_palette[iteration]);
}

int	burning_ship_colors(double brightness, int iteration)
{
	int	*burning_ship_palette;

	burning_ship_palette = (int []){0x000000, 0x330000, 0x660000, 0x930000,
		0xBF0000, 0xEF0000, 0xFF0000, 0xFF3300, 0xFF6600, 0xFF9900, 0xFFCC00,
		0xFFFF00, 0xE5FF00, 0xCFFF00, 0xBFFF00, 0xA5FF00, 0x80FF00, 0x60FF00,
		0x40FF00, 0x00FF00, 0x00CC00, 0x008000, 0x006000, 0x004000, 0x003000,
		0x330000, 0x260000, 0x1A0000, 0x0C0000, 0x060000};
	if (brightness != 1.0)
		return (burning_ship_palette[iteration] * brightness);
	return (burning_ship_palette[iteration]);
}
