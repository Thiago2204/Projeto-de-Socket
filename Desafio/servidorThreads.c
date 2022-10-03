#include <arpa/inet.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
 
// Variáveis dos semáforo
sem_t x, y;
pthread_t tid;
pthread_t writerthreads[100];
pthread_t readerthreads[100];
int readercount = 0;
 
// Função reader
void* reader(void* param)
{
    // Trava o semáforo
    sem_wait(&x);
    readercount++;
 
    if (readercount == 1)
        sem_wait(&y);
 
    // Destrava o semáforo
    sem_post(&x);
 
    printf("Leitor se encontra dentro\n%d",
           readercount);
 
    sleep(5);
 
    // Trava o semáforo
    sem_wait(&x);
    readercount--;
 
    if (readercount == 0) {
        sem_post(&y);
    }
 
    // Trava o semáforo
    sem_post(&x);
 
    printf("Leitor se encontra saindo\n%d",
           readercount + 1);
    pthread_exit(NULL);
}
 
// Função digitalizadora 
void* writer(void* param)
{
    printf("Digitalizador se encontra tentando entrar"\n");
 
    // Trava o semáforo
    sem_wait(&y);
 
    printf("Writer has entered\n");
 
    // Destrava o semáforo
    sem_post(&y);
 
    printf("Digitalizador se encontra saindo\n");
    pthread_exit(NULL);
}
 
// Código Driver
int main()
{
    // Inicializa variáveis
    int serverSocket, newSocket;
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
 
    socklen_t addr_size;
    sem_init(&x, 0, 1);
    sem_init(&y, 0, 1);
 
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8989);
 
    // Vincula o socket ao endereço e número da porta.
    bind(serverSocket,
         (struct sockaddr*)&serverAddr,
         sizeof(serverAddr));
 
   // Escuta no Socket, com conexão máxima de 40 pedidos na queue
    if (listen(serverSocket, 50) == 0)
        printf("Analizando\n");
    else
        printf("Erro\n");
 
    // Array para a thread
    pthread_t tid[60];
 
    int i = 0;
 
    while (1) {
        addr_size = sizeof(serverStorage);
 
        // Extrai a primeira conexão na fila
        newSocket = accept(serverSocket,
                           (struct sockaddr*)&serverStorage,
                           &addr_size);
        int choice = 0;
        recv(newSocket,
             &choice, sizeof(choice), 0);
 
        if (choice == 1) {
            // Cria a thread leitora 
            if (pthread_create(&readerthreads[i++], NULL,
                               reader, &newSocket)
                != 0)
 
                // Erro ao criar thread
                printf("Falha ao criar o thread\n");
        }
        else if (choice == 2) {
             // Cria a thread leitora 
            if (pthread_create(&writerthreads[i++], NULL,
                               writer, &newSocket)
                != 0)
 
                // Erro ao criar a thread
                printf("Falha ao criar o thread\n");
        }
 
        if (i >= 50) {
            // Update i
            i = 0;
 
            while (i < 50) {
               // Suspende a execução da thread de chamada até o destino
                // thread termina
                pthread_join(writerthreads[i++],
                             NULL);
                pthread_join(readerthreads[i++],
                             NULL);
            }
 
            // Update i
            i = 0;
        }
    }
 
    return 0;
}