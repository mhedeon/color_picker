#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <SDL.h>
# include <SDL_image.h>
# include <SDL_mixer.h>
# include <SDL_ttf.h>

# define WINDOW_HEIGHT 500
# define WINDOW_WIDTH 500

# define KEY e.type == SDL_KEYDOWN && e.key.keysym.sym

typedef struct	s_test
{
	SDL_Window* win;
	SDL_Renderer* ren;
	SDL_Texture* tex;
	Uint32* buff;
	SDL_Color color;

}				t_test;


/*
**	main.c
*/


/*
**	init.c
*/
int init(t_test* test);
int error_log(char* message);

/*
**	color.c
*/
SDL_Color hsv2rgb(double h, double s, double v);
void draw_palette(t_test* test, double h);

/*
**	window.c
*/
void set_pixel(t_test* test, SDL_Color* color, int x, int y);
void clear_buffer(t_test* test);
void screen_upd(t_test* test);



#endif
