/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:35:50 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/03 20:39:23 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* int main(void)
{
	char *content = "Content inside the node";
	t_list *node = ft_lstnew(content);

	printf("node->content: %s\n", (char *)node->content);
	free(node);
	return (0);
} */