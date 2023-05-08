#include "../includes/minirt.h"

void    check_d_line(char *line)
{
    int     i;
    char    **splitted;

    i = -1;
    splitted = ft_split_m(line);
    //checker for each line function
}

void    checker(char **splitted_line)
{
    if (splitted_line[0])
    {
        if (ft_strncmp(splitted_line[0], "A", 2))
            checker_A(splitted_line);
        // else if (ft_strncmp(splitted_line[0], "C", 2))
        // //
        // else if (ft_strncmp(splitted_line[0], "L", 2))
        // //
        // else if (ft_strncmp(splitted_line[0], "pl", 3))
        // //
        // else if (ft_strncmp(splitted_line[0], "sp", 3))
        // //
        // else if (ft_strncmp(splitted_line[0], "cy", 3))
        //     //
        else
            exit_code(1, "Invalid argument");    
    }
}

void    checker_A(char **splitted_A)
{
    int     i;
    float   range;
    char    **rgb;
    t_color *color;
    

    i = -1;
    while (splitted_A[++i])
        ;
    if (i != 3)
        exit_error(1, "Invalid number of parameters for A\n");
    range = ft_atof(splitted_A[1]);
    if (range < 0.0 || range > 1.0)
        exit_error(1, "Out of range for A\n");   
    rgb = ft_split(splitted_A, ',');
    color = check_rgb(rgb);
}

t_color *check_rgb(char **rgb)
{
    int     len;
    int     i;
    float   col;
    t_color *color;

    i = 0;
    col = 0;
    len = ft_double_len(rgb);
    if (len != 3)
        exit_code(1, "Invalid number of parameters for RGB\n");
    while (i < len)
    {
        col = ft_atof(rgb[i]);
        if (col < 0 || col > 255)
            exit_code(1, "Invalid range for RGB\n");
    }
    color = init_color(ft_atof(rgb[0]), ft_atof(rgb[1]), ft_atof(rgb[2]));
    return (color);
}
