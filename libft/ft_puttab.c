/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:19:57 by aliandie          #+#    #+#             */
/*   Updated: 2015/05/05 17:33:26 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\0' && i < ft_tablen(tab))
	{
		ft_putendl(tab[i]);
		i++;
	}
}
