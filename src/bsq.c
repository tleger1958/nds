#include "../include/bsq.h"
#include "../include/stream.h"
#include "../include/map_error.h"
#include "../include/ft.h"

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
