#include "header.h"

void	set_pixel(t_test* test, SDL_Color* color, int x, int y)
{
	test->buff[y * WINDOW_WIDTH + x] =
		color->r << 24 |
		color->g << 16 |
		color->b << 8 |
		color->a;
}

void	clear_buffer(t_test* test)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
			test->buff[y * WINDOW_WIDTH + x] = 0 << 16 |
			0 << 8 |
			0;
	}
}

void	screen_upd(t_test* test)
{
	SDL_UpdateTexture(test->tex, NULL, test->buff,
		WINDOW_WIDTH * sizeof(Uint32));
	SDL_RenderClear(test->ren);
	SDL_RenderCopy(test->ren, test->tex, NULL, NULL);
	SDL_RenderPresent(test->ren);
}