#define led 3 //3.Pinde LED olduğunu tanımlıyoruz
//int SERIAL_OUTPUT_FREQUENCY = 1000; 
unsigned long old_time;
unsigned long new_time;
long difference;


void setup() {

  pinMode(led, OUTPUT); //LED'in çıkış elemanı olduğunu belirtiyoruz
  Serial.begin(9600); //9600 Baundluk bir seri haberleşme başlatıyoruz
  old_time = millis();
}

void loop() {

  int LED_ACTIVATION_VALUE = analogRead(A0); //Işık değişkenini A0 pinindeki LDR ile okuyoruz
  new_time = millis();
  difference = new_time - old_time;
  if(difference > 1000){
    Serial.print("LIGHT SENSOR: ");
    Serial.println(LED_ACTIVATION_VALUE); //Okunan değeri seri iletişim ekranına yansıtıyoruz
    if (LED_ACTIVATION_VALUE > 200) { //Okunan ışık değeri 450'den büyük ise
 
      Serial.println("LED   STATUS: OFF");
    
    }

    if (LED_ACTIVATION_VALUE <= 200) { //Okunan ışık değeri 450'den küçük ise
    
      Serial.println("LED   STATUS: ON");
    }
  
    Serial.println();
    old_time = new_time;
  }

  
  

  if (LED_ACTIVATION_VALUE > 200) { //Okunan ışık değeri 450'den büyük ise
    digitalWrite(led, LOW); //LED yanmasın
  }

  if (LED_ACTIVATION_VALUE <= 200) { //Okunan ışık değeri 450'den küçük ise
    digitalWrite(led, HIGH); //LED yansın
  }
  

}
