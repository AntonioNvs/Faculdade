from typing import List
from unidecode import unidecode

def create_all_words_with_size_of_five():
    selecteds = []
    
    with open("files/dicionary.txt", "r") as src:
        words = src.read().split("\n")
        
        for word in words:
            if len(word) == 5:
                formatted_word = unidecode(word.upper())
                selecteds.append(formatted_word)

    with open("files/five-letters.txt", "w") as src:
        for word in selecteds[:-1]:
            src.write(word + "\n")
        src.write(word)


def read_all_selecteds_words() -> List[str]:
    with open("files/five-letters.txt", "r") as src:
        return src.read().split("\n")

if __name__ == "__main__":
    print(read_all_selecteds_words())