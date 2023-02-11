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
  
  if(digitalRead(pulsador)) {	            // Pulsador marcha/paro	(lectura = pulsación)
    estado= (++estado) % 4; 	             /* Actualización do estado para estar entre 0 e 3.  
                                             Isto signifa realizar a seguinte operación: Ao estado súmaselle unha unidade,e ese resultado divídese entre 4,
                                             que vai dar 0, pero nesa división sempre hai un resto; que vai ser o valor empregado para actualizar o estado.*/
     
   while(digitalRead(pulsador));{        // Comando while; quere dicir que mentras fai a operación anterior espere 20 milisegundos
      delay(20);
      }
    }
  
 if(digitalRead(FcArriba)) {            // Fin Carreira posición superior
   if(estado != 2 ) {			                // Se o estado é distinto de 2, actualiza a 1
      estado= 1;  				                  // Xanela parada arriba  
   
   }
      delay(20);                        // Esperar 20 milisegundos
   
  }
  
  
  if(digitalRead(FcAbaixo)) {	         	// Comando "if"; quere dicir que si se produce a lectura do Final carreira posición inferior (está activada), realice as seguintes accións:
     if(estado != 0 ) {                 // Comando "if"; quere dicir que si o estado non é 0, que sexa 3 ( vese na seguinte liña)
    estado = 3;			                     // Xanela parada abaixo
     }
      delay(20);                       // Esperar 20 milisegundos
     
  } 
  
                          // fin lectura do pulsador
 
                          // Comandos para a impresión de valores no monitor serie
  Serial.print("|  Estado Contador: ");
  Serial.println(estado);
   
                       // Accionamento dos motores
  
 
    if(estado == 0 ) {                      // Se o estado é 0, que realice as seguintes accións:
      digitalWrite(motorArriba, HIGH);      // A saída dixital motorArriba que se active
      digitalWrite(motorAbaixo, LOW);       // A saída dixital motorAbaixo que non se active (enclavamento)
      delay(70);                            // Esperar 70 milisegundos antes de volver executar bucle
     
  }
   else if (estado == 2) {                 /* Comandos "else" (senon fai isto) + "if" (si se cumple esto); no que queremos dicir que se o estado non é cero,
                                             pero é dous, que realice as seguintes accións: */
    
     digitalWrite(motorArriba,LOW);       // A saída dixital motorArriba que non se active
     digitalWrite(motorAbaixo, HIGH);    // A saída dixital motorAbaixo que se active
     delay(70);                          // Agardar 70 milisegundos
    
   } 
    else {                              // Comando "else" (senon fai isto); no que di que se o estado non é 0 nin 3 que realice as seguintes accións:
      digitalWrite(motorArriba, LOW);   // A saída dixital motorArriba que non se active
     digitalWrite(motorAbaixo,LOW);    // A saída dixital motorAbaixo que non se active
     delay(70);                        //  Agardar 70 milisegundos
   
      
    }
 }
                                                              //FIN PROCESO
