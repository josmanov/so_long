/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:44:28 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/25 18:45:02 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	clean_list(t_list **lst)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*remaining_buf;

	if (!lst || !*lst)
		return ;
	last_node = ft_lstlast(*lst);
	remaining_buf = malloc(BUFFER_SIZE + 1);
	if (remaining_buf == NULL)
		return ;
	clean_node = malloc(sizeof(t_list));
	if (remaining_buf == NULL || clean_node == NULL)
	{
		free(remaining_buf);
		return ;
	}
	i = len_to_newline(last_node);
	j = 0;
	while ((last_node->str_buf[i]))
		remaining_buf[j++] = last_node->str_buf[i++];
	remaining_buf[j] = '\0';
	clean_node->str_buf = remaining_buf;
	ft_dealloc(lst, clean_node);
}

// Ends buffered line 
void	append_node(t_list **lst, char *sub_string)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		free(sub_string);
		return ;
	}
	new_node->str_buf = sub_string;
	if (new_node->str_buf == NULL)
	{
		free(new_node);
		return ;
	}
	new_node->next = NULL;
	last_node = ft_lstlast(*lst);
	if (last_node == NULL)
		*lst = new_node;
	else
		last_node->next = new_node;
}

// Creates a new list
void	create_list(t_list **lst, int fd)
{
	int		bytes_read;
	char	*buf;

	while (!is_newline(*lst))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[bytes_read] = '\0';
		append_node(lst, buf);
	}
}

// Fetches a new line from a linked list
char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*next_line;
	int				line_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&lst, fd);
	if (lst == NULL)
		return (NULL);
	line_len = len_to_newline(lst);
	if (line_len <= 0)
		return (NULL);
	next_line = malloc(line_len + 1);
	if (next_line == NULL)
		return (NULL);
	str_cpy(lst, next_line);
	clean_list(&lst);
	return (next_line);
}
