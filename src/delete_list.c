/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 14:03:43 by aliandie          #+#    #+#             */
/*   Updated: 2015/06/13 18:56:11 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		cnt_tabline(char **t)
{
	int i;

	i = 0;
	while (t[i])
		i++;
	return (i);
}

char	**ft_tabdeline(char **t, int p)
{
	int		i;

	i = cnt_tabline(t);
	while (p < i - 1)
	{
		t[p] = t[p + 1];
		p++;
	}
	t[i - 1] = NULL;
	return (t);
}

void	delete_list(t_tools **tls, int *p)
{
	int i;

	if (cnt_tabline((*tls)->list) == 1)
	{
		term_rest();
		exit(0);
	}
	free((*tls)->list[*p]);
	(*tls)->list = ft_tabdeline((*tls)->list, *p);
	i = (*p);
	while (i < (*tls)->p_max)
	{
		(*tls)->selct[i] = (*tls)->selct[i + 1];
		i++;
	}
	(*tls)->p_max--;
}
