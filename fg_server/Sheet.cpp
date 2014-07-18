

#include "SheetBase.h"
#include "Sheet.h"

using namespace std;


SheetPropType* shPropType = NULL;
SheetResourceType* shResourceType = NULL;
SheetRole* shRole = NULL;
SheetPromptSpell* shPromptSpell = NULL;
SheetComposeRole* shComposeRole = NULL;
SheetClass* shClass = NULL;
SheetChangeClass* shChangeClass = NULL;
SheetChangeClassProp* shChangeClassProp = NULL;
SheetClassTitle* shClassTitle = NULL;
SheetComposeShape* shComposeShape = NULL;
SheetScene* shScene = NULL;
SheetMap* shMap = NULL;
SheetNPC* shNPC = NULL;
SheetSpell* shSpell = NULL;
SheetBuff* shBuff = NULL;
SheetSummon* shSummon = NULL;
SheetQuest* shQuest = NULL;
SheetEffects* shEffects = NULL;
SheetDungeon* shDungeon = NULL;
SheetDungeonLevel* shDungeonLevel = NULL;
SheetCombatWave* shCombatWave = NULL;
SheetCombatMonster* shCombatMonster = NULL;
SheetDramaCombatRole* shDramaCombatRole = NULL;
SheetRestrain* shRestrain = NULL;
SheetItem* shItem = NULL;
SheetEquipmentProp* shEquipmentProp = NULL;
SheetGem* shGem = NULL;
SheetGemInsertRule* shGemInsertRule = NULL;
SheetRoleLevel* shRoleLevel = NULL;
SheetPartnerLevelUp* shPartnerLevelUp = NULL;
SheetArenaCombatTarget* shArenaCombatTarget = NULL;
SheetArenaRankReward* shArenaRankReward = NULL;
SheetWorldBossRankReward* shWorldBossRankReward = NULL;
SheetVipLevel* shVipLevel = NULL;
SheetReward* shReward = NULL;
SheetLotPartner* shLotPartner = NULL;
SheetLotGem* shLotGem = NULL;
SheetShop* shShop = NULL;
SheetMount* shMount = NULL;
SheetMountLevelUp* shMountLevelUp = NULL;
SheetLevelDrop* shLevelDrop = NULL;
SheetDrama* shDrama = NULL;
SheetOpenAction* shOpenAction = NULL;
SheetLevelTarget* shLevelTarget = NULL;
SheetLevelCorresponding* shLevelCorresponding = NULL;
SheetHiddenLevelMonster* shHiddenLevelMonster = NULL;
SheetHiddenLevelShape* shHiddenLevelShape = NULL;
SheetHiddenLevelScore* shHiddenLevelScore = NULL;
SheetTalentOpen* shTalentOpen = NULL;
SheetTalentName* shTalentName = NULL;
SheetTalentProps* shTalentProps = NULL;
SheetMonsterDrop* shMonsterDrop = NULL;
SheetDropResourceType* shDropResourceType = NULL;
SheetEnchantSlot* shEnchantSlot = NULL;
SheetEnchantMaxProp* shEnchantMaxProp = NULL;
SheetEnchantPro* shEnchantPro = NULL;
SheetOnlineReward* shOnlineReward = NULL;
SheetLoginReward* shLoginReward = NULL;
SheetPropTypeData::SheetPropTypeData ()
{
	ID = 0;
	Type = 0;
	Name = "";
}

