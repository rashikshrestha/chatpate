from __future__ import print_function
import sys
import serial
import glob
import struct
import time
# import numpy as np



def serial_ports():
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


def look_for_available_ports():
    """
    find available serial ports to Arduino
    """
    available_ports = glob.glob('/dev/ttyACM*')
    print("Available ports: ")
    print(available_ports)

    return available_ports


def get_time_millis():
    return(int(round(time.time() * 1000)))


def get_time_seconds():
    return(int(round(time.time() * 1000000)))


def print_values(values):
    print("------ ONE MORE MEASUREMENT ------")
    print("Accelerations: ")
    print(values[0:3])
    print("Angular rates: ")
    print(values[3:6])
    print("Magnetometer: ")
    print(values[6:9])


class ReadFromArduino(object):
    """A class to read the serial messages from Arduino. The code running on Arduino
    can for example be the ArduinoSide_LSM9DS0 sketch."""

    def __init__(self, port, SIZE_STRUCT=36, verbose=0):
        self.port = port
        self.millis = get_time_millis()
        self.SIZE_STRUCT = SIZE_STRUCT
        self.verbose = verbose
        self.latest_values = -1
        self.t_init = get_time_millis()
        self.t = 0

        self.port.flushInput()

    def read_one_value(self):
        """Wait for next serial message from the Arduino, and read the whole
        message as a structure."""
        read = False

        while not read:
            myByte = self.port.read(1)
            if myByte.decode() == 'S':
                data = self.port.read(self.SIZE_STRUCT)
                myByte = self.port.read(1)
                if myByte.decode() == 'E':
                    self.t = (get_time_millis() - self.t_init) / 1000.0

                    # is  a valid message struct
                    new_values = struct.unpack('<fffffffff', data)

                    current_time = get_time_millis()
                    time_elapsed = current_time - self.millis
                    self.millis = current_time

                    read = True

                    self.latest_values = np.array(new_values)

                    # convert measurements to rad/s
                    self.latest_values[3: 6] = 3.1415 / 180.0 * self.latest_values[3: 6]

                    if self.verbose > 1:
                        print("Time elapsed since last (ms): " + str(time_elapsed))
                        print_values(new_values)

                    return(True)

        return(False)


print(serial_ports())