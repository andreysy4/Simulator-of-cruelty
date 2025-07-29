

#define WIN32_LEAN_AND_MEAN  // just say no to MFC

#define INIT_GUID

#include "hge.h"
#include <hgesprite.h>
#include <hgefont.h>
#include <hgecolor.h>
#include <hgeanim.h>
#include <hgegui.h>
#include <hgeparticle.h>
#include <windowsx.h> 
#include <mmsystem.h>
#include <list>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>
#include <stdarg.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <winsock2.h>
#include "menuitem.h"
#include <io.h>
#include <fcntl.h>


using namespace std;

#define WM_SOCKET	WM_USER+1	// Socket Windows Message

HGE *hge=0;


hgeGUI* menu;
hgeGUI* menu_info;
hgeGUI* menu_start;
hgeGUI* menu_video;
hgeGUI* menu_really;
hgeGUI* menu_class;
hgeGUI* menu_class2;

hgeParticleSystem*  blood_ssit_psi;
HTEXTURE blood_ssit_tex;
hgeSprite* blood_ssit_spr;

hgeParticleSystem*  RPG_healing_psi;
HTEXTURE RPG_healing_tex;
hgeSprite* RPG_healing_spr;

hgeParticleSystem*  vzriv_grena_psi;
HTEXTURE vzriv_grena_tex;
hgeSprite* vzriv_grena_spr;

hgeParticleSystem*  vzriv_ogon_grena_psi;
HTEXTURE vzriv_ogon_grena_tex;
hgeSprite* vzriv_ogon_grena_spr;


hgeColor* fonColor;

HTARGET	blood_target;
hgeSprite* blood_tar;

hgeSprite* pulya;//огонь
hgeSprite* pulya2;//огонь 2
hgeSprite* p;//пуля
hgeSprite* p2;//пуля2
hgeSprite* optika1;


hgeSprite* p1d1;
hgeSprite* p1d2;
hgeSprite* p1d3;
hgeSprite* p1d4;
hgeSprite* p2d1;
hgeSprite* p2d2;
hgeSprite* p2d3;
hgeSprite* p2d4;


hgeSprite* gilza_pist;
hgeSprite* gilza_avt;



hgeSprite* fon1;//фон пожухлой травы
hgeSprite* fon2;//фон из пожухлой травы в лесную
hgeSprite* fon3;//фон лесной травы


hgeSprite* oblaka1;

hgeSprite* alkash1;

hgeSprite* derevo1;
hgeSprite* penek1;


hgeSprite* znak_polputi;
hgeSprite* polosa_finish;


hgeSprite* ak47;//автомат
hgeSprite* pm;//пистолет Макарова
hgeSprite* pp19_vityaz; //ПП 19-01 "Витязь"
hgeSprite* fn_f2000;//ФН_Ф2000
hgeSprite* tt;//Тульский Токарев 
hgeSprite* rpk;//РПК 74
hgeSprite* mac;//MAC 1 
hgeSprite* winchester; //винчестер
hgeAnimation* winchester_anime;
hgeSprite* rpk47;//РПК 47
hgeSprite* glok;//GLOK
hgeSprite* rgd5;//РГД-5
hgeAnimation* katana1_anime;
hgeSprite* milkor;//Milkor MGL
hgeSprite* panzer;//Panzerfaust-3
hgeSprite* webley;//Webley MK 4
hgeSprite* fn_five_seven;//FN Five-Seven


hgeSprite* ak472;//автомат 2
hgeSprite* pm2;//пистолет Макарова 2
hgeSprite* pp19_vityaz2; //ПП 19-01 "Витязь" 2
hgeSprite* fn_f20002;//ФН_Ф2000 2
hgeSprite* tt2;//Тульский Токарев 2
hgeSprite* rpk2;//РПК 74 2
hgeSprite* mac2;//MAC 2
hgeSprite* winchester2; //винчестер 2
hgeAnimation* winchester2_anime;
hgeSprite* rpk472;//РПК 47 2
hgeSprite* glok2;//GLOK2
hgeSprite* rgd52;//РГД-5 2
hgeAnimation* katana2_anime;
hgeSprite* milkor2;//Milkor MGL 2
hgeSprite* panzer2;//Panzerfaust-3 2
hgeSprite* webley2;//Webley MK 4
hgeSprite* fn_five_seven2;//FN Five-Seven

hgeSprite* granata_podstvol;//граната из подствольника
hgeSprite* granata_panzer;//граната из panzerfaust-3
hgeSprite* qlz87_pushka;
hgeSprite* qlz87_trenoga;

hgeFont*  oboima_text;//показатель обоймы
hgeFont*  info;//текст инфы
hgeFont*  infoR;//красный текст
hgeFont*  infoD;//потухлый текст
hgeFont*  infoBR;//большой темно-красный текст

hgeFont*  menu_font;

hgeSprite* galka;
hgeSprite* galka_menu;
hgeSprite* strelka_menu;


hgeSprite* znak_myasnik;
hgeSprite* znak_strelok;
hgeSprite* znak_razrushitel;
hgeSprite* znak_tehnik;




hgeSprite* status_opit;
hgeSprite* status_udar;
hgeSprite* status_status;
hgeSprite* opit1_progress;

hgeSprite* opit_okno_vibora;

hgeSprite* okno_lvl_progress;
hgeSprite* okno_lvl_progress_red;
hgeSprite* okno_lvl_progress_green;
hgeSprite* okno_lvl_polzunok;



hgeAnimation* player1_myasnik;//игрок 1 мясник
hgeAnimation* player1_strelok;//игрок 1 стрелок
hgeAnimation* player1_razrushitel;//игрок 1 разрушитель
hgeAnimation* player1_tehnik;//игрок 1 техник
hgeAnimation* player1_gogranata_ruka1;
hgeAnimation* player1_gogranata_ruka2;
hgeAnimation* player1_myasnik_ruka1_udar_sleva;
hgeAnimation* player1_ruka1_pistol;
hgeAnimation* player1_ruka1_vintovka;
hgeAnimation* player1_ruka1_winch;

hgeAnimation* player2_strelok;//игрок 2 стрелок
hgeAnimation* player2_gogranata_ruka1;
hgeAnimation* player2_gogranata_ruka2;
hgeAnimation* player2_myasnik_ruka1_udar_sleva;
hgeAnimation* player2_ruka1_pistol;
hgeAnimation* player2_ruka1_vintovka;


hgeAnimation* zayac;//заяц
hgeAnimation* uhi_a;//кровяк на ушах
hgeSprite* uhi;//заячьи уши
hgeSprite* zayac_boshka;
hgeSprite* zayac_boshka_bezuh;
hgeSprite* zayac_trup1;

hgeAnimation* volk;
hgeSprite* volk_trup1;

hgeAnimation* medved;//медведь
hgeSprite* medved_trup1;
hgeSprite* medved_boshka;

hgeAnimation* ptenec;//птенец!
hgeAnimation* ptenec_wait;
hgeSprite* ptenec_trup1;
hgeSprite* ptenec_boshka_vzriv1;

hgeSprite* RPG_healer;
hgeSprite* RPG_illusionist;
hgeSprite* RPG_teleporter;


hgeSprite* bonus_this;
hgeSprite* bonus_shilo;

hgeSprite* bonus_this_text;
hgeSprite* bonus_shilo_text;
hgeSprite* bonus_daun_text;
hgeSprite* bonus_ulitka_text;
hgeSprite* bonus_umnik_text;

hgeSprite* bonus_shilo_status;
hgeSprite* bonus_daun_status;
hgeSprite* bonus_ulitka_status;
hgeSprite* bonus_umnik_status;

hgeSprite* krovyak1; //при попадании
hgeSprite* krovyak2;
hgeSprite* krovyak3;

hgeSprite* krovyak_shot1;

hgeSprite* krovyak_plyam1;
hgeSprite* krovyak_plyam2;
hgeSprite* krovyak_plyam3;

hgeSprite* krovyak_luzha1;


hgeSprite* krovyak_myaso1;
hgeSprite* krovyak_myaso2;
hgeSprite* krovyak_myaso3;
hgeSprite* krovyak_myaso4;
hgeSprite* krovyak_myaso5;


hgeSprite* krovyak_zayac_noga1;
hgeSprite* krovyak_zayac_noga2;
hgeSprite* krovyak_zayac_noga3;
hgeSprite* krovyak_zayac_noga4;

hgeSprite* krovyak_zayac_rebra1;
hgeSprite* krovyak_zayac_rebra2;


hgeSprite* krovyak_vzriv1;
/*ТИПЫ ТРУПОВ
1-ЗАЯЦ 1
2-УШИ(АНИМЕ)
3-УШИ(СПРАЙТ)
300-ВСПЛЕСК ОТ ВЗРЫВА1
301-ВСПЛЕСК ОТ ВЗРЫВА1/2
330-ВСПЛЕСК БОШКИ ПТЕНЦА1
400-КРОВЯК1
401-КРОВЯК2
402-КРОВЯК3
500-МЯСО1
501-МЯСО2
502-МЯСО3
503-МЯСО4
504-МЯСО5
505-ЗАЯЧЬИ РЕБРА1
506-ЗАЯЧЬИ РЕБРА2
507-ЗАЯЧЬЯ НОГА1
508-ЗАЯЧЬЯ НОГА2
509-ЗАЯЧЬЯ НОГА3
510-ЗАЯЧЬЯ НОГА4
511-МЕДВЕЖЬЯ БОШКА1
6-БОШКА
7-БОШКА БЕЗ УШЕЙ
800-ПЛЯМ 1
801-ПЛЯМ 2
802-ПЛЯМ 3
9-ЛУЖА 1 
10-ВОЛК 1
20-МЕДВЕД 1
30-ПТЕНЕЦ 1
31-ЛЕТУЧИЙ ПТЕНЕЦ=)

ТИПЫ БОНУСОВ
0-ВОПРОС
1-ШИЛО
*/






// Handle for a sound effect
HEFFECT menu_sound;
HEFFECT menu_choose;

HEFFECT snd;
HEFFECT ak_reload1;
HEFFECT ak_reload2;
HEFFECT pm_fire;
HEFFECT pm_reload1;
HEFFECT pm_reload2;
HEFFECT pp19_fire;
HEFFECT pp19_reload1;
HEFFECT pp19_reload2;
HEFFECT fn_f2000_fire;
HEFFECT tt_fire;
HEFFECT mac_fire;
HEFFECT mac_reload1;
HEFFECT mac_reload2;
HEFFECT webley_fire;
HEFFECT webley_reload1;
HEFFECT webley_reload2;
HEFFECT fn_five_seven_fire;
HEFFECT milkor_fire;
HEFFECT winch_fire;
HEFFECT rocket_fire;
HEFFECT rocket2_fire;
HEFFECT rocket_polet;
HEFFECT rocket2_polet;
HEFFECT drob_reload1;
HEFFECT drob_pompa;

HEFFECT vzriv_grena1;

HEFFECT myaso_upalo1;
HEFFECT myaso_upalo2;
HEFFECT myaso_upalo3;
HEFFECT myaso_upalo4;
HEFFECT myaso_upalo5;
HEFFECT myaso_upalo6;
HEFFECT myaso_upalo7;
HEFFECT myaso_upalo8;

HEFFECT myaso_razriv_user1;
HEFFECT myaso_razriv_user2;

HEFFECT shot1;
HEFFECT headshot1;
HEFFECT headshot2;
HEFFECT headshot3;
HEFFECT headshot4;
HEFFECT headshot5;
HEFFECT headshot6;
HEFFECT headshot7;
HEFFECT headshot8;

HEFFECT ssik1;
HEFFECT ssik2;
HEFFECT ssik3;
HEFFECT ssik4;

HEFFECT ptenec_death1;


HTEXTURE    oblaka1_tex;

HTEXTURE    alkash1_tex;
HTEXTURE    derevo1_tex;
HTEXTURE    penek1_tex;

HTEXTURE    znak_polputi_tex;

HTEXTURE    polosa_finish_tex;


HTEXTURE    ak; //автомат ак 47
HTEXTURE    ak2;
HTEXTURE    ak_upgraded;
HTEXTURE    ak2_upgraded;
HTEXTURE    w_pm_tex; //пистолет Макарова
HTEXTURE    w_pp19_vityaz_tex; //ПП19-01 "Витязь"
HTEXTURE    w_fn_f2000_tex;
HTEXTURE    w_fn_f2000_upgraded_tex;
HTEXTURE    w_tt_tex;
HTEXTURE    w_rpk_tex;
HTEXTURE    w_mac_tex;
HTEXTURE    w_winchester_tex;
HTEXTURE    w_winchester_anime_tex;
HTEXTURE    w_rpk47_tex;
HTEXTURE    w_glok_tex;
HTEXTURE    w_glok2_tex;
HTEXTURE    w_rgd5_tex;
HTEXTURE    katana_udar_sleva_tex;
HTEXTURE    w_milkor_tex;
HTEXTURE    w_granata_podstvol_tex;
HTEXTURE    w_panzer_tex;
HTEXTURE    w_panzer_out_tex;
HTEXTURE    w_granata_panzer_tex;
HTEXTURE    w_webley_tex;
HTEXTURE    w_fn_five_seven_tex;
HTEXTURE    w_qlz87_pushka_tex;
HTEXTURE    w_qlz87_trenoga_tex;
HTEXTURE    ogon1; 
HTEXTURE    player1_myasnik_tex;
HTEXTURE    player1_strelok_tex;
HTEXTURE    player1_razrushitel_tex;
HTEXTURE    player1_tehnik_tex;
HTEXTURE    player1_myasnik_gogranata_ruka1_tex;
HTEXTURE    player1_myasnik_gogranata_ruka2_tex;
HTEXTURE    player1_strelok_gogranata_ruka1_tex;
HTEXTURE    player1_strelok_gogranata_ruka2_tex;
HTEXTURE    player1_razrushitel_gogranata_ruka1_tex;
HTEXTURE    player1_razrushitel_gogranata_ruka2_tex;
HTEXTURE    player1_tehnik_gogranata_ruka1_tex;
HTEXTURE    player1_tehnik_gogranata_ruka2_tex;
HTEXTURE    player1_myasnik_ruka1_udar_sleva_tex;
HTEXTURE    player1_strelok_ruka1_udar_sleva_tex;
HTEXTURE    player1_razrushitel_ruka1_udar_sleva_tex;
HTEXTURE    player1_tehnik_ruka1_udar_sleva_tex;
HTEXTURE    player1_myasnik_ruka1_pistol_tex;
HTEXTURE    player1_strelok_ruka1_pistol_tex;
HTEXTURE    player1_razrushitel_ruka1_pistol_tex;
HTEXTURE    player1_tehnik_ruka1_pistol_tex;
HTEXTURE    player1_myasnik_ruka1_vintovka_tex;
HTEXTURE    player1_strelok_ruka1_vintovka_tex;
HTEXTURE    player1_razrushitel_ruka1_vintovka_tex;
HTEXTURE    player1_tehnik_ruka1_vintovka_tex;
HTEXTURE    player1_myasnik_ruka1_winch_tex;
HTEXTURE    player1_strelok_ruka1_winch_tex;
HTEXTURE    player1_razrushitel_ruka1_winch_tex;
HTEXTURE    player1_tehnik_ruka1_winch_tex;
HTEXTURE    player2_strelok_tex;
HTEXTURE    player2_gogranata_ruka1_tex;
HTEXTURE    player2_gogranata_ruka2_tex;
HTEXTURE    player2_strelok_ruka1_udar_sleva_tex;
HTEXTURE    player2_strelok_ruka1_pistol_tex;
HTEXTURE    player2_strelok_ruka1_vintovka_tex;
HTEXTURE    zayac_go_tex; //заяц
HTEXTURE    zayac_go_bezuh_tex; //заяц без ух
HTEXTURE    zayac_uhi_tex; //ухи зайца (анимация)
HTEXTURE    zayac_uhi_s_tex;//ухи зайца (спрайт)
HTEXTURE    zayac_uhi_k_tex;//ухи зайца (конец)
HTEXTURE    zayac_boshka_tex;
HTEXTURE    zayac_boshka_bezuh_tex;
HTEXTURE    volk_go_tex;
HTEXTURE    volk_trup1_a_tex;
HTEXTURE    volk_trup1_b_tex;
HTEXTURE    volk_trup1_c_tex;
HTEXTURE    medved_go_tex;
HTEXTURE    ptenec_go_tex;
HTEXTURE    ptenec_wait_tex;
HTEXTURE    ptenec_vpolete_tex;
HTEXTURE    ptenec_vpolete_reverse_tex;
HTEXTURE    ptenec_trup1_tex;
HTEXTURE    ptenec_boshka_vzriv1_a_tex;
HTEXTURE    ptenec_boshka_vzriv1_b_tex;
HTEXTURE    ptenec_boshka_vzriv1_c_tex;
HTEXTURE    ptenec_boshka_vzriv1_d_tex;
HTEXTURE    ptenec_boshka_vzriv1_e_tex;
HTEXTURE    RPG_healer_tex;
HTEXTURE    RPG_illusionist_tex;
HTEXTURE    RPG_teleporter_tex;
HTEXTURE    bonus_this_tex;
HTEXTURE    bonus_shilo_tex;
HTEXTURE    bonus_this_text_tex;
HTEXTURE    bonus_shilo_text_tex;
HTEXTURE    bonus_daun_text_tex;
HTEXTURE    bonus_ulitka_text_tex;
HTEXTURE    bonus_umnik_text_tex;
HTEXTURE    bonus_shilo_status_tex;
HTEXTURE    bonus_daun_status_tex;
HTEXTURE    bonus_ulitka_status_tex;
HTEXTURE    bonus_umnik_status_tex;
HTEXTURE    blood1_tex;
HTEXTURE    blood2_tex;
HTEXTURE    blood3_tex;
HTEXTURE    blood_shot1_tex;
HTEXTURE    blood_plyam1_tex;
HTEXTURE    blood_plyam2_tex;
HTEXTURE    blood_plyam3_tex;
HTEXTURE    blood_luzha1_tex;
HTEXTURE    blood_myaso1_tex;
HTEXTURE    blood_myaso2_tex;
HTEXTURE    blood_myaso3_tex;
HTEXTURE    blood_myaso4_tex;
HTEXTURE    blood_myaso5_tex;
HTEXTURE    blood_zayac_noga1_tex;
HTEXTURE    blood_zayac_noga2_tex;
HTEXTURE    blood_zayac_noga3_tex;
HTEXTURE    blood_zayac_noga4_tex;
HTEXTURE    blood_zayac_rebra1_tex;
HTEXTURE    blood_zayac_rebra2_tex;
HTEXTURE    blood_vzriv1_a_tex;
HTEXTURE    blood_vzriv1_b_tex;
HTEXTURE    blood_vzriv1_c_tex;
HTEXTURE    blood_vzriv1_d_tex;
HTEXTURE    blood_vzriv1_e_tex;
HTEXTURE    blood_vzriv1_e2_tex;
HTEXTURE    fon1_tex;
HTEXTURE    fon2_tex;
HTEXTURE    fon3_tex;
HTEXTURE    zayac_trup1_a_tex;
HTEXTURE    zayac_trup1_b_tex;
HTEXTURE    zayac_trup1_c_tex;
HTEXTURE    zayac_trup1_d_tex;
HTEXTURE    zayac_trup1_a_bezuh_tex;
HTEXTURE    zayac_trup1_b_bezuh_tex;
HTEXTURE    zayac_trup1_c_bezuh_tex;
HTEXTURE    zayac_trup1_d_bezuh_tex;
HTEXTURE    zayac_trup1_a_bezboshki_tex;
HTEXTURE    zayac_trup1_b_bezboshki_tex;
HTEXTURE    zayac_trup1_c_bezboshki_tex;
HTEXTURE    zayac_trup1_d_bezboshki_tex;

HTEXTURE    medved_trup1_a_tex;
HTEXTURE    medved_trup1_b_tex;
HTEXTURE    medved_trup1_c_tex;
HTEXTURE    medved_trup1_d_tex;
HTEXTURE    medved_trup1_e_tex;
HTEXTURE    medved_trup1_f_tex;
HTEXTURE    medved_trup1_a_bezboshki_tex;
HTEXTURE    medved_trup1_b_bezboshki_tex;
HTEXTURE    medved_trup1_c_bezboshki_tex;
HTEXTURE    medved_trup1_d_bezboshki_tex;
HTEXTURE    medved_trup1_e_bezboshki_tex;
HTEXTURE    medved_trup1_f_bezboshki_tex;
HTEXTURE    medved_boshka1_tex;

HTEXTURE    galka_tex;
HTEXTURE    galka_menu_tex;
HTEXTURE    strelka_menu_tex;
HTEXTURE    strelka_menu_D_tex;

HTEXTURE znak_myasnik_tex;
HTEXTURE znak_strelok_tex;
HTEXTURE znak_razrushitel_tex;
HTEXTURE znak_tehnik_tex;


HTEXTURE    status_opit_tex;
HTEXTURE    status_udar_tex;
HTEXTURE    status_status_tex;
HTEXTURE    opit_okno_vibora_tex;
HTEXTURE    okno_lvl_progress_tex;
HTEXTURE    okno_lvl_progress_red_tex;
HTEXTURE    okno_lvl_progress_green_tex;
HTEXTURE    okno_lvl_polzunok_tex;
char* str1;
int X=0;
int Xz=0;
bool afk1,afk2,lvl_go1,lvl_go2,lvl_back1,lvl_back2;


bool TEST_REZHIM=false;

bool PAUSE=false;
bool pobeda=false;
bool porazhenie=false;
int pobeda_time;

int leveltime=0;

int kills;
int kills2;
int points1=0;
int points2=0;

int kills_zayac,kills_volk,kills_medved,kills_zayac_vschiii,kills_zayac_bezuh,kills_zayac_bezboshki;
int kills2_zayac,kills2_volk,kills2_medved,kills2_zayac_vschiii,kills2_zayac_bezuh,kills2_zayac_bezboshki;

float procent_kills_zayac_bezuh,procent_kills_zayac_bezboshki,procent_kills_zayac_vschiii;
float procent_kills2_zayac_bezuh,procent_kills2_zayac_bezboshki,procent_kills2_zayac_vschiii;
int LIVES=5;


int DIFF=1;
bool DIFF_UP=true;
bool DIFF_UPGRADED=false;
int n_zayac_up=0;
int n_zayac_down=0;
int n_volk_up=0;
int n_volk_down=0;
int n_medved_up=0;
int n_medved_down=0;
bool zayac_must_down=false;
bool volk_must_down=false;
bool medved_must_down=false;



int lvl1_lenght=8400;


int pause_time_sec=0;
float pause_time=0;

int pause_start_time_sec;
float pause_start_time;
bool pause_time_minus;


 




//СИСТЕМА КЛАССОВ
bool CLASSMOD=true;
int class1=2;
int class2=2;
int player_vibor=0;

//мясник
int primanka1=0;
int mosch1=0;
int primanka2=0;
int mosch2=0;


//стрелок
float tochnost1=1;
float tochnost2=1;

int postroenie1=0;
int postroenie2=0;

//подрывник
float vinoslivost1=1;
float vinoslivost2=1;

int vzrivchatka1=0;
int vzrivchatka2=0;
//техник
int modifikacii1=0;
int modifikacii2=0;

int technika1=0;
int technika2=0;




//СИСТЕМА КЛАССОВ




//РПГ-МОД
bool RPGMOD=true;



float status1x=1168;
float status1y=140;
float status2x=1168;
float status2y=510;

int status_queue1=0;
int status_queue2=0;

bool status_queue1_block=false;
bool status_queue2_block=false;

float opit1=0;
float opit2=0;

int LVL1=1;
int LVL2=1;

bool lvl1_ready=false;
bool lvl2_ready=false;

bool lvl1_vibor=false;
bool lvl2_vibor=false;


float lvl1_mig_time,lvl1_mig_time_milli;
float lvl2_mig_time,lvl2_mig_time_milli;

int lvl1_mig,lvl2_mig;

int attack1=0;
int attack2=0;
int luck1=0;
int luck2=0;
int skorost1=100;
int skorost2=100;








int daun1=1;
int daun2=1;
int umnik1=0;
int umnik2=0;




int weapon1_fire=0;
int weapon2_fire=0;


int opit_points1=0;
int opit_points2=0;
int naviki_points1=0;
int naviki_points2=0;


//прогресс опыта
float opit1_x2=970;
float opit2_x2=970;


int VIBOR=0;
int VIBOR_ITEM=1;

bool vibor_block=false;
int vibor_time;
float vibor_time_milli;

bool viborchange_block=false;
int viborchange_time;
float viborchange_time_milli;

bool lvl_key_block=false;
int  lvl_key_time;
float lvl_key_time_milli;

int opit_lvl[1000];
//{1000,1500,2500,4000,6000,8500,11500,15000,19000,23500,28500,34000,40000,46500,53500,61000,69000};

int defence_zayac=0;
int defence_volk=10;
int defence_medved=25;

bool rpg_healers=false;
bool rpg_illusionists=false;
bool rpg_teleporters=false;


int defence_upgrade_sec;
//ЗАКРЫТИЕ РПГ-МОДА

int schi=1;
int video_size;

int menu_aktive=1;
int game_start=0;

int player2_aktive=0;

int volume=100;


//переменные для перезарядки
int perez_akt=0;
float perez_akt_milli;
float perez_time; //точное время перезарядки (сек)
float perez_time_milli;//точно время перезарядки (миллисек)

int time_was=0;
int time_now=0;

int time;
int t;
bool reload=false;
bool reload2=false;
float perez_time2; //точное время перезарядки (сек)
float perez_time_milli2;//точно время перезарядки (миллисек)
float pompa_time;
float pompa_time_milli;
float pompa_time2;
float pompa_time_milli2;
int pompa_akt1=0;
int pompa_akt2=0;

//св-ва оружий. формат: АК,ПМ,ПП-19'Витязь',FN_F2000,TT,РПК,MAC,WINCHESTER,РПК47,ГЛОК,РГД-5,катана,MILKOR-MGL,
					//   0  1       2          3     4   5   6      7        8    9	    10     11      12     
//Panzerfaust3, Webley mk4, FN Five-Seven
//     13           14           15
int oboim[16]={30,8,30,30,8,45,50,8,75,17,1,0,6,1,6,20};
int oboim2[16]={30,8,30,30,8,45,50,8,75,17,1,0,6,1,6,20};
int oboima_alt[16]={1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0};
int oboima2_alt[16]={1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0};
int damage[16]={70,20,40,55,30,72,35,75,72,20,300,20,270,550,50,32};
float weight[16]={3,0.4f,2.2f,3.6f,0.5f,4.5f,2,3.2f,4.8f,0.7f,0.2f,0.5f,5.3f,8,0.7f,0.5f};
//            ак пм  пп19 ф2000  ТТ   рпк   мас  winch рпк47  глок ргд-5 катана MILKOR-MGL P3 Wmk4  FN5-7
int cena[16]={15000,0,7500,27500,1000,24000,5000,7500,22000,1500,3500,3000,20000,40000,2000,3000};
int cena_up[2]={12500,9000};
int reload_time[16]={2,1,1,2,1,3,1,0,3,1,0,0,0,3,1,1};
int reload_time_milli[16]={0,0,500,0,0,0,500,0,0,0,0,500,0,0,0,0};
float weapon_x1[16];
float weapon_y1[16];
float weapon_x2[16];
float weapon_y2[16];
float weapon2_x1[16];
float weapon2_y1[16];
float weapon2_x2[16];
float weapon2_y2[16];
float w_x1[16]={-55,-32,-46,-60,-35,-72,-30,-72,-73,-35,0,0,-60,-70,-40,-35};
float w_y1[16]={-15,-12,-15,-22,-13,-15,-15,-15,-15,-13,0,0,-20,-21,-16,-14};
float w_x2[16]={  8, -7,  7,  4, -7, 10,  3, 14,  9, -7,0,0, 10, 30, -8, -7};
float w_y2[16]={ 10,  8, 13,  6,  8, 12, 15,  9, 25,  8,0,0,  4,  4,  2,  5};


int radius_vzriva[4]={0,200,200,350};
int damage_gren[4]={0,300,270,500};

int random_rasst_min[16]={400,200,300,450,250,400,300,0,350,250,0,0,0,0,350,350};
int random_rasst_max[16]={600,400,500,650,500,500,450,0,450,400,0,0,0,0,500,500};
float random_value1[16]={5,6,5,3,5.5f,5.5f,5.5f,0,6,6,0,0,0,0,6,4};
float random_value2[16]={9,12,10,6,11,9,12,0,10,11.5f,0,0,0,0,12,10};

float w_opit_zayac[16]={1.2f,2,1.4f,0.8f,1.8f,1,1.6f,1.2f,1,2,1.5f,1.6f,1,0.8f,1.4f,1.2f};
float w_opit_zayac_vschiii[16]={1.2f,2,1.4f,0.8f,1.8f,1,1.6f,1,1,2,1.5f,1.6f,1,1,1.2f,1.4f};
float w_opit_volk[16]={1.2f,2,1.4f,0.8f,1.8f,1,1.6f,1,1,2,1.5f,1.8f,1.2f,1,1.5f,1.5f};
float w_opit_medved[16]={1.2f,2,1.4f,0.8f,1.8f,1,1.6f,1,1,2,1.8f,2,1.4f,1,1.8f,1.6f};

float vistrel_time;
int vistrel_time_sec;

float vistrel2_time;
int vistrel2_time_sec;


//переменные для смены оружия
int last_weapon1,pred_weapon1,weapon1_change,weapon1_buy;
float weapon1_change_time;
int weapon1_change_time_sec;

bool w1_buy[16];

bool w2_buy[16];


bool ak_buy=false;
bool pp19_buy=false;
bool fn_f2000_buy=false;
bool tt_buy=false;
bool rpk_buy=false;
bool mac_buy=false;
bool winchester_buy=false;
bool rpk47_buy=false;
bool glok_buy=false;
bool rgd5_buy=false;
bool katana_buy=false;
bool milkor_buy=false;
bool panzer_buy=false;
bool webley_buy=false;
bool fn_five_seven_buy=false;

bool ak_up=false;
bool fn_f2000_up=false;
//переменные для смены оружия игрока 2
int last_weapon2,pred_weapon2,weapon2_change,weapon2_buy;
float weapon2_change_time;
int weapon2_change_time_sec;
bool ak_buy2=false;
bool pp19_buy2=false;
bool fn_f2000_buy2=false;
bool tt_buy2=false;
bool rpk_buy2=false;
bool mac_buy2=false;
bool winchester_buy2=false;
bool rpk47_buy2=false;
bool glok_buy2=false;
bool rgd5_buy2=false;
bool katana_buy2=false;
bool milkor_buy2=false;
bool panzer_buy2=false;
bool webley_buy2=false;
bool fn_five_seven_buy2=false;

bool ak_up2=false;
bool fn_f2000_up2=false;


int menu1_on=0;
int pistol1=1;
int drob1,smg1,avtomat1,pulemet1,granatomet1,vintovka1,holodnoe1,spec1;

int menu2_on=0;
int pistol2=1;
int drob2,smg2,avtomat2,pulemet2,granatomet2,vintovka2,holodnoe2,spec2;


int GAME_PROGRESS=0;
int sit1=0;


// игрок1
float x=1000.0f, y=450.0f;
//и все что нужно для его движения
float dx=0.0f, dy=0.0f;
float speed=skorost1;
const float tormoz=0.89f;

float afx;
float afX;

// игрок2
float x2=1000.0f, y2=600.0f;
//и все что нужно для его движения
float dx2=0.0f, dy2=0.0f;
float speed2=skorost2;
const float tormoz2=0.89f;

float afx2;
float afX2;


//координаты огня пули игрока1
float a;
float b;
//координаты для РГД5 игрока1
float rgd5x1,rgd5y1,rgd5x2,rgd5y2;
//координаты для катаны игрока1
float katanax1,katanay1,katanax2,katanay2;
//координаты огня пули игрока2
float a2;
float b2;
//координаты для РГД5 игрока2
float rgd52x1,rgd52y1,rgd52x2,rgd52y2;
//координаты для катаны игрока2
float katana2x1,katana2y1,katana2x2,katana2y2;
int oboima;//кол-во пуль в обойме игрока 1
int oboima_akt;
int oboima2;//кол-во пуль в обойме игрока 2
int oboima2_akt;
//пуля
float px;
float py;
//пуля2
float p2x;
float p2y;
//дробь
float p1d1x,p1d1y;
float p1d2x,p1d2y;
float p1d3x,p1d3y;
float p1d4x,p1d4y;
//дробь2
float p2d1x,p2d1y;
float p2d2x,p2d2y;
float p2d3x,p2d3y;
float p2d4x,p2d4y;
int aktivatorp=0;
int aktivatorp1d1=0;
int aktivatorp1d2=0;
int aktivatorp1d3=0;
int aktivatorp1d4=0;
int aktivatorgren=0;
int p_vistrel;
float p_ogon_ms;
int p_ogon_s;
int ak_tex;
int aktivatorp2=0;
int aktivatorp2d1=0;
int aktivatorp2d2=0;
int aktivatorp2d3=0;
int aktivatorp2d4=0;
int aktivatorgren2=0;
int p_vistrel2;
float p_ogon_ms2;
int p_ogon_s2;
int ak2_tex;



//ЗВУКИ
int headshotPan;
int player1Pan;
int player2Pan;
int myasoupaloPan;
int myasorazrivPan;



//враг

#define MAX_ZAYAC 29
#define MAX_VOLK 20
#define MAX_MEDVED 20
#define MAX_PTENEC 20
#define MAX_TRUPS 5000
#define MAX_UHI 200
#define MAX_BLOOD 500
#define MAX_HEAD 200
#define MAX_GILZ 200
#define MAX_BONUS 200
#define MAX_BONUSTEXT 200
#define MAX_BONUSI 200
#define MAX_BONUSSTATUS 50
#define MAX_MYASO 2000
#define MAX_GREN 100
#define MAX_KILLS 100000
#define NET_STARTGAME 0x04
int N_ZAYAC;
int N_UHI;
int N_VOLK;
int N_MEDVED;
int N_PTENEC;
int N_TRUPS;
int NUMBER_TRUPS;
int N_BLOOD;
int NUMBER_BLOOD;
int N_HEAD;
int N_GILZ;
int N_BONUS;
int N_BONUSTEXT;
int N_BONUS1;
int N_BONUS2;
int N_BONUSSTATUS1;
int N_BONUSSTATUS2;
int N_MYASO;
int N_OBJECTS=26;//1 знак 5 пней и 20 деревьев
int N_Y;
int N_GREN;
int N_KILLS;


int N_WEAPON1=1;
int N_WEAPON2=1;


int ppp;
int bonus;

int shot=0;
int headshotRand;
int ssikRand;
int myaskoRand;
int razrivRand;
int myaskoSsit;






struct spriteObject  //ТРУПЫ--------------------
{
	float posX,posY;
	float posX2,posY2;
	
	float posX_s,posX2_s;
	float posX_X,posX2_X;

	int type;
	int aktiv;
	int frame;
	int frame_akt;
	float killtime;
	int killtime_sec;
	DWORD color;
	HTEXTURE trup_tex;
	float rot;
	float scaleX;
	float scaleY;
	int vrag;
	
};


int peregruzheno=0;
spriteObject*	trupsObjects;

struct zayacObject  //ЗАЙЦЫ---------------------
{ float v1x,v1y;
int bezuh;
int bezboshki;
int ubit;
int pokoin;
int health;
int killed_by;
float timeout_milli,timeout;
float speed;
int defence;
float kill_time;
int kill_time_sec;
int object_id;
int A;
bool vzorvan;					
float energy;
float rasstX,rasstY;
int chetvert;
int RPG_healer;
int RPG_illusionist;
float ill1_x,ill1_y,ill2_x,ill2_y;
int ill1_active,ill2_active;
int RPG_teleporter;
float teleportx;
int teleported;

};

zayacObject*   vragi1Objects;

struct uhiObject    //УШИ---------------------
{
	float uhix,uhiy;
	float niz;
    float gradus;
	float akt;
};



uhiObject*    uhiObjects;

struct volkObject //ВОЛКИ----------------------
{
float v2x,v2y;
int ubit;
int health;
int killed_by;
float timeout_milli,timeout;
float speed;
int defence;
int object_id;
int RPG_healer;
int RPG_illusionist;
float ill1_x,ill1_y,ill2_x,ill2_y;
int ill1_active,ill2_active;
int RPG_teleporter;
float teleportx,teleporty;
int teleported;
};

volkObject* vragi2Objects;

struct medvedObject //МЕДВЕДИ----------------------
{
float v3x,v3y;
int ubit;
int health;
int killed_by;
int bezboshki;
float timeout_milli,timeout;
float speed;
int defence;
int object_id;
int RPG_healer;
int RPG_illusionist;
float ill1_x,ill1_y,ill2_x,ill2_y;
int ill1_active,ill2_active;
int RPG_teleporter;
float teleportx,teleporty;
int teleported;
};

medvedObject* vragi3Objects;

struct ptenecObject //ПТЕНЦЫ!!!----------------------
{
float v4x,v4y;
float gradus;
float gradusNext;
int wait;
int wait_time_sec;
int bezboshki;
int ubit;
int health;
int killed_by;
float timeout_milli,timeout;
float speed;
int defence;
int object_id;
int polet;
float rx,ry;
float r;
float speedX,speedY;
bool up;
bool kruzhit;
int zahod,chetvert,chetvert_n;
bool vzorvan;					
float energy;
float rasstX,rasstY;
int krug;
};

ptenecObject* vragi4Objects;


struct bloodObject  //КРОВЯК---------------------
{
float x1,y1,x2,y2;
int akt;
int faza;
int seed;
float blood_time;
int blood_time_sec;
float xstart,niz;
int vrag;
float x_random;


};

int peregruzheno_blood=0;

bloodObject* krovyakObjects;



struct headObject  //БОШКИ---------------------
{
float bx,by;
float niz;
float gradus;
float akt;
int bezuh;
int bzdik;
int seed;
int bzdik_seed;
int vrag;

};



headObject* boshkiObjects;




struct gilzaObject //ГИЛЬЗЫ----------------------
{
float x,y;
float niz;
float xstart;
int akt;
int type;
int randomx;
};

gilzaObject* gilziObjects;


struct bonusObject //БОНУСЫ----------------------
{
float x1,y1;
float x2,y2;
float x1_s,x1_X,x2_s,x2_X;
int akt;
int type;
int owner;
float appear_time,appear_time_milli;
float akt_time,akt_time_milli;
int spin;
bool visible;
int mig_akt;
float mig_time,mig_time_milli;
float shans;


};

bonusObject* bonusiObjects;

struct bonustextObject //ТЕКСТ БОНУСОВ----------------------
{
float x,y;
float x_s;
float x_X;
int akt;
int type;
int owner;
float akt_time,akt_time_milli;
};

bonustextObject* bonustextiObjects;

struct bonusZnach //ЗНАЧЕНИЯ БОНУСОВ----------------------
{
int znachenie;
int type;
int id;
};

bonusZnach* bonusi1;
bonusZnach* bonusi2;


struct bonusStatus //СТАТУС БОНУСОВ----------------------
{
int akt;
int type;
int id;
int queue;
};

bonusStatus* statusi1;
bonusStatus* statusi2;


struct myasoObject  //ЩИ!!!(МЯСО)---------------------
{
float x1,y1;
int akt;
int seed;
float myaso_time;
int myaso_time_sec;
float xstart,niz;
int type;
float gradus;
float scaleX;
float speedX;
float speedY;
int bzdik;
float energy;



};


myasoObject* myasko;



struct granataObject   //ГРАНАТЫ--------------------------
{
float x,y;
float osX,osY;
int napravlenie;
int owner;
int akt;
int type;
float speedX,speedY;
float gradus;
};


granataObject* granati;



struct fragObject //СТАТИСТИКА-------------------
{
int player;
int vrag;
bool headshot;
bool vschiii;
bool bezuh;
bool bezboshki;
int weapon;
};

fragObject* ubijstva;


struct fonObject  //ФОН--------------------
{float x,y;
int type;};

fonObject* FON;


struct Object //ОБЪЕКТЫ НА ФОНЕ--------------------------
{
float x,y;
int pl;
int type;
float wide,height;
};

Object* Objects;
/*ТИПЫ:
0 - ЗНАК ПОЛПУТИ
1 - ПЕНЬКИ
*/


struct ALL     //УСЁ ШО НАДО------
{
int type;
float y;
int id;
};

ALL* A;


struct YCOORD  //КООРДИНАТЫ ЫГРИК
{
float y;
int type;
int id;
int A;
};

YCOORD* Y;

float y_min;
int y_type;
int y_id;

HWND      main_window_handle = NULL;
HINSTANCE main_instance      = NULL;
WSADATA WsaData;
int connection=WSAStartup (0x0202, &WsaData);	
bool connection_error=false;
SOCKET s[6]; //s[0] - server,s[1] - view of client by s[0],s[2] - server's client,s[3] - view of client by s[5],
//s[4] - client, s[5] = client's server
sockaddr_in server; //s[0]
sockaddr_in you; //s[4]
sockaddr_in client[1];// адрес клиента
int addr_size = sizeof (sockaddr);
int In=0;//от перенаселения
int ip[4]={127,0,0,1};
int n_ip=0;
char adress[16];
char buff[80];//текстовый буфер для сообщений об ошибке
bool srvr=false;//зацикливаем сервер...
bool clnt=false;//зацикливаем клиент...
int net_user=0;

char net_status[]="[статус сети]                                   ";//статус сети (спасибо Кэп)

int received=0;
int sleep_sec=0;
int net_faza=1;
char dataBuffer [496];
char sendBuffer [62][8];
char recvBuffer [62][8];

float GetTime() //БЕРЕТ ТЕКУЩУЮ МИЛЛИСЕКУНДУ
{
	SYSTEMTIME SysTime;
	float tmp;

	GetLocalTime(&SysTime);
	tmp=SysTime.wMilliseconds;
	return tmp;
}





float GetCurrentSecond()//БЕРЕТ ТЕКУЩУЮ СЕКУНДУ
{
	SYSTEMTIME SysTime;
	float tm;

	GetLocalTime(&SysTime);
	tm=SysTime.wSecond;
	return tm;
}



LRESULT CALLBACK WindowProc(HWND hwnd, 
						    UINT msg, 
                            WPARAM wparam, 
                            LPARAM lparam)
{
// this is the main message handler of the system
//PAINTSTRUCT		ps;		// used in WM_PAINT
//HDC				hdc;	// handle to a device context
char txtbuffer[80];        // used to print strings

// what is the message 
switch(msg)
	{	
	case WM_CREATE: 
        {
		// do initialization stuff here
        // return success
		return(0);
		} break;
   
	/*case WM_PAINT: 
		{
		// simply validate the window 
   	    hdc = BeginPaint(hwnd,&ps);	 
        
        // end painting
        EndPaint(hwnd,&ps);

        // return success
		return(0);
		} break;*/

	case WM_DESTROY: 
		{

		// kill the application, this sends a WM_QUIT message 
		PostQuitMessage(0);
        // return success
		return(0);
		} break;

	case WM_KILLFOCUS:
		{
			if (PAUSE!=true)
				PAUSE = true;
			return 0;
		} break;

	case WM_SETFOCUS:
		{
			if (PAUSE==true)
			{
				PAUSE = false;
			}
			return 0;
		} break;
	case WM_SOCKET:
		{
			if (WSAGETSELECTERROR(lparam))
			{	// error!
				sprintf (txtbuffer,"Error2: %d",WSAGetLastError());
				MessageBox (main_window_handle,txtbuffer,"Error",MB_OK);
				PostQuitMessage (0);
				return 0;
			}
			switch (WSAGETSELECTEVENT(lparam))
			{
			case FD_READ:
				{
/*
if(net_user==1)
{
char dataBuffer [4];
char sendBuffer [32];
char recvBuffer [32];
recv (s[4],recvBuffer,32,0);
if(recvBuffer=="Игрок вышел из игры")
{strcpy(net_status,recvBuffer);
player2_aktive=0;}
}
*/
/*
if(net_user==2)
{
char dataBuffer [4];
char sendBuffer [32];
char recvBuffer [32];
//sprintf (dataBuffer,"%3d",(int)x2);
//sprintf (dataBuffer,"%3d",(int)y2);
//sprintf (dataBuffer,"%.3f",dx2);
//sprintf (dataBuffer,"%.3f",dy2);
//send (s[4],dataBuffer,32,0);
recv (s[4],recvBuffer,32,0);
x=atof(recvBuffer);
strcpy(net_status,recvBuffer);
}
*/
if(net_user==2)
{char dataBuffer [32];
char sendBuffer [2][16];
char recvBuffer [2][16];
received=recv (s[4],dataBuffer,32,0);
memcpy(recvBuffer,dataBuffer,32);
x=atof(recvBuffer[0]);
y=atof(recvBuffer[1]);
}
				} break;

case FD_WRITE:
{
	/*		
if(net_user==1)
{
char dataBuffer [4];
char sendBuffer [32];
char recvBuffer [32];	
sprintf (sendBuffer,"%d",(int)x);
//sprintf (dataBuffer,"%3d",(int)y);
//sprintf (dataBuffer,"%.3f",dx);
//sprintf (dataBuffer,"%.3f",dy);
send (s[1],sendBuffer,32,0);
//recv (s[0],dataBuffer,32,0);
}	*/	

if(net_user==1)
{char dataBuffer [32];
char sendBuffer [2][16];
char recvBuffer [2][16];
sprintf (sendBuffer[0],"%d",(int)x);
sprintf (sendBuffer[1],"%d",(int)y);
memcpy(dataBuffer,sendBuffer,32);
send (s[1],dataBuffer,32,0);
}	

}
				break;
			case FD_CLOSE:
				{	char dataBuffer [4];
					char sendBuffer [32];
					char recvBuffer [32];	
					// opponent quit
					//sprintf (txtbuffer,"%c%d",RPSS_QUIT,0);
					//send (s,txtbuffer,2,0);	// tell server that we quit
					if(net_user==1)
					{shutdown (s[0],SD_SEND);
					shutdown (s[1],SD_SEND);
					closesocket (s[0]);
					closesocket (s[1]);}
					if(net_user==2)
					{shutdown (s[4],SD_SEND);
					closesocket (s[4]);			
					sprintf (sendBuffer,"%c","Игрок вышел из игры");
					send (s[4],txtbuffer,32,0);	// tell server that we quit
					}
					PostQuitMessage (0);
					return 0;
				} break;
			}
		} break;
	default:break;

} // end switch

// process any messages that we didn't take care of 
return (DefWindowProc(main_window_handle, msg, wparam, lparam));

} // end WinProc




void Connect_Net()
{
if (hge->Input_GetKeyState(HGEK_UP)&&(int)GetTime()%25==0) 
{ip[n_ip]++;
if(ip[n_ip]>255)
{ip[n_ip]=0;}
}
if (hge->Input_GetKeyState(HGEK_DOWN)&&(int)GetTime()%25==0) 
{ip[n_ip]--;
if(ip[n_ip]<0)
{ip[n_ip]=255;}
}
if (hge->Input_GetKeyState(HGEK_LEFT)&&(int)GetTime()%100==0) 
{n_ip--;
if(n_ip<0)
{n_ip=3;}
}
if (hge->Input_GetKeyState(HGEK_RIGHT)&&(int)GetTime()%100==0) 
{n_ip++;
if(n_ip>3)
{n_ip=0;}
}

if (hge->Input_GetKeyState(HGEK_ENTER)) //enter
{
sprintf (adress,"%d.%d.%d.%d",(int)ip[0],(int)ip[1],(int)ip[2],(int)ip[3]);
you.sin_addr.s_addr = inet_addr (adress); //адрес - вводимый


if (connect(s[4],(LPSOCKADDR)&you,sizeof(you))==SOCKET_ERROR)
{
						if (WSAGetLastError()==WSAEWOULDBLOCK)
						{
							Sleep (750);
						    connect(s[4],(LPSOCKADDR)&you,sizeof(you));
							return;
						}
						sprintf (buff,"Error: %d",WSAGetLastError());
						MessageBox (main_window_handle,buff,"Error connection",MB_OK);
						PostQuitMessage (0);
						return;
}
strcpy(net_status,"Вы подключены!");
player2_aktive=1;
//sprintf (buff,"%c%d",RPSS_STARTGAME,0);
//send (s[4],buff,2,0);
/*
received=recv(s[4],dataBuffer,8,0);
memcpy(recvBuffer,dataBuffer,8);
net_user=atoi(recvBuffer[0]);

if(net_user==-1)
{

s[5]=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
server.sin_family=AF_INET;
server.sin_port=htons(5556);
server.sin_addr.s_addr=INADDR_LOOPBACK;

if(bind(s[5],(struct sockaddr*)&server.sin_addr,sizeof(server))==SOCKET_ERROR)
{
WSACleanup ();
strcpy(net_status,"Ошибка bind   clnt");
sprintf (buff,"Error: %d",WSAGetLastError());
MessageBox (main_window_handle,buff,"Error connection",MB_OK);
PostQuitMessage (0);
return ;
}
if(listen( s[0], 1)==SOCKET_ERROR) //ждём запроса на коннект от клиента
{//connection_error=true;
WSACleanup ();
strcpy(net_status,"Ошибка listen   clnt");
sprintf (buff,"Error: %d",WSAGetLastError());
MessageBox (main_window_handle,buff,"Error connection",MB_OK);
PostQuitMessage (0);
return ;}

while(In<1)
{
s[In+3] = accept (s[5],(struct sockaddr*)&client[In],&addr_size);
if (s[In+3]==INVALID_SOCKET)
{
		strcpy(net_status,"Ошибка сокета клиента");
		sprintf (buff,"Error: %d",WSAGetLastError());
		MessageBox (main_window_handle,buff,"Error connection",MB_OK);
		PostQuitMessage (0);
		WSACleanup ();
		return ;
}
		else
{
		strcpy(net_status,"Игрок подключен!");
		//char buffer[18];
		//sprintf (buffer,"Проверка связи %d",In+1);
		//send (s[In+1],buffer,18,0);
		In++;
}
}
}
*/
net_user=2;

player1_myasnik->Play();
player1_strelok->Play();
player1_razrushitel->Play();
player1_tehnik->Play();
PAUSE=false;
clnt=false;
return;
}//enter
}




void Init_Net()
{
hge->System_SetState(HGE_TITLE, "ЩИ!!! Версия 0.1.9 [Зависли пока не подключится 2-й игрок]");
if(listen( s[0], 1)==SOCKET_ERROR) //ждём запроса на коннект от клиента
{//connection_error=true;
WSACleanup ();
strcpy(net_status,"Ошибка listen   ");
sprintf (buff,"Error: %d",WSAGetLastError());
MessageBox (main_window_handle,buff,"Error connection",MB_OK);
PostQuitMessage (0);
return ;}

while(In<1)
{
s[In+1] = accept (s[0],(struct sockaddr*)&client[In],&addr_size);
if (s[In+1]==INVALID_SOCKET)
{
		strcpy(net_status,"Ошибка сокета клиента");
		sprintf (buff,"Error: %d",WSAGetLastError());
		MessageBox (main_window_handle,buff,"Error connection",MB_OK);
		PostQuitMessage (0);
		WSACleanup ();
		return ;
}
		else
{
		strcpy(net_status,"Игрок подключен!");
		//char buffer[18];
		//sprintf (buffer,"Проверка связи %d",In+1);
		//send (s[In+1],buffer,18,0);
		In++;
}
}

if(In==1)
{
hge->System_SetState(HGE_TITLE, "ЩИ!!! Версия 0.1.9 ");
player2_strelok->Play();

/*
sprintf(dataBuffer,"%d",net_user);
send(s[1],dataBuffer,8,0);
s[2]=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);//создаем сокет
WSAAsyncSelect(s[2],main_window_handle,WM_SOCKET,(FD_CLOSE | FD_CONNECT | FD_READ | FD_WRITE));//сокет серверного клиента асинхронный
you.sin_family = AF_INET;
you.sin_port = htons (5556);
you.sin_addr.s_addr = inet_addr("127.0.0.1");
if (connect(s[2],(LPSOCKADDR)&you,sizeof(you))==SOCKET_ERROR)
{
						if (WSAGetLastError()==WSAEWOULDBLOCK)
						{
							Sleep (750);
						    connect(s[2],(LPSOCKADDR)&you,sizeof(you));
							return;
						}
						sprintf (buff,"Error: %d",WSAGetLastError());
						MessageBox (main_window_handle,buff,"Error connection",MB_OK);
						PostQuitMessage (0);
						return;
}
*/
net_user=1;
player2_aktive=1;
srvr=false;
PAUSE=false;
return ;
}

}








int Close_Net()
{
if(net_user==1)
{closesocket (s[0]);
strcpy(net_status,"Сервер отключился.                 ");}
if(net_user==2)
{closesocket (s[4]);
strcpy(net_status,"Вы отключились от сервера.         ");}
WSACleanup ();
net_user=0;
player2_aktive=0;
return 0;
}





//------------------------------------------------------

void vistrel() //ЗВУК ВЫСТРЕЛА ИГРОКА 1
{
//float pitch=hge->Random_Float(0,0.002f);


if(N_WEAPON1==0||N_WEAPON1==5||N_WEAPON1==8)//выстрел из АК
{hge->Effect_PlayEx(snd,volume*8/10,player1Pan,0);}
if(N_WEAPON1==1||N_WEAPON1==9)
{hge->Effect_PlayEx(pm_fire,volume*8/10,player1Pan,0);}
if(N_WEAPON1==2)
{hge->Effect_PlayEx(pp19_fire,volume,player1Pan,0);}
if(N_WEAPON1==3)
{hge->Effect_PlayEx(fn_f2000_fire,volume,player1Pan,0);}
if(N_WEAPON1==4)
{hge->Effect_PlayEx(tt_fire,volume,player1Pan,0);}
if(N_WEAPON1==6)
{hge->Effect_PlayEx(mac_fire,volume,player1Pan,0);}
if(N_WEAPON1==7)
{hge->Effect_PlayEx(winch_fire,volume,player1Pan,0);}
if(N_WEAPON1==12)
{hge->Effect_PlayEx(milkor_fire,volume,player1Pan,0);}
if(N_WEAPON1==13)
{hge->Effect_PlayEx(rocket_fire,volume,player1Pan,0);}
if(N_WEAPON1==14)
{hge->Effect_PlayEx(webley_fire,volume,player1Pan,0);}
if(N_WEAPON1==15)
{hge->Effect_PlayEx(fn_five_seven_fire,volume,player1Pan,0);}

}

void vistrel2() //ЗВУК ВЫСТРЕЛА ИГРОКА 2
{
//float pitch=hge->Random_Float(0,0.002f);


if(N_WEAPON2==0||N_WEAPON2==5||N_WEAPON2==8)//выстрел из АК
{hge->Effect_PlayEx(snd,volume*8/10,player2Pan,0);}
if(N_WEAPON2==1||N_WEAPON2==9)
{hge->Effect_PlayEx(pm_fire,volume*8/10,player2Pan,0);}
if(N_WEAPON2==2)
{hge->Effect_PlayEx(pp19_fire,volume,player2Pan,0);}
if(N_WEAPON2==3)
{hge->Effect_PlayEx(fn_f2000_fire,volume,player2Pan,0);}
if(N_WEAPON2==4)
{hge->Effect_PlayEx(tt_fire,volume,player2Pan,0);}
if(N_WEAPON2==6)
{hge->Effect_PlayEx(mac_fire,volume,player2Pan,0);}
if(N_WEAPON2==7)
{hge->Effect_PlayEx(winch_fire,volume,player2Pan,0);}
if(N_WEAPON2==12)
{hge->Effect_PlayEx(milkor_fire,volume,player2Pan,0);}
if(N_WEAPON2==13)
{hge->Effect_PlayEx(rocket2_fire,volume,player2Pan,0);}
if(N_WEAPON2==14)
{hge->Effect_PlayEx(webley_fire,volume,player2Pan,0);}
if(N_WEAPON2==15)
{hge->Effect_PlayEx(fn_five_seven_fire,volume,player2Pan,0);}
}




void myasko_upalo()
{myaskoRand=hge->Random_Int(1,7);
switch(myaskoRand)
{case 1:hge->Effect_PlayEx(myaso_upalo1,volume*9/10,myasoupaloPan,0);
break;
case 2:hge->Effect_PlayEx(myaso_upalo2,volume*9/10,myasoupaloPan,0);
break;
case 3:hge->Effect_PlayEx(myaso_upalo3,volume*9/10,myasoupaloPan,0);
break;
case 4:hge->Effect_PlayEx(myaso_upalo4,volume*9/10,myasoupaloPan,0);
break;
case 5:hge->Effect_PlayEx(myaso_upalo5,volume*9/10,myasoupaloPan,0);
break;
case 6:hge->Effect_PlayEx(myaso_upalo6,volume*9/10,myasoupaloPan,0);
break;
case 7:hge->Effect_PlayEx(myaso_upalo7,volume*9/10,myasoupaloPan,0);
break;
case 8:hge->Effect_PlayEx(myaso_upalo8,volume*9/10,myasoupaloPan,0);
break;}	
}


void myasko_razriv()
{razrivRand=hge->Random_Int(1,2);
switch(razrivRand)
{case 1:hge->Effect_PlayEx(myaso_razriv_user1,volume*9/10,myasorazrivPan,0);
break;
case 2:hge->Effect_PlayEx(myaso_razriv_user2,volume*9/10,myasorazrivPan,0);
break;}
}



void headshot()
{headshotRand=hge->Random_Int(1,8);
switch(headshotRand)
{case 1:hge->Effect_PlayEx(headshot1,volume*9/10,headshotPan,0);
break;
case 2:hge->Effect_PlayEx(headshot2,volume*9/10,headshotPan,0);
break;
case 3:hge->Effect_PlayEx(headshot3,volume*9/10,headshotPan,0);
break;
case 4:hge->Effect_PlayEx(headshot4,volume*9/10,headshotPan,0);
break;
case 5:hge->Effect_PlayEx(headshot5,volume*9/10,headshotPan,0);
break;
case 6:hge->Effect_PlayEx(headshot6,volume*9/10,headshotPan,0);
break;
case 7:hge->Effect_PlayEx(headshot7,volume*9/10,headshotPan,0);
break;
case 8:hge->Effect_PlayEx(headshot8,volume*9/10,headshotPan,0);
break;
}	
}



void myasko_ssit()
{
ssikRand=hge->Random_Int(1,4);
switch(ssikRand)
{case 1:hge->Effect_PlayEx(ssik1,volume*9/10,headshotPan,0);
break;
case 2:hge->Effect_PlayEx(ssik2,volume*9/10,headshotPan,0);
break;
case 3:hge->Effect_PlayEx(ssik3,volume*9/10,headshotPan,0);
break;
case 4:hge->Effect_PlayEx(ssik4,volume*9/10,headshotPan,0);
break;}
}








void fire1()//ВЫСТРЕЛ!!!
{
	if(reload==false)
	{
	player1_ruka1_pistol->Play();
	
	vistrel();//звук выстрела

	if(N_WEAPON1!=10&&N_WEAPON1!=11&&N_WEAPON1!=12&&N_WEAPON1!=13)//огнестрельные
	{
	vistrel_time=GetTime();
	vistrel_time_sec=perez_akt;
	
		 aktivatorp=1;//вылетает пуля
		 pulya->SetColor(0xFFFFA000);//огонь из ствола
	

	if(N_WEAPON1==7)
	{pompa_time=perez_akt;
	pompa_time_milli=GetTime();
	pompa_akt1=1;
	dx+=3;
	aktivatorp1d1=1;
	aktivatorp1d2=1;
	aktivatorp1d3=1;
	aktivatorp1d4=1;	
	}
	gilziObjects[N_GILZ].x=x-24;
	gilziObjects[N_GILZ].y=y-9;
	gilziObjects[N_GILZ].niz=y+60;
	gilziObjects[N_GILZ].xstart=x-24;
	gilziObjects[N_GILZ].randomx=hge->Random_Int(10,20);

	

	switch(N_WEAPON1)
	{case 1:
	case 4:
	case 9:
	case 14:
	case 15:
	gilziObjects[N_GILZ].type=1;
	break;
	case 0:
	case 2:
	case 3:
	case 5:
	case 6:
	case 7:
	case 8:
	gilziObjects[N_GILZ].type=2;
	break;}
	
	gilziObjects[N_GILZ].akt=1;

	N_GILZ++;


	if(N_GILZ>=MAX_GILZ-1)
	{N_GILZ=0;}


	}//огнестрельные




	if(N_WEAPON1==10)
	{aktivatorgren=1;
	vistrel_time=GetTime();
	vistrel_time_sec=perez_akt;
	oboima--;
	reload=true;
	granati[N_GREN].x=x+5;
	granati[N_GREN].y=y-44;
	granati[N_GREN].osY=y+48+dy*75;
	if(granati[N_GREN].osY<100)
	{granati[N_GREN].osY=100;}
	granati[N_GREN].osX=x-250+dx*75;
	if(dy<0)
	{granati[N_GREN].osX+=dy*40;//кидаем вверх- дальше (чтоб не было багов)
	if(dx>0)
	{granati[N_GREN].osX-=dx*40;}//при беге назад кидаем дальше (опять же чтоб не было багов)
	if(dx<0)
	{granati[N_GREN].osX-=dx*20;}}//при беге вперед кидаем ближе (чтоб не было жирно)
	if(dy>0)
	{granati[N_GREN].osX+=dy*35;}//кидаем вниз- ближе (баланс с состоянием без ускорения по оси Y)
	granati[N_GREN].owner=1;
	granati[N_GREN].akt=1;
	granati[N_GREN].type=1;
	granati[N_GREN].speedX=6;
	granati[N_GREN].speedY=0.018f;
	N_GREN++;
	if(N_GREN>=MAX_GREN-1)
	{N_GREN=0;}
	}

	if(N_WEAPON1==12)
	{aktivatorgren=1;
	vistrel_time=GetTime();
	vistrel_time_sec=perez_akt;
	oboima--;
	granati[N_GREN].x=x-55;
	granati[N_GREN].y=y-9;
	granati[N_GREN].osY=y-9+dy*100;
	if(granati[N_GREN].osY<100)
	{granati[N_GREN].osY=100;}
	granati[N_GREN].osX=x-505;
	if(dy<0)
	{granati[N_GREN].osX+=dy*175;//кидаем вверх- дальше (чтоб не было багов)
	if(dx>0)
	{granati[N_GREN].osX-=dx*20;}//при беге назад кидаем дальше (опять же чтоб не было багов)
	//if(dx<0)
	//{granati[N_GREN].osX-=dx*20;}//при беге вперед кидаем ближе (чтоб не было жирно)
	}
	if(dy>0)
	{granati[N_GREN].osX+=dy*275;}//кидаем вниз- ближе (баланс с состоянием без ускорения по оси Y)
	granati[N_GREN].owner=1;
	granati[N_GREN].akt=1;
	granati[N_GREN].type=2;
	granati[N_GREN].speedX=10;
	granati[N_GREN].speedY=0.005f;
	N_GREN++;
	if(N_GREN>=MAX_GREN-1)
	{N_GREN=0;}
	}

	if(N_WEAPON1==13)
	{aktivatorgren=1;
	vistrel_time=GetTime();
	vistrel_time_sec=perez_akt;
	oboima--;
	granati[N_GREN].x=x-70;
	granati[N_GREN].y=y-16;
	granati[N_GREN].osY=y-16;
	granati[N_GREN].osX=x-1200;
	granati[N_GREN].owner=1;
	granati[N_GREN].akt=1;
	granati[N_GREN].type=3;
	granati[N_GREN].speedX=15;
	granati[N_GREN].speedY=0;
	N_GREN++;
	if(N_GREN>=MAX_GREN-1)
	{N_GREN=0;}
	}


	if(N_WEAPON1==11)
	{
	vistrel_time=GetTime();
	vistrel_time_sec=perez_akt;	
	reload=true;}

		 
	}//if(reload==false)
}//выстрел


void fire2()//ВЫСТРЕЛ!!! 2
{
	if(reload2==false)
	
	{
	player2_ruka1_pistol->Play();
	
	vistrel2();//звук выстрела

	if(N_WEAPON2!=10&&N_WEAPON2!=11&&N_WEAPON2!=12&&N_WEAPON2!=13)//огнестрельные
	{
		 vistrel2_time=GetTime();
		 vistrel2_time_sec=perez_akt;
         
		 aktivatorp2=1;//вылетает пуля
		 pulya2->SetColor(0xFFFFA000);//огонь из ствола
		

	if(N_WEAPON2==7)
	{pompa_time2=perez_akt;
	pompa_time_milli2=GetTime();
	pompa_akt2=1;
	dx2+=3;
	aktivatorp2d1=1;
	aktivatorp2d2=1;
	aktivatorp2d3=1;
	aktivatorp2d4=1;
	}
	
	gilziObjects[N_GILZ].x=x2-24;
	gilziObjects[N_GILZ].y=y2-9;
	gilziObjects[N_GILZ].xstart=x2-24;
	gilziObjects[N_GILZ].niz=y2+60;
	gilziObjects[N_GILZ].randomx=hge->Random_Int(10,20);

	switch(N_WEAPON2)
	{case 1:
	case 4:
	case 9:
	case 14:
	case 15:
	gilziObjects[N_GILZ].type=1;
	break;
	case 0:
	case 2:
	case 3:
	case 5:
	case 6:
	case 7:
	case 8:
	gilziObjects[N_GILZ].type=2;
	break;}
	gilziObjects[N_GILZ].akt=1;

	N_GILZ++;
	
	if(N_GILZ>=MAX_GILZ-1)
	{N_GILZ=0;}

	}//огнестрельные


	if(N_WEAPON2==10)
	{aktivatorgren2=1;
	vistrel2_time=GetTime();
	vistrel2_time_sec=perez_akt;
	oboima2--;
	reload2=true;
	granati[N_GREN].x=x2+5;
	granati[N_GREN].y=y2-44;
	granati[N_GREN].osY=y2+48+dy2*75;
	if(granati[N_GREN].osY<100)
	{granati[N_GREN].osY=100;}
	granati[N_GREN].osX=x2-250+dx2*75;
	if(dy2<0)
	{granati[N_GREN].osX+=dy2*40;//кидаем вверх- дальше (чтоб не было багов)
	if(dx2>0)
	{granati[N_GREN].osX-=dx2*40;}//при беге назад кидаем дальше (опять же чтоб не было багов)
	if(dx2<0)
	{granati[N_GREN].osX-=dx2*20;}}//при беге вперед кидаем ближе (чтоб не было жирно)
	if(dy2>0)
	{granati[N_GREN].osX+=dy2*35;}//кидаем вниз- ближе (баланс с состоянием без ускорения по оси Y)
	granati[N_GREN].owner=2;
	granati[N_GREN].akt=1;
	granati[N_GREN].type=1;
	granati[N_GREN].speedX=6;
	granati[N_GREN].speedY=0.018f;
	N_GREN++;
	if(N_GREN>=MAX_GREN-1)
	{N_GREN=0;}
	}

	if(N_WEAPON2==12)
	{aktivatorgren2=1;
	vistrel2_time=GetTime();
	vistrel2_time_sec=perez_akt;
	oboima2--;
	granati[N_GREN].x=x2-55;
	granati[N_GREN].y=y2-9;
	granati[N_GREN].osY=y2-9+dy2*100;
	if(granati[N_GREN].osY<100)
	{granati[N_GREN].osY=100;}
	granati[N_GREN].osX=x2-505;
	if(dy2<0)
	{granati[N_GREN].osX+=dy2*175;//кидаем вверх- дальше (чтоб не было багов)
	if(dx2>0)
	{granati[N_GREN].osX-=dx2*20;}//при беге назад кидаем дальше (опять же чтоб не было багов)
	//if(dx2<0)
	//{granati[N_GREN].osX-=dx2*10;}//при беге вперед кидаем ближе (чтоб не было жирно)
	}
	if(dy2>0)
	{granati[N_GREN].osX+=dy2*275;}//кидаем вниз- ближе (баланс с состоянием без ускорения по оси Y)
	granati[N_GREN].owner=2;
	granati[N_GREN].akt=1;
	granati[N_GREN].type=2;
	granati[N_GREN].speedX=10;
	granati[N_GREN].speedY=0.005f;
	N_GREN++;
	if(N_GREN>=MAX_GREN-1)
	{N_GREN=0;}
	}

	if(N_WEAPON2==13)
	{aktivatorgren2=1;
	vistrel2_time=GetTime();
	vistrel2_time_sec=perez_akt;
	oboima2--;
	granati[N_GREN].x=x2-70;
	granati[N_GREN].y=y2-16;
	granati[N_GREN].osY=y2-16;
	granati[N_GREN].osX=x2-1200;
	granati[N_GREN].owner=2;
	granati[N_GREN].akt=1;
	granati[N_GREN].type=3;
	granati[N_GREN].speedX=15;
	granati[N_GREN].speedY=0;
	N_GREN++;
	if(N_GREN>=MAX_GREN-1)
	{N_GREN=0;}
	}


	if(N_WEAPON2==11)
	{
	vistrel2_time=GetTime();
	vistrel2_time_sec=perez_akt;	
	reload2=true;}


	}//if(reload2==false)
}//выстрел 2

void fire1_alt()//ВЫСТРЕЛ!!!
{if(reload==false)
{

	switch(N_WEAPON1)
	{case 0:
	case 3:
	oboima_alt[N_WEAPON1]--;
	
	granati[N_GREN].x=x-55;
	granati[N_GREN].y=y;
	granati[N_GREN].osY=y+dy*100;
	if(granati[N_GREN].osY<100)
	{granati[N_GREN].osY=100;}
	granati[N_GREN].osX=x-505;
	if(dy<0)
	{granati[N_GREN].osX+=dy*175;//кидаем вверх- дальше (чтоб не было багов)
	if(dx>0)
	{granati[N_GREN].osX-=dx*20;}//при беге назад кидаем дальше (опять же чтоб не было багов)
	//if(dx<0)
	//{granati[N_GREN].osX-=dx*20;}//при беге вперед кидаем ближе (чтоб не было жирно)
	}
	if(dy>0)
	{granati[N_GREN].osX+=dy*275;}//кидаем вниз- ближе (баланс с состоянием без ускорения по оси Y)
	granati[N_GREN].owner=1;
	granati[N_GREN].akt=1;
	granati[N_GREN].type=2;
	granati[N_GREN].speedX=10;
	granati[N_GREN].speedY=0.005f;
	N_GREN++;
	if(N_GREN>=MAX_GREN-1)
	{N_GREN=0;}

	break;
		
	}
	
}}


void fire2_alt()//ВЫСТРЕЛ!!!
{if(reload2==false)
{

	switch(N_WEAPON2)
	{case 0:
	case 3:
	oboima2_alt[N_WEAPON2]--;
	
	granati[N_GREN].x=x2-55;
	granati[N_GREN].y=y2;
	granati[N_GREN].osY=y2+dy2*100;
	if(granati[N_GREN].osY<100)
	{granati[N_GREN].osY=100;}
	granati[N_GREN].osX=x2-505;
	if(dy<0)
	{granati[N_GREN].osX+=dy2*175;//кидаем вверх- дальше (чтоб не было багов)
	if(dx>0)
	{granati[N_GREN].osX-=dx2*20;}//при беге назад кидаем дальше (опять же чтоб не было багов)
	//if(dx<0)
	//{granati[N_GREN].osX-=dx*20;}//при беге вперед кидаем ближе (чтоб не было жирно)
	}
	if(dy2>0)
	{granati[N_GREN].osX+=dy2*275;}//кидаем вниз- ближе (баланс с состоянием без ускорения по оси Y)
	granati[N_GREN].owner=2;
	granati[N_GREN].akt=1;
	granati[N_GREN].type=2;
	granati[N_GREN].speedX=10;
	granati[N_GREN].speedY=0.005f;
	N_GREN++;
	if(N_GREN>=MAX_GREN-1)
	{N_GREN=0;}

	break;
		
	}
	
}}


int Render_trups(int &i)
{
if(trupsObjects[i].type==1) //зайцы
        {
		if(trupsObjects[i].trup_tex==zayac_go_tex)//заяц с ушами
        {
		switch(trupsObjects[i].frame)
		{case 1:zayac_trup1->SetTexture(zayac_trup1_a_tex);
		break;
		case 2:zayac_trup1->SetTexture(zayac_trup1_b_tex);
		break;
		case 3:zayac_trup1->SetTexture(zayac_trup1_c_tex);
		break;
		case 4:zayac_trup1->SetTexture(zayac_trup1_d_tex);
		break;}
		}

		if(trupsObjects[i].trup_tex==zayac_go_bezuh_tex)//заяц без ушей
        {
		switch(trupsObjects[i].frame)
		{case 1:zayac_trup1->SetTexture(zayac_trup1_a_bezuh_tex);
		break;
		case 2:zayac_trup1->SetTexture(zayac_trup1_b_bezuh_tex);
		break;
		case 3:zayac_trup1->SetTexture(zayac_trup1_c_bezuh_tex);
		break;
		case 4:zayac_trup1->SetTexture(zayac_trup1_d_bezuh_tex);
		break;}
		}
		
		if(trupsObjects[i].trup_tex==zayac_boshka_tex)//заяц без бошки
        {
		switch(trupsObjects[i].frame)
		{case 1:zayac_trup1->SetTexture(zayac_trup1_a_bezboshki_tex);
		break;
		case 2:zayac_trup1->SetTexture(zayac_trup1_b_bezboshki_tex);
		break;
		case 3:zayac_trup1->SetTexture(zayac_trup1_c_bezboshki_tex);
		break;
		case 4:zayac_trup1->SetTexture(zayac_trup1_d_bezboshki_tex);
		break;}
		}






		zayac_trup1->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,0,1,0);//вывод мёртвых зайцев на экран
		}//закрытие зайцев
		

		if(trupsObjects[i].type==2) //уши (аниме)
		{uhi_a->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].rot);}
        if(trupsObjects[i].type==3) //уши (мёртвые)
		{uhi->SetTexture(zayac_uhi_k_tex);
		uhi->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].rot);}
		if(trupsObjects[i].type==300) //воронка1
		{krovyak_vzriv1->SetTexture(blood_vzriv1_e_tex);
		krovyak_vzriv1->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,0,trupsObjects[i].scaleX,1);}
		if(trupsObjects[i].type==301) //воронка1/2
		{krovyak_vzriv1->SetTexture(blood_vzriv1_e2_tex);
		krovyak_vzriv1->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,0,trupsObjects[i].scaleX,1);} 
		if(trupsObjects[i].type==330) //бошка птенца в щи1
		{ptenec_boshka_vzriv1->SetTexture(ptenec_boshka_vzriv1_e_tex);
		ptenec_boshka_vzriv1->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,0,trupsObjects[i].scaleX,1);}
        if(trupsObjects[i].type==400)//кровяк1
		{krovyak1->RenderStretch(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].posX2,trupsObjects[i].posY2);}
		if(trupsObjects[i].type==401)//кровяк2
		{krovyak2->RenderStretch(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].posX2,trupsObjects[i].posY2);}
		if(trupsObjects[i].type==402)//кровяк3
		{krovyak3->RenderStretch(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].posX2,trupsObjects[i].posY2);}
		if(trupsObjects[i].type==6) //бошки (мёртвые)
		{zayac_boshka->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].rot);}
		if(trupsObjects[i].type==7) //бошки без ушей(мёртвые)
		{zayac_boshka_bezuh->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].rot);}
		if(trupsObjects[i].type==800) //клякса 1
		{krovyak_plyam1->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,M_PI_2,0.2f,0.7f);}
		if(trupsObjects[i].type==801) //клякса 2
		{krovyak_plyam2->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,M_PI_2,0.2f,0.7f);}
		if(trupsObjects[i].type==802) //клякса 3
		{krovyak_plyam3->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,M_PI_2,0.2f,0.7f);}
		if(trupsObjects[i].type==9) //лужа 1
		{krovyak_luzha1->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,0,trupsObjects[i].scaleX,trupsObjects[i].scaleY);}
		if(trupsObjects[i].type==10)//труп волка
		{
		switch(trupsObjects[i].frame)
		{case 1:volk_trup1->SetTexture(volk_trup1_a_tex);
		break;
		case 2:volk_trup1->SetTexture(volk_trup1_b_tex);
		break;
		case 3:volk_trup1->SetTexture(volk_trup1_c_tex);
		break;}
		volk_trup1->Render(trupsObjects[i].posX+Xz, trupsObjects[i].posY);
		}
		if(trupsObjects[i].type==20)//труп медведя
		{
		if(trupsObjects[i].trup_tex==zayac_go_tex)
		{
		switch(trupsObjects[i].frame)
		{
		case 1:medved_trup1->SetTexture(medved_trup1_a_tex);
		break;
		case 2:medved_trup1->SetTexture(medved_trup1_b_tex);
		break;
		case 3:medved_trup1->SetTexture(medved_trup1_c_tex);
		break;
		case 4:medved_trup1->SetTexture(medved_trup1_d_tex);
		break;
		case 5:medved_trup1->SetTexture(medved_trup1_e_tex);
		break;
		case 6:medved_trup1->SetTexture(medved_trup1_f_tex);
			break;}
		medved_trup1->Render(trupsObjects[i].posX+Xz, trupsObjects[i].posY);
		}
		if(trupsObjects[i].trup_tex==zayac_go_bezuh_tex)
		{
		switch(trupsObjects[i].frame)
		{
		case 1:medved_trup1->SetTexture(medved_trup1_a_bezboshki_tex);
		break;
		case 2:medved_trup1->SetTexture(medved_trup1_b_bezboshki_tex);
		break;
		case 3:medved_trup1->SetTexture(medved_trup1_c_bezboshki_tex);
		break;
		case 4:medved_trup1->SetTexture(medved_trup1_d_bezboshki_tex);
		break;
		case 5:medved_trup1->SetTexture(medved_trup1_e_bezboshki_tex);
		break;
		case 6:medved_trup1->SetTexture(medved_trup1_f_bezboshki_tex);
			break;}
		medved_trup1->Render(trupsObjects[i].posX+Xz, trupsObjects[i].posY);
		}
		}
		if(trupsObjects[i].type==30)//труп птенца
		{ptenec_trup1->SetTexture(ptenec_trup1_tex);
		ptenec_trup1->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,0,0.7f,0);}
		if(trupsObjects[i].type==500) //мясо 1
		{krovyak_myaso1->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].rot,trupsObjects[i].scaleX,0);}
		if(trupsObjects[i].type==501) //мясо 2
		{krovyak_myaso2->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].rot,trupsObjects[i].scaleX,0);}
		if(trupsObjects[i].type==502) //мясо 3
		{krovyak_myaso3->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].rot,trupsObjects[i].scaleX,0);}
		if(trupsObjects[i].type==503) //мясо 4
		{krovyak_myaso4->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].rot,trupsObjects[i].scaleX,0);}
		if(trupsObjects[i].type==504) //мясо 5
		{krovyak_myaso5->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].rot,trupsObjects[i].scaleX,0);}
		if(trupsObjects[i].type==505) //заячьи ребра 1
		{krovyak_zayac_rebra1->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].rot,1,0);}
		if(trupsObjects[i].type==506) //заячьи ребра 2
		{krovyak_zayac_rebra2->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].rot,1,0);}
		if(trupsObjects[i].type==507) //заячья нога 1
		{krovyak_zayac_noga1->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].rot,1,0);}
		if(trupsObjects[i].type==508) //заячья нога 2
		{krovyak_zayac_noga2->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].rot,1,0);}
		if(trupsObjects[i].type==509) //заячья нога 3
		{krovyak_zayac_noga3->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].rot,1,0);}
		if(trupsObjects[i].type==510) //заячья нога 4
		{krovyak_zayac_noga4->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].rot,1,0);}
		if(trupsObjects[i].type==511) //медвежья бошка 1
		{medved_boshka->RenderEx(trupsObjects[i].posX+Xz, trupsObjects[i].posY,trupsObjects[i].rot,1,0);}
return 0;

};



void ak_perez1()   //звук - начало перезарядки ак
{ hge->Effect_PlayEx(ak_reload1,volume,player1Pan,0);}
void ak_perez2()  //звук - конец перезарядки ак
{hge->Effect_PlayEx(ak_reload2,volume,player1Pan,0);}
void pm_perez1()  //звук - начало перезарядки пм
{ hge->Effect_PlayEx(pm_reload1,volume,player1Pan,0);}
void pm_perez2()  //звук - конец перезарядки пм
{ hge->Effect_PlayEx(pm_reload2,volume,player1Pan,0);}
void pp19_perez1()   //звук - начало перезарядки пп-19
{ hge->Effect_PlayEx(pp19_reload1,volume,player1Pan,0);}
void pp19_perez2()   //звук - конец перезарядки пп-19
{ hge->Effect_PlayEx(pp19_reload2,volume,player1Pan,0);}
void mac_perez1()   //звук - начало перезарядки MAC
{ hge->Effect_PlayEx(mac_reload1,volume,player1Pan,0);}
void mac_perez2()   //звук - конец перезарядки MAC
{ hge->Effect_PlayEx(mac_reload2,volume,player1Pan,0);}
void webley_perez1()   //звук - начало перезарядки webley
{ hge->Effect_PlayEx(webley_reload1,volume,player1Pan,0);}
void webley_perez2()   //звук - конец перезарядки webley
{ hge->Effect_PlayEx(webley_reload2,volume,player1Pan,0);}




void ak2_perez1()   //звук - начало перезарядки ак
{ hge->Effect_PlayEx(ak_reload1,volume,player2Pan,0);}
void ak2_perez2()  //звук - конец перезарядки ак
{hge->Effect_PlayEx(ak_reload2,volume,player2Pan,0);}
void pm2_perez1()  //звук - начало перезарядки пм
{ hge->Effect_PlayEx(pm_reload1,volume,player2Pan,0);}
void pm2_perez2()  //звук - конец перезарядки пм
{ hge->Effect_PlayEx(pm_reload2,volume,player2Pan,0);}
void pp192_perez1()   //звук - начало перезарядки пп-19
{ hge->Effect_PlayEx(pp19_reload1,volume,player2Pan,0);}
void pp192_perez2()   //звук - конец перезарядки пп-19
{ hge->Effect_PlayEx(pp19_reload2,volume,player2Pan,0);}
void mac2_perez1()   //звук - начало перезарядки MAC
{ hge->Effect_PlayEx(mac_reload1,volume,player2Pan,0);}
void mac2_perez2()   //звук - конец перезарядки MAC
{ hge->Effect_PlayEx(mac_reload2,volume,player2Pan,0);}
void webley2_perez1()   //звук - начало перезарядки webley
{ hge->Effect_PlayEx(webley_reload1,volume,player2Pan,0);}
void webley2_perez2()   //звук - конец перезарядки webley
{ hge->Effect_PlayEx(webley_reload2,volume,player2Pan,0);}



void new_game()
{
N_WEAPON1=1;
N_WEAPON2=1;

X=0;
Xz=0;

net_user=0;

TEST_REZHIM=false;

PAUSE=false;

pobeda=false;
porazhenie=false;
leveltime=0;
LIVES=5;
DIFF=1;

DIFF_UP=true;
DIFF_UPGRADED=false;
n_zayac_up=0;
n_zayac_down=0;
n_volk_up=0;
n_volk_down=0;
n_medved_up=0;
n_medved_down=0;
zayac_must_down=false;
volk_must_down=false;
medved_must_down=false;

aktivatorp=0;
aktivatorp2=0;
aktivatorp1d1=0;
aktivatorp1d2=0;
aktivatorp1d3=0;
aktivatorp1d4=0;
aktivatorp2d1=0;
aktivatorp2d2=0;
aktivatorp2d3=0;
aktivatorp2d4=0;

perez_akt=0;
time_was=0;

oboima=8;
oboima2=8;
oboima_alt[0]=1;
oboima2_alt[0]=1;
oboima_alt[3]=1;
oboima2_alt[3]=1;

reload=false;
reload2=false;


N_ZAYAC=0;
N_VOLK=-1;
N_MEDVED=-1;
N_PTENEC=-1;
N_UHI=0;
N_TRUPS=0;
NUMBER_TRUPS=0;
N_BLOOD=0;
NUMBER_BLOOD=0;
N_HEAD=0;
N_GILZ=0;
N_BONUS=0;
N_BONUSTEXT=0;
N_BONUS1=0;
N_BONUS2=0;
N_BONUSSTATUS1=0;
N_BONUSSTATUS2=0;
N_MYASO=0;
N_Y=0;
N_GREN=0;
N_KILLS=0;

peregruzheno=0;
peregruzheno_blood=0;

GAME_PROGRESS=0;
sit1=0;


pause_time_sec=0;
pause_time=0;


float opit1_x2=970;
float opit2_x2=970;

x=1000;
x2=1000;
y=450;
y2=600;

ak_buy=false;
pp19_buy=false;
fn_f2000_buy=false;
tt_buy=false;
rpk_buy=false;
mac_buy=false;
winchester_buy=false;
rpk47_buy=false;
glok_buy=false;
rgd5_buy=false;
katana_buy=false;
milkor_buy=false;
panzer_buy=false;
webley_buy=false;
fn_five_seven_buy=false;

ak_up=false;
fn_f2000_up=false;

ak_buy2=false;
pp19_buy2=false;
fn_f2000_buy2=false;
tt_buy2=false;
rpk_buy2=false;
mac_buy2=false;
winchester_buy2=false;
rpk47_buy2=false;
glok_buy2=false;
rgd5_buy2=false;
katana_buy2=false;
milkor_buy2=false;
panzer_buy2=false;
webley_buy2=false;
fn_five_seven_buy2=false;

ak_up2=false;
fn_f2000_up2=false;

kills=0;
kills2=0;
points1=0;
points2=0;


kills_zayac=0;
kills_volk=0;
kills_medved=0;
kills_zayac_vschiii=0;
kills_zayac_bezuh=0;
kills_zayac_bezboshki=0;

kills2_zayac=0;
kills2_volk=0;
kills2_medved=0;
kills2_zayac_vschiii=0;
kills2_zayac_bezuh=0;
kills2_zayac_bezboshki=0;


opit1=0;
opit2=0;

status_queue1=0;
status_queue2=0;
status_queue1_block=false;
status_queue2_block=false;

LVL1=1;
LVL2=1;

lvl1_ready=false;
lvl2_ready=false;

lvl1_vibor=false;
lvl2_vibor=false;

lvl1_mig=0;
lvl2_mig=0;

attack1=0;
attack2=0;
luck1=0;
luck2=0;
skorost1=100;
skorost2=100;


primanka1=0;
mosch1=0;
primanka2=0;
mosch2=0;



postroenie1=0;
postroenie2=0;
tochnost1=1;
tochnost2=1;

vinoslivost1=1;
vinoslivost2=1;
vzrivchatka1=0;
vzrivchatka2=0;


modifikacii1=0;
modifikacii2=0;
technika1=0;
technika2=0;



speed=skorost1;
speed2=skorost2;

daun1=1;
daun2=1;

umnik1=0;
umnik2=0;

weapon1_fire=0;
weapon2_fire=0;



VIBOR=0;



opit_points1=0;
opit_points2=0;
naviki_points1=0;
naviki_points2=0;

lvl_key_block=false;
vibor_block=false;
viborchange_block=false;

menu1_on=0;
pistol1=1;
menu2_on=0;
pistol2=1;


//oboim[8]={30,8,30,30,8,45,50,8};
//oboim2[8]={30,8,30,30,8,45,50,8};
oboim[0]=30;
oboim[1]=8;
oboim[2]=30;
oboim[3]=30;
oboim[4]=8;
oboim[5]=45;
oboim[6]=50;
oboim[7]=8;
oboim[8]=75;
oboim[9]=17;
oboim[10]=1;
oboim[12]=6;
oboim[13]=1;
oboim[14]=6;
oboim[15]=20;


oboim2[0]=30;
oboim2[1]=8;
oboim2[2]=30;
oboim2[3]=30;
oboim2[4]=8;
oboim2[5]=45;
oboim2[6]=50;
oboim2[7]=8;
oboim2[8]=75;
oboim2[9]=17;
oboim2[10]=1;
oboim2[12]=6;
oboim2[13]=1;
oboim2[14]=6;
oboim2[15]=20;

defence_zayac=0;
defence_volk=10;
defence_medved=25;

rpg_healers=false;
rpg_illusionists=false;
rpg_teleporters=false;

for(int i90=0;i90<=MAX_TRUPS-1;i90++)
{trupsObjects[i90].aktiv=0;
 trupsObjects[i90].type=0;}

for(int i4=0;i4<=MAX_ZAYAC-1;i4++)
{vragi1Objects[i4].ubit=0;//все зайцы живы
vragi1Objects[i4].pokoin=0;
vragi1Objects[i4].health=50;
vragi1Objects[i4].v1x=-50;
vragi1Objects[i4].v1y=hge->Random_Float(60,840);
vragi1Objects[i4].bezuh=0;//все зайцы с ушами
vragi1Objects[i4].bezboshki=0;
vragi1Objects[i4].speed=hge->Random_Float(0.9f,1.1f);
vragi1Objects[i4].defence=0;
vragi1Objects[i4].object_id=-1;
vragi1Objects[i4].A=0;
vragi1Objects[i4].vzorvan=false;
vragi1Objects[i4].energy=0;
vragi1Objects[i4].rasstX=0;
vragi1Objects[i4].rasstY=0;
vragi1Objects[i4].chetvert=0;
}

for(int i91=0;i91<=MAX_VOLK-1;i91++)
{vragi2Objects[i91].ubit=0;//все волки живы
vragi2Objects[i91].health=125;
vragi2Objects[i91].v2x=-50;
vragi2Objects[i91].v2y=hge->Random_Float(60,840);
vragi2Objects[i91].speed=hge->Random_Float(0.9f,1.1f);
vragi2Objects[i91].defence=0;
vragi2Objects[i91].object_id=-1;
}


for(int i92=0;i92<=MAX_MEDVED-1;i92++)
{vragi3Objects[i92].ubit=0;//все зайцы живы
vragi3Objects[i92].health=250;
vragi3Objects[i92].v3x=-50;
vragi3Objects[i92].v3y=hge->Random_Float(60,840);
vragi3Objects[i92].speed=hge->Random_Float(0.9f,1.1f);
vragi3Objects[i92].defence=0;
vragi3Objects[i92].object_id=-1;
}

for(int i92=0;i92<=MAX_PTENEC-1;i92++)
{vragi4Objects[i92].ubit=0;//все птенцы живы
vragi4Objects[i92].health=20;
vragi4Objects[i92].v4x=-50;
vragi4Objects[i92].v4y=hge->Random_Float(120,800);
vragi4Objects[i92].speed=hge->Random_Float(0.5f,0.6f);
vragi4Objects[i92].defence=0;
vragi4Objects[i92].object_id=-1;
vragi4Objects[i92].polet=0;
vragi4Objects[i92].vzorvan=false;
}

for(int i7=0;i7<=MAX_UHI-1;i7++)
{uhiObjects[i7].gradus=hge->Random_Float(0,M_PI);}

for(int i17=0;i17<=MAX_HEAD-1;i17++)
{boshkiObjects[i17].gradus=hge->Random_Float(0,M_PI);}

for(int i13=0;i13<=MAX_BLOOD-1;i13++)
{krovyakObjects[i13].akt=0;}



delete []gilziObjects;
gilziObjects=new gilzaObject[MAX_GILZ];


delete []bonusiObjects;
bonusiObjects= new bonusObject[MAX_BONUS];


delete [] bonusi1;
bonusi1=new bonusZnach[MAX_BONUSI];
delete [] bonusi2;
bonusi2=new bonusZnach[MAX_BONUSI];

delete [] statusi1;
delete [] statusi2;
statusi1= new bonusStatus[MAX_BONUSSTATUS];
statusi2= new bonusStatus[MAX_BONUSSTATUS];

delete [] bonustextiObjects;
bonustextiObjects= new bonustextObject[MAX_BONUSTEXT];

delete [] myasko;
myasko= new myasoObject[MAX_MYASO];

delete [] A;
A= new ALL[MAX_ZAYAC+MAX_VOLK+MAX_MEDVED+MAX_MYASO+MAX_BONUS+MAX_UHI+MAX_HEAD+N_OBJECTS+MAX_GILZ+MAX_BLOOD+MAX_GREN+2];

delete []Y;
Y= new YCOORD[MAX_ZAYAC+MAX_VOLK+MAX_MEDVED+MAX_MYASO+MAX_BONUS+MAX_UHI+MAX_HEAD+N_OBJECTS+MAX_GILZ+MAX_BLOOD+MAX_GREN+2];

delete []granati;
granati=new granataObject[MAX_GREN];

for(int i58=0;i58<=	MAX_GREN-1;i58++)
{granati[i58].gradus=0;}

for(int i96=0;i96<=	MAX_MYASO-1;i96++)
{myasko[i96].gradus=0;
myasko[i96].akt=0;
myasko[i96].niz=0;}

delete []ubijstva;
ubijstva=new fragObject[MAX_KILLS];

}//ЗАКРЫТИЕ НОВОЙ ИГРЫ


void zayac_add()
{N_ZAYAC++;
vragi1Objects[N_ZAYAC].v1x=-50;
if(player2_aktive==0)
{vragi1Objects[N_ZAYAC].v1y=hge->Random_Float(200,700);}
if(player2_aktive==1)
{vragi1Objects[N_ZAYAC].v1y=hge->Random_Float(150,850);}
vragi1Objects[N_ZAYAC].ubit=0;
vragi1Objects[N_ZAYAC].pokoin=0;
vragi1Objects[N_ZAYAC].health=50;
vragi1Objects[N_ZAYAC].bezuh=0;
vragi1Objects[N_ZAYAC].bezboshki=0;
vragi1Objects[N_ZAYAC].speed=hge->Random_Float(1,1.2f);
if(sit1==2)
{vragi1Objects[N_ZAYAC].speed=0.5f;}
vragi1Objects[N_ZAYAC].defence=defence_zayac;
vragi1Objects[N_ZAYAC].object_id=-1;
vragi1Objects[N_ZAYAC].vzorvan=false;
vragi1Objects[N_ZAYAC].energy=0;
vragi1Objects[N_ZAYAC].rasstX=0;
vragi1Objects[N_ZAYAC].rasstY=0;
vragi1Objects[N_ZAYAC].chetvert=0;
vragi1Objects[N_ZAYAC].timeout=0;
vragi1Objects[N_ZAYAC].timeout_milli=0;
}

void volk_add()
{N_VOLK++;
vragi2Objects[N_VOLK].v2x=-50;
if(player2_aktive==0)
{vragi2Objects[N_VOLK].v2y=hge->Random_Float(200,700);}
if(player2_aktive==1)
{vragi2Objects[N_VOLK].v2y=hge->Random_Float(150,750);}
vragi2Objects[N_VOLK].ubit=0;
vragi2Objects[N_VOLK].health=125;
vragi2Objects[N_VOLK].speed=hge->Random_Float(0.7f,0.9f);
vragi2Objects[N_VOLK].defence=defence_volk;
vragi2Objects[N_VOLK].object_id=-1;
vragi2Objects[N_VOLK].RPG_healer=0;
vragi2Objects[N_VOLK].RPG_illusionist=0;
vragi2Objects[N_VOLK].RPG_teleporter=0;
vragi2Objects[N_VOLK].timeout=0;
vragi2Objects[N_VOLK].timeout_milli=0;
}



void medved_add()
{N_MEDVED++;
vragi3Objects[N_MEDVED].v3x=-150;
if(player2_aktive==0)
{vragi3Objects[N_MEDVED].v3y=hge->Random_Float(200,700);}
if(player2_aktive==1)
{vragi3Objects[N_MEDVED].v3y=hge->Random_Float(150,750);}
vragi3Objects[N_MEDVED].bezboshki=0;
vragi3Objects[N_MEDVED].ubit=0;
vragi3Objects[N_MEDVED].health=400;
vragi3Objects[N_MEDVED].speed=hge->Random_Float(0.45f,0.55f);
vragi3Objects[N_MEDVED].defence=defence_medved;
vragi3Objects[N_MEDVED].object_id=-1;
vragi3Objects[N_MEDVED].RPG_healer=0;
vragi3Objects[N_MEDVED].RPG_illusionist=0;
vragi3Objects[N_MEDVED].ill1_active=0;
vragi3Objects[N_MEDVED].ill2_active=0;
vragi3Objects[N_MEDVED].RPG_teleporter=0;
vragi3Objects[N_MEDVED].teleportx=0;
vragi3Objects[N_MEDVED].teleported=0;
vragi3Objects[N_MEDVED].timeout=0;
vragi3Objects[N_MEDVED].timeout_milli=0;}



void ptenec_add()
{N_PTENEC++;
vragi4Objects[N_PTENEC].bezboshki=0;
vragi4Objects[N_PTENEC].v4x=-50;
if(player2_aktive==0)
{vragi4Objects[N_PTENEC].v4y=hge->Random_Float(200,700);}
if(player2_aktive==1)
{vragi4Objects[N_PTENEC].v4y=hge->Random_Float(150,750);}
vragi4Objects[N_PTENEC].gradus=0;
vragi4Objects[N_PTENEC].ubit=0;
vragi4Objects[N_PTENEC].health=20;
vragi4Objects[N_PTENEC].speed=hge->Random_Float(0.5f,0.6f);
vragi4Objects[N_PTENEC].defence=defence_zayac;
vragi4Objects[N_PTENEC].object_id=-1;
vragi4Objects[N_PTENEC].timeout=0;
vragi4Objects[N_PTENEC].timeout_milli=0;
vragi4Objects[N_PTENEC].wait=0;
vragi4Objects[N_PTENEC].wait_time_sec=0;
vragi4Objects[N_PTENEC].polet=0;
vragi4Objects[N_PTENEC].vzorvan=false;					
vragi4Objects[N_PTENEC].energy=0;
vragi4Objects[N_PTENEC].rasstX=0;
vragi4Objects[N_PTENEC].rasstY=0;

}



void situation1()
{
if(sit1==1)
{
int n_volk=N_VOLK;
int n_medved=N_MEDVED;
int sit_progress=-1;


if(sit_progress==-1)//убираем волков
{
if(N_VOLK>=0)
{
for(int i106=0;i106<=N_VOLK;i106++)
{
if(vragi2Objects[N_VOLK].ubit==1||vragi2Objects[N_VOLK].v2x<0)
{N_VOLK--;}
}}
if(N_VOLK<0)
{sit_progress=0;}
}

if(sit_progress==0)//добавляем медведей
{
medved_add();
medved_add();
medved_add();
medved_add();
sit_progress=1;
}

if(sit_progress==1)//смотрим, убиты ли они
{
for(int i107=0;i107<=N_MEDVED;i107++)
{
if((vragi3Objects[N_MEDVED].ubit==1||vragi3Objects[N_MEDVED].v3x<0)&&n_medved!=N_MEDVED)
{N_MEDVED--;}}

if(n_medved==N_MEDVED)
{sit_progress=2;}
}

if(sit_progress==2)//возвращаем все на место
{
for(int i108=0;i108<=n_volk;i108++)
{volk_add();}

sit1=0;
}
}

}//situation1




void bonus_shans()
{bonus=hge->Random_Int(1,1000);}

void bonustext1_0()
{//появление текста пусто
bonustextiObjects[N_BONUSTEXT].akt=1;
bonustextiObjects[N_BONUSTEXT].akt_time=perez_akt;
bonustextiObjects[N_BONUSTEXT].akt_time_milli=GetTime();
bonustextiObjects[N_BONUSTEXT].type=0;
bonustextiObjects[N_BONUSTEXT].x=x-28;
bonustextiObjects[N_BONUSTEXT].x_s=x-28;
bonustextiObjects[N_BONUSTEXT].x_X=X;
bonustextiObjects[N_BONUSTEXT].y=y-50;

N_BONUSTEXT++;

if(N_BONUSTEXT>=MAX_BONUSTEXT-1)
{N_BONUSTEXT=0;}

}

void bonustext1_1()
{//появление текста +10% скорость
bonustextiObjects[N_BONUSTEXT].akt=1;
bonustextiObjects[N_BONUSTEXT].akt_time=perez_akt;
bonustextiObjects[N_BONUSTEXT].akt_time_milli=GetTime();
bonustextiObjects[N_BONUSTEXT].type=1;
bonustextiObjects[N_BONUSTEXT].x=x-60;
bonustextiObjects[N_BONUSTEXT].x_s=x-60;
bonustextiObjects[N_BONUSTEXT].x_X=X;
bonustextiObjects[N_BONUSTEXT].y=y-50;

N_BONUSTEXT++;

if(N_BONUSTEXT>=MAX_BONUSTEXT-1)
{N_BONUSTEXT=0;}

}

void bonustext1_2()
{//появление текста -50% обучение
bonustextiObjects[N_BONUSTEXT].akt=1;
bonustextiObjects[N_BONUSTEXT].akt_time=perez_akt;
bonustextiObjects[N_BONUSTEXT].akt_time_milli=GetTime();
bonustextiObjects[N_BONUSTEXT].type=2;
bonustextiObjects[N_BONUSTEXT].x=x-60;
bonustextiObjects[N_BONUSTEXT].x_s=x-60;
bonustextiObjects[N_BONUSTEXT].x_X=X;
bonustextiObjects[N_BONUSTEXT].y=y-50;

N_BONUSTEXT++;

if(N_BONUSTEXT>=MAX_BONUSTEXT-1)
{N_BONUSTEXT=0;}

}

void bonustext1_3()
{//появление текста -20% скорость
bonustextiObjects[N_BONUSTEXT].akt=1;
bonustextiObjects[N_BONUSTEXT].akt_time=perez_akt;
bonustextiObjects[N_BONUSTEXT].akt_time_milli=GetTime();
bonustextiObjects[N_BONUSTEXT].type=3;
bonustextiObjects[N_BONUSTEXT].x=x-60;
bonustextiObjects[N_BONUSTEXT].x_s=x-60;
bonustextiObjects[N_BONUSTEXT].x_X=X;
bonustextiObjects[N_BONUSTEXT].y=y-50;

N_BONUSTEXT++;

if(N_BONUSTEXT>=MAX_BONUSTEXT-1)
{N_BONUSTEXT=0;}

}

void bonustext1_4()
{//появление текста +25% обучение
bonustextiObjects[N_BONUSTEXT].akt=1;
bonustextiObjects[N_BONUSTEXT].akt_time=perez_akt;
bonustextiObjects[N_BONUSTEXT].akt_time_milli=GetTime();
bonustextiObjects[N_BONUSTEXT].type=4;
bonustextiObjects[N_BONUSTEXT].x=x-60;
bonustextiObjects[N_BONUSTEXT].x_s=x-60;
bonustextiObjects[N_BONUSTEXT].x_X=X;
bonustextiObjects[N_BONUSTEXT].y=y-50;

N_BONUSTEXT++;

if(N_BONUSTEXT>=MAX_BONUSTEXT-1)
{N_BONUSTEXT=0;}

}



void bonustext2_0()
{//появление текста пусто
bonustextiObjects[N_BONUSTEXT].akt=1;
bonustextiObjects[N_BONUSTEXT].akt_time=perez_akt;
bonustextiObjects[N_BONUSTEXT].akt_time_milli=GetTime();
bonustextiObjects[N_BONUSTEXT].type=0;
bonustextiObjects[N_BONUSTEXT].x=x2-28;
bonustextiObjects[N_BONUSTEXT].x_s=x2-28;
bonustextiObjects[N_BONUSTEXT].x_X=X;
bonustextiObjects[N_BONUSTEXT].y=y2-50;

N_BONUSTEXT++;

if(N_BONUSTEXT>=MAX_BONUSTEXT-1)
{N_BONUSTEXT=0;}

}

void bonustext2_1()
{//появление текста +10% скорость
bonustextiObjects[N_BONUSTEXT].akt=1;
bonustextiObjects[N_BONUSTEXT].akt_time=perez_akt;
bonustextiObjects[N_BONUSTEXT].akt_time_milli=GetTime();
bonustextiObjects[N_BONUSTEXT].type=1;
bonustextiObjects[N_BONUSTEXT].x=x2-60;
bonustextiObjects[N_BONUSTEXT].x_s=x2-60;
bonustextiObjects[N_BONUSTEXT].x_X=X;
bonustextiObjects[N_BONUSTEXT].y=y2-50;

N_BONUSTEXT++;

if(N_BONUSTEXT>=MAX_BONUSTEXT-1)
{N_BONUSTEXT=0;}

}

void bonustext2_2()
{//появление текста -50% обучение
bonustextiObjects[N_BONUSTEXT].akt=1;
bonustextiObjects[N_BONUSTEXT].akt_time=perez_akt;
bonustextiObjects[N_BONUSTEXT].akt_time_milli=GetTime();
bonustextiObjects[N_BONUSTEXT].type=2;
bonustextiObjects[N_BONUSTEXT].x=x2-60;
bonustextiObjects[N_BONUSTEXT].x_s=x2-60;
bonustextiObjects[N_BONUSTEXT].x_X=X;
bonustextiObjects[N_BONUSTEXT].y=y2-50;

N_BONUSTEXT++;

if(N_BONUSTEXT>=MAX_BONUSTEXT-1)
{N_BONUSTEXT=0;}

}


void bonustext2_3()
{//появление текста -20% скорость
bonustextiObjects[N_BONUSTEXT].akt=1;
bonustextiObjects[N_BONUSTEXT].akt_time=perez_akt;
bonustextiObjects[N_BONUSTEXT].akt_time_milli=GetTime();
bonustextiObjects[N_BONUSTEXT].type=3;
bonustextiObjects[N_BONUSTEXT].x=x2-60;
bonustextiObjects[N_BONUSTEXT].x_s=x2-60;
bonustextiObjects[N_BONUSTEXT].x_X=X;
bonustextiObjects[N_BONUSTEXT].y=y2-50;

N_BONUSTEXT++;

if(N_BONUSTEXT>=MAX_BONUSTEXT-1)
{N_BONUSTEXT=0;}

}

void bonustext2_4()
{//появление текста +25% обучение
bonustextiObjects[N_BONUSTEXT].akt=1;
bonustextiObjects[N_BONUSTEXT].akt_time=perez_akt;
bonustextiObjects[N_BONUSTEXT].akt_time_milli=GetTime();
bonustextiObjects[N_BONUSTEXT].type=4;
bonustextiObjects[N_BONUSTEXT].x=x2-60;
bonustextiObjects[N_BONUSTEXT].x_s=x2-60;
bonustextiObjects[N_BONUSTEXT].x_X=X;
bonustextiObjects[N_BONUSTEXT].y=y2-50;

N_BONUSTEXT++;

if(N_BONUSTEXT>=MAX_BONUSTEXT-1)
{N_BONUSTEXT=0;}

}

/*
void trups_podvintes()
{
if(peregruzheno==1)
{
for (int i100=0;i100<=NUMBER_TRUPS-1;i100++)
{trupsObjects[i100].aktiv=trupsObjects[i100+1].aktiv;
trupsObjects[i100].color=trupsObjects[i100+1].color;
trupsObjects[i100].frame=trupsObjects[i100+1].frame;
trupsObjects[i100].frame_akt=trupsObjects[i100+1].frame_akt;
trupsObjects[i100].killtime=trupsObjects[i100+1].killtime;
trupsObjects[i100].killtime_sec=trupsObjects[i100+1].killtime_sec;
trupsObjects[i100].posX=trupsObjects[i100+1].posX;
trupsObjects[i100].posX2=trupsObjects[i100+1].posX2;
trupsObjects[i100].posX2_s=trupsObjects[i100+1].posX2_s;
trupsObjects[i100].posX2_X=trupsObjects[i100+1].posX2_X;
trupsObjects[i100].posX_s=trupsObjects[i100+1].posX_s;
trupsObjects[i100].posX_X=trupsObjects[i100+1].posX_X;
trupsObjects[i100].posY=trupsObjects[i100+1].posY;
trupsObjects[i100].posY2=trupsObjects[i100+1].posY2;
trupsObjects[i100].rot=trupsObjects[i100+1].rot;
trupsObjects[i100].scaleX=trupsObjects[i100+1].scaleX;
trupsObjects[i100].scaleY=trupsObjects[i100+1].scaleY;
trupsObjects[i100].trup_tex=trupsObjects[i100+1].trup_tex;
trupsObjects[i100].type=trupsObjects[i100+1].type;
trupsObjects[i100].vrag=trupsObjects[i100+1].vrag;
}
N_TRUPS=NUMBER_TRUPS;
}
}
*/


void weapon1_fire_skill()
{

if(naviki_points1>0)
{if(LVL1>=12+weapon1_fire*3&&attack1>=15+weapon1_fire*3&&skorost1>=5+weapon1_fire*2)
{info->printf(650,400,HGETEXT_LEFT,"Оружие:огонь");
info->printf(650,420,HGETEXT_LEFT,"Уровень %d",weapon1_fire+1);
info->printf(650,440,HGETEXT_LEFT,"Снижает защиту врага");
info->printf(650,460,HGETEXT_LEFT,"на %d ед. за попадание",weapon1_fire+1);}}

if(naviki_points1<=0||LVL1<12+weapon1_fire*3||attack1<15+weapon1_fire*3||skorost1<5+weapon1_fire*2)
{infoD->printf(650,400,HGETEXT_LEFT,"Оружие:огонь");
infoD->printf(650,420,HGETEXT_LEFT,"Уровень %d",weapon1_fire+1);
infoD->printf(650,440,HGETEXT_LEFT,"Снижает защиту врага");
infoD->printf(650,460,HGETEXT_LEFT,"на %d ед. за попадание",weapon1_fire+1);}

}



//-----------------------------------------------------------------

bool FocusGainFunc()
{
if(blood_tar && blood_target) 
blood_tar->SetTexture(hge->Target_GetTexture(blood_target));
return false;
}



//-----------------------------------------------------------------

bool FrameFunc()
{
MSG		   msg;		 // generic message
bool enter;
bool shift;
bool space;
bool r_key;
float dt=hge->Timer_GetDelta();	
int fps=hge->Timer_GetFPS();
	
time=GetTime();

int id;
static int lastid=0;


if(menu_aktive==1)
{
id=menu->Update(dt);
if(id == -1)
{
switch(lastid)
{
case 1:
if(game_start==0)//если игра не началась то вход в меню выбора игроков
{lastid=id;	//старт
menu_aktive=-1;
menu->Enter();
break;}
if(game_start==1&&pobeda==false&&porazhenie==false)//игра уже началась
{lastid=id;	//продолжить
menu_aktive=0;
menu->Enter();
PAUSE=false;
break;}
if(game_start==1&&(pobeda==true||porazhenie==true))//игра уже началась и выиграли/просрали игру
{lastid=id;	//статистика
menu_aktive=-5;
menu->Enter();
break;}
case 2://ОПЦИИ или новая игра
if(game_start==0)
{menu->Enter();
menu_aktive=2;	
break;}	
if(game_start==1)
{menu->Enter();
menu_aktive=-1;	
break;}	
case 3://ИНФО или опции
if(game_start==0)
{menu->Enter();
menu_aktive=3;
break;}	
if(game_start==1)
{menu->Enter();
menu_aktive=2;
break;}	
case 4:	//АВТОРЫ или инфо
if(game_start==0)
{menu->Enter();
menu_aktive=4;
break;}
if(game_start==1)
{menu->Enter();
menu_aktive=3;
break;}
case 5:
if(game_start==0)
{return true;} //ВЫХОД или авторы
if(game_start==1)
{menu->Enter();
menu_aktive=4;
break;}
case 6:
if(game_start==0)
{menu->SetFocus(1);
menu->Enter();}
if(game_start==1)
{
if(net_user!=0)
{Close_Net();
}	
return true;}

}
}
else if(id) 
{lastid=id; 
menu->Leave();}
}


if(menu_aktive==3)//МЕНЮ ИНФЫ
{
id=menu_info->Update(dt);
if(id == -1)
{
switch(lastid)
{
case 1://враги
menu_info->Enter();
menu_aktive=31;
break;
case 2://оружие
menu_info->Enter();
menu_aktive=32;
break;
case 3://бонусы
menu_info->Enter();
menu_aktive=33;
break;
case 4://НАЗАД
menu_info->Enter();
menu_aktive=1;	
break;		
}
}
else if(id) 
{lastid=id; 
menu_info->Leave();}
}


if(menu_aktive==-1)//выбор КОЛ-ВА ИГРОКОВ
{
id=menu_start->Update(dt);
if(id == -1)
{
switch(lastid)
{
case 1://1 игрок
menu_start->Enter();
player2_aktive=0;
if(CLASSMOD==false)
{
if(game_start==1)
{new_game();}
game_start=1;
menu_aktive=0;
PAUSE=false;
defence_upgrade_sec=GetCurrentSecond();
}
if(CLASSMOD==true)
{menu_aktive=-3;
player_vibor=1;}
break;
case 2://2 игрока
menu_start->Enter();
player2_aktive=1;
if(CLASSMOD==false)
{
if(game_start==1)
{new_game();}
game_start=1;
menu_aktive=0;
defence_upgrade_sec=GetCurrentSecond();
}
if(CLASSMOD==true)
{menu_aktive=-3;
player_vibor=1;}
break;
case 3://НАЗАД
menu_start->Enter();
menu_aktive=1;	
break;		
}
}
else if(id) 
{lastid=id; 
menu_start->Leave();}
}


if(menu_aktive==-3)//CИСТЕМА КЛАССОВ
{
id=menu_class->Update(dt);
if(id == -1)
{
switch(lastid)
{
case 1://мясник
menu_class->Enter();
//первый игрок
if(player_vibor==1)
{class1=1;
//если нет второго - начало игры
if(player2_aktive==0)
{menu_aktive=0;
if(game_start==1)
{new_game();}
game_start=1;
PAUSE=false;
speed+=5;
defence_upgrade_sec=GetCurrentSecond();}
//если есть - его выбор
if(player2_aktive==1)
{player_vibor=2;
menu_aktive=-4;}
}
break;


case 2://стрелок
menu_class->Enter();
//первый игрок
if(player_vibor==1)
{class1=2;
//если нет второго - начало игры
if(player2_aktive==0)
{menu_aktive=0;
if(game_start==1)
{new_game();}
game_start=1;
PAUSE=false;

tochnost1=0.8f;

defence_upgrade_sec=GetCurrentSecond();}
//если есть - его выбор
if(player2_aktive==1)
{player_vibor=2;
menu_aktive=-4;}
}
break;


case 3://подрывник
menu_class->Enter();
//первый игрок
if(player_vibor==1)
{class1=3;
//если нет второго - начало игры
if(player2_aktive==0)
{menu_aktive=0;
if(game_start==1)
{new_game();}
game_start=1;
PAUSE=false;

vinoslivost1=1;
vzrivchatka1=5;

defence_upgrade_sec=GetCurrentSecond();}
//если есть - его выбор
if(player2_aktive==1)
{player_vibor=2;
menu_aktive=-4;}
}
break;	


case 4://инжинер
menu_class->Enter();
//первый игрок
if(player_vibor==1)
{class1=4;
//если нет второго - начало игры
if(player2_aktive==0)
{menu_aktive=0;
if(game_start==1)
{new_game();}
game_start=1;
PAUSE=false;
defence_upgrade_sec=GetCurrentSecond();}
//если есть - его выбор
if(player2_aktive==1)
{player_vibor=2;
menu_aktive=-4;}
}
break;

case 5://НАЗАД
menu_class->Enter();
menu_aktive=-1;	
break;	

	
}
}
else if(id) 
{lastid=id; 
menu_class->Leave();}
}


if(menu_aktive==-4)//CИСТЕМА КЛАССОВ ИГРОК ВТОРОЙ
{
id=menu_class2->Update(dt);
if(id == -1)
{
switch(lastid)
{
case 1://мясник
menu_class2->Enter();
class2=1;
menu_aktive=0;
if(game_start==1)
{new_game();}
game_start=1;
PAUSE=false;
speed2+=5;

switch(class1)
{case 1:
speed+=5;
break;
case 2:
tochnost1=0.8f;
break;
case 3:
vinoslivost1=1;
vzrivchatka1=5;
break;
case 4:
break;
}




defence_upgrade_sec=GetCurrentSecond();
break;


case 2://стрелок
menu_class2->Enter();
class2=2;
menu_aktive=0;
if(game_start==1)
{new_game();}
game_start=1;
PAUSE=false;


switch(class1)
{case 1:
speed+=5;
break;
case 2:
tochnost1=0.8f;
break;
case 3:
vinoslivost1=1;
vzrivchatka1=5;
break;
case 4:
break;
}


tochnost2=0.8f;

defence_upgrade_sec=GetCurrentSecond();
break;


case 3://подрывник
menu_class2->Enter();
class2=3;
menu_aktive=0;
if(game_start==1)
{new_game();}
game_start=1;
PAUSE=false;



switch(class1)
{case 1:
speed+=5;
break;
case 2:
tochnost1=0.8f;
break;
case 3:
vinoslivost1=1;
vzrivchatka1=5;
break;
case 4:
break;
}

vinoslivost2=1;
vzrivchatka2=5;

defence_upgrade_sec=GetCurrentSecond();
break;	


case 4://инжинер
menu_class2->Enter();
class2=4;
menu_aktive=0;
if(game_start==1)
{new_game();}
game_start=1;
PAUSE=false;



switch(class1)
{case 1:
speed+=5;
break;
case 2:
tochnost1=0.8f;
break;
case 3:
vinoslivost1=1;
vzrivchatka1=5;
break;
case 4:
break;
}


defence_upgrade_sec=GetCurrentSecond();
break;	

case 5://НАЗАД
menu_class2->Enter();
menu_aktive=-1;	
break;	
	
}
}
else if(id) 
{lastid=id; 
menu_class2->Leave();}
}


if(menu_aktive==-5)//СТАТИСТИКА
{
if(hge->Input_GetKeyState(HGEK_ESCAPE)) 
{menu->DelCtrl(1);
menu->DelCtrl(2);
menu->DelCtrl(3);
menu->DelCtrl(4);
menu->DelCtrl(5);
menu->DelCtrl(6);
menu->AddCtrl(new hgeGUIMenuItem(1,menu_font,menu_sound,menu_choose,600,200,0.0f,"Статистика"));
menu->AddCtrl(new hgeGUIMenuItem(2,menu_font,menu_sound,menu_choose,600,240,0.0f,"НоваЯ Игра"));
menu->AddCtrl(new hgeGUIMenuItem(3,menu_font,menu_sound,menu_choose,600,280,0.0f,"Опции"));
menu->AddCtrl(new hgeGUIMenuItem(4,menu_font,menu_sound,menu_choose,600,320,0.0f,"Инфо"));
menu->AddCtrl(new hgeGUIMenuItem(5,menu_font,menu_sound,menu_choose,600,360,0.0f,"Авторы"));
menu->AddCtrl(new hgeGUIMenuItem(6,menu_font,menu_sound,menu_choose,600,400,0.0f,"Выход"));
menu_aktive=1;
PAUSE=true;
menu->SetFocus(1);
menu->Enter();}
}


/*
if(menu_aktive==-2)//выбор yes or no
{
id=menu_really->Update(dt);
if(id == -1)
{
switch(lastid)
{
case 1://da
menu_really->Enter();
menu_aktive=-1;
break;
case 2://net
menu_really->Enter();
menu_aktive=1;
break;	
}
}
else if(id) 
{lastid=id; 
menu_really->Leave();}
}
*/

if(menu_aktive==2)//МЕНЮ OPTIONS
{
id=menu_video->Update(dt);
if(id == -1)
{
switch(lastid)
{
case 1://СИСТЕМА КЛАССОВ on
if(CLASSMOD==false)
{CLASSMOD=true;}
menu_video->Enter();
break;

case 2://СИСТЕМА КЛАССОВ off
if(CLASSMOD==true)
{CLASSMOD=false;}
menu_video->Enter();
break;

case 3://RPGMOD on
if(RPGMOD==false)
{RPGMOD=true;}
menu_video->Enter();
break;

case 4://RPGMOD off
if(RPGMOD==true)
{RPGMOD=false;}
menu_video->Enter();
break;

case 5://ЗВУК
menu_video->Enter();
break;
}
}
else if(id) 
{lastid=id; 
menu_video->Leave();}
}


if(menu_aktive==2)
{
if(hge->Input_GetKeyState(HGEK_ESCAPE)) 
{menu_aktive=1;}
}

if(menu_aktive==4)
{
if(hge->Input_GetKeyState(HGEK_ESCAPE)||hge->Input_GetKeyState(HGEK_ENTER)) 
{menu_aktive=1;}
}

if(menu_aktive==31||menu_aktive==32||menu_aktive==33)
{if(hge->Input_GetKeyState(HGEK_ESCAPE)||hge->Input_GetKeyState(HGEK_ENTER)) 
{menu_aktive=3;}
}






if(menu_aktive==0)
{

//-----------------------------------------------------------||||||||||||||||||||||||||||||||||||||
if(PAUSE==false)
{


char dataBuffer [496];
char sendBuffer [62][8];
char recvBuffer [62][8];

char dataBuffer2 [496];
char sendBuffer2 [62][8];
char recvBuffer2 [62][8];

float sleep_milli;

//-----------------------------------------------------------ПОСЫЛАЕМ ДАННЫЕ КЛИЕНТУ/СЕРВЕРУ-------------------------------

if(net_faza==1)//сервер-клиенту
{
if(net_user==1)
{
sprintf (sendBuffer[0],"%d",(int)x);
sprintf (sendBuffer[1],"%d",(int)y);
sprintf (sendBuffer[2],"%.2f",dx);
sprintf (sendBuffer[3],"%.2f",dy);
sprintf (sendBuffer[4],"%d",(int)px);
sprintf (sendBuffer[5],"%d",(int)py);
sprintf (sendBuffer[6],"%d", oboima);
sprintf (sendBuffer[7],"%d", N_WEAPON1);
sprintf (sendBuffer[8],"%d", hge->Input_GetKeyState(HGEK_ENTER));
sprintf (sendBuffer[9],"%d", hge->Input_GetKeyState(HGEK_SHIFT));
sprintf (sendBuffer[10],"%d", kills);
sprintf (sendBuffer[11],"%d", points1);
for (int ite=0;ite<=N_ZAYAC;ite++)
{
sprintf (sendBuffer[12+ite],"%d", (int)vragi1Objects[ite].v1x);
}
for (int ite=0;ite<=N_ZAYAC;ite++)
{
sprintf (sendBuffer[13+N_ZAYAC+ite],"%d", (int)vragi1Objects[ite].v1y);
}

memcpy(dataBuffer,sendBuffer,496);
send (s[1],dataBuffer,496,0);
net_faza=2;
}

if(net_user==2)
{
received=recv (s[4],dataBuffer2,496,0);
memcpy(recvBuffer2,dataBuffer2,496);

x=atof(recvBuffer2[0]);
y=atof(recvBuffer2[1]);
dx=atof(recvBuffer2[2]);
dy=atof(recvBuffer2[3]);
px=atoi(recvBuffer2[4]);
py=atoi(recvBuffer2[5]);
oboima=atoi(recvBuffer2[6]);
N_WEAPON1=atoi(recvBuffer2[7]);
enter=atoi(recvBuffer2[8]);
shift=atoi(recvBuffer2[9]);
kills=atoi(recvBuffer2[10]);
points1=atoi(recvBuffer2[11]);
for (int ite=0;ite<=N_ZAYAC;ite++)
{
vragi1Objects[ite].v1x= atoi (recvBuffer2[12+ite]);
}
for (int ite=0;ite<=N_ZAYAC;ite++)
{
vragi1Objects[ite].v1y= atoi (recvBuffer2[13+N_ZAYAC+ite]);
}

net_faza=2;
}
}//сервер-клиенту

if(net_faza==2)//клиент-серверу
{
if(net_user==2)
{
sprintf (sendBuffer2[0],"%d",(int)x2);
sprintf (sendBuffer2[1],"%d",(int)y2);
sprintf (sendBuffer2[2],"%.2f",dx2);
sprintf (sendBuffer2[3],"%.2f",dy2);
sprintf (sendBuffer2[4],"%d",(int)p2x);
sprintf (sendBuffer2[5],"%d",(int)p2y);
sprintf (sendBuffer2[6],"%d", oboima2);
sprintf (sendBuffer2[7],"%d", N_WEAPON2);
sprintf (sendBuffer2[8],"%d", hge->Input_GetKeyState(HGEK_SPACE));
sprintf (sendBuffer2[9],"%d", hge->Input_GetKeyState(HGEK_R));
sprintf (sendBuffer2[10],"%d", kills2);
sprintf (sendBuffer2[11],"%d", points2);
memcpy(dataBuffer2,sendBuffer2,96);
send (s[3],dataBuffer2,96,0);
net_faza=1;
}

if(net_user==1)
{
received=recv (s[0],dataBuffer,96,0);
memcpy(recvBuffer,dataBuffer,96);

x2=atof(recvBuffer[0]);
y2=atof(recvBuffer[1]);
dx2=atof(recvBuffer[2]);
dy2=atof(recvBuffer[3]);
p2x=atoi(recvBuffer[4]);
p2y=atoi(recvBuffer[5]);
oboima2=atoi(recvBuffer[6]);
N_WEAPON2=atoi(recvBuffer[7]);
space=atoi(recvBuffer[8]);
r_key=atoi(recvBuffer[9]);
kills2=atoi(recvBuffer[10]);
points2=atoi(recvBuffer[11]);

net_faza=1;
}



}//клиент-серверу





float lag=((1+dt*12)*sqrt(dt/0.006f));
float lag_p=((1+dt*10)*sqrt(dt/0.01f))*((x+1200)/2400);

//чтоб игрок1 тормозил и не улетал за экран
dx*=tormoz; dy*=tormoz;
float lag_igrokam=((1+12*dt)/(1+5*dt))*sqrt(sqrt(sqrt(140/(float)fps)));
x+=dx*lag_igrokam; y+=dy*lag_igrokam;
if(x>1184) {x=1184;}
	if(x<16) {x=16;}
	if(y>884) {y=884;}
	if(y<65) {y=65;}


//чтоб игрок2 тормозил и не улетал за экран
dx2*=tormoz2; dy2*=tormoz2;
x2+=dx2*lag_igrokam; y2+=dy2*lag_igrokam;
	if(x2>1184) {x2=1184;}
	if(x2<16) {x2=16;}
	if(y2>884) {y2=884;}
	if(y2<66) {y2=66;}



for (int i56=0;i56<=N_OBJECTS-1;i56++)//контакт игроков с предметами
{


switch(Objects[i56].type)
{
case 1:
case 2:
//1-й игрок
if((X-Objects[i56].x)<x-10&&(x-10)-(X-Objects[i56].x)<=30&&
y+48<=Objects[i56].y+30&&y+48>=Objects[i56].y+5)//объект перед щами!!!
{x=X-Objects[i56].x+40;}
if((X-Objects[i56].x)>x+10&&(X-Objects[i56].x)-(x+10)<=30&&
y+48<=Objects[i56].y+30&&y+48>=Objects[i56].y+15)//объект за щами!!!
{x=X-Objects[i56].x-40;}
if(X-Objects[i56].x+27>=x-10&&X-Objects[i56].x-30<=x+10&&
y+48>=Objects[i56].y&&y+48-Objects[i56].y>=0&&y+48-Objects[i56].y<=15)//объект под щами!!!
{y=Objects[i56].y-47;}
if(X-Objects[i56].x+27>=x-10&&X-Objects[i56].x-30<=x+10&&
y+48>=Objects[i56].y&&y+48-Objects[i56].y<=40&&y+48-Objects[i56].y>=25)//объект над щами!!!
{y=Objects[i56].y-10;}

//2-й игрок
if((X-Objects[i56].x)<x2-10&&(x2-10)-(X-Objects[i56].x)<=30&&
y2+48<=Objects[i56].y+30&&y2+48>=Objects[i56].y+5)//объект перед щами!!!
{x2=X-Objects[i56].x+39;}
if((X-Objects[i56].x)>x2+10&&(X-Objects[i56].x)-(x2+10)<=30&&
y2+48<=Objects[i56].y+30&&y2+48>=Objects[i56].y+15)//объект за щами!!!
{x2=X-Objects[i56].x-39;}
if(X-Objects[i56].x+27>=x2-10&&X-Objects[i56].x-30<=x2+10&&
y2+48>=Objects[i56].y&&y2+48-Objects[i56].y>=0&&y2+48-Objects[i56].y<=15)//объект под щами!!!
{y2=Objects[i56].y-48;}
if(X-Objects[i56].x+27>=x2-10&&X-Objects[i56].x-30<=x2+10&&
y2+48>=Objects[i56].y&&y2+48-Objects[i56].y<=40&&y2+48-Objects[i56].y>=25)//объект над щами!!!
{y2=Objects[i56].y-11;}
break;
}
}




//ЗАЯЦ

for (int i3=0;i3<=N_ZAYAC;i3++)
{

if(vragi1Objects[i3].ubit!=1)//сама скорость
{	
vragi1Objects[i3].v1x+=vragi1Objects[i3].speed*lag;
//vragi1Objects[i3].v1x+=vragi1Objects[i3].speed*lag;
zayac->Resume();


//агро мясника
if(class1==1&&primanka1>0&&vragi1Objects[i3].v1x<=x-16&&sqrt(((x-16)-vragi1Objects[i3].v1x)*((x-16)-vragi1Objects[i3].v1x)+
(vragi1Objects[i3].v1y-(y-12))*(vragi1Objects[i3].v1y-(y-12)))<=(60+5*primanka1))
{
if(vragi1Objects[i3].v1y<y-12)
{vragi1Objects[i3].v1y+=(0.1f+0.2f*sqrt((float)primanka1))*lag;}
if(vragi1Objects[i3].v1y>y-12)
{vragi1Objects[i3].v1y-=(0.1f+0.2f*sqrt((float)primanka1))*lag;}
}

if(class2==1&&primanka2>0&&vragi1Objects[i3].v1x<=x2-16&&sqrt(((x2-16)-vragi1Objects[i3].v1x)*((x2-16)-vragi1Objects[i3].v1x)+
(vragi1Objects[i3].v1y-(y2-12))*(vragi1Objects[i3].v1y-(y2-12)))<=(60+5*primanka2))
{
if(vragi1Objects[i3].v1y<y2-12)
{vragi1Objects[i3].v1y+=(0.1f+0.2f*sqrt((float)primanka2))*lag;}
if(vragi1Objects[i3].v1y>y2-12)
{vragi1Objects[i3].v1y-=(0.1f+0.2f*sqrt((float)primanka2))*lag;}
}




for (int i51=0;i51<=N_OBJECTS-1;i51++)//контакт с предметами
{
if((X-Objects[i51].x)>vragi1Objects[i3].v1x&&(X-Objects[i51].x)-vragi1Objects[i3].v1x<=200)//объект перед щами!!!
{

switch(Objects[i51].type)
{
case 0:
case 1:
case 2:
if(Objects[i51].y>=vragi1Objects[i3].v1y&&Objects[i51].y-vragi1Objects[i3].v1y<=50)//объект ниже
{
if(Objects[i51].pl==0)//если объект не плоский
{vragi1Objects[i3].v1y-=0.6f;}
vragi1Objects[i3].object_id=i51;}
if(Objects[i51].y<vragi1Objects[i3].v1y&&vragi1Objects[i3].v1y-Objects[i51].y<=35)//объект выше
{vragi1Objects[i3].v1y+=0.6f;}
break;

}

}//закрытие объект перед щами




if((X-Objects[i51].x)<vragi1Objects[i3].v1x&&vragi1Objects[i3].v1x-(X-Objects[i51].x)<=100)//назад на место
{
switch(Objects[i51].type)
{
case 0:
case 1:
case 2:
if(Objects[i51].y>=vragi1Objects[i3].v1y&&
Objects[i51].y-vragi1Objects[i3].v1y>=30&&Objects[i51].y-vragi1Objects[i3].v1y<=80)//объект ниже
{vragi1Objects[i3].v1y+=0.3f;}
if(Objects[i51].y<vragi1Objects[i3].v1y&&
vragi1Objects[i3].v1y-Objects[i51].y>=15&&vragi1Objects[i3].v1y-Objects[i51].y<=50)//объект выше
{vragi1Objects[i3].v1y-=0.3f;}
break;
}
}//закрытие возврата на место



}//закрытие контакта с предметами

}//закрытие скорости


for (int i22=0;i22<=N_VOLK;i22++)//контакт с волком
{
if(((vragi1Objects[i3].v1y>vragi2Objects[i22].v2y&&vragi1Objects[i3].v1y-vragi2Objects[i22].v2y<=70)||
   (vragi2Objects[i22].v2y>vragi1Objects[i3].v1y&&vragi2Objects[i22].v2y-vragi1Objects[i3].v1y<=70))&&
   ((vragi1Objects[i3].v1x>vragi2Objects[i22].v2x&&vragi1Objects[i3].v1x-vragi2Objects[i22].v2x<=100)||
   (vragi2Objects[i22].v2x>vragi1Objects[i3].v1x&&vragi2Objects[i22].v2x-vragi1Objects[i3].v1x<=100))
   &&vragi2Objects[i22].ubit!=1)
{
if(DIFF!=0||(DIFF==0&&vragi1Objects[i3].v1x>=236))
{vragi1Objects[i3].speed+=0.01f*lag;}
if(vragi1Objects[i3].v1x<236&&DIFF==0)
{vragi1Objects[i3].speed+=0.005f*lag;}
}
}

for (int i85=0;i85<=N_MEDVED;i85++)//контакт с медведем
{
if(vragi1Objects[i3].v1y>vragi3Objects[i85].v3y+150&&vragi1Objects[i3].v1y-(vragi3Objects[i85].v3y+200)<=150&&
   vragi1Objects[i3].v1x<vragi3Objects[i85].v3x&&vragi3Objects[i85].ubit!=1)
{vragi1Objects[i3].v1y-=(vragi1Objects[i3].speed/4)*lag;
//if(vragi3Objects[i85].v3x-vragi1Objects[i3].v1x<40)
//{vragi1Objects[i3].speed=0.6f;}
}

if(vragi1Objects[i3].v1y<=vragi3Objects[i85].v3y+150&&(vragi3Objects[i85].v3y+200)-vragi1Objects[i3].v1y<=150&&
   vragi1Objects[i3].v1x<vragi3Objects[i85].v3x&&vragi3Objects[i85].ubit!=1)
{vragi1Objects[i3].v1y+=(vragi1Objects[i3].speed/4)*lag;
//if(vragi3Objects[i85].v3x-vragi1Objects[i3].v1x<40)
//{vragi1Objects[i3].speed=0.6f;}
}

}




 //если замочили - появляется заново
if(vragi1Objects[i3].ubit==1)
{
if(perez_akt==vragi1Objects[i3].timeout&&
((perez_akt_milli>=vragi1Objects[i3].timeout_milli&&vragi1Objects[i3].timeout_milli<800)||
(perez_akt_milli<vragi1Objects[i3].timeout_milli&&vragi1Objects[i3].timeout_milli>=800)))
{zayac->SetTexture(zayac_go_tex);
vragi1Objects[i3].ubit=0;
vragi1Objects[i3].pokoin=0;	
vragi1Objects[i3].v1x=-50;
vragi1Objects[i3].bezuh=0;
vragi1Objects[i3].bezboshki=0;
if(player2_aktive==0)
{
if(DIFF!=0)
{vragi1Objects[i3].v1y=hge->Random_Float(250,750);}
if(DIFF==0)
{vragi1Objects[i3].v1y=hge->Random_Float(300,700);}
}
if(player2_aktive==1)
{
if(DIFF!=0)
{vragi1Objects[i3].v1y=hge->Random_Float(200,800);}
if(DIFF==0)
{vragi1Objects[i3].v1y=hge->Random_Float(250,750);}
}
vragi1Objects[i3].health=50;
switch(DIFF)
{
case 0:
vragi1Objects[i3].speed=hge->Random_Float(0.8f,0.9f);
break;

case 1:
vragi1Objects[i3].speed=hge->Random_Float(1,1.1f);
break;

case 2:
vragi1Objects[i3].speed=hge->Random_Float(1.1f,1.3f);
break;
}
if(sit1==2)
{vragi1Objects[N_ZAYAC].speed=0.5f;}
vragi1Objects[i3].defence=defence_zayac;
vragi1Objects[i3].object_id=-1;
vragi1Objects[i3].A=0;
vragi1Objects[i3].energy=0;
vragi1Objects[i3].vzorvan=false;}

}







if(vragi1Objects[i3].v1x>1200&&vragi1Objects[i3].ubit!=1) // если заяц забежал за экран
{LIVES--;
vragi1Objects[i3].bezuh=0;
vragi1Objects[i3].bezboshki=0;
vragi1Objects[i3].v1x=-50;
if(player2_aktive==0)
{
if(DIFF!=0)
{vragi1Objects[i3].v1y=hge->Random_Float(250,750);}
if(DIFF==0)
{vragi1Objects[i3].v1y=hge->Random_Float(300,700);}
}
if(player2_aktive==1)
{
if(DIFF!=0)
{vragi1Objects[i3].v1y=hge->Random_Float(150,850);}
if(DIFF==0)
{vragi1Objects[i3].v1y=hge->Random_Float(250,750);}
}
vragi1Objects[i3].health=50;
switch(DIFF)
{
case 0:
vragi1Objects[i3].speed=hge->Random_Float(0.8f,0.9f);
break;

case 1:
vragi1Objects[i3].speed=hge->Random_Float(1,1.1f);
break;

case 2:
vragi1Objects[i3].speed=hge->Random_Float(1.1f,1.3f);
break;
}
if(sit1==2)
{vragi1Objects[N_ZAYAC].speed=0.5f;}
vragi1Objects[i3].defence=defence_zayac;
vragi1Objects[i3].object_id=-1;
vragi1Objects[i3].A=0;
}



//коцанье зайца (отрывание ушей)
if(((((py<=vragi1Objects[i3].v1y+12&&py>vragi1Objects[i3].v1y&&px<vragi1Objects[i3].v1x)||
	 (p1d1y<=vragi1Objects[i3].v1y+12&&p1d1y>vragi1Objects[i3].v1y&&p1d1x<vragi1Objects[i3].v1x)||
     (p1d2y<=vragi1Objects[i3].v1y+12&&p1d2y>vragi1Objects[i3].v1y&&p1d2x<vragi1Objects[i3].v1x)||
     (p1d3y<=vragi1Objects[i3].v1y+12&&p1d3y>vragi1Objects[i3].v1y&&p1d3x<vragi1Objects[i3].v1x)||
     (p1d4y<=vragi1Objects[i3].v1y+12&&p1d4y>vragi1Objects[i3].v1y&&p1d4x<vragi1Objects[i3].v1x))&&
	 aktivatorp==1&&x-55>vragi1Objects[i3].v1x&&vragi1Objects[i3].bezuh==0&&vragi1Objects[i3].ubit!=1)||
(((p2y<=vragi1Objects[i3].v1y+12&&p2y>vragi1Objects[i3].v1y&&p2x<vragi1Objects[i3].v1x)||
 (p2d1y<=vragi1Objects[i3].v1y+12&&p2d1y>vragi1Objects[i3].v1y&&p2d1x<vragi1Objects[i3].v1x)||
 (p2d2y<=vragi1Objects[i3].v1y+12&&p2d2y>vragi1Objects[i3].v1y&&p2d2x<vragi1Objects[i3].v1x)||
 (p2d3y<=vragi1Objects[i3].v1y+12&&p2d3y>vragi1Objects[i3].v1y&&p2d3x<vragi1Objects[i3].v1x)||
 (p2d4y<=vragi1Objects[i3].v1y+12&&p2d4y>vragi1Objects[i3].v1y&&p2d4x<vragi1Objects[i3].v1x))&&
 aktivatorp2==1&&x2-55>vragi1Objects[i3].v1x&&vragi1Objects[i3].bezuh==0&&vragi1Objects[i3].ubit!=1))||
 (katana1_anime->IsPlaying()==true&&vragi1Objects[i3].v1x>x-90&&y<vragi1Objects[i3].v1y+12&&y>vragi1Objects[i3].v1y&&
 x-55>vragi1Objects[i3].v1x&&vragi1Objects[i3].bezuh==0&&vragi1Objects[i3].ubit!=1))
//vragi1Objects[i3].bezuh==0 чтобы ухи не возвращались на место после повторного попадания зайцу по "ушам"
{


uhiObjects[N_UHI].niz=vragi1Objects[i3].v1y+38;
vragi1Objects[i3].bezuh=1;
uhiObjects[N_UHI].uhix=vragi1Objects[i3].v1x+18;
uhiObjects[N_UHI].uhiy=vragi1Objects[i3].v1y-3;
uhiObjects[N_UHI].akt=1;

if((((py<=vragi1Objects[i3].v1y+12&&py>vragi1Objects[i3].v1y&&px<vragi1Objects[i3].v1x)||
	 (p1d1y<=vragi1Objects[i3].v1y+12&&p1d1y>vragi1Objects[i3].v1y&&p1d1x<vragi1Objects[i3].v1x)||
     (p1d2y<=vragi1Objects[i3].v1y+12&&p1d2y>vragi1Objects[i3].v1y&&p1d2x<vragi1Objects[i3].v1x)||
     (p1d3y<=vragi1Objects[i3].v1y+12&&p1d3y>vragi1Objects[i3].v1y&&p1d3x<vragi1Objects[i3].v1x)||
     (p1d4y<=vragi1Objects[i3].v1y+12&&p1d4y>vragi1Objects[i3].v1y&&p1d4x<vragi1Objects[i3].v1x))&&
	 aktivatorp==1&&x-55>vragi1Objects[i3].v1x)||
 (katana1_anime->IsPlaying()==true&&vragi1Objects[i3].v1x>x-90&&y<vragi1Objects[i3].v1y+12&&y>vragi1Objects[i3].v1y&&
 x-55>vragi1Objects[i3].v1x&&vragi1Objects[i3].bezuh==0&&vragi1Objects[i3].ubit!=1))
{points1+=10;}//10 очков за уши игроку 1
if(((p2y<=vragi1Objects[i3].v1y+12&&p2y>vragi1Objects[i3].v1y&&p2x<vragi1Objects[i3].v1x)||
 (p2d1y<=vragi1Objects[i3].v1y+12&&p2d1y>vragi1Objects[i3].v1y&&p2d1x<vragi1Objects[i3].v1x)||
 (p2d2y<=vragi1Objects[i3].v1y+12&&p2d2y>vragi1Objects[i3].v1y&&p2d2x<vragi1Objects[i3].v1x)||
 (p2d3y<=vragi1Objects[i3].v1y+12&&p2d3y>vragi1Objects[i3].v1y&&p2d3x<vragi1Objects[i3].v1x)||
 (p2d4y<=vragi1Objects[i3].v1y+12&&p2d4y>vragi1Objects[i3].v1y&&p2d4x<vragi1Objects[i3].v1x))&&
 aktivatorp2==1&&x2-55>vragi1Objects[i3].v1x)
{points2+=10;}//10 очков за уши игроку 2

N_UHI++;

if(N_UHI>=MAX_UHI-1)
{N_UHI=0;}

}//закрытие коцанья зайца





if(uhi_a->IsPlaying()==false)
{
for (int i8=0;i8<=N_TRUPS;i8++)
{
if(trupsObjects[i8].type==2)
{trupsObjects[i8].type=3;}
}
}


if((((py<vragi1Objects[i3].v1y+40&&py>vragi1Objects[i3].v1y+12&&px<=vragi1Objects[i3].v1x&&px>vragi1Objects[i3].v1x-600*lag)||
   (p1d1y<vragi1Objects[i3].v1y+40&&p1d1y>vragi1Objects[i3].v1y+12&&p1d1x<=vragi1Objects[i3].v1x&&p1d1x>vragi1Objects[i3].v1x-300*lag)||
   (p1d2y<vragi1Objects[i3].v1y+40&&p1d2y>vragi1Objects[i3].v1y+12&&p1d2x<=vragi1Objects[i3].v1x&&p1d2x>vragi1Objects[i3].v1x-300*lag)||
   (p1d3y<vragi1Objects[i3].v1y+40&&p1d3y>vragi1Objects[i3].v1y+12&&p1d3x<=vragi1Objects[i3].v1x&&p1d3x>vragi1Objects[i3].v1x-300*lag)||
   (p1d4y<vragi1Objects[i3].v1y+40&&p1d4y>vragi1Objects[i3].v1y+12&&p1d4x<=vragi1Objects[i3].v1x&&p1d4x>vragi1Objects[i3].v1x-300*lag))&&
   aktivatorp==1&&x-55>vragi1Objects[i3].v1x&&vragi1Objects[i3].ubit!=1)||
   (((p2y<vragi1Objects[i3].v1y+40&&p2y>vragi1Objects[i3].v1y+12&&p2x<=vragi1Objects[i3].v1x&&p2x>vragi1Objects[i3].v1x-600*lag)||
   (p2d1y<vragi1Objects[i3].v1y+40&&p2d1y>vragi1Objects[i3].v1y+12&&p2d1x<=vragi1Objects[i3].v1x&&p2d1x>vragi1Objects[i3].v1x-300*lag)||
   (p2d2y<vragi1Objects[i3].v1y+40&&p2d2y>vragi1Objects[i3].v1y+12&&p2d2x<=vragi1Objects[i3].v1x&&p2d2x>vragi1Objects[i3].v1x-300*lag)||
   (p2d3y<vragi1Objects[i3].v1y+40&&p2d3y>vragi1Objects[i3].v1y+12&&p2d3x<=vragi1Objects[i3].v1x&&p2d3x>vragi1Objects[i3].v1x-300*lag)||
   (p2d4y<vragi1Objects[i3].v1y+40&&p2d4y>vragi1Objects[i3].v1y+12&&p2d4x<=vragi1Objects[i3].v1x&&p2d4x>vragi1Objects[i3].v1x-300*lag))&&
  aktivatorp2==1&&x2-55>vragi1Objects[i3].v1x&&vragi1Objects[i3].ubit!=1))//просчёт урона
{


if(shot==0)
{
if(((py<vragi1Objects[i3].v1y+40&&py>vragi1Objects[i3].v1y+12&&px<=vragi1Objects[i3].v1x&&px>vragi1Objects[i3].v1x-600*lag)||
   (p1d1y<vragi1Objects[i3].v1y+40&&p1d1y>vragi1Objects[i3].v1y+12&&p1d1x<=vragi1Objects[i3].v1x&&p1d1x>vragi1Objects[i3].v1x-300*lag)||
   (p1d2y<vragi1Objects[i3].v1y+40&&p1d2y>vragi1Objects[i3].v1y+12&&p1d2x<=vragi1Objects[i3].v1x&&p1d2x>vragi1Objects[i3].v1x-300*lag)||
   (p1d3y<vragi1Objects[i3].v1y+40&&p1d3y>vragi1Objects[i3].v1y+12&&p1d3x<=vragi1Objects[i3].v1x&&p1d3x>vragi1Objects[i3].v1x-300*lag)||
   (p1d4y<vragi1Objects[i3].v1y+40&&p1d4y>vragi1Objects[i3].v1y+12&&p1d4x<=vragi1Objects[i3].v1x&&p1d4x>vragi1Objects[i3].v1x-300*lag))&&
 aktivatorp==1&&x-55>vragi1Objects[i3].v1x)	
{vragi1Objects[i3].killed_by=1;}//попал игрок 1
if(((p2y<vragi1Objects[i3].v1y+40&&p2y>vragi1Objects[i3].v1y+12&&p2x<=vragi1Objects[i3].v1x&&p2x>vragi1Objects[i3].v1x-600*lag)||
   (p2d1y<vragi1Objects[i3].v1y+40&&p2d1y>vragi1Objects[i3].v1y+12&&p2d1x<=vragi1Objects[i3].v1x&&p2d1x>vragi1Objects[i3].v1x-300*lag)||
   (p2d2y<vragi1Objects[i3].v1y+40&&p2d2y>vragi1Objects[i3].v1y+12&&p2d2x<=vragi1Objects[i3].v1x&&p2d2x>vragi1Objects[i3].v1x-300*lag)||
   (p2d3y<vragi1Objects[i3].v1y+40&&p2d3y>vragi1Objects[i3].v1y+12&&p2d3x<=vragi1Objects[i3].v1x&&p2d3x>vragi1Objects[i3].v1x-300*lag)||
   (p2d4y<vragi1Objects[i3].v1y+40&&p2d4y>vragi1Objects[i3].v1y+12&&p2d4x<=vragi1Objects[i3].v1x&&p2d4x>vragi1Objects[i3].v1x-300*lag))&&
 aktivatorp2==1&&x2-55>vragi1Objects[i3].v1x)
{vragi1Objects[i3].killed_by=2;}//попал игрок 2











if(((py<vragi1Objects[i3].v1y+40&&py>vragi1Objects[i3].v1y+18)||
   (p1d1y<vragi1Objects[i3].v1y+40&&p1d1y>vragi1Objects[i3].v1y+18)||
   (p1d2y<vragi1Objects[i3].v1y+40&&p1d2y>vragi1Objects[i3].v1y+18)||
   (p1d3y<vragi1Objects[i3].v1y+40&&p1d3y>vragi1Objects[i3].v1y+18)||
   (p1d4y<vragi1Objects[i3].v1y+40&&p1d4y>vragi1Objects[i3].v1y+18))||
   ((p2y<vragi1Objects[i3].v1y+40&&p2y>vragi1Objects[i3].v1y+18)||
   (p2d1y<vragi1Objects[i3].v1y+40&&p2d1y>vragi1Objects[i3].v1y+18)||
   (p2d2y<vragi1Objects[i3].v1y+40&&p2d2y>vragi1Objects[i3].v1y+18)||
   (p2d3y<vragi1Objects[i3].v1y+40&&p2d3y>vragi1Objects[i3].v1y+18)||
   (p2d4y<vragi1Objects[i3].v1y+40&&p2d4y>vragi1Objects[i3].v1y+18)))//ОБЫЧНОЕ ПОПАДАНИЕ	
{

if(vragi1Objects[i3].killed_by==1)	
{

if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi1Objects[i3].defence>=5||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi1Objects[i3].defence>=5)
{
if(LVL1%2==0)
{vragi1Objects[i3].health-=damage[N_WEAPON1]+LVL1/2*attack1-vragi1Objects[i3].defence;}
if(LVL1%2==1)
{vragi1Objects[i3].health-=damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi1Objects[i3].defence;}
}
//гарантированный урон
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi1Objects[i3].defence<5||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi1Objects[i3].defence<5)
{vragi1Objects[i3].health-=5;}
}//RPG

if(RPGMOD==false)
{vragi1Objects[i3].health-=damage[N_WEAPON1];}

}//урон от оружия игрока 1

if(vragi1Objects[i3].killed_by==2)
{

if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi1Objects[i3].defence>=5||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi1Objects[i3].defence>=5)
{
if(LVL2%2==0)	
{vragi1Objects[i3].health-=damage[N_WEAPON2]+LVL2/2*attack2-vragi1Objects[i3].defence;}
if(LVL2%2==1)	
{vragi1Objects[i3].health-=damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi1Objects[i3].defence;}
}
//гарантированный урон
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi1Objects[i3].defence<5||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi1Objects[i3].defence<5)
{vragi1Objects[i3].health-=5;}
}//RPG

if(RPGMOD==false)
{vragi1Objects[i3].health-=damage[N_WEAPON2];}

}//урон от оружия игрока 2

hge->Effect_PlayEx(shot1,volume*8/10,0,0);
}//ЗАКРЫТИЕ ПОПАДАНИЯ

if(((py<=vragi1Objects[i3].v1y+18&&py>vragi1Objects[i3].v1y+12)||
   (p1d1y<=vragi1Objects[i3].v1y+18&&p1d1y>vragi1Objects[i3].v1y+12)||
   (p1d2y<=vragi1Objects[i3].v1y+18&&p1d2y>vragi1Objects[i3].v1y+12)||
   (p1d3y<=vragi1Objects[i3].v1y+18&&p1d3y>vragi1Objects[i3].v1y+12)||
   (p1d4y<=vragi1Objects[i3].v1y+18&&p1d4y>vragi1Objects[i3].v1y+12))||
   ((p2y<=vragi1Objects[i3].v1y+18&&p2y>vragi1Objects[i3].v1y+12)||
   (p2d1y<=vragi1Objects[i3].v1y+18&&p2d1y>vragi1Objects[i3].v1y+12)||
   (p2d2y<=vragi1Objects[i3].v1y+18&&p2d2y>vragi1Objects[i3].v1y+12)||
   (p2d3y<=vragi1Objects[i3].v1y+18&&p2d3y>vragi1Objects[i3].v1y+12)||
   (p2d4y<=vragi1Objects[i3].v1y+18&&p2d4y>vragi1Objects[i3].v1y+12)))//ХЭДШОТ!!!
{

if(vragi1Objects[i3].killed_by==1)	
{
if(RPGMOD==true)//RPG
{
if((damage[N_WEAPON1]+LVL1/2*attack1-vragi1Objects[i3].defence)*2>=10||
(damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi1Objects[i3].defence)*2>=10)
{
if(LVL1%2==0)
{vragi1Objects[i3].health-=(damage[N_WEAPON1]+LVL1/2*attack1-vragi1Objects[i3].defence)*2;}
if(LVL1%2==1)
{vragi1Objects[i3].health-=(damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi1Objects[i3].defence)*2;}
}
//гарантированный урон
if((damage[N_WEAPON1]+LVL1/2*attack1-vragi1Objects[i3].defence)*2<10||
(damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi1Objects[i3].defence)*2<10)
{vragi1Objects[i3].health-=10;}
}//RPG

if(RPGMOD==false)
{vragi1Objects[i3].health-=damage[N_WEAPON1]*2;}

points1+=25;}//урон от оружия игрока 1

if(vragi1Objects[i3].killed_by==2)
{
if(RPGMOD==true)//RPG
{
if((damage[N_WEAPON2]+LVL2/2*attack2-vragi1Objects[i3].defence)*2>=10||
(damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi1Objects[i3].defence)*2>=10)
{
if(LVL2%2==0)	
{vragi1Objects[i3].health-=(damage[N_WEAPON2]+LVL2/2*attack2-vragi1Objects[i3].defence)*2;}
if(LVL2%2==1)	
{vragi1Objects[i3].health-=(damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi1Objects[i3].defence)*2;}
}

//гарантированный урон
if((damage[N_WEAPON2]+LVL2/2*attack2-vragi1Objects[i3].defence)*2<10||
(damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi1Objects[i3].defence)*2<10)
{vragi1Objects[i3].health-=10;}
}//RPG

if(RPGMOD==false)
{vragi1Objects[i3].health-=damage[N_WEAPON2]*2;}

points2+=25;}//урон от оружия игрока 2

headshotPan=-75+vragi1Objects[i3].v1x/9;
headshot();

if(vragi1Objects[i3].health<-70&&vragi1Objects[i3].bezboshki==0)//отрывание бошки
{
vragi1Objects[i3].bezboshki=1;
if(vragi1Objects[i3].killed_by==1)
{points1+=25;}
if(vragi1Objects[i3].killed_by==2)
{points2+=25;}

if(vragi1Objects[i3].bezuh==0)
{boshkiObjects[N_HEAD].bezuh=0;}
if(vragi1Objects[i3].bezuh==1)
{boshkiObjects[N_HEAD].bezuh=1;}

boshkiObjects[N_HEAD].vrag=1;
boshkiObjects[N_HEAD].niz=vragi1Objects[i3].v1y+38;
boshkiObjects[N_HEAD].bx=vragi1Objects[i3].v1x+18;
boshkiObjects[N_HEAD].by=vragi1Objects[i3].v1y-3;
boshkiObjects[N_HEAD].bzdik=0;
boshkiObjects[N_HEAD].seed=hge->Random_Int(1,5);
boshkiObjects[N_HEAD].bzdik_seed=hge->Random_Int(1,3);
boshkiObjects[N_HEAD].akt=1;

N_HEAD++;

if(N_HEAD>=MAX_HEAD-1)
{N_HEAD=0;}

}//закрытие отрывания бошки


}//ХЭДШОТ ЗАКОНЧИЛСЯ


if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!



krovyakObjects[N_BLOOD].seed=hge->Random_Int(1,3);
krovyakObjects[N_BLOOD].vrag=1;

if(vragi1Objects[i3].killed_by==1)	
{
if(py<vragi1Objects[i3].v1y+40&&py>vragi1Objects[i3].v1y+12&&px<=vragi1Objects[i3].v1x)	
{ppp=1;
krovyakObjects[N_BLOOD].y1=py; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=py+5;}
if(p1d1y<vragi1Objects[i3].v1y+40&&p1d1y>vragi1Objects[i3].v1y+12&&p1d1x<=vragi1Objects[i3].v1x)	
{ppp=2;
krovyakObjects[N_BLOOD].y1=p1d1y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p1d1y+5;}
if(p1d2y<vragi1Objects[i3].v1y+40&&p1d2y>vragi1Objects[i3].v1y+12&&p1d2x<=vragi1Objects[i3].v1x)	
{ppp=3;
krovyakObjects[N_BLOOD].y1=p1d2y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p1d2y+5;}
if(p1d3y<vragi1Objects[i3].v1y+40&&p1d3y>vragi1Objects[i3].v1y+12&&p1d3x<=vragi1Objects[i3].v1x)	
{ppp=4;
krovyakObjects[N_BLOOD].y1=p1d3y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p1d3y+5;}
if(p1d4y<vragi1Objects[i3].v1y+40&&p1d4y>vragi1Objects[i3].v1y+12&&p1d4x<=vragi1Objects[i3].v1x)	
{ppp=5;
krovyakObjects[N_BLOOD].y1=p1d4y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p1d4y+5;}
}
if(vragi1Objects[i3].killed_by==2)
{
if(p2y<vragi1Objects[i3].v1y+40&&p2y>vragi1Objects[i3].v1y+12&&p2x<=vragi1Objects[i3].v1x)
{ppp=1;
krovyakObjects[N_BLOOD].y1=p2y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p2y+5;}
if(p2d1y<vragi1Objects[i3].v1y+40&&p2d1y>vragi1Objects[i3].v1y+12&&p2d1x<=vragi1Objects[i3].v1x)
{ppp=2;
krovyakObjects[N_BLOOD].y1=p2d1y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p2d1y+5;}
if(p2d2y<vragi1Objects[i3].v1y+40&&p2d2y>vragi1Objects[i3].v1y+12&&p2d2x<=vragi1Objects[i3].v1x)
{ppp=3;
krovyakObjects[N_BLOOD].y1=p2d2y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p2d2y+5;}
if(p2d3y<vragi1Objects[i3].v1y+40&&p2d3y>vragi1Objects[i3].v1y+12&&p2d3x<=vragi1Objects[i3].v1x)
{ppp=4;
krovyakObjects[N_BLOOD].y1=p2d3y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p2d3y+5;}
if(p2d4y<vragi1Objects[i3].v1y+40&&p2d4y>vragi1Objects[i3].v1y+12&&p2d4x<=vragi1Objects[i3].v1x)
{ppp=5;
krovyakObjects[N_BLOOD].y1=p2d4y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p2d4y+5;}
}
krovyakObjects[N_BLOOD].x2=vragi1Objects[i3].v1x+10;
krovyakObjects[N_BLOOD].x1=vragi1Objects[i3].v1x;
krovyakObjects[N_BLOOD].xstart=vragi1Objects[i3].v1x;
krovyakObjects[N_BLOOD].niz=vragi1Objects[i3].v1y+40;
krovyakObjects[N_BLOOD].blood_time=GetTime();
krovyakObjects[N_BLOOD].blood_time_sec=perez_akt;
krovyakObjects[N_BLOOD].akt=1;
krovyakObjects[N_BLOOD].faza=1;


N_BLOOD++;

if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!


krovyakObjects[N_BLOOD].seed=0;//кровяк самого попадания (точка)
krovyakObjects[N_BLOOD].vrag=1;

if(vragi1Objects[i3].killed_by==1)
{
if(ppp==1)	
{krovyakObjects[N_BLOOD].y1=py-4;
krovyakObjects[N_BLOOD].y2=py+4;}
if(ppp==2)	
{krovyakObjects[N_BLOOD].y1=p1d1y-4;
krovyakObjects[N_BLOOD].y2=p1d1y+4;}
if(ppp==3)	
{krovyakObjects[N_BLOOD].y1=p1d2y-4;
krovyakObjects[N_BLOOD].y2=p1d2y+4;}
if(ppp==4)	
{krovyakObjects[N_BLOOD].y1=p1d3y-4;
krovyakObjects[N_BLOOD].y2=p1d3y+4;}
if(ppp==5)	
{krovyakObjects[N_BLOOD].y1=p1d4y-4;
krovyakObjects[N_BLOOD].y2=p1d4y+4;}
}

if(vragi1Objects[i3].killed_by==2)
{
if(ppp==1)	
{krovyakObjects[N_BLOOD].y1=p2y-4;
krovyakObjects[N_BLOOD].y2=p2y+4;}
if(ppp==2)	
{krovyakObjects[N_BLOOD].y1=p2d1y-4;
krovyakObjects[N_BLOOD].y2=p2d1y+4;}
if(ppp==3)	
{krovyakObjects[N_BLOOD].y1=p2d2y-4;
krovyakObjects[N_BLOOD].y2=p2d2y+4;}
if(ppp==4)	
{krovyakObjects[N_BLOOD].y1=p2d3y-4;
krovyakObjects[N_BLOOD].y2=p2d3y+4;}
if(ppp==5)	
{krovyakObjects[N_BLOOD].y1=p2d4y-4;
krovyakObjects[N_BLOOD].y2=p2d4y+4;}
}

krovyakObjects[N_BLOOD].x2=vragi1Objects[i3].v1x+46;
krovyakObjects[N_BLOOD].x1=vragi1Objects[i3].v1x+38;
krovyakObjects[N_BLOOD].blood_time=GetTime();
krovyakObjects[N_BLOOD].blood_time_sec=perez_akt;
krovyakObjects[N_BLOOD].akt=1;


N_BLOOD++;

if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!


krovyakObjects[N_BLOOD].seed=hge->Random_Int(101,103);
krovyakObjects[N_BLOOD].vrag=1;
if(vragi1Objects[i3].killed_by==1)	
{
if(ppp==1)
{krovyakObjects[N_BLOOD].y1=py; //КРОВЯК (вперед)
krovyakObjects[N_BLOOD].y2=py+5;}
if(ppp==2)	
{krovyakObjects[N_BLOOD].y1=p1d1y;
krovyakObjects[N_BLOOD].y2=p1d1y+5;}
if(ppp==3)	
{krovyakObjects[N_BLOOD].y1=p1d2y;
krovyakObjects[N_BLOOD].y2=p1d2y+5;}
if(ppp==4)	
{krovyakObjects[N_BLOOD].y1=p1d3y;
krovyakObjects[N_BLOOD].y2=p1d3y+5;}
if(ppp==5)	
{krovyakObjects[N_BLOOD].y1=p1d4y;
krovyakObjects[N_BLOOD].y2=p1d4y+5;}
}

if(vragi1Objects[i3].killed_by==2)
{
if(ppp==1)	
{krovyakObjects[N_BLOOD].y1=p2y;
krovyakObjects[N_BLOOD].y2=p2y+5;}
if(ppp==2)	
{krovyakObjects[N_BLOOD].y1=p2d1y;
krovyakObjects[N_BLOOD].y2=p2d1y+5;}
if(ppp==3)	
{krovyakObjects[N_BLOOD].y1=p2d2y;
krovyakObjects[N_BLOOD].y2=p2d2y+5;}
if(ppp==4)	
{krovyakObjects[N_BLOOD].y1=p2d3y;
krovyakObjects[N_BLOOD].y2=p2d3y+5;}
if(ppp==5)	
{krovyakObjects[N_BLOOD].y1=p2d4y;
krovyakObjects[N_BLOOD].y2=p2d4y+5;}
}

krovyakObjects[N_BLOOD].x2=vragi1Objects[i3].v1x+40;
krovyakObjects[N_BLOOD].x1=vragi1Objects[i3].v1x+45;
krovyakObjects[N_BLOOD].xstart=vragi1Objects[i3].v1x+40;
krovyakObjects[N_BLOOD].niz=vragi1Objects[i3].v1y+40;
krovyakObjects[N_BLOOD].blood_time=GetTime();
krovyakObjects[N_BLOOD].blood_time_sec=perez_akt;
krovyakObjects[N_BLOOD].akt=1;
krovyakObjects[N_BLOOD].faza=1;


N_BLOOD++;

if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!






shot=1;


if(vragi1Objects[i3].killed_by==1)
{
if(N_WEAPON1==1||N_WEAPON1==2||N_WEAPON1==4||N_WEAPON1==6||N_WEAPON1==9||N_WEAPON1==15)//если это ПМ или ПП19 или ТТ или МАС или Glock или FN 5-7 то патрон слабый
{aktivatorp=0;
oboima-=1;}


if(N_WEAPON1==7)
{
if(ppp==2)
{aktivatorp1d1=0;
p1d1y=y-9;
p1d1x=x-24;}
if(ppp==3)
{aktivatorp1d2=0;
p1d2y=y-9;
p1d2x=x-24;}
if(ppp==4)
{aktivatorp1d3=0;
p1d3y=y-9;
p1d3x=x-24;}
if(ppp==5)
{aktivatorp1d4=0;
p1d4y=y-9;
p1d4x=x-24;}
}


if(N_WEAPON1==0||N_WEAPON1==3||N_WEAPON1==5||N_WEAPON1==8||N_WEAPON1==14)// если это АК или револьвер то косит всех подряд
{shot=0;}
}

if(vragi1Objects[i3].killed_by==2)
{
if(N_WEAPON2==1||N_WEAPON2==2||N_WEAPON2==4||N_WEAPON2==6||N_WEAPON2==9||N_WEAPON2==15)//если это ПМ или ПП19 или ТТ или МАС или Glock или FN 5-7 то патрон слабый
{aktivatorp2=0;
oboima2-=1;}

if(N_WEAPON2==7)
{
if(ppp==2)
{aktivatorp2d1=0;
p2d1y=y2-9;
p2d1x=x2-24;}
if(ppp==3)
{aktivatorp2d2=0;
p2d2y=y2-9;
p2d2x=x2-24;}
if(ppp==4)
{aktivatorp2d3=0;
p2d3y=y2-9;
p2d3x=x2-24;}
if(ppp==5)
{aktivatorp2d4=0;
p2d4y=y2-9;
p2d4x=x2-24;}

}


if(N_WEAPON2==0||N_WEAPON2==3||N_WEAPON2==5||N_WEAPON2==8||N_WEAPON2==14)// если это АК или револьвер то косит всех подряд
{shot=0;}
}














}//if shot==0


}//закрытие просчёта урона













//разрыв в ЩИ!!!-------------------------ММММММММЯЯЯЯЯЯЯЯЯЯССССССССООООООООООО
if(vragi1Objects[i3].health<-140&&vragi1Objects[i3].ubit!=1)
{
vragi1Objects[i3].ubit=1;







vragi1Objects[i3].timeout_milli=GetTime();
switch(DIFF)
{
case 0:
if(perez_akt<56)
{vragi1Objects[i3].timeout=perez_akt+4;}
if(perez_akt>=56)
{vragi1Objects[i3].timeout=perez_akt-56;}
break;
case 1:
if(perez_akt<57)
{vragi1Objects[i3].timeout=perez_akt+3;}
if(perez_akt>=57)
{vragi1Objects[i3].timeout=perez_akt-57;}
break;
case 2:
if(perez_akt<58)
{vragi1Objects[i3].timeout=perez_akt+2;}
if(perez_akt>=58)
{vragi1Objects[i3].timeout=perez_akt-58;}
break;
}
if(vragi1Objects[i3].killed_by==1)
{kills++;

//статистика
ubijstva[N_KILLS].player=1;
ubijstva[N_KILLS].vrag=1;
ubijstva[N_KILLS].weapon=N_WEAPON1;
ubijstva[N_KILLS].bezuh=false;
if(vragi1Objects[i3].bezuh==1)
{ubijstva[N_KILLS].bezuh=true;}
ubijstva[N_KILLS].bezboshki=false;
if(vragi1Objects[i3].bezboshki==1)
{ubijstva[N_KILLS].bezboshki=true;}
ubijstva[N_KILLS].headshot=false;
ubijstva[N_KILLS].vschiii=true;
N_KILLS++;
if(N_KILLS>=MAX_KILLS-1)
{N_KILLS=0;}
//статистика

points1+=150;
opit1+=(75+vragi1Objects[i3].defence*vragi1Objects[i3].defence/LVL1)*w_opit_zayac_vschiii[N_WEAPON1]*(1+0.25f*umnik1)/daun1;


}//закрытие для 1 игрока

if(vragi1Objects[i3].killed_by==2)
{kills2++;

//статистика
ubijstva[N_KILLS].player=2;
ubijstva[N_KILLS].vrag=1;
ubijstva[N_KILLS].weapon=N_WEAPON2;
ubijstva[N_KILLS].bezuh=false;
if(vragi1Objects[i3].bezuh==1)
{ubijstva[N_KILLS].bezuh=true;}
ubijstva[N_KILLS].bezboshki=false;
if(vragi1Objects[i3].bezboshki==1)
{ubijstva[N_KILLS].bezboshki=true;}
ubijstva[N_KILLS].headshot=false;
ubijstva[N_KILLS].vschiii=true;
N_KILLS++;
if(N_KILLS>=MAX_KILLS-1)
{N_KILLS=0;}
//статистика

points2+=150;
opit2+=(75+vragi1Objects[i3].defence*vragi1Objects[i3].defence/LVL2)*w_opit_zayac_vschiii[N_WEAPON2]*(1+0.25f*umnik2)/daun2;

}//закрытие про второго игрока






//БОНУС?!
bonus_shans();
if(vragi1Objects[i3].killed_by==1)
{
if(bonus>=371&&bonus<=379+5*luck1)
{
bonusiObjects[N_BONUS].x1=vragi1Objects[i3].v1x+5;
bonusiObjects[N_BONUS].y1=vragi1Objects[i3].v1y+5;
bonusiObjects[N_BONUS].x1_s=vragi1Objects[i3].v1x+5;
bonusiObjects[N_BONUS].x1_X=X;
bonusiObjects[N_BONUS].x2=vragi1Objects[i3].v1x+35;
bonusiObjects[N_BONUS].y2=vragi1Objects[i3].v1y+35;
bonusiObjects[N_BONUS].x2_s=vragi1Objects[i3].v1x+35;
bonusiObjects[N_BONUS].x2_X=X;
bonusiObjects[N_BONUS].appear_time_milli=GetTime();
bonusiObjects[N_BONUS].appear_time=perez_akt;
bonusiObjects[N_BONUS].type=hge->Random_Int(0,1);
bonusiObjects[N_BONUS].akt=1;
bonusiObjects[N_BONUS].spin=0;
bonusiObjects[N_BONUS].visible=true;
bonusiObjects[N_BONUS].mig_akt=0;

N_BONUS++;
if(N_BONUS>=MAX_BONUS-1)
{N_BONUS=0;}

}

}//if(vragi1Objects[i3].killed_by==1)

if(vragi1Objects[i3].killed_by==2)
{
if(bonus>=371&&bonus<=379+5*luck2)
{
bonusiObjects[N_BONUS].x1=vragi1Objects[i3].v1x+5;
bonusiObjects[N_BONUS].y1=vragi1Objects[i3].v1y+5;
bonusiObjects[N_BONUS].x1_s=vragi1Objects[i3].v1x+5;
bonusiObjects[N_BONUS].x1_X=X;
bonusiObjects[N_BONUS].x2=vragi1Objects[i3].v1x+35;
bonusiObjects[N_BONUS].y2=vragi1Objects[i3].v1y+35;
bonusiObjects[N_BONUS].x2_s=vragi1Objects[i3].v1x+35;
bonusiObjects[N_BONUS].x2_X=X;
bonusiObjects[N_BONUS].appear_time_milli=GetTime();
bonusiObjects[N_BONUS].appear_time=perez_akt;
bonusiObjects[N_BONUS].type=hge->Random_Int(0,1);
bonusiObjects[N_BONUS].akt=1;
bonusiObjects[N_BONUS].spin=0;
bonusiObjects[N_BONUS].visible=true;
bonusiObjects[N_BONUS].mig_akt=0;

N_BONUS++;
if(N_BONUS>=MAX_BONUS-1)
{N_BONUS=0;}

}

}//if(vragi1Objects[i3].killed_by==2)



//ВСПЛЕСК ДРИСНИ
krovyakObjects[N_BLOOD].seed=1001;
krovyakObjects[N_BLOOD].x1=vragi1Objects[i3].v1x+10;
krovyakObjects[N_BLOOD].x2=vragi1Objects[i3].v1x+10;
krovyakObjects[N_BLOOD].xstart=hge->Random_Float(1.2f,1.4f);
krovyakObjects[N_BLOOD].y1=vragi1Objects[i3].v1y+10;
krovyakObjects[N_BLOOD].y2=vragi1Objects[i3].v1y+10;
krovyakObjects[N_BLOOD].blood_time=GetTime();
krovyakObjects[N_BLOOD].blood_time_sec=perez_akt;
krovyakObjects[N_BLOOD].akt=1;
krovyakObjects[N_BLOOD].faza=1;
N_BLOOD++;
if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!



myasorazrivPan=-75+vragi1Objects[i3].v1x/9;
myasko_razriv();

int rebra_was=0;

//крупное мясо
for (int i60=1;i60<=10;i60++)
{
myasko[N_MYASO].seed=hge->Random_Int(1,5);
myasko[N_MYASO].x1=vragi1Objects[i3].v1x+hge->Random_Float(0,10);
myasko[N_MYASO].y1=vragi1Objects[i3].v1y+hge->Random_Float(-5,5);
myasko[N_MYASO].niz=vragi1Objects[i3].v1y+hge->Random_Float(15,50);
myasko[N_MYASO].xstart=myasko[N_MYASO].x1;
myasko[N_MYASO].type=1;
myasko[N_MYASO].myaso_time_sec=perez_akt;
myasko[N_MYASO].myaso_time=GetTime();
myasko[N_MYASO].scaleX=hge->Random_Float(0.4f,0.5f);
myasko[N_MYASO].gradus=hge->Random_Float(0,1);
myasko[N_MYASO].speedX=hge->Random_Float(0.5f,2);
myasko[N_MYASO].akt=1;
myasko[N_MYASO].bzdik=0;
myasko[N_MYASO].energy=0;

if(rebra_was==0)
{
int randomize=hge->Random_Int(1,10);
if(randomize==10)
{myasko[N_MYASO].seed=hge->Random_Int(7,8);
rebra_was=1;}
}

if(vragi1Objects[i3].vzorvan==true)
{myasko[N_MYASO].energy=vragi1Objects[i3].energy;
//передача энергии(выше) и её распределение
//если не прям под щами
if(myasko[N_MYASO].energy<=0.9f)
{
if(vragi1Objects[i3].chetvert==1)
{myasko[N_MYASO].speedX=hge->Random_Float(1,3)*myasko[N_MYASO].energy*(vragi1Objects[i3].rasstX/(vragi1Objects[i3].rasstX+vragi1Objects[i3].rasstY));
myasko[N_MYASO].speedY=-hge->Random_Float(1,3)*myasko[N_MYASO].energy*(vragi1Objects[i3].rasstY/(vragi1Objects[i3].rasstX+vragi1Objects[i3].rasstY));
myasko[N_MYASO].niz=vragi1Objects[i3].v1y+20*myasko[N_MYASO].speedY;}
if(vragi1Objects[i3].chetvert==2)
{myasko[N_MYASO].speedX=hge->Random_Float(1,3)*myasko[N_MYASO].energy*(vragi1Objects[i3].rasstX/(vragi1Objects[i3].rasstX+vragi1Objects[i3].rasstY));
myasko[N_MYASO].speedY=hge->Random_Float(1,3)*myasko[N_MYASO].energy*(vragi1Objects[i3].rasstY/(vragi1Objects[i3].rasstX+vragi1Objects[i3].rasstY));
myasko[N_MYASO].niz=vragi1Objects[i3].v1y-20*myasko[N_MYASO].speedY;}
if(vragi1Objects[i3].chetvert==3)
{myasko[N_MYASO].speedX=-1*hge->Random_Float(1,3)*myasko[N_MYASO].energy*(vragi1Objects[i3].rasstX/(vragi1Objects[i3].rasstX+vragi1Objects[i3].rasstY));
myasko[N_MYASO].speedY=hge->Random_Float(1,3)*myasko[N_MYASO].energy*(vragi1Objects[i3].rasstY/(vragi1Objects[i3].rasstX+vragi1Objects[i3].rasstY));
myasko[N_MYASO].niz=vragi1Objects[i3].v1y-20*myasko[N_MYASO].speedY;}
if(vragi1Objects[i3].chetvert==4)
{myasko[N_MYASO].speedX=-1*hge->Random_Float(1,3)*myasko[N_MYASO].energy*(vragi1Objects[i3].rasstX/(vragi1Objects[i3].rasstX+vragi1Objects[i3].rasstY));
myasko[N_MYASO].speedY=-hge->Random_Float(1,3)*myasko[N_MYASO].energy*(vragi1Objects[i3].rasstY/(vragi1Objects[i3].rasstX+vragi1Objects[i3].rasstY));
myasko[N_MYASO].niz=vragi1Objects[i3].v1y+20*myasko[N_MYASO].speedY;}
}//если не прям под щами

//если прям под щами
if(myasko[N_MYASO].energy>0.9f)
{
myasko[N_MYASO].speedY=-hge->Random_Float(5,8)*myasko[N_MYASO].energy;
myasko[N_MYASO].speedX=hge->Random_Float(-1,1)*myasko[N_MYASO].energy;
myasko[N_MYASO].niz=vragi1Objects[i3].v1y+hge->Random_Float(20,60)*myasko[N_MYASO].energy;

}//если прям под щами


}//закрытие взорванного мяса


N_MYASO++;
if(N_MYASO>=MAX_MYASO-1)
{N_MYASO=0;}

}
//крупное мясо

int head_was=0;
int noga_was=0;

//мелкое мясо
for (int i61=1;i61<=20;i61++)
{
myasko[N_MYASO].seed=hge->Random_Int(1,5);
myasko[N_MYASO].x1=vragi1Objects[i3].v1x+hge->Random_Float(-10,10);
myasko[N_MYASO].y1=vragi1Objects[i3].v1y+hge->Random_Float(-5,5);
myasko[N_MYASO].niz=vragi1Objects[i3].v1y+hge->Random_Float(10,50);
myasko[N_MYASO].xstart=myasko[N_MYASO].x1;
myasko[N_MYASO].type=2;
myasko[N_MYASO].myaso_time_sec=perez_akt;
myasko[N_MYASO].myaso_time=GetTime();
myasko[N_MYASO].scaleX=hge->Random_Float(0.3f,0.4f);
myasko[N_MYASO].gradus=hge->Random_Float(0,1);
myasko[N_MYASO].speedX=hge->Random_Float(2,3);
myasko[N_MYASO].speedY=hge->Random_Float(0.6f,1);
myasko[N_MYASO].akt=1;
myasko[N_MYASO].bzdik=0;
myasko[N_MYASO].energy=0;

if(head_was==0)
{
int randomize=hge->Random_Int(1,10);
if(randomize==10)
{myasko[N_MYASO].seed=6;
head_was=1;}
}
if(noga_was<2)
{
int randomize=hge->Random_Int(1,10);
if(randomize==10)
{myasko[N_MYASO].seed=hge->Random_Int(9,12);
noga_was++;}
}

if(vragi1Objects[i3].vzorvan==true)
{myasko[N_MYASO].energy=vragi1Objects[i3].energy;
//передача энергии(выше) и её распределение

//если не прям под щами
if(myasko[N_MYASO].energy<=0.9f)
{
if(vragi1Objects[i3].chetvert==1)
{myasko[N_MYASO].speedX=hge->Random_Float(1.5f,3)*myasko[N_MYASO].energy*(vragi1Objects[i3].rasstX/(vragi1Objects[i3].rasstX+vragi1Objects[i3].rasstY));
myasko[N_MYASO].speedY=-hge->Random_Float(1.5f,3)*myasko[N_MYASO].energy*(vragi1Objects[i3].rasstY/(vragi1Objects[i3].rasstX+vragi1Objects[i3].rasstY));
myasko[N_MYASO].niz=vragi1Objects[i3].v1y+5*myasko[N_MYASO].speedY;}
if(vragi1Objects[i3].chetvert==2)
{myasko[N_MYASO].speedX=hge->Random_Float(1.5f,3)*myasko[N_MYASO].energy*(vragi1Objects[i3].rasstX/(vragi1Objects[i3].rasstX+vragi1Objects[i3].rasstY));
myasko[N_MYASO].speedY=hge->Random_Float(1.5f,3)*myasko[N_MYASO].energy*(vragi1Objects[i3].rasstY/(vragi1Objects[i3].rasstX+vragi1Objects[i3].rasstY));
myasko[N_MYASO].niz=vragi1Objects[i3].v1y-5*myasko[N_MYASO].speedY;}
if(vragi1Objects[i3].chetvert==3)
{myasko[N_MYASO].speedX=-1*hge->Random_Float(1.5f,3)*myasko[N_MYASO].energy*(vragi1Objects[i3].rasstX/(vragi1Objects[i3].rasstX+vragi1Objects[i3].rasstY));
myasko[N_MYASO].speedY=hge->Random_Float(1.5f,3)*myasko[N_MYASO].energy*(vragi1Objects[i3].rasstY/(vragi1Objects[i3].rasstX+vragi1Objects[i3].rasstY));
myasko[N_MYASO].niz=vragi1Objects[i3].v1y-5*myasko[N_MYASO].speedY;}
if(vragi1Objects[i3].chetvert==4)
{myasko[N_MYASO].speedX=-1*hge->Random_Float(1.5f,3)*myasko[N_MYASO].energy*(vragi1Objects[i3].rasstX/(vragi1Objects[i3].rasstX+vragi1Objects[i3].rasstY));
myasko[N_MYASO].speedY=-hge->Random_Float(1.5f,3)*myasko[N_MYASO].energy*(vragi1Objects[i3].rasstY/(vragi1Objects[i3].rasstX+vragi1Objects[i3].rasstY));
myasko[N_MYASO].niz=vragi1Objects[i3].v1y+5*myasko[N_MYASO].speedY;}
}//если прям не под щами

//если прям под щами
if(myasko[N_MYASO].energy>0.9f)
{
myasko[N_MYASO].speedY=-hge->Random_Float(6,9)*myasko[N_MYASO].energy;
myasko[N_MYASO].speedX=hge->Random_Float(-2.5f,2.5f)*myasko[N_MYASO].energy;
myasko[N_MYASO].niz=vragi1Objects[i3].v1y+hge->Random_Float(-40,60)*myasko[N_MYASO].energy;

}//если прям под щами

}//закрытие взорванного мяса



N_MYASO++;
if(N_MYASO>=MAX_MYASO-1)
{N_MYASO=0;}

}
//мелкое мясо




}//закрытие разрыва в ЩИ



//холодное оружие
if((katana1_anime->IsPlaying()==true&&katana1_anime->GetFrame()==2&&vragi1Objects[i3].health>0&&x-55>vragi1Objects[i3].v1x&&
vragi1Objects[i3].v1x+40>x-95&&y<vragi1Objects[i3].v1y+40&&y>vragi1Objects[i3].v1y+12)||
(katana2_anime->IsPlaying()==true&&katana2_anime->GetFrame()==2&&vragi1Objects[i3].health>0&&x2-55>vragi1Objects[i3].v1x&&
vragi1Objects[i3].v1x+40>x2-95&&y2<vragi1Objects[i3].v1y+40&&y2>vragi1Objects[i3].v1y+12))
{

if(katana1_anime->IsPlaying()==true&&katana1_anime->GetFrame()==2&&vragi1Objects[i3].health>0&&x-55>vragi1Objects[i3].v1x&&
vragi1Objects[i3].v1x+40>x-95&&y<vragi1Objects[i3].v1y+40&&y>vragi1Objects[i3].v1y+12)
{vragi1Objects[i3].killed_by=1;}
if(katana2_anime->IsPlaying()==true&&katana2_anime->GetFrame()==2&&vragi1Objects[i3].health>0&&x2-55>vragi1Objects[i3].v1x&&
vragi1Objects[i3].v1x+40>x2-95&&y2<vragi1Objects[i3].v1y+40&&y2>vragi1Objects[i3].v1y+12)
{vragi1Objects[i3].killed_by=2;}


if((y<=vragi1Objects[i3].v1y+17&&y>vragi1Objects[i3].v1y+13)||
(y2<=vragi1Objects[i3].v1y+17&&y2>vragi1Objects[i3].v1y+13))//ХЭДШОТ!!!
{

if(vragi1Objects[i3].killed_by==1)	
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi1Objects[i3].defence>=5||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi1Objects[i3].defence>=5)
{

if(CLASSMOD==true&&class1==1)
{
if(LVL1%2==0)
{vragi1Objects[i3].health-=(damage[N_WEAPON1]+LVL1/2*attack1)*1.2f-vragi1Objects[i3].defence;}
if(LVL1%2==1)
{vragi1Objects[i3].health-=(damage[N_WEAPON1]+(LVL1-1)/2*attack1)*1.2f-vragi1Objects[i3].defence;}
}

if(CLASSMOD==false||class1!=1)
{
if(LVL1%2==0)
{vragi1Objects[i3].health-=damage[N_WEAPON1]+LVL1/2*attack1-vragi1Objects[i3].defence;}
if(LVL1%2==1)
{vragi1Objects[i3].health-=damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi1Objects[i3].defence;}
}

}
//гарантированный урон
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi1Objects[i3].defence<5||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi1Objects[i3].defence<5)
{vragi1Objects[i3].health-=5;}
}//RPG

if(RPGMOD==false)
{vragi1Objects[i3].health-=damage[N_WEAPON1];}
if(RPGMOD==false&&CLASSMOD==true&&class1==1)
{vragi1Objects[i3].health-=damage[N_WEAPON1]*1.2f;}

points1+=25;}//урон от оружия игрока 1


if(vragi1Objects[i3].killed_by==2)	
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi1Objects[i3].defence>=5||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi1Objects[i3].defence>=5)
{

if(CLASSMOD==true&&class2==1)
{
if(LVL2%2==0)
{vragi1Objects[i3].health-=(damage[N_WEAPON2]+LVL2/2*attack2)*1.2f-vragi1Objects[i3].defence;}
if(LVL2%2==1)
{vragi1Objects[i3].health-=(damage[N_WEAPON2]+(LVL2-1)/2*attack2)*1.2f-vragi1Objects[i3].defence;}
}

if(CLASSMOD==false||class2!=1)
{
if(LVL2%2==0)
{vragi1Objects[i3].health-=damage[N_WEAPON2]+LVL2/2*attack2-vragi1Objects[i3].defence;}
if(LVL2%2==1)
{vragi1Objects[i3].health-=damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi1Objects[i3].defence;}
}

}
//гарантированный урон
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi1Objects[i3].defence<5||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi1Objects[i3].defence<5)
{vragi1Objects[i3].health-=5;}
}//RPG

if(RPGMOD==false&&CLASSMOD==false)
{vragi1Objects[i3].health-=damage[N_WEAPON2];}
if(RPGMOD==false&&CLASSMOD==true&&class2==1)
{vragi1Objects[i3].health-=damage[N_WEAPON2]*1.2f;}

points2+=25;}//урон от оружия игрока 2


headshotPan=-75+vragi1Objects[i3].v1x/9;
headshot();

if(vragi1Objects[i3].bezboshki==0&&vragi1Objects[i3].health<=0)//отрывание бошки
{
vragi1Objects[i3].bezboshki=1;

if(vragi1Objects[i3].killed_by==1)
{points1+=25;}
if(vragi1Objects[i3].killed_by==2)
{points2+=25;}

if(vragi1Objects[i3].bezuh==0)
{boshkiObjects[N_HEAD].bezuh=0;}
if(vragi1Objects[i3].bezuh==1)
{boshkiObjects[N_HEAD].bezuh=1;}
boshkiObjects[N_HEAD].vrag=1;
boshkiObjects[N_HEAD].niz=vragi1Objects[i3].v1y+38;
boshkiObjects[N_HEAD].bx=vragi1Objects[i3].v1x+18;
boshkiObjects[N_HEAD].by=vragi1Objects[i3].v1y-3;
boshkiObjects[N_HEAD].bzdik=0;
boshkiObjects[N_HEAD].seed=hge->Random_Int(1,5);
boshkiObjects[N_HEAD].bzdik_seed=hge->Random_Int(1,3);
boshkiObjects[N_HEAD].akt=1;

N_HEAD++;

if(N_HEAD>=MAX_HEAD-1)
{N_HEAD=0;}

}//закрытие отрывания бошки


}//ХЭДШОТ ЗАКОНЧИЛСЯ



if(vragi1Objects[i3].killed_by==1)
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi1Objects[i3].defence>=10||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi1Objects[i3].defence>=10)
{

if(CLASSMOD==true&&class1==1)
{
if(LVL1%2==0)
{vragi1Objects[i3].health-=(damage[N_WEAPON1]+LVL1/2*attack1)*1.2f-vragi1Objects[i3].defence;}
if(LVL1%2==1)
{vragi1Objects[i3].health-=(damage[N_WEAPON1]+(LVL1-1)/2*attack1)*1.2f-vragi1Objects[i3].defence;}
}


if(CLASSMOD==false||class1!=1)
{
if(LVL1%2==0)
{vragi1Objects[i3].health-=damage[N_WEAPON1]+LVL1/2*attack1-vragi1Objects[i3].defence;}
if(LVL1%2==1)
{vragi1Objects[i3].health-=damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi1Objects[i3].defence;}
}


}
//гарантированный урон
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi1Objects[i3].defence<10||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi1Objects[i3].defence<10)
{vragi1Objects[i3].health-=10;}
}//RPG
if(RPGMOD==false)
{vragi1Objects[i3].health-=damage[N_WEAPON1];}

krovyakObjects[N_BLOOD].y1=y-10; //КРОВЯК (вперед)
krovyakObjects[N_BLOOD].y2=y;

}

if(vragi1Objects[i3].killed_by==2)
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi1Objects[i3].defence>=10||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi1Objects[i3].defence>=10)
{

if(CLASSMOD==true&&class2==1)
{
if(LVL2%2==0)
{vragi1Objects[i3].health-=(damage[N_WEAPON2]+LVL2/2*attack2)*1.2f-vragi1Objects[i3].defence;}
if(LVL2%2==1)
{vragi1Objects[i3].health-=(damage[N_WEAPON2]+(LVL2-1)/2*attack2)*1.2f-vragi1Objects[i3].defence;}
}

if(CLASSMOD==false&&class2!=1)
{
if(LVL2%2==0)
{vragi1Objects[i3].health-=damage[N_WEAPON2]+LVL2/2*attack2-vragi1Objects[i3].defence;}
if(LVL2%2==1)
{vragi1Objects[i3].health-=damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi1Objects[i3].defence;}
}

}
//гарантированный урон
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi1Objects[i3].defence<10||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi1Objects[i3].defence<10)
{vragi1Objects[i3].health-=10;}
}//RPG
if(RPGMOD==false)
{vragi1Objects[i3].health-=damage[N_WEAPON2];}

krovyakObjects[N_BLOOD].y1=y2-10; //КРОВЯК (вперед)
krovyakObjects[N_BLOOD].y2=y2;

}

krovyakObjects[N_BLOOD].seed=hge->Random_Int(101,103);
krovyakObjects[N_BLOOD].vrag=1;
krovyakObjects[N_BLOOD].x2=x-95+10;
krovyakObjects[N_BLOOD].x1=x-95+35;
krovyakObjects[N_BLOOD].xstart=x-95+10;
krovyakObjects[N_BLOOD].niz=vragi1Objects[i3].v1y+60;
krovyakObjects[N_BLOOD].blood_time=GetTime();
krovyakObjects[N_BLOOD].blood_time_sec=perez_akt;
krovyakObjects[N_BLOOD].akt=1;
krovyakObjects[N_BLOOD].faza=1;
N_BLOOD++;
if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!

hge->Effect_PlayEx(shot1,volume*8/10,0,0);



}//холодное оружие






if(vragi1Objects[i3].health<=0&&vragi1Objects[i3].pokoin==0)
{vragi1Objects[i3].kill_time=GetTime();
vragi1Objects[i3].kill_time_sec=perez_akt;
vragi1Objects[i3].pokoin=1;
}

if(vragi1Objects[i3].health<=0&&vragi1Objects[i3].pokoin==1&&vragi1Objects[i3].ubit==0)//убийство зайца
{
//pause
if((vragi1Objects[i3].kill_time<990&&
((perez_akt_milli>=vragi1Objects[i3].kill_time+10&&perez_akt==vragi1Objects[i3].kill_time_sec)||
(perez_akt!=vragi1Objects[i3].kill_time_sec)))
||(vragi1Objects[i3].kill_time>=990&&perez_akt!=vragi1Objects[i3].kill_time_sec))
{
zayac->Stop();
vragi1Objects[i3].ubit=1;
vragi1Objects[i3].timeout_milli=GetTime();
switch(DIFF)
{
case 0:
if(perez_akt<55)
{vragi1Objects[i3].timeout=perez_akt+5;}
if(perez_akt>=55)
{vragi1Objects[i3].timeout=perez_akt-55;}
break;
case 1:
if(perez_akt<56)
{vragi1Objects[i3].timeout=perez_akt+4;}
if(perez_akt>=56)
{vragi1Objects[i3].timeout=perez_akt-56;}
break;
case 2:
if(perez_akt<57)
{vragi1Objects[i3].timeout=perez_akt+3;}
if(perez_akt>=57)
{vragi1Objects[i3].timeout=perez_akt-57;}
break;
}

if(vragi1Objects[i3].killed_by==1)
{kills++;

//статистика
ubijstva[N_KILLS].player=1;
ubijstva[N_KILLS].vrag=1;
ubijstva[N_KILLS].weapon=N_WEAPON1;
ubijstva[N_KILLS].bezuh=false;
if(vragi1Objects[i3].bezuh==1)
{ubijstva[N_KILLS].bezuh=true;}
ubijstva[N_KILLS].bezboshki=false;
if(vragi1Objects[i3].bezboshki==1)
{ubijstva[N_KILLS].bezboshki=true;}
ubijstva[N_KILLS].headshot=false;
ubijstva[N_KILLS].vschiii=false;
N_KILLS++;
if(N_KILLS>=MAX_KILLS-1)
{N_KILLS=0;}
//статистика

points1+=100;
opit1+=(30+vragi1Objects[i3].defence*vragi1Objects[i3].defence/LVL1)*w_opit_zayac[N_WEAPON1]*(1+0.25f*umnik1)/daun1;


}//закрытие для 1 игрока

if(vragi1Objects[i3].killed_by==2)
{kills2++;

//статистика
ubijstva[N_KILLS].player=2;
ubijstva[N_KILLS].vrag=1;
ubijstva[N_KILLS].weapon=N_WEAPON2;
ubijstva[N_KILLS].bezuh=false;
if(vragi1Objects[i3].bezuh==1)
{ubijstva[N_KILLS].bezuh=true;}
ubijstva[N_KILLS].bezboshki=false;
if(vragi1Objects[i3].bezboshki==1)
{ubijstva[N_KILLS].bezboshki=true;}
ubijstva[N_KILLS].headshot=false;
ubijstva[N_KILLS].vschiii=false;
N_KILLS++;
if(N_KILLS>=MAX_KILLS-1)
{N_KILLS=0;}
//статистика

points2+=100;
opit2+=(30+vragi1Objects[i3].defence*vragi1Objects[i3].defence/LVL2)*w_opit_zayac[N_WEAPON2]*(1+0.25f*umnik2)/daun2;

}//закрытие про второго игрока




trupsObjects[N_TRUPS].killtime=GetTime();//лужа кровяка
trupsObjects[N_TRUPS].killtime_sec=perez_akt;
trupsObjects[N_TRUPS].posX=vragi1Objects[i3].v1x+24;
trupsObjects[N_TRUPS].posY=vragi1Objects[i3].v1y+32;
trupsObjects[N_TRUPS].posX_s=vragi1Objects[i3].v1x+24;
trupsObjects[N_TRUPS].posX_X=X;
trupsObjects[N_TRUPS].vrag=1;
trupsObjects[N_TRUPS].scaleX=0.1f;
trupsObjects[N_TRUPS].scaleY=0;
trupsObjects[N_TRUPS].aktiv=1;
trupsObjects[N_TRUPS].type=9;



N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}




if(vragi1Objects[i3].bezuh==1&&vragi1Objects[i3].bezboshki==0)//заец умирает с оторванными ушами
{trupsObjects[N_TRUPS].trup_tex=zayac_go_bezuh_tex;
trupsObjects[N_TRUPS].type=1;}//труп зайца

if(vragi1Objects[i3].bezuh==0&&vragi1Objects[i3].bezboshki==0)
{trupsObjects[N_TRUPS].type=1;//труп зайца
trupsObjects[N_TRUPS].trup_tex=zayac_go_tex;}


if(vragi1Objects[i3].bezboshki==1)//заец умирает без бошки
{trupsObjects[N_TRUPS].type=1;//труп зайца
trupsObjects[N_TRUPS].trup_tex=zayac_boshka_tex;}


trupsObjects[N_TRUPS].killtime=GetTime();
trupsObjects[N_TRUPS].killtime_sec=perez_akt;
trupsObjects[N_TRUPS].frame=1;
trupsObjects[N_TRUPS].frame_akt=1;
trupsObjects[N_TRUPS].posX=vragi1Objects[i3].v1x;
trupsObjects[N_TRUPS].posY=vragi1Objects[i3].v1y;
trupsObjects[N_TRUPS].posX_s=vragi1Objects[i3].v1x;
trupsObjects[N_TRUPS].posX_X=X;


N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}





//БОНУС?!
bonus_shans();
if(vragi1Objects[i3].killed_by==1)
{
if(bonus>=371&&bonus<=379+5*luck1)
{
bonusiObjects[N_BONUS].x1=vragi1Objects[i3].v1x+5;
bonusiObjects[N_BONUS].y1=vragi1Objects[i3].v1y+5;
bonusiObjects[N_BONUS].x1_s=vragi1Objects[i3].v1x+5;
bonusiObjects[N_BONUS].x1_X=X;
bonusiObjects[N_BONUS].x2=vragi1Objects[i3].v1x+35;
bonusiObjects[N_BONUS].y2=vragi1Objects[i3].v1y+35;
bonusiObjects[N_BONUS].x2_s=vragi1Objects[i3].v1x+35;
bonusiObjects[N_BONUS].x2_X=X;
bonusiObjects[N_BONUS].appear_time_milli=GetTime();
bonusiObjects[N_BONUS].appear_time=perez_akt;
bonusiObjects[N_BONUS].type=hge->Random_Int(0,1);
bonusiObjects[N_BONUS].akt=1;
bonusiObjects[N_BONUS].spin=0;
bonusiObjects[N_BONUS].visible=true;
bonusiObjects[N_BONUS].mig_akt=0;

N_BONUS++;
if(N_BONUS>=MAX_BONUS-1)
{N_BONUS=0;}

}

}//if(vragi1Objects[i3].killed_by==1)

if(vragi1Objects[i3].killed_by==2)
{
if(bonus>=371&&bonus<=379+5*luck2)
{
bonusiObjects[N_BONUS].x1=vragi1Objects[i3].v1x+5;
bonusiObjects[N_BONUS].y1=vragi1Objects[i3].v1y+5;
bonusiObjects[N_BONUS].x1_s=vragi1Objects[i3].v1x+5;
bonusiObjects[N_BONUS].x1_X=X;
bonusiObjects[N_BONUS].x2=vragi1Objects[i3].v1x+35;
bonusiObjects[N_BONUS].y2=vragi1Objects[i3].v1y+35;
bonusiObjects[N_BONUS].x2_s=vragi1Objects[i3].v1x+35;
bonusiObjects[N_BONUS].x2_X=X;
bonusiObjects[N_BONUS].appear_time_milli=GetTime();
bonusiObjects[N_BONUS].appear_time=perez_akt;
bonusiObjects[N_BONUS].type=hge->Random_Int(0,1);
bonusiObjects[N_BONUS].akt=1;
bonusiObjects[N_BONUS].spin=0;
bonusiObjects[N_BONUS].visible=true;
bonusiObjects[N_BONUS].mig_akt=0;

N_BONUS++;
if(N_BONUS>=MAX_BONUS-1)
{N_BONUS=0;}

}

}//if(vragi1Objects[i3].killed_by==2)

}//закрытие pause








}//закрытие убийства



}//ЗАКРЫТИЕ САГИ ПРО ЗАЙЦА



//ВОЛК
for (int i20=0;i20<=N_VOLK;i20++)
{

if(vragi2Objects[i20].ubit!=1)//сама скорость
{	
vragi2Objects[i20].v2x+=vragi2Objects[i20].speed*lag;
volk->Resume();


//агро мясника
if(class1==1&&primanka1>0&&vragi2Objects[i20].v2x+100<=x-16&&sqrt(((x-16)-vragi2Objects[i20].v2x+100)*((x-16)-vragi2Objects[i20].v2x+100)+
(vragi2Objects[i20].v2y+20-y)*(vragi2Objects[i20].v2y+20-y))<=(60+5*primanka1))
{
if(vragi2Objects[i20].v2y+20<y)
{vragi2Objects[i20].v2y+=(0.05f+0.1f*sqrt((float)primanka1))*lag;}
if(vragi2Objects[i20].v2y+20>y)
{vragi2Objects[i20].v2y-=(0.05f+0.1f*sqrt((float)primanka1))*lag;}
}

if(class2==1&&primanka2>0&&vragi2Objects[i20].v2x+100<=x2-16&&sqrt(((x2-16)-vragi2Objects[i20].v2x+100)*((x2-16)-vragi2Objects[i20].v2x+100)+
(vragi2Objects[i20].v2y+20-y2)*(vragi2Objects[i20].v2y+20-y2))<=(60+5*primanka2))
{
if(vragi2Objects[i20].v2y+20<y2)
{vragi2Objects[i20].v2y+=(0.05f+0.1f*sqrt((float)primanka2))*lag;}
if(vragi2Objects[i20].v2y+20>y2)
{vragi2Objects[i20].v2y-=(0.05f+0.1f*sqrt((float)primanka2))*lag;}
}





//ЛЕЧИЛКА
if(vragi2Objects[i20].RPG_healer!=0&&vragi2Objects[i20].health<125&&RPGMOD==true)
{vragi2Objects[i20].health+=vragi2Objects[i20].RPG_healer;
RPG_healing_psi->FireAt(vragi2Objects[i20].v2x+60,vragi2Objects[i20].v2y);}

//ИЛЛЮЗИИ
if(vragi2Objects[i20].RPG_illusionist!=0&&RPGMOD==true)
{
vragi2Objects[i20].ill1_x+=vragi2Objects[i20].speed*lag;
vragi2Objects[i20].ill2_x+=vragi2Objects[i20].speed*lag;

if((((py<vragi2Objects[i20].ill1_y+50&&py>vragi2Objects[i20].ill1_y&&px<=vragi2Objects[i20].ill1_x&&px>vragi2Objects[i20].ill1_x-600*lag)||
   (p1d1y<vragi2Objects[i20].ill1_y+50&&p1d1y>vragi2Objects[i20].ill1_y&&p1d1x<=vragi2Objects[i20].ill1_x&&p1d1x>vragi2Objects[i20].ill1_x-600*lag)||
   (p1d2y<vragi2Objects[i20].ill1_y+50&&p1d2y>vragi2Objects[i20].ill1_y&&p1d2x<=vragi2Objects[i20].ill1_x&&p1d2x>vragi2Objects[i20].ill1_x-600*lag)||
   (p1d3y<vragi2Objects[i20].ill1_y+50&&p1d3y>vragi2Objects[i20].ill1_y&&p1d3x<=vragi2Objects[i20].ill1_x&&p1d3x>vragi2Objects[i20].ill1_x-600*lag)||
   (p1d4y<vragi2Objects[i20].ill1_y+50&&p1d4y>vragi2Objects[i20].ill1_y&&p1d4x<=vragi2Objects[i20].ill1_x&&p1d4x>vragi2Objects[i20].ill1_x-600*lag))&&
  aktivatorp==1&&x-55>vragi2Objects[i20].ill1_x&&vragi2Objects[i20].ubit!=1)||
   (((p2y<vragi2Objects[i20].ill1_y+50&&p2y>vragi2Objects[i20].ill1_y&&p2x<=vragi2Objects[i20].ill1_x&&p2x>vragi2Objects[i20].ill1_x-600*lag)||
   (p2d1y<vragi2Objects[i20].ill1_y+50&&p2d1y>vragi2Objects[i20].ill1_y&&p2d1x<=vragi2Objects[i20].ill1_x&&p2d1x>vragi2Objects[i20].ill1_x-600*lag)||
   (p2d2y<vragi2Objects[i20].ill1_y+50&&p2d2y>vragi2Objects[i20].ill1_y&&p2d2x<=vragi2Objects[i20].ill1_x&&p2d2x>vragi2Objects[i20].ill1_x-600*lag)||
   (p2d3y<vragi2Objects[i20].ill1_y+50&&p2d3y>vragi2Objects[i20].ill1_y&&p2d3x<=vragi2Objects[i20].ill1_x&&p2d3x>vragi2Objects[i20].ill1_x-600*lag)||
   (p2d4y<vragi2Objects[i20].ill1_y+50&&p2d4y>vragi2Objects[i20].ill1_y&&p2d4x<=vragi2Objects[i20].ill1_x&&p2d4x>vragi2Objects[i20].ill1_x-600*lag))&&
  aktivatorp2==1&&x2-55>vragi2Objects[i20].ill1_x&&vragi2Objects[i20].ubit!=1))//просчёт урона
{vragi2Objects[i20].ill1_active=0;}

if((((py<vragi2Objects[i20].ill2_y+50&&py>vragi2Objects[i20].ill2_y&&px<=vragi2Objects[i20].ill2_x&&px>vragi2Objects[i20].ill2_x-600*lag)||
   (p1d1y<vragi2Objects[i20].ill2_y+50&&p1d1y>vragi2Objects[i20].ill2_y&&p1d1x<=vragi2Objects[i20].ill2_x&&p1d1x>vragi2Objects[i20].ill2_x-600*lag)||
   (p1d2y<vragi2Objects[i20].ill2_y+50&&p1d2y>vragi2Objects[i20].ill2_y&&p1d2x<=vragi2Objects[i20].ill2_x&&p1d2x>vragi2Objects[i20].ill2_x-600*lag)||
   (p1d3y<vragi2Objects[i20].ill2_y+50&&p1d3y>vragi2Objects[i20].ill2_y&&p1d3x<=vragi2Objects[i20].ill2_x&&p1d3x>vragi2Objects[i20].ill2_x-600*lag)||
   (p1d4y<vragi2Objects[i20].ill2_y+50&&p1d4y>vragi2Objects[i20].ill2_y&&p1d4x<=vragi2Objects[i20].ill2_x&&p1d4x>vragi2Objects[i20].ill2_x-600*lag))&&
  aktivatorp==1&&x-55>vragi2Objects[i20].ill2_x&&vragi2Objects[i20].ubit!=1)||
   (((p2y<vragi2Objects[i20].ill2_y+50&&p2y>vragi2Objects[i20].ill2_y&&p2x<=vragi2Objects[i20].ill2_x&&p2x>vragi2Objects[i20].ill2_x-600*lag)||
   (p2d1y<vragi2Objects[i20].ill2_y+50&&p2d1y>vragi2Objects[i20].ill2_y&&p2d1x<=vragi2Objects[i20].ill2_x&&p2d1x>vragi2Objects[i20].ill2_x-600*lag)||
   (p2d2y<vragi2Objects[i20].ill2_y+50&&p2d2y>vragi2Objects[i20].ill2_y&&p2d2x<=vragi2Objects[i20].ill2_x&&p2d2x>vragi2Objects[i20].ill2_x-600*lag)||
   (p2d3y<vragi2Objects[i20].ill2_y+50&&p2d3y>vragi2Objects[i20].ill2_y&&p2d3x<=vragi2Objects[i20].ill2_x&&p2d3x>vragi2Objects[i20].ill2_x-600*lag)||
   (p2d4y<vragi2Objects[i20].ill2_y+50&&p2d4y>vragi2Objects[i20].ill2_y&&p2d4x<=vragi2Objects[i20].ill2_x&&p2d4x>vragi2Objects[i20].ill2_x-600*lag))&&
  aktivatorp2==1&&x2-55>vragi2Objects[i20].ill2_x&&vragi2Objects[i20].ubit!=1))//просчёт урона
{vragi2Objects[i20].ill2_active=0;}

}

//ТЕЛЕПОРТАЦИЯ
if(vragi2Objects[i20].RPG_teleporter!=0&&RPGMOD==true)
{
if(vragi2Objects[i20].teleported==0&&vragi2Objects[i20].v2x>=vragi2Objects[i20].teleportx)
{
if(player2_aktive==0)
{if(DIFF!=0)
{vragi2Objects[i20].teleporty=hge->Random_Float(150,800);}
if(DIFF==0)
{vragi2Objects[i20].teleporty=hge->Random_Float(250,700);}}
if(player2_aktive==1)
{if(DIFF!=0)
{vragi2Objects[i20].teleporty=hge->Random_Float(100,850);}
if(DIFF==0)
{vragi2Objects[i20].teleporty=hge->Random_Float(200,750);}}


while((vragi2Objects[i20].teleporty>vragi2Objects[i20].v2y&&vragi2Objects[i20].teleporty-vragi2Objects[i20].v2y<150)||
	  (vragi2Objects[i20].v2y>vragi2Objects[i20].teleporty&&vragi2Objects[i20].v2y-vragi2Objects[i20].teleporty<150))
{
if(player2_aktive==0)
{if(DIFF!=0)
{vragi2Objects[i20].teleporty=hge->Random_Float(150,800);}
if(DIFF==0)
{vragi2Objects[i20].teleporty=hge->Random_Float(250,700);}}
if(player2_aktive==1)
{if(DIFF!=0)
{vragi2Objects[i20].teleporty=hge->Random_Float(100,850);}
if(DIFF==0)
{vragi2Objects[i20].teleporty=hge->Random_Float(200,750);}}
}
vragi2Objects[i20].v2y=vragi2Objects[i20].teleporty;
vragi2Objects[i20].teleported=1;
}
if(vragi2Objects[i20].teleported==1)
{
vragi2Objects[i20].teleportx=hge->Random_Float(vragi2Objects[i20].v2x+200,vragi2Objects[i20].v2x+400);
vragi2Objects[i20].teleported=0;
}

}



for (int i52=0;i52<=N_OBJECTS-1;i52++)//контакт с предметами
{
if((X-Objects[i52].x)>vragi2Objects[i20].v2x&&(X-Objects[i52].x)-vragi2Objects[i20].v2x<=200)//объект перед щами!!!
{

switch(Objects[i52].type)
{
case 0:
case 1:
case 2:
if(Objects[i52].y>=vragi2Objects[i20].v2y&&Objects[i52].y-vragi2Objects[i20].v2y<=50)//объект ниже
{
if(Objects[i52].pl==0)//если объект не плоский
{vragi2Objects[i20].v2y-=0.4f;}
vragi2Objects[i20].object_id=i52;}
if(Objects[i52].y<vragi2Objects[i20].v2y&&vragi2Objects[i20].v2y-Objects[i52].y<=35)//объект выше
{vragi2Objects[i20].v2y+=0.4f;}
break;

}

}//закрытие объект перед щами




if((X-Objects[i52].x)<vragi2Objects[i20].v2x&&vragi2Objects[i20].v2x-(X-Objects[i52].x)<=100)//назад на место
{
switch(Objects[i52].type)
{
case 0:
case 1:
case 2:
if(Objects[i52].y>=vragi2Objects[i20].v2y&&
Objects[i52].y-vragi2Objects[i20].v2y>=30&&Objects[i52].y-vragi2Objects[i20].v2y<=80)//объект ниже
{vragi2Objects[i20].v2y+=0.2f;}
if(Objects[i52].y<vragi2Objects[i20].v2y&&
vragi2Objects[i20].v2y-Objects[i52].y>=15&&vragi2Objects[i20].v2y-Objects[i52].y<=50)//объект выше
{vragi2Objects[i20].v2y-=0.2f;}
break;
}
}//закрытие возврата на место



}//закрытие контакта с предметами


}//закрытие скорости


 //если замочили - появляется заново
if(vragi2Objects[i20].ubit==1)
{
if(perez_akt==vragi2Objects[i20].timeout&&
((perez_akt_milli>=vragi2Objects[i20].timeout_milli&&vragi2Objects[i20].timeout_milli<900)||
(perez_akt_milli<vragi2Objects[i20].timeout_milli&&vragi2Objects[i20].timeout_milli>=900)))
{vragi2Objects[i20].ubit=0;	
vragi2Objects[i20].v2x=-50;
if(player2_aktive==0)
{if(DIFF!=0)
{vragi2Objects[i20].v2y=hge->Random_Float(200,800);}
if(DIFF==0)
{vragi2Objects[i20].v2y=hge->Random_Float(300,700);}}
if(player2_aktive==1)
{if(DIFF!=0)
{vragi2Objects[i20].v2y=hge->Random_Float(100,850);}
if(DIFF==0)
{vragi2Objects[i20].v2y=hge->Random_Float(200,750);}
}
vragi2Objects[i20].health=125;
vragi2Objects[i20].speed=hge->Random_Float(0.7f,0.9f);
vragi2Objects[i20].defence=defence_volk;
vragi2Objects[i20].object_id=-1;

vragi2Objects[i20].RPG_healer=0;
vragi2Objects[i20].RPG_illusionist=0;
vragi2Objects[i20].ill1_active=0;
vragi2Objects[i20].ill2_active=0;
vragi2Objects[i20].RPG_teleporter=0;
vragi2Objects[i20].teleportx=0;
vragi2Objects[i20].teleported=0;
//руны
if(RPGMOD==true)
{
int randomize= hge->Random_Int(1,100);

if(randomize<=25&&rpg_healers==true)
{vragi2Objects[i20].RPG_healer=1;}

if(randomize>25&&randomize<=35&&rpg_illusionists==true)
{vragi2Objects[i20].RPG_illusionist=1;
vragi2Objects[i20].ill1_active=1;
vragi2Objects[i20].ill1_x=vragi2Objects[i20].v2x+hge->Random_Int(-30,30);
if(player2_aktive==0)
{vragi2Objects[i20].ill1_y=hge->Random_Float(150,800);}
if(player2_aktive==1)
{vragi2Objects[i20].ill1_y=hge->Random_Float(100,850);}
vragi2Objects[i20].ill2_active=1;
vragi2Objects[i20].ill2_x=vragi2Objects[i20].v2x+hge->Random_Int(-30,30);
if(player2_aktive==0)
{vragi2Objects[i20].ill2_y=hge->Random_Float(150,800);}
if(player2_aktive==1)
{vragi2Objects[i20].ill2_y=hge->Random_Float(100,850);}
}

if(randomize>35&&randomize<=50&&rpg_teleporters==true)
{vragi2Objects[i20].RPG_teleporter=1;
vragi2Objects[i20].teleportx=hge->Random_Float(200,600);}
}//руны

}
}



if(vragi2Objects[i20].v2x>1200&&vragi2Objects[i20].ubit!=1) // если волк забежал за экран
{LIVES--;
vragi2Objects[i20].v2x=-50;
if(player2_aktive==0)
{if(DIFF!=0)
{vragi2Objects[i20].v2y=hge->Random_Float(200,800);}
if(DIFF==0)
{vragi2Objects[i20].v2y=hge->Random_Float(300,700);}}
if(player2_aktive==1)
{if(DIFF!=0)
{vragi2Objects[i20].v2y=hge->Random_Float(100,850);}
if(DIFF==0)
{vragi2Objects[i20].v2y=hge->Random_Float(200,750);}}
vragi2Objects[i20].health=125;
vragi2Objects[i20].speed=hge->Random_Float(0.7f,0.9f);
vragi2Objects[i20].defence=defence_volk;
vragi2Objects[i20].object_id=-1;

vragi2Objects[i20].RPG_healer=0;
vragi2Objects[i20].RPG_illusionist=0;
vragi2Objects[i20].ill1_active=0;
vragi2Objects[i20].ill2_active=0;
vragi2Objects[i20].RPG_teleporter=0;
vragi2Objects[i20].teleportx=0;
vragi2Objects[i20].teleported=0;
//руны
if(RPGMOD==true)
{
int randomize= hge->Random_Int(1,100);

if(randomize<=25&&rpg_healers==true)
{vragi2Objects[i20].RPG_healer=1;}

if(randomize>25&&randomize<=35&&rpg_illusionists==true)
{vragi2Objects[i20].RPG_illusionist=1;
vragi2Objects[i20].ill1_active=1;
vragi2Objects[i20].ill1_x=vragi2Objects[i20].v2x+hge->Random_Int(-30,30);
if(player2_aktive==0)
{vragi2Objects[i20].ill1_y=hge->Random_Float(150,800);}
if(player2_aktive==1)
{vragi2Objects[i20].ill1_y=hge->Random_Float(100,850);}
vragi2Objects[i20].ill2_active=1;
vragi2Objects[i20].ill2_x=vragi2Objects[i20].v2x+hge->Random_Int(-30,30);
if(player2_aktive==0)
{vragi2Objects[i20].ill2_y=hge->Random_Float(150,800);}
if(player2_aktive==1)
{vragi2Objects[i20].ill2_y=hge->Random_Float(100,850);}
}

if(randomize>35&&randomize<=50&&rpg_teleporters==true)
{vragi2Objects[i20].RPG_teleporter=1;
vragi2Objects[i20].teleportx=hge->Random_Float(200,500);}
}//руны

}


if((((py<vragi2Objects[i20].v2y+50&&py>vragi2Objects[i20].v2y&&px<=vragi2Objects[i20].v2x&&px>vragi2Objects[i20].v2x-600*lag)||
   (p1d1y<vragi2Objects[i20].v2y+50&&p1d1y>vragi2Objects[i20].v2y&&p1d1x<=vragi2Objects[i20].v2x&&p1d1x>vragi2Objects[i20].v2x-600*lag)||
   (p1d2y<vragi2Objects[i20].v2y+50&&p1d2y>vragi2Objects[i20].v2y&&p1d2x<=vragi2Objects[i20].v2x&&p1d2x>vragi2Objects[i20].v2x-600*lag)||
   (p1d3y<vragi2Objects[i20].v2y+50&&p1d3y>vragi2Objects[i20].v2y&&p1d3x<=vragi2Objects[i20].v2x&&p1d3x>vragi2Objects[i20].v2x-600*lag)||
   (p1d4y<vragi2Objects[i20].v2y+50&&p1d4y>vragi2Objects[i20].v2y&&p1d4x<=vragi2Objects[i20].v2x&&p1d4x>vragi2Objects[i20].v2x-600*lag))&&
  aktivatorp==1&&x-55>vragi2Objects[i20].v2x&&vragi2Objects[i20].ubit!=1)||
   (((p2y<vragi2Objects[i20].v2y+50&&p2y>vragi2Objects[i20].v2y&&p2x<=vragi2Objects[i20].v2x&&p2x>vragi2Objects[i20].v2x-600*lag)||
   (p2d1y<vragi2Objects[i20].v2y+50&&p2d1y>vragi2Objects[i20].v2y&&p2d1x<=vragi2Objects[i20].v2x&&p2d1x>vragi2Objects[i20].v2x-600*lag)||
   (p2d2y<vragi2Objects[i20].v2y+50&&p2d2y>vragi2Objects[i20].v2y&&p2d2x<=vragi2Objects[i20].v2x&&p2d2x>vragi2Objects[i20].v2x-600*lag)||
   (p2d3y<vragi2Objects[i20].v2y+50&&p2d3y>vragi2Objects[i20].v2y&&p2d3x<=vragi2Objects[i20].v2x&&p2d3x>vragi2Objects[i20].v2x-600*lag)||
   (p2d4y<vragi2Objects[i20].v2y+50&&p2d4y>vragi2Objects[i20].v2y&&p2d4x<=vragi2Objects[i20].v2x&&p2d4x>vragi2Objects[i20].v2x-600*lag))&&
  aktivatorp2==1&&x2-55>vragi2Objects[i20].v2x&&vragi2Objects[i20].ubit!=1))//просчёт урона
{


if(shot==0)
{
if(((py<vragi2Objects[i20].v2y+50&&py>vragi2Objects[i20].v2y&&px<=vragi2Objects[i20].v2x&&px>vragi2Objects[i20].v2x-600*lag)||
   (p1d1y<vragi2Objects[i20].v2y+50&&p1d1y>vragi2Objects[i20].v2y&&p1d1x<=vragi2Objects[i20].v2x&&p1d1x>vragi2Objects[i20].v2x-600*lag)||
   (p1d2y<vragi2Objects[i20].v2y+50&&p1d2y>vragi2Objects[i20].v2y&&p1d2x<=vragi2Objects[i20].v2x&&p1d2x>vragi2Objects[i20].v2x-600*lag)||
   (p1d3y<vragi2Objects[i20].v2y+50&&p1d3y>vragi2Objects[i20].v2y&&p1d3x<=vragi2Objects[i20].v2x&&p1d3x>vragi2Objects[i20].v2x-600*lag)||
   (p1d4y<vragi2Objects[i20].v2y+50&&p1d4y>vragi2Objects[i20].v2y&&p1d4x<=vragi2Objects[i20].v2x&&p1d4x>vragi2Objects[i20].v2x-600*lag))&&
  aktivatorp==1&&x-55>vragi2Objects[i20].v2x)	
{vragi2Objects[i20].killed_by=1;}//попал игрок 1
if(((p2y<vragi2Objects[i20].v2y+50&&p2y>vragi2Objects[i20].v2y&&p2x<=vragi2Objects[i20].v2x&&p2x>vragi2Objects[i20].v2x-600*lag)||
   (p2d1y<vragi2Objects[i20].v2y+50&&p2d1y>vragi2Objects[i20].v2y&&p2d1x<=vragi2Objects[i20].v2x&&p2d1x>vragi2Objects[i20].v2x-600*lag)||
   (p2d2y<vragi2Objects[i20].v2y+50&&p2d2y>vragi2Objects[i20].v2y&&p2d2x<=vragi2Objects[i20].v2x&&p2d2x>vragi2Objects[i20].v2x-600*lag)||
   (p2d3y<vragi2Objects[i20].v2y+50&&p2d3y>vragi2Objects[i20].v2y&&p2d3x<=vragi2Objects[i20].v2x&&p2d3x>vragi2Objects[i20].v2x-600*lag)||
   (p2d4y<vragi2Objects[i20].v2y+50&&p2d4y>vragi2Objects[i20].v2y&&p2d4x<=vragi2Objects[i20].v2x&&p2d4x>vragi2Objects[i20].v2x-600*lag))&&
  aktivatorp2==1&&x2-55>vragi2Objects[i20].v2x)
{vragi2Objects[i20].killed_by=2;}//попал игрок 2











if(((py<vragi2Objects[i20].v2y+50&&py>vragi2Objects[i20].v2y)||
   (p1d1y<vragi2Objects[i20].v2y+50&&p1d1y>vragi2Objects[i20].v2y)||
   (p1d2y<vragi2Objects[i20].v2y+50&&p1d2y>vragi2Objects[i20].v2y)||
   (p1d3y<vragi2Objects[i20].v2y+50&&p1d3y>vragi2Objects[i20].v2y)||
   (p1d4y<vragi2Objects[i20].v2y+50&&p1d4y>vragi2Objects[i20].v2y))||
   ((p2y<vragi2Objects[i20].v2y+50&&p2y>vragi2Objects[i20].v2y)||
   (p2d1y<vragi2Objects[i20].v2y+50&&p2d1y>vragi2Objects[i20].v2y)||
   (p2d2y<vragi2Objects[i20].v2y+50&&p2d2y>vragi2Objects[i20].v2y)||
   (p2d3y<vragi2Objects[i20].v2y+50&&p2d3y>vragi2Objects[i20].v2y)||
   (p2d4y<vragi2Objects[i20].v2y+50&&p2d4y>vragi2Objects[i20].v2y)))//ОБЫЧНОЕ ПОПАДАНИЕ	
{

if(vragi2Objects[i20].killed_by==1)	
{

if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi2Objects[i20].defence>=5||
   damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi2Objects[i20].defence>=5)
{
if(LVL1%2==0)
{vragi2Objects[i20].health-=damage[N_WEAPON1]+LVL1/2*attack1-vragi2Objects[i20].defence;}
if(LVL1%2==1)
{vragi2Objects[i20].health-=damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi2Objects[i20].defence;}
}

if(damage[N_WEAPON1]+LVL1/2*attack1-vragi2Objects[i20].defence<5||
 damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi2Objects[i20].defence<5)
{vragi2Objects[i20].health-=5;}
}//RPG

if(RPGMOD==false)
{vragi2Objects[i20].health-=damage[N_WEAPON1];}


}//урон от оружия игрока 1

if(vragi2Objects[i20].killed_by==2)
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi2Objects[i20].defence>=5||
   damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi2Objects[i20].defence>=5)
{
if(LVL2%2==0)
{vragi2Objects[i20].health-=damage[N_WEAPON2]+LVL2/2*attack2-vragi2Objects[i20].defence;}
if(LVL2%2==1)
{vragi2Objects[i20].health-=damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi2Objects[i20].defence;}
}

if(damage[N_WEAPON2]+LVL2/2*attack2-vragi2Objects[i20].defence<5||
   damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi2Objects[i20].defence<5)
{vragi2Objects[i20].health-=5;}
}//RPG

if(RPGMOD==false)
{vragi2Objects[i20].health-=damage[N_WEAPON2];}

}//урон от оружия игрока 2

hge->Effect_PlayEx(shot1,volume*8/10,0,0);
}//ЗАКРЫТИЕ ПОПАДАНИЯ

/*if(((py<=vragi1Objects[i3].v1y+18&&py>vragi1Objects[i3].v1y+12)||
   (p1d1y<=vragi1Objects[i3].v1y+18&&p1d1y>vragi1Objects[i3].v1y+12)||
   (p1d2y<=vragi1Objects[i3].v1y+18&&p1d2y>vragi1Objects[i3].v1y+12)||
   (p1d3y<=vragi1Objects[i3].v1y+18&&p1d3y>vragi1Objects[i3].v1y+12)||
   (p1d4y<=vragi1Objects[i3].v1y+18&&p1d4y>vragi1Objects[i3].v1y+12))||
   ((p2y<=vragi1Objects[i3].v1y+18&&p2y>vragi1Objects[i3].v1y+12)||
   (p2d1y<=vragi1Objects[i3].v1y+18&&p2d1y>vragi1Objects[i3].v1y+12)||
   (p2d2y<=vragi1Objects[i3].v1y+18&&p2d2y>vragi1Objects[i3].v1y+12)||
   (p2d3y<=vragi1Objects[i3].v1y+18&&p2d3y>vragi1Objects[i3].v1y+12)||
   (p2d4y<=vragi1Objects[i3].v1y+18&&p2d4y>vragi1Objects[i3].v1y+12)))//ХЭДШОТ!!!
{

if(vragi1Objects[i3].killed_by==1)	
{vragi1Objects[i3].health-=damage[N_WEAPON1]*2;
points1+=25;}//урон от оружия игрока 1

if(vragi1Objects[i3].killed_by==2)
{vragi1Objects[i3].health-=damage[N_WEAPON2]*2;
points2+=25;}//урон от оружия игрока 2

headshotPan=-75+vragi1Objects[i3].v1x/9;
headshot();

if(vragi1Objects[i3].health<-70)//отрывание бошки
{
vragi1Objects[i3].bezboshki=1;
if(vragi1Objects[i3].killed_by==1)
{points1+=25;}
if(vragi1Objects[i3].killed_by==2)
{points2+=25;}

if(vragi1Objects[i3].bezuh==0)
{boshkiObjects[N_HEAD].bezuh=0;}
if(vragi1Objects[i3].bezuh==1)
{boshkiObjects[N_HEAD].bezuh=1;}


boshkiObjects[N_HEAD].niz=vragi1Objects[i3].v1y+38;
boshkiObjects[N_HEAD].bx=vragi1Objects[i3].v1x+18;
boshkiObjects[N_HEAD].by=vragi1Objects[i3].v1y-3;
boshkiObjects[N_HEAD].bzdik=0;
boshkiObjects[N_HEAD].seed=hge->Random_Int(1,5);
boshkiObjects[N_HEAD].bzdik_seed=hge->Random_Int(1,3);
boshkiObjects[N_HEAD].akt=1;

N_HEAD++;

if(N_HEAD>=MAX_HEAD-1)
{N_HEAD=0;}

}//закрытие отрывания бошки


}//ХЭДШОТ ЗАКОНЧИЛСЯ
*/

if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!


krovyakObjects[N_BLOOD].seed=hge->Random_Int(1,3);
krovyakObjects[N_BLOOD].vrag=2;
if(vragi2Objects[i20].killed_by==1)	
{
if(py<vragi2Objects[i20].v2y+50&&py>vragi2Objects[i20].v2y&&px<=vragi2Objects[i20].v2x&&px>vragi2Objects[i20].v2x-150)	
{ppp=1;
krovyakObjects[N_BLOOD].y1=py; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=py+5;}
if(p1d1y<vragi2Objects[i20].v2y+50&&p1d1y>vragi2Objects[i20].v2y&&p1d1x<=vragi2Objects[i20].v2x&&p1d1x>vragi2Objects[i20].v2x-150)	
{ppp=2;
krovyakObjects[N_BLOOD].y1=p1d1y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p1d1y+5;}
if(p1d2y<vragi2Objects[i20].v2y+50&&p1d2y>vragi2Objects[i20].v2y&&p1d2x<=vragi2Objects[i20].v2x&&p1d2x>vragi2Objects[i20].v2x-150)	
{ppp=3;
krovyakObjects[N_BLOOD].y1=p1d2y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p1d2y+5;}
if(p1d3y<vragi2Objects[i20].v2y+50&&p1d3y>vragi2Objects[i20].v2y&&p1d3x<=vragi2Objects[i20].v2x&&p1d3x>vragi2Objects[i20].v2x-150)	
{ppp=4;
krovyakObjects[N_BLOOD].y1=p1d3y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p1d3y+5;}
if(p1d4y<vragi2Objects[i20].v2y+50&&p1d4y>vragi2Objects[i20].v2y&&p1d4x<=vragi2Objects[i20].v2x&&p1d4x>vragi2Objects[i20].v2x-150)	
{ppp=5;
krovyakObjects[N_BLOOD].y1=p1d4y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p1d4y+5;}
}
if(vragi2Objects[i20].killed_by==2)
{
if(p2y<vragi2Objects[i20].v2y+50&&p2y>vragi2Objects[i20].v2y&&p2x<=vragi2Objects[i20].v2x&&p2x>vragi2Objects[i20].v2x-150)
{ppp=1;
krovyakObjects[N_BLOOD].y1=p2y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p2y+5;}
if(p2d1y<vragi2Objects[i20].v2y+50&&p2d1y>vragi2Objects[i20].v2y&&p2d1x<=vragi2Objects[i20].v2x&&p2d1x>vragi2Objects[i20].v2x-150)
{ppp=2;
krovyakObjects[N_BLOOD].y1=p2d1y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p2d1y+5;}
if(p2d2y<vragi2Objects[i20].v2y+50&&p2d2y>vragi2Objects[i20].v2y&&p2d2x<=vragi2Objects[i20].v2x&&p2d2x>vragi2Objects[i20].v2x-150)
{ppp=3;
krovyakObjects[N_BLOOD].y1=p2d2y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p2d2y+5;}
if(p2d3y<vragi2Objects[i20].v2y+50&&p2d3y>vragi2Objects[i20].v2y&&p2d3x<=vragi2Objects[i20].v2x&&p2d3x>vragi2Objects[i20].v2x-150)
{ppp=4;
krovyakObjects[N_BLOOD].y1=p2d3y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p2d3y+5;}
if(p2d4y<vragi2Objects[i20].v2y+50&&p2d4y>vragi2Objects[i20].v2y&&p2d4x<=vragi2Objects[i20].v2x&&p2d4x>vragi2Objects[i20].v2x-150)
{ppp=5;
krovyakObjects[N_BLOOD].y1=p2d4y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p2d4y+5;}
}
krovyakObjects[N_BLOOD].x2=vragi2Objects[i20].v2x+30;
krovyakObjects[N_BLOOD].x1=vragi2Objects[i20].v2x+20;
krovyakObjects[N_BLOOD].xstart=vragi2Objects[i20].v2x;
krovyakObjects[N_BLOOD].niz=vragi2Objects[i20].v2y+50;
krovyakObjects[N_BLOOD].blood_time=GetTime();
krovyakObjects[N_BLOOD].blood_time_sec=perez_akt;
krovyakObjects[N_BLOOD].akt=1;
krovyakObjects[N_BLOOD].faza=1;


N_BLOOD++;

if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!


krovyakObjects[N_BLOOD].seed=0;//кровяк самого попадания (точка)
krovyakObjects[N_BLOOD].vrag=2;
if(vragi2Objects[i20].killed_by==1)
{
if(ppp==1)	
{krovyakObjects[N_BLOOD].y1=py-4;
krovyakObjects[N_BLOOD].y2=py+4;}
if(ppp==2)	
{krovyakObjects[N_BLOOD].y1=p1d1y-4;
krovyakObjects[N_BLOOD].y2=p1d1y+4;}
if(ppp==3)	
{krovyakObjects[N_BLOOD].y1=p1d2y-4;
krovyakObjects[N_BLOOD].y2=p1d2y+4;}
if(ppp==4)	
{krovyakObjects[N_BLOOD].y1=p1d3y-4;
krovyakObjects[N_BLOOD].y2=p1d3y+4;}
if(ppp==5)	
{krovyakObjects[N_BLOOD].y1=p1d4y-4;
krovyakObjects[N_BLOOD].y2=p1d4y+4;}
}

if(vragi2Objects[i20].killed_by==2)
{
if(ppp==1)	
{krovyakObjects[N_BLOOD].y1=p2y-4;
krovyakObjects[N_BLOOD].y2=p2y+4;}
if(ppp==2)	
{krovyakObjects[N_BLOOD].y1=p2d1y-4;
krovyakObjects[N_BLOOD].y2=p2d1y+4;}
if(ppp==3)	
{krovyakObjects[N_BLOOD].y1=p2d2y-4;
krovyakObjects[N_BLOOD].y2=p2d2y+4;}
if(ppp==4)	
{krovyakObjects[N_BLOOD].y1=p2d3y-4;
krovyakObjects[N_BLOOD].y2=p2d3y+4;}
if(ppp==5)	
{krovyakObjects[N_BLOOD].y1=p2d4y-4;
krovyakObjects[N_BLOOD].y2=p2d4y+4;}
}

krovyakObjects[N_BLOOD].x2=vragi2Objects[i20].v2x+126;
krovyakObjects[N_BLOOD].x1=vragi2Objects[i20].v2x+118;
krovyakObjects[N_BLOOD].blood_time=GetTime();
krovyakObjects[N_BLOOD].blood_time_sec=perez_akt;
krovyakObjects[N_BLOOD].akt=1;


N_BLOOD++;

if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!


krovyakObjects[N_BLOOD].seed=hge->Random_Int(101,103);
krovyakObjects[N_BLOOD].vrag=2;
if(vragi2Objects[i20].killed_by==1)	
{
if(ppp==1)
{krovyakObjects[N_BLOOD].y1=py; //КРОВЯК (вперед)
krovyakObjects[N_BLOOD].y2=py+5;}
if(ppp==2)	
{krovyakObjects[N_BLOOD].y1=p1d1y;
krovyakObjects[N_BLOOD].y2=p1d1y+5;}
if(ppp==3)	
{krovyakObjects[N_BLOOD].y1=p1d2y;
krovyakObjects[N_BLOOD].y2=p1d2y+5;}
if(ppp==4)	
{krovyakObjects[N_BLOOD].y1=p1d3y;
krovyakObjects[N_BLOOD].y2=p1d3y+5;}
if(ppp==5)	
{krovyakObjects[N_BLOOD].y1=p1d4y;
krovyakObjects[N_BLOOD].y2=p1d4y+5;}
}

if(vragi2Objects[i20].killed_by==2)
{
if(ppp==1)	
{krovyakObjects[N_BLOOD].y1=p2y;
krovyakObjects[N_BLOOD].y2=p2y+5;}
if(ppp==2)	
{krovyakObjects[N_BLOOD].y1=p2d1y;
krovyakObjects[N_BLOOD].y2=p2d1y+5;}
if(ppp==3)
{krovyakObjects[N_BLOOD].y1=p2d2y;
krovyakObjects[N_BLOOD].y2=p2d2y+5;}
if(ppp==4)	
{krovyakObjects[N_BLOOD].y1=p2d3y;
krovyakObjects[N_BLOOD].y2=p2d3y+5;}
if(ppp==5)	
{krovyakObjects[N_BLOOD].y1=p2d4y;
krovyakObjects[N_BLOOD].y2=p2d4y+5;}
}

krovyakObjects[N_BLOOD].x2=vragi2Objects[i20].v2x+120;
krovyakObjects[N_BLOOD].x1=vragi2Objects[i20].v2x+125;
krovyakObjects[N_BLOOD].xstart=vragi2Objects[i20].v2x+120;
krovyakObjects[N_BLOOD].niz=vragi2Objects[i20].v2y+50;
krovyakObjects[N_BLOOD].blood_time=GetTime();
krovyakObjects[N_BLOOD].blood_time_sec=perez_akt;
krovyakObjects[N_BLOOD].akt=1;
krovyakObjects[N_BLOOD].faza=1;


N_BLOOD++;

if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!






shot=1;


if(vragi2Objects[i20].killed_by==1)
{
if(N_WEAPON1==1||N_WEAPON1==2||N_WEAPON1==4||N_WEAPON1==6||N_WEAPON1==9||N_WEAPON1==14||N_WEAPON1==15)//если это ПМ или ПП19 или ТТ или МАС или Glock то патрон слабый
{aktivatorp=0;
oboima-=1;}


if(N_WEAPON1==7)
{

if(ppp==2)
{p1d1y=y-9;
p1d1x=x-24;}
if(ppp==3)
{p1d2y=y-9;
p1d2x=x-24;}
if(ppp==4)
{p1d3y=y-9;
p1d3x=x-24;}
if(ppp==5)
{p1d4y=y-9;
p1d4x=x-24;}
}


if(N_WEAPON1==0||N_WEAPON1==3||N_WEAPON1==5||N_WEAPON1==8)// если это АК то косит всех подряд
{shot=0;}

}

if(vragi2Objects[i20].killed_by==2)
{
if(N_WEAPON2==1||N_WEAPON2==2||N_WEAPON2==4||N_WEAPON2==6||N_WEAPON2==9||N_WEAPON2==14||N_WEAPON2==15)//если это ПМ или ПП19 или ТТ или МАС или Glock то патрон слабый
{aktivatorp2=0;
oboima2-=1;}

if(N_WEAPON2==7)
{
if(ppp==2)
{p2d1y=y2-9;
p2d1x=x2-24;}
if(ppp==3)
{p2d2y=y2-9;
p2d2x=x2-24;}
if(ppp==4)
{p2d3y=y2-9;
p2d3x=x2-24;}
if(ppp==5)
{p2d4y=y2-9;
p2d4x=x2-24;}
}


if(N_WEAPON2==0||N_WEAPON2==3||N_WEAPON2==5||N_WEAPON2==8)// если это АК то косит всех подряд
{shot=0;}

}




}//if shot==0





}//закрытие просчёта урона волку

//холодное оружие
if((katana1_anime->IsPlaying()==true&&katana1_anime->GetFrame()==2&&vragi2Objects[i20].health>0&&x-55>vragi2Objects[i20].v2x+10&&
vragi2Objects[i20].v2x+120>x-95&&y<vragi2Objects[i20].v2y+40&&y>vragi2Objects[i20].v2y+12)||
(katana2_anime->IsPlaying()==true&&katana2_anime->GetFrame()==2&&vragi2Objects[i20].health>0&&x2-55>vragi2Objects[i20].v2x+10&&
vragi2Objects[i20].v2x+120>x2-95&&y2<vragi2Objects[i20].v2y+40&&y2>vragi2Objects[i20].v2y+12))
{

if(katana1_anime->IsPlaying()==true&&katana1_anime->GetFrame()==2&&vragi2Objects[i20].health>0&&x-55>vragi2Objects[i20].v2x+10&&
vragi2Objects[i20].v2x+120>x-95&&y<vragi2Objects[i20].v2y+40&&y>vragi2Objects[i20].v2y+12)
{vragi2Objects[i20].killed_by=1;}
if(katana2_anime->IsPlaying()==true&&katana2_anime->GetFrame()==2&&vragi2Objects[i20].health>0&&x2-55>vragi2Objects[i20].v2x+10&&
vragi2Objects[i20].v2x+120>x2-95&&y2<vragi2Objects[i20].v2y+40&&y2>vragi2Objects[i20].v2y+12)
{vragi2Objects[i20].killed_by=2;}


if((y<=vragi2Objects[i20].v2y+17&&y>vragi2Objects[i20].v2y+3)||
(y2<=vragi2Objects[i20].v2y+17&&y2>vragi2Objects[i20].v2y+3))//ХЭДШОТ!!!
{

if(vragi2Objects[i20].killed_by==1)	
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi2Objects[i20].defence>=5||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi2Objects[i20].defence>=5)
{

if(CLASSMOD==true&&class1==1)
{
if(LVL1%2==0)
{vragi2Objects[i20].health-=(damage[N_WEAPON1]+LVL1/2*attack1)*1.2f-vragi2Objects[i20].defence;}
if(LVL1%2==1)
{vragi2Objects[i20].health-=(damage[N_WEAPON1]+(LVL1-1)/2*attack1)*1.2f-vragi2Objects[i20].defence;}
}

if(CLASSMOD==false||class1!=1)
{
if(LVL1%2==0)
{vragi2Objects[i20].health-=damage[N_WEAPON1]+LVL1/2*attack1-vragi2Objects[i20].defence;}
if(LVL1%2==1)
{vragi2Objects[i20].health-=damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi2Objects[i20].defence;}
}

}
//гарантированный урон
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi2Objects[i20].defence<5||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi2Objects[i20].defence<5)
{vragi2Objects[i20].health-=5;}
}//RPG

if(RPGMOD==false)
{vragi2Objects[i20].health-=damage[N_WEAPON1];}
if(RPGMOD==false&&CLASSMOD==true&&class1==1)
{vragi2Objects[i20].health-=damage[N_WEAPON1]*1.2f;}

points1+=25;}//урон от оружия игрока 1


if(vragi2Objects[i20].killed_by==2)	
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi2Objects[i20].defence>=5||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi2Objects[i20].defence>=5)
{

if(CLASSMOD==true&&class2==1)
{
if(LVL2%2==0)
{vragi2Objects[i20].health-=(damage[N_WEAPON2]+LVL2/2*attack2)*1.2f-vragi2Objects[i20].defence;}
if(LVL2%2==1)
{vragi2Objects[i20].health-=(damage[N_WEAPON2]+(LVL2-1)/2*attack2)*1.2f-vragi2Objects[i20].defence;}
}

if(CLASSMOD==false||class2!=1)
{
if(LVL2%2==0)
{vragi2Objects[i20].health-=damage[N_WEAPON2]+LVL2/2*attack2-vragi2Objects[i20].defence;}
if(LVL2%2==1)
{vragi2Objects[i20].health-=damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi2Objects[i20].defence;}
}

}
//гарантированный урон
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi2Objects[i20].defence<5||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi2Objects[i20].defence<5)
{vragi2Objects[i20].health-=5;}
}//RPG

if(RPGMOD==false&&CLASSMOD==false)
{vragi2Objects[i20].health-=damage[N_WEAPON2];}
if(RPGMOD==false&&CLASSMOD==true&&class2==1)
{vragi2Objects[i20].health-=damage[N_WEAPON2]*1.2f;}

points2+=25;}//урон от оружия игрока 2


headshotPan=-75+(vragi2Objects[i20].v2x+120)/9;
headshot();




}//ХЭДШОТ ЗАКОНЧИЛСЯ



if(vragi2Objects[i20].killed_by==1)
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi2Objects[i20].defence>=10||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi2Objects[i20].defence>=10)
{

if(CLASSMOD==true&&class1==1)
{
if(LVL1%2==0)
{vragi2Objects[i20].health-=(damage[N_WEAPON1]+LVL1/2*attack1)*1.2f-vragi2Objects[i20].defence;}
if(LVL1%2==1)
{vragi2Objects[i20].health-=(damage[N_WEAPON1]+(LVL1-1)/2*attack1)*1.2f-vragi2Objects[i20].defence;}
}


if(CLASSMOD==false||class1!=1)
{
if(LVL1%2==0)
{vragi2Objects[i20].health-=damage[N_WEAPON1]+LVL1/2*attack1-vragi2Objects[i20].defence;}
if(LVL1%2==1)
{vragi2Objects[i20].health-=damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi2Objects[i20].defence;}
}


}
//гарантированный урон
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi2Objects[i20].defence<10||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi2Objects[i20].defence<10)
{vragi2Objects[i20].health-=10;}
}//RPG
if(RPGMOD==false)
{vragi2Objects[i20].health-=damage[N_WEAPON1];}

krovyakObjects[N_BLOOD].y1=y-10; //КРОВЯК (вперед)
krovyakObjects[N_BLOOD].y2=y;

}

if(vragi2Objects[i20].killed_by==2)
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi2Objects[i20].defence>=10||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi2Objects[i20].defence>=10)
{

if(CLASSMOD==true&&class2==1)
{
if(LVL2%2==0)
{vragi2Objects[i20].health-=(damage[N_WEAPON2]+LVL2/2*attack2)*1.2f-vragi2Objects[i20].defence;}
if(LVL2%2==1)
{vragi2Objects[i20].health-=(damage[N_WEAPON2]+(LVL2-1)/2*attack2)*1.2f-vragi2Objects[i20].defence;}
}

if(CLASSMOD==false&&class2!=1)
{
if(LVL2%2==0)
{vragi2Objects[i20].health-=damage[N_WEAPON2]+LVL2/2*attack2-vragi2Objects[i20].defence;}
if(LVL2%2==1)
{vragi2Objects[i20].health-=damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi2Objects[i20].defence;}
}

}
//гарантированный урон
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi2Objects[i20].defence<10||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi2Objects[i20].defence<10)
{vragi2Objects[i20].health-=10;}
}//RPG
if(RPGMOD==false)
{vragi2Objects[i20].health-=damage[N_WEAPON2];}

krovyakObjects[N_BLOOD].y1=y2-10; //КРОВЯК (вперед)
krovyakObjects[N_BLOOD].y2=y2;

}

krovyakObjects[N_BLOOD].seed=hge->Random_Int(101,103);
krovyakObjects[N_BLOOD].vrag=2;
krovyakObjects[N_BLOOD].x2=x-95+10;
krovyakObjects[N_BLOOD].x1=x-95+35;
krovyakObjects[N_BLOOD].xstart=x-95+10;
krovyakObjects[N_BLOOD].niz=vragi2Objects[i20].v2y+60;
krovyakObjects[N_BLOOD].blood_time=GetTime();
krovyakObjects[N_BLOOD].blood_time_sec=perez_akt;
krovyakObjects[N_BLOOD].akt=1;
krovyakObjects[N_BLOOD].faza=1;
N_BLOOD++;
if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!

hge->Effect_PlayEx(shot1,volume*8/10,0,0);



}//холодное оружие




if(vragi2Objects[i20].health<=0&&vragi2Objects[i20].ubit==0)//убийство волка
{
volk->Stop();
vragi2Objects[i20].ubit=1;
vragi2Objects[i20].timeout_milli=GetTime();
switch(DIFF)
{
case 0:
if(perez_akt<49)
{vragi2Objects[i20].timeout=perez_akt+11;}
if(perez_akt>=49)
{vragi2Objects[i20].timeout=perez_akt-49;}
break;
case 1:
if(perez_akt<51)
{vragi2Objects[i20].timeout=perez_akt+9;}
if(perez_akt>=51)
{vragi2Objects[i20].timeout=perez_akt-51;}
break;
case 2:
if(perez_akt<52)
{vragi2Objects[i20].timeout=perez_akt+8;}
if(perez_akt>=52)
{vragi2Objects[i20].timeout=perez_akt-52;}
break;
}
if(vragi2Objects[i20].killed_by==1)
{kills++;

//статистика
ubijstva[N_KILLS].player=1;
ubijstva[N_KILLS].vrag=2;
ubijstva[N_KILLS].weapon=N_WEAPON1;
ubijstva[N_KILLS].bezuh=false;
ubijstva[N_KILLS].bezboshki=false;
ubijstva[N_KILLS].headshot=false;
ubijstva[N_KILLS].vschiii=false;
N_KILLS++;
if(N_KILLS>=MAX_KILLS-1)
{N_KILLS=0;}
//статистика

points1+=200;
opit1+=(70+vragi2Objects[i20].defence*vragi2Objects[i20].defence/LVL1)*w_opit_volk[N_WEAPON1]*(1+0.25f*umnik1)/daun1;

}

if(vragi2Objects[i20].killed_by==2)
{kills2++;

//статистика
ubijstva[N_KILLS].player=2;
ubijstva[N_KILLS].vrag=2;
ubijstva[N_KILLS].weapon=N_WEAPON2;
ubijstva[N_KILLS].bezuh=false;
ubijstva[N_KILLS].bezboshki=false;
ubijstva[N_KILLS].headshot=false;
ubijstva[N_KILLS].vschiii=false;
N_KILLS++;
if(N_KILLS>=MAX_KILLS-1)
{N_KILLS=0;}
//статистика

points2+=200;
opit2+=(70+vragi2Objects[i20].defence*vragi2Objects[i20].defence/LVL2)*w_opit_volk[N_WEAPON2]*(1+0.25f*umnik2)/daun2;
}


trupsObjects[N_TRUPS].killtime=GetTime();//лужа кровяка
trupsObjects[N_TRUPS].killtime_sec=perez_akt;
trupsObjects[N_TRUPS].posX=vragi2Objects[i20].v2x+60;
trupsObjects[N_TRUPS].posY=vragi2Objects[i20].v2y+42;
trupsObjects[N_TRUPS].posX_s=vragi2Objects[i20].v2x+60;
trupsObjects[N_TRUPS].posX_X=X;
trupsObjects[N_TRUPS].vrag=2;
trupsObjects[N_TRUPS].scaleX=0.1f;
trupsObjects[N_TRUPS].scaleY=0;
trupsObjects[N_TRUPS].aktiv=1;
trupsObjects[N_TRUPS].type=9;




N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}


//БОНУС?!
bonus_shans();

if(vragi2Objects[i20].killed_by==1)
{
if(bonus>=371&&bonus<=379+5*luck1)
{
bonusiObjects[N_BONUS].x1=vragi2Objects[i20].v2x+5;
bonusiObjects[N_BONUS].y1=vragi2Objects[i20].v2y+5;
bonusiObjects[N_BONUS].x1_s=vragi2Objects[i20].v2x+5;
bonusiObjects[N_BONUS].x1_X=X;
bonusiObjects[N_BONUS].x2=vragi2Objects[i20].v2x+35;
bonusiObjects[N_BONUS].y2=vragi2Objects[i20].v2y+35;
bonusiObjects[N_BONUS].x2_s=vragi2Objects[i20].v2x+35;
bonusiObjects[N_BONUS].x2_X=X;
bonusiObjects[N_BONUS].appear_time_milli=GetTime();
bonusiObjects[N_BONUS].appear_time=perez_akt;
bonusiObjects[N_BONUS].type=0;
bonusiObjects[N_BONUS].akt=1;
bonusiObjects[N_BONUS].spin=0;
bonusiObjects[N_BONUS].visible=true;
bonusiObjects[N_BONUS].mig_akt=0;

N_BONUS++;
if(N_BONUS>=MAX_BONUS-1)
{N_BONUS=0;}

}
}//if(vragi2Objects[i20].killed_by==1)

if(vragi2Objects[i20].killed_by==2)
{
if(bonus>=371&&bonus<=379+5*luck2)
{
bonusiObjects[N_BONUS].x1=vragi2Objects[i20].v2x+5;
bonusiObjects[N_BONUS].y1=vragi2Objects[i20].v2y+5;
bonusiObjects[N_BONUS].x1_s=vragi2Objects[i20].v2x+5;
bonusiObjects[N_BONUS].x1_X=X;
bonusiObjects[N_BONUS].x2=vragi2Objects[i20].v2x+35;
bonusiObjects[N_BONUS].y2=vragi2Objects[i20].v2y+35;
bonusiObjects[N_BONUS].x2_s=vragi2Objects[i20].v2x+35;
bonusiObjects[N_BONUS].x2_X=X;
bonusiObjects[N_BONUS].appear_time_milli=GetTime();
bonusiObjects[N_BONUS].appear_time=perez_akt;
bonusiObjects[N_BONUS].type=0;
bonusiObjects[N_BONUS].akt=1;
bonusiObjects[N_BONUS].spin=0;
bonusiObjects[N_BONUS].visible=true;
bonusiObjects[N_BONUS].mig_akt=0;

N_BONUS++;
if(N_BONUS>=MAX_BONUS-1)
{N_BONUS=0;}

}
}//if(vragi2Objects[i20].killed_by==2)


trupsObjects[N_TRUPS].type=10;
trupsObjects[N_TRUPS].killtime=GetTime();
trupsObjects[N_TRUPS].killtime_sec=perez_akt;
trupsObjects[N_TRUPS].frame=1;
trupsObjects[N_TRUPS].frame_akt=1;
trupsObjects[N_TRUPS].posX=vragi2Objects[i20].v2x;
trupsObjects[N_TRUPS].posY=vragi2Objects[i20].v2y;
trupsObjects[N_TRUPS].posX_s=vragi2Objects[i20].v2x;
trupsObjects[N_TRUPS].posX_X=X;


N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}




}//закрытие убийства волка

}//ЗАКРЫТИЕ САГИ ПРО ВОЛКА






//МЕДВЕДЬ

for (int i80=0;i80<=N_MEDVED;i80++)
{

if(vragi3Objects[i80].ubit!=1)//сама скорость
{
vragi3Objects[i80].v3x+=vragi3Objects[i80].speed*lag;
medved->Resume();

//агро мясника
if(class1==1&&primanka1>0&&vragi3Objects[i80].v3x+180<=x-16&&sqrt(((x-16)-vragi3Objects[i80].v3x+180)*((x-16)-vragi3Objects[i80].v3x+180)+
(vragi3Objects[i80].v3y+200-y)*(vragi3Objects[i80].v3y+200-y))<=(60+5*primanka1))
{
if(vragi3Objects[i80].v3y+200<y)
{vragi3Objects[i80].v3y+=(0.05f+0.1f*sqrt((float)primanka1))*lag;}
if(vragi3Objects[i80].v3y+200>y)
{vragi3Objects[i80].v3y-=(0.05f+0.1f*sqrt((float)primanka1))*lag;}
}

if(class2==1&&primanka2>0&&vragi3Objects[i80].v3x+180<=x2-16&&sqrt(((x2-16)-vragi3Objects[i80].v3x+180)*((x2-16)-vragi3Objects[i80].v3x+180)+
(vragi3Objects[i80].v3y+200-y2)*(vragi3Objects[i80].v3y+200-y2))<=(60+5*primanka2))
{
if(vragi3Objects[i80].v3y+200<y2)
{vragi3Objects[i80].v3y+=(0.05f+0.1f*sqrt((float)primanka2))*lag;}
if(vragi3Objects[i80].v3y+200>y2)
{vragi3Objects[i80].v3y-=(0.05f+0.1f*sqrt((float)primanka2))*lag;}
}


for (int i81=0;i81<=N_OBJECTS-1;i81++)//контакт с предметами
{
if((X-Objects[i81].x)>vragi3Objects[i80].v3x&&(X-Objects[i81].x)-vragi3Objects[i80].v3x<=300)//объект перед щами!!!
{

switch(Objects[i81].type)
{
case 0:
case 1:
case 2:
if(Objects[i81].y>=vragi3Objects[i80].v3y+200&&Objects[i81].y-(vragi3Objects[i80].v3y+200)<=50)//объект ниже
{
if(Objects[i81].pl==0)//если объект не плоский
{vragi3Objects[i80].v3y-=0.6f;}
vragi1Objects[i80].object_id=i81;}
if(Objects[i81].y<(vragi3Objects[i80].v3y+100)&&(vragi3Objects[i80].v3y+100)-Objects[i81].y<=35)//объект выше
{vragi3Objects[i80].v3y+=0.6f;}
break;

}

}//закрытие объект перед щами




if((X-Objects[i81].x)<vragi3Objects[i80].v3x&&vragi3Objects[i80].v3x-(X-Objects[i81].x)<=100)//назад на место
{
switch(Objects[i81].type)
{
case 0:
case 1:
case 2:
if(Objects[i81].y>=vragi3Objects[i80].v3y&&
Objects[i81].y-(vragi3Objects[i80].v3y+200)>=30&&Objects[i81].y-(vragi3Objects[i80].v3y+200)<=80)//объект ниже
{vragi3Objects[i80].v3y+=0.3f;}
if(Objects[i81].y<vragi3Objects[i80].v3y&&
(vragi3Objects[i80].v3y+100)-Objects[i81].y>=15&&(vragi3Objects[i80].v3y+100)-Objects[i81].y<=50)//объект выше
{vragi3Objects[i80].v3y-=0.3f;}
break;
}
}//закрытие возврата на место
}//закрытие контакта с предметами
}//закрытие скорости




//ЛЕЧИЛКА
if(vragi3Objects[i80].RPG_healer!=0&&vragi3Objects[i80].health<400&&RPGMOD==true)
{vragi3Objects[i80].health+=vragi3Objects[i80].RPG_healer;
RPG_healing_psi->FireAt(vragi3Objects[i80].v3x+100,vragi3Objects[i80].v3y+120);}

//ИЛЛЮЗИИ
if(vragi3Objects[i80].RPG_illusionist!=0&&RPGMOD==true)
{
vragi3Objects[i80].ill1_x+=vragi3Objects[i80].speed*lag;
vragi3Objects[i80].ill2_x+=vragi3Objects[i80].speed*lag;

if((((py<vragi3Objects[i80].ill1_y+200&&py>vragi3Objects[i80].ill1_y+105&&px<=vragi3Objects[i80].ill1_x&&px>vragi3Objects[i80].ill1_x-600*lag)||
   (p1d1y<vragi3Objects[i80].ill1_y+200&&p1d1y>vragi3Objects[i80].ill1_y+105&&p1d1x<=vragi3Objects[i80].ill1_x&&p1d1x>vragi3Objects[i80].ill1_x-600*lag)||
   (p1d2y<vragi3Objects[i80].ill1_y+200&&p1d2y>vragi3Objects[i80].ill1_y+105&&p1d2x<=vragi3Objects[i80].ill1_x&&p1d2x>vragi3Objects[i80].ill1_x-600*lag)||
   (p1d3y<vragi3Objects[i80].ill1_y+200&&p1d3y>vragi3Objects[i80].ill1_y+105&&p1d3x<=vragi3Objects[i80].ill1_x&&p1d3x>vragi3Objects[i80].ill1_x-600*lag)||
   (p1d4y<vragi3Objects[i80].ill1_y+200&&p1d4y>vragi3Objects[i80].ill1_y+105&&p1d4x<=vragi3Objects[i80].ill1_x&&p1d4x>vragi3Objects[i80].ill1_x-600*lag))&&
  aktivatorp==1&&x-55>vragi3Objects[i80].ill1_x&&vragi3Objects[i80].ubit!=1)||
   (((p2y<vragi3Objects[i80].ill1_y+200&&p2y>vragi3Objects[i80].ill1_y+105&&p2x<=vragi3Objects[i80].ill1_x&&p2x>vragi3Objects[i80].ill1_x-600*lag)||
   (p2d1y<vragi3Objects[i80].ill1_y+200&&p2d1y>vragi3Objects[i80].ill1_y+105&&p2d1x<=vragi3Objects[i80].ill1_x&&p2d1x>vragi3Objects[i80].ill1_x-600*lag)||
   (p2d2y<vragi3Objects[i80].ill1_y+200&&p2d2y>vragi3Objects[i80].ill1_y+105&&p2d2x<=vragi3Objects[i80].ill1_x&&p2d2x>vragi3Objects[i80].ill1_x-600*lag)||
   (p2d3y<vragi3Objects[i80].ill1_y+200&&p2d3y>vragi3Objects[i80].ill1_y+105&&p2d3x<=vragi3Objects[i80].ill1_x&&p2d3x>vragi3Objects[i80].ill1_x-600*lag)||
   (p2d4y<vragi3Objects[i80].ill1_y+200&&p2d4y>vragi3Objects[i80].ill1_y+105&&p2d4x<=vragi3Objects[i80].ill1_x&&p2d4x>vragi3Objects[i80].ill1_x-600*lag))&&
  aktivatorp2==1&&x2-55>vragi3Objects[i80].ill1_x&&vragi3Objects[i80].ubit!=1))//просчёт урона
{vragi3Objects[i80].ill1_active=0;}

if((((py<vragi3Objects[i80].ill2_y+200&&py>vragi3Objects[i80].ill2_y+105&&px<=vragi3Objects[i80].ill2_x&&px>vragi3Objects[i80].ill2_x-600*lag)||
   (p1d1y<vragi3Objects[i80].ill2_y+200&&p1d1y>vragi3Objects[i80].ill2_y+105&&p1d1x<=vragi3Objects[i80].ill2_x&&p1d1x>vragi3Objects[i80].ill2_x-600*lag)||
   (p1d2y<vragi3Objects[i80].ill2_y+200&&p1d2y>vragi3Objects[i80].ill2_y+105&&p1d2x<=vragi3Objects[i80].ill2_x&&p1d2x>vragi3Objects[i80].ill2_x-600*lag)||
   (p1d3y<vragi3Objects[i80].ill2_y+200&&p1d3y>vragi3Objects[i80].ill2_y+105&&p1d3x<=vragi3Objects[i80].ill2_x&&p1d3x>vragi3Objects[i80].ill2_x-600*lag)||
   (p1d4y<vragi3Objects[i80].ill2_y+200&&p1d4y>vragi3Objects[i80].ill2_y+105&&p1d4x<=vragi3Objects[i80].ill2_x&&p1d4x>vragi3Objects[i80].ill2_x-600*lag))&&
  aktivatorp==1&&x-55>vragi3Objects[i80].ill2_x&&vragi3Objects[i80].ubit!=1)||
   (((p2y<vragi3Objects[i80].ill2_y+200&&p2y>vragi3Objects[i80].ill2_y+105&&p2x<=vragi3Objects[i80].ill2_x&&p2x>vragi3Objects[i80].ill2_x-600*lag)||
   (p2d1y<vragi3Objects[i80].ill2_y+200&&p2d1y>vragi3Objects[i80].ill2_y+105&&p2d1x<=vragi3Objects[i80].ill2_x&&p2d1x>vragi3Objects[i80].ill2_x-600*lag)||
   (p2d2y<vragi3Objects[i80].ill2_y+200&&p2d2y>vragi3Objects[i80].ill2_y+105&&p2d2x<=vragi3Objects[i80].ill2_x&&p2d2x>vragi3Objects[i80].ill2_x-600*lag)||
   (p2d3y<vragi3Objects[i80].ill2_y+200&&p2d3y>vragi3Objects[i80].ill2_y+105&&p2d3x<=vragi3Objects[i80].ill2_x&&p2d3x>vragi3Objects[i80].ill2_x-600*lag)||
   (p2d4y<vragi3Objects[i80].ill2_y+200&&p2d4y>vragi3Objects[i80].ill2_y+105&&p2d4x<=vragi3Objects[i80].ill2_x&&p2d4x>vragi3Objects[i80].ill2_x-600*lag))&&
  aktivatorp2==1&&x2-55>vragi3Objects[i80].ill2_x&&vragi3Objects[i80].ubit!=1))//просчёт урона
{vragi3Objects[i80].ill2_active=0;}

}

//ТЕЛЕПОРТАЦИЯ
if(vragi3Objects[i80].RPG_teleporter!=0&&RPGMOD==true)
{
if(vragi3Objects[i80].teleported==0&&vragi3Objects[i80].v3x>=vragi3Objects[i80].teleportx)
{
if(player2_aktive==0)
{if(DIFF!=0)
{vragi3Objects[i80].teleporty=hge->Random_Float(250,650);}
if(DIFF==0)
{vragi3Objects[i80].teleporty=hge->Random_Float(350,550);}}
if(player2_aktive==1)
{if(DIFF!=0)
{vragi3Objects[i80].teleporty=hge->Random_Float(200,700);}
if(DIFF==0)
{vragi3Objects[i80].teleporty=hge->Random_Float(300,600);}}


while((vragi3Objects[i80].teleporty>vragi3Objects[i80].v3y&&vragi3Objects[i80].teleporty-vragi3Objects[i80].v3y<100)||
	  (vragi3Objects[i80].v3y>vragi3Objects[i80].teleporty&&vragi3Objects[i80].v3y-vragi3Objects[i80].teleporty<100))
{
if(player2_aktive==0)
{if(DIFF!=0)
{vragi3Objects[i80].teleporty=hge->Random_Float(250,650);}
if(DIFF==0)
{vragi3Objects[i80].teleporty=hge->Random_Float(350,550);}}
if(player2_aktive==1)
{if(DIFF!=0)
{vragi3Objects[i80].teleporty=hge->Random_Float(200,700);}
if(DIFF==0)
{vragi3Objects[i80].teleporty=hge->Random_Float(300,600);}}
}
vragi3Objects[i80].v3y=vragi3Objects[i80].teleporty;
vragi3Objects[i80].teleported=1;
}
if(vragi3Objects[i80].teleported==1)
{
vragi3Objects[i80].teleportx=hge->Random_Float(vragi3Objects[i80].v3x+200,vragi3Objects[i80].v3x+400);
vragi3Objects[i80].teleported=0;
}

}





 //если замочили - появляется заново
if(vragi3Objects[i80].ubit==1)
{
if(perez_akt==vragi3Objects[i80].timeout&&
((perez_akt_milli>=vragi3Objects[i80].timeout_milli&&vragi3Objects[i80].timeout_milli<800)||
(perez_akt_milli<vragi3Objects[i80].timeout_milli&&vragi3Objects[i80].timeout_milli>=800)))
{vragi3Objects[i80].ubit=0;	
vragi3Objects[i80].v3x=-150;
if(player2_aktive==0)
{if(DIFF!=0)	
{vragi3Objects[i80].v3y=hge->Random_Float(300,700);}
if(DIFF==0)	
{vragi3Objects[i80].v3y=hge->Random_Float(400,600);}}
if(player2_aktive==1)
{if(DIFF!=0)	
{vragi3Objects[i80].v3y=hge->Random_Float(250,750);}
if(DIFF==0)	
{vragi3Objects[i80].v3y=hge->Random_Float(350,650);}}
vragi3Objects[i80].health=400;
vragi3Objects[i80].speed=hge->Random_Float(0.45f,0.55f);
vragi3Objects[i80].defence=defence_medved;
vragi3Objects[i80].bezboshki=0;
vragi3Objects[i80].object_id=-1;

vragi3Objects[i80].RPG_healer=0;
vragi3Objects[i80].RPG_illusionist=0;
vragi3Objects[i80].ill1_active=0;
vragi3Objects[i80].ill2_active=0;
vragi3Objects[i80].RPG_teleporter=0;
vragi3Objects[i80].teleportx=0;
vragi3Objects[i80].teleported=0;
//руны
if(RPGMOD==true)
{
int randomize= hge->Random_Int(1,100);

if(randomize<=25&&rpg_healers==true)
{vragi3Objects[i80].RPG_healer=1;}

if(randomize>25&&randomize<=35&&rpg_illusionists==true)
{vragi3Objects[i80].RPG_illusionist=1;
vragi3Objects[i80].ill1_active=1;
vragi3Objects[i80].ill1_x=vragi3Objects[i80].v3x+hge->Random_Int(-50,50);
if(player2_aktive==0)
{vragi3Objects[i80].ill1_y=hge->Random_Float(300,700);}
if(player2_aktive==1)
{vragi3Objects[i80].ill1_y=hge->Random_Float(250,750);}
vragi3Objects[i80].ill2_active=1;
vragi3Objects[i80].ill2_x=vragi3Objects[i80].v3x+hge->Random_Int(-50,50);
if(player2_aktive==0)
{vragi3Objects[i80].ill2_y=hge->Random_Float(300,700);}
if(player2_aktive==1)
{vragi3Objects[i80].ill2_y=hge->Random_Float(250,750);}
}

if(randomize>35&&randomize<=50&&rpg_teleporters==true)
{vragi3Objects[i80].RPG_teleporter=1;
vragi3Objects[i80].teleportx=hge->Random_Float(200,600);}
}//руны

}
}



if(vragi3Objects[i80].v3x>1200&&vragi3Objects[i80].ubit!=1) // если медведь забежал за экран
{LIVES--;
vragi3Objects[i80].v3x=-150;
if(player2_aktive==0)
{if(DIFF!=0)	
{vragi3Objects[i80].v3y=hge->Random_Float(300,700);}
if(DIFF==0)	
{vragi3Objects[i80].v3y=hge->Random_Float(400,600);}}
if(player2_aktive==1)
{if(DIFF!=0)	
{vragi3Objects[i80].v3y=hge->Random_Float(250,750);}
if(DIFF==0)	
{vragi3Objects[i80].v3y=hge->Random_Float(350,650);}}
vragi3Objects[i80].health=400;
vragi3Objects[i80].speed=hge->Random_Float(0.45f,0.55f);
vragi3Objects[i80].defence=defence_medved;
vragi3Objects[i80].object_id=-1;

vragi3Objects[i80].RPG_healer=0;
vragi3Objects[i80].RPG_illusionist=0;
vragi3Objects[i80].ill1_active=0;
vragi3Objects[i80].ill2_active=0;
vragi3Objects[i80].RPG_teleporter=0;
vragi3Objects[i80].teleportx=0;
vragi3Objects[i80].teleported=0;
//руны
if(RPGMOD==true)
{
int randomize= hge->Random_Int(1,100);

if(randomize<=25&&rpg_healers==true)
{vragi3Objects[i80].RPG_healer=1;}

if(randomize>25&&randomize<=35&&rpg_illusionists==true)
{vragi3Objects[i80].RPG_illusionist=1;
vragi3Objects[i80].ill1_active=1;
vragi3Objects[i80].ill1_x=vragi3Objects[i80].v3x+hge->Random_Int(-50,50);
if(player2_aktive==0)
{vragi3Objects[i80].ill1_y=hge->Random_Float(300,700);}
if(player2_aktive==1)
{vragi3Objects[i80].ill1_y=hge->Random_Float(250,750);}
vragi3Objects[i80].ill2_active=1;
vragi3Objects[i80].ill2_x=vragi3Objects[i80].v3x+hge->Random_Int(-50,50);
if(player2_aktive==0)
{vragi3Objects[i80].ill2_y=hge->Random_Float(300,700);}
if(player2_aktive==1)
{vragi3Objects[i80].ill2_y=hge->Random_Float(250,750);}
}

if(randomize>35&&randomize<=50&&rpg_teleporters==true)
{vragi3Objects[i80].RPG_teleporter=1;
vragi3Objects[i80].teleportx=hge->Random_Float(200,600);}
}//руны
}




if((((p1d1y<vragi3Objects[i80].v3y+200&&p1d1y>vragi3Objects[i80].v3y+105&&p1d1x<=vragi3Objects[i80].v3x+170&&p1d1x>vragi3Objects[i80].v3x-300*lag&&aktivatorp1d1==1)||
   (p1d2y<vragi3Objects[i80].v3y+200&&p1d2y>vragi3Objects[i80].v3y+105&&p1d2x<=vragi3Objects[i80].v3x+170&&p1d2x>vragi3Objects[i80].v3x-300*lag&&aktivatorp1d2==1)||
   (p1d3y<vragi3Objects[i80].v3y+200&&p1d3y>vragi3Objects[i80].v3y+105&&p1d3x<=vragi3Objects[i80].v3x+170&&p1d3x>vragi3Objects[i80].v3x-300*lag&&aktivatorp1d3==1)||
   (p1d4y<vragi3Objects[i80].v3y+200&&p1d4y>vragi3Objects[i80].v3y+105&&p1d4x<=vragi3Objects[i80].v3x+170&&p1d4x>vragi3Objects[i80].v3x-300*lag&&aktivatorp1d4==1)||
   (py<vragi3Objects[i80].v3y+200&&py>vragi3Objects[i80].v3y+105&&px<=vragi3Objects[i80].v3x+170&&px>vragi3Objects[i80].v3x-300*lag&&aktivatorp==1))
  &&x-55>vragi3Objects[i80].v3x&&vragi3Objects[i80].ubit!=1)||
   (((p2d1y<vragi3Objects[i80].v3y+200&&p2d1y>vragi3Objects[i80].v3y+105&&p2d1x<=vragi3Objects[i80].v3x+170&&p2d1x>vragi3Objects[i80].v3x-300*lag&&aktivatorp2d1==1)||
   (p2d2y<vragi3Objects[i80].v3y+200&&p2d2y>vragi3Objects[i80].v3y+105&&p2d2x<=vragi3Objects[i80].v3x+170&&p2d2x>vragi3Objects[i80].v3x-300*lag&&aktivatorp2d2==1)||
   (p2d3y<vragi3Objects[i80].v3y+200&&p2d3y>vragi3Objects[i80].v3y+105&&p2d3x<=vragi3Objects[i80].v3x+170&&p2d3x>vragi3Objects[i80].v3x-300*lag&&aktivatorp2d3==1)||
   (p2d4y<vragi3Objects[i80].v3y+200&&p2d4y>vragi3Objects[i80].v3y+105&&p2d4x<=vragi3Objects[i80].v3x+170&&p2d4x>vragi3Objects[i80].v3x-300*lag&&aktivatorp2d4==1)||
   (p2y<vragi3Objects[i80].v3y+200&&p2y>vragi3Objects[i80].v3y+119&&p2x<=vragi3Objects[i80].v3x+170&&p2x>vragi3Objects[i80].v3x-300*lag&&aktivatorp2==1))
  &&x2-55>vragi3Objects[i80].v3x&&vragi3Objects[i80].ubit!=1))//просчёт урона
{


if(shot==0)
{
if(((py<vragi3Objects[i80].v3y+200&&py>vragi3Objects[i80].v3y+105&&px<=vragi3Objects[i80].v3x+170&&px>vragi3Objects[i80].v3x-300*lag&&aktivatorp==1)||
   (p1d1y<vragi3Objects[i80].v3y+200&&p1d1y>vragi3Objects[i80].v3y+105&&p1d1x<=vragi3Objects[i80].v3x+170&&p1d1x>vragi3Objects[i80].v3x-300*lag&&aktivatorp1d1==1)||
   (p1d2y<vragi3Objects[i80].v3y+200&&p1d2y>vragi3Objects[i80].v3y+105&&p1d2x<=vragi3Objects[i80].v3x+170&&p1d2x>vragi3Objects[i80].v3x-300*lag&&aktivatorp1d2==1)||
   (p1d3y<vragi3Objects[i80].v3y+200&&p1d3y>vragi3Objects[i80].v3y+105&&p1d3x<=vragi3Objects[i80].v3x+170&&p1d3x>vragi3Objects[i80].v3x-300*lag&&aktivatorp1d3==1)||
   (p1d4y<vragi3Objects[i80].v3y+200&&p1d4y>vragi3Objects[i80].v3y+105&&p1d4x<=vragi3Objects[i80].v3x+170&&p1d4x>vragi3Objects[i80].v3x-300*lag&&aktivatorp1d4==1))
&&x-55>vragi3Objects[i80].v3x)	
{vragi3Objects[i80].killed_by=1;}//попал игрок 1
if(((p2y<vragi3Objects[i80].v3y+200&&p2y>vragi3Objects[i80].v3y+105&&p2x<=vragi3Objects[i80].v3x+170&&p2x>vragi3Objects[i80].v3x-300*lag&&aktivatorp2==1)||
   (p2d1y<vragi3Objects[i80].v3y+200&&p2d1y>vragi3Objects[i80].v3y+105&&p2d1x<=vragi3Objects[i80].v3x+170&&p2d1x>vragi3Objects[i80].v3x-300*lag&&aktivatorp1d1==1)||
   (p2d2y<vragi3Objects[i80].v3y+200&&p2d2y>vragi3Objects[i80].v3y+105&&p2d2x<=vragi3Objects[i80].v3x+170&&p2d2x>vragi3Objects[i80].v3x-300*lag&&aktivatorp1d2==1)||
   (p2d3y<vragi3Objects[i80].v3y+200&&p2d3y>vragi3Objects[i80].v3y+105&&p2d3x<=vragi3Objects[i80].v3x+170&&p2d3x>vragi3Objects[i80].v3x-300*lag&&aktivatorp1d3==1)||
   (p2d4y<vragi3Objects[i80].v3y+200&&p2d4y>vragi3Objects[i80].v3y+105&&p2d4x<=vragi3Objects[i80].v3x+170&&p2d4x>vragi3Objects[i80].v3x-300*lag&&aktivatorp1d4==1))
 &&x2-55>vragi3Objects[i80].v3x)
{vragi3Objects[i80].killed_by=2;}//попал игрок 2











if(((py<vragi3Objects[i80].v3y+200&&py>vragi3Objects[i80].v3y+105)||
   (p1d1y<vragi3Objects[i80].v3y+200&&p1d1y>vragi3Objects[i80].v3y+105)||
   (p1d2y<vragi3Objects[i80].v3y+200&&p1d2y>vragi3Objects[i80].v3y+105)||
   (p1d3y<vragi3Objects[i80].v3y+200&&p1d3y>vragi3Objects[i80].v3y+105)||
   (p1d4y<vragi3Objects[i80].v3y+200&&p1d4y>vragi3Objects[i80].v3y+105))||
   ((p2y<vragi3Objects[i80].v3y+200&&p2y>vragi3Objects[i80].v3y+105)||
   (p2d1y<vragi3Objects[i80].v3y+200&&p2d1y>vragi3Objects[i80].v3y+105)||
   (p2d2y<vragi3Objects[i80].v3y+200&&p2d2y>vragi3Objects[i80].v3y+105)||
   (p2d3y<vragi3Objects[i80].v3y+200&&p2d3y>vragi3Objects[i80].v3y+105)||
   (p2d4y<vragi3Objects[i80].v3y+200&&p2d4y>vragi3Objects[i80].v3y+105)))//ОБЫЧНОЕ ПОПАДАНИЕ	
{

if(vragi3Objects[i80].killed_by==1)	
{

if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi3Objects[i80].defence>=5||
   damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi3Objects[i80].defence>=5)
{
if(LVL1%2==0)
{vragi3Objects[i80].health-=damage[N_WEAPON1]+LVL1/2*attack1-vragi3Objects[i80].defence;}
if(LVL1%2==1)
{vragi3Objects[i80].health-=damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi3Objects[i80].defence;}
}

if(damage[N_WEAPON1]+LVL1/2*attack1-vragi3Objects[i80].defence<5||
 damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi3Objects[i80].defence<5)
{vragi3Objects[i80].health-=5;}
}//RPG

if(RPGMOD==false)
{vragi3Objects[i80].health-=damage[N_WEAPON1];}


}//урон от оружия игрока 1

if(vragi3Objects[i80].killed_by==2)
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi3Objects[i80].defence>=5||
   damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi3Objects[i80].defence>=5)
{
if(LVL2%2==0)
{vragi3Objects[i80].health-=damage[N_WEAPON2]+LVL2/2*attack2-vragi3Objects[i80].defence;}
if(LVL2%2==1)
{vragi3Objects[i80].health-=damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi3Objects[i80].defence;}
}

if(damage[N_WEAPON2]+LVL2/2*attack2-vragi3Objects[i80].defence<5||
   damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi3Objects[i80].defence<5)
{vragi3Objects[i80].health-=5;}
}//RPG

if(RPGMOD==false)
{vragi3Objects[i80].health-=damage[N_WEAPON2];}

}//урон от оружия игрока 2

hge->Effect_PlayEx(shot1,volume*8/10,0,0);
}//ЗАКРЫТИЕ ПОПАДАНИЯ



if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!


krovyakObjects[N_BLOOD].seed=hge->Random_Int(1,3);
krovyakObjects[N_BLOOD].vrag=3;
if(vragi3Objects[i80].killed_by==1)	
{
if(py<vragi3Objects[i80].v3y+200&&py>vragi3Objects[i80].v3y+105&&px<=vragi3Objects[i80].v3x+170&&px>vragi3Objects[i80].v3x-300*lag)	
{ppp=1;
krovyakObjects[N_BLOOD].y1=py; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=py+5;}
if(p1d1y<vragi3Objects[i80].v3y+200&&p1d1y>vragi3Objects[i80].v3y+105&&p1d1x<=vragi3Objects[i80].v3x+170&&p1d1x>vragi3Objects[i80].v3x-300*lag)	
{ppp=2;
krovyakObjects[N_BLOOD].y1=p1d1y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p1d1y+5;}
if(p1d2y<vragi3Objects[i80].v3y+200&&p1d2y>vragi3Objects[i80].v3y+105&&p1d2x<=vragi3Objects[i80].v3x+170&&p1d2x>vragi3Objects[i80].v3x-300*lag)	
{ppp=3;
krovyakObjects[N_BLOOD].y1=p1d2y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p1d2y+5;}
if(p1d3y<vragi3Objects[i80].v3y+200&&p1d3y>vragi3Objects[i80].v3y+105&&p1d3x<=vragi3Objects[i80].v3x+170&&p1d3x>vragi3Objects[i80].v3x-300*lag)	
{ppp=4;
krovyakObjects[N_BLOOD].y1=p1d3y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p1d3y+5;}
if(p1d4y<vragi3Objects[i80].v3y+200&&p1d4y>vragi3Objects[i80].v3y+105&&p1d4x<=vragi3Objects[i80].v3x+170&&p1d4x>vragi3Objects[i80].v3x-300*lag)	
{ppp=5;
krovyakObjects[N_BLOOD].y1=p1d4y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p1d4y+5;}
}
if(vragi3Objects[i80].killed_by==2)
{
if(p2y<vragi3Objects[i80].v3y+200&&p2y>vragi3Objects[i80].v3y+105&&p2x<=vragi3Objects[i80].v3x+170&&p2x>vragi3Objects[i80].v3x-300*lag)
{ppp=1;
krovyakObjects[N_BLOOD].y1=p2y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p2y+5;}
if(p2d1y<vragi3Objects[i80].v3y+200&&p2d1y>vragi3Objects[i80].v3y+105&&p2d1x<=vragi3Objects[i80].v3x+170&&p2d1x>vragi3Objects[i80].v3x-300*lag)
{ppp=2;
krovyakObjects[N_BLOOD].y1=p2d1y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p2d1y+5;}
if(p2d2y<vragi3Objects[i80].v3y+200&&p2d2y>vragi3Objects[i80].v3y+105&&p2d2x<=vragi3Objects[i80].v3x+170&&p2d2x>vragi3Objects[i80].v3x-300*lag)
{ppp=3;
krovyakObjects[N_BLOOD].y1=p2d2y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p2d2y+5;}
if(p2d3y<vragi3Objects[i80].v3y+200&&p2d3y>vragi3Objects[i80].v3y+105&&p2d3x<=vragi3Objects[i80].v3x+170&&p2d3x>vragi3Objects[i80].v3x-300*lag)
{ppp=4;
krovyakObjects[N_BLOOD].y1=p2d3y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p2d3y+5;}
if(p2d4y<vragi3Objects[i80].v3y+200&&p2d4y>vragi3Objects[i80].v3y+105&&p2d4x<=vragi3Objects[i80].v3x+170&&p2d4x>vragi3Objects[i80].v3x-300*lag)
{ppp=5;
krovyakObjects[N_BLOOD].y1=p2d4y; //КРОВЯК (назад)
krovyakObjects[N_BLOOD].y2=p2d4y+5;}
}
krovyakObjects[N_BLOOD].x2=vragi3Objects[i80].v3x+15;
krovyakObjects[N_BLOOD].x1=vragi3Objects[i80].v3x+5;
krovyakObjects[N_BLOOD].xstart=vragi3Objects[i80].v3x;
krovyakObjects[N_BLOOD].niz=vragi3Objects[i80].v3y+200;
krovyakObjects[N_BLOOD].blood_time=GetTime();
krovyakObjects[N_BLOOD].blood_time_sec=perez_akt;
krovyakObjects[N_BLOOD].akt=1;
krovyakObjects[N_BLOOD].faza=1;


N_BLOOD++;

if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!


krovyakObjects[N_BLOOD].seed=0;//кровяк самого попадания (точка)
krovyakObjects[N_BLOOD].vrag=3;
if(vragi3Objects[i80].killed_by==1)
{
if(ppp==1)	
{krovyakObjects[N_BLOOD].y1=py-4;
krovyakObjects[N_BLOOD].y2=py+4;}
if(ppp==2)	
{krovyakObjects[N_BLOOD].y1=p1d1y-4;
krovyakObjects[N_BLOOD].y2=p1d1y+4;}
if(ppp==3)	
{krovyakObjects[N_BLOOD].y1=p1d2y-4;
krovyakObjects[N_BLOOD].y2=p1d2y+4;}
if(ppp==4)	
{krovyakObjects[N_BLOOD].y1=p1d3y-4;
krovyakObjects[N_BLOOD].y2=p1d3y+4;}
if(ppp==5)	
{krovyakObjects[N_BLOOD].y1=p1d4y-4;
krovyakObjects[N_BLOOD].y2=p1d4y+4;}
}

if(vragi3Objects[i80].killed_by==2)
{
if(ppp==1)	
{krovyakObjects[N_BLOOD].y1=p2y-4;
krovyakObjects[N_BLOOD].y2=p2y+4;}
if(ppp==2)	
{krovyakObjects[N_BLOOD].y1=p2d1y-4;
krovyakObjects[N_BLOOD].y2=p2d1y+4;}
if(ppp==3)	
{krovyakObjects[N_BLOOD].y1=p2d2y-4;
krovyakObjects[N_BLOOD].y2=p2d2y+4;}
if(ppp==4)	
{krovyakObjects[N_BLOOD].y1=p2d3y-4;
krovyakObjects[N_BLOOD].y2=p2d3y+4;}
if(ppp==5)	
{krovyakObjects[N_BLOOD].y1=p2d4y-4;
krovyakObjects[N_BLOOD].y2=p2d4y+4;}
}

krovyakObjects[N_BLOOD].x2=vragi3Objects[i80].v3x+166;
krovyakObjects[N_BLOOD].x1=vragi3Objects[i80].v3x+178;
krovyakObjects[N_BLOOD].blood_time=GetTime();
krovyakObjects[N_BLOOD].blood_time_sec=perez_akt;
krovyakObjects[N_BLOOD].akt=1;


N_BLOOD++;

if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!


krovyakObjects[N_BLOOD].seed=hge->Random_Int(101,103);
krovyakObjects[N_BLOOD].vrag=3;
if(vragi3Objects[i80].killed_by==1)	
{
if(ppp==1)
{krovyakObjects[N_BLOOD].y1=py; //КРОВЯК (вперед)
krovyakObjects[N_BLOOD].y2=py+5;}
if(ppp==2)	
{krovyakObjects[N_BLOOD].y1=p1d1y;
krovyakObjects[N_BLOOD].y2=p1d1y+5;}
if(ppp==3)	
{krovyakObjects[N_BLOOD].y1=p1d2y;
krovyakObjects[N_BLOOD].y2=p1d2y+5;}
if(ppp==4)	
{krovyakObjects[N_BLOOD].y1=p1d3y;
krovyakObjects[N_BLOOD].y2=p1d3y+5;}
if(ppp==5)	
{krovyakObjects[N_BLOOD].y1=p1d4y;
krovyakObjects[N_BLOOD].y2=p1d4y+5;}
}

if(vragi3Objects[i80].killed_by==2)
{
if(ppp==1)	
{krovyakObjects[N_BLOOD].y1=p2y;
krovyakObjects[N_BLOOD].y2=p2y+5;}
if(ppp==2)	
{krovyakObjects[N_BLOOD].y1=p2d1y;
krovyakObjects[N_BLOOD].y2=p2d1y+5;}
if(ppp==3)
{krovyakObjects[N_BLOOD].y1=p2d2y;
krovyakObjects[N_BLOOD].y2=p2d2y+5;}
if(ppp==4)	
{krovyakObjects[N_BLOOD].y1=p2d3y;
krovyakObjects[N_BLOOD].y2=p2d3y+5;}
if(ppp==5)	
{krovyakObjects[N_BLOOD].y1=p2d4y;
krovyakObjects[N_BLOOD].y2=p2d4y+5;}
}

krovyakObjects[N_BLOOD].x2=vragi3Objects[i80].v3x+155;
krovyakObjects[N_BLOOD].x1=vragi3Objects[i80].v3x+160;
krovyakObjects[N_BLOOD].xstart=vragi3Objects[i80].v3x+155;
krovyakObjects[N_BLOOD].niz=vragi3Objects[i80].v3y+200;
krovyakObjects[N_BLOOD].blood_time=GetTime();
krovyakObjects[N_BLOOD].blood_time_sec=perez_akt;
krovyakObjects[N_BLOOD].akt=1;
krovyakObjects[N_BLOOD].faza=1;


N_BLOOD++;

if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!






shot=1;


if(vragi3Objects[i80].killed_by==1)
{
if(N_WEAPON1!=10&&aktivatorp!=0)//патрон слабый - ШКУРА МЕДВЕДЯ!!!!
{aktivatorp=0;
oboima-=1;}


if(N_WEAPON1==7)
{
if(ppp==2)
{p1d1y=y-9;
p1d1x=x-24;
aktivatorp1d1=0;}
if(ppp==3)
{p1d2y=y-9;
p1d2x=x-24;
aktivatorp1d2=0;}
if(ppp==4)
{p1d3y=y-9;
p1d3x=x-24;
aktivatorp1d3=0;}
if(ppp==5)
{p1d4y=y-9;
p1d4x=x-24;
aktivatorp1d4=0;}
}

}

if(vragi3Objects[i80].killed_by==2)
{
if(N_WEAPON2!=10&&aktivatorp2!=0)//патрон слабый
{aktivatorp2=0;
oboima2-=1;}

if(N_WEAPON2==7)
{
if(ppp==2)
{p2d1y=y2-9;
p2d1x=x2-24;
aktivatorp2d1=0;}
if(ppp==3)
{p2d2y=y2-9;
p2d2x=x2-24;
aktivatorp2d2=0;}
if(ppp==4)
{p2d3y=y2-9;
p2d3x=x2-24;
aktivatorp2d3=0;}
if(ppp==5)
{p2d4y=y2-9;
p2d4x=x2-24;
aktivatorp2d4=0;}
}
if(N_WEAPON2==0||N_WEAPON2==3)// если это АК то косит всех подряд
{shot=0;}
}





}//if shot==0

}//закрытие просчёта урона медведю




//холодное оружие
if((katana1_anime->IsPlaying()==true&&katana1_anime->GetFrame()==2&&vragi3Objects[i80].health>0&&x-55>vragi3Objects[i80].v3x+10&&
vragi3Objects[i80].v3x+170>x-95&&y<vragi3Objects[i80].v3y+220&&y>vragi3Objects[i80].v3y+125)||
(katana2_anime->IsPlaying()==true&&katana2_anime->GetFrame()==2&&vragi3Objects[i80].health>0&&x2-55>vragi3Objects[i80].v3x+10&&
vragi3Objects[i80].v3x+170>x2-95&&y2<vragi3Objects[i80].v3y+220&&y2>vragi3Objects[i80].v3y+125))
{

if(katana1_anime->IsPlaying()==true&&katana1_anime->GetFrame()==2&&vragi3Objects[i80].health>0&&x-55>vragi3Objects[i80].v3x+10&&
vragi3Objects[i80].v3x+170>x-95&&y<vragi3Objects[i80].v3y+220&&y>vragi3Objects[i80].v3y+125)
{vragi3Objects[i80].killed_by=1;}
if(katana2_anime->IsPlaying()==true&&katana2_anime->GetFrame()==2&&vragi3Objects[i80].health>0&&x2-55>vragi3Objects[i80].v3x+10&&
vragi3Objects[i80].v3x+170>x2-95&&y2<vragi3Objects[i80].v3y+220&&y2>vragi3Objects[i80].v3y+125)
{vragi3Objects[i80].killed_by=2;}

/*
if((y<=vragi3Objects[i80].v3y+17&&y>vragi3Objects[i80].v3y+13)||
(y2<=vragi3Objects[i80].v3y+17&&y2>vragi3Objects[i80].v3y+13))//ХЭДШОТ!!!
{

if(vragi3Objects[i80].killed_by==1)	
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi3Objects[i80].defence>=5||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi3Objects[i80].defence>=5)
{

if(CLASSMOD==true&&class1==1)
{
if(LVL1%2==0)
{vragi3Objects[i80].health-=(damage[N_WEAPON1]+LVL1/2*attack1)*1.2f-vragi3Objects[i80].defence;}
if(LVL1%2==1)
{vragi3Objects[i80].health-=(damage[N_WEAPON1]+(LVL1-1)/2*attack1)*1.2f-vragi3Objects[i80].defence;}
}

if(CLASSMOD==false||class1!=1)
{
if(LVL1%2==0)
{vragi3Objects[i80].health-=damage[N_WEAPON1]+LVL1/2*attack1-vragi3Objects[i80].defence;}
if(LVL1%2==1)
{vragi3Objects[i80].health-=damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi3Objects[i80].defence;}
}

}
//гарантированный урон
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi3Objects[i80].defence<5||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi3Objects[i80].defence<5)
{vragi3Objects[i80].health-=5;}
}//RPG

if(RPGMOD==false)
{vragi3Objects[i80].health-=damage[N_WEAPON1];}
if(RPGMOD==false&&CLASSMOD==true&&class1==1)
{vragi3Objects[i80].health-=damage[N_WEAPON1]*1.2f;}

points1+=25;}//урон от оружия игрока 1


if(vragi3Objects[i80].killed_by==2)	
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi3Objects[i80].defence>=5||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi3Objects[i80].defence>=5)
{

if(CLASSMOD==true&&class2==1)
{
if(LVL2%2==0)
{vragi3Objects[i80].health-=(damage[N_WEAPON2]+LVL2/2*attack2)*1.2f-vragi3Objects[i80].defence;}
if(LVL2%2==1)
{vragi3Objects[i80].health-=(damage[N_WEAPON2]+(LVL2-1)/2*attack2)*1.2f-vragi3Objects[i80].defence;}
}

if(CLASSMOD==false||class2!=1)
{
if(LVL2%2==0)
{vragi3Objects[i80].health-=damage[N_WEAPON2]+LVL2/2*attack2-vragi3Objects[i80].defence;}
if(LVL2%2==1)
{vragi3Objects[i80].health-=damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi3Objects[i80].defence;}
}

}
//гарантированный урон
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi3Objects[i80].defence<5||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi3Objects[i80].defence<5)
{vragi3Objects[i80].health-=5;}
}//RPG

if(RPGMOD==false&&CLASSMOD==false)
{vragi3Objects[i80].health-=damage[N_WEAPON2];}
if(RPGMOD==false&&CLASSMOD==true&&class2==1)
{vragi3Objects[i80].health-=damage[N_WEAPON2]*1.2f;}

points2+=25;}//урон от оружия игрока 2

headshotPan=-75+vragi3Objects[i80].v3x/9;
headshot();

}//ХЭДШОТ ЗАКОНЧИЛСЯ
*/


if(vragi3Objects[i80].killed_by==1)
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi3Objects[i80].defence>=10||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi3Objects[i80].defence>=10)
{

if(CLASSMOD==true&&class1==1)
{
if(LVL1%2==0)
{vragi3Objects[i80].health-=(damage[N_WEAPON1]+LVL1/2*attack1)*1.2f-vragi3Objects[i80].defence;}
if(LVL1%2==1)
{vragi3Objects[i80].health-=(damage[N_WEAPON1]+(LVL1-1)/2*attack1)*1.2f-vragi3Objects[i80].defence;}
}


if(CLASSMOD==false||class1!=1)
{
if(LVL1%2==0)
{vragi3Objects[i80].health-=damage[N_WEAPON1]+LVL1/2*attack1-vragi3Objects[i80].defence;}
if(LVL1%2==1)
{vragi3Objects[i80].health-=damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi3Objects[i80].defence;}
}


}
//гарантированный урон
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi3Objects[i80].defence<10||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi3Objects[i80].defence<10)
{vragi3Objects[i80].health-=10;}
}//RPG
if(RPGMOD==false)
{vragi3Objects[i80].health-=damage[N_WEAPON1];}

krovyakObjects[N_BLOOD].y1=y-10; //КРОВЯК (вперед)
krovyakObjects[N_BLOOD].y2=y;

}

if(vragi3Objects[i80].killed_by==2)
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi3Objects[i80].defence>=10||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi3Objects[i80].defence>=10)
{

if(CLASSMOD==true&&class2==1)
{
if(LVL2%2==0)
{vragi3Objects[i80].health-=(damage[N_WEAPON2]+LVL2/2*attack2)*1.2f-vragi3Objects[i80].defence;}
if(LVL2%2==1)
{vragi3Objects[i80].health-=(damage[N_WEAPON2]+(LVL2-1)/2*attack2)*1.2f-vragi3Objects[i80].defence;}
}

if(CLASSMOD==false&&class2!=1)
{
if(LVL2%2==0)
{vragi3Objects[i80].health-=damage[N_WEAPON2]+LVL2/2*attack2-vragi3Objects[i80].defence;}
if(LVL2%2==1)
{vragi3Objects[i80].health-=damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi3Objects[i80].defence;}
}

}
//гарантированный урон
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi3Objects[i80].defence<10||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi3Objects[i80].defence<10)
{vragi3Objects[i80].health-=10;}
}//RPG
if(RPGMOD==false)
{vragi3Objects[i80].health-=damage[N_WEAPON2];}

krovyakObjects[N_BLOOD].y1=y2-10; //КРОВЯК (вперед)
krovyakObjects[N_BLOOD].y2=y2;

}

krovyakObjects[N_BLOOD].seed=hge->Random_Int(101,103);
krovyakObjects[N_BLOOD].vrag=1;
krovyakObjects[N_BLOOD].x2=x-95+10;
krovyakObjects[N_BLOOD].x1=x-95+35;
krovyakObjects[N_BLOOD].xstart=x-95+10;
krovyakObjects[N_BLOOD].niz=vragi3Objects[i80].v3y+240;
krovyakObjects[N_BLOOD].blood_time=GetTime();
krovyakObjects[N_BLOOD].blood_time_sec=perez_akt;
krovyakObjects[N_BLOOD].akt=1;
krovyakObjects[N_BLOOD].faza=1;
N_BLOOD++;
if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!

hge->Effect_PlayEx(shot1,volume*8/10,0,0);



}//холодное оружие







if(vragi3Objects[i80].health<=0&&vragi3Objects[i80].ubit==0)//убийство медведя
{
medved->Stop();
vragi3Objects[i80].ubit=1;
vragi3Objects[i80].timeout_milli=GetTime();
switch(DIFF)
{
case 0:
if(perez_akt<44)
{vragi3Objects[i80].timeout=perez_akt+16;}
if(perez_akt>=44)
{vragi3Objects[i80].timeout=perez_akt-44;}
break;
case 1:
if(perez_akt<46)
{vragi3Objects[i80].timeout=perez_akt+14;}
if(perez_akt>=46)
{vragi3Objects[i80].timeout=perez_akt-46;}
break;
case 2:
if(perez_akt<48)
{vragi3Objects[i80].timeout=perez_akt+12;}
if(perez_akt>=48)
{vragi3Objects[i80].timeout=perez_akt-48;}
break;
}

if(vragi3Objects[i80].killed_by==1)
{kills++;

//статистика
ubijstva[N_KILLS].player=1;
ubijstva[N_KILLS].vrag=3;
ubijstva[N_KILLS].weapon=N_WEAPON1;
ubijstva[N_KILLS].bezuh=false;
ubijstva[N_KILLS].bezboshki=false;
ubijstva[N_KILLS].headshot=false;
ubijstva[N_KILLS].vschiii=false;
N_KILLS++;
if(N_KILLS>=MAX_KILLS-1)
{N_KILLS=0;}
//статистика


points1+=500;
opit1+=(150+vragi3Objects[i80].defence*vragi3Objects[i80].defence/LVL1)*w_opit_medved[N_WEAPON1]*(1+0.25f*umnik1)/daun1;

}

if(vragi3Objects[i80].killed_by==2)
{kills2++;

//статистика
ubijstva[N_KILLS].player=2;
ubijstva[N_KILLS].vrag=3;
ubijstva[N_KILLS].weapon=N_WEAPON2;
ubijstva[N_KILLS].bezuh=false;
ubijstva[N_KILLS].bezboshki=false;
ubijstva[N_KILLS].headshot=false;
ubijstva[N_KILLS].vschiii=false;
N_KILLS++;
if(N_KILLS>=MAX_KILLS-1)
{N_KILLS=0;}
//статистика

points2+=200;
opit2+=(150+vragi3Objects[i80].defence*vragi3Objects[i80].defence/LVL2)*w_opit_medved[N_WEAPON2]*(1+0.25f*umnik2)/daun2;
}

trupsObjects[N_TRUPS].killtime=GetTime();//лужа кровяка
trupsObjects[N_TRUPS].killtime_sec=perez_akt;
trupsObjects[N_TRUPS].posX=vragi3Objects[i80].v3x+95;
trupsObjects[N_TRUPS].posY=vragi3Objects[i80].v3y+215;
trupsObjects[N_TRUPS].posX_s=vragi3Objects[i80].v3x+95;
trupsObjects[N_TRUPS].posX_X=X;
trupsObjects[N_TRUPS].vrag=3;
trupsObjects[N_TRUPS].scaleX=0.1f;
trupsObjects[N_TRUPS].scaleY=0;
trupsObjects[N_TRUPS].aktiv=1;
trupsObjects[N_TRUPS].type=9;




N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}


//БОНУС?!
bonus_shans();

if(vragi3Objects[i80].killed_by==1)
{
if(bonus>=371&&bonus<=379+5*luck1)
{
bonusiObjects[N_BONUS].x1=vragi3Objects[i80].v3x+5;
bonusiObjects[N_BONUS].y1=vragi3Objects[i80].v3y+5;
bonusiObjects[N_BONUS].x1_s=vragi3Objects[i80].v3x+5;
bonusiObjects[N_BONUS].x1_X=X;
bonusiObjects[N_BONUS].x2=vragi3Objects[i80].v3x+35;
bonusiObjects[N_BONUS].y2=vragi3Objects[i80].v3y+35;
bonusiObjects[N_BONUS].x2_s=vragi3Objects[i80].v3x+35;
bonusiObjects[N_BONUS].x2_X=X;
bonusiObjects[N_BONUS].appear_time_milli=GetTime();
bonusiObjects[N_BONUS].appear_time=perez_akt;
bonusiObjects[N_BONUS].type=0;
bonusiObjects[N_BONUS].akt=1;
bonusiObjects[N_BONUS].spin=0;
bonusiObjects[N_BONUS].visible=true;
bonusiObjects[N_BONUS].mig_akt=0;

N_BONUS++;
if(N_BONUS>=MAX_BONUS-1)
{N_BONUS=0;}

}
}//if(vragi2Objects[i20].killed_by==1)

if(vragi3Objects[i80].killed_by==2)
{
if(bonus>=371&&bonus<=379+5*luck2)
{
bonusiObjects[N_BONUS].x1=vragi3Objects[i80].v3x+5;
bonusiObjects[N_BONUS].y1=vragi3Objects[i80].v3y+5;
bonusiObjects[N_BONUS].x1_s=vragi3Objects[i80].v3x+5;
bonusiObjects[N_BONUS].x1_X=X;
bonusiObjects[N_BONUS].x2=vragi3Objects[i80].v3x+35;
bonusiObjects[N_BONUS].y2=vragi3Objects[i80].v3y+35;
bonusiObjects[N_BONUS].x2_s=vragi3Objects[i80].v3x+35;
bonusiObjects[N_BONUS].x2_X=X;
bonusiObjects[N_BONUS].appear_time_milli=GetTime();
bonusiObjects[N_BONUS].appear_time=perez_akt;
bonusiObjects[N_BONUS].type=0;
bonusiObjects[N_BONUS].akt=1;
bonusiObjects[N_BONUS].spin=0;
bonusiObjects[N_BONUS].visible=true;
bonusiObjects[N_BONUS].mig_akt=0;

N_BONUS++;
if(N_BONUS>=MAX_BONUS-1)
{N_BONUS=0;}

}
}//if(vragi2Objects[i20].killed_by==2)


trupsObjects[N_TRUPS].type=20;
trupsObjects[N_TRUPS].killtime=GetTime();
trupsObjects[N_TRUPS].killtime_sec=perez_akt;
trupsObjects[N_TRUPS].frame=1;
trupsObjects[N_TRUPS].frame_akt=1;
trupsObjects[N_TRUPS].trup_tex=zayac_go_tex;
if(vragi3Objects[i80].bezboshki==1)
{trupsObjects[N_TRUPS].trup_tex=zayac_go_bezuh_tex;}
trupsObjects[N_TRUPS].posX=vragi3Objects[i80].v3x;
trupsObjects[N_TRUPS].posY=vragi3Objects[i80].v3y;
trupsObjects[N_TRUPS].posX_s=vragi3Objects[i80].v3x;
trupsObjects[N_TRUPS].posX_X=X;


N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}




}//закрытие убийства медведя






}//закрытие саги про медведя


//ПТЕНЕЦ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!111
for (int i120=0;i120<=N_PTENEC;i120++)
{

if(vragi4Objects[i120].ubit!=1)//сама скорость
{	
if(vragi4Objects[i120].wait!=1)
{vragi4Objects[i120].v4x+=vragi4Objects[i120].speed*lag;
if(vragi4Objects[i120].v4x>=230&&vragi4Objects[i120].wait==0)
{vragi4Objects[i120].wait=1;
vragi4Objects[i120].wait_time_sec=perez_akt;}}

ptenec->Resume();

if(vragi4Objects[i120].wait==1)
{ptenec_wait->Resume();

if((vragi4Objects[i120].wait_time_sec<57&&perez_akt==vragi4Objects[i120].wait_time_sec+3)||
   (vragi4Objects[i120].wait_time_sec>=57&&perez_akt==vragi4Objects[i120].wait_time_sec-57))
{vragi4Objects[i120].wait=-1;}
}



//агро мясника
if(class1==1&&primanka1>0&&vragi4Objects[i120].v4x+23<=x-16&&sqrt(((x-16)-vragi4Objects[i120].v4x+23)*((x-16)-vragi4Objects[i120].v4x+23)+
(vragi4Objects[i120].v4y+20-y)*(vragi4Objects[i120].v4y+20-y))<=(60+5*primanka1))
{
if(vragi4Objects[i120].v4y+20<y)
{vragi4Objects[i120].v4y+=(0.05f+0.1f*sqrt((float)primanka1))*lag;}
if(vragi4Objects[i120].v4y+20>y)
{vragi4Objects[i120].v4y-=(0.05f+0.1f*sqrt((float)primanka1))*lag;}
}

if(class2==1&&primanka2>0&&vragi4Objects[i120].v4x+23<=x2-16&&sqrt(((x2-16)-vragi4Objects[i120].v4x+23)*((x2-16)-vragi4Objects[i120].v4x+23)+
(vragi4Objects[i120].v4y+20-y2)*(vragi4Objects[i120].v4y+20-y2))<=(60+5*primanka2))
{
if(vragi4Objects[i120].v4y+20<y2)
{vragi4Objects[i120].v4y+=(0.05f+0.1f*sqrt((float)primanka2))*lag;}
if(vragi4Objects[i120].v4y+20>y2)
{vragi4Objects[i120].v4y-=(0.05f+0.1f*sqrt((float)primanka2))*lag;}
}



for (int i52=0;i52<=N_OBJECTS-1;i52++)//контакт с предметами
{
if((X-Objects[i52].x)>vragi4Objects[i120].v4x&&(X-Objects[i52].x)-vragi4Objects[i120].v4x<=200)//объект перед щами!!!
{

switch(Objects[i52].type)
{
case 0:
case 1:
case 2:
if(Objects[i52].y>=vragi4Objects[i120].v4y&&Objects[i52].y-vragi4Objects[i120].v4y<=50)//объект ниже
{
if(Objects[i52].pl==0)//если объект не плоский
{vragi4Objects[i120].v4y-=0.4f;}
vragi4Objects[i120].object_id=i52;}
if(Objects[i52].y<vragi4Objects[i120].v4y&&vragi4Objects[i120].v4y-Objects[i52].y<=35)//объект выше
{vragi4Objects[i120].v4y+=0.4f;}
break;

}

}//закрытие объект перед щами




if((X-Objects[i52].x)<vragi4Objects[i120].v4x&&vragi4Objects[i120].v4x-(X-Objects[i52].x)<=100)//назад на место
{
switch(Objects[i52].type)
{
case 0:
case 1:
case 2:
if(Objects[i52].y>=vragi4Objects[i120].v4y&&
Objects[i52].y-vragi4Objects[i120].v4y>=30&&Objects[i52].y-vragi4Objects[i120].v4y<=80)//объект ниже
{vragi4Objects[i120].v4y+=0.2f;}
if(Objects[i52].y<vragi4Objects[i120].v4y&&
vragi4Objects[i120].v4y-Objects[i52].y>=15&&vragi4Objects[i120].v4y-Objects[i52].y<=50)//объект выше
{vragi4Objects[i120].v4y-=0.2f;}
break;
}
}//закрытие возврата на место



}//закрытие контакта с предметами


}//закрытие скорости


 //если замочили - появляется заново
if(vragi4Objects[i120].ubit==1)
{
if(perez_akt==vragi4Objects[i120].timeout&&
((perez_akt_milli>=vragi4Objects[i120].timeout_milli&&vragi4Objects[i120].timeout_milli<900)||
(perez_akt_milli<vragi4Objects[i120].timeout_milli&&vragi4Objects[i120].timeout_milli>=900)))
{vragi4Objects[i120].ubit=0;	
vragi4Objects[i120].bezboshki=0;
vragi4Objects[i120].v4x=-50;
if(player2_aktive==0)
{if(DIFF!=0)
{vragi4Objects[i120].v4y=hge->Random_Float(250,750);}
if(DIFF==0)
{vragi4Objects[i120].v4y=hge->Random_Float(350,650);}}
if(player2_aktive==1)
{if(DIFF!=0)
{vragi4Objects[i120].v4y=hge->Random_Float(150,850);}
if(DIFF==0)
{vragi4Objects[i120].v4y=hge->Random_Float(250,750);}
}
vragi4Objects[i120].health=20;
vragi4Objects[i120].speed=hge->Random_Float(0.5f,0.6f);
vragi4Objects[i120].defence=defence_zayac;
vragi4Objects[i120].object_id=-1;
vragi4Objects[i120].wait=0;
vragi4Objects[i120].wait_time_sec=0;
vragi4Objects[i120].polet=0;
vragi4Objects[i120].energy=0;
vragi4Objects[i120].rasstX=0;
vragi4Objects[i120].rasstY=0;
vragi4Objects[i120].vzorvan=false;
}
}



if(vragi4Objects[i120].v4x>1200&&vragi4Objects[i120].ubit!=1) // если птенец забежал за экран
{LIVES--;
vragi4Objects[i120].bezboshki=0;
vragi4Objects[i120].v4x=-50;
if(player2_aktive==0)
{if(DIFF!=0)
{vragi4Objects[i120].v4y=hge->Random_Float(250,750);}
if(DIFF==0)
{vragi4Objects[i120].v4y=hge->Random_Float(350,650);}}
if(player2_aktive==1)
{if(DIFF!=0)
{vragi4Objects[i120].v4y=hge->Random_Float(150,850);}
if(DIFF==0)
{vragi4Objects[i120].v4y=hge->Random_Float(250,750);}}
vragi4Objects[i120].health=20;
vragi4Objects[i120].speed=hge->Random_Float(0.5f,0.6f);
vragi4Objects[i120].defence=defence_zayac;
vragi4Objects[i120].object_id=-1;
vragi4Objects[i120].wait=0;
vragi4Objects[i120].wait_time_sec=0;
vragi4Objects[i120].energy=0;
vragi4Objects[i120].rasstX=0;
vragi4Objects[i120].rasstY=0;
vragi4Objects[i120].vzorvan=false;
}


if((((py<vragi4Objects[i120].v4y+22&&py>vragi4Objects[i120].v4y&&px<=vragi4Objects[i120].v4x&&px>vragi4Objects[i120].v4x-600*lag)||
   (p1d1y<vragi4Objects[i120].v4y+22&&p1d1y>vragi4Objects[i120].v4y&&p1d1x<=vragi4Objects[i120].v4x&&p1d1x>vragi4Objects[i120].v4x-600*lag)||
   (p1d2y<vragi4Objects[i120].v4y+22&&p1d2y>vragi4Objects[i120].v4y&&p1d2x<=vragi4Objects[i120].v4x&&p1d2x>vragi4Objects[i120].v4x-600*lag)||
   (p1d3y<vragi4Objects[i120].v4y+22&&p1d3y>vragi4Objects[i120].v4y&&p1d3x<=vragi4Objects[i120].v4x&&p1d3x>vragi4Objects[i120].v4x-600*lag)||
   (p1d4y<vragi4Objects[i120].v4y+22&&p1d4y>vragi4Objects[i120].v4y&&p1d4x<=vragi4Objects[i120].v4x&&p1d4x>vragi4Objects[i120].v4x-600*lag))&&
  aktivatorp==1&&x-55>vragi4Objects[i120].v4x&&vragi4Objects[i120].ubit!=1)||
   (((p2y<vragi4Objects[i120].v4y+22&&p2y>vragi4Objects[i120].v4y&&p2x<=vragi4Objects[i120].v4x&&p2x>vragi4Objects[i120].v4x-600*lag)||
   (p2d1y<vragi4Objects[i120].v4y+22&&p2d1y>vragi4Objects[i120].v4y&&p2d1x<=vragi4Objects[i120].v4x&&p2d1x>vragi4Objects[i120].v4x-600*lag)||
   (p2d2y<vragi4Objects[i120].v4y+22&&p2d2y>vragi4Objects[i120].v4y&&p2d2x<=vragi4Objects[i120].v4x&&p2d2x>vragi4Objects[i120].v4x-600*lag)||
   (p2d3y<vragi4Objects[i120].v4y+22&&p2d3y>vragi4Objects[i120].v4y&&p2d3x<=vragi4Objects[i120].v4x&&p2d3x>vragi4Objects[i120].v4x-600*lag)||
   (p2d4y<vragi4Objects[i120].v4y+22&&p2d4y>vragi4Objects[i120].v4y&&p2d4x<=vragi4Objects[i120].v4x&&p2d4x>vragi4Objects[i120].v4x-600*lag))&&
  aktivatorp2==1&&x2-55>vragi4Objects[i120].v4x&&vragi4Objects[i120].ubit!=1))//просчёт урона
{


if(shot==0)
{
if(((py<vragi4Objects[i120].v4y+22&&py>vragi4Objects[i120].v4y&&px<=vragi4Objects[i120].v4x&&px>vragi4Objects[i120].v4x-600*lag)||
   (p1d1y<vragi4Objects[i120].v4y+22&&p1d1y>vragi4Objects[i120].v4y&&p1d1x<=vragi4Objects[i120].v4x&&p1d1x>vragi4Objects[i120].v4x-600*lag)||
   (p1d2y<vragi4Objects[i120].v4y+22&&p1d2y>vragi4Objects[i120].v4y&&p1d2x<=vragi4Objects[i120].v4x&&p1d2x>vragi4Objects[i120].v4x-600*lag)||
   (p1d3y<vragi4Objects[i120].v4y+22&&p1d3y>vragi4Objects[i120].v4y&&p1d3x<=vragi4Objects[i120].v4x&&p1d3x>vragi4Objects[i120].v4x-600*lag)||
   (p1d4y<vragi4Objects[i120].v4y+22&&p1d4y>vragi4Objects[i120].v4y&&p1d4x<=vragi4Objects[i120].v4x&&p1d4x>vragi4Objects[i120].v4x-600*lag))&&
  aktivatorp==1&&x-55>vragi4Objects[i120].v4x)	
{vragi4Objects[i120].killed_by=1;}//попал игрок 1
if(((p2y<vragi4Objects[i120].v4y+22&&p2y>vragi4Objects[i120].v4y&&p2x<=vragi4Objects[i120].v4x&&p2x>vragi4Objects[i120].v4x-600*lag)||
   (p2d1y<vragi4Objects[i120].v4y+22&&p2d1y>vragi4Objects[i120].v4y&&p2d1x<=vragi4Objects[i120].v4x&&p2d1x>vragi4Objects[i120].v4x-600*lag)||
   (p2d2y<vragi4Objects[i120].v4y+22&&p2d2y>vragi4Objects[i120].v4y&&p2d2x<=vragi4Objects[i120].v4x&&p2d2x>vragi4Objects[i120].v4x-600*lag)||
   (p2d3y<vragi4Objects[i120].v4y+22&&p2d3y>vragi4Objects[i120].v4y&&p2d3x<=vragi4Objects[i120].v4x&&p2d3x>vragi4Objects[i120].v4x-600*lag)||
   (p2d4y<vragi4Objects[i120].v4y+22&&p2d4y>vragi4Objects[i120].v4y&&p2d4x<=vragi4Objects[i120].v4x&&p2d4x>vragi4Objects[i120].v4x-600*lag))&&
  aktivatorp2==1&&x2-55>vragi4Objects[i120].v4x)
{vragi4Objects[i120].killed_by=2;}//попал игрок 2











if(((py<vragi4Objects[i120].v4y+22&&py>vragi4Objects[i120].v4y)||
   (p1d1y<vragi4Objects[i120].v4y+22&&p1d1y>vragi4Objects[i120].v4y)||
   (p1d2y<vragi4Objects[i120].v4y+22&&p1d2y>vragi4Objects[i120].v4y)||
   (p1d3y<vragi4Objects[i120].v4y+22&&p1d3y>vragi4Objects[i120].v4y)||
   (p1d4y<vragi4Objects[i120].v4y+22&&p1d4y>vragi4Objects[i120].v4y))||
   ((p2y<vragi4Objects[i120].v4y+22&&p2y>vragi4Objects[i120].v4y)||
   (p2d1y<vragi4Objects[i120].v4y+22&&p2d1y>vragi4Objects[i120].v4y)||
   (p2d2y<vragi4Objects[i120].v4y+22&&p2d2y>vragi4Objects[i120].v4y)||
   (p2d3y<vragi4Objects[i120].v4y+22&&p2d3y>vragi4Objects[i120].v4y)||
   (p2d4y<vragi4Objects[i120].v4y+22&&p2d4y>vragi4Objects[i120].v4y)))//ОБЫЧНОЕ ПОПАДАНИЕ	
{

if(vragi4Objects[i120].killed_by==1)	
{

if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi4Objects[i120].defence>=5||
   damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi4Objects[i120].defence>=5)
{
if(LVL1%2==0)
{vragi4Objects[i120].health-=damage[N_WEAPON1]+LVL1/2*attack1-vragi4Objects[i120].defence;}
if(LVL1%2==1)
{vragi4Objects[i120].health-=damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi4Objects[i120].defence;}
}

if(damage[N_WEAPON1]+LVL1/2*attack1-vragi4Objects[i120].defence<5||
 damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi4Objects[i120].defence<5)
{vragi4Objects[i120].health-=5;}
}//RPG

if(RPGMOD==false)
{vragi4Objects[i120].health-=damage[N_WEAPON1];}


}//урон от оружия игрока 1

if(vragi4Objects[i120].killed_by==2)
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi4Objects[i120].defence>=5||
   damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi4Objects[i120].defence>=5)
{
if(LVL2%2==0)
{vragi4Objects[i120].health-=damage[N_WEAPON2]+LVL2/2*attack2-vragi4Objects[i120].defence;}
if(LVL2%2==1)
{vragi4Objects[i120].health-=damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi4Objects[i120].defence;}
}

if(damage[N_WEAPON2]+LVL2/2*attack2-vragi4Objects[i120].defence<5||
   damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi4Objects[i120].defence<5)
{vragi4Objects[i120].health-=5;}
}//RPG

if(RPGMOD==false)
{vragi4Objects[i120].health-=damage[N_WEAPON2];}

}//урон от оружия игрока 2

hge->Effect_PlayEx(shot1,volume*8/10,0,0);
}//ЗАКРЫТИЕ ПОПАДАНИЯ

if(((py<=vragi4Objects[i120].v4y+11&&py>vragi4Objects[i120].v4y)||
   (p1d1y<=vragi4Objects[i120].v4y+11&&p1d1y>vragi4Objects[i120].v4y)||
   (p1d2y<=vragi4Objects[i120].v4y+11&&p1d2y>vragi4Objects[i120].v4y)||
   (p1d3y<=vragi4Objects[i120].v4y+11&&p1d3y>vragi4Objects[i120].v4y)||
   (p1d4y<=vragi4Objects[i120].v4y+11&&p1d4y>vragi4Objects[i120].v4y))||
   ((p2y<=vragi4Objects[i120].v4y+11&&p2y>vragi4Objects[i120].v4y)||
   (p2d1y<=vragi4Objects[i120].v4y+11&&p2d1y>vragi4Objects[i120].v4y)||
   (p2d2y<=vragi4Objects[i120].v4y+11&&p2d2y>vragi4Objects[i120].v4y)||
   (p2d3y<=vragi4Objects[i120].v4y+11&&p2d3y>vragi4Objects[i120].v4y)||
   (p2d4y<=vragi4Objects[i120].v4y+11&&p2d4y>vragi4Objects[i120].v4y)))//ХЭДШОТ!!!
{

if(vragi4Objects[i120].killed_by==1)	
{vragi4Objects[i120].health-=damage[N_WEAPON1];
points1+=25;}//урон от оружия игрока 1

if(vragi4Objects[i120].killed_by==2)
{vragi4Objects[i120].health-=damage[N_WEAPON2];
points2+=25;}//урон от оружия игрока 2

headshotPan=-75+vragi4Objects[i120].v4x/9;
headshot();

if(vragi4Objects[i120].health<-40)//отрывание бошки
{
vragi4Objects[i120].bezboshki=1;
if(vragi4Objects[i120].killed_by==1)
{points1+=25;}
if(vragi4Objects[i120].killed_by==2)
{points2+=25;}


}//закрытие отрывания бошки


}//ХЭДШОТ ЗАКОНЧИЛСЯ


if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!



shot=1;


if(vragi4Objects[i120].killed_by==1)
{
if(N_WEAPON1==1||N_WEAPON1==2||N_WEAPON1==4||N_WEAPON1==6||N_WEAPON1==9)//если это ПМ или ПП19 или ТТ или МАС или Glock то патрон слабый
{aktivatorp=0;
oboima-=1;}


if(N_WEAPON1==7)
{

if(ppp==2)
{p1d1y=y-9;
p1d1x=x-24;}
if(ppp==3)
{p1d2y=y-9;
p1d2x=x-24;}
if(ppp==4)
{p1d3y=y-9;
p1d3x=x-24;}
if(ppp==5)
{p1d4y=y-9;
p1d4x=x-24;}
}


if(N_WEAPON1==0||N_WEAPON1==3||N_WEAPON1==5||N_WEAPON1==8)// если это АК то косит всех подряд
{shot=0;}

}

if(vragi4Objects[i120].killed_by==2)
{
if(N_WEAPON2==1||N_WEAPON2==2||N_WEAPON2==4||N_WEAPON2==6||N_WEAPON2==9)//если это ПМ или ПП19 или ТТ или МАС или Glock то патрон слабый
{aktivatorp2=0;
oboima2-=1;}

if(N_WEAPON2==7)
{
if(ppp==2)
{p2d1y=y2-9;
p2d1x=x2-24;}
if(ppp==3)
{p2d2y=y2-9;
p2d2x=x2-24;}
if(ppp==4)
{p2d3y=y2-9;
p2d3x=x2-24;}
if(ppp==5)
{p2d4y=y2-9;
p2d4x=x2-24;}
}


if(N_WEAPON2==0||N_WEAPON2==3||N_WEAPON2==5||N_WEAPON2==8)// если это АК то косит всех подряд
{shot=0;}

}




}//if shot==0





}//закрытие просчёта урона волку

//холодное оружие
if((katana1_anime->IsPlaying()==true&&katana1_anime->GetFrame()==2&&vragi4Objects[i120].health>0&&x-55>vragi4Objects[i120].v4x&&
vragi4Objects[i120].v4x+22>x-95&&y<vragi4Objects[i120].v4y+22&&y>vragi4Objects[i120].v4y)||
(katana2_anime->IsPlaying()==true&&katana2_anime->GetFrame()==2&&vragi4Objects[i120].health>0&&x2-55>vragi4Objects[i120].v4x&&
vragi4Objects[i120].v4x+22>x2-95&&y2<vragi4Objects[i120].v4y+22&&y2>vragi4Objects[i120].v4y))
{

if(katana1_anime->IsPlaying()==true&&katana1_anime->GetFrame()==2&&vragi4Objects[i120].health>0&&x-55>vragi4Objects[i120].v4x&&
vragi4Objects[i120].v4x+22>x-95&&y<vragi4Objects[i120].v4y+22&&y>vragi4Objects[i120].v4y)
{vragi4Objects[i120].killed_by=1;}
if(katana2_anime->IsPlaying()==true&&katana2_anime->GetFrame()==2&&vragi4Objects[i120].health>0&&x2-55>vragi4Objects[i120].v4x&&
vragi4Objects[i120].v4x+22>x2-95&&y2<vragi4Objects[i120].v4y+22&&y2>vragi4Objects[i120].v4y)
{vragi4Objects[i120].killed_by=2;}


if((y<=vragi4Objects[i120].v4y+11&&y>vragi4Objects[i120].v4y)||
(y2<=vragi4Objects[i120].v4y+11&&y2>vragi4Objects[i120].v4y))//ХЭДШОТ!!!
{

if(vragi4Objects[i120].killed_by==1)	
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi4Objects[i120].defence>=5||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi4Objects[i120].defence>=5)
{

if(CLASSMOD==true&&class1==1)
{
if(LVL1%2==0)
{vragi4Objects[i120].health-=(damage[N_WEAPON1]+LVL1/2*attack1)*1.2f-vragi4Objects[i120].defence;}
if(LVL1%2==1)
{vragi4Objects[i120].health-=(damage[N_WEAPON1]+(LVL1-1)/2*attack1)*1.2f-vragi4Objects[i120].defence;}
}

if(CLASSMOD==false||class1!=1)
{
if(LVL1%2==0)
{vragi4Objects[i120].health-=damage[N_WEAPON1]+LVL1/2*attack1-vragi4Objects[i120].defence;}
if(LVL1%2==1)
{vragi4Objects[i120].health-=damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi4Objects[i120].defence;}
}

}
//гарантированный урон
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi4Objects[i120].defence<5||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi4Objects[i120].defence<5)
{vragi4Objects[i120].health-=5;}
}//RPG

if(RPGMOD==false)
{vragi4Objects[i120].health-=damage[N_WEAPON1];}
if(RPGMOD==false&&CLASSMOD==true&&class1==1)
{vragi4Objects[i120].health-=damage[N_WEAPON1]*1.2f;}

points1+=25;}//урон от оружия игрока 1


if(vragi4Objects[i120].killed_by==2)	
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi4Objects[i120].defence>=5||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi4Objects[i120].defence>=5)
{

if(CLASSMOD==true&&class2==1)
{
if(LVL2%2==0)
{vragi4Objects[i120].health-=(damage[N_WEAPON2]+LVL2/2*attack2)*1.2f-vragi4Objects[i120].defence;}
if(LVL2%2==1)
{vragi4Objects[i120].health-=(damage[N_WEAPON2]+(LVL2-1)/2*attack2)*1.2f-vragi4Objects[i120].defence;}
}

if(CLASSMOD==false||class2!=1)
{
if(LVL2%2==0)
{vragi4Objects[i120].health-=damage[N_WEAPON2]+LVL2/2*attack2-vragi4Objects[i120].defence;}
if(LVL2%2==1)
{vragi4Objects[i120].health-=damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi4Objects[i120].defence;}
}

}
//гарантированный урон
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi4Objects[i120].defence<5||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi4Objects[i120].defence<5)
{vragi4Objects[i120].health-=5;}
}//RPG

if(RPGMOD==false&&CLASSMOD==false)
{vragi4Objects[i120].health-=damage[N_WEAPON2];}
if(RPGMOD==false&&CLASSMOD==true&&class2==1)
{vragi4Objects[i120].health-=damage[N_WEAPON2]*1.2f;}

points2+=25;}//урон от оружия игрока 2


headshotPan=-75+(vragi4Objects[i120].v4x+120)/9;
headshot();




}//ХЭДШОТ ЗАКОНЧИЛСЯ



if(vragi4Objects[i120].killed_by==1)
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi4Objects[i120].defence>=10||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi4Objects[i120].defence>=10)
{

if(CLASSMOD==true&&class1==1)
{
if(LVL1%2==0)
{vragi4Objects[i120].health-=(damage[N_WEAPON1]+LVL1/2*attack1)*1.2f-vragi4Objects[i120].defence;}
if(LVL1%2==1)
{vragi4Objects[i120].health-=(damage[N_WEAPON1]+(LVL1-1)/2*attack1)*1.2f-vragi4Objects[i120].defence;}
}


if(CLASSMOD==false||class1!=1)
{
if(LVL1%2==0)
{vragi4Objects[i120].health-=damage[N_WEAPON1]+LVL1/2*attack1-vragi4Objects[i120].defence;}
if(LVL1%2==1)
{vragi4Objects[i120].health-=damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi4Objects[i120].defence;}
}


}
//гарантированный урон
if(damage[N_WEAPON1]+LVL1/2*attack1-vragi4Objects[i120].defence<10||
damage[N_WEAPON1]+(LVL1-1)/2*attack1-vragi4Objects[i120].defence<10)
{vragi4Objects[i120].health-=10;}
}//RPG
if(RPGMOD==false)
{vragi4Objects[i120].health-=damage[N_WEAPON1];}

krovyakObjects[N_BLOOD].y1=y-10; //КРОВЯК (вперед)
krovyakObjects[N_BLOOD].y2=y;

}

if(vragi4Objects[i120].killed_by==2)
{
if(RPGMOD==true)//RPG
{
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi4Objects[i120].defence>=10||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi4Objects[i120].defence>=10)
{

if(CLASSMOD==true&&class2==1)
{
if(LVL2%2==0)
{vragi4Objects[i120].health-=(damage[N_WEAPON2]+LVL2/2*attack2)*1.2f-vragi4Objects[i120].defence;}
if(LVL2%2==1)
{vragi4Objects[i120].health-=(damage[N_WEAPON2]+(LVL2-1)/2*attack2)*1.2f-vragi4Objects[i120].defence;}
}

if(CLASSMOD==false&&class2!=1)
{
if(LVL2%2==0)
{vragi4Objects[i120].health-=damage[N_WEAPON2]+LVL2/2*attack2-vragi4Objects[i120].defence;}
if(LVL2%2==1)
{vragi4Objects[i120].health-=damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi4Objects[i120].defence;}
}

}
//гарантированный урон
if(damage[N_WEAPON2]+LVL2/2*attack2-vragi4Objects[i120].defence<10||
damage[N_WEAPON2]+(LVL2-1)/2*attack2-vragi4Objects[i120].defence<10)
{vragi4Objects[i120].health-=10;}
}//RPG
if(RPGMOD==false)
{vragi4Objects[i120].health-=damage[N_WEAPON2];}

krovyakObjects[N_BLOOD].y1=y2-10; //КРОВЯК (вперед)
krovyakObjects[N_BLOOD].y2=y2;

}

krovyakObjects[N_BLOOD].seed=hge->Random_Int(101,103);
krovyakObjects[N_BLOOD].vrag=2;
krovyakObjects[N_BLOOD].x2=x-95+10;
krovyakObjects[N_BLOOD].x1=x-95+35;
krovyakObjects[N_BLOOD].xstart=x-95+10;
krovyakObjects[N_BLOOD].niz=vragi4Objects[i120].v4y+60;
krovyakObjects[N_BLOOD].blood_time=GetTime();
krovyakObjects[N_BLOOD].blood_time_sec=perez_akt;
krovyakObjects[N_BLOOD].akt=1;
krovyakObjects[N_BLOOD].faza=1;
N_BLOOD++;
if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!

hge->Effect_PlayEx(shot1,volume*8/10,0,0);



}//холодное оружие




if(vragi4Objects[i120].health<=0&&vragi4Objects[i120].ubit==0)//убийство птенца
{
ptenec->Stop();
hge->Effect_PlayEx(ptenec_death1,volume*9/10,headshotPan,0);
vragi4Objects[i120].ubit=1;
vragi4Objects[i120].timeout_milli=GetTime();
switch(DIFF)
{
case 0:
if(perez_akt<50)
{vragi4Objects[i120].timeout=perez_akt+10;}
if(perez_akt>=51)
{vragi4Objects[i120].timeout=perez_akt-50;}
break;
case 1:
if(perez_akt<45)
{vragi4Objects[i120].timeout=perez_akt+15;}
if(perez_akt>=46)
{vragi4Objects[i120].timeout=perez_akt-45;}
break;
case 2:
if(perez_akt<40)
{vragi4Objects[i120].timeout=perez_akt+20;}
if(perez_akt>=41)
{vragi4Objects[i120].timeout=perez_akt-40;}
break;
}






//БОНУС?!
bonus_shans();

if(vragi4Objects[i120].killed_by==1)
{
if(bonus>=371&&bonus<=379+5*luck1)
{
bonusiObjects[N_BONUS].x1=vragi4Objects[i120].v4x+5;
bonusiObjects[N_BONUS].y1=vragi4Objects[i120].v4y+5;
bonusiObjects[N_BONUS].x1_s=vragi4Objects[i120].v4x+5;
bonusiObjects[N_BONUS].x1_X=X;
bonusiObjects[N_BONUS].x2=vragi4Objects[i120].v4x+35;
bonusiObjects[N_BONUS].y2=vragi4Objects[i120].v4y+35;
bonusiObjects[N_BONUS].x2_s=vragi4Objects[i120].v4x+35;
bonusiObjects[N_BONUS].x2_X=X;
bonusiObjects[N_BONUS].appear_time_milli=GetTime();
bonusiObjects[N_BONUS].appear_time=perez_akt;
bonusiObjects[N_BONUS].type=0;
bonusiObjects[N_BONUS].akt=1;
bonusiObjects[N_BONUS].spin=0;
bonusiObjects[N_BONUS].visible=true;
bonusiObjects[N_BONUS].mig_akt=0;

N_BONUS++;
if(N_BONUS>=MAX_BONUS-1)
{N_BONUS=0;}

}
}//if(vragi4Objects[i120].killed_by==1)

if(vragi4Objects[i120].killed_by==2)
{
if(bonus>=371&&bonus<=379+5*luck2)
{
bonusiObjects[N_BONUS].x1=vragi4Objects[i120].v4x+5;
bonusiObjects[N_BONUS].y1=vragi4Objects[i120].v4y+5;
bonusiObjects[N_BONUS].x1_s=vragi4Objects[i120].v4x+5;
bonusiObjects[N_BONUS].x1_X=X;
bonusiObjects[N_BONUS].x2=vragi4Objects[i120].v4x+35;
bonusiObjects[N_BONUS].y2=vragi4Objects[i120].v4y+35;
bonusiObjects[N_BONUS].x2_s=vragi4Objects[i120].v4x+35;
bonusiObjects[N_BONUS].x2_X=X;
bonusiObjects[N_BONUS].appear_time_milli=GetTime();
bonusiObjects[N_BONUS].appear_time=perez_akt;
bonusiObjects[N_BONUS].type=0;
bonusiObjects[N_BONUS].akt=1;
bonusiObjects[N_BONUS].spin=0;
bonusiObjects[N_BONUS].visible=true;
bonusiObjects[N_BONUS].mig_akt=0;

N_BONUS++;
if(N_BONUS>=MAX_BONUS-1)
{N_BONUS=0;}

}
}//if(vragi4Objects[i120].killed_by==2)


if(vragi4Objects[i120].health>=-100)//ПРОСТОЕ УБИЙСТВО
{

if(vragi4Objects[i120].killed_by==1)
{kills++;

//статистика
ubijstva[N_KILLS].player=1;
ubijstva[N_KILLS].vrag=4;
ubijstva[N_KILLS].weapon=N_WEAPON1;
ubijstva[N_KILLS].bezuh=false;
ubijstva[N_KILLS].bezboshki=false;
ubijstva[N_KILLS].headshot=false;
ubijstva[N_KILLS].vschiii=false;
N_KILLS++;
if(N_KILLS>=MAX_KILLS-1)
{N_KILLS=0;}
//статистика

points1+=20;
opit1+=(20+vragi4Objects[i120].defence*vragi4Objects[i120].defence/LVL1)*w_opit_zayac[N_WEAPON1]*(1+0.25f*umnik1)/daun1;

}

if(vragi4Objects[i120].killed_by==2)
{kills2++;

//статистика
ubijstva[N_KILLS].player=2;
ubijstva[N_KILLS].vrag=4;
ubijstva[N_KILLS].weapon=N_WEAPON2;
ubijstva[N_KILLS].bezuh=false;
ubijstva[N_KILLS].bezboshki=false;
ubijstva[N_KILLS].headshot=false;
ubijstva[N_KILLS].vschiii=false;
N_KILLS++;
if(N_KILLS>=MAX_KILLS-1)
{N_KILLS=0;}
//статистика

points2+=20;
opit2+=(20+vragi4Objects[i120].defence*vragi4Objects[i120].defence/LVL2)*w_opit_zayac[N_WEAPON2]*(1+0.25f*umnik2)/daun2;
}

trupsObjects[N_TRUPS].killtime=GetTime();//лужа кровяка
trupsObjects[N_TRUPS].killtime_sec=perez_akt;
trupsObjects[N_TRUPS].posX=vragi4Objects[i120].v4x+5;
trupsObjects[N_TRUPS].posY=vragi4Objects[i120].v4y+15;
trupsObjects[N_TRUPS].posX_s=vragi4Objects[i120].v4x+5;
trupsObjects[N_TRUPS].posX_X=X;
trupsObjects[N_TRUPS].vrag=4;
trupsObjects[N_TRUPS].scaleX=0.1f;
trupsObjects[N_TRUPS].scaleY=0;
trupsObjects[N_TRUPS].aktiv=1;
trupsObjects[N_TRUPS].type=9;

N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}



//ВСПЛЕСК ДРИСНИ (БОШКА ПТЕНЦА)
krovyakObjects[N_BLOOD].seed=1002;
krovyakObjects[N_BLOOD].x1=vragi4Objects[i120].v4x-5;
krovyakObjects[N_BLOOD].x2=vragi4Objects[i120].v4x-5;
krovyakObjects[N_BLOOD].xstart=1;
krovyakObjects[N_BLOOD].y1=vragi4Objects[i120].v4y-10;
krovyakObjects[N_BLOOD].y2=vragi4Objects[i120].v4y-10;
krovyakObjects[N_BLOOD].blood_time=GetTime();
krovyakObjects[N_BLOOD].blood_time_sec=perez_akt;
krovyakObjects[N_BLOOD].akt=1;
krovyakObjects[N_BLOOD].faza=1;
N_BLOOD++;
if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!


trupsObjects[N_TRUPS].type=30;
trupsObjects[N_TRUPS].killtime=GetTime();
trupsObjects[N_TRUPS].killtime_sec=perez_akt;
trupsObjects[N_TRUPS].frame=1;
trupsObjects[N_TRUPS].frame_akt=1;
trupsObjects[N_TRUPS].posX=vragi4Objects[i120].v4x;
trupsObjects[N_TRUPS].posY=vragi4Objects[i120].v4y;
trupsObjects[N_TRUPS].posX_s=vragi4Objects[i120].v4x;
trupsObjects[N_TRUPS].posX_X=X;


N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}


vragi4Objects[i120].polet=1;
vragi4Objects[i120].krug=0;
vragi4Objects[i120].rx=vragi4Objects[i120].v4x+hge->Random_Int(-400,400);
vragi4Objects[i120].ry=vragi4Objects[i120].v4y+hge->Random_Int(-400,-200);
vragi4Objects[i120].r=hge->Random_Int(75,150);
//vragi4Objects[i120].speedX=hge->Random_Float(2,2.5f);
vragi4Objects[i120].speedY=hge->Random_Float(2,2.5f);
vragi4Objects[i120].up=true;
vragi4Objects[i120].kruzhit=false;
vragi4Objects[i120].zahod=-1;
if(vragi4Objects[i120].rx>=vragi4Objects[i120].v4x)
{vragi4Objects[i120].chetvert=1;
vragi4Objects[i120].chetvert_n=1;}
if(vragi4Objects[i120].rx<vragi4Objects[i120].v4x)
{vragi4Objects[i120].chetvert=-1;
vragi4Objects[i120].chetvert_n=-1;}

}//ПРОСТОЕ УБИЙСТВО





if(vragi4Objects[i120].health<-100)//РАЗРЫВ В ЩИ
{

//ВСПЛЕСК ДРИСНИ
krovyakObjects[N_BLOOD].seed=1001;
krovyakObjects[N_BLOOD].x1=vragi4Objects[i120].v4x+10;
krovyakObjects[N_BLOOD].x2=vragi4Objects[i120].v4x+10;
krovyakObjects[N_BLOOD].xstart=hge->Random_Float(0.8f,1);
krovyakObjects[N_BLOOD].y1=vragi4Objects[i120].v4y+5;
krovyakObjects[N_BLOOD].y2=vragi4Objects[i120].v4y+5;
krovyakObjects[N_BLOOD].blood_time=GetTime();
krovyakObjects[N_BLOOD].blood_time_sec=perez_akt;
krovyakObjects[N_BLOOD].akt=1;
krovyakObjects[N_BLOOD].faza=1;
N_BLOOD++;
if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!


myasorazrivPan=-75+vragi4Objects[i120].v4x/9;
myasko_razriv();


//крупное мясо
for (int i131=1;i131<=10;i131++)
{
myasko[N_MYASO].seed=hge->Random_Int(1,5);
myasko[N_MYASO].x1=vragi4Objects[i120].v4x+hge->Random_Float(0,10);
myasko[N_MYASO].y1=vragi4Objects[i120].v4y+hge->Random_Float(-5,5);
myasko[N_MYASO].niz=vragi4Objects[i120].v4y+hge->Random_Float(15,50);
myasko[N_MYASO].xstart=myasko[N_MYASO].x1;
myasko[N_MYASO].type=1;
myasko[N_MYASO].myaso_time_sec=perez_akt;
myasko[N_MYASO].myaso_time=GetTime();
myasko[N_MYASO].scaleX=hge->Random_Float(0.2f,0.3f);
myasko[N_MYASO].gradus=hge->Random_Float(0,1);
myasko[N_MYASO].speedX=hge->Random_Float(0.8f,1.6f);
myasko[N_MYASO].akt=1;
myasko[N_MYASO].bzdik=0;
myasko[N_MYASO].energy=0;

if(vragi4Objects[i120].vzorvan==true)
{myasko[N_MYASO].energy=vragi4Objects[i120].energy;
//передача энергии(выше) и её распределение
//если не прям под щами
if(myasko[N_MYASO].energy<=0.9f)
{
if(vragi4Objects[i120].chetvert==1)
{myasko[N_MYASO].speedX=hge->Random_Float(1,3)*myasko[N_MYASO].energy*(vragi4Objects[i120].rasstX/(vragi4Objects[i120].rasstX+vragi4Objects[i120].rasstY));
myasko[N_MYASO].speedY=-hge->Random_Float(1,3)*myasko[N_MYASO].energy*(vragi4Objects[i120].rasstY/(vragi4Objects[i120].rasstX+vragi4Objects[i120].rasstY));
myasko[N_MYASO].niz=vragi4Objects[i120].v4y+20*myasko[N_MYASO].speedY;}
if(vragi4Objects[i120].chetvert==2)
{myasko[N_MYASO].speedX=hge->Random_Float(1,3)*myasko[N_MYASO].energy*(vragi4Objects[i120].rasstX/(vragi4Objects[i120].rasstX+vragi4Objects[i120].rasstY));
myasko[N_MYASO].speedY=hge->Random_Float(1,3)*myasko[N_MYASO].energy*(vragi4Objects[i120].rasstY/(vragi4Objects[i120].rasstX+vragi4Objects[i120].rasstY));
myasko[N_MYASO].niz=vragi4Objects[i120].v4y-20*myasko[N_MYASO].speedY;}
if(vragi4Objects[i120].chetvert==3)
{myasko[N_MYASO].speedX=-1*hge->Random_Float(1,3)*myasko[N_MYASO].energy*(vragi4Objects[i120].rasstX/(vragi4Objects[i120].rasstX+vragi4Objects[i120].rasstY));
myasko[N_MYASO].speedY=hge->Random_Float(1,3)*myasko[N_MYASO].energy*(vragi4Objects[i120].rasstY/(vragi4Objects[i120].rasstX+vragi4Objects[i120].rasstY));
myasko[N_MYASO].niz=vragi4Objects[i120].v4y-20*myasko[N_MYASO].speedY;}
if(vragi4Objects[i120].chetvert==4)
{myasko[N_MYASO].speedX=-1*hge->Random_Float(1,3)*myasko[N_MYASO].energy*(vragi4Objects[i120].rasstX/(vragi4Objects[i120].rasstX+vragi4Objects[i120].rasstY));
myasko[N_MYASO].speedY=-hge->Random_Float(1,3)*myasko[N_MYASO].energy*(vragi4Objects[i120].rasstY/(vragi4Objects[i120].rasstX+vragi4Objects[i120].rasstY));
myasko[N_MYASO].niz=vragi4Objects[i120].v4y+20*myasko[N_MYASO].speedY;}
}//если не прям под щами

//если прям под щами
if(myasko[N_MYASO].energy>0.9f)
{
myasko[N_MYASO].speedY=-hge->Random_Float(5,8)*myasko[N_MYASO].energy;
myasko[N_MYASO].speedX=hge->Random_Float(-1,1)*myasko[N_MYASO].energy;
myasko[N_MYASO].niz=vragi4Objects[i120].v4y+hge->Random_Float(20,60)*myasko[N_MYASO].energy;

}//если прям под щами

}//закрытие взорванного мяса

N_MYASO++;
if(N_MYASO>=MAX_MYASO-1)
{N_MYASO=0;}

}
//крупное мясо


if(vragi4Objects[i120].killed_by==1)
{kills++;

//статистика
ubijstva[N_KILLS].player=1;
ubijstva[N_KILLS].vrag=4;
ubijstva[N_KILLS].weapon=N_WEAPON1;
ubijstva[N_KILLS].bezuh=false;
ubijstva[N_KILLS].bezboshki=false;
ubijstva[N_KILLS].headshot=false;
ubijstva[N_KILLS].vschiii=true;
N_KILLS++;
if(N_KILLS>=MAX_KILLS-1)
{N_KILLS=0;}
//статистика

points1+=30;
opit1+=(30+vragi4Objects[i120].defence*vragi4Objects[i120].defence/LVL1)*w_opit_zayac[N_WEAPON1]*(1+0.25f*umnik1)/daun1;

}

if(vragi4Objects[i120].killed_by==2)
{kills2++;

//статистика
ubijstva[N_KILLS].player=2;
ubijstva[N_KILLS].vrag=4;
ubijstva[N_KILLS].weapon=N_WEAPON2;
ubijstva[N_KILLS].bezuh=false;
ubijstva[N_KILLS].bezboshki=false;
ubijstva[N_KILLS].headshot=false;
ubijstva[N_KILLS].vschiii=true;
N_KILLS++;
if(N_KILLS>=MAX_KILLS-1)
{N_KILLS=0;}
//статистика

points2+=30;
opit2+=(30+vragi4Objects[i120].defence*vragi4Objects[i120].defence/LVL2)*w_opit_zayac[N_WEAPON2]*(1+0.25f*umnik2)/daun2;
}


}//РАЗРЫВ В ЩИ



}//закрытие убийства птенца


if(vragi4Objects[i120].polet==1)//polet
{

//летим к радиусу
if(sqrt((vragi4Objects[i120].v4y-vragi4Objects[i120].ry)*(vragi4Objects[i120].v4y-vragi4Objects[i120].ry)+
   (vragi4Objects[i120].v4x-vragi4Objects[i120].rx)*(vragi4Objects[i120].v4x-vragi4Objects[i120].rx))>=vragi4Objects[i120].r&&
  vragi4Objects[i120].kruzhit==false)
{
vragi4Objects[i120].v4y-=vragi4Objects[i120].speedY*lag;
if(vragi4Objects[i120].v4x>=vragi4Objects[i120].rx)
{vragi4Objects[i120].v4x-=vragi4Objects[i120].speedY*(vragi4Objects[i120].v4x-vragi4Objects[i120].rx)/(vragi4Objects[i120].v4y-vragi4Objects[i120].ry)*lag;}
if(vragi4Objects[i120].v4x<vragi4Objects[i120].rx)
{vragi4Objects[i120].v4x+=vragi4Objects[i120].speedY*(vragi4Objects[i120].rx-vragi4Objects[i120].v4x)/(vragi4Objects[i120].v4y-vragi4Objects[i120].ry)*lag;}



if(sqrt((vragi4Objects[i120].v4y-vragi4Objects[i120].ry)*(vragi4Objects[i120].v4y-vragi4Objects[i120].ry)+
(vragi4Objects[i120].v4x-vragi4Objects[i120].rx)*(vragi4Objects[i120].v4x-vragi4Objects[i120].rx))<=vragi4Objects[i120].r)
{vragi4Objects[i120].kruzhit=true;
if(vragi4Objects[i120].krug==0)
{vragi4Objects[i120].gradus=0;
vragi4Objects[i120].gradusNext=M_PI-M_PI_4;}
}

}
//прилетели к радиусу


//летим по кругу
if(vragi4Objects[i120].kruzhit==true)
{

if(vragi4Objects[i120].chetvert_n==1)
{vragi4Objects[i120].gradus-=M_PI_4/(42+(150/vragi4Objects[i120].r)*(150/vragi4Objects[i120].r))*(150/vragi4Objects[i120].r)*lag;}
if(vragi4Objects[i120].chetvert_n==-1)
{vragi4Objects[i120].gradus+=M_PI_4/(42+(150/vragi4Objects[i120].r)*(150/vragi4Objects[i120].r))*(150/vragi4Objects[i120].r)*lag;}

if(vragi4Objects[i120].zahod==-1)//заходим снизу 
{


if(vragi4Objects[i120].up==true)//летим вверх
{

//середина
if(vragi4Objects[i120].v4y>=(vragi4Objects[i120].ry-vragi4Objects[i120].r/2)&&
   vragi4Objects[i120].v4y<=(vragi4Objects[i120].ry+vragi4Objects[i120].r/2))	
{vragi4Objects[i120].v4y-=vragi4Objects[i120].speedY*lag;
if(vragi4Objects[i120].chetvert==1)//против часовой (справа)
{vragi4Objects[i120].v4x=sqrt(vragi4Objects[i120].r*vragi4Objects[i120].r-(vragi4Objects[i120].v4y-vragi4Objects[i120].ry)*(vragi4Objects[i120].v4y-vragi4Objects[i120].ry))+vragi4Objects[i120].rx;}
if(vragi4Objects[i120].chetvert==-1)//по часовой (слева)
{vragi4Objects[i120].v4x=vragi4Objects[i120].rx-sqrt(vragi4Objects[i120].r*vragi4Objects[i120].r-(vragi4Objects[i120].v4y-vragi4Objects[i120].ry)*(vragi4Objects[i120].v4y-vragi4Objects[i120].ry));}
}


//по краям
if(vragi4Objects[i120].v4y<=(vragi4Objects[i120].ry-vragi4Objects[i120].r/2)||
   vragi4Objects[i120].v4y>=(vragi4Objects[i120].ry+vragi4Objects[i120].r/2))	
{
if((vragi4Objects[i120].chetvert==-1&&vragi4Objects[i120].v4y<=(vragi4Objects[i120].ry-vragi4Objects[i120].r/2))||
(vragi4Objects[i120].chetvert==1&&vragi4Objects[i120].v4y>=(vragi4Objects[i120].ry+vragi4Objects[i120].r/2)))
{vragi4Objects[i120].v4x+=vragi4Objects[i120].speedY*lag;}
if((vragi4Objects[i120].chetvert==-1&&vragi4Objects[i120].v4y>=(vragi4Objects[i120].ry+vragi4Objects[i120].r/2))||
(vragi4Objects[i120].chetvert==1&&vragi4Objects[i120].v4y<=(vragi4Objects[i120].ry-vragi4Objects[i120].r/2)))
{vragi4Objects[i120].v4x-=vragi4Objects[i120].speedY*lag;}

if(vragi4Objects[i120].v4y>=vragi4Objects[i120].ry)
{vragi4Objects[i120].v4y=sqrt(vragi4Objects[i120].r*vragi4Objects[i120].r-(vragi4Objects[i120].v4x-vragi4Objects[i120].rx)*(vragi4Objects[i120].v4x-vragi4Objects[i120].rx))+vragi4Objects[i120].ry;}
if(vragi4Objects[i120].v4y<vragi4Objects[i120].ry)
{vragi4Objects[i120].v4y=vragi4Objects[i120].ry-sqrt(vragi4Objects[i120].r*vragi4Objects[i120].r-(vragi4Objects[i120].v4x-vragi4Objects[i120].rx)*(vragi4Objects[i120].v4x-vragi4Objects[i120].rx));}
}

//смена направления вниз
if(vragi4Objects[i120].v4y<=vragi4Objects[i120].ry-(vragi4Objects[i120].r-1))
{vragi4Objects[i120].up=false;
if(vragi4Objects[i120].chetvert_n==1&&vragi4Objects[i120].chetvert==1)
{vragi4Objects[i120].chetvert=-1;}
if(vragi4Objects[i120].chetvert_n==-1&&vragi4Objects[i120].chetvert==-1)
{vragi4Objects[i120].chetvert=1;}}//смена направления вниз
}//летим вверх




if(vragi4Objects[i120].up==false)//летим вниз
{

//середина
if(vragi4Objects[i120].v4y>=(vragi4Objects[i120].ry-vragi4Objects[i120].r/2)&&
   vragi4Objects[i120].v4y<=(vragi4Objects[i120].ry+vragi4Objects[i120].r/2))	
{vragi4Objects[i120].v4y+=vragi4Objects[i120].speedY*lag;
if(vragi4Objects[i120].chetvert==1)//против часовой (справа)
{vragi4Objects[i120].v4x=sqrt(vragi4Objects[i120].r*vragi4Objects[i120].r-(vragi4Objects[i120].v4y-vragi4Objects[i120].ry)*(vragi4Objects[i120].v4y-vragi4Objects[i120].ry))+vragi4Objects[i120].rx;}
if(vragi4Objects[i120].chetvert==-1)//по часовой (слева)
{vragi4Objects[i120].v4x=vragi4Objects[i120].rx-sqrt(vragi4Objects[i120].r*vragi4Objects[i120].r-(vragi4Objects[i120].v4y-vragi4Objects[i120].ry)*(vragi4Objects[i120].v4y-vragi4Objects[i120].ry));}
}


//по краям
if(vragi4Objects[i120].v4y<=(vragi4Objects[i120].ry-vragi4Objects[i120].r/2)||
   vragi4Objects[i120].v4y>=(vragi4Objects[i120].ry+vragi4Objects[i120].r/2))	
{
if((vragi4Objects[i120].chetvert==-1&&vragi4Objects[i120].v4y<=(vragi4Objects[i120].ry-vragi4Objects[i120].r/2))||
(vragi4Objects[i120].chetvert==1&&vragi4Objects[i120].v4y>=(vragi4Objects[i120].ry+vragi4Objects[i120].r/2)))
{vragi4Objects[i120].v4x-=vragi4Objects[i120].speedY*lag;}
if((vragi4Objects[i120].chetvert==-1&&vragi4Objects[i120].v4y>=(vragi4Objects[i120].ry+vragi4Objects[i120].r/2))||
(vragi4Objects[i120].chetvert==1&&vragi4Objects[i120].v4y<=(vragi4Objects[i120].ry-vragi4Objects[i120].r/2)))
{vragi4Objects[i120].v4x+=vragi4Objects[i120].speedY*lag;}

if(vragi4Objects[i120].v4y>=vragi4Objects[i120].ry)
{vragi4Objects[i120].v4y=sqrt(vragi4Objects[i120].r*vragi4Objects[i120].r-(vragi4Objects[i120].v4x-vragi4Objects[i120].rx)*(vragi4Objects[i120].v4x-vragi4Objects[i120].rx))+vragi4Objects[i120].ry;}
if(vragi4Objects[i120].v4y<vragi4Objects[i120].ry)
{vragi4Objects[i120].v4y=vragi4Objects[i120].ry-sqrt(vragi4Objects[i120].r*vragi4Objects[i120].r-(vragi4Objects[i120].v4x-vragi4Objects[i120].rx)*(vragi4Objects[i120].v4x-vragi4Objects[i120].rx));}
}

//смена направления вверх
if(vragi4Objects[i120].v4y>=vragi4Objects[i120].ry+(vragi4Objects[i120].r-1))
{vragi4Objects[i120].up=true;
if(vragi4Objects[i120].chetvert_n==1&&vragi4Objects[i120].chetvert==-1)
{vragi4Objects[i120].chetvert=1;}
if(vragi4Objects[i120].chetvert_n==-1&&vragi4Objects[i120].chetvert==1)
{vragi4Objects[i120].chetvert=-1;}}//смена направления вверх
}//летим вниз

}//заход снизу


if(vragi4Objects[i120].gradus>vragi4Objects[i120].gradusNext)
{vragi4Objects[i120].kruzhit=false;
vragi4Objects[i120].krug++;
if(vragi4Objects[i120].zahod==1)
{vragi4Objects[i120].zahod=-1;}
if(vragi4Objects[i120].zahod==-1)
{vragi4Objects[i120].zahod=1;}
vragi4Objects[i120].rx=hge->Random_Float(vragi4Objects[i120].rx,vragi4Objects[i120].rx+600);
vragi4Objects[i120].ry=hge->Random_Float(vragi4Objects[i120].ry-300,vragi4Objects[i120].ry-100);
vragi4Objects[i120].gradus=vragi4Objects[i120].gradusNext;
vragi4Objects[i120].gradusNext+=M_PI-M_PI_4;
vragi4Objects[i120].r=hge->Random_Int(25,50);
}

if(vragi4Objects[i120].gradus<-vragi4Objects[i120].gradusNext)
{vragi4Objects[i120].kruzhit=false;
vragi4Objects[i120].krug++;
if(vragi4Objects[i120].zahod==1)
{vragi4Objects[i120].zahod=-1;}
if(vragi4Objects[i120].zahod==-1)
{vragi4Objects[i120].zahod=1;}
vragi4Objects[i120].rx=hge->Random_Float(vragi4Objects[i120].rx-600,vragi4Objects[i120].rx);
vragi4Objects[i120].ry=hge->Random_Float(vragi4Objects[i120].ry+100,vragi4Objects[i120].ry+300);
vragi4Objects[i120].gradus=-vragi4Objects[i120].gradusNext;
vragi4Objects[i120].gradusNext+=-(M_PI-M_PI_4);
vragi4Objects[i120].r=hge->Random_Int(25,50);
}



}//kruzhim

}//polet


}//ЗАКРЫТИЕ САГИ ПРО ПТЕНЦА


for (int i6=0;i6<=N_UHI;i6++) // летящие уши
{
if(uhiObjects[i6].akt==1&&uhiObjects[i6].uhiy<uhiObjects[i6].niz)
{uhiObjects[i6].uhix-=hge->Random_Float(0,0.6f)*lag;
uhiObjects[i6].uhiy+=0.6f*lag;
uhiObjects[i6].gradus+=(M_PI_4/16)*lag;}


if(uhiObjects[i6].uhiy>uhiObjects[i6].niz&&uhiObjects[i6].akt==1)//если уши долетели
{
myasoupaloPan=-75+uhiObjects[i6].uhix/9;
myasko_upalo();
uhiObjects[i6].uhiy=uhiObjects[i6].niz;	//остановка
uhiObjects[i6].gradus+=0;//уши перестают верететься

trupsObjects[N_TRUPS].rot=uhiObjects[i6].gradus;
trupsObjects[N_TRUPS].posX=uhiObjects[i6].uhix;
trupsObjects[N_TRUPS].posY=uhiObjects[i6].uhiy;
trupsObjects[N_TRUPS].posX_s=uhiObjects[i6].uhix;
trupsObjects[N_TRUPS].posX_X=X;
trupsObjects[N_TRUPS].type=2;// труп ушей :)
uhi_a->Play();


N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}


uhiObjects[i6].akt=0;
}


}//закрытие летящих ушей 




for (int i15=0;i15<=N_HEAD;i15++) // летящие бошки
{

//ссущий кровяк!!! 	
if(boshkiObjects[i15].akt==1)
{blood_ssit_psi->FireAt(boshkiObjects[i15].bx,boshkiObjects[i15].by+5);
blood_ssit_psi->info.fDirection=boshkiObjects[i15].gradus;
blood_ssit_psi->Transpose(0.1f,0.1f);}

if(boshkiObjects[i15].akt==1&&boshkiObjects[i15].by<boshkiObjects[i15].niz&&boshkiObjects[i15].bzdik==0)
{
boshkiObjects[i15].bx-=(hge->Random_Float(2,2.5f)+boshkiObjects[i15].seed*0.2f)*lag;
boshkiObjects[i15].by+=0.8f*lag;
boshkiObjects[i15].gradus+=(M_PI_4/8)*lag;}

if(boshkiObjects[i15].by>=boshkiObjects[i15].niz&&boshkiObjects[i15].akt==1&&boshkiObjects[i15].bzdik==0)//если бошки долетели 1-й раз
{boshkiObjects[i15].by=boshkiObjects[i15].niz;
boshkiObjects[i15].bzdik=1;
myasoupaloPan=-75+boshkiObjects[i15].bx/9;
myasko_upalo();

//плям!!!

trupsObjects[N_TRUPS].posX=boshkiObjects[i15].bx;
trupsObjects[N_TRUPS].posY=boshkiObjects[i15].by;
trupsObjects[N_TRUPS].posX_s=boshkiObjects[i15].bx;
trupsObjects[N_TRUPS].posX_X=X;
trupsObjects[N_TRUPS].type=hge->Random_Int(800,802);



N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}


if(boshkiObjects[i15].bzdik_seed==1)//увы бошка дальше не полетит
{boshkiObjects[i15].akt=-1;}
}





if(boshkiObjects[i15].akt==1&&boshkiObjects[i15].by<=boshkiObjects[i15].niz&&boshkiObjects[i15].bzdik==1)
{
boshkiObjects[i15].bx-=(hge->Random_Float(0.5f,1)+boshkiObjects[i15].seed*0.2f)*lag;
if(boshkiObjects[i15].by>boshkiObjects[i15].niz-50)
{boshkiObjects[i15].by-=0.6f*lag;}
if(boshkiObjects[i15].by<=boshkiObjects[i15].niz-50)
{boshkiObjects[i15].bzdik=2;}
boshkiObjects[i15].gradus+=(M_PI_4/4)*lag;}

if(boshkiObjects[i15].akt==1&&boshkiObjects[i15].by<boshkiObjects[i15].niz&&boshkiObjects[i15].bzdik==2)
{
boshkiObjects[i15].bx-=(hge->Random_Float(0.5f,1)+boshkiObjects[i15].seed*0.2f)*lag;
boshkiObjects[i15].by+=0.6f*lag;
boshkiObjects[i15].gradus+=(M_PI_4/4)*lag;}


if(boshkiObjects[i15].by>=boshkiObjects[i15].niz&&boshkiObjects[i15].akt==1&&boshkiObjects[i15].bzdik==2)//если бошки долетели 2-й раз
{
myasoupaloPan=-75+boshkiObjects[i15].bx/9;
myasko_upalo();
boshkiObjects[i15].by=boshkiObjects[i15].niz;	//остановка
boshkiObjects[i15].gradus+=0;//бошки перестают верететься





//плям!!!

trupsObjects[N_TRUPS].posX=boshkiObjects[i15].bx;
trupsObjects[N_TRUPS].posY=boshkiObjects[i15].by;
trupsObjects[N_TRUPS].posX_s=boshkiObjects[i15].bx;
trupsObjects[N_TRUPS].posX_X=X;
trupsObjects[N_TRUPS].type=hge->Random_Int(800,802);



N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}


boshkiObjects[i15].bzdik=3;

if(boshkiObjects[i15].bzdik_seed==2)//увы бошка дальше не попрыгает
{boshkiObjects[i15].akt=-1;}

}


if(boshkiObjects[i15].akt==1&&boshkiObjects[i15].by>=boshkiObjects[i15].niz-20&&boshkiObjects[i15].bzdik==3)
{
boshkiObjects[i15].bx-=(hge->Random_Float(0.5f,0.7f)+boshkiObjects[i15].seed*0.15f)*lag;
boshkiObjects[i15].by-=0.6f*lag;
boshkiObjects[i15].gradus+=(M_PI_4/16)*lag;
}

if(boshkiObjects[i15].akt==1&&boshkiObjects[i15].by<=boshkiObjects[i15].niz-20&&boshkiObjects[i15].bzdik==3)
{boshkiObjects[i15].bzdik=4;}

if(boshkiObjects[i15].akt==1&&boshkiObjects[i15].by<=boshkiObjects[i15].niz&&boshkiObjects[i15].bzdik==4)
{boshkiObjects[i15].bx-=(hge->Random_Float(0.5f,0.7f)+boshkiObjects[i15].seed*0.15f)*lag;
boshkiObjects[i15].by+=0.5f*lag;
boshkiObjects[i15].gradus+=(M_PI_4/16)*lag;}

if(boshkiObjects[i15].akt==1&&boshkiObjects[i15].by>=boshkiObjects[i15].niz&&boshkiObjects[i15].bzdik==4)
{
myasoupaloPan=-75+boshkiObjects[i15].bx/9;
myasko_upalo();
boshkiObjects[i15].by=boshkiObjects[i15].niz;	//остановка

//плям!!!

trupsObjects[N_TRUPS].posX=boshkiObjects[i15].bx;
trupsObjects[N_TRUPS].posY=boshkiObjects[i15].by;
trupsObjects[N_TRUPS].posX_s=boshkiObjects[i15].bx;
trupsObjects[N_TRUPS].posX_X=X;
trupsObjects[N_TRUPS].type=hge->Random_Int(800,802);



N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}

	
	
if(boshkiObjects[i15].bzdik_seed==3)//увы бошка дальше не попрыгает
{boshkiObjects[i15].akt=-1;}

}





if(boshkiObjects[i15].akt==-1)//запись в массив с щами
{

trupsObjects[N_TRUPS].rot=boshkiObjects[i15].gradus;
trupsObjects[N_TRUPS].posX=boshkiObjects[i15].bx;
trupsObjects[N_TRUPS].posY=boshkiObjects[i15].by;
trupsObjects[N_TRUPS].posX_s=boshkiObjects[i15].bx;
trupsObjects[N_TRUPS].posX_X=X;
if(boshkiObjects[i15].vrag==1)
{
if(boshkiObjects[i15].bezuh==0)
{trupsObjects[N_TRUPS].type=6;}// труп бошек :)
if(boshkiObjects[i15].bezuh==1)
{trupsObjects[N_TRUPS].type=7;}
}

if(boshkiObjects[i15].vrag==3)
{
trupsObjects[N_TRUPS].type=511;// труп бошек :)
}


N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}



boshkiObjects[i15].akt=0;
}



}//закрытие летящих бошек




















//просчёт анимации трупов и появление луж кровяка
for(int i13=0;i13<=N_TRUPS;i13++)
{

if(trupsObjects[i13].type==1&&trupsObjects[i13].frame_akt==1)//анимация трупа зайца
{

if(trupsObjects[i13].killtime<950)		
{if((time>=trupsObjects[i13].killtime+50)||(time<trupsObjects[i13].killtime&&perez_akt!=trupsObjects[i13].killtime_sec)) //кадр 2
{trupsObjects[i13].frame=2;}}
if(trupsObjects[i13].killtime>=950)
{if(time>=trupsObjects[i13].killtime-950) 
{trupsObjects[i13].frame=2;}
}



if(trupsObjects[i13].killtime<900)
{if((time>=trupsObjects[i13].killtime+100&&trupsObjects[i13].frame==2)||
(time<trupsObjects[i13].killtime&&perez_akt!=trupsObjects[i13].killtime_sec&&trupsObjects[i13].frame==2)) //кадр 3
{trupsObjects[i13].frame=3;}}	
if(trupsObjects[i13].killtime>=900)
{if(time>=trupsObjects[i13].killtime-900&&trupsObjects[i13].frame==2) 
{trupsObjects[i13].frame=3;}}


if(trupsObjects[i13].killtime<850)
{if((time>=trupsObjects[i13].killtime+150&&trupsObjects[i13].frame==3)||
(time<trupsObjects[i13].killtime&&perez_akt!=trupsObjects[i13].killtime_sec&&trupsObjects[i13].frame==3))//кадр 4
{trupsObjects[i13].frame=4;
trupsObjects[i13].frame_akt=0;

}}
if(trupsObjects[i13].killtime>=850)
{if(time>=trupsObjects[i13].killtime-850&&trupsObjects[i13].frame==3)
{trupsObjects[i13].frame=4;
trupsObjects[i13].frame_akt=0;


}}


}//закрытие анимации зайцев

if(trupsObjects[i13].type==10&&trupsObjects[i13].frame_akt==1)//анимация трупа волка
{

if(trupsObjects[i13].killtime<900)		
{if((time>=trupsObjects[i13].killtime+100)||(time<trupsObjects[i13].killtime&&perez_akt!=trupsObjects[i13].killtime_sec)) //кадр 2
{trupsObjects[i13].frame=2;}}
if(trupsObjects[i13].killtime>=900)
{if(time>=trupsObjects[i13].killtime-900) 
{trupsObjects[i13].frame=2;}
}



if(trupsObjects[i13].killtime<800)
{if((time>=trupsObjects[i13].killtime+200&&trupsObjects[i13].frame==2)||
(time<trupsObjects[i13].killtime&&perez_akt!=trupsObjects[i13].killtime_sec&&trupsObjects[i13].frame==2)) //кадр 3
{trupsObjects[i13].frame=3;
trupsObjects[i13].frame_akt=0;}}	
if(trupsObjects[i13].killtime>=800)
{if(time>=trupsObjects[i13].killtime-800&&trupsObjects[i13].frame==2) 
{trupsObjects[i13].frame=3;
trupsObjects[i13].frame_akt=0;}}


}//закрытие анимации волков

if(trupsObjects[i13].type==20&&trupsObjects[i13].frame_akt==1)//анимация трупа медведя
{

for(int i93=1;i93<6;i93++)
{
if(trupsObjects[i13].frame==i93&&((trupsObjects[i13].killtime<900&&
(perez_akt_milli>=trupsObjects[i13].killtime+100||perez_akt!=trupsObjects[i13].killtime_sec))
||(trupsObjects[i13].killtime>=900&&
perez_akt_milli>=trupsObjects[i13].killtime-900&&perez_akt!=trupsObjects[i13].killtime_sec))) //кадр ][
{trupsObjects[i13].frame++;
trupsObjects[i13].killtime=GetTime();
trupsObjects[i13].killtime_sec=perez_akt;}

if(trupsObjects[i13].frame==6)
{trupsObjects[i13].frame_akt=0;}
}

}//закрытие анимации медведя

if(trupsObjects[i13].type==9&&trupsObjects[i13].aktiv==1)//лужи кровяка
{

if(trupsObjects[i13].vrag==1)//лужа после зайца
{
if(trupsObjects[i13].scaleX<=0.4f&&time%25==0)
{trupsObjects[i13].scaleX+=0.015f;}
if(trupsObjects[i13].scaleX>=0.4f)
{trupsObjects[i13].aktiv=0;}
}

if(trupsObjects[i13].vrag==2)//лужа после волка
{
if(trupsObjects[i13].scaleX<=0.7f&&time%25==0)
{trupsObjects[i13].scaleX+=0.02f;}
if(trupsObjects[i13].scaleX>=0.7f)
{trupsObjects[i13].aktiv=0;}
}

if(trupsObjects[i13].vrag==3)//лужа после медведя
{
if(trupsObjects[i13].scaleX<=1.3f&&time%25==0)
{trupsObjects[i13].scaleX+=0.02f;}
if(trupsObjects[i13].scaleX>=1.3f)
{trupsObjects[i13].aktiv=0;}
}

if(trupsObjects[i13].vrag==4)//лужа после птенца
{
if(trupsObjects[i13].scaleX<=0.3f&&time%25==0)
{trupsObjects[i13].scaleX+=0.01f;}
if(trupsObjects[i13].scaleX>=0.3f)
{trupsObjects[i13].aktiv=0;}
}

}




}//закрытие просчёта анимации трупов

























//кровяк


if(peregruzheno_blood==0)
{
for (int i12=0;i12<=N_BLOOD;i12++)
{
if(krovyakObjects[i12].seed!=0&&krovyakObjects[i12].seed<1000)
{

//krovyakObjects[i12].seed==1||krovyakObjects[i12].seed==2

//если миллисек меньше 750
if(krovyakObjects[i12].akt==1&&krovyakObjects[i12].blood_time<750&&perez_akt_milli<=krovyakObjects[i12].blood_time+250)
{

if(krovyakObjects[i12].seed==1||krovyakObjects[i12].seed==2||krovyakObjects[i12].seed==3)//чтоб поменьше ссанья
{
if(myaskoSsit!=0)
{myasko_ssit();
myaskoSsit=0;}
if(krovyakObjects[i12].blood_time>=950&&perez_akt_milli<=krovyakObjects[i12].blood_time-950)
{myaskoSsit=1;}
if((krovyakObjects[i12].blood_time<950&&perez_akt_milli<=krovyakObjects[i12].blood_time+50)
||(perez_akt!=krovyakObjects[i12].blood_time_sec))
{myaskoSsit=1;}
}

//летит по иксу
if(krovyakObjects[i12].seed==1||krovyakObjects[i12].seed==2||krovyakObjects[i12].seed==3)//назад
{

if(krovyakObjects[i12].vrag==1)
{
if(krovyakObjects[i12].xstart-krovyakObjects[i12].x1<=65)
{krovyakObjects[i12].x1-=hge->Random_Float(3,4)*lag;}}

if(krovyakObjects[i12].vrag==2)
{
if(krovyakObjects[i12].xstart-krovyakObjects[i12].x1<=45)
{krovyakObjects[i12].x1-=hge->Random_Float(3,4)*lag;}}

if(krovyakObjects[i12].vrag==3)
{
if(krovyakObjects[i12].xstart-krovyakObjects[i12].x1<=45)
{krovyakObjects[i12].x1-=hge->Random_Float(4,5)*lag;}}

}

if(krovyakObjects[i12].seed==101||krovyakObjects[i12].seed==102||krovyakObjects[i12].seed==103)//вперёд
{
if(krovyakObjects[i12].vrag==1)
{
if(krovyakObjects[i12].x1-krovyakObjects[i12].xstart<=35)
{krovyakObjects[i12].x1+=hge->Random_Float(3,4)*lag;}}

if(krovyakObjects[i12].vrag==2)
{
if(krovyakObjects[i12].x1-krovyakObjects[i12].xstart<=50)
{krovyakObjects[i12].x1+=hge->Random_Float(3,4)*lag;}}

if(krovyakObjects[i12].vrag==3)
{
if(krovyakObjects[i12].x1-krovyakObjects[i12].xstart<=65)
{krovyakObjects[i12].x1+=hge->Random_Float(4,5)*lag;}}


}


if(krovyakObjects[i12].faza==1&&(krovyakObjects[i12].y2-krovyakObjects[i12].y1<=25||krovyakObjects[i12].y2<=krovyakObjects[i12].niz))
{krovyakObjects[i12].y2+=1.5f*lag;}//растягивается вниз

if(krovyakObjects[i12].faza==1&&(krovyakObjects[i12].y2-krovyakObjects[i12].y1>=25||krovyakObjects[i12].y2>=krovyakObjects[i12].niz))
{krovyakObjects[i12].faza=2;
krovyakObjects[i12].y1+=1.5f*lag;}

if(krovyakObjects[i12].faza==2&&krovyakObjects[i12].y2-krovyakObjects[i12].y1>=12)//долетает вниз
{
krovyakObjects[i12].y1+=1.5f*lag;
if(krovyakObjects[i12].seed==101||krovyakObjects[i12].seed==102||krovyakObjects[i12].seed==103)//вперёд
{krovyakObjects[i12].x2+=hge->Random_Float(1,1.5f)*lag;}
}

switch(krovyakObjects[i12].seed)//запись в трупы
{case 1:
case 101:trupsObjects[N_TRUPS].type=400;
break;
case 2:
case 102:trupsObjects[N_TRUPS].type=401;
break;
case 3:
case 103:trupsObjects[N_TRUPS].type=402;
break;
}
trupsObjects[N_TRUPS].posY=krovyakObjects[i12].y1;
trupsObjects[N_TRUPS].posY2=krovyakObjects[i12].y2;
trupsObjects[N_TRUPS].posX=krovyakObjects[i12].x1;
trupsObjects[N_TRUPS].posX2=krovyakObjects[i12].x2;
trupsObjects[N_TRUPS].posX_s=krovyakObjects[i12].x1;
trupsObjects[N_TRUPS].posX2_s=krovyakObjects[i12].x2;
trupsObjects[N_TRUPS].posX_X=X;
trupsObjects[N_TRUPS].posX2_X=X;
if(time>=krovyakObjects[i12].blood_time+250)
{krovyakObjects[i12].akt=0;

N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}

}
}
//если более 750
if(krovyakObjects[i12].akt==1&&krovyakObjects[i12].blood_time>=750&&
perez_akt!=krovyakObjects[i12].blood_time_sec&&time<=krovyakObjects[i12].blood_time-750)
//||
//(krovyakObjects[i12].akt==1&&krovyakObjects[i12].blood_time>=750&&
//perez_akt==krovyakObjects[i12].blood_time_sec&&time>=krovyakObjects[i12].blood_time))
{

if(krovyakObjects[i12].seed==1||krovyakObjects[i12].seed==2)//чтоб поменьше ссанья
{
if(myaskoSsit!=0)
{myasko_ssit();
myaskoSsit=0;}
if(krovyakObjects[i12].blood_time>=950&&time<=krovyakObjects[i12].blood_time-950)
{myaskoSsit=1;}
if((krovyakObjects[i12].blood_time<950&&perez_akt_milli<=krovyakObjects[i12].blood_time+50)
||(perez_akt!=krovyakObjects[i12].blood_time_sec))
{myaskoSsit=1;}
}

//летит по иксу
if(krovyakObjects[i12].seed==1||krovyakObjects[i12].seed==2||krovyakObjects[i12].seed==3)//назад
{
if(krovyakObjects[i12].vrag==1)
{if(krovyakObjects[i12].xstart-krovyakObjects[i12].x1<=65)
{krovyakObjects[i12].x1-=hge->Random_Float(3,4)*lag;}}

if(krovyakObjects[i12].vrag==2)
{
if(krovyakObjects[i12].xstart-krovyakObjects[i12].x1<=45)
{krovyakObjects[i12].x1-=hge->Random_Float(3,4)*lag;}}

if(krovyakObjects[i12].vrag==3)
{
if(krovyakObjects[i12].xstart-krovyakObjects[i12].x1<=45)
{krovyakObjects[i12].x1-=hge->Random_Float(4,5)*lag;}}
}

if(krovyakObjects[i12].seed==101||krovyakObjects[i12].seed==102||krovyakObjects[i12].seed==103)//вперёд
{
if(krovyakObjects[i12].vrag==1)
{if(krovyakObjects[i12].x1-krovyakObjects[i12].xstart<=35)
{krovyakObjects[i12].x1+=hge->Random_Float(3,4)*lag;}}

if(krovyakObjects[i12].vrag==2)
{if(krovyakObjects[i12].x1-krovyakObjects[i12].xstart<=50)
{krovyakObjects[i12].x1+=hge->Random_Float(3,4)*lag;}}

if(krovyakObjects[i12].vrag==3)
{if(krovyakObjects[i12].x1-krovyakObjects[i12].xstart<=65)
{krovyakObjects[i12].x1+=hge->Random_Float(4,5)*lag;}}
}


if(krovyakObjects[i12].faza==1&&(krovyakObjects[i12].y2-krovyakObjects[i12].y1<=25||krovyakObjects[i12].y2<=krovyakObjects[i12].niz))
{krovyakObjects[i12].y2+=1.5f*lag;}//растягивается вниз

if(krovyakObjects[i12].faza==1&&(krovyakObjects[i12].y2-krovyakObjects[i12].y1>=25||krovyakObjects[i12].y2>=krovyakObjects[i12].niz))
{krovyakObjects[i12].faza=2;
krovyakObjects[i12].y1+=1.5f*lag;}

if(krovyakObjects[i12].faza==2&&krovyakObjects[i12].y2-krovyakObjects[i12].y1>=12)//долетает вниз
{
krovyakObjects[i12].y1+=1.5f*lag;
if(krovyakObjects[i12].seed==101||krovyakObjects[i12].seed==102||krovyakObjects[i12].seed==103)//вперёд
{krovyakObjects[i12].x2+=hge->Random_Float(1,1.5f)*lag;}
}

switch(krovyakObjects[i12].seed)
{case 1:
case 101:trupsObjects[N_TRUPS].type=400;
break;
case 2:
case 102:trupsObjects[N_TRUPS].type=401;
break;
case 3:
case 103:trupsObjects[N_TRUPS].type=402;
break;}
trupsObjects[N_TRUPS].posY=krovyakObjects[i12].y1;
trupsObjects[N_TRUPS].posY2=krovyakObjects[i12].y2;
trupsObjects[N_TRUPS].posX=krovyakObjects[i12].x1;
trupsObjects[N_TRUPS].posX2=krovyakObjects[i12].x2;
trupsObjects[N_TRUPS].posX_s=krovyakObjects[i12].x1;
trupsObjects[N_TRUPS].posX2_s=krovyakObjects[i12].x2;
trupsObjects[N_TRUPS].posX_X=X;
trupsObjects[N_TRUPS].posX2_X=X;
if(time>=krovyakObjects[i12].blood_time-750)
{krovyakObjects[i12].akt=0;

N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}

}
}

}//закрытие летящего кровяка 






if(krovyakObjects[i12].seed==0)//ТОЧКА
{
if(krovyakObjects[i12].akt==1&&krovyakObjects[i12].blood_time<950&&
  ((time>=krovyakObjects[i12].blood_time+50)||
  (perez_akt!=krovyakObjects[i12].blood_time_sec&&time<krovyakObjects[i12].blood_time)))
{krovyakObjects[i12].akt=0;}

if(krovyakObjects[i12].blood_time>=950&&krovyakObjects[i12].akt==1&&
time>=krovyakObjects[i12].blood_time-950)
{krovyakObjects[i12].akt=0;}
}

if(krovyakObjects[i12].seed==1001||krovyakObjects[i12].seed==1002)//ВСПЛЕСКИ И ВОРОНКИ КРОВЯКА
{

if(krovyakObjects[i12].akt==1)//анимация играет
{
if(krovyakObjects[i12].faza==1&&(
(krovyakObjects[i12].blood_time>=950&&
perez_akt_milli>=krovyakObjects[i12].blood_time-950&&perez_akt!=krovyakObjects[i12].blood_time_sec)||
((krovyakObjects[i12].blood_time<950&&perez_akt_milli>=krovyakObjects[i12].blood_time+50)||
(perez_akt!=krovyakObjects[i12].blood_time_sec))
))
{krovyakObjects[i12].faza=2;
krovyakObjects[i12].blood_time=GetTime();
krovyakObjects[i12].blood_time_sec=perez_akt;}
if(krovyakObjects[i12].faza==2&&(
(krovyakObjects[i12].blood_time>=950&&
perez_akt_milli>=krovyakObjects[i12].blood_time-950&&perez_akt!=krovyakObjects[i12].blood_time_sec)||
((krovyakObjects[i12].blood_time<950&&perez_akt_milli>=krovyakObjects[i12].blood_time+50)||
(perez_akt!=krovyakObjects[i12].blood_time_sec))
))
{krovyakObjects[i12].faza=3;
krovyakObjects[i12].blood_time=GetTime();
krovyakObjects[i12].blood_time_sec=perez_akt;}
if(krovyakObjects[i12].faza==3&&(
(krovyakObjects[i12].blood_time>=900&&
perez_akt_milli>=krovyakObjects[i12].blood_time-900&&perez_akt!=krovyakObjects[i12].blood_time_sec)||
((krovyakObjects[i12].blood_time<900&&perez_akt_milli>=krovyakObjects[i12].blood_time+100)||
(perez_akt!=krovyakObjects[i12].blood_time_sec))
))
{krovyakObjects[i12].faza=4;
krovyakObjects[i12].blood_time=GetTime();
krovyakObjects[i12].blood_time_sec=perez_akt;}
if(krovyakObjects[i12].faza==4&&(
(krovyakObjects[i12].blood_time>=900&&
perez_akt_milli>=krovyakObjects[i12].blood_time-900&&perez_akt!=krovyakObjects[i12].blood_time_sec)||
((krovyakObjects[i12].blood_time<900&&perez_akt_milli>=krovyakObjects[i12].blood_time+100)||
(perez_akt!=krovyakObjects[i12].blood_time_sec))
))
{krovyakObjects[i12].faza=5;
krovyakObjects[i12].blood_time=GetTime();
krovyakObjects[i12].blood_time_sec=perez_akt;
krovyakObjects[i12].akt=-1;}
}//анимация играет

if(krovyakObjects[i12].akt==-1)
{
if(krovyakObjects[i12].seed==1001)
{trupsObjects[N_TRUPS].type=hge->Random_Int(300,301);}
if(krovyakObjects[i12].seed==1002)
{trupsObjects[N_TRUPS].type=330;}
trupsObjects[N_TRUPS].posX=krovyakObjects[i12].x1;
trupsObjects[N_TRUPS].posY=krovyakObjects[i12].y1;
trupsObjects[N_TRUPS].posX_s=krovyakObjects[i12].x1;
trupsObjects[N_TRUPS].posX_X=X;
trupsObjects[N_TRUPS].scaleX=krovyakObjects[i12].xstart;

krovyakObjects[i12].akt=0;



N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}

}

}//всплески





}//for
}//закрытие кровяка




//КРОВЯК КОГДА ПЕРЕГРУЖЕНО
if(peregruzheno_blood==1)
{
for (int i92=0;i92<=NUMBER_BLOOD;i92++)
{
if(krovyakObjects[i92].seed!=0&&krovyakObjects[i92].seed<1000)
{

//krovyakObjects[i12].seed==1||krovyakObjects[i12].seed==2

//если миллисек меньше 750
if(krovyakObjects[i92].akt==1&&krovyakObjects[i92].blood_time<750&&time<=krovyakObjects[i92].blood_time+250)
{

if(krovyakObjects[i92].seed==1||krovyakObjects[i92].seed==2||krovyakObjects[i92].seed==3)//чтоб поменьше ссанья
{
if(myaskoSsit!=0)
{myasko_ssit();
myaskoSsit=0;}
if(krovyakObjects[i92].blood_time>=950&&time<=krovyakObjects[i92].blood_time-950)
{myaskoSsit=1;}
if((krovyakObjects[i92].blood_time<950&&perez_akt_milli<=krovyakObjects[i92].blood_time+50)
||(perez_akt!=krovyakObjects[i92].blood_time_sec))
{myaskoSsit=1;}
}

//летит по иксу
if(krovyakObjects[i92].seed==1||krovyakObjects[i92].seed==2||krovyakObjects[i92].seed==3)//назад
{

if(krovyakObjects[i92].vrag==1)
{
if(krovyakObjects[i92].xstart-krovyakObjects[i92].x1<=65)
{krovyakObjects[i92].x1-=hge->Random_Float(3,4)*lag;}}

if(krovyakObjects[i92].vrag==2)
{
if(krovyakObjects[i92].xstart-krovyakObjects[i92].x1<=45)
{krovyakObjects[i92].x1-=hge->Random_Float(3,4)*lag;}}

if(krovyakObjects[i92].vrag==3)
{
if(krovyakObjects[i92].xstart-krovyakObjects[i92].x1<=45)
{krovyakObjects[i92].x1-=hge->Random_Float(4,5)*lag;}}

}

if(krovyakObjects[i92].seed==101||krovyakObjects[i92].seed==102||krovyakObjects[i92].seed==103)//вперёд
{
if(krovyakObjects[i92].vrag==1)
{
if(krovyakObjects[i92].x1-krovyakObjects[i92].xstart<=35)
{krovyakObjects[i92].x1+=hge->Random_Float(3,4)*lag;}}

if(krovyakObjects[i92].vrag==2)
{
if(krovyakObjects[i92].x1-krovyakObjects[i92].xstart<=50)
{krovyakObjects[i92].x1+=hge->Random_Float(3,4)*lag;}}

if(krovyakObjects[i92].vrag==3)
{
if(krovyakObjects[i92].x1-krovyakObjects[i92].xstart<=65)
{krovyakObjects[i92].x1+=hge->Random_Float(4,5)*lag;}}

}


if(krovyakObjects[i92].faza==1&&(krovyakObjects[i92].y2-krovyakObjects[i92].y1<=25||krovyakObjects[i92].y2<=krovyakObjects[i92].niz))
{krovyakObjects[i92].y2+=1.5f*lag;}//растягивается вниз

if(krovyakObjects[i92].faza==1&&(krovyakObjects[i92].y2-krovyakObjects[i92].y1>=25||krovyakObjects[i92].y2>=krovyakObjects[i92].niz))
{krovyakObjects[i92].faza=2;
krovyakObjects[i92].y1+=1.5f*lag;}

if(krovyakObjects[i92].faza==2&&krovyakObjects[i92].y2-krovyakObjects[i92].y1>=12)//долетает вниз
{
krovyakObjects[i92].y1+=1.5f*lag;
if(krovyakObjects[i92].seed==101||krovyakObjects[i92].seed==102||krovyakObjects[i92].seed==103)//вперёд
{krovyakObjects[i92].x2+=hge->Random_Float(1,1.5f)*lag;}
}

switch(krovyakObjects[i92].seed)//запись в трупы
{case 1:
case 101:trupsObjects[N_TRUPS].type=400;
break;
case 2:
case 102:trupsObjects[N_TRUPS].type=401;
break;
case 3:
case 103:trupsObjects[N_TRUPS].type=402;
break;}
trupsObjects[N_TRUPS].posY=krovyakObjects[i92].y1;
trupsObjects[N_TRUPS].posY2=krovyakObjects[i92].y2;
trupsObjects[N_TRUPS].posX=krovyakObjects[i92].x1;
trupsObjects[N_TRUPS].posX2=krovyakObjects[i92].x2;
trupsObjects[N_TRUPS].posX_s=krovyakObjects[i92].x1;
trupsObjects[N_TRUPS].posX2_s=krovyakObjects[i92].x2;
trupsObjects[N_TRUPS].posX_X=X;
trupsObjects[N_TRUPS].posX2_X=X;
if(perez_akt_milli>=krovyakObjects[i92].blood_time+250)
{krovyakObjects[i92].akt=0;


N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}

}
}
//если более 750
if(krovyakObjects[i92].akt==1&&krovyakObjects[i92].blood_time>=750&&
perez_akt!=krovyakObjects[i92].blood_time_sec&&time<=krovyakObjects[i92].blood_time-750)
//||
//(krovyakObjects[i12].akt==1&&krovyakObjects[i12].blood_time>=750&&
//perez_akt==krovyakObjects[i12].blood_time_sec&&time>=krovyakObjects[i12].blood_time))
{

if(krovyakObjects[i92].seed==1||krovyakObjects[i92].seed==2)//чтоб поменьше ссанья
{
if(myaskoSsit!=0)
{myasko_ssit();
myaskoSsit=0;}
if(krovyakObjects[i92].blood_time>=950&&time<=krovyakObjects[i92].blood_time-950)
{myaskoSsit=1;}
if((krovyakObjects[i92].blood_time<950&&perez_akt_milli<=krovyakObjects[i92].blood_time+50)
||(perez_akt!=krovyakObjects[i92].blood_time_sec))
{myaskoSsit=1;}
}

//летит по иксу
if(krovyakObjects[i92].seed==1||krovyakObjects[i92].seed==2||krovyakObjects[i92].seed==3)//назад
{
if(krovyakObjects[i92].vrag==1)
{if(krovyakObjects[i92].xstart-krovyakObjects[i92].x1<=65)
{krovyakObjects[i92].x1-=hge->Random_Float(3,4)*lag;}}

if(krovyakObjects[i92].vrag==2)
{
if(krovyakObjects[i92].xstart-krovyakObjects[i92].x1<=45)
{krovyakObjects[i92].x1-=hge->Random_Float(3,4)*lag;}}

if(krovyakObjects[i92].vrag==3)
{
if(krovyakObjects[i92].xstart-krovyakObjects[i92].x1<=45)
{krovyakObjects[i92].x1-=hge->Random_Float(4,5)*lag;}}
}

if(krovyakObjects[i92].seed==101||krovyakObjects[i92].seed==102||krovyakObjects[i92].seed==103)//вперёд
{
if(krovyakObjects[i92].vrag==1)
{if(krovyakObjects[i92].x1-krovyakObjects[i92].xstart<=35)
{krovyakObjects[i92].x1+=hge->Random_Float(3,4)*lag;}}

if(krovyakObjects[i92].vrag==2)
{if(krovyakObjects[i92].x1-krovyakObjects[i92].xstart<=50)
{krovyakObjects[i92].x1+=hge->Random_Float(3,4)*lag;}}

if(krovyakObjects[i92].vrag==3)
{if(krovyakObjects[i92].x1-krovyakObjects[i92].xstart<=65)
{krovyakObjects[i92].x1+=hge->Random_Float(4,5)*lag;}}
}


if(krovyakObjects[i92].faza==1&&(krovyakObjects[i92].y2-krovyakObjects[i92].y1<=25||krovyakObjects[i92].y2<=krovyakObjects[i92].niz))
{krovyakObjects[i92].y2+=1.5f*lag;}//растягивается вниз

if(krovyakObjects[i92].faza==1&&(krovyakObjects[i92].y2-krovyakObjects[i92].y1>=25||krovyakObjects[i92].y2>=krovyakObjects[i92].niz))
{krovyakObjects[i92].faza=2;
krovyakObjects[i92].y1+=1.5f*lag;}

if(krovyakObjects[i92].faza==2&&krovyakObjects[i92].y2-krovyakObjects[i92].y1>=12)//долетает вниз
{
krovyakObjects[i92].y1+=1.5f*lag;
if(krovyakObjects[i92].seed==101||krovyakObjects[i92].seed==102||krovyakObjects[i92].seed==103)//вперёд
{krovyakObjects[i92].x2+=hge->Random_Float(1,1.5f)*lag;}
}

switch(krovyakObjects[i92].seed)
{case 1:
case 101:trupsObjects[N_TRUPS].type=400;
break;
case 2:
case 102:trupsObjects[N_TRUPS].type=401;
break;
case 3:
case 103:trupsObjects[N_TRUPS].type=402;
break;}
trupsObjects[N_TRUPS].posY=krovyakObjects[i92].y1;
trupsObjects[N_TRUPS].posY2=krovyakObjects[i92].y2;
trupsObjects[N_TRUPS].posX=krovyakObjects[i92].x1;
trupsObjects[N_TRUPS].posX2=krovyakObjects[i92].x2;
trupsObjects[N_TRUPS].posX_s=krovyakObjects[i92].x1;
trupsObjects[N_TRUPS].posX2_s=krovyakObjects[i92].x2;
trupsObjects[N_TRUPS].posX_X=X;
trupsObjects[N_TRUPS].posX2_X=X;
if(time>=krovyakObjects[i92].blood_time-750)
{krovyakObjects[i92].akt=0;


N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}

}
}

}//закрытие летящего кровяка 






if(krovyakObjects[i92].seed==0)//ТОЧКА
{
if(krovyakObjects[i92].akt==1&&krovyakObjects[i92].blood_time<950&&
  ((time>=krovyakObjects[i92].blood_time+50)||
  (perez_akt!=krovyakObjects[i92].blood_time_sec&&time<krovyakObjects[i92].blood_time)))
{krovyakObjects[i92].akt=0;}

if(krovyakObjects[i92].blood_time>=950&&krovyakObjects[i92].akt==1&&
time>=krovyakObjects[i92].blood_time-950)
{krovyakObjects[i92].akt=0;}
}



if(krovyakObjects[i92].seed==1001||krovyakObjects[i92].seed==1002)//ВСПЛЕСКИ И ВОРОНКИ КРОВЯКА
{

if(krovyakObjects[i92].akt==1)//анимация играет
{
if(krovyakObjects[i92].faza==1&&(
(krovyakObjects[i92].blood_time>=950&&
perez_akt_milli>=krovyakObjects[i92].blood_time-950&&perez_akt!=krovyakObjects[i92].blood_time_sec)||
((krovyakObjects[i92].blood_time<950&&perez_akt_milli>=krovyakObjects[i92].blood_time+50)||
(perez_akt!=krovyakObjects[i92].blood_time_sec))
))
{krovyakObjects[i92].faza=2;
krovyakObjects[i92].blood_time=GetTime();
krovyakObjects[i92].blood_time_sec=perez_akt;}
if(krovyakObjects[i92].faza==2&&(
(krovyakObjects[i92].blood_time>=950&&
perez_akt_milli>=krovyakObjects[i92].blood_time-950&&perez_akt!=krovyakObjects[i92].blood_time_sec)||
((krovyakObjects[i92].blood_time<950&&perez_akt_milli>=krovyakObjects[i92].blood_time+50)||
(perez_akt!=krovyakObjects[i92].blood_time_sec))
))
{krovyakObjects[i92].faza=3;
krovyakObjects[i92].blood_time=GetTime();
krovyakObjects[i92].blood_time_sec=perez_akt;}
if(krovyakObjects[i92].faza==3&&(
(krovyakObjects[i92].blood_time>=900&&
perez_akt_milli>=krovyakObjects[i92].blood_time-900&&perez_akt!=krovyakObjects[i92].blood_time_sec)||
((krovyakObjects[i92].blood_time<900&&perez_akt_milli>=krovyakObjects[i92].blood_time+100)||
(perez_akt!=krovyakObjects[i92].blood_time_sec))
))
{krovyakObjects[i92].faza=4;
krovyakObjects[i92].blood_time=GetTime();
krovyakObjects[i92].blood_time_sec=perez_akt;}
if(krovyakObjects[i92].faza==4&&(
(krovyakObjects[i92].blood_time>=900&&
perez_akt_milli>=krovyakObjects[i92].blood_time-900&&perez_akt!=krovyakObjects[i92].blood_time_sec)||
((krovyakObjects[i92].blood_time<900&&perez_akt_milli>=krovyakObjects[i92].blood_time+100)||
(perez_akt!=krovyakObjects[i92].blood_time_sec))
))
{krovyakObjects[i92].faza=5;
krovyakObjects[i92].blood_time=GetTime();
krovyakObjects[i92].blood_time_sec=perez_akt;
krovyakObjects[i92].akt=-1;}
}//анимация играет

if(krovyakObjects[i92].akt==-1)
{

if(krovyakObjects[i92].seed==1001)
{trupsObjects[N_TRUPS].type=hge->Random_Int(300,301);}
if(krovyakObjects[i92].seed==1002)
{trupsObjects[N_TRUPS].type=330;}
trupsObjects[N_TRUPS].posX=krovyakObjects[i92].x1;
trupsObjects[N_TRUPS].posY=krovyakObjects[i92].y1;
trupsObjects[N_TRUPS].posX_s=krovyakObjects[i92].x1;
trupsObjects[N_TRUPS].posX_X=X;
trupsObjects[N_TRUPS].scaleX=krovyakObjects[i92].xstart;

krovyakObjects[i92].akt=0;



N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}

}

}//всплески



}//for
}//закрытие кровяка







//ЛЕТЯЩЕЕ МЯСО
for(int i41=0;i41<=N_MYASO;i41++)
{

if(myasko[i41].akt==1)//летит
{

//защита облаков
if(myasko[i41].niz<100)
{myasko[i41].niz=100;}



if(myasko[i41].energy==0)//открытие невзорванного мяса
{

if(myasko[i41].y1<=myasko[i41].niz&&myasko[i41].bzdik==0)	
{myasko[i41].y1+=0.8f*lag;
myasko[i41].x1-=myasko[i41].speedX*lag;
myasko[i41].gradus+=(M_PI_4/4)*lag;}

//бздык!
if(myasko[i41].y1>=myasko[i41].niz&&myasko[i41].bzdik==0)	
{myasoupaloPan=-75+myasko[i41].x1/9;
myasko_upalo();
myasko[i41].bzdik=1;}


//лёгкое мясо взлетает вверх
if(myasko[i41].bzdik==1&&myasko[i41].scaleX<=0.4f)
{myasko[i41].y1-=myasko[i41].speedY*lag;
myasko[i41].x1-=(myasko[i41].speedX/2)*lag;
myasko[i41].gradus+=(M_PI_4/8)*lag;
if(myasko[i41].y1<=myasko[i41].niz-30&&myasko[i41].bzdik==1)
{myasko[i41].bzdik=2;}
}

//и летит вниз
if(myasko[i41].y1<=myasko[i41].niz&&myasko[i41].bzdik==2)
{myasko[i41].y1+=0.8f*lag;
myasko[i41].x1-=(myasko[i41].speedX/2)*lag;
myasko[i41].gradus+=(M_PI_4/8)*lag;
}

//бздык!
if(myasko[i41].y1>=myasko[i41].niz&&myasko[i41].bzdik==2)
{myasoupaloPan=-75+myasko[i41].x1/9;
myasko_upalo();
myasko[i41].bzdik=3;
}

if(myasko[i41].bzdik==3&&myasko[i41].scaleX<=0.4f)//катится мелочь
{myasko[i41].x1-=(myasko[i41].speedX/2)*lag;
myasko[i41].speedX-=0.025f*lag;
myasko[i41].gradus+=(M_PI_4/8)*lag;
headshotPan=-75+myasko[i41].x1/9;
if((int)myasko[i41].x1%50==0)
{myasko_ssit();}
}

if (myasko[i41].bzdik==1&&myasko[i41].scaleX>0.4f)//катится
{myasko[i41].x1-=myasko[i41].speedX*lag;
myasko[i41].speedX-=0.02f*lag;
myasko[i41].gradus+=(M_PI_4/8)*lag;
headshotPan=-75+myasko[i41].x1/9;
if((int)myasko[i41].x1%50==0)
{myasko_ssit();}
}


if(myasko[i41].speedX<=0)
{myasko[i41].akt=0;}

}//закрытие невзорванного мяса






if(myasko[i41].energy>0)//открытие взорванного мяса
{


if(myasko[i41].energy<0.85f)//открытие "земного" мяса
{

if((myasko[i41].speedY>=0&&myasko[i41].y1<=myasko[i41].niz&&myasko[i41].bzdik==0)||
   (myasko[i41].speedY<0&&myasko[i41].y1>=myasko[i41].niz&&myasko[i41].bzdik==0))
{
if(myasko[i41].speedY>=0.01f||myasko[i41].speedY<=-0.01f)
{myasko[i41].y1+=myasko[i41].speedY*lag;}
if(myasko[i41].speedY<=0.01f||myasko[i41].speedY>=-0.01f)
{myasko[i41].y1+=0.01f*lag;}
myasko[i41].x1+=myasko[i41].speedX*lag;
myasko[i41].gradus+=(M_PI_4/4)*lag;}

//бздык!
if((myasko[i41].speedY>=0&&myasko[i41].y1>=myasko[i41].niz&&myasko[i41].bzdik==0)||
   (myasko[i41].speedY<0&&myasko[i41].y1<=myasko[i41].niz&&myasko[i41].bzdik==0))	
{myasoupaloPan=-75+myasko[i41].x1/9;
myasko_upalo();
myasko[i41].bzdik=1;}


if (myasko[i41].bzdik==1)//катится
{myasko[i41].x1+=myasko[i41].speedX*lag;
myasko[i41].y1+=myasko[i41].speedY*lag;
if(myasko[i41].speedX>0)
{
myasko[i41].speedX-=0.005f*lag;
if(myasko[i41].speedX<=0)
{myasko[i41].bzdik=3;}
}
if(myasko[i41].speedX<0)
{
myasko[i41].speedX+=0.005f*lag;
if(myasko[i41].speedX>=0)
{myasko[i41].bzdik=3;}
}
if(myasko[i41].speedY>0)
{myasko[i41].speedY-=0.005f*lag;
//защита облаков
if(myasko[i41].y1<100)
{myasko[i41].y1=100;
myasko[i41].speedY=0;}}
if(myasko[i41].speedY<0)
{myasko[i41].speedY+=0.005f*lag;
//защита облаков
if(myasko[i41].y1<100)
{myasko[i41].y1=100;
myasko[i41].speedY=0;}}
myasko[i41].gradus+=(M_PI_4/8)*lag;
headshotPan=-75+myasko[i41].x1/9;
if((int)myasko[i41].x1%50==0)
{myasko_ssit();}
}

}//закрытие "земного" мяса


//МЯСНОЙ ДОЖДЬ
if(myasko[i41].energy>=0.85f)//открытие "космического" мяса
{

if(myasko[i41].y1<myasko[i41].niz)
{
myasko[i41].y1+=myasko[i41].speedY*lag;
myasko[i41].x1+=myasko[i41].speedX*0.5f*lag;
myasko[i41].gradus+=(M_PI_4/2)*lag;
if(myasko[i41].speedY<=4)
{myasko[i41].speedY+=0.05f*lag;}
}

if(myasko[i41].y1>=myasko[i41].niz)
{
myasko[i41].bzdik=3;
myasoupaloPan=-75+myasko[i41].x1/9;
myasko_upalo();

//плям!!!

trupsObjects[N_TRUPS].posX=myasko[i41].x1;
trupsObjects[N_TRUPS].posY=myasko[i41].y1;
trupsObjects[N_TRUPS].posX_s=myasko[i41].x1;
trupsObjects[N_TRUPS].posX_X=X;
trupsObjects[N_TRUPS].type=hge->Random_Int(800,802);



N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}

}


}//закрытие "космического" мяса
//МЯСНОЙ ДОЖДЬ


if(myasko[i41].bzdik==3)
{myasko[i41].akt=0;}

}//закрытие взорванного мяса





}//закрытие летящего мяса

if(myasko[i41].akt==0)//запись в щи
{
switch(myasko[i41].seed)
{case 1:trupsObjects[N_TRUPS].type=500;
break;
case 2:trupsObjects[N_TRUPS].type=501;
break;
case 3:trupsObjects[N_TRUPS].type=502;
break;
case 4:trupsObjects[N_TRUPS].type=503;
break;
case 5:trupsObjects[N_TRUPS].type=504;
break;
case 6:trupsObjects[N_TRUPS].type=7;//заячья бошка
break;
case 7:trupsObjects[N_TRUPS].type=505;//заячьи ребра 1
break;
case 8:trupsObjects[N_TRUPS].type=506;//заячьи ребра 2
break;
case 9:trupsObjects[N_TRUPS].type=507;//заячья нога 1
break;
case 10:trupsObjects[N_TRUPS].type=508;//заячья нога 2
break;
case 11:trupsObjects[N_TRUPS].type=509;//заячья нога 3
break;
case 12:trupsObjects[N_TRUPS].type=510;//заячья нога 4
break;
}

trupsObjects[N_TRUPS].posY=myasko[i41].y1;
trupsObjects[N_TRUPS].posX=myasko[i41].x1;
trupsObjects[N_TRUPS].posX_s=myasko[i41].x1;
trupsObjects[N_TRUPS].posX_X=X;
trupsObjects[N_TRUPS].rot=myasko[i41].gradus;
trupsObjects[N_TRUPS].scaleX=myasko[i41].scaleX;


N_TRUPS++;
if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}

myasko[i41].akt=-1;
}//закрытие записи в щи


}//ЗАКРЫТИЕ МЯСА





//-------------$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$-----------------------------
//БОНУСЫ
for (int i29=0;i29<=N_BONUS;i29++)
{

if(bonusiObjects[i29].akt==1)
{//берем бонус
if(x-10<=bonusiObjects[i29].x2&&x+10>=bonusiObjects[i29].x1&&
y-48<=bonusiObjects[i29].y1&&y+48>=bonusiObjects[i29].y2)
{bonusiObjects[i29].owner=1;}
if(x2-10<=bonusiObjects[i29].x2&&x2+10>=bonusiObjects[i29].x1&&
y2-48<=bonusiObjects[i29].y1&&y2+48>=bonusiObjects[i29].y2)
{bonusiObjects[i29].owner=2;}
//активируем его
if(bonusiObjects[i29].owner==1)
{
if(RPGMOD==true)
{
switch(bonusiObjects[i29].type)
{
case 0://рандом
bonusiObjects[i29].shans=hge->Random_Int(1,100);
//+ СКОРОСТЬ
if(bonusiObjects[i29].shans>=1&&bonusiObjects[i29].shans<=20+luck1/2)
{bonusi1[N_BONUS1].znachenie=skorost1*0.1f;
bonusi1[N_BONUS1].type=1;
bonusi1[N_BONUS1].id=i29;
speed+=bonusi1[N_BONUS1].znachenie;
bonustext1_1();


//появление статуса +10% скорость
statusi1[N_BONUSSTATUS1].akt=1;
statusi1[N_BONUSSTATUS1].type=1;
statusi1[N_BONUSSTATUS1].id=i29;
statusi1[N_BONUSSTATUS1].queue=status_queue1;
status_queue1++;
N_BONUSSTATUS1++;
if(N_BONUSSTATUS1>=MAX_BONUSSTATUS-1)
{N_BONUSSTATUS1=0;}




N_BONUS1++;
if(N_BONUS1>=MAX_BONUSI-1)
{N_BONUS1=0;}

}//закрытие про шило

//ДАУНИЗМ
if(bonusiObjects[i29].shans>=21+luck1/2&&bonusiObjects[i29].shans<=40)
{
daun1++;
bonusi1[N_BONUS1].type=2;
bonusi1[N_BONUS1].id=i29;
bonustext1_2();


//появление статуса даунизма
statusi1[N_BONUSSTATUS1].akt=1;
statusi1[N_BONUSSTATUS1].type=2;
statusi1[N_BONUSSTATUS1].id=i29;
statusi1[N_BONUSSTATUS1].queue=status_queue1;
status_queue1++;
N_BONUSSTATUS1++;
if(N_BONUSSTATUS1>=MAX_BONUSSTATUS-1)
{N_BONUSSTATUS1=0;}



N_BONUS1++;
if(N_BONUS1>=MAX_BONUSI-1)
{N_BONUS1=0;}}
//УЛИТКА
if(bonusiObjects[i29].shans>=41&&bonusiObjects[i29].shans<=60-luck1/2)
{
bonusi1[N_BONUS1].znachenie=skorost1*0.2f;
bonusi1[N_BONUS1].type=3;
bonusi1[N_BONUS1].id=i29;
speed-=bonusi1[N_BONUS1].znachenie;
bonustext1_3();

//появление статуса замедления
statusi1[N_BONUSSTATUS1].akt=1;
statusi1[N_BONUSSTATUS1].type=3;
statusi1[N_BONUSSTATUS1].id=i29;
statusi1[N_BONUSSTATUS1].queue=status_queue1;
status_queue1++;
N_BONUSSTATUS1++;
if(N_BONUSSTATUS1>=MAX_BONUSSTATUS-1)
{N_BONUSSTATUS1=0;}


N_BONUS1++;
if(N_BONUS1>=MAX_BONUSI-1)
{N_BONUS1=0;}}
//УМНИК
if(bonusiObjects[i29].shans>=61-luck1/2&&bonusiObjects[i29].shans<=80)
{
umnik1++;
bonusi1[N_BONUS1].type=4;
bonusi1[N_BONUS1].id=i29;
bonustext1_4();

//появление статуса
statusi1[N_BONUSSTATUS1].akt=1;
statusi1[N_BONUSSTATUS1].type=4;
statusi1[N_BONUSSTATUS1].id=i29;
statusi1[N_BONUSSTATUS1].queue=status_queue1;
status_queue1++;
N_BONUSSTATUS1++;
if(N_BONUSSTATUS1>=MAX_BONUSSTATUS-1)
{N_BONUSSTATUS1=0;}


N_BONUS1++;
if(N_BONUS1>=MAX_BONUSI-1)
{N_BONUS1=0;}}
//НИЧЕГО
if(bonusiObjects[i29].shans>80)
{bonustext1_0();}

bonusiObjects[i29].akt=0;
bonusiObjects[i29].akt_time=perez_akt;
bonusiObjects[i29].akt_time_milli=GetTime();

break;
case 1://шило в жопу

bonusi1[N_BONUS1].znachenie=skorost1*0.1f;
bonusi1[N_BONUS1].type=1;
bonusi1[N_BONUS1].id=i29;
speed+=bonusi1[N_BONUS1].znachenie;
bonustext1_1();

//появление статуса +10% скорость
statusi1[N_BONUSSTATUS1].akt=1;
statusi1[N_BONUSSTATUS1].type=1;
statusi1[N_BONUSSTATUS1].id=i29;
statusi1[N_BONUSSTATUS1].queue=status_queue1;
status_queue1++;
N_BONUSSTATUS1++;
if(N_BONUSSTATUS1>=MAX_BONUSSTATUS-1)
{N_BONUSSTATUS1=0;}




N_BONUS1++;
if(N_BONUS1>=MAX_BONUSI-1)
{N_BONUS1=0;}

bonusiObjects[i29].akt=0;
bonusiObjects[i29].akt_time=perez_akt;
bonusiObjects[i29].akt_time_milli=GetTime();



break;}

}//RPGMOD==true

if(RPGMOD==false)
{
switch(bonusiObjects[i29].type)
{
case 0://рандом
bonusiObjects[i29].shans=hge->Random_Int(1,100);
//+ СКОРОСТЬ
if(bonusiObjects[i29].shans>=1&&bonusiObjects[i29].shans<=50)
{bonusi1[N_BONUS1].znachenie=skorost1*0.1f;
bonusi1[N_BONUS1].type=1;
bonusi1[N_BONUS1].id=i29;
speed+=bonusi1[N_BONUS1].znachenie;
bonustext1_1();

N_BONUS1++;
if(N_BONUS1>=MAX_BONUSI-1)
{N_BONUS1=0;}}

if(bonusiObjects[i29].shans>50)
{bonustext1_0();}
bonusiObjects[i29].akt=0;
bonusiObjects[i29].akt_time=perez_akt;
bonusiObjects[i29].akt_time_milli=GetTime();
break;
case 1://шило в жопу

bonusi1[N_BONUS1].znachenie=skorost1*0.1f;
bonusi1[N_BONUS1].type=1;
bonusi1[N_BONUS1].id=i29;
speed+=bonusi1[N_BONUS1].znachenie;
bonustext1_1();

N_BONUS1++;
if(N_BONUS1>=MAX_BONUSI-1)
{N_BONUS1=0;}

bonusiObjects[i29].akt=0;
bonusiObjects[i29].akt_time=perez_akt;
bonusiObjects[i29].akt_time_milli=GetTime();

break;}

}//RPGMOD==false


}

if(bonusiObjects[i29].owner==2)
{
if(RPGMOD==true)
{
switch(bonusiObjects[i29].type)
{
case 0://рандом
bonusiObjects[i29].shans=hge->Random_Int(1,100);
//+СКОРОСТЬ 2
if(bonusiObjects[i29].shans>=1&&bonusiObjects[i29].shans<=20+luck2/2)
{bonusi2[N_BONUS2].znachenie=skorost2*0.1f;
bonusi2[N_BONUS2].type=1;
bonusi2[N_BONUS2].id=i29;
speed2+=bonusi2[N_BONUS2].znachenie;
bonustext2_1();

//появление статуса +10% скорость
statusi2[N_BONUSSTATUS2].akt=1;
statusi2[N_BONUSSTATUS2].type=1;
statusi2[N_BONUSSTATUS2].id=i29;
statusi2[N_BONUSSTATUS2].queue=status_queue2;
status_queue2++;
N_BONUSSTATUS2++;
if(N_BONUSSTATUS2>=MAX_BONUSSTATUS-1)
{N_BONUSSTATUS2=0;}

N_BONUS2++;
if(N_BONUS2>=MAX_BONUSI-1)
{N_BONUS2=0;}}
//ДАУНИЗМ 2
if(bonusiObjects[i29].shans>=21+luck2/2&&bonusiObjects[i29].shans<=40)
{
daun2++;
bonusi2[N_BONUS2].type=2;
bonusi2[N_BONUS2].id=i29;
bonustext2_2();

//появление статуса даунизма
statusi2[N_BONUSSTATUS2].akt=1;
statusi2[N_BONUSSTATUS2].type=2;
statusi2[N_BONUSSTATUS2].id=i29;
statusi2[N_BONUSSTATUS2].queue=status_queue2;
status_queue2++;
N_BONUSSTATUS2++;
if(N_BONUSSTATUS2>=MAX_BONUSSTATUS-1)
{N_BONUSSTATUS2=0;}


N_BONUS2++;
if(N_BONUS2>=MAX_BONUSI-1)
{N_BONUS2=0;}}
//УЛИТКА 2
if(bonusiObjects[i29].shans>=41&&bonusiObjects[i29].shans<=60-luck2/2)
{
bonusi2[N_BONUS2].znachenie=skorost2*0.2f;
bonusi2[N_BONUS2].type=3;
bonusi2[N_BONUS2].id=i29;
speed2-=bonusi2[N_BONUS2].znachenie;
bonustext2_3();

//появление статуса замедления
statusi2[N_BONUSSTATUS2].akt=1;
statusi2[N_BONUSSTATUS2].type=3;
statusi2[N_BONUSSTATUS2].id=i29;
statusi2[N_BONUSSTATUS2].queue=status_queue2;
status_queue2++;
N_BONUSSTATUS2++;
if(N_BONUSSTATUS2>=MAX_BONUSSTATUS-1)
{N_BONUSSTATUS2=0;}


N_BONUS2++;
if(N_BONUS2>=MAX_BONUSI-1)
{N_BONUS2=0;}}
//УМНИК 2
if(bonusiObjects[i29].shans>=61-luck2/2&&bonusiObjects[i29].shans<=80)
{
umnik2++;
bonusi2[N_BONUS2].type=4;
bonusi2[N_BONUS2].id=i29;
bonustext2_4();

//появление статуса
statusi2[N_BONUSSTATUS2].akt=1;
statusi2[N_BONUSSTATUS2].type=4;
statusi2[N_BONUSSTATUS2].id=i29;
statusi2[N_BONUSSTATUS2].queue=status_queue2;
status_queue2++;
N_BONUSSTATUS2++;
if(N_BONUSSTATUS2>=MAX_BONUSSTATUS-1)
{N_BONUSSTATUS2=0;}


N_BONUS2++;
if(N_BONUS2>=MAX_BONUSI-1)
{N_BONUS2=0;}}
//НИЧЕГО
if(bonusiObjects[i29].shans>80)
{bonustext2_0();}
bonusiObjects[i29].akt=0;
bonusiObjects[i29].akt_time=perez_akt;
bonusiObjects[i29].akt_time_milli=GetTime();
break;
case 1://шило в жопу

bonusi2[N_BONUS2].znachenie=skorost2*0.1f;
bonusi2[N_BONUS2].type=1;
bonusi2[N_BONUS2].id=i29;
speed2+=bonusi2[N_BONUS2].znachenie;
bonustext2_1();

//появление статуса +10% скорость
statusi2[N_BONUSSTATUS2].akt=1;
statusi2[N_BONUSSTATUS2].type=1;
statusi2[N_BONUSSTATUS2].id=i29;
statusi2[N_BONUSSTATUS2].queue=status_queue2;
status_queue2++;
N_BONUSSTATUS2++;
if(N_BONUSSTATUS2>=MAX_BONUSSTATUS-1)
{N_BONUSSTATUS2=0;}


N_BONUS2++;
if(N_BONUS2>=MAX_BONUSI-1)
{N_BONUS2=0;}

bonusiObjects[i29].akt=0;
bonusiObjects[i29].akt_time=perez_akt;
bonusiObjects[i29].akt_time_milli=GetTime();

break;}
}//RPGMOD==true


if(RPGMOD==false)
{
switch(bonusiObjects[i29].type)
{
case 0://рандом
bonusiObjects[i29].shans=hge->Random_Int(1,100);
//+СКОРОСТЬ
if(bonusiObjects[i29].shans>=1&&bonusiObjects[i29].shans<=50)
{bonusi2[N_BONUS2].znachenie=skorost2*0.1f;
bonusi2[N_BONUS2].type=1;
bonusi2[N_BONUS2].id=i29;
speed2+=bonusi2[N_BONUS2].znachenie;
bonustext2_1();

N_BONUS2++;
if(N_BONUS2>=MAX_BONUSI-1)
{N_BONUS2=0;}}

if(bonusiObjects[i29].shans>50)
{bonustext2_0();}
bonusiObjects[i29].akt=0;
bonusiObjects[i29].akt_time=perez_akt;
bonusiObjects[i29].akt_time_milli=GetTime();
break;
case 1://шило в жопу

bonusi2[N_BONUS2].znachenie=skorost2*0.1f;
bonusi2[N_BONUS2].type=1;
bonusi2[N_BONUS2].id=i29;
speed2+=bonusi2[N_BONUS2].znachenie;
bonustext2_1();

N_BONUS2++;
if(N_BONUS2>=MAX_BONUSI-1)
{N_BONUS2=0;}

bonusiObjects[i29].akt=0;
bonusiObjects[i29].akt_time=perez_akt;
bonusiObjects[i29].akt_time_milli=GetTime();

break;}
}//RPGMOD==false

}


//кручение бонусов
if(bonusiObjects[i29].spin==0&&bonusiObjects[i29].x2>=bonusiObjects[i29].x1)
{bonusiObjects[i29].x1+=0.2f;
bonusiObjects[i29].x2-=0.2f;}

if(bonusiObjects[i29].spin==0&&bonusiObjects[i29].x2<=bonusiObjects[i29].x1)
{bonusiObjects[i29].spin=1;}

if(bonusiObjects[i29].spin==1&&bonusiObjects[i29].x1-bonusiObjects[i29].x2<=30)
{bonusiObjects[i29].x1+=0.2f;
bonusiObjects[i29].x2-=0.2f;}

if(bonusiObjects[i29].spin==1&&bonusiObjects[i29].x1-bonusiObjects[i29].x2>=30)
{bonusiObjects[i29].spin=2;}

if(bonusiObjects[i29].spin==2&&bonusiObjects[i29].x1>=bonusiObjects[i29].x2)
{bonusiObjects[i29].x1-=0.2f;
bonusiObjects[i29].x2+=0.2f;}

if(bonusiObjects[i29].spin==2&&bonusiObjects[i29].x1<=bonusiObjects[i29].x2)
{bonusiObjects[i29].spin=3;}

if(bonusiObjects[i29].spin==3&&bonusiObjects[i29].x2-bonusiObjects[i29].x1<=30)
{bonusiObjects[i29].x1-=0.2f;
bonusiObjects[i29].x2+=0.2f;}

if(bonusiObjects[i29].spin==3&&bonusiObjects[i29].x2-bonusiObjects[i29].x1>=30)
{bonusiObjects[i29].spin=0;}






}//если активировано



if(bonusiObjects[i29].akt==0)//исчезновение бонусных апгрейдов
{
if((bonusiObjects[i29].akt_time<50&&perez_akt==bonusiObjects[i29].akt_time+10&&
   GetTime()>=bonusiObjects[i29].akt_time_milli)||
   (bonusiObjects[i29].akt_time>=50&&perez_akt==bonusiObjects[i29].akt_time-50&&
   GetTime()>=bonusiObjects[i29].akt_time_milli))
{
if(bonusiObjects[i29].owner==1)
{
switch(bonusiObjects[i29].type)
{
case 0:
//+10% скорость
if(bonusiObjects[i29].shans>=1&&bonusiObjects[i29].shans<=20+luck1/2)
{

for(int i34=0;i34<=N_BONUS1;i34++)
{
if(bonusi1[i34].id==i29)
{speed-=bonusi1[i34].znachenie;}
}

for(int i38=0;i38<=N_BONUSSTATUS1;i38++)
{
if(statusi1[i38].id==i29)
{statusi1[i38].akt=0;
status_queue1--;}
if(statusi1[i38].akt==1&&statusi1[i38].id!=i29)
{statusi1[i38].queue--;}
}//status


}
//даунизм
if(bonusiObjects[i29].shans>=21+luck1/2&&bonusiObjects[i29].shans<=40)
{
daun1--;
for(int i38=0;i38<=N_BONUSSTATUS1;i38++)
{
if(statusi1[i38].id==i29)
{statusi1[i38].akt=0;
status_queue1--;}
if(statusi1[i38].akt==1&&statusi1[i38].id!=i29)
{statusi1[i38].queue--;}
}//status
}
//-20% скорость
if(bonusiObjects[i29].shans>=41&&bonusiObjects[i29].shans<=60-luck1/2)
{

for(int i34=0;i34<=N_BONUS1;i34++)
{
if(bonusi1[i34].id==i29)
{speed+=bonusi1[i34].znachenie;}
}

for(int i38=0;i38<=N_BONUSSTATUS1;i38++)
{
if(statusi1[i38].id==i29)
{statusi1[i38].akt=0;
status_queue1--;}
if(statusi1[i38].akt==1&&statusi1[i38].id!=i29)
{statusi1[i38].queue--;}
}//status
}
//+25% обучение
if(bonusiObjects[i29].shans>=61-luck1/2&&bonusiObjects[i29].shans<=80)
{
umnik1--;

for(int i38=0;i38<=N_BONUSSTATUS1;i38++)
{
if(statusi1[i38].id==i29)
{statusi1[i38].akt=0;
status_queue1--;}
if(statusi1[i38].akt==1&&statusi1[i38].id!=i29)
{statusi1[i38].queue--;}
}//status
}


bonusiObjects[i29].akt=-1;
break;

case 1://шило в жопу
for(int i34=0;i34<=N_BONUS1;i34++)
{
if(bonusi1[i34].id==i29)
{speed-=bonusi1[i34].znachenie;}
}
for(int i38=0;i38<=N_BONUSSTATUS1;i38++)
{
if(statusi1[i38].id==i29)
{statusi1[i38].akt=0;
status_queue1--;}
if(statusi1[i38].akt==1&&statusi1[i38].id!=i29)
{statusi1[i38].queue--;}
}//status
bonusiObjects[i29--].akt=-1;
break;}
}//закрытие про игрока 1

if(bonusiObjects[i29].owner==2)
{
switch(bonusiObjects[i29].type)
{
case 0:
if(bonusiObjects[i29].shans>=1&&bonusiObjects[i29].shans<=20+luck2/2)
{
for(int i34=0;i34<=N_BONUS2;i34++)
{
if(bonusi2[i34].id==i29)
{speed2-=bonusi2[i34].znachenie;}
}
for(int i38=0;i38<=N_BONUSSTATUS2;i38++)
{
if(statusi2[i38].id==i29)
{statusi2[i38].akt=0;
status_queue2--;}
if(statusi2[i38].akt==1&&statusi2[i38].id!=i29)
{statusi2[i38].queue--;}
}//status
}

if(bonusiObjects[i29].shans>=21+luck2/2&&bonusiObjects[i29].shans<=40)
{
daun2--;
for(int i38=0;i38<=N_BONUSSTATUS2;i38++)
{
if(statusi2[i38].id==i29)
{statusi2[i38].akt=0;
status_queue2--;}
if(statusi2[i38].akt==1&&statusi2[i38].id!=i29)
{statusi2[i38].queue--;}
}//status
}


if(bonusiObjects[i29].shans>=41&&bonusiObjects[i29].shans<=60-luck2/2)
{
for(int i34=0;i34<=N_BONUS2;i34++)
{
if(bonusi2[i34].id==i29)
{speed2+=bonusi2[i34].znachenie;}
}
for(int i38=0;i38<=N_BONUSSTATUS2;i38++)
{
if(statusi2[i38].id==i29)
{statusi2[i38].akt=0;
status_queue2--;}
if(statusi2[i38].akt==1&&statusi2[i38].id!=i29)
{statusi2[i38].queue--;}
}//status
}

if(bonusiObjects[i29].shans>=61-luck2/2&&bonusiObjects[i29].shans<=80)
{
umnik2--;
for(int i38=0;i38<=N_BONUSSTATUS2;i38++)
{
if(statusi2[i38].id==i29)
{statusi2[i38].akt=0;
status_queue2--;}
if(statusi2[i38].akt==1&&statusi2[i38].id!=i29)
{statusi2[i38].queue--;}
}//status
}




bonusiObjects[i29].akt=-1;
break;
case 1://шило в жопу
for(int i34=0;i34<=N_BONUS2;i34++)
{
if(bonusi2[i34].id==i29)
{speed2-=bonusi2[i34].znachenie;}
}
for(int i38=0;i38<=N_BONUSSTATUS2;i38++)
{
if(statusi2[i38].id==i29)
{statusi2[i38].akt=0;
status_queue2--;}
if(statusi2[i38].akt==1&&statusi2[i38].id!=i29)
{statusi2[i38].queue--;}
}//status
bonusiObjects[i29].akt=-1;
break;}
}
}

}//закрытие исчезновения бонусных апгрейдов

if(bonusiObjects[i29].akt==1)//исчезновение бонусов
{

//мигание
if((bonusiObjects[i29].appear_time<53&&perez_akt==bonusiObjects[i29].appear_time+7&&
   perez_akt_milli>=bonusiObjects[i29].appear_time_milli)||
   (bonusiObjects[i29].appear_time>=53&&perez_akt==bonusiObjects[i29].appear_time-53&&
   perez_akt_milli>=bonusiObjects[i29].appear_time_milli))
{bonusiObjects[i29].mig_akt=1;
bonusiObjects[i29].mig_time=perez_akt;
bonusiObjects[i29].mig_time_milli=GetTime();}//закрытие активации мигания 

if(bonusiObjects[i29].mig_akt==1)
{
if(bonusiObjects[i29].mig_time_milli<750&&bonusiObjects[i29].visible==true&&
(perez_akt_milli>=bonusiObjects[i29].mig_time_milli+250||
(perez_akt_milli<bonusiObjects[i29].mig_time_milli&&perez_akt!=bonusiObjects[i29].mig_time)))
{bonusiObjects[i29].visible=false;
bonusiObjects[i29].mig_time=perez_akt;
bonusiObjects[i29].mig_time_milli=GetTime();}

if(bonusiObjects[i29].mig_time_milli<750&&bonusiObjects[i29].visible==false&&
(perez_akt_milli>=bonusiObjects[i29].mig_time_milli+250||
(perez_akt_milli<bonusiObjects[i29].mig_time_milli&&perez_akt!=bonusiObjects[i29].mig_time)))
{bonusiObjects[i29].visible=true;
bonusiObjects[i29].mig_time=perez_akt;
bonusiObjects[i29].mig_time_milli=GetTime();}

if(bonusiObjects[i29].mig_time_milli>=750&&bonusiObjects[i29].visible==true&&
perez_akt_milli>=bonusiObjects[i29].mig_time_milli-750&&perez_akt!=bonusiObjects[i29].mig_time)
{bonusiObjects[i29].visible=false;
bonusiObjects[i29].mig_time=perez_akt;
bonusiObjects[i29].mig_time_milli=GetTime();}

if(bonusiObjects[i29].mig_time_milli>=750&&bonusiObjects[i29].visible==false&&
perez_akt_milli>=bonusiObjects[i29].mig_time_milli-750&&perez_akt!=bonusiObjects[i29].mig_time)
{bonusiObjects[i29].visible=true;
bonusiObjects[i29].mig_time=perez_akt;
bonusiObjects[i29].mig_time_milli=GetTime();}

}//if bonusiObjects[i29].mig_akt==1

if((bonusiObjects[i29].appear_time<50&&perez_akt==bonusiObjects[i29].appear_time+10&&
   perez_akt_milli>=bonusiObjects[i29].appear_time_milli)||
   (bonusiObjects[i29].appear_time>=50&&perez_akt==bonusiObjects[i29].appear_time-50&&
   perez_akt_milli>=bonusiObjects[i29].appear_time_milli))
{bonusiObjects[i29].akt=-1;}
}//закрытие исчезновения бонусов


}//закрытие бонусов


//-------------$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$-----------------------------




//ТЕКСТЫ БОНУСОВ

for(int i55=0;i55<=N_BONUSTEXT;i55++)
{

if(bonustextiObjects[i55].akt==1)
{
//текст движется
if((bonustextiObjects[i55].akt_time<57&&perez_akt<=bonustextiObjects[i55].akt_time+3)||
   (bonustextiObjects[i55].akt_time==57&&(perez_akt==57||perez_akt==58||(perez_akt==59&&
   perez_akt_milli<=bonustextiObjects[i55].akt_time_milli)))||
   (bonustextiObjects[i55].akt_time==58&&(perez_akt==58||perez_akt==59||(perez_akt==0&&
   perez_akt_milli<=bonustextiObjects[i55].akt_time_milli)))||
   (bonustextiObjects[i55].akt_time==59&&(perez_akt==59||perez_akt==0||(perez_akt==1&&
   perez_akt_milli<=bonustextiObjects[i55].akt_time_milli))))
{bonustextiObjects[i55].y-=0.5f;}
//текст исчезает
if((bonustextiObjects[i55].akt_time<57&&perez_akt==bonustextiObjects[i55].akt_time+3&&
   perez_akt_milli>=bonustextiObjects[i55].akt_time_milli)||
   (bonustextiObjects[i55].akt_time>=57&&perez_akt==bonustextiObjects[i55].akt_time-57&&
   perez_akt_milli>=bonustextiObjects[i55].akt_time_milli))
{bonustextiObjects[i55].akt=0;}

}

}


//ПУЛЯ ИГРОКА 1
if(oboima>0)//если в обойме есть пули	
{

if(aktivatorp==0)//если не открыт огонь
{px=x-24;
if(N_WEAPON1!=14)
{py=y-9;}
if(N_WEAPON1==14)
{py=y-13;}
}

if(aktivatorp1d1==0)
{p1d1x=x-24;  p1d1y=y-9;}
if(aktivatorp1d2==0)
{p1d2x=x-24;  p1d2y=y-9;}
if(aktivatorp1d3==0)
{p1d3x=x-24;  p1d3y=y-9;}
if(aktivatorp1d4==0)
{p1d4x=x-24;  p1d4y=y-9;}

shot=0;
}//в обойме есть пули

if(aktivatorp==1)//если открыт огонь
{
//скорость пули 
if(N_WEAPON1!=3&&N_WEAPON1!=6)
{px-=150*lag_p;}
}

if(N_WEAPON1==7)
{
if(aktivatorp1d1==1)	
{p1d1x-=110*lag_p;}
if(aktivatorp1d2==1)
{p1d2x-=110*lag_p;}
if(aktivatorp1d3==1)
{p1d3x-=110*lag_p;}
if(aktivatorp1d4==1)
{p1d4x-=110*lag_p;}
}


if(N_WEAPON1==3||N_WEAPON1==6) //FN F2000 и MAC
{px-=150*lag_p;
}



//просчёт рандома--------------------->>>>>>>>>>>>>>>>>

if(N_WEAPON1!=7&&N_WEAPON1!=10&&N_WEAPON1!=11&&N_WEAPON1!=12&&N_WEAPON1!=13)
{
if(px<=x-(random_rasst_min[N_WEAPON1]+24)&&px>x-(random_rasst_max[N_WEAPON1]+24))
{py+=hge->Random_Float(-random_value1[N_WEAPON1]*tochnost1,random_value1[N_WEAPON1]*tochnost1);}//рандом на x

if(px<=x-(random_rasst_max[N_WEAPON1]+24))//если пуля на расстоянии от 400
{
if(py>y-9)//если раньше пуля улетела вниз
{py+=hge->Random_Float(0,random_value2[N_WEAPON1]*tochnost1);}
if(py<y-9)//если раньше пуля улетела вверх
{py+=hge->Random_Float(-random_value2[N_WEAPON1]*tochnost1,0);}
if(py==y-9)//если раньше пуля не отклонилась
{py+=hge->Random_Float(-random_value2[N_WEAPON1]*tochnost1,random_value2[N_WEAPON1]*tochnost1);}
}
}


if(N_WEAPON1==7)//WINCHESTER
{
if(px<=x-224&&px>x-424)//еслю пуля на расстоянии от 200 до 400	
{py+=hge->Random_Float(-1*tochnost1,1*tochnost1);}//рандом на 1

if(px<=x-424)//если пуля на расстоянии от 400
{
if(py>y-9)//если раньше пуля улетела вниз
{py+=hge->Random_Float(0,3*tochnost1);}
if(py<y-9)//если раньше пуля улетела вверх
{py+=hge->Random_Float(-3*tochnost1,0);}
if(py==y-9)//если раньше пуля не отклонилась
{py+=hge->Random_Float(-3*tochnost1,3*tochnost1);}
}

if(p1d1x<=x-224&&p1d1x>x-424)//еслю пуля на расстоянии от 200 до 400	
{p1d1y+=hge->Random_Float(-7*tochnost1,7*tochnost1);}//рандом на 7

if(p1d1x<=x-424)//если пуля на расстоянии от 400
{
if(p1d1y>y-9)//если раньше пуля улетела вниз
{p1d1y+=hge->Random_Float(0,15*tochnost1);}
if(p1d1y<y-9)//если раньше пуля улетела вверх
{p1d1y+=hge->Random_Float(-15*tochnost1,0);}
if(p1d1y==y-9)//если раньше пуля не отклонилась
{p1d1y+=hge->Random_Float(-15*tochnost1,15*tochnost1);}
}

if(p1d4x<=x-224&&p1d4x>x-424)//еслю пуля на расстоянии от 200 до 400	
{p1d4y+=hge->Random_Float(-7*tochnost1,7*tochnost1);}//рандом на 7

if(p1d4x<=x-424)//если пуля на расстоянии от 400
{
if(p1d4y>y-9)//если раньше пуля улетела вниз
{p1d4y+=hge->Random_Float(0,15*tochnost1);}
if(p1d4y<y-9)//если раньше пуля улетела вверх
{p1d4y+=hge->Random_Float(-15*tochnost1,0);}
if(p1d4y==y-9)//если раньше пуля не отклонилась
{p1d4y+=hge->Random_Float(-15*tochnost1,15*tochnost1);}
}


if(p1d2x<=x-224&&p1d2x>x-424)//еслю пуля на расстоянии от 200 до 400	
{p1d2y+=hge->Random_Float(-3*tochnost1,3*tochnost1);}//рандом на 3

if(p1d2x<=x-424)//если пуля на расстоянии от 400
{
if(p1d2y>y-9)//если раньше пуля улетела вниз
{p1d2y+=hge->Random_Float(0,8*tochnost1);}
if(p1d2y<y-9)//если раньше пуля улетела вверх
{p1d2y+=hge->Random_Float(-8*tochnost1,0);}
if(p1d2y==y-9)//если раньше пуля не отклонилась
{p1d2y+=hge->Random_Float(-8*tochnost1,8*tochnost1);}
}

if(p1d3x<=x-224&&p1d3x>x-424)//еслю пуля на расстоянии от 200 до 400	
{p1d3y+=hge->Random_Float(-3*tochnost1,3*tochnost1);}//рандом на 3

if(p1d3x<=x-424)//если пуля на расстоянии от 400
{
if(p1d3y>y-9)//если раньше пуля улетела вниз
{p1d3y+=hge->Random_Float(0,8*tochnost1);}
if(p1d3y<y-9)//если раньше пуля улетела вверх
{p1d3y+=hge->Random_Float(-8*tochnost1,0);}
if(p1d3y==y-9)//если раньше пуля не отклонилась
{p1d3y+=hge->Random_Float(-8*tochnost1,8*tochnost1);}
}

} //закрытие про WINCHESTER







if(px<-100&&aktivatorp==1)//если пуля долетела до конца экрана
{aktivatorp=0;
oboima-=1;
px=x-24;
if(N_WEAPON1!=14)
{py=y-9;}
if(N_WEAPON1==14)
{py=y-13;}
}


if(p1d1x<-100)
{aktivatorp1d1=0;
p1d1x=x-24;  p1d1y=y-9;}
if(p1d2x<-100)
{aktivatorp1d2=0;
p1d2x=x-24;  p1d2y=y-9;}
if(p1d3x<-100)
{aktivatorp1d3=0;
p1d3x=x-24;  p1d3y=y-9;}
if(p1d4x<-100)
{aktivatorp1d4=0;
p1d4x=x-24;  p1d4y=y-9;}

	


if(oboima<=0)
{px=x-24;
if(N_WEAPON1!=14)
{py=y-9;}
if(N_WEAPON1==14)
{py=y-13;}

if(aktivatorp1d1==0)
{p1d1x=x-24;  p1d1y=y-9;}
if(aktivatorp1d2==0)
{p1d2x=x-24;  p1d2y=y-9;}
if(aktivatorp1d3==0)
{p1d3x=x-24;  p1d3y=y-9;}
if(aktivatorp1d4==0)
{p1d4x=x-24;  p1d4y=y-9;}

}
//ЗАКРЫТИЕ ПУЛИ ИГРОКА 1


//ПУЛЯ ИГРОКА 2
if(oboima2>0)//если в обойме есть пули	
{

if(aktivatorp2==0)//если не открыт огонь
{p2x=x2-24;
if(N_WEAPON2!=14)
{p2y=y2-9;}
if(N_WEAPON2==14)
{p2y=y2-13;}

p2d1x=x2-24;  p2d1y=y2-9;
p2d2x=x2-24;  p2d2y=y2-9;
p2d3x=x2-24;  p2d3y=y2-9;
p2d4x=x2-24;  p2d4y=y2-9;

shot=0;
}

if(aktivatorp2==1)//если открыт огонь
{
//скорость пули
if(N_WEAPON2!=3&&N_WEAPON2!=6)
{p2x-=150*lag_p;

if(N_WEAPON2==7)
{p2d1x-=110*lag_p;
p2d2x-=110*lag_p;
p2d3x-=110*lag_p;
p2d4x-=110*lag_p;}

}
if(N_WEAPON2==3||N_WEAPON2==6) //FN F2000 и MAC
{p2x-=150*lag_p;
}




//просчёт рандома--------------------->>>>>>>>>>>>>>>>>


if(N_WEAPON2!=7&&N_WEAPON2!=10&&N_WEAPON2!=11&&N_WEAPON2!=12&&N_WEAPON2!=13)
{
if(p2x<=x2-(random_rasst_min[N_WEAPON2]+24)&&p2x>x2-(random_rasst_max[N_WEAPON2]+24))
{p2y+=hge->Random_Float(-random_value1[N_WEAPON2]*tochnost2,random_value1[N_WEAPON2]*tochnost2);}//рандом на x

if(p2x<=x2-(random_rasst_max[N_WEAPON2]+24))//если пуля на расстоянии от 400
{
if(p2y>y2-9)//если раньше пуля улетела вниз
{p2y+=hge->Random_Float(0,random_value2[N_WEAPON2]*tochnost2);}
if(p2y<y2-9)//если раньше пуля улетела вверх
{p2y+=hge->Random_Float(-random_value2[N_WEAPON2]*tochnost2,0);}
if(p2y==y2-9)//если раньше пуля не отклонилась
{p2y+=hge->Random_Float(-random_value2[N_WEAPON2]*tochnost2,random_value2[N_WEAPON2]*tochnost2);}
}
}


if(N_WEAPON2==7)//WINCHESTER
{
if(p2x<=x2-224&&p2x>x2-424)//еслю пуля на расстоянии от 200 до 400	
{p2y+=hge->Random_Float(-1*tochnost2,1*tochnost2);}//рандом на 1

if(p2x<=x2-424)//если пуля на расстоянии от 400
{
if(p2y>y2-9)//если раньше пуля улетела вниз
{p2y+=hge->Random_Float(0,3*tochnost2);}
if(p2y<y2-9)//если раньше пуля улетела вверх
{p2y+=hge->Random_Float(-3*tochnost2,0);}
if(p2y==y2-9)//если раньше пуля не отклонилась
{p2y+=hge->Random_Float(-3*tochnost2,3*tochnost2);}
}

if(p2d1x<=x2-224&&p2d1x>x2-424)//еслю пуля на расстоянии от 200 до 400	
{p2d1y+=hge->Random_Float(-7*tochnost2,7*tochnost2);}//рандом на 7

if(p2d1x<=x2-424)//если пуля на расстоянии от 400
{
if(p2d1y>y2-9)//если раньше пуля улетела вниз
{p2d1y+=hge->Random_Float(0,15*tochnost2);}
if(p2d1y<y2-9)//если раньше пуля улетела вверх
{p2d1y+=hge->Random_Float(-15*tochnost2,0);}
if(p2d1y==y2-9)//если раньше пуля не отклонилась
{p2d1y+=hge->Random_Float(-15*tochnost2,15*tochnost2);}
}

if(p2d4x<=x2-224&&p2d4x>x2-424)//еслю пуля на расстоянии от 200 до 400	
{p2d4y+=hge->Random_Float(-7*tochnost2,7*tochnost2);}//рандом на 7

if(p2d4x<=x2-424)//если пуля на расстоянии от 400
{
if(p2d4y>y2-9)//если раньше пуля улетела вниз
{p2d4y+=hge->Random_Float(0,15*tochnost2);}
if(p2d4y<y2-9)//если раньше пуля улетела вверх
{p2d4y+=hge->Random_Float(-15*tochnost2,0);}
if(p2d4y==y2-9)//если раньше пуля не отклонилась
{p2d4y+=hge->Random_Float(-15*tochnost2,15*tochnost2);}
}


if(p2d2x<=x2-224&&p2d2x>x2-424)//еслю пуля на расстоянии от 200 до 400	
{p2d2y+=hge->Random_Float(-3*tochnost2,3*tochnost2);}//рандом на 3

if(p2d2x<=x2-424)//если пуля на расстоянии от 400
{
if(p2d2y>y2-9)//если раньше пуля улетела вниз
{p2d2y+=hge->Random_Float(0,8*tochnost2);}
if(p2d2y<y2-9)//если раньше пуля улетела вверх
{p2d2y+=hge->Random_Float(-8*tochnost2,0);}
if(p2d2y==y2-9)//если раньше пуля не отклонилась
{p2d2y+=hge->Random_Float(-8*tochnost2,8*tochnost2);}
}

if(p2d3x<=x2-224&&p2d3x>x2-424)//еслю пуля на расстоянии от 200 до 400	
{p2d3y+=hge->Random_Float(-3*tochnost2,3*tochnost2);}//рандом на 3

if(p2d3x<=x2-424)//если пуля на расстоянии от 400
{
if(p2d3y>y2-9)//если раньше пуля улетела вниз
{p2d3y+=hge->Random_Float(0,8*tochnost2);}
if(p2d3y<y2-9)//если раньше пуля улетела вверх
{p2d3y+=hge->Random_Float(-8*tochnost2,0);}
if(p2d3y==y2-9)//если раньше пуля не отклонилась
{p2d3y+=hge->Random_Float(-8*tochnost2,8*tochnost2);}
}

} //закрытие про WINCHESTER




if(p2x<-100&&aktivatorp2==1)//если пуля 2 долетела до конца экрана
{aktivatorp2=0;
oboima2-=1;
p2x=x2-24;
if(N_WEAPON2!=14)
{p2y=y2-9;}
if(N_WEAPON2==14)
{p2y=y2-13;}}

if(p2d1x<-100)
{p2d1x=x2-24;  p2d1y=y2-9;}
if(p2d2x<-100)
{p2d2x=x2-24;  p2d2y=y2-9;}
if(p2d3x<-100)
{p2d3x=x2-24;  p2d3y=y2-9;}
if(p2d4x<-100)
{p2d4x=x2-24;  p2d4y=y2-9;}





}	






}
if(oboima2<=0)
{p2x=x2-24;
if(N_WEAPON2!=14)
{p2y=y2-9;}
if(N_WEAPON2==14)
{p2y=y2-13;}
p2d1x=x2-24;  p2d1y=y2-9;
p2d2x=x2-24;  p2d2y=y2-9;
p2d3x=x2-24;  p2d3y=y2-9;
p2d4x=x2-24;  p2d4y=y2-9;
}

//ЗАКРЫТИЕ ПУЛИ





//координаты огня выстрела
switch (N_WEAPON1)
{case 0:	
if(ak_tex==0)
{a=x-56;}
if(ak_tex==1)
{a=x-61;}
b=y-9;
break;
case 1:
case 9:
a=x-33;
b=y-10;
break;
case 2:
a=x-47;
b=y-9;
break;
case 3:
a=x-59;
b=y-11;
break;
case 4:
a=x-37;
b=y-10;
break;
case 5:
case 8:
a=x-71;
b=y-8;
break;
case 6:
a=x-30;
b=y-9;
break;
case 7:
a=x-81;
b=y-11;
break;
case 14:
a=x-40;
b=y-13;
break;
case 15:
a=x-36;
b=y-10;
break;
}


//координаты огня выстрела игрока 2
switch (N_WEAPON2)
{case 0:	
if(ak_tex==0)
{a2=x2-56;}
if(ak_tex==1)
{a2=x2-61;}
b2=y2-9;
break;
case 1:
case 9:
a2=x2-33;
b2=y2-10;
break;
case 2:
a2=x2-47;
b2=y2-9;
break;
case 3:
a2=x2-59;
b2=y2-11;
break;
case 4:
a2=x2-37;
b2=y2-10;
break;
case 5:
case 8:
a2=x2-71;
b2=y2-8;
break;
case 6:
a2=x2-30;
b2=y2-9;
break;
case 7:
a2=x2-81;
b2=y2-11;
break;
case 14:
a2=x2-40;
b2=y2-13;
break;
case 15:
a2=x2-36;
b2=y2-10;
break;
}


//летящие  гильзы

for(int i180=0;i180<=MAX_GILZ-1;i180++)
{

if(gilziObjects[i180].akt==1&&gilziObjects[i180].y<=gilziObjects[i180].niz)
{
if(gilziObjects[i180].x<=gilziObjects[i180].xstart+gilziObjects[i180].randomx)
{gilziObjects[i180].x+=0.5f*lag;
gilziObjects[i180].y-=0.1f*(gilziObjects[i180].xstart+gilziObjects[i180].randomx-gilziObjects[i180].x)*lag;}

if(gilziObjects[i180].x>=gilziObjects[i180].xstart+gilziObjects[i180].randomx)
{gilziObjects[i180].x+=0.5f*lag;
gilziObjects[i180].y+=0.04f*(gilziObjects[i180].x-gilziObjects[i180].xstart+gilziObjects[i180].randomx)*lag;}

}

if(gilziObjects[i180].y>=gilziObjects[i180].niz)
{gilziObjects[i180].akt=0;}



}//закрытие гильз



//ЛЕТЯЩИЕ ГРЕНКИ!!!!!!!------------------------------------
for(int i70=0;i70<=MAX_GREN-1;i70++)
{
if(granati[i70].akt==1)
{granati[i70].x-=granati[i70].speedX*lag;
granati[i70].y-=granati[i70].speedY*(granati[i70].x-granati[i70].osX)*lag;
if(granati[i70].type==1)
{granati[i70].gradus+=M_PI_4/4*lag;}

int rocketPan=-75+granati[i70].x/9;
if(granati[i70].type==3&&granati[i70].x>0)
{if(granati[i70].owner==1)
{hge->Effect_PlayEx(rocket_polet,volume,rocketPan,0);}
if(granati[i70].owner==2)
{hge->Effect_PlayEx(rocket2_polet,volume,rocketPan,0);}}
if(granati[i70].type==3&&granati[i70].x<=0)
{if(granati[i70].owner==1)
{hge->Effect_PlayEx(rocket_polet,volume,-100,0);}
if(granati[i70].owner==2)
{hge->Effect_PlayEx(rocket2_polet,volume,-100,0);}}
}

if(granati[i70].akt==1&&granati[i70].x<granati[i70].osX&&granati[i70].y>=granati[i70].osY-16)
{granati[i70].akt=0;}

if((granati[i70].type==2||granati[i70].type==3)&&granati[i70].akt==1)//гранаты из подствольника или РПГ детонируют при контакте с врагом
{
for (int i132=0;i132<=N_ZAYAC;i132++)
{
if(granati[i70].x<=vragi1Objects[i132].v1x+10&&granati[i70].x>vragi1Objects[i132].v1x-100*lag&&
granati[i70].y<=vragi1Objects[i132].v1y+44&&granati[i70].y>vragi1Objects[i132].v1y+5&&
vragi1Objects[i132].ubit!=1)
{granati[i70].akt=0;}
}
for (int i133=0;i133<=N_VOLK;i133++)
{
if(granati[i70].x<=vragi2Objects[i133].v2x+100&&granati[i70].x>vragi2Objects[i133].v2x-150*lag&&
granati[i70].y<=vragi2Objects[i133].v2y+50&&granati[i70].y>vragi2Objects[i133].v2y&&
vragi2Objects[i133].ubit!=1)
{granati[i70].akt=0;}
}
for (int i134=0;i134<=N_MEDVED;i134++)
{
if(granati[i70].x<=vragi3Objects[i134].v3x+100&&granati[i70].x>vragi3Objects[i134].v3x-300*lag&&
granati[i70].y<=vragi3Objects[i134].v3y+200&&granati[i70].y>vragi3Objects[i134].v3y+105&&
vragi3Objects[i134].ubit!=1)
{granati[i70].akt=0;}
}
for (int i135=0;i135<=N_PTENEC;i135++)
{
if(granati[i70].x<=vragi4Objects[i135].v4x&&granati[i70].x>vragi4Objects[i135].v4x-40*lag&&
granati[i70].y<=vragi4Objects[i135].v4y+22&&granati[i70].y>vragi4Objects[i135].v4y&&
vragi4Objects[i135].ubit!=1)
{granati[i70].akt=0;}
}

}

if(granati[i70].akt==0)//ВЗРЫВ!!!---------
{vzriv_grena_psi->FireAt(granati[i70].x,granati[i70].y);
vzriv_ogon_grena_psi->FireAt(granati[i70].x,granati[i70].y);
hge->Effect_PlayEx(vzriv_grena1,volume*9/10,-75+granati[i70].x/9,0);

//про зайцев----
for (int i56=0;i56<=N_ZAYAC;i56++)
{

if(RPGMOD==false)	
{	//радиус
if(granati[i70].x-vragi1Objects[i56].v1x<=radius_vzriva[granati[i70].type]&&granati[i70].x-vragi1Objects[i56].v1x>=-radius_vzriva[granati[i70].type]&&
  granati[i70].y-vragi1Objects[i56].v1y<=radius_vzriva[granati[i70].type]&&granati[i70].y-vragi1Objects[i56].v1y>=-radius_vzriva[granati[i70].type])
  //УРОН ОТ ВЗРЫВЧАТКИ
{

vragi1Objects[i56].health-=damage_gren[granati[i70].type]*(radius_vzriva[granati[i70].type]-sqrt((granati[i70].x-vragi1Objects[i56].v1x)*(granati[i70].x-vragi1Objects[i56].v1x)+
(granati[i70].y-vragi1Objects[i56].v1y)*(granati[i70].y-vragi1Objects[i56].v1y)))/radius_vzriva[granati[i70].type];



//энергия взрыва
vragi1Objects[i56].energy=(radius_vzriva[granati[i70].type]-sqrt((granati[i70].x-vragi1Objects[i56].v1x)*(granati[i70].x-vragi1Objects[i56].v1x)+
(granati[i70].y-vragi1Objects[i56].v1y)*(granati[i70].y-vragi1Objects[i56].v1y)))/radius_vzriva[granati[i70].type];


//определение расстояния
if(granati[i70].x>=vragi1Objects[i56].v1x)
{vragi1Objects[i56].rasstX=granati[i70].x-vragi1Objects[i56].v1x;}
if(granati[i70].x<=vragi1Objects[i56].v1x)
{vragi1Objects[i56].rasstX=vragi1Objects[i56].v1x-granati[i70].x;}
if(granati[i70].y>=vragi1Objects[i56].v1y)
{vragi1Objects[i56].rasstY=granati[i70].y-vragi1Objects[i56].v1y;}
if(granati[i70].y<=vragi1Objects[i56].v1y)
{vragi1Objects[i56].rasstY=vragi1Objects[i56].v1y-granati[i70].y;}

//направление щей (четверти)
if(granati[i70].x<vragi1Objects[i56].v1x&&granati[i70].y>=vragi1Objects[i56].v1y)
{vragi1Objects[i56].chetvert=1;}
if(granati[i70].x<vragi1Objects[i56].v1x&&granati[i70].y<vragi1Objects[i56].v1y)
{vragi1Objects[i56].chetvert=2;}
if(granati[i70].x>=vragi1Objects[i56].v1x&&granati[i70].y<vragi1Objects[i56].v1y)
{vragi1Objects[i56].chetvert=3;}
if(granati[i70].x>=vragi1Objects[i56].v1x&&granati[i70].y>=vragi1Objects[i56].v1y)
{vragi1Objects[i56].chetvert=4;}
}
}


if(RPGMOD==true)	
{
//---

//РАДИУС ИГРОКА 1	
if(granati[i70].owner==1)
{	
//радиус
if(granati[i70].x-vragi1Objects[i56].v1x<=radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)&&granati[i70].x-vragi1Objects[i56].v1x>=-radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)&&
  granati[i70].y-vragi1Objects[i56].v1y<=radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)&&granati[i70].y-vragi1Objects[i56].v1y>=-radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1))
  //УРОН ОТ ВЗРЫВЧАТКИ
{

if(LVL1%2==0)	
{vragi1Objects[i56].health-=(damage_gren[granati[i70].type]+attack1*LVL1/2)*(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)-sqrt((granati[i70].x-vragi1Objects[i56].v1x)*(granati[i70].x-vragi1Objects[i56].v1x)+
(granati[i70].y-vragi1Objects[i56].v1y)*(granati[i70].y-vragi1Objects[i56].v1y)))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1);}
if(LVL1%2==1)	
{vragi1Objects[i56].health-=(damage_gren[granati[i70].type]+attack1*(LVL1-1)/2)*(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)-sqrt((granati[i70].x-vragi1Objects[i56].v1x)*(granati[i70].x-vragi1Objects[i56].v1x)+
(granati[i70].y-vragi1Objects[i56].v1y)*(granati[i70].y-vragi1Objects[i56].v1y)))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1);}
//энергия взрыва
vragi1Objects[i56].energy=(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)-sqrt((granati[i70].x-vragi1Objects[i56].v1x)*(granati[i70].x-vragi1Objects[i56].v1x)+
(granati[i70].y-vragi1Objects[i56].v1y)*(granati[i70].y-vragi1Objects[i56].v1y)))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1);


//определение расстояния
if(granati[i70].x>=vragi1Objects[i56].v1x)
{vragi1Objects[i56].rasstX=granati[i70].x-vragi1Objects[i56].v1x;}
if(granati[i70].x<=vragi1Objects[i56].v1x)
{vragi1Objects[i56].rasstX=vragi1Objects[i56].v1x-granati[i70].x;}
if(granati[i70].y>=vragi1Objects[i56].v1y)
{vragi1Objects[i56].rasstY=granati[i70].y-vragi1Objects[i56].v1y;}
if(granati[i70].y<=vragi1Objects[i56].v1y)
{vragi1Objects[i56].rasstY=vragi1Objects[i56].v1y-granati[i70].y;}

if(vragi1Objects[i56].rasstX<20)
{vragi1Objects[i56].rasstX=20;}
if(vragi1Objects[i56].rasstY<20)
{vragi1Objects[i56].rasstY=20;}

//направление щей (четверти)
if(granati[i70].x<vragi1Objects[i56].v1x&&granati[i70].y>=vragi1Objects[i56].v1y)
{vragi1Objects[i56].chetvert=1;}
if(granati[i70].x<vragi1Objects[i56].v1x&&granati[i70].y<vragi1Objects[i56].v1y)
{vragi1Objects[i56].chetvert=2;}
if(granati[i70].x>=vragi1Objects[i56].v1x&&granati[i70].y<vragi1Objects[i56].v1y)
{vragi1Objects[i56].chetvert=3;}
if(granati[i70].x>=vragi1Objects[i56].v1x&&granati[i70].y>=vragi1Objects[i56].v1y)
{vragi1Objects[i56].chetvert=4;}


}
}

//РАДИУС ИГРОКА 2
if(granati[i70].owner==2)
{	
//радиус
if(granati[i70].x-vragi1Objects[i56].v1x<=radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)&&granati[i70].x-vragi1Objects[i56].v1x>=-radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)&&
  granati[i70].y-vragi1Objects[i56].v1y<=radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)&&granati[i70].y-vragi1Objects[i56].v1y>=-radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2))
  //УРОН ОТ ВЗРЫВЧАТКИ
{
if(LVL2%2==0)
{vragi1Objects[i56].health-=(damage_gren[granati[i70].type]+attack2*LVL2/2)*(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)-sqrt((granati[i70].x-vragi1Objects[i56].v1x)*(granati[i70].x-vragi1Objects[i56].v1x)+
(granati[i70].y-vragi1Objects[i56].v1y)*(granati[i70].y-vragi1Objects[i56].v1y)))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2);}
if(LVL2%2==1)
{vragi1Objects[i56].health-=(damage_gren[granati[i70].type]+attack2*(LVL2-1)/2)*(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)-sqrt((granati[i70].x-vragi1Objects[i56].v1x)*(granati[i70].x-vragi1Objects[i56].v1x)+
(granati[i70].y-vragi1Objects[i56].v1y)*(granati[i70].y-vragi1Objects[i56].v1y)))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2);}

//энергия взрыва
vragi1Objects[i56].energy=(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)-sqrt((granati[i70].x-vragi1Objects[i56].v1x)*(granati[i70].x-vragi1Objects[i56].v1x)+
(granati[i70].y-vragi1Objects[i56].v1y)*(granati[i70].y-vragi1Objects[i56].v1y)))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2);


//определение расстояния
if(granati[i70].x>=vragi1Objects[i56].v1x)
{vragi1Objects[i56].rasstX=granati[i70].x-vragi1Objects[i56].v1x;}
if(granati[i70].x<=vragi1Objects[i56].v1x)
{vragi1Objects[i56].rasstX=vragi1Objects[i56].v1x-granati[i70].x;}
if(granati[i70].y>=vragi1Objects[i56].v1y)
{vragi1Objects[i56].rasstY=granati[i70].y-vragi1Objects[i56].v1y;}
if(granati[i70].y<=vragi1Objects[i56].v1y)
{vragi1Objects[i56].rasstY=vragi1Objects[i56].v1y-granati[i70].y;}

if(vragi1Objects[i56].rasstX<20)
{vragi1Objects[i56].rasstX=20;}
if(vragi1Objects[i56].rasstY<20)
{vragi1Objects[i56].rasstY=20;}

//направление щей (четверти)
if(granati[i70].x<vragi1Objects[i56].v1x&&granati[i70].y>=vragi1Objects[i56].v1y)
{vragi1Objects[i56].chetvert=1;}
if(granati[i70].x<vragi1Objects[i56].v1x&&granati[i70].y<vragi1Objects[i56].v1y)
{vragi1Objects[i56].chetvert=2;}
if(granati[i70].x>=vragi1Objects[i56].v1x&&granati[i70].y<vragi1Objects[i56].v1y)
{vragi1Objects[i56].chetvert=3;}
if(granati[i70].x>=vragi1Objects[i56].v1x&&granati[i70].y>=vragi1Objects[i56].v1y)
{vragi1Objects[i56].chetvert=4;}


}
}

//---
}//RPGMOD==TRUE






if(RPGMOD==true)
{vragi1Objects[i56].health+=vragi1Objects[i56].defence;
if(vragi1Objects[i56].health>50)
{vragi1Objects[i56].health=50;}
}//RPGMOD

//убил!:'(
if(vragi1Objects[i56].health<=0)
{
vragi1Objects[i56].vzorvan=true;
if(granati[i70].owner==1)
{vragi1Objects[i56].killed_by=1;}
if(granati[i70].owner==2)
{vragi1Objects[i56].killed_by=2;}
}

}//про зайцев-----


//про волков----
for (int i57=0;i57<=N_VOLK;i57++)
{

	
if(RPGMOD==false)	
{	//радиус
if(granati[i70].x-vragi2Objects[i57].v2x<=radius_vzriva[granati[i70].type]&&granati[i70].x-vragi2Objects[i57].v2x>=-radius_vzriva[granati[i70].type]&&
  granati[i70].y-vragi2Objects[i57].v2y<=radius_vzriva[granati[i70].type]&&granati[i70].y-vragi2Objects[i57].v2y>=-radius_vzriva[granati[i70].type])
  //УРОН ОТ ВЗРЫВЧАТКИ
{
vragi2Objects[i57].health-=damage_gren[granati[i70].type]*(radius_vzriva[granati[i70].type]-sqrt((granati[i70].x-vragi2Objects[i57].v2x)*(granati[i70].x-vragi2Objects[i57].v2x)+
(granati[i70].y-vragi2Objects[i57].v2y)*(granati[i70].y-vragi2Objects[i57].v2y)))/radius_vzriva[granati[i70].type];

}
}


if(RPGMOD==true)	
{
//РАДИУС ИГРОКА 1	
if(granati[i70].owner==1)
{	
//радиус
if(granati[i70].x-vragi2Objects[i57].v2x<=radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)&&granati[i70].x-vragi2Objects[i57].v2x>=-radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)&&
  granati[i70].y-vragi2Objects[i57].v2y<=radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)&&granati[i70].y-vragi2Objects[i57].v2y>=-radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1))
 //УРОН ОТ ВЗРЫВЧАТКИ
{
 if(LVL1%2==0)
 {vragi2Objects[i57].health-=(damage_gren[granati[i70].type]+attack1*LVL1/2)*(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)-sqrt((granati[i70].x-vragi2Objects[i57].v2x)*(granati[i70].x-vragi2Objects[i57].v2x)+
 (granati[i70].y-vragi2Objects[i57].v2y)*(granati[i70].y-vragi2Objects[i57].v2y)))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1);}
if(LVL1%2==1)
 {vragi2Objects[i57].health-=(damage_gren[granati[i70].type]+attack1*(LVL1-1)/2)*(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)-sqrt((granati[i70].x-vragi2Objects[i57].v2x)*(granati[i70].x-vragi2Objects[i57].v2x)+
(granati[i70].y-vragi2Objects[i57].v2y)*(granati[i70].y-vragi2Objects[i57].v2y)))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1);}
}
}

//РАДИУС ИГРОКА 2
if(granati[i70].owner==2)
{	
//радиус 
if(granati[i70].x-vragi2Objects[i57].v2x<=radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)&&granati[i70].x-vragi2Objects[i57].v2x>=-radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)&&
  granati[i70].y-vragi2Objects[i57].v2y<=radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)&&granati[i70].y-vragi2Objects[i57].v2y>=-radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2))
  //УРОН ОТ ВЗРЫВЧАТКИ
{
if(LVL2%2==0)
{vragi2Objects[i57].health-=(damage_gren[granati[i70].type]+attack1*LVL2/2)*(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)-sqrt((granati[i70].x-vragi2Objects[i57].v2x)*(granati[i70].x-vragi2Objects[i57].v2x)+
(granati[i70].y-vragi2Objects[i57].v2y)*(granati[i70].y-vragi2Objects[i57].v2y)))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2);}
if(LVL2%2==1)
{vragi2Objects[i57].health-=(damage_gren[granati[i70].type]+attack1*(LVL2-1)/2)*(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)-sqrt((granati[i70].x-vragi2Objects[i57].v2x)*(granati[i70].x-vragi2Objects[i57].v2x)+
(granati[i70].y-vragi2Objects[i57].v2y)*(granati[i70].y-vragi2Objects[i57].v2y)))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2);}
}
}

}//RPGMOD==TRUE



if(RPGMOD==true)
{vragi2Objects[i57].health+=vragi2Objects[i57].defence;

if(vragi2Objects[i57].health>125)
{vragi2Objects[i57].health=125;}
}//RPGMOD

//убил!:'(
if(vragi2Objects[i57].health<=0)
{
if(granati[i70].owner==1)
{vragi2Objects[i57].killed_by=1;}
if(granati[i70].owner==2)
{vragi2Objects[i57].killed_by=2;}
}

}//про волков--------


//про медведей----
for (int i83=0;i83<=N_MEDVED;i83++)
{

	
if(RPGMOD==false)	
{	//радиус
if(granati[i70].x-(vragi3Objects[i83].v3x+90)<=radius_vzriva[granati[i70].type]&&granati[i70].x-(vragi3Objects[i83].v3x+90)>=-radius_vzriva[granati[i70].type]&&
  granati[i70].y-(vragi3Objects[i83].v3y+110)<=radius_vzriva[granati[i70].type]&&granati[i70].y-(vragi3Objects[i83].v3y+110)>=-radius_vzriva[granati[i70].type])
  //УРОН ОТ ВЗРЫВЧАТКИ
{
vragi3Objects[i83].health-=damage_gren[granati[i70].type]*(radius_vzriva[granati[i70].type]-sqrt((granati[i70].x-(vragi3Objects[i83].v3x+90))*(granati[i70].x-(vragi3Objects[i83].v3x+90))+
(granati[i70].y-(vragi3Objects[i83].v3y+110))*(granati[i70].y-(vragi3Objects[i83].v3y+110))))/radius_vzriva[granati[i70].type];
}
}


if(RPGMOD==true)	
{
//РАДИУС ИГРОКА 1	
if(granati[i70].owner==1)
{	
//радиус 
if(granati[i70].x-(vragi3Objects[i83].v3x+90)<=radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)&&granati[i70].x-(vragi3Objects[i83].v3x+90)>=-radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)&&
  granati[i70].y-(vragi3Objects[i83].v3y+110)<=radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)&&granati[i70].y-(vragi3Objects[i83].v3y+110)>=-radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1))
  //УРОН ОТ ВЗРЫВЧАТКИ
{
if(LVL1%2==0)
{vragi3Objects[i83].health-=(damage_gren[granati[i70].type]+attack1*LVL1/2)*(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)-sqrt((granati[i70].x-(vragi3Objects[i83].v3x+90))*(granati[i70].x-(vragi3Objects[i83].v3x+90))+
(granati[i70].y-(vragi3Objects[i83].v3y+110))*(granati[i70].y-(vragi3Objects[i83].v3y+110))))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1);}
if(LVL1%2==1)
{vragi3Objects[i83].health-=(damage_gren[granati[i70].type]+attack1*(LVL1-1)/2)*(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)-sqrt((granati[i70].x-(vragi3Objects[i83].v3x+90))*(granati[i70].x-(vragi3Objects[i83].v3x+90))+
(granati[i70].y-(vragi3Objects[i83].v3y+110))*(granati[i70].y-(vragi3Objects[i83].v3y+110))))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1);}
}
}

//РАДИУС ИГРОКА 2
if(granati[i70].owner==2)
{	
//радиус
if(granati[i70].x-(vragi3Objects[i83].v3x+90)<=radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)&&granati[i70].x-(vragi3Objects[i83].v3x+90)>=-radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)&&
  granati[i70].y-(vragi3Objects[i83].v3y+110)<=radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)&&granati[i70].y-(vragi3Objects[i83].v3y+110)>=-radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2))
  //УРОН ОТ ВЗРЫВЧАТКИ
{
  if(LVL2%2==0)
{vragi3Objects[i83].health-=(damage_gren[granati[i70].type]+attack2*LVL2/2)*(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)-sqrt((granati[i70].x-(vragi3Objects[i83].v3x+90))*(granati[i70].x-(vragi3Objects[i83].v3x+90))+
(granati[i70].y-(vragi3Objects[i83].v3y+110))*(granati[i70].y-(vragi3Objects[i83].v3y+110))))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2);}
 if(LVL2%2==0)
{vragi3Objects[i83].health-=(damage_gren[granati[i70].type]+attack2*(LVL2-1)/2)*(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)-sqrt((granati[i70].x-(vragi3Objects[i83].v3x+90))*(granati[i70].x-(vragi3Objects[i83].v3x+90))+
(granati[i70].y-(vragi3Objects[i83].v3y+110))*(granati[i70].y-(vragi3Objects[i83].v3y+110))))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2);}
}
}

}//RPGMOD==TRUE



if(RPGMOD==true)
{vragi3Objects[i83].health+=vragi3Objects[i83].defence;
if(vragi3Objects[i83].health>400)
{vragi3Objects[i83].health=400;}
}//RPGMOD

//убил!:'(
if(vragi3Objects[i83].health<=0&&vragi3Objects[i83].ubit==0)
{
if(granati[i70].owner==1)
{vragi3Objects[i83].killed_by=1;}
if(granati[i70].owner==2)
{vragi3Objects[i83].killed_by=2;}

if(vragi3Objects[i83].health<=-150)
{vragi3Objects[i83].bezboshki=1;
if(vragi3Objects[i83].killed_by==1)
{points1+=125;}
if(vragi3Objects[i83].killed_by==2)
{points2+=125;}
boshkiObjects[N_HEAD].bezuh=0;
boshkiObjects[N_HEAD].vrag=3;
boshkiObjects[N_HEAD].niz=vragi3Objects[i83].v3y+200;
boshkiObjects[N_HEAD].bx=vragi3Objects[i83].v3x+125;
boshkiObjects[N_HEAD].by=vragi3Objects[i83].v3y+120;
boshkiObjects[N_HEAD].bzdik=0;
boshkiObjects[N_HEAD].seed=hge->Random_Int(1,5);
boshkiObjects[N_HEAD].bzdik_seed=hge->Random_Int(1,3);
boshkiObjects[N_HEAD].akt=1;
N_HEAD++;
if(N_HEAD>=MAX_HEAD-1)
{N_HEAD=0;}
}

}

}//про медведей--------

//про птенцов----
for (int i130=0;i130<=N_PTENEC;i130++)
{

if(vragi4Objects[i130].ubit==0)
{

if(RPGMOD==false)	
{	//радиус
if(granati[i70].x-vragi4Objects[i130].v4x<=radius_vzriva[granati[i70].type]&&granati[i70].x-vragi4Objects[i130].v4x>=-radius_vzriva[granati[i70].type]&&
  granati[i70].y-vragi4Objects[i130].v4y<=radius_vzriva[granati[i70].type]&&granati[i70].y-vragi4Objects[i130].v4y>=-radius_vzriva[granati[i70].type])
  //УРОН ОТ ВЗРЫВЧАТКИ
{	

vragi4Objects[i130].health-=damage_gren[granati[i70].type]*(radius_vzriva[granati[i70].type]-sqrt((granati[i70].x-vragi4Objects[i130].v4x)*(granati[i70].x-vragi4Objects[i130].v4x)+
(granati[i70].y-vragi4Objects[i130].v4y)*(granati[i70].y-vragi4Objects[i130].v4y)))/radius_vzriva[granati[i70].type];

//энергия взрыва
vragi4Objects[i130].energy=(radius_vzriva[granati[i70].type]-sqrt((granati[i70].x-vragi4Objects[i130].v4x)*(granati[i70].x-vragi4Objects[i130].v4x)+
(granati[i70].y-vragi4Objects[i130].v4y)*(granati[i70].y-vragi4Objects[i130].v4y)))/radius_vzriva[granati[i70].type];

//определение расстояния
if(granati[i70].x>=vragi4Objects[i130].v4x)
{vragi4Objects[i130].rasstX=granati[i70].x-vragi4Objects[i130].v4x;}
if(granati[i70].x<=vragi4Objects[i130].v4x)
{vragi4Objects[i130].rasstX=vragi4Objects[i130].v4x-granati[i70].x;}
if(granati[i70].y>=vragi4Objects[i130].v4y)
{vragi4Objects[i130].rasstY=granati[i70].y-vragi4Objects[i130].v4y;}
if(granati[i70].y<=vragi4Objects[i130].v4y)
{vragi4Objects[i130].rasstY=vragi4Objects[i130].v4y-granati[i70].y;}

//направление щей (четверти)
if(granati[i70].x<vragi4Objects[i130].v4x&&granati[i70].y>=vragi4Objects[i130].v4y)
{vragi4Objects[i130].chetvert=1;}
if(granati[i70].x<vragi4Objects[i130].v4x&&granati[i70].y<vragi4Objects[i130].v4y)
{vragi4Objects[i130].chetvert=2;}
if(granati[i70].x>=vragi4Objects[i130].v4x&&granati[i70].y<vragi4Objects[i130].v4y)
{vragi4Objects[i130].chetvert=3;}
if(granati[i70].x>=vragi4Objects[i130].v4x&&granati[i70].y>=vragi4Objects[i130].v4y)
{vragi4Objects[i130].chetvert=4;}
}
}


if(RPGMOD==true)	
{
//---

//РАДИУС ИГРОКА 1	
if(granati[i70].owner==1)
{	
//радиус
if(granati[i70].x-vragi4Objects[i130].v4x<=radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)&&granati[i70].x-vragi4Objects[i130].v4x>=-radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)&&
  granati[i70].y-vragi4Objects[i130].v4y<=radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)&&granati[i70].y-vragi4Objects[i130].v4y>=-radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1))
  //УРОН ОТ ВЗРЫВЧАТКИ
{

if(LVL1%2==0)	
{vragi4Objects[i130].health-=(damage_gren[granati[i70].type]+attack1*LVL1/2)*(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)-sqrt((granati[i70].x-vragi4Objects[i130].v4x)*(granati[i70].x-vragi4Objects[i130].v4x)+
(granati[i70].y-vragi4Objects[i130].v4y)*(granati[i70].y-vragi4Objects[i130].v4y)))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1);}
if(LVL1%2==1)	
{vragi4Objects[i130].health-=(damage_gren[granati[i70].type]+attack1*(LVL1-1)/2)*(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)-sqrt((granati[i70].x-vragi4Objects[i130].v4x)*(granati[i70].x-vragi4Objects[i130].v4x)+
(granati[i70].y-vragi4Objects[i130].v4y)*(granati[i70].y-vragi4Objects[i130].v4y)))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1);}

//энергия взрыва
vragi4Objects[i130].energy=(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1)-sqrt((granati[i70].x-vragi4Objects[i130].v4x)*(granati[i70].x-vragi4Objects[i130].v4x)+
(granati[i70].y-vragi4Objects[i130].v4y)*(granati[i70].y-vragi4Objects[i130].v4y)))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka1);


//определение расстояния
if(granati[i70].x>=vragi4Objects[i130].v4x)
{vragi4Objects[i130].rasstX=granati[i70].x-vragi4Objects[i130].v4x;}
if(granati[i70].x<=vragi4Objects[i130].v4x)
{vragi4Objects[i130].rasstX=vragi4Objects[i130].v4x-granati[i70].x;}
if(granati[i70].y>=vragi4Objects[i130].v4y)
{vragi4Objects[i130].rasstY=granati[i70].y-vragi4Objects[i130].v4y;}
if(granati[i70].y<=vragi4Objects[i130].v4y)
{vragi4Objects[i130].rasstY=vragi4Objects[i130].v4y-granati[i70].y;}

if(vragi4Objects[i130].rasstX<20)
{vragi4Objects[i130].rasstX=20;}
if(vragi4Objects[i130].rasstY<20)
{vragi4Objects[i130].rasstY=20;}

//направление щей (четверти)
if(granati[i70].x<vragi4Objects[i130].v4x&&granati[i70].y>=vragi4Objects[i130].v4y)
{vragi4Objects[i130].chetvert=1;}
if(granati[i70].x<vragi4Objects[i130].v4x&&granati[i70].y<vragi4Objects[i130].v4y)
{vragi4Objects[i130].chetvert=2;}
if(granati[i70].x>=vragi4Objects[i130].v4x&&granati[i70].y<vragi4Objects[i130].v4y)
{vragi4Objects[i130].chetvert=3;}
if(granati[i70].x>=vragi4Objects[i130].v4x&&granati[i70].y>=vragi4Objects[i130].v4y)
{vragi4Objects[i130].chetvert=4;}


}
}

//РАДИУС ИГРОКА 2
if(granati[i70].owner==2)
{	
//радиус
if(granati[i70].x-vragi4Objects[i130].v4x<=radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)&&granati[i70].x-vragi4Objects[i130].v4x>=-radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)&&
  granati[i70].y-vragi4Objects[i130].v4y<=radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)&&granati[i70].y-vragi4Objects[i130].v4y>=-radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2))
  //УРОН ОТ ВЗРЫВЧАТКИ
{
if(LVL2%2==0)
{vragi4Objects[i130].health-=(damage_gren[granati[i70].type]+attack2*LVL2/2)*(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)-sqrt((granati[i70].x-vragi4Objects[i130].v4x)*(granati[i70].x-vragi4Objects[i130].v4x)+
(granati[i70].y-vragi4Objects[i130].v4y)*(granati[i70].y-vragi4Objects[i130].v4y)))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2);}
if(LVL2%2==1)
{vragi4Objects[i130].health-=(damage_gren[granati[i70].type]+attack2*(LVL2-1)/2)*(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)-sqrt((granati[i70].x-vragi4Objects[i130].v4x)*(granati[i70].x-vragi4Objects[i130].v4x)+
(granati[i70].y-vragi4Objects[i130].v4y)*(granati[i70].y-vragi4Objects[i130].v4y)))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2);}


//энергия взрыва
vragi4Objects[i130].energy=(radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2)-sqrt((granati[i70].x-vragi4Objects[i130].v4x)*(granati[i70].x-vragi4Objects[i130].v4x)+
(granati[i70].y-vragi4Objects[i130].v4y)*(granati[i70].y-vragi4Objects[i130].v4y)))/radius_vzriva[granati[i70].type]*(1+0.01f*vzrivchatka2);


//определение расстояния
if(granati[i70].x>=vragi4Objects[i130].v4x)
{vragi4Objects[i130].rasstX=granati[i70].x-vragi4Objects[i130].v4x;}
if(granati[i70].x<=vragi4Objects[i130].v4x)
{vragi4Objects[i130].rasstX=vragi4Objects[i130].v4x-granati[i70].x;}
if(granati[i70].y>=vragi4Objects[i130].v4y)
{vragi4Objects[i130].rasstY=granati[i70].y-vragi4Objects[i130].v4y;}
if(granati[i70].y<=vragi4Objects[i130].v4y)
{vragi4Objects[i130].rasstY=vragi4Objects[i130].v4y-granati[i70].y;}

if(vragi4Objects[i130].rasstX<20)
{vragi4Objects[i130].rasstX=20;}
if(vragi4Objects[i130].rasstY<20)
{vragi4Objects[i130].rasstY=20;}

//направление щей (четверти)
if(granati[i70].x<vragi4Objects[i130].v4x&&granati[i70].y>=vragi4Objects[i130].v4y)
{vragi4Objects[i130].chetvert=1;}
if(granati[i70].x<vragi4Objects[i130].v4x&&granati[i70].y<vragi4Objects[i130].v4y)
{vragi4Objects[i130].chetvert=2;}
if(granati[i70].x>=vragi4Objects[i130].v4x&&granati[i70].y<vragi4Objects[i130].v4y)
{vragi4Objects[i130].chetvert=3;}
if(granati[i70].x>=vragi4Objects[i130].v4x&&granati[i70].y>=vragi4Objects[i130].v4y)
{vragi4Objects[i130].chetvert=4;}


}
}

//---
}//RPGMOD==TRUE






if(RPGMOD==true)
{vragi4Objects[i130].health+=vragi4Objects[i130].defence;
if(vragi4Objects[i130].health>50)
{vragi4Objects[i130].health=50;}
}//RPGMOD

//убил!:'(
if(vragi4Objects[i130].health<=0)
{
vragi4Objects[i130].vzorvan=true;
if(granati[i70].owner==1)
{vragi4Objects[i130].killed_by=1;}
if(granati[i70].owner==2)
{vragi4Objects[i130].killed_by=2;}
}

}
}//про птенцов-----


granati[i70].akt=-1;
}//закрытие взрыва-------------------------



}
//ЗАКРЫТИЕ ГРЕНОК


for(int i150=0;i150<=15;i150++)
{
weapon_x1[i150]=x+w_x1[i150];
weapon_y1[i150]=y+w_y1[i150];
weapon_x2[i150]=x+w_x2[i150];
weapon_y2[i150]=y+w_y2[i150];
weapon2_x1[i150]=x2+w_x1[i150];
weapon2_y1[i150]=y2+w_y1[i150];
weapon2_x2[i150]=x2+w_x2[i150];
weapon2_y2[i150]=y2+w_y2[i150];
}


// кнопкы



char Buff[2][8];

char srbuff[16];

//СОХРАНЕНИЕ!!!!!!!!!!
	if (hge->Input_GetKeyState(HGEK_Q))
	{
	FILE * SaveFile;
SaveFile = fopen ("save01.txt","w");
sprintf (Buff[0],"       ");
sprintf (Buff[1],"       ");
sprintf (Buff[0],"%d",x);
sprintf (Buff[1],"%d",y);
memcpy(srbuff,Buff,32);
fwrite ((const char*)srbuff,16,1,SaveFile);
    fclose (SaveFile);
  }


//ЗАГРУЗКА!!!!!!!!!!
	if (hge->Input_GetKeyState(HGEK_E))
	{
	FILE * SavedFile;
	SavedFile = fopen ("save01.txt","r");
	fread(srbuff,16,1,SavedFile);
	memcpy(Buff,srbuff,16);
	x=(int)Buff[0];
	y=(int)Buff[1];

	
	
	}



//ЗАГРУЗКА!!!!!!!!!!
	//if (hge->Input_GetKeyState(HGEK_X))
	//{
//filebuf fb;
//fb.open=("save01.txt".save01.txt}
/*
	// кнопкы



	



	fprintf(SaveFile,"\nУдача:%d",luck1);


	if(player2_aktive==1)
	{fprintf(SaveFile,"\nУровень игрока2:%d",LVL2);}

    fclose (SaveFile);
  }}



//ЗАГРУЗКА!!!!!!!!!!
	if (hge->Input_GetKeyState(HGEK_X))
	{
	FILE * SavedFile;
	SavedFile = fopen ("save01.txt","a+");
	
	if (SavedFile!=NULL)
  {
	char buff[1];
	//НАСТРОЙКИ ИГРЫ
	//система классов и рпг-мод
	fseek (SavedFile ,35 , SEEK_SET);	
	fread(buff,1,1,SavedFile);
	if(isdigit(buff[0]))
	{CLASSMOD=atoi(buff);}
	fseek (SavedFile ,45 , SEEK_SET);	
	fread(buff,1,1,SavedFile);
	if(isdigit(buff[0]))
	{RPGMOD=atoi(buff);}
	//кол-во игроков
	fseek (SavedFile ,57 , SEEK_SET);	
	fread(buff,1,1,SavedFile);
	if(isdigit(buff[0]))
	{player2_aktive=atoi(buff);}
	//НАСТРОЙКИ ИГРЫ
	
	//игрок1
	int r_size;
	int m_size;
	fseek (SavedFile ,71 , SEEK_SET);	
	fread(buff,1,4,SavedFile);
	if(isdigit(buff[0]))
	{r_size=atoi(buff);}
	m_size=r_size;

	fseek (SavedFile ,82 , SEEK_SET);
	fread(buff,1,r_size,SavedFile);
	if(isdigit(buff[0]))
	{LVL1=atoi(buff);}
	

	fseek (SavedFile ,84+m_size , SEEK_SET);	
	fread(buff,1,4,SavedFile);
	if(isdigit(buff[0]))
	{r_size=atoi(buff);}

	fseek (SavedFile ,92+m_size, SEEK_SET);	
	fread(buff,1,r_size,SavedFile);
	if(isdigit(buff[0]))
	{opit1=atoi(buff);}
	m_size+=r_size;



	fseek (SavedFile ,94+(long)m_size , SEEK_SET);	
	fread(buff,1,4,SavedFile);
	if(isdigit(buff[0]))
	{r_size=atoi(buff);}

	fseek (SavedFile ,103+m_size, SEEK_SET);	
	fread(buff,1,r_size,SavedFile);
	if(isdigit(buff[0]))
	{attack1=atoi(buff);}
	m_size+=r_size;



	fseek (SavedFile ,105+(long)m_size , SEEK_SET);	
	fread(buff,1,4,SavedFile);
	if(isdigit(buff[0]))
	{r_size=atoi(buff);}

	fseek (SavedFile ,117+m_size, SEEK_SET);	
	fread(buff,1,r_size,SavedFile);
	if(isdigit(buff[0]))
	{skorost1=atoi(buff);}
	m_size+=r_size;









	
	
	fseek (SavedFile ,121 , SEEK_SET);	
	fread(buff,1,4,SavedFile);
	if(isdigit(buff[0]))
	{luck1=atoi(buff);}




	//игрок1

	
	
	if(player2_aktive==1)
	{fseek (SavedFile ,95 , SEEK_SET);	
	fread(buff,1,4,SavedFile);
	if(isdigit(buff[0]))
	{LVL2=atoi(buff);}}
	




    fclose (SavedFile);
  }	
	}
	*/

	if (hge->Input_GetKeyState(HGEK_LEFT)&&net_user!=2) //ВПЕРЕД
	{afk1=false;
	dx-=(speed-3*weight[N_WEAPON1]/sqrt(vinoslivost1))*sqrt(dt/1400);
	if(class1==2||CLASSMOD==false)
	{player1_strelok->Resume();//играет
	player1_strelok->Update(dt);}
	if(class1==1)
	{player1_myasnik->Resume();//играет
	player1_myasnik->Update(dt);}
	if(class1==3)
	{player1_razrushitel->Resume();//играет
	player1_razrushitel->Update(dt);}
	if(class1==4)
	{player1_tehnik->Resume();//играет
	player1_tehnik->Update(dt);}
	}

	if (hge->Input_GetKeyState(HGEK_RIGHT)&&net_user!=2) //НАЗАД
	{afk1=false;
	dx+=(speed-3*weight[N_WEAPON1]/sqrt(vinoslivost1))*sqrt(dt/1400);
	if(class1==2||CLASSMOD==false)
	{player1_strelok->Resume();//играет
	player1_strelok->Update(dt);}
	if(class1==1)
	{player1_myasnik->Resume();//играет
	player1_myasnik->Update(dt);}
	if(class1==3)
	{player1_razrushitel->Resume();//играет
	player1_razrushitel->Update(dt);}
	if(class1==4)
	{player1_tehnik->Resume();//играет
	player1_tehnik->Update(dt);}
	}
	
	if (hge->Input_GetKeyState(HGEK_UP)&&net_user!=2) //ВВЕРХ
    {afk1=false;
	dy-=(speed-3*weight[N_WEAPON1]/sqrt(vinoslivost1))*sqrt(dt/1400);
	if(class1==2||CLASSMOD==false)
	{player1_strelok->Resume();//играет
	player1_strelok->Update(dt);}
	if(class1==1)
	{player1_myasnik->Resume();//играет
	player1_myasnik->Update(dt);}
	if(class1==3)
	{player1_razrushitel->Resume();//играет
	player1_razrushitel->Update(dt);}
	if(class1==4)
	{player1_tehnik->Resume();//играет
	player1_tehnik->Update(dt);}
	}
	
	if (hge->Input_GetKeyState(HGEK_DOWN)&&net_user!=2) //ВНИЗ
	{afk1=false;
	dy+=(speed-3*weight[N_WEAPON1]/sqrt(vinoslivost1))*sqrt(dt/1400);
	if(class1==2||CLASSMOD==false)
	{player1_strelok->Resume();//играет
	player1_strelok->Update(dt);}
	if(class1==1)
	{player1_myasnik->Resume();//играет
	player1_myasnik->Update(dt);}
	if(class1==3)
	{player1_razrushitel->Resume();//играет
	player1_razrushitel->Update(dt);}
	if(class1==4)
	{player1_tehnik->Resume();//играет
	player1_tehnik->Update(dt);}
	}



	if((hge->Input_GetKeyState(HGEK_UP)==false && hge->Input_GetKeyState(HGEK_DOWN)==false&&
	hge->Input_GetKeyState(HGEK_LEFT)==false && hge->Input_GetKeyState(HGEK_RIGHT)==false&&net_user!=2)||(dx==0&&dy==0&&net_user==2))
	{player1_myasnik->Play();
	player1_strelok->Play();
	player1_razrushitel->Play();
	player1_tehnik->Play();
	if(afk1==false)
	{afx=x;
	afX=X;
	afk1=true;}
	}
	
	if(hge->Input_GetKeyState(HGEK_LEFT)==false && hge->Input_GetKeyState(HGEK_RIGHT)==false&&net_user!=2)
	{
	if(afk1==false)
	{afx=x;
	afX=X;
	afk1=true;}
	}


if(player2_aktive==1)//ЕСЛИ ВТОРОЙ ИГРОК ВООБЩЕ ЕСТЬ
{	if (hge->Input_GetKeyState(HGEK_A)&&net_user!=1) //ВПЕРЕД
	{afk2=false;
	dx2-=(speed2-3*weight[N_WEAPON2]/sqrt(vinoslivost2))*sqrt(dt/1400);
	player2_strelok->Resume();//играет
    player2_strelok->Update(dt);}

	if (hge->Input_GetKeyState(HGEK_D)&&net_user!=1) //НАЗАД
	{afk2=false;
	dx2+=(speed2-3*weight[N_WEAPON2]/sqrt(vinoslivost2))*sqrt(dt/1400);
	player2_strelok->Resume();//играет
    player2_strelok->Update(dt);
	}
	
	if (hge->Input_GetKeyState(HGEK_W)&&net_user!=1) //ВВЕРХ
    {afk2=false;
	dy2-=(speed2-3*weight[N_WEAPON2]/sqrt(vinoslivost2))*sqrt(dt/1400);
	player2_strelok->Resume();//играет
    player2_strelok->Update(dt);}
	
	if (hge->Input_GetKeyState(HGEK_S)&&net_user!=1) //ВНИЗ
	{afk2=false;
	dy2+=(speed2-3*weight[N_WEAPON2]/sqrt(vinoslivost2))*sqrt(dt/1400);
	player2_strelok->Resume();//играет
    player2_strelok->Update(dt);}

	if((hge->Input_GetKeyState(HGEK_A)==false && hge->Input_GetKeyState(HGEK_D)==false && 
		hge->Input_GetKeyState(HGEK_W)==false && hge->Input_GetKeyState(HGEK_S)==false&&net_user!=1)||(dx2==0&&dy2==0&&net_user==1))
	{
	if(afk2==false)	
	{afx2=x2;
	afX2=X;
	afk2=true;}
	player2_strelok->Play();}



	if(hge->Input_GetKeyState(HGEK_A)==false && hge->Input_GetKeyState(HGEK_D)==false&&net_user!=1)
	{
	if(afk2==false)	
	{afx2=x2;
	afX2=X;
	afk2=true;}}

}//если 2-й игрок вообще есть


    if(hge->Input_GetKeyState(HGEK_N)==true)
	{Xz+=hge->Random_Int(-3,3);}
	
    if(hge->Input_GetKeyState(HGEK_N)==false)
	{Xz=0;}


    
	//ПЕРЕЗАРЯДКА
	if (((hge->Input_GetKeyState(HGEK_SHIFT)&&net_user!=2)||(shift==true&&net_user==2))&&N_WEAPON1!=10&&N_WEAPON1!=11&&reload==false)
	{perez_time=perez_akt;
	//perez_time_milli=perez_akt_milli;
	reload=true;

	perez_time_milli=perez_akt_milli+reload_time_milli[N_WEAPON1];

	

	if(perez_time_milli<=900)
	{
	if(perez_akt<(60-reload_time[N_WEAPON1]))
	{perez_time=perez_akt+reload_time[N_WEAPON1];}
	if(perez_akt>=(60-reload_time[N_WEAPON1]))
	{perez_time=perez_akt-(60-reload_time[N_WEAPON1]);}
	}

	if(perez_time_milli>900&&perez_time_milli<1000)
	{
	if(perez_akt<(60-(reload_time[N_WEAPON1]+1)))
	{perez_time=perez_akt+reload_time[N_WEAPON1]+1;}
	if(perez_akt>=(60-(reload_time[N_WEAPON1]+1)))
	{perez_time=perez_akt-(60-(reload_time[N_WEAPON1]+1));}
	perez_time_milli=0;
	}

	if(perez_time_milli>=1000)
	{
	perez_time_milli-=1000;
	if(perez_akt<(60-(reload_time[N_WEAPON1]+1)))
	{perez_time=perez_akt+reload_time[N_WEAPON1]+1;}
	if(perez_akt>=(60-(reload_time[N_WEAPON1]+1)))
	{perez_time=perez_akt-(60-(reload_time[N_WEAPON1]+1));}
	}

	switch(N_WEAPON1)
	{
	case 0:
	case 3:
	case 5:
	case 8:
	ak_perez1();
	break;
	case 1:
	case 4:
	case 9:
	case 15:
	pm_perez1();
	break;
	case 2:
	pp19_perez1();
	break;
	case 6:
	mac_perez1();
	break;
	case 14:
	webley_perez1();
	break;
	default:
	break;
	}
	}
    
    /*АВТОМАТИЧЕСКАЯ ПЕРЕЗАРЯДКА (НУ ЛАДНО...ПОЛУ-АВТОМАТИЧЕСКАЯ)
	if(oboima==0&&hge->Input_GetKeyState(HGEK_ENTER))
	{perez_time=GetCurrentSecond();
	reload=true;}*/
	if(N_WEAPON1!=10&&N_WEAPON1!=11&&N_WEAPON1!=7&&N_WEAPON1!=12)
    {
	if(perez_akt==perez_time&&perez_akt_milli>=perez_time_milli&&reload==true)//перезарядился...
	{reload=false;
	switch(N_WEAPON1)
	{
	case 0:
	case 3:
	case 2:
	oboima=30;
	if(N_WEAPON1==0&&ak_up==true)
	{oboima_alt[0]=1;}
	if(N_WEAPON1==3&&fn_f2000_up==true)
	{oboima_alt[3]=1;}
	break;
	case 5:
	oboima=45;
	break;
	case 8:
	oboima=75;
	break;
	case 1:
	case 4:
	oboima=8;
	break;
	case 9:
	oboima=17;
	break;
	case 6:
	oboima=50;
	break;
	case 13:
	oboima=1;
	p_vistrel=1;
	break;
	case 14:
	oboima=6;
	break;
	case 15:
	oboima=20;
	break;
	}
	}	
	}




	if(N_WEAPON1==7)

	{
	if((perez_time_milli<500&&perez_akt_milli==perez_time_milli+500&&reload==true)||
	(perez_time_milli<500&&perez_akt_milli<perez_time_milli&&perez_time!=perez_akt&&reload==true))//WINCHESTER
	{oboima+=1;
	hge->Effect_PlayEx(drob_reload1,volume,player1Pan,0);
	perez_time=perez_akt;
	perez_time_milli=GetTime();}
 	if(perez_time_milli>=500&&perez_akt_milli>=perez_time_milli-500&&
	perez_akt!=perez_time&&reload==true)//WINCHESTER
	{oboima+=1;
	hge->Effect_PlayEx(drob_reload1,volume,player1Pan,0);
	perez_time=perez_akt;
	perez_time_milli=GetTime();}
	
	if(oboima>=8||hge->Input_GetKeyState(HGEK_ENTER))
	{
	if(oboima>=8&&reload==true)
	{pompa_time_milli=GetTime();
	pompa_time=perez_akt;
	pompa_akt1=1;}
	reload=false;
	}

	}


	if(N_WEAPON1==12)

	{
	if((perez_time_milli<600&&perez_akt_milli>=perez_time_milli+400&&reload==true&&oboima<6)
	//||
	//(perez_time_milli<500&&perez_akt_milli<perez_time_milli&&perez_time!=perez_akt&&reload==true)
	)//Milkor MGL
	{oboima+=1;
	hge->Effect_PlayEx(drob_reload1,volume,player1Pan,0);
	perez_time=perez_akt;
	perez_time_milli=GetTime();}
 	if(perez_time_milli>=600&&perez_akt_milli>=perez_time_milli-600&&
	perez_akt!=perez_time&&reload==true&&oboima<6)//Milkor MGL
	{oboima+=1;
	hge->Effect_PlayEx(drob_reload1,volume,player1Pan,0);
	perez_time=perez_akt;
	perez_time_milli=GetTime();}
	
	if(oboima>=6||hge->Input_GetKeyState(HGEK_ENTER))
	{reload=false;}

	}


	


//КОНЕЦ ПЕРЕЗАРЯДКИ



//ПЕРЕЗАРЯДКА ИГРОКА 2 ЕСЛИ ОН ЕСТЬ
	if(player2_aktive==1)
{
	if (((hge->Input_GetKeyState(HGEK_R)&&net_user!=1)||(r_key==true&&net_user==1))&&N_WEAPON2!=10&&N_WEAPON2!=11&&reload2==false)
	{perez_time2=perez_akt;
	//perez_time_milli=perez_akt_milli;
	reload2=true;

	perez_time_milli2=perez_akt_milli+reload_time_milli[N_WEAPON2];

	

	if(perez_time_milli2<=900)
	{
	if(perez_akt<(60-reload_time[N_WEAPON2]))
	{perez_time2=perez_akt+reload_time[N_WEAPON2];}
	if(perez_akt>=(60-reload_time[N_WEAPON2]))
	{perez_time2=perez_akt-(60-reload_time[N_WEAPON2]);}
	}

	if(perez_time_milli2>900&&perez_time_milli2<1000)
	{
	if(perez_akt<(60-(reload_time[N_WEAPON2]+1)))
	{perez_time2=perez_akt+reload_time[N_WEAPON2]+1;}
	if(perez_akt>=(60-(reload_time[N_WEAPON2]+1)))
	{perez_time2=perez_akt-(60-(reload_time[N_WEAPON2]+1));}
	perez_time_milli2=0;
	}

	if(perez_time_milli2>=1000)
	{
	perez_time_milli2-=1000;
	if(perez_akt<(60-(reload_time[N_WEAPON2]+1)))
	{perez_time2=perez_akt+reload_time[N_WEAPON2]+1;}
	if(perez_akt>=(60-(reload_time[N_WEAPON2]+1)))
	{perez_time2=perez_akt-(60-(reload_time[N_WEAPON2]+1));}
	}

	switch(N_WEAPON2)
	{
	case 0:
	case 3:
	case 5:
	case 8:
	ak2_perez1();
	break;
	case 1:
	case 4:
	case 9:
	case 15:
	pm2_perez1();
	break;
	case 2:
	pp192_perez1();
	break;
	case 6:
	mac2_perez1();
	break;
	case 14:
	webley2_perez1();
	break;
	default:
	break;
	}
	}
    
    /*АВТОМАТИЧЕСКАЯ ПЕРЕЗАРЯДКА (НУ ЛАДНО...ПОЛУ-АВТОМАТИЧЕСКАЯ)
	if(oboima==0&&hge->Input_GetKeyState(HGEK_ENTER))
	{perez_time=GetCurrentSecond();
	reload=true;}*/
	if(N_WEAPON2!=10&&N_WEAPON2!=11&&N_WEAPON2!=7&&N_WEAPON2!=12)
    {
	if(perez_akt==perez_time2&&perez_akt_milli>=perez_time_milli2&&reload2==true)//перезарядился...
	{reload2=false;
	switch(N_WEAPON2)
	{
	case 0:
	case 3:
	case 2:
	oboima2=30;
	if(N_WEAPON2==0&&ak_up2==true)
	{oboima2_alt[0]=1;}
	if(N_WEAPON2==3&&fn_f2000_up2==true)
	{oboima2_alt[3]=1;}
	break;
	case 5:
	oboima2=45;
	break;
	case 8:
	oboima2=75;
	break;
	case 1:
	case 4:
	oboima2=8;
	break;
	case 9:
	oboima2=17;
	break;
	case 6:
	oboima2=50;
	break;
	case 13:
	oboima2=1;
	p_vistrel2=1;
	break;
	case 14:
	oboima2=6;
	break;
	case 15:
	oboima2=20;
	break;
	}
	}	
	}


if(N_WEAPON2==7)
	{
	if((perez_time_milli2<500&&perez_akt_milli==perez_time_milli2+500&&reload2==true)||
	(perez_time_milli2<500&&perez_akt_milli<perez_time_milli2&&perez_time2!=perez_akt&&reload2==true))//WINCHESTER
	{oboima2+=1;
	hge->Effect_PlayEx(drob_reload1,volume,player2Pan,0);
	perez_time2=perez_akt;
	perez_time_milli2=GetTime();}
 	if(perez_time_milli2>=500&&perez_akt_milli>=perez_time_milli2-500&&
	perez_akt!=perez_time2&&reload2==true)//WINCHESTER
	{oboima2+=1;
	hge->Effect_PlayEx(drob_reload1,volume,player2Pan,0);
	perez_time2=perez_akt;
	perez_time_milli2=GetTime();} 
	
	if(oboima2>=8||hge->Input_GetKeyState(HGEK_SPACE))
	{
	if(oboima2>=8&&reload2==true)
	{pompa_time_milli2=GetTime();
	pompa_time2=perez_akt;
	pompa_akt2=1;}
	reload2=false;}
}

	if(N_WEAPON2==12)
	{
	if((perez_time_milli2<600&&perez_akt_milli==perez_time_milli2+400&&reload2==true&&oboima2<6)
	//||
	//(perez_time_milli2<500&&perez_akt_milli<perez_time_milli2&&perez_time2!=perez_akt&&reload2==true)
	)//Milkor MGL
	{oboima2+=1;
	hge->Effect_PlayEx(drob_reload1,volume,player2Pan,0);
	perez_time2=perez_akt;
	perez_time_milli2=GetTime();}
 	if(perez_time_milli2>=600&&perez_akt_milli>=perez_time_milli2-600&&
	perez_akt!=perez_time2&&reload2==true&&oboima2<6)//Milkor MGL
	{oboima2+=1;
	hge->Effect_PlayEx(drob_reload1,volume,player2Pan,0);
	perez_time2=perez_akt;
	perez_time_milli2=GetTime();} 
	
	if(oboima2>=6||hge->Input_GetKeyState(HGEK_SPACE))
	{reload2=false;}
	}


}
	//КОНЕЦ ПЕРЕЗАРЯДКИ ИГРОКА 2


if(N_WEAPON1==7)
{
if(((pompa_time_milli<750&&perez_akt_milli>=pompa_time_milli+250)||
   (pompa_time_milli>=750&&perez_akt_milli>=pompa_time_milli-750)||
   (perez_akt_milli<pompa_time_milli&&perez_akt!=pompa_time))&&pompa_akt1==1)
{
winchester_anime->Play();
player1_ruka1_winch->Play();
hge->Effect_PlayEx(drob_pompa,volume,player1Pan,0);
pompa_akt1=0;
}
}


if(N_WEAPON2==7)
{
if(((pompa_time_milli2<750&&perez_akt_milli>=pompa_time_milli2+250)||
   (pompa_time_milli2>=750&&perez_akt_milli>=pompa_time_milli2-750)||
   (perez_akt_milli<pompa_time_milli2&&perez_akt!=pompa_time2))&&pompa_akt2==1)
{
winchester2_anime->Play();
hge->Effect_PlayEx(drob_pompa,volume,player2Pan,0);
pompa_akt2=0;
}
}



	
	//огонь!!!
	if ((hge->Input_GetKeyState(HGEK_ENTER)&&net_user!=2)||(enter==true&&net_user==2)) 
{	 
    
    if(N_WEAPON1==0||N_WEAPON1==2||N_WEAPON1==3||N_WEAPON1==5||N_WEAPON1==6||N_WEAPON1==7||N_WEAPON1==8)
	{
	if(oboima>0&&p_vistrel!=0)
	{
	fire1();
	
	player1_ruka1_vintovka->Play();
	player1_ruka1_vintovka->Update(dt);
	p_ogon_ms=GetTime();
	p_ogon_s=perez_akt;
	p_vistrel=0;
	}
	}

    if(N_WEAPON1==1||N_WEAPON1==4||N_WEAPON1==9||N_WEAPON1==14||N_WEAPON1==15)//пистолеты
	{



	if(oboima>0)
	{
	if(N_WEAPON1==1||N_WEAPON1==9||N_WEAPON1==15)
	{weapon_x1[N_WEAPON1]++;
	weapon_x2[N_WEAPON1]++;}
	if(N_WEAPON1==4)
	{weapon_x1[N_WEAPON1]++;
	weapon_y1[N_WEAPON1]--;
	weapon_y2[N_WEAPON1]--;	}
	if(N_WEAPON1==14)
	{weapon_x1[N_WEAPON1]+=2;
	weapon_y1[N_WEAPON1]--;
	weapon_x2[N_WEAPON1]++;
	weapon_y2[N_WEAPON1]--;}
	}
    if(oboima>0&&p_vistrel!=0)
	{fire1();
	p_ogon_ms=GetTime();
	p_ogon_s=perez_akt;
	p_vistrel=0;}


    if(p_ogon_ms+125==GetTime()&&p_ogon_s==perez_akt)//чтобы огонь не горел постоянно при нажатом Ентере
	{pulya->SetColor(0x00FFA000);}
    if(p_ogon_ms>=875&&p_ogon_s!=perez_akt)//чтобы огонь не горел постоянно при нажатом Ентере
	{pulya->SetColor(0x00FFA000);}
	}
	
	
	if(N_WEAPON1==10&&oboima>0&&p_vistrel!=0)
	{fire1();
	player1_gogranata_ruka1->Play();
	player1_gogranata_ruka1->Update(dt);
	player1_gogranata_ruka2->Play();
	player1_gogranata_ruka2->Update(dt);
	p_vistrel=0;}


	if(N_WEAPON1==11&&p_vistrel!=0)
	{fire1();
	player1_myasnik_ruka1_udar_sleva->Play();
	player1_myasnik_ruka1_udar_sleva->Update(dt);
	katana1_anime->Play();
	katana1_anime->Update(dt);
	p_vistrel=0;}

	if((N_WEAPON1==12||N_WEAPON1==13)&&oboima>0&&p_vistrel!=0)
	{fire1();
	p_vistrel=0;}

		
	}


	//огонь!!! ВТОРОГО ИГРОКА ЕСЛИ ОН ИГРАЕТ

if(player2_aktive==1)	
{

	if ((hge->Input_GetKeyState(HGEK_SPACE)&&net_user!=1)||(space==true&&net_user==1))
{	 
    
    if(N_WEAPON2==0||N_WEAPON2==2||N_WEAPON2==3||N_WEAPON2==5||N_WEAPON2==6||N_WEAPON2==7||N_WEAPON2==8)
	{
	if(oboima2>0&&p_vistrel2!=0)
	{
	fire2();
	player2_ruka1_vintovka->Play();
	player2_ruka1_vintovka->Update(dt);
	p_ogon_ms2=GetTime();
	p_ogon_s2=perez_akt;
	p_vistrel2=0;
	}
	}

    if(N_WEAPON2==1||N_WEAPON2==4||N_WEAPON2==9||N_WEAPON2==14||N_WEAPON2==15)//пистолеты
	{
	if(oboima2>0)
	{
	if(N_WEAPON2==1||N_WEAPON2==9||N_WEAPON2==15)
	{weapon2_x1[N_WEAPON2]++;
	weapon2_x2[N_WEAPON2]++;}
	if(N_WEAPON2==4)
	{weapon2_x1[N_WEAPON2]++;
	weapon2_y1[N_WEAPON2]--;
	weapon2_y2[N_WEAPON2]--;}
	if(N_WEAPON2==14)
	{weapon2_x1[N_WEAPON2]+=2;
	weapon2_y1[N_WEAPON2]--;
	weapon2_x2[N_WEAPON2]++;
	weapon2_y2[N_WEAPON2]--;}
	}
	
    
	if(oboima2>0&&p_vistrel2!=0)
	{fire2();
	p_ogon_ms2=GetTime();
	p_ogon_s2=perez_akt;
	p_vistrel2=0;}
    
	if(p_ogon_ms2+125==GetTime()&&p_ogon_s2==perez_akt)//чтобы огонь не горел постоянно при нажатом Ентере
	{pulya2->SetColor(0x00FFA000);}
    if(p_ogon_ms2>=875&&p_ogon_s2!=perez_akt)//чтобы огонь не горел постоянно при нажатом Ентере
	{pulya2->SetColor(0x00FFA000);}
	}//закрытие про пистолеты

	if(N_WEAPON2==10&&oboima2>0&&p_vistrel2!=0)
	{fire2();
	player2_gogranata_ruka1->Play();
	player2_gogranata_ruka1->Update(dt);
	player2_gogranata_ruka2->Play();
	player2_gogranata_ruka2->Update(dt);
	p_vistrel2=0;}

	if(N_WEAPON2==11&&p_vistrel2!=0)
	{fire2();
	player2_myasnik_ruka1_udar_sleva->Play();
	player2_myasnik_ruka1_udar_sleva->Update(dt);
	katana2_anime->Play();
	katana2_anime->Update(dt);
	p_vistrel2=0;}

	if((N_WEAPON2==12||N_WEAPON2==13)&&oboima2>0&&p_vistrel2!=0)
	{fire2();
	p_vistrel2=0;}

		
 }	//закрытие огня


}//if player2_aktive==1


//АЛЬТЕРНАТИВНЫЙ огонь!!!
	if (hge->Input_GetKeyState(HGEK_BACKSLASH)&&net_user!=2) 
	{if(((N_WEAPON1==3&&fn_f2000_up==true)||(N_WEAPON1==0&&ak_up==true))&&oboima_alt[N_WEAPON1]==1)
	{fire1_alt();}	
	}

	if (hge->Input_GetKeyState(HGEK_Z)&&net_user!=1) 
	{if(((N_WEAPON2==3&&fn_f2000_up2==true)||(N_WEAPON2==0&&ak_up2==true))&&oboima2_alt[N_WEAPON2]==1)
	{fire2_alt();}	
	}



//шоб пуля не горела
if((vistrel_time<950&&GetTime()>=vistrel_time+25&&GetTime()<vistrel_time+50)||
   (vistrel_time>=975&&GetTime()<=vistrel_time-975&&perez_akt!=vistrel_time_sec))
{pulya->SetColor(0x00FFA000);}



//СКОРОСТРЕЛЬНОСТЬ

if(p_vistrel!=1&&(N_WEAPON1==0||N_WEAPON1==2||N_WEAPON1==3||N_WEAPON1==5||N_WEAPON1==6||N_WEAPON1==7||N_WEAPON1==8||N_WEAPON1==12||N_WEAPON1==13))
{



if((vistrel_time<975&&GetTime()>=vistrel_time+25)||(vistrel_time>=975&&GetTime()>=vistrel_time-975&&perez_akt!=vistrel_time_sec))
{//отдача
	
	
	
	
	
	
	if(N_WEAPON1==0||N_WEAPON1==2||N_WEAPON1==3||N_WEAPON1==5||N_WEAPON1==6||N_WEAPON1==8)
	{
	//if(ak_tex==0)
	//{akx1=x-53;}
	//if(ak_tex==1)
    //{akx1=x-58;}
	weapon_x1[N_WEAPON1]++;
	weapon_y1[N_WEAPON1]--;
	weapon_y2[N_WEAPON1]--;
	}

}

if((vistrel_time<750&&GetTime()<=vistrel_time+250)||(vistrel_time>=750&&GetTime()<=vistrel_time-750&&perez_akt!=vistrel_time_sec))
{	
	if(N_WEAPON1==7)
	{weapon_x1[N_WEAPON1]+=2;
	weapon_y1[N_WEAPON1]--;
	weapon_x2[N_WEAPON1]++;
	weapon_y2[N_WEAPON1]--;}
}










if(N_WEAPON1==0||N_WEAPON1==2||N_WEAPON1==5||N_WEAPON1==8)//для АК И ПП-19 И РПК (600)
{
if(vistrel_time<900)
{if((GetTime()>vistrel_time+100)||(GetTime()<vistrel_time&&perez_akt!=vistrel_time_sec))
{p_vistrel=1;}}
if(vistrel_time>=900&&GetTime()>=vistrel_time-900&&perez_akt!=vistrel_time_sec)
{p_vistrel=1;}
}

if(N_WEAPON1==3)//для FN F-2000 (850)
{
if(vistrel_time<928)
{if((GetTime()>vistrel_time+72)||(GetTime()<vistrel_time&&perez_akt!=vistrel_time_sec))
{p_vistrel=1;}}
if(vistrel_time>=928&&GetTime()>=vistrel_time-928&&perez_akt!=vistrel_time_sec)
{p_vistrel=1;}
}

if(N_WEAPON1==6)//для MAC (800)
{
if(vistrel_time<925)
{if((GetTime()>vistrel_time+75)||(GetTime()<vistrel_time&&perez_akt!=vistrel_time_sec))
{p_vistrel=1;}}
if(vistrel_time>=925&&GetTime()>vistrel_time-925&&perez_akt!=vistrel_time_sec)
{p_vistrel=1;}
}

if(N_WEAPON1==7)//для winchester(1)
{
if(perez_akt_milli>=vistrel_time&&perez_akt!=vistrel_time_sec)
{p_vistrel=1;}
}

if(N_WEAPON1==12||N_WEAPON1==13)//для Milkor MGL(0,5c)
{
if((vistrel_time<500&&perez_akt_milli>=vistrel_time+500)||
   (vistrel_time>=500&&perez_akt_milli>=vistrel_time-500&&perez_akt!=vistrel_time_sec))
{p_vistrel=1;}
}


}//закрытие для огнестрельных игрока 1


if(p_vistrel!=1&&N_WEAPON1==10&&oboima==0)
{

//if(GetTime()>=vistrel_time&&perez_akt!=vistrel_time_sec&&perez_akt!=60&&p_vistrel==1)
//{reload=false;
//oboima++;}


if(perez_akt_milli>=vistrel_time&&perez_akt!=vistrel_time_sec&&perez_akt!=60&&p_vistrel==0)
{p_vistrel=1;
reload=false;
oboima++;}

}//закрытие для взрывчатых игрока 1



if(N_WEAPON1==11&&p_vistrel!=1)
{
if(((vistrel_time<reload_time_milli[N_WEAPON1]&&(perez_akt_milli>=vistrel_time+reload_time_milli[N_WEAPON1]||perez_akt!=vistrel_time_sec))||
(vistrel_time>=reload_time_milli[N_WEAPON1]&&perez_akt_milli>=vistrel_time+reload_time_milli[N_WEAPON1]-1000&&perez_akt!=vistrel_time_sec))&&perez_akt!=60&&p_vistrel==0)
{p_vistrel=1;
reload=false;
}}







//чтобы огонь не горел постоянно
if((vistrel2_time<950&&GetTime()>=vistrel2_time+25&&GetTime()<vistrel2_time+50)||
   (vistrel2_time>=975&&GetTime()<=vistrel2_time-975&&perez_akt!=vistrel2_time_sec))
{pulya2->SetColor(0x00FFA000);}

if(p_vistrel2!=1&&(N_WEAPON2==0||N_WEAPON2==2||N_WEAPON2==3||N_WEAPON2==5||N_WEAPON2==6||N_WEAPON2==7||N_WEAPON2==8||N_WEAPON2==12||N_WEAPON2==13))
{

if((vistrel2_time<975&&GetTime()<=vistrel2_time+25)||(vistrel2_time>=975&&GetTime()<=vistrel2_time-975))
{//отдача
	if(N_WEAPON2==0||N_WEAPON2==2||N_WEAPON2==3||N_WEAPON2==5||N_WEAPON2==6||N_WEAPON2==8)
	{
	//if(ak_tex==0)
	//{akx1=x-53;}
	//if(ak_tex==1)
    //{akx1=x-58;}
	weapon2_x1[N_WEAPON2]++;
	weapon2_y1[N_WEAPON2]--;
	weapon2_y2[N_WEAPON2]--;
	}




}


if((vistrel2_time<750&&GetTime()<=vistrel2_time+250)||(vistrel2_time>=750&&GetTime()<=vistrel2_time-750&&perez_akt!=vistrel2_time_sec))
{	
	if(N_WEAPON2==7)
	{weapon2_x1[N_WEAPON2]+=2;
	weapon2_y1[N_WEAPON2]--;
	weapon2_x2[N_WEAPON2]++;
	weapon2_y2[N_WEAPON2]--;}
}











if(N_WEAPON2==0||N_WEAPON2==2||N_WEAPON2==5||N_WEAPON2==8)//для АК И ПП-19 И РПК (600)
{
if(vistrel2_time<900)
{if((GetTime()>vistrel2_time+100)||(GetTime()<vistrel2_time&&perez_akt!=vistrel2_time_sec))
{p_vistrel2=1;}}
if(vistrel2_time>=900&&GetTime()>vistrel2_time-900&&perez_akt!=vistrel2_time_sec)
{p_vistrel2=1;}
}

if(N_WEAPON2==3)//для FN F-2000 (850)
{
if(vistrel2_time<928)
{if((GetTime()>=vistrel2_time+72)||(GetTime()<vistrel2_time&&perez_akt!=vistrel2_time_sec))
{p_vistrel2=1;}}
if(vistrel2_time>=928&&GetTime()>vistrel2_time-928&&perez_akt!=vistrel2_time_sec)
{p_vistrel2=1;}
}

if(N_WEAPON2==6)//для MAC (800)
{
if(vistrel2_time<925)
{if((GetTime()>vistrel2_time+75)||(GetTime()<vistrel2_time&&perez_akt!=vistrel2_time_sec))
{p_vistrel2=1;}}
if(vistrel2_time>=925&&GetTime()>vistrel2_time-925&&perez_akt!=vistrel2_time_sec)
{p_vistrel2=1;}
}

if(N_WEAPON2==7)//для winchester (1)
{
if(perez_akt_milli>=vistrel2_time&&perez_akt!=vistrel2_time_sec)
{p_vistrel2=1;}
}

if(N_WEAPON2==12||N_WEAPON2==13)//для Milkor MGL(0,5c)
{
if((vistrel2_time<500&&perez_akt_milli>=vistrel2_time+500)||
   (vistrel2_time>=500&&perez_akt_milli>=vistrel2_time-500&&perez_akt!=vistrel2_time_sec))
{p_vistrel2=1;}
}

}//закрытие для игрока 2


if(p_vistrel2!=1&&N_WEAPON2==10&&oboima2==0)
{

//if(GetTime()>=vistrel2_time&&perez_akt!=vistrel2_time_sec&&perez_akt!=60&&p_vistrel2==1)
//{reload2=false;
//oboima2++;}

if(perez_akt_milli>=vistrel2_time&&perez_akt!=vistrel2_time_sec&&perez_akt!=60&&p_vistrel2==0)
{p_vistrel2=1;
reload2=false;
oboima2++;}



}//закрытие для взрывчатых игрока 2

if(N_WEAPON2==11&&p_vistrel2!=1)
{
if(((vistrel2_time<reload_time_milli[N_WEAPON2]&&(perez_akt_milli>=vistrel2_time+reload_time_milli[N_WEAPON2]||perez_akt!=vistrel2_time_sec))||
(vistrel2_time>=reload_time_milli[N_WEAPON2]&&perez_akt_milli>=vistrel2_time+reload_time_milli[N_WEAPON2]-1000&&perez_akt!=vistrel2_time_sec))&&perez_akt!=60&&p_vistrel2==0)
{p_vistrel2=1;
reload2=false;
}}


	//если не ведется огонь то его нет и оружие на месте
if((hge->Input_GetKeyState(HGEK_ENTER)==false&&net_user!=2)||(enter==false&&net_user==2))
{
if(N_WEAPON1!=10&&N_WEAPON1!=11&&N_WEAPON1!=12&&N_WEAPON1!=13)
{p_vistrel=1;
pulya->SetColor(0x00FFA000);
weapon_x1[N_WEAPON1]=x+w_x1[N_WEAPON1];
weapon_y1[N_WEAPON1]=y+w_y1[N_WEAPON1];
weapon_x2[N_WEAPON1]=x+w_x2[N_WEAPON1];
weapon_y2[N_WEAPON1]=y+w_y2[N_WEAPON1];}
}


if(player2_aktive==1)
{
if((hge->Input_GetKeyState(HGEK_SPACE)==false&&net_user!=1)||(space==false&&net_user==1))
{
if(N_WEAPON2!=10&&N_WEAPON2!=11&&N_WEAPON2!=12&&N_WEAPON2!=13)
{p_vistrel2=1;
pulya2->SetColor(0x00FFA000);
weapon2_x1[N_WEAPON2]=x2+w_x1[N_WEAPON2];
weapon2_y1[N_WEAPON2]=y2+w_y1[N_WEAPON2];
weapon2_x2[N_WEAPON2]=x2+w_x2[N_WEAPON2];
weapon2_y2[N_WEAPON2]=y2+w_y2[N_WEAPON2];}
}

}//if player2_aktive==1













if(hge->Input_GetKeyState(HGEK_ADD)&&time%25==0&&N_ZAYAC<=MAX_ZAYAC-10&&net_user!=2)
{zayac_add();}
if(hge->Input_GetKeyState(HGEK_SUBTRACT)&&time%25==0&&N_ZAYAC>=2&&net_user!=2)
{N_ZAYAC--;}
if(hge->Input_GetKeyState(HGEK_ADD)&&hge->Input_GetKeyState(HGEK_ALT)&&time%25==0&&N_PTENEC<=MAX_PTENEC-5&&net_user!=2)
{ptenec_add();}


//СТОРОНА ЗВУУУУУУУУУУУУУУУУУУУУУУУУУКА
player1Pan=-75+x/9;
player2Pan=-75+x2/9;





//ПОКУПКА--------------------------------------
if(hge->Input_GetKeyState(HGEK_BACKSPACE)&&net_user!=2&&reload==false) //игрок 1
{	
if(weapon1_buy!=0)
{menu1_on=1;//активация меню
PAUSE=true;
weapon1_buy=0;}
}



if(player2_aktive==1&&hge->Input_GetKeyState(HGEK_B)&&net_user!=1&&reload2==false) //игрок 2
{	
if(weapon2_buy!=0)
{menu2_on=1;//активация меню
PAUSE=true;
weapon2_buy=0;}
}





 //СМЕНА ОРУЖИЯ------------
if(hge->Input_GetKeyState(HGEK_CTRL)&&net_user!=2)
{
if(weapon1_change!=0&&(ak_buy==true||pp19_buy==true||fn_f2000_buy==true||tt_buy==true||
rpk_buy==true||mac_buy==true||winchester_buy==true||rpk47_buy==true||glok_buy==true||rgd5_buy==true||
katana_buy==true||milkor_buy==true||panzer_buy==true||webley_buy==true||fn_five_seven_buy==true)&&reload==false
&&p_vistrel==1&&aktivatorp==0)
{oboim[N_WEAPON1]=oboima;//запись кол-ва пуль
N_WEAPON1=pred_weapon1;//оружие меняется на предыдущее
oboima=oboim[N_WEAPON1];//загрузка кол-ва пуль
pred_weapon1=last_weapon1;//предыдущее равно последнему (что было)
last_weapon1=N_WEAPON1; //последнее оружие - сейчасное (=)з)
weapon1_change=0;}
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
}

if(player2_aktive==1&&hge->Input_GetKeyState(HGEK_Q)&&net_user!=1)
{
if(weapon2_change!=0&&(ak_buy2==true||pp19_buy2==true||fn_f2000_buy2==true||tt_buy2==true||
rpk_buy2==true||mac_buy2==true||winchester_buy2==true||rpk47_buy2==true||glok_buy2==true||rgd5_buy2==true||
katana_buy2==true||milkor_buy2==true||panzer_buy2==true||webley_buy2==true||fn_five_seven_buy2==true)&&reload2==false
&&p_vistrel2==1&&aktivatorp2==0)
{oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль
N_WEAPON2=pred_weapon2;//оружие меняется на предыдущее
oboima2=oboim2[N_WEAPON2];//загрузка кол-ва пуль
pred_weapon2=last_weapon2;//предыдущее равно последнему (что было)
last_weapon2=N_WEAPON2; //последнее оружие - сейчасное (=)з)
weapon2_change=0;}
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
}




if(menu1_on==0&&net_user!=2)//смена оружия по классам ИГРОКА 1
{

if(hge->Input_GetKeyState(HGEK_NUMPAD1)) //пистолеты
{
if(weapon1_change!=0&&reload==false&&N_WEAPON1!=pistol1)
{oboim[N_WEAPON1]=oboima;//запись кол-ва пуль
N_WEAPON1=pistol1;//оружие меняется на пистолет
oboima=oboim[N_WEAPON1];//загрузка кол-ва пуль
pred_weapon1=last_weapon1;//предыдущее равно последнему (что было)
last_weapon1=N_WEAPON1; //последнее оружие - сейчасное (=)з)
weapon1_change=0;}
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
}

if(hge->Input_GetKeyState(HGEK_NUMPAD2)) //дробовики
{
if(weapon1_change!=0&&reload==false&&N_WEAPON1!=drob1&&winchester_buy==true)
{oboim[N_WEAPON1]=oboima;//запись кол-ва пуль
N_WEAPON1=drob1;//оружие меняется на пистолет
oboima=oboim[N_WEAPON1];//загрузка кол-ва пуль
pred_weapon1=last_weapon1;//предыдущее равно последнему (что было)
last_weapon1=N_WEAPON1; //последнее оружие - сейчасное (=)з)
weapon1_change=0;}
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
}


if(hge->Input_GetKeyState(HGEK_NUMPAD3))  //смг
{
if(weapon1_change!=0&&reload==false&&N_WEAPON1!=smg1&&(pp19_buy==true||mac_buy==true))
{oboim[N_WEAPON1]=oboima;//запись кол-ва пуль
N_WEAPON1=smg1;//оружие меняется на пистолет
oboima=oboim[N_WEAPON1];//загрузка кол-ва пуль
pred_weapon1=last_weapon1;//предыдущее равно последнему (что было)
last_weapon1=N_WEAPON1; //последнее оружие - сейчасное (=)з)
weapon1_change=0;}
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
}

if(hge->Input_GetKeyState(HGEK_NUMPAD4))    //автоматы
{
if(weapon1_change!=0&&reload==false&&N_WEAPON1!=avtomat1&&(ak_buy==true||fn_f2000_buy==true))
{oboim[N_WEAPON1]=oboima;//запись кол-ва пуль
N_WEAPON1=avtomat1;//оружие меняется на пистолет
oboima=oboim[N_WEAPON1];//загрузка кол-ва пуль
pred_weapon1=last_weapon1;//предыдущее равно последнему (что было)
last_weapon1=N_WEAPON1; //последнее оружие - сейчасное (=)з)
weapon1_change=0;}
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
}

if(hge->Input_GetKeyState(HGEK_NUMPAD5))    //пулемёты
{
if(weapon1_change!=0&&reload==false&&N_WEAPON1!=pulemet1&&(rpk_buy==true||rpk47_buy==true))
{oboim[N_WEAPON1]=oboima;//запись кол-ва пуль
N_WEAPON1=pulemet1;//оружие меняется на пистолет
oboima=oboim[N_WEAPON1];//загрузка кол-ва пуль
pred_weapon1=last_weapon1;//предыдущее равно последнему (что было)
last_weapon1=N_WEAPON1; //последнее оружие - сейчасное (=)з)
weapon1_change=0;}
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
}

if(hge->Input_GetKeyState(HGEK_NUMPAD6))    //гранатомёты
{
if(weapon1_change!=0&&reload==false&&N_WEAPON1!=granatomet1&&(rgd5_buy==true||milkor_buy==true||panzer_buy==true))
{oboim[N_WEAPON1]=oboima;//запись кол-ва пуль
N_WEAPON1=granatomet1;//оружие меняется на пистолет
oboima=oboim[N_WEAPON1];//загрузка кол-ва пуль
pred_weapon1=last_weapon1;//предыдущее равно последнему (что было)
last_weapon1=N_WEAPON1; //последнее оружие - сейчасное (=)з)
weapon1_change=0;}
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
}

if(hge->Input_GetKeyState(HGEK_NUMPAD8))    //хододное
{
if(weapon1_change!=0&&reload==false&&N_WEAPON1!=holodnoe1&&katana_buy==true)
{oboim[N_WEAPON1]=oboima;//запись кол-ва пуль
N_WEAPON1=holodnoe1;//оружие меняется на пистолет
oboima=oboim[N_WEAPON1];//загрузка кол-ва пуль
pred_weapon1=last_weapon1;//предыдущее равно последнему (что было)
last_weapon1=N_WEAPON1; //последнее оружие - сейчасное (=)з)
weapon1_change=0;}
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
}



}




if(menu2_on==0&&player2_aktive==1&&net_user!=1)//смена оружия по классам ИГРОКА 2
{

if(hge->Input_GetKeyState(HGEK_1)) //пистолеты
{
if(weapon2_change!=0&&reload2==false&&N_WEAPON2!=pistol2)
{oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль
N_WEAPON2=pistol2;//оружие меняется на пистолет
oboima2=oboim2[N_WEAPON2];//загрузка кол-ва пуль
pred_weapon2=last_weapon2;//предыдущее равно последнему (что было)
last_weapon2=N_WEAPON2; //последнее оружие - сейчасное (=)з)
weapon2_change=0;}
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
}

if(hge->Input_GetKeyState(HGEK_2)) //дробовики
{
if(weapon2_change!=0&&reload2==false&&N_WEAPON2!=drob2&&winchester_buy2==true)
{oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль
N_WEAPON2=drob2;//оружие меняется на пистолет
oboima2=oboim2[N_WEAPON2];//загрузка кол-ва пуль
pred_weapon2=last_weapon2;//предыдущее равно последнему (что было)
last_weapon2=N_WEAPON2; //последнее оружие - сейчасное (=)з)
weapon2_change=0;}
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
}


if(hge->Input_GetKeyState(HGEK_3))  //смг
{
if(weapon2_change!=0&&reload2==false&&N_WEAPON2!=smg2&&(pp19_buy2==true||mac_buy2==true))
{oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль
N_WEAPON2=smg2;//оружие меняется на пистолет
oboima2=oboim2[N_WEAPON2];//загрузка кол-ва пуль
pred_weapon2=last_weapon2;//предыдущее равно последнему (что было)
last_weapon2=N_WEAPON2; //последнее оружие - сейчасное (=)з)
weapon2_change=0;}
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
}

if(hge->Input_GetKeyState(HGEK_4))    //автоматы
{
if(weapon2_change!=0&&reload2==false&&N_WEAPON2!=avtomat2&&(ak_buy2==true||fn_f2000_buy2==true))
{oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль
N_WEAPON2=avtomat2;//оружие меняется на пистолет
oboima2=oboim2[N_WEAPON2];//загрузка кол-ва пуль
pred_weapon2=last_weapon2;//предыдущее равно последнему (что было)
last_weapon2=N_WEAPON2; //последнее оружие - сейчасное (=)з)
weapon2_change=0;}
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
}

if(hge->Input_GetKeyState(HGEK_5))    //пулемёты
{
if(weapon2_change!=0&&reload2==false&&N_WEAPON2!=pulemet2&&(rpk_buy2==true||rpk47_buy2==true))
{oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль
N_WEAPON2=pulemet2;//оружие меняется на пистолет
oboima2=oboim2[N_WEAPON2];//загрузка кол-ва пуль
pred_weapon2=last_weapon2;//предыдущее равно последнему (что было)
last_weapon2=N_WEAPON2; //последнее оружие - сейчасное (=)з)
weapon2_change=0;}
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
}


if(hge->Input_GetKeyState(HGEK_6))    //гранатомёты
{
if(weapon2_change!=0&&reload2==false&&N_WEAPON2!=granatomet2&&(rgd5_buy2==true||milkor_buy2==true||panzer_buy2==true))
{oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль
N_WEAPON2=granatomet2;//оружие меняется на пистолет
oboima2=oboim2[N_WEAPON2];//загрузка кол-ва пуль
pred_weapon2=last_weapon2;//предыдущее равно последнему (что было)
last_weapon2=N_WEAPON2; //последнее оружие - сейчасное (=)з)
weapon2_change=0;}
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
}

if(hge->Input_GetKeyState(HGEK_8))    //холодное
{
if(weapon2_change!=0&&reload2==false&&N_WEAPON2!=holodnoe2&&katana_buy2==true)
{oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль
N_WEAPON2=holodnoe2;//оружие меняется на пистолет
oboima2=oboim2[N_WEAPON2];//загрузка кол-ва пуль
pred_weapon2=last_weapon2;//предыдущее равно последнему (что было)
last_weapon2=N_WEAPON2; //последнее оружие - сейчасное (=)з)
weapon2_change=0;}
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
}



}






//ЗАКРЫТИЕ СМЕНЫ ОРУЖИЯ


//ПЕРЕМЕЩЕНИЕ ПО УРОВНЮ

lvl_go1=false;
lvl_go2=false;
lvl_back1=false;
lvl_back2=false;


float lvl_go1_value=(2.4f-0.2f*140/fps)*speed*dt;
float lvl_go2_value=(2.4f-0.2f*140/fps)*speed2*dt;

if(player2_aktive==0)//1 ИГРОК
{
if(x<=286)
{
X+=lvl_go1_value;
x=287;
lvl_go1=true;
}


if(x>=1184&&X>=0)
{
X-=lvl_go1_value;
x=1183;
lvl_back1=true;
}
}

if(player2_aktive==1)//2 ИГРОКА
{
if(x<=286&&x2<=600)
{
X+=lvl_go1_value;
x=287;
lvl_go1=true;
//if(afk2==true)
//{x2=afx2+(X-afX2);}
}

if(x2<=286&&x<=600)
{
X+=lvl_go2_value;
x2=287;
lvl_go2=true;
//if(afk1==true)
//{x=afx+(X-afX);}
}

if(x>=1184&&x2>=600&&X>=0)
{
X-=lvl_go1_value;
x=1183;
lvl_back1=true;
//if(afk2==true)
//{x2=afx2+(X-afX2);}
}

if(x2>=1184&&x>=600&&X>=0)
{
X-=lvl_go2_value;
x2=1183;
lvl_back2=true;
//if(afk1==true)
//{x=afx+(X-afX);}
}

}



if(lvl_go1==true||lvl_go2==true||lvl_back1==true||lvl_back2==true)//оставление щей
{

if(peregruzheno==0)
{for(int i23=0;i23<=N_TRUPS;i23++)
{trupsObjects[i23].posX=trupsObjects[i23].posX_s+(X-trupsObjects[i23].posX_X);
trupsObjects[i23].posX2=trupsObjects[i23].posX2_s+(X-trupsObjects[i23].posX2_X);}
}

if(peregruzheno==1)
{for(int i23=0;i23<=NUMBER_TRUPS;i23++)
{trupsObjects[i23].posX=trupsObjects[i23].posX_s+(X-trupsObjects[i23].posX_X);
trupsObjects[i23].posX2=trupsObjects[i23].posX2_s+(X-trupsObjects[i23].posX2_X);}
}

for(int i35=0;i35<=N_BONUSTEXT;i35++)
{bonustextiObjects[i35].x=bonustextiObjects[i35].x_s+(X-bonustextiObjects[i35].x_X);}



if(lvl_go1==true)
{dx2+=(speed-3*weight[N_WEAPON1]*vinoslivost1)*sqrt(dt/1400);
for(int i24=0;i24<=N_ZAYAC;i24++)
{vragi1Objects[i24].v1x+=lvl_go1_value;}
for(int i25=0;i25<=N_VOLK;i25++)
{vragi2Objects[i25].v2x+=lvl_go1_value;
if(vragi2Objects[i25].RPG_illusionist!=0)
{vragi2Objects[i25].ill1_x+=lvl_go1_value;
vragi2Objects[i25].ill2_x+=lvl_go1_value;}}
for(int i26=0;i26<=N_UHI;i26++)
{uhiObjects[i26].uhix+=lvl_go1_value;}
for(int i27=0;i27<=N_HEAD;i27++)
{boshkiObjects[i27].bx+=lvl_go1_value;}
for(int i28=0;i28<=MAX_BLOOD-1;i28++)
{krovyakObjects[i28].x1+=lvl_go1_value;
krovyakObjects[i28].x2+=lvl_go1_value;}
for(int i34=0;i34<=N_BONUS;i34++)
{bonusiObjects[i34].x1+=lvl_go1_value;
bonusiObjects[i34].x2+=lvl_go1_value;}
for(int i42=0;i42<=MAX_MYASO-1;i42++)
{myasko[i42].x1+=lvl_go1_value;}
for(int i50=0;i50<=MAX_GREN-1;i50++)
{granati[i50].x+=lvl_go1_value;}
for(int i82=0;i82<=N_MEDVED;i82++)
{vragi3Objects[i82].v3x+=lvl_go1_value;
if(vragi3Objects[i82].RPG_illusionist!=0)
{vragi3Objects[i82].ill1_x+=lvl_go1_value;
vragi3Objects[i82].ill2_x+=lvl_go1_value;}}
for(int i124=0;i124<=N_PTENEC;i124++)
{vragi4Objects[i124].v4x+=lvl_go1_value;
if(vragi4Objects[i124].polet==1)
{vragi4Objects[i124].rx+=lvl_go1_value;}}
}


if(lvl_go2==true)
{dx+=(speed2-3*weight[N_WEAPON2]*vinoslivost2)*sqrt(dt/1400);
for(int i24=0;i24<=N_ZAYAC;i24++)
{vragi1Objects[i24].v1x+=lvl_go2_value;}
for(int i25=0;i25<=N_VOLK;i25++)
{vragi2Objects[i25].v2x+=lvl_go2_value;
if(vragi2Objects[i25].RPG_illusionist!=0)
{vragi2Objects[i25].ill1_x+=lvl_go2_value;
vragi2Objects[i25].ill2_x+=lvl_go2_value;}}
for(int i26=0;i26<=N_UHI;i26++)
{uhiObjects[i26].uhix+=lvl_go2_value;}
for(int i27=0;i27<=N_HEAD;i27++)
{boshkiObjects[i27].bx+=lvl_go2_value;}
for(int i28=0;i28<=MAX_BLOOD-1;i28++)
{krovyakObjects[i28].x1+=lvl_go2_value;
krovyakObjects[i28].x2+=lvl_go2_value;}
for(int i34=0;i34<=N_BONUS;i34++)
{bonusiObjects[i34].x1+=lvl_go2_value;
bonusiObjects[i34].x2+=lvl_go2_value;}
for(int i42=0;i42<=MAX_MYASO-1;i42++)
{myasko[i42].x1+=lvl_go2_value;}
for(int i50=0;i50<=MAX_GREN-1;i50++)
{granati[i50].x+=lvl_go2_value;}
for(int i82=0;i82<=N_MEDVED;i82++)
{vragi3Objects[i82].v3x+=lvl_go2_value;
if(vragi3Objects[i82].RPG_illusionist!=0)
{vragi3Objects[i82].ill1_x+=lvl_go2_value;
vragi3Objects[i82].ill2_x+=lvl_go2_value;}}
for(int i124=0;i124<=N_PTENEC;i124++)
{vragi4Objects[i124].v4x+=lvl_go2_value;
if(vragi4Objects[i124].polet==1)
{vragi4Objects[i124].rx+=lvl_go2_value;}}
}

if(lvl_back1==true)
{dx2-=(speed-3*weight[N_WEAPON1]*vinoslivost1)*sqrt(dt/1400);
for(int i24=0;i24<=N_ZAYAC;i24++)
{vragi1Objects[i24].v1x-=lvl_go1_value;}
for(int i25=0;i25<=N_VOLK;i25++)
{vragi2Objects[i25].v2x-=lvl_go1_value;
if(vragi2Objects[i25].RPG_illusionist!=0)
{vragi2Objects[i25].ill1_x-=lvl_go1_value;
vragi2Objects[i25].ill2_x-=lvl_go1_value;}}
for(int i26=0;i26<=N_UHI;i26++)
{uhiObjects[i26].uhix-=lvl_go1_value;}
for(int i27=0;i27<=N_HEAD;i27++)
{boshkiObjects[i27].bx-=lvl_go1_value;}
for(int i28=0;i28<=MAX_BLOOD-1;i28++)
{krovyakObjects[i28].x1-=lvl_go1_value;
krovyakObjects[i28].x2-=lvl_go1_value;}
for(int i34=0;i34<=N_BONUS;i34++)
{bonusiObjects[i34].x1-=lvl_go1_value;
bonusiObjects[i34].x2-=lvl_go1_value;}
for(int i42=0;i42<=MAX_MYASO-1;i42++)
{myasko[i42].x1-=lvl_go1_value;}
for(int i50=0;i50<=MAX_GREN-1;i50++)
{granati[i50].x-=lvl_go1_value;}
for(int i82=0;i82<=N_MEDVED;i82++)
{vragi3Objects[i82].v3x-=lvl_go1_value;
if(vragi3Objects[i82].RPG_illusionist!=0)
{vragi3Objects[i82].ill1_x-=lvl_go1_value;
vragi3Objects[i82].ill2_x-=lvl_go1_value;}}
for(int i124=0;i124<=N_PTENEC;i124++)
{vragi4Objects[i124].v4x-=lvl_go1_value;
if(vragi4Objects[i124].polet==1)
{vragi4Objects[i124].rx-=lvl_go1_value;}}
}

if(lvl_back2==true)
{dx-=(speed2-3*weight[N_WEAPON2]*vinoslivost2)*sqrt(dt/1400);
for(int i24=0;i24<=N_ZAYAC;i24++)
{vragi1Objects[i24].v1x-=lvl_go2_value;}
for(int i25=0;i25<=N_VOLK;i25++)
{vragi2Objects[i25].v2x-=lvl_go2_value;
if(vragi2Objects[i25].RPG_illusionist!=0)
{vragi2Objects[i25].ill1_x-=lvl_go2_value;
vragi2Objects[i25].ill2_x-=lvl_go2_value;}}
for(int i26=0;i26<=N_UHI;i26++)
{uhiObjects[i26].uhix-=lvl_go2_value;}
for(int i27=0;i27<=N_HEAD;i27++)
{boshkiObjects[i27].bx-=lvl_go2_value;}
for(int i28=0;i28<=MAX_BLOOD-1;i28++)
{krovyakObjects[i28].x1-=lvl_go2_value;
krovyakObjects[i28].x2-=lvl_go2_value;}
for(int i34=0;i34<=N_BONUS;i34++)
{bonusiObjects[i34].x1-=lvl_go2_value;
bonusiObjects[i34].x2-=lvl_go2_value;}
for(int i42=0;i42<=MAX_MYASO-1;i42++)
{myasko[i42].x1-=lvl_go2_value;}
for(int i50=0;i50<=MAX_GREN-1;i50++)
{granati[i50].x-=lvl_go2_value;}
for(int i82=0;i82<=N_MEDVED;i82++)
{vragi3Objects[i82].v3x-=lvl_go2_value;
if(vragi3Objects[i82].RPG_illusionist!=0)
{vragi3Objects[i82].ill1_x-=lvl_go2_value;
vragi3Objects[i82].ill2_x-=lvl_go2_value;}}
for(int i124=0;i124<=N_PTENEC;i124++)
{vragi4Objects[i124].v4x-=lvl_go2_value;
if(vragi4Objects[i124].polet==1)
{vragi4Objects[i124].rx-=lvl_go2_value;}}
}

}//закрытие оставления щей




//ЗАКРЫТИЕ ПЕРЕМЕЩЕНИЯ ПО УРОВНЮ

//Создание сервера
if(hge->Input_GetKeyState(HGEK_I)&&player2_aktive==0)
{
PAUSE=true;
s[0]=socket(AF_INET,SOCK_STREAM,0);//создаем сокет
//WSAAsyncSelect (s[0],main_window_handle,WM_SOCKET,(FD_CLOSE | FD_ACCEPT | FD_READ | FD_WRITE));//сокет сервера асинхронный
//if (connection==SOCKET_ERROR)
//{connection_error=true;
//WSACleanup ();
//strcpy(net_status,"Ошибка init   ");
//return 0;}

server.sin_family = AF_INET;//интернет
server.sin_port = htons (15624);//потр пять адын адын адын
server.sin_addr.s_addr = htonl (INADDR_LOOPBACK); //адрес - наш

if (bind(s[0],(LPSOCKADDR)&server,sizeof(server))==SOCKET_ERROR)//сокет имеет адрес
{connection_error=true;
WSACleanup ();
strcpy(net_status,"Ошибка  bind  server  ");
return 0;}

strcpy(net_status,"Ждем запроса на соединение...");
srvr=true;
}

if(hge->Input_GetKeyState(HGEK_C)&&player2_aktive==0)
{PAUSE=true;
s[4]=socket(AF_INET,SOCK_STREAM,0);//создаем сокет
//WSAAsyncSelect(s[4],main_window_handle,WM_SOCKET,(FD_CLOSE | FD_CONNECT | FD_READ | FD_WRITE));//сокет серверного клиента асинхронный
you.sin_family = AF_INET;
you.sin_port = htons (15624);	
strcpy(net_status,"Введите IP:");

client[0].sin_family=AF_INET;
client[0].sin_addr.s_addr= htonl (INADDR_LOOPBACK); //адрес - наш
client[0].sin_port= htons (IPPORT_REGISTERED_MAX );

clnt=true;
}

//blood_ssit_psi->MoveTo(x,y);
blood_ssit_psi->Fire();
blood_ssit_psi->info.bRelative=false;
blood_ssit_psi->info.fSpeedMin=-1.43f*sqrt(150/(float)fps);
blood_ssit_psi->info.fSpeedMax=-1.43f*sqrt(150/(float)fps);
blood_ssit_psi->info.fParticleLifeMin=0.16f*sqrt(150/(float)fps);
blood_ssit_psi->info.colColorStart=0xFFD72323;
blood_ssit_psi->info.colColorEnd=0xFFCD1A1A;
blood_ssit_psi->Update(dt);



RPG_healing_psi->Fire();
RPG_healing_psi->info.fSpeedMin=1.1f*sqrt(150/(float)fps);
RPG_healing_psi->info.fSpeedMax=sqrt(150/(float)fps);
RPG_healing_psi->info.fParticleLifeMin=0.36f*sqrt(150/(float)fps);
RPG_healing_psi->info.bRelative=false;
RPG_healing_psi->Update(dt);

//vzriv_grena_psi->info.nEmission=250;
//vzriv_grena_psi->info.fSpeedMin=sqrt(150/(float)fps);
//vzriv_grena_psi->info.fSpeedMax=sqrt(150/(float)fps);
//vzriv_grena_psi->info.fParticleLifeMin=0.7f*sqrt(150/(float)fps);
//vzriv_grena_psi->info.bRelative=false;
//vzriv_grena_psi->Update(dt);

vzriv_ogon_grena_psi->info.nEmission=300;
vzriv_ogon_grena_psi->info.fSpeedMin=2.5f*sqrt(150/(float)fps);
vzriv_ogon_grena_psi->info.fSpeedMax=0.8f*sqrt(150/(float)fps);
vzriv_ogon_grena_psi->info.fParticleLifeMin=0.16f*sqrt(150/(float)fps);
vzriv_ogon_grena_psi->info.bRelative=false;
vzriv_ogon_grena_psi->Update(dt);


if(RPGMOD==true)
{

//ПРОСЧЕТ ОПЫТА
opit1_x2=1023+177*opit1/opit_lvl[LVL1-1];
if(opit1>=opit_lvl[LVL1-1])
{opit1-=opit_lvl[LVL1-1];
lvl1_ready=true;
LVL1++;
opit_points1+=3;
if(LVL1%2==0)
{naviki_points1++;}
}


if(lvl1_ready==true)
{

if(lvl1_mig==0)
{lvl1_mig_time=perez_akt;
lvl1_mig_time_milli=GetTime();
lvl1_mig=1;
}

if(lvl1_mig==1&&lvl1_mig_time_milli<500&&perez_akt!=60&&
((perez_akt==lvl1_mig_time&&perez_akt_milli>=lvl1_mig_time_milli+500)||
 (perez_akt!=lvl1_mig_time)))
{lvl1_mig_time=perez_akt;
lvl1_mig_time_milli=GetTime();
lvl1_mig=2;}

if(lvl1_mig==1&&lvl1_mig_time_milli>=500&&perez_akt!=lvl1_mig_time&&perez_akt_milli>=lvl1_mig_time_milli-500)
{lvl1_mig_time=perez_akt;
lvl1_mig_time_milli=GetTime();
lvl1_mig=2;}

if(lvl1_mig==2&&lvl1_mig_time_milli<500&&perez_akt!=60&&
((perez_akt==lvl1_mig_time&&perez_akt_milli>=lvl1_mig_time_milli+500)||
 (perez_akt!=lvl1_mig_time)))
{lvl1_mig_time=perez_akt;
lvl1_mig_time_milli=GetTime();
lvl1_mig=1;}

if(lvl1_mig==2&&lvl1_mig_time_milli>=500&&perez_akt!=lvl1_mig_time&&perez_akt_milli>=lvl1_mig_time_milli-500)
{lvl1_mig_time=perez_akt;
lvl1_mig_time_milli=GetTime();
lvl1_mig=1;}


if(hge->Input_GetKeyState(HGEK_L)&&lvl_key_block==false&&reload==false&&reload2==false&&net_user!=2)
{lvl1_ready=false;
lvl1_mig=0;
lvl1_vibor=true;
lvl_key_block=true;
lvl_key_time=GetCurrentSecond();
lvl_key_time_milli=GetTime();
VIBOR=0;
VIBOR_ITEM=1;}

}//lvl1_ready==true


if(player2_aktive==1)
{
opit2_x2=1023+177*opit2/opit_lvl[LVL2-1];
if(opit2>=opit_lvl[LVL2-1])
{opit2-=opit_lvl[LVL2-1];
lvl2_ready=true;
LVL2++;
opit_points2+=3;
if(LVL2%2==0)
{naviki_points2++;}
}

if(lvl2_ready==true)
{

if(lvl2_mig==0)
{lvl2_mig_time=perez_akt;
lvl2_mig_time_milli=GetTime();
lvl2_mig=1;
}

if(lvl2_mig==1&&lvl2_mig_time_milli<500&&perez_akt!=60&&
((perez_akt==lvl2_mig_time&&perez_akt_milli>=lvl2_mig_time_milli+500)||
 (perez_akt!=lvl2_mig_time)))
{lvl2_mig_time=perez_akt;
lvl2_mig_time_milli=GetTime();
lvl2_mig=2;}

if(lvl2_mig==1&&lvl2_mig_time_milli>=500&&perez_akt!=lvl2_mig_time&&perez_akt_milli>=lvl2_mig_time_milli-500)
{lvl2_mig_time=perez_akt;
lvl2_mig_time_milli=GetTime();
lvl2_mig=2;}

if(lvl2_mig==2&&lvl2_mig_time_milli<500&&perez_akt!=60&&
((perez_akt==lvl2_mig_time&&perez_akt_milli>=lvl2_mig_time_milli+500)||
 (perez_akt!=lvl2_mig_time)))
{lvl2_mig_time=perez_akt;
lvl2_mig_time_milli=GetTime();
lvl2_mig=1;}

if(lvl2_mig==2&&lvl2_mig_time_milli>=500&&perez_akt!=lvl2_mig_time&&perez_akt_milli>=lvl2_mig_time_milli-500)
{lvl2_mig_time=perez_akt;
lvl2_mig_time_milli=GetTime();
lvl2_mig=1;}


if(hge->Input_GetKeyState(HGEK_F)&&lvl_key_block==false&&reload==false&&reload2==false&&net_user!=1)
{lvl2_ready=false;
lvl2_mig=0;
lvl2_vibor=true;
lvl_key_block=true;
lvl_key_time=GetCurrentSecond();
lvl_key_time_milli=GetTime();
VIBOR=0;
VIBOR_ITEM=1;}

}//lvl2_ready==true


}//player2_aktive==true

}//RPGMOD==true


if(TEST_REZHIM==false)//тестовый режим
{
//УСЛОВИЕ ПОБЕДЫ
if(player2_aktive==0&&X-lvl1_lenght>=x&&LIVES>=0)
{pobeda=true;}
if(player2_aktive==1&&X-lvl1_lenght>=x&&X-lvl1_lenght>=x2&&LIVES>=0)
{pobeda=true;}
//УСЛОВИЕ ПОРАЖЕНИЯ
if(LIVES<0&&player2_aktive==0&&X-lvl1_lenght<x)
{porazhenie=true;}
if(player2_aktive==1&&(X-lvl1_lenght<x||X-lvl1_lenght<x2)&&LIVES<0)
{porazhenie=true;}
}//тестовый режим

//ПРОДВИЖЕНИЕ ИГРЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫ-//////////////////////////////////
//120 - середина зеленого режима
if(player2_aktive==0)
{
if(kills>=2&&GAME_PROGRESS==0)
{zayac_add();
ptenec_add();
GAME_PROGRESS=1;}
if(kills>=15&&GAME_PROGRESS==1)
{zayac_add();
GAME_PROGRESS=2;}
if(kills>=40&&GAME_PROGRESS==2)
{zayac_add();
GAME_PROGRESS=3;}
if(kills>=70&&GAME_PROGRESS==3)
{zayac_add();
volk_add();
GAME_PROGRESS=4;}
if(kills>=100&&GAME_PROGRESS==4)
{zayac_add();
GAME_PROGRESS=5;}
if(kills>=150&&GAME_PROGRESS==5)
{medved_add();
GAME_PROGRESS=6;}
if(kills>=250&&GAME_PROGRESS==6)
{zayac_add();
rpg_healers=true;
GAME_PROGRESS=7;}
if(kills>=400&&GAME_PROGRESS==7)
{
volk_add();
rpg_illusionists=true;
GAME_PROGRESS=8;}
if(kills>=750&&GAME_PROGRESS==8)
{
rpg_teleporters=true;
GAME_PROGRESS=9;}
}




if(player2_aktive==1)
{

if(kills+kills2>=4&&GAME_PROGRESS==0)
{zayac_add();
zayac_add();
GAME_PROGRESS=1;}
if(kills+kills2>=30&&GAME_PROGRESS==1)
{zayac_add();
zayac_add();
GAME_PROGRESS=2;}
if(kills+kills2>=80&&GAME_PROGRESS==2)
{zayac_add();
zayac_add();
GAME_PROGRESS=3;}
if(kills+kills2>=140&&GAME_PROGRESS==3)
{zayac_add();//не хватает 1-го...ну и пусть
volk_add();
volk_add();
GAME_PROGRESS=4;}
if(kills+kills2>=200&&GAME_PROGRESS==4)
{zayac_add();
zayac_add();
GAME_PROGRESS=5;}
if(kills+kills2>=300&&GAME_PROGRESS==5)
{medved_add();
medved_add();
rpg_healers=true;
GAME_PROGRESS=6;}
if(kills+kills2>=360&&GAME_PROGRESS==6)
{zayac_add();
zayac_add();
rpg_healers=true;
GAME_PROGRESS=7;}
if(kills+kills2>=500&&GAME_PROGRESS==7)
{volk_add();
volk_add();
rpg_illusionists=true;
GAME_PROGRESS=8;}
if(kills>=600&&GAME_PROGRESS==8)
{rpg_teleporters=true;
GAME_PROGRESS=9;}

}



//ПОВЫШЕНИЕ ЗАЩИТЫ МОБОВ

if((defence_upgrade_sec<45&&perez_akt==defence_upgrade_sec+15)||
(defence_upgrade_sec>=45&&perez_akt==defence_upgrade_sec-45))
{
if(N_ZAYAC>=0)
{defence_zayac++;}

if(N_VOLK>=0)
{defence_volk++;}

if(N_MEDVED>=0)
{defence_medved++;}

defence_upgrade_sec=perez_akt;
}


//ПОВЫШЕНИЕ СЛОЖНОСТИ

if(perez_akt==30)
{

if(DIFF==1&&DIFF_UP==true&&DIFF_UPGRADED==false)//с синего на красный +
{DIFF++;
DIFF_UPGRADED=true;

if((int)(N_ZAYAC+1)%2==0)
{n_zayac_up=(N_ZAYAC+1)/2;}
if((int)(N_ZAYAC+1)%2!=0)
{n_zayac_up=N_ZAYAC/2;}
for(int i101=1;i101<=n_zayac_up;i101++)
{zayac_add();}

}

if(DIFF==1&&DIFF_UP==false&&DIFF_UPGRADED==false)//с синего на зелёный -
{DIFF--;
DIFF_UPGRADED=true;

if((int)(N_ZAYAC+1)%2==0)
{n_zayac_down=(N_ZAYAC+1)/2;}
if((int)(N_ZAYAC+1)%2!=0)
{n_zayac_down=N_ZAYAC/2;}
n_zayac_up=n_zayac_down;
zayac_must_down=true;
}
		
if(DIFF==2&&DIFF_UP==true&&DIFF_UPGRADED==false)//с красного на синий -
{DIFF--;
DIFF_UP=false;
DIFF_UPGRADED=true;

zayac_must_down=true;}

if(DIFF==0&&DIFF_UP==false&&DIFF_UPGRADED==false)//с зелёного на синий +
{DIFF++;
DIFF_UP=true;
DIFF_UPGRADED=true;

for (int i104=1;i104<=n_zayac_up;i104++)
{zayac_add();}
n_zayac_up=0;
}

}//if(perez_akt==30)

if(perez_akt==31&&DIFF_UPGRADED==true)
{DIFF_UPGRADED=false;}

if(zayac_must_down==true)//исчезновение лишних зайцев (когда они убиты)
{

if((vragi1Objects[N_ZAYAC].ubit==1||vragi1Objects[N_ZAYAC].v1x<0)&&n_zayac_up!=0&&DIFF==1)
{N_ZAYAC--;
n_zayac_up--;}
if(n_zayac_up==0&&DIFF==1)
{zayac_must_down=false;}

if((vragi1Objects[N_ZAYAC].ubit==1||vragi1Objects[N_ZAYAC].v1x<0)&&n_zayac_down!=0&&DIFF==0)
{N_ZAYAC--;
n_zayac_down--;}
if(n_zayac_down==0&&DIFF==0)
{zayac_must_down=false;}

}//закрытие исчезновения лишних зайцев




if(N_TRUPS>=MAX_TRUPS-1)
{NUMBER_TRUPS=N_TRUPS;
N_TRUPS=0;
peregruzheno=1;
}

if(N_BLOOD==MAX_BLOOD-1)
{
NUMBER_BLOOD=N_BLOOD;	
N_BLOOD=0;
peregruzheno_blood=1;}//  ААААА ФАК МОЙ МОСК ТУТ ВСЕГДА ДОЛЖЕН БЫТЬ 0!!!!!



//----Y-COORDINATING-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-


N_Y=0;//обнуление



for(int ii6=0;ii6<=N_ZAYAC;ii6++)
{
Y[N_Y].type=1;
Y[N_Y].y=vragi1Objects[ii6].v1y;
Y[N_Y].id=ii6;
N_Y++;
}

for(int ii7=0;ii7<=N_VOLK;ii7++)
{
Y[N_Y].type=2;
Y[N_Y].y=vragi2Objects[ii7].v2y+10;
Y[N_Y].id=ii7;
N_Y++;
}

for(int ii25=0;ii25<=N_MEDVED;ii25++)
{
Y[N_Y].type=10;
Y[N_Y].y=vragi3Objects[ii25].v3y+180;
Y[N_Y].id=ii25;
N_Y++;
}

for(int ii27=0;ii27<=N_PTENEC;ii27++)
{
Y[N_Y].type=11;
Y[N_Y].y=vragi4Objects[ii27].v4y+25;
Y[N_Y].id=ii27;
N_Y++;
}

for(int ii8=0;ii8<=N_MYASO;ii8++)
{
if(myasko[ii8].akt==1)
{Y[N_Y].type=3;
Y[N_Y].y=myasko[ii8].niz-15;
Y[N_Y].id=ii8;
N_Y++;}
}

for(int ii9=0;ii9<=N_UHI;ii9++)
{
Y[N_Y].type=4;
Y[N_Y].y=uhiObjects[ii9].niz-15;
Y[N_Y].id=ii9;
N_Y++;
}

for(int ii10=0;ii10<=N_HEAD;ii10++)
{
Y[N_Y].type=5;
Y[N_Y].y=boshkiObjects[ii10].niz-15;
Y[N_Y].id=ii10;
N_Y++;
}

for(int ii11=0;ii11<=N_BONUS;ii11++)
{
Y[N_Y].type=6;
Y[N_Y].y=bonusiObjects[ii11].y2;
Y[N_Y].id=ii11;
N_Y++;
}

for(int ii12=0;ii12<=N_OBJECTS-1;ii12++)
{
Y[N_Y].type=7;
switch(Objects[ii12].type)
{
case 0:
Y[N_Y].y=Objects[ii12].y;
break;
case 1:
Y[N_Y].y=Objects[ii12].y-10;
break;
case 2:
Y[N_Y].y=Objects[ii12].y-10;
break;}
Y[N_Y].id=ii12;
N_Y++;
}

for(int ii13=0;ii13<=N_GILZ;ii13++)
{
Y[N_Y].type=8;
Y[N_Y].y=gilziObjects[ii13].niz-hge->Random_Float(46,50);
Y[N_Y].id=ii13;
N_Y++;
}

for(int ii20=0;ii20<=N_GREN;ii20++)
{
Y[N_Y].type=9;
Y[N_Y].y=granati[ii20].y;
Y[N_Y].id=ii20;
N_Y++;
}




/*
for(int ii14=0;ii14<=N_BLOOD;ii14++)
{
Y[N_Y].type=9;
Y[N_Y].y=krovyakObjects[ii14].niz-hge->Random_Float(-3,3);
Y[N_Y].id=ii14;
N_Y++;
}*/

Y[N_Y].type=101;
Y[N_Y].y=y+10;
N_Y++;

Y[N_Y].type=102;
Y[N_Y].y=y2+10;
N_Y++;

//НАЧАЛО ТАСОВКИ

//проверка
for(int ii20=0; ii20<=N_Y; ii20++)
{
for(int ii21=0; ii21<=N_Y; ii21++)
{
if(Y[ii20].y==Y[ii21].y&&ii20!=ii21)
{Y[ii20].y+=0.1f;}
}
}





for(int ii2=0;ii2<=N_Y;ii2++)
{

for(int ii5=0;ii5<=N_Y;ii5++)
{if(Y[ii5].A!=1)
{y_min=Y[ii5].y;
y_type=Y[ii5].type;
y_id=Y[ii5].id;}}

for(int ii=0;ii<=N_Y;ii++)//проверка на меньшее число
{if(Y[ii].y<=y_min&&Y[ii].A!=1)  
{y_min=Y[ii].y;
y_type=Y[ii].type;
y_id=Y[ii].id;}}

for(int ii4=0;ii4<=N_Y;ii4++)//обсчитывается нужный object
{if(y_min==Y[ii4].y)  
{Y[ii4].A=1;}}
A[ii2].y=y_min;
A[ii2].type=y_type;
A[ii2].id=y_id;
}

//КОНЕЦ ТАСОВКИ



//ОБНУЛЕНИЕ
for(int ii3=0;ii3<=N_Y;ii3++)
{Y[ii3].A=0;}

//-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-


//БРАТЬ ВРЕМЯ ТУТ->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	/*perez_akt=GetCurrentSecond()-pause_time_sec;//это работает ПОСТОЯННО (не выносить в ф-ию)
	if(perez_akt>59)
	{perez_akt%=60;}
	if(perez_akt<0)
	{perez_akt=60+GetCurrentSecond()-pause_time_sec;}*/

	perez_akt_milli=GetTime();
	//perez_akt=GetCurrentSecond();

	time_now=GetCurrentSecond();
	
	if(time_was!=time_now)
	{
	time_was=time_now;
	
	if(perez_akt<60&&perez_akt>0)
	{perez_akt++;}


	if(perez_akt==0)
	{perez_akt=1;}

	
	if(perez_akt==60)//сразу исключаем 60-ю секунду (нулевую)
	{perez_akt=0;
	leveltime++;}
	
	
	}




}//-------------------------PAUSE==FALSE-----------------------------------------|||||||||||||||||||||||||||||||||||||||||||\

  


if(hge->Input_GetKeyState(HGEK_O)&&net_user!=0)
{Close_Net();
PAUSE=false;
}

if(clnt==true)
{
Connect_Net();
}

if(srvr==true)
{
Init_Net();
}



//----BUY

weapon1_buy=1;
weapon2_buy=1;


//выход из меню
if(menu1_on!=0&&hge->Input_GetKeyState(HGEK_NUMPAD0)&&net_user!=2)
{menu1_on=0;
PAUSE=false;
}

if(menu2_on!=0&&hge->Input_GetKeyState(HGEK_0)&&net_user!=1)
{menu2_on=0;
PAUSE=false;
}



//вход в меню пистолетов
if(menu1_on==1&&hge->Input_GetKeyState(HGEK_NUMPAD1)&&net_user!=2)
{menu1_on=2;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();}

if(menu2_on==1&&hge->Input_GetKeyState(HGEK_1)&&net_user!=1)
{menu2_on=2;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();}

//вход в меню дробовиков
if(menu1_on==1&&hge->Input_GetKeyState(HGEK_NUMPAD2)&&net_user!=2)
{menu1_on=3;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();}

if(menu2_on==1&&hge->Input_GetKeyState(HGEK_2)&&net_user!=1)
{menu2_on=3;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();}


//вход в меню SMG
if(menu1_on==1&&hge->Input_GetKeyState(HGEK_NUMPAD3)&&net_user!=2)
{menu1_on=4;}

if(menu2_on==1&&hge->Input_GetKeyState(HGEK_3)&&net_user!=1)
{menu2_on=4;}



//вход в меню автоматов
if(menu1_on==1&&hge->Input_GetKeyState(HGEK_NUMPAD4)&&net_user!=2)
{menu1_on=5;}

if(menu2_on==1&&hge->Input_GetKeyState(HGEK_4)&&net_user!=1)
{menu2_on=5;}

//вход в меню пулемётов
if(menu1_on==1&&hge->Input_GetKeyState(HGEK_NUMPAD5)&&net_user!=2)
{menu1_on=6;}

if(menu2_on==1&&hge->Input_GetKeyState(HGEK_5)&&net_user!=1)
{menu2_on=6;}

//вход в меню гранатомётов
if(menu1_on==1&&hge->Input_GetKeyState(HGEK_NUMPAD6)&&net_user!=2)
{menu1_on=7;}

if(menu2_on==1&&hge->Input_GetKeyState(HGEK_6)&&net_user!=1)
{menu2_on=7;}

//вход в меню холодного оружия
if(menu1_on==1&&hge->Input_GetKeyState(HGEK_NUMPAD8)&&net_user!=2)
{menu1_on=9;}

if(menu2_on==1&&hge->Input_GetKeyState(HGEK_8)&&net_user!=1)
{menu2_on=9;}


//апгрейд AK
if(menu1_on==5&&hge->Input_GetKeyState(HGEK_NUMPAD1)&&ak_buy==true&&ak_up==false&&net_user!=2)
{
if(points1>=cena_up[1])
{ak_up=true;
points1-=cena_up[1];
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena_up[1])
{menu1_on=0;
PAUSE=false;}
}
if(menu2_on==5&&hge->Input_GetKeyState(HGEK_1)&&ak_buy2==true&&ak_up2==false&&net_user!=1)
{
if(points2>=cena_up[1])
{ak_up2=true;
points2-=cena_up[1];
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena_up[1])
{menu2_on=0;
PAUSE=false;}
}


//покупка автомата АК
if(menu1_on==5&&hge->Input_GetKeyState(HGEK_NUMPAD1)&&ak_buy==false&&net_user!=2)
{
if(points1>=cena[0])
{pred_weapon1=N_WEAPON1;
oboim[N_WEAPON1]=oboima;//запись кол-ва пуль до покупки
N_WEAPON1=0;
ak_buy=true;
last_weapon1=N_WEAPON1;
oboima=oboim[N_WEAPON1];
points1-=cena[0];
if(fn_f2000_buy==false)
{avtomat1=0;}
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena[0])
{menu1_on=0;
PAUSE=false;}
}


if(menu2_on==5&&hge->Input_GetKeyState(HGEK_1)&&ak_buy2==false&&net_user!=1)
{
if(points2>=cena[0])
{pred_weapon2=N_WEAPON2;
oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль до покупки
N_WEAPON2=0;
ak_buy2=true;
last_weapon2=N_WEAPON2;
oboima2=oboim2[N_WEAPON2];
points2-=cena[0];
if(fn_f2000_buy2==false)
{avtomat2=0;}
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena[0])
{menu2_on=0;
PAUSE=false;}
}




//покупка ПП-19 "Витязь"
if(menu1_on==4&&hge->Input_GetKeyState(HGEK_NUMPAD2)&&pp19_buy==false&&net_user!=2)
{
if(points1>=cena[2])
{pred_weapon1=N_WEAPON1;
oboim[N_WEAPON1]=oboima;//запись кол-ва пуль до покупки
N_WEAPON1=2;
pp19_buy=true;
last_weapon1=N_WEAPON1;
oboima=oboim[N_WEAPON1];
points1-=cena[2];
smg1=2;
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena[2])
{menu1_on=0;
PAUSE=false;}
}


if(menu2_on==4&&hge->Input_GetKeyState(HGEK_2)&&pp19_buy2==false&&net_user!=1)
{
if(points2>=cena[2])
{pred_weapon2=N_WEAPON2;
oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль до покупки
N_WEAPON2=2;
pp19_buy2=true;
last_weapon2=N_WEAPON2;
oboima2=oboim2[N_WEAPON2];
points2-=cena[2];
smg2=2;
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena[2])
{menu2_on=0;
PAUSE=false;}
}


//апгрейд FN F-2000
if(menu1_on==5&&hge->Input_GetKeyState(HGEK_NUMPAD2)&&fn_f2000_buy==true&&fn_f2000_up==false&&net_user!=2)
{
if(points1>=cena_up[0])
{fn_f2000_up=true;
points1-=cena_up[0];
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena_up[0])
{menu1_on=0;
PAUSE=false;}
}
if(menu2_on==5&&hge->Input_GetKeyState(HGEK_2)&&fn_f2000_buy2==true&&fn_f2000_up2==false&&net_user!=1)
{
if(points2>=cena_up[0])
{fn_f2000_up2=true;
points2-=cena_up[0];
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena_up[0])
{menu2_on=0;
PAUSE=false;}
}


//покупка FN F-2000
if(menu1_on==5&&hge->Input_GetKeyState(HGEK_NUMPAD2)&&fn_f2000_buy==false&&net_user!=2)
{
if(points1>=cena[3])
{pred_weapon1=N_WEAPON1;
oboim[N_WEAPON1]=oboima;//запись кол-ва пуль до покупки
N_WEAPON1=3;
fn_f2000_buy=true;
last_weapon1=N_WEAPON1;
oboima=oboim[N_WEAPON1];
points1-=cena[3];
avtomat1=3;
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena[3])
{menu1_on=0;
PAUSE=false;}
}


if(menu2_on==5&&hge->Input_GetKeyState(HGEK_2)&&fn_f2000_buy2==false&&net_user!=1)
{
if(points2>=cena[3])
{pred_weapon2=N_WEAPON2;
oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль до покупки
N_WEAPON2=3;
fn_f2000_buy2=true;
last_weapon2=N_WEAPON2;
oboima2=oboim2[N_WEAPON2];
points2-=cena[3];
avtomat2=3;
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena[3])
{menu2_on=0;
PAUSE=false;}
}



//покупка TT
if(menu1_on==2&&weapon1_change!=0&&hge->Input_GetKeyState(HGEK_NUMPAD1)&&tt_buy==false&&net_user!=2)
{
if(points1>=cena[4])
{pred_weapon1=N_WEAPON1;
oboim[N_WEAPON1]=oboima;//запись кол-ва пуль до покупки
N_WEAPON1=4;
tt_buy=true;
last_weapon1=N_WEAPON1;
oboima=oboim[N_WEAPON1];
points1-=cena[4];
if(glok_buy==false&&webley_buy!=true&&fn_five_seven_buy!=true)
{pistol1=4;}
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena[4])
{menu1_on=0;
PAUSE=false;}
}

if(menu2_on==2&&weapon2_change!=0&&hge->Input_GetKeyState(HGEK_1)&&tt_buy2==false&&net_user!=1)
{
if(points2>=cena[4])
{pred_weapon2=N_WEAPON2;
oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль до покупки
N_WEAPON2=4;
tt_buy2=true;
last_weapon2=N_WEAPON2;
oboima2=oboim2[N_WEAPON2];
points2-=cena[4];
if(glok_buy2==false&&webley_buy2!=true&&fn_five_seven_buy2!=true)
{pistol2=4;}
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena[4])
{menu2_on=0;
PAUSE=false;}
}

//покупка РПК
if(menu1_on==6&&weapon1_change!=0&&hge->Input_GetKeyState(HGEK_NUMPAD2)&&rpk_buy==false&&net_user!=2)
{
if(points1>=cena[5])
{pred_weapon1=N_WEAPON1;
oboim[N_WEAPON1]=oboima;//запись кол-ва пуль до покупки
N_WEAPON1=5;
rpk_buy=true;
last_weapon1=N_WEAPON1;
oboima=oboim[N_WEAPON1];
points1-=cena[5];
pulemet1=5;
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena[5])
{menu1_on=0;
PAUSE=false;}
}

if(menu2_on==6&&weapon2_change!=0&&hge->Input_GetKeyState(HGEK_2)&&rpk_buy2==false&&net_user!=1)
{
if(points2>=cena[5])
{pred_weapon2=N_WEAPON2;
oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль до покупки
N_WEAPON2=5;
rpk_buy2=true;
last_weapon2=N_WEAPON2;
oboima2=oboim2[N_WEAPON2];
points2-=cena[5];
pulemet2=5;
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena[5])
{menu2_on=0;
PAUSE=false;}
}

//покупка MAC
if(menu1_on==4&&weapon1_change!=0&&hge->Input_GetKeyState(HGEK_NUMPAD1)&&mac_buy==false&&net_user!=2)
{
if(points1>=cena[6])
{pred_weapon1=N_WEAPON1;
oboim[N_WEAPON1]=oboima;//запись кол-ва пуль до покупки
N_WEAPON1=6;
mac_buy=true;
last_weapon1=N_WEAPON1;
oboima=oboim[N_WEAPON1];
points1-=cena[6];
if(pp19_buy==false)
{smg1=6;}
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena[6])
{menu1_on=0;
PAUSE=false;}
}

if(menu2_on==4&&weapon2_change!=0&&hge->Input_GetKeyState(HGEK_1)&&mac_buy2==false&&net_user!=1)
{
if(points2>=cena[6])
{pred_weapon2=N_WEAPON2;
oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль до покупки
N_WEAPON2=6;
mac_buy2=true;
last_weapon2=N_WEAPON2;
oboima2=oboim2[N_WEAPON2];
points2-=cena[6];
if(pp19_buy2==false)
{smg2=6;}
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena[6])
{menu2_on=0;
PAUSE=false;}
}


//покупка winchester
if(menu1_on==3&&weapon1_change!=0&&hge->Input_GetKeyState(HGEK_NUMPAD1)&&winchester_buy==false&&net_user!=2)
{
if(points1>=cena[7])
{pred_weapon1=N_WEAPON1;
oboim[N_WEAPON1]=oboima;//запись кол-ва пуль до покупки
N_WEAPON1=7;
winchester_buy=true;
last_weapon1=N_WEAPON1;
oboima=oboim[N_WEAPON1];
points1-=cena[7];
drob1=7;
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena[7])
{menu1_on=0;
PAUSE=false;}
}

if(menu2_on==3&&weapon2_change!=0&&hge->Input_GetKeyState(HGEK_1)&&winchester_buy2==false&&net_user!=1)
{
if(points2>=cena[7])
{pred_weapon2=N_WEAPON2;
oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль до покупки
N_WEAPON2=7;
winchester_buy2=true;
last_weapon2=N_WEAPON2;
oboima2=oboim2[N_WEAPON2];
points2-=cena[7];
drob2=7;
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena[7])
{menu2_on=0;
PAUSE=false;}
}

//покупка РПК 47
if(menu1_on==6&&weapon1_change!=0&&hge->Input_GetKeyState(HGEK_NUMPAD1)&&rpk47_buy==false&&net_user!=2)
{
if(points1>=cena[8])
{pred_weapon1=N_WEAPON1;
oboim[N_WEAPON1]=oboima;//запись кол-ва пуль до покупки
N_WEAPON1=8;
rpk47_buy=true;
last_weapon1=N_WEAPON1;
oboima=oboim[N_WEAPON1];
points1-=cena[8];
if(rpk_buy==false)
{pulemet1=8;}
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena[8])
{menu1_on=0;
PAUSE=false;}
}

if(menu2_on==6&&weapon2_change!=0&&hge->Input_GetKeyState(HGEK_1)&&rpk47_buy2==false&&net_user!=1)
{
if(points2>=cena[8])
{pred_weapon2=N_WEAPON2;
oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль до покупки
N_WEAPON2=8;
rpk47_buy2=true;
last_weapon2=N_WEAPON2;
oboima2=oboim2[N_WEAPON2];
points2-=cena[8];
if(rpk_buy2==false)
{pulemet2=8;}
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena[8])
{menu2_on=0;
PAUSE=false;}
}



//покупка GLOK
if(menu1_on==2&&weapon1_change!=0&&hge->Input_GetKeyState(HGEK_NUMPAD2)&&glok_buy==false&&net_user!=2)
{
if(points1>=cena[9])
{pred_weapon1=N_WEAPON1;
oboim[N_WEAPON1]=oboima;//запись кол-ва пуль до покупки
N_WEAPON1=9;
glok_buy=true;
last_weapon1=N_WEAPON1;
oboima=oboim[N_WEAPON1];
points1-=cena[9];
if(webley_buy!=true&&fn_five_seven_buy!=true)
{pistol1=9;}
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena[9])
{menu1_on=0;
PAUSE=false;}
}

if(menu2_on==2&&weapon2_change!=0&&hge->Input_GetKeyState(HGEK_2)&&glok_buy2==false&&net_user!=1)
{
if(points2>=cena[9])
{pred_weapon2=N_WEAPON2;
oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль до покупки
N_WEAPON2=9;
glok_buy2=true;
last_weapon2=N_WEAPON2;
oboima2=oboim2[N_WEAPON2];
points2-=cena[9];
if(webley_buy2!=true&&fn_five_seven_buy2!=true)
{pistol2=9;}
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena[9])
{menu2_on=0;
PAUSE=false;}
}


//покупка РГД-5
if(menu1_on==7&&weapon1_change!=0&&hge->Input_GetKeyState(HGEK_NUMPAD1)&&rgd5_buy==false&&net_user!=2)
{
if(points1>=cena[10])
{pred_weapon1=N_WEAPON1;
oboim[N_WEAPON1]=oboima;//запись кол-ва пуль до покупки
N_WEAPON1=10;
rgd5_buy=true;
last_weapon1=N_WEAPON1;
oboima=oboim[N_WEAPON1];
points1-=cena[10];
if(milkor_buy!=true&&panzer_buy!=true)
{granatomet1=10;}
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena[10])
{menu1_on=0;
PAUSE=false;}
}

if(menu2_on==7&&weapon2_change!=0&&hge->Input_GetKeyState(HGEK_1)&&rgd5_buy2==false&&net_user!=1)
{
if(points2>=cena[10])
{pred_weapon2=N_WEAPON2;
oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль до покупки
N_WEAPON2=10;
rgd5_buy2=true;
last_weapon2=N_WEAPON2;
oboima2=oboim2[N_WEAPON2];
points2-=cena[10];
if(milkor_buy2!=true&&panzer_buy2!=true)
{granatomet2=10;}
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena[10])
{menu2_on=0;
PAUSE=false;}
}


//покупка катаны
if(menu1_on==9&&weapon1_change!=0&&hge->Input_GetKeyState(HGEK_NUMPAD2)&&katana_buy==false&&net_user!=2)
{
if(points1>=cena[11])
{pred_weapon1=N_WEAPON1;
oboim[N_WEAPON1]=oboima;//запись кол-ва пуль до покупки
N_WEAPON1=11;
katana_buy=true;
last_weapon1=N_WEAPON1;
oboima=oboim[N_WEAPON1];
points1-=cena[11];
holodnoe1=11;
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena[11])
{menu1_on=0;
PAUSE=false;}
}

if(menu2_on==9&&weapon2_change!=0&&hge->Input_GetKeyState(HGEK_2)&&katana_buy2==false&&net_user!=1)
{
if(points2>=cena[11])
{pred_weapon2=N_WEAPON2;
oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль до покупки
N_WEAPON2=11;
katana_buy2=true;
last_weapon2=N_WEAPON2;
oboima2=oboim2[N_WEAPON2];
points2-=cena[11];
holodnoe2=11;
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena[11])
{menu2_on=0;
PAUSE=false;}
}


//покупка MILKOR MGL
if(menu1_on==7&&weapon1_change!=0&&hge->Input_GetKeyState(HGEK_NUMPAD3)&&milkor_buy==false&&net_user!=2)
{
if(points1>=cena[12])
{pred_weapon1=N_WEAPON1;
oboim[N_WEAPON1]=oboima;//запись кол-ва пуль до покупки
N_WEAPON1=12;
milkor_buy=true;
last_weapon1=N_WEAPON1;
oboima=oboim[N_WEAPON1];
points1-=cena[12];
if(panzer_buy!=true)
{granatomet1=12;}
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena[12])
{menu1_on=0;
PAUSE=false;}
}

if(menu2_on==7&&weapon2_change!=0&&hge->Input_GetKeyState(HGEK_3)&&milkor_buy2==false&&net_user!=1)
{
if(points2>=cena[12])
{pred_weapon2=N_WEAPON2;
oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль до покупки
N_WEAPON2=12;
milkor_buy2=true;
last_weapon2=N_WEAPON2;
oboima2=oboim2[N_WEAPON2];
points2-=cena[12];
if(panzer_buy2!=true)
{granatomet2=12;}
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena[12])
{menu2_on=0;
PAUSE=false;}
}

//покупка Panzerfaust 3
if(menu1_on==7&&weapon1_change!=0&&hge->Input_GetKeyState(HGEK_NUMPAD5)&&panzer_buy==false&&net_user!=2)
{
if(points1>=cena[13])
{pred_weapon1=N_WEAPON1;
oboim[N_WEAPON1]=oboima;//запись кол-ва пуль до покупки
N_WEAPON1=13;
panzer_buy=true;
last_weapon1=N_WEAPON1;
oboima=oboim[N_WEAPON1];
points1-=cena[13];
granatomet1=13;
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena[13])
{menu1_on=0;
PAUSE=false;}
}

if(menu2_on==7&&weapon2_change!=0&&hge->Input_GetKeyState(HGEK_5)&&panzer_buy2==false&&net_user!=1)
{
if(points2>=cena[13])
{pred_weapon2=N_WEAPON2;
oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль до покупки
N_WEAPON2=13;
panzer_buy2=true;
last_weapon2=N_WEAPON2;
oboima2=oboim2[N_WEAPON2];
points2-=cena[13];
granatomet2=13;
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena[13])
{menu2_on=0;
PAUSE=false;}
}


//покупка Webley MK4
if(menu1_on==2&&weapon1_change!=0&&hge->Input_GetKeyState(HGEK_NUMPAD3)&&webley_buy==false&&net_user!=2)
{
if(points1>=cena[14])
{pred_weapon1=N_WEAPON1;
oboim[N_WEAPON1]=oboima;//запись кол-ва пуль до покупки
N_WEAPON1=14;
webley_buy=true;
last_weapon1=N_WEAPON1;
oboima=oboim[N_WEAPON1];
points1-=cena[14];
if(fn_five_seven_buy!=true)
{pistol1=14;}
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena[14])
{menu1_on=0;
PAUSE=false;}
}

if(menu2_on==2&&weapon2_change!=0&&hge->Input_GetKeyState(HGEK_3)&&webley_buy2==false&&net_user!=1)
{
if(points2>=cena[14])
{pred_weapon2=N_WEAPON2;
oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль до покупки
N_WEAPON2=14;
webley_buy2=true;
last_weapon2=N_WEAPON2;
oboima2=oboim2[N_WEAPON2];
points2-=cena[14];
if(fn_five_seven_buy2!=true)
{pistol2=14;}
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena[14])
{menu2_on=0;
PAUSE=false;}
}

//покупка FN Five-Seven
if(menu1_on==2&&weapon1_change!=0&&hge->Input_GetKeyState(HGEK_NUMPAD4)&&fn_five_seven_buy==false&&net_user!=2)
{
if(points1>=cena[15])
{pred_weapon1=N_WEAPON1;
oboim[N_WEAPON1]=oboima;//запись кол-ва пуль до покупки
N_WEAPON1=15;
fn_five_seven_buy=true;
last_weapon1=N_WEAPON1;
oboima=oboim[N_WEAPON1];
points1-=cena[15];
pistol1=15;
menu1_on=0;
weapon1_change=0;
weapon1_change_time=GetTime();
weapon1_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points1<cena[15])
{menu1_on=0;
PAUSE=false;}
}

if(menu2_on==2&&weapon2_change!=0&&hge->Input_GetKeyState(HGEK_4)&&fn_five_seven_buy2==false&&net_user!=1)
{
if(points2>=cena[15])
{pred_weapon2=N_WEAPON2;
oboim2[N_WEAPON2]=oboima2;//запись кол-ва пуль до покупки
N_WEAPON2=15;
fn_five_seven_buy2=true;
last_weapon2=N_WEAPON2;
oboima2=oboim2[N_WEAPON2];
points2-=cena[15];
pistol2=15;
menu2_on=0;
weapon2_change=0;
weapon2_change_time=GetTime();
weapon2_change_time_sec=GetCurrentSecond();
PAUSE=false;
}
if(points2<cena[15])
{menu2_on=0;
PAUSE=false;}
}

//если оружие уже есть
if(net_user!=2)
{
if(menu1_on==5&&hge->Input_GetKeyState(HGEK_NUMPAD1)&&ak_buy==true)
{menu1_on=0;
PAUSE=false;}
if(menu1_on==4&&hge->Input_GetKeyState(HGEK_NUMPAD1)&&mac_buy==true)
{menu1_on=0;
PAUSE=false;}
if(menu1_on==4&&hge->Input_GetKeyState(HGEK_NUMPAD2)&&pp19_buy==true)
{menu1_on=0;
PAUSE=false;}
if(menu1_on==5&&hge->Input_GetKeyState(HGEK_NUMPAD2)&&fn_f2000_buy==true)
{menu1_on=0;
PAUSE=false;}
if(menu1_on==2&&hge->Input_GetKeyState(HGEK_NUMPAD1)&&tt_buy==true&&weapon1_change!=0)
{menu1_on=0;
PAUSE=false;}
if(menu1_on==6&&hge->Input_GetKeyState(HGEK_NUMPAD2)&&rpk_buy==true)
{menu1_on=0;
PAUSE=false;}
if(menu1_on==3&&hge->Input_GetKeyState(HGEK_NUMPAD1)&&winchester_buy==true)
{menu1_on=0;
PAUSE=false;}
if(menu1_on==6&&hge->Input_GetKeyState(HGEK_NUMPAD1)&&rpk47_buy==true)
{menu1_on=0;
PAUSE=false;}
if(menu1_on==2&&hge->Input_GetKeyState(HGEK_NUMPAD2)&&glok_buy==true)
{menu1_on=0;
PAUSE=false;}
if(menu1_on==7&&hge->Input_GetKeyState(HGEK_NUMPAD1)&&rgd5_buy==true)
{menu1_on=0;
PAUSE=false;}
if(menu1_on==9&&hge->Input_GetKeyState(HGEK_NUMPAD2)&&katana_buy==true)
{menu1_on=0;
PAUSE=false;}
if(menu1_on==7&&hge->Input_GetKeyState(HGEK_NUMPAD3)&&milkor_buy==true)
{menu1_on=0;
PAUSE=false;}
if(menu1_on==7&&hge->Input_GetKeyState(HGEK_NUMPAD5)&&panzer_buy==true)
{menu1_on=0;
PAUSE=false;}
if(menu1_on==2&&hge->Input_GetKeyState(HGEK_NUMPAD3)&&webley_buy==true)
{menu1_on=0;
PAUSE=false;}
if(menu1_on==2&&hge->Input_GetKeyState(HGEK_NUMPAD4)&&fn_five_seven_buy==true)
{menu1_on=0;
PAUSE=false;}
}
if(net_user!=1)
{
if(menu2_on==5&&hge->Input_GetKeyState(HGEK_1)&&ak_buy2==true)
{menu2_on=0;
PAUSE=false;}
if(menu2_on==4&&hge->Input_GetKeyState(HGEK_1)&&mac_buy2==true)
{menu2_on=0;
PAUSE=false;}
if(menu2_on==4&&hge->Input_GetKeyState(HGEK_2)&&pp19_buy2==true)
{menu2_on=0;
PAUSE=false;}
if(menu2_on==5&&hge->Input_GetKeyState(HGEK_2)&&fn_f2000_buy2==true)
{menu2_on=0;
PAUSE=false;}
if(menu2_on==2&&hge->Input_GetKeyState(HGEK_1)&&tt_buy2==true&&weapon2_change==1)
{menu2_on=0;
PAUSE=false;}
if(menu2_on==6&&hge->Input_GetKeyState(HGEK_2)&&rpk_buy2==true)
{menu2_on=0;
PAUSE=false;}
if(menu2_on==3&&hge->Input_GetKeyState(HGEK_1)&&winchester_buy2==true)
{menu2_on=0;
PAUSE=false;}
if(menu2_on==6&&hge->Input_GetKeyState(HGEK_1)&&rpk47_buy2==true)
{menu2_on=0;
PAUSE=false;}
if(menu2_on==2&&hge->Input_GetKeyState(HGEK_2)&&glok_buy2==true)
{menu2_on=0;
PAUSE=false;}
if(menu2_on==7&&hge->Input_GetKeyState(HGEK_1)&&rgd5_buy2==true)
{menu2_on=0;
PAUSE=false;}
if(menu2_on==9&&hge->Input_GetKeyState(HGEK_2)&&katana_buy2==true)
{menu2_on=0;
PAUSE=false;}
if(menu2_on==7&&hge->Input_GetKeyState(HGEK_3)&&milkor_buy2==true)
{menu2_on=0;
PAUSE=false;}
if(menu2_on==7&&hge->Input_GetKeyState(HGEK_5)&&panzer_buy2==true)
{menu2_on=0;
PAUSE=false;}
if(menu2_on==2&&hge->Input_GetKeyState(HGEK_3)&&webley_buy2==true)
{menu2_on=0;
PAUSE=false;}
if(menu2_on==2&&hge->Input_GetKeyState(HGEK_4)&&fn_five_seven_buy2==true)
{menu2_on=0;
PAUSE=false;}
}


//----BUY

if(weapon1_change==0&&((weapon1_change_time<800&&GetTime()>=weapon1_change_time+200)||
   (weapon1_change_time>=800&&GetCurrentSecond()!=weapon1_change_time_sec&&GetTime()>=weapon1_change_time-800)))
{weapon1_change=1;}
if(weapon2_change==0&&((weapon2_change_time<800&&GetTime()>=weapon2_change_time+200)||
   (weapon2_change_time>=800&&GetCurrentSecond()!=weapon2_change_time_sec&&GetTime()>=weapon2_change_time-800)))
{weapon2_change=1;}






if(RPGMOD==true)
{	
//ВЫБОР НАВЫКОВ	

if(lvl1_vibor==true)//ВЫБОР ИГРОКА 1
{
PAUSE=true;
	
	player1_myasnik->Stop();
	player1_strelok->Stop();
	player1_razrushitel->Stop();
	player1_tehnik->Stop();
	player2_strelok->Stop();
	zayac->Stop();
	volk->Stop();
	medved->Stop();
	uhi_a->Stop();
	winchester_anime->Stop();
	winchester2_anime->Stop();
	blood_ssit_psi->Stop();
	RPG_healing_psi->Stop();


//блокировка выбора навыков нажатием ентера
if(vibor_block==true&&opit_points1>0)
{
if(vibor_time_milli<800&&((GetCurrentSecond()==vibor_time&&GetTime()>=vibor_time_milli+200)||
(GetCurrentSecond()!=vibor_time&&GetTime()<vibor_time_milli)))
{vibor_block=false;}
if(vibor_time_milli>=800&&GetCurrentSecond()!=vibor_time&&GetTime()>=vibor_time_milli-800)
{vibor_block=false;}
}

if(opit_points1==0)
{vibor_block=true;}
//закрытие блокировки


//ВЫБОР НАВЫКА
if (hge->Input_GetKeyState(HGEK_DOWN)&&viborchange_block==false&&net_user!=2)
{
VIBOR++;
viborchange_block=true;
viborchange_time=GetCurrentSecond();
viborchange_time_milli=GetTime();

if(VIBOR>3&&CLASSMOD==false)
{VIBOR=0;}

if(VIBOR>5&&CLASSMOD==true)
{VIBOR=0;}
}

if (hge->Input_GetKeyState(HGEK_UP)&&viborchange_block==false&&net_user!=2)
{
VIBOR--;
viborchange_block=true;
viborchange_time=GetCurrentSecond();
viborchange_time_milli=GetTime();
if(VIBOR<0&&CLASSMOD==false)
{VIBOR=3;}
if(VIBOR<0&&CLASSMOD==true)
{VIBOR=5;}
}


if (hge->Input_GetKeyState(HGEK_ENTER)&&vibor_block==false&&VIBOR!=0&&net_user!=2)
{
vibor_block=true;
vibor_time=GetCurrentSecond();
vibor_time_milli=GetTime();
opit_points1--;

switch(VIBOR)
{case 1:
attack1++;
break;

case 2:
skorost1++;
speed++;
break;

case 3:
luck1++;
break;

case 4:
switch(class1)
{
case 1:
mosch1++;
break;

case 2:
tochnost1-=0.01f;
break;

case 3:
vinoslivost1++;
break;

case 4:
modifikacii1++;
break;
}
break;

case 5:
switch(class1)
{
case 1:
primanka1++;
break;

case 2:
postroenie1++;
break;

case 3:
vzrivchatka1++;
break;

case 4:
technika1++;
break;
}
break;


}

}


//ЗАКРЫТИЕ


//выход
if(hge->Input_GetKeyState(HGEK_L)&&lvl_key_block==false&&net_user!=2)
{
pause_start_time_sec=GetCurrentSecond();
pause_start_time=GetTime();
lvl_key_block=true;
lvl_key_time=GetCurrentSecond();
lvl_key_time_milli=GetTime();		
lvl1_vibor=false;
PAUSE=false;
	player1_myasnik->Play();
	player1_strelok->Play();
	player1_razrushitel->Play();
	player1_tehnik->Play();
	player2_strelok->Play();
	zayac->Play();
	volk->Play();
	medved->Play();
	uhi_a->Play();
	winchester_anime->Play();
	winchester2_anime->Play();
	blood_ssit_psi->Fire();
	RPG_healing_psi->Fire();
}
//закрытие выхода

}//закрытие выбора 1-го игрока

















if(lvl2_vibor==true)//ВЫБОР ИГРОКА 2
{
PAUSE=true;
	player1_myasnik->Stop();
	player1_strelok->Stop();
	player1_razrushitel->Stop();
	player1_tehnik->Stop();
	player2_strelok->Stop();
	zayac->Stop();
	volk->Stop();
	medved->Stop();
	uhi_a->Stop();
	winchester_anime->Stop();
	winchester2_anime->Stop();
	blood_ssit_psi->Stop();
	RPG_healing_psi->Stop();


//блокировка выбора навыков нажатием пробела
if(vibor_block==true&&opit_points2>0)
{
if(vibor_time_milli<800&&((GetCurrentSecond()==vibor_time&&GetTime()>=vibor_time_milli+200)||
(GetCurrentSecond()!=vibor_time&&GetTime()<vibor_time_milli)))
{vibor_block=false;}
if(vibor_time_milli>=800&&GetCurrentSecond()!=vibor_time&&GetTime()>=vibor_time_milli-800)
{vibor_block=false;}
}

if(opit_points2==0)
{vibor_block=true;}
//закрытие блокировки



//ВЫБОР НАВЫКА
if (hge->Input_GetKeyState(HGEK_S)&&viborchange_block==false&&net_user!=1)
{
VIBOR++;
viborchange_block=true;
viborchange_time=GetCurrentSecond();
viborchange_time_milli=GetTime();

if(VIBOR>3&&CLASSMOD==false)
{VIBOR=0;}
if(VIBOR>5&&CLASSMOD==true)
{VIBOR=0;}
}

if (hge->Input_GetKeyState(HGEK_W)&&viborchange_block==false&&net_user!=1)
{
VIBOR--;
viborchange_block=true;
viborchange_time=GetCurrentSecond();
viborchange_time_milli=GetTime();
if(VIBOR<0&&CLASSMOD==false)
{VIBOR=3;}
if(VIBOR<0&&CLASSMOD==true)
{VIBOR=5;}
}

if (hge->Input_GetKeyState(HGEK_SPACE)&&vibor_block==false&&VIBOR!=0&&net_user!=1)
{
vibor_block=true;
vibor_time=GetCurrentSecond();
vibor_time_milli=GetTime();
opit_points2--;

switch(VIBOR)
{case 1:
attack2++;
break;

case 2:
skorost2++;
speed2++;
break;

case 3:
luck2++;
break;

case 4:
switch(class2)
{
case 1:
mosch2++;
break;

case 2:
tochnost2-=0.01f;
break;

case 3:
vinoslivost2++;
break;

case 4:
modifikacii2++;
break;
}
break;

case 5:
switch(class2)
{
case 1:
primanka2++;
break;

case 2:
postroenie2++;
break;

case 3:
vzrivchatka2++;
break;

case 4:
technika2++;
break;
}
break;





}

}


//ЗАКРЫТИЕ



//выход
if(hge->Input_GetKeyState(HGEK_F)&&lvl_key_block==false&&net_user!=1)
{
pause_start_time_sec=GetCurrentSecond();
pause_start_time=GetTime();
lvl_key_block=true;
lvl_key_time=GetCurrentSecond();
lvl_key_time_milli=GetTime();	
lvl2_vibor=false;
PAUSE=false;
	player1_myasnik->Play();
	player1_strelok->Play();
	player1_razrushitel->Play();
	player1_tehnik->Play();
	player2_strelok->Play();
	zayac->Play();
	volk->Play();
	medved->Play();
	uhi_a->Play();
	winchester_anime->Play();
	winchester2_anime->Play();
	blood_ssit_psi->Fire();
	RPG_healing_psi->Fire();
}//закрытие выхода



}//закрытие выбора 2-го игрока

//блокировка окна выбора
if(lvl_key_block==true)
{
if(GetCurrentSecond()!=lvl_key_time&&GetTime()>=lvl_key_time_milli)
{
lvl_key_block=false;
}
}//закрытие блокировки

//блокировка смены выбора (ВВЕРХ-ВНИЗ)
if(viborchange_block==true)
{
if(viborchange_time_milli<900&&((GetCurrentSecond()==viborchange_time&&GetTime()>=viborchange_time_milli+100)||
(GetCurrentSecond()!=viborchange_time&&GetTime()<viborchange_time_milli)))
{viborchange_block=false;}
if(viborchange_time_milli>=900&&GetCurrentSecond()!=viborchange_time&&GetTime()>=viborchange_time_milli-900)
{viborchange_block=false;}
}//закрытие блокировки


}//if RPG_MOD==TRUE






if(TEST_REZHIM==false)//тестовый режим
{

//ПОРАЖЕНИЕ/ПОБЕДА
if((pobeda==true||porazhenie==true)&&PAUSE==false&&menu_aktive==0)
{
PAUSE=true;
player1_myasnik->Stop();
player1_strelok->Stop();
player1_razrushitel->Stop();
player1_tehnik->Stop();
player2_strelok->Stop();
zayac->Stop();
volk->Stop();
medved->Stop();
uhi_a->Stop();
winchester_anime->Stop();
winchester2_anime->Stop();
blood_ssit_psi->Stop();
RPG_healing_psi->Stop();
pobeda_time=GetCurrentSecond();
}
//небольшая пауза
if((pobeda==true||porazhenie==true)&&PAUSE==true)
{
if((pobeda_time<57&&GetCurrentSecond()==pobeda_time+3)||(pobeda_time>=57&&GetCurrentSecond()==pobeda_time-57))
{PAUSE=false;
player1_myasnik->Play();
player1_strelok->Play();
player1_razrushitel->Play();
player1_tehnik->Play();
player2_strelok->Play();
zayac->Play();
volk->Play();
medved->Play();
uhi_a->Play();
winchester_anime->Play();
winchester2_anime->Play();
blood_ssit_psi->Fire();
RPG_healing_psi->Fire();
//ПОКАЗ СТАТИСТИКИ



for(int i91=0;i91<=N_KILLS;i91++)
{
//1 игрок
if(ubijstva[i91].player==1)
{
if(ubijstva[i91].vrag==1)
{kills_zayac++;
if(ubijstva[i91].bezuh==true)
{kills_zayac_bezuh++;}
if(ubijstva[i91].bezboshki==true)
{kills_zayac_bezboshki++;}
if(ubijstva[i91].vschiii==true)
{kills_zayac_vschiii++;}}
if(ubijstva[i91].vrag==2)
{kills_volk++;}
if(ubijstva[i91].vrag==3)
{kills_medved++;}
}//1 игрок

//2 игрок
if(ubijstva[i91].player==2)
{
if(ubijstva[i91].vrag==1)
{kills2_zayac++;
if(ubijstva[i91].bezuh==true)
{kills2_zayac_bezuh++;}
if(ubijstva[i91].bezboshki==true)
{kills2_zayac_bezboshki++;}
if(ubijstva[i91].vschiii==true)
{kills2_zayac_vschiii++;}}
if(ubijstva[i91].vrag==2)
{kills2_volk++;}
if(ubijstva[i91].vrag==3)
{kills2_medved++;}
}//2 игрок

}//закрытие просчёта убийств


procent_kills_zayac_bezuh=(float)kills_zayac_bezuh/(float)kills_zayac*100;
procent_kills_zayac_bezboshki=(float)kills_zayac_bezboshki*100/(float)kills_zayac;
procent_kills_zayac_vschiii=(float)kills_zayac_vschiii*100/(float)kills_zayac;
procent_kills2_zayac_bezuh=(float)kills2_zayac_bezuh*100/(float)kills2_zayac;
procent_kills2_zayac_bezboshki=(float)kills2_zayac_bezboshki*100/(float)kills2_zayac;
procent_kills2_zayac_vschiii=(float)kills2_zayac_vschiii*100/(float)kills2_zayac;


menu_aktive=-5;
}
}

//ПОРАЖЕНИЕ/ПОБЕДА
}//если не в тестовом режиме




	if (hge->Input_GetKeyState(HGEK_ESCAPE)) //ВЫХОД В МЕНЮЮЮЮЮЮЮЮЮЮЮ
		
{	menu->DelCtrl(1);
	menu->DelCtrl(2);
	menu->DelCtrl(3);
	menu->DelCtrl(4);
	menu->DelCtrl(5);
	menu->DelCtrl(6);
	menu->AddCtrl(new hgeGUIMenuItem(1,menu_font,menu_sound,menu_choose,600,200,0.0f,"Продолжить"));
	menu->AddCtrl(new hgeGUIMenuItem(2,menu_font,menu_sound,menu_choose,600,240,0.0f,"НоваЯ Игра"));
	menu->AddCtrl(new hgeGUIMenuItem(3,menu_font,menu_sound,menu_choose,600,280,0.0f,"Опции"));
	menu->AddCtrl(new hgeGUIMenuItem(4,menu_font,menu_sound,menu_choose,600,320,0.0f,"Инфо"));
	menu->AddCtrl(new hgeGUIMenuItem(5,menu_font,menu_sound,menu_choose,600,360,0.0f,"Авторы"));
	menu->AddCtrl(new hgeGUIMenuItem(6,menu_font,menu_sound,menu_choose,600,400,0.0f,"Выход"));
	menu_aktive=1;
	PAUSE=true;
	menu->SetFocus(1);
	menu->Enter();
	pause_start_time_sec=GetCurrentSecond();
	pause_start_time=GetTime();

}

	
}//меню не активно	

//ТЕСТОВЫЙ РЕЖИМ
if (hge->Input_GetKeyState(HGEK_T)&&TEST_REZHIM==false&&net_user!=2)
{TEST_REZHIM=true;
points1+=1000;
points2+=1000;}
if (hge->Input_GetKeyState(HGEK_CTRL)&&hge->Input_GetKeyState(HGEK_T)&&TEST_REZHIM==true)
{TEST_REZHIM=false;}
//ТЕСТОВЫЙ РЕЖИМ

if((PAUSE==true||menu_aktive!=0)&&game_start==1)
{

if(GetCurrentSecond()!=pause_start_time_sec&&pause_time_minus==false)
{pause_time_minus=true;
pause_start_time_sec=GetCurrentSecond();}

if(pause_time_minus==true)
{pause_time_sec++;
pause_time_minus=false;}


}


	
	// Continue execution
	return false;
}












//----------------------------------------------------------------------------

// This function will be called by HGE when
// the application window should be redrawn.
// Put your rendering code here.
bool RenderFunc()
{
	
	float delta=hge->Timer_GetDelta();
	player1_strelok->Update(delta);
	player1_gogranata_ruka1->Update(delta);
	player1_gogranata_ruka2->Update(delta);
	player1_myasnik->Update(delta);
	player1_razrushitel->Update(delta);
	player1_myasnik_ruka1_udar_sleva->Update(delta);
	player1_ruka1_pistol->Update(delta);
	player1_ruka1_vintovka->Update(delta);
	player1_ruka1_winch->Update(delta);
	player2_strelok->Update(delta);
	player2_gogranata_ruka1->Update(delta);
	player2_gogranata_ruka2->Update(delta);
	player2_myasnik_ruka1_udar_sleva->Update(delta);
	player2_ruka1_pistol->Update(delta);
	player2_ruka1_vintovka->Update(delta);
	zayac->Update(delta);
	volk->Update(delta);
	medved->Update(delta);
	ptenec->Update(delta);
	ptenec_wait->Update(delta);
	uhi_a->Update(delta);
	winchester_anime->Update(delta);
	winchester2_anime->Update(delta);
	katana1_anime->Update(delta);
	katana2_anime->Update(delta);
	blood_ssit_psi->Update(delta);
	RPG_healing_psi->Update(delta);
	vzriv_grena_psi->Update(delta);
	vzriv_ogon_grena_psi->Update(delta);



	
	//hge->Gfx_BeginScene(blood_target);
	//hge->Gfx_Clear(0);
	//hge->Gfx_EndScene();

	

	hge->Gfx_BeginScene();


	hge->Gfx_Clear(0);




	
if(menu_aktive==0)
{	
	
			for(int i43=0;i43<=31;i43++) 
	{
	switch (FON[i43].type)
	{case 1:
	fon1->Render(X-FON[i43].x+Xz,FON[i43].y);
	break;
	case 2:
	fon2->Render(X-FON[i43].x+Xz,FON[i43].y);
	break;
	case 3:
	fon3->Render(X-FON[i43].x+Xz,FON[i43].y);
	break;

	}
	}
	polosa_finish->Render(X-lvl1_lenght,0);
	polosa_finish->Render(X-lvl1_lenght,477);
	oblaka1->Render(-800+X/12+Xz,0);
	alkash1->Render(X-300+Xz,600);


	if(peregruzheno==0)//ЩИ
	{for(int i=0;i<=N_TRUPS;i++)      
	{    
		Render_trups(i);
	}}//закрытие щей
	
if(peregruzheno==1)//ЩИ
{
if(N_TRUPS<NUMBER_TRUPS)
{
	for(int i95=N_TRUPS+1;i95<=NUMBER_TRUPS;i95++)      
	{Render_trups(i95);}
	for(int i95=0;i95<=N_TRUPS;i95++)      
	{ Render_trups(i95);}
}//если N_TRUPS<NUMBER_TRUPS
if(N_TRUPS>=NUMBER_TRUPS)
	{
	for(int i95=0;i95<=NUMBER_TRUPS;i95++) 
	{Render_trups(i95);}
}
}//закрытие щей if(peregruzheno==1)


	


for(int i11=0;i11<=N_BLOOD;i11++)//КРОВЯК
	{
	if(krovyakObjects[i11].akt!=0)
	{

    if(krovyakObjects[i11].seed!=0)
	{
	switch(krovyakObjects[i11].seed)
    {case 1:
	case 101:krovyak1->RenderStretch(krovyakObjects[i11].x1+Xz,krovyakObjects[i11].y1,
	krovyakObjects[i11].x2+Xz,krovyakObjects[i11].y2);
	break;
	case 2:
	case 102:krovyak2->RenderStretch(krovyakObjects[i11].x1+Xz,krovyakObjects[i11].y1,
	krovyakObjects[i11].x2+Xz,krovyakObjects[i11].y2);
	break;
	case 3:
	case 103:krovyak3->RenderStretch(krovyakObjects[i11].x1+Xz,krovyakObjects[i11].y1,
	krovyakObjects[i11].x2+Xz,krovyakObjects[i11].y2);
	break;
	case 1001:
	switch (krovyakObjects[i11].faza)
	{case 1:
	krovyak_vzriv1->SetTexture(blood_vzriv1_a_tex);
	break;
	case 2:
	krovyak_vzriv1->SetTexture(blood_vzriv1_b_tex);
	break;
	case 3:
	krovyak_vzriv1->SetTexture(blood_vzriv1_c_tex);
	break;
	case 4:
	krovyak_vzriv1->SetTexture(blood_vzriv1_d_tex);
	break;
	case 5:
	krovyak_vzriv1->SetTexture(blood_vzriv1_e_tex);
	break;}
	krovyak_vzriv1->Render(krovyakObjects[i11].x1+Xz,krovyakObjects[i11].y1);
	break;
	case 1002:
	switch (krovyakObjects[i11].faza)
	{case 1:
	ptenec_boshka_vzriv1->SetTexture(ptenec_boshka_vzriv1_a_tex);
	break;
	case 2:
	ptenec_boshka_vzriv1->SetTexture(ptenec_boshka_vzriv1_b_tex);
	break;
	case 3:
	ptenec_boshka_vzriv1->SetTexture(ptenec_boshka_vzriv1_c_tex);
	break;
	case 4:
	ptenec_boshka_vzriv1->SetTexture(ptenec_boshka_vzriv1_d_tex);
	break;
	case 5:
	ptenec_boshka_vzriv1->SetTexture(ptenec_boshka_vzriv1_e_tex);
	break;}
	ptenec_boshka_vzriv1->RenderEx(krovyakObjects[i11].x1+Xz,krovyakObjects[i11].y1,0,krovyakObjects[i11].xstart,0);
	break;
	}
	}

	if(krovyakObjects[i11].seed==0)
	{krovyak_shot1->RenderStretch(krovyakObjects[i11].x1+Xz,krovyakObjects[i11].y1,
	krovyakObjects[i11].x2+Xz,krovyakObjects[i11].y2);}

	}
}







//БОЛЬШОЙ СЛОЁНЫЙ ПИРОГ!!!!!!!!!!!!
for(int I=0;I<=N_Y;I++)
{
switch(A[I].type)
{
//ЗАЙЦЫ
case 1:
zayac->SetTexture(zayac_go_tex);
if(vragi1Objects[A[I].id].bezuh==1)//если заяц покоцан
{zayac->SetTexture(zayac_go_bezuh_tex);}//то он без ушей
if(vragi1Objects[A[I].id].ubit!=1)
{zayac->Render(vragi1Objects[A[I].id].v1x+Xz,vragi1Objects[A[I].id].v1y);}//вывод живых зайцев на экран
break;
//ВОЛКИ
case 2:
if(vragi2Objects[A[I].id].ubit!=1)
{volk->SetColor(0xFFAAAAAA);
volk->Render(vragi2Objects[A[I].id].v2x+Xz,vragi2Objects[A[I].id].v2y);

if(vragi2Objects[A[I].id].RPG_healer!=0&&RPGMOD==true)//хилер
{RPG_healer->RenderEx(vragi2Objects[A[I].id].v2x+50+Xz,vragi2Objects[A[I].id].v2y+8,0,0.35f,0);}

if(vragi2Objects[A[I].id].RPG_illusionist!=0&&RPGMOD==true)//иллюзионист
{RPG_illusionist->SetColor(0xFFAAAAAA);
RPG_illusionist->RenderEx(vragi2Objects[A[I].id].v2x+50+Xz,vragi2Objects[A[I].id].v2y+8,0,0.35f,0);
//иллюзии
if(vragi2Objects[A[I].id].ill1_active!=0)
{volk->SetColor(0xFFAAAAAA);
volk->Render(vragi2Objects[A[I].id].ill1_x+Xz,vragi2Objects[A[I].id].ill1_y);
RPG_illusionist->SetColor(0xFFAAAAAA);
RPG_illusionist->RenderEx(vragi2Objects[A[I].id].ill1_x+50+Xz,vragi2Objects[A[I].id].ill1_y+8,0,0.35f,0);}
if(vragi2Objects[A[I].id].ill2_active!=0)
{volk->SetColor(0xFFAAAAAA);
volk->Render(vragi2Objects[A[I].id].ill2_x+Xz,vragi2Objects[A[I].id].ill2_y);
RPG_illusionist->SetColor(0xFFAAAAAA);
RPG_illusionist->RenderEx(vragi2Objects[A[I].id].ill2_x+50+Xz,vragi2Objects[A[I].id].ill2_y+8,0,0.35f,0);}
if(vragi2Objects[A[I].id].ill1_active==0)
{volk->SetColor(0xFFAAAAAA);
volk->Render(vragi2Objects[A[I].id].ill1_x+Xz,vragi2Objects[A[I].id].ill1_y);
RPG_illusionist->SetColor(0xFFAAAAAA);
RPG_illusionist->RenderEx(vragi2Objects[A[I].id].ill1_x+50+Xz,vragi2Objects[A[I].id].ill1_y+8,0,0.35f,0);}
if(vragi2Objects[A[I].id].ill2_active==0)
{volk->SetColor(0xFFAAAAAA);
volk->Render(vragi2Objects[A[I].id].ill2_x+Xz,vragi2Objects[A[I].id].ill2_y);
RPG_illusionist->SetColor(0xFFAAAAAA);
RPG_illusionist->RenderEx(vragi2Objects[A[I].id].ill2_x+50+Xz,vragi2Objects[A[I].id].ill2_y+8,0,0.35f,0);}
//иллюзии
}

if(vragi2Objects[A[I].id].RPG_teleporter!=0&&RPGMOD==true)//телепортер
{RPG_teleporter->RenderEx(vragi2Objects[A[I].id].v2x+50+Xz,vragi2Objects[A[I].id].v2y+8,0,0.35f,0);}

if(vragi2Objects[A[I].id].RPG_healer!=0&&vragi2Objects[A[I].id].health<125&&
RPGMOD==true)
{RPG_healing_psi->Render();}
}//вывод живых волков на экран
break;
//МЯСО!!!!!!!!!
case 3:
if(myasko[A[I].id].akt==1)
{
switch(myasko[A[I].id].seed)
{case 1:krovyak_myaso1->RenderEx(myasko[A[I].id].x1+Xz,myasko[A[I].id].y1,myasko[A[I].id].gradus,myasko[A[I].id].scaleX,0);
break;
case 2:krovyak_myaso2->RenderEx(myasko[A[I].id].x1+Xz,myasko[A[I].id].y1,myasko[A[I].id].gradus,myasko[A[I].id].scaleX,0);
break;
case 3:krovyak_myaso3->RenderEx(myasko[A[I].id].x1+Xz,myasko[A[I].id].y1,myasko[A[I].id].gradus,myasko[A[I].id].scaleX,0);
break;
case 4:krovyak_myaso4->RenderEx(myasko[A[I].id].x1+Xz,myasko[A[I].id].y1,myasko[A[I].id].gradus,myasko[A[I].id].scaleX,0);
break;
case 5:krovyak_myaso5->RenderEx(myasko[A[I].id].x1+Xz,myasko[A[I].id].y1,myasko[A[I].id].gradus,myasko[A[I].id].scaleX,0);
break;
case 6:zayac_boshka_bezuh->RenderEx(myasko[A[I].id].x1+Xz,myasko[A[I].id].y1,myasko[A[I].id].gradus,1,0);
break;
case 7:krovyak_zayac_rebra1->RenderEx(myasko[A[I].id].x1+Xz,myasko[A[I].id].y1,myasko[A[I].id].gradus,1,0);
break;
case 8:krovyak_zayac_rebra2->RenderEx(myasko[A[I].id].x1+Xz,myasko[A[I].id].y1,myasko[A[I].id].gradus,1,0);
break;
case 9:krovyak_zayac_noga1->RenderEx(myasko[A[I].id].x1+Xz,myasko[A[I].id].y1,myasko[A[I].id].gradus,1,0);
break;
case 10:krovyak_zayac_noga2->RenderEx(myasko[A[I].id].x1+Xz,myasko[A[I].id].y1,myasko[A[I].id].gradus,1,0);
break;
case 11:krovyak_zayac_noga3->RenderEx(myasko[A[I].id].x1+Xz,myasko[A[I].id].y1,myasko[A[I].id].gradus,1,0);
break;
case 12:krovyak_zayac_noga4->RenderEx(myasko[A[I].id].x1+Xz,myasko[A[I].id].y1,myasko[A[I].id].gradus,1,0);
break;
}
}
break;
//УШИ
case 4:
if(uhiObjects[A[I].id].akt==1)
{uhi->RenderEx(uhiObjects[A[I].id].uhix+Xz,uhiObjects[A[I].id].uhiy,uhiObjects[A[I].id].gradus,1,0);}
break;

//БОШКИ
case 5:
if(boshkiObjects[A[I].id].akt==1)
{
blood_ssit_psi->Render();
if(boshkiObjects[A[I].id].vrag==1)
{
if(boshkiObjects[A[I].id].bezuh==0)
{zayac_boshka->RenderEx(boshkiObjects[A[I].id].bx+Xz,boshkiObjects[A[I].id].by,boshkiObjects[A[I].id].gradus,1,0);}
if(boshkiObjects[A[I].id].bezuh==1)
{zayac_boshka_bezuh->RenderEx(boshkiObjects[A[I].id].bx+Xz,boshkiObjects[A[I].id].by,boshkiObjects[A[I].id].gradus,1,0);}
}
if(boshkiObjects[A[I].id].vrag==3)
{medved_boshka->RenderEx(boshkiObjects[A[I].id].bx+Xz,boshkiObjects[A[I].id].by,boshkiObjects[A[I].id].gradus,1,0);}
}
break;

//БОНУСЫ
case 6:
if(bonusiObjects[A[I].id].akt==1&&bonusiObjects[A[I].id].visible==true)
{
switch(bonusiObjects[A[I].id].type)	
{
case 0:
bonus_this->RenderStretch(bonusiObjects[A[I].id].x1+Xz,bonusiObjects[A[I].id].y1,bonusiObjects[A[I].id].x2+Xz,bonusiObjects[A[I].id].y2);
break;
case 1:
bonus_shilo->RenderStretch(bonusiObjects[A[I].id].x1+Xz,bonusiObjects[A[I].id].y1,bonusiObjects[A[I].id].x2+Xz,bonusiObjects[A[I].id].y2);
break;}
}
break;

//ОБЪЕКТЫ
case 7:
switch(Objects[A[I].id].type)
{case 0:
znak_polputi->Render(X-Objects[A[I].id].x+Xz,Objects[A[I].id].y);
break;
case 1:	
penek1->Render(X-Objects[A[I].id].x+Xz,Objects[A[I].id].y);
break;
case 2:	
derevo1->Render(X-Objects[A[I].id].x+Xz,Objects[A[I].id].y);
break;}
break;

//ГИЛЬЗЫ
case 8:
if(gilziObjects[A[I].id].akt==1)
{
switch(gilziObjects[A[I].id].type)
{case 1:
gilza_pist->Render(gilziObjects[A[I].id].x+Xz,gilziObjects[A[I].id].y);
break;
case 2:
gilza_avt->Render(gilziObjects[A[I].id].x+Xz,gilziObjects[A[I].id].y);
break;
}
}
break;


//КРОВЯК
/*case 9:
	if(krovyakObjects[A[I].id].akt!=0)
	{

    if(krovyakObjects[A[I].id].seed!=0)
	{
	switch(krovyakObjects[A[I].id].seed)
    {case 1:
	case 101:krovyak1->RenderStretch(krovyakObjects[A[I].id].x1,krovyakObjects[A[I].id].y1,
	krovyakObjects[A[I].id].x2,krovyakObjects[A[I].id].y2);
	break;
	case 2:
	case 102:krovyak2->RenderStretch(krovyakObjects[A[I].id].x1,krovyakObjects[A[I].id].y1,
	krovyakObjects[A[I].id].x2,krovyakObjects[A[I].id].y2);
	break;
	case 3:
	case 103:krovyak3->RenderStretch(krovyakObjects[A[I].id].x1,krovyakObjects[A[I].id].y1,
	krovyakObjects[A[I].id].x2,krovyakObjects[A[I].id].y2);
	break;
	}
	}

	if(krovyakObjects[A[I].id].seed==0)
	{krovyak_shot1->RenderStretch(krovyakObjects[A[I].id].x1,krovyakObjects[A[I].id].y1,
	krovyakObjects[A[I].id].x2,krovyakObjects[A[I].id].y2);}

	}	
break;
*/

//ГРЕНКИ
case 9:
if(granati[A[I].id].akt==1)
{
switch(granati[A[I].id].type)
{case 1:
rgd5->RenderEx(granati[A[I].id].x+Xz,granati[A[I].id].y,granati[A[I].id].gradus,0.7f,0);
break;
case 2:
granata_podstvol->RenderEx(granati[A[I].id].x+Xz,granati[A[I].id].y,granati[A[I].id].gradus,0.18f,0);
break;
case 3:
granata_panzer->RenderEx(granati[A[I].id].x+Xz,granati[A[I].id].y,granati[A[I].id].gradus,0.66f,0);
break;
}
}

break;

//МЕДВЕДИ
case 10:
if(vragi3Objects[A[I].id].ubit!=1)
{medved->SetColor(0xFFFFFFFF);
medved->RenderEx(vragi3Objects[A[I].id].v3x+Xz,vragi3Objects[A[I].id].v3y,0,1,0);

if(vragi3Objects[A[I].id].RPG_healer!=0&&RPGMOD==true)//хилер
{RPG_healer->RenderEx(vragi3Objects[A[I].id].v3x+70+Xz,vragi3Objects[A[I].id].v3y+130,0,0.5f,0);}
if(vragi3Objects[A[I].id].RPG_healer!=0&&vragi3Objects[A[I].id].health<400&&
RPGMOD==true)
{RPG_healing_psi->Render();}

if(vragi3Objects[A[I].id].RPG_illusionist!=0&&RPGMOD==true)//иллюзионист
{RPG_illusionist->SetColor(0xFFFFFFFF);
RPG_illusionist->RenderEx(vragi3Objects[A[I].id].v3x+70+Xz,vragi3Objects[A[I].id].v3y+130,0,0.5f,0);
//иллюзии
if(vragi3Objects[A[I].id].ill1_active!=0)
{medved->SetColor(0xFFFFFFFF);
medved->Render(vragi3Objects[A[I].id].ill1_x+Xz,vragi3Objects[A[I].id].ill1_y);
RPG_illusionist->SetColor(0xFFFFFFFF);
RPG_illusionist->RenderEx(vragi3Objects[A[I].id].ill1_x+70+Xz,vragi3Objects[A[I].id].ill1_y+130,0,0.5f,0);}
if(vragi3Objects[A[I].id].ill2_active!=0)
{medved->SetColor(0xFFFFFFFF);
medved->Render(vragi3Objects[A[I].id].ill2_x+Xz,vragi3Objects[A[I].id].ill2_y);
RPG_illusionist->SetColor(0xFFFFFFFF);
RPG_illusionist->RenderEx(vragi3Objects[A[I].id].ill2_x+70+Xz,vragi3Objects[A[I].id].ill2_y+130,0,0.5f,0);}
if(vragi3Objects[A[I].id].ill1_active==0)
{medved->SetColor(0xFFFFFFFF);
medved->Render(vragi3Objects[A[I].id].ill1_x+Xz,vragi3Objects[A[I].id].ill1_y);
RPG_illusionist->SetColor(0xFFFFFFFF);
RPG_illusionist->RenderEx(vragi3Objects[A[I].id].ill1_x+70+Xz,vragi3Objects[A[I].id].ill1_y+130,0,0.5f,0);}
if(vragi3Objects[A[I].id].ill2_active==0)
{medved->SetColor(0xFFFFFFFF);
medved->Render(vragi3Objects[A[I].id].ill2_x+Xz,vragi3Objects[A[I].id].ill2_y);
RPG_illusionist->SetColor(0xFFFFFFFF);
RPG_illusionist->RenderEx(vragi3Objects[A[I].id].ill2_x+70+Xz,vragi3Objects[A[I].id].ill2_y+130,0,0.5f,0);}
//иллюзии
}

if(vragi3Objects[A[I].id].RPG_teleporter!=0&&RPGMOD==true)//телепортер
{RPG_teleporter->RenderEx(vragi3Objects[A[I].id].v3x+70+Xz,vragi3Objects[A[I].id].v3y+130,0,0.5f,0);}

}//вывод живых медведей на экран
break;

case 11://ПТЕНЦЫ!!!
if(vragi4Objects[A[I].id].ubit!=1)
{
if(vragi4Objects[A[I].id].wait!=1)
{ptenec->RenderEx(vragi4Objects[A[I].id].v4x+Xz,vragi4Objects[A[I].id].v4y,0,0.7f,0);}
if(vragi4Objects[A[I].id].wait==1)
{ptenec_wait->RenderEx(vragi4Objects[A[I].id].v4x+Xz,vragi4Objects[A[I].id].v4y,0,0.7f,0);}
}

if(vragi4Objects[A[I].id].polet==1)
{if(vragi4Objects[A[I].id].chetvert_n==1)
{ptenec_trup1->SetTexture(ptenec_vpolete_tex);}
if(vragi4Objects[A[I].id].chetvert_n==-1)
{ptenec_trup1->SetTexture(ptenec_vpolete_reverse_tex);}
ptenec_trup1->RenderEx(vragi4Objects[A[I].id].v4x+Xz,vragi4Objects[A[I].id].v4y,vragi4Objects[A[I].id].gradus,0.7f,0);}

break;


//ПЕРВЫЙ ИГРОК И ВСЯ ЕГО УТВАРЬ
case 101:
if(aktivatorp!=0)
{p->Render(px+Xz,py);//пуля1
p1d1->Render(p1d1x+Xz,p1d1y);
p1d2->Render(p1d2x+Xz,p1d2y);
p1d3->Render(p1d3x+Xz,p1d3y);
p1d4->Render(p1d4x+Xz,p1d4y);}


switch(N_WEAPON1)
{case 0 :
if(ak_up==false)
{
if(ak_tex==0)
{ak47->SetTexture(ak);}
if(ak_tex==1)
{ak47->SetTexture(ak2);}
}


if(ak_up==true)
{
if(ak_tex==0)
{ak47->SetTexture(ak_upgraded);}
if(ak_tex==1)
{ak47->SetTexture(ak2_upgraded);}
}
ak47->RenderStretch(weapon_x1[N_WEAPON1]+Xz,weapon_y1[N_WEAPON1],weapon_x2[N_WEAPON1]+Xz,weapon_y2[N_WEAPON1]);
break;
case 1 :pm->RenderStretch(weapon_x1[N_WEAPON1]+Xz,weapon_y1[N_WEAPON1],weapon_x2[N_WEAPON1]+Xz,weapon_y2[N_WEAPON1]);
//ruka_pistol->RenderStretch(ruk1x1+Xz,ruk1y1,ruk1x2+Xz,ruk1y2);
break;
case 2:pp19_vityaz->RenderStretch(weapon_x1[N_WEAPON1]+Xz,weapon_y1[N_WEAPON1],weapon_x2[N_WEAPON1]+Xz,weapon_y2[N_WEAPON1]);
break;
case 3:
if(fn_f2000_up==false)
{fn_f2000->SetTexture(w_fn_f2000_tex);}
if(fn_f2000_up==true)
{fn_f2000->SetTexture(w_fn_f2000_upgraded_tex);}
fn_f2000->RenderStretch(weapon_x1[N_WEAPON1]+Xz,weapon_y1[N_WEAPON1],weapon_x2[N_WEAPON1]+Xz,weapon_y2[N_WEAPON1]);
break;
case 4:tt->RenderStretch(weapon_x1[N_WEAPON1]+Xz,weapon_y1[N_WEAPON1],weapon_x2[N_WEAPON1]+Xz,weapon_y2[N_WEAPON1]);
//ruka_pistol->RenderStretch(ruk1x1+Xz,ruk1y1,ruk1x2+Xz,ruk1y2);
break;
case 5:rpk->RenderStretch(weapon_x1[N_WEAPON1]+Xz,weapon_y1[N_WEAPON1],weapon_x2[N_WEAPON1]+Xz,weapon_y2[N_WEAPON1]);
break;
case 6:mac->RenderStretch(weapon_x1[N_WEAPON1]+Xz,weapon_y1[N_WEAPON1],weapon_x2[N_WEAPON1]+Xz,weapon_y2[N_WEAPON1]);
break;
case 7:winchester_anime->RenderStretch(weapon_x1[N_WEAPON1]+Xz,weapon_y1[N_WEAPON1],weapon_x2[N_WEAPON1]+Xz,weapon_y2[N_WEAPON1]);
break;
case 8:rpk47->RenderStretch(weapon_x1[N_WEAPON1]+Xz,weapon_y1[N_WEAPON1],weapon_x2[N_WEAPON1]+Xz,weapon_y2[N_WEAPON1]);
break;
case 9:glok->RenderStretch(weapon_x1[N_WEAPON1]+Xz,weapon_y1[N_WEAPON1],weapon_x2[N_WEAPON1]+Xz,weapon_y2[N_WEAPON1]);
//ruka_pistol->RenderStretch(ruk1x1+Xz,ruk1y1,ruk1x2+Xz,ruk1y2);
break;
case 10:
if(oboima>0)
rgd5->RenderEx(x+9+Xz,y-44,0,0.7f,0);
if(class1==1)
{player1_gogranata_ruka2->SetTexture(player1_myasnik_gogranata_ruka2_tex);}
if(class1==2)
{player1_gogranata_ruka2->SetTexture(player1_strelok_gogranata_ruka2_tex);}
if(class1==3)
{player1_gogranata_ruka2->SetTexture(player1_razrushitel_gogranata_ruka2_tex);}
if(class1==4)
{player1_gogranata_ruka2->SetTexture(player1_tehnik_gogranata_ruka2_tex);}
player1_gogranata_ruka2->Render(x-48+Xz, y-48);
break;
case 12:milkor->RenderStretch(weapon_x1[N_WEAPON1]+Xz,weapon_y1[N_WEAPON1],weapon_x2[N_WEAPON1]+Xz,weapon_y2[N_WEAPON1]);
break;
case 13:
if(oboima!=0)
{panzer->SetTexture(w_panzer_tex);}
if(oboima<=0)
{panzer->SetTexture(w_panzer_out_tex);}
panzer->RenderStretch(weapon_x1[N_WEAPON1]+Xz,weapon_y1[N_WEAPON1],weapon_x2[N_WEAPON1]+Xz,weapon_y2[N_WEAPON1]);
break;
case 14:webley->RenderStretch(weapon_x1[N_WEAPON1]+Xz,weapon_y1[N_WEAPON1],weapon_x2[N_WEAPON1]+Xz,weapon_y2[N_WEAPON1]);
break;
case 15:fn_five_seven->RenderStretch(weapon_x1[N_WEAPON1]+Xz,weapon_y1[N_WEAPON1],weapon_x2[N_WEAPON1]+Xz,weapon_y2[N_WEAPON1]);
break;
}





switch (class1)
{
case 1:
player1_myasnik->Render(x-48+Xz, y-48);
break;
case 2:
player1_strelok->Render(x-48+Xz, y-48);
break;
case 3:
player1_razrushitel->Render(x-48+Xz, y-48);
break;
case 4:
player1_tehnik->Render(x-48+Xz, y-48);
break;
}

if(N_WEAPON1==1||N_WEAPON1==4||N_WEAPON1==9||N_WEAPON1==14||N_WEAPON1==15)
{
switch (class1)
{
case 1:
player1_ruka1_pistol->SetTexture(player1_myasnik_ruka1_pistol_tex);
break;
case 2:
player1_ruka1_pistol->SetTexture(player1_strelok_ruka1_pistol_tex);
break;
case 3:
player1_ruka1_pistol->SetTexture(player1_razrushitel_ruka1_pistol_tex);
break;
case 4:
player1_ruka1_pistol->SetTexture(player1_tehnik_ruka1_pistol_tex);
break;
}

player1_ruka1_pistol->Render(x-48+Xz,y-48);
}


if(N_WEAPON1==0||N_WEAPON1==2||N_WEAPON1==3||N_WEAPON1==5||N_WEAPON1==8)
{
switch (class1)
{
case 1:
player1_ruka1_vintovka->SetTexture(player1_myasnik_ruka1_vintovka_tex);
break;
case 2:
player1_ruka1_vintovka->SetTexture(player1_strelok_ruka1_vintovka_tex);
break;
case 3:
player1_ruka1_vintovka->SetTexture(player1_razrushitel_ruka1_vintovka_tex);
break;
case 4:
player1_ruka1_vintovka->SetTexture(player1_tehnik_ruka1_vintovka_tex);
break;
}
if(N_WEAPON1!=2&&N_WEAPON1!=8)
{player1_ruka1_vintovka->Render(x-48+Xz, y-48);}
if(N_WEAPON1==2||N_WEAPON1==8)
{player1_ruka1_vintovka->Render(x-48+Xz, y-45);}
}



if(N_WEAPON1==7)
{
switch(class1)
{
case 1:
player1_ruka1_winch->SetTexture(player1_myasnik_ruka1_winch_tex);
break;
case 2:
player1_ruka1_winch->SetTexture(player1_strelok_ruka1_winch_tex);
break;
case 3:
player1_ruka1_winch->SetTexture(player1_razrushitel_ruka1_winch_tex);
break;
case 4:
player1_ruka1_winch->SetTexture(player1_tehnik_ruka1_winch_tex);
break;
}
player1_ruka1_winch->Render(x-48+Xz-17, y-45);
}


if(N_WEAPON1==10)
{
switch(class1)
{
case 1:
player1_gogranata_ruka1->SetTexture(player1_myasnik_gogranata_ruka1_tex);
break;
case 2:
player1_gogranata_ruka1->SetTexture(player1_strelok_gogranata_ruka1_tex);
break;
case 3:
player1_gogranata_ruka1->SetTexture(player1_razrushitel_gogranata_ruka1_tex);
break;
case 4:
player1_gogranata_ruka1->SetTexture(player1_tehnik_gogranata_ruka1_tex);
break;
}
player1_gogranata_ruka1->Render(x-48+Xz, y-48);
}

if(N_WEAPON1==11)
{
if(katana1_anime->GetFrame()!=2)	
{katana1_anime->Render(x-75+Xz, y-80);}
if(katana1_anime->GetFrame()==2)
{katana1_anime->Render(x-95+Xz, y-82);}
if(class1==1)
{player1_myasnik_ruka1_udar_sleva->SetTexture(player1_myasnik_ruka1_udar_sleva_tex);}
if(class1==2)
{player1_myasnik_ruka1_udar_sleva->SetTexture(player1_strelok_ruka1_udar_sleva_tex);}
if(class1==3)
{player1_myasnik_ruka1_udar_sleva->SetTexture(player1_razrushitel_ruka1_udar_sleva_tex);}
if(class1==4)
{player1_myasnik_ruka1_udar_sleva->SetTexture(player1_tehnik_ruka1_udar_sleva_tex);}
player1_myasnik_ruka1_udar_sleva->Render(x-48+Xz, y-48);}




pulya->Render(a+Xz, b);
break;


//ВТОРОЙ ИГРОК И ВСЯ ЕГО УТВАРЬ
case 102:
if(player2_aktive==1)//если игрок 2 играет
{

if(aktivatorp2!=0)
{p2->Render(p2x+Xz,p2y);//пуля2
p2d1->Render(p2d1x+Xz,p2d1y);
p2d2->Render(p2d2x+Xz,p2d2y);
p2d3->Render(p2d3x+Xz,p2d3y);
p2d4->Render(p2d4x+Xz,p2d4y);}

switch(N_WEAPON2)
{case 0 :
if(ak_up2==false)
{
if(ak2_tex==0)
{ak472->SetTexture(ak);}
if(ak2_tex==1)
{ak472->SetTexture(ak2);}
}

if(ak_up2==true)
{
if(ak2_tex==0)
{ak472->SetTexture(ak_upgraded);}
if(ak2_tex==1)
{ak472->SetTexture(ak2_upgraded);}
}
ak472->RenderStretch(weapon2_x1[N_WEAPON2]+Xz,weapon2_y1[N_WEAPON2],weapon2_x2[N_WEAPON2]+Xz,weapon2_y2[N_WEAPON2]);
break;
case 1 :pm2->RenderStretch(weapon2_x1[N_WEAPON2]+Xz,weapon2_y1[N_WEAPON2],weapon2_x2[N_WEAPON2]+Xz,weapon2_y2[N_WEAPON2]);
break;
case 2:pp19_vityaz2->RenderStretch(weapon2_x1[N_WEAPON2]+Xz,weapon2_y1[N_WEAPON2],weapon2_x2[N_WEAPON2]+Xz,weapon2_y2[N_WEAPON2]);
break;
case 3:
if(fn_f2000_up2==false)
{fn_f20002->SetTexture(w_fn_f2000_tex);}
if(fn_f2000_up2==true)
{fn_f20002->SetTexture(w_fn_f2000_upgraded_tex);}		
fn_f20002->RenderStretch(weapon2_x1[N_WEAPON2]+Xz,weapon2_y1[N_WEAPON2],weapon2_x2[N_WEAPON2]+Xz,weapon2_y2[N_WEAPON2]);
break;
case 4:tt2->RenderStretch(weapon2_x1[N_WEAPON2]+Xz,weapon2_y1[N_WEAPON2],weapon2_x2[N_WEAPON2]+Xz,weapon2_y2[N_WEAPON2]);
break;
case 5:rpk2->RenderStretch(weapon2_x1[N_WEAPON2]+Xz,weapon2_y1[N_WEAPON2],weapon2_x2[N_WEAPON2]+Xz,weapon2_y2[N_WEAPON2]);
break;
case 6:mac2->RenderStretch(weapon2_x1[N_WEAPON2]+Xz,weapon2_y1[N_WEAPON2],weapon2_x2[N_WEAPON2]+Xz,weapon2_y2[N_WEAPON2]);
break;
case 7:winchester2_anime->RenderStretch(weapon2_x1[N_WEAPON2]+Xz,weapon2_y1[N_WEAPON2],weapon2_x2[N_WEAPON2]+Xz,weapon2_y2[N_WEAPON2]);
break;
case 8:rpk472->RenderStretch(weapon2_x1[N_WEAPON2]+Xz,weapon2_y1[N_WEAPON2],weapon2_x2[N_WEAPON2]+Xz,weapon2_y2[N_WEAPON2]);
break;
case 9:glok2->RenderStretch(weapon2_x1[N_WEAPON2]+Xz,weapon2_y1[N_WEAPON2],weapon2_x2[N_WEAPON2]+Xz,weapon2_y2[N_WEAPON2]);
break;
case 10:
if(oboima2>0)
rgd52->RenderEx(x2+9+Xz,y2-44,0,0.7f,0);
player2_gogranata_ruka2->Render(x2-48+Xz, y2-48);
break;
case 12:milkor2->RenderStretch(weapon2_x1[N_WEAPON2]+Xz,weapon2_y1[N_WEAPON2],weapon2_x2[N_WEAPON2]+Xz,weapon2_y2[N_WEAPON2]);
break;
case 13:
if(oboima2!=0)
{panzer2->SetTexture(w_panzer_tex);}
if(oboima2<=0)
{panzer2->SetTexture(w_panzer_out_tex);}
panzer2->RenderStretch(weapon2_x1[N_WEAPON2]+Xz,weapon2_y1[N_WEAPON2],weapon2_x2[N_WEAPON2]+Xz,weapon2_y2[N_WEAPON2]);
break;
case 14:webley2->RenderStretch(weapon2_x1[N_WEAPON2]+Xz,weapon2_y1[N_WEAPON2],weapon2_x2[N_WEAPON2]+Xz,weapon2_y2[N_WEAPON2]);
break;
case 15:fn_five_seven2->RenderStretch(weapon2_x1[N_WEAPON2]+Xz,weapon2_y1[N_WEAPON2],weapon2_x2[N_WEAPON2]+Xz,weapon2_y2[N_WEAPON2]);
break;
}


player2_strelok->Render(x2-48+Xz, y2-48);



if(N_WEAPON2==1||N_WEAPON2==4||N_WEAPON2==9||N_WEAPON2==14||N_WEAPON2==15)
{
//switch (class1)
//{
//case 1:
//player1_ruka1_pistol->SetTexture(player2_myasnik_ruka1_pistol_tex);
//break;
//case 2:
player2_ruka1_pistol->SetTexture(player2_strelok_ruka1_pistol_tex);
//break;
//case 3:
//player1_ruka1_pistol->SetTexture(player2_razrushitel_ruka1_pistol_tex);
//break;
//case 4:
//player1_ruka1_pistol->SetTexture(player2_tehnik_ruka1_pistol_tex);
//break;
//}
player2_ruka1_pistol->Render(x2-48+Xz,y2-48);
}


if(N_WEAPON2==0||N_WEAPON2==2||N_WEAPON2==3||N_WEAPON2==5||N_WEAPON2==8)
{
if(N_WEAPON2!=2&&N_WEAPON2!=8)
{player2_ruka1_vintovka->Render(x2-48+Xz, y2-48);}
if(N_WEAPON2==2||N_WEAPON2==8)
{player2_ruka1_vintovka->Render(x2-48+Xz, y2-45);}
}



if(N_WEAPON2==10)
{player2_gogranata_ruka1->Render(x2-48+Xz, y2-48);}

if(N_WEAPON2==11)
{
if(katana2_anime->GetFrame()!=2)	
{katana2_anime->Render(x2-75+Xz, y2-80);}
if(katana2_anime->GetFrame()==2)
{katana2_anime->Render(x2-95+Xz, y2-82);}

player2_myasnik_ruka1_udar_sleva->Render(x2-48+Xz, y2-48);
}



pulya2->Render(a2+Xz, b2);
}//закрытие if player2_aktive==1
break;



default:
break;

}

}//ЗАКРЫТИЕ ПИРОЖКА...СМАЧНОГО!!!





vzriv_grena_psi->Render();
vzriv_ogon_grena_psi->Render();




	


//КОЛ-ВО ПАТРОНОВ----------игрока 1
	if((reload==false||N_WEAPON1==7||N_WEAPON1==12)&&N_WEAPON1!=11)
	{oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "%d",oboima);
	if((N_WEAPON1==3&&fn_f2000_up==true)||(N_WEAPON1==0&&ak_up==true))
	{oboima_text->printf(x-22+Xz, y-28, HGETEXT_CENTER, "+%d",oboima_alt[N_WEAPON1]);}
	}

	
//КОЛ-ВО ПАТРОНОВ----------игрока 2
	if((reload2==false||N_WEAPON2==7||N_WEAPON2==12)&&player2_aktive==1&&N_WEAPON2!=11)
	{oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "%d",oboima2);
	if((N_WEAPON2==3&&fn_f2000_up2==true)||(N_WEAPON2==0&&ak_up2==true))
	{oboima_text->printf(x2-22+Xz, y2-28, HGETEXT_CENTER, "+%d",oboima2_alt[N_WEAPON2]);}
	}


	
//ВЫВОД ПРОГРЕССА ПЕРЕЗАРЯДКИ ИГРОКА 1
	if(reload==true)
	{   
	

	if(N_WEAPON1==0||N_WEAPON1==3||N_WEAPON1==5||N_WEAPON1==8)
	{
	if(perez_time>reload_time[N_WEAPON1]) //если секунда от 0 до 57
	{
	if(perez_akt==perez_time-reload_time[N_WEAPON1])
	{oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-  ]");}

	if((reload_time[N_WEAPON1]%2==0&&perez_akt==perez_time-(reload_time[N_WEAPON1]-reload_time[N_WEAPON1]/2))||
	   (reload_time[N_WEAPON1]%2!=0&&perez_akt==perez_time-(reload_time[N_WEAPON1]-((reload_time[N_WEAPON1]-1)/2)))||
	   (reload_time[N_WEAPON1]%2!=0&&perez_akt==perez_time-(reload_time[N_WEAPON1]-((reload_time[N_WEAPON1]+1)/2))))
    {
	oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-- ]");
	if(perez_akt_milli==perez_time_milli&&(perez_akt==perez_time-1||perez_akt==59))
	{ak_perez2();}
	}
    
	if(perez_akt==perez_time&&perez_akt_milli<perez_time_milli)
    {oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[---]");}
	}
	}


	if(N_WEAPON1==0||N_WEAPON1==3)
	{
	if(perez_time==0) //если секунда 58
	{
	if(perez_akt==58)
	{oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-  ]");}
	
	if(perez_akt==59)
    {
	oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-- ]");
	if(perez_akt_milli==perez_time_milli){ak_perez2();}
	}
	
	if(perez_akt==0&&perez_akt_milli<perez_time_milli)
    {oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[---]");}
	}

	if(perez_time==1) //если секунда 59
	{
	if(perez_akt==59)
	{oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-  ]");}
	
	if(perez_akt==0)
    {
	oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-- ]");
	if(perez_akt_milli==perez_time_milli){ak_perez2();}
	}
	
	if(perez_akt==1&&perez_akt_milli<perez_time_milli)
    {oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[---]");}
	}

	if(perez_time==2) //если секунда 0
	{
	if(perez_akt==0)
	{oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-  ]");}
	
	if(perez_akt==1)
    {
	oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-- ]");
	if(perez_akt_milli==perez_time_milli){ak_perez2();}
	}
	
	if(perez_akt==2&&perez_akt_milli<perez_time_milli)
    {oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[---]");}
	}
 }
	

 if(N_WEAPON1==1||N_WEAPON1==4||N_WEAPON1==9||N_WEAPON1==14||N_WEAPON1==15)
{


	if((perez_akt==perez_time-1&&perez_time!=0)||(perez_akt==59&&perez_time==0))
	{oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-  ]");}

 if(perez_time>0) //если секунда меньше 59
	{
	if(perez_time_milli<700&&perez_akt_milli>perez_time_milli+300||
	   perez_time_milli>=700&&perez_akt_milli>perez_time_milli-700)
	 { oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-- ]");}
   

    if(perez_time_milli<500&&perez_akt_milli==perez_time_milli+500||
	   perez_time_milli>=500&&perez_akt==perez_time&&perez_akt_milli==perez_time_milli-500)
	{
	if(N_WEAPON1!=14)	
	{pm_perez2();}
	if(N_WEAPON1==14)	
	{webley_perez2();}
	}

	if(perez_akt==perez_time&&perez_akt_milli<perez_time_milli)
    {oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[---]");
	}
    }
   if(perez_time==0) //если секуда 59-я
   {
	if(perez_time_milli<700&&perez_akt_milli>perez_time_milli+300||
	   perez_time_milli>=700&&perez_akt_milli>perez_time_milli-700)
	 { oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-- ]");}
   

    if(perez_time_milli<500&&perez_akt_milli==perez_time_milli+500||
	   perez_time_milli>=500&&perez_akt==perez_time&&perez_akt_milli==perez_time_milli-500)
	{if(N_WEAPON1!=14)	
	{pm_perez2();}
	if(N_WEAPON1==14)	
	{webley_perez2();}
	}

	if(perez_akt==perez_time-59&&perez_akt_milli<perez_time_milli)
    {oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[---]");} 
   }
}


if(N_WEAPON1==2||N_WEAPON1==6)
{

if(perez_time>=2&&perez_akt==perez_time-2)
{oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-  ]");}
if((perez_time==0&perez_akt==58)||(perez_time==1&perez_akt==59))
{oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-  ]");}


if(perez_time>=1
&&perez_akt==perez_time-1&&perez_akt_milli<=perez_time_milli)
{oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-- ]");
if(perez_akt_milli==perez_time_milli)
{
if(N_WEAPON1==2)
{pp19_perez2();}
if(N_WEAPON1==6)
{mac_perez2();}
}}
if(perez_time==0
&&perez_akt==59&&perez_akt_milli<=perez_time_milli)
{oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-- ]");
if(perez_akt_milli==perez_time_milli)
{
if(N_WEAPON1==2)
{pp19_perez2();}
if(N_WEAPON1==6)
{mac_perez2();}
}}

if((perez_time>=1
&&perez_akt==perez_time-1&&perez_akt_milli>=perez_time_milli)||perez_akt==perez_time)
{oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[---]");}
if((perez_time==0
&&perez_akt==59&&perez_akt_milli>=perez_time_milli)||perez_akt==0)
{oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[---]");}
}


 if(N_WEAPON1==5||N_WEAPON1==8)
{

	if(perez_time==0) //если секунда 57
	{
	if(perez_akt==57)
	{oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-  ]");}
	
	if(perez_akt==58)
    {
	oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-- ]");
	if(perez_akt_milli==perez_time_milli){ak_perez2();}
	}
	
	if(perez_akt==59&&perez_akt_milli<perez_time_milli)
    {oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[---]");}
	}

	if(perez_time==1) //если секунда 58
	{
	if(perez_akt==58)
	{oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-  ]");}
	
	if(perez_akt==59)
    {
	oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-- ]");
	if(perez_akt_milli==perez_time_milli){ak_perez2();}
	}
	
	if(perez_akt==0&&perez_akt_milli<perez_time_milli)
    {oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[---]");}
	}

	if(perez_time==2) //если секунда 59
	{
	if(perez_akt==59)
	{oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-  ]");}
	
	if(perez_akt==0)
    {
	oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-- ]");
	if(perez_akt_milli==perez_time_milli){ak_perez2();}
	}
	
	if(perez_akt==1&&perez_akt_milli<perez_time_milli)
    {oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[---]");}
	}

	if(perez_time==3) //если секунда 0
	{
	if(perez_akt==0)
	{oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-  ]");}
	
	if(perez_akt==1)
    {
	oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[-- ]");
	if(perez_akt_milli==perez_time_milli){ak_perez2();}
	}
	
	if(perez_akt==2&&perez_akt_milli<perez_time_milli)
    {oboima_text->printf(x-35+Xz, y-28, HGETEXT_CENTER, "[---]");}
	}
 }

	} //ЗАКРЫТИЕ ВЫВОДА ПРОГРЕССА ПЕРЕЗАРЯДКИ ИГРОКА 1

//ВЫВОД ПРОГРЕССА ПЕРЕЗАРЯДКИ ИГРОКА 2
	if(reload2==true)
	{   
	
	if(N_WEAPON2==0||N_WEAPON2==3||N_WEAPON2==5||N_WEAPON2==8)
	{
	if(perez_time2>reload_time[N_WEAPON2]) //если секунда от 0 до 57
	{
	if(perez_akt==perez_time2-reload_time[N_WEAPON2])
	{oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-  ]");}

	if((reload_time[N_WEAPON2]%2==0&&perez_akt==perez_time2-(reload_time[N_WEAPON2]-reload_time[N_WEAPON2]/2))||
	   (reload_time[N_WEAPON2]%2!=0&&perez_akt==perez_time2-(reload_time[N_WEAPON2]-((reload_time[N_WEAPON2]-1)/2)))||
	   (reload_time[N_WEAPON2]%2!=0&&perez_akt==perez_time2-(reload_time[N_WEAPON2]-((reload_time[N_WEAPON2]+1)/2))))
    {
	oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-- ]");
	if(perez_akt_milli==perez_time_milli2&&(perez_akt==perez_time2-1||perez_akt==59))
	{ak2_perez2();}
	}
    
	if(perez_akt==perez_time2&&perez_akt_milli<perez_time_milli2)
    {oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[---]");}
	}
	}


	if(N_WEAPON2==0||N_WEAPON2==3)
	{
	if(perez_time2==0) //если секунда 58
	{
	if(perez_akt==58)
	{oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-  ]");}
	
	if(perez_akt==59)
    {
	oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-- ]");
	if(perez_akt_milli==perez_time_milli2){ak2_perez2();}
	}
	
	if(perez_akt==0&&perez_akt_milli<perez_time_milli2)
    {oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[---]");}
	}

	if(perez_time2==1) //если секунда 59
	{
	if(perez_akt==59)
	{oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-  ]");}
	
	if(perez_akt==0)
    {
	oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-- ]");
	if(perez_akt_milli==perez_time_milli2){ak2_perez2();}
	}
	
	if(perez_akt==1&&perez_akt_milli<perez_time_milli2)
    {oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[---]");}
	}

	if(perez_time2==2) //если секунда 0
	{
	if(perez_akt==0)
	{oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-  ]");}
	
	if(perez_akt==1)
    {
	oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-- ]");
	if(perez_akt_milli==perez_time_milli2){ak2_perez2();}
	}
	
	if(perez_akt==2&&perez_akt_milli<perez_time_milli2)
    {oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[---]");}
	}
 }
	

 if(N_WEAPON2==1||N_WEAPON2==4||N_WEAPON2==9||N_WEAPON2==14||N_WEAPON2==15)
{


	if((perez_akt==perez_time2-1&&perez_time2!=0)||(perez_akt==59&&perez_time2==0))
	{oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-  ]");}

 if(perez_time2>0) //если секунда меньше 59
	{
	if(perez_time_milli2<700&&perez_akt_milli>perez_time_milli2+300||
	   perez_time_milli2>=700&&perez_akt_milli>perez_time_milli2-700)
	 { oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-- ]");}
   

    if(perez_time_milli2<500&&perez_akt_milli==perez_time_milli2+500||
	   perez_time_milli2>=500&&perez_akt==perez_time2&&perez_akt_milli==perez_time_milli2-500)
	{if(N_WEAPON2!=14)	
	{pm2_perez2();}
	if(N_WEAPON2==14)	
	{webley2_perez2();}}

	if(perez_akt==perez_time2&&perez_akt_milli<perez_time_milli2)
    {oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[---]");
	}
    }
   if(perez_time2==0) //если секуда 59-я
   {
	if(perez_time_milli2<700&&perez_akt_milli>perez_time_milli2+300||
	   perez_time_milli2>=700&&perez_akt_milli>perez_time_milli2-700)
	 { oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-- ]");}
   

    if(perez_time_milli2<500&&perez_akt_milli==perez_time_milli2+500||
	   perez_time_milli2>=500&&perez_akt==perez_time2&&perez_akt_milli==perez_time_milli2-500)
	{if(N_WEAPON2!=14)	
	{pm2_perez2();}
	if(N_WEAPON2==14)	
	{webley2_perez2();}}

	if(perez_akt==perez_time2-59&&perez_akt_milli<perez_time_milli2)
    {oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[---]");} 
   }
}


if(N_WEAPON2==2||N_WEAPON2==6)
{

if(perez_time2>=2&&perez_akt==perez_time2-2)
{oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-  ]");}
if((perez_time2==0&perez_akt==58)||(perez_time2==1&perez_akt==59))
{oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-  ]");}


if(perez_time2>=1
&&perez_akt==perez_time2-1&&perez_akt_milli<=perez_time_milli2)
{oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-- ]");
if(perez_akt_milli==perez_time_milli2)
{
if(N_WEAPON2==2)
{pp192_perez2();}
if(N_WEAPON2==6)
{mac2_perez2();}
}}
if(perez_time2==0
&&perez_akt==59&&perez_akt_milli<=perez_time_milli2)
{oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-- ]");
if(perez_akt_milli==perez_time_milli2)
{
if(N_WEAPON2==2)
{pp192_perez2();}
if(N_WEAPON2==6)
{mac2_perez2();}
}}

if((perez_time2>=1
&&perez_akt==perez_time2-1&&perez_akt_milli>=perez_time_milli2)||perez_akt==perez_time2)
{oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[---]");}
if((perez_time2==0
&&perez_akt==59&&perez_akt_milli>=perez_time_milli2)||perez_akt==0)
{oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[---]");}
}


 if(N_WEAPON2==5||N_WEAPON2==8)
{

	if(perez_time2==0) //если секунда 57
	{
	if(perez_akt==57)
	{oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-  ]");}
	
	if(perez_akt==58)
    {
	oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-- ]");
	if(perez_akt_milli==perez_time_milli2){ak2_perez2();}
	}
	
	if(perez_akt==59&&perez_akt_milli<perez_time_milli2)
    {oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[---]");}
	}

	if(perez_time2==1) //если секунда 58
	{
	if(perez_akt==58)
	{oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-  ]");}
	
	if(perez_akt==59)
    {
	oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-- ]");
	if(perez_akt_milli==perez_time_milli2){ak2_perez2();}
	}
	
	if(perez_akt==0&&perez_akt_milli<perez_time_milli2)
    {oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[---]");}
	}

	if(perez_time2==2) //если секунда 59
	{
	if(perez_akt==59)
	{oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-  ]");}
	
	if(perez_akt==0)
    {
	oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-- ]");
	if(perez_akt_milli==perez_time_milli2){ak2_perez2();}
	}
	
	if(perez_akt==1&&perez_akt_milli<perez_time_milli2)
    {oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[---]");}
	}

	if(perez_time2==3) //если секунда 0
	{
	if(perez_akt==0)
	{oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-  ]");}
	
	if(perez_akt==1)
    {
	oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[-- ]");
	if(perez_akt_milli==perez_time_milli2){ak2_perez2();}
	}
	
	if(perez_akt==2&&perez_akt_milli<perez_time_milli2)
    {oboima_text->printf(x2-35+Xz, y2-28, HGETEXT_CENTER, "[---]");}
	}
 }


	} //ЗАКРЫТИЕ ВЫВОДА ПРОГРЕССА ПЕРЕЗАРЯДКИ ИГРОКА 2



	//ОПТИЧЕСКИЕ ПРИЦЕЛЫ--------
	if(N_WEAPON1==3)
	{optika1->RenderEx(x-374+Xz,y-9,0,1,0);
	 optika1->RenderEx(x-380+Xz,y-9,0,1,0);
	 optika1->RenderEx(x-375+Xz,y-13,M_PI_2,1,0);
	 optika1->RenderEx(x-375+Xz,y-7,M_PI_2,1,0);
	}

	if(N_WEAPON1==12)
	{optika1->RenderEx(x-374+Xz,y-49,0,1,0);
	 optika1->RenderEx(x-380+Xz,y-49,0,1,0);
	 optika1->RenderEx(x-375+Xz,y-53,M_PI_2,1,0);
	 optika1->RenderEx(x-375+Xz,y-47,M_PI_2,1,0);
	}

	if(N_WEAPON1==13)
	{optika1->RenderEx(x-374+Xz,y-16,0,1,0);
	 optika1->RenderEx(x-380+Xz,y-16,0,1,0);
	 optika1->RenderEx(x-375+Xz,y-20,M_PI_2,1,0);
	 optika1->RenderEx(x-375+Xz,y-14,M_PI_2,1,0);
	}

	if(N_WEAPON2==3)
	{optika1->RenderEx(x2-374+Xz,y2-9,0,1,0);
	 optika1->RenderEx(x2-380+Xz,y2-9,0,1,0);
	 optika1->RenderEx(x2-375+Xz,y2-13,M_PI_2,1,0);
	 optika1->RenderEx(x2-375+Xz,y2-7,M_PI_2,1,0);
	}

	if(N_WEAPON2==12)
	{optika1->RenderEx(x2-374+Xz,y2-49,0,1,0);
	 optika1->RenderEx(x2-380+Xz,y2-49,0,1,0);
	 optika1->RenderEx(x2-375+Xz,y2-53,M_PI_2,1,0);
	 optika1->RenderEx(x2-375+Xz,y2-47,M_PI_2,1,0);
	}

	if(N_WEAPON2==13)
	{optika1->RenderEx(x2-374+Xz,y2-16,0,1,0);
	 optika1->RenderEx(x2-380+Xz,y2-16,0,1,0);
	 optika1->RenderEx(x2-375+Xz,y2-20,M_PI_2,1,0);
	 optika1->RenderEx(x2-375+Xz,y2-14,M_PI_2,1,0);
	}


	//--------------------------

	//тексты бонуса
	for(int i35=0;i35<=N_BONUSTEXT;i35++)
	{
	if(bonustextiObjects[i35].akt==1)
	{
	switch(bonustextiObjects[i35].type)
	{
	case 0:
	bonus_this_text->Render(bonustextiObjects[i35].x+Xz,bonustextiObjects[i35].y);
	break;
	case 1:
	bonus_shilo_text->Render(bonustextiObjects[i35].x+Xz,bonustextiObjects[i35].y);
	break;
	case 2:
	bonus_daun_text->Render(bonustextiObjects[i35].x+Xz,bonustextiObjects[i35].y);
	break;
	case 3:
	bonus_ulitka_text->Render(bonustextiObjects[i35].x+Xz,bonustextiObjects[i35].y);
	break;
	case 4:
	bonus_umnik_text->Render(bonustextiObjects[i35].x+Xz,bonustextiObjects[i35].y);
	break;
	}
	}
	
	}//закрытие текста бонуса

    info->printf(5,10, HGETEXT_LEFT, "dt:%.3f\nFPS:%d",
              hge->Timer_GetDelta(), hge->Timer_GetFPS());
	info->printf(5,50,HGETEXT_LEFT,"Перегрузка: %d/%d",N_TRUPS,MAX_TRUPS);
	info->printf(5,70,HGETEXT_LEFT,"Врагов: %d",N_ZAYAC+1+N_VOLK+1+N_MEDVED+1+N_PTENEC+1);

	
	
	//время игры
	if(perez_akt<10&leveltime<10)
	{info->printf(600,30,HGETEXT_CENTER,"0%d:0%d",leveltime,perez_akt);}
	if(perez_akt<10&leveltime>=10)
	{info->printf(600,30,HGETEXT_CENTER,"%d:0%d",leveltime,perez_akt);}
	if(perez_akt>=10&&leveltime<10)
	{info->printf(600,30,HGETEXT_CENTER,"0%d:%d",leveltime,perez_akt);}
	if(perez_akt>=10&&leveltime>=10)
	{info->printf(600,30,HGETEXT_CENTER,"%d:%d",leveltime,perez_akt);}



	info->printf(1050,30,HGETEXT_LEFT,"ИГРОК 1");
    info->printf(1050,50,HGETEXT_LEFT,"ОЧКИ: %d",points1);
    info->printf(1050,70,HGETEXT_LEFT,"Убито: %d",kills);

	//RPG
	if(RPGMOD==true)
	{

	if(lvl1_ready==false)
	{info->printf(960,92,HGETEXT_LEFT,"Ур.:%d",LVL1);}
	if(lvl1_ready==true)
	{
	if(lvl1_mig==1)
	infoR->printf(960,92,HGETEXT_LEFT,"Ур.:%d",LVL1);
	if(lvl1_mig==2)
	info->printf(960,92,HGETEXT_LEFT,"Ур.:%d",LVL1);
	}

	opit1_progress->RenderStretch(1023,103,opit1_x2,117);
	status_opit->Render(1020,100);
	status_udar->Render(1020,120);
	//статус	
	for(int i39=0;i39<=N_BONUSSTATUS1;i39++)
	{
	if(statusi1[i39].akt==1)
	{switch(statusi1[i39].type)
	{case 1:
	bonus_shilo_status->Render(status1x+14,status1y+40+20*statusi1[i39].queue);
	break;
	case 2:
	bonus_daun_status->Render(status1x+14,status1y+40+20*statusi1[i39].queue);
	break;
	case 3:
	bonus_ulitka_status->Render(status1x+14,status1y+40+20*statusi1[i39].queue);
	break;
	case 4:
	bonus_umnik_status->Render(status1x+14,status1y+40+20*statusi1[i39].queue);
	break;
	}
	}
	} 
	
	status_status->Render(status1x,status1y);
	//закрытие статуса
	}//RPG
    


	if(player2_aktive==1)
	{
	info->printf(1050,780,HGETEXT_LEFT,"ИГРОК 2");
	info->printf(1050,810,HGETEXT_LEFT,"ОЧКИ: %d",points2);
	info->printf(1050,830,HGETEXT_LEFT,"Убито: %d",kills2);	
	
	//RPG
	if(RPGMOD==true)
	{
	if(lvl2_ready==false)
	{info->printf(960,852,HGETEXT_LEFT,"Ур.:%d",LVL2);}
	if(lvl2_ready==true)
	{
	if(lvl2_mig==1)
	infoR->printf(960,852,HGETEXT_LEFT,"Ур.:%d",LVL2);
	if(lvl2_mig==2)
	info->printf(960,852,HGETEXT_LEFT,"Ур.:%d",LVL2);
	}

	opit1_progress->RenderStretch(1023,863,opit2_x2,877);
	status_opit->Render(1020,860);
	status_udar->Render(1020,880);
	//статус
	for(int i39=0;i39<=N_BONUSSTATUS2;i39++)
	{
	if(statusi2[i39].akt==1)
	{switch(statusi2[i39].type)
	{case 1:
	bonus_shilo_status->Render(status2x+14,status2y+40+20*statusi2[i39].queue);
	break;
	case 2:
	bonus_daun_status->Render(status2x+14,status2y+40+20*statusi2[i39].queue);
	break;
	case 3:
	bonus_ulitka_status->Render(status2x+14,status2y+40+20*statusi2[i39].queue);
	break;
	case 4:
	bonus_umnik_status->Render(status2x+14,status2y+40+20*statusi2[i39].queue);
	break;
	}
	}
	}

	status_status->Render(status2x,status2y);
	//закрытие статуса

	}//RPG
	
	
	
	}


   
    
    switch(menu1_on)
	{case 1:info->printf(0,100,HGETEXT_LEFT,"1.Пистолеты\n2.Дробовики\n3.Пистолеты-пулемёты\n4.Автоматы\n5.Пулемёты\n6.Гранатомёты\n7.Винтовки\n8.Холодное\n9.Спец.оружие\n0.Выход");
	break;
	case 2:

		
//TT
	if(tt_buy==false)
	{
	if(points1>=cena[4])
	{info->printf(0,100,HGETEXT_LEFT,"1.TT(СССР) %d\n",cena[4]);}
	else
	{infoR->printf(0,100,HGETEXT_LEFT,"1.TT(СССР) %d\n",cena[4]);}
	}
	if(tt_buy==true)
	{infoD->printf(0,100,HGETEXT_LEFT,"1.TT(СССР) %d\n",cena[4]);
	galka->Render(330,114);}
//GLOK
	if(glok_buy==false)
	{
	if(points1>=cena[9])
	{info->printf(0,120,HGETEXT_LEFT,"2.GLOCK(Австрия) %d\n",cena[9]);}
	else
	{infoR->printf(0,120,HGETEXT_LEFT,"2.GLOCK(Австрия) %d\n",cena[9]);}
	}
	if(glok_buy==true)
	{infoD->printf(0,120,HGETEXT_LEFT,"2.GLOCK(Австрия) %d\n",cena[9]);
	galka->Render(330,134);}
//Webley mk4
	if(webley_buy==false)
	{
	if(points1>=cena[14])
	{info->printf(0,140,HGETEXT_LEFT,"3.Webley mkIV(Англия) %d\n",cena[14]);}
	else
	{infoR->printf(0,140,HGETEXT_LEFT,"3.Webley mkIV(Англия) %d\n",cena[14]);}
	}
	if(webley_buy==true)
	{infoD->printf(0,140,HGETEXT_LEFT,"3.Webley mkIV(Англия) %d\n",cena[14]);
	galka->Render(330,154);}
//FN Five-Seven
	if(fn_five_seven_buy==false)
	{
	if(points1>=cena[15])
	{info->printf(0,160,HGETEXT_LEFT,"4.FN Five-Seven(Бельгия) %d\n0.Выход",cena[15]);}
	else
	{infoR->printf(0,160,HGETEXT_LEFT,"4.FN Five-Seven(Бельгия) %d\n0.Выход",cena[15]);}
	}
	if(fn_five_seven_buy==true)
	{infoD->printf(0,160,HGETEXT_LEFT,"4.FN Five-Seven(Бельгия) %d\n0.Выход",cena[15]);
	galka->Render(330,174);}
	break;

	case 3:
//WINCHESTER
	if(winchester_buy==false)
	{
	if(points1>=cena[7])
	{info->printf(0,100,HGETEXT_LEFT,"1.Winchester %d\n0.Выход",cena[7]);}
	else
	{infoR->printf(0,100,HGETEXT_LEFT,"1.Winchester %d\n0.Выход",cena[7]);}
	}
	if(winchester_buy==true)
	{infoD->printf(0,100,HGETEXT_LEFT,"1.Winchester %d\n0.Выход",cena[7]);
	galka->Render(330,114);}
	break;
    case 4:
//MAC	
	if(mac_buy==false)
	{
	if(points1>=cena[6])
	{info->printf(0,100,HGETEXT_LEFT,"1.MAC(США) %d\n",cena[6]);}
	else
	{infoR->printf(0,100,HGETEXT_LEFT,"1.MAC(США) %d\n",cena[6]);}
	}
	if(mac_buy==true)
	{infoD->printf(0,100,HGETEXT_LEFT,"1.MAC(США) %d\n",cena[6]);
	galka->Render(330,114);}
//PP-19	
	if(pp19_buy==false)
	{
	if(points1>=cena[2])
	{info->printf(0,120,HGETEXT_LEFT,"2.ПП-19'Витязь'(Россия) %d\n0.Выход",cena[2]);}
	else
	{infoR->printf(0,120,HGETEXT_LEFT,"2.ПП-19'Витязь'(Россия) %d\n0.Выход",cena[2]);}
	}
	if(pp19_buy==true)
	{infoD->printf(0,120,HGETEXT_LEFT,"2.ПП-19'Витязь'(Россия) %d\n0.Выход",cena[2]);
	galka->Render(330,134);}
	break;
	case 5: 
	
//AK-74	
	if(ak_buy==false)
	{
	if(points1>=cena[0])
	{info->printf(0,100,HGETEXT_LEFT,"1.АК-74(СССР) %d\n",cena[0]);}
	else
	{infoR->printf(0,100,HGETEXT_LEFT,"1.АК-74(СССР) %d\n",cena[0]);}
	}
	if(ak_buy==true&&ak_up==false)
	{
	if(points1>=cena_up[1])
	{info->printf(0,100,HGETEXT_LEFT,"1.АК-74(СССР) upgrade %d\n",cena_up[1]);}
	if(points1<cena_up[1])
	{infoR->printf(0,100,HGETEXT_LEFT,"1.АК-74(СССР) upgrade %d\n",cena_up[1]);}
	}
	if(ak_buy==true&&ak_up==true)
	{infoD->printf(0,100,HGETEXT_LEFT,"1.АК-74(СССР) %d\n",cena[0]);
	galka->Render(330,114);}
	

//FN F2000
	if(fn_f2000_buy==false)
	{
	if(points1>=cena[3])
	{info->printf(0,120,HGETEXT_LEFT,"2.FN_F2000(Бельгия) %d\n0.Выход",cena[3]);}
	else
	{infoR->printf(0,120,HGETEXT_LEFT,"2.FN_F2000(Бельгия) %d\n0.Выход",cena[3]);}
	}
	if(fn_f2000_buy==true&&fn_f2000_up==false)
	{
	if(points1>=cena_up[0])
	{info->printf(0,120,HGETEXT_LEFT,"2.FN_F2000(Бельгия) upgrade %d\n0.Выход",cena_up[0]);}
	if(points1<cena_up[0])
	{infoR->printf(0,120,HGETEXT_LEFT,"2.FN_F2000(Бельгия) upgrade %d\n0.Выход",cena_up[0]);}
	}
	if(fn_f2000_buy==true&&fn_f2000_up==true)
	{infoD->printf(0,120,HGETEXT_LEFT,"2.FN_F2000(Бельгия) %d\n0.Выход",cena[3]);
	galka->Render(330,134);}
	break;
	case 6:
//RPK 47
	if(rpk47_buy==false)
	{
	if(points1>=cena[8])	
	{info->printf(0,100,HGETEXT_LEFT,"1.РПК-74(СССР) %d\n",cena[8]);}
	else
	{infoR->printf(0,100,HGETEXT_LEFT,"1.РПК-74(СССР) %d\n",cena[8]);}
	}
	if(rpk47_buy==true)
	{infoD->printf(0,100,HGETEXT_LEFT,"1.РПК-74(СССР) %d\n",cena[8]);
	galka->Render(330,114);}
		
		
//RPK
	if(rpk_buy==false)
	{
	if(points1>=cena[5])	
	{info->printf(0,120,HGETEXT_LEFT,"2.РПК-74М(СССР) %d\n0.Выход",cena[5]);}
	else
	{infoR->printf(0,120,HGETEXT_LEFT,"2.РПК-74М(СССР) %d\n0.Выход",cena[5]);}
	}
	if(rpk_buy==true)
	{infoD->printf(0,120,HGETEXT_LEFT,"2.РПК-74М(СССР) %d\n0.Выход",cena[5]);
	galka->Render(330,134);}
	break;


//РГД-5
	case 7:
	if(rgd5_buy==false)
	{
	if(points1>=cena[10])	
	{info->printf(0,100,HGETEXT_LEFT,"1.РГД-5(СССР) %d\n",cena[10]);}
	else
	{infoR->printf(0,100,HGETEXT_LEFT,"1.РГД-5(СССР) %d\n",cena[10]);}
	}
	if(rgd5_buy==true)
	{infoD->printf(0,100,HGETEXT_LEFT,"1.РГД-5(СССР) %d\n",cena[10]);
	galka->Render(330,114);}	
//MILKOR MGL
	if(milkor_buy==false)
	{
	if(points1>=cena[12])	
	{info->printf(0,140,HGETEXT_LEFT,"3.Milkor MGL %d\n",cena[12]);}
	else
	{infoR->printf(0,140,HGETEXT_LEFT,"3.Milkor MGL %d\n",cena[12]);}
	}
	if(milkor_buy==true)
	{infoD->printf(0,140,HGETEXT_LEFT,"3.Milkor MGL %d\n",cena[12]);
	galka->Render(330,154);}
	//Panzerfaust 3
	if(panzer_buy==false)
	{
	if(points1>=cena[13])	
	{info->printf(0,180,HGETEXT_LEFT,"5.Panzerfaust-3(Германия) %d\n0.Выход",cena[13]);}
	else
	{infoR->printf(0,180,HGETEXT_LEFT,"5.Panzerfaust-3(Германия) %d\n0.Выход",cena[13]);}
	}
	if(panzer_buy==true)
	{infoD->printf(0,180,HGETEXT_LEFT,"5.Panzerfaust-3(Германия) %d\n0.Выход",cena[13]);
	galka->Render(330,194);}
	break;

//катана
	case 9:
	if(katana_buy==false)
	{
	if(points1>=cena[11])	
	{info->printf(0,120,HGETEXT_LEFT,"2.Катана(Япония) %d\n0.Выход",cena[11]);}
	else
	{infoR->printf(0,120,HGETEXT_LEFT,"2.Катана(Япония) %d\n0.Выход",cena[11]);}
	}
	if(katana_buy==true)
	{infoD->printf(0,120,HGETEXT_LEFT,"2.Катана(Япония) %d\n0.Выход",cena[11]);
	galka->Render(330,134);}
	break;



    }

	switch(menu2_on)
	{case 1:info->printf(0,550,HGETEXT_LEFT,"1.Пистолеты\n2.Дробовики\n3.Пистолеты-пулемёты\n4.Автоматы\n5.Пулемёты\n6.Гранатомёты\n7.Винтовки\n8.Холодное\n9.Спец.оружие\n0.Выход");
	break;
	case 2:


//ТТ
	if(tt_buy2==false)
	{
	if(points2>=cena[4])
	{info->printf(0,550,HGETEXT_LEFT,"1.TT(СССР) %d\n",cena[4]);}
	else
	{infoR->printf(0,550,HGETEXT_LEFT,"1.TT(СССР) %d\n",cena[4]);}
	}
	if(tt_buy2==true)
	{infoD->printf(0,550,HGETEXT_LEFT,"1.TT(СССР) %d\n",cena[4]);
	galka->Render(330,564);}		

//GLOK
	if(glok_buy2==false)
	{
	if(points2>=cena[9])
	{info->printf(0,570,HGETEXT_LEFT,"2.GLOCK(Австрия) %d\n",cena[9]);}
	else
	{infoR->printf(0,570,HGETEXT_LEFT,"2.GLOCK(Австрия) %d\n",cena[9]);}
	}
	if(glok_buy2==true)
	{infoD->printf(0,570,HGETEXT_LEFT,"2.GLOCK(Австрия) %d\n",cena[9]);
	galka->Render(330,584);}		
//Webley mk4
	if(webley_buy2==false)
	{
	if(points2>=cena[14])
	{info->printf(0,590,HGETEXT_LEFT,"3.Webley mkIV(Англия) %d\n",cena[14]);}
	else
	{infoR->printf(0,590,HGETEXT_LEFT,"3.Webley mkIV(Англия) %d\n",cena[14]);}
	}
	if(webley_buy2==true)
	{infoD->printf(0,590,HGETEXT_LEFT,"3.Webley mkIV(Англия) %d\n",cena[14]);
	galka->Render(330,604);}
//FN Five-Seven
	if(fn_five_seven_buy2==false)
	{
	if(points2>=cena[15])
	{info->printf(0,610,HGETEXT_LEFT,"4.FN Five-Seven(Бельгия) %d\n0.Выход",cena[15]);}
	else
	{infoR->printf(0,610,HGETEXT_LEFT,"4.FN Five-Seven(Бельгия) %d\n0.Выход",cena[15]);}
	}
	if(fn_five_seven_buy2==true)
	{infoD->printf(0,610,HGETEXT_LEFT,"4.FN Five-Seven(Бельгия) %d\n0.Выход",cena[15]);
	galka->Render(330,624);}
	break;

	case 3:
//WINCHESTER
	if(winchester_buy2==false)
	{
	if(points2>=cena[7])
	{info->printf(0,550,HGETEXT_LEFT,"1.Winchester %d\n0.Выход",cena[7]);}
	else
	{infoR->printf(0,550,HGETEXT_LEFT,"1.Winchester %d\n0.Выход",cena[7]);}
	}
	if(winchester_buy2==true)
	{infoD->printf(0,550,HGETEXT_LEFT,"1.Winchester %d\n0.Выход",cena[7]);
	galka->Render(330,564);}
	break;
    case 4:
//MAC	
	if(mac_buy2==false)
	{
	if(points2>=cena[6])
	{info->printf(0,550,HGETEXT_LEFT,"1.MAC(США) %d\n",cena[6]);}
	else
	{infoR->printf(0,550,HGETEXT_LEFT,"1.MAC(США) %d\n",cena[6]);}
	}
	if(mac_buy2==true)
	{infoD->printf(0,550,HGETEXT_LEFT,"1.MAC(США) %d\n",cena[6]);
	galka->Render(330,564);}
//PP-19	
	if(pp19_buy2==false)
	{
	if(points2>=cena[2])
	{info->printf(0,570,HGETEXT_LEFT,"2.ПП-19'ВитЯзь'(Россия) %d\n0.Выход",cena[2]);}
	else
	{infoR->printf(0,570,HGETEXT_LEFT,"2.ПП-19'ВитЯзь'(Россия) %d\n0.Выход",cena[2]);}
	}
	if(pp19_buy2==true)
	{infoD->printf(0,570,HGETEXT_LEFT,"2.ПП-19'ВитЯзь'(Россия) %d\n0.Выход",cena[2]);
	galka->Render(330,584);}
	break;
	case 5: 
//AK-74	
	if(ak_buy2==false)
	{
	if(points2>=cena[0])
	{info->printf(0,550,HGETEXT_LEFT,"1.АК-74(СССР) %d\n",cena[0]);}
	else
	{infoR->printf(0,550,HGETEXT_LEFT,"1.АК-74(СССР) %d\n",cena[0]);}
	}
	if(ak_buy2==true&&ak_up2==false)
	{
	if(points2>=cena_up[1])
	{info->printf(0,550,HGETEXT_LEFT,"1.АК-74(СССР) upgrade %d\n",cena_up[1]);}
	if(points2<cena_up[1])
	{infoR->printf(0,550,HGETEXT_LEFT,"1.АК-74(СССР) upgrade %d\n",cena_up[1]);}
	}
	if(ak_buy2==true&&ak_up2==true)
	{infoD->printf(0,550,HGETEXT_LEFT,"1.АК-74(СССР) %d\n",cena[0]);
	galka->Render(330,564);}

//FN F2000
	if(fn_f2000_buy2==false)
	{
	if(points2>=cena[3])
	{info->printf(0,570,HGETEXT_LEFT,"2.FN_F2000(Бельгия) %d\n0.Выход",cena[3]);}
	else
	{infoR->printf(0,570,HGETEXT_LEFT,"2.FN_F2000(Бельгия) %d\n0.Выход",cena[3]);}
	}
	if(fn_f2000_buy2==true&&fn_f2000_up2==false)
	{
	if(points2>=cena_up[0])
	{info->printf(0,570,HGETEXT_LEFT,"2.FN_F2000(Бельгия) upgrade %d\n0.Выход",cena_up[0]);}
	if(points2<cena_up[0])
	{infoR->printf(0,570,HGETEXT_LEFT,"2.FN_F2000(Бельгия) upgrade %d\n0.Выход",cena_up[0]);}
	}
	if(fn_f2000_buy2==true&&fn_f2000_up2==true)
	{infoD->printf(0,570,HGETEXT_LEFT,"2.FN_F2000(Бельгия) %d\n0.Выход",cena[3]);
	galka->Render(330,584);}
	break;
	case 6:
	//RPK 47
	if(rpk47_buy2==false)
	{
	if(points2>=cena[8])	
	{info->printf(0,550,HGETEXT_LEFT,"1.РПК-74(СССР) %d\n",cena[8]);}
	else
	{infoR->printf(0,550,HGETEXT_LEFT,"1.РПК-74(СССР) %d\n",cena[8]);}
	}
	if(rpk47_buy2==true)
	{infoD->printf(0,550,HGETEXT_LEFT,"1.РПК-74(СССР) %d\n",cena[8]);
	galka->Render(330,564);}
		
		
//RPK
	if(rpk_buy2==false)
	{
	if(points2>=cena[5])	
	{info->printf(0,570,HGETEXT_LEFT,"2.РПК-74М(СССР) %d\n0.Выход",cena[5]);}
	else
	{infoR->printf(0,570,HGETEXT_LEFT,"2.РПК-74М(СССР) %d\n0.Выход",cena[5]);}
	}
	if(rpk_buy2==true)
	{infoD->printf(0,570,HGETEXT_LEFT,"2.РПК-74М(СССР) %d\n0.Выход",cena[5]);
	galka->Render(330,584);}
	break;


//РГД-5		
	case 7:
	if(rgd5_buy2==false)
	{
	if(points2>=cena[10])	
	{info->printf(0,550,HGETEXT_LEFT,"1.РГД-5(СССР) %d\n",cena[10]);}
	else
	{infoR->printf(0,550,HGETEXT_LEFT,"1.РГД-5(СССР) %d\n",cena[10]);}
	}
	if(rgd5_buy2==true)
	{infoD->printf(0,550,HGETEXT_LEFT,"1.РГД-5(СССР) %d\n",cena[10]);}
//MILKOR MGL
	if(milkor_buy2==false)
	{
	if(points2>=cena[12])	
	{info->printf(0,590,HGETEXT_LEFT,"3.Milkor MGL %d\n",cena[12]);}
	else
	{infoR->printf(0,590,HGETEXT_LEFT,"3.Milkor MGL %d\n",cena[12]);}
	}
	if(milkor_buy2==true)
	{infoD->printf(0,590,HGETEXT_LEFT,"3.Milkor MGL %d\n",cena[12]);
	galka->Render(330,604);}
//Panzerfaust 3
	if(panzer_buy2==false)
	{
	if(points2>=cena[13])	
	{info->printf(0,630,HGETEXT_LEFT,"5.Panzerfaust-3(Германия) %d\n0.Выход",cena[13]);}
	else
	{infoR->printf(0,630,HGETEXT_LEFT,"5.Panzerfaust-3(Германия) %d\n0.Выход",cena[13]);}
	}
	if(panzer_buy2==true)
	{infoD->printf(0,630,HGETEXT_LEFT,"5.Panzerfaust-3(Германия) %d\n0.Выход",cena[13]);
	galka->Render(330,644);}
	break;


	//катана
	case 9:
	if(katana_buy2==false)
	{
	if(points2>=cena[11])	
	{info->printf(0,570,HGETEXT_LEFT,"2.Катана(Япония) %d\n0.Выход",cena[11]);}
	else
	{infoR->printf(0,570,HGETEXT_LEFT,"2.Катана(Япония) %d\n0.Выход",cena[11]);}
	}
	if(katana_buy2==true)
	{infoD->printf(0,570,HGETEXT_LEFT,"2.Катана(Япония) %d\n0.Выход",cena[11]);
	galka->Render(330,584);}
	break;
   
	}


if(RPGMOD==true)
{


//выбор навыков игрока 1
if(lvl1_vibor==true)
{opit_okno_vibora->Render(600,450);
infoBR->printf(600,240,HGETEXT_CENTER,"Уровень %d",LVL1);

info->printf(600,320,HGETEXT_CENTER,"Осталось распределить");

if(opit_points1>=2&&opit_points1<=4)
{info->printf(430,340,HGETEXT_CENTER,"%d очка",opit_points1);}
if(opit_points1==0||opit_points1>4)
{info->printf(430,340,HGETEXT_CENTER,"%d очков",opit_points1);}
if(opit_points1==1)
{info->printf(430,340,HGETEXT_CENTER,"%d очко",opit_points1);}

//если есть очки х-к
if(opit_points1>0)
{
info->printf(430,380,HGETEXT_CENTER,"Характеристики:");
if(VIBOR_ITEM==1)
{
switch(VIBOR)
{
case 0:		
infoR->printf(350,400,HGETEXT_LEFT,"Атака: %d",attack1);
//infoR->printf(350,420,HGETEXT_LEFT,"Урон +атака*ур./2");
infoR->printf(350,440,HGETEXT_LEFT,"Скорость: %d",skorost1-100);
//infoR->printf(350,460,HGETEXT_LEFT,"Скорость +1%");
infoR->printf(350,480,HGETEXT_LEFT,"Удача: %d",luck1);
//infoR->printf(350,500,HGETEXT_LEFT,"Влияет на бонусы");
if(CLASSMOD==true)
{
switch(class1)	
{case 1:	
infoR->printf(350,520,HGETEXT_LEFT,"Мощь: %d",mosch1);
infoR->printf(350,560,HGETEXT_LEFT,"Приманка: %d",primanka1);
break;

case 2:	
infoR->printf(350,520,HGETEXT_LEFT,"Точность: %.0f",(0.8f-tochnost1)*100);
infoR->printf(350,560,HGETEXT_LEFT,"Построение: %d",postroenie1);
break;

case 3:	
infoR->printf(350,520,HGETEXT_LEFT,"Выносливость: %.0f",vinoslivost1-1);
infoR->printf(350,560,HGETEXT_LEFT,"Взрывчатка: %d",vzrivchatka1-5);
break;

case 4:	
infoR->printf(350,520,HGETEXT_LEFT,"Модификации: %d",modifikacii1);
infoR->printf(350,560,HGETEXT_LEFT,"Техника: %d",technika1);
break;}
}
break;

case 1:		
info->printf(350,400,HGETEXT_LEFT,"Атака: %d",attack1);
//info->printf(350,420,HGETEXT_LEFT,"Урон +атака*ур./2");
infoR->printf(350,440,HGETEXT_LEFT,"Скорость: %d",skorost1-100);
//infoR->printf(350,460,HGETEXT_LEFT,"Скорость +1%");
infoR->printf(350,480,HGETEXT_LEFT,"Удача: %d",luck1);
//infoR->printf(350,500,HGETEXT_LEFT,"Влияет на бонусы");
if(CLASSMOD==true)
{
switch(class1)	
{case 1:	
infoR->printf(350,520,HGETEXT_LEFT,"Мощь: %d",mosch1);
infoR->printf(350,560,HGETEXT_LEFT,"Приманка: %d",primanka1);
break;

case 2:	
infoR->printf(350,520,HGETEXT_LEFT,"Точность: %.0f",(0.8f-tochnost1)*100);
infoR->printf(350,560,HGETEXT_LEFT,"Построение: %d",postroenie1);
break;

case 3:	
infoR->printf(350,520,HGETEXT_LEFT,"Выносливость: %.0f",vinoslivost1-1);
infoR->printf(350,560,HGETEXT_LEFT,"Взрывчатка: %d",vzrivchatka1-5);
break;

case 4:	
infoR->printf(350,520,HGETEXT_LEFT,"Модификации: %d",modifikacii1);
infoR->printf(350,560,HGETEXT_LEFT,"Техника: %d",technika1);
break;}
}
break;

case 2:		
infoR->printf(350,400,HGETEXT_LEFT,"Атака: %d",attack1);
//infoR->printf(350,420,HGETEXT_LEFT,"Урон +атака*ур./2");
info->printf(350,440,HGETEXT_LEFT,"Скорость: %d",skorost1-100);
//info->printf(350,460,HGETEXT_LEFT,"Скорость +1%");
infoR->printf(350,480,HGETEXT_LEFT,"Удача: %d",luck1);
//infoR->printf(350,500,HGETEXT_LEFT,"Влияет на бонусы");
if(CLASSMOD==true)
{
switch(class1)	
{case 1:	
infoR->printf(350,520,HGETEXT_LEFT,"Мощь: %d",mosch1);
infoR->printf(350,560,HGETEXT_LEFT,"Приманка: %d",primanka1);
break;

case 2:	
infoR->printf(350,520,HGETEXT_LEFT,"Точность: %.0f",(0.8f-tochnost1)*100);
infoR->printf(350,560,HGETEXT_LEFT,"Построение: %d",postroenie1);
break;

case 3:	
infoR->printf(350,520,HGETEXT_LEFT,"Выносливость: %.0f",vinoslivost1-1);
infoR->printf(350,560,HGETEXT_LEFT,"Взрывчатка: %d",vzrivchatka1-5);
break;

case 4:	
infoR->printf(350,520,HGETEXT_LEFT,"Модификации: %d",modifikacii1);
infoR->printf(350,560,HGETEXT_LEFT,"Техника: %d",technika1);
break;}
}
break;

case 3:		
infoR->printf(350,400,HGETEXT_LEFT,"Атака: %d",attack1);
//infoR->printf(350,420,HGETEXT_LEFT,"Урон +атака*ур./2");
infoR->printf(350,440,HGETEXT_LEFT,"Скорость: %d",skorost1-100);
//infoR->printf(350,460,HGETEXT_LEFT,"Скорость +1%");
info->printf(350,480,HGETEXT_LEFT,"Удача: %d",luck1);
//info->printf(350,500,HGETEXT_LEFT,"Влияет на бонусы");
if(CLASSMOD==true)
{
switch(class1)	
{case 1:	
infoR->printf(350,520,HGETEXT_LEFT,"Мощь: %d",mosch1);
infoR->printf(350,560,HGETEXT_LEFT,"Приманка: %d",primanka1);
break;

case 2:	
infoR->printf(350,520,HGETEXT_LEFT,"Точность: %.0f",(0.8f-tochnost1)*100);
infoR->printf(350,560,HGETEXT_LEFT,"Построение: %d",postroenie1);
break;

case 3:	
infoR->printf(350,520,HGETEXT_LEFT,"Выносливость: %.0f",vinoslivost1-1);
infoR->printf(350,560,HGETEXT_LEFT,"Взрывчатка: %d",vzrivchatka1-5);
break;

case 4:	
infoR->printf(350,520,HGETEXT_LEFT,"Модификации: %d",modifikacii1);
infoR->printf(350,560,HGETEXT_LEFT,"Техника: %d",technika1);
break;}
}
break;

case 4:
infoR->printf(350,400,HGETEXT_LEFT,"Атака: %d",attack1);
//infoR->printf(350,420,HGETEXT_LEFT,"Урон +атака*ур./2");
infoR->printf(350,440,HGETEXT_LEFT,"Скорость: %d",skorost1-100);
//infoR->printf(350,460,HGETEXT_LEFT,"Скорость +1%");
infoR->printf(350,480,HGETEXT_LEFT,"Удача: %d",luck1);
//infoR->printf(350,500,HGETEXT_LEFT,"Влияет на бонусы");

if(CLASSMOD==true)
{
switch(class1)	
{case 1:	
info->printf(350,520,HGETEXT_LEFT,"Мощь: %d",mosch1);
infoR->printf(350,560,HGETEXT_LEFT,"Приманка: %d",primanka1);
break;

case 2:	
info->printf(350,520,HGETEXT_LEFT,"Точность: %.0f",(0.8f-tochnost1)*100);
infoR->printf(350,560,HGETEXT_LEFT,"Построение: %d",postroenie1);
break;

case 3:	
info->printf(350,520,HGETEXT_LEFT,"Выносливость: %.0f",vinoslivost1-1);
infoR->printf(350,560,HGETEXT_LEFT,"Взрывчатка: %d",vzrivchatka1-5);
break;

case 4:	
info->printf(350,520,HGETEXT_LEFT,"Модификации: %d",modifikacii1);
infoR->printf(350,560,HGETEXT_LEFT,"Техника: %d",technika1);
break;}}
break;

case 5:
infoR->printf(350,400,HGETEXT_LEFT,"Атака: %d",attack1);
//infoR->printf(350,420,HGETEXT_LEFT,"Урон +атака*ур./2");
infoR->printf(350,440,HGETEXT_LEFT,"Скорость: %d",skorost1-100);
//infoR->printf(350,460,HGETEXT_LEFT,"Скорость +1%");
infoR->printf(350,480,HGETEXT_LEFT,"Удача: %d",luck1);
//infoR->printf(350,500,HGETEXT_LEFT,"Влияет на бонусы");
if(CLASSMOD==true)
{
switch(class1)	
{case 1:	
infoR->printf(350,520,HGETEXT_LEFT,"Мощь: %d",mosch1);
info->printf(350,560,HGETEXT_LEFT,"Приманка: %d",primanka1);
break;

case 2:	
infoR->printf(350,520,HGETEXT_LEFT,"Точность: %.0f",(0.8f-tochnost1)*100);
info->printf(350,560,HGETEXT_LEFT,"Построение: %d",postroenie1);
break;

case 3:	
infoR->printf(350,520,HGETEXT_LEFT,"Выносливость: %.0f",vinoslivost1-1);
info->printf(350,560,HGETEXT_LEFT,"Взрывчатка: %d",vzrivchatka1-5);
break;

case 4:	
infoR->printf(350,520,HGETEXT_LEFT,"Модификации: %d",modifikacii1);
info->printf(350,560,HGETEXT_LEFT,"Техника: %d",technika1);
break;}}
break;

}
}
}//если есть очки х-к

if(opit_points1==0)
{infoD->printf(430,380,HGETEXT_CENTER,"Характеристики:");
infoD->printf(350,400,HGETEXT_LEFT,"Атака: %d",attack1);
//infoD->printf(350,420,HGETEXT_LEFT,"Урон +атака*ур./2");
infoD->printf(350,440,HGETEXT_LEFT,"Скорость: %d",skorost1-100);
//infoD->printf(350,460,HGETEXT_LEFT,"Скорость +1%");
infoD->printf(350,480,HGETEXT_LEFT,"Удача: %d",luck1);
//infoD->printf(350,500,HGETEXT_LEFT,"Влияет на бонусы");
if(CLASSMOD==true)
{
switch(class1)
{
case 1:
infoD->printf(350,520,HGETEXT_LEFT,"Мощь: %d",mosch1);
infoD->printf(350,560,HGETEXT_LEFT,"Приманка: %d",primanka1);
break;

case 2:	
infoD->printf(350,520,HGETEXT_LEFT,"Точность: %.0f",(0.8f-tochnost1)*100);
infoD->printf(350,560,HGETEXT_LEFT,"Построение: %d",postroenie1);
break;

case 3:	
infoD->printf(350,520,HGETEXT_LEFT,"Выносливость: %.0f",vinoslivost1-1);
infoD->printf(350,560,HGETEXT_LEFT,"Взрывчатка: %d",vzrivchatka1-5);
break;

case 4:	
infoD->printf(350,520,HGETEXT_LEFT,"Модификации: %d",modifikacii1);
infoD->printf(350,560,HGETEXT_LEFT,"Техника: %d",technika1);
break;

}}

}
//выбор характеристик


//НАВЫКИ
if(naviki_points1>=2&&naviki_points1<=4)
{info->printf(750,340,HGETEXT_CENTER,"%d очка",naviki_points1);}
if(naviki_points1==0||naviki_points1>4)
{info->printf(750,340,HGETEXT_CENTER,"%d очков",naviki_points1);}
if(naviki_points1==1)
{info->printf(750,340,HGETEXT_CENTER,"%d очко",naviki_points1);}



if(naviki_points1>0)
info->printf(750,380,HGETEXT_CENTER,"Навыки:");
if(naviki_points1<=0)
infoD->printf(750,380,HGETEXT_CENTER,"Навыки:");


if(VIBOR_ITEM==2)
{
switch(VIBOR)
{
case 1:
weapon1_fire_skill();
break;

default:	
break;
}
}




//ОПАСНОСТЕ!!!
info->printf(410,530,HGETEXT_LEFT,"Защита:");
if(LVL1%2==0)
{

if(attack1*LVL1/2-defence_zayac>=0)
{info->printf(410,550,HGETEXT_LEFT,"зайца %d ",defence_zayac);}
else
{infoR->printf(410,550,HGETEXT_LEFT,"зайца %d ",defence_zayac);}

if(attack1*LVL1/2-defence_volk>=0)
{info->printf(510,550,HGETEXT_LEFT,"волка %d ",defence_volk);}
else
{infoR->printf(510,550,HGETEXT_LEFT,"волка %d ",defence_volk);}

}
//-----
if(LVL1%2==1)
{

if(attack1*(LVL1-1)/2-defence_zayac>=0)
{info->printf(410,550,HGETEXT_LEFT,"зайца %d ",defence_zayac);}
else
{infoR->printf(410,550,HGETEXT_LEFT,"зайца %d ",defence_zayac);}

if(attack1*(LVL1-1)/2-defence_volk>=0)
{info->printf(510,550,HGETEXT_LEFT,"волка %d ",defence_volk);}
else
{infoR->printf(510,550,HGETEXT_LEFT,"волка %d ",defence_volk);}

}
//ОПАСНОСТЕ!!!


}//закрыте выбора игрока 1



//выбор навыков игрока 2
if(lvl2_vibor==true)
{opit_okno_vibora->Render(600,450);
infoBR->printf(600,240,HGETEXT_CENTER,"Уровень %d",LVL2);

info->printf(600,320,HGETEXT_CENTER,"Осталось распределить");

if(opit_points2>=2&&opit_points2<=4)
{info->printf(430,340,HGETEXT_CENTER,"%d очка",opit_points2);}
if(opit_points2==0||opit_points2>4)
{info->printf(430,340,HGETEXT_CENTER,"%d очков",opit_points2);}
if(opit_points2==1)
{info->printf(430,340,HGETEXT_CENTER,"%d очко",opit_points2);}

//если есть очки х-к
if(opit_points2>0)
{
info->printf(430,380,HGETEXT_CENTER,"Характеристики:");
if(VIBOR_ITEM==1)
{
switch(VIBOR)
{
case 0:		
infoR->printf(350,400,HGETEXT_LEFT,"Атака: %d",attack2);
//infoR->printf(350,420,HGETEXT_LEFT,"Урон +атака*ур./2");
infoR->printf(350,440,HGETEXT_LEFT,"Скорость: %d",skorost2-100);
//infoR->printf(350,460,HGETEXT_LEFT,"Скорость +1%");
infoR->printf(350,480,HGETEXT_LEFT,"Удача: %d",luck2);
//infoR->printf(350,500,HGETEXT_LEFT,"Влияет на бонусы");
if(CLASSMOD==true)
{
switch(class2)	
{case 1:	
infoR->printf(350,520,HGETEXT_LEFT,"Мощь: %d",mosch2);
infoR->printf(350,560,HGETEXT_LEFT,"Приманка: %d",primanka2);
break;

case 2:	
infoR->printf(350,520,HGETEXT_LEFT,"Точность: %.0f",(0.8f-tochnost2)*100);
infoR->printf(350,560,HGETEXT_LEFT,"Построение: %d",postroenie2);
break;

case 3:	
infoR->printf(350,520,HGETEXT_LEFT,"Выносливость: %.0f",vinoslivost2-1);
infoR->printf(350,560,HGETEXT_LEFT,"Взрывчатка: %d",vzrivchatka2-5);
break;

case 4:	
infoR->printf(350,520,HGETEXT_LEFT,"Модификации: %d",modifikacii2);
infoR->printf(350,560,HGETEXT_LEFT,"Техника: %d",technika2);
break;}}
break;

case 1:		
info->printf(350,400,HGETEXT_LEFT,"Атака: %d",attack2);
//info->printf(350,420,HGETEXT_LEFT,"Урон +атака*ур./2");
infoR->printf(350,440,HGETEXT_LEFT,"Скорость: %d",skorost2-100);
//infoR->printf(350,460,HGETEXT_LEFT,"Скорость +1%");
infoR->printf(350,480,HGETEXT_LEFT,"Удача: %d",luck2);
//infoR->printf(350,500,HGETEXT_LEFT,"Влияет на бонусы");
if(CLASSMOD==true)
{
switch(class2)	
{case 1:	
infoR->printf(350,520,HGETEXT_LEFT,"Мощь: %d",mosch2);
infoR->printf(350,560,HGETEXT_LEFT,"Приманка: %d",primanka2);
break;

case 2:	
infoR->printf(350,520,HGETEXT_LEFT,"Точность: %.0f",(0.8f-tochnost2)*100);
infoR->printf(350,560,HGETEXT_LEFT,"Построение: %d",postroenie2);
break;

case 3:	
infoR->printf(350,520,HGETEXT_LEFT,"Выносливость: %.0f",vinoslivost2-1);
infoR->printf(350,560,HGETEXT_LEFT,"Взрывчатка: %d",vzrivchatka2-5);
break;

case 4:	
infoR->printf(350,520,HGETEXT_LEFT,"Модификации: %d",modifikacii2);
infoR->printf(350,560,HGETEXT_LEFT,"Техника: %d",technika2);
break;

default:
break;}
}
break;

case 2:		
infoR->printf(350,400,HGETEXT_LEFT,"Атака: %d",attack2);
//infoR->printf(350,420,HGETEXT_LEFT,"Урон +атака*ур./2");
info->printf(350,440,HGETEXT_LEFT,"Скорость: %d",skorost2-100);
//info->printf(350,460,HGETEXT_LEFT,"Скорость +1%");
infoR->printf(350,480,HGETEXT_LEFT,"Удача: %d",luck2);
//infoR->printf(350,500,HGETEXT_LEFT,"Влияет на бонусы");
if(CLASSMOD==true)
{
switch(class2)	
{case 1:	
infoR->printf(350,520,HGETEXT_LEFT,"Мощь: %d",mosch2);
infoR->printf(350,560,HGETEXT_LEFT,"Приманка: %d",primanka2);
break;

case 2:	
infoR->printf(350,520,HGETEXT_LEFT,"Точность: %.0f",(0.8f-tochnost2)*100);
infoR->printf(350,560,HGETEXT_LEFT,"Построение: %d",postroenie2);
break;

case 3:	
infoR->printf(350,520,HGETEXT_LEFT,"Выносливость: %.0f",vinoslivost2-1);
infoR->printf(350,560,HGETEXT_LEFT,"Взрывчатка: %d",vzrivchatka2-5);
break;

case 4:	
infoR->printf(350,520,HGETEXT_LEFT,"Модификации: %d",modifikacii2);
infoR->printf(350,560,HGETEXT_LEFT,"Техника: %d",technika2);
break;

default:
break;}
}
break;

case 3:		
infoR->printf(350,400,HGETEXT_LEFT,"Атака: %d",attack2);
//infoR->printf(350,420,HGETEXT_LEFT,"Урон +атака*ур./2");
infoR->printf(350,440,HGETEXT_LEFT,"Скорость: %d",skorost2-100);
//infoR->printf(350,460,HGETEXT_LEFT,"Скорость +1%");
info->printf(350,480,HGETEXT_LEFT,"Удача: %d",luck2);
//info->printf(350,500,HGETEXT_LEFT,"Влияет на бонусы");
if(CLASSMOD==true)
{
switch(class2)	
{case 1:	
infoR->printf(350,520,HGETEXT_LEFT,"Мощь: %d",mosch2);
infoR->printf(350,560,HGETEXT_LEFT,"Приманка: %d",primanka2);
break;

case 2:	
infoR->printf(350,520,HGETEXT_LEFT,"Точность: %.0f",(0.8f-tochnost2)*100);
infoR->printf(350,560,HGETEXT_LEFT,"Построение: %d",postroenie2);
break;

case 3:	
infoR->printf(350,520,HGETEXT_LEFT,"Выносливость: %.0f",vinoslivost2-1);
infoR->printf(350,560,HGETEXT_LEFT,"Взрывчатка: %d",vzrivchatka2-5);
break;

case 4:	
infoR->printf(350,520,HGETEXT_LEFT,"Модификации: %d",modifikacii2);
infoR->printf(350,560,HGETEXT_LEFT,"Техника: %d",technika2);
break;

default:
break;}
}
break;

case 4:
infoR->printf(350,400,HGETEXT_LEFT,"Атака: %d",attack2);
//infoR->printf(350,420,HGETEXT_LEFT,"Урон +атака*ур./2");
infoR->printf(350,440,HGETEXT_LEFT,"Скорость: %d",skorost2-100);
//infoR->printf(350,460,HGETEXT_LEFT,"Скорость +1%");
infoR->printf(350,480,HGETEXT_LEFT,"Удача: %d",luck2);
//infoR->printf(350,500,HGETEXT_LEFT,"Влияет на бонусы");

if(CLASSMOD==true)
{
switch(class2)	
{case 1:	
info->printf(350,520,HGETEXT_LEFT,"Мощь: %d",mosch2);
infoR->printf(350,560,HGETEXT_LEFT,"Приманка: %d",primanka2);
break;

case 2:	
info->printf(350,520,HGETEXT_LEFT,"Точность: %.0f",(0.8f-tochnost2)*100);
infoR->printf(350,560,HGETEXT_LEFT,"Построение: %d",postroenie2);
break;

case 3:	
info->printf(350,520,HGETEXT_LEFT,"Выносливость: %.0f",vinoslivost2-1);
infoR->printf(350,560,HGETEXT_LEFT,"Взрывчатка: %d",vzrivchatka2-5);
break;

case 4:	
info->printf(350,520,HGETEXT_LEFT,"Модификации: %d",modifikacii2);
infoR->printf(350,560,HGETEXT_LEFT,"Техника: %d",technika2);
break;}}
break;

case 5:
infoR->printf(350,400,HGETEXT_LEFT,"Атака: %d",attack2);
//infoR->printf(350,420,HGETEXT_LEFT,"Урон +атака*ур./2");
infoR->printf(350,440,HGETEXT_LEFT,"Скорость: %d",skorost2-100);
//infoR->printf(350,460,HGETEXT_LEFT,"Скорость +1%");
infoR->printf(350,480,HGETEXT_LEFT,"Удача: %d",luck2);
//infoR->printf(350,500,HGETEXT_LEFT,"Влияет на бонусы");
if(CLASSMOD==true)
{
switch(class2)	
{case 1:	
infoR->printf(350,520,HGETEXT_LEFT,"Мощь: %d",mosch2);
info->printf(350,560,HGETEXT_LEFT,"Приманка: %d",primanka2);
break;

case 2:	
infoR->printf(350,520,HGETEXT_LEFT,"Точность: %.0f",(0.8f-tochnost2)*100);
info->printf(350,560,HGETEXT_LEFT,"Построение: %d",postroenie2);
break;

case 3:	
infoR->printf(350,520,HGETEXT_LEFT,"Выносливость: %.0f",vinoslivost2-1);
info->printf(350,560,HGETEXT_LEFT,"Взрывчатка: %d",vzrivchatka2-5);
break;

case 4:	
infoR->printf(350,520,HGETEXT_LEFT,"Модификации: %d",modifikacii2);
info->printf(350,560,HGETEXT_LEFT,"Техника: %d",technika2);
break;}}
break;

}
}
}//если есть очки х-к

if(opit_points2==0)
{infoD->printf(430,380,HGETEXT_CENTER,"Характеристики:");
infoD->printf(350,400,HGETEXT_LEFT,"Атака: %d",attack2);
//infoD->printf(350,420,HGETEXT_LEFT,"Урон +атака*ур./2");
infoD->printf(350,440,HGETEXT_LEFT,"Скорость: %d",skorost2-100);
//infoD->printf(350,460,HGETEXT_LEFT,"Скорость +1%");
infoD->printf(350,480,HGETEXT_LEFT,"Удача: %d",luck2);
//infoD->printf(350,500,HGETEXT_LEFT,"Влияет на бонусы");
if(CLASSMOD==true)
{
switch(class2)
{
case 1:
infoD->printf(350,520,HGETEXT_LEFT,"Мощь: %d",mosch2);
infoD->printf(350,560,HGETEXT_LEFT,"Приманка: %d",primanka2);
break;

case 2:	
infoD->printf(350,520,HGETEXT_LEFT,"Точность: %.0f",(0.8f-tochnost2)*100);
infoD->printf(350,560,HGETEXT_LEFT,"Построение: %d",postroenie2);
break;

case 3:	
infoD->printf(350,520,HGETEXT_LEFT,"Выносливость: %.0f",vinoslivost2-1);
infoD->printf(350,560,HGETEXT_LEFT,"Взрывчатка: %d",vzrivchatka2-5);
break;

case 4:	
infoD->printf(350,520,HGETEXT_LEFT,"Модификации: %d",modifikacii2);
infoD->printf(350,560,HGETEXT_LEFT,"Техника: %d",technika2);
break;

default:
break;

}}

}
//выбор характеристик


//НАВЫКИ
if(naviki_points2>=2&&naviki_points2<=4)
{info->printf(750,340,HGETEXT_CENTER,"%d очка",naviki_points2);}
if(naviki_points2==0||naviki_points2>4)
{info->printf(750,340,HGETEXT_CENTER,"%d очков",naviki_points2);}
if(naviki_points2==1)
{info->printf(750,340,HGETEXT_CENTER,"%d очко",naviki_points2);}



if(naviki_points2>0)
info->printf(750,380,HGETEXT_CENTER,"Навыки:");
if(naviki_points2<=0)
infoD->printf(750,380,HGETEXT_CENTER,"Навыки:");


if(VIBOR_ITEM==2)
{
switch(VIBOR)
{
case 1:
weapon1_fire_skill();
break;

default:	
break;
}
}




//ОПАСНОСТЕ!!!
info->printf(410,530,HGETEXT_LEFT,"Защита:");
if(LVL2%2==0)
{

if(attack2*LVL2/2-defence_zayac>=0)
{info->printf(410,550,HGETEXT_LEFT,"зайца %d ",defence_zayac);}
else
{infoR->printf(410,550,HGETEXT_LEFT,"зайца %d ",defence_zayac);}

if(attack2*LVL2/2-defence_volk>=0)
{info->printf(510,550,HGETEXT_LEFT,"волка %d ",defence_volk);}
else
{infoR->printf(510,550,HGETEXT_LEFT,"волка %d ",defence_volk);}

}
//-----
if(LVL2%2==1)
{

if(attack2*(LVL2-1)/2-defence_zayac>=0)
{info->printf(410,550,HGETEXT_LEFT,"зайца %d ",defence_zayac);}
else
{infoR->printf(410,550,HGETEXT_LEFT,"зайца %d ",defence_zayac);}

if(attack2*(LVL2-1)/2-defence_volk>=0)
{info->printf(510,550,HGETEXT_LEFT,"волка %d ",defence_volk);}
else
{infoR->printf(510,550,HGETEXT_LEFT,"волка %d ",defence_volk);}

}
//ОПАСНОСТЕ!!!


}//закрыте выбора игрока 2



}//if RPGMOD==TRUE


if(DIFF==0)
{okno_lvl_progress_green->Render(600,800);}
if(DIFF==1)
{okno_lvl_progress->Render(600,800);}
if(DIFF==2)
{okno_lvl_progress_red->Render(600,800);}


if(player2_aktive==0)
{
if(890-(X+1200-x)/16>=305)
{okno_lvl_polzunok->Render(895-(X+1200-x)/16,800);}
else
{okno_lvl_polzunok->Render(305,800);}
}
if(player2_aktive==1)
{
if(890-(X+1200-((x+x2)/2))/16>=305)
{okno_lvl_polzunok->Render(895-(X+1200-((x+x2)/2))/16,800);}
else
{okno_lvl_polzunok->Render(305,800);}
}


} //if menu_aktive=0


if(menu_aktive==1)// МЕНЮ ИГРЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫ
{menu->Render();}

if(menu_aktive==-1)//выбор игроков
{menu_start->Render();}


//ОПЦИИ
if(menu_aktive==2)
{
if(player2_aktive==0)
{info->printf(600,100,HGETEXT_CENTER,"1 ИГРОК\nРАЗРЕШЕНИЕ:1200х900");}
if(player2_aktive==1)
{info->printf(600,100,HGETEXT_CENTER,"2 ИГРОКА\nРАЗРЕШЕНИЕ:1200х900");}

menu_font->printf(600,380,HGETEXT_CENTER,"RPGMOD");

menu_font->printf(600,240,HGETEXT_CENTER,"CИСТЕМА КЛАССОВ");

if(RPGMOD==true)
{info->printf(600,440,HGETEXT_CENTER,"Если не переносите задротства,\nто можете выключить");
galka_menu->Render(780,520);}
if(RPGMOD==false)
{info->printf(600,440,HGETEXT_CENTER,"Если любите задротство,\nто можете включить");
galka_menu->Render(800,560);}
if(CLASSMOD==true)
{galka_menu->Render(900,300);}
if(CLASSMOD==false)
{galka_menu->Render(920,340);}

if(menu_video->GetFocus()==5)
{info->printf(600,630,HGETEXT_CENTER,"%d",volume);
if((hge->Input_GetKeyState(HGEK_LEFT)==true||hge->Input_GetKeyState(HGEK_D))&&volume>0)
{volume--;}
if((hge->Input_GetKeyState(HGEK_RIGHT)==true||hge->Input_GetKeyState(HGEK_A))&&volume<100)
{volume++;}
if(volume==0)
{strelka_menu->SetTexture(strelka_menu_D_tex);}
if(volume>0)
{strelka_menu->SetTexture(strelka_menu_tex);}
strelka_menu->Render(550,650);
if(volume==100)
{strelka_menu->SetTexture(strelka_menu_D_tex);}
if(volume<100)
{strelka_menu->SetTexture(strelka_menu_tex);}
strelka_menu->RenderStretch(675,625,625,675);
}

menu_video->Render();
}
//ОПЦИИ


if(menu_aktive==3)
{menu_info->Render();}
if(menu_aktive==4)//авторы
{info->printf(600,300,HGETEXT_CENTER,"ПРОГРАММИРОВАНИЕ:\nСирант Андрей aka Ан147\nГРАФИКА:\nСирант Андрей aka Ан147\nЗВУК:\nСирант Андрей aka Ан147\nПольдЯев Андрей aka Шустрый\nТЕСТЕРЫ:\nДмитрий Кашуба aka Airyng\nСирант Андрей aka Ан147");}


if(menu_aktive==31)//инфа про врагов
{zayac->Render(600,250);
info->printf(600,300,HGETEXT_CENTER,"ЗАЙЦЫ\nЗдоровье:50\nБонус про попадании в голову\n(область между ушами и глазами):2Х\nПримечания:Могут отваливаться уши");}


if(menu_aktive==32)//инфа про ружбайки
{info->printf(600,50,HGETEXT_CENTER,"ПИСТОЛЕТЫ");
info->printf(50,120,HGETEXT_LEFT,"ПМ(Пистолет Макарова)");
pm->RenderStretch(150,140,200,180);
info->printf(50,200,HGETEXT_LEFT,"Урон: 20\nКол-во патронов в магазине: 8\nСкорость перезарядки: 1 сек.\nСтоимость: Бесплатно\nСтрана производитель: СССР\nТочность:\n-=расстояние=-                -=рандом=-\nот 200 до 400 пикселей - 6 пикселей\nболее 400                     - 12 пикселей\nПримечание: Стартовое оружие");
info->printf(450,120,HGETEXT_LEFT,"ТТ(Тульский Токарев)");
tt->RenderStretch(510,140,574,185);
info->printf(450,200,HGETEXT_LEFT,"Урон: 30\nКол-во патронов в магазине: 8\nСкорость перезарядки: 1 сек.\nСтоимость: 500\nСтрана производитель: СССР\nТочность:\n-=расстояние=-                -=рандом=-\nот 250 до 500 пикселей - 5,5 пикселей\nболее 500                     - 11 пикселей\nПримечание: Дешёвый");
info->printf(600,450,HGETEXT_CENTER,"АВТОМАТЫ");
info->printf(50,520,HGETEXT_LEFT,"АК(Автомат Калашникова)");
ak47->RenderStretch(115,540,245,585);
info->printf(50,605,HGETEXT_LEFT,"Урон: 70\nКол-во патронов в магазине: 30\nСкорость перезарядки: 2 сек.\nСтоимость: 5500\nСтрана производитель: СССР\nТочность:\n-=расстояние=-                -=рандом=-\nот 400 до 600 пикселей - 5 пикселей\nболее 600                     - 8,5 пикселей\nПримечание: Мощный патрон");
}


if(menu_aktive==33)//инфа про бонусы
{
info->printf(600,50,HGETEXT_CENTER,"ПОЛОЖИТЕЛЬНЫЕ");
info->printf(150,120,HGETEXT_LEFT,"Шило");
bonus_shilo->RenderStretch(160,160,190,190);
info->printf(150,210,HGETEXT_LEFT,"Эффект:Скорость увеличивается\nна 10 процентов от стартовой скорости.\nЭффекты суммируются. Эффект длитсЯ 10 секунд.");

}



if(menu_aktive==-2)
{info->printf(600,250,HGETEXT_CENTER,"ТОЧНО?");
menu_really->Render();}

if(menu_aktive==-3)
{
menu_font->printf(600,200,HGETEXT_CENTER,"ВЫБОР ИГРОКА 1");
menu_class->Render();
znak_myasnik->Render(400,330);
znak_myasnik->Render(800,330);
znak_strelok->Render(400,430);
znak_strelok->Render(800,430);
znak_razrushitel->Render(400,530);
znak_razrushitel->Render(800,530);
znak_tehnik->Render(400,630);
znak_tehnik->Render(800,630);

}

if(menu_aktive==-4)
{
menu_font->printf(600,200,HGETEXT_CENTER,"ВЫБОР ИГРОКА 2");	
menu_class2->Render();
znak_myasnik->Render(400,330);
znak_myasnik->Render(800,330);
znak_strelok->Render(400,430);
znak_strelok->Render(800,430);
znak_razrushitel->Render(400,530);
znak_razrushitel->Render(800,530);
znak_tehnik->Render(400,630);
znak_tehnik->Render(800,630);

}

//статистика
if(menu_aktive==-5)
{
if(player2_aktive==0)
{
info->printf(600,200,HGETEXT_CENTER,"В ОБЩЕМ:");
//время игры
if(pobeda==true)
{
if(perez_akt<10&leveltime<10)
{info->printf(600,220,HGETEXT_CENTER,"Время пройденной игры: 0%d:0%d",leveltime,perez_akt);}
if(perez_akt<10&leveltime>=10)
{info->printf(600,220,HGETEXT_CENTER,"Время пройденной игры: %d:0%d",leveltime,perez_akt);}
if(perez_akt>=10&&leveltime<10)
{info->printf(600,220,HGETEXT_CENTER,"Время пройденной игры: 0%d:%d",leveltime,perez_akt);}
if(perez_akt>=10&&leveltime>=10)
{info->printf(600,220,HGETEXT_CENTER,"Время пройденной игры: %d:%d",leveltime,perez_akt);}
}

if(pobeda!=true)
{
if(perez_akt<10&leveltime<10)
{info->printf(600,220,HGETEXT_CENTER,"Вы продержались: 0%d:0%d",leveltime,perez_akt);}
if(perez_akt<10&leveltime>=10)
{info->printf(600,220,HGETEXT_CENTER,"Вы продержались: %d:0%d",leveltime,perez_akt);}
if(perez_akt>=10&&leveltime<10)
{info->printf(600,220,HGETEXT_CENTER,"Вы продержались: 0%d:%d",leveltime,perez_akt);}
if(perez_akt>=10&&leveltime>=10)
{info->printf(600,220,HGETEXT_CENTER,"Вы продержались: %d:%d",leveltime,perez_akt);}
}

info->printf(600,240,HGETEXT_CENTER,"Набрано очков:%d",points1);
info->printf(600,260,HGETEXT_CENTER,"Всего убито:%d",kills);
info->printf(600,280,HGETEXT_CENTER,"В ТОМ ЧИСЛЕ:");
info->printf(600,300,HGETEXT_CENTER,"Зайцев:%d",kills_zayac);
info->printf(600,320,HGETEXT_CENTER,"Волков:%d",kills_volk);
info->printf(600,340,HGETEXT_CENTER,"Медведей:%d",kills_medved);

info->printf(50,300,HGETEXT_LEFT,"ЗАЙЦЫ:");
info->printf(50,320,HGETEXT_LEFT,"Оторвано ушей:%d (%.2f%%)",kills_zayac_bezuh,procent_kills_zayac_bezuh);
info->printf(50,340,HGETEXT_LEFT,"Оторвано бошек:%d (%.2f%%)",kills_zayac_bezboshki,procent_kills_zayac_bezboshki);
info->printf(50,360,HGETEXT_LEFT,"Разорвано в ЩИ:%d (%.2f%%)",kills_zayac_vschiii,procent_kills_zayac_vschiii);

}

if(player2_aktive==1)
{
info->printf(600,200,HGETEXT_CENTER,"В ОБЩЕМ:");

if(pobeda==true)
{
if(perez_akt<10&leveltime<10)
{info->printf(600,220,HGETEXT_CENTER,"Время пройденной игры: 0%d:0%d",leveltime,perez_akt);}
if(perez_akt<10&leveltime>=10)
{info->printf(600,220,HGETEXT_CENTER,"Время пройденной игры: %d:0%d",leveltime,perez_akt);}
if(perez_akt>=10&&leveltime<10)
{info->printf(600,220,HGETEXT_CENTER,"Время пройденной игры: 0%d:%d",leveltime,perez_akt);}
if(perez_akt>=10&&leveltime>=10)
{info->printf(600,220,HGETEXT_CENTER,"Время пройденной игры: %d:%d",leveltime,perez_akt);}
}

if(pobeda!=true)
{
if(perez_akt<10&leveltime<10)
{info->printf(600,220,HGETEXT_CENTER,"Вы продержались: 0%d:0%d",leveltime,perez_akt);}
if(perez_akt<10&leveltime>=10)
{info->printf(600,220,HGETEXT_CENTER,"Вы продержались: %d:0%d",leveltime,perez_akt);}
if(perez_akt>=10&&leveltime<10)
{info->printf(600,220,HGETEXT_CENTER,"Вы продержались: 0%d:%d",leveltime,perez_akt);}
if(perez_akt>=10&&leveltime>=10)
{info->printf(600,220,HGETEXT_CENTER,"Вы продержались: %d:%d",leveltime,perez_akt);}
}

info->printf(600,240,HGETEXT_CENTER,"Набрано очков:%d",points1+points2);
info->printf(600,260,HGETEXT_CENTER,"Всего убито:%d",kills+kills2);
info->printf(600,280,HGETEXT_CENTER,"В ТОМ ЧИСЛЕ:");
info->printf(600,300,HGETEXT_CENTER,"Зайцев:%d",kills_zayac+kills2_zayac);
info->printf(600,320,HGETEXT_CENTER,"Волков:%d",kills_volk+kills2_volk);
info->printf(600,340,HGETEXT_CENTER,"Медведей:%d",kills_medved+kills2_medved);

info->printf(50,200,HGETEXT_LEFT,"ИГРОК 1");
info->printf(50,220,HGETEXT_LEFT,"Набрал очков:%d",points1);
info->printf(50,240,HGETEXT_LEFT,"Врагов убил:%d",kills);
info->printf(50,280,HGETEXT_LEFT,"Зайцев:%d",kills_zayac);
info->printf(50,300,HGETEXT_LEFT,"Волков:%d",kills_volk);
info->printf(50,320,HGETEXT_LEFT,"Медведей:%d",kills_medved);
info->printf(50,340,HGETEXT_LEFT,"ЗАЙЦЫ:");
info->printf(50,360,HGETEXT_LEFT,"Оторвано ушей:%d (%.2f%%)",kills_zayac_bezuh,procent_kills_zayac_bezuh);
info->printf(50,380,HGETEXT_LEFT,"Оторвано бошек:%d (%.2f%%)",kills_zayac_bezboshki,procent_kills_zayac_bezboshki);
info->printf(50,400,HGETEXT_LEFT,"Разорвано в ЩИ:%d (%.2f%%)",kills_zayac_vschiii,procent_kills_zayac_vschiii);

info->printf(1150,200,HGETEXT_RIGHT,"ИГРОК 2");
info->printf(1150,220,HGETEXT_RIGHT,"Набрал очков:%d",points2);
info->printf(1150,240,HGETEXT_RIGHT,"Врагов убил:%d",kills2);
info->printf(1150,280,HGETEXT_RIGHT,"Зайцев:%d",kills2_zayac);
info->printf(1150,300,HGETEXT_RIGHT,"Волков:%d",kills2_volk);
info->printf(1150,320,HGETEXT_RIGHT,"Медведей:%d",kills2_medved);
info->printf(1150,340,HGETEXT_RIGHT,"ЗАЙЦЫ:");
info->printf(1150,360,HGETEXT_RIGHT,"Оторвано ушей:%d (%.2f%%)",kills2_zayac_bezuh,procent_kills2_zayac_bezuh);
info->printf(1150,380,HGETEXT_RIGHT,"Оторвано бошек:%d (%.2f%%)",kills2_zayac_bezboshki,procent_kills2_zayac_bezboshki);
info->printf(1150,400,HGETEXT_RIGHT,"Разорвано в ЩИ:%d (%.2f%%)",kills2_zayac_vschiii,procent_kills2_zayac_vschiii);

}

//выход
info->printf(50,850,HGETEXT_LEFT,"ДлЯ вЫхоДа нАжМитЕ Esc");
}//статистика
/*
for(int iief=0;iief<=N_PTENEC;iief++)
{
if(vragi4Objects[iief].polet==1)
{
rgd5->RenderEx(vragi4Objects[iief].rx,vragi4Objects[iief].ry,0,1,0);
info->printf(vragi4Objects[iief].rx,vragi4Objects[iief].ry,HGETEXT_CENTER,"rx %.0f",vragi4Objects[iief].rx);
info->printf(vragi4Objects[iief].rx,vragi4Objects[iief].ry+15,HGETEXT_CENTER,"ry %.0f",vragi4Objects[iief].ry);
info->printf(vragi4Objects[iief].rx,vragi4Objects[iief].ry+30,HGETEXT_CENTER,"v4x %.0f",vragi4Objects[iief].v4x);
info->printf(vragi4Objects[iief].rx,vragi4Objects[iief].ry+45,HGETEXT_CENTER,"v4y %.0f",vragi4Objects[iief].v4y);
info->printf(vragi4Objects[iief].rx,vragi4Objects[iief].ry+60,HGETEXT_CENTER,"r %.0f",vragi4Objects[iief].r);
info->printf(vragi4Objects[iief].rx,vragi4Objects[iief].ry+75,HGETEXT_CENTER,"up %d",vragi4Objects[iief].up);
}
}
*/
if(net_user!=0||srvr==true||clnt==true)
{//info->printf(50,800,HGETEXT_LEFT,"%d",In);
if(n_ip==0)
{info->printf(300,830,HGETEXT_CENTER,"%d.",(int)ip[0]);}
else
{infoR->printf(300,830,HGETEXT_CENTER,"%d.",(int)ip[0]);}
if(n_ip==1)
{info->printf(350,830,HGETEXT_CENTER,"%d.",(int)ip[1]);}
else
{infoR->printf(350,830,HGETEXT_CENTER,"%d.",(int)ip[1]);}
if(n_ip==2)
{info->printf(400,830,HGETEXT_CENTER,"%d.",(int)ip[2]);}
else
{infoR->printf(400,830,HGETEXT_CENTER,"%d.",(int)ip[2]);}
if(n_ip==3)
{info->printf(450,830,HGETEXT_CENTER,"%d",(int)ip[3]);}
else
{infoR->printf(450,830,HGETEXT_CENTER,"%d",(int)ip[3]);}
info->printf(50,850,HGETEXT_LEFT,"Сервер:%s,порт %d\n", inet_ntoa(server.sin_addr), htons(server.sin_port));
info->printf(50,870,HGETEXT_LEFT,"Клиент:%s,порт %d\n", inet_ntoa(client[0].sin_addr), htons(client[0].sin_port));
info->printf(50,830,HGETEXT_LEFT,"%s",net_status);
info->printf(600,200,HGETEXT_CENTER,"%d",received);}

//info->printf(600,200,HGETEXT_CENTER,"%.0f",speed);
//info->printf(660,300,HGETEXT_CENTER,"%.3f",blood_ssit_psi->info.fSpeedMax);
//info->printf(720,300,HGETEXT_CENTER,"%.3f",blood_ssit_psi->info.fParticleLifeMin);
if(menu_aktive==0)
{
if(LIVES>0&&pobeda==false)
{info->printf(600,820,HGETEXT_CENTER,"%d",LIVES);}
if(LIVES==0&&pobeda==false)
{infoD->printf(600,820,HGETEXT_CENTER,"%d",LIVES);
 info->printf(600,840,HGETEXT_CENTER,"Без права на ошибку");}
if(LIVES<0&&pobeda==false)
{infoR->printf(600,450,HGETEXT_CENTER,"Игра проиграна");}
if(pobeda==true)
{info->printf(600,450,HGETEXT_CENTER,"Победа!!!");}
}

if(TEST_REZHIM==true)
{info->printf(50,860,HGETEXT_LEFT,"Тестовый режим");}

	// End rendering and update the screen
	hge->Gfx_EndScene();


	// RenderFunc should always return false
	return false;
}

//-----------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// Get HGE interface
	hge = hgeCreate(HGE_VERSION);

	// Set up log file, frame function, render function and window title
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_FOCUSGAINFUNC, FocusGainFunc);
	hge->System_SetState(HGE_TITLE, "ЩИ!!! Версия 0.1.9");

	// Set up video mode
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH, 1200);
	hge->System_SetState(HGE_SCREENHEIGHT, 900);
	hge->System_SetState(HGE_SCREENBPP, 32);
	hge->System_SetState(HGE_FPS, 150);	

	main_window_handle = hge->System_GetState(HGE_HWND);

WNDCLASSEX winclass; // this will hold the class we create





	blood_tar=0;
	blood_target=0;

	if(hge->System_Initiate())
	{
		
        ak_tex=hge->Random_Int(0,1);
		ak2_tex=hge->Random_Int(0,1);

	
        oboima_text=new hgeFont("Data/myfont.fnt");
		info= new hgeFont("Data/game_font_rus.fnt");
		infoR= new hgeFont("Data/game_font_red_rus.fnt");
		infoD= new hgeFont("Data/game_font_dark_rus.fnt");
		infoBR= new hgeFont("Data/game_font_red_lvl_rus.fnt");
		infoBR->SetScale(1.2f);


		menu_font= new hgeFont("Data/menu_font.fnt");
		
		// Load sound and texture

		menu_sound=hge->Effect_Load("Zvuki/menu.wav");
		menu_choose=hge->Effect_Load("Zvuki/menu_vibor.mp3");
		//звуки выстрелов и перезарядки
		snd=hge->Effect_Load("Zvuki/pushki/ak_1.wav");
		pm_fire=hge->Effect_Load("Zvuki/pushki/pm_1.wav");
		pp19_fire=hge->Effect_Load("Zvuki/pushki/pp19_vityaz_1.wav");
		ak_reload1=hge->Effect_Load("Zvuki/pushki/ak_reload1.wav");
		ak_reload2=hge->Effect_Load("Zvuki/pushki/ak_reload2.wav");
		pm_reload1=hge->Effect_Load("Zvuki/pushki/pm_reload1.wav");
        pm_reload2=hge->Effect_Load("Zvuki/pushki/pm_reload2.wav");
        pp19_reload1=hge->Effect_Load("Zvuki/pushki/pp19_reload1.wav");
		pp19_reload2=hge->Effect_Load("Zvuki/pushki/pp19_reload2.wav");
		fn_f2000_fire=hge->Effect_Load("Zvuki/pushki/FN_F2000_1.mp3");
		tt_fire=hge->Effect_Load("Zvuki/pushki/TT_1.mp3");
		mac_fire=hge->Effect_Load("Zvuki/pushki/MAC_1.mp3");
		mac_reload1=hge->Effect_Load("Zvuki/pushki/MAC_reload1.mp3");
		mac_reload2=hge->Effect_Load("Zvuki/pushki/MAC_reload2.mp3");
		webley_fire=hge->Effect_Load("Zvuki/pushki/webley_1.mp3");
		webley_reload1=hge->Effect_Load("Zvuki/pushki/webley_reload1.mp3");
		webley_reload2=hge->Effect_Load("Zvuki/pushki/webley_reload2.mp3");
		fn_five_seven_fire=hge->Effect_Load("Zvuki/pushki/fiveseven_1.mp3");
		milkor_fire=hge->Effect_Load("Zvuki/pushki/milkor_1.mp3");
		winch_fire=hge->Effect_Load("Zvuki/pushki/winchester_1.wav");
		rocket_fire=hge->Effect_Load("Zvuki/pushki/rocket_fire.mp3");
		rocket2_fire=hge->Effect_Load("Zvuki/pushki/rocket_fire.mp3");
		rocket_polet=hge->Effect_Load("Zvuki/pushki/rocket_polet.mp3");
		rocket2_polet=hge->Effect_Load("Zvuki/pushki/rocket_polet.mp3");

		drob_reload1=hge->Effect_Load("Zvuki/pushki/drob_reload1.wav");
		drob_pompa=hge->Effect_Load("Zvuki/pushki/drob_pompa.wav");

		vzriv_grena1=hge->Effect_Load("Zvuki/pushki/vzriv_grena.wav");

		

		//мясо
		shot1=hge->Effect_Load("Zvuki/myaso/shot1.wav");
		headshot1=hge->Effect_Load("Zvuki/myaso/headshot1.mp3");
		headshot2=hge->Effect_Load("Zvuki/myaso/headshot2.mp3");
		headshot3=hge->Effect_Load("Zvuki/myaso/headshot3.mp3");
		headshot4=hge->Effect_Load("Zvuki/myaso/headshot4.mp3");
		headshot5=hge->Effect_Load("Zvuki/myaso/headshot5.mp3");
		headshot6=hge->Effect_Load("Zvuki/myaso/headshot6.mp3");
		headshot7=hge->Effect_Load("Zvuki/myaso/headshot7.mp3");
		headshot8=hge->Effect_Load("Zvuki/myaso/headshot8.mp3");
		myaso_upalo1=hge->Effect_Load("Zvuki/myaso/myaso_kusok_upal1.mp3");
		myaso_upalo2=hge->Effect_Load("Zvuki/myaso/myaso_kusok_upal2.mp3");
		myaso_upalo3=hge->Effect_Load("Zvuki/myaso/myaso_kusok_upal3.mp3");
		myaso_upalo4=hge->Effect_Load("Zvuki/myaso/myaso_kusok_upal4.mp3");
		myaso_upalo5=hge->Effect_Load("Zvuki/myaso/myaso_kusok_upal5.mp3");
		myaso_upalo6=hge->Effect_Load("Zvuki/myaso/myaso_kusok_upal6.mp3");
		myaso_upalo7=hge->Effect_Load("Zvuki/myaso/myaso_kusok_upal7.mp3");
		myaso_upalo8=hge->Effect_Load("Zvuki/myaso/myaso_kusok_upal8.mp3");

		myaso_razriv_user1=hge->Effect_Load("Zvuki/myaso/myaso_razriv_user1.wav");
		myaso_razriv_user2=hge->Effect_Load("Zvuki/myaso/myaso_razriv_user2.wav");


		ssik1=hge->Effect_Load("Zvuki/myaso/ssik1.mp3");
		ssik2=hge->Effect_Load("Zvuki/myaso/ssik2.mp3");
		ssik3=hge->Effect_Load("Zvuki/myaso/ssik3.mp3");
		ssik4=hge->Effect_Load("Zvuki/myaso/ssik4.mp3");

		ptenec_death1=hge->Effect_Load("Zvuki/myaso/ptenec_death1.mp3");



        blood1_tex=hge->Texture_Load("Sprite/krovyak/krovyak1_head.png");
        blood2_tex=hge->Texture_Load("Sprite/krovyak/krovyak2_head.png");
		blood3_tex=hge->Texture_Load("Sprite/krovyak/krovyak3_head.png");

        blood_shot1_tex=hge->Texture_Load("Sprite/krovyak/krovyak_shot1.png");

		blood_plyam1_tex=hge->Texture_Load("Sprite/krovyak/krovyak_plyam1.png");
		blood_plyam2_tex=hge->Texture_Load("Sprite/krovyak/krovyak_plyam2.png");
		blood_plyam3_tex=hge->Texture_Load("Sprite/krovyak/krovyak_plyam3.png");

		blood_luzha1_tex=hge->Texture_Load("Sprite/krovyak/krovyak_luzha1.png");

		blood_myaso1_tex=hge->Texture_Load("Sprite/krovyak/krovyak_myaso1.png");
		blood_myaso2_tex=hge->Texture_Load("Sprite/krovyak/krovyak_myaso2.png");
		blood_myaso3_tex=hge->Texture_Load("Sprite/krovyak/krovyak_myaso3.png");
		blood_myaso4_tex=hge->Texture_Load("Sprite/krovyak/krovyak_myaso4.png");
		blood_myaso5_tex=hge->Texture_Load("Sprite/krovyak/krovyak_myaso5.png");

		blood_zayac_noga1_tex=hge->Texture_Load("Sprite/krovyak/krovyak_zayac_noga1.png");
		blood_zayac_noga2_tex=hge->Texture_Load("Sprite/krovyak/krovyak_zayac_noga2.png");
		blood_zayac_noga3_tex=hge->Texture_Load("Sprite/krovyak/krovyak_zayac_noga3.png");
		blood_zayac_noga4_tex=hge->Texture_Load("Sprite/krovyak/krovyak_zayac_noga4.png");

		blood_zayac_rebra1_tex=hge->Texture_Load("Sprite/krovyak/krovyak_zayac_rebra1.png");
		blood_zayac_rebra2_tex=hge->Texture_Load("Sprite/krovyak/krovyak_zayac_rebra2.png");

		blood_vzriv1_a_tex=hge->Texture_Load("Sprite/krovyak/krovyak_vzriv1_a.png");
		blood_vzriv1_b_tex=hge->Texture_Load("Sprite/krovyak/krovyak_vzriv1_b.png");
		blood_vzriv1_c_tex=hge->Texture_Load("Sprite/krovyak/krovyak_vzriv1_c.png");
		blood_vzriv1_d_tex=hge->Texture_Load("Sprite/krovyak/krovyak_vzriv1_d.png");
		blood_vzriv1_e_tex=hge->Texture_Load("Sprite/krovyak/krovyak_vzriv1_e.png");
		blood_vzriv1_e2_tex=hge->Texture_Load("Sprite/krovyak/krovyak_vzriv1_e2.png");


		
		player1_myasnik_gogranata_ruka1_tex=hge->Texture_Load("Sprite/Igrok1/player1_myasnik_gogranata_ruka1.png");
		player1_myasnik_gogranata_ruka2_tex=hge->Texture_Load("Sprite/Igrok1/player1_myasnik_gogranata_ruka2.png");
		player1_strelok_gogranata_ruka1_tex=hge->Texture_Load("Sprite/Igrok1/player1_strelok_gogranata_ruka1.png");
		player1_strelok_gogranata_ruka2_tex=hge->Texture_Load("Sprite/Igrok1/player1_strelok_gogranata_ruka2.png");
		player1_razrushitel_gogranata_ruka1_tex=hge->Texture_Load("Sprite/Igrok1/player1_razrushitel_gogranata_ruka1.png");
		player1_razrushitel_gogranata_ruka2_tex=hge->Texture_Load("Sprite/Igrok1/player1_razrushitel_gogranata_ruka2.png");
		player1_tehnik_gogranata_ruka1_tex=hge->Texture_Load("Sprite/Igrok1/player1_tehnik_gogranata_ruka1.png");
		player1_tehnik_gogranata_ruka2_tex=hge->Texture_Load("Sprite/Igrok1/player1_tehnik_gogranata_ruka2.png");
		player1_myasnik_tex=hge->Texture_Load("Sprite/Igrok1/player1_myasnik.png");
		player1_strelok_tex=hge->Texture_Load("Sprite/Igrok1/player1_strelok.png");
		player1_razrushitel_tex=hge->Texture_Load("Sprite/Igrok1/player1_razrushitel.png");
		player1_tehnik_tex=hge->Texture_Load("Sprite/Igrok1/player1_tehnik.png");
		player1_myasnik_ruka1_udar_sleva_tex=hge->Texture_Load("Sprite/Igrok1/player1_myasnik_ruka1_udar_sleva.png");
		player1_strelok_ruka1_udar_sleva_tex=hge->Texture_Load("Sprite/Igrok1/player1_strelok_ruka1_udar_sleva.png");
		player1_razrushitel_ruka1_udar_sleva_tex=hge->Texture_Load("Sprite/Igrok1/player1_razrushitel_ruka1_udar_sleva.png");
		player1_tehnik_ruka1_udar_sleva_tex=hge->Texture_Load("Sprite/Igrok1/player1_tehnik_ruka1_udar_sleva.png");
		player1_myasnik_ruka1_pistol_tex=hge->Texture_Load("Sprite/Igrok1/player1_myasnik_ruka1_pistol.png");
		player1_strelok_ruka1_pistol_tex=hge->Texture_Load("Sprite/Igrok1/player1_strelok_ruka1_pistol.png");
		player1_razrushitel_ruka1_pistol_tex=hge->Texture_Load("Sprite/Igrok1/player1_razrushitel_ruka1_pistol.png");
		player1_tehnik_ruka1_pistol_tex=hge->Texture_Load("Sprite/Igrok1/player1_tehnik_ruka1_pistol.png");
		player1_myasnik_ruka1_vintovka_tex=hge->Texture_Load("Sprite/Igrok1/player1_myasnik_ruka1_vintovka.png");
		player1_strelok_ruka1_vintovka_tex=hge->Texture_Load("Sprite/Igrok1/player1_strelok_ruka1_vintovka.png");
		player1_razrushitel_ruka1_vintovka_tex=hge->Texture_Load("Sprite/Igrok1/player1_razrushitel_ruka1_vintovka.png");	
		player1_tehnik_ruka1_vintovka_tex=hge->Texture_Load("Sprite/Igrok1/player1_tehnik_ruka1_vintovka.png");	
		player1_myasnik_ruka1_winch_tex=hge->Texture_Load("Sprite/Igrok1/player1_myasnik_ruka1_winch.png");
		player1_strelok_ruka1_winch_tex=hge->Texture_Load("Sprite/Igrok1/player1_strelok_ruka1_winch.png");
		player1_razrushitel_ruka1_winch_tex=hge->Texture_Load("Sprite/Igrok1/player1_razrushitel_ruka1_winch.png");
		player1_tehnik_ruka1_winch_tex=hge->Texture_Load("Sprite/Igrok1/player1_tehnik_ruka1_winch.png");
		player2_strelok_tex=hge->Texture_Load("Sprite/Igrok2/player2_strelok.png");
		player2_gogranata_ruka1_tex=hge->Texture_Load("Sprite/Igrok2/player2_gogranata_ruka1.png");
		player2_gogranata_ruka2_tex=hge->Texture_Load("Sprite/Igrok2/player2_gogranata_ruka2.png");
		player2_strelok_ruka1_udar_sleva_tex=hge->Texture_Load("Sprite/Igrok2/player2_strelok_ruka1_udar_sleva.png");
		player2_strelok_ruka1_pistol_tex=hge->Texture_Load("Sprite/Igrok2/player2_strelok_ruka1_pistol.png");
		player2_strelok_ruka1_vintovka_tex=hge->Texture_Load("Sprite/Igrok2/player2_strelok_ruka1_vintovka.png");
		//заяц
		zayac_go_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_go.png");
		zayac_uhi_k_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_uhi_sprite_k.tga");
		zayac_uhi_s_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_uhi_sprite.png");
		zayac_uhi_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_uhi.png");
		zayac_go_bezuh_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_go_bezuh.png");

		zayac_boshka_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_boshka.png");
		zayac_boshka_bezuh_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_boshka_bezuh.png");



        zayac_trup1_a_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_trup1a.png");
		zayac_trup1_b_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_trup1b.png");
		zayac_trup1_c_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_trup1c.png");
		zayac_trup1_d_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_trup1d.png");
		zayac_trup1_a_bezuh_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_trup1a_bezuh.png");
		zayac_trup1_b_bezuh_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_trup1b_bezuh.png");
		zayac_trup1_c_bezuh_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_trup1c_bezuh.png");
		zayac_trup1_d_bezuh_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_trup1d_bezuh.png");
		zayac_trup1_a_bezboshki_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_trup1a_bezboshki.png");
		zayac_trup1_b_bezboshki_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_trup1b_bezboshki.png");
		zayac_trup1_c_bezboshki_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_trup1c_bezboshki.png");
		zayac_trup1_d_bezboshki_tex=hge->Texture_Load("Sprite/vragi/zayac/zayac_trup1d_bezboshki.png");

		volk_go_tex=hge->Texture_Load("Sprite/vragi/volk/volk_anime.png");
		volk_trup1_a_tex=hge->Texture_Load("Sprite/vragi/volk/volk_trup1a.png");
		volk_trup1_b_tex=hge->Texture_Load("Sprite/vragi/volk/volk_trup1b.png");
		volk_trup1_c_tex=hge->Texture_Load("Sprite/vragi/volk/volk_trup1c.png");


		medved_trup1_a_tex=hge->Texture_Load("Sprite/vragi/medved/medved_trup1a.png");
		medved_trup1_b_tex=hge->Texture_Load("Sprite/vragi/medved/medved_trup1b.png");
		medved_trup1_c_tex=hge->Texture_Load("Sprite/vragi/medved/medved_trup1c.png");
		medved_trup1_d_tex=hge->Texture_Load("Sprite/vragi/medved/medved_trup1d.png");
		medved_trup1_e_tex=hge->Texture_Load("Sprite/vragi/medved/medved_trup1e.png");
		medved_trup1_f_tex=hge->Texture_Load("Sprite/vragi/medved/medved_trup1f.png");
		medved_trup1_a_bezboshki_tex=hge->Texture_Load("Sprite/vragi/medved/medved_trup1a_bezboshki.png");
		medved_trup1_b_bezboshki_tex=hge->Texture_Load("Sprite/vragi/medved/medved_trup1b_bezboshki.png");
		medved_trup1_c_bezboshki_tex=hge->Texture_Load("Sprite/vragi/medved/medved_trup1c_bezboshki.png");
		medved_trup1_d_bezboshki_tex=hge->Texture_Load("Sprite/vragi/medved/medved_trup1d_bezboshki.png");
		medved_trup1_e_bezboshki_tex=hge->Texture_Load("Sprite/vragi/medved/medved_trup1e_bezboshki.png");
		medved_trup1_f_bezboshki_tex=hge->Texture_Load("Sprite/vragi/medved/medved_trup1f_bezboshki.png");
		medved_go_tex=hge->Texture_Load("Sprite/vragi/medved/medved_anime.png");
		medved_boshka1_tex=hge->Texture_Load("Sprite/vragi/medved/medved_boshka1.png");


		ptenec_go_tex=hge->Texture_Load("Sprite/vragi/ptenec/ptenec_anime.png");
		ptenec_wait_tex=hge->Texture_Load("Sprite/vragi/ptenec/ptenec_wait.png");
		ptenec_vpolete_tex=hge->Texture_Load("Sprite/vragi/ptenec/ptenec_vpolete.png");
		ptenec_vpolete_reverse_tex=hge->Texture_Load("Sprite/vragi/ptenec/ptenec_vpolete_reverse.png");
		ptenec_trup1_tex=hge->Texture_Load("Sprite/vragi/ptenec/ptenec_trup1.png");
		ptenec_boshka_vzriv1_a_tex=hge->Texture_Load("Sprite/vragi/ptenec/ptenec_boshka_vzriv1_a.png");
		ptenec_boshka_vzriv1_b_tex=hge->Texture_Load("Sprite/vragi/ptenec/ptenec_boshka_vzriv1_b.png");
		ptenec_boshka_vzriv1_c_tex=hge->Texture_Load("Sprite/vragi/ptenec/ptenec_boshka_vzriv1_c.png");
		ptenec_boshka_vzriv1_d_tex=hge->Texture_Load("Sprite/vragi/ptenec/ptenec_boshka_vzriv1_d.png");
		ptenec_boshka_vzriv1_e_tex=hge->Texture_Load("Sprite/vragi/ptenec/ptenec_boshka_vzriv1_e.png");


		RPG_healer_tex=hge->Texture_Load("Sprite/vragi/RPG/runa_healer.png");
		RPG_illusionist_tex=hge->Texture_Load("Sprite/vragi/RPG/runa_illusionist.png");
		RPG_teleporter_tex=hge->Texture_Load("Sprite/vragi/RPG/runa_teleporter.png");

		bonus_this_tex=hge->Texture_Load("Sprite/bonus/bonus_this.png");
		bonus_shilo_tex=hge->Texture_Load("Sprite/bonus/bonus_shilo.png");

		bonus_this_text_tex=hge->Texture_Load("Sprite/bonus/bonus_this_text.png");
		bonus_shilo_text_tex=hge->Texture_Load("Sprite/bonus/bonus_shilo_text.png");
		bonus_daun_text_tex=hge->Texture_Load("Sprite/bonus/bonus_daun_text.png");
		bonus_ulitka_text_tex=hge->Texture_Load("Sprite/bonus/bonus_ulitka_text.png");
		bonus_umnik_text_tex=hge->Texture_Load("Sprite/bonus/bonus_umnik_text.png");
       

		bonus_shilo_status_tex=hge->Texture_Load("Sprite/bonus/bonus_shilo_status.png");
		bonus_daun_status_tex=hge->Texture_Load("Sprite/bonus/bonus_daun_status.png");
		bonus_ulitka_status_tex=hge->Texture_Load("Sprite/bonus/bonus_ulitka_status.png");
		bonus_umnik_status_tex=hge->Texture_Load("Sprite/bonus/bonus_umnik_status.png");

		
		fon1_tex=hge->Texture_Load("Sprite/fon/fon_trava_pojuxlaya.png");
		fon2_tex=hge->Texture_Load("Sprite/fon/fon_trava_poj-trava_vlesu.png");
		fon3_tex=hge->Texture_Load("Sprite/fon/fon_trava_vlesu.png");



		oblaka1_tex=hge->Texture_Load("Sprite/oblaka/oblaka_derevnya.png");

		alkash1_tex=hge->Texture_Load("Sprite/fon_interaktive/alkash1.png");
		derevo1_tex=hge->Texture_Load("Sprite/objects/trees/derevo1.png");
		penek1_tex=hge->Texture_Load("Sprite/objects/trees/penek1.png");

		znak_polputi_tex=hge->Texture_Load("Sprite/fon_lvling/znak_polputi.png");

		polosa_finish_tex=hge->Texture_Load("Sprite/fon_lvling/polosa_finish.png");

		okno_lvl_progress_tex=hge->Texture_Load("Sprite/status/okno_lvl_progress.png");
		okno_lvl_progress_red_tex=hge->Texture_Load("Sprite/status/okno_lvl_progress_red.png");
		okno_lvl_progress_green_tex=hge->Texture_Load("Sprite/status/okno_lvl_progress_green.png");
		okno_lvl_polzunok_tex=hge->Texture_Load("Sprite/status/okno_lvl_polzunok.png");

		galka_tex=hge->Texture_Load("Sprite/other/galka.png");
		galka_menu_tex=hge->Texture_Load("Sprite/other/galka_menu.png");
		strelka_menu_tex=hge->Texture_Load("Sprite/other/strelka_menu.png");
		strelka_menu_D_tex=hge->Texture_Load("Sprite/other/strelka_menu_D.png");


		znak_myasnik_tex=hge->Texture_Load("Sprite/class/znak_myasnik.png");
		znak_strelok_tex=hge->Texture_Load("Sprite/class/znak_strelok.png");
		znak_razrushitel_tex=hge->Texture_Load("Sprite/class/znak_razrushitel.png");
		znak_tehnik_tex=hge->Texture_Load("Sprite/class/znak_tehnik.png");
		
		status_opit_tex=hge->Texture_Load("Sprite/status/okno_opit.png");
		status_udar_tex=hge->Texture_Load("Sprite/status/okno_udar.png");
		status_status_tex=hge->Texture_Load("Sprite/status/okno_status.png");
		opit_okno_vibora_tex=hge->Texture_Load("Sprite/status/opit_oknovibora.png");


		
		//текстуры оружия
		if(ak_tex==0)
		{ak=hge->Texture_Load("Sprite/pushki/ak47.tga");}
		if(ak_tex==1)
		{ak=hge->Texture_Load("Sprite/pushki/ak47_2.tga");}
		if(ak2_tex==0)
		{ak2=hge->Texture_Load("Sprite/pushki/ak47.tga");}
		if(ak2_tex==1)
		{ak2=hge->Texture_Load("Sprite/pushki/ak47_2.tga");}
		ak_upgraded=hge->Texture_Load("Sprite/pushki/ak47_upgraded.tga");
		ak2_upgraded=hge->Texture_Load("Sprite/pushki/ak47_2_upgraded.tga");
        w_pm_tex=hge->Texture_Load("Sprite/pushki/pm.png");
        w_pp19_vityaz_tex=hge->Texture_Load("Sprite/pushki/pp19_vityaz.tga");
		w_fn_f2000_tex=hge->Texture_Load("Sprite/pushki/FN_F2000.png");
		w_fn_f2000_upgraded_tex=hge->Texture_Load("Sprite/pushki/FN_F2000_upgraded.png");
		w_tt_tex=hge->Texture_Load("Sprite/pushki/TT.png");
		w_rpk_tex=hge->Texture_Load("Sprite/pushki/RPK74.png");
		w_mac_tex=hge->Texture_Load("Sprite/pushki/MAC.png");
		w_winchester_tex=hge->Texture_Load("Sprite/pushki/winchester.png");
		w_winchester_anime_tex=hge->Texture_Load("Sprite/pushki/winchester_anime.png");
		w_rpk47_tex=hge->Texture_Load("Sprite/pushki/RPK47.png");
		w_glok_tex=hge->Texture_Load("Sprite/pushki/glock-37.png");
		w_glok2_tex=hge->Texture_Load("Sprite/pushki/glock-37.png");
		w_rgd5_tex=hge->Texture_Load("Sprite/pushki/rgd5.png");
		w_milkor_tex=hge->Texture_Load("Sprite/pushki/Milkor MGL.png");
		w_panzer_tex=hge->Texture_Load("Sprite/pushki/panzerfaust3.png");
		w_panzer_out_tex=hge->Texture_Load("Sprite/pushki/panzerfaust3_out.png");
		w_webley_tex=hge->Texture_Load("Sprite/pushki/webley_mk4.png");
		w_fn_five_seven_tex=hge->Texture_Load("Sprite/pushki/fn_five-seven.png");
		w_qlz87_pushka_tex=hge->Texture_Load("Sprite/pushki/qlz-87_pushka.png");
		w_qlz87_trenoga_tex=hge->Texture_Load("Sprite/pushki/qlz-87_trenoga.png");

		w_granata_podstvol_tex=hge->Texture_Load("Sprite/pushki/granata_podstvol.png");
		w_granata_panzer_tex=hge->Texture_Load("Sprite/pushki/granata_panzerfaust3.png");

		katana_udar_sleva_tex=hge->Texture_Load("Sprite/pushki/katana_udar_sleva.png");
		
		ogon1=hge->Texture_Load("Sprite/fire/pulya.tga");


		
		blood_ssit_tex=hge->Texture_Load("Data/blood_ssit.png");
		RPG_healing_tex=hge->Texture_Load("Data/particle_zvezda.png");
		vzriv_grena_tex=hge->Texture_Load("Data/particles.png");
		vzriv_ogon_grena_tex=hge->Texture_Load("Data/particles.png");
		

		if(!menu_font||!oboima_text||!info||!infoR||!infoD||!infoBR||
			!oblaka1_tex||!fon1_tex||!fon2_tex||!fon3_tex||
			!galka_tex||!galka_menu_tex||!strelka_menu_tex||!strelka_menu_D_tex||
			!znak_myasnik_tex||!znak_strelok_tex||!znak_razrushitel_tex||!znak_tehnik_tex||
			!status_opit_tex||!status_udar_tex||!status_status_tex||!opit_okno_vibora_tex||
			!okno_lvl_progress_tex||!okno_lvl_progress_red_tex||!okno_lvl_progress_green_tex||!okno_lvl_polzunok_tex||
			!snd||!ak_reload1||!ak_reload2||!pm_fire||!pm_reload1||!pm_reload2||
			!pp19_fire||!pp19_reload1||!pp19_reload2||!fn_f2000_fire||!tt_fire||
			!mac_fire||!mac_reload1||!mac_reload2||!webley_fire||!webley_reload1||!webley_reload2||!milkor_fire||
			!fn_five_seven_fire||!winch_fire||!drob_reload1||!drob_pompa||!vzriv_grena1||
			!rocket_fire||!rocket2_fire||!rocket_polet||!rocket2_polet||
			!myaso_upalo1||!myaso_upalo2||!myaso_upalo3||!myaso_upalo4||!myaso_upalo5||!myaso_upalo6||!myaso_upalo7||
			!myaso_upalo8||
			!myaso_razriv_user1||!myaso_razriv_user2||
			!menu_sound||!menu_choose||
			!shot1||!headshot1||!headshot2||!headshot3||!headshot4||!headshot5||!headshot6||!headshot7||!headshot8||
			!ssik1||!ssik2||!ssik3|!ssik4||
			!ptenec_death1||
			!ak||!ak2||!ak_upgraded||!ak2_upgraded||!w_pm_tex||!w_pp19_vityaz_tex||!w_fn_f2000_tex||!w_fn_f2000_upgraded_tex||
			!w_tt_tex||!w_rpk_tex||!w_mac_tex||
			!w_winchester_tex||!w_winchester_anime_tex||!w_rpk47_tex||!w_glok_tex||!w_glok2_tex||!w_rgd5_tex||!w_milkor_tex||
			!w_panzer_tex||!w_panzer_out_tex||!w_webley_tex||!w_fn_five_seven_tex||!w_granata_podstvol_tex||!w_granata_panzer_tex||
			!w_qlz87_pushka_tex||!w_qlz87_trenoga_tex||!katana_udar_sleva_tex||
			!blood1_tex||!blood2_tex||!blood3_tex||!blood_shot1_tex||
			!blood_plyam1_tex||!blood_plyam2_tex||!blood_plyam3_tex||!blood_luzha1_tex||
			!blood_myaso1_tex||!blood_myaso2_tex||!blood_myaso3_tex||!blood_myaso4_tex||!blood_myaso5_tex||
			!blood_zayac_noga1_tex||!blood_zayac_noga2_tex||!blood_zayac_noga3_tex||!blood_zayac_noga4_tex||
			!blood_zayac_rebra1_tex||!blood_zayac_rebra2_tex||
			!blood_vzriv1_a_tex||!blood_vzriv1_b_tex||!blood_vzriv1_c_tex||!blood_vzriv1_d_tex||!blood_vzriv1_e_tex||
			!blood_vzriv1_e2_tex||
			!player1_myasnik_gogranata_ruka1_tex||!player1_myasnik_gogranata_ruka2_tex||
			!player1_strelok_gogranata_ruka1_tex||!player1_strelok_gogranata_ruka2_tex||
			!player1_razrushitel_gogranata_ruka1_tex||!player1_razrushitel_gogranata_ruka2_tex||		
			!player1_tehnik_gogranata_ruka1_tex||!player1_tehnik_gogranata_ruka2_tex||
			!player1_myasnik_tex||!player1_strelok_tex||!player1_razrushitel_tex||!player1_tehnik_tex||
			!player1_myasnik_ruka1_udar_sleva_tex||!player1_strelok_ruka1_udar_sleva_tex||
			!player1_razrushitel_ruka1_udar_sleva_tex||!player1_tehnik_ruka1_udar_sleva_tex||
			!player1_myasnik_ruka1_pistol_tex||!player1_strelok_ruka1_pistol_tex||
			!player1_razrushitel_ruka1_pistol_tex||!player1_tehnik_ruka1_pistol_tex||
			!player1_myasnik_ruka1_vintovka_tex||!player1_strelok_ruka1_vintovka_tex||
			!player1_razrushitel_ruka1_vintovka_tex||!player1_tehnik_ruka1_vintovka_tex||
			!player1_myasnik_ruka1_winch_tex||!player1_strelok_ruka1_winch_tex||
			!player1_razrushitel_ruka1_winch_tex||!player1_tehnik_ruka1_winch_tex||
			!player2_strelok_tex||!player2_gogranata_ruka1_tex||!player2_gogranata_ruka2_tex||
			!player2_strelok_ruka1_udar_sleva_tex||!player2_strelok_ruka1_vintovka_tex||!player2_strelok_ruka1_pistol_tex||
			!zayac_go_tex||!zayac_uhi_k_tex||!zayac_uhi_s_tex||!zayac_uhi_tex||
			!zayac_boshka_tex||!zayac_boshka_bezuh_tex||
			!volk_go_tex||!volk_trup1_a_tex||!volk_trup1_b_tex||!volk_trup1_c_tex||
			!medved_go_tex||!medved_boshka1_tex||
			!medved_trup1_a_tex||!medved_trup1_b_tex||!medved_trup1_c_tex||!medved_trup1_d_tex||!medved_trup1_e_tex||!medved_trup1_f_tex||
			!medved_trup1_a_bezboshki_tex||!medved_trup1_b_bezboshki_tex||!medved_trup1_c_bezboshki_tex||
			!medved_trup1_d_bezboshki_tex||!medved_trup1_e_bezboshki_tex||!medved_trup1_f_bezboshki_tex||
			!ptenec_go_tex||!ptenec_wait_tex||!ptenec_vpolete_tex||!ptenec_vpolete_reverse_tex||!ptenec_trup1_tex||
			!ptenec_boshka_vzriv1_a_tex||!ptenec_boshka_vzriv1_b_tex||!ptenec_boshka_vzriv1_c_tex||
			!ptenec_boshka_vzriv1_d_tex||!ptenec_boshka_vzriv1_e_tex||
			!RPG_healer_tex||!RPG_illusionist_tex||!RPG_teleporter_tex||
			!bonus_shilo_tex||!bonus_this_tex||
			!bonus_shilo_text_tex||!bonus_this_text_tex||!bonus_daun_text_tex||!bonus_ulitka_text_tex||!bonus_umnik_text_tex||
			!bonus_shilo_status_tex||!bonus_daun_status_tex||!bonus_ulitka_status_tex||!bonus_umnik_status_tex||
			!zayac_trup1_a_tex||!zayac_trup1_b_tex||!zayac_trup1_c_tex||!zayac_trup1_d_tex||
			!zayac_trup1_a_bezuh_tex||!zayac_trup1_b_bezuh_tex||!zayac_trup1_c_bezuh_tex||!zayac_trup1_d_bezuh_tex||
			!zayac_trup1_a_bezboshki_tex||!zayac_trup1_b_bezboshki_tex||!zayac_trup1_c_bezboshki_tex||
			!zayac_trup1_d_bezboshki_tex||
			!zayac_go_bezuh_tex||!ogon1||
			!blood_ssit_tex||!RPG_healing_tex||!vzriv_grena_tex||!vzriv_ogon_grena_tex||
			!alkash1_tex||!derevo1_tex||!penek1_tex||
			!znak_polputi_tex||!polosa_finish_tex)
		{
			// If one of the data files is not found, display
			// an error message and shutdown.
			MessageBox(NULL, "Ошибка загрузки игровых файлов.", "Ошибка, пля!!!", MB_OK | MB_ICONERROR | MB_APPLMODAL);
			hge->System_Shutdown();
			hge->Release();
			return 0;
		}




//начальные коррдинаты пули		
px=x-24;
py=y-9;


kills=0;
		

menu= new hgeGUI();
menu->AddCtrl(new hgeGUIMenuItem(1,menu_font,menu_sound,menu_choose,600,200,0.0f,"Старт"));
menu->AddCtrl(new hgeGUIMenuItem(2,menu_font,menu_sound,menu_choose,600,240,0.1f,"Опции"));
menu->AddCtrl(new hgeGUIMenuItem(3,menu_font,menu_sound,menu_choose,600,280,0.2f,"Инфо"));
menu->AddCtrl(new hgeGUIMenuItem(4,menu_font,menu_sound,menu_choose,600,320,0.3f,"Авторы"));
menu->AddCtrl(new hgeGUIMenuItem(5,menu_font,menu_sound,menu_choose,600,360,0.4f,"Выход"));
menu->AddCtrl(new hgeGUIMenuItem(6,menu_font,0,0,600,400,0.4f,""));
menu->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
menu->SetFocus(1);
menu->Enter();



menu_info= new hgeGUI();
menu_info->AddCtrl(new hgeGUIMenuItem(1,menu_font,menu_sound,menu_choose,600,200,0.0f,"Враги"));
menu_info->AddCtrl(new hgeGUIMenuItem(2,menu_font,menu_sound,menu_choose,600,240,0.1f,"Оружие"));
menu_info->AddCtrl(new hgeGUIMenuItem(3,menu_font,menu_sound,menu_choose,600,280,0.2f,"Бонусы"));
menu_info->AddCtrl(new hgeGUIMenuItem(4,menu_font,menu_sound,menu_choose,600,320,0.3f,"Назад"));
menu_info->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
menu_info->SetFocus(1);
menu_info->Enter();

menu_start= new hgeGUI();
menu_start->AddCtrl(new hgeGUIMenuItem(1,menu_font,menu_sound,menu_choose,600,200,0.0f,"1 ИГРОК"));
menu_start->AddCtrl(new hgeGUIMenuItem(2,menu_font,menu_sound,menu_choose,600,240,0.1f,"2 ИГРОКА"));
menu_start->AddCtrl(new hgeGUIMenuItem(3,menu_font,menu_sound,menu_choose,600,280,0.2f,"Назад"));
menu_start->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
menu_start->SetFocus(1);
menu_start->Enter();

menu_video= new hgeGUI();
menu_video->AddCtrl(new hgeGUIMenuItem(1,menu_font,menu_sound,menu_choose,600,280,0.0f,"ВКЛ СИСТЕМУ КЛАССОВ"));
menu_video->AddCtrl(new hgeGUIMenuItem(2,menu_font,menu_sound,menu_choose,600,320,0.1f,"ВЫКЛ СИСТЕМУ КЛАССОВ"));
menu_video->AddCtrl(new hgeGUIMenuItem(3,menu_font,menu_sound,menu_choose,600,500,0.0f,"ВКЛ RPGMOD"));
menu_video->AddCtrl(new hgeGUIMenuItem(4,menu_font,menu_sound,menu_choose,600,540,0.1f,"ВЫКЛ RPGMOD"));
menu_video->AddCtrl(new hgeGUIMenuItem(5,menu_font,menu_sound,menu_choose,600,580,0.1f,"ЗВУК"));
menu_video->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
menu_video->SetFocus(1);
menu_video->Enter();

menu_really= new hgeGUI();
menu_really->AddCtrl(new hgeGUIMenuItem(1,menu_font,menu_sound,menu_choose,300,450,0.0f,"Да"));
menu_really->AddCtrl(new hgeGUIMenuItem(2,menu_font,menu_sound,menu_choose,900,450,0.1f,"Нет"));
menu_really->SetNavMode(HGEGUI_LEFTRIGHT | HGEGUI_CYCLED);
menu_really->SetFocus(2);
menu_really->Enter();


menu_class= new hgeGUI();
menu_class->AddCtrl(new hgeGUIMenuItem(1,menu_font,menu_sound,menu_choose,600,300,0.0f,"МЯСНИК"));
menu_class->AddCtrl(new hgeGUIMenuItem(2,menu_font,menu_sound,menu_choose,600,400,0.1f,"СТРЕЛОК"));
menu_class->AddCtrl(new hgeGUIMenuItem(3,menu_font,menu_sound,menu_choose,600,500,0.2f,"РАЗРУШИТЕЛЬ"));
menu_class->AddCtrl(new hgeGUIMenuItem(4,menu_font,menu_sound,menu_choose,600,600,0.3f,"ИНЖЕНЕР"));
menu_class->AddCtrl(new hgeGUIMenuItem(5,menu_font,menu_sound,menu_choose,600,700,0.4f,"Назад"));
menu_class->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
menu_class->SetFocus(2);
menu_class->Enter();

menu_class2= new hgeGUI();
menu_class2->AddCtrl(new hgeGUIMenuItem(1,menu_font,menu_sound,menu_choose,600,300,0.0f,"МЯСНИК"));
menu_class2->AddCtrl(new hgeGUIMenuItem(2,menu_font,menu_sound,menu_choose,600,400,0.1f,"СТРЕЛОК"));
menu_class2->AddCtrl(new hgeGUIMenuItem(3,menu_font,menu_sound,menu_choose,600,500,0.2f,"РАЗРУШИТЕЛЬ"));
menu_class2->AddCtrl(new hgeGUIMenuItem(4,menu_font,menu_sound,menu_choose,600,600,0.3f,"ИНЖЕНЕР"));
menu_class2->AddCtrl(new hgeGUIMenuItem(5,menu_font,menu_sound,menu_choose,600,700,0.4f,"Назад"));
menu_class2->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
menu_class2->SetFocus(2);
menu_class2->Enter();



fonColor= new hgeColor(0xFFCCCCCC);

blood_target=hge->Target_Create(1200,900,false);
blood_tar=new hgeSprite(hge->Target_GetTexture(blood_target),0,0,1200,900);
blood_tar->SetColor(0xFFFFFFFF);
blood_tar->SetBlendMode(BLEND_COLORMUL|BLEND_ALPHAADD|BLEND_NOZWRITE);


//фон
fon1= new hgeSprite(fon1_tex,0,0,600,450); //пожухлая трава
fon1->SetColor(fonColor->GetHWColor());

fon2= new hgeSprite(fon2_tex,0,0,600,450); //из пожухлой в лесную
fon2->SetColor(fonColor->GetHWColor());

fon3= new hgeSprite(fon3_tex,0,0,600,450); //лесная трава
fon3->SetColor(fonColor->GetHWColor());
	

oblaka1= new hgeSprite(oblaka1_tex,0,0,2000,100);
oblaka1->SetColor(0xFFFFFFFF);


alkash1= new hgeSprite(alkash1_tex,0,0,150,50);
alkash1->SetColor(0xFFAAAAAA);

derevo1= new hgeSprite(derevo1_tex,0,0,200,450);
derevo1->SetColor(0xFFAAAAAA);
derevo1->SetHotSpot(100, 428);
penek1= new hgeSprite(penek1_tex,0,0,100,55);
penek1->SetColor(0xFFAAAAAA);
penek1->SetHotSpot(50, 22);


znak_polputi= new hgeSprite(znak_polputi_tex,0,0,100,100);
znak_polputi->SetColor(0xFFAAAAAA);
znak_polputi->SetHotSpot(50, 50);


polosa_finish= new hgeSprite(polosa_finish_tex,0,0,15,477);
polosa_finish->SetColor(0xFFAAAAAA);


galka=new hgeSprite(galka_tex, 0, 0, 20, 20);
galka->SetColor(0xFFFFFFFF);
galka->SetHotSpot(10, 10);


galka_menu=new hgeSprite(galka_menu_tex, 0, 0, 50, 50);
galka_menu->SetColor(0xFFFFFFFF);
galka_menu->SetHotSpot(25, 25);

strelka_menu=new hgeSprite(strelka_menu_tex, 0, 0, 50, 50);
strelka_menu->SetColor(0xFFFFFFFF);
strelka_menu->SetHotSpot(25, 25);


znak_myasnik= new hgeSprite(znak_myasnik_tex, 0, 0, 64, 64);
znak_myasnik->SetColor(0xFFFFFFFF);
znak_myasnik->SetHotSpot(32, 32);


znak_strelok= new hgeSprite(znak_strelok_tex, 0, 0, 64, 64);
znak_strelok->SetColor(0xFFFFFFFF);
znak_strelok->SetHotSpot(32, 32);


znak_razrushitel= new hgeSprite(znak_razrushitel_tex, 0, 0, 64, 64);
znak_razrushitel->SetColor(0xFFFFFFFF);
znak_razrushitel->SetHotSpot(32, 32);


znak_tehnik= new hgeSprite(znak_tehnik_tex, 0, 0, 64, 64);
znak_tehnik->SetColor(0xFFFFFFFF);
znak_tehnik->SetHotSpot(32, 32);


status_opit=new hgeSprite(status_opit_tex, 0, 0, 180, 20);
status_opit->SetColor(0xDDFFFFFF);
//status_opit->SetHotSpot(90, 10);

status_udar=new hgeSprite(status_udar_tex, 0, 0, 180, 20);
status_udar->SetColor(0xDDFFFFFF);

status_status=new hgeSprite(status_status_tex, 0, 0, 28, 250);
status_status->SetColor(0xDDFFFFFF);


opit1_progress=new hgeSprite(0, 0, 0, 180, 18);
opit1_progress->SetColor(0xAAF0FF02);
//opit1_progress->SetHotSpot(90, 9);


opit_okno_vibora=new hgeSprite(opit_okno_vibora_tex, 0, 0, 700, 517);
opit_okno_vibora->SetColor(0xFFFFFFFF);
opit_okno_vibora->SetHotSpot(350, 259);


okno_lvl_progress=new hgeSprite(okno_lvl_progress_tex, 0, 0, 600, 20);
okno_lvl_progress->SetColor(0xDDFFFFFF);
okno_lvl_progress->SetHotSpot(300, 10);

okno_lvl_progress_red=new hgeSprite(okno_lvl_progress_red_tex, 0, 0, 600, 20);
okno_lvl_progress_red->SetColor(0xDDFFFFFF);
okno_lvl_progress_red->SetHotSpot(300, 10);

okno_lvl_progress_green=new hgeSprite(okno_lvl_progress_green_tex, 0, 0, 600, 20);
okno_lvl_progress_green->SetColor(0xDDFFFFFF);
okno_lvl_progress_green->SetHotSpot(300, 10);

okno_lvl_polzunok=new hgeSprite(okno_lvl_polzunok_tex, 0, 0, 10, 36);
okno_lvl_polzunok->SetColor(0xAAFFFFFF);
okno_lvl_polzunok->SetHotSpot(5, 18);


//огонь выстрела
		pulya=new hgeSprite(ogon1, 0, 0, 16, 16);
    pulya->SetColor(0x00FFFFFF);
    pulya->SetHotSpot(8, 8);
//огонь выстрела 2
		pulya2=new hgeSprite(ogon1, 0, 0, 16, 16);
    pulya2->SetColor(0x00FFFFFF);
    pulya2->SetHotSpot(8, 8);

	
//пуля
	p=new hgeSprite(0, 0, 0, 3, 1);
    p->SetColor(0xFFFFDC1D);


//пуля2
	p2=new hgeSprite(0, 0, 0, 3, 1);
    p2->SetColor(0xFFFFDC1D);


	p1d1=new hgeSprite(0, 0, 0, 3, 1);
    p1d1->SetColor(0xFFFFDC1D);
	p1d2=new hgeSprite(0, 0, 0, 3, 1);
    p1d2->SetColor(0xFFFFDC1D);
	p1d3=new hgeSprite(0, 0, 0, 3, 1);
    p1d3->SetColor(0xFFFFDC1D);
	p1d4=new hgeSprite(0, 0, 0, 3, 1);
    p1d4->SetColor(0xFFFFDC1D);

	p2d1=new hgeSprite(0, 0, 0, 3, 1);
    p2d1->SetColor(0xFFFFDC1D);
	p2d2=new hgeSprite(0, 0, 0, 3, 1);
    p2d2->SetColor(0xFFFFDC1D);
	p2d3=new hgeSprite(0, 0, 0, 3, 1);
    p2d3->SetColor(0xFFFFDC1D);
	p2d4=new hgeSprite(0, 0, 0, 3, 1);
    p2d4->SetColor(0xFFFFDC1D);

optika1=new hgeSprite(0, 0, 0, 3, 1);
optika1->SetColor(0xFFFFFFFF);


gilza_pist=new hgeSprite(0, 0, 0, 1, 1);
gilza_pist->SetColor(0xFFFFDC1D);


gilza_avt=new hgeSprite(0, 0, 0, 2, 1);
gilza_avt->SetColor(0xFFFFDC1D);


granata_podstvol=new hgeSprite(w_granata_podstvol_tex, 0, 0, 58, 24);
granata_podstvol->SetColor(0xFFAAAAAA);
granata_podstvol->SetHotSpot(29,12);

granata_panzer=new hgeSprite(w_granata_panzer_tex, 0, 0, 64, 13);
granata_panzer->SetColor(0xFFFFFFFF);
granata_panzer->SetHotSpot(32,6);


        
//ak47-1
	
	if(ak_tex==0)	//деревянный старый
	{ak47=new hgeSprite(ak , 0 , 0, 128, 40);
	ak47->SetColor(0xFFFFFFFF);
    ak47->SetHotSpot(64, 20);}
	if(ak_tex==1)   //железный
	{ak47=new hgeSprite(ak2 , 0 , 0, 123, 37);}
    ak47->SetColor(0xFFFFFFFF);
    ak47->SetHotSpot(62, 18);

//ak47-2
	if(ak2_tex==0)	//деревянный старый
	{ak472=new hgeSprite(ak , 0 , 0, 128, 40);
	ak472->SetColor(0xFFFFFFFF);
    ak472->SetHotSpot(64, 20);}
	if(ak2_tex==1)   //железный
	{ak472=new hgeSprite(ak2 , 0 , 0, 123, 37);}
    ak472->SetColor(0xFFFFFFFF);
    ak472->SetHotSpot(62, 18);





//Пистолет Макарова
pm=new hgeSprite(w_pm_tex , 0 , 0, 100, 80);
pm->SetColor(0xFFFFFFFF);
pm->SetHotSpot(50,40);

//Пистолет Макарова 2
pm2=new hgeSprite(w_pm_tex , 0 , 0, 100, 80);
pm2->SetColor(0xFFFFFFFF);
pm2->SetHotSpot(50,40);

//ПП19-01 "Витязь"	
pp19_vityaz=new hgeSprite(w_pp19_vityaz_tex , 0 , 0, 100,44);
pp19_vityaz->SetColor(0xFFFFFFFF);
pp19_vityaz->SetHotSpot(50,22);

//ПП19-01 "Витязь" 2	
pp19_vityaz2=new hgeSprite(w_pp19_vityaz_tex , 0 , 0, 100,44);
pp19_vityaz2->SetColor(0xFFFFFFFF);
pp19_vityaz2->SetHotSpot(50,22);


//FN F2000
fn_f2000=new hgeSprite(w_fn_f2000_tex , 0 , 0, 128,56);
fn_f2000->SetColor(0xFFFFFFFF);
fn_f2000->SetHotSpot(64,28);

//FN F2000 2
fn_f20002=new hgeSprite(w_fn_f2000_tex , 0 , 0, 128,56);
fn_f20002->SetColor(0xFFFFFFFF);
fn_f20002->SetHotSpot(64,28);

//TT
tt=new hgeSprite(w_tt_tex , 0 , 0, 64,45);
tt->SetColor(0xFFFFFFFF);
tt->SetHotSpot(32,22);

//TT 2
tt2=new hgeSprite(w_tt_tex , 0 , 0, 64,45);
tt2->SetColor(0xFFFFFFFF);
tt2->SetHotSpot(32,22);

//РПК 74
rpk=new hgeSprite(w_rpk_tex , 0 , 0, 150,45);
rpk->SetColor(0xFFFFFFFF);
rpk->SetHotSpot(75,22);

//РПК 74 2
rpk2=new hgeSprite(w_rpk_tex , 0 , 0, 150,45);
rpk2->SetColor(0xFFFFFFFF);
rpk2->SetHotSpot(75,22);

//MAC
mac=new hgeSprite(w_mac_tex , 0 , 0, 100,88);
mac->SetColor(0xFFFFFFFF);
mac->SetHotSpot(50,44);

//MAC 2
mac2=new hgeSprite(w_mac_tex , 0 , 0, 100,88);
mac2->SetColor(0xFFFFFFFF);
mac2->SetHotSpot(50,44);

//Винчестер 1
winchester=new hgeSprite(w_winchester_tex , 0 , 0, 128,27);
winchester->SetColor(0xFFFFFFFF);
winchester->SetHotSpot(64,13);

//Винчестер 2
winchester2=new hgeSprite(w_winchester_tex , 0 , 0, 128,27);
winchester2->SetColor(0xFFFFFFFF);
winchester2->SetHotSpot(64,13);


winchester_anime=new hgeAnimation(w_winchester_anime_tex,3,8.0f,0,0,128,27);
winchester_anime->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_NOLOOP);
winchester_anime->SetColor(0xFFFFFFFF);//анимация видима

winchester2_anime=new hgeAnimation(w_winchester_anime_tex,3,8.0f,0,0,128,27);
winchester2_anime->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_NOLOOP);
winchester2_anime->SetColor(0xFFFFFFFF);//анимация видима

//РПК 47
rpk47=new hgeSprite(w_rpk47_tex , 0 , 0, 150,64);
rpk47->SetColor(0xFFFFFFFF);
rpk47->SetHotSpot(75,32);

//РПК 47 2
rpk472=new hgeSprite(w_rpk47_tex , 0 , 0, 150,64);
rpk472->SetColor(0xFFFFFFFF);
rpk472->SetHotSpot(75,32);


//GLOCK
glok=new hgeSprite(w_glok_tex , 0 , 0, 100,66);
glok->SetColor(0xFFFFFFFF);
glok->SetHotSpot(50,33);

//GLOCK 2
glok2=new hgeSprite(w_glok2_tex , 0 , 0, 100,66);
glok2->SetColor(0xFFFFFFFF);
glok2->SetHotSpot(50,33);

//РГД-5
rgd5=new hgeSprite(w_rgd5_tex , 0 , 0, 25,25);
rgd5->SetColor(0xFFFFFFFF);
rgd5->SetHotSpot(10,10);

//РГД-5 2
rgd52=new hgeSprite(w_rgd5_tex , 0 , 0, 25,25);
rgd52->SetColor(0xFFFFFFFF);
rgd52->SetHotSpot(10,10);

//КАТАНА 1
katana1_anime=new hgeAnimation(katana_udar_sleva_tex,4,20.0f,0,0,150,96);
katana1_anime->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_NOLOOP);
katana1_anime->SetColor(0xFFAAAAAA);

//КАТАНА 2
katana2_anime=new hgeAnimation(katana_udar_sleva_tex,4,20.0f,0,0,150,96);
katana2_anime->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_NOLOOP);
katana2_anime->SetColor(0xFFAAAAAA);

//Milkor MGL
milkor=new hgeSprite(w_milkor_tex , 0, 0, 100,34);
milkor->SetColor(0xFFFFFFFF);
milkor->SetHotSpot(50,17);

//Milkor MGL 2
milkor2=new hgeSprite(w_milkor_tex , 0, 0, 100,34);
milkor2->SetColor(0xFFFFFFFF);
milkor2->SetHotSpot(50,17);

//Panzerfaust-3
panzer=new hgeSprite(w_panzer_tex , 0, 0, 150,38);
panzer->SetColor(0xFFFFFFFF);
panzer->SetHotSpot(55,19);

//Panzerfaust-3 2
panzer2=new hgeSprite(w_panzer_tex , 0, 0, 150,38);
panzer2->SetColor(0xFFFFFFFF);
panzer2->SetHotSpot(55,19);

//Webley MK4
webley=new hgeSprite(w_webley_tex , 0, 0, 100,53);
webley->SetColor(0xFFFFFFFF);
webley->SetHotSpot(50,26);

//Webley MK4 2
webley2=new hgeSprite(w_webley_tex , 0, 0, 100,53);
webley2->SetColor(0xFFFFFFFF);
webley2->SetHotSpot(50,26);

//FN Five-Seven
fn_five_seven=new hgeSprite(w_fn_five_seven_tex , 0, 0, 64,44);
fn_five_seven->SetColor(0xFFFFFFFF);
fn_five_seven->SetHotSpot(32,22);

//FN Five-Seven 2
fn_five_seven2=new hgeSprite(w_fn_five_seven_tex , 0, 0, 64,44);
fn_five_seven2->SetColor(0xFFFFFFFF);
fn_five_seven2->SetHotSpot(32,22);

qlz87_pushka=new hgeSprite(w_qlz87_pushka_tex , 0, 0, 116,40);
qlz87_pushka->SetColor(0xFFFFFFFF);
qlz87_pushka->SetHotSpot(90,16);

qlz87_trenoga=new hgeSprite(w_qlz87_trenoga_tex , 0, 0, 118,57);
qlz87_trenoga->SetColor(0xFFFFFFFF);
qlz87_trenoga->SetHotSpot(59,28);

//ИГРОК 1

player1_myasnik=new hgeAnimation(player1_myasnik_tex,4,12.0f,0,0,96,96);
player1_myasnik->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_LOOP);
player1_myasnik->SetColor(0xFFAAAAAA);//МЯСНИК

player1_strelok=new hgeAnimation(player1_strelok_tex,4,12.0f,0,0,96,96);
player1_strelok->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_LOOP);
player1_strelok->SetColor(0xFFAAAAAA);//СТРЕЛОК

player1_razrushitel=new hgeAnimation(player1_razrushitel_tex,4,12.0f,0,0,96,96);
player1_razrushitel->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_LOOP);
player1_razrushitel->SetColor(0xFFAAAAAA);//РАЗРУШИТЕЛЬ

player1_tehnik=new hgeAnimation(player1_tehnik_tex,4,12.0f,0,0,96,96);
player1_tehnik->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_LOOP);
player1_tehnik->SetColor(0xFFAAAAAA);//ТЕХНИК

player1_myasnik_ruka1_udar_sleva=new hgeAnimation(player1_myasnik_ruka1_udar_sleva_tex,4,20.0f,0,0,96,96);
player1_myasnik_ruka1_udar_sleva->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_NOLOOP);
player1_myasnik_ruka1_udar_sleva->SetColor(0xFFAAAAAA);//рука с ручным оружием

player1_ruka1_pistol=new hgeAnimation(player1_strelok_ruka1_pistol_tex,2,20.0f,0,0,96,96);
player1_ruka1_pistol->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_NOLOOP);
player1_ruka1_pistol->SetColor(0xFFAAAAAA);//рука с пистолетом

player1_ruka1_vintovka=new hgeAnimation(player1_strelok_ruka1_vintovka_tex,2,20.0f,0,0,96,96);
player1_ruka1_vintovka->SetMode(HGEANIM_FWD|HGEANIM_NOPINGPONG|HGEANIM_NOLOOP);
player1_ruka1_vintovka->SetColor(0xFFAAAAAA);//рука с винтовкой

player1_ruka1_winch=new hgeAnimation(player1_tehnik_ruka1_winch_tex,3,8.0f,0,0,96,96);
player1_ruka1_winch->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_NOLOOP);
player1_ruka1_winch->SetColor(0xFFAAAAAA);//рука с дробовиком

player1_gogranata_ruka1=new hgeAnimation(player1_strelok_gogranata_ruka1_tex,4,20.0f,0,0,96,96);
player1_gogranata_ruka1->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_NOLOOP);
player1_gogranata_ruka1->SetColor(0xFFAAAAAA);

player1_gogranata_ruka2=new hgeAnimation(player1_strelok_gogranata_ruka2_tex,4,20.0f,0,0,96,96);
player1_gogranata_ruka2->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_NOLOOP);
player1_gogranata_ruka2->SetColor(0xFFAAAAAA);


//ИГРОК 2
player2_strelok=new hgeAnimation(player2_strelok_tex,4,12.0f,0,0,96,96);
player2_strelok->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_LOOP);
player2_strelok->SetColor(0xFFAAAAAA);//СТРЕЛОК

player2_gogranata_ruka1=new hgeAnimation(player2_gogranata_ruka1_tex,4,20.0f,0,0,96,96);
player2_gogranata_ruka1->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_NOLOOP);
player2_gogranata_ruka1->SetColor(0xFFAAAAAA);

player2_gogranata_ruka2=new hgeAnimation(player2_gogranata_ruka2_tex,4,20.0f,0,0,96,96);
player2_gogranata_ruka2->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_NOLOOP);
player2_gogranata_ruka2->SetColor(0xFFAAAAAA);

player2_myasnik_ruka1_udar_sleva=new hgeAnimation(player2_strelok_ruka1_udar_sleva_tex,4,20.0f,0,0,96,96);
player2_myasnik_ruka1_udar_sleva->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_NOLOOP);
player2_myasnik_ruka1_udar_sleva->SetColor(0xFFAAAAAA);//рука с ручным оружием

player2_ruka1_pistol=new hgeAnimation(player2_strelok_ruka1_pistol_tex,2,20.0f,0,0,96,96);
player2_ruka1_pistol->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_NOLOOP);
player2_ruka1_pistol->SetColor(0xFFAAAAAA);//рука с пистолетом

player2_ruka1_vintovka=new hgeAnimation(player2_strelok_ruka1_vintovka_tex,2,20.0f,0,0,96,96);
player2_ruka1_vintovka->SetMode(HGEANIM_FWD|HGEANIM_NOPINGPONG|HGEANIM_NOLOOP);
player2_ruka1_vintovka->SetColor(0xFFAAAAAA);//рука с винтовкой



//ЗАЯЦ
zayac=new hgeAnimation(zayac_go_tex,6,9.0f,0,0,40,40);
zayac->SetMode(HGEANIM_FWD|HGEANIM_NOPINGPONG|HGEANIM_LOOP);
zayac->SetColor(0xFFAAAAAA);//анимация видима
zayac->SetHotSpot(0,0);


uhi=new hgeSprite(zayac_uhi_s_tex,0,0,18,16);
uhi->SetColor(0xFFAAAAAA);
uhi->SetHotSpot(9,8);


zayac_boshka=new hgeSprite(zayac_boshka_tex,0,0,24,24);
zayac_boshka->SetColor(0xFFAAAAAA);
zayac_boshka->SetHotSpot(15,17);

zayac_boshka_bezuh=new hgeSprite(zayac_boshka_bezuh_tex,0,0,24,24);
zayac_boshka_bezuh->SetColor(0xFFAAAAAA);
zayac_boshka_bezuh->SetHotSpot(15,17);



//ТРУП ЗАЙЦА
zayac_trup1= new hgeSprite(zayac_go_tex,0,0,40,40);
zayac_trup1->SetColor(0xFFAAAAAA); 


uhi_a= new hgeAnimation(zayac_uhi_tex,6,12.0f,0,0,18,16);
uhi_a->SetColor(0xFFAAAAAA);
uhi_a->SetMode(HGEANIM_FWD|HGEANIM_NOPINGPONG|HGEANIM_NOLOOP);
uhi_a->SetHotSpot(9,8);


//ВОЛК
volk=new hgeAnimation(volk_go_tex,7,9.0f,0,0,120,50);
volk->SetMode(HGEANIM_FWD|HGEANIM_NOPINGPONG|HGEANIM_LOOP);
volk->SetColor(0xFFAAAAAA);//анимация видима
volk->SetHotSpot(0,0);

//ТРУП ВОЛКА
volk_trup1= new hgeSprite(volk_go_tex,0,0,120,50);
volk_trup1->SetColor(0xFFAAAAAA); 



//МЕДВЕДЬ
medved=new hgeAnimation(medved_go_tex,6,4.0f,0,0,190,225);

//ТРУП МЕДВЕДЯ
medved_trup1= new hgeSprite(medved_go_tex,0,0,190,225);

medved_boshka= new hgeSprite(medved_boshka1_tex,0,0,55,48);
medved_boshka->SetHotSpot(22,24);
//ПТЕНЕЦ
ptenec=new hgeAnimation(ptenec_go_tex,3,4.0f,0,0,32,32);
ptenec->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_LOOP);
ptenec->SetColor(0xFFAAAAAA);//анимация видима

ptenec_wait=new hgeAnimation(ptenec_wait_tex,9,6.0f,0,0,32,32);
ptenec_wait->SetMode(HGEANIM_FWD|HGEANIM_PINGPONG|HGEANIM_LOOP);
ptenec_wait->SetColor(0xFFAAAAAA);//анимация видима

ptenec_trup1= new hgeSprite(ptenec_trup1_tex,0,0,32,32);
ptenec_trup1->SetColor(0xFFAAAAAA); 


ptenec_boshka_vzriv1= new hgeSprite(ptenec_boshka_vzriv1_a_tex,0,0,42,42);
ptenec_boshka_vzriv1->SetColor(0xFFAAAAAA); 

//руны
RPG_healer= new hgeSprite(RPG_healer_tex,0,0,64,64);
RPG_healer->SetColor(0xFFAAAAAA); 
RPG_illusionist= new hgeSprite(RPG_illusionist_tex,0,0,64,64);
RPG_illusionist->SetColor(0xFFAAAAAA);
RPG_teleporter= new hgeSprite(RPG_teleporter_tex,0,0,64,64);
RPG_teleporter->SetColor(0xFFAAAAAA);


//БОНУСЫ

bonus_this=new hgeSprite(bonus_this_tex,0,0,30,30);
bonus_this->SetColor(0xFFAAAAAA);
bonus_this->SetHotSpot(15,15);


bonus_shilo=new hgeSprite(bonus_shilo_tex,0,0,30,30);
bonus_shilo->SetColor(0xFFAAAAAA);
bonus_shilo->SetHotSpot(15,15);


//ТЕКСТЫ БОНУСОВ

bonus_this_text=new hgeSprite(bonus_this_text_tex,0,0,56,21);
bonus_this_text->SetColor(0xFFAAAAAA);
bonus_this_text->SetHotSpot(28,10);


bonus_shilo_text=new hgeSprite(bonus_shilo_text_tex,0,0,120,23);
bonus_shilo_text->SetColor(0xFFAAAAAA);
bonus_shilo_text->SetHotSpot(60,11);

bonus_daun_text=new hgeSprite(bonus_daun_text_tex,0,0,120,22);
bonus_daun_text->SetColor(0xFFAAAAAA);
bonus_daun_text->SetHotSpot(60,11);

bonus_ulitka_text=new hgeSprite(bonus_ulitka_text_tex,0,0,120,23);
bonus_ulitka_text->SetColor(0xFFAAAAAA);
bonus_ulitka_text->SetHotSpot(60,11);

bonus_umnik_text=new hgeSprite(bonus_umnik_text_tex,0,0,120,22);
bonus_umnik_text->SetColor(0xFFAAAAAA);
bonus_umnik_text->SetHotSpot(60,11);


//ЗНАЧКИ СТАТУСА БОНУСОВ

bonus_shilo_status=new hgeSprite(bonus_shilo_status_tex,0,0,20,20);
bonus_shilo_status->SetColor(0xFFFFFFFF);
bonus_shilo_status->SetHotSpot(10,10);

bonus_daun_status=new hgeSprite(bonus_daun_status_tex,0,0,20,20);
bonus_daun_status->SetColor(0xFFFFFFFF);
bonus_daun_status->SetHotSpot(10,10);

bonus_ulitka_status=new hgeSprite(bonus_ulitka_status_tex,0,0,20,20);
bonus_ulitka_status->SetColor(0xFFFFFFFF);
bonus_ulitka_status->SetHotSpot(10,10);

bonus_umnik_status=new hgeSprite(bonus_umnik_status_tex,0,0,20,20);
bonus_umnik_status->SetColor(0xFFFFFFFF);
bonus_umnik_status->SetHotSpot(10,10);

/*
krovyak1=new hgeAnimation(blood1_tex,8,24.0f,0,0,64,64);
krovyak1->SetColor(0xFFAAAAAA);
krovyak1->SetMode(HGEANIM_FWD|HGEANIM_NOPINGPONG|HGEANIM_NOLOOP);
krovyak1->SetHotSpot(32,32);


krovyak1_s=new hgeSprite(blood1_s_tex , 0 , 0, 64,64);
krovyak1_s->SetColor(0xFFAAAAAA);
krovyak1_s->SetHotSpot(32,32);*/

//ДРИСНЯ
krovyak1= new hgeSprite(blood1_tex,0,0,128,64);
krovyak1->SetColor(0xFFAAAAAA);
krovyak1->SetHotSpot(64,32);
krovyak2= new hgeSprite(blood2_tex,0,0,128,64);
krovyak2->SetColor(0xFFAAAAAA);
krovyak2->SetHotSpot(64,32);
krovyak3= new hgeSprite(blood3_tex,0,0,128,64);
krovyak3->SetColor(0xFFAAAAAA);
krovyak3->SetHotSpot(64,32);
//ТОЧЕЧНЫЙ КРОВЯК
krovyak_shot1= new hgeSprite(blood_shot1_tex,0,0,16,16);
krovyak_shot1->SetColor(0xFFAAAAAA);
krovyak_shot1->SetHotSpot(8,8);

//КЛЯКСЫ
krovyak_plyam1= new hgeSprite(blood_plyam1_tex,0,0,64,64);
krovyak_plyam1->SetColor(0xFFAAAAAA);
krovyak_plyam1->SetHotSpot(32,32);

krovyak_plyam2= new hgeSprite(blood_plyam2_tex,0,0,64,60);
krovyak_plyam2->SetColor(0xFFAAAAAA);
krovyak_plyam2->SetHotSpot(32,30);

krovyak_plyam3= new hgeSprite(blood_plyam3_tex,0,0,64,60);
krovyak_plyam3->SetColor(0xFFAAAAAA);
krovyak_plyam3->SetHotSpot(32,30);

//ЛУЖИ
krovyak_luzha1= new hgeSprite(blood_luzha1_tex,0,0,128,64);
krovyak_luzha1->SetColor(0xFFAAAAAA);
krovyak_luzha1->SetHotSpot(64,32);

//МЯСО!!!
krovyak_myaso1= new hgeSprite(blood_myaso1_tex,0,0,43,24);
krovyak_myaso1->SetColor(0xFFAAAAAA);
krovyak_myaso1->SetHotSpot(21,12);
krovyak_myaso2= new hgeSprite(blood_myaso2_tex,0,0,36,22);
krovyak_myaso2->SetColor(0xFFAAAAAA);
krovyak_myaso2->SetHotSpot(18,11);
krovyak_myaso3= new hgeSprite(blood_myaso3_tex,0,0,38,25);
krovyak_myaso3->SetColor(0xFFAAAAAA);
krovyak_myaso3->SetHotSpot(19,12);
krovyak_myaso4= new hgeSprite(blood_myaso4_tex,0,0,30,19);
krovyak_myaso4->SetColor(0xFFAAAAAA);
krovyak_myaso4->SetHotSpot(15,9);
krovyak_myaso5= new hgeSprite(blood_myaso5_tex,0,0,30,19);
krovyak_myaso5->SetColor(0xFFAAAAAA);
krovyak_myaso5->SetHotSpot(15,9);



krovyak_zayac_noga1= new hgeSprite(blood_zayac_noga1_tex,0,0,14,21);
krovyak_zayac_noga1->SetColor(0xFFAAAAAA);
krovyak_zayac_noga1->SetHotSpot(7,10);
krovyak_zayac_noga2= new hgeSprite(blood_zayac_noga2_tex,0,0,18,23);
krovyak_zayac_noga2->SetColor(0xFFAAAAAA);
krovyak_zayac_noga2->SetHotSpot(9,18);//чтоб летела как культяпка)))
krovyak_zayac_noga3= new hgeSprite(blood_zayac_noga3_tex,0,0,18,23);
krovyak_zayac_noga3->SetColor(0xFFAAAAAA);
krovyak_zayac_noga3->SetHotSpot(9,20);//чтоб летела как культяпка)))
krovyak_zayac_noga4= new hgeSprite(blood_zayac_noga4_tex,0,0,18,20);
krovyak_zayac_noga4->SetColor(0xFFAAAAAA);
krovyak_zayac_noga4->SetHotSpot(9,10);



krovyak_zayac_rebra1= new hgeSprite(blood_zayac_rebra1_tex,0,0,16,13);
krovyak_zayac_rebra1->SetColor(0xFFAAAAAA);
krovyak_zayac_rebra1->SetHotSpot(8,6);
krovyak_zayac_rebra2= new hgeSprite(blood_zayac_rebra2_tex,0,0,16,13);
krovyak_zayac_rebra2->SetColor(0xFFAAAAAA);
krovyak_zayac_rebra2->SetHotSpot(8,6);

krovyak_vzriv1= new hgeSprite(blood_vzriv1_e_tex,0,0,64,64);
krovyak_vzriv1->SetColor(0xFFAAAAAA);
krovyak_vzriv1->SetHotSpot(32,32);



    blood_ssit_spr=new hgeSprite(blood_ssit_tex, 0,0, 29, 30);
    blood_ssit_spr->SetColor(0xFFAAAAAA);
    blood_ssit_spr->SetHotSpot(15, 15);

	blood_ssit_psi=new hgeParticleSystem("Data/blood_ssit.psi", blood_ssit_spr);
	blood_ssit_psi->Fire();


	RPG_healing_spr=new hgeSprite(RPG_healing_tex, 0,0, 20, 20);
    RPG_healing_spr->SetColor(0xFFAAAAAA);
    RPG_healing_spr->SetHotSpot(10, 10);
	
	
	RPG_healing_psi=new hgeParticleSystem("Data/particle_healing.psi", RPG_healing_spr);
	RPG_healing_psi->Fire();

	vzriv_grena_spr=new hgeSprite(vzriv_grena_tex, 0,96, 32, 32);
    vzriv_grena_spr->SetColor(0xFFAAAAAA);
    vzriv_grena_spr->SetHotSpot(16, 16);

	vzriv_grena_psi=new hgeParticleSystem("Data/particle_vzriv_grena.psi", vzriv_grena_spr);
	vzriv_grena_psi->Fire();
		

	vzriv_ogon_grena_spr=new hgeSprite(vzriv_ogon_grena_tex, 0,96, 32, 32);
    vzriv_ogon_grena_spr->SetColor(0xFFAAAAAA);
    vzriv_ogon_grena_spr->SetHotSpot(16, 16);

	vzriv_ogon_grena_psi=new hgeParticleSystem("Data/particle_vzriv_ogon_grena.psi", vzriv_ogon_grena_spr);
	vzriv_ogon_grena_psi->Fire();


for (int iii=0;iii<=999;iii++)
{opit_lvl[iii]=1000+500*(iii*iii+iii)/2;}




trupsObjects=new spriteObject[MAX_TRUPS];  //ТРУПЫ
N_TRUPS=0;

vragi1Objects= new zayacObject[MAX_ZAYAC];  //ЗАЙЦЫ
N_ZAYAC=0;

vragi2Objects= new volkObject[MAX_VOLK];  //ВОЛКИ
N_VOLK=-1;

vragi3Objects= new medvedObject[MAX_MEDVED];  //МЕДВЕДИ
N_MEDVED=-1;

vragi4Objects= new ptenecObject[MAX_PTENEC];  //ПТЕНЦЫ!!!
N_PTENEC=-1;

uhiObjects= new uhiObject[MAX_UHI];          //УШИ
N_UHI=0;


krovyakObjects= new bloodObject[MAX_BLOOD]; //КРОВЯК
N_BLOOD=0;


boshkiObjects= new headObject[MAX_HEAD]; //БОШКИ
N_HEAD=0;

gilziObjects= new gilzaObject[MAX_GILZ];//ГИЛЬЗЫ

N_GILZ=0;

bonusiObjects= new bonusObject[MAX_BONUS];//БОНУСЫ

N_BONUS=0;

bonustextiObjects= new bonustextObject[MAX_BONUSTEXT]; //ТЕКСТЫ БОНУСОВ

N_BONUSTEXT=0;


bonusi1= new bonusZnach[MAX_BONUSI];//БОНУСНЫЕ ЗНАЧЕНИЯ
N_BONUS1=0;
bonusi2= new bonusZnach[MAX_BONUSI];
N_BONUS2=0;



statusi1= new bonusStatus[MAX_BONUSSTATUS];//СТАТУСЫ
N_BONUSSTATUS1=0;

statusi2= new bonusStatus[MAX_BONUSSTATUS];
N_BONUSSTATUS2=0;

myasko= new myasoObject[MAX_MYASO];//МЯСО
N_MYASO=0;


FON= new fonObject[32];//ФОН

	for(int i53=0;i53<=31;i53++) 
	{	
	if(i53%2==0)
	{FON[i53].x=600*(i53/2-1);
	FON[i53].y=0;}
	if(i53%2==1)
	{FON[i53].x=600*((i53-1)/2-1);
	FON[i53].y=450;}
	
	if(i53<=11) //3 экрана
	{FON[i53].type=1;}//пожухлая трава

	if(i53>11&&i53<=13)//пол-экрана
	{FON[i53].type=2;}//переход из пожухлой в лесную
	
	if(i53>13)//остальное
	{FON[i53].type=3;}//лесная трава

	}


granati= new granataObject[MAX_GREN];
N_GREN=0;

ubijstva=new fragObject[MAX_KILLS];
N_KILLS=0;


Objects= new Object[N_OBJECTS];//ОБЪЕТЫ НА ФОНЕ

for(int i50=0;i50<=N_OBJECTS-1;i50++)
{
if(i50>5&&i50<=25)//20 деревьев
{Objects[i50].x=hge->Random_Float(3000,8000);
Objects[i50].y=hge->Random_Float(200,700);
Objects[i50].pl=0;
Objects[i50].type=2;}

if(i50>0&&i50<=5)//5 пней
{Objects[i50].x=hge->Random_Float(1000,6000);
Objects[i50].y=hge->Random_Float(200,700);
Objects[i50].pl=0;
Objects[i50].type=1;}

if(i50==0)//знак полпути
{Objects[i50].x=(lvl1_lenght-1200)/2;
Objects[i50].y=250;
Objects[i50].pl=1;
Objects[i50].type=0;}

}


A= new ALL[MAX_ZAYAC+MAX_VOLK+MAX_MYASO+MAX_BONUS+MAX_UHI+MAX_HEAD+N_OBJECTS+MAX_GILZ+MAX_BLOOD+MAX_GREN+MAX_MEDVED+MAX_PTENEC+2];


Y= new YCOORD[MAX_ZAYAC+MAX_VOLK+MAX_MYASO+MAX_BONUS+MAX_UHI+MAX_HEAD+N_OBJECTS+MAX_GILZ+MAX_BLOOD+MAX_GREN+MAX_MEDVED+MAX_PTENEC+2];
N_Y=0;


                    //ОРУЖИЕ!!!!!!!!!!!!!!
oboima=8;
oboima2=8;


for(int i4=0;i4<=N_ZAYAC;i4++)
{vragi1Objects[i4].ubit=0;//все зайцы живы
vragi1Objects[i4].pokoin=0;
vragi1Objects[i4].health=50;
vragi1Objects[i4].v1x=0;
vragi1Objects[i4].v1y=hge->Random_Float(50,850);
vragi1Objects[i4].bezuh=0;//все зайцы с ушами
vragi1Objects[i4].bezboshki=0;
vragi1Objects[i4].speed=hge->Random_Float(1,1.2f);
vragi1Objects[i4].defence=0;
vragi1Objects[i4].object_id=-1;
vragi1Objects[i4].A=0;
vragi1Objects[i4].vzorvan=false;
vragi1Objects[i4].energy=0;
vragi1Objects[i4].rasstX=0;
vragi1Objects[i4].rasstY=0;
vragi1Objects[i4].chetvert=0;
}
	


for(int i7=0;i7<=MAX_UHI-1;i7++)
{uhiObjects[i7].gradus=hge->Random_Float(0,M_PI);
uhiObjects[i7].niz=0;}

for(int i17=0;i17<=	MAX_HEAD-1;i17++)
{boshkiObjects[i17].gradus=hge->Random_Float(0,M_PI);}

for(int i13=0;i13<=MAX_BLOOD-1;i13++)
{krovyakObjects[i13].akt=0;}


for(int i37=0;i37<=N_VOLK;i37++)
{vragi2Objects[i37].defence=0;
vragi2Objects[i37].object_id=-1;}

for(int i58=0;i58<=	MAX_GREN-1;i58++)
{granati[i58].gradus=0;}





kills_zayac=0;
kills_volk=0;
kills_medved=0;
kills_zayac_vschiii=0;
kills_zayac_bezuh=0;
kills_zayac_bezboshki=0;

kills2_zayac=0;
kills2_volk=0;
kills2_medved=0;
kills2_zayac_vschiii=0;
kills2_zayac_bezuh=0;
kills2_zayac_bezboshki=0;


		// Let's rock now!
		hge->System_Start();

		// Free loaded texture and sound
        hge->Texture_Free(ak);
		hge->Texture_Free(ak2);
		hge->Texture_Free(ak_upgraded);
		hge->Texture_Free(ak2_upgraded);
		hge->Texture_Free(w_pm_tex);
		hge->Texture_Free(ogon1);
		 hge->Texture_Free(player1_myasnik_gogranata_ruka1_tex);
		 hge->Texture_Free(player1_myasnik_gogranata_ruka2_tex);
		 hge->Texture_Free(player1_strelok_gogranata_ruka1_tex);
		 hge->Texture_Free(player1_strelok_gogranata_ruka2_tex);
		 hge->Texture_Free(player1_razrushitel_gogranata_ruka1_tex);
		 hge->Texture_Free(player1_razrushitel_gogranata_ruka2_tex);	 
		 hge->Texture_Free(player1_tehnik_gogranata_ruka1_tex);
		 hge->Texture_Free(player1_tehnik_gogranata_ruka2_tex);
		 hge->Texture_Free(player1_myasnik_tex);
		 hge->Texture_Free(player1_strelok_tex);
		 hge->Texture_Free(player1_razrushitel_tex);
		 hge->Texture_Free(player1_tehnik_tex);
		 hge->Texture_Free(player1_myasnik_ruka1_udar_sleva_tex);
		 hge->Texture_Free(player1_strelok_ruka1_udar_sleva_tex);
		 hge->Texture_Free(player1_razrushitel_ruka1_udar_sleva_tex);
		 hge->Texture_Free(player1_tehnik_ruka1_udar_sleva_tex);
		 hge->Texture_Free(player1_myasnik_ruka1_pistol_tex);
		 hge->Texture_Free(player1_strelok_ruka1_pistol_tex);
		 hge->Texture_Free(player1_razrushitel_ruka1_pistol_tex);
		 hge->Texture_Free(player1_tehnik_ruka1_pistol_tex);
		 hge->Texture_Free(player1_myasnik_ruka1_vintovka_tex);
		 hge->Texture_Free(player1_strelok_ruka1_vintovka_tex);
		 hge->Texture_Free(player1_razrushitel_ruka1_vintovka_tex);
		 hge->Texture_Free(player1_tehnik_ruka1_vintovka_tex);
		 hge->Texture_Free(player1_myasnik_ruka1_winch_tex);
		 hge->Texture_Free(player1_strelok_ruka1_winch_tex);
		 hge->Texture_Free(player1_razrushitel_ruka1_winch_tex);
		 hge->Texture_Free(player1_tehnik_ruka1_winch_tex);
		 hge->Texture_Free(player2_strelok_tex);
		 hge->Texture_Free(player2_gogranata_ruka1_tex);
		 hge->Texture_Free(player2_gogranata_ruka2_tex);
		 hge->Texture_Free(player2_strelok_ruka1_udar_sleva_tex);
		 hge->Texture_Free(player2_strelok_ruka1_pistol_tex);
		 hge->Texture_Free(player2_strelok_ruka1_vintovka_tex);
		hge->Texture_Free(zayac_go_tex);
			hge->Texture_Free(zayac_go_bezuh_tex);
			hge->Texture_Free(zayac_uhi_tex);
			hge->Texture_Free(zayac_boshka_tex);
			hge->Texture_Free(zayac_boshka_bezuh_tex);
			hge->Texture_Free(zayac_trup1_a_tex);
			hge->Texture_Free(zayac_trup1_b_tex);
			hge->Texture_Free(zayac_trup1_c_tex);
			hge->Texture_Free(zayac_trup1_d_tex);
			hge->Texture_Free(zayac_trup1_a_bezuh_tex);
			hge->Texture_Free(zayac_trup1_b_bezuh_tex);
			hge->Texture_Free(zayac_trup1_c_bezuh_tex);
			hge->Texture_Free(zayac_trup1_d_bezuh_tex);
			hge->Texture_Free(zayac_trup1_a_bezboshki_tex);
			hge->Texture_Free(zayac_trup1_b_bezboshki_tex);
			hge->Texture_Free(zayac_trup1_c_bezboshki_tex);
			hge->Texture_Free(zayac_trup1_d_bezboshki_tex);
			hge->Texture_Free(volk_go_tex);
			hge->Texture_Free(volk_trup1_a_tex);
			hge->Texture_Free(volk_trup1_b_tex);
			hge->Texture_Free(volk_trup1_c_tex);
			hge->Texture_Free(medved_trup1_a_tex);
			hge->Texture_Free(medved_trup1_b_tex);
			hge->Texture_Free(medved_trup1_c_tex);
			hge->Texture_Free(medved_trup1_d_tex);
			hge->Texture_Free(medved_trup1_e_tex);
			hge->Texture_Free(medved_trup1_f_tex);
			hge->Texture_Free(medved_trup1_a_bezboshki_tex);
			hge->Texture_Free(medved_trup1_b_bezboshki_tex);
			hge->Texture_Free(medved_trup1_c_bezboshki_tex);
			hge->Texture_Free(medved_trup1_d_bezboshki_tex);
			hge->Texture_Free(medved_trup1_e_bezboshki_tex);
			hge->Texture_Free(medved_trup1_f_bezboshki_tex);
			hge->Texture_Free(medved_go_tex);
			hge->Texture_Free(ptenec_go_tex);
			hge->Texture_Free(ptenec_wait_tex);
			hge->Texture_Free(ptenec_vpolete_tex);
			hge->Texture_Free(ptenec_vpolete_reverse_tex);
			hge->Texture_Free(ptenec_trup1_tex);
			hge->Texture_Free(ptenec_boshka_vzriv1_a_tex);
			hge->Texture_Free(ptenec_boshka_vzriv1_b_tex);
			hge->Texture_Free(ptenec_boshka_vzriv1_c_tex);
			hge->Texture_Free(ptenec_boshka_vzriv1_d_tex);
			hge->Texture_Free(ptenec_boshka_vzriv1_e_tex);		
			hge->Texture_Free(RPG_healer_tex);
			hge->Texture_Free(RPG_illusionist_tex);
			hge->Texture_Free(RPG_teleporter_tex);
			hge->Texture_Free(bonus_this_tex);
			hge->Texture_Free(bonus_shilo_tex);
			hge->Texture_Free(bonus_this_text_tex);
			hge->Texture_Free(bonus_shilo_text_tex);
			hge->Texture_Free(bonus_daun_text_tex);
			hge->Texture_Free(bonus_ulitka_text_tex);
			hge->Texture_Free(bonus_umnik_text_tex);
			hge->Texture_Free(bonus_shilo_status_tex);
			hge->Texture_Free(bonus_daun_status_tex);
			hge->Texture_Free(bonus_ulitka_status_tex);
			hge->Texture_Free(bonus_umnik_status_tex);
			hge->Texture_Free(blood1_tex);
			hge->Texture_Free(blood2_tex);
			hge->Texture_Free(blood3_tex);
			hge->Texture_Free(blood_shot1_tex);
			hge->Texture_Free(blood_plyam1_tex);
			hge->Texture_Free(blood_plyam2_tex);
			hge->Texture_Free(blood_plyam3_tex);
			hge->Texture_Free(blood_luzha1_tex);
			hge->Texture_Free(blood_myaso1_tex);
			hge->Texture_Free(blood_myaso2_tex);
			hge->Texture_Free(blood_myaso3_tex);
			hge->Texture_Free(blood_myaso4_tex);
			hge->Texture_Free(blood_myaso5_tex);
			hge->Texture_Free(blood_zayac_noga1_tex);
			hge->Texture_Free(blood_zayac_noga2_tex);
			hge->Texture_Free(blood_zayac_noga3_tex);
			hge->Texture_Free(blood_zayac_noga4_tex);
			hge->Texture_Free(blood_zayac_rebra1_tex);
			hge->Texture_Free(blood_zayac_rebra2_tex);
			hge->Texture_Free(blood_vzriv1_a_tex);
			hge->Texture_Free(blood_vzriv1_b_tex);
			hge->Texture_Free(blood_vzriv1_c_tex);
			hge->Texture_Free(blood_vzriv1_d_tex);
			hge->Texture_Free(blood_vzriv1_e_tex);
			hge->Texture_Free(blood_vzriv1_e2_tex);

hge->Texture_Free(zayac_uhi_s_tex);
hge->Texture_Free(fon1_tex);
hge->Texture_Free(fon2_tex);
hge->Texture_Free(fon3_tex);
hge->Texture_Free(oblaka1_tex);
hge->Texture_Free(alkash1_tex);
hge->Texture_Free(derevo1_tex);
hge->Texture_Free(penek1_tex);
hge->Texture_Free(znak_polputi_tex);
hge->Texture_Free(polosa_finish_tex);
hge->Texture_Free(w_pm_tex);
hge->Texture_Free(w_pp19_vityaz_tex);
hge->Texture_Free(w_fn_f2000_tex);
hge->Texture_Free(w_fn_f2000_upgraded_tex);
hge->Texture_Free(w_tt_tex);
hge->Texture_Free(w_rpk_tex);
hge->Texture_Free(w_mac_tex);
hge->Texture_Free(w_winchester_tex);
hge->Texture_Free(w_winchester_anime_tex);
hge->Texture_Free(w_rpk47_tex);
hge->Texture_Free(w_glok_tex);
hge->Texture_Free(w_glok2_tex);
hge->Texture_Free(w_rgd5_tex);
hge->Texture_Free(katana_udar_sleva_tex);
hge->Texture_Free(w_milkor_tex);
hge->Texture_Free(w_granata_podstvol_tex);
hge->Texture_Free(w_panzer_tex);
hge->Texture_Free(w_panzer_out_tex);
hge->Texture_Free(w_granata_panzer_tex);
hge->Texture_Free(w_webley_tex);
hge->Texture_Free(w_fn_five_seven_tex);
hge->Texture_Free(w_qlz87_pushka_tex);
hge->Texture_Free(w_qlz87_trenoga_tex);
			hge->Texture_Free(blood_ssit_tex);
			hge->Texture_Free(RPG_healing_tex);
			hge->Texture_Free(vzriv_grena_tex);
			hge->Texture_Free(vzriv_ogon_grena_tex);
			hge->Texture_Free(galka_tex);
			hge->Texture_Free(galka_menu_tex);
			hge->Texture_Free(strelka_menu_tex);
			hge->Texture_Free(strelka_menu_D_tex);
			hge->Texture_Free(znak_myasnik_tex);
			hge->Texture_Free(znak_strelok_tex);
			hge->Texture_Free(znak_razrushitel_tex);
			hge->Texture_Free(znak_tehnik_tex);
			hge->Texture_Free(status_opit_tex);
			hge->Texture_Free(status_udar_tex);
			hge->Texture_Free(status_status_tex);
			hge->Texture_Free(opit_okno_vibora_tex);
			hge->Texture_Free(okno_lvl_progress_tex);
			hge->Texture_Free(okno_lvl_progress_red_tex);
			hge->Texture_Free(okno_lvl_progress_green_tex);
			hge->Texture_Free(okno_lvl_polzunok_tex);
		hge->Effect_Free(menu_sound);
		hge->Effect_Free(menu_choose);
		hge->Effect_Free(snd);
		hge->Effect_Free(ak_reload1);
		hge->Effect_Free(ak_reload2);
		hge->Effect_Free(pm_fire);
		hge->Effect_Free(pm_reload1);
		hge->Effect_Free(pm_reload2);
		hge->Effect_Free(pp19_fire);
		hge->Effect_Free(pp19_reload1);
		hge->Effect_Free(pp19_reload2);
		hge->Effect_Free(fn_f2000_fire);
		hge->Effect_Free(tt_fire);
		hge->Effect_Free(mac_fire);
		hge->Effect_Free(mac_reload1);
		hge->Effect_Free(mac_reload2);
		hge->Effect_Free(webley_fire);
		hge->Effect_Free(webley_reload1);
		hge->Effect_Free(webley_reload2);
		hge->Effect_Free(fn_five_seven_fire);
		hge->Effect_Free(milkor_fire);
		hge->Effect_Free(winch_fire);
		hge->Effect_Free(rocket_fire);
		hge->Effect_Free(rocket2_fire);
		hge->Effect_Free(rocket_polet);
		hge->Effect_Free(rocket2_polet);
		hge->Effect_Free(drob_reload1);
		hge->Effect_Free(drob_pompa);
		hge->Effect_Free(vzriv_grena1);
		hge->Effect_Free(myaso_upalo1);
		hge->Effect_Free(myaso_upalo2);
		hge->Effect_Free(myaso_upalo3);
		hge->Effect_Free(myaso_upalo4);
		hge->Effect_Free(myaso_upalo5);
		hge->Effect_Free(myaso_upalo6);
		hge->Effect_Free(myaso_upalo7);
		hge->Effect_Free(myaso_upalo8);
		hge->Effect_Free(myaso_razriv_user1);
		hge->Effect_Free(myaso_razriv_user2);
		hge->Effect_Free(shot1);
		hge->Effect_Free(headshot1);
		hge->Effect_Free(headshot2);
		hge->Effect_Free(headshot3);
		hge->Effect_Free(headshot4);
		hge->Effect_Free(headshot5);
		hge->Effect_Free(headshot6);
		hge->Effect_Free(headshot7);
		hge->Effect_Free(headshot8);

		hge->Effect_Free(ssik1);
		hge->Effect_Free(ssik2);
		hge->Effect_Free(ssik3);
		hge->Effect_Free(ssik4);

		hge->Effect_Free(ptenec_death1);

		hge->Target_Free(blood_target);


		delete blood_tar;

		delete menu;
		delete menu_info;
		delete menu_start;
		delete menu_video;
		delete menu_really;
		delete menu_class;
		delete menu_class2;
		delete pulya;
		delete pulya2;
		delete granata_podstvol;
		delete granata_panzer;
		delete ak47;
		delete pm;
		delete pp19_vityaz;
		delete fn_f2000;
		delete tt;
		delete rpk;
		delete mac;
		delete winchester;
		delete winchester_anime;
		delete ak472;
		delete pm2;
		delete pp19_vityaz2;
		delete fn_f20002;
		delete tt2;
		delete rpk2;
		delete mac2;
		delete winchester2;
		delete winchester2_anime;
		delete rpk47;
		delete rpk472;
		delete glok;
		delete glok2;
		delete rgd5;
		delete rgd52;
		delete katana1_anime;
		delete katana2_anime;
		delete milkor;
		delete milkor2;
		delete panzer;
		delete panzer2;
		delete webley;
		delete webley2;
		delete fn_five_seven;
		delete fn_five_seven2;
		delete qlz87_pushka;
		delete qlz87_trenoga;
		delete info;
		delete infoR;
		delete infoD;
		delete infoBR;
		delete oboima_text;
		delete menu_font;
		delete galka;
		delete galka_menu;
		delete strelka_menu;
		delete znak_myasnik;
		delete znak_strelok;
		delete znak_razrushitel;
		delete znak_tehnik;
		delete status_opit;
		delete status_udar;
		delete status_status;
		delete opit1_progress;
		delete opit_okno_vibora;
		delete okno_lvl_progress;
		delete okno_lvl_progress_red;
		delete okno_lvl_progress_green;
		delete okno_lvl_polzunok;
		delete p;
		delete p2;
		delete p1d1,p1d2,p1d3,p1d4,p2d1,p2d2,p2d3,p2d4;
		delete optika1;
		delete gilza_pist;
		delete gilza_avt;
		delete zayac_trup1;
		delete player1_gogranata_ruka1;
		delete player1_gogranata_ruka2;
		delete player1_myasnik;
		delete player1_strelok;
		delete player1_razrushitel;
		delete player1_tehnik;
		delete player1_myasnik_ruka1_udar_sleva;
		delete player1_ruka1_pistol;
		delete player1_ruka1_vintovka;
		delete player1_ruka1_winch;
		delete player2_strelok;
		delete player2_gogranata_ruka1;
		delete player2_gogranata_ruka2;
		delete player2_myasnik_ruka1_udar_sleva;
		delete player2_ruka1_pistol;
		delete player2_ruka1_vintovka;
		delete zayac;
		delete uhi;
		delete uhi_a;
		delete zayac_boshka;
		delete zayac_boshka_bezuh;
		delete volk;
		delete volk_trup1;
		delete medved;
		delete medved_trup1;
		delete medved_boshka;
		delete ptenec;
		delete ptenec_wait;
		delete ptenec_trup1;
		delete ptenec_boshka_vzriv1;
		delete RPG_healer;
		delete RPG_illusionist;
		delete RPG_teleporter;
		delete bonus_this;
		delete bonus_shilo;
		delete bonus_this_text;
		delete bonus_shilo_text;
		delete bonus_daun_text;
		delete bonus_ulitka_text;
		delete bonus_umnik_text;
		delete bonus_shilo_status;
		delete bonus_daun_status;
		delete bonus_ulitka_status;
		delete bonus_umnik_status;
		delete krovyak1;
		delete krovyak2;
		delete krovyak3;
		delete krovyak_shot1;
		delete krovyak_plyam1;
		delete krovyak_plyam2;
		delete krovyak_plyam3;
		delete krovyak_luzha1;
		delete krovyak_myaso1;
		delete krovyak_myaso2;
		delete krovyak_myaso3;
		delete krovyak_myaso4;
		delete krovyak_myaso5;
		delete krovyak_zayac_noga1;
		delete krovyak_zayac_noga2;
		delete krovyak_zayac_noga3;
		delete krovyak_zayac_noga4;
		delete krovyak_zayac_rebra1;
		delete krovyak_zayac_rebra2;
		delete krovyak_vzriv1;
		delete blood_ssit_psi;
		delete blood_ssit_spr;
		delete RPG_healing_psi;
		delete RPG_healing_spr;
		delete vzriv_grena_psi;
		delete vzriv_grena_spr;
		delete vzriv_ogon_grena_psi;
		delete vzriv_ogon_grena_spr;
		delete [] trupsObjects;
		delete [] vragi1Objects;
		delete [] vragi2Objects;
		delete [] vragi3Objects;
		delete [] vragi4Objects;
		delete [] uhiObjects;
		delete [] boshkiObjects;
		delete [] gilziObjects;
		delete [] bonusiObjects;
		delete [] bonustextiObjects;
		delete [] bonusi1;
		delete [] bonusi2;
		delete [] statusi1;
		delete [] statusi2;
		delete [] myasko;
		delete [] ubijstva;
		delete [32] FON;
		delete [] granati;
		delete [] Objects;
		delete [] A;
		delete [] Y;
		delete fon1;
		delete fon2;
		delete fon3;
		delete oblaka1;
		delete alkash1;
		delete derevo1;
		delete penek1;
		delete znak_polputi;
		delete polosa_finish;
		delete fonColor;
	
	
	

	}
	else MessageBox(NULL, hge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);

	// Clean up and shutdown
	hge->System_Shutdown();
	hge->Release();
	return 0;
}
