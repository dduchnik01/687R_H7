#ifndef __TS_H
#define __TS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h> 

typedef struct {
	void       (*Init)();
	uint8_t    (*ReadID)();
	void       (*Start)();
	uint8_t    (*DetectTouch)();
	void       (*GetXY)(uint16_t*, uint16_t*);
	void       (*EnableIT)();
	void       (*ClearIT)();
	uint8_t    (*GetITStatus)();
	void       (*DisableIT)();
	void       (*InterruptHandler)();
} TS_DrvTypeDef;

#ifdef __cplusplus
}
#endif

#endif /* TS_H */
