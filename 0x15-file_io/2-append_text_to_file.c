#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: filename.
 * @text_content: The string to add to the end of the file.
 *
 * Return: 1 if the file exists. -1 if the file does not exist
 * or if filename is NULL -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int s;
	int famous;
	int r;

	if (!filename)
		return (-1);

	s = open(filename, O_WRONLY | O_APPEND);

	if (s == -1)
		return (-1);

	if (text_content)
	{
		for (famous = 0; text_content[famous];)
			famous++;
	}

	r = write(s, text_content, famous);

	if (r == -1)
		return (-1);

	close(s);

	return (1);
}
