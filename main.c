#include "header.h"


int main(int ac, char **av)
{
	t_test* test;
	if ((test = (t_test*)malloc(sizeof(t_test))) == NULL)
		return (0);
	if (!init(test))
		return (0);
	
	draw_palette(test, 0);

	screen_upd(test);

	SDL_Event e;
	while (SDL_PollEvent(&e) || 1)
	{
		if (e.type == SDL_QUIT || (KEY == SDLK_ESCAPE))
			break ;
		int x, y;
		if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT))
			if (x >= 450 && x <= 470 && y >= 50 && y <= 410)
			{
				draw_palette(test, (double)(360 - y + 50));
				screen_upd(test);
			}

	}

	return (0);
}
