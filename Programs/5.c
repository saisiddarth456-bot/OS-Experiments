#include <stdio.h>
#include <threads.h>
int seats, readers = 0, r_cnt, w_cnt;
mtx_t m;
cnd_t cv;
int read_db(void *id) {
 mtx_lock(&m);
 readers++;
 int available = seats;
 mtx_unlock(&m);
 printf("Passenger %d sees %d seats\n",
 *(int *)id, available);
 mtx_lock(&m);
 if (--readers == 0)
 cnd_signal(&cv);
 mtx_unlock(&m);
 return 0;
}
int write_db(void *id) {
 mtx_lock(&m);
 while (readers > 0)
 cnd_wait(&cv, &m);
 if (seats > 0)
 printf("Booking %d -> Seats remaining: %d\n",
 *(int *)id, --seats);
 else
 printf("Booking %d -> No seats available\n",
 *(int *)id);
 mtx_unlock(&m);
return 0;
}
int main() {
 printf("Seats, Readers, Writers: ");
 if (scanf("%d %d %d", &seats, &r_cnt, &w_cnt) != 3 ||
 seats < 0 || r_cnt < 0 || w_cnt < 0 ||
 r_cnt + w_cnt > 100)
 return 1;
 mtx_init(&m, mtx_plain);
 cnd_init(&cv);
 thrd_t t[100];
 int ids[100], n = 0;
 for (int i = 0; i < r_cnt || i < w_cnt; i++) {
 if (i < r_cnt) {
 ids[n] = i + 1;
 thrd_create(&t[n], read_db, &ids[n]);
 n++;
 }
 if (i < w_cnt) {
 ids[n] = i + 1;
 thrd_create(&t[n], write_db, &ids[n]);
 n++;
 }
 }
 for (int i = 0; i < n; i++)
 thrd_join(t[i], NULL);
 cnd_destroy(&cv);
 mtx_destroy(&m);
 return 0;
}
