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
