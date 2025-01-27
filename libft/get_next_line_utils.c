/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:44:28 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/25 18:45:13 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_dealloc(t_list **lst, t_list *clean_node)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->str_buf);
		free(*lst);
		*lst = tmp;
	}
	if (clean_node && clean_node->str_buf && clean_node->str_buf[0] != '\0')
	{
		*lst = clean_node;
		(*lst)->next = NULL;
	}
	else
	{
		free(clean_node->str_buf);
		free(clean_node);
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	str_cpy(t_list *lst, char *str)
{
	int		i;
	int		j;

	if (str == NULL)
		return ;
	j = 0;
	while (lst)
	{
		i = 0;
		while (lst->str_buf[i])
		{
			str[j++] = lst->str_buf[i++];
			if (lst->str_buf[i - 1] == '\n')
			{
				str[j] = '\0';
				return ;
			}
		}
		lst = lst->next;
	}
	str[j] = '\0';
}

int	len_to_newline(t_list *lst)
{
	int		i;
	int		len;

	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->str_buf[i])
		{
			if (lst->str_buf[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		lst = lst->next;
	}
	return (len);
}

int	is_newline(t_list *lst)
{
	int		i;

	while (lst)
	{
		i = 0;
		while (lst->str_buf[i])
		{
			if (lst->str_buf[i] == '\n')
				return (1);
			i++;
		}
		lst = lst->next;
	}
	return (0);
}
