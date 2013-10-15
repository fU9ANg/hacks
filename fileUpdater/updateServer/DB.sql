# SQL-Front 5.1  (Build 4.16)

/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE */;
/*!40101 SET SQL_MODE='' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES */;
/*!40103 SET SQL_NOTES='ON' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;


# Host: 192.168.0.254    Database: teaching_db
# ------------------------------------------------------
# Server version 5.5.29-0ubuntu0.12.04.1

DROP DATABASE IF EXISTS `teaching_db`;
CREATE DATABASE `teaching_db` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `teaching_db`;

# ======================================================
#
# Source for table report (报表)
#
DROP TABLE IF EXISTS `report`;
CREATE TABLE `report` (
    `report_id` int(11) NOT NULL AUTO_INCREMENT,
    `number_id` int(11) NOT NULL,
    `teacher_id` int(11) NOT NULL,
    `student_id` int(11) NOT NULL,
    `course_id` int(11) NOT NULL,
    `used_time` char(20) DEFAULT '0时0分0秒', # fixme: change data type to datetime
    PRIMARY KEY (`report_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table report
#
LOCK TABLES `report` WRITE;
/*!40000 ALTER TABLE `report` DISABLE KEYS */;
INSERT INTO `report` VALUES (1,3,1,23,4,'0时3分0秒');
INSERT INTO `report` VALUES (2,4,1,13,4,'0时4分0秒');
INSERT INTO `report` VALUES (3,1,1,18,4,'0时1分0秒');
INSERT INTO `report` VALUES (4,5,1,30,4,'0时5分0秒');
INSERT INTO `report` VALUES (5,2,1,16,4,'0时2分0秒');
/*!40000 ALTER TABLE `report` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table school (学校表)
#
DROP TABLE IF EXISTS `school`;
CREATE TABLE `school` (
    `school_id` int(11) NOT NULL,
    `school_name` char(100) NOT NULL,
    PRIMARY KEY (`school_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table school
#
LOCK TABLES `school` WRITE;
/*!40000 ALTER TABLE `school` DISABLE KEYS */;
INSERT INTO `school` VALUES (1,'双楠幼儿园');
/*!40000 ALTER TABLE `school` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table grade (年级表)
#
DROP TABLE IF EXISTS `grade`;
CREATE TABLE `grade` (
    `grade_id` int(11) NOT NULL,
    `grade_name` char(100) NOT NULL,
    PRIMARY KEY (`grade_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table grade
#
LOCK TABLES `grade` WRITE;
/*!40000 ALTER TABLE `grade` DISABLE KEYS */;
INSERT INTO `grade` VALUES (1,'小班');
INSERT INTO `grade` VALUES (2,'中班');
INSERT INTO `grade` VALUES (3,'大班');
/*!40000 ALTER TABLE `grade` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table classroom (教室表)
#
DROP TABLE IF EXISTS `classroom`;
CREATE TABLE `classroom` (
    `classroom_id` int(11) NOT NULL,
    `classroom_name` char(100) NOT NULL,
    `white_board` char(20) NOT NULL,
    PRIMARY KEY (`classroom_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table classroom
#
LOCK TABLES `classroom` WRITE;
/*!40000 ALTER TABLE `classroom` DISABLE KEYS */;
INSERT INTO `classroom` VALUES (1,'A教室','白板1');
INSERT INTO `classroom` VALUES (2,'B教室','白板2');
INSERT INTO `classroom` VALUES (3,'C教室','白板3');
INSERT INTO `classroom` VALUES (4,'D教室','白板4');
INSERT INTO `classroom` VALUES (5,'E教室','白板5');
/*!40000 ALTER TABLE `classroom` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table class (班级表)
#
DROP TABLE IF EXISTS `class`;
CREATE TABLE `class` (
    `class_id` int(11) NOT NULL,
    `class_name` char(40) NOT NULL,
    `grade_id` int(11) NOT NULL,
    `school_id` int(11) DEFAULT '1',
    PRIMARY KEY (`class_id`)
)   ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table class
#
LOCK TABLES `class` WRITE;
/*!40000 ALTER TABLE `class` DISABLE KEYS */;
INSERT INTO `class` VALUES (1,'向阳班',1,1);
INSERT INTO `class` VALUES (2,'草莓班',1,1);
INSERT INTO `class` VALUES (3,'苹果班',1,1);
INSERT INTO `class` VALUES (4,'豆豆班',1,1);
INSERT INTO `class` VALUES (5,'果冻班',1,1);
/*!40000 ALTER TABLE `class` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table course_group (课件组表)
#
DROP TABLE IF EXISTS `course_group`;
CREATE TABLE `course_group` (
    `group_id` int (11) NOT NULL,
    `group_name` char (40) NOT NULL,
    PRIMARY KEY (`group_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table course_group
#
LOCK TABLES `course_group` WRITE;
/*!40000 ALTER TABLE `course_group` DISABLE KEYS */;
INSERT INTO `course_group` VALUES (1,'教材组1');
INSERT INTO `course_group` VALUES (2,'教材组2');
INSERT INTO `course_group` VALUES (3,'教材组3');
INSERT INTO `course_group` VALUES (4,'教材组4');
/*!40000 ALTER TABLE `course_group` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table course (课程表)
#
DROP TABLE IF EXISTS `course`;
CREATE TABLE `course` (
    `course_id` int (11) NOT NULL,
    `course_name` char (40) NOT NULL,
    `resource_id` int(11) NOT NULL,
    `group_id` int (11) NOT NULL,
    `language` int (11) NOT NULL,
    `art` int (11) NOT NULL,
    `community` int (11) NOT NULL,
    `health` int (11) NOT NULL,
    `science` int (11) NOT NULL,
    PRIMARY KEY (`course_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table course
#
LOCK TABLES `course` WRITE;
/*!40000 ALTER TABLE `course` DISABLE KEYS */;
INSERT INTO `course` VALUES (1,'暖身操',100,1, 13, 56, 76, 25, 92);
INSERT INTO `course` VALUES (2,'动画片',101,1, 83, 64, 15, 18, 32);
INSERT INTO `course` VALUES (3,'造房子',103,1, 41, 26, 11, 65, 82);
INSERT INTO `course` VALUES (4,'拼图'  ,104,1, 35, 56, 25, 95, 11);
/*!40000 ALTER TABLE `course` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table course_group_course (课件课程表)
#
DROP TABLE IF EXISTS `course_group_course`;
CREATE TABLE `course_group_course` (
    `group_course_id` int (11) NOT NULL,
    `group_id` int (11) NOT NULL,
    `course_id` int (11) NOT NULL,
    PRIMARY KEY (`group_course_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table course_group_course
#
LOCK TABLES `course_group_course` WRITE;
/*!40000 ALTER TABLE `course_group_course` DISABLE KEYS */;
INSERT INTO `course_group_course` VALUES (1, 1, 1);
INSERT INTO `course_group_course` VALUES (2, 1, 2);
INSERT INTO `course_group_course` VALUES (3, 1, 3);
INSERT INTO `course_group_course` VALUES (4, 1, 4);

