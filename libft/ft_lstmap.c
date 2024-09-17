/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:10:15 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:25:04 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Iterates a list and applies a function f to each node, mapping the output to a new list.
/// @param lst Pointer to the list to iterate and map.
/// @param f Void pointer to the function f to map the nodes with.
/// @param del Void pointer to a function that deletes the old memory addresses of the old list.
/// @return Pointer to the new list created, whose nodes are mapped from the previous list.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*set;

	if (!f || !del || !lst)
		return (NULL);
	new_list = NULL;
	new_node = NULL;
	while (lst)
	{
		set = f(lst->content);
		new_node = ft_lstnew(set);
		if (!new_node)
		{
			del(set);
			ft_lstclear(&new_list, del);
			return (new_list);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
