#include "header.h"

void	set_pixel(t_window* window, SDL_Color* color, int x, int y)
{
	window->buff[y * WINDOW_WIDTH + x] =
		color->r << 24 |
		color->g << 16 |
		color->b << 8 |
		color->a;
}

void	clear_buffer(t_window* window)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
			window->buff[y * WINDOW_WIDTH + x] = 0 << 16 |
			0 << 8 |
			0;
	}
}

void color_area(t_window* window, SDL_Rect* rect, SDL_Color* color)
{
	int x;
	int y;
	int h;
	int w;

	h = rect->y + rect->h;
	w = rect->x + rect->w;
	y = rect->y - 1;
	while (++y < h)
	{
		x = rect->x - 1;
		while (++x < w)
		{
			window->buff[y * WINDOW_WIDTH + x] = color->r << 24 |
				color->g << 16 |
				color->b << 8 |
				color->a;
		}
	}
}

void	color_buffer(t_window* window, SDL_Color* color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
			window->buff[y * WINDOW_WIDTH + x] = color->r << 24 |
			color->g << 16 |
			color->b << 8 |
			color->a;
	}
}

void	screen_upd(t_window* window)
{
	SDL_UpdateTexture(window->tex, NULL, window->buff,
		WINDOW_WIDTH * sizeof(Uint32));
	SDL_RenderClear(window->ren);
	SDL_RenderCopy(window->ren, window->tex, NULL, NULL);
	SDL_RenderPresent(window->ren);
}
