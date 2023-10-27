/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:42:04 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 20:04:27 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "miniRT.h"

void	hooks(t_data *data);
void	move_camera2(int key, t_data *data);
void	move_camera(int key, t_data *data);

#endif
