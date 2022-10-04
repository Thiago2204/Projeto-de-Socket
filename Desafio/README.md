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
- Cada cliente foi associado a uma thread e espera seu atendimento.


# servidorTreads.c

## Funcionamento

- Incluimos as seguintes bibliotecas: 
`#include <arpa/inet.h>`
`#include <pthread.h>`
`#include <semaphore.h>`
`#include <stdio.h>`
`#include <stdlib.h>`
`#include <string.h>`
`#include <sys/socket.h>`
`#include <unistd.h>`

- Passamos as variaveis dos semáforos.
- Fizemos laços para as checagens.
- `sleep` para realizar os respectivos intervalos.
- De acordo com as Threads, o `semáforo` trava, e reinicia, fazendo esse fluxo de threads.
- Associa cada socket ao seu respectivo endereço.
- Cada thread passa as solicitacoes dos clientes e as atende.


### Vídeo:
- https://youtu.be/J5VX7xg187U
