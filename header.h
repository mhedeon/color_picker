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
# define L_CLICK SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)
# define R_CLICK SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT)

typedef struct	s_hsv
{
	double		h;
	double		s;
	double		v;
}				t_hsv;

typedef struct	s_slider
{
	SDL_Rect	size;
	SDL_Color color;
	void (*set_sl)();
	void (*set_color)();
	void (*draw)();
	void (*set_size)();
}				t_slider;

typedef struct	s_window
{
	SDL_Window* win;
	SDL_Renderer* ren;
	SDL_Texture* tex;
	Uint32* buff;
	SDL_Color color;
}				t_window;

typedef struct	s_palette
{
	t_hsv hsv;
	SDL_Rect size;
	t_slider* hue;
	t_slider* sv;
}				t_palette;


/*
**	main.c
*/


/*
**	init.c
*/
int init(t_window* window);
int error_log(char* message);

/*
**	color.c
*/
SDL_Color hsv2rgb(double h, double s, double v);
void draw_palette(t_window* window, t_palette *pal);
int in_hue(t_palette *pal);

/*
**	window.c
*/
void set_pixel(t_window* window, SDL_Color* color, int x, int y);
void clear_buffer(t_window* window);
void color_area(t_window* window, SDL_Rect* rect, SDL_Color* color);
void	color_buffer(t_window* window, SDL_Color* color);
void screen_upd(t_window* window);

/*
**	slider.c
*/
t_slider* init_sl(SDL_Rect* size);

/*
**	palette.c
*/
t_palette* init_palette(SDL_Rect* size);

#endif
