
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
	{ .elemty = 0, .print = 0, .i = 32 },
	{ .elemty = 0, .print = 0, .i = 32 },
	{ .elemty = 0, .print = 0, .i = 64 },
	{ .elemty = 0, .print = 0, .i = 16 },
	{ .elemty = 1, .print = 1, .f = 238.11451143551605 },
	{ .elemty = 2, .print = 1, .d = -9.060400 },
	{ .elemty = 1, .print = 1, .f = -92.6760051616203 },
	{ .elemty = 2, .print = 1, .d = 11.028901 },
	{ .elemty = 1, .print = 1, .f = 235.61953826826752 },
	{ .elemty = 2, .print = 1, .d = 0.000000 },
	{ .elemty = 1, .print = 1, .f = -282.68052807222034 },
	{ .elemty = 2, .print = 1, .d = -16.197678 },
	{ .elemty = 1, .print = 1, .f = -22.078441277602316 },
	{ .elemty = 2, .print = 1, .d = -5.568604 },
	{ .elemty = 1, .print = 1, .f = -400.3391921739955 },
	{ .elemty = 2, .print = 1, .d = 0.000000 },
	{ .elemty = 1, .print = 1, .f = 86.78670646747543 },
	{ .elemty = 2, .print = 1, .d = -1.551978 },
	{ .elemty = 1, .print = 1, .f = -253.2879819572715 },
	{ .elemty = 2, .print = 1, .d = -11.149355 },
	{ .elemty = 1, .print = 1, .f = 97.0590771603132 },
	{ .elemty = 2, .print = 1, .d = 1.849801 },
	{ .elemty = 1, .print = 1, .f = -509.53122101407297 },
	{ .elemty = 2, .print = 1, .d = -5.097127 },
	{ .elemty = 1, .print = 1, .f = 138.51975972937868 },
	{ .elemty = 2, .print = 1, .d = 3.047543 },
	{ .elemty = 1, .print = 1, .f = -81.058098494148 },
	{ .elemty = 2, .print = 1, .d = 32.924064 },
	{ .elemty = 1, .print = 1, .f = 48.93275456781927 },
	{ .elemty = 2, .print = 1, .d = 7.440886 },
	{ .elemty = 1, .print = 1, .f = 116.84478411284229 },
	{ .elemty = 2, .print = 1, .d = 5.035644 },
	{ .elemty = 1, .print = 1, .f = 13.537291548278716 },
	{ .elemty = 2, .print = 1, .d = -7.997801 },
	{ .elemty = 1, .print = 1, .f = 16.677563935467813 },
	{ .elemty = 2, .print = 1, .d = 0.000000 },

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
