#include <stdio.h>

#define XMAX 20
#define YMAX 20

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))  // comment
struct point {
  int x;
  int y;
};
struct rect {
  struct point pt1;
  struct point pt2;
};

int main(int argc, char const *argv[]) {
  struct rect screen;
  struct point middle;
  struct point makepoint(int x, int y);

  screen.pt1 = makepoint(0, 0);
  screen.pt2 = makepoint(XMAX, YMAX);
  middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
                     (screen.pt1.y + screen.pt2.y) / 2);

  struct point origan = { 1, 5 }, *pp;

  pp = &origan;
  printf("origan is (%d,%d)", (*pp).x, pp->y);

  // 下面的表达式等价
  struct rect r, *rp = &r;
  r.pt1.x;
  rp->pt1.x;
  (r.pt1).x;

  // 运算符的优先级

  return 0;
}

// makepoint函数: 通过x,y坐标构造一个点
struct point makepoint(int x, int y) {
  struct point temp;

  temp.x = x;
  temp.y = y;
  return temp;
}

// addpoint 函数: 将两个点相加
struct point addpoint(struct point p1, struct point p2) {
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
}

/**
 *  pt_in_rect 函数: 如果p在矩形r内,返回1, 否则返回0
 *  约定: 矩形包括其左侧边和底边, 不包括顶边和右侧边.
 */
int pt_in_rect(struct point p, struct rect r) {
  return p.x >= r.pt1.x && p.x <= r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

struct rect canonrect(struct rect r) {
  struct rect temp;

  temp.pt1.x = min(r.pt1.x, r.pt2.x);
  temp.pt1.y = min(r.pt1.y, r.pt2.y);
  temp.pt1.x = max(r.pt1.x, r.pt2.x);
  temp.pt1.y = max(r.pt1.y, r.pt2.y);
  return temp;
}
