import random
import pygame
import math

from copy import deepcopy

class Environment:
    # This constants needed to be negatives
    INIT_PIXEL = -2
    FINAL_PIXEL = -3
    OBSTACLE_PIXEL = -4
    PATH_PIXEL = -5

    def __init__(self, m: int, n: int) -> None:
        self.m = m
        self.n = n

        self.width = 1200
        self.height = 1200

        pygame.init()

        self.pixels = [[-1 for i in range(self.m)] for j in range(self.n)]

        self.font = pygame.font.SysFont('Arial', 10)
        self.window = pygame.display.set_mode((self.width, self.height))
        
        pygame.display.set_caption("Wave Front Planner Simulation")

        self.inital_pos = (0, 0)
        self.final_pos = (self.m-1, self.n-1)

        self.pixels[0][0] = self.INIT_PIXEL
        self.pixels[self.m-1][self.n-1] = self.FINAL_PIXEL


    def create_random_obstacles(self, n_ob) -> None:
        assert n_ob > 0 and n_ob < self.m*self.n/1.5

        for _ in range(n_ob):
            while True:
                x = random.randint(0, self.m-1)
                y = random.randint(0, self.n-1)

                if self.pixels[x][y] == -1:
                    self.pixels[x][y] = self.OBSTACLE_PIXEL
                    break        


    def drawing_the_screen(self) -> None:
        self.window.fill((0, 0, 0))
        
        ratio_w = self.width / self.m
        ratio_h = self.height / self.n

        colors = {
            self.INIT_PIXEL: (255, 10, 10),
            self.FINAL_PIXEL: (50, 200, 50),
            self.OBSTACLE_PIXEL: (34, 65, 254),
            self.PATH_PIXEL: (230, 230, 0)
        }

        for i in range(self.m):
            for j in range(self.n):
                rect = pygame.Rect(
                        i*ratio_w,
                        j*ratio_h,
                        ratio_w,
                        ratio_h
                    )

                if self.pixels[i][j] in colors.keys():
                    pygame.draw.rect(self.window, colors[self.pixels[i][j]], rect)
                else:
                    text = self.font.render(str(self.pixels[i][j]), False, (255, 255, 255))
                    new_rect = text.get_rect(center=rect.center)

                    self.window.blit(text, new_rect)
        
        pygame.display.update()

                    
    def main(self, n_ob) -> None:        
        self.create_random_obstacles(n_ob)

        pygame.time.delay(10000)

        self.update_wavefront()
        self.define_way()

        window_is_open = True

        while window_is_open:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    window_is_open = False
            

    def update_wavefront(self) -> None:
        x, y = self.final_pos

        queue = []

        queue.append((x, y, 0))

        while queue:
            i, j, v = queue.pop(0)                

            options = [(i-1, j), (i, j-1), (i+1, j), (i, j+1)]


            for nx, ny in options:
                if nx >= 0 and ny >= 0 and nx < self.m and ny < self.n and self.pixels[nx][ny] == -1:
                    self.pixels[nx][ny] = v
                    queue.append((nx, ny, v+1))

            self.drawing_the_screen()
            pygame.time.delay(2)


    def define_way(self) -> None:
        x, y = self.inital_pos

        queue = []

        queue.append((x, y, []))
        
        self.pixels[x][y] = math.inf

        self.visiteds = [[0 for i in range(self.n)] for j in range(self.m)]

        self.visiteds[x][y] = 1
        define_path = []

        while queue:
            i, j, path = queue.pop(0)

            if i == self.final_pos[0] and j == self.final_pos[1]:
                define_path = path
                define_path.pop()
                break

            path = deepcopy(path)

            options = [(i-1, j), (i, j-1), (i+1, j), (i, j+1)]

            for nx, ny in options:
                if nx >= 0 and ny >= 0 and nx < self.m and ny < self.n and self.pixels[nx][ny] < self.pixels[i][j] and self.visiteds[nx][ny] == 0:
                    self.visiteds[nx][ny] = 1
                    queue.append((nx, ny, path + [(nx, ny)]))

        self.pixels[x][y] = self.INIT_PIXEL

        if not define_path:
            print("Doesn't exist a path for this configuration")

        for x, y in define_path:
            self.pixels[x][y] = self.PATH_PIXEL
            self.drawing_the_screen()
            pygame.time.delay(80)


if __name__ == "__main__":
    # Works just on square enviroments
    env = Environment(50, 50)
    env.main(450)
