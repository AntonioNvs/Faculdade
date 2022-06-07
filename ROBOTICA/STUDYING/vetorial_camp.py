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

    # Create obstacules
    self.obstacules = [
      # Obstacule(10, 560, 720)
      # Obstacule(60, 800, 100),
      # Obstacule(50, 1100, 400),
      Obstacule(90, 300, 400),
    ]

  
  def draw_the_window(self) -> None:
    self.window.fill((0, 0, 0))

    self.robot.draw(self.window)

    for obstacule in self.obstacules:
      obstacule.draw(self.window)

    pygame.display.update()


  def execute(self) -> None:
    window_is_open = True

    while window_is_open:
      for event in pygame.event.get():
        if event.type == pygame.QUIT:
          window_is_open = False

      if pygame.mouse.get_pressed()[0]:
        goal = np.array(pygame.mouse.get_pos())

        while np.linalg.norm(goal-self.robot.pos) > 1.0:
          fatt = 0.05*(goal - self.robot.pos)

          # Calculte the repulsion force
          frep = 0
          y = 2
          min_distance = 100
          krep = 0.1

          for obstacule in self.obstacules:
            dot = obstacule.dot_more_close(self.robot)
            
            if obstacule.minimum_distance_from_the_robot(self.robot) > min_distance:
              continue
            
            dist = abs(goal - dot)
            frep += krep*((100/dist - 100/min_distance)**y)/y

          print(frep)
          self.robot.move(fatt + frep)

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


class Obstacule:
  def __init__(self, radius: float, x_pos: int, y_pos: int) -> None:
    self.radius = radius
    self.pos = np.array([x_pos, y_pos])

    self.color = (200, 100, 0)


  def draw(self, window: pygame.Surface) -> None:
    pygame.draw.circle(window, self.color, (self.pos[0], self.pos[1]), self.radius)

  def minimum_distance_from_the_robot(self, robot: Robot) -> float:
    distance = np.linalg.norm(self.pos-robot.pos)

    return distance - self.radius - robot.radius

  def dot_more_close(self, robot: Robot) -> float:
    hip = np.linalg.norm(self.pos-robot.pos)

    costeta = (self.pos[0] - robot.pos[0]) / hip
    senbeta = (self.pos[1] - robot.pos[1]) / hip
    
    x = self.pos[0] - self.radius*costeta
    y = self.pos[1] - self.radius*senbeta

    return np.array([x, y])



if __name__ == "__main__":
  Environment(40).execute()
