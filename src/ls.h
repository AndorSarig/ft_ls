/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:00:10 by asarig            #+#    #+#             */
/*   Updated: 2018/02/02 16:29:14 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <string.h>
# include "libft/includes/libft.h"

typedef struct stat		t_stat;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct			s_data
{
	char				*name;
	char				*path;
	char				*rights;
	int					nlink;
	char				*ui;
	char				*group;
	int					size;
	time_t				mtime;
	char				*mt;
	int					nrblocks;
}						t_data;

void	ft_free_data(t_data *file);
void					ft_print_lsl(t_data *file, char *flags);
void					print(t_data *file, char *flags);
void					print_bad_arg(char *path, int npaths);
void					print_ill_opt(char ill);
int						ft_get_n_links(t_stat filestat);
char					*ft_get_user(t_stat filestat);
char					*ft_get_group(t_stat filestat);
int						ft_get_size(t_stat filestat);
char					*ft_rights(char *filepath, t_stat fs);
char					*ft_create_path(char *fpath, char *filename);
void					ft_get_data_of_file(char *filepath, t_stat filestat,
		t_data *current);
int						get_rec_nfiles(int i, int a, char *path);
char					*ft_get_flags(char **argv);
int						ft_ls(char *path, char *flags);
int						ft_handle_args(char **argv);
t_data					*ft_get_data(char *path, t_data *file);
int						recursive(char *path, char *flags, int a);
void					ft_swap_data(t_data *first, t_data *second);
void					ft_sort_revtime(t_data *file);
void					ft_sort_time(t_data *file);
void					ft_sort_revalph(t_data *file);
void					ft_sort_abc(t_data *file);
int						ft_nblocks(t_data *file, char *flags);

#endif
