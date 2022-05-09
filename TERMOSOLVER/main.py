from random import choice
from scraping import Scraping
from factors import ControllFactors
from words import read_all_selecteds_words

all_words = read_all_selecteds_words()

attemps = 6
page = Scraping()
controller = ControllFactors()

word_attempt = "ALUNO"

for i in range(attemps):
    page.writing(word_attempt)

    factors = page.get_information_from_attempts()

    for factor in factors:
        controller.add(factor)
    
    selected_words = controller.search_based_on_info(all_words)

    word_attempt = choice(selected_words)