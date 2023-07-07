#include "minirt.h"

static char	**check_d_line(char *line)
{
	char	**splitted;

	splitted = ft_split_m(line);
	return (splitted);
}

int checkerForEachObject(char **splitted_line, t_scene *scene)
{
	static int	upperLetters = 0;

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
		exit_code(1, "Invalid argument\n", scene, NULL);
	return (upperLetters);
}

static void	reading_file(int fd, t_scene *scene)
{
	char	*line;
	char	**splitted;

	int		count;

	line = NULL;
	splitted = NULL;
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		splitted = check_d_line(line);
		if (line)
			free_null(line);
		if (splitted && splitted[0][0] != '\n')
			count = checkerForEachObject(splitted, scene);
		if (splitted)
			double_free(splitted);
	}
	if (count != 3)
		exit_code(1, "upper letter objects are repeated or absent in file\n", \
			scene, NULL);

}

void	parsing(int argc, char **argv, t_scene *var_scene)
{
	int		fd;

	fd = 0;
	if (argc != 2)
	{
		if (argc == 1)
			exit_code(1, "No argument\n", NULL , NULL);
		else
			exit_code(1, "More arguments\n", NULL, NULL);
	}
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		exit_code(1, "error opening the file\n", NULL, NULL);
	reading_file(fd, var_scene);
}