INSERT INTO `course_group_course` VALUES (5, 2, 2);
INSERT INTO `course_group_course` VALUES (6, 2, 3);
INSERT INTO `course_group_course` VALUES (7, 2, 1);
INSERT INTO `course_group_course` VALUES (8, 2, 4);

INSERT INTO `course_group_course` VALUES (9, 3, 4);
INSERT INTO `course_group_course` VALUES (10, 3, 2);
INSERT INTO `course_group_course` VALUES (11, 3, 1);
INSERT INTO `course_group_course` VALUES (12, 3, 4);

INSERT INTO `course_group_course` VALUES (13, 4, 1);
INSERT INTO `course_group_course` VALUES (14, 4, 3);
INSERT INTO `course_group_course` VALUES (15, 4, 2);
INSERT INTO `course_group_course` VALUES (16, 4, 4);
/*!40000 ALTER TABLE `course_group_course` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table item (选项表)
#
DROP TABLE IF EXISTS `item`;
CREATE TABLE `item` (
    `item_id` int (11) NOT NULL,
    `item_name` char (40) NOT NULL,
    PRIMARY KEY (`item_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table item
#
LOCK TABLES `item` WRITE;
/*!40000 ALTER TABLE `item` DISABLE KEYS */;
INSERT INTO `item` VALUES (1,'空白');
INSERT INTO `item` VALUES (2,'动画串场');
INSERT INTO `item` VALUES (3,'控场动画');
INSERT INTO `item` VALUES (4,'互动');
INSERT INTO `item` VALUES (5,'互动环节2');

