/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:25:33 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 23:45:14 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define BUFFER_SIZE 100

# define ROT_SPEED 0.005
# define MOVE_SPEED 0.025

# define W_KEY 119
# define S_KEY 115
# define D_KEY 100
# define A_KEY 97
# define LFT_KEY 65361
# define RGHT_KEY 65363
# define ESC_KEY 65307

typedef struct		s_pnt
{
	int				p_x;
	int				p_y;
}					t_pnt;

typedef struct		s_sprt
{
	double			sprt_dist;
	int				x;
	int				y;
}					t_sprt;

typedef struct		s_inf
{
	int				r_hei;
	int				r_wid;
	int				col_r_c;
	int				col_g_c;
	int				col_b_c;
	int				col_r_f;
	int				col_g_f;
	int				col_b_f;
	char			*t_path_no;
	char			*t_path_so;
	char			*t_path_ea;
	char			*t_path_we;
	char			*t_path_s;
	char			**map;
	int				map_h;
	int				map_w;
	int				*ar_mw;
	int				st_x;
	int				st_y;
	t_sprt			*sprt;
	int				am_sprt;
	int				scr_w;
	int				scr_h;
}					t_inf;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_keys
{
	int				w;
	int				s;
	int				d;
	int				a;
	int				rght;
	int				lft;
}					t_keys;

typedef struct		s_chk_inf
{
	int				am_res;
	int				am_no;
	int				am_so;
	int				am_we;
	int				am_ea;
	int				am_s;
	int				am_f;
	int				am_c;
	int				am_pl;
	char			**ff_ar;
}					t_chk_inf;

typedef struct		s_plr
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			pln_x;
	double			pln_y;
}					t_plr;

typedef struct		s_dda
{
	int				x;
	double			*buf;
	double			camera_x;
	int				stp_x;
	int				stp_y;
	int				hit;
	double			sd_dst_x;
	double			sd_dst_y;
	double			dlt_dst_x;
	double			dlt_dst_y;
	int				map_x;
	int				map_y;
	int				side;
	double			pwd;
	double			rd_x;
	double			rd_y;
	int				dr_strt;
	int				dr_end;
	int				ln_hei;
	double			wall_x;
	int				text_x;
	int				text_y;
	double			step;
	double			text_pos;
	double			sprt_x;
	double			sprt_y;
	double			inv_det;
	double			trform_x;
	double			trform_y;
	int				sprt_scr_x;
	int				sprt_hei;
	int				sprt_wid;
	int				sprt_strt_x;
	int				sprt_strt_y;
	int				sprt_end_x;
	int				sprt_end_y;
	int				sprt_tx;
	int				sprt_ty;
}					t_dda;

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				l_l;
	int				end;
}					t_data;

typedef struct		s_cub
{
	void			*mlx;
	void			*win;
	t_data			img;
	t_data			no_wall;
	t_data			so_wall;
	t_data			ea_wall;
	t_data			we_wall;
	t_data			s_sprt;
	int				no_w;
	int				no_h;
	int				so_w;
	int				so_h;
	int				ea_w;
	int				ea_h;
	int				we_w;
	int				we_h;
	int				s_w;
	int				s_h;
}					t_cub;

typedef struct		s_str
{
	t_inf			inf;
	t_chk_inf		chk;
	t_plr			plr;
	t_cub			cub;
	t_dda			dda;
	t_keys			keys;
}					t_str;

t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_putstr_fd(char *s, int fd);
int					ft_strlen(const char *str);
int					ft_atoi_cub(const char *str);
char				*ft_strchr(const char *str, int symbol);
char				*ft_strdup(char *str);
char				*ft_substr(char const *str, unsigned int start, size_t len);
char				*ft_strjoin(char const *str1, char const *str2);
int					get_next_line(int fd, char **line);

int					main(int argc, char **argv);
void				ft_put_message(char *message);
int					ft_chk_map_format(char *name);
int					ft_chk_save(char *str1, char *str2);
void				ft_extra_symbols_colour(char *str, int i);
void				ft_parser_inf(int fd, t_str *str);
void				ft_extra_symbols_colour(char *str, int i);
void				ft_get_inf(char *s, t_str *str);
void				ft_get_no_path(char *s, t_str *str);
void				ft_no_text_to_img(t_str *str);
void				ft_wall_no_text(t_str *str);
void				ft_get_so_path(char *s, t_str *str);
void				ft_so_text_to_img(t_str *str);
void				ft_wall_so_text(t_str *str);
void				ft_get_ea_path(char *s, t_str *str);
void				ft_ea_text_to_img(t_str *str);
void				ft_wall_ea_text(t_str *str);
void				ft_get_we_path(char *s, t_str *str);
void				ft_we_text_to_img(t_str *str);
void				ft_wall_we_text(t_str *str);
void				ft_get_s_path(char *s, t_str *str);
void				ft_s_text_to_img(t_str *str);
void				ft_wall_text(t_str *str);
void				ft_floor(t_str *str);
void				ft_ceiling(t_str *str);
void				ft_get_map(t_list *list, t_str *str);
void				ft_check_inf(t_str *str);
void				ft_set_plr_params(t_str *str);
void				ft_creat_sprt_arr(t_str *str);
void				ft_check_map(t_str *str);
void				ft_check_ff_map(t_str *str);
void				ft_cub3d_start(t_str *str);
void				ft_resolution(t_str *str);
void				ft_images(t_str *str);
int					col_pix(t_data *img, int x, int y);
void				my_mlx_pixel_put(t_str *str, int x, int y, int colour);
void				ft_get_dda_param(t_str *str);
void				ft_dda(t_str *str);
void				ft_dist_to_wall(t_str *str);
void				ft_wall_hei(t_str *str);
void				ft_text_param(t_str *str);
void				ft_wall_text(t_str *str);
void				ft_floor(t_str *str);
void				ft_ceiling(t_str *str);
void				ft_drawing(t_str *str);
int					ft_close_win(t_str *str);
int					ft_release_key(int keycode, t_str *str);
int					ft_press_key(int keycode, t_str *str);
void				ft_check_keys(t_str *str);
void				ft_init_keys(t_str *str);
void				ft_init_structs(t_str *str);
void				ft_check_keys(t_str *str);
int					ft_play(t_str *str);
void				ft_start(t_str *str);
void				ft_plr_mv_frnt(t_str *str);
void				ft_plr_mv_bck(t_str *str);
void				ft_plr_mv_lft(t_str *str);
void				ft_plr_mv_rght(t_str *str);
void				ft_plr_rot_rght(t_str *str);
void				ft_plr_rot_lft(t_str *str);
void				ft_creat_sprt_arr(t_str *str);
void				ft_sprites(t_str *str);
void				ft_screenshot(t_str *str, char *argv1);
void				ft_sort_sprites(t_str *str);
void				ft_free_exit(t_str *str);
int					ft_check_file(char *argv1);

#endif
