#include "ls.h"

char	*ft_rights(char *filepath, t_stat fS)
{
	struct stat	linkStat;
	char *r;

	r = ft_strnew(11);
	lstat(filepath, &linkStat);
	if (S_ISLNK(linkStat.st_mode))
		r[0] = 'l';
	else if (S_ISDIR(fS.st_mode))
		r[0] = 'd';
	else
		r[0] = '-';
	if (fS.st_mode & S_IRUSR)
		r[1] = 'r';
	else
		r[1] = '-';
	if (fS.st_mode & S_IWUSR)
		r[2] = 'w';
	else
		r[2] = '-';
	if (fS.st_mode & S_IXUSR)
		r[3] = 'x';
	else
		r[3] = '-';
	if (fS.st_mode & S_IRGRP)
		r[4] = 'r';
	else
		r[4] = '-';
	if (fS.st_mode & S_IWGRP)
		r[5] = 'w';
	else
		r[5] = '-';
	if (fS.st_mode & S_IXGRP)
		r[6] = 'x';
	else
		r[6] = '-';
	if (fS.st_mode & S_IROTH)
		r[7] = 'r';
	else
		r[7] = '-';
	if (fS.st_mode & S_IWOTH)
		r[8] = 'w';
	else
		r[8] = '-';
	if (fS.st_mode & S_IXOTH)
		r[9] = 'x';
	else
		r[9] = '-';
	return (r);
}

