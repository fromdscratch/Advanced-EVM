#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include <Adafruit_Fingerprint.h>

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

#define PB1 A0  //Candidate 1
#define PB2 A1  //Candidate 2
#define PB3 A2  //Candidate 3
#define PB4 A3  //Candidate 4
#define PB5 A4  //Check Status

#define buzzer 4

int z = 0;

int a = 0, b = 0, c = 0, d = 0;

int a1 = 0, b1 = 0, c1 = 0, d1 = 0;

#define voice_playback 5

void message1(void);
void message2(void);
void message3(void);
void message4(void);
void message5(void);
void message6(void);
void message7(void);
void message8(void);

void setup()
{
  pinMode(buzzer, OUTPUT);
    digitalWrite(buzzer, LOW);
  
  pinMode(PB1, INPUT_PULLUP);
  pinMode(PB2, INPUT_PULLUP);
  pinMode(PB3, INPUT_PULLUP);
  pinMode(PB4, INPUT_PULLUP);
  pinMode(PB5, INPUT_PULLUP);

  pinMode(voice_playback, OUTPUT);
    digitalWrite(voice_playback, HIGH);
     delay(500);
     digitalWrite(voice_playback, LOW);
    
  Serial.begin(9600);
  
  //gsmSerial.begin(9600);
  
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print(" Voting System  ");
}

