#include "zones.h"
#include <string.h>

const char * posix_tz_db_get_posix_str(const char * name)
{
  const posix_tz_db_pair * pair = posix_tz_db_tzs;
  while (pair->name) {
    if (0 == strcmp(pair->name, name)) {
      return pair->posix_str;
    }
    pair++;
  }
  return NULL;
}

const posix_tz_db_pair posix_tz_db_tzs[460] = {
  {.name="Africa/Abidjan", .posix_str="GMT0"}, 
  {.name="Africa/Accra", .posix_str="GMT0"}, 
  {.name="Africa/Addis_Ababa", .posix_str="EAT-3"}, 
  {.name="Africa/Algiers", .posix_str="CET-1"}, 
  {.name="Africa/Asmara", .posix_str="EAT-3"}, 
  {.name="Africa/Bamako", .posix_str="GMT0"}, 
  {.name="Africa/Bangui", .posix_str="WAT-1"}, 
  {.name="Africa/Banjul", .posix_str="GMT0"}, 
  {.name="Africa/Bissau", .posix_str="GMT0"}, 
  {.name="Africa/Blantyre", .posix_str="CAT-2"}, 
  {.name="Africa/Brazzaville", .posix_str="WAT-1"}, 
  {.name="Africa/Bujumbura", .posix_str="CAT-2"}, 
  {.name="Africa/Cairo", .posix_str="EET-2"}, 
  {.name="Africa/Casablanca", .posix_str=""}, 
  {.name="Africa/Ceuta", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Africa/Conakry", .posix_str="GMT0"}, 
  {.name="Africa/Dakar", .posix_str="GMT0"}, 
  {.name="Africa/Dar_es_Salaam", .posix_str="EAT-3"}, 
  {.name="Africa/Djibouti", .posix_str="EAT-3"}, 
  {.name="Africa/Douala", .posix_str="WAT-1"}, 
  {.name="Africa/El_Aaiun", .posix_str=""}, 
  {.name="Africa/Freetown", .posix_str="GMT0"}, 
  {.name="Africa/Gaborone", .posix_str="CAT-2"}, 
  {.name="Africa/Harare", .posix_str="CAT-2"}, 
  {.name="Africa/Johannesburg", .posix_str="SAST-2"}, 
  {.name="Africa/Juba", .posix_str="EAT-3"}, 
  {.name="Africa/Kampala", .posix_str="EAT-3"}, 
  {.name="Africa/Khartoum", .posix_str="CAT-2"}, 
  {.name="Africa/Kigali", .posix_str="CAT-2"}, 
  {.name="Africa/Kinshasa", .posix_str="WAT-1"}, 
  {.name="Africa/Lagos", .posix_str="WAT-1"}, 
  {.name="Africa/Libreville", .posix_str="WAT-1"}, 
  {.name="Africa/Lome", .posix_str="GMT0"}, 
  {.name="Africa/Luanda", .posix_str="WAT-1"}, 
  {.name="Africa/Lubumbashi", .posix_str="CAT-2"}, 
  {.name="Africa/Lusaka", .posix_str="CAT-2"}, 
  {.name="Africa/Malabo", .posix_str="WAT-1"}, 
  {.name="Africa/Maputo", .posix_str="CAT-2"}, 
  {.name="Africa/Maseru", .posix_str="SAST-2"}, 
  {.name="Africa/Mbabane", .posix_str="SAST-2"}, 
  {.name="Africa/Mogadishu", .posix_str="EAT-3"}, 
  {.name="Africa/Monrovia", .posix_str="GMT0"}, 
  {.name="Africa/Nairobi", .posix_str="EAT-3"}, 
  {.name="Africa/Ndjamena", .posix_str="WAT-1"}, 
  {.name="Africa/Niamey", .posix_str="WAT-1"}, 
  {.name="Africa/Nouakchott", .posix_str="GMT0"}, 
  {.name="Africa/Ouagadougou", .posix_str="GMT0"}, 
  {.name="Africa/Porto-Novo", .posix_str="WAT-1"}, 
  {.name="Africa/Sao_Tome", .posix_str="GMT0"}, 
  {.name="Africa/Tripoli", .posix_str="EET-2"}, 
  {.name="Africa/Tunis", .posix_str="CET-1"}, 
  {.name="Africa/Windhoek", .posix_str="CAT-2"}, 
  {.name="America/Adak", .posix_str="HST10HDT,M3.2.0,M11.1.0"}, 
  {.name="America/Anchorage", .posix_str="AKST9AKDT,M3.2.0,M11.1.0"}, 
  {.name="America/Anguilla", .posix_str="AST4"}, 
  {.name="America/Antigua", .posix_str="AST4"}, 
  {.name="America/Araguaina", .posix_str="<-03>3"}, 
  {.name="America/Argentina/Buenos_Aires", .posix_str="<-03>3"}, 
  {.name="America/Argentina/Catamarca", .posix_str="<-03>3"}, 
  {.name="America/Argentina/Cordoba", .posix_str="<-03>3"}, 
  {.name="America/Argentina/Jujuy", .posix_str="<-03>3"}, 
  {.name="America/Argentina/La_Rioja", .posix_str="<-03>3"}, 
  {.name="America/Argentina/Mendoza", .posix_str="<-03>3"}, 
  {.name="America/Argentina/Rio_Gallegos", .posix_str="<-03>3"}, 
  {.name="America/Argentina/Salta", .posix_str="<-03>3"}, 
  {.name="America/Argentina/San_Juan", .posix_str="<-03>3"}, 
  {.name="America/Argentina/San_Luis", .posix_str="<-03>3"}, 
  {.name="America/Argentina/Tucuman", .posix_str="<-03>3"}, 
  {.name="America/Argentina/Ushuaia", .posix_str="<-03>3"}, 
  {.name="America/Aruba", .posix_str="AST4"}, 
  {.name="America/Asuncion", .posix_str="<-04>4<-03>,M10.1.0/0,M3.4.0/0"}, 
  {.name="America/Atikokan", .posix_str="EST5"}, 
  {.name="America/Bahia", .posix_str="<-03>3"}, 
  {.name="America/Bahia_Banderas", .posix_str="CST6CDT,M4.1.0,M10.5.0"}, 
  {.name="America/Barbados", .posix_str="AST4"}, 
  {.name="America/Belem", .posix_str="<-03>3"}, 
  {.name="America/Belize", .posix_str="CST6"}, 
  {.name="America/Blanc-Sablon", .posix_str="AST4"}, 
  {.name="America/Boa_Vista", .posix_str="<-04>4"}, 
  {.name="America/Bogota", .posix_str="<-05>5"}, 
  {.name="America/Boise", .posix_str="MST7MDT,M3.2.0,M11.1.0"}, 
  {.name="America/Cambridge_Bay", .posix_str="MST7MDT,M3.2.0,M11.1.0"}, 
  {.name="America/Campo_Grande", .posix_str="<-04>4"}, 
  {.name="America/Cancun", .posix_str="EST5"}, 
  {.name="America/Caracas", .posix_str="<-04>4"}, 
  {.name="America/Cayenne", .posix_str="<-03>3"}, 
  {.name="America/Cayman", .posix_str="EST5"}, 
  {.name="America/Chicago", .posix_str="CST6CDT,M3.2.0,M11.1.0"}, 
  {.name="America/Chihuahua", .posix_str="MST7MDT,M4.1.0,M10.5.0"}, 
  {.name="America/Costa_Rica", .posix_str="CST6"}, 
  {.name="America/Creston", .posix_str="MST7"}, 
  {.name="America/Cuiaba", .posix_str="<-04>4"}, 
  {.name="America/Curacao", .posix_str="AST4"}, 
  {.name="America/Danmarkshavn", .posix_str="GMT0"}, 
  {.name="America/Dawson", .posix_str="PST8PDT,M3.2.0,M11.1.0"}, 
  {.name="America/Dawson_Creek", .posix_str="MST7"}, 
  {.name="America/Denver", .posix_str="MST7MDT,M3.2.0,M11.1.0"}, 
  {.name="America/Detroit", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Dominica", .posix_str="AST4"}, 
  {.name="America/Edmonton", .posix_str="MST7MDT,M3.2.0,M11.1.0"}, 
  {.name="America/Eirunepe", .posix_str="<-05>5"}, 
  {.name="America/El_Salvador", .posix_str="CST6"}, 
  {.name="America/Fortaleza", .posix_str="<-03>3"}, 
  {.name="America/Fort_Nelson", .posix_str="MST7"}, 
  {.name="America/Glace_Bay", .posix_str="AST4ADT,M3.2.0,M11.1.0"}, 
  {.name="America/Godthab", .posix_str=""}, 
  {.name="America/Goose_Bay", .posix_str="AST4ADT,M3.2.0,M11.1.0"}, 
  {.name="America/Grand_Turk", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Grenada", .posix_str="AST4"}, 
  {.name="America/Guadeloupe", .posix_str="AST4"}, 
  {.name="America/Guatemala", .posix_str="CST6"}, 
  {.name="America/Guayaquil", .posix_str="<-05>5"}, 
  {.name="America/Guyana", .posix_str="<-04>4"}, 
  {.name="America/Halifax", .posix_str="AST4ADT,M3.2.0,M11.1.0"}, 
  {.name="America/Havana", .posix_str="CST5CDT,M3.2.0/0,M11.1.0/1"}, 
  {.name="America/Hermosillo", .posix_str="MST7"}, 
  {.name="America/Indiana/Indianapolis", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Indiana/Knox", .posix_str="CST6CDT,M3.2.0,M11.1.0"}, 
  {.name="America/Indiana/Marengo", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Indiana/Petersburg", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Indiana/Tell_City", .posix_str="CST6CDT,M3.2.0,M11.1.0"}, 
  {.name="America/Indiana/Vevay", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Indiana/Vincennes", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Indiana/Winamac", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Inuvik", .posix_str="MST7MDT,M3.2.0,M11.1.0"}, 
  {.name="America/Iqaluit", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Jamaica", .posix_str="EST5"}, 
  {.name="America/Juneau", .posix_str="AKST9AKDT,M3.2.0,M11.1.0"}, 
  {.name="America/Kentucky/Louisville", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Kentucky/Monticello", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Kralendijk", .posix_str="AST4"}, 
  {.name="America/La_Paz", .posix_str="<-04>4"}, 
  {.name="America/Lima", .posix_str="<-05>5"}, 
  {.name="America/Los_Angeles", .posix_str="PST8PDT,M3.2.0,M11.1.0"}, 
  {.name="America/Lower_Princes", .posix_str="AST4"}, 
  {.name="America/Maceio", .posix_str="<-03>3"}, 
  {.name="America/Managua", .posix_str="CST6"}, 
  {.name="America/Manaus", .posix_str="<-04>4"}, 
  {.name="America/Marigot", .posix_str="AST4"}, 
  {.name="America/Martinique", .posix_str="AST4"}, 
  {.name="America/Matamoros", .posix_str="CST6CDT,M3.2.0,M11.1.0"}, 
  {.name="America/Mazatlan", .posix_str="MST7MDT,M4.1.0,M10.5.0"}, 
  {.name="America/Menominee", .posix_str="CST6CDT,M3.2.0,M11.1.0"}, 
  {.name="America/Merida", .posix_str="CST6CDT,M4.1.0,M10.5.0"}, 
  {.name="America/Metlakatla", .posix_str="AKST9AKDT,M3.2.0,M11.1.0"}, 
  {.name="America/Mexico_City", .posix_str="CST6CDT,M4.1.0,M10.5.0"}, 
  {.name="America/Miquelon", .posix_str="<-03>3<-02>,M3.2.0,M11.1.0"}, 
  {.name="America/Moncton", .posix_str="AST4ADT,M3.2.0,M11.1.0"}, 
  {.name="America/Monterrey", .posix_str="CST6CDT,M4.1.0,M10.5.0"}, 
  {.name="America/Montevideo", .posix_str="<-03>3"}, 
  {.name="America/Montreal", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Montserrat", .posix_str="AST4"}, 
  {.name="America/Nassau", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/New_York", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Nipigon", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Nome", .posix_str="AKST9AKDT,M3.2.0,M11.1.0"}, 
  {.name="America/Noronha", .posix_str="<-02>2"}, 
  {.name="America/North_Dakota/Beulah", .posix_str="CST6CDT,M3.2.0,M11.1.0"}, 
  {.name="America/North_Dakota/Center", .posix_str="CST6CDT,M3.2.0,M11.1.0"}, 
  {.name="America/North_Dakota/New_Salem", .posix_str="CST6CDT,M3.2.0,M11.1.0"}, 
  {.name="America/Ojinaga", .posix_str="MST7MDT,M3.2.0,M11.1.0"}, 
  {.name="America/Panama", .posix_str="EST5"}, 
  {.name="America/Pangnirtung", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Paramaribo", .posix_str="<-03>3"}, 
  {.name="America/Phoenix", .posix_str="MST7"}, 
  {.name="America/Port-au-Prince", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Port_of_Spain", .posix_str="AST4"}, 
  {.name="America/Porto_Velho", .posix_str="<-04>4"}, 
  {.name="America/Puerto_Rico", .posix_str="AST4"}, 
  {.name="America/Punta_Arenas", .posix_str="<-03>3"}, 
  {.name="America/Rainy_River", .posix_str="CST6CDT,M3.2.0,M11.1.0"}, 
  {.name="America/Rankin_Inlet", .posix_str="CST6CDT,M3.2.0,M11.1.0"}, 
  {.name="America/Recife", .posix_str="<-03>3"}, 
  {.name="America/Regina", .posix_str="CST6"}, 
  {.name="America/Resolute", .posix_str="CST6CDT,M3.2.0,M11.1.0"}, 
  {.name="America/Rio_Branco", .posix_str="<-05>5"}, 
  {.name="America/Santarem", .posix_str="<-03>3"}, 
  {.name="America/Santiago", .posix_str=""}, 
  {.name="America/Santo_Domingo", .posix_str="AST4"}, 
  {.name="America/Sao_Paulo", .posix_str="<-03>3"}, 
  {.name="America/Scoresbysund", .posix_str="<-01>1<+00>,M3.5.0/0,M10.5.0/1"}, 
  {.name="America/Sitka", .posix_str="AKST9AKDT,M3.2.0,M11.1.0"}, 
  {.name="America/St_Barthelemy", .posix_str="AST4"}, 
  {.name="America/St_Johns", .posix_str="NST3:30NDT,M3.2.0,M11.1.0"}, 
  {.name="America/St_Kitts", .posix_str="AST4"}, 
  {.name="America/St_Lucia", .posix_str="AST4"}, 
  {.name="America/St_Thomas", .posix_str="AST4"}, 
  {.name="America/St_Vincent", .posix_str="AST4"}, 
  {.name="America/Swift_Current", .posix_str="CST6"}, 
  {.name="America/Tegucigalpa", .posix_str="CST6"}, 
  {.name="America/Thule", .posix_str="AST4ADT,M3.2.0,M11.1.0"}, 
  {.name="America/Thunder_Bay", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Tijuana", .posix_str="PST8PDT,M3.2.0,M11.1.0"}, 
  {.name="America/Toronto", .posix_str="EST5EDT,M3.2.0,M11.1.0"}, 
  {.name="America/Tortola", .posix_str="AST4"}, 
  {.name="America/Vancouver", .posix_str="PST8PDT,M3.2.0,M11.1.0"}, 
  {.name="America/Whitehorse", .posix_str="PST8PDT,M3.2.0,M11.1.0"}, 
  {.name="America/Winnipeg", .posix_str="CST6CDT,M3.2.0,M11.1.0"}, 
  {.name="America/Yakutat", .posix_str="AKST9AKDT,M3.2.0,M11.1.0"}, 
  {.name="America/Yellowknife", .posix_str="MST7MDT,M3.2.0,M11.1.0"}, 
  {.name="Antarctica/Casey", .posix_str="<+08>-8"}, 
  {.name="Antarctica/Davis", .posix_str="<+07>-7"}, 
  {.name="Antarctica/DumontDUrville", .posix_str="<+10>-10"}, 
  {.name="Antarctica/Macquarie", .posix_str="<+11>-11"}, 
  {.name="Antarctica/Mawson", .posix_str="<+05>-5"}, 
  {.name="Antarctica/McMurdo", .posix_str="NZST-12NZDT,M9.5.0,M4.1.0/3"}, 
  {.name="Antarctica/Palmer", .posix_str="<-03>3"}, 
  {.name="Antarctica/Rothera", .posix_str="<-03>3"}, 
  {.name="Antarctica/Syowa", .posix_str="<+03>-3"}, 
  {.name="Antarctica/Troll", .posix_str="<+00>0<+02>-2,M3.5.0/1,M10.5.0/3"}, 
  {.name="Antarctica/Vostok", .posix_str="<+06>-6"}, 
  {.name="Arctic/Longyearbyen", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Asia/Aden", .posix_str="<+03>-3"}, 
  {.name="Asia/Almaty", .posix_str="<+06>-6"}, 
  {.name="Asia/Amman", .posix_str=""}, 
  {.name="Asia/Anadyr", .posix_str="<+12>-12"}, 
  {.name="Asia/Aqtau", .posix_str="<+05>-5"}, 
  {.name="Asia/Aqtobe", .posix_str="<+05>-5"}, 
  {.name="Asia/Ashgabat", .posix_str="<+05>-5"}, 
  {.name="Asia/Atyrau", .posix_str="<+05>-5"}, 
  {.name="Asia/Baghdad", .posix_str="<+03>-3"}, 
  {.name="Asia/Bahrain", .posix_str="<+03>-3"}, 
  {.name="Asia/Baku", .posix_str="<+04>-4"}, 
  {.name="Asia/Bangkok", .posix_str="<+07>-7"}, 
  {.name="Asia/Barnaul", .posix_str="<+07>-7"}, 
  {.name="Asia/Beirut", .posix_str="EET-2EEST,M3.5.0/0,M10.5.0/0"}, 
  {.name="Asia/Bishkek", .posix_str="<+06>-6"}, 
  {.name="Asia/Brunei", .posix_str="<+08>-8"}, 
  {.name="Asia/Chita", .posix_str="<+09>-9"}, 
  {.name="Asia/Choibalsan", .posix_str="<+08>-8"}, 
  {.name="Asia/Colombo", .posix_str="<+0530>-5:30"}, 
  {.name="Asia/Damascus", .posix_str="EET-2EEST,M3.5.5/0,M10.5.5/0"}, 
  {.name="Asia/Dhaka", .posix_str="<+06>-6"}, 
  {.name="Asia/Dili", .posix_str="<+09>-9"}, 
  {.name="Asia/Dubai", .posix_str="<+04>-4"}, 
  {.name="Asia/Dushanbe", .posix_str="<+05>-5"}, 
  {.name="Asia/Famagusta", .posix_str="EET-2EEST,M3.5.0/3,M10.5.0/4"}, 
  {.name="Asia/Gaza", .posix_str="EET-2EEST,M3.5.5/0,M10.5.6/1"}, 
  {.name="Asia/Hebron", .posix_str="EET-2EEST,M3.5.5/0,M10.5.6/1"}, 
  {.name="Asia/Ho_Chi_Minh", .posix_str="<+07>-7"}, 
  {.name="Asia/Hong_Kong", .posix_str="HKT-8"}, 
  {.name="Asia/Hovd", .posix_str="<+07>-7"}, 
  {.name="Asia/Irkutsk", .posix_str="<+08>-8"}, 
  {.name="Asia/Jakarta", .posix_str="WIB-7"}, 
  {.name="Asia/Jayapura", .posix_str="WIT-9"}, 
  {.name="Asia/Jerusalem", .posix_str=""}, 
  {.name="Asia/Kabul", .posix_str="<+0430>-4:30"}, 
  {.name="Asia/Kamchatka", .posix_str="<+12>-12"}, 
  {.name="Asia/Karachi", .posix_str="PKT-5"}, 
  {.name="Asia/Kathmandu", .posix_str="<+0545>-5:45"}, 
  {.name="Asia/Khandyga", .posix_str="<+09>-9"}, 
  {.name="Asia/Kolkata", .posix_str="IST-5:30"}, 
  {.name="Asia/Krasnoyarsk", .posix_str="<+07>-7"}, 
  {.name="Asia/Kuala_Lumpur", .posix_str="<+08>-8"}, 
  {.name="Asia/Kuching", .posix_str="<+08>-8"}, 
  {.name="Asia/Kuwait", .posix_str="<+03>-3"}, 
  {.name="Asia/Macau", .posix_str="CST-8"}, 
  {.name="Asia/Magadan", .posix_str="<+11>-11"}, 
  {.name="Asia/Makassar", .posix_str="WITA-8"}, 
  {.name="Asia/Manila", .posix_str="PST-8"}, 
  {.name="Asia/Muscat", .posix_str="<+04>-4"}, 
  {.name="Asia/Nicosia", .posix_str="EET-2EEST,M3.5.0/3,M10.5.0/4"}, 
  {.name="Asia/Novokuznetsk", .posix_str="<+07>-7"}, 
  {.name="Asia/Novosibirsk", .posix_str="<+07>-7"}, 
  {.name="Asia/Omsk", .posix_str="<+06>-6"}, 
  {.name="Asia/Oral", .posix_str="<+05>-5"}, 
  {.name="Asia/Phnom_Penh", .posix_str="<+07>-7"}, 
  {.name="Asia/Pontianak", .posix_str="WIB-7"}, 
  {.name="Asia/Pyongyang", .posix_str="KST-9"}, 
  {.name="Asia/Qatar", .posix_str="<+03>-3"}, 
  {.name="Asia/Qyzylorda", .posix_str="<+05>-5"}, 
  {.name="Asia/Riyadh", .posix_str="<+03>-3"}, 
  {.name="Asia/Sakhalin", .posix_str="<+11>-11"}, 
  {.name="Asia/Samarkand", .posix_str="<+05>-5"}, 
  {.name="Asia/Seoul", .posix_str="KST-9"}, 
  {.name="Asia/Shanghai", .posix_str="CST-8"}, 
  {.name="Asia/Singapore", .posix_str="<+08>-8"}, 
  {.name="Asia/Srednekolymsk", .posix_str="<+11>-11"}, 
  {.name="Asia/Taipei", .posix_str="CST-8"}, 
  {.name="Asia/Tashkent", .posix_str="<+05>-5"}, 
  {.name="Asia/Tbilisi", .posix_str="<+04>-4"}, 
  {.name="Asia/Tehran", .posix_str=""}, 
  {.name="Asia/Thimphu", .posix_str="<+06>-6"}, 
  {.name="Asia/Tokyo", .posix_str="JST-9"}, 
  {.name="Asia/Tomsk", .posix_str="<+07>-7"}, 
  {.name="Asia/Ulaanbaatar", .posix_str="<+08>-8"}, 
  {.name="Asia/Urumqi", .posix_str="<+06>-6"}, 
  {.name="Asia/Ust-Nera", .posix_str="<+10>-10"}, 
  {.name="Asia/Vientiane", .posix_str="<+07>-7"}, 
  {.name="Asia/Vladivostok", .posix_str="<+10>-10"}, 
  {.name="Asia/Yakutsk", .posix_str="<+09>-9"}, 
  {.name="Asia/Yangon", .posix_str="<+0630>-6:30"}, 
  {.name="Asia/Yekaterinburg", .posix_str="<+05>-5"}, 
  {.name="Asia/Yerevan", .posix_str="<+04>-4"}, 
  {.name="Atlantic/Azores", .posix_str="<-01>1<+00>,M3.5.0/0,M10.5.0/1"}, 
  {.name="Atlantic/Bermuda", .posix_str="AST4ADT,M3.2.0,M11.1.0"}, 
  {.name="Atlantic/Canary", .posix_str="WET0WEST,M3.5.0/1,M10.5.0"}, 
  {.name="Atlantic/Cape_Verde", .posix_str="<-01>1"}, 
  {.name="Atlantic/Faroe", .posix_str="WET0WEST,M3.5.0/1,M10.5.0"}, 
  {.name="Atlantic/Madeira", .posix_str="WET0WEST,M3.5.0/1,M10.5.0"}, 
  {.name="Atlantic/Reykjavik", .posix_str="GMT0"}, 
  {.name="Atlantic/South_Georgia", .posix_str="<-02>2"}, 
  {.name="Atlantic/Stanley", .posix_str="<-03>3"}, 
  {.name="Atlantic/St_Helena", .posix_str="GMT0"}, 
  {.name="Australia/Adelaide", .posix_str="ACST-9:30ACDT,M10.1.0,M4.1.0/3"}, 
  {.name="Australia/Brisbane", .posix_str="AEST-10"}, 
  {.name="Australia/Broken_Hill", .posix_str="ACST-9:30ACDT,M10.1.0,M4.1.0/3"}, 
  {.name="Australia/Currie", .posix_str="AEST-10AEDT,M10.1.0,M4.1.0/3"}, 
  {.name="Australia/Darwin", .posix_str="ACST-9:30"}, 
  {.name="Australia/Eucla", .posix_str="<+0845>-8:45"}, 
  {.name="Australia/Hobart", .posix_str="AEST-10AEDT,M10.1.0,M4.1.0/3"}, 
  {.name="Australia/Lindeman", .posix_str="AEST-10"}, 
  {.name="Australia/Lord_Howe", .posix_str="<+1030>-10:30<+11>-11,M10.1.0,M4.1.0"}, 
  {.name="Australia/Melbourne", .posix_str="AEST-10AEDT,M10.1.0,M4.1.0/3"}, 
  {.name="Australia/Perth", .posix_str="AWST-8"}, 
  {.name="Australia/Sydney", .posix_str="AEST-10AEDT,M10.1.0,M4.1.0/3"}, 
  {.name="Europe/Amsterdam", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Andorra", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Astrakhan", .posix_str="<+04>-4"}, 
  {.name="Europe/Athens", .posix_str="EET-2EEST,M3.5.0/3,M10.5.0/4"}, 
  {.name="Europe/Belgrade", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Berlin", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Bratislava", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Brussels", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Bucharest", .posix_str="EET-2EEST,M3.5.0/3,M10.5.0/4"}, 
  {.name="Europe/Budapest", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Busingen", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Chisinau", .posix_str="EET-2EEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Copenhagen", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Dublin", .posix_str="GMT0IST,M3.5.0/1,M10.5.0"}, 
  {.name="Europe/Gibraltar", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Guernsey", .posix_str="GMT0BST,M3.5.0/1,M10.5.0"}, 
  {.name="Europe/Helsinki", .posix_str="EET-2EEST,M3.5.0/3,M10.5.0/4"}, 
  {.name="Europe/Isle_of_Man", .posix_str="GMT0BST,M3.5.0/1,M10.5.0"}, 
  {.name="Europe/Istanbul", .posix_str="<+03>-3"}, 
  {.name="Europe/Jersey", .posix_str="GMT0BST,M3.5.0/1,M10.5.0"}, 
  {.name="Europe/Kaliningrad", .posix_str="EET-2"}, 
  {.name="Europe/Kiev", .posix_str="EET-2EEST,M3.5.0/3,M10.5.0/4"}, 
  {.name="Europe/Kirov", .posix_str="<+03>-3"}, 
  {.name="Europe/Lisbon", .posix_str="WET0WEST,M3.5.0/1,M10.5.0"}, 
  {.name="Europe/Ljubljana", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/London", .posix_str="GMT0BST,M3.5.0/1,M10.5.0"}, 
  {.name="Europe/Luxembourg", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Madrid", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Malta", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Mariehamn", .posix_str="EET-2EEST,M3.5.0/3,M10.5.0/4"}, 
  {.name="Europe/Minsk", .posix_str="<+03>-3"}, 
  {.name="Europe/Monaco", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Moscow", .posix_str="MSK-3"}, 
  {.name="Europe/Oslo", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Paris", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Podgorica", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Prague", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Riga", .posix_str="EET-2EEST,M3.5.0/3,M10.5.0/4"}, 
  {.name="Europe/Rome", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Samara", .posix_str="<+04>-4"}, 
  {.name="Europe/San_Marino", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Sarajevo", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Saratov", .posix_str="<+04>-4"}, 
  {.name="Europe/Simferopol", .posix_str="MSK-3"}, 
  {.name="Europe/Skopje", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Sofia", .posix_str="EET-2EEST,M3.5.0/3,M10.5.0/4"}, 
  {.name="Europe/Stockholm", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Tallinn", .posix_str="EET-2EEST,M3.5.0/3,M10.5.0/4"}, 
  {.name="Europe/Tirane", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Ulyanovsk", .posix_str="<+04>-4"}, 
  {.name="Europe/Uzhgorod", .posix_str="EET-2EEST,M3.5.0/3,M10.5.0/4"}, 
  {.name="Europe/Vaduz", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Vatican", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Vienna", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Vilnius", .posix_str="EET-2EEST,M3.5.0/3,M10.5.0/4"}, 
  {.name="Europe/Volgograd", .posix_str="<+04>-4"}, 
  {.name="Europe/Warsaw", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Zagreb", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Europe/Zaporozhye", .posix_str="EET-2EEST,M3.5.0/3,M10.5.0/4"}, 
  {.name="Europe/Zurich", .posix_str="CET-1CEST,M3.5.0,M10.5.0/3"}, 
  {.name="Indian/Antananarivo", .posix_str="EAT-3"}, 
  {.name="Indian/Chagos", .posix_str="<+06>-6"}, 
  {.name="Indian/Christmas", .posix_str="<+07>-7"}, 
  {.name="Indian/Cocos", .posix_str="<+0630>-6:30"}, 
  {.name="Indian/Comoro", .posix_str="EAT-3"}, 
  {.name="Indian/Kerguelen", .posix_str="<+05>-5"}, 
  {.name="Indian/Mahe", .posix_str="<+04>-4"}, 
  {.name="Indian/Maldives", .posix_str="<+05>-5"}, 
  {.name="Indian/Mauritius", .posix_str="<+04>-4"}, 
  {.name="Indian/Mayotte", .posix_str="EAT-3"}, 
  {.name="Indian/Reunion", .posix_str="<+04>-4"}, 
  {.name="Pacific/Apia", .posix_str="<+13>-13<+14>,M9.5.0/3,M4.1.0/4"}, 
  {.name="Pacific/Auckland", .posix_str="NZST-12NZDT,M9.5.0,M4.1.0/3"}, 
  {.name="Pacific/Bougainville", .posix_str="<+11>-11"}, 
  {.name="Pacific/Chatham", .posix_str="<+1245>-12:45<+1345>,M9.5.0/2:45,M4.1.0/3:45"}, 
  {.name="Pacific/Chuuk", .posix_str="<+10>-10"}, 
  {.name="Pacific/Easter", .posix_str=""}, 
  {.name="Pacific/Efate", .posix_str="<+11>-11"}, 
  {.name="Pacific/Enderbury", .posix_str="<+13>-13"}, 
  {.name="Pacific/Fakaofo", .posix_str="<+13>-13"}, 
  {.name="Pacific/Fiji", .posix_str=""}, 
  {.name="Pacific/Funafuti", .posix_str="<+12>-12"}, 
  {.name="Pacific/Galapagos", .posix_str="<-06>6"}, 
  {.name="Pacific/Gambier", .posix_str="<-09>9"}, 
  {.name="Pacific/Guadalcanal", .posix_str="<+11>-11"}, 
  {.name="Pacific/Guam", .posix_str="ChST-10"}, 
  {.name="Pacific/Honolulu", .posix_str="HST10"}, 
  {.name="Pacific/Kiritimati", .posix_str="<+14>-14"}, 
  {.name="Pacific/Kosrae", .posix_str="<+11>-11"}, 
  {.name="Pacific/Kwajalein", .posix_str="<+12>-12"}, 
  {.name="Pacific/Majuro", .posix_str="<+12>-12"}, 
  {.name="Pacific/Marquesas", .posix_str="<-0930>9:30"}, 
  {.name="Pacific/Midway", .posix_str="SST11"}, 
  {.name="Pacific/Nauru", .posix_str="<+12>-12"}, 
  {.name="Pacific/Niue", .posix_str="<-11>11"}, 
  {.name="Pacific/Norfolk", .posix_str="<+11>-11<+12>,M10.1.0,M4.1.0/3"}, 
  {.name="Pacific/Noumea", .posix_str="<+11>-11"}, 
  {.name="Pacific/Pago_Pago", .posix_str="SST11"}, 
  {.name="Pacific/Palau", .posix_str="<+09>-9"}, 
  {.name="Pacific/Pitcairn", .posix_str="<-08>8"}, 
  {.name="Pacific/Pohnpei", .posix_str="<+11>-11"}, 
  {.name="Pacific/Port_Moresby", .posix_str="<+10>-10"}, 
  {.name="Pacific/Rarotonga", .posix_str="<-10>10"}, 
  {.name="Pacific/Saipan", .posix_str="ChST-10"}, 
  {.name="Pacific/Tahiti", .posix_str="<-10>10"}, 
  {.name="Pacific/Tarawa", .posix_str="<+12>-12"}, 
  {.name="Pacific/Tongatapu", .posix_str="<+13>-13"}, 
  {.name="Pacific/Wake", .posix_str="<+12>-12"}, 
  {.name="Pacific/Wallis", .posix_str="<+12>-12"}, 
  {.name="Etc/GMT", .posix_str="GMT0"}, 
  {.name="Etc/GMT-0", .posix_str="GMT0"}, 
  {.name="Etc/GMT-1", .posix_str="<+01>-1"}, 
  {.name="Etc/GMT-2", .posix_str="<+02>-2"}, 
  {.name="Etc/GMT-3", .posix_str="<+03>-3"}, 
  {.name="Etc/GMT-4", .posix_str="<+04>-4"}, 
  {.name="Etc/GMT-5", .posix_str="<+05>-5"}, 
  {.name="Etc/GMT-6", .posix_str="<+06>-6"}, 
  {.name="Etc/GMT-7", .posix_str="<+07>-7"}, 
  {.name="Etc/GMT-8", .posix_str="<+08>-8"}, 
  {.name="Etc/GMT-9", .posix_str="<+09>-9"}, 
  {.name="Etc/GMT-10", .posix_str="<+10>-10"}, 
  {.name="Etc/GMT-11", .posix_str="<+11>-11"}, 
  {.name="Etc/GMT-12", .posix_str="<+12>-12"}, 
  {.name="Etc/GMT-13", .posix_str="<+13>-13"}, 
  {.name="Etc/GMT-14", .posix_str="<+14>-14"}, 
  {.name="Etc/GMT0", .posix_str="GMT0"}, 
  {.name="Etc/GMT+0", .posix_str="GMT0"}, 
  {.name="Etc/GMT+1", .posix_str="<-01>1"}, 
  {.name="Etc/GMT+2", .posix_str="<-02>2"}, 
  {.name="Etc/GMT+3", .posix_str="<-03>3"}, 
  {.name="Etc/GMT+4", .posix_str="<-04>4"}, 
  {.name="Etc/GMT+5", .posix_str="<-05>5"}, 
  {.name="Etc/GMT+6", .posix_str="<-06>6"}, 
  {.name="Etc/GMT+7", .posix_str="<-07>7"}, 
  {.name="Etc/GMT+8", .posix_str="<-08>8"}, 
  {.name="Etc/GMT+9", .posix_str="<-09>9"}, 
  {.name="Etc/GMT+10", .posix_str="<-10>10"}, 
  {.name="Etc/GMT+11", .posix_str="<-11>11"}, 
  {.name="Etc/GMT+12", .posix_str="<-12>12"}, 
  {.name="Etc/UCT", .posix_str="UTC0"}, 
  {.name="Etc/UTC", .posix_str="UTC0"}, 
  {.name="Etc/Greenwich", .posix_str="GMT0"}, 
  {.name="Etc/Universal", .posix_str="UTC0"}, 
  {.name="Etc/Zulu", .posix_str="UTC0"}
};
