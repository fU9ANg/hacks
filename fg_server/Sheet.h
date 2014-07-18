
#ifndef __SHEET_H__
#define __SHEET_H__

#include "SheetBase.h"

class SheetPropTypeData : public SheetBaseData
{
public:
	int ID;	//ID
	int Type;	//类型
	string Name;	//名称
	SheetPropTypeData ();
};

class SheetPropType : public SheetBase
{
private:
	SheetPropTypeData *data;
public:
	vector<SheetPropTypeData*> getAll ();
	SheetPropTypeData* getRow (int n);
	bool forEach (SheetPropTypeData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetPropType* shPropType;
class SheetResourceTypeData : public SheetBaseData
{
public:
	int ID;	//ID
	string Name;	//名称
	SheetResourceTypeData ();
};

class SheetResourceType : public SheetBase
{
private:
	SheetResourceTypeData *data;
public:
	vector<SheetResourceTypeData*> getAll ();
	SheetResourceTypeData* getRow (int n);
	bool forEach (SheetResourceTypeData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetResourceType* shResourceType;
class SheetRoleData : public SheetBaseData
{
public:
	int ID;	//ID
	string Name;	//名称
	int Shape;	//外观
	int Scale;	//缩放
	int Quality;	//品质
	int Class;	//职业
	int RoleType;	//角色类型
	int AttackRange;	//攻击范围
	int MonsterType;	//怪物类型
	int MonsterCategory;	//怪物分类
	int BornTime;	//出生时间
	int Level;	//等级
	int Spell1;	//技能1
	int Spell2;	//技能2
	int Spell3;	//技能3
	int Spell4;	//技能4
	int Spell5;	//技能5
	int Spell6;	//技能6
	int triggerWay;	//触发方式
	int triggerType;	//触发类型
	int triggerArg1;	//触发参数1
	int Price;	//价格
	int Aptitude;	//资质
	int MoveSpeed;	//移动速度
	int MaxHp;	//生命上限
	int MaxMp;	//法力上限
	int PhysicalAttack;	//物理攻击
	int PhysicalDefense;	//物理防御
	int MagicAttack;	//魔法攻击
	int MagicDefense;	//魔法防御
	int Cirt;	//暴击
	int Penetration;	//穿透
	int Luck;	//幸运
	int Resist;	//韧性
	int Hit;	//命中
	int Miss;	//闪避
	int Threat;	//仇恨
	string SoundDie;	//死亡音效
	string Desc;	//描述
	SheetRoleData ();
};

class SheetRole : public SheetBase
{
private:
	SheetRoleData *data;
public:
	vector<SheetRoleData*> getAll ();
	SheetRoleData* getRow (int n);
	bool forEach (SheetRoleData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetRole* shRole;
class SheetPromptSpellData : public SheetBaseData
{
public:
	int ID;	//ID
	int Type;	//类型
	int AttackSpell;	//提示技能ID
	int DefenseSpell;	//防御技能ID
	SheetPromptSpellData ();
};

class SheetPromptSpell : public SheetBase
{
private:
	SheetPromptSpellData *data;
public:
	vector<SheetPromptSpellData*> getAll ();
	SheetPromptSpellData* getRow (int n);
	bool forEach (SheetPromptSpellData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetPromptSpell* shPromptSpell;
class SheetComposeRoleData : public SheetBaseData
{
public:
	int ComposeLevel;	//合成等级
	int RequireLevel;	//需求等级
	int CostMoney;	//消耗金币
	int AddAptitude;	//增加资质
	SheetComposeRoleData ();
};

class SheetComposeRole : public SheetBase
{
private:
	SheetComposeRoleData *data;
public:
	vector<SheetComposeRoleData*> getAll ();
	SheetComposeRoleData* getRow (int n);
	bool forEach (SheetComposeRoleData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetComposeRole* shComposeRole;
class SheetClassData : public SheetBaseData
{
public:
	int ID;	//ID
	int Type;	//类型
	int IsTalent;	//是否天赋
	string ClassName;	//名称
	string Speciality;	//特长
	int Shape;	//外观
	int AttackType;	//攻击类型
	int StaToHp;	//生命值
	int StrToPhyAtk;	//物理攻击
	int StrToPhyDef;	//物理防御
	int IntToMgcAtk;	//魔法攻击
	int IntToMgcDef;	//魔法防御
	string Title;	//标题
	string Desc;	//描述
	int Spy1;	//特长属性1
	int Spy2;	//特长属性2
	int Spy3;	//特长属性3
	string RestrainDesc;	//克制描述
	SheetClassData ();
};

class SheetClass : public SheetBase
{
private:
	SheetClassData *data;
public:
	vector<SheetClassData*> getAll ();
	SheetClassData* getRow (int n);
	bool forEach (SheetClassData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetClass* shClass;
class SheetChangeClassData : public SheetBaseData
{
public:
	int ClassLevel;	//转职等级
	int RoleQuality;	//角色品质
	int RequireLevel;	//需求等级
	int CostMoney;	//消耗铜钱
	int MaterialId;	//材料ID
	int MaterialNum;	//材料数量
	SheetChangeClassData ();
};

class SheetChangeClass : public SheetBase
{
private:
	SheetChangeClassData *data;
public:
	vector<SheetChangeClassData*> getAll ();
	SheetChangeClassData* getRow (int n);
	bool forEach (SheetChangeClassData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetChangeClass* shChangeClass;
class SheetChangeClassPropData : public SheetBaseData
{
public:
	int RoleQuality;	//角色品质
	int ClassLevel;	//转职等级
	int ComposeLevel;	//合成等级
	int Aptitude;	//资质
	SheetChangeClassPropData ();
};

class SheetChangeClassProp : public SheetBase
{
private:
	SheetChangeClassPropData *data;
public:
	vector<SheetChangeClassPropData*> getAll ();
	SheetChangeClassPropData* getRow (int n);
	bool forEach (SheetChangeClassPropData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetChangeClassProp* shChangeClassProp;
class SheetClassTitleData : public SheetBaseData
{
public:
	int ClassId;	//职业
	int ClassLevel;	//转职等级
	string Title;	//称号
	SheetClassTitleData ();
};

class SheetClassTitle : public SheetBase
{
private:
	SheetClassTitleData *data;
public:
	vector<SheetClassTitleData*> getAll ();
	SheetClassTitleData* getRow (int n);
	bool forEach (SheetClassTitleData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetClassTitle* shClassTitle;
class SheetComposeShapeData : public SheetBaseData
{
public:
	int RoleId;	//角色ID
	int ComposeLevel;	//合成等级
	int Shape;	//外观
	SheetComposeShapeData ();
};

class SheetComposeShape : public SheetBase
{
private:
	SheetComposeShapeData *data;
public:
	vector<SheetComposeShapeData*> getAll ();
	SheetComposeShapeData* getRow (int n);
	bool forEach (SheetComposeShapeData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetComposeShape* shComposeShape;
class SheetSceneData : public SheetBaseData
{
public:
	int ID;	//ID
	string Name;	//名称
	int IsCombat;	//可否战斗
	int SceneType;	//场景类型
	int MapId;	//地图
	int Instancing;	//副本
	int EnterPosX;	//进入位置x
	int EnterPosY;	//进入位置y
	SheetSceneData ();
};

class SheetScene : public SheetBase
{
private:
	SheetSceneData *data;
public:
	vector<SheetSceneData*> getAll ();
	SheetSceneData* getRow (int n);
	bool forEach (SheetSceneData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetScene* shScene;
class SheetMapData : public SheetBaseData
{
public:
	int ID;	//ID
	int Width;	//宽度
	int Height;	//高度
	SheetMapData ();
};

class SheetMap : public SheetBase
{
private:
	SheetMapData *data;
public:
	vector<SheetMapData*> getAll ();
	SheetMapData* getRow (int n);
	bool forEach (SheetMapData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetMap* shMap;
class SheetNPCData : public SheetBaseData
{
public:
	int ID;	//ID
	int Shape;	//外观
	int Type;	//类型
	int SceneId;	//场景ID
	int PosX;	//位置x
	int PosY;	//位置y
	string Name;	//名称
	string Desc;	//描述
	int ActionId;	//功能
	string ActionText;	//功能文字
	SheetNPCData ();
};

class SheetNPC : public SheetBase
{
private:
	SheetNPCData *data;
public:
	vector<SheetNPCData*> getAll ();
	SheetNPCData* getRow (int n);
	bool forEach (SheetNPCData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetNPC* shNPC;
class SheetSpellData : public SheetBaseData
{
public:
	int ID;	//ID
	string Name;	//名称
	int IsNormal;	//是否普技
	int SpellSlot;	//技能栏位
	int UseType;	//使用类型
	int DamageType;	//伤害类型
	int cdId;	//CD组
	int gcdId;	//GCD组
	int AIPriority;	//AI优先级
	int AICombatType;	//AI战斗
	int AICond;	//AI条件
	int AICondArg1;	//AI条件参1
	int AICondArg2;	//AI条件参2
	int AITarget;	//AI目标
	int AIDelay;	//AI延时
	int AICastInterval;	//AI施放间隔
	int ArenaCastDelay;	//竞技延时
	int castTime;	//施放时间
	int immuneBreak;	//免疫打断
	int castTarget;	//施放目标
	int costMana;	//消耗法力
	int useTime;	//使用次数
	int cdTime;	//冷却时间
	int triggerWay;	//触发方式
	int triggerPro;	//触发几率
	int triggerType;	//触发类型
	int triggerArg1;	//触发参数1
	int triggerArg2;	//触发参数2
	int selectTargetType;	//选择目标
	int selectTargetNum;	//选择数量
	int flySpeed;	//飞行速度
	int ShootTimes;	//发射次数
	int ShootInterval;	//发射间隔
	int effectTarget;	//作用目标
	int effectWay;	//作用方式
	int effectOrder;	//作用排序
	int effectNum;	//作用数量
	int effectArg1;	//作用参数1
	int effectArg2;	//作用参数2
	int DamageWay;	//伤害方式
	int DamageArg1;	//伤害参数1
	int damage;	//基础伤害
	int playerDamage;	//玩家伤害
	int bossDamage;	//Boss伤害
	int worldBossDamage;	//世界Boss伤害
	int eliteCombatDamage;	//精英本伤害
	int targetEffectId1;	//目标效果1
	int targetEffectPro1;	//目标几率1
	int targetEffectArg1_1;	//目标参数1_1
	int targetEffectArg1_2;	//目标参数1_2
	int targetEffectId2;	//目标效果2
	int targetEffectPro2;	//目标几率2
	int targetEffectArg2_1;	//目标参数2_1
	int targetEffectArg2_2;	//目标参数2_2
	int selfEffectId;	//自身效果
	int selfEffectPro;	//自身几率
	int selfEffectArg1;	//自身参数1
	int selfEffectArg2;	//自身参数2
	int Icon;	//图标
	string SoundCasting;	//施法音效
	string SoundCast;	//施放音效
	string SoundFly;	//飞行音效
	string SoundBeam;	//命中音效
	string spellEffect;	//技能特效
	int spellEffectPlace;	//播放位置
	string targetEffect;	//目标动画
	int IsPlayEffect;	//释放特效
	int castIcon;	//释放图标
	string desc;	//描述
	SheetSpellData ();
};

class SheetSpell : public SheetBase
{
private:
	SheetSpellData *data;
public:
	vector<SheetSpellData*> getAll ();
	SheetSpellData* getRow (int n);
	bool forEach (SheetSpellData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetSpell* shSpell;
class SheetBuffData : public SheetBaseData
{
public:
	int ID;	//ID
	int Type;	//类型
	int classId;	//分类Id
	int DispelLevel;	//驱散等级
	int groupId;	//组Id
	int groupLevel;	//组等级
	string Name;	//名称
	int damageType;	//伤害类型
	int Times;	//叠加层数
	int maxTimes;	//层数上限
	int overlayType;	//覆盖方式
	int durationTimes;	//维持次数
	int durationInterval;	//维持间隔
	int triggerWay;	//触发方式
	int triggerArg1;	//触发参数1
	int triggerPro;	//触发几率
	int triggerType;	//触发类型
	int effectId1;	//效果类型1
	int eftArg1_1;	//效果参数1_1
	int eftArg1_2;	//效果参数1_2
	int effectId2;	//效果类型2
	int eftArg2_1;	//效果参数2_1
	int eftArg2_2;	//效果参数2_2
	int effectId3;	//效果类型3
	int eftArg3_1;	//效果参数3_1
	int eftArg3_2;	//效果参数3_2
	int Icon;	//图标
	string effectOne;	//播放1次
	string effectSum;	//持续播放
	int Scale;	//缩放比例
	string desc;	//描述
	SheetBuffData ();
};

class SheetBuff : public SheetBase
{
private:
	SheetBuffData *data;
public:
	vector<SheetBuffData*> getAll ();
	SheetBuffData* getRow (int n);
	bool forEach (SheetBuffData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetBuff* shBuff;
class SheetSummonData : public SheetBaseData
{
public:
	int ID;	//ID
	int MonsterId;	//怪物Id
	int OffTrack;	//跑道偏移
	int OffPos;	//位置偏移
	int OffCombatPos;	//战位偏移
	SheetSummonData ();
};

class SheetSummon : public SheetBase
{
private:
	SheetSummonData *data;
public:
	vector<SheetSummonData*> getAll ();
	SheetSummonData* getRow (int n);
	bool forEach (SheetSummonData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetSummon* shSummon;
class SheetQuestData : public SheetBaseData
{
public:
	int ID;	//ID
	int OrderId;	//序号
	string Name;	//任务名称
	int RequireLevel;	//等级要求
	int PreQuestId;	//前置任务
	int AccepteNpcId;	//接取NPC
	int CompleteNpcId;	//完成NPC
	int DungeonLevelId;	//关卡ID
	int TargetType;	//目标类型
	int TargetId;	//目标参数
	int TargetNum;	//目标数量
	int RewardId;	//奖励Id
	string Desc;	//任务描述
	SheetQuestData ();
};

class SheetQuest : public SheetBase
{
private:
	SheetQuestData *data;
public:
	vector<SheetQuestData*> getAll ();
	SheetQuestData* getRow (int n);
	bool forEach (SheetQuestData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetQuest* shQuest;
class SheetEffectsData : public SheetBaseData
{
public:
	string ID;	//ID
	int Tier;	//层类型
	int HurtFrame;	//伤害帧
	SheetEffectsData ();
};

class SheetEffects : public SheetBase
{
private:
	SheetEffectsData *data;
public:
	vector<SheetEffectsData*> getAll ();
	SheetEffectsData* getRow (int n);
	bool forEach (SheetEffectsData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetEffects* shEffects;
class SheetDungeonData : public SheetBaseData
{
public:
	int ID;	//ID
	string Name;	//名称
	int SceneId;	//场景
	int RequireLevel;	//要求等级
	int PreDungeon;	//前置副本
	int MaterialLevel;	//转职材料等级
	SheetDungeonData ();
};

class SheetDungeon : public SheetBase
{
private:
	SheetDungeonData *data;
public:
	vector<SheetDungeonData*> getAll ();
	SheetDungeonData* getRow (int n);
	bool forEach (SheetDungeonData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetDungeon* shDungeon;
class SheetDungeonLevelData : public SheetBaseData
{
public:
	int ID;	//ID
	int Type;	//类型
	int DungeonId;	//副本
	string Name;	//名称
	int MinLevel;	//等级下限
	int MaxLevel;	//等级上限
	int PreLevel1;	//前置关卡1
	int PreLevel2;	//前置关卡2
	int AcceptedQuestId;	//接受任务
	int CompleteQuestId;	//完成任务
	int PlayerCamp;	//玩家阵营
	int BossHeadID;	//BOSS头像ID
	int CombatId;	//战斗ID
	int CombatDuration;	//战斗时间
	int RewardId;	//奖励ID
	int Next;	//下一关
	int TargetType;	//目标类型
	int TargetArg1;	//目标参数1
	int TargetArg2;	//目标参数2
	int PreDramaId;	//战前剧情
	int AfterDramaId;	//战后剧情
	int IsNextWave;	//可否下波
	int IsCanWin;	//是否立即胜利
	int IsCanEscrow;	//可否托管
	int IsShowProgress;	//显示进度
	int DropId;	//掉落ID
	int DropNum;	//掉落数量
	int DropCrit;	//掉落暴击
	int SuitLevel;	//掉落套装等级
	SheetDungeonLevelData ();
};

class SheetDungeonLevel : public SheetBase
{
private:
	SheetDungeonLevelData *data;
public:
	vector<SheetDungeonLevelData*> getAll ();
	SheetDungeonLevelData* getRow (int n);
	bool forEach (SheetDungeonLevelData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetDungeonLevel* shDungeonLevel;
class SheetCombatWaveData : public SheetBaseData
{
public:
	int CombatId;	//战斗
	int WaveId;	//波次
	int WaitTime;	//等待时间
	int IntervalTime;	//间隔时间
	SheetCombatWaveData ();
};

class SheetCombatWave : public SheetBase
{
private:
	SheetCombatWaveData *data;
public:
	vector<SheetCombatWaveData*> getAll ();
	SheetCombatWaveData* getRow (int n);
	bool forEach (SheetCombatWaveData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetCombatWave* shCombatWave;
class SheetCombatMonsterData : public SheetBaseData
{
public:
	int CombatId;	//战斗
	int WaveId;	//波次
	int Interval;	//间隔
	int Camp;	//阵营
	int MonsterId;	//怪物
	int AIType;	//AI类型
	int AIArg1;	//AI参数1
	int BornTrack;	//出生跑道
	int BornOffX;	//出生偏移
	int EventType;	//事件类型
	int EventTime;	//事件时间
	int EventArg1;	//事件参数1
	int DropType;	//掉落类型
	SheetCombatMonsterData ();
};

class SheetCombatMonster : public SheetBase
{
private:
	SheetCombatMonsterData *data;
public:
	vector<SheetCombatMonsterData*> getAll ();
	SheetCombatMonsterData* getRow (int n);
	bool forEach (SheetCombatMonsterData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetCombatMonster* shCombatMonster;
class SheetDramaCombatRoleData : public SheetBaseData
{
public:
	int CombatId;	//战斗ID
	int RoleId;	//角色ID
	int IsPlayer;	//是否玩家
	SheetDramaCombatRoleData ();
};

class SheetDramaCombatRole : public SheetBase
{
private:
	SheetDramaCombatRoleData *data;
public:
	vector<SheetDramaCombatRoleData*> getAll ();
	SheetDramaCombatRoleData* getRow (int n);
	bool forEach (SheetDramaCombatRoleData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetDramaCombatRole* shDramaCombatRole;
class SheetRestrainData : public SheetBaseData
{
public:
	int ID;	//精英本ID
	int ClassId1;	//职业1
	int ClassId2;	//职业2
	int ClassId3;	//职业3
	int SpellType;	//技能类型
	SheetRestrainData ();
};

class SheetRestrain : public SheetBase
{
private:
	SheetRestrainData *data;
public:
	vector<SheetRestrainData*> getAll ();
	SheetRestrainData* getRow (int n);
	bool forEach (SheetRestrainData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetRestrain* shRestrain;
class SheetItemData : public SheetBaseData
{
public:
	int ID;	//ID
	string Name;	//名称
	int Type;	//类型
	int TypeArg;	//类型参数
	int Level;	//等级
	int Quality;	//品质
	int Stacks;	//堆叠上限
	int Duration;	//维持时间
	int SellMoney;	//出售金钱
	int SellBadge;	//出售徽章
	int ComposeId;	//合成ID
	int UseEffect;	//使用效果
	int UseArg1;	//使用参数1
	int UseArg2;	//使用参数2
	int UseRemove;	//使用消失
	int Icon;	//图标
	int DropIcon;	//掉落图标
	string Desc;	//描述
	SheetItemData ();
};

class SheetItem : public SheetBase
{
private:
	SheetItemData *data;
public:
	vector<SheetItemData*> getAll ();
	SheetItemData* getRow (int n);
	bool forEach (SheetItemData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetItem* shItem;
class SheetEquipmentPropData : public SheetBaseData
{
public:
	int ItemId;	//物品ID
	int Type;	//类型
	int PropId;	//属性
	int Value;	//数值
	SheetEquipmentPropData ();
};

class SheetEquipmentProp : public SheetBase
{
private:
	SheetEquipmentPropData *data;
public:
	vector<SheetEquipmentPropData*> getAll ();
	SheetEquipmentPropData* getRow (int n);
	bool forEach (SheetEquipmentPropData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetEquipmentProp* shEquipmentProp;
class SheetGemData : public SheetBaseData
{
public:
	int ID;	//ID
	string Name;	//名称
	int Level;	//等级
	int Quality;	//品质
	int PropId;	//属性
	int Value;	//数值
	int Icon;	//图标
	string Desc;	//描述
	SheetGemData ();
};

class SheetGem : public SheetBase
{
private:
	SheetGemData *data;
public:
	vector<SheetGemData*> getAll ();
	SheetGemData* getRow (int n);
	bool forEach (SheetGemData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetGem* shGem;
class SheetGemInsertRuleData : public SheetBaseData
{
public:
	int ClassId;	//职业
	int PropId1;	//宝石属性1
	int PropId2;	//宝石属性2
	int PropId3;	//宝石属性3
	int PropId4;	//宝石属性4
	int PropId5;	//宝石属性5
	int PropId6;	//宝石属性6
	int PropId7;	//宝石属性7
	int PropId8;	//宝石属性8
	SheetGemInsertRuleData ();
};

class SheetGemInsertRule : public SheetBase
{
private:
	SheetGemInsertRuleData *data;
public:
	vector<SheetGemInsertRuleData*> getAll ();
	SheetGemInsertRuleData* getRow (int n);
	bool forEach (SheetGemInsertRuleData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetGemInsertRule* shGemInsertRule;
class SheetRoleLevelData : public SheetBaseData
{
public:
	int Level;	//等级
	int NeedExp;	//需要经验
	int AddPower;	//增加体力
	int BuyMoney;	//购买金钱
	int HiddenLevelMoney;	//隐藏金币
	int HiddenLevelMoney2;	//隐藏金币2
	int WorldBossMoney;	//世界BOSS金币
	int WorldBossKillMoney;	//世界BOSS击杀金币
	int ArenaMoney;	//竞技场金币
	SheetRoleLevelData ();
};

class SheetRoleLevel : public SheetBase
{
private:
	SheetRoleLevelData *data;
public:
	vector<SheetRoleLevelData*> getAll ();
	SheetRoleLevelData* getRow (int n);
	bool forEach (SheetRoleLevelData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetRoleLevel* shRoleLevel;
class SheetPartnerLevelUpData : public SheetBaseData
{
public:
	int Quality;	//品质
	int Level;	//等级
	int NeedExp;	//需要经验
	int NeedMoney;	//需要金钱
	SheetPartnerLevelUpData ();
};

class SheetPartnerLevelUp : public SheetBase
{
private:
	SheetPartnerLevelUpData *data;
public:
	vector<SheetPartnerLevelUpData*> getAll ();
	SheetPartnerLevelUpData* getRow (int n);
	bool forEach (SheetPartnerLevelUpData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetPartnerLevelUp* shPartnerLevelUp;
class SheetArenaCombatTargetData : public SheetBaseData
{
public:
	int MinRank;	//排名下限
	int MaxRank;	//排名上限
	int Offset1;	//偏移1
	int Offset2;	//偏移2
	int Offset3;	//偏移3
	int Offset4;	//偏移4
	int Offset5;	//偏移5
	SheetArenaCombatTargetData ();
};

class SheetArenaCombatTarget : public SheetBase
{
private:
	SheetArenaCombatTargetData *data;
public:
	vector<SheetArenaCombatTargetData*> getAll ();
	SheetArenaCombatTargetData* getRow (int n);
	bool forEach (SheetArenaCombatTargetData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetArenaCombatTarget* shArenaCombatTarget;
class SheetArenaRankRewardData : public SheetBaseData
{
public:
	int MinRank;	//排名下限
	int MaxRank;	//排名上限
	int MoneyMul;	//金币倍数
	int IdentifyItem;	//圣水
	int TalentItem;	//天赋石
	SheetArenaRankRewardData ();
};

class SheetArenaRankReward : public SheetBase
{
private:
	SheetArenaRankRewardData *data;
public:
	vector<SheetArenaRankRewardData*> getAll ();
	SheetArenaRankRewardData* getRow (int n);
	bool forEach (SheetArenaRankRewardData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetArenaRankReward* shArenaRankReward;
class SheetWorldBossRankRewardData : public SheetBaseData
{
public:
	int MinRank;	//排名下限
	int MaxRank;	//排名上限
	int IdentifyItem;	//圣水
	int MoneyMul;	//金币倍数
	int TalentItem;	//天赋石
	SheetWorldBossRankRewardData ();
};

class SheetWorldBossRankReward : public SheetBase
{
private:
	SheetWorldBossRankRewardData *data;
public:
	vector<SheetWorldBossRankRewardData*> getAll ();
	SheetWorldBossRankRewardData* getRow (int n);
	bool forEach (SheetWorldBossRankRewardData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetWorldBossRankReward* shWorldBossRankReward;
class SheetVipLevelData : public SheetBaseData
{
public:
	int Level;	//等级
	int RechargeAmount;	//充值金额
	int BuyPowerTime;	//买体力次数
	int BuyMoneyTime;	//买金钱次数
	int ResetEliteLevelTimes;	//重置精英关卡次数
	SheetVipLevelData ();
};

class SheetVipLevel : public SheetBase
{
private:
	SheetVipLevelData *data;
public:
	vector<SheetVipLevelData*> getAll ();
	SheetVipLevelData* getRow (int n);
	bool forEach (SheetVipLevelData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetVipLevel* shVipLevel;
class SheetRewardData : public SheetBaseData
{
public:
	int ID;	//ID
	int GroupId;	//组Id
	int rewardType;	//奖励类型
	int RewardId;	//奖励Id
	int RewardNum;	//奖励数量
	int Probability;	//几率
	SheetRewardData ();
};

class SheetReward : public SheetBase
{
private:
	SheetRewardData *data;
public:
	vector<SheetRewardData*> getAll ();
	SheetRewardData* getRow (int n);
	bool forEach (SheetRewardData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetReward* shReward;
class SheetLotPartnerData : public SheetBaseData
{
public:
	int RoleId;	//伙伴ID
	int CouponPro;	//点券几率
	int GoldPro;	//符石几率
	int RequireLevelId;	//关卡需求
	SheetLotPartnerData ();
};

class SheetLotPartner : public SheetBase
{
private:
	SheetLotPartnerData *data;
public:
	vector<SheetLotPartnerData*> getAll ();
	SheetLotPartnerData* getRow (int n);
	bool forEach (SheetLotPartnerData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetLotPartner* shLotPartner;
class SheetLotGemData : public SheetBaseData
{
public:
	int GroupId;	//组Id
	int ResType;	//资源类型
	int ResId;	//资源Id
	int ResNum;	//资源数量
	int Probability;	//几率
	SheetLotGemData ();
};

class SheetLotGem : public SheetBase
{
private:
	SheetLotGemData *data;
public:
	vector<SheetLotGemData*> getAll ();
	SheetLotGemData* getRow (int n);
	bool forEach (SheetLotGemData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetLotGem* shLotGem;
class SheetShopData : public SheetBaseData
{
public:
	int ID;	//ID
	int ResourceType;	//资源类型
	int ResourceId;	//资源Id
	int ResourceNum;	//资源数量
	int Price;	//价格
	string Desc;	//描述
	int Icon;	//图标
	SheetShopData ();
};

class SheetShop : public SheetBase
{
private:
	SheetShopData *data;
public:
	vector<SheetShopData*> getAll ();
	SheetShopData* getRow (int n);
	bool forEach (SheetShopData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetShop* shShop;
class SheetMountData : public SheetBaseData
{
public:
	int ID;	//ID
	string Name;	//名称
	int SpellId;	//技能
	int Aptitude;	//资质
	int FeedCost;	//喂养消耗
	int MaxLuck;	//最大幸运
	int Speed;	//速度
	SheetMountData ();
};

class SheetMount : public SheetBase
{
private:
	SheetMountData *data;
public:
	vector<SheetMountData*> getAll ();
	SheetMountData* getRow (int n);
	bool forEach (SheetMountData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetMount* shMount;
class SheetMountLevelUpData : public SheetBaseData
{
public:
	int MountId;	//坐骑ID
	int MinValue;	//幸运下限
	int MaxValue;	//幸运上限
	int Probability;	//升级几率
	SheetMountLevelUpData ();
};

class SheetMountLevelUp : public SheetBase
{
private:
	SheetMountLevelUpData *data;
public:
	vector<SheetMountLevelUpData*> getAll ();
	SheetMountLevelUpData* getRow (int n);
	bool forEach (SheetMountLevelUpData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetMountLevelUp* shMountLevelUp;
class SheetLevelDropData : public SheetBaseData
{
public:
	int LevelId;	//关卡ID
	int ResType;	//掉落类型
	int ResId;	//掉落ID
	int ResNum;	//掉落数量
	int IsGuide;	//是否引导
	SheetLevelDropData ();
};

class SheetLevelDrop : public SheetBase
{
private:
	SheetLevelDropData *data;
public:
	vector<SheetLevelDropData*> getAll ();
	SheetLevelDropData* getRow (int n);
	bool forEach (SheetLevelDropData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetLevelDrop* shLevelDrop;
class SheetDramaData : public SheetBaseData
{
public:
	int ID;	//ID
	int Type;	//类型
	int Arg1;	//参数1
	int Arg2;	//参数2
	int Arg3;	//参数3
	string Arg4;	//参数4
	string Arg5;	//参数5
	SheetDramaData ();
};

class SheetDrama : public SheetBase
{
private:
	SheetDramaData *data;
public:
	vector<SheetDramaData*> getAll ();
	SheetDramaData* getRow (int n);
	bool forEach (SheetDramaData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetDrama* shDrama;
class SheetOpenActionData : public SheetBaseData
{
public:
	int ID;	//ID
	int FunctionID;	//功能ID
	int OpenLevel;	//开启等级
	int OpenDungeonId;	//开启怪点
	SheetOpenActionData ();
};

class SheetOpenAction : public SheetBase
{
private:
	SheetOpenActionData *data;
public:
	vector<SheetOpenActionData*> getAll ();
	SheetOpenActionData* getRow (int n);
	bool forEach (SheetOpenActionData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetOpenAction* shOpenAction;
class SheetLevelTargetData : public SheetBaseData
{
public:
	int ID;	//ID
	string Content;	//内容
	SheetLevelTargetData ();
};

class SheetLevelTarget : public SheetBase
{
private:
	SheetLevelTargetData *data;
public:
	vector<SheetLevelTargetData*> getAll ();
	SheetLevelTargetData* getRow (int n);
	bool forEach (SheetLevelTargetData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetLevelTarget* shLevelTarget;
class SheetLevelCorrespondingData : public SheetBaseData
{
public:
	int LevelId;	//怪点ID
	int LevelTargetId;	//目标ID
	int Arg1;	//参数1
	int Arg2;	//参数2
	SheetLevelCorrespondingData ();
};

class SheetLevelCorresponding : public SheetBase
{
private:
	SheetLevelCorrespondingData *data;
public:
	vector<SheetLevelCorrespondingData*> getAll ();
	SheetLevelCorrespondingData* getRow (int n);
	bool forEach (SheetLevelCorrespondingData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetLevelCorresponding* shLevelCorresponding;
class SheetHiddenLevelMonsterData : public SheetBaseData
{
public:
	int Type;	//怪物类型
	int Level;	//怪物等级
	int RoleId;	//怪物ID
	SheetHiddenLevelMonsterData ();
};

class SheetHiddenLevelMonster : public SheetBase
{
private:
	SheetHiddenLevelMonsterData *data;
public:
	vector<SheetHiddenLevelMonsterData*> getAll ();
	SheetHiddenLevelMonsterData* getRow (int n);
	bool forEach (SheetHiddenLevelMonsterData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetHiddenLevelMonster* shHiddenLevelMonster;
class SheetHiddenLevelShapeData : public SheetBaseData
{
public:
	int DungeonId;	//副本ID
	int Type;	//怪物类型
	string Name;	//怪物名字
	int Shape;	//怪物外观
	SheetHiddenLevelShapeData ();
};

class SheetHiddenLevelShape : public SheetBase
{
private:
	SheetHiddenLevelShapeData *data;
public:
	vector<SheetHiddenLevelShapeData*> getAll ();
	SheetHiddenLevelShapeData* getRow (int n);
	bool forEach (SheetHiddenLevelShapeData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetHiddenLevelShape* shHiddenLevelShape;
class SheetHiddenLevelScoreData : public SheetBaseData
{
public:
	int RequireScore;	//要求积分
	int MountFeed;	//马鞭
	int GemItem;	//宝石礼券
	int RoleItem;	//伙伴礼券
	int MoneyMul;	//金币倍数
	int MoneyMul2;	//金币倍数2
	int Badge;	//徽章
	SheetHiddenLevelScoreData ();
};

class SheetHiddenLevelScore : public SheetBase
{
private:
	SheetHiddenLevelScoreData *data;
public:
	vector<SheetHiddenLevelScoreData*> getAll ();
	SheetHiddenLevelScoreData* getRow (int n);
	bool forEach (SheetHiddenLevelScoreData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetHiddenLevelScore* shHiddenLevelScore;
class SheetTalentOpenData : public SheetBaseData
{
public:
	int TalentId;	//天赋节点
	int OpenLevel;	//开启等级
	int OpenPrice;	//开启价格
	int ResetPrice;	//重置价格
	int ItemPrice;	//开启花费道具
	SheetTalentOpenData ();
};

class SheetTalentOpen : public SheetBase
{
private:
	SheetTalentOpenData *data;
public:
	vector<SheetTalentOpenData*> getAll ();
	SheetTalentOpenData* getRow (int n);
	bool forEach (SheetTalentOpenData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetTalentOpen* shTalentOpen;
class SheetTalentNameData : public SheetBaseData
{
public:
	int TalentId;	//天赋节点
	int ClassId;	//职业ID
	string TalentName;	//天赋名称
	SheetTalentNameData ();
};

class SheetTalentName : public SheetBase
{
private:
	SheetTalentNameData *data;
public:
	vector<SheetTalentNameData*> getAll ();
	SheetTalentNameData* getRow (int n);
	bool forEach (SheetTalentNameData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetTalentName* shTalentName;
class SheetTalentPropsData : public SheetBaseData
{
public:
	int ClassId;	//职业ID
	int PropId;	//属性ID
	int MinQ1;	//绿色下限
	int MaxQ1;	//绿色上限
	int MinQ2;	//蓝色下限
	int MaxQ2;	//蓝色上限
	int MinQ3;	//紫色下限
	int MaxQ3;	//紫色上限
	int MaxVal;	//最大数值
	SheetTalentPropsData ();
};

class SheetTalentProps : public SheetBase
{
private:
	SheetTalentPropsData *data;
public:
	vector<SheetTalentPropsData*> getAll ();
	SheetTalentPropsData* getRow (int n);
	bool forEach (SheetTalentPropsData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetTalentProps* shTalentProps;
class SheetMonsterDropData : public SheetBaseData
{
public:
	int DropId;	//掉落ID
	int ResType;	//资源类型
	int ResId;	//资源ID
	int ResNum;	//资源数量
	int Stacks;	//堆数
	SheetMonsterDropData ();
};

class SheetMonsterDrop : public SheetBase
{
private:
	SheetMonsterDropData *data;
public:
	vector<SheetMonsterDropData*> getAll ();
	SheetMonsterDropData* getRow (int n);
	bool forEach (SheetMonsterDropData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetMonsterDrop* shMonsterDrop;
class SheetDropResourceTypeData : public SheetBaseData
{
public:
	int ID;	//ID
	int MonsterCategory1;	//怪物分类1
	int MonsterCategory2;	//怪物分类2
	int MonsterCategory3;	//怪物分类3
	SheetDropResourceTypeData ();
};

class SheetDropResourceType : public SheetBase
{
private:
	SheetDropResourceTypeData *data;
public:
	vector<SheetDropResourceTypeData*> getAll ();
	SheetDropResourceTypeData* getRow (int n);
	bool forEach (SheetDropResourceTypeData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetDropResourceType* shDropResourceType;
class SheetEnchantSlotData : public SheetBaseData
{
public:
	int EquipmentSlot;	//装备部位
	int ItemId;	//物品ID
	int PropId;	//附魔属性
	SheetEnchantSlotData ();
};

class SheetEnchantSlot : public SheetBase
{
private:
	SheetEnchantSlotData *data;
public:
	vector<SheetEnchantSlotData*> getAll ();
	SheetEnchantSlotData* getRow (int n);
	bool forEach (SheetEnchantSlotData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetEnchantSlot* shEnchantSlot;
class SheetEnchantMaxPropData : public SheetBaseData
{
public:
	int EquipmentLevel;	//装备等级
	int MaxProp;	//属性上限
	int Blue;	//蓝
	int Purple;	//紫
	int Orange;	//橙
	SheetEnchantMaxPropData ();
};

class SheetEnchantMaxProp : public SheetBase
{
private:
	SheetEnchantMaxPropData *data;
public:
	vector<SheetEnchantMaxPropData*> getAll ();
	SheetEnchantMaxPropData* getRow (int n);
	bool forEach (SheetEnchantMaxPropData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetEnchantMaxProp* shEnchantMaxProp;
class SheetEnchantProData : public SheetBaseData
{
public:
	int EquipmentLevel;	//装备等级
	int Times;	//附魔次数
	int SuccPro;	//成功几率
	SheetEnchantProData ();
};

class SheetEnchantPro : public SheetBase
{
private:
	SheetEnchantProData *data;
public:
	vector<SheetEnchantProData*> getAll ();
	SheetEnchantProData* getRow (int n);
	bool forEach (SheetEnchantProData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetEnchantPro* shEnchantPro;
class SheetOnlineRewardData : public SheetBaseData
{
public:
	int ID;	//ID
	int Interval;	//间隔时间
	int ResType;	//资源类型
	int ResId;	//资源ID
	int ResNum;	//资源数量
	SheetOnlineRewardData ();
};

class SheetOnlineReward : public SheetBase
{
private:
	SheetOnlineRewardData *data;
public:
	vector<SheetOnlineRewardData*> getAll ();
	SheetOnlineRewardData* getRow (int n);
	bool forEach (SheetOnlineRewardData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetOnlineReward* shOnlineReward;
class SheetLoginRewardData : public SheetBaseData
{
public:
	int ID;	//ID
	int Gold;	//符石
	int Money;	//金币
	int Power;	//体力
	int RoleId;	//伙伴
	int ItemId;	//物品Id
	int ItemNum;	//物品数量
	SheetLoginRewardData ();
};

class SheetLoginReward : public SheetBase
{
private:
	SheetLoginRewardData *data;
public:
	vector<SheetLoginRewardData*> getAll ();
	SheetLoginRewardData* getRow (int n);
	bool forEach (SheetLoginRewardData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetLoginReward* shLoginReward;
#endif // __SHEET_H__
