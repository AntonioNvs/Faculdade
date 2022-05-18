import random
import pygame

class Environment:
    # This constants needed to be negatives
    INIT_PIXEL = -2
    FINAL_PIXEL = -3
    OBSTACLE_PIXEL = -4

    def __init__(self, m: int, n: int) -> None:
        self.m = m
        self.n = n

        self.width = 960
        self.height = 960

        pygame.init()

        self.pixels = [[-1 for i in range(self.m)] for j in range(self.n)]

        self.font = pygame.font.SysFont('Arial', 12)
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
            self.OBSTACLE_PIXEL: (34, 65, 254)
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

        self.update_wavefront()

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

            if i == j:
                options.append((i-1, j-1))

            for nx, ny in options:
                if nx >= 0 and ny >= 0 and nx < self.m and ny < self.n and self.pixels[nx][ny] == -1:
                    self.pixels[nx][ny] = v
                    queue.append((nx, ny, v+1))

            self.drawing_the_screen()
            pygame.time.delay(70)

if __name__ == "__main__":
    # Works just on square enviroments
    env = Environment(30, 30)
    env.main(120)
