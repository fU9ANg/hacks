#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <time.h>
#include "protocol.h"
#include "SQL.h"

#define SERV_IP "127.0.0.1"
#define SERV_PORT 9999 
#define CON_NUM 500
#include "database.h"

#include "gtest/gtest.h"


TEST(database, Basic) {
      CONFIG->readconfig("./../config.lua");
      DATABASE->Init(CONFIG->db_host, CONFIG->db_username, CONFIG->db_password, CONFIG->db_database);
      Statement* pstmt = DATABASE->getStatement();
      ResultSet* rest1 = pstmt->executeQuery("SELECT student_id FROM student");
      int i = 0;
      while(rest1->next()){
          i++;
      }

      ResultSet* rest2 = pstmt->executeQuery("SELECT count(1) FROM student");
      rest2->next();
      int j = rest2->getInt(1);
      delete rest1;
      delete rest2;
      delete pstmt;
      EXPECT_EQ(i,j);
}

TEST(database, pre) {
  //CONFIG->readconfig("./../config.lua");
  //DATABASE->Init(CONFIG->db_host, CONFIG->db_username, CONFIG->db_password, CONFIG->db_database);
    PreparedStatement* p = DATABASE->preStatement("select first_name from student where student_id= ?");
    p->setInt(1, 1);
    ResultSet* prest = p->executeQuery();
    while(prest->next()) {
        printf("%s\n", prest->getString(1).c_str());
    }
    delete prest;
    delete p;
}

TEST(database, xxx) {
    for(int i = 0; i<1000; i++) {
        try {
            PreparedStatement* pstmt = DATABASE->preStatement(SQL_SELECT_STU);
            pstmt->setString(1, "35");
            pstmt->setString(2, "123456");
            ResultSet* prst = pstmt->executeQuery();
            while(prst->next()) {
            }   
            delete prst;
            delete pstmt;
        }   
        catch(SQLException e) {
            printf("[%s] %s\n",__FUNCTION__, e.what());
        }   
    }
}

void* xxx(void* p) {
    for(int i = 0; i<100; i++) {
        try {
            MutexLockGuard guard(DATABASE->m_mutex);
            PreparedStatement* pstmt = DATABASE->preStatement(SQL_SELECT_STU);
            pstmt->setString(1, "35");
            pstmt->setString(2, "123456");
            ResultSet* prst = pstmt->executeQuery();
            while(prst->next()) {
            }   
            prst->close();
            delete prst;
            delete pstmt;
        }   
        catch(SQLException e) {
            printf("[%s] %s\n",__FUNCTION__, e.what());
        }   
    }
    return NULL;
}

TEST(database, yyy) {
    pthread_t pid[10];
    for(int i = 0;i <10; ++i) {
        pthread_create(&pid[i], NULL, xxx, NULL);
    }

    for(int i = 0;i <10; ++i) {
        pthread_join(pid[i], NULL);
    }
}
