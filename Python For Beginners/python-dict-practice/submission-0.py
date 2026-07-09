from typing import Dict # this adds type hinting for Dict

def count_characters(word: str) -> Dict[str, int]:
    d = {}
    for c in word:
        if c in d:
            d[c]+=1
        else:
            d[c] = 1
    return d




# don't modify below this line
print(count_characters("hello"))
print(count_characters("world"))
print(count_characters("hello world"))
print(count_characters("this is a longer sentence"))
