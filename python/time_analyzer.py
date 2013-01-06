import serial
import string
import re

ser = serial.Serial("COM18", 19200, timeout=1) 

x = "n"
string = ''
	
empty_buff = ''

while True:
	if(ser.readline(1) != ''):
		break
while True: #GET TIME SIG
	x = ser.readline(1)
	if(ord(x) == 2): #if start char, enter loop until end
		while True:
			x = ser.readline(1)	
			if(ord(x) == 4): 
				string = string.replace(" ", "")
				break #break if end character
			string += x
		
	if(string.find(".") != -1 and len(string)<=7): 
		print string
	string = ''
	