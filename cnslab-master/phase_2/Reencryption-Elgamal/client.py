# client.py
import socket
import elgamal
import pickle

#elgamal
keys=elgamal.generate_keys()
key_for_client=keys.copy()
del key_for_client['privateKey']
key_client=pickle.dumps(key_for_client,-1)

# create a socket object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 8000
s.connect((host, port))

s.send(key_client)
key_server=s.recv(1024)
key_server=pickle.loads(key_server)

msg=" "
while msg!="bye":
    msg=input("Client : ")
    cipher = elgamal.encrypt(key_server['publicKey'],msg) #returns a string
    print("Client(enc) : %s" % cipher)
    s.send(cipher.encode('ascii'))

    smsg=s.recv(1024)#.decode('ascii')
    plaintext = elgamal.decrypt(keys['privateKey'],smsg)  #returns the message passed to elgamal.encrypt()
    print("Server(enc) : %s" % smsg)
    print("Server : %s" % plaintext)

s.close()