INSERT INTO `item` VALUES (6,'暖身操');
INSERT INTO `item` VALUES (7,'动画剧院');
INSERT INTO `item` VALUES (8,'拍照');
INSERT INTO `item` VALUES (9,'拼图');
INSERT INTO `item` VALUES (10,'示范造房');
INSERT INTO `item` VALUES (11,'学生造房');
INSERT INTO `item` VALUES (12, '造房串场');
INSERT INTO `item` VALUES (13, '暖身串场');
INSERT INTO `item` VALUES (14, '拼图串场');
/*!40000 ALTER TABLE `item` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table course_item (课程选项表)
#
DROP TABLE IF EXISTS `course_item`;
CREATE TABLE `course_item` (
    `course_item_id` int (11) NOT NULL AUTO_INCREMENT,
    `course_id` int (11) NOT NULL,
    `item_id` int (11) NOT NULL,
    `keys_info` varchar(512) NOT NULL,
    `fck_desc` varchar(512) NOT NULL,
    PRIMARY KEY (`course_item_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table course_item
#
LOCK TABLES `course_item` WRITE;
/*!40000 ALTER TABLE `course_item` DISABLE KEYS */;
# INSERT INTO `course_item`(`course_id`, `item_id`, `keys_info`, `fck_desc`) VALUES (1,13, '开始,停止,进入下一阶段', '说明:暖身操(暖身串场)');
INSERT INTO `course_item`(`course_id`, `item_id`, `keys_info`, `fck_desc`) VALUES (1,6, '返回上一阶段,开始,停止', '说明:暖身操(暖身操)');
INSERT INTO `course_item`(`course_id`, `item_id`, `keys_info`, `fck_desc`) VALUES (2,2, '返回上一阶段,离开,进入下一阶段', '说明:动画片(动画串场)');
INSERT INTO `course_item`(`course_id`, `item_id`, `keys_info`, `fck_desc`) VALUES (2,7, '返回上一阶段,开始,停止', '说明:动画片(动画剧院)');
INSERT INTO `course_item`(`course_id`, `item_id`, `keys_info`, `fck_desc`) VALUES (3,12, '返回上一阶段,离开,彩,虹,小,屋,彩虹谷,小怪物,创造游戏,进入下一阶段', '说明:造房子(造房串场)');
# INSERT INTO `course_item`(`course_id`, `item_id`, `keys_info`, `fck_desc`) VALUES (3,10, '', '说明:造房子(示范造房)');
INSERT INTO `course_item`(`course_id`, `item_id`, `keys_info`, `fck_desc`) VALUES (3,11, '返回上一阶段,学生造房,进入下一阶段', '说明:造房子(学生造房)');
INSERT INTO `course_item`(`course_id`, `item_id`, `keys_info`, `fck_desc`) VALUES (3,4, '返回上一阶段,彩虹谷场景,进入下一阶段', '说明:造房子(互动)');
INSERT INTO `course_item`(`course_id`, `item_id`, `keys_info`, `fck_desc`) VALUES (3,8, '返回上一阶段,拍照,盖章,进入下一阶段', '说明:造房子(拍照)');
# INSERT INTO `course_item`(`course_id`, `item_id`, `keys_info`, `fck_desc`) VALUES (4,14, '返回上一阶段,待机,进入下一阶段', '说明:拼图(拼图串场)');
# INSERT INTO `course_item`(`course_id`, `item_id`, `keys_info`, `fck_desc`) VALUES (4,9, '返回上一阶段,方块,凹凸,12块,20块,启动,拼图监视,结束', '说明:拼图(拼图)');
# INSERT INTO `course_item`(`course_id`, `item_id`, `keys_info`, `fck_desc`) VALUES (4,9, '返回上一阶段,启动', '说明:拼图(拼图)');
INSERT INTO `course_item`(`course_id`, `item_id`, `keys_info`, `fck_desc`) VALUES (4,9, '返回上一阶段,启动', '说明:拼图(拼图)');
/*!40000 ALTER TABLE `course_item` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table grade_course (年级课程表)
#
DROP TABLE IF EXISTS `grade_course`;
CREATE TABLE `grade_course` (
    `grade_course_id` int (11) NOT NULL AUTO_INCREMENT,
    `grade_id` int (11) NOT NULL,
    `course_id` int (11) NOT NULL,
    PRIMARY KEY (`grade_course_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table grade_course
#
LOCK TABLES `grade_course` WRITE;
/*!40000 ALTER TABLE `grade_course` DISABLE KEYS */;
INSERT INTO `grade_course` VALUES (1,1,1);
INSERT INTO `grade_course` VALUES (2,1,2);
INSERT INTO `grade_course` VALUES (3,1,3);
INSERT INTO `grade_course` VALUES (4,1,4);
INSERT INTO `grade_course` VALUES (5,1,5);

