#ifndef _TOOL_H
#define _TOOL_H

/*
*在std中已经包含了min与max对象

#ifndef _MAX
#define _MAX
struct Max
{
    public:
        template <typename T>
        T operator() (T  x , T y){
            return (
                (x>y)?
                    x :
                    y
            );
        }
};
Max max ;
#endif

#ifndef _MIN
#define _MIN
struct Min{
    public :
        template <typename T>
        T operator() (T x , T y){
            return (
                (x < y)?
                        x :
                        y
            );
        }
};
Min min ;
#endif
*/


#ifndef _EQUAL
#define _EQUAL
struct EQUAL{
    template <typename T>
    bool operator() (const T& x ,const T& y){
        return (
            (bool) (x == y)
        );
    }
};
/*
*std中有equal了，且参数列表不同...
Equal equal ;
*/
EQUAL Equal ;

#endif


#endif