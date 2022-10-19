from turtle import Turtle

ALIGN = "center"
FONT = ("Courier", 25 , "normal")

class Scoreboard(Turtle):
    def __init__(self):
        super().__init__()
        self.l_score = 0
        self.r_score = 0
        self.color("white")
        self.penup()
        self.update_score()
        self.hideturtle()


    def update_score(self):
        self.goto(-150, 200)
        self.write(f"Score: {self.l_score}", align=ALIGN, font=FONT)
        self.goto(150, 200)
        self.write(f"Score: {self.r_score}", align=ALIGN, font=FONT)

    def l_point(self):
        self.l_score += 1
        self.clear()
        self.update_score()

    def r_point(self):
        self.r_score += 1
        self.clear()
        self.update_score()