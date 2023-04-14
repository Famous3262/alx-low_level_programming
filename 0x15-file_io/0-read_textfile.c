#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to stdout.
 * @filename: text file
 * @letters: number of letters printed
 *
 * Return: numbers of letters printed. if it fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t n;
	ssize_t m;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	m = read(fd, buf, letters);
	n = write(STDOUT_FILENO, buf, m);

	free(buf);
	close(fd);
	return (n);
}
