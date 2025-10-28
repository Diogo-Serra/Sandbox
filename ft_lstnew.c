/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:17:32 by diosoare          #+#    #+#             */
/*   Updated: 2025/10/28 18:19:36 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*node;

	node->content = content;
	node->next = NULL;
}

int	main(void)
{
	char	*p;
	
	p = ft_lstnew("Hello World!");
	return (0);
}