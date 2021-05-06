/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:29:54 by mtournay          #+#    #+#             */
/*   Updated: 2021/04/28 10:27:41 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main()
{
    int fd;
    int k;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    line = NULL;
    k = 0;
get_next_line(fd, &line);
		printf("line nbr : %d\n", k);
        printf("%s\n", line);
    while ((k = get_next_line(fd, &line)) > 0)
    {
		printf("line nbr : %d\n", k);
        printf("%s\n", line);
    } 
    close(fd);
    return (0);
}
