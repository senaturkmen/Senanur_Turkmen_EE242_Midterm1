#define rccahblenR * ( (unsigned volatile int *)0x40023830)
#define gpiodmask 1<<3
#define gpiodModr *((unsigned volatile int* )0x40020c00)
#define gpiodP14mask 1<<28
#define gpiodP13mask 1<<26
#define gpiodP15mask 1<<30
#define gpiodP12mask 1<<24
#define gpiodOdr  *((unsigned volatile int *)0x40020c14)
#define gpiodp14onmask 1<<14
#define gpiodp14ofmask 0<<14
#define gpiodp13onmask 1<<13
#define gpiodp13ofmask ~(1<<13)
#define gpiodp15onmask 1<<15
#define gpiodp15ofmask 0<<15
#define gpiodp12onmask 1<<12
#define gpiodp12ofmask 0<<12

// 14=kırmızı , 15=mavi , 13=turuncu , 12=yeşil

void init_leds ();
void turn_name_on();
void turn_surname_on();
void turn_name_off();
void turn_surname_off();
void delayy();

int main() {

init_leds();
turn_name_on();
turn_name_off(); //1    s
turn_name_on();
turn_name_off(); //2    e
turn_name_on();
turn_name_off(); //3    n
turn_name_on();
turn_name_off(); //4    a
turn_name_on();
turn_name_off(); //5    n
turn_name_on();
turn_name_off(); //6    u
turn_name_on();
turn_name_off(); //7    r

turn_surname_on();
turn_surname_off(); //1   t
turn_surname_on();
turn_surname_off(); //2   u
turn_surname_on();
turn_surname_off(); //3   r
turn_surname_on();
turn_surname_off(); //4   k
turn_surname_on();
turn_surname_off(); //5   m
turn_surname_on();
turn_surname_off(); //6   e
turn_surname_on();
turn_surname_off(); //7   n

return 0;
}


void init_leds(){

	rccahblenR = gpiodmask; // senanur = 764 , mod4=0 , kırmızı
	gpiodModr=gpiodP14mask;
	gpiodModr |=gpiodP13mask; // turkmen = 774 , mod4=2 , turuncu





}
void turn_name_on(){

	gpiodOdr=gpiodp14onmask;

delayy();

}
void turn_name_off(){

gpiodOdr&=gpiodp14ofmask;
delayy();

}
void turn_surname_on(){

gpiodOdr|=gpiodp13onmask;
delayy();

}
void turn_surname_off(){

gpiodOdr&=gpiodp13ofmask;
delayy();

}

void delayy(){
for(int i=0;i<0x03ABCDEF;i++){

}
}
