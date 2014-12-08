#ifndef FLASHSTEPMEMORY_H
#define FLASHSTEPMEMORY_H

#include "IHWLayer.h"
#include "IStepMemory.h"
#include "DrumStep.h"
#include "RackInstrumentDefinitions.h"

/*
 * -----------------------------------------------------------------------
 * |                             PATTERN                           | ... |
 * -----------------------------------------------------------------------
 * |        INSTRUMENT1         |      INSTRUMENT 2          | ... | ... |
 * -----------------------------------------------------------------------
 * | ACTIVES | MUTES | SUBSTEPS | ACTIVES | MUTES | SUBSTEPS | ... | ... |
 * -----------------------------------------------------------------------
 *
 */

class NoVelocityStepMemory : public IStepMemory
{
public:
	NoVelocityStepMemory();
    virtual DrumStep getDrumStep( unsigned char instrumentID, unsigned char pattern, unsigned char step);
    virtual bool getNextActiveDrumStep( unsigned char instrumentID, unsigned char pattern, unsigned char & step, DrumStep & drumStep);
    virtual bool setDrumStep(unsigned char instrumentID, unsigned char pattern, unsigned char step, DrumStep stepData);
    virtual void getActivesAndMutesForNote(unsigned char instrumentID, unsigned char pattern, unsigned char windowIndex, unsigned char * data);
    virtual void getPatternSettings(unsigned char patternIndex, unsigned char * settings);
    virtual void setPatternSettings(unsigned char patternIndex, unsigned char * settings);
private:
    unsigned char data_[289];
};

#endif // FLASHSTEPMEMORY_H