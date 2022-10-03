#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
 
// Função para enviar dados para
// soquete do servidor.
void* clienthread(void* args)
{
 
    int client_request = *((int*)args);
    int network_socket;
 
    // Cria um Socket de fluxo
    network_socket = socket(AF_INET,
                            SOCK_STREAM, 0);
 
    // Inicializa o número da porta e o endereço
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8989);
 
    // Inicia uma conexão de socket
    int connection_status = connect(network_socket,
                                    (struct sockaddr*)&server_address,
                                    sizeof(server_address));
 
    // Verifica se há erro de conexão
    if (connection_status < 0) {
        puts("Erro\n");
        return 0;
    }
 
    printf("Conexão estabelecida\n");
 
    //Envia dados para o socket
    send(network_socket, &client_request,
         sizeof(client_request), 0);
 
    //Fecha a conexão
    close(network_socket);
    pthread_exit(NULL);
 
    return 0;
}
 
// Código Drive
int main()
{
    printf("1. Ler\n");
    printf("2. Escrever\n");
 
    // Input
    int choice;
    scanf("%d", &choice);
    pthread_t tid;
 
    //Cria conexão dependendo da entrada
    switch (choice) {
    case 1: {
        int client_request = 1;
 
        // Cria uma thread
        pthread_create(&tid, NULL,
                       clienthread,
                       &client_request);
        sleep(20);
        break;
    }
    case 2: {
        int client_request = 2;
 
        // Cria uma thread
        pthread_create(&tid, NULL,
                       clienthread,
                       &client_request);
        sleep(20);
        break;
    }
    default:
        printf("Input invalido\n");
        break;
    }
 
    // Suspende a execução e chama a thread
    pthread_join(tid, NULL);
}
