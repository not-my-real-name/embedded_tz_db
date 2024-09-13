#include <stdio.h>
#include "embedded_tz_db.h"

static const char * TZ_DATA_VERS = "2024b-2";

static const embeddedTz_t embedded_tz_db_zones[90] = {
  {"Pacific/Pago_Pago", "SST11"},
  {"Pacific/Niue", "<-11>11"},
  {"Pacific/Honolulu", "HST10"},
  {"Pacific/Tahiti", "<-10>10"},
  {"America/Adak", "HST10HDT,M3.2.0,M11.1.0"},
  {"Pacific/Marquesas", "<-0930>9:30"},
  {"Pacific/Gambier", "<-09>9"},
  {"America/Anchorage", "AKST9AKDT,M3.2.0,M11.1.0"},
  {"Pacific/Pitcairn", "<-08>8"},
  {"America/Los_Angeles", "PST8PDT,M3.2.0,M11.1.0"},
  {"America/Phoenix", "MST7"},
  {"America/Denver", "MST7MDT,M3.2.0,M11.1.0"},
  {"Pacific/Galapagos", "<-06>6"},
  {"America/Mexico_City", "CST6"},
  {"Pacific/Easter", "<-06>6<-05>,M9.1.6/22,M4.1.6/22"},
  {"America/Chicago", "CST6CDT,M3.2.0,M11.1.0"},
  {"America/Lima", "<-05>5"},
  {"America/Jamaica", "EST5"},
  {"America/Havana", "CST5CDT,M3.2.0/0,M11.1.0/1"},
  {"America/New_York", "EST5EDT,M3.2.0,M11.1.0"},
  {"America/Caracas", "<-04>4"},
  {"America/Santo_Domingo", "AST4"},
  {"America/Santiago", "<-04>4<-03>,M9.1.6/24,M4.1.6/24"},
  {"America/Asuncion", "<-04>4<-03>,M10.1.0/0,M3.4.0/0"},
  {"America/Halifax", "AST4ADT,M3.2.0,M11.1.0"},
  {"America/St_Johns", "NST3:30NDT,M3.2.0,M11.1.0"},
  {"America/Sao_Paulo", "<-03>3"},
  {"America/Miquelon", "<-03>3<-02>,M3.2.0,M11.1.0"},
  {"America/Noronha", "<-02>2"},
  {"America/Nuuk", "<-02>2<-01>,M3.5.0/-1,M10.5.0/0"},
  {"Atlantic/Cape_Verde", "<-01>1"},
  {"Atlantic/Azores", "<-01>1<+00>,M3.5.0/0,M10.5.0/1"},
  {"Africa/Abidjan", "GMT0"},
  {"Europe/London", "GMT0BST,M3.5.0/1,M10.5.0"},
  {"Europe/Lisbon", "WET0WEST,M3.5.0/1,M10.5.0"},
  {"Antarctica/Troll", "<+00>0<+02>-2,M3.5.0/1,M10.5.0/3"},
  {"Africa/Algiers", "CET-1"},
  {"Africa/Lagos", "WAT-1"},
  {"Europe/Dublin", "IST-1GMT0,M10.5.0,M3.5.0/1"},
  {"Africa/Casablanca", "<+01>-1"},
  {"Europe/Paris", "CET-1CEST,M3.5.0,M10.5.0/3"},
  {"Africa/Maputo", "CAT-2"},
  {"Africa/Tripoli", "EET-2"},
  {"Africa/Johannesburg", "SAST-2"},
  {"Europe/Athens", "EET-2EEST,M3.5.0/3,M10.5.0/4"},
  {"Africa/Cairo", "EET-2EEST,M4.5.5/0,M10.5.4/24"},
  {"Asia/Beirut", "EET-2EEST,M3.5.0/0,M10.5.0/0"},
  {"Europe/Chisinau", "EET-2EEST,M3.5.0,M10.5.0/3"},
  {"Asia/Gaza", "EET-2EEST,M3.4.4/50,M10.4.4/50"},
  {"Asia/Jerusalem", "IST-2IDT,M3.4.4/26,M10.5.0"},
  {"Europe/Istanbul", "<+03>-3"},
  {"Africa/Nairobi", "EAT-3"},
  {"Europe/Moscow", "MSK-3"},
  {"Asia/Tehran", "<+0330>-3:30"},
  {"Asia/Dubai", "<+04>-4"},
  {"Asia/Kabul", "<+0430>-4:30"},
  {"Asia/Tashkent", "<+05>-5"},
  {"Asia/Karachi", "PKT-5"},
  {"Asia/Colombo", "<+0530>-5:30"},
  {"Asia/Kolkata", "IST-5:30"},
  {"Asia/Kathmandu", "<+0545>-5:45"},
  {"Asia/Dhaka", "<+06>-6"},
  {"Asia/Yangon", "<+0630>-6:30"},
  {"Asia/Bangkok", "<+07>-7"},
  {"Asia/Jakarta", "WIB-7"},
  {"Asia/Singapore", "<+08>-8"},
  {"Australia/Perth", "AWST-8"},
  {"Asia/Shanghai", "CST-8"},
  {"Asia/Hong_Kong", "HKT-8"},
  {"Asia/Manila", "PST-8"},
  {"Asia/Makassar", "WITA-8"},
  {"Australia/Eucla", "<+0845>-8:45"},
  {"Asia/Chita", "<+09>-9"},
  {"Asia/Tokyo", "JST-9"},
  {"Asia/Seoul", "KST-9"},
  {"Asia/Jayapura", "WIT-9"},
  {"Australia/Darwin", "ACST-9:30"},
  {"Australia/Adelaide", "ACST-9:30ACDT,M10.1.0,M4.1.0/3"},
  {"Asia/Vladivostok", "<+10>-10"},
  {"Australia/Brisbane", "AEST-10"},
  {"Pacific/Guam", "ChST-10"},
  {"Australia/Sydney", "AEST-10AEDT,M10.1.0,M4.1.0/3"},
  {"Australia/Lord_Howe", "<+1030>-10:30<+11>-11,M10.1.0,M4.1.0"},
  {"Pacific/Bougainville", "<+11>-11"},
  {"Pacific/Norfolk", "<+11>-11<+12>,M10.1.0,M4.1.0/3"},
  {"Asia/Kamchatka", "<+12>-12"},
  {"Pacific/Auckland", "NZST-12NZDT,M9.5.0,M4.1.0/3"},
  {"Pacific/Chatham", "<+1245>-12:45<+1345>,M9.5.0/2:45,M4.1.0/3:45"},
  {"Pacific/Tongatapu", "<+13>-13"},
  {"Pacific/Kiritimati", "<+14>-14"}
};

/** This hash table allows for faster lookup of the timezone names. Timezones are not in alphabetical order. 
 *  Timezone names are converted to lower case and then summed. The 8 bit sum is stored here.
 **/
static const unsigned char embedded_tz_db_hashTable[90] = {
  171,
  175,
  116,
  129,
  146,
  208,
  213,
  169,
  88,
  141,
  252,
  133,
  173,
  158,
  130,
  207,
  164,
  199,
  112,
  111,
  207,
  114,
  87,
  97,
  222,
  105,
  196,
  107,
  246,
  196,
  141,
  19,
  94,
  73,
  70,
  118,
  124,
  171,
  61,
  142,
  222,
  43,
  152,
  155,
  66,
  163,
  88,
  19,
  112,
  149,
  33,
  121,
  87,
  79,
  210,
  220,
  47,
  160,
  184,
  180,
  138,
  198,
  89,
  170,
  171,
  149,
  24,
  16,
  135,
  63,
  32,
  255,
  214,
  3,
  245,
  42,
  122,
  30,
  131,
  59,
  168,
  145,
  184,
  255,
  249,
  114,
  65,
  212,
  209,
  53
};

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