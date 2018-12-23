#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

/* 莉雁屓縺ｮ險ｭ螳壹ｒ讒矩�菴薙〒險倩ｿｰ*/
struct condition
{
  int width;
  int height;
  double G; // gravity constant
};

struct star
{
  double m;   // mass
  double x;   // position_x
  double vx;  // velocity_x
};

struct star stars[] = {
  { 1.0, -10.0, 0.0 },
  { 0.5,  10.0, 0.2 }
};

const int nstars = sizeof(stars) / sizeof(struct star);

void plot_stars(FILE *fp, const double t,struct condition cond)
{
  int width = cond.width;
  int height = cond.height;
  char space[width][height];

  memset(space, ' ', sizeof(space));
  for (int i = 0; i < nstars; i++) {
    const int x = width  / 2 + stars[i].x;
    const int y = height / 2;
    if (x < 0 || x >= width)  continue;
    if (y < 0 || y >= height) continue;
    char c = (stars[i].m >= 1.0)?'O':'o'; // 雉ｪ驥上′螟ｧ縺阪＞蝣ｴ蜷医�陦ｨ遉ｺ繧貞､峨∴繧�
    space[x][y] = c;
  }

  fprintf(fp, "----------\n");
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++)
      fputc(space[x][y], fp);
    fputc('\n', fp);
  }
  fflush(fp);

  printf("t = %5.1f", t);
  for (int i = 0; i < nstars; i++)
    printf(", stars[%d].x = %7.2f", i, stars[i].x);
  printf("\n");
}

void update_velocities(const double dt,struct condition cond)
{
  int i, j;
  for (i = 0; i < nstars; i++) {
    double ax = 0;



    stars[i].vx += ax * dt;
  }
}

void update_positions(const double dt)
{
  for (int i = 0; i < nstars; i++) {
    stars[i].x += stars[i].vx * dt;
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

  double t = 0.;
  for (int i = 0; t <= stop_time; i++) {
    t = i * dt;
    update_velocities(dt,cond);
    update_positions(dt);
    if (i % 10 == 0) {
      plot_stars(fp, t, cond);
      usleep(200 * 1000);
    }
  }

  fclose(fp);

  return 0;
}
