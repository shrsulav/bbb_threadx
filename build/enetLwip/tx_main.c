/*
 * tx_main.c
 *
 *  Created on: May 2, 2023
 *      Author: heisenberg
 */

#include "consoleUtils.h"
#include "systick.h"
#include "delay.h"
#include "tx_user.h"
#include "tx_api.h"
#include "tx_port.h"

TX_BYTE_POOL byte_pool_0;
TX_SEMAPHORE semaphore_0, semaphore_1;
TX_THREAD my_thread, my_thread_2;

void my_thread_entry(ULONG thread_input)
{
    UINT status;
    UINT thread_counter = 0;
    /* Enter into a forever loop. */

    while(1)
    {
        /* Get the semaphore with suspension. */
        status = tx_semaphore_get(&semaphore_0, TX_WAIT_FOREVER);

        /* Check status. */
        if (status != TX_SUCCESS) break;

        /* Increment thread counter. */
        thread_counter++;

        ConsoleUtilsPrintf("\r\nThread 1 Count: %d", thread_counter);

        tx_thread_sleep(200); // sleep for 2 seconds

        /* Release the semaphore. */
        status = tx_semaphore_put(&semaphore_1);

        /* Check status. */
        if (status != TX_SUCCESS) break;
    }
}

void my_thread_entry_2(ULONG thread_input)
{
    UINT status;
    UINT thread_counter = 0;

    /* Enter into a forever loop. */
    while(1)
    {
        /* Get the semaphore with suspension. */
        status = tx_semaphore_get(&semaphore_1, TX_WAIT_FOREVER);

        /* Check status. */
        if (status != TX_SUCCESS) break;

        /* Increment thread counter. */
        thread_counter++;

        ConsoleUtilsPrintf("\r\nThread 2 Count: %d", thread_counter);

        tx_thread_sleep(200); // sleep for 2 seconds

        /* Release the semaphore. */
        status = tx_semaphore_put(&semaphore_0);

        /* Check status. */
        if (status != TX_SUCCESS) break;
    }
}

void tx_application_define(void *first_unused_memory)
{
    CHAR *pointer;

    /* Create a byte memory pool from which to allocate the thread stacks. */
    tx_byte_pool_create(&byte_pool_0, "byte pool 0", first_unused_memory, 8192);

    /* Allocate the stack for thread 0. */
    tx_byte_allocate(&byte_pool_0, &pointer, 1024, TX_NO_WAIT);

    /* Create my_thread! */
    tx_thread_create(&my_thread, "My Thread",
                     my_thread_entry, 0x1234, pointer, 1024,
                     3, 3, TX_NO_TIME_SLICE, TX_AUTO_START);

    /* Allocate the stack for thread 1. */
    tx_byte_allocate(&byte_pool_0, &pointer, 1024, TX_NO_WAIT);

    /* Create my_thread! */
    tx_thread_create(&my_thread_2, "My Thread 2",
                     my_thread_entry_2, 0x1234, pointer, 1024,
                     3, 3, TX_NO_TIME_SLICE, TX_AUTO_START);

    /* Create the semaphore. */
    tx_semaphore_create(&semaphore_0, "semaphore 0", 1);

    /* Create the semaphore. */
    tx_semaphore_create(&semaphore_1, "semaphore 1", 0);

}

void tx_systick_handler_test(void)
{
    ConsoleUtilsPrintf("\r\nTimer is working\r\n");
}

void _tx_timer_interrupt(void);
void tx_systick_init(void)
{
    TimerTickConfigure(_tx_timer_interrupt);
    TimerTickPeriodSet(TX_SYSTICK_PERIOD_MS);
    TimerTickEnable();
}

void AintcSetUp(void);
void tx_prescheduler_init(void)
{
    AintcSetUp();
    DelayTimerSetup();
    tx_systick_init();
}


