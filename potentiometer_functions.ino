int sensor_pin = A0; //Corresponde al pin analógico 1 del microcontrolador.
int sensor_value = 0; //para guardar el valor leido por el pin analogo.
float converted_value = 0.00;
float ratio = 0.00;
bool flag_u1 = false, flag_u2 = false;
int previus_u1 = 0, previus_u2 = 0;

void _read_potentiometer(){
  sensor_value = analogRead(sensor_pin); //Se lee el valor analógico del pin y se asigna.
  ratio = (30.0 - 10.0) / (1023.0 - 0.0);
  converted_value = (sensor_value - 0) * ratio + 10.0;
  value = ceil(converted_value);
  EEPROM.write(0, value);
  cy = 30-value;

  if(previus_u1<=15 && previus_u1!=0){
    flag_u1 = true;
  }
  if(previus_u2<=20 && previus_u2!=0){
    flag_u2 = true;
  }

  if(value>15 && flag_u1 == true){
    u1 ++;
    EEPROM.write(1, u1);
    flag_u1 = false;
  }
  if(value>20 && flag_u2 == true){
    u2 ++;
    EEPROM.write(2, u2);
    flag_u2 = false;
  }
  previus_u1 = value;
  previus_u2 = value;
}