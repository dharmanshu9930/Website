for password in range(1):
    import random

    lower = "abcdefghijklmnopqrstuvwxyz"
    upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    numbers = "0123456789"
    take = lower + upper + numbers
    length = 7
    password = "".join(random.sample(take, length))
    print("your capcha is :", password)
    
