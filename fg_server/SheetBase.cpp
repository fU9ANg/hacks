
#include "SheetBase.h"

bool SheetUtils::readToken (FILE* fp, string& value)
{
    value = "";
    while (1) {
        char c = (char) fgetc (fp);
        if (c == EOF)
            break;
        else if (c == ',')
            break;
        else
            value += c;
    }

    return (value != "");
}

bool SheetUtils::skipChar (FILE* fp, char ch)
{
    while (1) {
        char c = (char) fgetc (fp);
        if (c == EOF)
            return (false);
        if (c == ch)
            break;
    }

    fgetc (fp);

    if (feof (fp))
        return (false);
    else
        fseek (fp, -1, SEEK_CUR);

    return (true);
}

void SheetUtils::skipBom (FILE* fp)
{
    //
}
