/* ************************************************************************** */
/*  LE - /            */
/*      /             */
/*   fractol.h            .::    .:/ .      .::   */
/*                     +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                     #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 23:24:07 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 00:33:28 by widrye      ###    #+. /#+    ###.fr     */
/* /                  */
/*                            /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define SCALE 256

# define GREEN "\x1b[32m"
# define BLUE "\x1b[34m"
# define RED "\x1b[31m"
# define YLW "\x1b[33m"
# define NC "\x1b[0m"

# define KEY_ESCAPE					53
# define KEY_F1						122
# define KEY_F2						120
# define KEY_F3						99
# define KEY_F4						118
# define KEY_F5						96
# define KEY_F6						97
# define KEY_F7						98
# define KEY_F8						100
# define KEY_F9						101
# define KEY_F10					109
# define KEY_F11					103
# define KEY_F12					111
# define KEY_F13					105
# define KEY_F14					107
# define KEY_F15					113
# define KEY_F16					106
# define KEY_F17					64
# define KEY_F18					79
# define KEY_F19					80
# define KEY_TILDE					50
# define KEY_1						18
# define KEY_2						19
# define KEY_3						20
# define KEY_4						21
# define KEY_5						23
# define KEY_6						22
# define KEY_7						26
# define KEY_8						28
# define KEY_9						25
# define KEY_0						29
# define KEY_MINUS					27
# define KEY_EQUAL					24
# define KEY_BACKSPACE				51
# define KEY_TAB					48
# define KEY_Q						12
# define KEY_W						13
# define KEY_E						14
# define KEY_R						15
# define KEY_T						17
# define KEY_Y						16
# define KEY_U						32
# define KEY_I						34
# define KEY_O						31
# define KEY_P						35
# define KEY_OPEN_BRACKET			33
# define KEY_OPEN_BRACE				33
# define KEY_CLOSE_BRACKET			30
# define KEY_CLOSE_BRACE			30
# define KEY_BACKSLASH				42
# define KEY_PIPE					42
# define KEY_CAPSLOCK				272
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2
# define KEY_F						3
# define KEY_G						5
# define KEY_H						4
# define KEY_J						38
# define KEY_K						40
# define KEY_L						37
# define KEY_COLON					41
# define KEY_SEMI_COLON				41
# define KEY_SIMPLE_QUOTE			39
# define KEY_DOUBLE_QUOTES			39
# define KEY_ENTER					36
# define KEY_SHIFT_LEFT				257
# define KEY_Z						6
# define KEY_X						7
# define KEY_C						8
# define KEY_V						9
# define KEY_B						11
# define KEY_N						45
# define KEY_M						46
# define KEY_LESS_THAN				43
# define KEY_COMMA					43
# define KEY_GREATER_THAN			47
# define KEY_DOT					47
# define KEY_SLASH					44
# define KEY_QUESTION_MARK			44
# define KEY_SHIFT_RIGHT			258
# define KEY_CTRL_LEFT				256
# define KEY_COMMAND_LEFT			259
# define KEY_OPTION_LEFT			261
# define KEY_ALT					261
# define KEY_SPACE					49
# define KEY_COMMAND_RIGHT			260
# define KEY_ALT_GR					262
# define KEY_FN						279
# define KEY_CTRL_RIGHT				269
# define KEY_LEFT					123
# define KEY_DOWN					125
# define KEY_RIGHT					124
# define KEY_UP						126
# define KEY_DEL					117
# define KEY_HOME					115
# define KEY_END					119
# define KEY_PAGE_UP				116
# define KEY_PAGE_DOWN				121
# define KEY_CLEAR					71
# define KEY_PAD_1					83
# define KEY_PAD_2					84
# define KEY_PAD_3					85
# define KEY_PAD_4					86
# define KEY_PAD_5					87
# define KEY_PAD_6					88
# define KEY_PAD_7					89
# define KEY_PAD_8					91
# define KEY_PAD_9					92
# define KEY_PAD_0					82
# define KEY_PAD_EQUAL				81
# define KEY_PAD_DIVIDE				75
# define KEY_PAD_MULTIPLY			67
# define KEY_PAD_SUB				78
# define KEY_PAD_ADD				69
# define KEY_PAD_ENTER				76
# define KEY_PAD_DOT				65
# define MOUSE_LEFT					280
# define MOUSE_RIGHT				281
# define MOUSE_MID					282
# define MOUSE_SCROLL_UP			283
# define MOUSE_SCROLL_DOWN			284

# define KEYPRESS					2
# define KEYRELEASE					3
# define BUTTONPRESS				4
# define BUTTONRELEASE				5
# define MOTIONNOTIFY				6
# define ENTERNOTIFY				7
# define LEAVENOTIFY				8
# define FOCUSIN					9
# define FOCUSOUT					10
# define KEYMAPNOTIFY				11
# define EXPOSE						12
# define GRAPHICSEXPOSE				13
# define NOEXPOSE					14
# define VISIBILITYNOTIFY			15
# define CREATENOTIFY				16
# define DESTROYNOTIFY				17
# define UNMAPNOTIFY				18
# define MAPNOTIFY					19
# define MAPREQUEST					20
# define REPARENTNOTIFY				21
# define CONFIGURENOTIFY			22
# define CONFIGUREREQUEST			23
# define GRAVITYNOTIFY				24
# define RESIZEREQUEST				25
# define CIRCULATENOTIFY			26
# define CIRCULATEREQUEST			27
# define PROPERTYNOTIFY				28
# define SELECTIONCLEAR				29
# define SELECTIONREQUEST			30
# define SELECTIONNOTIFY			31
# define COLORMAPNOTIFY				32
# define CLIENTMESSAGE				33
# define MAPPINGNOTIFY				34
# define LASTEVENTS					35
# define NOEVENTMASK				0L
# define KEYPRESSMASK				(1L<<0)
# define KEYRELEASEMASK				(1L<<1)
# define BUTTONPRESSMASK			(1L<<2)
# define BUTTONRELEASEMASK			(1L<<3)
# define ENTERWINDOWMASK			(1L<<4)
# define LEAVEWINDOWMASK			(1L<<5)
# define POINTERMOTIONMASK			(1L<<6)
# define POINTERMOTIONHINTMASK		(1L<<7)
# define BUTTON1MOTIONMASK			(1L<<8)
# define BUTTON2MOTIONMASK			(1L<<9)
# define BUTTON3MOTIONMASK			(1L<<10)
# define BUTTON4MOTIONMASK			(1L<<11)
# define BUTTON5MOTIONMASK			(1L<<12)
# define BUTTONMOTIONMASK			(1L<<13)
# define KRYMAPSTATEMASK			(1L<<14)
# define EXPOSUREMASK				(1L<<15)
# define VISIBILITYCHANGEMASK		(1L<<16)
# define STRUCTURENOTIFYMASK		(1L<<17)
# define RESIZEREDIRECTMASK			(1L<<18)
# define SUBSTRUCTURENOTIFYMASK		(1L<<19)
# define SUBSTRUCTUREREDIRECTMASK	(1L<<20)
# define FOCUSCHANGEMASK			(1L<<21)
# define PROPERTYCHANGEMASK			(1L<<22)
# define COLORMAPCHANGEMASK			(1L<<23)
# define OWNERGRABBUTTONMASK		(1L<<24)

# include "../miniLibX/mlx.h"
# include "math.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

#include <stdio.h> // remove this shit bruh

typedef struct  s_image
{
	void        *img;
	uint32_t    *px;
	int         bpp;
	int         bypl;
	int         endian;
}               t_image;

typedef struct s_cursor
{
	int         x;
	int         y;
}               t_cursor;

typedef struct  s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*img;	
	double		zoom;
	double		lzoom;
	size_t		speed;
	double		o_x;
	double		o_y;
	double		lastoy;
	double		lastox;
	double		offsety;
	double		offsetx;
	char		set;
	t_cursor   *cursor;
}               t_window;

typedef struct		s_sline
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				x;
	int				y;
}					t_sline;

typedef struct		s_complex
{
	double			a;
	double			bi;
}					t_complex;

/*
** --- libft functions ---
*/

