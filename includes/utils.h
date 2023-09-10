/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:54:01 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/09 19:00:13 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"
# include "stdlib.h"

void	ft_lstaddback(t_objs **alst, t_objs *new);
double			ft_atod(const char *str);

#endif
