import pygame
import sys
import serial
import string
import re
from datetime import datetime
ser = serial.Serial("COM18", 19200, timeout=1) 
x = "n"
string = ''

pygame.init()
#screen = pygame.display.set_mode((1024, 768), pygame.FULLSCREEN)
screen = pygame.display.set_mode((1024, 768))
pygame.display.set_caption('IASAS Swimming Running Time')
screen.fill((0, 255, 33))

# Create a font
font = pygame.font.Font(r"C:\Users\15107514\Desktop\arialbi.ttf", 32)

# Render the text
text = font.render('', True, (255,255, 255), (0, 255, 33))

# Create a rectangle
textRect = text.get_rect()

# Center the rectangle
textRect.bottomright = (500,500)

# Blit the text
screen.blit(text, textRect)
pygame.display.update()

b = pygame.sprite.Sprite() # create sprite
b.image = pygame.image.load(r"C:\Users\15107514\Desktop\time_overlay-01.png").convert_alpha() # load ball image
b.rect = b.image.get_rect() # use image extent values
b.rect.topleft = [0, 0] # put the ball in the top left corner

ser.flushInput()
while (ser.inWaiting()==0): #stall time
		print ser.inWaiting()
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				sys.exit()
		pygame.display.update()

num = 0
while True:
	screen.fill((0, 255, 33))	
	screen.blit(b.image, b.rect)

	# Start of time reading
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
			text = font.render(string, True, (0,0,0)) #antialias, full black
			textRect = text.get_rect()
			textRect.bottomright = (782,645)
			ser.flushInput() #clean out buffer
			print ser.inWaiting()
		
		string = ''
	# End of time reading
	
	screen.blit(text, textRect)

	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			sys.exit()
				
	pygame.display.update()


