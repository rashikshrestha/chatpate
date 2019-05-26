from tkinter import *

root = Tk()
root.title('Chatpate Prototype Tester')
root.iconbitmap(r'aayam icon.ico')
root.geometry('640x480')

l1 = Label(root,text='Name')
l2 = Label(root,text='Password')
l3 = Label(root,text='test')

e1 = Entry(root)        #User input field
e2 = Entry(root)

cb = Checkbutton(root, text='Keep me logged in')
 
l1.grid(row=0,sticky=E)   #sticky sticks the widget to east, west, north, south of the grid box
l2.grid(row=1,sticky=E)

e1.grid(row=0,column=1)
e2.grid(row=1,column=1)

cb.grid(row=2,columnspan=2)  #keeps the widget in two columns




root.mainloop()