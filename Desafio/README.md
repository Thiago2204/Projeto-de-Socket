# clienteTreads.c

## Funcionamento

- Houve um include das seguintes bibliotecas: 
`#include <stdio.h>`
`#include <stdlib.h>`
`#include <string.h>`
`#include <sys/socket.h>`
`#include <arpa/inet.h>`
`#include <unistd.h>`
`#include <pthread.h>`
`#include <semaphore.h>`

- Utilizamos `args` para passar os argumentos para as threads.
- Utilizamosm`struct` como uma forma de armazenar os dados e endereços do servidor.
- Criamos laços para checar o funcionamento.
- E o `pthread_create` e o `pthread_join` para criar uma thread e dar join nelas respectivamente.
- Por fim a `sleep` como um intervalo e seu tempo como seu argumento.
## Testagem

# servidorTreads.c

## Funcionamento

## Testagem

### Vídeo:
