
#ifndef __SHEET_H__
#define __SHEET_H__

#include "SheetBase.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//////////////////////////////////////////////
class SheetTestData : public SheetBaseData
{
public:
	int ID;	//ID
	int Type;	//编号
	string Name;	//名称
	SheetTestData ();
};

class SheetTest : public SheetBase
{
private:
	SheetTestData *data;
	std::map<int, int> index_ID;
public:
	vector<SheetTestData*> getAll ();
	SheetTestData* getRow (int n);
	bool forEach (SheetTestData& item);
	virtual int init ();
	virtual int initLink ();
	SheetTestData* findByID (int _ID);
	SheetTestData* tryFindByID (int _ID);
	void dump (void);
};
extern SheetTest* shTest;

//////////////////////////////////////////////
class SheetTest2Data : public SheetBaseData
{
public:
	int ID2;	//ID
	int Type2;	//编号
	string Name2;	//名称
	SheetTest2Data ();
};

class SheetTest2 : public SheetBase
{
private:
	SheetTest2Data *data;
public:
	vector<SheetTest2Data*> getAll ();
	SheetTest2Data* getRow (int n);
	bool forEach (SheetTest2Data& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetTest2* shTest2;

//////////////////////////////////////////////
class SheetPlayerData : public SheetBaseData
{
public:
	int ID;	//ID
	string Name;	//名称
	int Quality;	//品质
	int Level;	//等级
	SheetPlayerData ();
};

struct _SheetIndexTypePlayerIDNameQualityLevel {
	int ID;
	string Name;
	int Quality;
	int Level;
	_SheetIndexTypePlayerIDNameQualityLevel();
	_SheetIndexTypePlayerIDNameQualityLevel(int _ID,string _Name,int _Quality,int _Level) {
		ID = _ID;
		Name = _Name;
		Quality = _Quality;
		Level = _Level;
	}
	bool operator<(const _SheetIndexTypePlayerIDNameQualityLevel& s) const {
		if (this->ID<s.ID) return (true);
		if (this->ID>s.ID) return (false);
		if (this->Name<s.Name) return (true);
		if (this->Name>s.Name) return (false);
		if (this->Quality<s.Quality) return (true);
		if (this->Quality>s.Quality) return (false);
		if (this->Level<s.Level) return (true);
		if (this->Level>s.Level) return (false);
		return (false);
	}
};
struct _SheetIndexTypePlayerIDNameQuality {
	int ID;
	string Name;
	int Quality;
	_SheetIndexTypePlayerIDNameQuality();
	_SheetIndexTypePlayerIDNameQuality(int _ID,string _Name,int _Quality) {
		ID = _ID;
		Name = _Name;
		Quality = _Quality;
	}
	bool operator<(const _SheetIndexTypePlayerIDNameQuality& s) const {
		if (this->ID<s.ID) return (true);
		if (this->ID>s.ID) return (false);
		if (this->Name<s.Name) return (true);
		if (this->Name>s.Name) return (false);
		if (this->Quality<s.Quality) return (true);
		if (this->Quality>s.Quality) return (false);
		return (false);
	}
};
struct _SheetIndexTypePlayerIDName {
	int ID;
	string Name;
	_SheetIndexTypePlayerIDName();
	_SheetIndexTypePlayerIDName(int _ID,string _Name) {
		ID = _ID;
		Name = _Name;
	}
	bool operator<(const _SheetIndexTypePlayerIDName& s) const {
		if (this->ID<s.ID) return (true);
		if (this->ID>s.ID) return (false);
		if (this->Name<s.Name) return (true);
		if (this->Name>s.Name) return (false);
		return (false);
	}
};
class SheetPlayer : public SheetBase
{
private:
	SheetPlayerData *data;
	std::multimap<_SheetIndexTypePlayerIDName, int> index_ID_Name;
	std::multimap<_SheetIndexTypePlayerIDNameQuality, int> index_ID_Name_Quality;
	std::multimap<_SheetIndexTypePlayerIDNameQualityLevel, int> index_ID_Name_Quality_Level;
	std::map<int, int> index_ID;
public:
	vector<SheetPlayerData*> getAll ();
	SheetPlayerData* getRow (int n);
	std::vector<SheetPlayerData*> findByIDNameQualityLevel (int _ID,string _Name,int _Quality,int _Level);
	std::vector<SheetPlayerData*> findByIDNameQuality (int _ID,string _Name,int _Quality);
	std::vector<SheetPlayerData*> findByIDName (int _ID,string _Name);
	bool forEach (SheetPlayerData& item);
	virtual int init ();
	virtual int initLink ();
	SheetPlayerData* findByID (int _ID);
	SheetPlayerData* tryFindByID (int _ID);
	void dump (void);
};
extern SheetPlayer* shPlayer;

//////////////////////////////////////////////
class SheetMonsterData : public SheetBaseData
{
public:
	int ID;	//ID
	int MonsterID;	//怪物表ID
	string MonsterName;	//怪物表名称
	int MonsterQuality;	//怪物表品质
	int MonsterLevel;	//怪物表等级
	SheetMonsterData ();
};

class SheetMonster : public SheetBase
{
private:
	SheetMonsterData *data;
	std::multimap<int, int> index_MonsterID;
	std::map<int, int> index_ID;
public:
	vector<SheetMonsterData*> getAll ();
	SheetMonsterData* getRow (int n);
	bool forEach (SheetMonsterData& item);
	virtual int init ();
	virtual int initLink ();
	SheetMonsterData* findByID (int _ID);
	SheetMonsterData* tryFindByID (int _ID);
	std::vector<SheetMonsterData*> findByMonsterID (int _MonsterID);
	void dump (void);
};
extern SheetMonster* shMonster;
#endif // __SHEET_H__
