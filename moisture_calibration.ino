const int AirValue = 916;   //you need to replace this value with Value_1
const int WaterValue = 380;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;
float m;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  // Initialize serial
}

void loop() {
  // put your main code here, to run repeatedly:
int soilMoistureValue_2 = 0;
float k;
for (int i=0;i<100;i++)
{  
soilMoistureValue_2 = analogRead(A0);  //put Sensor insert into soil
k=soilMoistureValue_2+k;
delay(10);
}
soilMoistureValue=k/100;
Serial.println(soilMoistureValue);
soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);

if(soilmoisturepercent >= 100)
{
  Serial.println("100 %");
  m=100;
}
else if(soilmoisturepercent <=0)
{
  Serial.println("0 %");
  m=0;
}
else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
{
  Serial.print(soilmoisturepercent);
  Serial.println("%");
  m=soilmoisturepercent; 
}
}
