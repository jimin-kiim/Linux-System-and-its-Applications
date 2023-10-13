#include <stdio.h>
#include <sys/syscall.h>

int main(void)
{
	long ret = syscall(460);
	printf("System Call returned: %ld\n", ret);

	return 0;
}
