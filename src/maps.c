#include "../include/maps.h"
#include "../include/stream.h"
#include "../include/ft.h"
#include "../include/utilities.h"

/*
*	Cette fonction prend, pour chaque fichier passé en paramètre, son contenu,
*	et le place dans une ligne du tableau 'maps'.
*/
void	set_maps(char ***maps, int argc, char **argv)
{
	int	i;

	*maps = malloc(argc * sizeof(char *));
	i = 1;
	while (i < argc)
	{
		(*maps)[i - 1] = malloc((number_char_file(argv[i]) + 1) * sizeof(char));
		copy_file_to_str((*maps)[i - 1], argv[i]);
		i++;
	}
	(*maps)[i - 1] = NULL;
}

int 	is_error(char *map)
{
	int		i;
	int 	j;

	if (*map == '\0')
		return (1);
	i = size_header(map) - 4;
	j = 0;
	while (j < i)
	{
		if (map[j] < '0' || map[j] > '9')
			return (1);
		j++;
	}
	if (map[i] == map[i + 1] || map[i] == map[i + 2] ||
		map[i + 1] == map[i + 2])
		return(1);
	if (body_error(map, map[i], map[i + 1]) == 1)
		return (1);
	return (0);
}

int 	body_error(char *map, char empty, char obstacle)
{
	int i;
	int c;
	int width;
	int height;

	height = 0;
	width = 0;
	i = size_header(map);
	c = 0;
	while (map[i] != '\0')
	{
		//printf("map[%i]=%c\n", i, map[i]);
		if (map[i] == '\n')
		{
			width = width == 0 ? c : width;
			//printf("c=%i\n", c);
			//printf("width=%i\n", width);
			if (c != width)
				return (1);
			width = c;
			c = 0;
			height++;
		}
		else
		{
			if (map[i] != empty && map[i] != obstacle)
				return (1);
			c++;
		}
		i++;
	}
	//printf("height=%i\n", height);
	if (width == 0 || height != get_height(map))
		return (1);
	return (0);
}
