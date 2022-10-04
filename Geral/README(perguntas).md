# Projeto-de-Socket
## Projeto computacional de Socket de Redes Computacionais 5G

- Manipulando vários clientes no servidor com multithreading usando programação de soquete utilizando C
- - Optamos por C pela maior familiaridade com Threads na linguagem
- Chat entre 2 IPs utilizando Python
- - Foi escolhido Python pela maior facilidade da linguagem com o intuito de simplificar o maximo. 


### Questão 1. Compile dos programas (cliente e servidor) TCP e UDP:

a)	Execute o cliente TCP antes de executar o servidor TCP. O que acontece? Por quê?

- Escrevendo a mensagem, ela não sera atendida pelo servidor. uma vez que não houve uma conexão estabelecida entre cliente servidor, Uma vez que o servidor não está funcional e homologado.

(COLOCAR OS PRINTS)

b)	Faça o mesmo procedimento para o cliente e servidor UDP. O resultado foi similar ao socket TCP? Compare os resultados e justifique.

- O resultado não foi igual ao socket TCP. No caso TCP, não foi possível que os dados (mensagem) fosse enviada ao servidor executando o cliente primero. Já no Socket UDP, a mensagem foi enviada executando o cliente antes do servidor. Tal acontecimento se dá se justifica devido aos protocolos serem diferentes. O TCP trabalha com envio e confirmação que os dados foram recibidos, para considerar uma tarefa concluída, no caso do UDP que não trata a perda de pacotes durante a transmissão.
(COLOCAR OS PRINTS)

c)	O que acontece se o número da porta que o cliente tentar se conectar for diferente da porta disponibilizada pelo servidor?

- Se isso ocorrer, não será possível concretizar o envio desses dados, uma vez que é necessário, além do IP, a porta correta de conexão sejam disponibilizados pelo servidor.
(COLOCAR OS PRINTS)
