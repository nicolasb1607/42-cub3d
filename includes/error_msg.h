/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:59:04 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/08 10:49:52 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define ERROR_OPEN_FILE "Error: open file\n"
# define ERROR_EXTENSION "File extension not supported (.cub only)\n"
# define ERROR_MALLOC "Error: malloc\n"
# define ERROR_MISSING_TEXTURE "Error: check map texture\n"
# define ERROR_MISSING_MAP "Error: missing map\n"
# define ERROR_MAP_FORMAT "Error: invalid character in map\n"
# define ERROR_MAP_SIZE "Error: invalid map size\n"
# define ERROR_PLAYER "Error: invalid player\n"
# define ERROR_MAP_NOT_CLOSED "Error: map not closed\n"
# define ERROR_GUI_INIT "Error: GUI initialization failed\n"
# define ERROR_COLOR_FORMAT "Error: Wrong color format (\"R,G,B\" expected)\n"
# define ERROR_LOAD_TEXTURE "Error: loading texture failed\n"
# define ERROR_TEXTURE_SIZE "Error: texture size is not 64*64\n"

#endif 