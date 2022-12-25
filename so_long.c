/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:25:06 by wcista            #+#    #+#             */
/*   Updated: 2022/12/25 18:45:18 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "libs/minilibx-linux/mlx.h"
//#include "libs/libft/get_next_line.h"

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

void	sprites_check()

int	main(int ac, char *av[])
{
	char	*map;

	map = "";
	if (ac == 2)
	{
		extension_check(av[1]);
		map = get_map(map, av);
		is_rectangle(map);
		parsing(map);
		pathfinding(map);
		printf("%s", map);
		mlx_n();
		free(map);
	}
	else
		write(2, "Error\nNo arguments or multiple arguments found.\n", 48);
	return (0);
}
