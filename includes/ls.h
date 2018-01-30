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
# include "../libft/includes/libft.h"

typedef struct stat	t_stat;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct
{
	char	*name;
	char	*path;
	char	*rights;
	int	nlink;
	char	*ui;
	char	*group;
	int	size;
	time_t	mtime;
	char	*mt;
	int	nrblocks;
}	data;

void	ft_print_lsl(data *file, char *flags);
void	print(data *file, char *flags);
int	ft_get_n_links(t_stat filestat);
char	*ft_get_user(t_stat filestat);
char	*ft_get_group(t_stat filestat);
int	ft_get_size(t_stat filestat);
char	*ft_rights(char *filepath, t_stat fS);
char	*ft_create_path(char *fpath, char *filename);
void	ft_get_data_of_file(char *filepath, t_stat filestat, data *current);
int	get_rec_nfiles(int i, int a, char *path);
char	*ft_get_flags(char **argv);
int	ft_ls(char *path, char *flags);
int	ft_handle_args(char **argv);
data	*ft_get_data(char *path, data *file);
int	recursive(char *path, char *flags);
void	ft_swap_data(data *first, data *second);
void	ft_sort_revtime(data *file);
void	ft_sort_time(data *file);
void	ft_sort_revalph(data *file);
int	ft_nblocks(data *file, char *flags);

#endif
