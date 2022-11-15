#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define SensorTemp A0

LiquidCrystal_I2C lcd(0x27,16,2);

int ventilador1 = 2;
int ventilador2 = 3;
int ventilador3 = 4;
int ventilador4 = 5;
int ventilador5 = 6;

void setup() {
  pinMode(ventilador1, OUTPUT);
  pinMode(ventilador2, OUTPUT);
  pinMode(ventilador3, OUTPUT);
  pinMode(ventilador4, OUTPUT);
  pinMode(ventilador5, OUTPUT);
  pinMode(A0, INPUT);
  
  lcd.init();
  lcd.init();
  lcd.backlight();
   
  Serial.begin(9600);
}

void loop () {
  double tmp = analogRead(A0);
  tmp = ((tmp)/22);
 
  Serial.print (tmp);
  Serial.println ("C");
  delay (100);
    
  if (tmp < 20) {
    digitalWrite (ventilador1, LOW);
    digitalWrite (ventilador2, LOW);
    digitalWrite (ventilador3, LOW);
    digitalWrite (ventilador4, LOW);
    digitalWrite (ventilador5, LOW);
} if ((tmp > 20) && (tmp <= 25)) {
    digitalWrite (ventilador1, HIGH);
    digitalWrite (ventilador2, LOW);
    digitalWrite (ventilador3, LOW);
    digitalWrite (ventilador4, LOW);
    digitalWrite (ventilador5, LOW);
    
    lcd.setCursor (3,0);
    lcd.println("Ventilador 1");
    lcd.setCursor (2,3);
    lcd.println("ligado");
    delay(1000);
    
    lcd.clear();
    delay(10);
    
    lcd.setCursor(3,0);
    lcd.print(tmp);
    lcd.println("C");
    delay(1000);
    
    lcd.clear(); 
    delay(10);   
   
  } else if ((tmp > 25) && (tmp <= 30)) {
    digitalWrite (ventilador1, HIGH);
    digitalWrite (ventilador2, HIGH);
    digitalWrite (ventilador3, LOW);
    digitalWrite (ventilador4, LOW);
    digitalWrite (ventilador5, LOW);
    
    lcd.setCursor (3,0);
    lcd.println("Ventilador 2");
    lcd.setCursor (2,3);
    lcd.println("ligado");
    delay(1000);
    
    lcd.clear();
    delay(10);
    
    lcd.setCursor(3,0);
    lcd.print(tmp);
    lcd.println("C");
    delay(1000);
    
    lcd.clear();
    delay(10);   
   
  } else if ((tmp > 30) && (tmp <= 35)) {
    digitalWrite (ventilador1, HIGH);
    digitalWrite (ventilador2, HIGH);
    digitalWrite (ventilador3, HIGH);
    digitalWrite (ventilador4, LOW);
    digitalWrite (ventilador5, LOW); 
    
    lcd.setCursor (3,0);
    lcd.println("Ventilador 3");
    lcd.setCursor (2,3);
    lcd.println("ligado");
    delay(1000);
    
    lcd.clear();
    delay(10);
    
    lcd.setCursor(3,0);
    lcd.print(tmp);
    lcd.println(" C             ");
    delay(1000);
    
    lcd.clear(); 
    delay(10);   
      
  } if ((tmp > 35 && tmp <= 40)) {
    digitalWrite (ventilador1, HIGH);
    digitalWrite (ventilador2, HIGH);
    digitalWrite (ventilador3, HIGH);
    digitalWrite (ventilador4, HIGH);
    digitalWrite (ventilador5, LOW);
    
    lcd.setCursor (3,0);
    lcd.println("Ventilador 4");
    lcd.setCursor (2,3);
    lcd.println("ligado");
    delay(1000);
    lcd.clear();
    delay(10);
    
    lcd.setCursor(3,0);
    lcd.print(tmp);
    lcd.println("C");
    delay(1000); 
    
    lcd.clear(); 
    delay(10);    
  } if (tmp > 40) {
    digitalWrite (ventilador1, HIGH);
    digitalWrite (ventilador2, HIGH);
    digitalWrite (ventilador3, HIGH);
    digitalWrite (ventilador4, HIGH);
    digitalWrite (ventilador5, HIGH);
    
    lcd.setCursor (3,0);
    lcd.println("Ventilador 5");
    lcd.setCursor (2,3);
    lcd.println("ligado");
    delay(1000);
    
    lcd.clear();
    delay(10); 
    
    lcd.setCursor(3,0);
    lcd.print(tmp);
    lcd.println("C");
    delay(1000);
    
    lcd.clear();
    delay(10);   
  }
}
