#include "Gallows.h"
#include <chrono>
void Gallows::Print() {
	{
		int user1;// ввод пользователя для выбора сложности
		stop =rand() % 80;// выбирает случайное слово из файла
		char buffer[100];
		char str[100];
		ifstream file;
		file.open(worlduser);
		if (!file.is_open())
			cout << "Ошибка открытия файла\n";
		else {
			int count = 0;// счетчик слов из файла
			while (!file.eof()) {
				file >> str;
				if (count == stop) // при совпадении счетчика и случайно сгенирированного цифры выбирает слово из файла
					break;
				count++;
			}
			strcpy_s(buffer, str);// слово записывается в буффер
			file.close();
		}
		cout << "Игра Виселица. Нужно отдагать зашифрованное слово по буквам. Максимальное количество ошибок 10\n";
		cout << "Выберите сложность: \n1-легкий(с подказкой в виде одной открытой буквы) \n2-сложный(все буквы закрыты)\n";
		cin >> user1;
		switch (user1)// выбор сложности
		{
		case 1:
			Help(buffer);
			Interface(buffer, str);
			break;
		case 2:
			NoHelp(buffer);
			Interface(buffer, str);
			break;
		default:
			cout << "Неправильное действие. Попробуйте еще\n";
			break;
		}
	}
}

char Gallows::Help(char world[])// ф-ия для шифрования слова в легкой сложности
{
	int number = 0;
		 stop = rand() % strlen(world);// случайно выбранная буква 
		for (int i = 0; i < strlen(world); i++) {//проверка на повторяющиеся буквы в слове, если сгенирированая цифра попадает на букву которая встречается в слове не один раз, то цифра генерируется пока не будет выполнено условие
			for (int j = i + 1; j < strlen(world); j++)
				if (world[i] == world[j] && (i==stop || j==stop)) {
					stop = rand() % strlen(world);
					i = 0;
				}
		}
			for (int i = 0; i < strlen(world); i++) {
				if (stop != i)
					world[i] = '*';
				cout << world[i];
			}
			size = strlen(world) - 1;
			return world[strlen(world)],size;//возвращает слово и размер с одгой известной буквой
	}

char Gallows::NoHelp(char world[])// для сложного уровня
{
	for (int i = 0; i < strlen(world); i++) {
		world[i] = '*';
		cout << world[i];
	}
	size = strlen(world);
	return world[strlen(world)],size;
}

void Gallows::Interface(char world[], char str[])
{
	auto start = chrono::steady_clock::now();//начало отсчета времени
	cout << "\nВведите буквы(русские)\n";
	int attempt = 0;// счетчик ошибок
	int i = 0;//счетчик отгаданных букв
	for (; i < size;) {
		if (i >= size) {
			cout << "ВЫ ВЫИГРАЛИ!\n";
			break;
		}
		else if (attempt == 10)
			break;
		cin >> user;
		for (int j = 0; j < strlen(str); j++) {
			for (int k = j + 1; k < strlen(str); k++) {//проверка на повторяющиеся буквы
				if (str[j] == str[k] && str[k] == user && world[k]!=user) {
					world[k] = user;
					++i;
				}
			}
			if (str[j] == user && world[j] != user) {//проверка на совпадении правильности
				world[j] = user;
				cout << world << endl;
				arr[j] = user;
				++i;
				break;
			}
			else if ( j == strlen(str) - 1 || world[j]==user) {//ошибка
				arr1[attempt] = user;
				attempt++;
				if (attempt == 1) {
					cout << "____________" << endl;
					break;
				}
				else if (attempt == 2) {
					cout << "      |      " << endl;
					cout << "      |      " << endl;
					cout << "      |      " << endl;
					cout << "      |      " << endl;
					cout << "      |      " << endl;
					cout << "      |      " << endl;
					cout << "______|______" << endl;
					break;
				}
				else if (attempt == 3) {
					cout << "      ____________" << endl;
					cout << "      |      " << endl;
					cout << "      |      " << endl;
					cout << "      |      " << endl;
					cout << "      |      " << endl;
					cout << "      |      " << endl;
					cout << "      |      " << endl;
					cout << "______|______" << endl;
					break;
				}
				else if (attempt == 4) {
					cout << "      ____________" << endl;
					cout << "      |           |" << endl;
					cout << "      |           |" << endl;
					cout << "      |      " << endl;
					cout << "      |      " << endl;
					cout << "      |      " << endl;
					cout << "      |      " << endl;
					cout << "______|______" << endl;
					break;
				}
				else if (attempt == 5) {
					cout << "      ____________" << endl;
					cout << "      |           |" << endl;
					cout << "      |           |" << endl;
					cout << "      |           @" << endl;
					cout << "      |      " << endl;
					cout << "      |      " << endl;
					cout << "      |      " << endl;
					cout << "______|______" << endl;
					break;
				}
				else if (attempt == 6) {
					cout << "      ____________" << endl;
					cout << "      |           |" << endl;
					cout << "      |           |" << endl;
					cout << "      |           @" << endl;
					cout << "      |          ( )" << endl;
					cout << "      |      " << endl;
					cout << "      |      " << endl;
					cout << "______|______" << endl;
					break;
				}
				else if (attempt == 7) {
					cout << "      ____________" << endl;
					cout << "      |           |" << endl;
					cout << "      |           |" << endl;
					cout << "      |           @" << endl;
					cout << "      |          ( )\\" << endl;
					cout << "      |            " << endl;
					cout << "      |      " << endl;
					cout << "______|______" << endl;
					break;
				}
				else if (attempt == 8) {
					cout << "      ____________" << endl;
					cout << "      |           |" << endl;
					cout << "      |           |" << endl;
					cout << "      |           @" << endl;
					cout << "      |         /( )\\" << endl;
					cout << "      |            " << endl;
					cout << "      |      " << endl;
					cout << "______|______" << endl;
					break;
				}
				else if (attempt == 9) {
					cout << "      ____________" << endl;
					cout << "      |           |" << endl;
					cout << "      |           |" << endl;
					cout << "      |           @" << endl;
					cout << "      |         /( )\\" << endl;
					cout << "      |            \\" << endl;
					cout << "      |      " << endl;
					cout << "______|______" << endl;
					break;
				}
				else if (attempt == 10) {
					cout << "      ____________" << endl;
					cout << "      |           |" << endl;
					cout << "      |           |" << endl;
					cout << "      |           @" << endl;
					cout << "      |         /( )\\" << endl;
					cout << "      |          / \\" << endl;
					cout << "      |      " << endl;
					cout << "______|______" << endl;
					cout << "Игра окончена\n";
					break;
				}
			}
		}
	}
	auto end = chrono::steady_clock::now();//окончание отсчета времени
	cout << "\nСлово " << str << endl;
	cout << "Введенные буквы \n";
	for (int j = 0; j < 25; j++)
		cout << arr[j] << " " << arr1[j] << " ";
	cout << "\nСтатистика:\nУгаданных букв " << i << " из " << size << endl;
	cout << "Ошибок " << attempt;
	cout << "\nВаше время: "
		<< chrono::duration_cast<chrono::seconds>(end - start).count()
		<< " сек.";
	}