#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str)
{
	size_t		a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

void    *thread_routine(void    *arg)
{
    int     nr_lines = *((int *)arg);
    int     fd;
    int     i = 0;
    char *buf = "Nueva linea \n";

    printf("El hilo comienza a ejecutarse...\n");
    while (i < nr_lines)
    {
        printf("Trabajando en el hilo\n");
        fd = open("file.txt", O_WRONLY | O_APPEND);
        write (fd, buf, ft_strlen(buf));
        usleep(1000000);
        close (fd);
        i++;
    }
    return ((void *)0);
}

int main(int argc, char **argv)
{
    pthread_t thread1, thread2;
    int        value;
    
    if (argc > 1)
        value = atoi(argv[1]);
    else
        return (1);
    if (pthread_create(&thread1, NULL, thread_routine, &value) != 0)
        return (1);
    pthread_join(thread1, NULL);
    printf("Trabajo en el hilo finalizado\n");
    return (0);
}