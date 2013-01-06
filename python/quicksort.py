string = ''
file = open(r"D:\Dropbox\capture_swim.txt")

while(True):
	character = file.read(1)
	
	if(ord(character) == 2):
		while(True):
			char = file.read(1)
			if(ord(char) == 4): 
				print string
				string = ''
				break
			string = string + char
			
