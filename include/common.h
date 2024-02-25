#ifndef GSAGB_COMMON_H_
#define GSAGB_COMMON_H_

// At our linking stage we do not yet know where our final binary will be placed and we cannot
// resolve long calls anymore, thus every call to an external function will have to be a long call
#define EXTERN_CALL extern __attribute__((long_call))

#endif // GSAGB_COMMON_H_