/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:44:35 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/25 18:42:52 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "../libft.h"
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	create_list(t_list **lst, int fd);
int		is_newline(t_list *lst);
void	append_node(t_list **lst, char *buf);
void	clean_list(t_list **lst);
int		len_to_newline(t_list *lst);
void	str_cpy(t_list *lst, char *str);
t_list	*ft_lstlast(t_list *lst);
void	ft_dealloc(t_list **lst, t_list *clean_node);

#endif
