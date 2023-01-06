/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:27:05 by wcista            #+#    #+#             */
/*   Updated: 2023/01/06 15:22:53 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_v *v)
{
	v->x.img_0 = NULL;
	v->x.img_1 = NULL;
	v->x.img_e = NULL;
	v->x.img_c = NULL;
	v->x.img_p = NULL;
}

void	convert_sprites(t_v *v)
{
	v->x.img_0 = mlx_xpm_file_to_image(v->x.mlx, "./sprites/img_0.xmp",
			&v->x.img_pxl, &v->x.img_pxl);
	if (!v->x.img_0)
		error_return(v, 12);
	v->x.img_1 = mlx_xpm_file_to_image(v->x.mlx, "./sprites/img_1.xmp",
			&v->x.img_pxl, &v->x.img_pxl);
	if (!v->x.img_1)
		error_return(v, 12);
	v->x.img_e = mlx_xpm_file_to_image(v->x.mlx, "./sprites/img_e.xmp",
			&v->x.img_pxl, &v->x.img_pxl);
	if (!v->x.img_e)
		error_return(v, 12);
	v->x.img_c = mlx_xpm_file_to_image(v->x.mlx, "./sprites/img_c.xmp",
			&v->x.img_pxl, &v->x.img_pxl);
	if (!v->x.img_c)
		error_return(v, 12);
	v->x.img_p = mlx_xpm_file_to_image(v->x.mlx, "./sprites/img_p.xmp",
			&v->x.img_pxl, &v->x.img_pxl);
	if (!v->x.img_p)
		error_return(v, 12);
}

void	get_sprites(t_v *v)
{
	init_sprites(v);
	convert_sprites(v);
}
