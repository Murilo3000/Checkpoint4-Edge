<h1># Checkpoint 4 - Edge</h1>

Este é um projeto sobre o envio dos dados recebidos de temperatura, luminosidade e umidade pela placa ESP32 para a plataforma Tago.io. Esses dados são fictícios, mas com suas devidas alterações, podem ser calculados por sensores reais.<br><br>
A proposta do dispositivo tem como função:
  - medir a temperatura do ambiente aonde está localizado os vinhos.
  - verificar sua umidade.
  - verificar sua luminosidade.

Assim, auxiliando na preservação dos vinhos, garantindo assim que eles estejam com o ambiente apropriado, evitando que o conteúdo que ela esteja armazenando seja prejudicado de várias formas diferentes.

<h2>Requisitos</h2>

- Arduino compatível com Wifi (No caso, o utilizado foi o ESP32).
- Sensor de temperatura, umidade e luminosidade (DHT)(Adafruit).
- As bibliotecas: WiFi.h, Adafruit_TSL2561_U.h, Wire.h, DHT.h, Arduino.h e HTTPClient.
- Conta no Tago.io com um dispositivo configurado e Token de autenticação para dar um destino aos dados recebidos.

<h2>Configuração</h2>

Antes de usar o código, é necessário realizar algumas configurações:

1. Altere as informações da rede Wifi:

   ```cpp
   char wifiSsid[] = "SUA_REDE_WIFI"; // Nome da rede Wi-Fi
   char wifiPass[] = "SUA_SENHA_WIFI"; // Senha da rede Wi-Fi

2. Altere as informações do Tago.io e seu Token de autenticação
   
   ```cpp
   char serverAddress[] = "https://admin.tago.io/devices/SEU_DISPOSITIVO"; // Endereço do servidor Tago.io
   char tokenHeader[] = "SEU_TOKEN_TAGO"; // Token de autenticação Tago.io

<h2>Uso</h2>

- O dispositivo medirá a temperatura, humidade e luminosidade em intervalos regulares e a enviará para o Tago.io.
- Certifique-se de que os dispositivos estejam conectados à rede Wifi, para que assim os dados possam ser enviados.

<h2>Monitoramento</h2>
  
Você pode monitorar os dados enviados para o Tago.io através da plataforma Tago.
Certifique-se de que seu dispositivo e variáveis estejam configurados corretamente no Tago.io.

<h2>Contribuição</h2>

Fique à vontade para contribuir com melhorias e correções neste projeto. Basta fazer um fork deste repositório, fazer suas alterações e enviar um pull request.

<h2>Problemas reconhecidos</h2>

Devido à falta dos sensores de temperatura e umidade e luminosidade, foi realizada uma função int dhtHumidity, int dhtTemperature e luminosidadeSimulada para simular valores. Caso possua os equipamentos em mãos, é necessária a alteração de certas linhas do código.

<h2>Recursos Adicionais</h2>

- Para obter mais informações sobre o Tago.io e como configurar dispositivos e variáveis, consulte a documentação oficial em [Tago.io Documentation](https://tago.io/docs/).
- Para informações sobre o sensor DHT e como usá-lo com o Arduino, consulte a documentação da biblioteca DHT em [Arduino DHT Library](https://github.com/adafruit/DHT-sensor-library).
- Para saber mais sobre a luminosidade, foi utilizado o ChatGPT.
- O ChatGPT foi utilizado para corrigir e explicar certas partes do código. Recomenda-se a utilização do mesmo para corrigir futuros erros ou dúvidas específicas.
