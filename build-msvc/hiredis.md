
修改adapters\libevent.h：
redisLibeventHandler改为(event_callback_fn)redisLibeventHandler

修改hiredis.h:    typedef long long ssize_t;  改为
    #if !defined(_SSIZE_T_) && !defined(_SSIZE_T_DEFINED)
    typedef long long ssize_t;
    # define _SSIZE_T_
    # define _SSIZE_T_DEFINED
    #endif

修改sds.h:       typedef long long ssize_t;改为 
	#if !defined(_SSIZE_T_) && !defined(_SSIZE_T_DEFINED)
    typedef long long ssize_t;
    # define _SSIZE_T_
    # define _SSIZE_T_DEFINED
    #endif


