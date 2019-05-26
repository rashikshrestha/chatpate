from tkinter import *

root = Tk()
root.title('Chatpate Prototype Tester')
root.iconbitmap(r'aayam icon.ico')
root.geometry('640x480')

logo = PhotoImage(file='aayaam tech small.png')
logo_label = Label(root, image=logo)

def function_name(event):
    print('My name is Rashik')

b = Button(root, text='Press to Print :p')
b.bind('<Button-1>', function_name)


logo_label.pack()
b.pack()

root.mainloop()