#include "main.h"

/**
 * error_files - checks if files can be opened.
 * @src_fd: file descriptor of source file.
 * @dest_fd: file descriptor of destination file.
 * @argv: arguments vector.
 * Return: no return.
 */
void error_files(int src_fd, int dest_fd, char *argv[])
{
	if (src_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - check the code for Holberton School students.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int src_fd, dest_fd, close_error;
	ssize_t n_chars, n_written;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	src_fd = open(argv[1], O_RDONLY);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_files(src_fd, dest_fd, argv);

	n_chars = 1024;
	while (n_chars == 1024)
	{
		n_chars = read(src_fd, buffer, 1024);
		if (n_chars == -1)
			error_files(-1, 0, argv);
		n_written = write(dest_fd, buffer, n_chars);
		if (n_written == -1)
			error_files(0, -1, argv);
	}

	close_error = close(src_fd);
	if (close_error == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src_fd);
		exit(100);
	}

	close_error = close(dest_fd);
	if (close_error == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd);
		exit(100);
	}
	return (0);
}
