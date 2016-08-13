import random
import sys

letters = "abcdefgh"

n = 5
print n

qt = 15
for i in range(qt):
    c = letters[random.randrange(0, len(letters))]
    sys.stdout.write(c)
print

print 0
