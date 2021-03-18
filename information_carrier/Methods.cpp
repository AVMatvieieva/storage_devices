#include"Information_Carrier.h"

using namespace std;

Inf_type::Inf_type()
{
	this->produser = nullptr;
	this-> model = nullptr;
	this-> name = nullptr;
	this-> value = 0;
	this-> count=0;
}

Inf_type::Inf_type(const char* p, const char* m, const char* n, double v, int c)
{
	this->produser = new char[strlen(p) + 1]{};
	strcpy_s(this->produser, _msize(this->produser), p);
	this->model = new char[strlen(m) + 1]{};
	strcpy_s(this->model, _msize(this->model), m);
	this->name = new char[strlen(n) + 1]{};
	strcpy_s(this->name, _msize(this->name), n);
	this->value = v;
	this->count = c;
}

int Inf_type::GetCount()
{
	return this->count;
}

void Inf_type::SetProduser(char* p)
{
	if (this->model != nullptr)
	{
		delete[]this->produser;
	}
	int size = strlen(p);
	this->produser = new char[size + 1]{};
	strcpy(this->produser, p);
	
}

void Inf_type::SetModel(char* m)
{
	if (this->model!=nullptr)
	{
		delete[]this->model;
	}
	int size = strlen(m);
	this->model = new char[size + 1]{};
	strcpy(this->model, m);
}

void Inf_type::SetName(char* n)
{
	if (this->model != nullptr)
	{
		delete[]this->name;
	}
	int size = strlen(n);
	this->name = new char[size + 1]{};
	strcpy(this->name, n);
	
}
void Inf_type::SetValue(double v)
{
	this->value = v;
}
void Inf_type::SetCount(int c)
{
	this->count = c;
}

const char* Inf_type::GetProduser()
{
	return this->produser;
}
const char* Inf_type::GetName()
{
	return this->name;
}
const char* Inf_type::GetModel()
{
	return this->model;
}
double Inf_type::GetValue()
{
	return this->value;
}

void Inf_type:: Print()
{
	std::cout <<"Производитель:"<< this->produser << endl;
	std::cout <<"Модель:"<< this->model << endl;
	std::cout <<"Наименование: " <<this->name << endl;
	std::cout <<"Объем носителя: "<< this->value << endl;
	std::cout <<"Количество: "<< this->count << endl;
}
void Inf_type::Save(ofstream& out)
{
	out << this->produser << endl;
	out << this->model << endl;
	out << this->name << endl;
	out << this->value << endl;
	out << this->count << endl;
}
void Inf_type::Load(ifstream& in)
{
	string p;
	getline(in, p);
	int size = p.size();

	this->produser = new char[size + 1]{};
	strcpy(this->produser, p.c_str());
	
	getline(in, p);
	size = p.size();
	this->model = new char[size + 1]{};
	strcpy(this->model, p.c_str());
	
	getline(in, p);
	size = p.size();
	this->name = new char[size + 1]{};
	strcpy(this->name, p.c_str());
	
	getline(in, p);
	this->value = stoi(p);

	getline(in, p);
	this->count = stoi(p);
	
}
Inf_type::~Inf_type()
{
	delete[]this->produser;
	delete[]this->model;
	delete[]this->name;
}

USB::USB()
{
	Inf_type::Inf_type();
	this->speed = 0;
}
USB::USB(const char* p, const char* m, const char* n, double v, int c, int s) :Inf_type(p, m, n, v, c)
{
	this->speed = s;
}
void USB::SetProduser(char* p)
{
	Inf_type::SetProduser(p);
}
void  USB::SetModel(char* m)
{
	Inf_type::SetModel(m);
}
void  USB::SetName(char* n)
{
	Inf_type::SetName(n);
}
void  USB::SetValue(double v)
{
	Inf_type::SetValue(v);
}
void  USB::SetCount(int c)
{
	Inf_type::SetCount(c);
}
void USB::SetSpeed(double s)
{
	this->speed = s;
}
const char* USB::GetProduser()
{
	return Inf_type::GetProduser();
}
const char* USB::GetName()
{
	return Inf_type::GetName();
}
double USB::GetValue()
{
	return Inf_type::GetValue();
}
int USB::GetCount()
{
	return Inf_type::GetCount();
}
const char* USB::GetModel()
{
	return Inf_type::GetModel();
}
void USB::Print()
{
	Inf_type::Print();
	std::cout << "Скорость USB: " << this->speed << endl;
}
void USB::Save(ofstream& out)
{
	Inf_type::Save(out);
	out << this->speed << endl;
	
}
void USB::Load(ifstream& in)
{
	Inf_type::Load(in);
	string p;
	getline(in, p);
	this->speed = stoi(p);
	//std::cout << this->speed << endl << endl;
	
}
void USB::Add()
{
	Inf_type::Add();
	double s;
	std::cout << "Введите скорость: ";
	std::cin >> s;
	std::cin.sync();
	std::cin.get();
	this->speed = s;

}
HDD::HDD()
{
	Inf_type::Inf_type();
	this->speed = 0;
}
HDD::HDD(const char* p, const char* m, const char* n, double v, int c, int s) :Inf_type(p, m, n, v, c)
{
	this->speed = s;
}
void HDD::SetProduser(char* p)
{
	Inf_type::SetProduser(p);
}
void  HDD::SetModel(char* m)
{
	Inf_type::SetModel(m);
}
void  HDD::SetName(char* n)
{
	Inf_type::SetName(n);
}
void  HDD::SetValue(double v)
{
	Inf_type::SetValue(v);
}
void  HDD::SetCount(int c)
{
	Inf_type::SetCount(c);
}
void HDD::SetSpeed(double s)
{
	this->speed = s;
}
const char* HDD::GetProduser()
{
	return Inf_type::GetProduser();
}
const char* HDD::GetName()
{
	return Inf_type::GetName();
}
const char* HDD::GetModel()
{
	return Inf_type::GetModel();
}
double HDD::GetValue()
{
	return Inf_type::GetValue();
}
int HDD::GetCount()
{
	return Inf_type::GetCount();
}
void HDD::Print()
{
	Inf_type::Print();
	std::cout << "Скорость вращения шпинделя: " << this->speed << endl;
}

