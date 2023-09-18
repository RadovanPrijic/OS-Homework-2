#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

void 
writer(char *name, char *buffer, int num)
{
	int fd;
	fd = open(name, O_CREATE | O_RDWR); 
	write(fd, buffer, num);
	close(fd);
}

int
main(int argc, char *argv[])
{
	int i, c, num;
	char *name;
																									//blockwriter -b 10 --output-file short.txt
	name = argv[1];
    num = atoi(argv[2]);
    char buffer[num];
	
    for (i = 0; i < num; i++){
        c = 0 + i/512;
		buffer[i] = c + 'a';
	}

	writer(name, buffer, num);
	exit();
}
