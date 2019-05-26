from tkinter import *

root = Tk()

topframe = Frame(root)
topframe.pack()

bottomframe = Frame(root)
bottomframe.pack()

b1 = Button(topframe, text='Button 1', fg='red')
b2 = Button(topframe, text='Button 2', fg='blue')
b3 = Button(topframe, text='^', fg='green')
b4 = Button(bottomframe, text='v', fg='purple')

b1.pack(side=RIGHT)               #Default side=TOP
b2.pack()
b3.pack(side=BOTTOM)
b4.pack()

root.mainloop()

