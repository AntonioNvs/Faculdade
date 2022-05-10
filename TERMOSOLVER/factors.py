from typing import List

class ControllFactors:
    def __init__(self) -> None:
        self.info = []
        self.caracters = set()

        self.know = False

    def add(self, factor) -> None:
        if not self.factor_already_exists(factor):
            self.info.append(factor)
            self.caracters.add(factor.c)

        n_pos = 0
        # Remove the problem of not have two or more of the same letter on the word
        for fact1 in self.info:
            for fact2 in self.info:
                if isinstance(fact1, SameCaracterButAnotherPosition) and isinstance(fact2, DontHaveThatLetter):
                    if fact1.c == fact2.c:
                        self.info.remove(fact2)
                if isinstance(fact1, SameCaracterOnSamePosition) and isinstance(fact2, DontHaveThatLetter):
                    if fact1.c == fact2.c:
                        self.info.remove(fact2)

            if isinstance(fact1, SameCaracterOnSamePosition):
                n_pos += 1
        
        if n_pos == 5:
            self.know = True

    def search_based_on_info(self, words: List[str]) -> List[str]:
        selecteds = []

        for word in words:
            if all([factor.search(word) for factor in self.info]):
                selecteds.append(word)

        return selecteds
        

    def factor_already_exists(self, new) -> bool:
        return any([factor.is_the_same(new) for factor in self.info])

            
class SameCaracterOnSamePosition:
    def __init__(self, c: str, pos: int) -> None:
        self.c = c
        self.pos = pos

    def __repr__(self) -> str:
        return f"Have the {self.c} letter on this {self.pos} position."

    def search(self, word: str) -> bool:
        return word[self.pos] == self.c

    def is_the_same(self, new) -> bool:
        if not isinstance(new, SameCaracterOnSamePosition):
            return False
        return new.c == self.c and new.pos == self.pos


class SameCaracterButAnotherPosition:
    def __init__(self, c: str, pos: int) -> None:
        self.c = c
        self.pos = pos

    def __repr__(self) -> str:
        return f"Have the {self.c} letter but on different position of {self.pos}"

    def search(self, word: str) -> bool:
        return self.c in word and word[self.pos] != self.c

    def is_the_same(self, new) -> bool:
        if not isinstance(new, SameCaracterButAnotherPosition):
            return False
        return new.c == self.c and new.pos == self.pos


class DontHaveThatLetter:
    def __init__(self, c: str) -> None:
        self.c = c

    def __repr__(self) -> str:
        return f"Don't have the {self.c} letter."

    def search(self, word: str) -> bool:
        return self.c not in word

    def is_the_same(self, new) -> bool:
        if not isinstance(new, DontHaveThatLetter):
            return False
        return new.c == self.c