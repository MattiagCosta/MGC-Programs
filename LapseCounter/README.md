# LapseCounter

## Table of contents

- [Concepts](#concepts)
- [How to use LapseCounters](#how-to-use-lapsecounters)
  - [LapseData](#lapsedata-struct)
  - [LapseCounter](#lapsecounter-struct)
  - [StartLapseCounter](#startlapsecounter)
  - [CallLapseCounter](#calllapsecounter)
  - [Constants](#constants)
- [Example](#example)
- [Files](#files)
- [Informations](#informations)

## Concepts

A LapseCounter is used to count how many times it gets called in a certain lapse.

Calling the LapseCounter is the operation that increases the count of calls by one.

If the lapse is exceeded, then calling a LapseCounter resets the count and starts a new lapse.

[For example](#example), if I want to count the iterations of a loop in a lapse of a second, I can call the LapseCounter at the end of the loop for a certain amount of time.

The structures, functions and constants uses the keyword "lapse".

## How to use LapseCounters

### LapseData struct

It's a struct that contains the data of a lapse.

**Members**:
- count - Contains the number of counts of a lapse.
- timer - Contains the time that really passed, which isn't always the lapse.

### LapseCounter struct

Use this struct to declare a LapseCounter variable.

**Members**:
- lt, t - Takes track of the time, the user doesn't need these.
- lapse - Stores the lapse the user wants to consider.
- thisLapseData - A [LapseData struct](#lapsedata) of the current laspe, whose data can change.
- previousLapseData - A [LapseData struct](#lapsedata) of the prevoius lapse, whose data is fixed until the current lapse ends.

### StartLapseCounter
It's a function which starts / resets a LapseCounter.

The user has to decide a lapse to consider, which will be stored in the *lapse* member of the LapseCounter.

The function sets the *thisLapseData* and *previousLapseData* members' data to zero to start the new lapse.

**Attributes**:
- lapseCounter - Points to the LapseCounter to start / reset.
- lapse - It's the lapse chosen by the user: it can be a positive number, zero or a [constant](#constants).

The function doesn't return anything.

### CallLapseCounter

It's a function that increases the *count* member of *thisLapseData* by one.

When the lapse has been exceeded, the function transfers the data of *thisLapseData* into *previousLapseData* and returns 1; the data in *thisLapseData* is set to zero.

**Attributes**:
- lapseCounter - Points to the LapseCounter to call.

**Return values**:
- 0 - If the lapse hasn't been exceeded.
- 1 - If the lapse has been exceeded.

CallLapseCounter is useful when used in if-statements (as showed in the [example](#example)).

### Constants

These constants help user to define the lapse to consider, since the lapse are counted in 100-nanoseconds intervals.

They are:
- LAPSE_ISTANT
- LAPSE_MICROSECOND
- LAPSE_MILLISECOND
- LAPSE_SECOND
- LAPSE_MINUTE

## Example

```c
#include "LapseCounter.h"
#include <stdio.h>

int main(){

	int secondsPassed = 0;

	LapseCounter lapseCounter;
	StartLapseCounter(&lapseCounter, LAPSE_SECOND);

	while(secondsPassed<4){
		if(CallLapseCounter(&lapseCounter)){
			printf("%d iterations / %d 100-nanoseconds\n", lapseCounter.previousLapseData.count, lapseCounter.previousLapseData.timer);
			secondsPassed++;
		}
	}

	return 0;
}
```

## Files

Under the directory "..\LapseCounter":
- LapseCounter.h: The library to use LapseCounters
- LapseCounter.c: Contains the implementations for the library
- README.md: This file - keep it!

## Informations

### LapseCounter code

Version: 1.0

Dated: 2025-02-16

Author: Mattia G. Costa

### README
Version: 1.0

Dated: 2025-02-17

Author: Mattia G. Costa

### License

This project is available under the [MIT License](https://github.com/MattiagCosta/MGC-Programs/blob/main/LICENSE).