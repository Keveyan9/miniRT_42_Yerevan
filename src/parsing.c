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
		checker_parsing(splitted, var_head);
	}
}

void	parsing(int argc, char **argv, t_head *var_head)
{
	int		fd;

=======
	return (splitted);
}

int checkerForEachObject(char **splitted_line, t_scene *scene)
{
	static int	upperLetters = 0;

	if (splitted_line[0][0] == '\n')
		return (0);
	if (ft_strncmp(splitted_line[0], "A", 2) == 0 && ++upperLetters)
		checker_A(splitted_line, scene);
	else if (ft_strncmp(splitted_line[0], "C", 2) == 0 && ++upperLetters)
		checker_C(splitted_line, scene);
	else if (ft_strncmp(splitted_line[0], "L", 2) == 0 && ++upperLetters)
		checker_L(splitted_line, scene);
	else if (ft_strncmp(splitted_line[0], "pl", 3) == 0)
		checkerPl(splitted_line, scene);
	else if (ft_strncmp(splitted_line[0], "sp", 3) == 0)
		checkerSp(splitted_line, scene);
	else if (ft_strncmp(splitted_line[0], "cy", 3) == 0)
		checkerCy(splitted_line, scene);
	else
	    exit_code(1, "Invalid argument\n");
	return (upperLetters);
}

static void	reading_file(int fd, t_scene *scene)
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
		if (checkerForEachObject(splitted, scene) != 3)
			exit_code(1, "upper letter objects repeated in file\n");
	}
}

void	parsing(int argc, char **argv, t_scene *var_scene)
{
	int		fd;

>>>>>>> e56c2580ca659774f6cb40549f947c93618c50ba
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
<<<<<<< HEAD
	reading_file(fd, var_head);
}
=======
	reading_file(fd, var_scene);
}
>>>>>>> e56c2580ca659774f6cb40549f947c93618c50ba
