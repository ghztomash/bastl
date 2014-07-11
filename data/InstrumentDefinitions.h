#ifndef INSTRUMENTDEFINITIONS_H
#define INSTRUMENTDEFINITIONS_H

#define STEPS_PER_PATTERN 64

#define DRUM_INSTRUMENTS 20
#define DRUM_PATTERNS 16
#define DRUM_STEPS DRUM_INSTRUMENTS * DRUM_PATTERNS * STEPS_PER_PATTERN

#define MONO_INSTRUMENTS 4
#define MONO_PATTERNS 16
#define MONO_STEPS MONO_INSTRUMENTS * MONO_PATTERNS * STEPS_PER_PATTERN

#define INSTRUMENTS DRUM_INSTRUMENTS + MONO_INSTRUMENTS

#define ALL_INSTRUMENTS_IN_BYTES 3

class InstrumentTypes {
public:
    enum InstrumentType {DRUM, MONO, POLY};
};

#endif // INSTRUMENTDEFINITIONS_H