INSERT INTO `grade_course` VALUES (6,2,1);
INSERT INTO `grade_course` VALUES (7,2,5);

INSERT INTO `grade_course` VALUES (8,3,2);
INSERT INTO `grade_course` VALUES (9,3,3);
INSERT INTO `grade_course` VALUES (10,3,4);
/*!40000 ALTER TABLE `grade_course` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table resource_type (资源类型表)
#
DROP TABLE IF EXISTS `resource_type`;
CREATE TABLE `resource_type` (
    `type_id` int (11) NOT NULL,
    `name` int (11) NOT NULL,
    PRIMARY KEY (`type_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table resource_type
#
LOCK TABLES `resource_type` WRITE;
/*!40000 ALTER TABLE `resource_type` DISABLE KEYS */;
INSERT INTO `resource_type` VALUES (1,'动物');
INSERT INTO `resource_type` VALUES (2,'植物');
INSERT INTO `resource_type` VALUES (3,'建筑');
INSERT INTO `resource_type` VALUES (4,'人物');
/*!40000 ALTER TABLE `resource_type` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table resource (资源表)
#
DROP TABLE IF EXISTS `resource`;
CREATE TABLE `resource` (
    `resource_id` int (11) NOT NULL,
    `type_id` int (11) NOT NULL,
    `name` int (11) NOT NULL,
    `size` int (11) NOT NULL,
    `path` char (128) NOT NULL,
    PRIMARY KEY (`resource_id`, `type_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table resource
#
LOCK TABLES `resource` WRITE;
/*!40000 ALTER TABLE `resource` DISABLE KEYS */;
INSERT INTO `resource` VALUES (1,1,'小花',64,'/tmp/pic/1.png');
INSERT INTO `resource` VALUES (2,1,'小草',64,'/tmp/pic/2.png');
INSERT INTO `resource` VALUES (3,1,'小树',64,'/tmp/pic/3.png');
INSERT INTO `resource` VALUES (4,2,'老虎',128,'/tmp/pic/4.png');
INSERT INTO `resource` VALUES (5,2,'松鼠',128,'/tmp/pic/5.png');
INSERT INTO `resource` VALUES (6,2,'兔子',128,'/tmp/pic/6.png');
INSERT INTO `resource` VALUES (7,2,'狮子',128,'/tmp/pic/7.png');
INSERT INTO `resource` VALUES (8,3,'房子',64,'/tmp/pic/8.png');
INSERT INTO `resource` VALUES (9,4,'小女孩',32,'/tmp/pic/9.png');

