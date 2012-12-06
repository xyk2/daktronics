import serial
import string
import re

ser = serial.Serial("COM18", 19200, timeout=1) 

x = "n"
string = ''

""" while True:
	x = ser.readline(1)
	#if(x == " "): x = "#"
	#if(ord(x) == 22 or ord(x) == 23 or ord(x) == 1 or ord(x) == 4): x = '.'
	
	if(ord(x) != 2): string += x
	
	#print x,
	#print ord(x)
	if(ord(x) == 2): 
		print string
		#print re.split("/W+", string)
		#print str(string).split(".")
		print
		string = ''
		"""
		
empty_buff = ''

while True:
	if(ser.readline(1) != ''):
		break
while True: #GET TIME SIG
	x = ser.readline(1)
	if(ord(x) == 2): #if start char, enter loop until end
		while True:
			x = ser.readline(1)	
			if(ord(x) == 4): break #break if end character
			string += x
		
	if(string.find(".") != -1): 
		print string.replace(" ", "")
	string = ''
	


	
	
	
	
	