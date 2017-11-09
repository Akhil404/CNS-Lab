# server.py
import socket
import elgamal
import pickle

#elgamal
keys=elgamal.generate_keys()
key_for_server=keys.copy()
del key_for_server['privateKey']
key_server=pickle.dumps(key_for_server,-1)

# create a socket object
serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 8001
serversocket.bind(('', port))
serversocket.listen(5)
clientsocket,addr = serversocket.accept()
print("Got a connection from %s" % str(addr))
msg=" "

key_client=clientsocket.recv(1024)
clientsocket.send(key_server)
key_client=pickle.loads(key_client)


while msg!="bye":
    smsg=clientsocket.recv(1024)#.decode('ascii')
    plaintext = elgamal.decrypt(keys['privateKey'],smsg)  #returns the message passed to elgamal.encrypt()
    print("Client(enc) : %s" % smsg)
    print("Client : %s" % plaintext)

    msg=input("Server : ")
    cipher = elgamal.encrypt(key_client['publicKey'],msg)  #returns a string
    print("Server(enc) : %s" % cipher)
    clientsocket.send(cipher.encode('ascii'))

clientsocket.close()
