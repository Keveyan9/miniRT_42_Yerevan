/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:23:32 by skeveyan          #+#    #+#             */
/*   Updated: 2023/07/10 21:23:35 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MYMMlX_H
# define MYMMlX_H

typedef struct s_mlx
{
	void	*win;
	void	*mlx;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_all
{
	t_mlx	*mlx_data;
	t_scene	*scene;
	int		x;
	int		y;
	int		check;
}	t_all;

#endif
