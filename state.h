#ifndef _STATE_H
#define _STATE_H

    #ifndef     OK
    #define     OK           1
    #endif

    #ifndef     ERROR       
    #define     ERROR        0
    #endif

    #ifndef     INFEASIBLE  
    #define     INFEASIBEL  -1
    #endif

    #ifndef     OVERFLOW
    #define     OVERFLOW    -2
    #endif


    #ifndef     Status
        typedef int Status;
    #endif

    //useful tools  
    #define SWAP(T, a, b)   do{ T tmp = (a); (a) = (b); (b) = tmp; } while (0)
#endif
