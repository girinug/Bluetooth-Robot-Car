#include <SoftwareSerial.h>

//PIN Rx dan Tx UNTUK BLUETOOTH
const int Rx = 3;
const int Tx = 2;

//MEMBUAT INSTANCE "mySerial" pada Class SoftwareSerial
SoftwareSerial mySerial(Rx,Tx);

//PIN BUAT RODA, DIJADIIN ARRAY BIAR SIMPLE
const int roda[] = {4, 5, 6, 7}; 
int data;

void maju(){
  //RODA KIRI
  analogWrite(roda[0], 130);
  analogWrite(roda[1], 125);

  //RODA KANAN
  analogWrite(roda[2], 130);
  analogWrite(roda[3], 125);
}
void mundur(){
  //RODA  KIRI
  analogWrite(roda[1], 130);
  analogWrite(roda[0], 127);

  //RODA KANAN
  analogWrite(roda[3], 130);
  analogWrite(roda[2], 127);
}

void kiri(){
  //RODA KIRI
  analogWrite(roda[0], 0);
  analogWrite(roda[1], 0);

  //RODA KANAN
  analogWrite(roda[2], 130);
  analogWrite(roda[3], 125);
}

void kanan(){
  //RODA KIRI
  analogWrite(roda[0], 130);
  analogWrite(roda[1], 125);

  //RODA KANAN
  analogWrite(roda[2], 0);
  analogWrite(roda[3], 0);
}
void stoped(){
  analogWrite(roda[0], 0);
  analogWrite(roda[1], 0);
  analogWrite(roda[2], 0);
  analogWrite(roda[3], 0);
}
void setup() {
  //INI KOMUNIKASI KE KOMPUTER
  Serial.begin(9600);

  //INI KOMUNIKASI KE "ORANG KETIGA"
  mySerial.begin(9600);

  //ARRAY PIN DIJADIIN OUTPUT, BUAT RODA
  pinMode(roda, OUTPUT);
  delay(2000);

}

void loop() {

  /* 
   *  
   *  USAHAIN CEK DULU, DATA YANG DIKIRIM DARI APLIKASI GIMANA!
   *  
   if (mySerial.available()) {
        //KERJAKAN SESUATU
   }
   DIBACA => "JIKA ADA KONEKSI BLUETOOTH, MAKA...
  
  
  */
  
  if (mySerial.available()) {
    
    data = mySerial.read();
    switch (data){
      case 70:
      //APLIKASI YANG GUA PAKE NGASIHNYA NILAI 70, UTK PANAH KE ATAS
        maju();
        Serial.println(data);
        break;
      case 66:
      //APLIKASI YANG GUA PAKE NGASIHNYA NILAI 70, UTK PANAH KE BAWAH
        mundur();
        Serial.println(data);
        break;
      case 82:
      //APLIKASI YANG GUA PAKE NGASIHNYA NILAI 70, UTK PANAH KE KANAN
        kanan();
        Serial.println(data);
        break;
      case 76:
      //APLIKASI YANG GUA PAKE NGASIHNYA NILAI 70, UTK PANAH KE KIRI
        kiri();
        Serial.println(data);
        break;
      case 83:
      //PAS DI DIEMIN, APLIKASI GUA NGASIH NILAI 83
        stoped();
        Serial.println(data);
        break; 
    }
    
    
  }
}
