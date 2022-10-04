# Projeto-de-Socket
## Projeto computacional de Socket de Redes Computacionais 5G

- Manipulando vários clientes no servidor com multithreading usando programação de soquete utilizando C
- - Optamos por C pela maior familiaridade com Threads na linguagem
- Chat entre 2 IPs utilizando Python
- - Foi escolhido Python pela maior facilidade da linguagem com o intuito de simplificar o maximo. 


### Questão 1. Compile dos programas (cliente e servidor) TCP e UDP:

a)	Execute o cliente TCP antes de executar o servidor TCP. O que acontece? Por quê?

- Escrevendo a mensagem, ela não sera atendida pelo servidor. uma vez que não houve uma conexão estabelecida entre cliente servidor, Uma vez que o servidor não está funcional e homologado.

b)	Faça o mesmo procedimento para o cliente e servidor UDP. O resultado foi similar ao socket TCP? Compare os resultados e justifique.

- O resultado não foi similar ao socket TCP. No Socket TCP, não foi possível que a mensagem fosse encaminhada ao servidor rodando o cliente primero. Já no Socket UDP, a mensagem se dá como enviada executando o cliente antes do servidor. Isso se dá ao fato dos protocolos serem diferentes. O TCP trabalha com envio e confirmação de recepção para considerar uma tarefa concluída, diferentemente do UDP que não trata a perda de pacotes ao longo da transmissão.

c)	O que acontece se o número da porta que o cliente tentar se conectar for diferente da porta disponibilizada pelo servidor?

- Se isso ocorrer, não será possível concretizar o envio desses dados, uma vez que é necessário, além do IP, a porta correta de conexão sejam disponibilizados pelo servidor.
