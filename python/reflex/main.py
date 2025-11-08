import random
import pyperclip

GROUP_SIZE = 20
MAX_VALUE = 10
MIN_VALUE = 1
ONLY_PLUS = True

def make_addition():
    a = random.randint(MIN_VALUE, MAX_VALUE)
    b = MAX_VALUE - a
    if b > MIN_VALUE:
        b = random.randint(MIN_VALUE, b)
  
    a_str = f" {a}" if a < 10 else str(a)
    b_str = f" {b}" if b < 10 else str(b)
    return f"{a_str} + {b_str} ="

def make_subtraction():
    a = random.randint(MIN_VALUE, MAX_VALUE)
    b = random.randint(MIN_VALUE, MAX_VALUE)
    a, b = max(a, b), min(a, b)
    a_str = f" {a}" if a < 10 else str(a)
    b_str = f" {b}" if b < 10 else str(b)
    return f"{a_str} - {b_str} ="

def make_unique_expressions(group_size):
    expressions = []    #I know O^2
    while len(expressions) < group_size:
        if ONLY_PLUS:
            expr = make_addition()
        else:
            #value_if_true if condition else value_if_false
            expr = make_addition() if len(expressions) % 2 == 0 else make_subtraction()
        if expr not in expressions:
            expressions.append(expr)
    return expressions

if __name__ == "__main__":
    text = ""
    for expression in make_unique_expressions(GROUP_SIZE):
        text += expression
        text += '\n'
        print(expression)
    
    pyperclip.copy(text)
    print("expressions copied to clipboard")
