#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(int num_arg, char *vetor_arg[])
{
    if(num_arg != 2)
        {
            fprintf(stderr, "Modo de uso: %s <n_processos>\n", vetor_arg[0]);
            return EXIT_FAILURE;
        }
    
    int contador = atoi(vetor_arg[1]);
    if(contador <= 0)
        {
            fprintf(stderr, "Escolha N processos nao negativos.\n");
            return EXIT_FAILURE;
        }

    for(int iterador = 0; iterador < contador; iterador++)
        {
            pid_t pid = fork();

            if(pid < 0)
                {
                    perror("Houve erro no fork");
                    return EXIT_FAILURE;
                }
            else if(pid == 0)
                {
                    execl("./printing_program", "printing_program", NULL);
                    perror("Erro -> execl");
                    return EXIT_FAILURE;
                }
        }

    while(wait(NULL) > 0);

    printf("Todos os %d requisitados terminaram!\n", contador);

    return EXIT_SUCCESS;
}