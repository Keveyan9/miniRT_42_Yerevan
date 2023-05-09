#include "../include/minirt.h"

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
        else if (ft_strncmp(splitted_line[0], "C", 2))
            //
        // else if (ft_strncmp(splitted_line[0], "L", 2))
        // //
        // else if (ft_strncmp(splitted_line[0], "pl", 3))
        // //
        // else if (ft_strncmp(splitted_line[0], "sp", 3))
        // //
        // else if (ft_strncmp(splitted_line[0], "cy", 3))
        //     //
        // else
        //     exit_code(1, "Invalid argument");    
    }
}

int color_range_check(int col0, int col1, int col2)
{
    if ((col0 < 0 || col0 > 255) || (col1 < 0 || col1 > 255)
        || (col2 < 0 || col2 > 255))
        return (0);
    return (1);
}

void check_rgb(char **rgb, int *color[3])
{
    int     i;

    i = 0;
    if (ft_double_len(rgb) != 3)
        exit_code(1, "Invalid number of parameters for RGB\n");
    *color[0] = ft_atof(rgb[0]);
    *color[1] = ft_atof(rgb[1]);
    *color[2] = ft_atof(rgb[2]);
    if (color_range_check(*color[0], *color[1], *color[2]) == 0)
        exit_code(1, "R, G, B out of range, [0, 255]\n");
    //color = init_color(ft_atof(rgb[0]), ft_atof(rgb[1]), ft_atof(rgb[2]));
}

void    checker_A(char **splitted_A)
{
    int     i;
    float   range;
    char    **rgb;
    int     color[3];

    i = -1;
    while (splitted_A[++i])
        ;
    if (i != 3)
        exit_error(1, "Invalid number of parameters for A\n");
    range = ft_atof(splitted_A[1]);
    if (range < 0.0 || range > 1.0)
        exit_error(1, "Out of range for A\n");
    rgb = ft_split(splitted_A, ',');
    check_rgb(rgb, &color);
}

void    checker_C(char **splitted_C)
{
    int     i;
    float   range;
    char    **rgb;
    int     color[3];

    i = -1;
    while (splitted_C[++i])
        ;
    if (i != 3)
        exit_error(1, "Invalid number of parameters for A\n");
    range = ft_atof(splitted_C[1]);
    if (range < 0.0 || range > 1.0)
        exit_error(1, "Out of range for A\n");
    rgb = ft_split(splitted_C, ',');
    check_rgb(rgb, &color);
}