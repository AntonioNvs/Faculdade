import pygame
import random
import math

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

    # Pixels per second
    velocity = 200

    while window_is_open:
      for event in pygame.event.get():
        if event.type == pygame.QUIT:
          window_is_open = False

      x_steps = random.randint(-self.width/2, self.width/2)
      y_steps = random.randint(-self.width/2, self.height/2)

      # Euclidian distance
      distance = math.sqrt(x_steps**2 + y_steps**2)

      frames = int((distance/velocity) * self.fps)

      if self.robot.x + x_steps < 2*self.robot.radius: continue
      if self.robot.y + y_steps < 2*self.robot.radius: continue
      if self.robot.x + x_steps > self.width - 2*self.robot.radius: continue
      if self.robot.y + y_steps > self.height - 2*self.robot.radius: continue

      for step in range(frames):
        self.robot.move(x_steps/frames, y_steps/frames, self.width, self.height)

        self.draw_the_window()

        pygame.time.delay(int((distance*1000) / (velocity*frames)))

      pygame.time.delay(500)


class Robot:
  def __init__(self, radius: float, x_pos: int = 0, y_pos: int = 0) -> None:
    self.radius = radius
    self.x = x_pos
    self.y = y_pos

    self.color = (30, 200, 30)


  def draw(self, window: pygame.Surface):
    pygame.draw.circle(window, self.color, (self.x, self.y), self.radius)
    

  def move(self, x_steps: int, y_steps: int, max_width: int, max_height: int):
    self.x += x_steps
    self.y += y_steps
  

if __name__ == "__main__":
  Environment(30).execute()