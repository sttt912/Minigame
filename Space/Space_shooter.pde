PImage bot,img, en;
PFont font;

int radiusOfHero=100, radiusOfEnemy, speedOfEnemy=1, Counter=0;
float positionOfHeroY=200, positionOfHeroX=100.0, positionOfEnemyY = 0.0, positionOfEnemyX=0.0;
int a=2; //состояние игры

void setup(){
  size(640, 400);// задаем размеры окна
  //Добавляем
   bot = loadImage("data/ff.png");// задаем картинку, файл должен лежать в директории Processing
   img = loadImage("data/bg.png");// задаем картинку, файл должен лежать в директории Processing
   en = loadImage("data/en.png");// задаем картинку, файл должен лежать в директории Processing
   background(img);
   font = createFont( "data/LetterGothicStd.otf", 32 );
   textFont(font);
}

void draw() {
  if (a==0){
    background(img);
    fill(255);
    text("Score:"+Counter, 470,50);// отредачив


//===============definiton of hero position=============
   image(bot,positionOfHeroX, positionOfHeroY);// положение шара-героя
//===============definition of enemy===============

radiusOfEnemy=round(random(60));
    for(int i = 0; i < height; i++){
      positionOfEnemyY=positionOfEnemyY+0.02*speedOfEnemy;// скорость падения шаров-противников по оси ординат
      image(en,positionOfEnemyX, positionOfEnemyY);
    }// отрисовка шаров-противников

if (positionOfEnemyY>height) {
  positionOfEnemyY=0.0;
  positionOfEnemyX = round(random(width)); // условие для повторения падения шаров-противников
  Counter++;
}

//==============clash==========================
if (abs(positionOfHeroX-positionOfEnemyX) < (radiusOfHero+radiusOfEnemy)/2 &
   (abs(height-radiusOfHero/2)-positionOfEnemyY) < (radiusOfHero+radiusOfEnemy)/2){// условие столкновения шаров-противников
      Counter=0;
      background(255,0,0);
      a=1;
}

if (keyPressed) {
      if (key == 'd' || key == 'D') {
    positionOfHeroX=positionOfHeroX+5;
      }

      if (key == 'a' || key == 'A') {
    positionOfHeroX=positionOfHeroX-5;
      }

       if (key == 'w' || key == 'W') {
    positionOfHeroY=positionOfHeroY-5;
      }

      if (key == 's' || key == 'S') {
    positionOfHeroY=positionOfHeroY+5;
      }
}}

if (a==1){
  text("GAME OVER!", 220,100);
  button(250,150,120,80,"GAME",0);
  stops(250,250,120,80,"EXIT");
}

if (a==2){
  button(250,100,120,80,"GAME",0);
  stops(250,200,120,80,"EXIT");
}

}


void button(int x, int y, int w, int h,String p,int v){
  fill(255, 0);
  rect(x, y, w, h);
  fill(0);
  text(p,x+(w/6),y+(h/2));
    if (mouseX > x && mouseX < x + w && mouseY > y && mouseY < y + h) {
      if (mousePressed){
        a=v;
      }
    }
}

void stops(int x, int y, int w, int h,String p){
  fill(255, 0);
  rect(x, y, w, h);
  fill(0);
  text(p,x+(w/6),y+(h/2));
    if (mouseX > x && mouseX < x + w && mouseY > y && mouseY < y + h) {
      if (mousePressed){
        exit();
      }
    }
}
