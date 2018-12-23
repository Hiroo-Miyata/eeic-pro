#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

struct condition
{
  int width;
  int height;
  double G; // gravity constant
  double fusion_distance;
};

struct star
{
    double m;     // mass
    double x;     // position_x
    double y;     // position_y
    double vx;    // velocity_x
    double vy;    // velocity_y
    int alive;
};

struct star stars[] = {
  { 1.0, -10.0, 10.0, 0.0, 0.0, 1 },
  { 0.5, 10.0, -10.0, 0.1, 0.1, 1 },
  { 0.0, 0, 0, 0.1, -0.1, 1 }
};

const int nstars = sizeof(stars) / sizeof(struct star);

void plot_stars(FILE *fp, const double t,struct condition cond)
{
  int width = cond.width;
  int height = cond.height;
  char space[width][height];

  memset(space, ' ', sizeof(space));
  for (int i = 0; i < nstars; i++) {
      if ( stars[i].alive == 1) {
        const int x = width  / 2  + stars[i].x;
        const int y = height / 2 + stars[i].y;
        if (x < 0 || x >= width)  continue;
        if (y < 0 || y >= height) continue;
        char c = (stars[i].m >= 1.0)?'O':'o'; // 雉ｪ驥上′螟ｧ縺阪＞蝣ｴ蜷医�陦ｨ遉ｺ繧貞､峨∴繧�
        space[x][y] = c;
      }
  }

  fprintf(fp, "----------\n");
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++)
      fputc(space[x][y], fp);
    fputc('\n', fp);
  }
  fflush(fp);

  printf("t = %5.1f", t);
  for (int i = 0; i < nstars; i++) {
    if (stars[i].alive == 1) {
        printf(", stars[%d].x = %7.2f", i, stars[i].x);
    } else {
        printf(", stars[%d].x = fusioned", i);
    }
  }
  printf("\n");
}

void update_velocities(const double dt,struct condition cond)
{
  int i, j;
  for (i = 0; i < nstars; i++) {
      if (stars[i].alive == 0) {
          continue;
      }
      double ax = 0;
      double ay = 0;
      for (j = 0; j < nstars; j ++) {
          if (stars[i].alive == 0 || j == i) {
              continue;
          } else {
              double distance = sqrt(pow(stars[j].x - stars[i].x, 2) + pow(stars[j].y - stars[i].y, 2));
              if (distance < cond.fusion_distance) {
                  stars[j].alive = 0;
                  stars[i].vx = (stars[i].m * stars[i].vx + stars[j].m * stars[j].vx) / (stars[i].m + stars[j].m);
                  stars[i].vy = (stars[i].m * stars[i].vy + stars[j].m * stars[j].vy) / (stars[i].m + stars[j].m);
                  stars[i].m = stars[i].m + stars[j].m;
                  return;
              } else {
                  ax += cond.G * stars[j].m / pow(distance, 3) * (stars[j].x - stars[i].x);
                  ay += cond.G * stars[j].m / pow(distance, 3) * (stars[j].y - stars[i].y);
              }
          }
      }
      stars[i].vx += ax * dt;
      stars[i].vy += ay * dt;
  }
}

void update_positions(const double dt)
{
  for (int i = 0; i < nstars; i++) {
    stars[i].x += stars[i].vx * dt;
    stars[i].y += stars[i].vy * dt;
  }
}

int main()
{
  const char *filename = "space.txt";
  FILE *fp;
  if ((fp = fopen(filename, "a")) == NULL) {
    fprintf(stderr, "error: cannot open %s.\n", filename);
    return 1;
  }

  const double dt = 1.0;
  const double stop_time = 400;

  struct condition cond;
  cond.height = 40;
  cond.width = 75;
  cond.G = 1.0;
  cond.fusion_distance = 10.0;

  int i;
  double t;
  for (i = 0, t = 0; t <= stop_time; i++, t += dt) {
      update_velocities(dt, cond);
      update_positions(dt);
      if (i % 10 == 0) {
          plot_stars(fp, t, cond);
          usleep(500 * 1000);
      }
  }

  fclose(fp);

  return 0;
}
