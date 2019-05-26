from tkinter import *
import serial

w = 800
h = 600

delay_duration = 1
pwm = 100
motion = 2

rev1 = 1
div1 = 1
rev2 = 1
div2 = 1
rev3 = 1
div3 = 1
rev4 = 1
div4 = 1

root = Tk()
root.title('Chatpate Prototype Tester')
root.iconbitmap(r'aayam icon.ico')
root.geometry(str(w)+'x'+str(h))

def fn_delay_up(event):
    global delay_duration
    delay_duration += 1
    delay_duration_label.configure(text=str(delay_duration))

def fn_delay_down(event):
    global delay_duration
    delay_duration -= 1
    if delay_duration<0:
        delay_duration = 0
    delay_duration_label.configure(text=str(delay_duration))

def fn_pwm_up(event):
    global pwm
    pwm += 10
    if pwm > 250:
        pwm = 250
    pwm_label.configure(text=str(pwm))

def fn_pwm_down(event):
    global pwm
    pwm -= 10
    if pwm<0:
        pwm = 0
    pwm_label.configure(text=str(pwm))

def fn_motion_up(event):
    global motion
    motion += 1
    if motion > 4:
        motion = 4
    motion_label.configure(text=str(motion))

def fn_motion_down(event):
    global motion
    motion -= 1
    if motion < 1:
        motion = 1
    motion_label.configure(text=str(motion))

def fn_rev1_up(event):
    global rev1
    rev1 += 1
    rev1_label.configure(text=str(rev1))

def fn_rev1_down(event):
    global rev1
    rev1 -= 1
    if rev1 < 1:
        rev1 = 1
    rev1_label.configure(text=str(rev1))

def fn_rev2_up(event):
    global rev2
    rev2 += 1
    rev2_label.configure(text=str(rev2))

def fn_rev2_down(event):
    global rev2
    rev2 -= 1
    if rev2 < 1:
        rev2 = 1
    rev2_label.configure(text=str(rev2))

def fn_rev3_up(event):
    global rev3
    rev3 += 1
    rev3_label.configure(text=str(rev3))

def fn_rev3_down(event):
    global rev3
    rev3 -= 1
    if rev3 < 1:
        rev3 = 1
    rev3_label.configure(text=str(rev3))

def fn_rev4_up(event):
    global rev4
    rev4 += 1
    rev4_label.configure(text=str(rev4))

def fn_rev4_down(event):
    global rev4
    rev4 -= 1
    if rev4 < 1:
        rev4 = 1
    rev4_label.configure(text=str(rev4))

def fn_div1_up(event):
    global div1
    div1 += 1
    div1_label.configure(text=str(div1))

def fn_div1_down(event):
    global div1
    div1 -= 1
    if div1 < 1:
        div1 = 1
    div1_label.configure(text=str(div1))

def fn_div2_up(event):
    global div2
    div2 += 1
    div2_label.configure(text=str(div2))

def fn_div2_down(event):
    global div2
    div2 -= 1
    if div2 < 1:
        div2 = 1
    div2_label.configure(text=str(div2))

def fn_div3_up(event):
    global div3
    div3 += 1
    div3_label.configure(text=str(div3))

def fn_div3_down(event):
    global div3
    div3 -= 1
    if div3 < 1:
        div3 = 1
    div3_label.configure(text=str(div3))

def fn_div4_up(event):
    global div4
    div4 += 1
    div4_label.configure(text=str(div4))

def fn_div4_down(event):
    global div4
    div4 -= 1
    if div4 < 1:
        div4 = 1
    div4_label.configure(text=str(div4))

def start_it(event):
    pass

def stop_it(event):
    pass



f_A = Frame(root, pady=10)
f_A.pack()

f_B= Frame(root, pady=10)#, width = 400, height = 100)
f_B.pack()#side=RIGHT, expand = 1)

f_B1 = Frame(f_B)
f_B1.pack(side=LEFT)

f_B2 = Frame(f_B)
f_B2.pack(side=RIGHT)

f_B2_i = Frame(f_B2)
f_B2_i.pack(side=BOTTOM)

f_C= Frame(root, pady=10)#, width = 400, height = 100)
f_C.pack()#side=RIGHT, expand = 1)

f_C1= Frame(f_C)
f_C1.pack()

f_C2= Frame(f_C)
f_C2.pack()

f_D= Frame(root, pady=10)#, width = 400, height = 100)
f_D.pack()#side=RIGHT, expand = 1)

