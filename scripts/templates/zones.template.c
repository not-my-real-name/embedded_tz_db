#include "zones.h"
#include <stdio.h>
#include <ctype.h>

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
    if (tolower(*target) != tolower(*other)) {
      break;
    }
    do {
      target++;
    } while (*target == '_');
    do {
      other++;
    } while (*other == '_');
  }

  return tolower(*target) - tolower(*other);
}

const char *micro_tz_db_get_posix_str(const char *name) {
  int lo = 0, hi = sizeof(micro_tz_db_tzs) / sizeof(micro_tz_db_pair);
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    micro_tz_db_pair mid_pair = micro_tz_db_tzs[mid];
    int comparison = tz_name_cmp(name, mid_pair.name);
    if (comparison == 0) {
      return mid_pair.posix_str;
    } else if (comparison < 0) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return NULL;
}