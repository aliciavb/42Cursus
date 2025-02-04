/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:06:08 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/04 13:02:54 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst && del)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = temp;
		}
	}
} */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		if (del)
			del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

/* int main(void)
{
    t_list *node1 = ft_lstnew(strdup("First node"));
    t_list *node2 = ft_lstnew(strdup("Node to be deleted"));

    if (!node1 || !node2)
    {
        // Handle allocation failure
        free(node1);
        free(node2);
        return (1);
    }

    ft_lstadd_front(&node1, node2);

    ft_lstclear(&node1, free);
	printf("node1: %p\n", (void *)node1);
    return (0);
} */