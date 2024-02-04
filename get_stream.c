#include "monty.h"

/**
 * open_and_read_file - This opens a file and also read the content of the file
 * @file_path: the name of the file
 */
/**
 * stream_file - a Function that ...
 * @file_path: Description of file_path.
 * Return: Description of the return value.
 */
void stream_file(char *file_path)
{
	int fd;

	if (file_path == NULL)
	{
		;
	}

	fd = open(file_path, O_RDONLY);

	if (fd == -1)
		/**
		 * file_error - a Function that ...
		 * Return: Description of the return value.
		 */
		file_error();

	arguments->stream = fopen(file_path, "r");

	if (arguments->stream == NULL)
	{
		fclose(arguments->stream);
		file_error();
	}

	close(fd);
}

