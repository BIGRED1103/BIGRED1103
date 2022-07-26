import tkinter as tk
import math
import json

from bezier import smoothing_base_bezier


class App(tk.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.pack()

        self.master.title("111")
        self.master.geometry("400x400+70+70")

        self.canvas = tk.Canvas(self.master,bg='#CDC9A5',height=400,width=400)
        self.canvas.pack()

        self.canvas.bind("<ButtonPress-1>", self.on_b1_press)
        self.canvas.bind("<B1-Motion>", self.on_b1_motion)
        self.canvas.bind("<ButtonRelease-1>", self.on_b1_release)

        self.idx = 0
        self.IDX_LEVEL = 5
        self.tra = list()
        self.tra_status = False

    def on_b1_press(self, event):
        self.tra.clear()
        print(event.x, event.y)
        self.tra_status = True
        self.tra.append((event.x, event.y))
        self.canvas.create_oval(event.x+2, event.y+2, event.x-2, event.y-2)

    def on_b1_motion(self, event):
        if self.tra_status:
            self.idx = (self.idx + 1) % self.IDX_LEVEL
            if self.idx == self.IDX_LEVEL - 1:
                print(event.x, event.y)
                self.tra.append((event.x, event.y))
                self.canvas.create_oval(event.x+2, event.y+2, event.x-2, event.y-2)

    def on_b1_release(self, event):
        print(event.x, event.y)
        self.tra_status = True
        self.tra.append((event.x, event.y))
        self.canvas.create_oval(event.x+2, event.y+2, event.x-2, event.y-2)
        x_list = [pt[0] for pt in self.tra]
        y_list = [pt[1] for pt in self.tra]

        new_list = []
        d = 0
        OFFSET = 30
        x_curve, y_curve = smoothing_base_bezier(x_list, y_list, k=0.6,inserted=20 ,closed=False)
        for idx, _ in enumerate(x_curve):
            if idx == 0:
                new_list.append((x_curve[idx], y_curve[idx]-OFFSET))
                continue

            dx = x_curve[idx] - x_curve[idx-1]
            dy = y_curve[idx] - y_curve[idx-1]
            d = d + math.sqrt(math.pow(dx, 2) + math.pow(dy, 2))
            if d >= 0.33 / 0.087 or idx == len(x_curve):
                new_list.append((x_curve[idx], y_curve[idx]-OFFSET))
                print(d)
                d = 0

        for pt in new_list:
            self.canvas.create_oval(pt[0]+2, pt[1]+2, pt[0]-2, pt[1]-2)

        with open("./a.json", "w+") as f:
            out = {"tra":new_list}
            f.write(json.dumps(out))

myapp = App(tk.Tk())
myapp.mainloop()