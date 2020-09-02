

修改adapters\libevent.h：

redisLibeventHandler改为(event_callback_fn)redisLibeventHandler





修改hiredis.h:

typedef long long ssize_t;改为typedef int ssize_t;





修改sds.h:

typedef long long ssize_t;改为typedef int ssize_t;