class Dial:
    def __init__(self, x : int):
        self.num = x

    def __iadd__(self, x):
        self.num += x
        self.normalize()
        return self
    
    def __isub__(self, x):
        self.num -= x
        self.normalize()
        return self
    
    def normalize(self):
        while self.num < 0:
            self.num += 100
        while self.num > 99:
            self.num -= 100

dial = Dial(50)
zero_count = 0

with open("input.txt", 'r') as f:
    for i in f:
        # We remove direction character and newline character
        n = int(i[1:-1])
        if i[0] == 'L':
            dial += n
        if i[0] == 'R':
            dial -= n
        if dial.num == 0:
            zero_count += 1

print(zero_count)