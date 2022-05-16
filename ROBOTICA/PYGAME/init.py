import pygame
import random
import os

from typing import List

class Window:
    def __init__(self) -> None:
        pygame.init()
        
        self.width = 1280
        self.height = 780

        self.window = pygame.display.set_mode((self.width, self.height))
        
        pygame.display.set_caption("Robot Simulation")


    def __del__(self):
        pygame.quit()


    def generate_random_objects(self, n_obj: int) -> None:
        assert n_obj > 0

        min_max_wh = (30, 200)
        color = (30, 255, 100)

        objects = []

        for _ in range(n_obj):
            while True:
                w = random.randint(min_max_wh[0], min_max_wh[1])
                h = random.randint(min_max_wh[0], min_max_wh[1])

                x = random.randint(w, self.width - w)
                y = random.randint(h, self.height - h)

                new_obj = Object(x, y, w, h, color, self.window)

                all_not_colised = True

                for obj in objects:
                    if obj.rect.colliderect(new_obj.rect):
                        all_not_colised = False
                        break

                if all_not_colised:
                    break                

            objects.append(new_obj)

        return objects

"""

for(int i = 0; i < strlen(str); i+=3) {
    int x;

    if (str[i] == '0') {
        x = str[i+1] - '0';

    } else {
        int fd = str[i] - '0';
        int sd = str[i+1] - '0';

        x = fd*10 + sd;
    }

    if(str[i+2] == 'C')
        C[x]++;
    else if ...
}

"""
    def main(self) -> None:
        window_is_open = True
        delay = 50

        objects = self.generate_random_objects(10)

        self.robot = Robot(300, 300, 50, 50, 15, self.window, objects)

        while window_is_open:    
            os.system("clear")

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    window_is_open = False

            commands = pygame.key.get_pressed()

            self.window.fill((0, 0, 0))

            self.robot.action(objects)

            for obj in objects:
                obj.draw()

            pygame.display.update()
            pygame.time.delay(delay)


class Robot:
    def __init__(self, x: int, y: int, width: int, height: int, velocity: int, window, objects) -> None:
        self.x = x
        self.y = y
        self.width = width
        self.height = height

        self.velocity = velocity
        self.direction = "RIGHT"

        self.rect = pygame.Rect(self.x, self.y, self.width, self.height)

        self.w_window, self.h_window = pygame.display.get_surface().get_size()

        while self.colision(objects):
            

            self.x = random.randint(0, self.w_window-self.width)
            self.y = random.randint(0, self.h_window-self.height)

            self.rect = pygame.Rect(self.x, self.y, self.width, self.height)

        self.window = window
    

    def draw(self) -> None:
        pygame.draw.rect(self.window, (255, 10, 10), self.rect)
    

    def colision(self, objects) -> bool:
        for obj in objects:
            if obj.rect.colliderect(self.rect):
                return True
        
        return False


    def outside_window(self) -> bool:
        return self.x < 0 or self.x + self.width > self.w_window or self.y < 0 or self.y + self.height > self.h_window


    def turn_on(self) -> None:
        directions = ["UP", "DOWN", "RIGHT", "LEFT"]
        directions.remove(self.direction)

        self.direction = random.choice(directions)


    def action(self, objects) -> None:
        commands_action = {
            "UP": (self.x, self.y - self.velocity),
            "DOWN": (self.x, self.y + self.velocity),
            "RIGHT": (self.x + self.velocity, self.y),
            "LEFT": (self.x - self.velocity, self.y)
        }
        
        x_bef, y_bef = self.x, self.y

        self.x, self.y = commands_action[self.direction]
        
        self.rect = pygame.Rect(self.x, self.y, self.width, self.height)

        if self.colision(objects) or self.outside_window():
            self.x, self.y = x_bef, y_bef
            self.turn_on()

        self.rect = pygame.Rect(self.x, self.y, self.width, self.height)

        self.draw()



class Object:
    def __init__(self, x: int, y: int, width: int, height: int, color: tuple, window) -> None:
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        self.color = color

        self.rect = pygame.Rect(self.x, self.y, self.width, self.height)

        self.window = window

    def draw(self) -> None:
        pygame.draw.rect(self.window, self.color, self.rect)


if __name__ == "__main__":
    Window().main()