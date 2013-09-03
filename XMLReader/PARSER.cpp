
ccgsXMLIo& ccgsXMLIo::getInstance ()
{
    static ccgsXMLIo xmlio;
    return (xmlio);
}

ccgsXMLIo::~ccgsXMLIo ()
{
}

ccgsXMLNode* load (const string& path)
{
}

void save (const string& path, const ccgsXMLNode* node)
{
}