f_D1 = Frame(f_D) 
f_D1.pack(side=LEFT)

f_D1_i = Frame(f_D1)
f_D1_ii = Frame(f_D1)

f_D2 = Frame(f_D) 
f_D2.pack(side=LEFT)

f_D2_i = Frame(f_D2)
f_D2_ii = Frame(f_D2)

f_D3 = Frame(f_D) 
f_D3.pack(side=LEFT)

f_D3_i = Frame(f_D3)
f_D3_ii = Frame(f_D3)

f_D4 = Frame(f_D) 
f_D4.pack(side=LEFT)

f_D4_i = Frame(f_D4)
f_D4_ii = Frame(f_D4)

f_E = Frame(root,pady=30)
f_E.pack() 

f_F = Frame(root)
f_F.pack(side=BOTTOM) 

##############################################################################################

logo = PhotoImage(file='aayaam tech small.png')
Label(f_A, image=logo, pady=100).pack()

##############################################################################################

dirn = BooleanVar()
dirn.set(0)

Label(f_B1, text='Initial Direction', padx = 30).pack(anchor=W)

Radiobutton(f_B1, text="Direction 1", padx = 30, variable=dirn, value=0).pack(anchor=CENTER)
Radiobutton(f_B1, text="Direction 2", padx = 30, variable=dirn, value=1).pack(anchor=CENTER)

##############################################################################################

continuous_rev = BooleanVar()
continuous_rev.set(0)

Label(f_B2, text='Continuous Rotation', padx = 30).pack(anchor=CENTER)

Radiobutton(f_B2, text="ON", padx = 30, variable=continuous_rev, value=0).pack(anchor=CENTER)
Radiobutton(f_B2, text="OFF", padx = 30, variable=continuous_rev, value=1).pack(anchor=CENTER)

##############################################################################################

Label(f_B2_i, text='Delay Duration  ', padx = 20).pack(side=LEFT)

delay_up = Button(f_B2_i, text='^')
delay_up.bind('<Button-1>', fn_delay_up)
delay_up.pack(side=LEFT)

delay_duration_label = Label(f_B2_i, text=str(delay_duration), padx = 10)
delay_duration_label.pack(side=LEFT)

delay_down = Button(f_B2_i, text='v')
delay_down.bind('<Button-1>', fn_delay_down)
delay_down.pack(side=LEFT)

##############################################################################################

Label(f_C1, text='PWM    ', padx = 20).pack(side=LEFT)

pwm_up = Button(f_C1, text='^')
pwm_up.bind('<Button-1>', fn_pwm_up)
pwm_up.pack(side=LEFT)

pwm_label = Label(f_C1, text=str(pwm), padx = 20)
pwm_label.pack(side=LEFT)

pwm_down = Button(f_C1, text='v')
pwm_down.bind('<Button-1>', fn_pwm_down)
pwm_down.pack(side=LEFT)

##############################################################################################

Label(f_C2, text='Motions  ', padx = 20).pack(side=LEFT)

motion_up = Button(f_C2, text='^')
motion_up.bind('<Button-1>', fn_motion_up)
motion_up.pack(side=LEFT)

motion_label = Label(f_C2, text=str(motion), padx = 20)
motion_label.pack(side=LEFT)

motion_down = Button(f_C2, text='v')
motion_down.bind('<Button-1>', fn_motion_down)
motion_down.pack(side=LEFT)

##############################################################################################

Label(f_D1, text='Motion 1', padx = 20).pack()

##############################################################################################

f_D1_i.pack()

Label(f_D1_i, text='No. of rev', padx = 20).pack(anchor=W,side=LEFT)

rev1_up = Button(f_D1_i, text='^')
rev1_up.bind('<Button-1>', fn_rev1_up)
rev1_up.pack(side=LEFT)

rev1_label = Label(f_D1_i, text=str(rev1), padx = 20)
rev1_label.pack(side=LEFT)

rev1_down = Button(f_D1_i, text='v')
rev1_down.bind('<Button-1>', fn_rev1_down)
rev1_down.pack(side=LEFT)

##############################################################################################

f_D1_ii.pack()

Label(f_D1_ii, text='Divisor     ', padx = 20).pack(anchor=W, side=LEFT)

div1_up = Button(f_D1_ii, text='^')
div1_up.bind('<Button-1>', fn_div1_up)
div1_up.pack(side=LEFT)

