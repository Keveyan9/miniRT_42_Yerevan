#include "minirt.h"

static char	**check_d_line(char *line)
{
	int		i;
	char	**splitted;

	i = -1;
	splitted = ft_split_m(line);
	return (splitted);
}

static void	reading_file(int fd, t_scene *var_scene)
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
		if (checker_parsing(splitted, var_scene) > 3)
			exit_code(1, "upper letter objects repeated in file\n");
	}
}

void	parsing(int argc, char **argv, t_scene *var_scene)
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
	reading_file(fd, var_scene);
}