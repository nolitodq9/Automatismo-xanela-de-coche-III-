/*
Práctica 22, Xanela de carro (III).
Programa para simular función dunha fiestra movil de maneira simplificada. 
O funcionamento é o seguinte:
Dispoñemos dun botón (pin 7 do Arduíno) para a baixada e subida da xanela, e 2 botóns que simulan fins de carreira ( Pin 8 fcArriba e Pin 9 fcAbaixo). 
O funcionamento parte do estado do pulsador en 1, no que a xanela está parada arriba, accionada polo FcArriba; cando pulsamos
o botón pásase ao estado 2, no que se activa o motor que fai baixar a xanela (motorAbaixo). Cando prememos o FcAbaixo o estado cambia ao 3, no que o motor se para simulando que a xanela está baixada. Se pulsamos novamente o botón, pasaremos ao estado 0, no que a xanela comeza a subir debido a que se activou (motorArriba). Este sería o funcionamento, no que tamén se pasaría do estado de subida ao de baixada ou ao revés se prememos 2 veces seguidas o botón de arriba/abaixo.

Entradas Pulsador (3x dixital)
Saidas: Rele (2x dixital)

Autor: Manuel Dominguez
Data: 10 Febreiro de 2023
*/

#define motorArriba 12    // Aquí indica molle a Arduino que a acción motorArriba está definida no pin 12
#define motorAbaixo 11    // Aquí indica molle a Arduino que a acción motorArriba está definida no pin 11
#define pulsador     7    // Aquí indica molle a Arduino que a acción pulsador está definido no pin 7
#define FcArriba	   8    // Aquí indica molle a Arduino que a acción FcArriba está definido no pin 7
#define FcAbaixo	   9    // Aquí indica molle a Arduino que a acción FcAbaixo está definido no pin 7
 
int estado = 1;       // o valor é un numero enteiro, pode ser 0,1,2,3 ...
int contador = 0;    // contador para o numero de impulsos do motor


void setup() {			// Aquí definimos as entradas e saídas dos pins + a velocidade de sincronismodas comunicacións

  pinMode(motorArriba, OUTPUT);     // Aquí explicámolle a Arduino que o pin motorArriba é unha saída
  pinMode(motorAbaixo, OUTPUT);     // Aquí explicámolle a Arduino que o pin motorAbaixo é unha saída
  pinMode(pulsador, INPUT);         // Aquí explicamos a Arduino que o pin pulsador é unha entrada
  pinMode(FcArriba, INPUT);         // Aquí explicámolle a Arduíno que FcArriba é unha entrada
  pinMode(FcAbaixo, INPUT);         // Aquí explicámolle a Arduíno que FcAbaixo é unha entrada
  
  Serial.begin(9600);              //velocidade sincronismo das comunicacions
}


void loop() {		          //Esta parte é na que se executa o código "bucle"       	
                          //Lectura dos pulsadores
  
  if(digitalRead(pulsador)) {	      // Pulsador marcha/paro	
    estado= (++estado) % 4; 	      // Actuaizacion do estado para estar entre 0 e 3.
    
    while(digitalRead(pulsador));{
      delay(20);
      }
    }
  
 if(digitalRead(FcArriba)) {   // Fin Carreira posición superior
   if(estado != 2 ) {			// Se o estado é distinto de 2, actualiza a 1
      estado= 1;  				// Xanela parada arriba  
   
   }
   					// Xanela parada arriba
      delay(20);
   
  }
  
  
  if(digitalRead(FcAbaixo)) {		// Fina carreira posición inferior
     if(estado != 0 ) {
    estado = 3;			// Xanela parada abaixo
     }
      delay(20);
     
  } 
  
  // fin lectura do pulsador
  
  Serial.print("|  Estado Contador: ");
  Serial.println(estado);
   
  // Accionamento dos motores
  
 
    if(estado == 0 ) {
      digitalWrite(motorArriba, HIGH);
      digitalWrite(motorAbaixo, LOW);
      delay(70);
     
  }
   else if (estado == 2) {
     digitalWrite(motorArriba,LOW);
     digitalWrite(motorAbaixo, HIGH);
     delay(70);
    
   } 
    else {
      digitalWrite(motorArriba, LOW);
     digitalWrite(motorAbaixo,LOW);
     delay(70);
   
      
    }
 }
  