void HDD::Save(ofstream& out)
{
	Inf_type::Save(out);
	out << this->speed << endl;
	
}
void HDD::Load(ifstream &in)
{
	Inf_type::Load(in);
	string p;
	getline(in, p);
	this->speed = stoi(p);
	//std::cout << this->speed << endl << endl;

}
void HDD::Add()
{
	Inf_type::Add();
	double s;
	std::cout << "Введите скорость: ";
	std::cin >> s;
	std::cin.sync();
	std::cin.get();
	this->speed = s;

}
DVD::DVD()
{
	Inf_type::Inf_type();
	this->speed = 0;
}
DVD::DVD(const char* p, const char* m, const char* n, double v, int c, int s) :Inf_type(p, m, n, v, c)
{
	this->speed = s;
}
void DVD::SetProduser(char* p)
{
	Inf_type::SetProduser(p);
}
void  DVD::SetModel(char* m)
{
	Inf_type::SetModel(m);
}
void  DVD::SetName(char* n)
{
	Inf_type::SetName(n);
}
void  DVD::SetValue(double v)
{
	Inf_type::SetValue(v);
}
void  DVD::SetCount(int c)
{
	Inf_type::SetCount(c);
}
void DVD::SetSpeed(double s)
{
	this->speed = s;
}
const char* DVD::GetProduser()
{
	return Inf_type::GetProduser();
}
const char* DVD::GetName()
{
	return Inf_type::GetName();
}

