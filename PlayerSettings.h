#ifndef PLAYERSETTINGS_H
#define PLAYERSETTINGS_H

#include "RackInstrumentDefinitions.h"
#include "DrumStep.h"
#include "BitArrayOperations.h"

class PlayerSettings
{
public:

	enum DrumInstrumentEventType {TRIGGER, GATE};
	enum QuantizationType {_1_64, _1_32, _1_16, _1_8};
	enum MultiplicationType {_1, _2, _4, _8};
	enum PlayerMode {MASTER, SLAVE};

    PlayerSettings();

    QuantizationType getRecordQuantizationType();
    unsigned char getRecordQuantizationSize();
    void setRecordQuantizationType(QuantizationType quatizationType);

    DrumInstrumentEventType getDrumInstrumentEventType(unsigned char instrumentID);
    void setDrumInstrumentEventType(unsigned char instrumentID, DrumInstrumentEventType eventType);

    bool isInstrumentOn(unsigned char instrumentID);
    void setInstrumentOn(unsigned char instrumentID, bool isOn);

    void setCurrentPattern(unsigned char pattern);
    unsigned char getCurrentPattern();

    void setPatternChangedCallback(void (*patternChangedCallback)(unsigned char originalPatternIndex, unsigned char newPatternIndex));

    MultiplicationType getMultiplication();
    void setMultiplication(MultiplicationType multiplication);
    void setMultiplicationChangedCallback(void (*multiplicationChangedCallback)(MultiplicationType multiplication));

    unsigned int getBPM();
    void setBPM(unsigned int bpm, bool raiseCallback = true);
    void setBPMChangedCallback(void (*bpmChangedCallback)(unsigned int bpm));

    PlayerMode getPlayerMode();
    void setPlayerMode(PlayerMode playerMode);
    void setPlayerModeChangedCallback(void (*playerModeChangedCallback)(PlayerMode playerMode));

    void loadFromByteArray(unsigned char * data);
    void getInByteArray(unsigned char * data);

    void setSettingsChangedCallback(void (*settingsChangedCallback)());
    unsigned int * getManipulatedPatternsBitArray();
    void resetManipulatedPatterns();
private:
    unsigned char drumInstrumentEventTypes_;
    unsigned char instrumentStatuses_;
    unsigned char currentPattern_;
    void (*patternChangedCallback_)(unsigned char originalPatternIndex, unsigned char newPatternIndex);
    QuantizationType recordQunatizationType_;
    MultiplicationType multiplication_;
    void (*multiplicationChangedCallback_)(MultiplicationType multiplication);
    unsigned int bpm_;
    void (*bpmChangedCallback_)(unsigned int bpm);
    PlayerMode playerMode_;
    void (*playerModeChangedCallback_)(PlayerMode playerMode);
    void (*settingsChangedCallback_)();
    unsigned int manipulatedPatterns_[4];

};

inline unsigned int * PlayerSettings::getManipulatedPatternsBitArray() {
	return manipulatedPatterns_;
}

inline void PlayerSettings::setInstrumentOn(unsigned char instrumentID, bool isOn)
{
	if (isInstrumentOn(instrumentID) != isOn) {
		BitArrayOperations::setBit(instrumentStatuses_, instrumentID, isOn);
		settingsChangedCallback_();
	}
}

inline bool PlayerSettings::isInstrumentOn(unsigned char instrumentID)
{
	return BitArrayOperations::getBit(instrumentStatuses_, instrumentID);
}

inline PlayerSettings::DrumInstrumentEventType PlayerSettings::getDrumInstrumentEventType(unsigned char instrumentID)
{
	return GETBIT(drumInstrumentEventTypes_, instrumentID) ? GATE : TRIGGER;
}

inline void PlayerSettings::setDrumInstrumentEventType(unsigned char instrumentID, DrumInstrumentEventType eventType)
{
	if (getDrumInstrumentEventType(instrumentID) != eventType) {
		SETBIT(drumInstrumentEventTypes_, instrumentID, eventType == GATE);
		settingsChangedCallback_();
	}
}

inline unsigned char PlayerSettings::getCurrentPattern() {
	return currentPattern_;
}

inline void PlayerSettings::setPatternChangedCallback(void (*patternChangedCallback)(unsigned char originalPatternIndex, unsigned char newPatternIndex)) {
	patternChangedCallback_ = patternChangedCallback;
}

inline PlayerSettings::QuantizationType PlayerSettings::getRecordQuantizationType() {
	return recordQunatizationType_;
}

inline void PlayerSettings::setRecordQuantizationType(PlayerSettings::QuantizationType quatizationType) {
	if (recordQunatizationType_ != quatizationType) {
		recordQunatizationType_ = quatizationType;
		settingsChangedCallback_();
	}
}

inline PlayerSettings::MultiplicationType PlayerSettings::getMultiplication() {
	return multiplication_;
}

inline void PlayerSettings::setMultiplication(PlayerSettings::MultiplicationType multiplication) {
	if (multiplication_ != multiplication) {
		multiplication_ = multiplication;
		multiplicationChangedCallback_(multiplication_);
		settingsChangedCallback_();
	}
}

inline void PlayerSettings::setMultiplicationChangedCallback(void (*multiplicationChangedCallback)(PlayerSettings::MultiplicationType multiplication)) {
	multiplicationChangedCallback_ = multiplicationChangedCallback;
}

inline unsigned int PlayerSettings::getBPM() {
	return bpm_;
}

inline void PlayerSettings::setBPMChangedCallback(void (*bpmChangedCallback)(unsigned int bpm)) {
	bpmChangedCallback_ = bpmChangedCallback;
}

inline PlayerSettings::PlayerMode PlayerSettings::getPlayerMode() {
	return playerMode_;
}

inline void PlayerSettings::setBPM(unsigned int bpm, bool raiseCallback) {
	if (bpm_ != bpm) {
		bpm_ = bpm;
		if (raiseCallback) {
			bpmChangedCallback_(bpm);
		}
		settingsChangedCallback_();
	}
}

inline void PlayerSettings::setPlayerMode(PlayerSettings::PlayerMode playerMode) {
	if (playerMode_ != playerMode) {
		playerMode_ = playerMode;
		playerModeChangedCallback_(playerMode_);
		settingsChangedCallback_();
	}
}

inline void PlayerSettings::setPlayerModeChangedCallback(void (*playerModeChangedCallback)(PlayerSettings::PlayerMode playerMode)) {
	playerModeChangedCallback_ = playerModeChangedCallback;
}

inline void PlayerSettings::setSettingsChangedCallback(void (*settingsChangedCallback)()) {
	settingsChangedCallback_ = settingsChangedCallback;
}
#endif // PLAYERSETTINGS_H
