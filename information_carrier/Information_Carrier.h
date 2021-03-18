#pragma once
#pragma warning(disable : 4996) 
#include<string>
#include<Windows.h>
#include<fstream>
#include<iostream>
using namespace std;


class Inf_type
{
	char* produser;
	char* model;
	char* name;
	double value;
	int count;
public:
	Inf_type();
	Inf_type(const char* p, const char* m, const char* n, double v, int c);
	
	virtual void SetProduser(char *p);
	virtual void SetModel( char* m);
	virtual void SetName( char* n);
	virtual void SetValue(double v);
	virtual void SetCount(int c);
	virtual const char* GetProduser();
	virtual const char* GetName();
	virtual double GetValue();
	virtual const char* GetModel();
	virtual int GetCount();
	virtual void Print();
	virtual void Save(ofstream& out);
	virtual void Load(ifstream& in);
	virtual void Add();
	virtual ~Inf_type();
};
class USB :public Inf_type
{
	double speed;
public:
	USB();
	USB(const char* p, const char* m, const char* n, double v, int c, int s);
	void SetProduser(char* p);
	void SetModel(char* m);
	void SetName(char* n);
	void SetValue(double v);
	void SetCount(int c);
	void SetSpeed(double s);
	const char* GetProduser();
	const char* GetName();
	double GetValue();
	const char* GetModel();
	int GetCount();
	void Print();
	void Save(ofstream& out);
	void Load(ifstream& in);
	void Add();

	~USB() {};
};
class HDD :public Inf_type
{
	double speed;
public:
	HDD();
	HDD(const char* p, const char* m, const char* n, double v, int c, int s);
	void SetProduser(char* p);
	void SetModel(char* m);
	void SetName(char* n);
	void SetValue(double v);
	void SetCount(int c);
	void SetSpeed(double s);
	const char* GetProduser();
	const char* GetName();
	double GetValue();
	const char* GetModel();
	int GetCount();
	void Print();
	void Save(ofstream& out);
	void Load(ifstream& in);
	void Add();
	~HDD() {};
};
class DVD :public Inf_type
{
	double speed;
public:
	DVD();
	DVD(const char* p, const char* m, const char* n, double v, int c, int s);
	void SetProduser(char* p);
	void SetModel(char* m);
	void SetName(char* n);
	void SetValue(double v);
	void SetCount(int c);
	void SetSpeed(double s);
	const char* GetProduser();
	const char* GetName();
	double GetValue();
	const char* GetModel();
	int GetCount();
	void Print();
	void Save(ofstream& out);
	void Load(ifstream& in);
	void Add();
	~DVD() {};
};

class List
{
	Inf_type** Drv;
	int countOfDrv;
public:
	List();
	~List();
	void AddInfType();
	void PrintInfType();
	void SaveInfType();
	void LoadInfType();
	void Delete();
	void Find();
	void Edit();
	void ProgramMenu();

};
