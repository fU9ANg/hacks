
//
// Opcodes
//

#ifndef _PROTOCOL_H
#define _PROTOCOL_H

#pragma pack(1)
enum CommandType
{
    CT_Test = 1,
    ST_Test,
    CT_GetVersion,
    ST_GetVersion,
    CT_GetUpdateContent,
    ST_GetUpdateContent,
};



// 下面是所有用到的数据结构体
//
struct sCommonStruct
{
    unsigned int iValue;
};

struct sDBRecordFinished
{
    unsigned int iFlagFinished;
};
/*
    CT_GetDBRecordFinished,
    ST_GetDBRecordFinished,
*/

struct sSceneEnd
{
    int type;
};
/*
    CT_Scene_End,
    ST_Scene_End,
*/

struct sDBCount
{
    int count;
};

enum mClientType
{
    MCT_STUDENT = 1,
    MCT_TEACHER,
    MCT_WHITEBOARD,
};

enum eTeacherIntoRoomType
{
    TT_LOGIN_CLASSROOM  = 1,
    TT_LOGOUT_CLASSROOM = 2,
};

enum eClientStatus
{
    eCS_ONLINE  = 1,
    eCS_OFFLINE = 2,
    eCS_LEAVEEARLY = 3,
    eCS_NOLOGIN = 4
};

struct sLogin
{
    int type;   // 客户端的类型(学生,教师或白板)
    char username[20];
    char password[20];
};
/*
| len | CT_Login | struct sLogin |
*/

enum mLoginOutResult
{
    RES_SUCCEED = 1,
    RES_FAIL,
};
struct sLoginOutResult
{
    int succeed;
    char message[50];
};
/*
| len | CT_LoginResult | struct sLoginOutResult |
*/

struct sLogout
{
    int type; // 客户端的类型(学生,教师或白板)
};
/*
| len | CT_Logout | struct sLogout |
*/

struct sCourseGroup
{
    char sGradeName[20];    // 服务器没有处理这个字段
    char sCourseGroupName[20];
};
/*
| len | CT_SetCourseGroup | struct sCourseGroup |
*/

struct sGetCourseGroup
{
    char sCourseList[128];   // 动画片,暖身操,xxxx,
};
/*
| len | CT_GetCourseGroup |
| len | CT_GetCourseGroup | struct sGetCourseList |
*/

struct sGetCourseDB
{
    char sGradeName[20];
    char sGroupName[20];
    char sCourseName[20];
    int  iLanguage;
    int  iArt;
    int  iCommunity;
    int  iHealth;
    int  iScience;
};
/*
+------------+-------------+----------+-----+-----------+--------+---------+------------+
| group_name | course_name | language | art | community | health | science | grade_name |
+------------+-------------+----------+-----+-----------+--------+---------+------------+
| 课件1      | 暖身操      |       73 |  56 |        85 |     45 |      62 | 中班       |
+------------+-------------+----------+-----+-----------+--------+---------+------------+
| len | CT_GetCourseDB | struct sGetCourseDB |
*/

/*
| len | CT_CourseFinished | int course_id |
| len | ST_CourseFinished | int course_id |
*/

struct sGetGradeDB
{
    char sGradeName[20];
};
/*
+----------+------------+
| grade_id | grade_name |
+----------+------------+
|        1 | 小班       |
|        2 | 中班       |
+----------+------------+
| len | CT_sGetGradeDB | struct sGetGradeDB |
*/

struct sGetClassDB
{
    char sClassName[20];
};
/*
+----------+------------+
| grade_id | class_name |
+----------+------------+
|        1 | 一班     |
|        1 | 二班     |
|        1 | 三班     |
+----------+------------+
| len | CT_GetClassDB | struct sGetClassDB |
*/

struct sGetClassRoomDB
{
    char sClassRoomName[20];
};
/*
+----------------+
| classroom_name |
+----------------+
| A教室          |
| B教室          |
| C教室          |
+----------------+
| len | CT_GetClassRoomDB | struct sGetClassRoomDB |
*/

typedef struct sSelectedClassRoom{
    unsigned int classroom_id;
    mClientType client_type;
}TSelectedClassRoom;

struct sGetCourseItem
{
    char sCourseName[20];
};

/**
 * 学生在线状态
 */

//| MSG_HEAD | len | struct1 | student2 | ... | studentx |
//unsigned int len;
typedef struct ST_SendStudentStatusReq {
    unsigned int student_id;
    unsigned int status;
}TSendStudentStatusReq;


