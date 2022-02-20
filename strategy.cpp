#include <iostream>
#include <ctime>
using namespace std;

// интерфейсы, которые описывают абстрактное поведение
__interface FlyBehavior
{
	void Fly();
};

__interface QuackBehavior
{
	void Quack();
};

///////////////////////////////////////////////////////////////////

// классы, которые реализуют типы полёта
class FlyWithWings : public FlyBehavior
{
public:
	void Fly()
	{
		cout << "машет крыльями!\n";
	}
};

class Flightless : public FlyBehavior
{
public:
	void Fly()
	{
		cout << "я не умею летать :(\n";
	}
};

class JetPack : public FlyBehavior
{
public:
	void Fly()
	{
		cout << "использует реактивный ранец\n";
	}
};

///////////////////////////////////////////////////////////////////////

// классы, которые реализуют типы кряканья
class UsualQuack : public QuackBehavior
{
public:
	void Quack()
	{
		cout << "кря-кря!\n";
	}
};

class Squeak : public QuackBehavior
{
public:
	void Quack()
	{
		cout << "пиип-пиип!\n";
	}
};

class SilentSqueak : public QuackBehavior
{
public:
	void Quack()
	{
		cout << "* тишина *\n";
		// или вообще, тело метода можно оставить пустым
	}
};

////////////////////////////////////////////////////////////////

// базовый абстрактный класс уток
class Duck abstract
{
protected:
	FlyBehavior* fly_behavior = nullptr;
	QuackBehavior* quack_behavior = nullptr;

public:
	void virtual Swim() // может быть переопределён
	{
		cout << "все утки плавают!\n";
	}

	void virtual Display() = 0; // должен быть переопределён!

	//////////////////////////////////////////////////////////////////////

	void PerformFly()
	{
		fly_behavior->Fly(); // делегирование поведения
	}

	void PerformQuack()
	{
		quack_behavior->Quack();
	}

	//////////////////////////////////////////////////////////////////////

	void SetFlyBehavior(FlyBehavior* new_fly_behavior)
	{
		if (fly_behavior != nullptr) delete fly_behavior;
		fly_behavior = new_fly_behavior;
	}

	void SetQuackBehavior(QuackBehavior* new_quack_behavior)
	{
		if (quack_behavior != nullptr) delete quack_behavior;
		quack_behavior = new_quack_behavior;
	}
};

////////////////////////////////////////////////////////////////

// конкретные утки
class MallardDuck : public Duck
{
public:
	MallardDuck()
	{
		fly_behavior = new FlyWithWings;
		quack_behavior = new UsualQuack;
	}
	void Display()
	{
		system("start https://trancemusic.000webhostapp.com/cpp/mallard.jpg");
	}
};

class RubberDuck : public Duck
{
public:
	RubberDuck()
	{
		fly_behavior = new Flightless;
		quack_behavior = new Squeak;
	}
	void virtual Display()
	{
		system("start https://trancemusic.000webhostapp.com/cpp/rubber.jpg");
	}
};

class DecoyDuck : public Duck // деревянная утка-манок
{
public:
	DecoyDuck()
	{
		fly_behavior = new Flightless;
		quack_behavior = new SilentSqueak;
	}
	void virtual Display()
	{
		system("start https://trancemusic.000webhostapp.com/cpp/decoy.jpg");
	}
};

int main()
{
	setlocale(0, "");
	system("title Решение # 2");

	Duck* duck = new MallardDuck;
	duck->PerformFly();
	duck->PerformQuack();
	duck->Swim();
	// duck->Display();
	// delete duck;
	cout << endl;

	///////////////////////////////////////////// 

	duck = new RubberDuck;
	duck->PerformFly();
	duck->PerformQuack();
	// duck->Swim();
	// delete duck;
	cout << endl;

	/////////////////////////////////////////////

	duck = new DecoyDuck;
	duck->PerformFly();
	duck->PerformQuack();
	// duck->Swim();
	cout << endl;

	duck->SetFlyBehavior(new JetPack);
	duck->SetQuackBehavior(new Squeak);
	duck->PerformFly();
	duck->PerformQuack();
	// delete duck;
}