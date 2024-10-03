#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int hour;
    int min;
    int sec;
} time;

time* createTime(int hour, int min, int sec);
time* readTime();
int validateTime(int hour, int min, int sec);
void showTime(time *t);
void incrementTime(time *t);
void decrementTime(time *t);
time* secToTime(int s);
int timeToSec(time *t);
time* timediffe(time *t1, time *t2);

int main() {
    
    time *t1, *t2, *t3;

    t1 = createTime(0, 30, 24);
    t2 = readTime();
    t3 = t2;

    printf("Horario 1: ");
    showTime(t1);
    printf("Horario 2: ");
    showTime(t2);
    printf("Horario 3: ");
    showTime(t3);
    printf("\n");

    incrementTime(t1);
    incrementTime(t2);

    printf("Horario 1 apos incremento: ");
    showTime(t1);
    printf("Horario 2 apos incremento: ");
    showTime(t2);
    printf("Horario 3 apos incremento no horario 2: ");
    showTime(t3);
    printf("\n");

    printf("Diferenca entre horario 1 e horario 3: ");
    showTime(timediffe(t1, t3));
    printf("\n");

    return 0;
}

time* createTime(int hour, int min, int sec) {
    time *t = (time *)malloc(sizeof(time));
    t->hour = hour;
    t->min = min;
    t->sec = sec;
    return t;
}

time* readTime() {
    int hour, min, sec;
    printf("Insira as horas: ");
    scanf("%d", &hour);
    printf("Insira os minutos: ");
    scanf("%d", &min);
    printf("Insira os segundos: ");
    scanf("%d", &sec);

    if(validateTime(hour, sec, min) == 1) {
        return createTime(hour, min, sec);
    } else {
        return NULL;
    };

    
}

int validateTime(int hour, int min, int sec) {
    if ((hour < 0 || hour > 24) || ((min || sec) < 0 || (min || sec) > 60)) return 0;
    else return 1;
}

void showTime(time *t) {
    printf("%2dh %2dm %2ds\n", t->hour, t->min, t->sec);
}

void incrementTime(time *t) {
    if (t->sec == 59) {
        t->sec = 0;
        if (t->min == 59) {
            t->min = 0;
            t->hour += 1;
        } else {
            t->min += 1;
        }
    } else {
        t->sec += 1;
    }
}

void decrementTime(time *t) {
    if (t->sec == 0) {
        t->sec = 59;
        if (t->min == 0) {
            t->min = 59;
            t->hour -= 1;
        } else {
            t->min -= 1;
        }
    } else {
        t->sec -= 1;
    }
}

int timeToSec(time *t) {
    return t->hour * 3600 + t->min * 60 + t->sec;
}

time* secToTime(int s) {
    int h, m;
    h = s / 3600;
    s = s % 3600;
    m = s / 60;
    s = s % 60;
    return createTime(h, m, s % 60);
}

time* timediffe(time *t1, time *t2) {
    int v1, v2;

    v1 = timeToSec(t1);
    v2 = timeToSec(t2);

    if (v1 > v2) return secToTime(v1 - v2);
    else return secToTime(v2 - v1);

}