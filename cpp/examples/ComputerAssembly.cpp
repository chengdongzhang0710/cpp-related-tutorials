#include <iostream>
using namespace std;

class CPU
{
public:
	virtual void calculate() = 0;
};

class GPU
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void store() = 0;
};

class Computer
{
private:
	CPU* computerCPU;
	GPU* computerGPU;
	Memory* computerMemory;

public:
	Computer(CPU* cpu, GPU* gpu, Memory* memory) : computerCPU(cpu), computerGPU(gpu), computerMemory(memory)
	{
	}

	~Computer()
	{
		if (computerCPU != NULL)
		{
			delete computerCPU;
			computerCPU = NULL;
		}

		if (computerGPU != NULL)
		{
			delete computerGPU;
			computerGPU = NULL;
		}

		if (computerMemory != NULL)
		{
			delete computerMemory;
			computerMemory = NULL;
		}
	}

	void work()
	{
		computerCPU->calculate();
		computerGPU->display();
		computerMemory->store();
	}
};

class IntelCPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel CPU is working" << endl;
	}
};

class IntelGPU : public GPU
{
public:
	virtual void display()
	{
		cout << "Intel GPU is working" << endl;
	}
};

class IntelMemory : public Memory
{
public:
	virtual void store()
	{
		cout << "Intel Memory is working" << endl;
	}
};

class LenovoCPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo CPU is working" << endl;
	}
};

class LenovoGPU : public GPU
{
public:
	virtual void display()
	{
		cout << "Lenovo GPU is working" << endl;
	}
};

class LenovoMemory : public Memory
{
public:
	virtual void store()
	{
		cout << "Lenovo Memory is working" << endl;
	}
};

void test1()
{
	CPU* intelCPU = new IntelCPU;
	GPU* intelGPU = new IntelGPU;
	Memory* intelMemory = new IntelMemory;

	Computer* computer1 = new Computer(intelCPU, intelGPU, intelMemory);
	computer1->work();
	delete computer1;

	cout << "----------" << endl;

	Computer* computer2 = new Computer(new LenovoCPU, new LenovoGPU, new LenovoMemory);
	computer2->work();
	delete computer2;

	cout << "----------" << endl;

	Computer* computer3 = new Computer(new LenovoCPU, new IntelGPU, new LenovoMemory);
	computer3->work();
	delete computer3;
}

int main()
{
	test1();

	system("pause");
	return 0;
}
