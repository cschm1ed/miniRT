

#include "../../includes/minirt.h"

/**
 * trgb - converts individual color components into a single integer
 * @t: transparency component
 * @r: red component
 * @g: green component
 * @b: blue component
 *
 * Combines transparency, red, green, and blue components into a single integer.
 *
 * Return: the combined color value as an integer
 */

int	get_colour(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
