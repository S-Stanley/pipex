#include "../main.h"

t_list	get_infile(t_list lst, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		str_write("No such file or directory");
		exit(1);
	}
	close(fd);
	lst.infile = argv[1];
	return (lst);
}

t_list	get_outfile(t_list lst, char **argv)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		close(fd);
		str_write("No such file or directory");
		exit(1);
	}
	close(fd);
	lst.outfile = argv[4];
	return (lst);
}
