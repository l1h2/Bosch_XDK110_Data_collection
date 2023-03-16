#include "time_to_date.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SECONDS_IN_DAY = 86400;
const int DAYS_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int* create_time_array(float time_in_day, int base_year) {
    static int time_in_month[12];

    for(int i = 0; i < 12; i++) {
    	time_in_month[i] = DAYS_IN_MONTH[i] * time_in_day;
    }

	if(base_year % 4 == 0) {
		time_in_month[1] += time_in_day;
	}
	return time_in_month;
}


char* time_to_str(int time) {
	const int length = snprintf(NULL, 0, "%d", time);
    char* time_str = malloc(length + 1);

    if (time < 10) {
        time_str[0] = '0';
        time_str[1] = time + '0';
    } else {
		snprintf(time_str, length + 1, "%d", time);
    }
    return time_str;
}


char* get_milliseconds(int time, int length) {
    char* time_str = malloc(length + 1);

    if(time < 10) {
        time_str[0] = '0';
        time_str[1] = '0';
        time_str[2] = time + '0';
    } else if(time < 100) {
    	time_str[0] = '0';
    	const int first_digit = time / 10;
        time_str[1] = first_digit + '0';
        const int last_digit = time - first_digit * 10;
        time_str[2] = last_digit + '0';
    } else {
    	snprintf(time_str, length + 1, "%d", time);
    }
    return time_str;
}


char* get_fraction(int time, float time_in_second) {
	if(time <= 1) {
		return "N/A";
	}

	const int length = snprintf(NULL, 0, "%d", time);
	char* time_str = malloc(length + 1);

	if(time_in_second <= 10) {
        time_str[0] = time + '0';
        time_str[1] = '0';
	} else if(time_in_second <= 100) {
		char* temp_str = time_to_str(time);
		strcpy(time_str, temp_str);
	} else if(time_in_second <= 1000) {
		char* temp_str = get_milliseconds(time, length);
		strcpy(time_str, temp_str);
	} else {
		printf("Invalid time interval selected, please reconfigure and try again.");
	}
    return time_str;
}


char* get_date(unsigned int ref_time, float time_in_day, int month, int year, float time_in_second) {

    const float full_day = (float) ref_time / time_in_day + 1;
    const int day = full_day;
    const float full_hour = (full_day - day) * 24;
    const int hour = full_hour;
    const float full_min = (full_hour - hour) * 60;
    const int min = full_min;
    const float full_sec = (full_min - min) * 60;
    const int sec = full_sec;

    char* year_str = time_to_str(year);
    char* month_str = time_to_str(month + 1);
	char* day_str = time_to_str(day);
    char* hour_str = time_to_str(hour);
    char* min_str = time_to_str(min);
    char* sec_str = time_to_str(sec);

    const int timestamp_size = 25;
    char* timestamp = malloc(timestamp_size);
    snprintf(timestamp, timestamp_size, "%s/%s/%s %s:%s:%s", day_str, month_str, year_str, hour_str, min_str, sec_str);

    if(time_in_second > 1) {
    	const int fraction = (full_sec - sec) * time_in_second;
    	char* fraction_str = get_fraction(fraction, time_in_second);
    	strcat(strcat(timestamp, ":"), fraction_str);
    }
    return timestamp;
}


char* timeToDate(unsigned int ref_time, int base_month, int base_year, float time_in_second) {
	const float time_in_day = SECONDS_IN_DAY * time_in_second;
    int *time_in_month = create_time_array(time_in_day, base_year);
    int month = base_month - 1;
    unsigned int ref_month = time_in_month[month];
    int year = base_year;

    do {
    	if(ref_time >= ref_month) {
			ref_time -= time_in_month[month];
			month++;

            if(month == 12) {
                month = 0;
                year++;

                time_in_month[1] = DAYS_IN_MONTH[1] * time_in_day;
                if(year % 4 == 0) {
                    time_in_month[1] += time_in_day;
                }
            }
			ref_month = time_in_month[month];
    	}
    }
    while(ref_time > ref_month);

    char *timestamp = get_date(ref_time, time_in_day, month, year, time_in_second);

    return timestamp;
}
