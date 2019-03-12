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



void draw_sv(t_window* window, t_palette* pal)
{
	int x;
	int y;

	y = pal->size.y - 1;
	while (++y < (pal->size.y + pal->size.h))
	{
		x = pal->size.x - 1;
		while (++x < (pal->size.x + pal->size.h))
		{
			window->color = hsv2rgb(pal->hsv.h, (x - (double)pal->size.x) / (double)pal->size.h, 1.0 - (y - (double)pal->size.y) / (double)pal->size.h);
			set_pixel(window, &window->color, x , y);
		}
	}
}

void draw_hue(t_window* window, t_palette* pal)
{
	int x;
	int h;
	int width;

	width = pal->size.h / 18;
	h = -1;
	while (++h < (double)pal->size.h)
	{
		window->color = hsv2rgb((double)(h * 360.0 / pal->size.h), 1.0, 1.0);
		x = pal->size.x + pal->size.h + width - 1;
		while (++x < pal->size.x + pal->size.h + width * 2)
		{
			set_pixel(window, &window->color, x, pal->size.y + h);
		}
	}
}

int in_hue(t_palette* pal)
{
	int width = pal->size.h / 18;
	int x;
	int y;

	SDL_GetMouseState(&x, &y);
	if (y < pal->size.y || y >= (pal->size.y + pal->size.h))
		return (0);
	if (x < (pal->size.x + pal->size.h + width) || x >= (pal->size.x + pal->size.h + width * 2))
		return (0);
	pal->hsv.h = y - (double)pal->size.y;
	pal->hue->set_sl(pal->hue, &(SDL_Rect){pal->hue->size.x, y - pal->hue->size.h / 2 - 4, 0, 0});
	return (1);
}

void draw_palette(t_window *window, t_palette *pal)
{
	color_buffer(window, &(SDL_Color) { 100, 100, 100, 0 });
	draw_sv(window, pal);
	draw_hue(window, pal);
	pal->hue->color = hsv2rgb(pal->hsv.h, 1.0, 1.0);
	//pal->hue->set_sl(pal->hue, &(SDL_Rect){pal->hue->size.x, pal->hsv.h* pal->size.h / 360 + pal->size.y, 0, 0});
	pal->hue->draw(window, pal->hue);
}

#endif