INSERT INTO `resource` VALUES (1001,4,'小朋友',32,'denglu/student1.png');
INSERT INTO `resource` VALUES (1002,4,'小朋友',32,'denglu/student2.png');
INSERT INTO `resource` VALUES (1003,4,'小朋友',32,'denglu/student3.png');
INSERT INTO `resource` VALUES (1004,4,'小朋友',32,'denglu/student4.png');
INSERT INTO `resource` VALUES (1005,4,'小朋友',32,'denglu/student5.png');

INSERT INTO `resource` VALUES (1006,4,'小朋友',32,'denglu/student6.png');
INSERT INTO `resource` VALUES (1007,4,'小朋友',32,'denglu/student7.png');
INSERT INTO `resource` VALUES (1008,4,'小朋友',32,'denglu/student8.png');
INSERT INTO `resource` VALUES (1009,4,'小朋友',32,'denglu/student9.png');
INSERT INTO `resource` VALUES (1010,4,'小朋友',32,'denglu/student10.png');

INSERT INTO `resource` VALUES (1011,4,'小朋友',32,'denglu/student11.png');
INSERT INTO `resource` VALUES (1012,4,'小朋友',32,'denglu/student12.png');
INSERT INTO `resource` VALUES (1013,4,'小朋友',32,'denglu/student13.png');
INSERT INTO `resource` VALUES (1014,4,'小朋友',32,'denglu/student14.png');
INSERT INTO `resource` VALUES (1015,4,'小朋友',32,'denglu/student15.png');

INSERT INTO `resource` VALUES (1016,4,'小朋友',32,'denglu/student16.png');
INSERT INTO `resource` VALUES (1017,4,'小朋友',32,'denglu/student17.png');
INSERT INTO `resource` VALUES (1018,4,'小朋友',32,'denglu/student18.png');
INSERT INTO `resource` VALUES (1019,4,'小朋友',32,'denglu/student19.png');
INSERT INTO `resource` VALUES (1020,4,'小朋友',32,'denglu/student20.png');
INSERT INTO `resource` VALUES (1021,4,'小朋友',32,'denglu/student21.png');

INSERT INTO `resource` VALUES (1022,4,'小朋友',32,'denglu/student22.png');
INSERT INTO `resource` VALUES (1023,4,'小朋友',32,'denglu/student23.png');
INSERT INTO `resource` VALUES (1024,4,'小朋友',32,'denglu/student24.png');
INSERT INTO `resource` VALUES (1025,4,'小朋友',32,'denglu/student25.png');

INSERT INTO `resource` VALUES (1026,4,'小朋友',32,'denglu/student26.png');
INSERT INTO `resource` VALUES (1027,4,'小朋友',32,'denglu/student27.png');
INSERT INTO `resource` VALUES (1028,4,'小朋友',32,'denglu/student28.png');
INSERT INTO `resource` VALUES (1029,4,'小朋友',32,'denglu/student29.png');
INSERT INTO `resource` VALUES (1030,4,'小朋友',32,'denglu/student30.png');

INSERT INTO `resource` VALUES (1031,4,'小朋友',32,'denglu/student31.png');
INSERT INTO `resource` VALUES (1032,4,'小朋友',32,'denglu/student32.png');
INSERT INTO `resource` VALUES (1033,4,'小朋友',32,'denglu/student33.png');
INSERT INTO `resource` VALUES (1034,4,'小朋友',32,'denglu/student34.png');
INSERT INTO `resource` VALUES (1035,4,'小朋友',32,'denglu/student35.png');

INSERT INTO `resource` VALUES (2001,4,'教师'  ,32,'denglu/teacher.png');
INSERT INTO `resource` VALUES (2002,4,'教师'  ,32,'denglu/teacher02.png');
INSERT INTO `resource` VALUES (2003,4,'教师'  ,32,'denglu/teacher03.png');