SheetPropTypeData* SheetPropType::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetPropTypeData*> SheetPropType::getAll ()
{
	vector<SheetPropTypeData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetPropType::init ()
{
	FILE *fp;
	fp = fopen ("./PropType.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "PropType.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "PropType.txt";
	vector<SheetPropTypeData> d;
	while (1) {
		SheetPropTypeData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Type = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name = value;
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetPropTypeData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetPropType::initLink ()
{
	return (0);
}

void SheetPropType::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetPropType" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetPropType" << "[" << i << "] :: data." << "Type" << " = " << data[i].Type << endl;
		cout << "SheetPropType" << "[" << i << "] :: data." << "Name" << " = " << data[i].Name << endl;
	}
}
SheetResourceTypeData::SheetResourceTypeData ()
{
	ID = 0;
	Name = "";
}

SheetResourceTypeData* SheetResourceType::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetResourceTypeData*> SheetResourceType::getAll ()
{
	vector<SheetResourceTypeData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetResourceType::init ()
{
	FILE *fp;
	fp = fopen ("./ResourceType.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "ResourceType.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "ResourceType.txt";
	vector<SheetResourceTypeData> d;
	while (1) {
		SheetResourceTypeData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name = value;
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetResourceTypeData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetResourceType::initLink ()
{
	return (0);
}

void SheetResourceType::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetResourceType" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetResourceType" << "[" << i << "] :: data." << "Name" << " = " << data[i].Name << endl;
	}
}
SheetRoleData::SheetRoleData ()
{
	ID = 0;
	Name = "";
	Shape = 0;
	Scale = 100;
	Quality = 0;
	Class = 0;
	RoleType = 0;
	AttackRange = 0;
	MonsterType = 0;
	MonsterCategory = 0;
	BornTime = 0;
	Level = 0;
	Spell1 = 0;
	Spell2 = 0;
	Spell3 = 0;
	Spell4 = 0;
	Spell5 = 0;
	Spell6 = 0;
	triggerWay = 0;
	triggerType = 0;
	triggerArg1 = 0;
	Price = 0;
	Aptitude = 0;
	MoveSpeed = 0;
	MaxHp = 0;
	MaxMp = 0;
	PhysicalAttack = 0;
	PhysicalDefense = 0;
	MagicAttack = 0;
	MagicDefense = 0;
	Cirt = 0;
	Penetration = 0;
	Luck = 0;
	Resist = 0;
	Hit = 0;
	Miss = 0;
	Threat = 0;
	SoundDie = "";
	Desc = "";
}

SheetRoleData* SheetRole::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetRoleData*> SheetRole::getAll ()
{
	vector<SheetRoleData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetRole::init ()
{
	FILE *fp;
	fp = fopen ("./Role.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Role.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Role.txt";
	vector<SheetRoleData> d;
	while (1) {
		SheetRoleData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name = value;
		SheetUtils::readToken (fp, value);
		oneData.Shape = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Scale = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Quality = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Class = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.RoleType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AttackRange = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MonsterType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MonsterCategory = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.BornTime = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Level = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Spell1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Spell2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Spell3 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Spell4 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Spell5 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Spell6 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.triggerWay = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.triggerType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.triggerArg1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Price = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Aptitude = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MoveSpeed = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MaxHp = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MaxMp = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PhysicalAttack = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PhysicalDefense = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MagicAttack = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MagicDefense = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Cirt = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Penetration = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Luck = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Resist = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Hit = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Miss = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Threat = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.SoundDie = value;
		SheetUtils::readToken (fp, value);
		oneData.Desc = value;
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetRoleData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetRole::initLink ()
{
	return (0);
}

void SheetRole::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetRole" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Name" << " = " << data[i].Name << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Shape" << " = " << data[i].Shape << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Scale" << " = " << data[i].Scale << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Quality" << " = " << data[i].Quality << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Class" << " = " << data[i].Class << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "RoleType" << " = " << data[i].RoleType << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "AttackRange" << " = " << data[i].AttackRange << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "MonsterType" << " = " << data[i].MonsterType << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "MonsterCategory" << " = " << data[i].MonsterCategory << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "BornTime" << " = " << data[i].BornTime << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Level" << " = " << data[i].Level << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Spell1" << " = " << data[i].Spell1 << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Spell2" << " = " << data[i].Spell2 << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Spell3" << " = " << data[i].Spell3 << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Spell4" << " = " << data[i].Spell4 << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Spell5" << " = " << data[i].Spell5 << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Spell6" << " = " << data[i].Spell6 << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "triggerWay" << " = " << data[i].triggerWay << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "triggerType" << " = " << data[i].triggerType << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "triggerArg1" << " = " << data[i].triggerArg1 << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Price" << " = " << data[i].Price << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Aptitude" << " = " << data[i].Aptitude << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "MoveSpeed" << " = " << data[i].MoveSpeed << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "MaxHp" << " = " << data[i].MaxHp << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "MaxMp" << " = " << data[i].MaxMp << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "PhysicalAttack" << " = " << data[i].PhysicalAttack << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "PhysicalDefense" << " = " << data[i].PhysicalDefense << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "MagicAttack" << " = " << data[i].MagicAttack << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "MagicDefense" << " = " << data[i].MagicDefense << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Cirt" << " = " << data[i].Cirt << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Penetration" << " = " << data[i].Penetration << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Luck" << " = " << data[i].Luck << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Resist" << " = " << data[i].Resist << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Hit" << " = " << data[i].Hit << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Miss" << " = " << data[i].Miss << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Threat" << " = " << data[i].Threat << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "SoundDie" << " = " << data[i].SoundDie << endl;
		cout << "SheetRole" << "[" << i << "] :: data." << "Desc" << " = " << data[i].Desc << endl;
	}
}
SheetPromptSpellData::SheetPromptSpellData ()
{
	ID = 0;
	Type = 0;
	AttackSpell = 0;
	DefenseSpell = 0;
}

SheetPromptSpellData* SheetPromptSpell::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetPromptSpellData*> SheetPromptSpell::getAll ()
{
	vector<SheetPromptSpellData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetPromptSpell::init ()
{
	FILE *fp;
	fp = fopen ("./PromptSpell.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "PromptSpell.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "PromptSpell.txt";
	vector<SheetPromptSpellData> d;
	while (1) {
		SheetPromptSpellData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Type = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AttackSpell = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.DefenseSpell = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetPromptSpellData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetPromptSpell::initLink ()
{
	return (0);
}

void SheetPromptSpell::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetPromptSpell" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetPromptSpell" << "[" << i << "] :: data." << "Type" << " = " << data[i].Type << endl;
		cout << "SheetPromptSpell" << "[" << i << "] :: data." << "AttackSpell" << " = " << data[i].AttackSpell << endl;
		cout << "SheetPromptSpell" << "[" << i << "] :: data." << "DefenseSpell" << " = " << data[i].DefenseSpell << endl;
	}
}
SheetComposeRoleData::SheetComposeRoleData ()
{
	ComposeLevel = 0;
	RequireLevel = 0;
	CostMoney = 0;
	AddAptitude = 0;
}

SheetComposeRoleData* SheetComposeRole::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetComposeRoleData*> SheetComposeRole::getAll ()
{
	vector<SheetComposeRoleData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetComposeRole::init ()
{
	FILE *fp;
	fp = fopen ("./ComposeRole.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "ComposeRole.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "ComposeRole.txt";
	vector<SheetComposeRoleData> d;
	while (1) {
		SheetComposeRoleData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ComposeLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.RequireLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.CostMoney = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AddAptitude = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetComposeRoleData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetComposeRole::initLink ()
{
	return (0);
}

void SheetComposeRole::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetComposeRole" << "[" << i << "] :: data." << "ComposeLevel" << " = " << data[i].ComposeLevel << endl;
		cout << "SheetComposeRole" << "[" << i << "] :: data." << "RequireLevel" << " = " << data[i].RequireLevel << endl;
		cout << "SheetComposeRole" << "[" << i << "] :: data." << "CostMoney" << " = " << data[i].CostMoney << endl;
		cout << "SheetComposeRole" << "[" << i << "] :: data." << "AddAptitude" << " = " << data[i].AddAptitude << endl;
	}
}
SheetClassData::SheetClassData ()
{
	ID = 0;
	Type = 0;
	IsTalent = 0;
	ClassName = "";
	Speciality = "";
	Shape = 0;
	AttackType = 0;
	StaToHp = 0;
	StrToPhyAtk = 0;
	StrToPhyDef = 0;
	IntToMgcAtk = 0;
	IntToMgcDef = 0;
	Title = "";
	Desc = "";
	Spy1 = 0;
	Spy2 = 0;
	Spy3 = 0;
	RestrainDesc = "";
}

SheetClassData* SheetClass::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetClassData*> SheetClass::getAll ()
{
	vector<SheetClassData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetClass::init ()
{
	FILE *fp;
	fp = fopen ("./Class.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Class.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Class.txt";
	vector<SheetClassData> d;
	while (1) {
		SheetClassData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Type = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.IsTalent = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ClassName = value;
		SheetUtils::readToken (fp, value);
		oneData.Speciality = value;
		SheetUtils::readToken (fp, value);
		oneData.Shape = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AttackType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.StaToHp = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.StrToPhyAtk = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.StrToPhyDef = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.IntToMgcAtk = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.IntToMgcDef = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Title = value;
		SheetUtils::readToken (fp, value);
		oneData.Desc = value;
		SheetUtils::readToken (fp, value);
		oneData.Spy1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Spy2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Spy3 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.RestrainDesc = value;
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetClassData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetClass::initLink ()
{
	return (0);
}

void SheetClass::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetClass" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "Type" << " = " << data[i].Type << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "IsTalent" << " = " << data[i].IsTalent << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "ClassName" << " = " << data[i].ClassName << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "Speciality" << " = " << data[i].Speciality << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "Shape" << " = " << data[i].Shape << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "AttackType" << " = " << data[i].AttackType << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "StaToHp" << " = " << data[i].StaToHp << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "StrToPhyAtk" << " = " << data[i].StrToPhyAtk << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "StrToPhyDef" << " = " << data[i].StrToPhyDef << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "IntToMgcAtk" << " = " << data[i].IntToMgcAtk << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "IntToMgcDef" << " = " << data[i].IntToMgcDef << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "Title" << " = " << data[i].Title << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "Desc" << " = " << data[i].Desc << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "Spy1" << " = " << data[i].Spy1 << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "Spy2" << " = " << data[i].Spy2 << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "Spy3" << " = " << data[i].Spy3 << endl;
		cout << "SheetClass" << "[" << i << "] :: data." << "RestrainDesc" << " = " << data[i].RestrainDesc << endl;
	}
}
SheetChangeClassData::SheetChangeClassData ()
{
	ClassLevel = 0;
	RoleQuality = 0;
	RequireLevel = 0;
	CostMoney = 0;
	MaterialId = 0;
	MaterialNum = 0;
}

SheetChangeClassData* SheetChangeClass::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetChangeClassData*> SheetChangeClass::getAll ()
{
	vector<SheetChangeClassData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetChangeClass::init ()
{
	FILE *fp;
	fp = fopen ("./ChangeClass.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "ChangeClass.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "ChangeClass.txt";
	vector<SheetChangeClassData> d;
	while (1) {
		SheetChangeClassData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ClassLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.RoleQuality = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.RequireLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.CostMoney = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MaterialId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MaterialNum = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetChangeClassData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetChangeClass::initLink ()
{
	return (0);
}

void SheetChangeClass::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetChangeClass" << "[" << i << "] :: data." << "ClassLevel" << " = " << data[i].ClassLevel << endl;
		cout << "SheetChangeClass" << "[" << i << "] :: data." << "RoleQuality" << " = " << data[i].RoleQuality << endl;
		cout << "SheetChangeClass" << "[" << i << "] :: data." << "RequireLevel" << " = " << data[i].RequireLevel << endl;
		cout << "SheetChangeClass" << "[" << i << "] :: data." << "CostMoney" << " = " << data[i].CostMoney << endl;
		cout << "SheetChangeClass" << "[" << i << "] :: data." << "MaterialId" << " = " << data[i].MaterialId << endl;
		cout << "SheetChangeClass" << "[" << i << "] :: data." << "MaterialNum" << " = " << data[i].MaterialNum << endl;
	}
}
SheetChangeClassPropData::SheetChangeClassPropData ()
{
	RoleQuality = 0;
	ClassLevel = 0;
	ComposeLevel = 0;
	Aptitude = 0;
}

SheetChangeClassPropData* SheetChangeClassProp::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetChangeClassPropData*> SheetChangeClassProp::getAll ()
{
	vector<SheetChangeClassPropData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetChangeClassProp::init ()
{
	FILE *fp;
	fp = fopen ("./ChangeClassProp.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "ChangeClassProp.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "ChangeClassProp.txt";
	vector<SheetChangeClassPropData> d;
	while (1) {
		SheetChangeClassPropData oneData;
		SheetUtils::readToken (fp, value);
		oneData.RoleQuality = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ClassLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ComposeLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Aptitude = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetChangeClassPropData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetChangeClassProp::initLink ()
{
	return (0);
}

void SheetChangeClassProp::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetChangeClassProp" << "[" << i << "] :: data." << "RoleQuality" << " = " << data[i].RoleQuality << endl;
		cout << "SheetChangeClassProp" << "[" << i << "] :: data." << "ClassLevel" << " = " << data[i].ClassLevel << endl;
		cout << "SheetChangeClassProp" << "[" << i << "] :: data." << "ComposeLevel" << " = " << data[i].ComposeLevel << endl;
		cout << "SheetChangeClassProp" << "[" << i << "] :: data." << "Aptitude" << " = " << data[i].Aptitude << endl;
	}
}
SheetClassTitleData::SheetClassTitleData ()
{
	ClassId = 0;
	ClassLevel = 0;
	Title = "";
}

SheetClassTitleData* SheetClassTitle::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetClassTitleData*> SheetClassTitle::getAll ()
{
	vector<SheetClassTitleData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetClassTitle::init ()
{
	FILE *fp;
	fp = fopen ("./ClassTitle.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "ClassTitle.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "ClassTitle.txt";
	vector<SheetClassTitleData> d;
	while (1) {
		SheetClassTitleData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ClassId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ClassLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Title = value;
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetClassTitleData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetClassTitle::initLink ()
{
	return (0);
}

void SheetClassTitle::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetClassTitle" << "[" << i << "] :: data." << "ClassId" << " = " << data[i].ClassId << endl;
		cout << "SheetClassTitle" << "[" << i << "] :: data." << "ClassLevel" << " = " << data[i].ClassLevel << endl;
		cout << "SheetClassTitle" << "[" << i << "] :: data." << "Title" << " = " << data[i].Title << endl;
	}
}
SheetComposeShapeData::SheetComposeShapeData ()
{
	RoleId = 0;
	ComposeLevel = 0;
	Shape = 0;
}

SheetComposeShapeData* SheetComposeShape::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetComposeShapeData*> SheetComposeShape::getAll ()
{
	vector<SheetComposeShapeData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetComposeShape::init ()
{
	FILE *fp;
	fp = fopen ("./ComposeShape.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "ComposeShape.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "ComposeShape.txt";
	vector<SheetComposeShapeData> d;
	while (1) {
		SheetComposeShapeData oneData;
		SheetUtils::readToken (fp, value);
		oneData.RoleId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ComposeLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Shape = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetComposeShapeData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetComposeShape::initLink ()
{
	return (0);
}

void SheetComposeShape::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetComposeShape" << "[" << i << "] :: data." << "RoleId" << " = " << data[i].RoleId << endl;
		cout << "SheetComposeShape" << "[" << i << "] :: data." << "ComposeLevel" << " = " << data[i].ComposeLevel << endl;
		cout << "SheetComposeShape" << "[" << i << "] :: data." << "Shape" << " = " << data[i].Shape << endl;
	}
}
SheetSceneData::SheetSceneData ()
{
	ID = 0;
	Name = "";
	IsCombat = 0;
	SceneType = 0;
	MapId = 0;
	Instancing = 0;
	EnterPosX = 0;
	EnterPosY = 0;
}

SheetSceneData* SheetScene::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetSceneData*> SheetScene::getAll ()
{
	vector<SheetSceneData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetScene::init ()
{
	FILE *fp;
	fp = fopen ("./Scene.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Scene.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Scene.txt";
	vector<SheetSceneData> d;
	while (1) {
		SheetSceneData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name = value;
		SheetUtils::readToken (fp, value);
		oneData.IsCombat = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.SceneType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MapId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Instancing = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.EnterPosX = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.EnterPosY = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetSceneData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetScene::initLink ()
{
	return (0);
}

void SheetScene::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetScene" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetScene" << "[" << i << "] :: data." << "Name" << " = " << data[i].Name << endl;
		cout << "SheetScene" << "[" << i << "] :: data." << "IsCombat" << " = " << data[i].IsCombat << endl;
		cout << "SheetScene" << "[" << i << "] :: data." << "SceneType" << " = " << data[i].SceneType << endl;
		cout << "SheetScene" << "[" << i << "] :: data." << "MapId" << " = " << data[i].MapId << endl;
		cout << "SheetScene" << "[" << i << "] :: data." << "Instancing" << " = " << data[i].Instancing << endl;
		cout << "SheetScene" << "[" << i << "] :: data." << "EnterPosX" << " = " << data[i].EnterPosX << endl;
		cout << "SheetScene" << "[" << i << "] :: data." << "EnterPosY" << " = " << data[i].EnterPosY << endl;
	}
}
SheetMapData::SheetMapData ()
{
	ID = 0;
	Width = 0;
	Height = 0;
}

SheetMapData* SheetMap::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetMapData*> SheetMap::getAll ()
{
	vector<SheetMapData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetMap::init ()
{
	FILE *fp;
	fp = fopen ("./Map.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Map.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Map.txt";
	vector<SheetMapData> d;
	while (1) {
		SheetMapData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Width = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Height = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetMapData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetMap::initLink ()
{
	return (0);
}

void SheetMap::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetMap" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetMap" << "[" << i << "] :: data." << "Width" << " = " << data[i].Width << endl;
		cout << "SheetMap" << "[" << i << "] :: data." << "Height" << " = " << data[i].Height << endl;
	}
}
SheetNPCData::SheetNPCData ()
{
	ID = 0;
	Shape = 0;
	Type = 0;
	SceneId = 0;
	PosX = 0;
	PosY = 0;
	Name = "";
	Desc = "";
	ActionId = 0;
	ActionText = "";
}

SheetNPCData* SheetNPC::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetNPCData*> SheetNPC::getAll ()
{
	vector<SheetNPCData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetNPC::init ()
{
	FILE *fp;
	fp = fopen ("./NPC.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "NPC.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "NPC.txt";
	vector<SheetNPCData> d;
	while (1) {
		SheetNPCData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Shape = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Type = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.SceneId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PosX = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PosY = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name = value;
		SheetUtils::readToken (fp, value);
		oneData.Desc = value;
		SheetUtils::readToken (fp, value);
		oneData.ActionId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ActionText = value;
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetNPCData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetNPC::initLink ()
{
	return (0);
}

void SheetNPC::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetNPC" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetNPC" << "[" << i << "] :: data." << "Shape" << " = " << data[i].Shape << endl;
		cout << "SheetNPC" << "[" << i << "] :: data." << "Type" << " = " << data[i].Type << endl;
		cout << "SheetNPC" << "[" << i << "] :: data." << "SceneId" << " = " << data[i].SceneId << endl;
		cout << "SheetNPC" << "[" << i << "] :: data." << "PosX" << " = " << data[i].PosX << endl;
		cout << "SheetNPC" << "[" << i << "] :: data." << "PosY" << " = " << data[i].PosY << endl;
		cout << "SheetNPC" << "[" << i << "] :: data." << "Name" << " = " << data[i].Name << endl;
		cout << "SheetNPC" << "[" << i << "] :: data." << "Desc" << " = " << data[i].Desc << endl;
		cout << "SheetNPC" << "[" << i << "] :: data." << "ActionId" << " = " << data[i].ActionId << endl;
		cout << "SheetNPC" << "[" << i << "] :: data." << "ActionText" << " = " << data[i].ActionText << endl;
	}
}
SheetSpellData::SheetSpellData ()
{
	ID = 0;
	Name = "";
	IsNormal = 0;
	SpellSlot = 0;
	UseType = 0;
	DamageType = 0;
	cdId = 0;
	gcdId = 0;
	AIPriority = 0;
	AICombatType = 0;
	AICond = 0;
	AICondArg1 = 0;
	AICondArg2 = 0;
	AITarget = 0;
	AIDelay = 0;
	AICastInterval = 0;
	ArenaCastDelay = 0;
	castTime = 0;
	immuneBreak = 0;
	castTarget = 0;
	costMana = 0;
	useTime = 0;
	cdTime = 0;
	triggerWay = 0;
	triggerPro = 0;
	triggerType = 0;
	triggerArg1 = 0;
	triggerArg2 = 0;
	selectTargetType = 0;
	selectTargetNum = 0;
	flySpeed = 0;
	ShootTimes = 0;
	ShootInterval = 0;
	effectTarget = 0;
	effectWay = 0;
	effectOrder = 0;
	effectNum = 0;
	effectArg1 = 0;
	effectArg2 = 0;
	DamageWay = 0;
	DamageArg1 = 0;
	damage = 0;
	playerDamage = 0;
	bossDamage = 0;
	worldBossDamage = 0;
	eliteCombatDamage = 0;
	targetEffectId1 = 0;
	targetEffectPro1 = 0;
	targetEffectArg1_1 = 0;
	targetEffectArg1_2 = 0;
	targetEffectId2 = 0;
	targetEffectPro2 = 0;
	targetEffectArg2_1 = 0;
	targetEffectArg2_2 = 0;
	selfEffectId = 0;
	selfEffectPro = 0;
	selfEffectArg1 = 0;
	selfEffectArg2 = 0;
	Icon = 0;
	SoundCasting = "";
	SoundCast = "";
	SoundFly = "";
	SoundBeam = "";
	spellEffect = "";
	spellEffectPlace = 0;
	targetEffect = "";
	IsPlayEffect = 0;
	castIcon = 0;
	desc = "";
}

SheetSpellData* SheetSpell::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetSpellData*> SheetSpell::getAll ()
{
	vector<SheetSpellData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetSpell::init ()
{
	FILE *fp;
	fp = fopen ("./Spell.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Spell.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Spell.txt";
	vector<SheetSpellData> d;
	while (1) {
		SheetSpellData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name = value;
		SheetUtils::readToken (fp, value);
		oneData.IsNormal = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.SpellSlot = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.UseType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.DamageType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.cdId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.gcdId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AIPriority = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AICombatType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AICond = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AICondArg1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AICondArg2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AITarget = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AIDelay = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AICastInterval = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ArenaCastDelay = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.castTime = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.immuneBreak = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.castTarget = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.costMana = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.useTime = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.cdTime = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.triggerWay = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.triggerPro = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.triggerType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.triggerArg1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.triggerArg2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.selectTargetType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.selectTargetNum = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.flySpeed = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ShootTimes = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ShootInterval = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.effectTarget = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.effectWay = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.effectOrder = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.effectNum = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.effectArg1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.effectArg2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.DamageWay = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.DamageArg1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.damage = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.playerDamage = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.bossDamage = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.worldBossDamage = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.eliteCombatDamage = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.targetEffectId1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.targetEffectPro1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.targetEffectArg1_1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.targetEffectArg1_2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.targetEffectId2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.targetEffectPro2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.targetEffectArg2_1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.targetEffectArg2_2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.selfEffectId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.selfEffectPro = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.selfEffectArg1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.selfEffectArg2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Icon = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.SoundCasting = value;
		SheetUtils::readToken (fp, value);
		oneData.SoundCast = value;
		SheetUtils::readToken (fp, value);
		oneData.SoundFly = value;
		SheetUtils::readToken (fp, value);
		oneData.SoundBeam = value;
		SheetUtils::readToken (fp, value);
		oneData.spellEffect = value;
		SheetUtils::readToken (fp, value);
		oneData.spellEffectPlace = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.targetEffect = value;
		SheetUtils::readToken (fp, value);
		oneData.IsPlayEffect = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.castIcon = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.desc = value;
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetSpellData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetSpell::initLink ()
{
	return (0);
}

void SheetSpell::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetSpell" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "Name" << " = " << data[i].Name << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "IsNormal" << " = " << data[i].IsNormal << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "SpellSlot" << " = " << data[i].SpellSlot << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "UseType" << " = " << data[i].UseType << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "DamageType" << " = " << data[i].DamageType << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "cdId" << " = " << data[i].cdId << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "gcdId" << " = " << data[i].gcdId << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "AIPriority" << " = " << data[i].AIPriority << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "AICombatType" << " = " << data[i].AICombatType << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "AICond" << " = " << data[i].AICond << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "AICondArg1" << " = " << data[i].AICondArg1 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "AICondArg2" << " = " << data[i].AICondArg2 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "AITarget" << " = " << data[i].AITarget << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "AIDelay" << " = " << data[i].AIDelay << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "AICastInterval" << " = " << data[i].AICastInterval << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "ArenaCastDelay" << " = " << data[i].ArenaCastDelay << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "castTime" << " = " << data[i].castTime << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "immuneBreak" << " = " << data[i].immuneBreak << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "castTarget" << " = " << data[i].castTarget << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "costMana" << " = " << data[i].costMana << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "useTime" << " = " << data[i].useTime << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "cdTime" << " = " << data[i].cdTime << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "triggerWay" << " = " << data[i].triggerWay << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "triggerPro" << " = " << data[i].triggerPro << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "triggerType" << " = " << data[i].triggerType << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "triggerArg1" << " = " << data[i].triggerArg1 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "triggerArg2" << " = " << data[i].triggerArg2 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "selectTargetType" << " = " << data[i].selectTargetType << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "selectTargetNum" << " = " << data[i].selectTargetNum << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "flySpeed" << " = " << data[i].flySpeed << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "ShootTimes" << " = " << data[i].ShootTimes << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "ShootInterval" << " = " << data[i].ShootInterval << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "effectTarget" << " = " << data[i].effectTarget << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "effectWay" << " = " << data[i].effectWay << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "effectOrder" << " = " << data[i].effectOrder << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "effectNum" << " = " << data[i].effectNum << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "effectArg1" << " = " << data[i].effectArg1 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "effectArg2" << " = " << data[i].effectArg2 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "DamageWay" << " = " << data[i].DamageWay << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "DamageArg1" << " = " << data[i].DamageArg1 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "damage" << " = " << data[i].damage << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "playerDamage" << " = " << data[i].playerDamage << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "bossDamage" << " = " << data[i].bossDamage << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "worldBossDamage" << " = " << data[i].worldBossDamage << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "eliteCombatDamage" << " = " << data[i].eliteCombatDamage << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "targetEffectId1" << " = " << data[i].targetEffectId1 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "targetEffectPro1" << " = " << data[i].targetEffectPro1 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "targetEffectArg1_1" << " = " << data[i].targetEffectArg1_1 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "targetEffectArg1_2" << " = " << data[i].targetEffectArg1_2 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "targetEffectId2" << " = " << data[i].targetEffectId2 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "targetEffectPro2" << " = " << data[i].targetEffectPro2 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "targetEffectArg2_1" << " = " << data[i].targetEffectArg2_1 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "targetEffectArg2_2" << " = " << data[i].targetEffectArg2_2 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "selfEffectId" << " = " << data[i].selfEffectId << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "selfEffectPro" << " = " << data[i].selfEffectPro << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "selfEffectArg1" << " = " << data[i].selfEffectArg1 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "selfEffectArg2" << " = " << data[i].selfEffectArg2 << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "Icon" << " = " << data[i].Icon << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "SoundCasting" << " = " << data[i].SoundCasting << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "SoundCast" << " = " << data[i].SoundCast << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "SoundFly" << " = " << data[i].SoundFly << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "SoundBeam" << " = " << data[i].SoundBeam << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "spellEffect" << " = " << data[i].spellEffect << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "spellEffectPlace" << " = " << data[i].spellEffectPlace << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "targetEffect" << " = " << data[i].targetEffect << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "IsPlayEffect" << " = " << data[i].IsPlayEffect << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "castIcon" << " = " << data[i].castIcon << endl;
		cout << "SheetSpell" << "[" << i << "] :: data." << "desc" << " = " << data[i].desc << endl;
	}
}
SheetBuffData::SheetBuffData ()
{
	ID = 0;
	Type = 0;
	classId = 0;
	DispelLevel = 0;
	groupId = 0;
	groupLevel = 0;
	Name = "";
	damageType = 0;
	Times = 0;
	maxTimes = 0;
	overlayType = 0;
	durationTimes = 0;
	durationInterval = 0;
	triggerWay = 0;
	triggerArg1 = 0;
	triggerPro = 0;
	triggerType = 0;
	effectId1 = 0;
	eftArg1_1 = 0;
	eftArg1_2 = 0;
	effectId2 = 0;
	eftArg2_1 = 0;
	eftArg2_2 = 0;
	effectId3 = 0;
	eftArg3_1 = 0;
	eftArg3_2 = 0;
	Icon = 0;
	effectOne = "";
	effectSum = "";
	Scale = 0;
	desc = "";
}

SheetBuffData* SheetBuff::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetBuffData*> SheetBuff::getAll ()
{
	vector<SheetBuffData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetBuff::init ()
{
	FILE *fp;
	fp = fopen ("./Buff.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Buff.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Buff.txt";
	vector<SheetBuffData> d;
	while (1) {
		SheetBuffData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Type = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.classId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.DispelLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.groupId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.groupLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name = value;
		SheetUtils::readToken (fp, value);
		oneData.damageType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Times = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.maxTimes = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.overlayType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.durationTimes = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.durationInterval = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.triggerWay = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.triggerArg1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.triggerPro = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.triggerType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.effectId1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.eftArg1_1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.eftArg1_2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.effectId2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.eftArg2_1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.eftArg2_2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.effectId3 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.eftArg3_1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.eftArg3_2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Icon = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.effectOne = value;
		SheetUtils::readToken (fp, value);
		oneData.effectSum = value;
		SheetUtils::readToken (fp, value);
		oneData.Scale = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.desc = value;
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetBuffData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetBuff::initLink ()
{
	return (0);
}

void SheetBuff::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetBuff" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "Type" << " = " << data[i].Type << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "classId" << " = " << data[i].classId << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "DispelLevel" << " = " << data[i].DispelLevel << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "groupId" << " = " << data[i].groupId << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "groupLevel" << " = " << data[i].groupLevel << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "Name" << " = " << data[i].Name << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "damageType" << " = " << data[i].damageType << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "Times" << " = " << data[i].Times << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "maxTimes" << " = " << data[i].maxTimes << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "overlayType" << " = " << data[i].overlayType << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "durationTimes" << " = " << data[i].durationTimes << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "durationInterval" << " = " << data[i].durationInterval << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "triggerWay" << " = " << data[i].triggerWay << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "triggerArg1" << " = " << data[i].triggerArg1 << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "triggerPro" << " = " << data[i].triggerPro << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "triggerType" << " = " << data[i].triggerType << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "effectId1" << " = " << data[i].effectId1 << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "eftArg1_1" << " = " << data[i].eftArg1_1 << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "eftArg1_2" << " = " << data[i].eftArg1_2 << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "effectId2" << " = " << data[i].effectId2 << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "eftArg2_1" << " = " << data[i].eftArg2_1 << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "eftArg2_2" << " = " << data[i].eftArg2_2 << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "effectId3" << " = " << data[i].effectId3 << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "eftArg3_1" << " = " << data[i].eftArg3_1 << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "eftArg3_2" << " = " << data[i].eftArg3_2 << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "Icon" << " = " << data[i].Icon << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "effectOne" << " = " << data[i].effectOne << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "effectSum" << " = " << data[i].effectSum << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "Scale" << " = " << data[i].Scale << endl;
		cout << "SheetBuff" << "[" << i << "] :: data." << "desc" << " = " << data[i].desc << endl;
	}
}
SheetSummonData::SheetSummonData ()
{
	ID = 0;
	MonsterId = 0;
	OffTrack = 0;
	OffPos = 0;
	OffCombatPos = 0;
}

SheetSummonData* SheetSummon::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetSummonData*> SheetSummon::getAll ()
{
	vector<SheetSummonData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetSummon::init ()
{
	FILE *fp;
	fp = fopen ("./Summon.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Summon.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Summon.txt";
	vector<SheetSummonData> d;
	while (1) {
		SheetSummonData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MonsterId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.OffTrack = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.OffPos = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.OffCombatPos = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetSummonData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetSummon::initLink ()
{
	return (0);
}

void SheetSummon::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetSummon" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetSummon" << "[" << i << "] :: data." << "MonsterId" << " = " << data[i].MonsterId << endl;
		cout << "SheetSummon" << "[" << i << "] :: data." << "OffTrack" << " = " << data[i].OffTrack << endl;
		cout << "SheetSummon" << "[" << i << "] :: data." << "OffPos" << " = " << data[i].OffPos << endl;
		cout << "SheetSummon" << "[" << i << "] :: data." << "OffCombatPos" << " = " << data[i].OffCombatPos << endl;
	}
}
SheetQuestData::SheetQuestData ()
{
	ID = 0;
	OrderId = 0;
	Name = "";
	RequireLevel = 0;
	PreQuestId = 0;
	AccepteNpcId = 0;
	CompleteNpcId = 0;
	DungeonLevelId = 0;
	TargetType = 0;
	TargetId = 0;
	TargetNum = 0;
	RewardId = 0;
	Desc = "";
}

SheetQuestData* SheetQuest::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetQuestData*> SheetQuest::getAll ()
{
	vector<SheetQuestData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetQuest::init ()
{
	FILE *fp;
	fp = fopen ("./Quest.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Quest.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Quest.txt";
	vector<SheetQuestData> d;
	while (1) {
		SheetQuestData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.OrderId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name = value;
		SheetUtils::readToken (fp, value);
		oneData.RequireLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PreQuestId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AccepteNpcId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.CompleteNpcId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.DungeonLevelId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.TargetType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.TargetId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.TargetNum = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.RewardId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Desc = value;
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetQuestData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetQuest::initLink ()
{
	return (0);
}

void SheetQuest::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetQuest" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetQuest" << "[" << i << "] :: data." << "OrderId" << " = " << data[i].OrderId << endl;
		cout << "SheetQuest" << "[" << i << "] :: data." << "Name" << " = " << data[i].Name << endl;
		cout << "SheetQuest" << "[" << i << "] :: data." << "RequireLevel" << " = " << data[i].RequireLevel << endl;
		cout << "SheetQuest" << "[" << i << "] :: data." << "PreQuestId" << " = " << data[i].PreQuestId << endl;
		cout << "SheetQuest" << "[" << i << "] :: data." << "AccepteNpcId" << " = " << data[i].AccepteNpcId << endl;
		cout << "SheetQuest" << "[" << i << "] :: data." << "CompleteNpcId" << " = " << data[i].CompleteNpcId << endl;
		cout << "SheetQuest" << "[" << i << "] :: data." << "DungeonLevelId" << " = " << data[i].DungeonLevelId << endl;
		cout << "SheetQuest" << "[" << i << "] :: data." << "TargetType" << " = " << data[i].TargetType << endl;
		cout << "SheetQuest" << "[" << i << "] :: data." << "TargetId" << " = " << data[i].TargetId << endl;
		cout << "SheetQuest" << "[" << i << "] :: data." << "TargetNum" << " = " << data[i].TargetNum << endl;
		cout << "SheetQuest" << "[" << i << "] :: data." << "RewardId" << " = " << data[i].RewardId << endl;
		cout << "SheetQuest" << "[" << i << "] :: data." << "Desc" << " = " << data[i].Desc << endl;
	}
}
SheetEffectsData::SheetEffectsData ()
{
	ID = "";
	Tier = 0;
	HurtFrame = 0;
}

SheetEffectsData* SheetEffects::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetEffectsData*> SheetEffects::getAll ()
{
	vector<SheetEffectsData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetEffects::init ()
{
	FILE *fp;
	fp = fopen ("./Effects.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Effects.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Effects.txt";
	vector<SheetEffectsData> d;
	while (1) {
		SheetEffectsData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = value;
		SheetUtils::readToken (fp, value);
		oneData.Tier = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.HurtFrame = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetEffectsData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetEffects::initLink ()
{
	return (0);
}

void SheetEffects::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetEffects" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetEffects" << "[" << i << "] :: data." << "Tier" << " = " << data[i].Tier << endl;
		cout << "SheetEffects" << "[" << i << "] :: data." << "HurtFrame" << " = " << data[i].HurtFrame << endl;
	}
}
SheetDungeonData::SheetDungeonData ()
{
	ID = 0;
	Name = "";
	SceneId = 0;
	RequireLevel = 0;
	PreDungeon = 0;
	MaterialLevel = 0;
}

SheetDungeonData* SheetDungeon::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetDungeonData*> SheetDungeon::getAll ()
{
	vector<SheetDungeonData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetDungeon::init ()
{
	FILE *fp;
	fp = fopen ("./Dungeon.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Dungeon.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Dungeon.txt";
	vector<SheetDungeonData> d;
	while (1) {
		SheetDungeonData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name = value;
		SheetUtils::readToken (fp, value);
		oneData.SceneId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.RequireLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PreDungeon = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MaterialLevel = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetDungeonData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetDungeon::initLink ()
{
	return (0);
}

void SheetDungeon::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetDungeon" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetDungeon" << "[" << i << "] :: data." << "Name" << " = " << data[i].Name << endl;
		cout << "SheetDungeon" << "[" << i << "] :: data." << "SceneId" << " = " << data[i].SceneId << endl;
		cout << "SheetDungeon" << "[" << i << "] :: data." << "RequireLevel" << " = " << data[i].RequireLevel << endl;
		cout << "SheetDungeon" << "[" << i << "] :: data." << "PreDungeon" << " = " << data[i].PreDungeon << endl;
		cout << "SheetDungeon" << "[" << i << "] :: data." << "MaterialLevel" << " = " << data[i].MaterialLevel << endl;
	}
}
SheetDungeonLevelData::SheetDungeonLevelData ()
{
	ID = 0;
	Type = 0;
	DungeonId = 0;
	Name = "";
	MinLevel = 0;
	MaxLevel = 0;
	PreLevel1 = 0;
	PreLevel2 = 0;
	AcceptedQuestId = 0;
	CompleteQuestId = 0;
	PlayerCamp = 0;
	BossHeadID = 0;
	CombatId = 0;
	CombatDuration = 0;
	RewardId = 0;
	Next = 0;
	TargetType = 0;
	TargetArg1 = 0;
	TargetArg2 = 0;
	PreDramaId = 0;
	AfterDramaId = 0;
	IsNextWave = 0;
	IsCanWin = 0;
	IsCanEscrow = 0;
	IsShowProgress = 0;
	DropId = 0;
	DropNum = 0;
	DropCrit = 0;
	SuitLevel = 0;
}

SheetDungeonLevelData* SheetDungeonLevel::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetDungeonLevelData*> SheetDungeonLevel::getAll ()
{
	vector<SheetDungeonLevelData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetDungeonLevel::init ()
{
	FILE *fp;
	fp = fopen ("./DungeonLevel.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "DungeonLevel.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "DungeonLevel.txt";
	vector<SheetDungeonLevelData> d;
	while (1) {
		SheetDungeonLevelData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Type = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.DungeonId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name = value;
		SheetUtils::readToken (fp, value);
		oneData.MinLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MaxLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PreLevel1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PreLevel2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AcceptedQuestId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.CompleteQuestId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PlayerCamp = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.BossHeadID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.CombatId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.CombatDuration = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.RewardId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Next = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.TargetType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.TargetArg1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.TargetArg2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PreDramaId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AfterDramaId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.IsNextWave = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.IsCanWin = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.IsCanEscrow = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.IsShowProgress = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.DropId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.DropNum = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.DropCrit = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.SuitLevel = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetDungeonLevelData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetDungeonLevel::initLink ()
{
	return (0);
}

void SheetDungeonLevel::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "Type" << " = " << data[i].Type << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "DungeonId" << " = " << data[i].DungeonId << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "Name" << " = " << data[i].Name << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "MinLevel" << " = " << data[i].MinLevel << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "MaxLevel" << " = " << data[i].MaxLevel << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "PreLevel1" << " = " << data[i].PreLevel1 << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "PreLevel2" << " = " << data[i].PreLevel2 << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "AcceptedQuestId" << " = " << data[i].AcceptedQuestId << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "CompleteQuestId" << " = " << data[i].CompleteQuestId << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "PlayerCamp" << " = " << data[i].PlayerCamp << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "BossHeadID" << " = " << data[i].BossHeadID << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "CombatId" << " = " << data[i].CombatId << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "CombatDuration" << " = " << data[i].CombatDuration << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "RewardId" << " = " << data[i].RewardId << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "Next" << " = " << data[i].Next << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "TargetType" << " = " << data[i].TargetType << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "TargetArg1" << " = " << data[i].TargetArg1 << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "TargetArg2" << " = " << data[i].TargetArg2 << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "PreDramaId" << " = " << data[i].PreDramaId << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "AfterDramaId" << " = " << data[i].AfterDramaId << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "IsNextWave" << " = " << data[i].IsNextWave << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "IsCanWin" << " = " << data[i].IsCanWin << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "IsCanEscrow" << " = " << data[i].IsCanEscrow << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "IsShowProgress" << " = " << data[i].IsShowProgress << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "DropId" << " = " << data[i].DropId << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "DropNum" << " = " << data[i].DropNum << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "DropCrit" << " = " << data[i].DropCrit << endl;
		cout << "SheetDungeonLevel" << "[" << i << "] :: data." << "SuitLevel" << " = " << data[i].SuitLevel << endl;
	}
}
SheetCombatWaveData::SheetCombatWaveData ()
{
	CombatId = 0;
	WaveId = 0;
	WaitTime = 0;
	IntervalTime = 0;
}

SheetCombatWaveData* SheetCombatWave::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetCombatWaveData*> SheetCombatWave::getAll ()
{
	vector<SheetCombatWaveData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetCombatWave::init ()
{
	FILE *fp;
	fp = fopen ("./CombatWave.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "CombatWave.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "CombatWave.txt";
	vector<SheetCombatWaveData> d;
	while (1) {
		SheetCombatWaveData oneData;
		SheetUtils::readToken (fp, value);
		oneData.CombatId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.WaveId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.WaitTime = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.IntervalTime = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetCombatWaveData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetCombatWave::initLink ()
{
	return (0);
}

void SheetCombatWave::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetCombatWave" << "[" << i << "] :: data." << "CombatId" << " = " << data[i].CombatId << endl;
		cout << "SheetCombatWave" << "[" << i << "] :: data." << "WaveId" << " = " << data[i].WaveId << endl;
		cout << "SheetCombatWave" << "[" << i << "] :: data." << "WaitTime" << " = " << data[i].WaitTime << endl;
		cout << "SheetCombatWave" << "[" << i << "] :: data." << "IntervalTime" << " = " << data[i].IntervalTime << endl;
	}
}
SheetCombatMonsterData::SheetCombatMonsterData ()
{
	CombatId = 0;
	WaveId = 0;
	Interval = 0;
	Camp = 0;
	MonsterId = 0;
	AIType = 0;
	AIArg1 = 0;
	BornTrack = 0;
	BornOffX = 0;
	EventType = 0;
	EventTime = 0;
	EventArg1 = 0;
	DropType = 0;
}

SheetCombatMonsterData* SheetCombatMonster::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetCombatMonsterData*> SheetCombatMonster::getAll ()
{
	vector<SheetCombatMonsterData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetCombatMonster::init ()
{
	FILE *fp;
	fp = fopen ("./CombatMonster.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "CombatMonster.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "CombatMonster.txt";
	vector<SheetCombatMonsterData> d;
	while (1) {
		SheetCombatMonsterData oneData;
		SheetUtils::readToken (fp, value);
		oneData.CombatId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.WaveId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Interval = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Camp = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MonsterId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AIType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AIArg1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.BornTrack = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.BornOffX = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.EventType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.EventTime = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.EventArg1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.DropType = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetCombatMonsterData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetCombatMonster::initLink ()
{
	return (0);
}

void SheetCombatMonster::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetCombatMonster" << "[" << i << "] :: data." << "CombatId" << " = " << data[i].CombatId << endl;
		cout << "SheetCombatMonster" << "[" << i << "] :: data." << "WaveId" << " = " << data[i].WaveId << endl;
		cout << "SheetCombatMonster" << "[" << i << "] :: data." << "Interval" << " = " << data[i].Interval << endl;
		cout << "SheetCombatMonster" << "[" << i << "] :: data." << "Camp" << " = " << data[i].Camp << endl;
		cout << "SheetCombatMonster" << "[" << i << "] :: data." << "MonsterId" << " = " << data[i].MonsterId << endl;
		cout << "SheetCombatMonster" << "[" << i << "] :: data." << "AIType" << " = " << data[i].AIType << endl;
		cout << "SheetCombatMonster" << "[" << i << "] :: data." << "AIArg1" << " = " << data[i].AIArg1 << endl;
		cout << "SheetCombatMonster" << "[" << i << "] :: data." << "BornTrack" << " = " << data[i].BornTrack << endl;
		cout << "SheetCombatMonster" << "[" << i << "] :: data." << "BornOffX" << " = " << data[i].BornOffX << endl;
		cout << "SheetCombatMonster" << "[" << i << "] :: data." << "EventType" << " = " << data[i].EventType << endl;
		cout << "SheetCombatMonster" << "[" << i << "] :: data." << "EventTime" << " = " << data[i].EventTime << endl;
		cout << "SheetCombatMonster" << "[" << i << "] :: data." << "EventArg1" << " = " << data[i].EventArg1 << endl;
		cout << "SheetCombatMonster" << "[" << i << "] :: data." << "DropType" << " = " << data[i].DropType << endl;
	}
}
SheetDramaCombatRoleData::SheetDramaCombatRoleData ()
{
	CombatId = 0;
	RoleId = 0;
	IsPlayer = 0;
}

SheetDramaCombatRoleData* SheetDramaCombatRole::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetDramaCombatRoleData*> SheetDramaCombatRole::getAll ()
{
	vector<SheetDramaCombatRoleData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetDramaCombatRole::init ()
{
	FILE *fp;
	fp = fopen ("./DramaCombatRole.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "DramaCombatRole.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "DramaCombatRole.txt";
	vector<SheetDramaCombatRoleData> d;
	while (1) {
		SheetDramaCombatRoleData oneData;
		SheetUtils::readToken (fp, value);
		oneData.CombatId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.RoleId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.IsPlayer = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetDramaCombatRoleData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetDramaCombatRole::initLink ()
{
	return (0);
}

void SheetDramaCombatRole::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetDramaCombatRole" << "[" << i << "] :: data." << "CombatId" << " = " << data[i].CombatId << endl;
		cout << "SheetDramaCombatRole" << "[" << i << "] :: data." << "RoleId" << " = " << data[i].RoleId << endl;
		cout << "SheetDramaCombatRole" << "[" << i << "] :: data." << "IsPlayer" << " = " << data[i].IsPlayer << endl;
	}
}
SheetRestrainData::SheetRestrainData ()
{
	ID = 0;
	ClassId1 = 0;
	ClassId2 = 0;
	ClassId3 = 0;
	SpellType = 0;
}

SheetRestrainData* SheetRestrain::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetRestrainData*> SheetRestrain::getAll ()
{
	vector<SheetRestrainData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetRestrain::init ()
{
	FILE *fp;
	fp = fopen ("./Restrain.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Restrain.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Restrain.txt";
	vector<SheetRestrainData> d;
	while (1) {
		SheetRestrainData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ClassId1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ClassId2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ClassId3 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.SpellType = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetRestrainData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetRestrain::initLink ()
{
	return (0);
}

void SheetRestrain::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetRestrain" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetRestrain" << "[" << i << "] :: data." << "ClassId1" << " = " << data[i].ClassId1 << endl;
		cout << "SheetRestrain" << "[" << i << "] :: data." << "ClassId2" << " = " << data[i].ClassId2 << endl;
		cout << "SheetRestrain" << "[" << i << "] :: data." << "ClassId3" << " = " << data[i].ClassId3 << endl;
		cout << "SheetRestrain" << "[" << i << "] :: data." << "SpellType" << " = " << data[i].SpellType << endl;
	}
}
SheetItemData::SheetItemData ()
{
	ID = 0;
	Name = "";
	Type = 0;
	TypeArg = 0;
	Level = 0;
	Quality = 0;
	Stacks = 0;
	Duration = 0;
	SellMoney = 0;
	SellBadge = 0;
	ComposeId = 0;
	UseEffect = 0;
	UseArg1 = 0;
	UseArg2 = 0;
	UseRemove = 0;
	Icon = 0;
	DropIcon = 0;
	Desc = "";
}

SheetItemData* SheetItem::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetItemData*> SheetItem::getAll ()
{
	vector<SheetItemData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetItem::init ()
{
	FILE *fp;
	fp = fopen ("./Item.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Item.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Item.txt";
	vector<SheetItemData> d;
	while (1) {
		SheetItemData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name = value;
		SheetUtils::readToken (fp, value);
		oneData.Type = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.TypeArg = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Level = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Quality = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Stacks = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Duration = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.SellMoney = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.SellBadge = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ComposeId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.UseEffect = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.UseArg1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.UseArg2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.UseRemove = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Icon = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.DropIcon = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Desc = value;
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetItemData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetItem::initLink ()
{
	return (0);
}

void SheetItem::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetItem" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "Name" << " = " << data[i].Name << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "Type" << " = " << data[i].Type << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "TypeArg" << " = " << data[i].TypeArg << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "Level" << " = " << data[i].Level << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "Quality" << " = " << data[i].Quality << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "Stacks" << " = " << data[i].Stacks << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "Duration" << " = " << data[i].Duration << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "SellMoney" << " = " << data[i].SellMoney << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "SellBadge" << " = " << data[i].SellBadge << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "ComposeId" << " = " << data[i].ComposeId << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "UseEffect" << " = " << data[i].UseEffect << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "UseArg1" << " = " << data[i].UseArg1 << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "UseArg2" << " = " << data[i].UseArg2 << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "UseRemove" << " = " << data[i].UseRemove << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "Icon" << " = " << data[i].Icon << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "DropIcon" << " = " << data[i].DropIcon << endl;
		cout << "SheetItem" << "[" << i << "] :: data." << "Desc" << " = " << data[i].Desc << endl;
	}
}
SheetEquipmentPropData::SheetEquipmentPropData ()
{
	ItemId = 0;
	Type = 0;
	PropId = 0;
	Value = 0;
}

SheetEquipmentPropData* SheetEquipmentProp::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetEquipmentPropData*> SheetEquipmentProp::getAll ()
{
	vector<SheetEquipmentPropData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetEquipmentProp::init ()
{
	FILE *fp;
	fp = fopen ("./EquipmentProp.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "EquipmentProp.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "EquipmentProp.txt";
	vector<SheetEquipmentPropData> d;
	while (1) {
		SheetEquipmentPropData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ItemId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Type = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PropId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Value = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetEquipmentPropData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetEquipmentProp::initLink ()
{
	return (0);
}

void SheetEquipmentProp::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetEquipmentProp" << "[" << i << "] :: data." << "ItemId" << " = " << data[i].ItemId << endl;
		cout << "SheetEquipmentProp" << "[" << i << "] :: data." << "Type" << " = " << data[i].Type << endl;
		cout << "SheetEquipmentProp" << "[" << i << "] :: data." << "PropId" << " = " << data[i].PropId << endl;
		cout << "SheetEquipmentProp" << "[" << i << "] :: data." << "Value" << " = " << data[i].Value << endl;
	}
}
SheetGemData::SheetGemData ()
{
	ID = 0;
	Name = "";
	Level = 0;
	Quality = 0;
	PropId = 0;
	Value = 0;
	Icon = 0;
	Desc = "";
}

SheetGemData* SheetGem::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetGemData*> SheetGem::getAll ()
{
	vector<SheetGemData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetGem::init ()
{
	FILE *fp;
	fp = fopen ("./Gem.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Gem.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Gem.txt";
	vector<SheetGemData> d;
	while (1) {
		SheetGemData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name = value;
		SheetUtils::readToken (fp, value);
		oneData.Level = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Quality = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PropId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Value = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Icon = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Desc = value;
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetGemData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetGem::initLink ()
{
	return (0);
}

void SheetGem::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetGem" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetGem" << "[" << i << "] :: data." << "Name" << " = " << data[i].Name << endl;
		cout << "SheetGem" << "[" << i << "] :: data." << "Level" << " = " << data[i].Level << endl;
		cout << "SheetGem" << "[" << i << "] :: data." << "Quality" << " = " << data[i].Quality << endl;
		cout << "SheetGem" << "[" << i << "] :: data." << "PropId" << " = " << data[i].PropId << endl;
		cout << "SheetGem" << "[" << i << "] :: data." << "Value" << " = " << data[i].Value << endl;
		cout << "SheetGem" << "[" << i << "] :: data." << "Icon" << " = " << data[i].Icon << endl;
		cout << "SheetGem" << "[" << i << "] :: data." << "Desc" << " = " << data[i].Desc << endl;
	}
}
SheetGemInsertRuleData::SheetGemInsertRuleData ()
{
	ClassId = 0;
	PropId1 = 0;
	PropId2 = 0;
	PropId3 = 0;
	PropId4 = 0;
	PropId5 = 0;
	PropId6 = 0;
	PropId7 = 0;
	PropId8 = 0;
}

SheetGemInsertRuleData* SheetGemInsertRule::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetGemInsertRuleData*> SheetGemInsertRule::getAll ()
{
	vector<SheetGemInsertRuleData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetGemInsertRule::init ()
{
	FILE *fp;
	fp = fopen ("./GemInsertRule.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "GemInsertRule.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "GemInsertRule.txt";
	vector<SheetGemInsertRuleData> d;
	while (1) {
		SheetGemInsertRuleData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ClassId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PropId1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PropId2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PropId3 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PropId4 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PropId5 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PropId6 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PropId7 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PropId8 = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetGemInsertRuleData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetGemInsertRule::initLink ()
{
	return (0);
}

void SheetGemInsertRule::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetGemInsertRule" << "[" << i << "] :: data." << "ClassId" << " = " << data[i].ClassId << endl;
		cout << "SheetGemInsertRule" << "[" << i << "] :: data." << "PropId1" << " = " << data[i].PropId1 << endl;
		cout << "SheetGemInsertRule" << "[" << i << "] :: data." << "PropId2" << " = " << data[i].PropId2 << endl;
		cout << "SheetGemInsertRule" << "[" << i << "] :: data." << "PropId3" << " = " << data[i].PropId3 << endl;
		cout << "SheetGemInsertRule" << "[" << i << "] :: data." << "PropId4" << " = " << data[i].PropId4 << endl;
		cout << "SheetGemInsertRule" << "[" << i << "] :: data." << "PropId5" << " = " << data[i].PropId5 << endl;
		cout << "SheetGemInsertRule" << "[" << i << "] :: data." << "PropId6" << " = " << data[i].PropId6 << endl;
		cout << "SheetGemInsertRule" << "[" << i << "] :: data." << "PropId7" << " = " << data[i].PropId7 << endl;
		cout << "SheetGemInsertRule" << "[" << i << "] :: data." << "PropId8" << " = " << data[i].PropId8 << endl;
	}
}
SheetRoleLevelData::SheetRoleLevelData ()
{
	Level = 0;
	NeedExp = 0;
	AddPower = 0;
	BuyMoney = 0;
	HiddenLevelMoney = 0;
	HiddenLevelMoney2 = 0;
	WorldBossMoney = 0;
	WorldBossKillMoney = 0;
	ArenaMoney = 0;
}

SheetRoleLevelData* SheetRoleLevel::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetRoleLevelData*> SheetRoleLevel::getAll ()
{
	vector<SheetRoleLevelData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetRoleLevel::init ()
{
	FILE *fp;
	fp = fopen ("./RoleLevel.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "RoleLevel.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "RoleLevel.txt";
	vector<SheetRoleLevelData> d;
	while (1) {
		SheetRoleLevelData oneData;
		SheetUtils::readToken (fp, value);
		oneData.Level = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.NeedExp = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.AddPower = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.BuyMoney = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.HiddenLevelMoney = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.HiddenLevelMoney2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.WorldBossMoney = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.WorldBossKillMoney = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ArenaMoney = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetRoleLevelData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetRoleLevel::initLink ()
{
	return (0);
}

void SheetRoleLevel::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetRoleLevel" << "[" << i << "] :: data." << "Level" << " = " << data[i].Level << endl;
		cout << "SheetRoleLevel" << "[" << i << "] :: data." << "NeedExp" << " = " << data[i].NeedExp << endl;
		cout << "SheetRoleLevel" << "[" << i << "] :: data." << "AddPower" << " = " << data[i].AddPower << endl;
		cout << "SheetRoleLevel" << "[" << i << "] :: data." << "BuyMoney" << " = " << data[i].BuyMoney << endl;
		cout << "SheetRoleLevel" << "[" << i << "] :: data." << "HiddenLevelMoney" << " = " << data[i].HiddenLevelMoney << endl;
		cout << "SheetRoleLevel" << "[" << i << "] :: data." << "HiddenLevelMoney2" << " = " << data[i].HiddenLevelMoney2 << endl;
		cout << "SheetRoleLevel" << "[" << i << "] :: data." << "WorldBossMoney" << " = " << data[i].WorldBossMoney << endl;
		cout << "SheetRoleLevel" << "[" << i << "] :: data." << "WorldBossKillMoney" << " = " << data[i].WorldBossKillMoney << endl;
		cout << "SheetRoleLevel" << "[" << i << "] :: data." << "ArenaMoney" << " = " << data[i].ArenaMoney << endl;
	}
}
SheetPartnerLevelUpData::SheetPartnerLevelUpData ()
{
	Quality = 0;
	Level = 0;
	NeedExp = 0;
	NeedMoney = 0;
}

SheetPartnerLevelUpData* SheetPartnerLevelUp::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetPartnerLevelUpData*> SheetPartnerLevelUp::getAll ()
{
	vector<SheetPartnerLevelUpData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetPartnerLevelUp::init ()
{
	FILE *fp;
	fp = fopen ("./PartnerLevelUp.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "PartnerLevelUp.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "PartnerLevelUp.txt";
	vector<SheetPartnerLevelUpData> d;
	while (1) {
		SheetPartnerLevelUpData oneData;
		SheetUtils::readToken (fp, value);
		oneData.Quality = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Level = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.NeedExp = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.NeedMoney = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetPartnerLevelUpData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetPartnerLevelUp::initLink ()
{
	return (0);
}

void SheetPartnerLevelUp::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetPartnerLevelUp" << "[" << i << "] :: data." << "Quality" << " = " << data[i].Quality << endl;
		cout << "SheetPartnerLevelUp" << "[" << i << "] :: data." << "Level" << " = " << data[i].Level << endl;
		cout << "SheetPartnerLevelUp" << "[" << i << "] :: data." << "NeedExp" << " = " << data[i].NeedExp << endl;
		cout << "SheetPartnerLevelUp" << "[" << i << "] :: data." << "NeedMoney" << " = " << data[i].NeedMoney << endl;
	}
}
SheetArenaCombatTargetData::SheetArenaCombatTargetData ()
{
	MinRank = 0;
	MaxRank = 0;
	Offset1 = 0;
	Offset2 = 0;
	Offset3 = 0;
	Offset4 = 0;
	Offset5 = 0;
}

SheetArenaCombatTargetData* SheetArenaCombatTarget::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetArenaCombatTargetData*> SheetArenaCombatTarget::getAll ()
{
	vector<SheetArenaCombatTargetData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetArenaCombatTarget::init ()
{
	FILE *fp;
	fp = fopen ("./ArenaCombatTarget.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "ArenaCombatTarget.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "ArenaCombatTarget.txt";
	vector<SheetArenaCombatTargetData> d;
	while (1) {
		SheetArenaCombatTargetData oneData;
		SheetUtils::readToken (fp, value);
		oneData.MinRank = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MaxRank = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Offset1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Offset2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Offset3 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Offset4 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Offset5 = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetArenaCombatTargetData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetArenaCombatTarget::initLink ()
{
	return (0);
}

void SheetArenaCombatTarget::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetArenaCombatTarget" << "[" << i << "] :: data." << "MinRank" << " = " << data[i].MinRank << endl;
		cout << "SheetArenaCombatTarget" << "[" << i << "] :: data." << "MaxRank" << " = " << data[i].MaxRank << endl;
		cout << "SheetArenaCombatTarget" << "[" << i << "] :: data." << "Offset1" << " = " << data[i].Offset1 << endl;
		cout << "SheetArenaCombatTarget" << "[" << i << "] :: data." << "Offset2" << " = " << data[i].Offset2 << endl;
		cout << "SheetArenaCombatTarget" << "[" << i << "] :: data." << "Offset3" << " = " << data[i].Offset3 << endl;
		cout << "SheetArenaCombatTarget" << "[" << i << "] :: data." << "Offset4" << " = " << data[i].Offset4 << endl;
		cout << "SheetArenaCombatTarget" << "[" << i << "] :: data." << "Offset5" << " = " << data[i].Offset5 << endl;
	}
}
SheetArenaRankRewardData::SheetArenaRankRewardData ()
{
	MinRank = 0;
	MaxRank = 0;
	MoneyMul = 0;
	IdentifyItem = 0;
	TalentItem = 0;
}

SheetArenaRankRewardData* SheetArenaRankReward::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetArenaRankRewardData*> SheetArenaRankReward::getAll ()
{
	vector<SheetArenaRankRewardData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetArenaRankReward::init ()
{
	FILE *fp;
	fp = fopen ("./ArenaRankReward.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "ArenaRankReward.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "ArenaRankReward.txt";
	vector<SheetArenaRankRewardData> d;
	while (1) {
		SheetArenaRankRewardData oneData;
		SheetUtils::readToken (fp, value);
		oneData.MinRank = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MaxRank = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MoneyMul = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.IdentifyItem = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.TalentItem = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetArenaRankRewardData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetArenaRankReward::initLink ()
{
	return (0);
}

void SheetArenaRankReward::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetArenaRankReward" << "[" << i << "] :: data." << "MinRank" << " = " << data[i].MinRank << endl;
		cout << "SheetArenaRankReward" << "[" << i << "] :: data." << "MaxRank" << " = " << data[i].MaxRank << endl;
		cout << "SheetArenaRankReward" << "[" << i << "] :: data." << "MoneyMul" << " = " << data[i].MoneyMul << endl;
		cout << "SheetArenaRankReward" << "[" << i << "] :: data." << "IdentifyItem" << " = " << data[i].IdentifyItem << endl;
		cout << "SheetArenaRankReward" << "[" << i << "] :: data." << "TalentItem" << " = " << data[i].TalentItem << endl;
	}
}
SheetWorldBossRankRewardData::SheetWorldBossRankRewardData ()
{
	MinRank = 0;
	MaxRank = 0;
	IdentifyItem = 0;
	MoneyMul = 0;
	TalentItem = 0;
}

SheetWorldBossRankRewardData* SheetWorldBossRankReward::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetWorldBossRankRewardData*> SheetWorldBossRankReward::getAll ()
{
	vector<SheetWorldBossRankRewardData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetWorldBossRankReward::init ()
{
	FILE *fp;
	fp = fopen ("./WorldBossRankReward.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "WorldBossRankReward.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "WorldBossRankReward.txt";
	vector<SheetWorldBossRankRewardData> d;
	while (1) {
		SheetWorldBossRankRewardData oneData;
		SheetUtils::readToken (fp, value);
		oneData.MinRank = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MaxRank = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.IdentifyItem = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MoneyMul = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.TalentItem = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetWorldBossRankRewardData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetWorldBossRankReward::initLink ()
{
	return (0);
}

void SheetWorldBossRankReward::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetWorldBossRankReward" << "[" << i << "] :: data." << "MinRank" << " = " << data[i].MinRank << endl;
		cout << "SheetWorldBossRankReward" << "[" << i << "] :: data." << "MaxRank" << " = " << data[i].MaxRank << endl;
		cout << "SheetWorldBossRankReward" << "[" << i << "] :: data." << "IdentifyItem" << " = " << data[i].IdentifyItem << endl;
		cout << "SheetWorldBossRankReward" << "[" << i << "] :: data." << "MoneyMul" << " = " << data[i].MoneyMul << endl;
		cout << "SheetWorldBossRankReward" << "[" << i << "] :: data." << "TalentItem" << " = " << data[i].TalentItem << endl;
	}
}
SheetVipLevelData::SheetVipLevelData ()
{
	Level = 0;
	RechargeAmount = 0;
	BuyPowerTime = 0;
	BuyMoneyTime = 0;
	ResetEliteLevelTimes = 0;
}

SheetVipLevelData* SheetVipLevel::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetVipLevelData*> SheetVipLevel::getAll ()
{
	vector<SheetVipLevelData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetVipLevel::init ()
{
	FILE *fp;
	fp = fopen ("./VipLevel.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "VipLevel.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "VipLevel.txt";
	vector<SheetVipLevelData> d;
	while (1) {
		SheetVipLevelData oneData;
		SheetUtils::readToken (fp, value);
		oneData.Level = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.RechargeAmount = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.BuyPowerTime = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.BuyMoneyTime = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResetEliteLevelTimes = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetVipLevelData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetVipLevel::initLink ()
{
	return (0);
}

void SheetVipLevel::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetVipLevel" << "[" << i << "] :: data." << "Level" << " = " << data[i].Level << endl;
		cout << "SheetVipLevel" << "[" << i << "] :: data." << "RechargeAmount" << " = " << data[i].RechargeAmount << endl;
		cout << "SheetVipLevel" << "[" << i << "] :: data." << "BuyPowerTime" << " = " << data[i].BuyPowerTime << endl;
		cout << "SheetVipLevel" << "[" << i << "] :: data." << "BuyMoneyTime" << " = " << data[i].BuyMoneyTime << endl;
		cout << "SheetVipLevel" << "[" << i << "] :: data." << "ResetEliteLevelTimes" << " = " << data[i].ResetEliteLevelTimes << endl;
	}
}
SheetRewardData::SheetRewardData ()
{
	ID = 0;
	GroupId = 0;
	rewardType = 0;
	RewardId = 0;
	RewardNum = 0;
	Probability = 0;
}

SheetRewardData* SheetReward::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetRewardData*> SheetReward::getAll ()
{
	vector<SheetRewardData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetReward::init ()
{
	FILE *fp;
	fp = fopen ("./Reward.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Reward.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Reward.txt";
	vector<SheetRewardData> d;
	while (1) {
		SheetRewardData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.GroupId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.rewardType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.RewardId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.RewardNum = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Probability = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetRewardData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetReward::initLink ()
{
	return (0);
}

void SheetReward::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetReward" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetReward" << "[" << i << "] :: data." << "GroupId" << " = " << data[i].GroupId << endl;
		cout << "SheetReward" << "[" << i << "] :: data." << "rewardType" << " = " << data[i].rewardType << endl;
		cout << "SheetReward" << "[" << i << "] :: data." << "RewardId" << " = " << data[i].RewardId << endl;
		cout << "SheetReward" << "[" << i << "] :: data." << "RewardNum" << " = " << data[i].RewardNum << endl;
		cout << "SheetReward" << "[" << i << "] :: data." << "Probability" << " = " << data[i].Probability << endl;
	}
}
SheetLotPartnerData::SheetLotPartnerData ()
{
	RoleId = 0;
	CouponPro = 0;
	GoldPro = 0;
	RequireLevelId = 0;
}

SheetLotPartnerData* SheetLotPartner::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetLotPartnerData*> SheetLotPartner::getAll ()
{
	vector<SheetLotPartnerData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetLotPartner::init ()
{
	FILE *fp;
	fp = fopen ("./LotPartner.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "LotPartner.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "LotPartner.txt";
	vector<SheetLotPartnerData> d;
	while (1) {
		SheetLotPartnerData oneData;
		SheetUtils::readToken (fp, value);
		oneData.RoleId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.CouponPro = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.GoldPro = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.RequireLevelId = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetLotPartnerData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetLotPartner::initLink ()
{
	return (0);
}

void SheetLotPartner::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetLotPartner" << "[" << i << "] :: data." << "RoleId" << " = " << data[i].RoleId << endl;
		cout << "SheetLotPartner" << "[" << i << "] :: data." << "CouponPro" << " = " << data[i].CouponPro << endl;
		cout << "SheetLotPartner" << "[" << i << "] :: data." << "GoldPro" << " = " << data[i].GoldPro << endl;
		cout << "SheetLotPartner" << "[" << i << "] :: data." << "RequireLevelId" << " = " << data[i].RequireLevelId << endl;
	}
}
SheetLotGemData::SheetLotGemData ()
{
	GroupId = 0;
	ResType = 0;
	ResId = 0;
	ResNum = 0;
	Probability = 0;
}

SheetLotGemData* SheetLotGem::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetLotGemData*> SheetLotGem::getAll ()
{
	vector<SheetLotGemData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetLotGem::init ()
{
	FILE *fp;
	fp = fopen ("./LotGem.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "LotGem.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "LotGem.txt";
	vector<SheetLotGemData> d;
	while (1) {
		SheetLotGemData oneData;
		SheetUtils::readToken (fp, value);
		oneData.GroupId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResNum = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Probability = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetLotGemData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetLotGem::initLink ()
{
	return (0);
}

void SheetLotGem::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetLotGem" << "[" << i << "] :: data." << "GroupId" << " = " << data[i].GroupId << endl;
		cout << "SheetLotGem" << "[" << i << "] :: data." << "ResType" << " = " << data[i].ResType << endl;
		cout << "SheetLotGem" << "[" << i << "] :: data." << "ResId" << " = " << data[i].ResId << endl;
		cout << "SheetLotGem" << "[" << i << "] :: data." << "ResNum" << " = " << data[i].ResNum << endl;
		cout << "SheetLotGem" << "[" << i << "] :: data." << "Probability" << " = " << data[i].Probability << endl;
	}
}
SheetShopData::SheetShopData ()
{
	ID = 0;
	ResourceType = 0;
	ResourceId = 0;
	ResourceNum = 0;
	Price = 0;
	Desc = "";
	Icon = 0;
}

SheetShopData* SheetShop::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetShopData*> SheetShop::getAll ()
{
	vector<SheetShopData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetShop::init ()
{
	FILE *fp;
	fp = fopen ("./Shop.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Shop.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Shop.txt";
	vector<SheetShopData> d;
	while (1) {
		SheetShopData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResourceType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResourceId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResourceNum = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Price = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Desc = value;
		SheetUtils::readToken (fp, value);
		oneData.Icon = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetShopData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetShop::initLink ()
{
	return (0);
}

void SheetShop::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetShop" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetShop" << "[" << i << "] :: data." << "ResourceType" << " = " << data[i].ResourceType << endl;
		cout << "SheetShop" << "[" << i << "] :: data." << "ResourceId" << " = " << data[i].ResourceId << endl;
		cout << "SheetShop" << "[" << i << "] :: data." << "ResourceNum" << " = " << data[i].ResourceNum << endl;
		cout << "SheetShop" << "[" << i << "] :: data." << "Price" << " = " << data[i].Price << endl;
		cout << "SheetShop" << "[" << i << "] :: data." << "Desc" << " = " << data[i].Desc << endl;
		cout << "SheetShop" << "[" << i << "] :: data." << "Icon" << " = " << data[i].Icon << endl;
	}
}
SheetMountData::SheetMountData ()
{
	ID = 0;
	Name = "";
	SpellId = 0;
	Aptitude = 0;
	FeedCost = 0;
	MaxLuck = 0;
	Speed = 0;
}

SheetMountData* SheetMount::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetMountData*> SheetMount::getAll ()
{
	vector<SheetMountData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetMount::init ()
{
	FILE *fp;
	fp = fopen ("./Mount.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Mount.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Mount.txt";
	vector<SheetMountData> d;
	while (1) {
		SheetMountData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name = value;
		SheetUtils::readToken (fp, value);
		oneData.SpellId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Aptitude = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.FeedCost = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MaxLuck = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Speed = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetMountData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetMount::initLink ()
{
	return (0);
}

void SheetMount::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetMount" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetMount" << "[" << i << "] :: data." << "Name" << " = " << data[i].Name << endl;
		cout << "SheetMount" << "[" << i << "] :: data." << "SpellId" << " = " << data[i].SpellId << endl;
		cout << "SheetMount" << "[" << i << "] :: data." << "Aptitude" << " = " << data[i].Aptitude << endl;
		cout << "SheetMount" << "[" << i << "] :: data." << "FeedCost" << " = " << data[i].FeedCost << endl;
		cout << "SheetMount" << "[" << i << "] :: data." << "MaxLuck" << " = " << data[i].MaxLuck << endl;
		cout << "SheetMount" << "[" << i << "] :: data." << "Speed" << " = " << data[i].Speed << endl;
	}
}
SheetMountLevelUpData::SheetMountLevelUpData ()
{
	MountId = 0;
	MinValue = 0;
	MaxValue = 0;
	Probability = 0;
}

SheetMountLevelUpData* SheetMountLevelUp::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetMountLevelUpData*> SheetMountLevelUp::getAll ()
{
	vector<SheetMountLevelUpData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetMountLevelUp::init ()
{
	FILE *fp;
	fp = fopen ("./MountLevelUp.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "MountLevelUp.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "MountLevelUp.txt";
	vector<SheetMountLevelUpData> d;
	while (1) {
		SheetMountLevelUpData oneData;
		SheetUtils::readToken (fp, value);
		oneData.MountId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MinValue = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MaxValue = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Probability = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetMountLevelUpData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetMountLevelUp::initLink ()
{
	return (0);
}

void SheetMountLevelUp::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetMountLevelUp" << "[" << i << "] :: data." << "MountId" << " = " << data[i].MountId << endl;
		cout << "SheetMountLevelUp" << "[" << i << "] :: data." << "MinValue" << " = " << data[i].MinValue << endl;
		cout << "SheetMountLevelUp" << "[" << i << "] :: data." << "MaxValue" << " = " << data[i].MaxValue << endl;
		cout << "SheetMountLevelUp" << "[" << i << "] :: data." << "Probability" << " = " << data[i].Probability << endl;
	}
}
SheetLevelDropData::SheetLevelDropData ()
{
	LevelId = 0;
	ResType = 0;
	ResId = 0;
	ResNum = 0;
	IsGuide = 0;
}

SheetLevelDropData* SheetLevelDrop::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetLevelDropData*> SheetLevelDrop::getAll ()
{
	vector<SheetLevelDropData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetLevelDrop::init ()
{
	FILE *fp;
	fp = fopen ("./LevelDrop.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "LevelDrop.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "LevelDrop.txt";
	vector<SheetLevelDropData> d;
	while (1) {
		SheetLevelDropData oneData;
		SheetUtils::readToken (fp, value);
		oneData.LevelId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResNum = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.IsGuide = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetLevelDropData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetLevelDrop::initLink ()
{
	return (0);
}

void SheetLevelDrop::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetLevelDrop" << "[" << i << "] :: data." << "LevelId" << " = " << data[i].LevelId << endl;
		cout << "SheetLevelDrop" << "[" << i << "] :: data." << "ResType" << " = " << data[i].ResType << endl;
		cout << "SheetLevelDrop" << "[" << i << "] :: data." << "ResId" << " = " << data[i].ResId << endl;
		cout << "SheetLevelDrop" << "[" << i << "] :: data." << "ResNum" << " = " << data[i].ResNum << endl;
		cout << "SheetLevelDrop" << "[" << i << "] :: data." << "IsGuide" << " = " << data[i].IsGuide << endl;
	}
}
SheetDramaData::SheetDramaData ()
{
	ID = 0;
	Type = 0;
	Arg1 = 0;
	Arg2 = 0;
	Arg3 = 0;
	Arg4 = "";
	Arg5 = "";
}

SheetDramaData* SheetDrama::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetDramaData*> SheetDrama::getAll ()
{
	vector<SheetDramaData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetDrama::init ()
{
	FILE *fp;
	fp = fopen ("./Drama.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Drama.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Drama.txt";
	vector<SheetDramaData> d;
	while (1) {
		SheetDramaData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Type = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Arg1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Arg2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Arg3 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Arg4 = value;
		SheetUtils::readToken (fp, value);
		oneData.Arg5 = value;
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetDramaData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetDrama::initLink ()
{
	return (0);
}

void SheetDrama::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetDrama" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetDrama" << "[" << i << "] :: data." << "Type" << " = " << data[i].Type << endl;
		cout << "SheetDrama" << "[" << i << "] :: data." << "Arg1" << " = " << data[i].Arg1 << endl;
		cout << "SheetDrama" << "[" << i << "] :: data." << "Arg2" << " = " << data[i].Arg2 << endl;
		cout << "SheetDrama" << "[" << i << "] :: data." << "Arg3" << " = " << data[i].Arg3 << endl;
		cout << "SheetDrama" << "[" << i << "] :: data." << "Arg4" << " = " << data[i].Arg4 << endl;
		cout << "SheetDrama" << "[" << i << "] :: data." << "Arg5" << " = " << data[i].Arg5 << endl;
	}
}
SheetOpenActionData::SheetOpenActionData ()
{
	ID = 0;
	FunctionID = 0;
	OpenLevel = 0;
	OpenDungeonId = 0;
}

SheetOpenActionData* SheetOpenAction::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetOpenActionData*> SheetOpenAction::getAll ()
{
	vector<SheetOpenActionData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetOpenAction::init ()
{
	FILE *fp;
	fp = fopen ("./OpenAction.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "OpenAction.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "OpenAction.txt";
	vector<SheetOpenActionData> d;
	while (1) {
		SheetOpenActionData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.FunctionID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.OpenLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.OpenDungeonId = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetOpenActionData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetOpenAction::initLink ()
{
	return (0);
}

void SheetOpenAction::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetOpenAction" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetOpenAction" << "[" << i << "] :: data." << "FunctionID" << " = " << data[i].FunctionID << endl;
		cout << "SheetOpenAction" << "[" << i << "] :: data." << "OpenLevel" << " = " << data[i].OpenLevel << endl;
		cout << "SheetOpenAction" << "[" << i << "] :: data." << "OpenDungeonId" << " = " << data[i].OpenDungeonId << endl;
	}
}
SheetLevelTargetData::SheetLevelTargetData ()
{
	ID = 0;
	Content = "";
}

SheetLevelTargetData* SheetLevelTarget::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetLevelTargetData*> SheetLevelTarget::getAll ()
{
	vector<SheetLevelTargetData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetLevelTarget::init ()
{
	FILE *fp;
	fp = fopen ("./LevelTarget.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "LevelTarget.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "LevelTarget.txt";
	vector<SheetLevelTargetData> d;
	while (1) {
		SheetLevelTargetData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Content = value;
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetLevelTargetData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetLevelTarget::initLink ()
{
	return (0);
}

void SheetLevelTarget::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetLevelTarget" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetLevelTarget" << "[" << i << "] :: data." << "Content" << " = " << data[i].Content << endl;
	}
}
SheetLevelCorrespondingData::SheetLevelCorrespondingData ()
{
	LevelId = 0;
	LevelTargetId = 0;
	Arg1 = 0;
	Arg2 = 0;
}

SheetLevelCorrespondingData* SheetLevelCorresponding::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetLevelCorrespondingData*> SheetLevelCorresponding::getAll ()
{
	vector<SheetLevelCorrespondingData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetLevelCorresponding::init ()
{
	FILE *fp;
	fp = fopen ("./LevelCorresponding.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "LevelCorresponding.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "LevelCorresponding.txt";
	vector<SheetLevelCorrespondingData> d;
	while (1) {
		SheetLevelCorrespondingData oneData;
		SheetUtils::readToken (fp, value);
		oneData.LevelId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.LevelTargetId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Arg1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Arg2 = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetLevelCorrespondingData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetLevelCorresponding::initLink ()
{
	return (0);
}

void SheetLevelCorresponding::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetLevelCorresponding" << "[" << i << "] :: data." << "LevelId" << " = " << data[i].LevelId << endl;
		cout << "SheetLevelCorresponding" << "[" << i << "] :: data." << "LevelTargetId" << " = " << data[i].LevelTargetId << endl;
		cout << "SheetLevelCorresponding" << "[" << i << "] :: data." << "Arg1" << " = " << data[i].Arg1 << endl;
		cout << "SheetLevelCorresponding" << "[" << i << "] :: data." << "Arg2" << " = " << data[i].Arg2 << endl;
	}
}
SheetHiddenLevelMonsterData::SheetHiddenLevelMonsterData ()
{
	Type = 0;
	Level = 0;
	RoleId = 0;
}

SheetHiddenLevelMonsterData* SheetHiddenLevelMonster::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetHiddenLevelMonsterData*> SheetHiddenLevelMonster::getAll ()
{
	vector<SheetHiddenLevelMonsterData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetHiddenLevelMonster::init ()
{
	FILE *fp;
	fp = fopen ("./HiddenLevelMonster.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "HiddenLevelMonster.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "HiddenLevelMonster.txt";
	vector<SheetHiddenLevelMonsterData> d;
	while (1) {
		SheetHiddenLevelMonsterData oneData;
		SheetUtils::readToken (fp, value);
		oneData.Type = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Level = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.RoleId = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetHiddenLevelMonsterData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetHiddenLevelMonster::initLink ()
{
	return (0);
}

void SheetHiddenLevelMonster::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetHiddenLevelMonster" << "[" << i << "] :: data." << "Type" << " = " << data[i].Type << endl;
		cout << "SheetHiddenLevelMonster" << "[" << i << "] :: data." << "Level" << " = " << data[i].Level << endl;
		cout << "SheetHiddenLevelMonster" << "[" << i << "] :: data." << "RoleId" << " = " << data[i].RoleId << endl;
	}
}
SheetHiddenLevelShapeData::SheetHiddenLevelShapeData ()
{
	DungeonId = 0;
	Type = 0;
	Name = "";
	Shape = 0;
}

SheetHiddenLevelShapeData* SheetHiddenLevelShape::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetHiddenLevelShapeData*> SheetHiddenLevelShape::getAll ()
{
	vector<SheetHiddenLevelShapeData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetHiddenLevelShape::init ()
{
	FILE *fp;
	fp = fopen ("./HiddenLevelShape.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "HiddenLevelShape.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "HiddenLevelShape.txt";
	vector<SheetHiddenLevelShapeData> d;
	while (1) {
		SheetHiddenLevelShapeData oneData;
		SheetUtils::readToken (fp, value);
		oneData.DungeonId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Type = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name = value;
		SheetUtils::readToken (fp, value);
		oneData.Shape = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetHiddenLevelShapeData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetHiddenLevelShape::initLink ()
{
	return (0);
}

void SheetHiddenLevelShape::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetHiddenLevelShape" << "[" << i << "] :: data." << "DungeonId" << " = " << data[i].DungeonId << endl;
		cout << "SheetHiddenLevelShape" << "[" << i << "] :: data." << "Type" << " = " << data[i].Type << endl;
		cout << "SheetHiddenLevelShape" << "[" << i << "] :: data." << "Name" << " = " << data[i].Name << endl;
		cout << "SheetHiddenLevelShape" << "[" << i << "] :: data." << "Shape" << " = " << data[i].Shape << endl;
	}
}
SheetHiddenLevelScoreData::SheetHiddenLevelScoreData ()
{
	RequireScore = 0;
	MountFeed = 0;
	GemItem = 0;
	RoleItem = 0;
	MoneyMul = 0;
	MoneyMul2 = 0;
	Badge = 0;
}

SheetHiddenLevelScoreData* SheetHiddenLevelScore::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetHiddenLevelScoreData*> SheetHiddenLevelScore::getAll ()
{
	vector<SheetHiddenLevelScoreData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetHiddenLevelScore::init ()
{
	FILE *fp;
	fp = fopen ("./HiddenLevelScore.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "HiddenLevelScore.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "HiddenLevelScore.txt";
	vector<SheetHiddenLevelScoreData> d;
	while (1) {
		SheetHiddenLevelScoreData oneData;
		SheetUtils::readToken (fp, value);
		oneData.RequireScore = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MountFeed = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.GemItem = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.RoleItem = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MoneyMul = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MoneyMul2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Badge = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetHiddenLevelScoreData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetHiddenLevelScore::initLink ()
{
	return (0);
}

void SheetHiddenLevelScore::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetHiddenLevelScore" << "[" << i << "] :: data." << "RequireScore" << " = " << data[i].RequireScore << endl;
		cout << "SheetHiddenLevelScore" << "[" << i << "] :: data." << "MountFeed" << " = " << data[i].MountFeed << endl;
		cout << "SheetHiddenLevelScore" << "[" << i << "] :: data." << "GemItem" << " = " << data[i].GemItem << endl;
		cout << "SheetHiddenLevelScore" << "[" << i << "] :: data." << "RoleItem" << " = " << data[i].RoleItem << endl;
		cout << "SheetHiddenLevelScore" << "[" << i << "] :: data." << "MoneyMul" << " = " << data[i].MoneyMul << endl;
		cout << "SheetHiddenLevelScore" << "[" << i << "] :: data." << "MoneyMul2" << " = " << data[i].MoneyMul2 << endl;
		cout << "SheetHiddenLevelScore" << "[" << i << "] :: data." << "Badge" << " = " << data[i].Badge << endl;
	}
}
SheetTalentOpenData::SheetTalentOpenData ()
{
	TalentId = 0;
	OpenLevel = 0;
	OpenPrice = 0;
	ResetPrice = 0;
	ItemPrice = 0;
}

SheetTalentOpenData* SheetTalentOpen::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetTalentOpenData*> SheetTalentOpen::getAll ()
{
	vector<SheetTalentOpenData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetTalentOpen::init ()
{
	FILE *fp;
	fp = fopen ("./TalentOpen.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "TalentOpen.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "TalentOpen.txt";
	vector<SheetTalentOpenData> d;
	while (1) {
		SheetTalentOpenData oneData;
		SheetUtils::readToken (fp, value);
		oneData.TalentId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.OpenLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.OpenPrice = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResetPrice = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ItemPrice = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetTalentOpenData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetTalentOpen::initLink ()
{
	return (0);
}

void SheetTalentOpen::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetTalentOpen" << "[" << i << "] :: data." << "TalentId" << " = " << data[i].TalentId << endl;
		cout << "SheetTalentOpen" << "[" << i << "] :: data." << "OpenLevel" << " = " << data[i].OpenLevel << endl;
		cout << "SheetTalentOpen" << "[" << i << "] :: data." << "OpenPrice" << " = " << data[i].OpenPrice << endl;
		cout << "SheetTalentOpen" << "[" << i << "] :: data." << "ResetPrice" << " = " << data[i].ResetPrice << endl;
		cout << "SheetTalentOpen" << "[" << i << "] :: data." << "ItemPrice" << " = " << data[i].ItemPrice << endl;
	}
}
SheetTalentNameData::SheetTalentNameData ()
{
	TalentId = 0;
	ClassId = 0;
	TalentName = "";
}

SheetTalentNameData* SheetTalentName::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetTalentNameData*> SheetTalentName::getAll ()
{
	vector<SheetTalentNameData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetTalentName::init ()
{
	FILE *fp;
	fp = fopen ("./TalentName.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "TalentName.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "TalentName.txt";
	vector<SheetTalentNameData> d;
	while (1) {
		SheetTalentNameData oneData;
		SheetUtils::readToken (fp, value);
		oneData.TalentId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ClassId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.TalentName = value;
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetTalentNameData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetTalentName::initLink ()
{
	return (0);
}

void SheetTalentName::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetTalentName" << "[" << i << "] :: data." << "TalentId" << " = " << data[i].TalentId << endl;
		cout << "SheetTalentName" << "[" << i << "] :: data." << "ClassId" << " = " << data[i].ClassId << endl;
		cout << "SheetTalentName" << "[" << i << "] :: data." << "TalentName" << " = " << data[i].TalentName << endl;
	}
}
SheetTalentPropsData::SheetTalentPropsData ()
{
	ClassId = 0;
	PropId = 0;
	MinQ1 = 0;
	MaxQ1 = 0;
	MinQ2 = 0;
	MaxQ2 = 0;
	MinQ3 = 0;
	MaxQ3 = 0;
	MaxVal = 0;
}

SheetTalentPropsData* SheetTalentProps::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetTalentPropsData*> SheetTalentProps::getAll ()
{
	vector<SheetTalentPropsData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetTalentProps::init ()
{
	FILE *fp;
	fp = fopen ("./TalentProps.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "TalentProps.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "TalentProps.txt";
	vector<SheetTalentPropsData> d;
	while (1) {
		SheetTalentPropsData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ClassId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PropId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MinQ1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MaxQ1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MinQ2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MaxQ2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MinQ3 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MaxQ3 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MaxVal = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetTalentPropsData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetTalentProps::initLink ()
{
	return (0);
}

void SheetTalentProps::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetTalentProps" << "[" << i << "] :: data." << "ClassId" << " = " << data[i].ClassId << endl;
		cout << "SheetTalentProps" << "[" << i << "] :: data." << "PropId" << " = " << data[i].PropId << endl;
		cout << "SheetTalentProps" << "[" << i << "] :: data." << "MinQ1" << " = " << data[i].MinQ1 << endl;
		cout << "SheetTalentProps" << "[" << i << "] :: data." << "MaxQ1" << " = " << data[i].MaxQ1 << endl;
		cout << "SheetTalentProps" << "[" << i << "] :: data." << "MinQ2" << " = " << data[i].MinQ2 << endl;
		cout << "SheetTalentProps" << "[" << i << "] :: data." << "MaxQ2" << " = " << data[i].MaxQ2 << endl;
		cout << "SheetTalentProps" << "[" << i << "] :: data." << "MinQ3" << " = " << data[i].MinQ3 << endl;
		cout << "SheetTalentProps" << "[" << i << "] :: data." << "MaxQ3" << " = " << data[i].MaxQ3 << endl;
		cout << "SheetTalentProps" << "[" << i << "] :: data." << "MaxVal" << " = " << data[i].MaxVal << endl;
	}
}
SheetMonsterDropData::SheetMonsterDropData ()
{
	DropId = 0;
	ResType = 0;
	ResId = 0;
	ResNum = 0;
	Stacks = 0;
}

SheetMonsterDropData* SheetMonsterDrop::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetMonsterDropData*> SheetMonsterDrop::getAll ()
{
	vector<SheetMonsterDropData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetMonsterDrop::init ()
{
	FILE *fp;
	fp = fopen ("./MonsterDrop.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "MonsterDrop.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "MonsterDrop.txt";
	vector<SheetMonsterDropData> d;
	while (1) {
		SheetMonsterDropData oneData;
		SheetUtils::readToken (fp, value);
		oneData.DropId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResNum = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Stacks = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetMonsterDropData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetMonsterDrop::initLink ()
{
	return (0);
}

void SheetMonsterDrop::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetMonsterDrop" << "[" << i << "] :: data." << "DropId" << " = " << data[i].DropId << endl;
		cout << "SheetMonsterDrop" << "[" << i << "] :: data." << "ResType" << " = " << data[i].ResType << endl;
		cout << "SheetMonsterDrop" << "[" << i << "] :: data." << "ResId" << " = " << data[i].ResId << endl;
		cout << "SheetMonsterDrop" << "[" << i << "] :: data." << "ResNum" << " = " << data[i].ResNum << endl;
		cout << "SheetMonsterDrop" << "[" << i << "] :: data." << "Stacks" << " = " << data[i].Stacks << endl;
	}
}
SheetDropResourceTypeData::SheetDropResourceTypeData ()
{
	ID = 0;
	MonsterCategory1 = 0;
	MonsterCategory2 = 0;
	MonsterCategory3 = 0;
}

SheetDropResourceTypeData* SheetDropResourceType::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetDropResourceTypeData*> SheetDropResourceType::getAll ()
{
	vector<SheetDropResourceTypeData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetDropResourceType::init ()
{
	FILE *fp;
	fp = fopen ("./DropResourceType.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "DropResourceType.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "DropResourceType.txt";
	vector<SheetDropResourceTypeData> d;
	while (1) {
		SheetDropResourceTypeData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MonsterCategory1 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MonsterCategory2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MonsterCategory3 = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetDropResourceTypeData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetDropResourceType::initLink ()
{
	return (0);
}

void SheetDropResourceType::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetDropResourceType" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetDropResourceType" << "[" << i << "] :: data." << "MonsterCategory1" << " = " << data[i].MonsterCategory1 << endl;
		cout << "SheetDropResourceType" << "[" << i << "] :: data." << "MonsterCategory2" << " = " << data[i].MonsterCategory2 << endl;
		cout << "SheetDropResourceType" << "[" << i << "] :: data." << "MonsterCategory3" << " = " << data[i].MonsterCategory3 << endl;
	}
}
SheetEnchantSlotData::SheetEnchantSlotData ()
{
	EquipmentSlot = 0;
	ItemId = 0;
	PropId = 0;
}

SheetEnchantSlotData* SheetEnchantSlot::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetEnchantSlotData*> SheetEnchantSlot::getAll ()
{
	vector<SheetEnchantSlotData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetEnchantSlot::init ()
{
	FILE *fp;
	fp = fopen ("./EnchantSlot.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "EnchantSlot.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "EnchantSlot.txt";
	vector<SheetEnchantSlotData> d;
	while (1) {
		SheetEnchantSlotData oneData;
		SheetUtils::readToken (fp, value);
		oneData.EquipmentSlot = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ItemId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.PropId = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetEnchantSlotData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetEnchantSlot::initLink ()
{
	return (0);
}

void SheetEnchantSlot::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetEnchantSlot" << "[" << i << "] :: data." << "EquipmentSlot" << " = " << data[i].EquipmentSlot << endl;
		cout << "SheetEnchantSlot" << "[" << i << "] :: data." << "ItemId" << " = " << data[i].ItemId << endl;
		cout << "SheetEnchantSlot" << "[" << i << "] :: data." << "PropId" << " = " << data[i].PropId << endl;
	}
}
SheetEnchantMaxPropData::SheetEnchantMaxPropData ()
{
	EquipmentLevel = 0;
	MaxProp = 0;
	Blue = 0;
	Purple = 0;
	Orange = 0;
}

SheetEnchantMaxPropData* SheetEnchantMaxProp::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetEnchantMaxPropData*> SheetEnchantMaxProp::getAll ()
{
	vector<SheetEnchantMaxPropData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetEnchantMaxProp::init ()
{
	FILE *fp;
	fp = fopen ("./EnchantMaxProp.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "EnchantMaxProp.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "EnchantMaxProp.txt";
	vector<SheetEnchantMaxPropData> d;
	while (1) {
		SheetEnchantMaxPropData oneData;
		SheetUtils::readToken (fp, value);
		oneData.EquipmentLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MaxProp = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Blue = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Purple = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Orange = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetEnchantMaxPropData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetEnchantMaxProp::initLink ()
{
	return (0);
}

void SheetEnchantMaxProp::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetEnchantMaxProp" << "[" << i << "] :: data." << "EquipmentLevel" << " = " << data[i].EquipmentLevel << endl;
		cout << "SheetEnchantMaxProp" << "[" << i << "] :: data." << "MaxProp" << " = " << data[i].MaxProp << endl;
		cout << "SheetEnchantMaxProp" << "[" << i << "] :: data." << "Blue" << " = " << data[i].Blue << endl;
		cout << "SheetEnchantMaxProp" << "[" << i << "] :: data." << "Purple" << " = " << data[i].Purple << endl;
		cout << "SheetEnchantMaxProp" << "[" << i << "] :: data." << "Orange" << " = " << data[i].Orange << endl;
	}
}
SheetEnchantProData::SheetEnchantProData ()
{
	EquipmentLevel = 0;
	Times = 0;
	SuccPro = 0;
}

SheetEnchantProData* SheetEnchantPro::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetEnchantProData*> SheetEnchantPro::getAll ()
{
	vector<SheetEnchantProData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetEnchantPro::init ()
{
	FILE *fp;
	fp = fopen ("./EnchantPro.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "EnchantPro.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "EnchantPro.txt";
	vector<SheetEnchantProData> d;
	while (1) {
		SheetEnchantProData oneData;
		SheetUtils::readToken (fp, value);
		oneData.EquipmentLevel = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Times = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.SuccPro = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetEnchantProData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetEnchantPro::initLink ()
{
	return (0);
}

void SheetEnchantPro::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetEnchantPro" << "[" << i << "] :: data." << "EquipmentLevel" << " = " << data[i].EquipmentLevel << endl;
		cout << "SheetEnchantPro" << "[" << i << "] :: data." << "Times" << " = " << data[i].Times << endl;
		cout << "SheetEnchantPro" << "[" << i << "] :: data." << "SuccPro" << " = " << data[i].SuccPro << endl;
	}
}
SheetOnlineRewardData::SheetOnlineRewardData ()
{
	ID = 0;
	Interval = 0;
	ResType = 0;
	ResId = 0;
	ResNum = 0;
}

SheetOnlineRewardData* SheetOnlineReward::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetOnlineRewardData*> SheetOnlineReward::getAll ()
{
	vector<SheetOnlineRewardData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetOnlineReward::init ()
{
	FILE *fp;
	fp = fopen ("./OnlineReward.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "OnlineReward.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "OnlineReward.txt";
	vector<SheetOnlineRewardData> d;
	while (1) {
		SheetOnlineRewardData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Interval = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResType = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ResNum = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetOnlineRewardData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetOnlineReward::initLink ()
{
	return (0);
}

void SheetOnlineReward::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetOnlineReward" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetOnlineReward" << "[" << i << "] :: data." << "Interval" << " = " << data[i].Interval << endl;
		cout << "SheetOnlineReward" << "[" << i << "] :: data." << "ResType" << " = " << data[i].ResType << endl;
		cout << "SheetOnlineReward" << "[" << i << "] :: data." << "ResId" << " = " << data[i].ResId << endl;
		cout << "SheetOnlineReward" << "[" << i << "] :: data." << "ResNum" << " = " << data[i].ResNum << endl;
	}
}
SheetLoginRewardData::SheetLoginRewardData ()
{
	ID = 0;
	Gold = 0;
	Money = 0;
	Power = 0;
	RoleId = 0;
	ItemId = 0;
	ItemNum = 0;
}

SheetLoginRewardData* SheetLoginReward::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetLoginRewardData*> SheetLoginReward::getAll ()
{
	vector<SheetLoginRewardData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetLoginReward::init ()
{
	FILE *fp;
	fp = fopen ("./LoginReward.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "LoginReward.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "LoginReward.txt";
	vector<SheetLoginRewardData> d;
	while (1) {
		SheetLoginRewardData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Gold = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Money = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Power = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.RoleId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ItemId = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.ItemNum = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetLoginRewardData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetLoginReward::initLink ()
{
	return (0);
}

void SheetLoginReward::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetLoginReward" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetLoginReward" << "[" << i << "] :: data." << "Gold" << " = " << data[i].Gold << endl;
		cout << "SheetLoginReward" << "[" << i << "] :: data." << "Money" << " = " << data[i].Money << endl;
		cout << "SheetLoginReward" << "[" << i << "] :: data." << "Power" << " = " << data[i].Power << endl;
		cout << "SheetLoginReward" << "[" << i << "] :: data." << "RoleId" << " = " << data[i].RoleId << endl;
		cout << "SheetLoginReward" << "[" << i << "] :: data." << "ItemId" << " = " << data[i].ItemId << endl;
		cout << "SheetLoginReward" << "[" << i << "] :: data." << "ItemNum" << " = " << data[i].ItemNum << endl;
	}
}
int SheetUtils::initSheets ()
{
	shPropType = new SheetPropType;
	if (shPropType->init() != 0) return (-1);
	if (shPropType->initLink() != 0) return (-1);
	shResourceType = new SheetResourceType;
	if (shResourceType->init() != 0) return (-1);
	if (shResourceType->initLink() != 0) return (-1);
	shRole = new SheetRole;
	if (shRole->init() != 0) return (-1);
	if (shRole->initLink() != 0) return (-1);
	shPromptSpell = new SheetPromptSpell;
	if (shPromptSpell->init() != 0) return (-1);
	if (shPromptSpell->initLink() != 0) return (-1);
	shComposeRole = new SheetComposeRole;
	if (shComposeRole->init() != 0) return (-1);
	if (shComposeRole->initLink() != 0) return (-1);
	shClass = new SheetClass;
	if (shClass->init() != 0) return (-1);
	if (shClass->initLink() != 0) return (-1);
	shChangeClass = new SheetChangeClass;
	if (shChangeClass->init() != 0) return (-1);
	if (shChangeClass->initLink() != 0) return (-1);
	shChangeClassProp = new SheetChangeClassProp;
	if (shChangeClassProp->init() != 0) return (-1);
	if (shChangeClassProp->initLink() != 0) return (-1);
	shClassTitle = new SheetClassTitle;
	if (shClassTitle->init() != 0) return (-1);
	if (shClassTitle->initLink() != 0) return (-1);
	shComposeShape = new SheetComposeShape;
	if (shComposeShape->init() != 0) return (-1);
	if (shComposeShape->initLink() != 0) return (-1);
	shScene = new SheetScene;
	if (shScene->init() != 0) return (-1);
	if (shScene->initLink() != 0) return (-1);
	shMap = new SheetMap;
	if (shMap->init() != 0) return (-1);
	if (shMap->initLink() != 0) return (-1);
	shNPC = new SheetNPC;
	if (shNPC->init() != 0) return (-1);
	if (shNPC->initLink() != 0) return (-1);
	shSpell = new SheetSpell;
	if (shSpell->init() != 0) return (-1);
	if (shSpell->initLink() != 0) return (-1);
	shBuff = new SheetBuff;
	if (shBuff->init() != 0) return (-1);
	if (shBuff->initLink() != 0) return (-1);
	shSummon = new SheetSummon;
	if (shSummon->init() != 0) return (-1);
	if (shSummon->initLink() != 0) return (-1);
	shQuest = new SheetQuest;
	if (shQuest->init() != 0) return (-1);
	if (shQuest->initLink() != 0) return (-1);
	shEffects = new SheetEffects;
	if (shEffects->init() != 0) return (-1);
	if (shEffects->initLink() != 0) return (-1);
	shDungeon = new SheetDungeon;
	if (shDungeon->init() != 0) return (-1);
	if (shDungeon->initLink() != 0) return (-1);
	shDungeonLevel = new SheetDungeonLevel;
	if (shDungeonLevel->init() != 0) return (-1);
	if (shDungeonLevel->initLink() != 0) return (-1);
	shCombatWave = new SheetCombatWave;
	if (shCombatWave->init() != 0) return (-1);
	if (shCombatWave->initLink() != 0) return (-1);
	shCombatMonster = new SheetCombatMonster;
	if (shCombatMonster->init() != 0) return (-1);
	if (shCombatMonster->initLink() != 0) return (-1);
	shDramaCombatRole = new SheetDramaCombatRole;
	if (shDramaCombatRole->init() != 0) return (-1);
	if (shDramaCombatRole->initLink() != 0) return (-1);
	shRestrain = new SheetRestrain;
	if (shRestrain->init() != 0) return (-1);
	if (shRestrain->initLink() != 0) return (-1);
	shItem = new SheetItem;
	if (shItem->init() != 0) return (-1);
	if (shItem->initLink() != 0) return (-1);
	shEquipmentProp = new SheetEquipmentProp;
	if (shEquipmentProp->init() != 0) return (-1);
	if (shEquipmentProp->initLink() != 0) return (-1);
	shGem = new SheetGem;
	if (shGem->init() != 0) return (-1);
	if (shGem->initLink() != 0) return (-1);
	shGemInsertRule = new SheetGemInsertRule;
	if (shGemInsertRule->init() != 0) return (-1);
	if (shGemInsertRule->initLink() != 0) return (-1);
	shRoleLevel = new SheetRoleLevel;
	if (shRoleLevel->init() != 0) return (-1);
	if (shRoleLevel->initLink() != 0) return (-1);
	shPartnerLevelUp = new SheetPartnerLevelUp;
	if (shPartnerLevelUp->init() != 0) return (-1);
	if (shPartnerLevelUp->initLink() != 0) return (-1);
	shArenaCombatTarget = new SheetArenaCombatTarget;
	if (shArenaCombatTarget->init() != 0) return (-1);
	if (shArenaCombatTarget->initLink() != 0) return (-1);
	shArenaRankReward = new SheetArenaRankReward;
	if (shArenaRankReward->init() != 0) return (-1);
	if (shArenaRankReward->initLink() != 0) return (-1);
	shWorldBossRankReward = new SheetWorldBossRankReward;
	if (shWorldBossRankReward->init() != 0) return (-1);
	if (shWorldBossRankReward->initLink() != 0) return (-1);
	shVipLevel = new SheetVipLevel;
	if (shVipLevel->init() != 0) return (-1);
	if (shVipLevel->initLink() != 0) return (-1);
	shReward = new SheetReward;
	if (shReward->init() != 0) return (-1);
	if (shReward->initLink() != 0) return (-1);
	shLotPartner = new SheetLotPartner;
	if (shLotPartner->init() != 0) return (-1);
	if (shLotPartner->initLink() != 0) return (-1);
	shLotGem = new SheetLotGem;
	if (shLotGem->init() != 0) return (-1);
	if (shLotGem->initLink() != 0) return (-1);
	shShop = new SheetShop;
	if (shShop->init() != 0) return (-1);
	if (shShop->initLink() != 0) return (-1);
	shMount = new SheetMount;
	if (shMount->init() != 0) return (-1);
	if (shMount->initLink() != 0) return (-1);
	shMountLevelUp = new SheetMountLevelUp;
	if (shMountLevelUp->init() != 0) return (-1);
	if (shMountLevelUp->initLink() != 0) return (-1);
	shLevelDrop = new SheetLevelDrop;
	if (shLevelDrop->init() != 0) return (-1);
	if (shLevelDrop->initLink() != 0) return (-1);
	shDrama = new SheetDrama;
	if (shDrama->init() != 0) return (-1);
	if (shDrama->initLink() != 0) return (-1);
	shOpenAction = new SheetOpenAction;
	if (shOpenAction->init() != 0) return (-1);
	if (shOpenAction->initLink() != 0) return (-1);
	shLevelTarget = new SheetLevelTarget;
	if (shLevelTarget->init() != 0) return (-1);
	if (shLevelTarget->initLink() != 0) return (-1);
	shLevelCorresponding = new SheetLevelCorresponding;
	if (shLevelCorresponding->init() != 0) return (-1);
	if (shLevelCorresponding->initLink() != 0) return (-1);
	shHiddenLevelMonster = new SheetHiddenLevelMonster;
	if (shHiddenLevelMonster->init() != 0) return (-1);
	if (shHiddenLevelMonster->initLink() != 0) return (-1);
	shHiddenLevelShape = new SheetHiddenLevelShape;
	if (shHiddenLevelShape->init() != 0) return (-1);
	if (shHiddenLevelShape->initLink() != 0) return (-1);
	shHiddenLevelScore = new SheetHiddenLevelScore;
	if (shHiddenLevelScore->init() != 0) return (-1);
	if (shHiddenLevelScore->initLink() != 0) return (-1);
	shTalentOpen = new SheetTalentOpen;
	if (shTalentOpen->init() != 0) return (-1);
	if (shTalentOpen->initLink() != 0) return (-1);
	shTalentName = new SheetTalentName;
	if (shTalentName->init() != 0) return (-1);
	if (shTalentName->initLink() != 0) return (-1);
	shTalentProps = new SheetTalentProps;
	if (shTalentProps->init() != 0) return (-1);
	if (shTalentProps->initLink() != 0) return (-1);
	shMonsterDrop = new SheetMonsterDrop;
	if (shMonsterDrop->init() != 0) return (-1);
	if (shMonsterDrop->initLink() != 0) return (-1);
	shDropResourceType = new SheetDropResourceType;
	if (shDropResourceType->init() != 0) return (-1);
	if (shDropResourceType->initLink() != 0) return (-1);
	shEnchantSlot = new SheetEnchantSlot;
	if (shEnchantSlot->init() != 0) return (-1);
	if (shEnchantSlot->initLink() != 0) return (-1);
	shEnchantMaxProp = new SheetEnchantMaxProp;
	if (shEnchantMaxProp->init() != 0) return (-1);
	if (shEnchantMaxProp->initLink() != 0) return (-1);
	shEnchantPro = new SheetEnchantPro;
	if (shEnchantPro->init() != 0) return (-1);
	if (shEnchantPro->initLink() != 0) return (-1);
	shOnlineReward = new SheetOnlineReward;
	if (shOnlineReward->init() != 0) return (-1);
	if (shOnlineReward->initLink() != 0) return (-1);
	shLoginReward = new SheetLoginReward;
	if (shLoginReward->init() != 0) return (-1);
	if (shLoginReward->initLink() != 0) return (-1);
	return (0);
}
