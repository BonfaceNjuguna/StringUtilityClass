class Item
{
public:
	virtual ~Item();
	virtual void Use() = 0;
	virtual void Describe() = 0;
};

Item::~Item()
{
}