#include <Arduino.h>
#include <Stream.h>

class DataParser
{
  private:
    Stream* _stream;
    uint32_t _timeout;

    String data = "";
    String header = "@#$";
    String footer = "%^&";
    char inChar;

    String acc = "";

  public:
    void begin(Stream& stream, uint32_t timeout = 500)
    {
      _stream = &stream;
      _timeout = timeout;
    }

    void wait_for_data()
    {
      while (!_stream->available())
      {
        Serial.println("Waiting For Data");
        delay(100);
      }

      while (_stream->available() > 0)
      {
        inChar = _stream->read();
        data += (char)inChar;
      }
    }

    uint8_t* get_values()
    {
      uint8_t data_integers[70];

      uint8_t index = 3;

      for (uint8_t i = 0; i < 70; i++)
      {
        while (data.charAt(index) != ',')
        {
          acc += (char)data.charAt(index);
          index++;
        }

        data_integers[i] = acc.toInt();

        acc = "";
        index++;

      }

      return data_integers;


    }

    void print_data()
    {
      Serial.println();

      Serial.print("Recieved Data is :  ");
      Serial.println(data);


      if (data.startsWith(header))
      {
        Serial.println("Header Verified !!! ");
      }

      if (data.endsWith(footer))
      {
        Serial.println("Footer Verified !!! ");
      }

      Serial.println();
    }

    void nullify()
    {
      data = "";
    }


};

