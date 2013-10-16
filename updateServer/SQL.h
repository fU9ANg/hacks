//
// SQL scripts
//

#ifndef _SQL_H_
#define _SQL_H_

#define SQL_SELECT_STU          \
"SELECT s.student_id AS student_id, s.first_name AS first_name, s.last_name AS last_name, s.account AS account, s.password AS password, r.path AS picture_name FROM student AS s, resource AS r WHERE s.picture_id = r.resource_id AND s.account=? AND s.password=?"
#define SQL_SELECT_COURSE       \
"SELECT course_name FROM course WHERE course_name = ?"
#define SQL_SELECT_CLASS        \
"SELECT count(*) AS COUNT FROM class WHERE class_name = ?"
#define SQL_SELECT_CLASSROOM    \
"SELECT classroom_name, white_board FROM classroom WHERE classroom_name = ?"
#define SQL_SELECT_CLASSROOM1   \
"SELECT classroom_name, white_board FROM classroom WHERE white_board = ?"
#define SQL_SELECT_TEACHER      \
"SELECT * FROM teacher WHERE account = ?"
#define SQL_SELECT_GRADE        \
"SELECT grade_name FROM grade WHERE grade_name = ?"
#define SQL_SELECT_ALLSTU       \
"SELECT stu.first_name, stu.last_name, stu.account, cla.class_name, gra.grade_name FROM student AS stu, class AS cla, grade AS gra WHERE stu.class_id = cla.class_id AND stu.grade_id = gra.grade_id AND gra.grade_name = ? AND cla.class_name = ?"

#define SQL_SELECT_USED_COURSE  \
"select cg.group_name, c.course_id, c.course_name, c.language, c.art, c.community, c.health, c.science, g.grade_name FROM course_group_course AS cgc, course_group AS cg, course AS c, grade AS g, grade_course AS gc WHERE  cgc.group_id = cg.group_id AND cgc.course_id = c.course_id AND gc.grade_id = g.grade_id AND c.course_id = gc.course_id AND g.grade_name=? AND group_name=?"

#define SQL_SELECT_COURSE_DB    \
"select cg.group_name, c.course_name, c.language, c.art, c.community, c.health, c.science, g.grade_name, concat (g.grade_name, cg.group_name) AS grade_group_name FROM course_group_course AS cgc, course_group AS cg, course AS c, grade AS g, grade_course AS gc WHERE  cgc.group_id = cg.group_id AND cgc.course_id = c.course_id AND gc.grade_id = g.grade_id AND c.course_id = gc.course_id"

#define SQL_SELECT_GRADE_DB     \
"select grade_name from grade"
#define SQL_SELECT_CLASS_DB     \
"select class_name from class"
#define SQL_SELECT_CLASSROOM_DB \
"select classroom_name, white_board from classroom"
#define SQL_SELECT_STUDENT_DB   \
"SELECT s.student_id, r.path AS picture_name, s.account AS student_name FROM student AS s, resource AS r WHERE s.picture_id = r.resource_id"
#define SQL_SELECT_COURSEITEM_DB "SELECT c.course_name, i.item_name, ci.fck_desc from course_item AS ci, course AS c, item AS i WHERE ci.course_id=c.course_id AND ci.item_id=i.item_id AND (c.course_name=? OR c.course_name=? OR c.course_name=? OR c.course_name=?)"

#define SQL_SELECT_ROOM         \
"SELECT classroom_id, classroom_name, white_board FROM classroom"

#define SQL_SELECT_ITEM_KEYS    \
"select ci.keys_info from course_item as ci, course as c, item as i where c.course_id=ci.course_id and i.item_id=ci.item_id and item_name=?"

#define SQL_SELECT_STUDENT_DETAILINFO \
"SELECT s.number, s.last_name, s.first_name, s.sex, sc.school_name, g.grade_name, c.class_name, s.account, t.first_name AS tf_name, t.last_name AS tl_name, s.picture_id FROM student AS s, school AS sc, grade AS g, class AS c, teacher AS t WHERE t.teacher_id = s.class_teacher_id AND sc.school_id = s.school_id AND g.grade_id = s.grade_id AND c.class_id = s.class_id AND s.student_id=? AND s.account=?"

#define SQL_SELECT_TEACHER_DETAILINFO \
"SELECT t.first_name, t.last_name, t.account, r.path AS pic_name FROM teacher as t, resource as r WHERE r.resource_id=t.picture_id AND t.account=?"

#endif
