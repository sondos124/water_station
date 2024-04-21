#include<LiquidCrystal.h>

const int rs= 12 , en =11 ,d4=5 , d5=4 , d6=3 ,d7=2 ;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7 );

int lowTank=A3 , quTank=A2 ,halfTank=A1 ,fullTank=A0 ;
int motor = 13 ; 
int i , j , k , l ;




void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Tank Status ...........");

  pinMode(lowTank , INPUT);
  pinMode(lowTank , INPUT);
  pinMode(lowTank ,INPUT);
  pinMode(lowTank , INPUT);
  pinMode(motor , OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  i=digitalRead(fullTank);
  j=digitalRead(halfTank);
  k=digitalRead(quTank);
  l=digitalRead(lowTank);

  if (i==1 && j==1 && k==1 && l==1 ){
    lcd.setCursor(0,0);
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print(' ');
    lcd.setCursor(5,0);
    lcd.print("FULL .......");
    lcd.setCursor(0,1);
    lcd.print("MOTOR IS OFF              ");
    digitalWrite(motor , LOW ) ; 
  }
  else{
  if (i==0 && j==1 && k==1 && l==1 ){
    lcd.setCursor(0,0);
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print("_");
    lcd.print(' ');
    lcd.setCursor(5,0);
    lcd.print("HALF .......");
    lcd.setCursor(0,1);
    lcd.print("MOTOR IS OFF              ");
    digitalWrite(motor , LOW ) ; 
  }
  else{
    if (i==0 && j==0 && k==1 && l==1 ){
    lcd.setCursor(0,0);
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print("_");
    lcd.print("_");
    lcd.print(' ');
    lcd.setCursor(5,0);
    lcd.print("QUATER .......");
    lcd.setCursor(0,1);
    lcd.print("MOTOR IS On              ");
    digitalWrite(motor , HIGH ) ; 
  }
  else{
    if (i==0 && j==0 && k==0 && l==1 ){
    lcd.setCursor(0,0);
    lcd.print(char(219));
    lcd.print("_");
    lcd.print("_");
    lcd.print("_");
    lcd.print(' ');
    lcd.setCursor(5,0);
    lcd.print("LOW .......");
    lcd.setCursor(0,1);
    lcd.print("MOTOR IS ON              ");
    digitalWrite(motor , HIGH ) ; 
  }
  else{
    if (i==0 && j==0 && k==0 && l==0 ){
    lcd.setCursor(0,0);
    lcd.print("_");
    lcd.print("_");
    lcd.print("_");
    lcd.print("_");
    lcd.print(' ');
    lcd.setCursor(5,0);
    lcd.print("EMPTY .......");
    lcd.setCursor(0,1);
    lcd.print("MOTOR IS ON              ");
    digitalWrite(motor , HIGH ) ; 
  }
  else {
   digitalWrite(motor , LOW ) ;
   lcd.setCursor(0,0);
   lcd.print("sensor FAIL " ) ;
   lcd.setCursor(0,1);
   lcd.print("NEED CHECK-UP .......");
  }
}
  }}}}
