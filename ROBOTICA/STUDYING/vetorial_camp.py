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
      Obstacule(10, 560, 720),
      Obstacule(60, 800, 100),
      Obstacule(50, 900, 400),
      Obstacule(90, 300, 400),
    ]

  
  def draw_the_window(self, fatt, frep) -> None:
    self.window.fill((0, 0, 0))
    self.robot.draw(self.window)

    for obstacule in self.obstacules:
      obstacule.draw(self.window)

    x, y = self.robot.pos

    pygame.draw.line(self.window, (10, 10, 255), (x,y), (x+fatt[0],y+fatt[1]), width=2)
    pygame.draw.line(self.window, (255, 10, 10), (x,y), (x+frep[0],y+frep[1]), width=2)

    pygame.display.update()


  def normalize_force(self, force):
    limit = 10

    modl = np.linalg.norm(force)
    if modl > limit:
      force *= (limit/modl)

    return force


  def execute(self) -> None:
    window_is_open = True

    while window_is_open:
      for event in pygame.event.get():
        if event.type == pygame.QUIT:
          window_is_open = False

      if pygame.mouse.get_pressed()[0]:
        goal = np.array(pygame.mouse.get_pos())

        while np.linalg.norm(goal-self.robot.pos) > 1.0:
          fatt = 0.5*(goal - self.robot.pos)

          # Calculte the repulsion force
          frep = np.array([0.0, 0.0])
          y = 2
          min_distance = 160
          krep = 5*10e4

          for obstacule in self.obstacules:
            dot_obs = obstacule.dot_more_close(self.robot)
            dot_robot = self.robot.dot_more_close(obstacule)

            if obstacule.minimum_distance_from_the_robot(self.robot) > min_distance:
              continue

            dist = np.linalg.norm(dot_robot - dot_obs)
            frep += (krep / (dist**2)) *((1/dist - 1/min_distance)**(y-1)) * ((dot_robot-dot_obs)/dist)

          
          frep = self.normalize_force(frep)
          fatt = self.normalize_force(fatt)

          force = self.normalize_force(frep + fatt)
          
          self.robot.move(force)

          self.draw_the_window(fatt, frep)
          pygame.time.delay(50)

      pygame.time.delay(100)

      self.draw_the_window([0, 0], [0, 0])


class Robot:
  def __init__(self, radius: float, x_pos: int = 0, y_pos: int = 0) -> None:
    self.radius = radius
    self.pos = np.array([x_pos, y_pos])

    self.color = (30, 200, 30)


  def draw(self, window: pygame.Surface):
    pygame.draw.circle(window, self.color, (self.pos[0], self.pos[1]), self.radius)
  

  def dot_more_close(self, obstacule) -> float:
    hip = np.linalg.norm(self.pos-obstacule.pos)

    costeta = (self.pos[0] - obstacule.pos[0]) / hip
    senbeta = (self.pos[1] - obstacule.pos[1]) / hip
    
    x = self.pos[0] - self.radius*costeta
    y = self.pos[1] - self.radius*senbeta

    return np.array([x, y])


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
