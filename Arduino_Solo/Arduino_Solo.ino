const int PINO_SENSOR_UMIDADE = A0;
const int ValorAr = 550;
const int ValorAgua = 230;

int valorUmidadeSolo = 0;
float porcentagemUmidade = 0;

void setup(){
  Serial.begin(9600);
}

void loop() {

  int valorUmidadeSolo = analogRead(PINO_SENSOR_UMIDADE);

  int faixa = ValorAr - ValorAgua;
  int distancia = ValorAr - valorUmidadeSolo;

  porcentagemUmidade = (float)distancia / faixa * 100.0;

  if (porcentagemUmidade < 0) porcentagemUmidade = 0;
  if (porcentagemUmidade > 100) porcentagemUmidade = 100;

 
  Serial.println(porcentagemUmidade);   // Valor da umidade calculado em PORCENTAGEM a partir do valor bruto            
 
 /*
  O Serial.print "escreve" oq o gráfico vai receber, como se fosse uma mensagem
  O Serial.printLN "envia" essa mensagem para o plotter criando um gráfico automático com as medições que foram capturadas durante o tempo delay de 1 segundo
  
  
  lembrando q o valor deve ser uma variável q seja número, a string serve apenas para nomear os numeros do gráfico.
  */
  delay(2000);
}
  
 

 
