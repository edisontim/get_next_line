/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:26:13 by tedison           #+#    #+#             */
/*   Updated: 2021/04/14 11:28:56 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
int		ft_strcpy(char *dst, char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);
int		check_if_next_line(char *buffer);
char	*ft_strdup(char *s1, char *s2);
int		ft_malloc(char **str, int size, int bytes);
int		free_all(char *buffer, char **line, char **prev_line, int ret);

#endif