div1_label = Label(f_D1_ii, text=str(div1), padx = 20)
div1_label.pack(side=LEFT)

div1_down = Button(f_D1_ii, text='v')
div1_down.bind('<Button-1>', fn_div1_down)
div1_down.pack(side=LEFT)

##############################################################################################

Label(f_D2, text='Motion 2', padx = 20).pack()

##############################################################################################

f_D2_i.pack()

Label(f_D2_i, text='No. of rev', padx = 20).pack(side=LEFT)

rev2_up = Button(f_D2_i, text='^')
rev2_up.bind('<Button-1>', fn_rev2_up)
rev2_up.pack(side=LEFT)

rev2_label = Label(f_D2_i, text=str(rev2), padx = 20)
rev2_label.pack(side=LEFT)

rev2_down = Button(f_D2_i, text='v')
rev2_down.bind('<Button-1>', fn_rev2_down)
rev2_down.pack(side=LEFT)

##############################################################################################

f_D2_ii.pack()

Label(f_D2_ii, text='Divisor     ', padx = 20).pack(side=LEFT)

div2_up = Button(f_D2_ii, text='^')
div2_up.bind('<Button-1>', fn_div2_up)
div2_up.pack(side=LEFT)

div2_label = Label(f_D2_ii, text=str(div2), padx = 20)
div2_label.pack(side=LEFT)

div2_down = Button(f_D2_ii, text='v')
div2_down.bind('<Button-1>', fn_div2_down)
div2_down.pack(side=LEFT)

##############################################################################################

Label(f_D3, text='Motion 3', padx = 20).pack()

##############################################################################################

f_D3_i.pack()

Label(f_D3_i, text='No. of rev', padx = 20).pack(side=LEFT)

rev3_up = Button(f_D3_i, text='^')
rev3_up.bind('<Button-1>', fn_rev3_up)
rev3_up.pack(side=LEFT)

rev3_label = Label(f_D3_i, text=str(rev3), padx = 20)
rev3_label.pack(side=LEFT)

rev3_down = Button(f_D3_i, text='v')
rev3_down.bind('<Button-1>', fn_rev3_down)
rev3_down.pack(side=LEFT)

##############################################################################################

f_D3_ii.pack()

Label(f_D3_ii, text='Divisor     ', padx = 20).pack(side=LEFT)

div3_up = Button(f_D3_ii, text='^')
div3_up.bind('<Button-1>', fn_div3_up)
div3_up.pack(side=LEFT)

div3_label = Label(f_D3_ii, text=str(div3), padx = 20)
div3_label.pack(side=LEFT)

div3_down = Button(f_D3_ii, text='v')
div3_down.bind('<Button-1>', fn_div3_down)
div3_down.pack(side=LEFT)

##############################################################################################

Label(f_D4, text='Motion 4', padx = 20).pack()

##############################################################################################

f_D4_i.pack()

Label(f_D4_i, text='No. of rev', padx = 20).pack(side=LEFT)

rev4_up = Button(f_D4_i, text='^')
rev4_up.bind('<Button-1>', fn_rev4_up)
rev4_up.pack(side=LEFT)

rev4_label = Label(f_D4_i, text=str(rev4), padx = 20)
rev4_label.pack(side=LEFT)

rev4_down = Button(f_D4_i, text='v')
rev4_down.bind('<Button-1>', fn_rev4_down)
rev4_down.pack(side=LEFT)

##############################################################################################

f_D4_ii.pack()

Label(f_D4_ii, text='Divisor     ', padx = 20).pack(side=LEFT)

div4_up = Button(f_D4_ii, text='^')
div4_up.bind('<Button-1>', fn_div4_up)
div4_up.pack(side=LEFT)

div4_label = Label(f_D4_ii, text=str(div4), padx = 20)
div4_label.pack(side=LEFT)

div4_down = Button(f_D4_ii, text='v')
div4_down.bind('<Button-1>', fn_div4_down)
div4_down.pack(side=LEFT)

##############################################################################################

start = Button(f_E, text='START', padx = 30, pady=20)
start.bind('<Button-1>', start_it)
start.pack(side=LEFT)

stop = Button(f_E, text='STOP', padx = 30, pady=20)
stop.bind('<Button-1>', stop_it)
stop.pack(side=RIGHT)

##############################################################################################

Label(f_F, text='Copyright © 2019 Aayaam Technologies - All Rights Reserved', padx = 20).pack(side=LEFT)

##############################################################################################

root.mainloop()