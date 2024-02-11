#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int fd = open("example.txt", O_RDWR | O_CREAT, 0777);

	if (fd == -1)
	{
		printf("error open the file");
		return 1;
	}
	char buffer[100];
	size_t bytesRead;

	while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0)
		write(1,buffer, bytesRead);
	if (bytesRead == -1)
		printf("errror read the file");
	
	char *add = "this is the text who added";
	size_t a = write(fd, add, strlen(add));
	if (a != -1)
		write(1, "the text has written sucessfully", 40);
	


	
	
	
	
	
	close(fd);
	return 0;
}