void loop()
{
  finger.begin(57600);

  int fingerprintID = getFingerprintID();
  delay(50);
  
  if ((fingerprintID == 1) || (fingerprintID == 2) || (fingerprintID == 3) || (fingerprintID == 4))
  { 
    Serial.println("Fingerprint Access Granted");

    if(fingerprintID == 1) 
    {
      lcd.setCursor(0, 1);
      lcd.print("Muguntha Granted");
      delay(500);
      
      a1 = a1 + 1;
    }
    else if(fingerprintID == 2) 
    {
      lcd.setCursor(0, 1);
      lcd.print(" Harish Granted ");
      delay(500);
      
      b1 = b1 + 1;
    }
    else if(fingerprintID == 3) 
    {
      lcd.setCursor(0, 1);
      lcd.print("SaiAkash Granted");
      delay(500);
      
      c1 = c1 + 1;
    }
    else if(fingerprintID == 4) 
    {
      lcd.setCursor(0, 1);
      lcd.print("Nithish Granted ");
      delay(500);
      
      d1 = d1 + 1;
    }
    
    while(1)
    {
      if((a1 >= 2) || (b1 >= 2) || (c1 >= 2) || (d1 >= 2))
      {
        digitalWrite(buzzer, HIGH);
        
        lcd.setCursor(0, 1);
        lcd.print(" Already Voted  ");
        
        delay(2000);

        digitalWrite(buzzer, LOW);
        
        lcd.setCursor(0, 1);
        lcd.print("                ");
        delay(100);
        
        break;
      }
      
      if(digitalRead(PB1) == LOW)
      {
        a = a + 1;

        lcd.setCursor(0, 1);
        lcd.print("                ");
        delay(100);
        
        lcd.setCursor(0, 1);
        lcd.print("Voted Successfully");

        if(fingerprintID == 1)
        {
          delay(100);
          message1();
          delay(100);
        }
        else if(fingerprintID == 2)
        {
          delay(100);
          message2();
          delay(100);
        }
        else if(fingerprintID == 3)
        {
          delay(100);
          message3();
          delay(100);
        }
        else if(fingerprintID == 4)
        {
          delay(100);
          message4();
          delay(100);
        }
        
        delay(1000);
        
        lcd.setCursor(0, 1);
        lcd.print("                ");
        delay(100);
        
        break;
      }
      
      else if(digitalRead(PB2) == LOW)
      {
        b = b + 1;

        lcd.setCursor(0, 1);
        lcd.print("                ");
        delay(100);
        
        lcd.setCursor(0, 1);
        lcd.print("Voted Successfully");
        
        if(fingerprintID == 1)
        {
          delay(100);
          message1();
          delay(100);
        }
        else if(fingerprintID == 2)
        {
          delay(100);
          message2();
          delay(100);
        }
        else if(fingerprintID == 3)
        {
          delay(100);
          message3();
          delay(100);
        }
        else if(fingerprintID == 4)
        {
          delay(100);
          message4();
          delay(100);
        }
        else if(fingerprintID == 6)
        {
          delay(100);
          message4();
          delay(100);
        }
        else if(fingerprintID == 7)
        {
          delay(100);
          message4();
          delay(100);
        }
        delay(1000);
        
        lcd.setCursor(0, 1);
        lcd.print("                ");
        delay(100);

        break;
      }
      
      else if(digitalRead(PB3) == LOW)
      {
        c = c + 1;

        lcd.setCursor(0, 1);
        lcd.print("                ");
        delay(100);
        
        lcd.setCursor(0, 1);
        lcd.print("Voted Successfully");
        
        if(fingerprintID == 1)
        {
          delay(100);
          message1();
          delay(100);
        }
        else if(fingerprintID == 2)
        {
          delay(100);
          message2();
          delay(100);
        }
        else if(fingerprintID == 3)
        {
          delay(100);
          message3();
          delay(100);
        }
        else if(fingerprintID == 4)
        {
          delay(100);
          message4();
          delay(100);
        }
        else if(fingerprintID == 6)
        {
          delay(100);
          message4();
          delay(100);
        }
        else if(fingerprintID == 7)
        {
          delay(100);
          message4();
          delay(100);
        }
        
        delay(1000);
        
        lcd.setCursor(0, 1);
        lcd.print("                ");
        delay(100);

        break;
      }
      
      else if(digitalRead(PB4) == LOW)
      {
        d = d + 1;

        lcd.setCursor(0, 1);
        lcd.print("                ");
        delay(100);
        
        lcd.setCursor(0, 1);
        lcd.print("Voted Successfully");
        
        if(fingerprintID == 1)
        {
          delay(100);
          message1();
          delay(100);
        }
        else if(fingerprintID == 2)
        {
          delay(100);
          message2();
          delay(100);
        }
        else if(fingerprintID == 3)
        {
          delay(100);
          message3();
          delay(100);
        }
        else if(fingerprintID == 4)
        {
          delay(100);
          message4();
          delay(100);
        }
        else if(fingerprintID == 6)
        {
          delay(100);
          message4();
          delay(100);
        }
        else if(fingerprintID == 7)
        {
          delay(100);
          message4();
          delay(100);
        }
        
        delay(1000);
        
        lcd.setCursor(0, 1);
        lcd.print("                ");
        delay(100);

        break;
      }
    }
    
    lcd.setCursor(0, 1);
    lcd.print("                ");
    delay(200);
  }  
  
  else if((fingerprintID == 5) || (fingerprintID == 6))
  {
    Serial.println("Fingerprint Access Granted - Check Status");

    lcd.setCursor(0, 1);
    lcd.print("  Check Status  ");
    delay(200);
    
    while(1)
    {
      if(digitalRead(PB5) == LOW)
      {
        if(a1 == 0)
        {
          delay(100);
          message5();
          delay(100);
        }
        
        if(b1 == 0)
        {
          delay(100);
          message6();
          delay(100);
        }
        
        if(c1 == 0)
        {
          delay(100);
          message7();
          delay(100);
        }
        
        if(d1 == 0)
        {
          delay(100);
          message8();
          delay(100);
        }

        break;
      }
    }
    
    lcd.setCursor(0, 1);
    lcd.print("                ");
    delay(200);
  }
  
  delay(500);
}

int getFingerprintID()
{
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;
  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  return finger.fingerID;
}

void message1(void)
{
  Serial.print("AT\r\n");delay(800);
  Serial.print("AT+CMGF=1\r\n");delay(800);
  Serial.print("AT+CMGS=");delay(500);
  Serial.write('"');delay(500);
  Serial.print("+917358341347");delay(500);//Change the calling number
  Serial.write('"');
  Serial.print("\r\n");delay(500);
  Serial.print("'Congratulations Mughuntha Voted Successfully and completed your duty towards nation'\r\n");delay(500);//17
  delay(500);
  Serial.write((char)26);
}

