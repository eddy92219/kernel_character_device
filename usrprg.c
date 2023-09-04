#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define WR_VALUE _IOW('a', 'a', int32_t*)
#define WR_VALUE1 _IOW('a', 'b', int32_t*)
#define RD_VALUE _IOR('a', 'c', int32_t*)


int8_t write_buf[1024];
int8_t read_buf[1024];

int main()
{
	int fd;
	char option;
	int32_t value, number;

	fd = open("/dev/my_device", O_RDWR);
	if(fd < 0)
	{
		printf("Cannot open device file\n");
		return 0;
	}


	while(1)
	{
		printf("****Please enter the option******\n");
		printf("    1. Write      \n");
		printf("    2. Write and plus 1      \n");
		printf("    3. Read      \n");
		printf("    4. Exit      \n");
		printf("*********************************\n");
		scanf(" %c", &option);
		printf("your option = %c\n", option);

		switch(option)
		{
			case '1':
				printf("Enter the value to send:\n");
				scanf("%d", &number);
				printf("Data writing..\n");
				ioctl(fd, WR_VALUE, (int32_t*)&number);
				printf("Done!\n");
				break;
			case '2':
				printf("Enter the value to send:\n");
				scanf("%d", &number);
				number = number + 1;
				printf("Data+1 writing..\n");
				ioctl(fd, WR_VALUE1, (int32_t*)&number);
				printf("Done!\n");
				break;
			case '3':
				printf("Data Reading..\n");
				ioctl(fd, RD_VALUE, (int32_t*)&value);
				printf("Done!\n");
				printf("Value is = %d\n", value);
				break;
			case '4':
				close(fd);
				exit(1);
				break;
			default:
				printf("Enter valid option\n");
				break;
		}
	}
	close(fd);
}
