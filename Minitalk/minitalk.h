/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:32:11 by olshklya          #+#    #+#             */
/*   Updated: 2026/01/22 18:53:15 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_message
{
	unsigned char	current_char;
	int				bit_position;
	pid_t			client_pid;
	size_t			total_chars;
}					t_message;

#endif