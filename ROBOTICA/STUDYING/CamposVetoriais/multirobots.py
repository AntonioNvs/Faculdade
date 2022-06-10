import pygame
import random
import math
import numpy as np

class Environment:
  def __init__(self) -> None:
    self.width = 1200
    self.height = 800

    pygame.init()

    self.window = pygame.display.set_mode((self.width, self.height))

    pygame.display.set_caption("Vetorial Camp Simulator")

    self.robot_radius = 10

    self.robots = [
      Robot(self.robot_radius, 50, 50),
      Robot(self.robot_radius, 80, 80),
      Robot(self.robot_radius, 15, 30),
      # Robot(self.robot_radius, 80, 80),
      # Robot(self.robot_radius, 80, 80),
      Robot(self.robot_radius, 140, 600)
    ]

    # Create obstacules
    self.obstacules = [
      Obstacule(10, 560, 720),
      Obstacule(60, 800, 100),
      Obstacule(50, 900, 400),
      Obstacule(90, 300, 400),
    ]

  
  def draw_the_window(self) -> None:
    self.window.fill((0, 0, 0))

    for obstacule in self.obstacules:
      obstacule.draw(self.window)

    for robot in self.robots:
      robot.draw(self.window)

    pygame.display.update()


  def normalize_force(self, f):
    limit = 10

    modl = np.linalg.norm(f)
    if modl > limit:
      f *= (limit/modl)

    return f


  def sum_of_distance_of_all_robots(self, goal) -> int:
    dist = 0
    for robot in self.robots:
      dist += np.linalg.norm(goal-robot.pos)

    return dist


  def execute(self) -> None:
    window_is_open = True

    while window_is_open:
      for event in pygame.event.get():
        if event.type == pygame.QUIT:
          window_is_open = False

      if pygame.mouse.get_pressed()[0]:
        # Get the mouse position for define the goal
        goal = np.array(pygame.mouse.get_pos())

        # Until the distance is more than one pixel, the robot will move
        while self.sum_of_distance_of_all_robots(goal) > self.robot_radius*(len(self.robots) + 10):
          for robot in self.robots:
            # Calculate the attraction force.
            fatt = 0.5*(goal - robot.pos)

            # Calculte the repulsion force
            frep = np.array([0.0, 0.0])
            y = 2
            min_distance = 40
            krep = 5*10e4

            for obstacule in self.obstacules + self.robots:
              if obstacule == robot:
                continue

              dot_obs = obstacule.dot_more_close(robot)
              dot_robot = robot.dot_more_close(obstacule)

              # If the distance from the obstacule is less than the minimum, the obstacule will be ignored.
              if obstacule.minimum_distance_from_the_robot(robot) > min_distance:
                continue
              
              # Calculating the derivation of the repulsion potential
              dist = np.linalg.norm(dot_robot - dot_obs)
              frep += (krep / (dist**2)) *((1/dist - 1/min_distance)**(y-1)) * ((dot_robot-dot_obs)/dist)

            # Normalize the forces
            frep_norm = self.normalize_force(frep)
            fatt_norm = self.normalize_force(fatt)

            force = self.normalize_force(frep_norm + fatt_norm)
            
            # Make the robot move
            robot.move(force)

          self.draw_the_window()
          pygame.time.delay(50)

      pygame.time.delay(100)

      self.draw_the_window()


class Robot:
  def __init__(self, radius: float, x_pos: int = 0, y_pos: int = 0) -> None:
    self.radius = radius
    self.pos = np.array([x_pos, y_pos])

    self.color = (30, 200, 30)


  def draw(self, window: pygame.Surface):
    pygame.draw.circle(window, self.color, (self.pos[0], self.pos[1]), self.radius)
  

  def minimum_distance_from_the_robot(self, robot) -> float:
    distance = np.linalg.norm(self.pos-robot.pos)

    return distance - self.radius - robot.radius


  def dot_more_close(self, obstacule) -> float:
    """
      With trigonometry, define the close dot from the obstacule.
    """

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
    """
      With trigonometry, define the close dot from the robot.
    """

    hip = np.linalg.norm(self.pos-robot.pos)

    costeta = (self.pos[0] - robot.pos[0]) / hip
    senbeta = (self.pos[1] - robot.pos[1]) / hip
    
    x = self.pos[0] - self.radius*costeta
    y = self.pos[1] - self.radius*senbeta

    return np.array([x, y])



if __name__ == "__main__":
  Environment().execute()