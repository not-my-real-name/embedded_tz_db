#include <stdio.h>
#include "embedded_tz_db.h"

//! Declaration goes here!

/**
 * Convert to a safe char representation. Ignore case and spaces.
 **/
static char safeChar(char c) {
  if(c == ' ') return '_';
  if((c >= 'A') && (c <= 'Z')) return c | 0x20;
  return c;
}

/** 
 * Create an 8 bit hash of the timezone name. 
 * Timezones are not in alphabetical order so the hash table is used to make lookups faster.
 **/
static unsigned char createHash(const char * name){
  unsigned char hash = 0;
  while(*name != '\0'){
    hash += safeChar(*(name++));
  }
  return hash;
}

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
    if (safeChar(*target) != safeChar(*other)) {
      break;
    }
    target++;
    other++;
  }
  return safeChar(*target) - safeChar(*other);
}


const char *tz_db_get_posix_str(const char *name) {
  unsigned char hash = createHash(name);
  
  for(int i = 0; i < sizeof(embedded_tz_db_hashTable); i ++){
    if(embedded_tz_db_hashTable[i] == hash){
      // Also do string comparison to check for hash collisions. 
      if(tz_name_cmp(name, embedded_tz_db_zones[i].name) == 0){
        return embedded_tz_db_zones[i].rule;
      }
    }
  }
  return NULL;
}

const char * tz_db_get_version(){
  return TZ_DATA_VERS;
}

const embeddedTz_t * tz_db_get_all_zones(){
  return embedded_tz_db_zones;
}