#Scanning first 1000 ports of any target IP
#!/usr/bin/pyhton

import socket

sock=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket.setdefaulttimeout(1)

host=raw_input("Enter the host to scan : ")

def portscanner(port):
  if sock.connect_ex((host,port))
    print "Port %d is closed" % (port)
  else :
         print "[+] Port %d is Open !!" % (port)
for port in range(1,1000):
  portscanner(port)
