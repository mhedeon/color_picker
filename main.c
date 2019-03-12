#include "header.h"

// TODO: code optimisation
// TODO: fix sliders on sifferent sizes
// TODO: universal data structure
// TODO: getter + setter

int main(int ac, char **av)
{
	t_window* window;
	if ((window = (t_window*)malloc(sizeof(t_window))) == NULL)
		return (0);
	t_palette* palette;
	if ((palette = init_palette(&(SDL_Rect) { 50, 50, 0, 360 })) == NULL)
		return (0);
	if (!init(window))
		return (0);

	

	draw_palette(window, palette);
	screen_upd(window);

	SDL_Event e;
	while (SDL_PollEvent(&e) || 1)
	{
		if (e.type == SDL_QUIT || (KEY == SDLK_ESCAPE))
			break ;
		if ((L_CLICK))
			if (in_hue(palette))
			{
				draw_palette(window, palette);
				screen_upd(window);
			}

	}

	return (0);
}
