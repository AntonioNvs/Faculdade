import math
import pygame
import itertools
import numpy as np

class Environment:
  def __init__(self) -> None:
    self.width = 1200
    self.height = 800

    pygame.init()

    self.window = pygame.display.set_mode((self.width, self.height))

    pygame.display.set_caption("Vetorial Camp Simulator")

    self.f = Formation("circle", (120, 120), 10)

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

    for robot in self.f.robots + [self.f.center_robot]:
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
    for robot in self.f.robots:
      dist += np.linalg.norm(self.f.get_robot_goal(robot) - robot.pos)

    dist += np.linalg.norm(self.f.center_robot.pos - goal)
    print(dist)

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
        while self.sum_of_distance_of_all_robots(goal) >= 5:
          for robot in self.f.robots + [self.f.center_robot]:
            if robot == self.f.center_robot:
                katt = 0.3
                robot_goal = goal
            else:
                katt = 0.5
                robot_goal = self.f.get_robot_goal(robot)

            # Calculate the attraction force.
            fatt = katt*(robot_goal - robot.pos)

            # Calculte the repulsion force
            frep = np.array([0.0, 0.0])
            y = 2
            min_distance = 25
            krep = 4*10e4

            for obstacule in self.obstacules + self.f.robots + [self.f.center_robot]:
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
          pygame.time.delay(20)

      pygame.time.delay(100)

      self.draw_the_window()


class Formation:
  info = {
    "square": {
      "n_robots": 4,
      "side": 70
    },
    "circle": {
      "n_robots": 5,
      "side": 90
    }
  }

  def __init__(self, formation: str, center: tuple, robot_radius: int) -> None:
    self.formation = formation
    self.robot_radius = robot_radius

    assert self.robot_radius < 40, "The robot radius must to be less than fourty."

    self.center_robot = Robot(self.robot_radius, center[0], center[1], visible=False)

    x = center[0]
    y = center[1]
    self.side = self.info[self.formation]["side"]

    if formation == "square":
      side = (self.side/2) + 2*self.robot_radius
      
      self.robots = [
        Robot(self.robot_radius, x-side, y-side),
        Robot(self.robot_radius, x-side, y+side),
        Robot(self.robot_radius, x+side, y-side),
        Robot(self.robot_radius, x+side, y+side)
      ]
    
    if formation == "circle":
      ratio = self.side - 2*self.robot_radius
      
      self.robots = [
        Robot(self.robot_radius, x + ratio*math.cos(math.radians(90)), y + ratio*math.cos(math.radians(180))),
        Robot(self.robot_radius, x + ratio*math.cos(math.radians(162)), y + ratio*math.cos(math.radians(252))),
        Robot(self.robot_radius, x + ratio*math.cos(math.radians(252)), y + ratio*math.cos(math.radians(324))),
        Robot(self.robot_radius, x + ratio*math.cos(math.radians(324)), y + ratio*math.cos(math.radians(36))),
        Robot(self.robot_radius, x + ratio*math.cos(math.radians(36)), y + ratio*math.cos(math.radians(108)))
      ]


  def _get_the_coords_of_each_vertice(self):
    x, y = self.center_robot.pos

    if self.formation == "circle":
      ratio = self.side - 2*self.robot_radius

      coords = [
        (x + ratio*math.cos(math.radians(90)), y + ratio*math.cos(math.radians(180))),
        (x + ratio*math.cos(math.radians(162)), y + ratio*math.cos(math.radians(252))),
        (x + ratio*math.cos(math.radians(234)), y + ratio*math.cos(math.radians(324))),
        (x + ratio*math.cos(math.radians(306)), y + ratio*math.cos(math.radians(36))),
        (x + ratio*math.cos(math.radians(18)), y + ratio*math.cos(math.radians(108)))
      ]

    if self.formation == "square":
      size = (self.side/2) + 2*self.robot_radius

      coords = (
          (x-size, y-size),
          (x-size, y+size),
          (x+size, y-size),
          (x+size, y+size)
      )

    return coords


  def _get_distance_of_all_robots_to_your_vertices(self, combination):
    """
      Auxiliar function of '_get_the_best_combination', which is reponsable to
      calculate the distance of each robot to your respective vertice.
    """

    coords = self._get_the_coords_of_each_vertice()

    dist = 0
    for i, robot in enumerate(self.robots):
      dist += np.linalg.norm(robot.pos - coords[combination[i]])

    return dist
      
  def _get_the_best_combination(self) -> list:
    """
      Return the best combination of each robot for your vertice, 
      in other words, the minimum distance to each target
    """

    minimum_combination = [math.inf, []]

    permutations = list(itertools.permutations(list(range(0, self.info[self.formation]["n_robots"]))))

    for combination in permutations:
      dist = self._get_distance_of_all_robots_to_your_vertices(combination)
      if minimum_combination[0] > dist:
        minimum_combination[0] = dist
        minimum_combination[1] = combination

    return minimum_combination[1]


  def get_robot_goal(self, robot) -> np.ndarray:
    coords = self._get_the_coords_of_each_vertice()
    idx = self.robots.index(robot)
    combination = self._get_the_best_combination()
    
    return coords[combination.index(idx)]
    


class Robot:
  def __init__(self, radius: float, x_pos: int = 0, y_pos: int = 0, visible = True) -> None:
    self.radius = radius
    self.pos = np.array([x_pos, y_pos])

    self.color = (30, 200, 30)
    self.visible = visible


  def draw(self, window: pygame.Surface):
    if not self.visible:
      return

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