import atexit

from time import sleep
from typing import List
from unidecode import unidecode

from selenium import webdriver
from selenium.webdriver.common.by import By
from bs4 import BeautifulSoup

from factors import SameCaracterOnSamePosition, SameCaracterButAnotherPosition, DontHaveThatLetter

class Scraping:
    def __init__(self) -> None:
        self.driver = webdriver.Firefox(executable_path="./drivers/geckodriver")
        self.driver.maximize_window()
        
        self.driver.get("https://term.ooo/")

        sleep(1)

        self.driver.find_element(By.TAG_NAME, "body").click()
        
        self.__get_all_buttons()

        atexit.register(self.driver.quit)

        self.current_row = 0

    def __get_all_buttons(self) -> None:
        buttons = self.driver.execute_script(
            """
        return document.querySelector('wc-kbd').shadowRoot.querySelectorAll('button')
            """
        )

        self.buttons = {}

        for button in buttons:
            self.buttons[button.text] = button


    def get_information_from_attempts(self) -> List[str]:
        letters = self.driver.execute_script(
            f"""
        return document.querySelector('wc-board').shadowRoot.querySelectorAll('wc-row')[{self.current_row}].shadowRoot.querySelectorAll('div')
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

    def writing(self, keyword: str) -> str:
        # Find all empty letters to write a keyword, for beggining

        assert len(keyword) == 5, "The initial keyword it has to be size 5."

        for c in keyword:
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
            sleep(3)
            if notify.text != "":
                return "f"
            else:
                return "c"


if __name__ == "__main__":
    scrap = Scraping()
    
    sleep(1)

    scrap.writing("BAFOS")
    scrap.get_information_from_attempts()
    
    sleep(3)