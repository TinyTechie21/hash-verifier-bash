#include <stdio.h>
#include <string.h>

#define MAXC 1024

int main(int argc, char *argv[]) {

    FILE *fd1, *fd2;
    char fd1_buffer[MAXC], fd2_buffer[MAXC];
    int line_num = 1;

    if (argc != 3) {
        printf("Utilização: %s ficheiro1 ficheiro2 \n", argv[0]);
        return 0;
    }

    fd1 = fopen(argv[1], "r");
    if (fd1 == NULL) {
        perror("Erro ao abrir o ficheiro1");
        return 1;
    }

    fd2 = fopen(argv[2], "r");
    if (fd2 == NULL) {
        perror("Erro ao abrir o ficheiro2");
        return 1;
    }

    while (fgets(fd1_buffer, MAXC, fd1) != NULL && fgets(fd2_buffer, MAXC, fd2) != NULL) {
        if (strcmp(fd1_buffer, fd2_buffer) != 0) {
            printf("#%d: %s %s\n", line_num, fd1_buffer, fd2_buffer);
        }
        line_num++;
    }

    fclose(fd1);
    fclose(fd2);

    return 0;
}
