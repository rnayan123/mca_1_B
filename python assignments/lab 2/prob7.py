dict = {"num1": 4, "num2": 100, "num3": 2, "num4": 1}

sort = sorted(dict.items(), key = lambda x: x[1], reverse=True)

print(sort)