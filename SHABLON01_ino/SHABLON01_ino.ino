//-слэш - разрез /слэш в гору \слэш с горы
//Маркеры памяти
//void - пустота - космос - ничего - не использует память
//int  - интеджер - целое - память для чисел 12345
//char - символы - буквы
//long - для всего
//------setup - Название
//------() - круглые скобки (SHIFT+9, SHIFT+0) настройки
//------{} - фигурные скобки (SHIFT+Х, SHIFT+Ъ) Начало и конец
//------[] - квадратные скобки 
//Сложных приказов
const byte dynPin = 2;
//-------------------
int lastButtonState; [2](https://arduinogetstarted.com/faq/arduino-how-to-detect-button-press-event)
//----------------------------------------
//

// мини игра нажми на кнопку - угадай последовательность
// загараются пиксели разного цвета, нужно нажать на кнопку такого цвета.

//способности:
//включить пиксель на матрице

//a номер
//b номер
void pix(int a, int b) {
  
}
//проиграть цепочку цветов
void cvet(){

}

int k[5]={0,0,0,0,0}

//проверить кнопку
void knop(int a) {
 // читаем значение кнопки
    int buttonState = digitalRead(a+1);
    if (lastButtonState != buttonState) {  // состояние изменилось
        delay(50);  // время антидребезга
        if (buttonState == LOW)
            Serial.println("Нажатие кнопки ");
             Serial.print(a);
            k[a]=1;
        else
            Serial.println("Отпускание кнопки ");
             Serial.print(a);

            
        lastButtonState = buttonState;
    }
}

void reset(){
  for (int a=1; a<#k; a++){
    k[a]=0;
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
  if (s==1){
    for (int a=1; a<#k; a++){
       if (k[a]==1){
        s=2;
        reset();
        break
       }
     }
  }
//------------
//состояния
  //ждать
  if (s==1){
    
  }
//
//работа

//1=красный
//2=зелёный
//3=синий
//4=белый
//5=ораневый

  if (s==2){
    //задать последовательнось на уровень 
    int cep[5]={1,2,3,4,5}
    //засветить последовательность
    for (int a=1; a<#cep; a++){
      pix(math.random(1,64),cep[a])
    }
    //захватить последовательность нажатий
    // int otv={}
      int otv={}
    // while (#otv<#cep){
      while (#onv<#cep){
    //   for (int a=1; a<#k; a++){
         for (int a=1; a<#)
    //    if (k[a]==1){

    //     otv[a]=a

    //     reset();

    //     break
          break
    //    }
        }
    //  }
       }
    // }
      }
    //сравнить результат изменить состояние на выиграл или проиграл
      
  }
//
// выиграл
  if (s==3){
    
  }
//
// проиграл
  if (s==4){
    
  }
//
// разряжен
  if (s==5){
    
  }
//
//------------

}