/*!40000 ALTER TABLE `resource` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table country (国家表)
#

DROP TABLE IF EXISTS `country`;
CREATE TABLE `country` (
    `country_id` int(11) NOT NULL,
    `country_name` char(100) NOT NULL,
    PRIMARY KEY (`country_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table country
#

LOCK TABLES `country` WRITE;
/*!40000 ALTER TABLE `country` DISABLE KEYS */;
INSERT INTO `country` VALUES (1,'中国');
/*!40000 ALTER TABLE `country` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table race (民族配置表)
#

DROP TABLE IF EXISTS `race`;
CREATE TABLE `race` (
    `race_id` int(11) NOT NULL,
    `race_name` char(40) NOT NULL,
    PRIMARY KEY (`race_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table race
#

LOCK TABLES `race` WRITE;
/*!40000 ALTER TABLE `race` DISABLE KEYS */;
INSERT INTO `race` VALUES (1,'汉族');
INSERT INTO `race` VALUES (2,'美利坚');
/*!40000 ALTER TABLE `race` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table native_place (所在地配置表)
#

DROP TABLE IF EXISTS `native_place`;
CREATE TABLE `native_place` (
    `native_id` int(11) NOT NULL,
    `province` char(20) NOT NULL,
    `city` char(20) DEFAULT NULL,
    PRIMARY KEY (`native_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table native_place
#

LOCK TABLES `native_place` WRITE;
/*!40000 ALTER TABLE `native_place` DISABLE KEYS */;
INSERT INTO `native_place` VALUES (1,'四川',NULL);
/*!40000 ALTER TABLE `native_place` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table student (学生表)
#
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student` (
    `student_id` int(11) NOT NULL,
    `number` char(20) NOT NULL,
    `last_name` char(10) NOT NULL,
    `first_name` char(10) NOT NULL,
    `sex` char(2) DEFAULT '男',
    `school_id` int(11) NOT NULL,
    `grade_id` int(11) NOT NULL,
    `class_id` int(11) NOT NULL,
    `account` char(100) NOT NULL,
    `password` char(34) NOT NULL,
    `birthday` date NOT NULL,
    `country_id` int(11) DEFAULT '1',
    `race_id` int(11) NOT NULL,
    `native_place_id` int(11) NOT NULL,
    `class_teacher_id` int (11) NOT NULL,
    `picture_id` int(11) NOT NULL,
    PRIMARY KEY (`student_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table student
#

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES (1,'10000001','yang','c1','男',1,1,1,'学生1','bea43f5f7ad39e2d184cb16885043d42','2000-01-01',1,1,1,2,1001);
INSERT INTO `student` VALUES (2,'10000002','yang','c2','男',1,1,1,'学生2','de94903812cefa17dc6b0a5955680ac1','2000-01-01',1,1,1,2,1002);
INSERT INTO `student` VALUES (3,'10000003','yang','c3','女',1,1,1,'学生3','2bbfa55dc58149cbdc795d293e8a5f7a','2000-01-01',1,1,1,2,1003);
INSERT INTO `student` VALUES (4,'10000004','yang','c4','女',1,1,1,'学生4','d3c4e8360c80aecf0d4224f49ad051c0','2000-01-01',1,1,1,2,1004);
INSERT INTO `student` VALUES (5,'10000005','yang','c5','女',1,1,1,'学生5','dba41b1f69fd877ff70f6aee9eec3351','2000-01-01',1,1,1,2,1005);
INSERT INTO `student` VALUES (6,'10000006','yang','c6','男',1,1,1,'学生6','3f3cc3f5c42ba508e079e529761db1b9','2000-01-01',1,1,1,2,1006);
INSERT INTO `student` VALUES (7,'10000007','yang','c7','女',1,1,1,'学生7','98d60f366acac9708057d113c94b332a','2000-01-01',1,1,1,2,1007);
INSERT INTO `student` VALUES (8,'10000008','yang','c8','女',1,1,1,'学生8','bdcb8247a921d7aeb25bb471f06efa76','2000-01-01',1,1,1,2,1008);
INSERT INTO `student` VALUES (9,'10000009','yang','c9','男',1,1,1,'学生9','8df27312657eff7452b8e61eedf5ada4','2000-01-01',1,1,1,2,1009);
INSERT INTO `student` VALUES (10,'10000010','yang','c10','女',1,1,1,'学生10','aa4e5df5219f2a3edb7fb66cc675e93e','2000-01-01',1,1,1,2,1010);
INSERT INTO `student` VALUES (11,'10000011','yang','c11','女',1,1,1,'学生11','aba5d94d4665c1b6e851a9fab26af79c','2000-01-01',1,1,1,2,1011);
INSERT INTO `student` VALUES (12,'10000012','yang','c12','女',1,1,1,'学生12','a12a6a129a59b6f181fc980fa63507cd','2000-01-01',1,1,1,2,1012);
INSERT INTO `student` VALUES (13,'10000013','yang','c13','女',1,1,1,'学生13','ab84804819501bf9a45706483321ad65','2000-01-01',1,1,1,2,1013);
INSERT INTO `student` VALUES (14,'10000014','yang','c14','女',1,1,1,'学生14','792a9747d590c8a25b02b3f6cbdb2ad2','2000-01-01',1,1,1,2,1014);
INSERT INTO `student` VALUES (15,'10000015','yang','c15','女',1,1,1,'学生15','6baaca734be42d39f03bfd78ce842a91','2000-01-01',1,1,1,2,1015);
INSERT INTO `student` VALUES (16,'10000016','yang','c16','男',1,1,1,'学生16','826d61930d8639a0ef6dc9078b39272a','2000-01-01',1,1,1,2,1016);
INSERT INTO `student` VALUES (17,'10000017','yang','c17','女',1,1,1,'学生17','7c0bc0a2cfa414ba234e0e0ed039544b','2000-01-01',1,1,1,2,1017);
INSERT INTO `student` VALUES (18,'10000018','yang','c18','女',1,1,1,'学生18','ae278ea65f9d6a6231eee1ac08fb7fd6','2000-01-01',1,1,1,2,1018);
INSERT INTO `student` VALUES (19,'10000019','yang','c19','女',1,1,1,'学生19','8574732cc24b431c3293702585dee05e','2000-01-01',1,1,1,2,1019);
INSERT INTO `student` VALUES (20,'10000020','yang','c20','女',1,1,1,'学生20','2ac99db5826c702807e33ac9037aba19','2000-01-01',1,1,1,2,1020);
INSERT INTO `student` VALUES (21,'10000021','yang','c21','男',1,1,1,'学生21','83391ac3577c539d6b3fc221fce5be46','2000-01-01',1,1,1,2,1021);
INSERT INTO `student` VALUES (22,'10000022','yang','c22','女',1,1,1,'学生22','aa48d391a221dfbcce380f738d1eeeea','2000-01-01',1,1,1,2,1022);
INSERT INTO `student` VALUES (23,'10000023','yang','c23','女',1,1,1,'学生23','d6a2e3c51e2434ed72ca2e8ecfe9a34c','2000-01-01',1,1,1,2,1023);
INSERT INTO `student` VALUES (24,'10000024','yang','c24','男',1,1,1,'学生24','18fc834db5fb034cfee712cdfd6658d1','2000-01-01',1,1,1,2,1024);
INSERT INTO `student` VALUES (25,'10000025','yang','c25','女',1,1,1,'学生25','571d2d9b9b0d2db4b6478f3d09a8132c','2000-01-01',1,1,1,2,1025);
INSERT INTO `student` VALUES (26,'10000026','yang','c26','男',1,1,1,'学生26','d3b31661eb0011d581f919b24f5b8fa8','2000-01-01',1,1,1,2,1026);
INSERT INTO `student` VALUES (27,'10000027','yang','c27','女',1,1,1,'学生27','bb5363841fa70b95c4c674d5f89853ff','2000-01-01',1,1,1,2,1027);
INSERT INTO `student` VALUES (28,'10000028','yang','c28','男',1,1,1,'学生28','a7ed71163005bf11fc6f2ab960b808fe','2000-01-01',1,1,1,2,1028);
INSERT INTO `student` VALUES (29,'10000029','yang','c29','女',1,1,1,'学生29','70b3c2f542fd8b08931c0693864ec9c3','2000-01-01',1,1,1,2,1029);
INSERT INTO `student` VALUES (30,'10000030','yang','c30','男',1,1,1,'学生30','506039225a12450268a5b89ea499b581','2000-01-01',1,1,1,2,1030);
INSERT INTO `student` VALUES (31,'10000031','yang','c31','女',1,1,1,'学生31','7d8f98220ec5f4ba662c2e13c546bbe6','2000-01-01',1,1,1,2,1031);
INSERT INTO `student` VALUES (32,'10000032','yang','c32','女',1,1,1,'学生32','ca4c4f5c547cc471afb46e1a5c6dbe06','2000-01-01',1,1,1,2,1032);
INSERT INTO `student` VALUES (33,'10000033','yang','c33','女',1,1,1,'学生33','ee976e0f28cebe3e47493667d5d6ff83','2000-01-01',1,1,1,2,1033);
INSERT INTO `student` VALUES (34,'10000034','yang','c34','女',1,1,1,'学生34','5b36158c8eb2fe88b02bd676821132a8','2000-01-01',1,1,1,2,1034);
INSERT INTO `student` VALUES (35,'10000035','yang','c35','男',1,1,1,'学生35','a61d21f8abfb9d2ab9a561ff0429a1b1','2000-01-01',1,1,1,2,1035);
UPDATE student SET password = "123456";
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table teacher (教师表)
#

DROP TABLE IF EXISTS `teacher`;
CREATE TABLE `teacher` (
    `teacher_id` int(11) NOT NULL,
    `last_name` char(100) NOT NULL,
    `first_name` char(100) NOT NULL,
    `sex` char(2) DEFAULT '男',
    `account` char(100) NOT NULL,
    `password` char(100) NOT NULL,
    `school_id` int(11) NOT NULL,
    `birthday` date NOT NULL,
    `country_id` int(11) NOT NULL DEFAULT '0',
    `race_id` int(11) NOT NULL,
    `native_place_id` int(11) NOT NULL,
    `picture_id` int(11) NOT NULL,
  PRIMARY KEY (`teacher_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table teacher
#

LOCK TABLES `teacher` WRITE;
/*!40000 ALTER TABLE `teacher` DISABLE KEYS */;
INSERT INTO `teacher` VALUES (1,'张','三','女','张三','e14b4e10a3107f50a07362d74e856218',1,'1989-12-30',1,1,1,2001);
INSERT INTO `teacher` VALUES (2,'李','四','男','李四','e14b4e10a3107f50a07362d74e856218',1,'1989-12-30',1,1,1,2001);
INSERT INTO `teacher` VALUES (3,'王','五','男','王五','e14b4e10a3107f50a07362d74e856218',1,'1989-12-30',1,1,1,2001);
INSERT INTO `teacher` VALUES (4,'A','A','男','A','e14b4e10a3107f50a07362d74e856218',1,'1989-12-30',1,1,1,2001);
INSERT INTO `teacher` VALUES (5,'a','a','男','a','e14b4e10a3107f50a07362d74e856218',1,'1989-12-30',1,1,1,2001);
INSERT INTO `teacher` VALUES (6,'B','B','男','B','e14b4e10a3107f50a07362d74e856218',1,'1989-12-30',1,1,1,2001);
INSERT INTO `teacher` VALUES (7,'b','b','男','b','e14b4e10a3107f50a07362d74e856218',1,'1989-12-30',1,1,1,2001);
INSERT INTO `teacher` VALUES (8,'C','C','男','C','e14b4e10a3107f50a07362d74e856218',1,'1989-12-30',1,1,1,2001);
INSERT INTO `teacher` VALUES (9,'c','c','男','c','e14b4e10a3107f50a07362d74e856218',1,'1989-12-30',1,1,1,2001);
INSERT INTO `teacher` VALUES (10,'D','D','男','D','e14b4e10a3107f50a07362d74e856218',1,'1989-12-30',1,1,1,2001);
INSERT INTO `teacher` VALUES (11,'d','d','男','d','e14b4e10a3107f50a07362d74e856218',1,'1989-12-30',1,1,1,2001);
UPDATE teacher SET password = "123456";
/*!40000 ALTER TABLE `teacher` ENABLE KEYS */;
UNLOCK TABLES;

/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
