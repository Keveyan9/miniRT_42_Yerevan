#include "../includes/minirt.h"

int main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc != 2)
		exit_code(1, "Invalid number of arguments");
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		exit_code(1, "error opening the file");
	while (line = get_next_line(fd))
	{
		//here Zheno's function call
	}
}