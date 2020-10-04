//Simple Basic Port Scanner

#!/usr/bin/pyhton

import socket

sock=socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host="192.168.1.4" \\enter the IP of target
port=443 \\enter the port which u want to scan

def portscanner(port):
  if sock.connect_ex((host,port))
    print "Port %d is closed" % (port)
  else :
         print "[+] Port %d is Open !!" % (port)

portscanner(port)
