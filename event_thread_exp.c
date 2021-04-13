#include <stdio.h>
#include <event.h>
#include <pthread.h>

typedef struct mbim_priv_s
{
    struct event    *mbim_event;
    uint8_t         is_mbim_event;
    uint8_t         is_thread_created;
    pthread_t       read_tid;
} mbim_priv_t;

typedef struct act_dev_s
{
    mbim_priv_t     mbim_priv;
    struct event    *act_dev_event;
} act_dev_t;

struct event_base *evbase;


static void *mbim_read_thread(void *arg)
{
    printf("%s is created\n", __func__);

    while (1) {
        sleep(5);
        printf("mbim-read-thread: in while loop after 5 sec...\n");
    }
}

int mbim_main(evutil_socket_t fd, short what, void *arg)
{
#if 0
    printf("MBIM-MAIN: On tmo\n");
#else
    act_dev_t *act_dev = (act_dev_t *) arg;
    if (NULL == act_dev) {
        printf("act device is NULL\n");
        return -1;
    }
    if (act_dev->mbim_priv.is_thread_created != 1) {
        pthread_create(&act_dev->mbim_priv.read_tid, NULL, mbim_read_thread, (void *) act_dev);
        printf("mbim-main: pthread created: as mbim-read-thread\n");
        act_dev->mbim_priv.is_thread_created = 1;
    }
#endif
}

void modem_pre_sim(evutil_socket_t fd, short what, void *arg)
{
#if 0
    printf("ModemPreSim: on tmo\n");
#else
    act_dev_t *act_dev = (act_dev_t *) arg;
    if (NULL == act_dev) {
        printf("modem-pre-sim: act device is NULL\n");
        return;
    }

    if (act_dev->mbim_priv.is_mbim_event != 1) {
        struct timeval  tv;
        struct event    *ev;

        tv.tv_sec = 1;
        tv.tv_usec = 0;
        ev = event_new(evbase, -1, EV_PERSIST, (void *) mbim_main, (void *) act_dev);
        if ( ev < 0 ) {
            printf("Failed in create Mbim Event\n");
            return;
        }
        event_add(ev, &tv);
        act_dev->mbim_priv.mbim_event = ev;
        act_dev->mbim_priv.is_mbim_event = 1;
        printf("MBIM Event Created\n");
    }

    printf("On modem-pre-sim: MBIM Event state checking after tmo\n");
#endif
}

void init_active_device(act_dev_t *act_dev)
{
    struct timeval  tv;
    struct event    *ev;

    if (act_dev == NULL) return;

    tv.tv_sec = 2;
    tv.tv_usec = 0;
    ev = event_new(evbase, -1, EV_PERSIST, (void *) modem_pre_sim, (void *) act_dev);
    if ( ev < 0 ) {
        printf("Failed in create ActiveDevice Event\n");
        return;
    }
	event_add(ev, &tv);
    act_dev->act_dev_event = ev;
    printf("ActiveDevice Event Created\n");
}

int main()
{
    act_dev_t       act_dev;

    event_init();
    evbase = event_base_new();
    if (NULL == evbase) {
        printf("Failed in create of evbase\n");
        return -1;
    }

    init_active_device(&act_dev);
    printf("main: init-act-dev is done\n");
    event_base_dispatch(evbase);
    printf("main: event-base disptached\n");
    //pthread_join(act_dev.mbim_priv.read_tid, NULL);
}
