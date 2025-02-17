import random
words = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+" # 80 characters

words = list(words)
random.shuffle(words) # TypeError: 'str' object does not support item assignment
password = "".join(words[:15])
print(password) # AttributeError: 'list' object has no attribute 'join'