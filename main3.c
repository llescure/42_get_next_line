#include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int main(void)
{
int fd = -1;
char *line = NULL;
int ret;

/* open file - if an error occurs here, the test will be ignored, that's not your fault ! */
if ((fd = open("test.txt", O_RDONLY)) == -1 || read(fd, NULL, 0) == -1) {
        printf("test error");
return (0);
}

while ((ret = get_next_line(fd, &line)) > 0) {
printf("%s\n", line);
free(line);
line = NULL;
}
printf("return value: %d\n", ret);
free(line);

/* cleaning up */
close(fd);

    printf("test success");
while (1);
return (0);
}
