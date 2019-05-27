import sys
import serial
import time

def list_serial_ports():
    """ Lists serial port names
        :raises EnvironmentError:
            On unsupported or unknown platforms
        :returns:
            A list of the serial ports available on the system
    """
    if sys.platform.startswith('win'):
        ports = ['COM%s' % (i + 1) for i in range(256)]
    elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
        # this excludes your current terminal "/dev/tty"
        ports = glob.glob('/dev/tty[A-Za-z]*')
    elif sys.platform.startswith('darwin'):
        ports = glob.glob('/dev/tty.*')
    else:
        raise EnvironmentError('Unsupported platform')

    result = []
    for port in ports:
        try:
            s = serial.Serial(port)
            s.close()
            result.append(port)
        except (OSError, serial.SerialException):
            pass
    return result

port_list = list_serial_ports()
ser = serial.Serial()
ser.port = port_list[0]
ser.baudrate = 9600
ser.close()
ser.open()
time.sleep(1)

ser.write ( b'r' )  #serialcmd.encode('utf-8'))
time.sleep(1)
ser.write ( b't' )  #serialcmd.encode('utf-8'))

