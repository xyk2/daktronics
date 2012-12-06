import serial
import string
import re

ser = serial.Serial("COM18", 19200, timeout=1) 

x = "n"
string = ''

"""
while True:
	x = ser.readline(1)
	#if(x == " "): x = "#"
	#if(ord(x) == 22 or ord(x) == 23 or ord(x) == 1 or ord(x) == 4): x = '.'
	
	string += x
	
	#print x,
	#print ord(x)
	if(ord(x) == 2): 
		print string
		#print re.split("/W+", string)
		#print str(string).split(".")
		#print
		f.write(string, '\n')
		string = ''
		
		
empty_buff = ''
"""
def print_spaces(number_spaces, text):
	spaces = number_spaces - len(text)
	print " " * spaces,
	print text
	
	
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
		
	string = string.strip() #remove leading and trailing whitespace
	string = string.split(' ') #convert to space-separated list
	string = filter(lambda name: name.strip(), string)
	print len(string)
	if(len(string) > 3): #exclude running time
		print string
		string = filter(lambda name: name.strip(), string) #filter out all elements with only whitespace
		print_spaces(10, string[0])
		print_spaces(10, string[1])
		print_spaces(10, string[2])
		print_spaces(10, string[3])
		print
	
	string = ''
	
	
	
	
	
	

	
	
	
	
	
		
