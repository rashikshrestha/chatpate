#include <Arduino.h>
#include <Stream.h>

#define DATA_LENGTH 160

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
      _stream->setTimeout(_timeout);
    }

    void wait_for_data()
    {
      bool dummy = 1;
      while (!_stream->available())
      {
        if (dummy)
        {
          Serial.print("Waiting For Data");
          dummy = 0;
        }
        Serial.print(".");

        delay(100);
      }
      Serial.println();

      data = _stream->readStringUntil('\n');
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

    bool validate_data()
    {
      uint8_t confidence_level = 0;

      Serial.println();

      Serial.print("Recieved Data is :  ");
      Serial.println(data);

      Serial.print("Size:  ");
      Serial.print(data.length());
      Serial.println("  (expected "  + String(DATA_LENGTH) + " )");

      if (data.length() == DATA_LENGTH)
      {
        Serial.println("Length Verified !!!");
        confidence_level++;
      }
      else
      {
        Serial.println("Length Error !!!");
      }


      if (data.startsWith(header))
      {
        Serial.println("Header Verified !!! ");
        confidence_level++;
      }
      else
      {
        Serial.println("Header Error !!! ");
      }

      if (data.endsWith(footer))
      {
        Serial.println("Footer Verified !!! ");
        confidence_level++;
      }
      else
      {
        Serial.println("Footer Error !!! ");
      }

      if (confidence_level == 3)
      {
        Serial.println("  >>> VALID DATA \n");
        return 1;
      }

      else
      {
        Serial.println("  >>> ERROR !!!!    INVALID DATA \n");
        return 0;
      }


    }

    void nullify()
    {
      data = "";
    }


};