int                 ft_atoi(const char *str);
int                 ft_isspace(char c);
int                 ft_isdigit(char c);
void                ft_strdel(char **as);
void                ft_putchar(const char c);
void                ft_putstr(const char *s);
void                ft_putendl(const char *src);
char                *ft_strnew(size_t size);
char                *ft_lowercase(char *s);
char                *ft_strchr(const char *s, int c);
char                *ft_strjoin(const char *s1, const char *s2);
char                *ft_strsub(char const *s, unsigned int start, size_t len);
char                *ft_strdup(const char *src);
char                *ft_strcpy(char *dst, const char *src);
char                *ft_strcat(char *dst, const char *src);
char                *ft_strsub(char const *s, unsigned int start, size_t len);
char                *ft_strndup(const char *str, size_t n);
char                *ft_itoa(int value);
size_t              ft_strcspn(const char *s, const char *charset);
size_t              ft_strlen(const char *str);
int                 ft_strcmp(const char *s1, const char *s2);

/*
** --- call to mlx functions ---
*/

int                 init_winstruct(t_window *win, char set);
int                 init_imgstruct(t_window *win);

int                 key_event(int key, t_window *win);
int					mouse_event(int button, int x, int y, t_window *win);

void				pixelit(t_image *img, int64_t y, int64_t x, int rgba);
void				yx_to_graph(double *y, double *x);
void                draw_mandelbrot(t_window *win);
void				draw_sline(t_image *img, t_sline *sl);
t_sline				*init_sline(t_sline *sl, int x1, int x2, int y1, int y2);

// int             key_press_hook(int key, t_keyboard *keyboard)
// int        	 	mouse_motion_hook(int x, int y, t_mouse *mouse)



int                 clean_exit(t_window *win);

#endif