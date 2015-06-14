/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 15:13:39 by aliandie          #+#    #+#             */
/*   Updated: 2015/06/13 19:22:34 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char	**listfill(char **av, char **list)
{
	int i;

	i = 0;
	while (av[i])
	{
		list[i] = ft_strdup(av[i]);
		i++;
	}
	return (list);
}

t_tools	*tools_init(char **av, int ac)
{
	t_tools	*tls;
	int		i;

	i = 0;
	tls = (t_tools*)malloc(sizeof(t_tools));
	tls->p_max = ac - 2;
	tls->list = (char **)malloc(sizeof(char*) * (cnt_tabline(av) + 1));
	tls->list[cnt_tabline(av)] = 0;
	tls->list = listfill(av, tls->list);
	tls->selct = (int*)malloc(sizeof(int) * ac - 1);
	i = 0;
	while (i < ac - 1)
	{
		tls->selct[i] = 0;
		i++;
	}
	return (tls);
}
