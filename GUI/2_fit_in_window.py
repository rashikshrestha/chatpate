from tkinter import *

root = Tk()

l1 = Label(root,text="hehehaha",bg='red')
l2 = Label(root,text="k vayo oiii",bg='green')
l3 = Label(root,text="yestai xa zindagi",bg='blue')

l1.pack(fill=X)
l2.pack(side=LEFT,fill=Y)
l3.pack()

root.mainloop()