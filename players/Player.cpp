#include "Player.h"
#include "../data/IStepMemory.h"
#include "IMIDICommandProcessor.h"
#include "../data/MIDICommand.h"

//#define DEBUG

#ifdef DEBUG
#include <iostream>
#endif

#define SUBSTEPS_PER_STEP 4

Player::Player(IStepMemory * memory, IMIDICommandProcessor * midiProcessor, PlayerSettings * settings) : memory_(memory),
                                                                                                      midiProcessor_(midiProcessor),
                                                                                                      settings_(settings)

{
    for (unsigned char i = 0; i < INSTRUMENTS; i++) {
        currentSteps_[i] = 0;
    }
    for (unsigned char i = 0 ; i < ALL_INSTRUMENTS_IN_BYTES; i++) {
        playingInstruments[i] = 0;
    }
}

void Player::stepFourth()
{
    stepDrumInstruments();
}

void Player::stepDrumInstruments()
{
    for (unsigned char i = 0; i < DRUM_INSTRUMENTS; i++) {
        DrumStep nextStep;

        bool nextStepExists = true;
        // when in the substep sequence dont ask for the next step otherwise ask for newxt available
        if (currentSteps_[i] % SUBSTEPS_PER_STEP != 0) {
            unsigned char nextStepIndex = currentSteps_[i] / SUBSTEPS_PER_STEP;
            //printf("calling currentStep on for %i index is %i \n", i, nextStepIndex);
            nextStep = memory_->getDrumStep(i, currentPatterns_[i], nextStepIndex);
        } else {
            unsigned char currentStepIndex = currentSteps_[i] / SUBSTEPS_PER_STEP;
            //printf("calling nextStep on for %i index is %i \n", i, currentStepIndex);
            nextStepExists = memory_->getNextActiveDrumStep(i, currentPatterns_[i], currentStepIndex, nextStep);
            //if (nextStepExists) printf("NextStepExists index %i\n", currentStepIndex);
            currentSteps_[i] = SUBSTEPS_PER_STEP * currentStepIndex;
        }

        if (nextStepExists) {
            if (settings_->isInstrumentOn(InstrumentTypes::DRUM, i)) {
                //printf("ON ");
                if (isInstrumentPlaying(i)) {
                    //printf("Playing ");
                    MIDICommand command(MIDICommand::NOTEOFF, 0, 0);
                    midiProcessor_->SendCommand(command);
                    setInstrumentPlaying(i, false);
                }

                if (!nextStep.isMuted()) {
                    //printf("Not muted");
                    DrumStep::DrumVelocityType type = nextStep.getSubStep(currentSteps_[i] % SUBSTEPS_PER_STEP);
                    if (type != DrumStep::OFF) {

                        unsigned char velocity = settings_->getMIDIVelocityFromDrumVelocity(nextStep.getSubStep(type));
                        MIDICommand command(MIDICommand::NOTEON, 0, velocity) ;
                        midiProcessor_->SendCommand(command);
                        setInstrumentPlaying(i, true);
                    }
                }
            }
            currentSteps_[i] = (currentSteps_[i] + 1) % (SUBSTEPS_PER_STEP * STEPS_PER_PATTERN);
        }
        //printf("\n");
    }
}
