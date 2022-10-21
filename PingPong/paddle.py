from turtle import Turtle, Screen

class Paddle(Turtle):
    def __init__(self, postion):
        super().__init__()
        self.shape("square")
        self.shapesize(stretch_wid=5, stretch_len=1)
        self.color("white")
        self.penup()
        self.goto(postion)


    def go_up(self):
        new_y = self.ycor() + 20
        self.goto(self.xcor(), new_y)

    def go_down(self):
        new_x = self.ycor() - 20
        self.goto(self.xcor(), new_x)