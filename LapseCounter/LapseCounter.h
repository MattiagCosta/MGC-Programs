/**
 * Implementations in LapseCounter.c
 * 
 * Keyword: Lapse
 * 
 * @author Mattia G. Costa
 * @date 2025-02-16
 * @version 1.0
 */
#ifndef LAPSESCOUNTER_H
#define LAPSESCOUNTER_H

#include <windows.h>

/// @brief This is NOT used todeclare a LapseCounter
typedef struct{
	ULONGLONG count, timer;
} LapseData;

/// @brief The struct to declare a LaspeCounter
typedef struct{
	// 100-nanonesconds intervals; 10000 100-nanoseconds intervals = 1 millisecond
	ULARGE_INTEGER lt, t;
	ULONGLONG lapse;
	LapseData thisLapseData, previousLapseData;
} LapseCounter;

#define LAPSE_ISTANT 0
#define LAPSE_MICROSECOND 10
#define LAPSE_MILLISECOND 10000
#define LAPSE_SECOND 10000000
#define LAPSE_MINUTE 600000000

/**
 * @brief Used to start / reset a LapseCounter
 * @param lapseCounter Pointer to the LapseCounter already created
 * @param lapse The lapse you want to consider
 */
void StartLapseCounter(LapseCounter* lapseCounter, ULONGLONG lapse);

/**
 * @brief Increases the count of a LapseCounter by one
 * @param lapseCounter Pointer to the LapseCounter already created
 * @return 1 if the lapse has been exceeded, otherwise 0
 */
int CallLapseCounter(LapseCounter* lapseCounter);

#endif // LAPSESCOUNTER_H