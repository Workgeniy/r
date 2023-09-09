#include "Gallows.h"
#include <chrono>
void Gallows::Print() {
	{
		int user1;// ���� ������������ ��� ������ ���������
		stop =rand() % 80;// �������� ��������� ����� �� �����
		char buffer[100];
		char str[100];
		ifstream file;
		file.open(worlduser);
		if (!file.is_open())
			cout << "������ �������� �����\n";
		else {
			int count = 0;// ������� ���� �� �����
			while (!file.eof()) {
				file >> str;
				if (count == stop) // ��� ���������� �������� � �������� ���������������� ����� �������� ����� �� �����
					break;
				count++;
			}
			strcpy_s(buffer, str);// ����� ������������ � ������
			file.close();
		}
		cout << "���� ��������. ����� �������� ������������� ����� �� ������. ������������ ���������� ������ 10\n";
		cout << "�������� ���������: \n1-������(� ��������� � ���� ����� �������� �����) \n2-�������(��� ����� �������)\n";
		cin >> user1;
		switch (user1)// ����� ���������
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
			cout << "������������ ��������. ���������� ���\n";
			break;
		}
	}
}

char Gallows::Help(char world[])// �-�� ��� ���������� ����� � ������ ���������
{
	int number = 0;
		 stop = rand() % strlen(world);// �������� ��������� ����� 
		for (int i = 0; i < strlen(world); i++) {//�������� �� ������������� ����� � �����, ���� �������������� ����� �������� �� ����� ������� ����������� � ����� �� ���� ���, �� ����� ������������ ���� �� ����� ��������� �������
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
			return world[strlen(world)],size;//���������� ����� � ������ � ����� ��������� ������
	}

char Gallows::NoHelp(char world[])// ��� �������� ������
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
	auto start = chrono::steady_clock::now();//������ ������� �������
	cout << "\n������� �����(�������)\n";
	int attempt = 0;// ������� ������
	int i = 0;//������� ���������� ����
	for (; i < size;) {
		if (i >= size) {
			cout << "�� ��������!\n";
			break;
		}
		else if (attempt == 10)
			break;
		cin >> user;
		for (int j = 0; j < strlen(str); j++) {
			for (int k = j + 1; k < strlen(str); k++) {//�������� �� ������������� �����
				if (str[j] == str[k] && str[k] == user && world[k]!=user) {
					world[k] = user;
					++i;
				}
			}
			if (str[j] == user && world[j] != user) {//�������� �� ���������� ������������
				world[j] = user;
				cout << world << endl;
				arr[j] = user;
				++i;
				break;
			}
			else if ( j == strlen(str) - 1 || world[j]==user) {//������
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
					cout << "���� ��������\n";
					break;
				}
			}
		}
	}
	auto end = chrono::steady_clock::now();//��������� ������� �������
	cout << "\n����� " << str << endl;
	cout << "��������� ����� \n";
	for (int j = 0; j < 25; j++)
		cout << arr[j] << " " << arr1[j] << " ";
	cout << "\n����������:\n��������� ���� " << i << " �� " << size << endl;
	cout << "������ " << attempt;
	cout << "\n���� �����: "
		<< chrono::duration_cast<chrono::seconds>(end - start).count()
		<< " ���.";
	}