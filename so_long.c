/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:25:06 by wcista            #+#    #+#             */
/*   Updated: 2022/12/05 19:49:55 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "libs/minilibx-linux/mlx.h"
#include "libs/libft/get_next_line.h"


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	mlx_n(void)
{
	void	*mlx_pointer;
	void	*window;
	t_data	img;

	mlx_pointer = mlx_init();
	window = mlx_new_window(mlx_pointer, 1920, 1080, "Test");
	img.img = mlx_new_image(mlx_pointer, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx_pointer, window, img.img, 0, 0);
	mlx_destroy_window(mlx_pointer, window);
	mlx_destroy_display(mlx_pointer);
	free(mlx_pointer);
	mlx_loop(mlx_pointer);
}

int	main(int ac, char *av[])
{
	char	*map;

	map = "";
	if (ac == 2)
	{
		map = get_map(map, av);
		extension_check(av[1], map);
		is_rectangle(map);
		parsing(map);
		pathfinding(map);
		mlx_n();
		//printf("%s", map);
		free(map);
	}
	return (0);
}
