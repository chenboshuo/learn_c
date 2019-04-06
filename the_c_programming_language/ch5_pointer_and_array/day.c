/**
 * 把某年某月某日这种日期表示形式转换为某年中第几天的表示形式.
 * 例如3.1是非闰年的第60 天, 是闰年的61 天.
 * 在这里, 我们定义两个函数进行日期转换,同时用到一张记录每月天数的表,
 * 对于闰年与非闰年来说, 每个月天数不同,
 * 所以把这些天数放到二维数组中比较判断2月有多少天更容易.
 */
#include <stdio.h>

static char daytab[2][13] ={
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/**
 * 将日期表示转化为某年的天数表示
 * @param  year  年份
 * @param  month 月份
 * @param  day   天
 * @return       这一年的第几天
 */
int day_of_year(int year, int month, int day) {
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for( i = 1; i < month; ++i){
    day += daytab[leap][i];
  }
  return day;
}

/**
 * 将某年中的第几天的日期表示形式转化为某月某日的表示形式
 * @param year    年
 * @param yearday 第几天
 * @param pmonth  指向月份的指针
 * @param pday    指向年的指针
 */
void mouth_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for( i = 1; yearday > daytab[leap][i]; ++i){
    yearday -= daytab[leap][i];
  }
  *pmonth = i;
  *pday = yearday;
}

int main(int argc, char const *argv[]) {
  printf("%d\n", day_of_year(2000,12,31));
  int m,d;
  mouth_day(2000,365,&m,&d);
  printf("%d %d\n", m, d);
  return 0;
}
/**
 * output
 * 366
 * 12 30
 */
