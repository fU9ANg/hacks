#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sqlite3.h>
#include <iostream>
#include <string>

#include "StrUtil.h"

using namespace std;

int main (void)
{
    sqlite3* db = NULL;
    char* zErrMsg = 0;
    int rc;
    string sql, str;
    int nrow = 0, ncolumn = 0;
    char** azResult;

    rc =sqlite3_open ("teaching_db.db", &db);
    if (rc)
    {
        fprintf (stderr, "Can't open database: %s\n", sqlite3_errmsg (db));
        sqlite3_close (db);
        exit (1);
    }
    else
        printf ("is ok\n");

    sql = "select * from student where first_name = ?";
    stringUtil su;
    su.set_string (sql, "c02");
    su.set_int (sql, 10);
    sqlite3_get_table (db, sql.c_str(), &azResult, &nrow, &ncolumn, &zErrMsg);

    int i = 0;
    int j = 0;
    nrow++;
    printf ("row:%d, column=%d\n", nrow, ncolumn);
    printf ("The result of querying is: \n");

#if 1
    // printf fields
    for (j = 0; j < ncolumn; j++)
        printf ("%s ", azResult[j]);
    // printf each row
    for (printf ("\n\n"), i = 1; i < nrow; i++)
    {
        for (j = 0; j < ncolumn; j++)
            if (j + 1 == ncolumn)
                printf ("%s", azResult[i*ncolumn + j]);
            else
                printf ("%s, ", azResult[i*ncolumn + j]);
        printf ("\n");
    }
#else
    for (j = 0; j < nrow * ncolumn; j++)
        printf ("[%d]=%s, ", j, azResult[j]);
    printf ("\n");
#endif
    sqlite3_free_table (azResult);

    sqlite3_close (db);
    return (0);
}
