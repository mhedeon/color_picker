#ifndef COLOR_C
# define COLOR_C
# include "header.h"
# define P pqt[0]
# define Q pqt[1]
# define T pqt[2]
# define BOOST(X) (Uint8)(X * 255.0)

/*
**	hue = [0, 360]
**	saturation = [0, 1]
**	value = [0, 1]
*/

SDL_Color hsv2rgb(double h, double s, double v)
{
	double pqt[3];
	double f;
	int i;

	if (s == 0.0)
		return ((SDL_Color) { BOOST(v), BOOST(v), BOOST(v), 0 });
	h /= 60;
	i = (int)floor(h);
	f = h - (double)i;
	i %= 6;
	P = v * (1.0 - s);
	Q = v * (1.0 - s * f);
	T = v * (1.0 - s * (1.0 - f));
	if (i == 0)
		return ((SDL_Color) { BOOST(v), BOOST(T), BOOST(P), 0 });
	else if (i == 1)
		return ((SDL_Color) { BOOST(Q), BOOST(v), BOOST(P), 0 });
	else if (i == 2)
		return ((SDL_Color) { BOOST(P), BOOST(v), BOOST(T), 0 });
	else if (i == 3)
		return ((SDL_Color) { BOOST(P), BOOST(Q), BOOST(v), 0 });
	else if (i == 4)
		return ((SDL_Color) { BOOST(T), BOOST(P), BOOST(v), 0 });
	else
		return ((SDL_Color) { BOOST(v), BOOST(P), BOOST(Q), 0 });
	return ((SDL_Color) { 0, 0, 0, 0 });
}

void draw_palette(t_test *test, double h)
{
	for (int y = 0; y < 360; y++)
	{
		for (int x = 0; x < 360; x++)
		{
			test->color = hsv2rgb((double)h, (double)(x / 359.0), (double)(y / 359.0));
			set_pixel(test, &test->color, x + 50, 360 + 50 - y);
		}
	}
	for (h = 0; h < 360; h++)
	{
		test->color = hsv2rgb((double)h, 1.0, 1.0);
		for (int x = 0; x < 20; x++)
		{
			set_pixel(test, &test->color, x + 450, 360 + 50 - (int)h);
		}
	}
}

#endif
