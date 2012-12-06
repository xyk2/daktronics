import pygame
import sys
import serial
import string
import re

ser = serial.Serial("COM18", 19200, timeout=1) 
x = "n"
string = ''

LANE_ONE = ['', '', '', '', '', '', ''] 

pygame.init()
#screen = pygame.display.set_mode((1280, 1024), pygame.FULLSCREEN)
screen = pygame.display.set_mode((1000, 600))
pygame.display.set_caption('IASAS Swimming Running Time')
screen.fill((0, 255, 33))

# Create a font
font = pygame.font.Font(r"C:\Users\15107514\Desktop\arialbi.ttf", 40)

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
b.image = pygame.image.load(r"C:\Users\15107514\Desktop\swimming_timer_outer_small.png").convert_alpha() # load ball image
b.rect = b.image.get_rect() # use image extent values
b.rect.topleft = [100, 100] # put the ball in the top left corner



while True:
	screen.fill((0, 255, 33))	
	screen.blit(b.image, b.rect)
	
	
	while True: #stall time
		if(ser.readline(1) != ''):
			break
	
	x = ser.readline(1)
	if(ord(x) == 2): #if start char, enter loop until end
		while True:
			x = ser.readline(1)	
			if(ord(x) == 4): break #break if end character
			string += x
	string = string.strip() #remove leading and trailing whitespace
	string = string.split(' ') #convert to space-separated list
	string = filter(lambda name: name.strip(), string) #filter out all elements with only whitespace
	if(len(string) > 3): #exclude running time
		print string
		text = font.render( string[2], True, (0,0, 0))
		textRect = text.get_rect()
		textRect.bottomright = (500,500)
	string = ''

	screen.blit(text, textRect)

	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			sys.exit()
	pygame.display.update()



