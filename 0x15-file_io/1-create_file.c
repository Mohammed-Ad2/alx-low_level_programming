#include "main.h"

/**
 * create_file - Creates a file with specified content.
 * @filename: The name of the file to create.
 * @text_content: The content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, rwr, len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
		text_content = "";

	for (len = 0; text_content[len]; len++)
		;

	rwr = write(fd, text_content, strlen(text_content));
	if (rwr == -1)
		return (-1);

	close(fd);
	return (1);
}
