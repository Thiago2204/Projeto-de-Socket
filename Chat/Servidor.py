import socket
import select
import sys

'''Substitui "thread" por "_thread" para python 3'''
from thread import *
 
"""O primeiro argumento AF_INET é o domínio de endereço do
soquete. Isso é usado quando temos um Domínio da Internet com
quaisquer dois hosts O segundo argumento é o tipo de soquete.
SOCK_STREAM significa que dados ou caracteres são lidos em
fluxo contínuo."""

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
 
# verifica se argumentos suficientes foram fornecidos
if len(sys.argv) != 3:
    print ("Uso correto: script, endereço IP, número da porta")
    exit()
 
# pega o primeiro argumento do prompt de comando como endereço IP
IP_address = str(sys.argv[1])
 
# recebe o segundo argumento do prompt de comando como número da porta
Port = int(sys.argv[2])
 
"""
vincula o servidor a um endereço IP inserido e no
número de porta especificado.
O cliente deve estar ciente desses parâmetros
"""
server.bind((IP_address, Port))
 
"""
escuta 100 conexões ativas. Este número pode ser
aumentado conforme a conveniência.
"""
server.listen(100)
 
list_of_clients = []
 
def clientthread(conn, addr):
 # envia uma mensagem para o cliente cujo objeto de usuário é conn
    conn.send("Bem-vindo a esta sala de bate-papo!")
 
    while True:
            try:
                message = conn.recv(2048)
                if message:
 
                   """imprime a mensagem e o endereço do
                    usuário que acabou de enviar a mensagem no servidor
                    terminal"""
                    print ("<" + addr[0] + "> " + message)
 
                    # Chama a função broadcast para enviar mensagem a todos
                    message_to_send = "<" + addr[0] + "> " + message
                    broadcast(message_to_send, conn)
 
                else:
                   """mensagem pode não ter conteúdo se a conexão
                    está quebrado, neste caso removemos a conexão"""
                    remove(conn)
 
            except:
                continue
 
"""Usando a função abaixo, transmitimos a mensagem para todos
clientes cujo objeto não é o mesmo que está enviando
a mensagem """
def broadcast(message, connection):
    for clients in list_of_clients:
        if clients!=connection:
            try:
                clients.send(message)
            except:
                clients.close()
 
               # se o link estiver quebrado, removemos o cliente
                remove(clients)
 
"""A seguinte função simplesmente remove o objeto
da lista que foi criada no início de
o programa"""
def remove(connection):
    if connection in list_of_clients:
        list_of_clients.remove(connection)
 
while True:
 
   """Aceita uma solicitação de conexão e armazena dois parâmetros,
    conn, que é um objeto de soquete para esse usuário, e addr
    que contém o endereço IP do cliente que acabou de
    conectado"""
    conn, addr = server.accept()
 
    """Mantém uma lista de clientes para facilitar a transmissão
    uma mensagem para todas as pessoas disponíveis na sala de chat"""
    list_of_clients.append(conn)
 
   # imprime o endereço do usuário que acabou de se conectar
    print (addr[0] + " connected")
 
    # cria um thread individual para cada usuário
    # que conecta

    start_new_thread(clientthread,(conn,addr))    
 
conn.close()
server.close()