void message2(void)
{
  Serial.print("AT\r\n");delay(800);
  Serial.print("AT+CMGF=1\r\n");delay(800);
  Serial.print("AT+CMGS=");delay(500);
  Serial.write('"');delay(500);
  Serial.print("+917200030070");delay(500);//Change the calling number
  Serial.write('"');
  Serial.print("\r\n");delay(500);
  Serial.print("'Congratulations Harish Voted Successfully and completed your duty towards nation'\r\n");delay(500);//17
  delay(500);
  Serial.write((char)26);
}

void message3(void)
{
  Serial.print("AT\r\n");delay(800);
  Serial.print("AT+CMGF=1\r\n");delay(800);
  Serial.print("AT+CMGS=");delay(500);
  Serial.write('"');delay(500);
  Serial.print("+916381772850");delay(500);//Change the calling number
  Serial.write('"');
  Serial.print("\r\n");delay(500);
  Serial.print("'Congratulations Sai akash Voted Successfully and completed your duty towards nation'\r\n");delay(500);//17
  delay(500);
  Serial.write((char)26);
}

void message4(void)
{
  Serial.print("AT\r\n");delay(800);
  Serial.print("AT+CMGF=1\r\n");delay(800);
  Serial.print("AT+CMGS=");delay(500);
  Serial.write('"');delay(500);
  Serial.print("+918248836046");delay(500);//Change the calling number
  Serial.write('"');
  Serial.print("\r\n");delay(500);
  Serial.print("'Congratulations Nithish Voted Successfully and completed your duty towards nation'\r\n");delay(500);//17
  delay(500);
  Serial.write((char)26);
}
 
 

void message5(void)
{
  Serial.print("AT\r\n");delay(800);
  Serial.print("AT+CMGF=1\r\n");delay(800);
  Serial.print("AT+CMGS=");delay(500);
  Serial.write('"');delay(500);
  Serial.print("+917358341347");delay(500);//Change the calling number
  Serial.write('"');
  Serial.print("\r\n");delay(500);
  Serial.print("'Mughuntha - You have not voted Complete your duty towards the nation'\r\n");delay(500);//17
  delay(500);
  Serial.write((char)26);
}

void message6(void)
{
  Serial.print("AT\r\n");delay(800);
  Serial.print("AT+CMGF=1\r\n");delay(800);
  Serial.print("AT+CMGS=");delay(500);
  Serial.write('"');delay(500);
  Serial.print("+917200030070");delay(500);//Change the calling number
  Serial.write('"');
  Serial.print("\r\n");delay(500);
  Serial.print("'Harish - You have not voted Complete your duty towards the nation'\r\n");delay(500);//17
  delay(500);
  Serial.write((char)26);
}

void message7(void)
{
  Serial.print("AT\r\n");delay(800);
  Serial.print("AT+CMGF=1\r\n");delay(800);
  Serial.print("AT+CMGS=");delay(500);
  Serial.write('"');delay(500);
  Serial.print("+916381772850");delay(500);//Change the calling number
  Serial.write('"');
  Serial.print("\r\n");delay(500);
  Serial.print("'Sai Akash - You have not voted Complete your duty towards the nation'\r\n");delay(500);//17
  delay(500);
  Serial.write((char)26);
}

void message8(void)
{
  Serial.print("AT\r\n");delay(800);
  Serial.print("AT+CMGF=1\r\n");delay(800);
  Serial.print("AT+CMGS=");delay(500);
  Serial.write('"');delay(500);
  Serial.print("+918248836046");delay(500);//Change the calling number
  Serial.write('"');
  Serial.print("\r\n");delay(500);
  Serial.print("'Nithish - You have not voted Complete your duty towards the nation'\r\n");delay(500);//17
  delay(500);
  Serial.write((char)26);
}
