# include "header.h"

int init(t_window* window)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (error_log("Unable to initialize SDL:"));
	if ((window->win = SDL_CreateWindow("color picker", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN)) == NULL)
		return (error_log("Could not create window:"));
	if ((window->ren = SDL_CreateRenderer(window->win, -1, SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC)) == NULL)
		return (error_log("Could not create renderer:"));
	if ((window->tex = SDL_CreateTexture(window->ren, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, WINDOW_WIDTH, WINDOW_HEIGHT)) == NULL)
		return (error_log("Could not create texture:"));
	if ((window->buff = (Uint32*)malloc(sizeof(Uint32) *
		(WINDOW_HEIGHT * WINDOW_WIDTH))) == NULL)
		return (error_log("Could not allocate memory for buff"));
	clear_buffer(window);
	return (1);
}

int				error_log(char* message)
{
	SDL_Log("\x1b[31m%s %s\x1b[0m\n", message, SDL_GetError());
	return (0);
}
