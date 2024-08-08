<img src="https://gist.githubusercontent.com/ChristofferIsac/e24f145840c50591c231a4c842c2512a/raw/9a7984dfd5e5dc98711f7cda949931d5cf1f9cf5/BotArduino.svg">

# ArduinoSeguidorDeLinha

## Introdução

> ℹ️ **NOTE:** Projeto desenvolvido em ambiente escolar, como forma de introdução ao uso da robótica


<img align="right" width="180px" src="https://gist.githubusercontent.com/ChristofferIsac/6e53e983945621f7ef31beff873b5e0e/raw/81da0ad8192347d21220d779e0f8f0966615e098/ArduinoBot.svg">
Este projeto trata do desenvolvimento de um carrinho seguidor de linha utilizando a plataforma Arduino. O objetivo principal é criar um veículo robótico que seja capaz de seguir uma linha preta traçada em um fundo branco, navegando automaticamente pelo percurso definido. Este tipo de projeto é amplamente utilizado em competições de robótica e como uma introdução prática ao mundo da programação e eletrônica.

## Descrição do Projeto
O carrinho seguidor de linha é um projeto robótico, sendo controlado por um microcontrolador Arduino, equipado com sensores de linha e motores que garantem sua execução corretamente. A estrutura básica do projeto inclui:

|  Peças utilizadas |    Função     |
| :----: | -------------------------------------------------------------------------------------- |
|  Arduino  | O microcontrolador principal que controla todos os componentes do carrinho |       
|  Módulo Ponte H  | Controla a direção e a velocidade dos motores DC do carrinho |  
|  Sensores de Reflexão  | Dois sensores infravermelhos (IR) posicionados na frente do carrinho para detectar a linha preta |
|  Baterias 18650  | Duas baterias que fornecem energia para o funcionamento do carrinho |
|  Chave Liga/Desliga  | Permite ligar e desligar o carrinho facilmente |
|  Motores e Driver de Motor  | Dois motores DC conectados às rodas do carrinho, controlados por um driver de motor para gerenciar a direção e a velocidade |
|  Fios Jumper  | Cerca de 20 unidades utilizadas para realizar conexões entre os componentes |
|  Sensor Ultrassom  | Sensor opcional para detectar obstáculos à frente do carrinho |
|  Chassi do Carrinho  | A estrutura física que sustenta todos os componentes |


## Funcionamento
Suas funcionalidades foram desenvolvidas e estão sendo revisadas para que sua perfomance não seja afetada durante a execução. O carrinho funciona do seguinte modo:

|  Função |    Descrição    |
| :----: | -------------------------------------------------------------------------------------- |
|  Detecção da Linha  | Os sensores IR detectam a presença da linha preta. Quando o sensor está sobre a linha, ele retorna um valor alto (HIGH) |       
|  Controle de Movimento  | Com base na leitura dos sensores, o Arduino toma decisões sobre a direção e a velocidade dos motores |  
|  Ambos os Sensores na Linha  | O carrinho para, dá ré por um breve período, e então para novamente. Isso pode ser uma resposta a uma situação de erro, como um cruzamento ou final de linha |  
|  Sensor Direito na Linha  | O carrinho gira para a esquerda ajustando a velocidade dos motores |  
|  Sensor Esquerdo na Linha  | O carrinho gira para a direita ajustando a velocidade dos motores |  
|  Nenhum Sensor na Linha  | O carrinho segue em frente |  


