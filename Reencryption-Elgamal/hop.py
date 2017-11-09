# hop.py
import socket
import elgamal
import pickle


# create a socket object(act as client for server.py)
c = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port2 = 8001
c.connect((host, port2))

# create a socket object(act as server for client.py)
serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port1 = 8000
serversocket.bind(('', port1))
serversocket.listen(5)
clientsocket,addr = serversocket.accept()
print("Got a connection from %s" % str(addr))

key_client=clientsocket.recv(1024)
c.send(key_client)
key_client=pickle.loads(key_client)

key_server=c.recv(1024)
clientsocket.send(key_server)
key_server=pickle.loads(key_server)

smsg=" "
while smsg!="bye":
    cmsg=clientsocket.recv(1024).decode('ascii')
    print("Client(enc) : %s" % cmsg)
    cipher = elgamal.reencrypt(key_server['publicKey'],cmsg) #returns a string
    print("Client(reenc) : %s" % cipher)
    c.send(cipher.encode('ascii'))

    smsg=c.recv(1024).decode('ascii')
    print("Server(enc) : %s" % smsg)
    cipher = elgamal.reencrypt(key_client['publicKey'],smsg) #returns a string
    print("Server(reenc) : %s" % cipher)
    clientsocket.send(cipher.encode('ascii'))


clientsocket.close()
