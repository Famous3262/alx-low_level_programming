#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: filename
 * @text_content: A pointer to the content written in the file.
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, wrt, pet = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (pet = 0; text_content[pet];)
			pet++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wrt = write(fd, text_content, pet);

	if (fd == -1 || wrt == -1)
		return (-1);

	close(fd);

	return (1);
}
