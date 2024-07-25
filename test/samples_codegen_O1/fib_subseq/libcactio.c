
#include "stdint.h"
#include "stdio.h"
#include "math.h"

uint32_t next;
uint64_t start_time, start_cycle, start_instnum;

struct ioval {
    uint8_t elemty : 2;
    uint8_t print  : 1;
    union {
        int i;
        float f;
        double d;
    };
};

struct ioval iovals[] = {
	{ .elemty = 0, .print = 0, .i = 153 },
	{ .elemty = 0, .print = 1, .i = 7 },

};

void timer_check(){
    uint64_t time, cycle, instnum; 
    int is_end = ( (sizeof(iovals) / sizeof(struct ioval)) == (next+1) );

    if( (0 == next) || is_end ){
        asm("rdcycle %0\n\t"
            : "=r"(cycle) );
        asm("rdtime %0\n\t"
            : "=r"(time) );
        asm("rdinstret %0\n\t"
            : "=r"(instnum) );

        if( is_end ){
            printf("Execution Success! [%lu]time [%lu]kInsts [%lu]kCycles\n", 
                ((time - start_time) >> 10), ((instnum - start_instnum) >> 10), ((cycle - start_cycle) >> 10) );
        } else {
            start_time    = time;
            start_cycle   = cycle;
            start_instnum = instnum;
        }
    }
}

void dump_error(){
    printf("wrong IO: expect ");
    if( iovals[next].print ){
        printf("print ");
    } else {
        printf("get ");
    }

    if( 0 == iovals[next].elemty ){
        printf("int %d , ", iovals[next].i);
    } else
    if( 1 == iovals[next].elemty ){
        printf("float %f , ", iovals[next].f);
    } else
    if( 2 == iovals[next].elemty ){
        printf("double %f , ", iovals[next].d);
    } else {
        if( iovals[next].i ){
            printf("bool true, ");
        } else {
            printf("bool false, ");
        }
    }
}

void print_int(int i){
    if( (0 == iovals[next].elemty) || (1 == iovals[next].print) || (i == iovals[next].i) ){
        timer_check();
    } else {
        dump_error();
        printf("found print int %d\n", iovals[next].i);
    }
    next ++;
}

void print_float(float fl){
    float diff;
    if( (1 == iovals[next].elemty) || (1 == iovals[next].print) ){
        diff = fl - iovals[next].f;
        if( diff < 0 ){
            diff = -diff;
        }

        if( diff < 1e-2 ){
            timer_check();
        } else {
            printf("float accuracy not met: expected %f, found %f\n", iovals[next].f, fl);
        }
    } else {
        dump_error();
        printf("found print float %f\n", iovals[next].f);
    }
    next ++;
}

void print_double(double d){
    float diff;
    if( (2 == iovals[next].elemty) || (1 == iovals[next].print) ){
        diff = fabs(d - iovals[next].d);
        if( diff < 1e-4 ){
            timer_check();
        } else {
            printf("double accuracy not met: expected %f, found %f\n", iovals[next].d, d);
        }
    } else {
        dump_error();
        printf("found print double %f\n", iovals[next].d);
    }
    next ++;
}

void print_bool(int b){
    if( (3 == iovals[next].elemty) || (1 == iovals[next].print) || (b == iovals[next].i) ){
        timer_check();
    } else {
        dump_error();
        if( b ){
            printf("found print bool true\n");
        } else {
            printf("found print bool false\n");
        }
    }
    next ++;
}

int get_int(){
    int ret = iovals[next].i;
    if( (0 == iovals[next].elemty) && (0 == iovals[next].print) ){
        timer_check();
        next ++;
        return ret;
    } else {
        dump_error();
        printf("found get int %d.\n", ret);
    }
    next ++;
    return 0;
}

float get_float(){
    float ret = iovals[next].f;
    if( (1 == iovals[next].elemty) && (0 == iovals[next].print) ){
        timer_check();
        next ++;
        return ret;
    } else {
        dump_error();
        printf("found get float %f.\n", ret);
    }
    next ++;
    return 0.0f;
}

double get_double(){
    double ret = iovals[next].d;
    if( (2 == iovals[next].elemty) && (0 == iovals[next].print) ){
        timer_check();
        next ++;
        return ret;
    } else {
        dump_error();
        printf("found get double %f.\n", ret);
    }
    next ++;
    return 0.0;   
}
