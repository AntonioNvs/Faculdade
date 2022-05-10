import os

from time import sleep
from random import choice
from scraping import Scraping
from factors import ControllFactors
from words import read_all_selecteds_words


def termooo():
    all_words = read_all_selecteds_words()

    attemps = 6
    page = Scraping(1)
    controller = ControllFactors()

    word_attempt = "ROSEA"
    already_try = []

    for i in range(attemps):
        while True:
            result = page.writing(word_attempt)

            if result == "wne":
                word_attempt = choice(selected_words)
                all_words.remove(word_attempt)
                continue                
            break

        if result == "f":
            print(f"The show is over! The keyword was: {word_attempt}")
            break

        factors = page.get_information()[0]

        for factor in factors:
            controller.add(factor)
        
        selected_words = controller.search_based_on_info(all_words)
        
        [print(fact) for fact in controller.info]
        sleep(3)
        os.system("clear")

        while True:
            word_attempt = choice(selected_words)
            if word_attempt not in already_try:
                already_try.append(word_attempt)
                break

    
    page.driver.quit()


def duetoo_or_quartetoo(attemps, n_boards, n_controllers):
    all_words = read_all_selecteds_words()

    page = Scraping(n_controllers)

    controllers = [ControllFactors() for _ in range(n_controllers)]

    word_attempt = "ROSEA"
    already_try = []

    for i in range(attemps):
        already_try.append(word_attempt)

        result = page.writing(word_attempt)

        if result == "wne":
            word_attempt = choice(selected_words)
            all_words.remove(word_attempt)
            i -= 1
            continue
        elif result == "f":
            print(f"The show is over! The keyword was: {word_attempt}")
            break

        os.system("clear")

        boards = page.get_information()
        word_attempt = ""

        all_selecteds_words = []
        for i, factors in enumerate(boards):
            for factor in factors:
                controllers[i].add(factor)
            
            if controllers[i].know:
                continue

            selected_words = controllers[i].search_based_on_info(all_words)
            
            if len(selected_words) == 1:
                word_attempt = selected_words[0]
                break

            all_selecteds_words += selected_words
        
        if word_attempt == "":
            maxi = {"pontuation": -1, "word": ""}

            for word in all_selecteds_words:
                pontuation = 0
                for c in word:
                    for controller in controllers:
                        if c not in controller.caracters and not controller.know:
                            pontuation += 1
                
                if pontuation > maxi["pontuation"] and word not in already_try:
                    print(pontuation, word)
                    maxi = {"pontuation": pontuation, "word": word}
            
            word_attempt = maxi["word"]
    
    page.driver.quit()



if __name__ == "__main__":
    termooo()
    sleep(1)

    duetoo_or_quartetoo(7, 2, 2)
    sleep(1)

    duetoo_or_quartetoo(9, 4, 4)

    print("I SOLVE ALL HAHAHAH")