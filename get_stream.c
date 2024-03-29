#include "monty.h"

/**
 * stream_file - This opens a file and also read the content of the file
 * @file_path: the name of the file
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
		file_error();

	arguments->stream = fopen(file_path, "r");

	if (arguments->stream == NULL)
	{
		fclose(arguments->stream);
		file_error();
	}

	close(fd);
}
