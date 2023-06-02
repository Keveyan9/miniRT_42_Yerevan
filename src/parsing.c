#include "minirt.h"

static char	**check_d_line(char *line)
{
	int		i;
	char	**splitted;

	i = -1;
	splitted = ft_split_m(line);
<<<<<<< HEAD
	free (*line);//stex line need doing free
	return (splitted);
}


=======
	//free (line);//stex line need doing free
	return (splitted);
}

>>>>>>> 61d7204ee9f1bc3f99e90e0bc475ab2b0f512df0
static void	reading_file(int fd, t_head *var_head)
{
	char	*line;
	char	**splitted;

	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		splitted = check_d_line(line);
<<<<<<< HEAD
=======
		// printf("line == %s\n", line);
>>>>>>> 61d7204ee9f1bc3f99e90e0bc475ab2b0f512df0
		checker_parsing(splitted, var_head);
	}
}

void	parsing(int argc, char **argv, t_head *var_head)
{
	int		fd;

	fd = 0;
	if (argc != 2)
	{
		if (argc == 1)
			exit_code(1, "Is not argument\n");
		else
			exit_code(1, "Is more arguments\n");
	}
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		exit_code(1, "error opening the file\n");
	reading_file(fd, var_head);
}
