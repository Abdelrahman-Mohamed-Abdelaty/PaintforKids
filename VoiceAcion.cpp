#include "VoiceAcion.h"


VoiceAcion::VoiceAcion(ApplicationManager* app):Action(app)
{

}

void VoiceAcion::ReadActionParameters()
{
}

void VoiceAcion::Execute(bool readparameters)
{
	VoiceOn=pManager->isVoiceOn();
	if (VoiceOn)
		pManager->setVoiceOn(false);
	else
		pManager->setVoiceOn(true);

}
