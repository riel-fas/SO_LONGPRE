/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:49:02 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/17 14:09:40 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	errors()
void free_game(t_game *game)
{
    int i;

    if (game->map.grid)
    {
        i = 0;
        while (i < game->map.height)
        {
            if (game->map.grid[i])
                free(game->map.grid[i]);
            i++;
        }
        free(game->map.grid);
    }
}

void exit_with_error(char *message)
{
    write(2, message, ft_strlen(message));
    write(2, "\n", 1);
    exit(EXIT_FAILURE);
}

int handle_window_close(t_game *game)
{
    free_game(game); // Free allocated memory
    exit(0);
    return (0);
}
