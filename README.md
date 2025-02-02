# 🚦 Projeto: Simulação de Semáforo com Raspberry Pi Pico

Este projeto implementa a lógica de um **semáforo** utilizando um **Raspberry Pi Pico**, alternando entre os estados **vermelho, amarelo e verde** a cada 3 segundos. O código foi testado exclusivamente no **simulador Wokwi** e já inclui o arquivo `diagram.json` para facilitar a configuração.

## 🎯 Objetivo

Criar um semáforo funcional utilizando LEDs conectados ao Raspberry Pi Pico, alternando os estados automaticamente.

## 🛠️ Tecnologias Utilizadas

- **Linguagem C**
- **Pico SDK**
- **Simulador Wokwi**
- **Bibliotecas padrão do Pico (pico/stdlib.h)**

## 🔧 Como o Semáforo Funciona?

1. O sistema inicia com o **LED vermelho aceso**.
2. A cada **3 segundos**, ocorre a mudança de estado:
   - Vermelho → Amarelo
   - Amarelo → Verde
   - Verde → Vermelho
3. O estado atual do semáforo é impresso no console.

## 📎 Mapeamento dos Pinos

| Cor do LED  | Pino do Pico |
|-------------|-------------|
| Vermelho    | GP11        |
| Amarelo     | GP12        |
| Verde       | GP13        |

## 🚀 Como Rodar o Projeto

### 1️⃣ Clonar o Repositório

```sh
git clone https://github.com/camillerodriguees/semaforo-one.git