/*
| len | CT_GetCourseItem | struct sGetCourseItem |
*/

struct sCourseItem
{
    char sCourseName[20];
    char sItemName[20];
    char sDesc[512];
    int  iId;
};
/*
SELECT c.course_name, i.item_name from course_item AS ci, course AS c, item AS i WHERE ci.course_id=c.course_id AND ci.item_id=i.item_id AND c.course_name="造房子";
+-------------+---------------+
| course_name | item_name     |
+-------------+---------------+
| 造房子      | 空白          |
| 造房子      | 串场          |
| 造房子      | 开场          |
| 造房子      | 互动环节1     |
| 造房子      | 互动环节2     |
+-------------+---------------+
| len | CT_GetCourseItem | struct sCourseItem |
*/

struct sLoginOutClassRoom
{
    int  type;
    char sTeacherName[20];
    char sClassName[20];
    char sClassRoomName[20];
};
/*
| len | CT_LoginClassRoom | struct sLoginOutClassRoom |
| len | CT_LogoutClassRoom | struct sLoginOutClassRoom |
*/

struct sStudentDetail
{
    int  iStudentId;
    char sStudentName[20];
};
/*
| len | CT_GetStudentDetailInfo | struct sStudentDetailInfo |
*/

struct sGetStudentDetailInfo
{
    char sNumber[20];
    char sFirstName[20];
    char sLastName[20];
    char sSex[10];
    char sSchoolName[20];
    char sGradeName[20];
    char sClassName[20];
    char sAccount[20];
    char birthday[20];
    char stFirstName[20];
    char stLastName[20];
    int  iPicture_id;
};
/*
SELECT s.number, s.last_name, s.first_name, s.sex, sc.school_name, g.grade_name, c.class_name, s.account, s.password, s.birthday, t.first_name, t.last_name, s.picture_id FROM student AS s, school AS sc, grade AS g, class AS c, teacher AS t WHERE t.teacher_id = s.class_teacher_id AND sc.school_id = s.school_id AND g.grade_id = s.grade_id AND c.class_id = s.class_id;
+----------+-----------+------------+------+-----------------+------------+------------+---------+------------+------------+-----------+------------+
| number   | last_name | first_name | sex  | school_name     | grade_name | class_name | account | birthday   | first_name | last_name | picture_id |
+----------+-----------+------------+------+-----------------+------------+------------+---------+------------+------------+-----------+------------+
| 10000001 | yang      | c1         | 男   | 双楠幼儿园      | 小班       | 一年级     | 1       | 2000-01-01 | 四         | 李        |       1001 |
| 10000035 | yang      | c35        | 男   | 双楠幼儿园      | 小班       | 一年级     | 35      | 2000-01-01 | 四         | 李        |       1035 |
+----------+-----------+------------+------+-----------------+------------+------------+---------+------------+------------+-----------+------------+

| len | ST_GetStudentDetailInfo | struct sGetStudentDetailInfo |
*/

struct sGetAllStudentInfo
{
    int iStudentId;
    char sPicName[128];
    char sStudentName[20];
};
/*
select s.student_id, r.path AS picture_name from student AS s, resource AS r where s.picture_id=r.resource_id;
+------------+----------------+
| student_id | picture_name   |
+------------+----------------+
|          1 | /tmp/pic/9.png |
+------------+----------------+
| len | CT_GetAllStudentInfo | struct sGetAllStudentInfo |
*/

struct sLeaveEarly // LeaveEarly / ConfirmLeaveEarly
{
    //char sStudentName[20];
    //char sTeacharName[20];
    //char sClassroomName[20];
    //char sClassName[20];
    int student_id;
};

enum ePuzzleType
{
    PT_SQUARE = 1,  // 方块
    PT_CIRCLE,      // 圆形
};
struct sPuzzleType
{
    unsigned int type;
};

struct sPuzzleSize
{
    unsigned int rowCount;
    unsigned int columnCount;
};
/*

struct sPuzzleGameStart
{
    char type;
    char size;  // 20/12
};
*/
/*
| len | CT_Puzzle_GameStart | struct sPuzzleGameStart |
| len | ST_Puzzle_GameStart | struct sPuzzleGameStart |
*/

/*
| len | CT_LeaveEarly | struct sLeaveEarly |
| len | CT_ConfirmLeaveEarly | struct sLeaveEarly |
*/

