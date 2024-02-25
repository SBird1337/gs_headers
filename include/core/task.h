/**
 * @file
 * @brief Task Library
*/

#ifndef GSAGB_TASK_H_
#define GSAGB_TASK_H_

#include "../common.h"
#include "../types.h"

typedef void task_t(void);

/**
 * @address{AGFE,080145A8}
*/
EXTERN_CALL void CreateTask(task_t *task, u16 priority);

/**
 * @address{AGFE,08014644}
*/
EXTERN_CALL void DestroyTask(task_t *task);

#endif // GSAGB_TASK_H_