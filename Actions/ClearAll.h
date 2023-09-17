#include "Action.h"
class ClearAll :public Action
{
private :
	ApplicationManager *m;
public:
ClearAll(ApplicationManager *pApp);
virtual void ReadActionParameters();
virtual void Execute(bool readparameters);
virtual bool Record();
};