#define MISO 6
#define MOSI 5
#define SS   7
#define SCK 3
uint8_t transfer(uint8_t outdata);
uint8_t dataFromSlave ;
/*
* Function: setup
* Description: Hàm chỉ chạy 1 lần duy nhất khi Arduino hoạt động
*/
void setup() {
  pinMode(SCK , OUTPUT);
  pinMode(SS , OUTPUT);
  pinMode(MOSI , OUTPUT);
  pinMode(MISO , INPUT);
  digitalWrite(SCK, LOW);
  digitalWrite(SS, HIGH);
  digitalWrite(MOSI, LOW);
  Serial.begin(9600);
}

/*
* Function: loop
* Description: Hàm loop thực hiện lặp lại liên tục trong quá trình chạy chương trình
* Input:
*   void
* Output:
*   return: None
*/
void loop() {
  // put your main code here, to run repeatedly:
 transfer(15);
 Serial.println(15);
    delay(50);
    dataFromSlave = transfer(20);
    Serial.print("Data Received from Slave: ");
    Serial.println((int)dataFromSlave);
    delay(50);

}
/*
* Function: setupSCK
* Description: Hàm tín hiệu xung Clock
* Input:
*   No Input
* Output:
*   return : None
*/
void setupSCK() {
  digitalWrite(SCK, HIGH);
  delay(10);
  digitalWrite(SCK, LOW);
  delay(10);
}
/*
* Function: transfer
* Description: Hàm gửi Data từ Master -> Slave & nhận Data từ  Slave -> Master 
                
* Input:
*   mData - uint8_t
* Output:
*   return : None
*/
uint8_t transfer(uint8_t outdata) {
  uint8_t indata , t = 0, ibit = 0;
  digitalWrite(SS, LOW);
  
  for (ibit = 0x80; ibit > 0; ibit >>= 1) {
    t = outdata & ibit;
    if (t > 0) {
      digitalWrite(MOSI, HIGH);      
    } else {
      digitalWrite(MOSI, LOW);
    }
    if (digitalRead(MISO) == HIGH) {
      indata = indata | ibit;
    }
   
    
    setupSCK();
  }
  
  digitalWrite(SS, HIGH);
  
  return indata;
}
