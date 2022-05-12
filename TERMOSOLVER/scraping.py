import atexit

from time import sleep
from typing import List
from unidecode import unidecode

from selenium import webdriver
from selenium.webdriver.common.by import By
from bs4 import BeautifulSoup

from factors import SameCaracterOnSamePosition, SameCaracterButAnotherPosition, DontHaveThatLetter

class Scraping:
    def __init__(self, driver, n_boards: int) -> None:
        self.driver = driver

        atexit.register(self.driver.quit)

        self.driver.maximize_window()
        
        route_param = "" if n_boards == 1 else str(n_boards)

        self.driver.get(f"https://term.ooo/{route_param}")

        sleep(1)

        self.driver.find_element(By.TAG_NAME, "body").click()
        
        self.__get_all_buttons()

        self.boards = []
        for i in range(n_boards):
            self.boards.append(Board(self, i))

    def __get_all_buttons(self) -> None:
        buttons = self.driver.execute_script(
            """
        return document.querySelector('wc-kbd').shadowRoot.querySelectorAll('button')
            """
        )

        self.buttons = {}

        for button in buttons:
            self.buttons[button.text] = button


    def get_information(self) -> List[List]:
        info = []
        for board in self.boards:
            info.append(board.get_information_from_attempts())

        return info

    def writing(self, keyword: str) -> str:
        # Find all empty letters to write a keyword, for beggining

        assert len(keyword) == 5, "The initial keyword it has to be size 5."

        for c in keyword.upper():
            self.buttons[c].click()

        self.buttons["ENTER"].click()

        sleep(1)
        notify = self.driver.find_element(By.TAG_NAME, "wc-notify")

        if notify.text == "essa palavra não é aceita":
            for i in range(5):
                self.buttons[""].click()
            sleep(1)
            return "wne"
        else:
            sleep(4)
            
            if len(notify.text) > 0:
                return "f"
            else:
                return "c"


class Board:
    def __init__(self, scrap: Scraping, idx: int):
        self.idx = idx
        self.scrap = scrap
        self.current_row = 0

    
    def get_information_from_attempts(self) -> List[str]:
        letters = self.scrap.driver.execute_script(
            f"""
        return document.querySelectorAll('wc-board')[{self.idx}].shadowRoot.querySelectorAll('wc-row')[{self.current_row}].shadowRoot.querySelectorAll('div')
            """
        )
        
        factors = []

        for pos, letter in enumerate(letters):
            info = letter.get_attribute("class")
            caracter = unidecode(letter.text)

            if "place" in info:
                factors.append(SameCaracterButAnotherPosition(caracter, pos))
            elif "wrong" in info:
                factors.append(DontHaveThatLetter(caracter))
            elif "right" in info:
                factors.append(SameCaracterOnSamePosition(caracter, pos))
        
        self.current_row += 1

        return factors
if __name__ == "__main__":
    scrap = Scraping(1)
    
    sleep(1)

    scrap.writing("ROSEA")
    print(scrap.get_information())
    
    sleep(3)