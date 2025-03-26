//-слэш - разрез /слэш в гору \слэш с горы
//Маркеры памяти
//void - пустота - космос - ничего - не использует память
//int  - интеджер - целое - память для чисел 12345
//char - символы - буквы
//long - для всего
//------setup - Название
//------() - круглые скобки (SHIFT+9, SHIFT+0) настройки
//------{} - фигурные скобки (SHIFT+Х, SHIFT+Ъ) Начало и конец)
//Сложных приказов
const byte dynPin = 2;
//-------------------
#define BUTTON_PIN 7
int lastButtonState; [2](https://arduinogetstarted.com/faq/arduino-how-to-detect-button-press-event)
//----------------------------------------
//
//способности:
//включить пиксель на матрице
void pix() {
  
}
//проиграть цепочку цветов
void cvet(){

}

//проверить кнопку
void knop() {
 // читаем значение кнопки
    int buttonState = digitalRead(BUTTON_PIN);
    if (lastButtonState != buttonState) {  // состояние изменилось
        delay(50);  // время антидребезга
        if (buttonState == LOW)
            Serial.println("Нажатие кнопки");
        else
            Serial.println("Отпускание кнопки");
        lastButtonState = buttonState;
    }
}

//издать звук
void mus() {
  tone(dynPin, 100);  // генерируем звук с частотой 100 Гц [3](https://robotclass.ru/tutorials/arduino-speaker/)
    delay(100);  // пауза 500 миллисекунд
    noTone(dynPin);  // выключаем звук
    delay(900);  // снова пауза 500 мс
}
//показать результат
void res() {

}
void setup() {
  pinMode(dynPin, OUTPUT);  // настраиваем контакт №2 на выход [3](https://robotclass.ru/tutorials/arduino-speaker/

Serial.begin(9600);
    pinMode(BUTTON_PIN, INPUT_PULLUP);  // включаем внутренний подтягивающий резистор
    lastButtonState = digitalRead(BUTTON_PIN);

   int s=0;
}

}

void loop() {
//триггеры

//------------
//состояния
  //ждать
  if (s==1){
    
  }
//------------

}