double DVD::GetValue()
{
	return Inf_type::GetValue();
}
int DVD::GetCount()
{
	return Inf_type::GetCount();
}
const char* DVD::GetModel()
{
	return Inf_type::GetModel();
}
void DVD::Print()
{
	Inf_type::Print();
	std::cout << "Скорость записи DVD: " << this->speed << endl;
}
void DVD::Save(ofstream& out)
{
	Inf_type::Save(out);
	out << this->speed << endl;


}
void DVD::Load(ifstream& in)
{
	Inf_type::Load(in);
	string p;
	getline(in, p);
	this->speed = stoi(p);
	//cout << this->speed << endl << endl;

	
}
void DVD::Add()
{
	Inf_type::Add();
	double s;
	cout << "Введите скорость: ";
	cin >> s;
	cin.sync();
	cin.get();

	this->speed = s;

}
List::List()
{
	this->Drv = nullptr;
	this->countOfDrv = 0;
}
List::~List()
{
	for (int i = 0; i < this->countOfDrv; i++)
	{
		delete this->Drv[i];
	}
	delete[] this->Drv;
}
void Inf_type::Add()
{
	char* f = new char[50]{};
	char* m = new char[50]{}; 
	char* n = new char[50]{};
	double v;
	int c;
	cin.sync();
	cin.get();

	cout << "Введите производителя: ";
	cin.getline(f, 49);

	cout << "Введите модель: ";
	cin.getline(m, 49);

	cout << "Введите название: ";
	cin.getline(n, 49);

	cout << "Введите обьем носителя: ";
	cin >> v;
	cin.sync();
	cin.get();

	cout << "Введите количество: ";

	cin >> c;

	cin.sync();
	cin.get();

	this->SetProduser(f);
	this->SetModel(m);
	this->SetName(n);
	this->SetValue(v);
	this->SetCount(c);
	//очистить память
	delete[]f;
	delete[]m;
	delete[]n;
}
void List::AddInfType()
{
	int e;
	cout << "Выберите тип носителя информации: " << endl;
	cout << "1-USB-флеш-накопитель\n2-Портативный жесткий диск\n3-DVD–диск\n " << endl;
	cin >> e;
	cin.sync();
	cin.get();

	Inf_type** TMP = new Inf_type * [this->countOfDrv + 1];

	for (int i = 0; i < this->countOfDrv; i++)
	{
			TMP[i] = this->Drv[i];
	}

	switch (e)
	{
	case 1: TMP[this->countOfDrv] = new USB;
		break;
	case 2: TMP[this->countOfDrv] = new HDD;
		break;
	case 3: TMP[this->countOfDrv] = new DVD;
		break;
	}
	
	TMP[this->countOfDrv]->Add();
	delete[]this->Drv;
	this->Drv = TMP;
	this->countOfDrv++;
}
void  List::PrintInfType()
{
	for (int i = 0; i < this->countOfDrv; i++)
	{
		cout << "Номер: " << (i + 1) << endl;
		this->Drv[i]->Print();
		cout << endl;
	}
	system("pause");
}
void List::SaveInfType()
{
	ofstream out("List.txt", ios::out);
	ofstream out1("USB.txt", ios::out);
	ofstream out3("DVD.txt", ios::out);
	ofstream out2("HDD.txt", ios::out);
	if (!out.is_open()&& !out2.is_open()&& !out1.is_open()&& !out3.is_open()) // если открытие файла завершилось неудачей - выходим
	{
		cout << "Error!\n";
		return;
	}
	
	out << countOfDrv;

	for (int  i = 0; i < this->countOfDrv; i++)
	{
		USB* tmp_usb = dynamic_cast<USB*>(this->Drv[i]);
		if (tmp_usb)
		{
			out << "USB\n";
			this->Drv[i]->Save(out1);
		}
		else
		{
			DVD* tmp_dvd = dynamic_cast<DVD*>(this->Drv[i]);
			if (tmp_dvd)
			{
				out << "DVD\n";
				this->Drv[i]->Save(out3);
			}
			else
			{
				ofstream out2("HDD.txt", ios::out);
				out << "HDD\n"; this->Drv[i]->Save(out2);
			}
		}

	}
	out.close();
	out1.close();
	out2.close();
	out3.close();
	
}
void List::LoadInfType()
{
	ifstream in("List.txt", ios::in);
	ifstream in1("USB.txt", ios::in);
	ifstream in2("HDD.txt", ios::in);
	ifstream in3("DVD.txt", ios::in);
	string type;
	
	in >> this->countOfDrv;
	cout << "\nКоличество носителей информации: " << this->countOfDrv;

	Inf_type** Drv_copy = new Inf_type * [this->countOfDrv];

	for (int i = 0; i < this->countOfDrv; i++)
	{
		getline(in, type);
		if (type=="USB")
		{
			Drv_copy[i] = new USB;
			Drv_copy[i]->Load(in1);
		}
		else if (type == "DVD")
		{
			Drv_copy[i] = new DVD;
			Drv_copy[i]->Load(in3);
		}
		else
		{
			Drv_copy[i] = new HDD;
			Drv_copy[i]->Load(in2);
		}

	}
	if (this->Drv!=nullptr)
	{
		for (int i = 0; i < this->countOfDrv; i++)
		{
			delete this->Drv[i];
		}
		delete[]this->Drv;
	}
	this->Drv = Drv_copy;
	Drv_copy = nullptr;

	in.close();
	in1.close();
	in2.close();
	in3.close();
}
void List::Delete()
{
	int NumberOfDrv;
	cout << "Введите номер носителя, который вы хотите удалить: \n";
	cin>> NumberOfDrv;
	
	Inf_type** TMP = new Inf_type * [this->countOfDrv - 1];
	for (int  i = 0; i < this->countOfDrv; i++)
	{
		if (i >= (NumberOfDrv - 1))
		{
			TMP[i] = this->Drv[i + 1];

		}
		else
			TMP[i] = this->Drv[i];
	}
	delete this->Drv[NumberOfDrv];
	delete[]this->Drv;
	this->Drv = TMP;
	this->countOfDrv--;

}
void List::Find()
{
	int TypeOfFind;
	char* s=new char[255];
	char* b = new char[255];
	cout << "Введите критерий:\n 1-Производитель\n 2-Название\n 3-Обьем\n";
	cin >> TypeOfFind;
	for (int  i = 0; i < 1; i++)
	{
		switch (TypeOfFind)
		{
		case 1:
			cout << "Введите производителя: \n";
			cin.sync();
			cin.get();
			cin.getline(s, 254);
			for (int i = 0; i < this->countOfDrv; i++)
			{
				if (strstr((Drv[i]->GetProduser()),s)!=NULL)
				{
					cout << "Number: " << (i + 1) << endl;
					this->Drv[i]->Print();
					cout << endl;
				}
			}
			break;
		case 2:
			cout << "Введите название: \n";
			cin.sync();
			cin.get();
			cin.getline(b, 254);
			for (int i = 0; i < this->countOfDrv; i++)
			{
				if (strstr((Drv[i]->GetName()), b) != NULL)
				{
					cout << "Number: " << (i + 1) << endl;
					this->Drv[i]->Print();
					cout << endl;
				}
			}
			break;
		case 3:
			cout << "Введите обьем накопителя: \n";
			double d;
			cin >> d;
			for (int i = 0; i < this->countOfDrv; i++)
			{
				if (Drv[i]->GetValue()==d)
				{
					cout << "Number: " << (i + 1) << endl;
					this->Drv[i]->Print();
					cout << endl;
				}
			}
			break;
		default:
			break;
		}
		system("pause");
	}
}
void List::Edit()
{
	int NumberOfMedia;
	cout << "Введите номер носителя который хотите изменить: \n";
	cin >> NumberOfMedia;
	int stringOfEdit;
	cout << "Введите что вы хотите изменит: \n";
	cout << "1-Производитель\n2-Модель\n3-Имя\n4-Объем\n5-Количество\n";
	
	Inf_type** tmp = new Inf_type * [this->countOfDrv + 1];
	for (size_t i = 0; i < this->countOfDrv+1; i++)
	{
		if (i == (NumberOfMedia - 1))
		{
			cin >> stringOfEdit;
			char* p = new char[50]; char* m = new char[50]; char* n = new char[50];

			switch (stringOfEdit)
			{
			case 1:
				
				cin.sync();
				cin.get();
				cin.getline(p, 49);
				Drv[i]->SetProduser(p);
				tmp[i] = new Inf_type(Drv[i]->GetProduser(), Drv[i]->GetModel(), Drv[i]->GetName(), Drv[i]->GetValue(), Drv[i]->GetCount());
				
				break;
			case 2:
				
				cin.sync();
				cin.get();
				cin.getline(m, 49);
				Drv[i]->SetModel(m);
				tmp[i] = new Inf_type(Drv[i]->GetProduser(), Drv[i]->GetModel(), Drv[i]->GetName(), Drv[i]->GetValue(), Drv[i]->GetCount());
				
				break;
			case 3:
				
				cin.sync();
				cin.get();
				cin.getline(n, 49);
				Drv[i]->SetName(n);
				tmp[i] = new Inf_type(Drv[i]->GetProduser(), Drv[i]->GetModel(), Drv[i]->GetName(), Drv[i]->GetValue(), Drv[i]->GetCount());
				
				break;
			case 4:
				double v;
				cin >> v;
				Drv[i]->SetValue(v);
				tmp[i] = new Inf_type(Drv[i]->GetProduser(), Drv[i]->GetModel(), Drv[i]->GetName(), Drv[i]->GetValue(), Drv[i]->GetCount());
				break;
			case 5:
				int c;
				cin >> c;
				Drv[i]->SetCount(c);
				tmp[i] = new Inf_type(Drv[i]->GetProduser(), Drv[i]->GetModel(), Drv[i]->GetName(), Drv[i]->GetValue(), Drv[i]->GetCount());
				break;
			}
			delete[]p; 
			delete[]m;
			delete[]n;
		}
		else tmp[i] = this->Drv[i];

	}
	
	delete[]this->Drv;
	this->Drv = tmp;
	system("cls");
}
void List::ProgramMenu()
{
	bool menu = true;
	int variant = 0;

	while (menu)
	{
		printf("\nВыберите действие: \n");
		printf("1-Ввести новый носитель информации\n2-Распечатать все носители информации");
		printf("\n3-Сохранить в файл\n4-Загрузить из файла");
		printf("\n5-Удалить носитель\n6-Найти носитель");
		printf("\n7-Изменить носитель\n8-Выйти\n");

		cin >> variant;
	
			switch (variant)
			{
			case 1:
				this->AddInfType(); 
				this->ProgramMenu();
				break;
			case 2:
				this->PrintInfType();
				this->ProgramMenu();
				break;
			case 3:
				this->SaveInfType();
				this->ProgramMenu();
				break;
			case 4:
				this->LoadInfType();
				this->ProgramMenu();
				break;
			case 5:
				this->Delete();
				this->ProgramMenu();
				break;
			case 6:
				this->Find();
				this->ProgramMenu();
				break;
			case 7:
				this->Edit();
				this->ProgramMenu();
				break;
			case 8:
				menu = false;
				break;
			}
			break;
			
	}

}
