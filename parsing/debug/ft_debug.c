#include "../include/parsing.h"

void	debug_color(const char *name, int color)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	printf("%s: %d -> (R:%d, G:%d, B:%d)\n", name, color, r, g, b);
}

void	debug_game(t_cub *game, t_texturse *txt)
{
	int	i;

	i = 0;
	printf("===== DEBUG GAME =====\n");
	printf("Map width: %d\n", game->map.width);
	printf("Map height: %d\n", game->map.height);
	debug_color("Floor", game->map.f_color);
	debug_color("Ceiling", game->map.c_color);
	// ADD THIS: Debug textures
	printf("\nTextures:\n");
	printf("  NO: -> %s\n", txt->so);
	printf("  SO: -> %s\n", txt->no);
	printf("  WE: -> %s\n", txt->we);
	printf("  EA: -> %s\n", txt->ea);
	printf("\nMap grid:\n");
	while (i < game->map.height && game->map.grid[i])
	{
		printf("%s\n", game->map.grid[i]);
		i++;
	}
	printf("======================\n");
}

void	pro_debug(void)
{
	static int	index = 1;

	printf("______%d______\n", index++);
}

void	debug_map_info(int width, int height)
{
	printf("Map width: %d\n", width);
	printf("Map height: %d\n", height);
}

void	debug_map_grid(t_cub *game)
{
	int	i;

	i = 0;
	while (i < game->map.height && game->map.grid[i])
	{
		printf("%s", game->map.grid[i]);
		i++;
	}
}

void	debug_textures(char *no, char *so, char *we, char *ea, char *sprite,
		char *sky, char *floor)
{
	printf("NO: %s\n", no);
	printf("SO: %s\n", so);
	printf("WE: %s\n", we);
	printf("EA: %s\n", ea);
	printf("S : %s\n", sprite);
	printf("ST: %s\n", sky);
	printf("FT: %s\n", floor);
}

void	debug_line_ascii(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		printf("char[%d] = '%c' (ascii=%d)\n", i, line[i],
			(unsigned char)line[i]);
		i++;
	}
}

void	debug_player(int x, int y, char dir)
{
	printf("Player position: (%d,%d) facing '%c'\n", x, y, dir);
}

int	debug_index(int reset)
{
	static int	index = 0;

	if (reset)
		index = 0;
	return (index++);
}
