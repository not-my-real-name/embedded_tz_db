#include "zones.h"

typedef struct {
  const char *name;
  const char *posix_str;
} micro_tz_db_pair;

//! Declaration goes here!

/**
 * Basically strcmp, but accounting for spaces that have become underscores
 * @param[in] target - the 0-terminated string on the left hand side of the comparison
 * @param[in] other - the 0-terminated string on the right hand side of the comparison
 * @return > 0 if target comes before other alphabetically,
 *         ==0 if they're the same,
 *         < 0 if other comes before target alphabetically
 *         (we don't expect NULL arguments, but, -1 if either is NULL)
 **/
static int tz_name_cmp(const char * target, const char * other) {
  if (!target || !other) {
    return -1;
  }

  while (*target) {
    if (*target != *other) {
      break;
    }
    target++;
    other++;
  }

  char true_target = *target == '_' ? '\0' : *target;
  char true_other = *other == '_' ? '\0' : *other;

  return true_target - true_other;
}

const char *micro_tz_db_get_posix_str(const char *name) {
  int lo = 0, hi = sizeof(micro_tz_db_tzs) / sizeof(micro_tz_db_pair);
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    const char * mid_name = micro_tz_db_tzs[mid].name;
    int comparison = tz_name_cmp(name, mid_name);
    if (comparison == 0) {
      return mid_name;
    } else if (comparison < 0) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return NULL;
}