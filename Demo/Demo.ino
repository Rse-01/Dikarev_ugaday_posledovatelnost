import time
import random

# Предположим, что у вас есть библиотеки для работы с матрицей, кнопками и звуком
# Например:
# from neopixel import NeoPixel
# import board
# import digitalio

# Константы
COLORS = {
    'red': (255, 0, 0),
    'yellow': (255, 255, 0),
    'blue': (0, 0, 255),
    'green': (0, 255, 0),
    'white': (255, 255, 255),
    'orange': (255, 165, 0),
    'green_circle': (0, 255, 0),
    'red_cross': (255, 0, 0)
}

BUTTON_PINS = [/* список пинов для 5 кнопок */]
BUTTONS = []  # список объектов кнопок

PIXEL_PINS = [/* список пинов для матрицы */]
NUM_PIXELS = 64

# Инициализация устройств
def init():
    global pixels, buttons
    # Инициализация матрицы
    # pixels = NeoPixel(board.NEOPIXEL, NUM_PIXELS)
    # Инициализация кнопок
    # for pin in BUTTON_PINS:
    #     btn = digitalio.DigitalInOut(pin)
    #     btn.direction = digitalio.Direction.INPUT
    #     btn.pull = digitalio.Pull.DOWN
    #     BUTTONS.append(btn)
    pass

# Функция для включения пикселя по индексу и цвету
def set_pixel(index, color):
    # pixels[index] = color
    pass

# Функция для отображения всей последовательности
def show_sequence(sequence):
    for color_name in sequence:
        color = COLORS[color_name]
        for i in range(NUM_PIXELS):
            set_pixel(i, color)
        time.sleep(0.5)
        clear_pixels()
        time.sleep(0.2)

def clear_pixels():
    for i in range(NUM_PIXELS):
        set_pixel(i, (0,0,0))

# Проигрывание цепочки цветов (можно расширить)
def play_colors():
    sequence = [random.choice(list(COLORS.keys())[:-2]) for _ in range(5)]
    show_sequence(sequence)
    return sequence

# Проверка нажатия кнопки и возврат индекса нажатой кнопки или -1 если не нажата
def check_buttons():
    for idx, btn in enumerate(BUTTONS):
        if btn.value:
            return idx
    return -1

# Проигрывать звук (заглушка)
def play_sound(success=True):
    if success:
        # проиграть "успех"
        pass
    else:
        # проиграть "ошибка"
        pass

# Отображение результата: круг или крест
def show_result(success=True):
    if success:
        # показать зеленый круг
        for i in range(NUM_PIXELS):
            set_pixel(i, COLORS['green_circle'])
        play_sound(True)
        time.sleep(2)
        clear_pixels()
    else:
        # показать красный крест
        for i in range(NUM_PIXELS):
            set_pixel(i, COLORS['red_cross'])
        play_sound(False)
        time.sleep(2)
        clear_pixels()

# Основная логика игры
def game():
    state = 'wait'  # состояния: wait, work, win, lose
    
    while True:
        if state == 'wait':
            # Ждем нажатия любой кнопки для начала игры
            if check_buttons() != -1:
                state = 'work'
                sequence = play_colors()
                user_input = []
                print("Sequence shown. Awaiting user input.")
        
        elif state == 'work':
            index = check_buttons()
            if index != -1:
                user_input.append(index)
                print(f"Button {index} pressed.")
                time.sleep(0.3)  # debounce
                
                if len(user_input) == len(sequence):
                    if user_input == sequence:
                        show_result(success=True)
                        state = 'win'
                    else:
                        show_result(success=False)
                        state = 'lose'
        
        elif state == 'win':
            print("You won! Starting new game.")
            time.sleep(1)
            state = 'wait'
        
        elif state == 'lose':
            print("You lost! Starting new game.")
            time.sleep(1)
            state = 'wait'
        
        elif state == 'charge':
            # Зарядка устройства при оранжевом экране — реализуйте по необходимости.
            pass
        
        time.sleep(0.1)

# Запуск программы
if __name__ == '__main__':
    init()
    game()