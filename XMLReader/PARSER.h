
#ifndef _CCGS_XML_PARSER_H
#define _CCGS_XML_PARSER_H

class ccgsXMLIo;
class ccgsXMLTree;
class ccgsXMLNode;
class ccgsXMLAttribute;

// ccgsXMLIo
class ccgsXMLIo
{
private:
    ccgsXMLIo ();

public:
    static ccgsXMLIo& getInstance ();
    ~ccgsXMLIo ();
    ccgsXMLNode* load (const string& path);
    void save (const string& path, const ccgsXMLNode* node);
};
ccgsXMLNode* ccgsXMLIo::load (const string& path)
{
    TiXmlElement* node = NULL;

    try {
        m_doc = new TiXmlDocument (path.c_str ());
        m_doc->LoadFile ();
        node = new ccgsXMLNode (m_doc->RootElement ());
    }
    catch (string& e) {
        return (NULL);
    }

    return (node);
}

ccgsXMLNode::ccgsXMLNode (TiXmlElement* node)
{
    try {
        
    }
    catch (string& e) {
    }
}

// ccgsXMLTree
class ccgsXMLTree
{
private:
    ccgsXMLNode *rootNode;

private:
    ccgsXMLTree (ccgsXMLTree&);
    void operator= (ccgsXMLTree&);

public:
    ccgsXMLTree ();
    ~ccgsXMLTree ();

    void init (const string& name);
    void load (const string& path);
    void save (const string& path);
};

void ccgsXMLTree::init (const string& name)
{
    this->rootNode = new ccgsXMLNode (name);
}

void ccgsXMLTree::load (const string& path)
{
    this->rootNode = ccgsXMLIo::getInstance ().load (path);
}

// ccgsXMLNode
class ccgsXMLNode
{
private:
    string name;
    string text;
    vector<ccgsXMLNode*> children;
    vector<ccgsXMLAttribute*> attributes;

private:
    ccgsXMLNode (ccgsXMLNode&);
    void operator= (ccgsXMLNode&);

public:
    ccgsXMLNode (const string& name);
    ~ccgsXMLNode ();

    const string& getName () const  { return name; }
    const string& getText () const  { return text; }
    int getChildCount ()     const  { return children.size (); }
    int getAttributeCount () const  { return attributes.size (); }

    ccgsXMLAttribute* getAttribute (int i) const;
    ccgsXMLAttribute* getAttribute (const string& name) const;
    ccgsXMLNode* getChild (int i) const;
    ccgsXMLNode* getChild (const string& childName, int childIndex=0) const;
    ccgsXMLNode* getParent() const;

    ccgsXMLNode* addChild (const string& name);
    ccgsXMLAttribute* addAttribute (const string& name, const string& value);
};

// ccgsXMLAttribute
class ccgsXMLAttribute
{
private:
    string name;
    string value;

private:
    ccgsXMLAttribute (ccgsXMLAttribute&);
    void operator= (ccgsXMLAttribute&);

public:
    ccgsXMLAttribute (const string& name, const string& value);

public:
    const string& getName () const  { return name; }
    const string& getValue() const  { return value; }

    bool  getBoolValue () const;
    int   getIntValue () const;
    int   getIntValue (
};


#endif  // _CCGS_XML_PARSER_H
