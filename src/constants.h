#define ENC_L1 32 // nutno urcit piny!!!
#define ENC_L2 35
#define ENC_R1 21
#define ENC_R2 19

#define WBP1 23 // nutno urcit piny!!!
#define WBP2 22
#define WBP3 36
#define WBP4 39
#define WBP5 0

#define WBZ1 5 // nutno urcit piny!!!
#define WBZ2 4
#define WBZ3 3
#define WBZ4 2
#define WBZ5 1

#define WBL 15// nutno urcit piny!!!
#define WBR 13

#define INFRA_L // nutno urcit piny!!! na expander.
#define INFRA_PL
#define INFRA_PP
#define INFRA_PR

#define SERVO_PIN   // nutno urcit piny!!!

bool enc_l1_pin = digitalRead(ENC_L1); // solo senzory nutno urcit piny
bool enc_l2_pin = digitalRead(ENC_L2);
bool enc_r1_pin = digitalRead(ENC_R1); // solo senzory nutno urcit piny
bool enc_r2_pin = digitalRead(ENC_R2);
bool enc_l1_pin_save, enc_r1_pin_save = false;
long enc_l, enc_r;

const int button1_pin = ; // pres expander pinu

int wbp1_current = analogRead(WBP1); // predni lista nutno urcit piny
int wbp2_current = analogRead(WBP2);
int wbp3_current = analogRead(WBP3);
int wbp4_current = analogRead(WBP4);
int wbp5_current = analogRead(WBP5);
int wbp1_b,wbp2_b,wbp3_b,wbp4_b,wbp5_b;//cerna
int wbp1_w,wbp2_w,wbp3_w,wbp4_w,wbp5_w;//bila
int wbp1_prumer,wbp2_prumer,wbp3_prumer,wbp4_prumer,wbp5_prumer;//prumer
bool wbp1,wbp2,wbp3,wbp4,wbp5 = true;

int wbz1_current = analogRead(WBZ1); // zadni lista nutno urcit piny
int wbz2_current = analogRead(WBZ2);
int wbz3_current = analogRead(WBZ3);
int wbz4_current = analogRead(WBZ4);
int wbz5_current = analogRead(WBZ5);
int wbz1_b,wbz2_b,wbz3_b,wbz4_b,wbz5_b;
int wbz1_w,wbz2_w,wbz3_w,wbz4_w,wbz5_w;
int wbz1_prumer,wbz2_prumer,wbz3_prumer,wbz4_prumer,wbz5_prumer;
bool wbz1,wbz2,wbz3,wbz4,wbz5 = true;

int wbl_current = analogRead(WBL); // solo senzory nutno urcit piny
int wbr_current = analogRead(WBR);
int wbl_b,wbr_b;
int wbl_w,wbr_w;
int wbl_prumer,wbr_prumer;
bool wbl,wbr = true;

bool infra_l  = man.expander().digitalRead(INFRA_L ); //nutno deklarovat pin
bool infra_pl = man.expander().digitalRead(INFRA_PL);
bool infra_pp = man.expander().digitalRead(INFRA_PP);
bool infra_pr = man.expander().digitalRead(INFRA_PR);

int Xr = 3;
int Yr = 0;
int Xl = 3;
int Yl = 0;

bool driver_enc_1 = true;
bool driver_enc_2 = true;
// obecne funkce
long long start_time;
 
// rotace motoru
bool rotate_l, rotate_r, rotate = false;
bool correction_direction, follow_line = false;
bool stracen, opravdu_stracen = true;

int cas_1, cas_2, cas; // cas otoceni o jeden tik
int last_time_1, last_time_2, last_time;// cas posledniho tiku virtualniho enc
int virtual_enc_1, virtual_enc_2, virtual_enc;// virtualni enc jako zrcadlo pro realne
int rozdil1, rozdil2, delta_l, delta_r;// rozdil virtualniho a realneho enc
int rychlost = 100;
uint8_t pvm_1, pvm_2, motor_spead_l, motor_spead_r,turn_spead;
uint8_t pp_enc = 900;
int16_t otacky_l, otacky_r, otacky; // otacky jednotlivich motoru
float odklon;

//pohybove funkce
float osa_otaceni; // osa kolem které se otaci robot
float osa_l;
float osa_r;
bool turn;
bool prava_zatackaS;
bool stop

//driveri
bool vnimani_prejete_cari_r = false;
bool vnimani_prejete_cari_l = false;
bool na_souradce = true; // true = X; false = Y
bool v_otacce = false;