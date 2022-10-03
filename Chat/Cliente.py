import socket
import select
import sys
 
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
if len(sys.argv) != 3:
    print ("Uso correto: script, endereço IP, número da porta")
    exit()
IP_address = str(sys.argv[1])
Port = int(sys.argv[2])
server.connect((IP_address, Port))
 
while True:
 
    # mantém uma lista de possíveis fluxos de entrada
    sockets_list = [sys.stdin, server]
 
    """ Existem duas situações de entrada possíveis:
    -usuário deseja dar entrada manual para enviar para outras pessoas.
    -Servidor está enviando uma mensagem para ser impressa no
    tela. Select retorna de sockets_list, o fluxo que
    é leitor para entrada. Por exemplo, se o servidor quiser
    para enviar uma mensagem, então a condição if será verdadeira
    
    Se o usuário quiser enviar uma mensagem, o else
    condição será avaliada como verdadeira"""
  
    read_sockets,write_socket, error_socket = select.select(sockets_list,[],[])
 
    for socks in read_sockets:
        if socks == server:
            message = socks.recv(2048)
            print (message)
        else:
            message = sys.stdin.readline()
            server.send(message)
            sys.stdout.write("<You>")
            sys.stdout.write(message)
            sys.stdout.flush()
server.close()
