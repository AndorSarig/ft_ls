#include "ls.h"

char	*ft_get_user(t_stat filestat)
{
	t_passwd	*pw;
	char	*name;

	if (!(pw = getpwuid(filestat.st_uid)))
		return (NULL);
	if (!(name = ft_strdup(pw->pw_name)))
		return (NULL);
	return (name);
}
