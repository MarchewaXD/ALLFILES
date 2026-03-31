import pygame
from pygame.locals import *
pygame.init()

bg_color = (0,0,0)
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption('Simple math equations')
screen.fill(bg_color)
pygame.display.flip()
running = True
while running:
    for event in pygame.event.get():
        pygame.draw.rect(screen, (20,20,20),
                         [200,200,400,200], 0)
        pygame.draw.rect(screen, (200,200,200),
                         pygame.rect(30,30,60,60), 2, 0, 0, 3)
        pygame.display.update()
        if event.type == pygame.QUIT:
            running = false