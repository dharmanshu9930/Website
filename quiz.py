import json, random

# Opening JSON file
f = open('Hacktoberfest_festdharmanshu9930/quizzes.json')
# returns JSON object as a dictionary
data = json.load(f)
# Closing file
f.close()

def soal():
    x = random.randint(0, len(data))
    print(data[x]['question'])
    print(data[x]['options'])
    jawab = input('Answer: ')
    if jawab == data[x]['answer']:
        print('Correct')
    else:
        print('Wrong')
    tanya = input('Play again (y/n)? ').lower()
    if tanya == 'y':
        soal()

soal()