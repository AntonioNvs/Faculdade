import os

from time import sleep
from random import choice
from scraping import Scraping
from factors import ControllFactors
from words import read_all_selecteds_words

all_words = read_all_selecteds_words()

attemps = 6
page = Scraping()
controller = ControllFactors()

word_attempt = "ROSEA"

for i in range(attemps):
    os.system("clear")
    result = page.writing(word_attempt)

    if result == "wne":
        word_attempt = choice(selected_words)
        i -= 1
        continue
    elif result == "f":
        print(f"The show is over! The keyword was: {word_attempt}")

    factors = page.get_information_from_attempts()

    for factor in factors:
        controller.add(factor)
    
    selected_words = controller.search_based_on_info(all_words)
    
    [print(fact) for fact in controller.info]

    word_attempt = choice(selected_words)