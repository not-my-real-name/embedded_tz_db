//IANA time Zone database version used to generate this file.
const embedded_tz_IanaDbVers = "2024b-2";

// Short List of selectable time zones for embedded devices
const embedded_tz_db_short = {
    "Africa/Abidjan":"GMT0",
    "Africa/Cairo":"EET-2EEST,M4.5.5/0,M10.5.4/24",
    "Africa/Casablanca":"<+01>-1",
    "Africa/Johannesburg":"SAST-2",
    "Africa/Juba":"CAT-2",
    "Africa/Khartoum":"CAT-2",
    "Africa/Lagos":"WAT-1",
    "Africa/Nairobi":"EAT-3",
    "Africa/Sao_Tome":"GMT0",
    "Africa/Tripoli":"EET-2",
    "Africa/Windhoek":"CAT-2",
    "America/Adak":"HST10HDT,M3.2.0,M11.1.0",
    "America/Anchorage":"AKST9AKDT,M3.2.0,M11.1.0",
    "America/Araguaina":"<-03>3",
    "America/Argentina/Buenos_Aires":"<-03>3",
    "America/Asuncion":"<-04>4<-03>,M10.1.0/0,M3.4.0/0",
    "America/Bahia":"<-03>3",
    "America/Bogota":"<-05>5",
    "America/Cancun":"EST5",
    "America/Caracas":"<-04>4",
    "America/Cayenne":"<-03>3",
    "America/Chicago":"CST6CDT,M3.2.0,M11.1.0",
    "America/Chihuahua":"CST6",
    "America/Cuiaba":"<-04>4",
    "America/Denver":"MST7MDT,M3.2.0,M11.1.0",
    "America/Grand_Turk":"EST5EDT,M3.2.0,M11.1.0",
    "America/Guatemala":"CST6",
    "America/Halifax":"AST4ADT,M3.2.0,M11.1.0",
    "America/Havana":"CST5CDT,M3.2.0/0,M11.1.0/1",
    "America/Indiana/Indianapolis":"EST5EDT,M3.2.0,M11.1.0",
    "America/La_Paz":"<-04>4",
    "America/Los_Angeles":"PST8PDT,M3.2.0,M11.1.0",
    "America/Mexico_City":"CST6",
    "America/Miquelon":"<-03>3<-02>,M3.2.0,M11.1.0",
    "America/Montevideo":"<-03>3",
    "America/New_York":"EST5EDT,M3.2.0,M11.1.0",
    "America/Nuuk":"<-02>2<-01>,M3.5.0/-1,M10.5.0/0",
    "America/Phoenix":"MST7",
    "America/Port-au-Prince":"EST5EDT,M3.2.0,M11.1.0",
    "America/Punta_Arenas":"<-03>3",
    "America/Regina":"CST6",
    "America/Santiago":"<-04>4<-03>,M9.1.6/24,M4.1.6/24",
    "America/Sao_Paulo":"<-03>3",
    "America/St_Johns":"NST3:30NDT,M3.2.0,M11.1.0",
    "America/Tijuana":"PST8PDT,M3.2.0,M11.1.0",
    "America/Whitehorse":"MST7",
    "Asia/Almaty":"<+05>-5",
    "Asia/Amman":"<+03>-3",
    "Asia/Baghdad":"<+03>-3",
    "Asia/Baku":"<+04>-4",
    "Asia/Bangkok":"<+07>-7",
    "Asia/Barnaul":"<+07>-7",
    "Asia/Beirut":"EET-2EEST,M3.5.0/0,M10.5.0/0",
    "Asia/Chita":"<+09>-9",
    "Asia/Colombo":"<+0530>-5:30",
    "Asia/Damascus":"<+03>-3",
    "Asia/Dhaka":"<+06>-6",
    "Asia/Dubai":"<+04>-4",
    "Asia/Hebron":"EET-2EEST,M3.4.4/50,M10.4.4/50",
    "Asia/Hovd":"<+07>-7",
    "Asia/Irkutsk":"<+08>-8",
    "Asia/Jerusalem":"IST-2IDT,M3.4.4/26,M10.5.0",
    "Asia/Kabul":"<+0430>-4:30",
    "Asia/Kamchatka":"<+12>-12",
    "Asia/Karachi":"PKT-5",
    "Asia/Kathmandu":"<+0545>-5:45",
    "Asia/Kolkata":"IST-5:30",
    "Asia/Krasnoyarsk":"<+07>-7",
    "Asia/Magadan":"<+11>-11",
    "Asia/Novosibirsk":"<+07>-7",
    "Asia/Omsk":"<+06>-6",
    "Asia/Pyongyang":"KST-9",
    "Asia/Qyzylorda":"<+05>-5",
    "Asia/Riyadh":"<+03>-3",
    "Asia/Sakhalin":"<+11>-11",
    "Asia/Seoul":"KST-9",
    "Asia/Shanghai":"CST-8",
    "Asia/Singapore":"<+08>-8",
    "Asia/Srednekolymsk":"<+11>-11",
    "Asia/Taipei":"CST-8",
    "Asia/Tashkent":"<+05>-5",
    "Asia/Tbilisi":"<+04>-4",
    "Asia/Tehran":"<+0330>-3:30",
    "Asia/Tokyo":"JST-9",
    "Asia/Tomsk":"<+07>-7",
    "Asia/Ulaanbaatar":"<+08>-8",
    "Asia/Vladivostok":"<+10>-10",
    "Asia/Yakutsk":"<+09>-9",
    "Asia/Yangon":"<+0630>-6:30",
    "Asia/Yekaterinburg":"<+05>-5",
    "Asia/Yerevan":"<+04>-4",
    "Atlantic/Azores":"<-01>1<+00>,M3.5.0/0,M10.5.0/1",
    "Atlantic/Cape_Verde":"<-01>1",
    "Australia/Adelaide":"ACST-9:30ACDT,M10.1.0,M4.1.0/3",
    "Australia/Brisbane":"AEST-10",
    "Australia/Darwin":"ACST-9:30",
    "Australia/Eucla":"<+0845>-8:45",
    "Australia/Hobart":"AEST-10AEDT,M10.1.0,M4.1.0/3",
    "Australia/Lord_Howe":"<+1030>-10:30<+11>-11,M10.1.0,M4.1.0",
    "Australia/Perth":"AWST-8",
    "Australia/Sydney":"AEST-10AEDT,M10.1.0,M4.1.0/3",
    "Etc/GMT+11":"<-11>11",
    "Etc/GMT+12":"<-12>12",
    "Etc/GMT+2":"<-02>2",
    "Etc/GMT+8":"<-08>8",
    "Etc/GMT+9":"<-09>9",
    "Etc/GMT-12":"<+12>-12",
    "Etc/GMT-13":"<+13>-13",
    "Etc/UTC":"UTC0",
    "Europe/Astrakhan":"<+04>-4",
    "Europe/Berlin":"CET-1CEST,M3.5.0,M10.5.0/3",
    "Europe/Bucharest":"EET-2EEST,M3.5.0/3,M10.5.0/4",
    "Europe/Budapest":"CET-1CEST,M3.5.0,M10.5.0/3",
    "Europe/Chisinau":"EET-2EEST,M3.5.0,M10.5.0/3",
    "Europe/Istanbul":"<+03>-3",
    "Europe/Kaliningrad":"EET-2",
    "Europe/Kyiv":"EET-2EEST,M3.5.0/3,M10.5.0/4",
    "Europe/London":"GMT0BST,M3.5.0/1,M10.5.0",
    "Europe/Minsk":"<+03>-3",
    "Europe/Moscow":"MSK-3",
    "Europe/Paris":"CET-1CEST,M3.5.0,M10.5.0/3",
    "Europe/Samara":"<+04>-4",
    "Europe/Saratov":"<+04>-4",
    "Europe/Volgograd":"MSK-3",
    "Europe/Warsaw":"CET-1CEST,M3.5.0,M10.5.0/3",
    "Indian/Mauritius":"<+04>-4",
    "Pacific/Apia":"<+13>-13",
    "Pacific/Auckland":"NZST-12NZDT,M9.5.0,M4.1.0/3",
    "Pacific/Bougainville":"<+11>-11",
    "Pacific/Chatham":"<+1245>-12:45<+1345>,M9.5.0/2:45,M4.1.0/3:45",
    "Pacific/Easter":"<-06>6<-05>,M9.1.6/22,M4.1.6/22",
    "Pacific/Fiji":"<+12>-12",
    "Pacific/Guadalcanal":"<+11>-11",
    "Pacific/Honolulu":"HST10",
    "Pacific/Kiritimati":"<+14>-14",
    "Pacific/Marquesas":"<-0930>9:30",
    "Pacific/Norfolk":"<+11>-11<+12>,M10.1.0,M4.1.0/3",
    "Pacific/Port_Moresby":"<+10>-10",
    "Pacific/Tongatapu":"<+13>-13"
};
