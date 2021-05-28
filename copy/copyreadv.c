#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/uio.h>

int main(int argc,char**argv)
{
	if(argc < 3)
	{
		printf("Usage error, %s <To be copy filename> <To be paste filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	/*printf("Value = %s", argv[0]);	
	printf("Value = %s", argv[1]);
	printf("Value = %s", argv[2]);
	printf("Value = %s", argv[3]);*/

	char* src_file;
	char* dst_file;

	src_file = malloc(strlen(argv[1]) + 1);
	dst_file = malloc(strlen(argv[2]) + 1);

	strcpy(src_file,argv[1]);
	strcpy(dst_file,argv[2]);

	int fd = open(src_file,O_RDONLY);
	if (fd < 0)
	{
		perror("Open");
		free(src_file);
		free(dst_file);
		exit(EXIT_FAILURE);
	}
	free(src_file);

	/*
	char buffer[400000] = {0};

	ssize_t count = read(fd,buffer,400000);
	if (count < 0)
	{
		perror("Read ");
		free(dst_file);
		exit(EXIT_FAILURE);
	}
	close(fd);
	*/

	int dst_fd = creat(dst_file,S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (dst_fd < 0)
	{
		perror("Create ");
		free(dst_file);
		exit(EXIT_FAILURE);
	}
	free(dst_file);
	
	char buffer[BUFSIZ] = {0};
	ssize_t count = 0,write_count = 0;

//
	struct iovec iov[3];
	iov[0].iov_base = malloc(BUFSIZ);
	iov[0].iov_len = BUFSIZ;
	iov[1].iov_base = malloc(BUFSIZ);
	iov[1].iov_len = BUFSIZ;
	iov[2].iov_base = malloc(BUFSIZ);
	iov[2].iov_len = BUFSIZ;

	while((count = readv(fd,iov,3)) > 0)
	{
		write_count = writev(dst_fd,iov,3);
		if(write_count < 0)
		{
			perror("Write ");
			exit(EXIT_FAILURE);
		}
		memset(buffer,0,BUFSIZ);
	}
	
	free(iov[0].iov_base);
	free(iov[1].iov_base);
	free(iov[2].iov_base);

	if(count < 0)
	{
		perror("Read ");
		exit(EXIT_FAILURE);
	}
//
	close(fd);
	close(dst_fd);
}
