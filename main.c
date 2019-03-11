#include "header.h"

// TODO: code optimisation
// TODO: sliders
// TODO: universal data structure
// TODO: getter + setter

int main(int ac, char **av)
{
	t_test* test;
	if ((test = (t_test*)malloc(sizeof(t_test))) == NULL)
		return (0);
	if (!init(test))
		return (0);

	test->hsv = (t_hsv) { 0, 0, 0 };
	SDL_Rect pal = (SDL_Rect) { 0, 50, 0, 180 };
	
	draw_palette(test, &pal);
	screen_upd(test);

	SDL_Event e;
	while (SDL_PollEvent(&e) || 1)
	{
		if (e.type == SDL_QUIT || (KEY == SDLK_ESCAPE))
			break ;
		int x, y;
		if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT))
			if (in_hue(x, y, &pal))
			{
				test->hsv.h = (double)(y - 50.0);
				draw_palette(test, &pal);
				screen_upd(test);
			}

	}

	return (0);
}
