#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
using namespace std;

struct TollInformation
{
	string date = "";
	string carNumber = "";
	string ticketNumber = "";
};

class HeavyDutyQueue
{
	TollInformation * queue;
	TollInformation * leftCarQueue;
	int maxSize;
	int front;
	int rear;
	int leftCarQueueMaxSize;
	int leftCarQueueFront;
	int leftCarQueueRear;

	public:
		HeavyDutyQueue() {}

	void heavyDutyQueueInitializer(int size)
	{
		maxSize = size;
		leftCarQueueMaxSize = size;
		queue = new TollInformation[maxSize];
		leftCarQueue = new TollInformation[maxSize];
		front = -1;
		rear = -1;
		leftCarQueueFront = -1;
		leftCarQueueRear = -1;
	}

	void enQueue(TollInformation tollInformation)
	{
		if (rear == maxSize - 1)
		{
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "!! T H E   Q U E U E   I S   F U L L !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
		else if (front == -1 && rear == -1)
		{
			front = 0;
			rear = 0;
			queue[rear] = tollInformation;
		}
		else
		{
			rear++;
			queue[rear] = tollInformation;
		}
	}

	void leftCarEnQueue(TollInformation tollInformation)
	{
		if (leftCarQueueRear == leftCarQueueMaxSize - 1)
		{
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "!! T H E   Q U E U E   I S   F U L L !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
		else if (leftCarQueueFront == -1 && leftCarQueueRear == -1)
		{
			leftCarQueueFront = 0;
			leftCarQueueRear = 0;
			leftCarQueue[leftCarQueueRear] = tollInformation;
		}
		else
		{
			leftCarQueueRear++;
			leftCarQueue[leftCarQueueRear] = tollInformation;
		}
	}

	void deQueue()
	{
		if (front == -1 && rear == -1)
		{
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "!! T H E   Q U E U E   I S   E M P T Y !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
		else if (front == rear && front != -1)
		{
			leftCarEnQueue(queue[front]);
			front = -1;
			rear = -1;
		}
		else
		{
			leftCarEnQueue(queue[front]);
			front++;
		}
	}

	double calculateTotalEarningOfADay()
	{
		double totalEarningOfDay = 0.0;
		for (int count = 0; count <= rear; count++)
		{
			if (front == -1 && rear == -1)
			{
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "!! T H E   Q U E U E   I S   E M P T Y !!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			}
			else
				totalEarningOfDay += 700;
		}

		return totalEarningOfDay;
	}

	void printQueue()
	{
		if (front == -1 && rear == -1)
		{
			system("CLS");
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "!! T H E   Q U E U E   I S   E M P T Y !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			system("PAUSE");
		}
		else
		{
			for (int count = front; count <= rear; count++)
			{
				system("CLS");
				cout << "||=======================================================||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
				cout << "|| H E A V Y - D U T Y   T O L L   I N F O R M A T I O N ||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
				cout << "||=======================================================||" << endl;
				cout << "|| C A R    N U M B E R      :   " << queue[count].carNumber << endl;
				cout << "||-------------------------------------------------------||" << endl;
				cout << "|| D A T E                   :   " << queue[count].date << endl;
				cout << "||-------------------------------------------------------||" << endl;
				cout << "|| T I C K E T   N U M B E R :   " << queue[count].ticketNumber << endl;
				cout << "||=======================================================||" << endl;
				system("PAUSE");
			}
		}
	}

	void checkIfItHasTheRequiredCar(string carNumber)
	{
		for (int count = front; count <= rear; count++)
		{
			if (carNumber == queue[count].carNumber)
			{
				system("CLS");
				cout << "||=======================================================||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
				cout << "|| H E A V Y - D U T Y   T O L L   I N F O R M A T I O N ||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
				cout << "||=======================================================||" << endl;
				cout << "|| C A R    N U M B E R      :   " << queue[count].carNumber << endl;
				cout << "||-------------------------------------------------------||" << endl;
				cout << "|| D A T E                   :   " << queue[count].date << endl;
				cout << "||-------------------------------------------------------||" << endl;
				cout << "|| T I C K E T   N U M B E R :   " << queue[count].ticketNumber << endl;
				cout << "||=======================================================||" << endl;
				system("PAUSE");
			}
		}

		for (int count = leftCarQueueFront; count <= leftCarQueueRear; count++)
		{
			if (carNumber == leftCarQueue[count].carNumber)
			{
				system("CLS");
				cout << "||=================================||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><||" << endl;
				cout << "|| T O L L   I N F O R M A T I O N ||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><||" << endl;
				cout << "||=================================||" << endl;
				cout << "|| T H E   C A R   H A S   L E F T ||" << endl;
				cout << "||=================================||" << endl;
				system("PAUSE");
			}
		}
	}

	void printLeftCarQueue()
	{
		for (int count = leftCarQueueFront; count <= leftCarQueueRear; count++)
		{
			system("CLS");
			cout << "||=======================================================||" << endl;
			cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
			cout << "|| H E A V Y - D U T Y   T O L L   I N F O R M A T I O N ||" << endl;
			cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
			cout << "||=======================================================||" << endl;
			cout << "|| C A R    N U M B E R      :   " << leftCarQueue[count].carNumber << endl;
			cout << "||-------------------------------------------------------||" << endl;
			cout << "|| D A T E                   :   " << leftCarQueue[count].date << endl;
			cout << "||-------------------------------------------------------||" << endl;
			cout << "|| T I C K E T   N U M B E R :   " << leftCarQueue[count].ticketNumber << endl;
			cout << "||=======================================================||" << endl;
			system("PAUSE");
		}
	}
};

class MediumDutyQueue
{
	TollInformation * queue;
	TollInformation * leftCarQueue;
	int maxSize;
	int front;
	int rear;
	int leftCarQueueMaxSize;
	int leftCarQueueFront;
	int leftCarQueueRear;

	public:
		MediumDutyQueue() {}

	void mediumDutyQueueInitializer(int size)
	{
		maxSize = size;
		leftCarQueueMaxSize = size;
		queue = new TollInformation[maxSize];
		leftCarQueue = new TollInformation[maxSize];
		front = -1;
		rear = -1;
		leftCarQueueFront = -1;
		leftCarQueueRear = -1;
	}

	void enQueue(TollInformation tollInformation)
	{
		if (rear == maxSize - 1)
		{
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "!! T H E   Q U E U E   I S   F U L L !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
		else if (front == -1 && rear == -1)
		{
			front = 0;
			rear = 0;
			queue[rear] = tollInformation;
		}
		else
		{
			rear++;
			queue[rear] = tollInformation;
		}
	}

	void leftCarEnQueue(TollInformation tollInformation)
	{
		if (leftCarQueueRear == leftCarQueueMaxSize - 1)
		{
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "!! T H E   Q U E U E   I S   F U L L !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
		else if (leftCarQueueFront == -1 && leftCarQueueRear == -1)
		{
			leftCarQueueFront = 0;
			leftCarQueueRear = 0;
			leftCarQueue[leftCarQueueRear] = tollInformation;
		}
		else
		{
			leftCarQueueRear++;
			leftCarQueue[leftCarQueueRear] = tollInformation;
		}
	}

	void deQueue()
	{
		if (front == -1 && rear == -1)
		{
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "!! T H E   Q U E U E   I S   E M P T Y !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
		else if (front == rear && front != -1)
		{
			leftCarEnQueue(queue[front]);
			front = -1;
			rear = -1;
		}
		else
		{
			leftCarEnQueue(queue[front]);
			front++;
		}
	}

	double calculateTotalEarningOfADay()
	{
		double totalEarningOfDay = 0.0;
		for (int count = 0; count <= rear; count++)
		{
			if (front == -1 && rear == -1)
			{
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "!! T H E   Q U E U E   I S   E M P T Y !!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			}
			else
				totalEarningOfDay += 400;
		}

		return totalEarningOfDay;
	}

	void printQueue()
	{
		for (int count = front; count <= rear; count++)
		{
			system("CLS");
			cout << "||=========================================================||" << endl;
			cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
			cout << "|| M E D I U M - D U T Y   T O L L   I N F O R M A T I O N ||" << endl;
			cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
			cout << "||=========================================================||" << endl;
			cout << "|| C A R    N U M B E R      :   " << queue[count].carNumber << endl;
			cout << "||---------------------------------------------------------||" << endl;
			cout << "|| D A T E                   :   " << queue[count].date << endl;
			cout << "||---------------------------------------------------------||" << endl;
			cout << "|| T I C K E T   N U M B E R :   " << queue[count].ticketNumber << endl;
			cout << "||=========================================================||" << endl;
			system("PAUSE");
		}
	}

	void checkIfItHasTheRequiredCar(string carNumber)
	{
		for (int count = front; count <= rear; count++)
		{
			if (carNumber == queue[count].carNumber)
			{
				system("CLS");
				cout << "||=========================================================||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
				cout << "|| M E D I U M - D U T Y   T O L L   I N F O R M A T I O N ||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
				cout << "||=========================================================||" << endl;
				cout << "|| C A R    N U M B E R      :   " << queue[count].carNumber << endl;
				cout << "||---------------------------------------------------------||" << endl;
				cout << "|| D A T E                   :   " << queue[count].date << endl;
				cout << "||---------------------------------------------------------||" << endl;
				cout << "|| T I C K E T   N U M B E R :   " << queue[count].ticketNumber << endl;
				cout << "||=========================================================||" << endl;
				system("PAUSE");
			}
		}

		for (int count = leftCarQueueFront; count <= leftCarQueueRear; count++)
		{
			if (carNumber == leftCarQueue[count].carNumber)
			{
				system("CLS");
				cout << "||=================================||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><||" << endl;
				cout << "|| T O L L   I N F O R M A T I O N ||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><||" << endl;
				cout << "||=================================||" << endl;
				cout << "|| T H E   C A R   H A S   L E F T ||" << endl;
				cout << "||=================================||" << endl;
				system("PAUSE");
			}
		}
	}

	void printLeftCarQueue()
	{
		for (int count = leftCarQueueFront; count <= leftCarQueueRear; count++)
		{
			system("CLS");
			cout << "||=================================||" << endl;
			cout << "||<><><><><><><><><><><><><><><><><||" << endl;
			cout << "|| T O L L   I N F O R M A T I O N ||" << endl;
			cout << "||<><><><><><><><><><><><><><><><><||" << endl;
			cout << "||=================================||" << endl;
			cout << "|| C A R    N U M B E R      :   " << leftCarQueue[count].carNumber << endl;
			cout << "||---------------------------------||" << endl;
			cout << "|| D A T E                   :   " << leftCarQueue[count].date << endl;
			cout << "||---------------------------------||" << endl;
			cout << "|| T I C K E T   N U M B E R :   " << leftCarQueue[count].ticketNumber << endl;
			cout << "||=================================||\n" << endl;
			system("PAUSE");
		}
	}
};

class LightDutyQueue
{
	TollInformation * queue;
	TollInformation * leftCarQueue;
	int maxSize;
	int front;
	int rear;
	int leftCarQueueMaxSize;
	int leftCarQueueFront;
	int leftCarQueueRear;

	public:
		LightDutyQueue() {}

	void lightDutyQueueInitializer(int size)
	{
		maxSize = size;
		leftCarQueueMaxSize = size;
		queue = new TollInformation[maxSize];
		leftCarQueue = new TollInformation[maxSize];
		front = -1;
		rear = -1;
		leftCarQueueFront = -1;
		leftCarQueueRear = -1;
	}

	void enQueue(TollInformation tollInformation)
	{
		if (rear == maxSize - 1)
		{
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "!! T H E   Q U E U E   I S   F U L L !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
		else if (front == -1 && rear == -1)
		{
			front = 0;
			rear = 0;
			queue[rear] = tollInformation;
		}
		else
		{
			rear++;
			queue[rear] = tollInformation;
		}
	}

	void leftCarEnQueue(TollInformation tollInformation)
	{
		if (leftCarQueueRear == leftCarQueueMaxSize - 1)
		{
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "!! T H E   Q U E U E   I S   F U L L !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
		else if (leftCarQueueFront == -1 && leftCarQueueRear == -1)
		{
			leftCarQueueFront = 0;
			leftCarQueueRear = 0;
			leftCarQueue[leftCarQueueRear] = tollInformation;
		}
		else
		{
			leftCarQueueRear++;
			leftCarQueue[leftCarQueueRear] = tollInformation;
		}
	}

	void deQueue()
	{
		if (front == -1 && rear == -1)
		{
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "!! T H E   Q U E U E   I S   E M P T Y !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
		else if (front == rear && front != -1)
		{
			leftCarEnQueue(queue[front]);
			front = -1;
			rear = -1;
		}
		else
		{
			leftCarEnQueue(queue[front]);
			front++;
		}
	}

	double calculateTotalEarningOfADay()
	{
		double totalEarningOfDay = 0.0;
		for (int count = 0; count <= rear; count++)
		{
			if (front == -1 && rear == -1)
			{
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "!! T H E   Q U E U E   I S   E M P T Y !!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				break;
			}
			else
				totalEarningOfDay += 200;
		}

		return totalEarningOfDay;
	}

	void printQueue()
	{
		if (front == -1 && rear == -1)
		{
			system("CLS");
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "!! T H E   Q U E U E   I S   E M P T Y !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			system("PAUSE");
		}
		else
		{
			for (int count = front; count <= rear; count++)
			{
				system("CLS");
				cout << "||=======================================================||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
				cout << "|| L I G H T - D U T Y   T O L L   I N F O R M A T I O N ||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
				cout << "||=======================================================||" << endl;
				cout << "|| C A R    N U M B E R      :   " << queue[count].carNumber << endl;
				cout << "||-------------------------------------------------------||" << endl;
				cout << "|| D A T E                   :   " << queue[count].date << endl;
				cout << "||-------------------------------------------------------||" << endl;
				cout << "|| T I C K E T   N U M B E R :   " << queue[count].ticketNumber << endl;
				cout << "||=======================================================||" << endl;
				system("PAUSE");
			}
		}
	}

	void checkIfItHasTheRequiredCar(string carNumber)
	{
		for (int count = front; count <= rear; count++)
		{
			if (carNumber == queue[count].carNumber)
			{
				system("CLS");
				cout << "||=======================================================||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
				cout << "|| L I G H T - D U T Y   T O L L   I N F O R M A T I O N ||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
				cout << "||=======================================================||" << endl;
				cout << "|| C A R    N U M B E R      :   " << queue[count].carNumber << endl;
				cout << "||-------------------------------------------------------||" << endl;
				cout << "|| D A T E                   :   " << queue[count].date << endl;
				cout << "||-------------------------------------------------------||" << endl;
				cout << "|| T I C K E T   N U M B E R :   " << queue[count].ticketNumber << endl;
				cout << "||=======================================================||" << endl;
				system("PAUSE");
			}
		}

		for (int count = leftCarQueueFront; count <= leftCarQueueRear; count++)
		{
			if (carNumber == leftCarQueue[count].carNumber)
			{
				system("CLS");
				cout << "||=================================||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><||" << endl;
				cout << "|| T O L L   I N F O R M A T I O N ||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><||" << endl;
				cout << "||=================================||" << endl;
				cout << "|| T H E   C A R   H A S   L E F T ||" << endl;
				cout << "||=================================||" << endl;
				system("PAUSE");
			}
		}
	}

	void printLeftCarQueue()
	{
		if (leftCarQueueFront == -1 && leftCarQueueRear == -1)
		{
			system("CLS");
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "!! T H E   Q U E U E   I S   E M P T Y !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			system("PAUSE");
		}
		else
		{
			for (int count = leftCarQueueFront; count <= leftCarQueueRear; count++)
			{
				system("CLS");
				cout << "||=================================||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><||" << endl;
				cout << "|| T O L L   I N F O R M A T I O N ||" << endl;
				cout << "||<><><><><><><><><><><><><><><><><||" << endl;
				cout << "||=================================||" << endl;
				cout << "|| C A R    N U M B E R      :   " << leftCarQueue[count].carNumber << endl;
				cout << "||---------------------------------||" << endl;
				cout << "|| D A T E                   :   " << leftCarQueue[count].date << endl;
				cout << "||---------------------------------||" << endl;
				cout << "|| T I C K E T   N U M B E R :   " << leftCarQueue[count].ticketNumber << endl;
				cout << "||=================================||\n" << endl;
				system("PAUSE");
			}
		}
	}
};

int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	HeavyDutyQueue heavyDutyQueue;
	MediumDutyQueue mediumDutyQueue;
	LightDutyQueue lightDutyQueue;
	string temporaryString;
	int tollInformationCount;
	double totalEarningFromHeavyDutyVehicle = 0.0;
	double totalEarningFromMediumDutyVehicle = 0.0;
	double totalEarningFromLightDutyVehicle = 0.0;
	int status = 0;
	do {
		system("CLS");
		cout << "
||=================================================================================================================||
||<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><||
||=================================================================================================================||
||  _____ ___  _    _      __  __   _   _  _   _   ___ ___ __  __ ___ _  _ _____   _____   _____ _____ ___ __  __  ||
|| |_   _/ _ \| |  | |    |  \/  | /_\ | \| | /_\ / __| __|  \/  | __| \| |_   _| / __\ \ / / __|_   _| __|  \/  | ||
||   | || (_) | |__| |__  | |\/| |/ _ \| .` |/ _ \ (_ | _|| |\/| | _|| .` | | |   \__ \\ V /\__ \ | | | _|| |\/| | ||
||   |_| \___/|____|____| |_|  |_/_/ \_\_|\_/_/ \_\___|___|_|  |_|___|_|\_| |_|   |___/ |_| |___/ |_| |___|_|  |_| ||
||                                                                                                                 ||
||=================================================================================================================||
||<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><||
||=================================================================================================================||
)";
		cout << setw(80) << "||=============================================||" << endl;
		cout << setw(80) << "|| I N P U T   Y O U R   S T A T U S :         ||" << endl;
		cout << setw(80) << "||---------------------------------------------||" << endl;
		cout << setw(80) << "|| 1 .   A D M I N                             ||" << endl;
		cout << setw(80) << "||---------------------------------------------||" << endl;
		cout << setw(80) << "|| 2 .   E M P L O Y E E                       ||" << endl;
		cout << setw(80) << "||---------------------------------------------||" << endl;
		cout << setw(80) << "|| 3 .   E X I T                               ||" << endl;
		cout << setw(80) << "||=============================================||" << endl;
		cout << setw(42) << "||----->   ";
		do {
			cin >> status;
			if (status != 1 && status != 2 && status != 3)
			{
				cout << "||=============================================||" << endl;
				cout << "|| I N P U T   T H E   S E R I A L   N U M B E R   F R O M   1   T O   3 . . ." << endl;
				cout << "||----->   ";
			}
		} while (status != 1 && status != 2 && status != 3);
		switch (status)
		{
			case 1:
				{
					system("CLS");
					string username;
					string password;
					do {
						cout << "||=============================================||" << endl;
						cout << "||><><><><><><><><><><><><><><><><><><><><><><>||" << endl;
						cout << "||                 L O G   I N                 ||" << endl;
						cout << "||><><><><><><><><><><><><><><><><><><><><><><>||" << endl;
						cout << "||=============================================||" << endl;
						cout << "||=============================================||" << endl;
						cout << "|| U S E R N A M E :   ";
						cin >> username;
						cout << "||---------------------------------------------||" << endl;
						cout << "|| P A S S W O R D :   ";
						cin >> password;
						cout << "||=============================================||" << endl;
						if (username != "admin" && password != "admin")
						{
							cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
							cout << "!! U S E R N A M E   O R   P A S S W O R D   D O E S   N O T   M A T C H!!" << endl;
							cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
							cout << "|| P L E A S E   I N P U T   A G A I N . . . \n" << endl;
						}
					} while (username != "admin" && password != "admin");
					cout << "||=============================================||" << endl;
					cout << "||><><><><><><><><><><><><><><><><><><><><><><>||" << endl;
					cout << "||     L O G   I N   S U C C E S S F U L       ||" << endl;
					cout << "||><><><><><><><><><><><><><><><><><><><><><><>||" << endl;
					cout << "||=============================================||" << endl;
					system("PAUSE");
					int adminChoice = 0;
					do {
						system("CLS");
						cout << "||=================================================================||" << endl;
						cout << "||><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>||" << endl;
						cout << "||                       A D M I N   P A N E L                     ||" << endl;
						cout << "||><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>||" << endl;
						cout << "||=================================================================||" << endl;
						cout << "|| I N P U T  W H A T   Y O U   W A N N A  L I K E   T O   D O :   ||" << endl;
						cout << "||-----------------------------------------------------------------||" << endl;
						cout << "|| 1 .   G E T   I N F O R M A T I O N   O F    A   V E H I C L E  ||" << endl;
						cout << "||-----------------------------------------------------------------||" << endl;
						cout << "|| 2 .   G E T   I N F O R M A T I O N   O F    Q U E U E          ||" << endl;
						cout << "||-----------------------------------------------------------------||" << endl;
						cout << "|| 3 .   C A L C U L A T E   T O T A L   E A R N I N G   O F       ||" << endl;
						cout << "||       A   D A Y   O F   I N D I V I D U A L   C O U N T E R S   ||" << endl;
						cout << "||-----------------------------------------------------------------||" << endl;
						cout << "|| 4 .   C A L C U L A T E   T O T A L   E A R N I N G   O F       ||" << endl;
						cout << "||       A   D A Y   O F   A L L   C O U N T E R S                 ||" << endl;
						cout << "||-----------------------------------------------------------------||" << endl;
						cout << "|| 5 .   G E T   I N F O R M A T I O N   O F   V E H C L E S       ||" << endl;
						cout << "||       T H A T   H A V E   L E F T                               ||" << endl;
						cout << "||-----------------------------------------------------------------||" << endl;
						cout << "|| 6 .   E X I T                                                   ||" << endl;
						cout << "||-----------------------------------------------------------------||" << endl;
						do {
							cout << "|| ----->   ";
							cin >> adminChoice;
							if (adminChoice != 1 && adminChoice != 2 && adminChoice != 3 && adminChoice != 4 && adminChoice != 5 && adminChoice != 6)
							{
								cout << "\n||=================================================================||" << endl;
								cout << "|| I N P U T   T H E   S E R I A L   N U M B E R   F R O M   1   T O   6 . . ." << endl;
							}
						} while (adminChoice != 1 && adminChoice != 2 && adminChoice != 3 && adminChoice != 4 && adminChoice != 5 && adminChoice != 6);
						switch (adminChoice)
						{
							case 1:
								{
									system("CLS");
									cout << "||=================================================================||" << endl;
									cout << "||><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>||" << endl;
									cout << "||                       A D M I N   P A N E L                     ||" << endl;
									cout << "||><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>||" << endl;
									cout << "||=================================================================||" << endl;
									cout << "|| I N P U T   C A R   N U M B E R :   ";
									getline(cin, temporaryString);
									string carNumber = "";
									getline(cin, carNumber);
									heavyDutyQueue.checkIfItHasTheRequiredCar(carNumber);
									mediumDutyQueue.checkIfItHasTheRequiredCar(carNumber);
									lightDutyQueue.checkIfItHasTheRequiredCar(carNumber);
									break;
								}

							case 2:
								{
									system("CLS");
									cout << "||=================================================================||" << endl;
									cout << "||><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>||" << endl;
									cout << "||                       A D M I N   P A N E L                     ||" << endl;
									cout << "||><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>||" << endl;
									cout << "||=================================================================||" << endl;
									cout << "||=================================================================||" << endl;
									cout << "|| I N P U T   T H E   V E H  I C L E   T Y P E :                  ||" << endl;
									cout << "||=================================================================||" << endl;
									cout << "|| 1 .   H E A V Y - D U T Y   V E H I C L E                       ||" << endl;
									cout << "||-----------------------------------------------------------------||" << endl;
									cout << "|| 2 .   M E D I U M - D U T Y   V E H I C L E                     ||" << endl;
									cout << "||-----------------------------------------------------------------||" << endl;
									cout << "|| 3 .   L I G H T - D U T Y   V E H I C L E                       ||" << endl;
									cout << "||-----------------------------------------------------------------||" << endl;
									int vehicleType = 0;
									do {
										cout << "|| ----->   ";
										cin >> vehicleType;
										if (vehicleType != 1 && vehicleType != 2 && vehicleType != 3)
										{
											cout << "\n||=================================================================||" << endl;
											cout << "|| I N P U T   T H E   S E R I A L   N U M B E R   F R O M   1   T O   3 . . ." << endl;
										}
									} while (vehicleType != 1 && vehicleType != 2 && vehicleType != 3);
									switch (vehicleType)
									{
										case 1:
											{
												heavyDutyQueue.printQueue();
												break;
											}

										case 2:
											{
												mediumDutyQueue.printQueue();
												break;
											}

										case 3:
											{
												lightDutyQueue.printQueue();
												break;
											}
									}

									break;
								}

							case 3:
								{
									system("CLS");
									cout << "||=================================================================||" << endl;
									cout << "||><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>||" << endl;
									cout << "||                       A D M I N   P A N E L                     ||" << endl;
									cout << "||><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>||" << endl;
									cout << "||=================================================================||" << endl;
									cout << "||=================================================================||" << endl;
									cout << "|| I N P U T   T H E   V E H  I C L E   T Y P E :                  ||" << endl;
									cout << "||=================================================================||" << endl;
									cout << "|| 1 .   H E A V Y - D U T Y   V E H I C L E                       ||" << endl;
									cout << "||-----------------------------------------------------------------||" << endl;
									cout << "|| 2 .   M E D I U M - D U T Y   V E H I C L E                     ||" << endl;
									cout << "||-----------------------------------------------------------------||" << endl;
									cout << "|| 3 .   L I G H T - D U T Y   V E H I C L E                       ||" << endl;
									cout << "||-----------------------------------------------------------------||" << endl;
									int vehicleType = 0;
									do {
										cout << "|| ----->   ";
										cin >> vehicleType;
										if (vehicleType != 1 && vehicleType != 2 && vehicleType != 3)
										{
											cout << "\n||=================================================================||" << endl;
											cout << "|| I N P U T   T H E   S E R I A L   N U M B E R   F R O M   1   T O   3 . . ." << endl;
										}
									} while (vehicleType != 1 && vehicleType != 2 && vehicleType != 3);
									switch (vehicleType)
									{
										case 1:
											{
												cout << "\n||=================================================================||" << endl;
												cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
												cout << "|| T O T A L   E A R N I N G   F R O M   H E A V Y - D U T Y   V E H I C L E   I S :   " << totalEarningFromHeavyDutyVehicle << "   BDT" << endl;
												cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
												cout << "||=================================================================||" << endl;
												system("PAUSE");
												break;
											}

										case 2:
											{
												cout << "\n||=================================================================||" << endl;
												cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
												cout << "|| T O T A L   E A R N I N G   F R O M   M E D I U M - D U T Y   V E H I C L E   I S :   " << totalEarningFromMediumDutyVehicle << "   BDT" << endl;
												cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
												cout << "||=================================================================||" << endl;
												system("PAUSE");
												break;
											}

										case 3:
											{
												cout << "\n||=================================================================||" << endl;
												cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
												cout << "|| T O T A L   E A R N I N G   F R O M   L I G H T - D U T Y   V E H I C L E   I S :   " << totalEarningFromLightDutyVehicle << "   B D T" << endl;
												cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
												cout << "||=================================================================||" << endl;
												system("PAUSE");
												break;
											}
									}

									break;
								}

							case 4:
								{
									cout << "\n||=================================================================||" << endl;
									cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
									cout << "|| T O T A L   E A R N I N G   O F   A L L   C O U N T E R   I S :   " << (totalEarningFromHeavyDutyVehicle + totalEarningFromMediumDutyVehicle + totalEarningFromLightDutyVehicle) << "   B D T" << endl;
									cout << "||<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><||" << endl;
									cout << "||=================================================================||" << endl;
									system("PAUSE");
									break;
								}

							case 5:
								{
									heavyDutyQueue.printLeftCarQueue();
									mediumDutyQueue.printLeftCarQueue();
									lightDutyQueue.printLeftCarQueue();
								}
						}
					} while (adminChoice != 6);
					break;
				}

			case 2:
				{
					system("CLS");
					string username;
					string password;
					cout << "||=============================================||" << endl;
					cout << "||><><><><><><><><><><><><><><><><><><><><><><>||" << endl;
					cout << "||                 L O G   I N                 ||" << endl;
					cout << "||><><><><><><><><><><><><><><><><><><><><><><>||" << endl;
					cout << "||=============================================||" << endl;
					cout << "||=============================================||" << endl;
					cout << "|| U S E R N A M E :   ";
					cin >> username;
					cout << "||---------------------------------------------||" << endl;
					cout << "|| P A S S W O R D :   ";
					cin >> password;
					cout << "||=============================================||" << endl;
					cout << "||=============================================||" << endl;
					cout << "||><><><><><><><><><><><><><><><><><><><><><><>||" << endl;
					cout << "||     L O G   I N   S U C C E S S F U L       ||" << endl;
					cout << "||><><><><><><><><><><><><><><><><><><><><><><>||" << endl;
					cout << "||=============================================||" << endl;
					system("PAUSE");
					system("CLS");
					int employeeChoice = 0;
					do {
						system("CLS");
						cout << "||=================================================================||" << endl;
						cout << "||                   E M P L O Y E E   P A N E L                   ||" << endl;
						cout << "||=================================================================||" << endl;
						cout << "|| 1 .   I N P U T   T O L L   I N F O R M A T I O N               ||" << endl;
						cout << "||-----------------------------------------------------------------||" << endl;
						cout << "|| 2 .   I N P U T   H O W   M A N Y   C A R S   H A V E   L E F T ||" << endl;
						cout << "||-----------------------------------------------------------------||" << endl;
						cout << "|| 3 .   E X I T                                                   ||" << endl;
						cout << "||=================================================================||" << endl;
						do {
							cout << "|| ----->   ";
							cin >> employeeChoice;
							if (employeeChoice != 1 && employeeChoice != 2 && employeeChoice != 3)
							{
								cout << "\n||=================================================================||" << endl;
								cout << "|| I N P U T   T H E   S E R I A L   N U M B E R   F R O M   1   T O   3 . . ." << endl;
							}
						} while (employeeChoice != 1 && employeeChoice != 2 && employeeChoice != 3);
						system("CLS");
						switch (employeeChoice)
						{
							case 1:
								{
									cout << "||=================================================================||" << endl;
									cout << "||                   E M P L O Y E E   P A N E L                   ||" << endl;
									cout << "||=================================================================||" << endl;
									cout << "|| I N P U T   H O W   M A N Y   T O L L   I N F O R M A T I O N   Y O U   W A N T   T O   E N T E R :   ";
									cin >> tollInformationCount;
									heavyDutyQueue.heavyDutyQueueInitializer(tollInformationCount);
									mediumDutyQueue.mediumDutyQueueInitializer(tollInformationCount);
									lightDutyQueue.lightDutyQueueInitializer(tollInformationCount);
									for (int count = 0; count < tollInformationCount; count++)
									{
										system("CLS");
										cout << "||=================================================================||" << endl;
										cout << "|| I N P U T   T H E   V E H  I C L E   T Y P E :                  ||" << endl;
										cout << "||=================================================================||" << endl;
										cout << "|| 1 .   H E A V Y - D U T Y   V E H I C L E                       ||" << endl;
										cout << "||-----------------------------------------------------------------||" << endl;
										cout << "|| 2 .   M E D I U M - D U T Y   V E H I C L E                     ||" << endl;
										cout << "||-----------------------------------------------------------------||" << endl;
										cout << "|| 3 .   L I G H T - D U T Y   V E H I C L E                       ||" << endl;
										cout << "||-----------------------------------------------------------------||" << endl;
										int vehicleTypeChoice = 0;
										do {
											cout << "|| ----->   ";
											cin >> vehicleTypeChoice;
											if (vehicleTypeChoice != 1 && vehicleTypeChoice != 2 && vehicleTypeChoice != 3)
											{
												cout << "\n||=================================================================||" << endl;
												cout << "|| I N P U T   T H E   S E R I A L   N U M B E R   F R O M   1   T O   3 . . ." << endl;
											}
										} while (vehicleTypeChoice != 1 && vehicleTypeChoice != 2 && vehicleTypeChoice != 3);
										getline(cin, temporaryString);
										switch (vehicleTypeChoice)
										{
											case 1:
												{
													system("CLS");
													cout << R"(
||=========================================================================||
                       _____________________________________________________
                      |                                                     |
             _______  |                                                     |
            / _____ | |                                                     |
           / /(__) || |                                                     |
  ________/ / |OO| || |                                                     |
 |         |-------|| |                                                     |
(|         |     -.|| |_______________________                              |
 |  ____   \       ||_________||____________  |             ____      ____  |
/| / __ \   |______||     / __ \   / __ \   | |            / __ \    / __ \ |\
\|| /  \ |_______________| /  \ |_| /  \ |__| |___________| /  \ |__| /  \|_|/
   | () |                 | () |   | () |                  | () |    | () |
    \__/                   \__/     \__/                    \__/      \__/
---------------------------------------------------------------------------||
)" << '\n';
													cout << "||=========================================================================||" << endl;
													cout << "|| I N P U T   T H E   F O L L O W I N G   T O L L   I N F O R M A T I O N ||" << endl;
													cout << "||=========================================================================||" << endl;
													cout << "|| D A T E                   :   ";
													string date = "";
													getline(cin, date);
													cout << "||-------------------------------------------------------------------------||" << endl;
													cout << "|| C A R   N U M B E R       :   ";
													string carNumber = "";
													getline(cin, carNumber);
													cout << "||-------------------------------------------------------------------------||" << endl;
													cout << "|| T I C K E T   N U M B E R :   ";
													string ticketNumber = "";
													getline(cin, ticketNumber);
													cout << "||-------------------------------------------------------------------------||" << endl;
													struct TollInformation heavyDutyTollInformation;
													heavyDutyTollInformation.date = date;
													heavyDutyTollInformation.carNumber = carNumber;
													heavyDutyTollInformation.ticketNumber = ticketNumber;
													heavyDutyQueue.enQueue(heavyDutyTollInformation);
													cout << "||=========================================================================||" << endl;
													totalEarningFromHeavyDutyVehicle = heavyDutyQueue.calculateTotalEarningOfADay();
													break;
												}

											case 2:
												{
													system("CLS");
													cout << R"(
===========================================================================||
                       ____________________
                     //|           |        \
                   //  |           |          \
      ___________//____|___________|__________()\__________________
    /__________________|_=_________|_=___________|_________________{}
    [           ______ |           | .           | ==  ______      { }
  __[__        /##  ##\|           |             |    /##  ##\    _{# }_
 {_____)______|##    ##|___________|_____________|___|##    ##|__(______}
             /  ##__##                              /  ##__##        \
---------------------------------------------------------------------------||
)" << '\n';
													cout << "||=========================================================================||" << endl;
													cout << "|| I N P U T   T H E   F O L L O W I N G   T O L L   I N F O R M A T I O N ||" << endl;
													cout << "||=========================================================================||" << endl;
													cout << "|| D A T E                   :   ";
													string date = "";
													getline(cin, date);
													cout << "||-------------------------------------------------------------------------||" << endl;
													cout << "|| C A R   N U M B E R       :   ";
													string carNumber = "";
													getline(cin, carNumber);
													cout << "||-------------------------------------------------------------------------||" << endl;
													cout << "|| T I C K E T   N U M B E R :   ";
													string ticketNumber = "";
													getline(cin, ticketNumber);
													cout << "||-------------------------------------------------------------------------||" << endl;
													struct TollInformation mediumDutyTollInformation;
													mediumDutyTollInformation.date = date;
													mediumDutyTollInformation.carNumber = carNumber;
													mediumDutyTollInformation.ticketNumber = ticketNumber;
													mediumDutyQueue.enQueue(mediumDutyTollInformation);
													cout << "||=========================================================================||" << endl;
													totalEarningFromMediumDutyVehicle = mediumDutyQueue.calculateTotalEarningOfADay();
													break;
												}

											case 3:
												{
													system("CLS");
													cout << R"(
==================================================||
                                    ,-~ '|'
       ________________          o==]___|
      |                |            \ \
      |________________|            /\ \
 __  /  _,-----._      )           |  \ \.
|_||/_-~         `.   /()          |  /|]_|_____
  |//              \ |              \/ /_-~     ~-_
  //________________||              / //___________\
 //__|______________| \____________/ //___/-\ \~-_
((_________________/_-o___________/_//___/  /\,\  \
 |__/(  ((====)o===--~~                 (  ( (o/)  )
      \  ``==' /                         \  `--'  /
       `-.__,-'                           `-.__,-'
--------------------------------------------------||
)" << '\n';
													cout << "||=========================================================================||" << endl;
													cout << "|| I N P U T   T H E   F O L L O W I N G   T O L L   I N F O R M A T I O N ||" << endl;
													cout << "||=========================================================================||" << endl;
													cout << "|| D A T E                   :   ";
													string date = "";
													getline(cin, date);
													cout << "||-------------------------------------------------------------------------||" << endl;
													cout << "|| C A R   N U M B E R       :   ";
													string carNumber = "";
													getline(cin, carNumber);
													cout << "||-------------------------------------------------------------------------||" << endl;
													cout << "|| T I C K E T   N U M B E R :   ";
													string ticketNumber = "";
													getline(cin, ticketNumber);
													cout << "||-------------------------------------------------------------------------||" << endl;
													struct TollInformation lightDutyTollInformation;
													lightDutyTollInformation.date = date;
													lightDutyTollInformation.carNumber = carNumber;
													lightDutyTollInformation.ticketNumber = ticketNumber;
													lightDutyQueue.enQueue(lightDutyTollInformation);
													cout << "||=========================================================================||" << endl;
													totalEarningFromLightDutyVehicle = lightDutyQueue.calculateTotalEarningOfADay();
													break;
												}
										}
									}

									system("CLS");
									break;
								}

							case 2:
								{
									cout << "||=================================================================||" << endl;
									cout << "||                   E M P L O Y E E   P A N E L                   ||" << endl;
									cout << "||=================================================================||" << endl;
									cout << "|| I N P U T   H O W   M A N Y   C A R S   H A V E   L E F T :   ";
									int numberOfCarsThatHaveLeft = 0;
									cin >> numberOfCarsThatHaveLeft;
									system("CLS");
									for (int count = 0; count < numberOfCarsThatHaveLeft; count++)
									{
										system("cls");
										cout << "||=================================================================||" << endl;
										cout << "|| I N P U T   T H E   V E H  I C L E   T Y P E :                  ||" << endl;
										cout << "||=================================================================||" << endl;
										cout << "|| 1 .   H E A V Y - D U T Y   V E H I C L E                       ||" << endl;
										cout << "||-----------------------------------------------------------------||" << endl;
										cout << "|| 2 .   M E D I U M - D U T Y   V E H I C L E                     ||" << endl;
										cout << "||-----------------------------------------------------------------||" << endl;
										cout << "|| 3 .   L I G H T - D U T Y   V E H I C L E                       ||" << endl;
										cout << "||-----------------------------------------------------------------||" << endl;
										int vehicleTypeChoice = 0;
										do {
											cout << "|| ----->   ";
											cin >> vehicleTypeChoice;
											if (vehicleTypeChoice != 1 && vehicleTypeChoice != 2 && vehicleTypeChoice != 3)
											{
												cout << "\n||=================================================================||" << endl;
												cout << "|| I N P U T   T H E   S E R I A L   N U M B E R   F R O M   1   T O   3 . . ." << endl;
											}
										} while (vehicleTypeChoice != 1 && vehicleTypeChoice != 2 && vehicleTypeChoice != 3);
										switch (vehicleTypeChoice)
										{
											case 1:
												{
													heavyDutyQueue.deQueue();
													break;
												}

											case 2:
												{
													mediumDutyQueue.deQueue();
													break;
												}

											case 3:
												{
													lightDutyQueue.deQueue();
													break;
												}
										}
									}
								}
						}
					} while (employeeChoice != 3);
				}
		}
	} while (status != 3);
	return 0;
};