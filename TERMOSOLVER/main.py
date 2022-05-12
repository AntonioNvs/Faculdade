import os

from time import sleep
from random import choice
from scraping import Scraping
from selenium import webdriver
from factors import ControllFactors
from words import read_all_selecteds_words


def termooo(driver):
    all_words = read_all_selecteds_words()

    attemps = 6
    page = Scraping(driver, 1)
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

        os.system("clear")

        factors = page.get_information()[0]

        for factor in factors:
            controller.add(factor)
        
        selected_words = controller.search_based_on_info(all_words)
        
        word_attempt = ""

        if controller.n_letters_knowed == 4 and len(selected_words) > 1 and attemps-1 > i:
            what_pos = -1
            for i in range(5):
                if selected_words[0][i] != selected_words[1][i]:
                    what_pos = i
                    break

            unfound_letters = [word[what_pos] for word in selected_words]
            print(unfound_letters)

            maxi = {"pontuation": -1, "word": ""}
            for word in all_words:
                count = sum([1 if letter in word else 0 for letter in unfound_letters])

                if count > maxi["pontuation"]:
                    maxi["pontuation"] = count
                    maxi["word"] = word
            
            word_attempt = maxi["word"]

        if word_attempt == "":
            while True:
                word_attempt = choice(selected_words)
                if word_attempt not in already_try:
                    already_try.append(word_attempt)
                    break


def duetoo_or_quartetoo(attemps, n_boards, n_controllers, driver):
    all_words = read_all_selecteds_words()

    page = Scraping(driver, n_controllers)

    controllers = [ControllFactors() for _ in range(n_controllers)]

    word_attempt = "ROSEA"
    already_try = []

    for i in range(attemps):
        already_try.append(word_attempt)

        while True:
            result = page.writing(word_attempt)
        
            if result == "wne":
                word_attempt = choice(good_words)
                all_words.remove(word_attempt)
                continue
            break

        if result == "f":
            print(f"The show is over! The keyword was: {word_attempt}")

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
            good_words = [("", -1)]

            for word in all_selecteds_words:
                pontuation = 0
                for c in word:
                    for controller in controllers:
                        if c not in controller.caracters and not controller.know:
                            pontuation += 1
                
                if pontuation > good_words[-1][1] and word not in already_try:
                    good_words.append((word, pontuation))
            
            word_attempt = good_words[-1][0]



if __name__ == "__main__":
    driver = webdriver.Firefox(executable_path="./drivers/geckodriver")

    termooo(driver)
    sleep(1)

    duetoo_or_quartetoo(7, 2, 2, driver)
    sleep(1)

    duetoo_or_quartetoo(9, 4, 4, driver)

    driver.quit()
    print("I SOLVE ALL HAHAHAH")