#include "cub3d.h"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		if (check_extension(av[1], ".cub") == 1)
			launch_prgm(av[1]);
		else
			ft_putstr(ERROR_EXTENSION);
	}
	else
		ft_putstr("Too many arguments\n");
	return (0);
}