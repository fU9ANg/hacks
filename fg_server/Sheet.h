
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

struct _SheetIndexTypeTestTypeName {
	int Type;
	string Name;
	_SheetIndexTypeTestTypeName();
	_SheetIndexTypeTestTypeName(int _Type,string _Name) {
		Type = _Type;
		Name = _Name;
	}
	bool operator<(const _SheetIndexTypeTestTypeName& s) const {
		if (this->Type<s.Type) return (true);
		if (this->Type>s.Type) return (false);
		if (this->Name<s.Name) return (true);
		if (this->Name>s.Name) return (false);
		return (false);
	}
};
class SheetTest : public SheetBase
{
private:
	SheetTestData *data;
	std::map<_SheetIndexTypeTestTypeName, int> index_Type_Name;
	std::map<int, int> index_ID;
public:
	vector<SheetTestData*> getAll ();
	SheetTestData* getRow (int n);
	SheetTestData* findByTypeName (int _Type,string _Name);
	SheetTestData* tryFindByTypeName (int _Type,string _Name);
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

struct _SheetIndexTypeTest2ID2Name2 {
	int ID2;
	string Name2;
	_SheetIndexTypeTest2ID2Name2();
	_SheetIndexTypeTest2ID2Name2(int _ID2,string _Name2) {
		ID2 = _ID2;
		Name2 = _Name2;
	}
	bool operator<(const _SheetIndexTypeTest2ID2Name2& s) const {
		if (this->ID2<s.ID2) return (true);
		if (this->ID2>s.ID2) return (false);
		if (this->Name2<s.Name2) return (true);
		if (this->Name2>s.Name2) return (false);
		return (false);
	}
};
struct _SheetIndexTypeTest2ID2Type2 {
	int ID2;
	int Type2;
	_SheetIndexTypeTest2ID2Type2();
	_SheetIndexTypeTest2ID2Type2(int _ID2,int _Type2) {
		ID2 = _ID2;
		Type2 = _Type2;
	}
	bool operator<(const _SheetIndexTypeTest2ID2Type2& s) const {
		if (this->ID2<s.ID2) return (true);
		if (this->ID2>s.ID2) return (false);
		if (this->Type2<s.Type2) return (true);
		if (this->Type2>s.Type2) return (false);
		return (false);
	}
};
class SheetTest2 : public SheetBase
{
private:
	SheetTest2Data *data;
	std::map<_SheetIndexTypeTest2ID2Type2, int> index_ID2_Type2;
	std::map<_SheetIndexTypeTest2ID2Name2, int> index_ID2_Name2;
public:
	vector<SheetTest2Data*> getAll ();
	SheetTest2Data* getRow (int n);
	SheetTest2Data* findByID2Name2 (int _ID2,string _Name2);
	SheetTest2Data* tryFindByID2Name2 (int _ID2,string _Name2);
	SheetTest2Data* findByID2Type2 (int _ID2,int _Type2);
	SheetTest2Data* tryFindByID2Type2 (int _ID2,int _Type2);
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

struct _SheetIndexTypePlayerNameLevel {
	string Name;
	int Level;
	_SheetIndexTypePlayerNameLevel();
	_SheetIndexTypePlayerNameLevel(string _Name,int _Level) {
		Name = _Name;
		Level = _Level;
	}
	bool operator<(const _SheetIndexTypePlayerNameLevel& s) const {
		if (this->Name<s.Name) return (true);
		if (this->Name>s.Name) return (false);
		if (this->Level<s.Level) return (true);
		if (this->Level>s.Level) return (false);
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
	std::map<_SheetIndexTypePlayerIDName, int> index_ID_Name;
	std::multimap<_SheetIndexTypePlayerNameLevel, int> index_Name_Level;
	std::map<int, int> index_ID;
public:
	vector<SheetPlayerData*> getAll ();
	SheetPlayerData* getRow (int n);
	std::vector<SheetPlayerData*> findByNameLevel (string _Name,int _Level);
	SheetPlayerData* findByIDName (int _ID,string _Name);
	SheetPlayerData* tryFindByIDName (int _ID,string _Name);
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
	std::map<int, int> index_ID;
	std::multimap<int, int> index_MonsterQuality;
public:
	vector<SheetMonsterData*> getAll ();
	SheetMonsterData* getRow (int n);
	bool forEach (SheetMonsterData& item);
	virtual int init ();
	virtual int initLink ();
	std::vector<SheetMonsterData*> findByMonsterQuality (int _MonsterQuality);
	SheetMonsterData* findByID (int _ID);
	SheetMonsterData* tryFindByID (int _ID);
	void dump (void);
};
extern SheetMonster* shMonster;
#endif // __SHEET_H__
