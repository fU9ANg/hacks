#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sqlite3.h>

int main (void)
{
    sqlite3* db = NULL;
    char* zErrMsg = 0;
    int rc;
    char sql[1024];

    rc =sqlite3_open ("teaching_db.db", &db);
    if (rc)
    {
        fprintf (stderr, "Can't open database: %s\n", sqlite3_errmsg (db));
        sqlite3_close (db);
        exit (1);
    }
    else
        printf ("is ok\n");


    /*
     * Source for table report (报表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS report; CREATE TABLE report ("
        "report_id INTEGER NOT NULL,"
        "number_id INTEGER NOT NULL,"
        "teacher_id INTEGER NOT NULL,"
        "student_id INTEGER NOT NULL,"
        "course_id INTEGER NOT NULL,"
        "used_time VARCHAR(20) DEFAULT '0时0分0秒');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO report VALUES (1,3,1,23,4,'0时3分0秒');"
                        "INSERT INTO report VALUES (2,4,1,13,4,'0时4分0秒');"
                        "INSERT INTO report VALUES (3,1,1,18,4,'0时1分0秒');"
                        "INSERT INTO report VALUES (4,5,1,30,4,'0时5分0秒');"
                        "INSERT INTO report VALUES (5,2,1,16,4,'0时2分0秒');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);


    /*
     * Source for table school (学校表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS school; CREATE TABLE school ("
        "school_id INTEGER NOT NULL,"
        "school_name VARCHAR(100) NOT NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO school VALUES (1,'双楠幼儿园');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);


    /*
     * Source for table grade (年级表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS grade; CREATE TABLE grade ("
        "grade_id INTEGER NOT NULL,"
        "grade_name VARCHAR(100) NOT NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO grade VALUES (1,'小班');"
                        "INSERT INTO grade VALUES (2,'中班');"
                        "INSERT INTO grade VALUES (3,'大班');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);


    /*
     * Source for table classroom (教室表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS classroom; CREATE TABLE classroom ("
        "classroom_id INTEGER NOT NULL,"
        "classroom_name VARCHAR(100) NOT NULL,"
        "white_board VARCHAR(20) NOT NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO classroom VALUES (1,'A教室','白板1');"
                        "INSERT INTO classroom VALUES (2,'B教室','白板2');"
                        "INSERT INTO classroom VALUES (3,'C教室','白板3');"
                        "INSERT INTO classroom VALUES (4,'D教室','白板4');"
                        "INSERT INTO classroom VALUES (5,'E教室','白板5');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);


    /*
     * Source for table class (班级表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS class; CREATE TABLE class ("
        "class_id INTEGER NOT NULL,"
        "class_name VARCHAR(40) NOT NULL,"
        "grade_id INTEGER NOT NULL,"
        "school_id INTEGER DEFAULT '1');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO class VALUES (1,'向阳班',1,1);"
                        "INSERT INTO class VALUES (2,'草莓班',1,1);"
                        "INSERT INTO class VALUES (3,'苹果班',1,1);"
                        "INSERT INTO class VALUES (4,'豆豆班',1,1);"
                        "INSERT INTO class VALUES (5,'果冻班',1,1);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);


    /*
     * Source for table course_group (课件组表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS course_group; CREATE TABLE course_group ("
        "group_id INTEGER NOT NULL,"
        "group_name char (40) NOT NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO course_group VALUES (1,'课件1');"
                        "INSERT INTO course_group VALUES (2,'课件2');"
                        "INSERT INTO course_group VALUES (3,'课件3');"
                        "INSERT INTO course_group VALUES (4,'课件4');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);

    /*
     * Source for table course (课程表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS course; CREATE TABLE course ("
        "course_id INTEGER NOT NULL,"
        "course_name char (40) NOT NULL,"
        "resource_id INTEGER NOT NULL,"
        "group_id INTEGER NOT NULL,"
        "language INTEGER NOT NULL,"
        "art INTEGER NOT NULL,"
        "community INTEGER NOT NULL,"
        "health INTEGER NOT NULL,"
        "science INTEGER NOT NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO course VALUES (1,'暖身操',100,1, 13, 56, 76, 25, 92);"
                        "INSERT INTO course VALUES (2,'动画片',101,1, 83, 64, 15, 18, 32);"
                        "INSERT INTO course VALUES (3,'造房子',103,1, 41, 26, 11, 65, 82);"
                        "INSERT INTO course VALUES (4,'拼图'  ,104,1, 35, 56, 25, 95, 11);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);


    /*
     * Source for table course_group_course (课件课程表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS course_group_course; CREATE TABLE course_group_course ("
        "group_course_id INTEGER NOT NULL,"
        "group_id INTEGER NOT NULL,"
        "course_id INTEGER NOT NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO course_group_course VALUES (1, 1, 1);"
                        "INSERT INTO course_group_course VALUES (2, 1, 2);"
                        "INSERT INTO course_group_course VALUES (3, 1, 3);"
                        "INSERT INTO course_group_course VALUES (4, 1, 4);"
                        "INSERT INTO course_group_course VALUES (5, 2, 2);"
                        "INSERT INTO course_group_course VALUES (6, 2, 3);"
                        "INSERT INTO course_group_course VALUES (7, 2, 1);"
                        "INSERT INTO course_group_course VALUES (8, 2, 4);"
                        "INSERT INTO course_group_course VALUES (9, 3, 4);"
                        "INSERT INTO course_group_course VALUES (10, 3, 2);"
                        "INSERT INTO course_group_course VALUES (11, 3, 1);"
                        "INSERT INTO course_group_course VALUES (12, 3, 4);"
                        "INSERT INTO course_group_course VALUES (13, 4, 1);"
                        "INSERT INTO course_group_course VALUES (14, 4, 3);"
                        "INSERT INTO course_group_course VALUES (15, 4, 2);"
                        "INSERT INTO course_group_course VALUES (16, 4, 4);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);


    /*
     * Source for table item (选项表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS item; CREATE TABLE item ("
        "item_id INTEGER NOT NULL,"
        "item_name char (40) NOT NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO item VALUES (1,'空白');"
                        "INSERT INTO item VALUES (2,'动画串场');"
                        "INSERT INTO item VALUES (3,'控场动画');"
                        "INSERT INTO item VALUES (4,'互动');"
                        "INSERT INTO item VALUES (5,'互动环节2');"
                        "INSERT INTO item VALUES (6,'暖身操');"
                        "INSERT INTO item VALUES (7,'动画剧院');"
                        "INSERT INTO item VALUES (8,'拍照');"
                        "INSERT INTO item VALUES (9,'拼图');"
                        "INSERT INTO item VALUES (10,'示范造房');"
                        "INSERT INTO item VALUES (11,'学生造房');"
                        "INSERT INTO item VALUES (12, '造房串场');"
                        "INSERT INTO item VALUES (13, '暖身串场');"
                        "INSERT INTO item VALUES (14, '拼图串场');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);


    /*
     * Source for table course_item (课程选项表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS course_item; CREATE TABLE course_item ("
        "course_item_id INTEGER NOT NULL,"
        "course_id INTEGER NOT NULL,"
        "item_id INTEGER NOT NULL,"
        "keys_info varchar(512) NOT NULL,"
        "fck_desc varchar(512) NOT NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO course_item VALUES (1, 1,6, '返回上一阶段,开始,停止', '说明:暖身操(暖身操)');"
                        "INSERT INTO course_item VALUES (2, 2,2, '返回上一阶段,离开,进入下一阶段', '说明:动画片(动画串场)');"
                        "INSERT INTO course_item VALUES (3, 2,7, '返回上一阶段,开始,停止', '说明:动画片(动画剧院)');"
                        "INSERT INTO course_item VALUES (4, 3,12, '返回上一阶段,离开,彩,虹,小,屋,彩虹谷,小怪物,创造游戏,进入下一阶段', '说明:造房子(造房串场)');"
                        "INSERT INTO course_item VALUES (5, 3,10, '', '说明:造房子(示范造房)');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO course_item VALUES (6, 3,11, '', '说明:造房子(学生造房)');"
                        "INSERT INTO course_item VALUES (7, 3,4, '返回上一阶段,彩虹谷场景,进入下一阶段', '说明:造房子(互动)');"
                        "INSERT INTO course_item VALUES (8, 3,8, '返回上一阶段,拍照,盖章,进入下一阶段', '说明:造房子(拍照)');"
                        "INSERT INTO course_item VALUES (9, 4,9, '返回上一阶段,启动,结束', '说明:拼图(拼图)');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);


    /*
     * Source for table grade_course (年级课程表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS grade_course; CREATE TABLE grade_course ("
        "grade_course_id INTEGER NOT NULL,"
        "grade_id INTEGER NOT NULL,"
        "course_id INTEGER NOT NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO grade_course VALUES (1,1,1);"
                        "INSERT INTO grade_course VALUES (2,1,2);"
                        "INSERT INTO grade_course VALUES (3,1,3);"
                        "INSERT INTO grade_course VALUES (4,1,4);"
                        "INSERT INTO grade_course VALUES (5,1,5);"
                        "INSERT INTO grade_course VALUES (6,2,1);"
                        "INSERT INTO grade_course VALUES (7,2,5);"
                        "INSERT INTO grade_course VALUES (8,3,2);"
                        "INSERT INTO grade_course VALUES (9,3,3);"
                        "INSERT INTO grade_course VALUES (10,3,4);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);


    /*
     * Source for table resource_type (资源类型表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS resource_type; CREATE TABLE resource_type ("
        "type_id INTEGER NOT NULL,"
        "name INTEGER NOT NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO resource_type VALUES (1,'动物');"
                        "INSERT INTO resource_type VALUES (2,'植物');"
                        "INSERT INTO resource_type VALUES (3,'建筑');"
                        "INSERT INTO resource_type VALUES (4,'人物');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);


    /*
     * Source for table resource (资源表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS resource; CREATE TABLE resource ("
        "resource_id INTEGER NOT NULL,"
        "type_id INTEGER NOT NULL,"
        "name INTEGER NOT NULL,"
        "size INTEGER NOT NULL,"
        "path VARCHAR(128) NOT NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO resource VALUES (1,1,'小花',64,'/tmp/pic/1.png');"
                        "INSERT INTO resource VALUES (2,1,'小草',64,'/tmp/pic/2.png');"
                        "INSERT INTO resource VALUES (3,1,'小树',64,'/tmp/pic/3.png');"
                        "INSERT INTO resource VALUES (4,2,'老虎',128,'/tmp/pic/4.png');"
                        "INSERT INTO resource VALUES (5,2,'松鼠',128,'/tmp/pic/5.png');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO resource VALUES (6,2,'兔子',128,'/tmp/pic/6.png');"
                        "INSERT INTO resource VALUES (7,2,'狮子',128,'/tmp/pic/7.png');"
                        "INSERT INTO resource VALUES (8,3,'房子',64,'/tmp/pic/8.png');"
                        "INSERT INTO resource VALUES (9,4,'小女孩',32,'/tmp/pic/9.png');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO resource VALUES (1001,4,'小朋友',32,'denglu/student1.png');"
                        "INSERT INTO resource VALUES (1002,4,'小朋友',32,'denglu/student2.png');"
                        "INSERT INTO resource VALUES (1003,4,'小朋友',32,'denglu/student3.png');"
                        "INSERT INTO resource VALUES (1004,4,'小朋友',32,'denglu/student4.png');"
                        "INSERT INTO resource VALUES (1005,4,'小朋友',32,'denglu/student5.png');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO resource VALUES (1006,4,'小朋友',32,'denglu/student6.png');"
                        "INSERT INTO resource VALUES (1007,4,'小朋友',32,'denglu/student7.png');"
                        "INSERT INTO resource VALUES (1008,4,'小朋友',32,'denglu/student8.png');"
                        "INSERT INTO resource VALUES (1009,4,'小朋友',32,'denglu/student9.png');"
                        "INSERT INTO resource VALUES (1010,4,'小朋友',32,'denglu/student10.png');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO resource VALUES (1011,4,'小朋友',32,'denglu/student11.png');"
                        "INSERT INTO resource VALUES (1012,4,'小朋友',32,'denglu/student12.png');"
                        "INSERT INTO resource VALUES (1013,4,'小朋友',32,'denglu/student13.png');"
                        "INSERT INTO resource VALUES (1014,4,'小朋友',32,'denglu/student14.png');"
                        "INSERT INTO resource VALUES (1015,4,'小朋友',32,'denglu/student15.png');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO resource VALUES (1016,4,'小朋友',32,'denglu/student16.png');"
                        "INSERT INTO resource VALUES (1017,4,'小朋友',32,'denglu/student17.png');"
                        "INSERT INTO resource VALUES (1018,4,'小朋友',32,'denglu/student18.png');"
                        "INSERT INTO resource VALUES (1019,4,'小朋友',32,'denglu/student19.png');"
                        "INSERT INTO resource VALUES (1020,4,'小朋友',32,'denglu/student20.png');"
                        "INSERT INTO resource VALUES (1021,4,'小朋友',32,'denglu/student21.png');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO resource VALUES (1022,4,'小朋友',32,'denglu/student22.png');"
                        "INSERT INTO resource VALUES (1023,4,'小朋友',32,'denglu/student23.png');"
                        "INSERT INTO resource VALUES (1024,4,'小朋友',32,'denglu/student24.png');"
                        "INSERT INTO resource VALUES (1025,4,'小朋友',32,'denglu/student25.png');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO resource VALUES (1026,4,'小朋友',32,'denglu/student26.png');"
                        "INSERT INTO resource VALUES (1027,4,'小朋友',32,'denglu/student27.png');"
                        "INSERT INTO resource VALUES (1028,4,'小朋友',32,'denglu/student28.png');"
                        "INSERT INTO resource VALUES (1029,4,'小朋友',32,'denglu/student29.png');"
                        "INSERT INTO resource VALUES (1030,4,'小朋友',32,'denglu/student30.png');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO resource VALUES (1031,4,'小朋友',32,'denglu/student31.png');"
                        "INSERT INTO resource VALUES (1032,4,'小朋友',32,'denglu/student32.png');"
                        "INSERT INTO resource VALUES (1033,4,'小朋友',32,'denglu/student33.png');"
                        "INSERT INTO resource VALUES (1034,4,'小朋友',32,'denglu/student34.png');"
                        "INSERT INTO resource VALUES (1035,4,'小朋友',32,'denglu/student35.png');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO resource VALUES (2001,4,'教师'  ,32,'denglu/teacher.png');"
                        "INSERT INTO resource VALUES (2002,4,'教师'  ,32,'denglu/teacher02.png');"
                        "INSERT INTO resource VALUES (2003,4,'教师'  ,32,'denglu/teacher03.png');");


    /*
     * Source for table country (国家表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS country; CREATE TABLE country ("
        "country_id INTEGER NOT NULL,"
        "country_name VARCHAR(100) NOT NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO country VALUES (1,'中国');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);


    /*
     * Source for table race (民族配置表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS race; CREATE TABLE race ("
        "race_id INTEGER NOT NULL,"
        "race_name VARCHAR(40) NOT NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO race VALUES (1,'汉族');"
                        "INSERT INTO race VALUES (2,'美利坚');");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);


    /*
     * Source for table native_place (所在地配置表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS native_place; CREATE TABLE native_place ("
        "native_id INTEGER NOT NULL,"
        "province VARCHAR(20) NOT NULL,"
        "city VARCHAR(20) DEFAULT NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO native_place VALUES (1,'四川',NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);


    /*
     * Source for table student (学生表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS student; CREATE TABLE student ("
        "student_id INTEGER NOT NULL,"
        "number VARCHAR(20) NOT NULL,"
        "last_name VARCHAR(10) NOT NULL,"
        "first_name VARCHAR(10) NOT NULL,"
        "sex VARCHAR(2) DEFAULT '男',"
        "school_id INTEGER NOT NULL,"
        "grade_id INTEGER NOT NULL,"
        "class_id INTEGER NOT NULL,"
        "account VARCHAR(100) NOT NULL,"
        "password VARCHAR(34) NOT NULL,"
        "birthday date NOT NULL,"
        "country_id INTEGER DEFAULT '1',"
        "race_id INTEGER NOT NULL,"
        "native_place_id INTEGER NOT NULL,"
        "class_teacher_id INTEGER NOT NULL,"
        "picture_id INTEGER NOT NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO student VALUES (1 ,'10000001','yang','c01','男',1,1,1,'学生01','123456','2000-01-01',1,1,1,2,1001);"
                        "INSERT INTO student VALUES (2 ,'10000002','yang','c02','男',1,1,1,'学生02','123456','2000-01-01',1,1,1,2,1002);"
                        "INSERT INTO student VALUES (3 ,'10000003','yang','c03','女',1,1,1,'学生03','123456','2000-01-01',1,1,1,2,1003);"
                        "INSERT INTO student VALUES (4 ,'10000004','yang','c04','女',1,1,1,'学生04','123456','2000-01-01',1,1,1,2,1004);"
                        "INSERT INTO student VALUES (5 ,'10000005','yang','c05','女',1,1,1,'学生05','123456','2000-01-01',1,1,1,2,1005);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO student VALUES (6 ,'10000006','yang','c06','男',1,1,1,'学生06','123456','2000-01-01',1,1,1,2,1006);"
                        "INSERT INTO student VALUES (7 ,'10000007','yang','c07','女',1,1,1,'学生07','123456','2000-01-01',1,1,1,2,1007);"
                        "INSERT INTO student VALUES (8 ,'10000008','yang','c08','女',1,1,1,'学生08','123456','2000-01-01',1,1,1,2,1008);"
                        "INSERT INTO student VALUES (9 ,'10000009','yang','c09','男',1,1,1,'学生09','123456','2000-01-01',1,1,1,2,1009);"
                        "INSERT INTO student VALUES (10,'10000010','yang','c10','女',1,1,1,'学生10','123456','2000-01-01',1,1,1,2,1010);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO student VALUES (11,'10000011','yang','c11','女',1,1,1,'学生11','123456','2000-01-01',1,1,1,2,1011);"
                        "INSERT INTO student VALUES (12,'10000012','yang','c12','女',1,1,1,'学生12','123456','2000-01-01',1,1,1,2,1012);"
                        "INSERT INTO student VALUES (13,'10000013','yang','c13','女',1,1,1,'学生13','123456','2000-01-01',1,1,1,2,1013);"
                        "INSERT INTO student VALUES (14,'10000014','yang','c14','女',1,1,1,'学生14','123456','2000-01-01',1,1,1,2,1014);"
                        "INSERT INTO student VALUES (15,'10000015','yang','c15','女',1,1,1,'学生15','123456','2000-01-01',1,1,1,2,1015);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO student VALUES (16,'10000016','yang','c16','男',1,1,1,'学生16','123456','2000-01-01',1,1,1,2,1016);"
                        "INSERT INTO student VALUES (17,'10000017','yang','c17','女',1,1,1,'学生17','123456','2000-01-01',1,1,1,2,1017);"
                        "INSERT INTO student VALUES (18,'10000018','yang','c18','女',1,1,1,'学生18','123456','2000-01-01',1,1,1,2,1018);"
                        "INSERT INTO student VALUES (19,'10000019','yang','c19','女',1,1,1,'学生19','123456','2000-01-01',1,1,1,2,1019);"
                        "INSERT INTO student VALUES (20,'10000020','yang','c20','女',1,1,1,'学生20','123456','2000-01-01',1,1,1,2,1020);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO student VALUES (21,'10000021','yang','c21','男',1,1,1,'学生21','123456','2000-01-01',1,1,1,2,1021);"
                        "INSERT INTO student VALUES (22,'10000022','yang','c22','女',1,1,1,'学生22','123456','2000-01-01',1,1,1,2,1022);"
                        "INSERT INTO student VALUES (23,'10000023','yang','c23','女',1,1,1,'学生23','123456','2000-01-01',1,1,1,2,1023);"
                        "INSERT INTO student VALUES (24,'10000024','yang','c24','男',1,1,1,'学生24','123456','2000-01-01',1,1,1,2,1024);"
                        "INSERT INTO student VALUES (25,'10000025','yang','c25','女',1,1,1,'学生25','123456','2000-01-01',1,1,1,2,1025);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO student VALUES (26,'10000026','yang','c26','男',1,1,1,'学生26','123456','2000-01-01',1,1,1,2,1026);"
                        "INSERT INTO student VALUES (27,'10000027','yang','c27','女',1,1,1,'学生27','123456','2000-01-01',1,1,1,2,1027);"
                        "INSERT INTO student VALUES (28,'10000028','yang','c28','男',1,1,1,'学生28','123456','2000-01-01',1,1,1,2,1028);"
                        "INSERT INTO student VALUES (29,'10000029','yang','c29','女',1,1,1,'学生29','123456','2000-01-01',1,1,1,2,1029);"
                        "INSERT INTO student VALUES (30,'10000030','yang','c30','男',1,1,1,'学生30','123456','2000-01-01',1,1,1,2,1030);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO student VALUES (31,'10000031','yang','c31','女',1,1,1,'学生31','123456','2000-01-01',1,1,1,2,1031);"
                        "INSERT INTO student VALUES (32,'10000032','yang','c32','女',1,1,1,'学生32','123456','2000-01-01',1,1,1,2,1032);"
                        "INSERT INTO student VALUES (33,'10000033','yang','c33','女',1,1,1,'学生33','123456','2000-01-01',1,1,1,2,1033);"
                        "INSERT INTO student VALUES (34,'10000034','yang','c34','女',1,1,1,'学生34','123456','2000-01-01',1,1,1,2,1034);"
                        "INSERT INTO student VALUES (35,'10000035','yang','c35','男',1,1,1,'学生35','123456','2000-01-01',1,1,1,2,1035);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);


    /*
     * Source for table teacher (教师表)
     */
    sprintf (sql, "%s", "DROP TABLE IF EXISTS teacher; CREATE TABLE teacher ("
        "teacher_id INTEGER NOT NULL,"
        "last_name VARCHAR(100) NOT NULL,"
        "first_name VARCHAR(100) NOT NULL,"
        "sex VARCHAR(2) DEFAULT '男',"
        "account VARCHAR(100) NOT NULL,"
        "password VARCHAR(100) NOT NULL,"
        "school_id INTEGER NOT NULL,"
        "birthday date NOT NULL,"
        "country_id INTEGER NOT NULL DEFAULT '0',"
        "race_id INTEGER NOT NULL,"
        "native_place_id INTEGER NOT NULL,"
        "picture_id INTEGER NOT NULL);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);
    sprintf (sql, "%s", "INSERT INTO teacher VALUES (1,'张','三','女','张三','123456',1,'1989-12-30',1,1,1,2001);"
                        "INSERT INTO teacher VALUES (2,'李','四','男','李四','123456',1,'1989-12-30',1,1,1,2001);"
                        "INSERT INTO teacher VALUES (3,'王','五','男','王五','123456',1,'1989-12-30',1,1,1,2001);");
    sqlite3_exec (db, sql, 0, 0, &zErrMsg);


    sqlite3_close (db);
    return (0);
}
