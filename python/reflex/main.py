import random
import pyperclip
import os
import subprocess
from reportlab.lib.pagesizes import letter
from reportlab.pdfgen import canvas
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.lib.utils import ImageReader

GROUP_SIZE = 20

def make_addition(min_val : int, max_val: int):
    a = random.randint(min_val, max_val)
    b = max_val - a
    if b > min_val:
        b = random.randint(min_val, b)
  
    a_str = f" {a}" if a < 10 else str(a)
    b_str = f" {b}" if b < 10 else str(b)
    return f"{a_str} + {b_str} ="

def make_subtraction(min_val : int, max_val: int):
    a = random.randint(min_val, max_val)
    b = random.randint(min_val, max_val)
    a, b = max(a, b), min(a, b)
    a_str = f" {a}" if a < 10 else str(a)
    b_str = f" {b}" if b < 10 else str(b)
    return f"{a_str} - {b_str} ="

def make_unique_expressions(group_size : int, min_val : int, max_val: int, onlyPlus:bool):
    expressions = []    #I know O^2
    while len(expressions) < group_size:
        if onlyPlus:
            expr = make_addition(min_val, max_val)
        else:
            #value_if_true if condition else value_if_false
            expr = make_addition(min_val, max_val) if len(expressions) % 2 == 0 else make_subtraction(min_val, max_val)
        if expr not in expressions:
            expressions.append(expr)
    return expressions

def make_page(c : canvas, logo : ImageReader, min_val : int, max_val: int, onlyPlus:bool):
    font_size = 20
    rows = GROUP_SIZE
    line_spacing = 12
    # w = 612 pt, h = 792 pt
    width, height = letter
    margin = 40

    col_width = (width - 2 * margin) / 3
    #col_height = height - 2 * margin

    # Page 1
    c.drawImage(logo, width / 2 - 16, height - margin, width=32, height=32, mask='auto')
    
    text = c.beginText()
    text.setFont("RobotoMono-Medium", font_size)

    for i in range(3):
        text.setTextOrigin(margin + col_width * i, height - margin - 32)

        for expression in make_unique_expressions(rows, min_val, max_val, onlyPlus):
            text.textLine(expression)
            text.moveCursor(0, line_spacing)
        c.drawText(text)
        text = c.beginText()

    line_height = font_size * 1.2  # or use font size * 1.2 if not set
    total_height = rows * line_height
    topY = height - margin - line_spacing
    c.line(margin + col_width -10, topY, 
           margin + col_width -10, topY - total_height- (rows - 1) * line_spacing)
    
    c.line(margin + col_width * 2 -10, topY, 
           margin + col_width * 2 -10, topY - total_height- (rows - 1) * line_spacing)


def make_pdf(fileName):
    
    path_to_font = os.path.dirname(__file__) + os.sep + 'RobotoMono-Medium.ttf'
    pdfmetrics.registerFont(TTFont('RobotoMono-Medium', path_to_font))
    

    c = canvas.Canvas(fileName, pagesize=letter)
    img = ImageReader(os.path.dirname(__file__) + os.sep + 'V.jpg')
    make_page(c, img, 1, 20, False)
    c.showPage()    # Starts a new page
    img = ImageReader(os.path.dirname(__file__) + os.sep + 'S.jpg')
    make_page(c, img, 1, 20, False)
    c.showPage()    # Starts a new page
    img = ImageReader(os.path.dirname(__file__) + os.sep + 'N.jpg')
    make_page(c, img, 1, 10, True)
    
    c.save()
    #os.system("start " + fileName)
    #subprocess.run(['open', fileName], check=True)
    #os.startfile(fileName)

if __name__ == "__main__":
    text = ""
    # for expression in make_unique_expressions(GROUP_SIZE):
    #     text += expression
    #     text += '\n'
    #     print(expression)
    
    # pyperclip.copy(text)
    # print("expressions copied to clipboard")
    make_pdf(os.path.dirname(__file__) + os.sep + "out.pdf")
