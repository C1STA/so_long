/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:25:06 by wcista            #+#    #+#             */
/*   Updated: 2023/01/05 15:11:30 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "libs/minilibx-linux/mlx.h"

/* typedef struct	s_image
{
		void		*pointer;
		t_vector	size;
		char		*pixels;
}	t_image; */

/* t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;
	
	img.pointer = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
} */

void	mlx_n(void)
{
	t_program	mlx;
	t_image	img;
	int		width;
	int		height;

	mlx.mlx_pointer = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx_pointer, 1920, 1080, "Test");
	img.pointer = mlx_new_image(mlx.mlx_pointer, width, height);
	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel, &img.line_size, &img.endian);
	img.pointer = mlx_xpm_file_to_image(mlx.mlx_pointer, "sprites/servietsky.xpm", &width, &height);
	
	
	mlx_put_image_to_window(mlx.mlx_pointer, mlx.window, img.pointer, 0, 0);
	
	
	mlx_loop(mlx.mlx_pointer);
	free(mlx.mlx_pointer);
}

//void	sprites_check()
/* void	map_displayer(char *map)
{
	t_program	mlx;

	mlx.mlx_pointer = mlx_init();
	if (mlx.mlx_pointer == NULL)
		//free_mlx();
		mlx_put_image_to_window()
	
} */

void	printmap(t_v *v)
{
	int	i;

	i = 0;
	while (i < v->m.y)
	{
		printf("%s", v->m.map[i]);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_v	*v;

	if (ac != 2)
		return (write(2, "Error\nNo arg or multiple args found.\n", 48), 1);
	v = (t_v *)malloc(sizeof(t_v));
	if (!v)
		return (1);
	extension_check(av[1]);
	v->m.map = get_map(av, v);
	is_valid(v);
	//pathfinding(map);
	//printmap(v);
	is_playable(av, v);
	//map_displayer(map);
	//mlx_n();
	free_map(v);
	free(v);
	return (0);
}
