import pygame
import random
import math

import numpy as np

class Environment:
  def __init__(self, fps: int) -> None:
    self.fps = fps

    self.width = 1200
    self.height = 800

    pygame.init()

    self.window = pygame.display.set_mode((self.width, self.height))

    pygame.display.set_caption("Vetorial Camp Simulator")

    self.robot = Robot(30, 50, 50)

  
  def draw_the_window(self) -> None:
    self.window.fill((0, 0, 0))
    self.robot.draw(self.window)
    pygame.display.update()


  def execute(self) -> None:
    window_is_open = True

    while window_is_open:
      for event in pygame.event.get():
        if event.type == pygame.QUIT:
          window_is_open = False

      if pygame.mouse.get_pressed()[0]:
        goal = np.array(pygame.mouse.get_pos())

        while np.linalg.norm(goal-self.robot.pos) > 2:
          fatt = 0.05*(goal - self.robot.pos)

          self.robot.move(fatt)

          self.draw_the_window()
          pygame.time.delay(int(1000 / self.fps))

      pygame.time.delay(100)

      self.draw_the_window()

class Robot:
  def __init__(self, radius: float, x_pos: int = 0, y_pos: int = 0) -> None:
    self.radius = radius
    self.pos = np.array([x_pos, y_pos])

    self.color = (30, 200, 30)


  def draw(self, window: pygame.Surface):
    pygame.draw.circle(window, self.color, (self.pos[0], self.pos[1]), self.radius)
    

  def move(self, vec: np.ndarray):
    self.pos = np.add(self.pos, vec)

if __name__ == "__main__":
  Environment(300).execute()
