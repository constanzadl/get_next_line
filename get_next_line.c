/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduarte- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:56:59 by cduarte-          #+#    #+#             */
/*   Updated: 2020/03/04 14:24:23 by cduarte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*line_read(char *s)
{
	char	*string;
	int		i;

	i = 0;
	while (s &&  s[i] != '\0' && s[i] != '\n')
		i++;
	string = ft_strsub(s, 0, i);
	string[i] = '\0';
	return (string);
}

static char		*next_line(char *s, char *temp)
{
	if (ft_strchr(s, '\n'))
		temp = ft_strchr(s, '\n') + 1;
	else if (ft_strchr(s, '\0'))
		temp = ft_strchr(s, '\0');
	temp = ft_strdup(temp);
	free(s);
	s = temp;
	return(s);
}

int				get_next_line(const int fd, char **line)
{
	static char		*string[MAX_FD];
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char *temp;

	if (!line || fd < 0 || fd > MAX_FD || read(fd, buf, 0) < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!string[fd])
			string[fd] = ft_strnew(buf);
		buf[ret] = '\0';
		temp = ft_strjoin(string[fd], buf);
		free(string[fd]);
		string[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if ((string[fd] && *string[fd] == '\0') || !string[fd])	
		return (0);
	*line = line_read(string[fd]);
	string[fd] = next_line(string[fd], temp);
	return (1);
}
