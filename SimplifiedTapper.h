/*
 * SimplifiedTapper.h
 *
 *  Created on: Sep 5, 2014
 *      Author: bastl
 */

#ifndef SIMPLIFIED_TAPPER_H_
#define SIMPLIFIED_TAPPER_H_

#include "ITapper.h"

class SimplifiedTapper : public ITapper {
public:
	SimplifiedTapper();
	virtual ~SimplifiedTapper();
	virtual void init(unsigned int maxStepLengthInTimeUnits, unsigned int  maxStepDeviationInTImeUnits);
	virtual void tap(unsigned int tapTime);
	virtual void setStepsPerTap(unsigned char stepsPerTap);
	virtual unsigned int getTimeUnitsPerStep();
	virtual void setStepCallBack(void (*makeStep)());
	virtual bool anyStepDetected();
	unsigned int lastTapTime;
private:
	char stepsInRow_;
	unsigned int lastTapTime_;
	unsigned int currentTapTime_;
	unsigned int stepsPerTap_;
	unsigned int maxStepLengthInTimeUnits_;
	unsigned int maxStepDeviationInTImeUnits_;

	void (*makeStep_)();
};

inline void SimplifiedTapper::setStepsPerTap(unsigned char stepsPerTap) {
	stepsPerTap_ = stepsPerTap;
}

inline unsigned int SimplifiedTapper::getTimeUnitsPerStep() {
	return currentTapTime_ / stepsPerTap_;
}

inline void SimplifiedTapper::setStepCallBack(void (*makeStep)()) {
	makeStep_ = makeStep;
}

inline bool SimplifiedTapper::anyStepDetected() {
	return stepsInRow_ > 1;
}

#endif /* TAPPER_H_ */
