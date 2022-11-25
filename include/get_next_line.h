/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:10:32 by albertmanta       #+#    #+#             */
/*   Updated: 2022/03/26 13:38:53 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//definir nombre de la libreria 
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
//Utils para nuestra funcion
char	*ft_strchr2(char *s, int c);
size_t	ft_strlen2(char *s);
char	*ft_strjoin2(char *left_str, char *buff);

#endif