struct sGetTeacherInfo
{
    char sTeacherName[20];
    char sPicName[128];
};
/*
| len | CT_GetTeacherInfo | struct sGetTeacherInfo |
*/

struct sControlLevel
{
    int level;  // VALUE: 0 (待机), 1, 2, 3, 4 (下一节)
};
/*
| len | CT_ControlLevel | struct sControlLevel |
| len | ST_ControlLevel | struct sControlLevel |
*/

struct sBuildHouseCaiHongXiaoWu
{
    char sText[12];
};
/*
| len | CT_BuildHouse_CaiHongXiaoWu | struct sBuildHouseCaiHongXiaoWu |
| len | ST_BuildHouse_CaiHongXiaoWu | struct sBuildHouseCaiHongXiaoWu |
*/

struct sBuildHouseSetStuGroup
{
    int  iGroupIndex;
    int  iStudentCount;
};
struct sBuildHouseStudentList
{
    char sStudentName[10];
};
/*
| len | CT_BuildHouse_SetStuGroup | struct sBuildHouseSetStuGroup + struct sBuildHouseStudentList |
| len | CT_BuildHouse_GetStuGroup | struct sBuildHouseSetStuGroup + struct sBuildHouseStudentList |
*/

enum ePuzzleIconStatus
{
    PIS_OK = 1,
    PIS_ERR,
    PIS_WAIT,
};
struct sPuzzleIconStatus
{
    int status;
};
/*
| len | CT_Puzzle_IconStatus | struct sPuzzleIconStatus |
| len | ST_Puzzle_IconStatus | struct sPuzzleIconStatus |
*/

///////////////////

enum ePuzzleActionTypePic
{
    AP_MOVE = 1,
    AP_DELETE,
    AP_ADD,
};

//学生拼图正确时发送发送学生是那个拼图块拼正确了
struct sPuzzleUpdatePic
{
    int student_id;
    int pic_idx; // 某张拼图块
    int pic_real_idx;
};

//拼图开始数据
struct sJigsawInitData
{
	char picturePath[512];
	int	stencilId;
	int	rowCount;
	int columnCount;

};

///////////////////

typedef struct sSubmitData
{
	unsigned int cLen;          //数据长度
	enum CommandType cType;     //数据编号
	void *cData() {             //指向数据的指针
		return this+1;
	}; 	
}MSG_HEAD;

typedef struct _stCT_GetCourseItemKeyInfoReq{
    //unsigned int course_item_id;
    char course_item[64];
}GetCourseItemKeyInfoReq;

typedef struct _stCT_GetCourseItemKeyInfoRsp{
    char keys[512];
}GetCourseItemKeyInfoRsp;

typedef struct Make_House_Update {
    int node_id;
    float x;
    float y;
    float zoom;
    float angle;
} TMake_House_Update;
/*
typedef struct Make_House_Move{
    int node_id;
    float to_x;
    float to_y;
}TMake_House_Move;

typedef struct Make_House_Zoom{
    int node_id;
    float zoom;
    float angle;
}TMake_House_Zoom;
*/
typedef struct Make_House_Change_Layer{
    int node_id;
    int layer;
}TMake_House_Change_Layer;

typedef struct Make_House_Add_Pic {
    int node_id;
    float x;
    float y;
    char picture_name[40];
}TMake_House_Add_Pic;

typedef struct Make_House_Del_Pic {
    int node_id;
    char picture_name[40];
}TMake_House_Del_Pic;

typedef struct sRainbowValley_House_Num{
	int num;
}THouse_Number;


//|MWG_HEAD|int len|sRainbowValley_HouseItem_Info1|sRainbowValley_HouseItem_Info2|...|
typedef struct sRainbowValley_HouseItem_Info{
	int layer;
	float  x;
	float y;
	float zoom;
	float angle;
	char picture_name[40];
}THouseItem_Info;


// make house

struct AddPic{
	int studentId;
	float x;
	float y;
	//char picName[4];
    short picName;
};//添加
struct movePic{
	int layer; //层作为图片标识符
	float toX;
	float toY;
};//移动

struct scalePic{
   int layer;
	float toScale;
};//缩放

struct rotatePic{
int layer;
float toAngle;
};//旋转

struct putLayerPic{
	int layer;
	int toLayer;
};//调整层次

struct deletePic{
	int layer;

};//删除素材

#define MSG_HEAD_LEN sizeof(struct sSubmitData)

#pragma pack()

#endif //_PROTOCOL_H
