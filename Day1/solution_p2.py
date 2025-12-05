class Dial:
    def __init__(self, x : int):
        self.num = x
        self.previous = -1
        self.zero_count = 0

    def __iadd__(self, x):
        self.previous = self.num
        self.num += x
        self.normalize()
        return self
    
    def __isub__(self, x):
        self.previous = self.num
        self.num -= x
        self.normalize()
        return self
    
    def normalize(self):
        # Avoid double counting when starting from 0 and going right (negative)
        if self.num < 0 and self.previous == 0:
            self.zero_count -= 1
        
        while self.num < 0:
            self.num += 100
            self.zero_count += 1
        
        if self.num == 0: self.zero_count += 1 

        while self.num > 99:
            self.num -= 100
            self.zero_count += 1

dial = Dial(50)

with open("input.txt", 'r') as f:
    for i in f:
        # We remove direction character and newline character
        n = int(i[1:-1])
        if i[0] == 'L':
            dial += n
        if i[0] == 'R':
            dial -= n

print(dial.zero_count)