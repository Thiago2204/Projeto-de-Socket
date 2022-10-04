# cliente.py
## Modo de Usar

- Tanto o script do servidor quanto do cliente podem ser executados no prompt de comando (no Windows) ou no bash
   Terminal (Linux) simplesmente digitando
   "python Servidor.py " ou "python Cliente.py ".
   
## Funcionamento   

- Houve o include das seguintes bibliotecas:
`import socket`
`import select`
`import sys`

- Preciso substituir as `IP_address` e `Port

- Caso asa substituicoes de `IP_address` e `Port` forem feitas corretamente e o canal seja estabelecido ele vai imprimir:
`("Uso correto: script, endereço IP, número da porta")`

- Cria uma lista de fluxos de entrada em:  `sockets_list = [sys.stdin, server]`
- Ele le o socket com  `read_sockets` e escreve com `write_socket`
### Por exemplo: 
- Python `Servidor.py` (IP de Thiago) 8081 ou (IP de Professor) 8081
- Python `Cliente.py` (IP de Kenny) 8081 ou (IP de Aluno) 8081

- Cada Script deve ser aberto em um computador onde o Script `Cliente.py` vai requisitar a um contato com o `Servidor.Py` via endereco de IP e iniciar a troca de dados (chat) caso a conexao seja estabelecida.

# servidor.py

## Funcionamento   

- incluimos as mesmas bibliotecas, no caso:
`import socket`
`import select`
`import sys`

- Servidor foi atrelado a um socket em `server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)`
- O endereco de IP recebe o argumento 1 em` = str(sys.argv[1])` 
- A porta recebe o argumento 2 em` int(sys.argv[2])`
- `EM server.listen(100)` ele executa 100 conexoes ativas 
- Na função `clientthread` vai adicionar uma mensagem e ler ela.
- Na função `broadcast` vai receber a conexção e a mensagem.
E vai ter um while pra aceitar o cliente e se aceitar o servidor vai da "connected" e, assim fechando o servidor quando acabar a funcionalidade
- caso conectado ele vai imprimir uma mensagem de conectado caso contrario o vai imprimir o mesmo de que n foi possivel conectar.
### Testagem
![image](https://user-images.githubusercontent.com/80297158/193922293-6605e273-904f-4a51-bc31-f3640294a6b2.png)

### Vídeo:
- https://youtu.be/IzeJgarJjiU
